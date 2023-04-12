//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprRoczne1DAO.h"
#include "Sprz4SprReader.h"
#include "Sprz4Spr.h"
#include "WydzialyDICT.h"
#include "KomorkiDICT.h"
#include "KodyUslugDICT.h"
#include "SprzetDICT.h"
#include "RemontyDICT.h"
#include "MANAGER\stream_db.h"
#include <math.h>
#include "WaitFRM.h"
#include <memory.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
SprRoczne1DAO::SprRoczne1DAO(void)
{
 m_Client = new TClientDataSet(NULL);
 m_Reader = new readers::Sprz4SprReader();
 m_ZadSDB = new mng::StreamDB();
}
//---------------------------------------------------------------------------
SprRoczne1DAO::~SprRoczne1DAO(void)
{
 delete m_Client;
 delete m_Reader;
 delete m_ZadSDB;
}
//---------------------------------------------------------------------------
TClientDataSet * SprRoczne1DAO::getDataSet(void)
{
  return m_Client;
}
//---------------------------------------------------------------------------
void SprRoczne1DAO::open(const SprRocznePars& _Pars)
{
 //PRZYGOTOWANIE NARZÊDZI
   m_Pars = _Pars;
   createClient();
   m_ZadSDB->setQuery("select distinct id_harmonogramu, zadanie from pr_harmonogram  where rok=:ROK and typ='W'");
   m_ZadSDB->paramByName("ROK")->AsInteger = m_Pars.Rok;
   m_ZadSDB->open();
 //WCZYTANIE DANYCH DO BUFORA
   readers::Sprz4SprReader::Pars _SPars;
   _SPars.Rok    = m_Pars.Rok;
   _SPars.MiesOd = m_Pars.MiesOd;
   _SPars.MiesDo = m_Pars.MiesDo;
   msg::Sprz4Spr _Buff;
   m_Reader->read(_Buff,_SPars);
 //UTWORZENIE NAG£ÓWKÓW I STOPEK
   addHF(_Buff);
 //UTWORZENIE LISTY SZCZEGÓ£OWEJ
   addDetails(_Buff);
   fillLP();
 //SPRZ¥TANIE
   m_ZadSDB->close();
}
//---------------------------------------------------------------------------
void SprRoczne1DAO::createClient(void)
{
 close();
 m_Client->FieldDefs->Clear();
 m_Client->FieldDefs->Add("tratrib",ftString, 50);
 m_Client->FieldDefs->Add("KOD_WYDZIALU",ftString, 20);
 m_Client->FieldDefs->Add("WYDZIAL_IDX",ftInteger);
 m_Client->FieldDefs->Add("POZYCJA",ftInteger);
 m_Client->FieldDefs->Add("POZYCJA_IDX",ftInteger);
 m_Client->FieldDefs->Add("KOD_WARSZTATU",ftString, 20);
 m_Client->FieldDefs->Add("WARSZTAT_IDX",ftInteger);
 m_Client->FieldDefs->Add("LP",ftString, 300);
 m_Client->FieldDefs->Add("tdatrib_LP",ftString, 40);
 m_Client->FieldDefs->Add("NAZWA",ftString, 300);
 m_Client->FieldDefs->Add("INDEKS_MAT",ftString, 20);
 m_Client->FieldDefs->Add("ILOSC_P",ftCurrency);
 m_Client->FieldDefs->Add("RODZ_REM",ftString, 10);
 m_Client->FieldDefs->Add("RBH_P",ftCurrency);
 m_Client->FieldDefs->Add("RBH_R",ftCurrency);

 m_Client->FieldDefs->Add("ILOSC_WYR",ftString,100);
 m_Client->FieldDefs->Add("tdatrib_ILOSC_WYR",ftString,40);
 m_Client->FieldDefs->Add("PROC_WYR",ftString,20);
 m_Client->FieldDefs->Add("tdatrib_PROC_WYR",ftString,40);

 m_Client->FieldDefs->Add("ILOSC_WREM",ftString,100);
 m_Client->FieldDefs->Add("tdatrib_ILOSC_WREM",ftString,40);
 m_Client->FieldDefs->Add("PROC_WREM",ftString,20);
 m_Client->FieldDefs->Add("tdatrib_PROC_WREM",ftString,40);

 m_Client->FieldDefs->Add("ILOSC_ND",ftString,100);
 m_Client->FieldDefs->Add("tdatrib_ILOSC_ND",ftString,40);
 m_Client->FieldDefs->Add("PROC_ND",ftString,20);
 m_Client->FieldDefs->Add("tdatrib_PROC_ND",ftString,40);
 m_Client->FieldDefs->Add("UWAGI",ftString,500);



 if(m_Pars.Info)
 {
  m_Client->FieldDefs->Add("KUTY",ftString, 6000);

 }
 m_Client->IndexFieldNames = "KOD_WYDZIALU; WYDZIAL_IDX; KOD_WARSZTATU; WARSZTAT_IDX; POZYCJA; POZYCJA_IDX; NAZWA";
 m_Client->CreateDataSet();
 m_Client->LogChanges = false;
}
//---------------------------------------------------------------------------
void  SprRoczne1DAO::addHF(const msg::Sprz4Spr & _Buff)
{
 addW(_Buff);
 addK(_Buff);
}
//---------------------------------------------------------------------------
const int SprRoczne1DAO::M_HEAD_IDX(1);
const int SprRoczne1DAO::M_DET_IDX(2);
const int SprRoczne1DAO::M_FOOT_IDX(3);
const String SprRoczne1DAO::M_HEAD_SPAN("  colspan =\"13\"   ");
const String SprRoczne1DAO::M_HEAD_SPAN_EXT("  colspan =\"14\"   ");
const String SprRoczne1DAO::M_FOOT_SPAN(" colspan =\"3\" ");
const String SprRoczne1DAO::M_TR_ATRIB(" class=\"gruby\"   ");
const String SprRoczne1DAO::M_STYLE_CENTER("style =\"text-align: center; \"   ");
const String SprRoczne1DAO::M_STYLE_RIGHT("style =\"text-align: right; \"   ");
const String SprRoczne1DAO::M_NUMBER_FRMT("###,###,##0.00");
const String SprRoczne1DAO::M_NULL_VAL("------");
//---------------------------------------------------------------------------
void  SprRoczne1DAO::addW(const msg::Sprz4Spr & _Buff)
{
 String _IloscWyr, _IloscWRem;
 msg::Sprz4Spr::Key _Key;
 msg::Sprz4Spr::Val _Val;
 dict::WydzialyDICT & _Dict = dict::WydzialyDICT::instance();
 _Dict.first();
 bool _Proc;
 while(!_Dict.isEof())
 {
  _Key.IdWydz = _Dict.getID();
  _Val = _Buff.sum(_Key);
  if(!_Val.isEmpty())
  {
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = M_TR_ATRIB + String(" bgcolor=\"#B1AB7F\"  ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString = _Dict.getKod();
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_HEAD_IDX;
	m_Client->FieldByName("LP")->AsString           = _Dict.getKod() + String(" - ")+ _Dict.getName();
	m_Client->FieldByName("tdatrib_LP")->AsString = m_Pars.Info ? M_HEAD_SPAN_EXT : M_HEAD_SPAN;
   m_Client->Post();
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = M_TR_ATRIB + String(" bgcolor=\"#B1AB7F\"  ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString = _Dict.getKod();
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_FOOT_IDX;
	m_Client->FieldByName("LP")->AsString           = String("Razem ") +  _Dict.getName() + String(": ");
	m_Client->FieldByName("tdatrib_LP")->AsString  = M_FOOT_SPAN;
	m_Client->FieldByName("ILOSC_P")->AsCurrency    = _Val.IloscP;

	_Proc =_Val.IloscP >0;
	insToClient(&_Val,_Proc);
   m_Client->Post();
  }
  _Dict.next();
 }
}
//---------------------------------------------------------------------------
void  SprRoczne1DAO::addK(const msg::Sprz4Spr & _Buff)
{
 msg::Sprz4Spr::Key _Key;
 msg::Sprz4Spr::Val _Val;
 dict::KomorkiDICT & _Dict = dict::KomorkiDICT::instance();
 _Dict.first();
 bool _Proc;
 Currency _IlW, _ProcW;
 while(!_Dict.isEof())
 {
  _Key.IdKom = _Dict.getID();
  _Val = _Buff.sum(_Key);
  if(!_Val.isEmpty())
  {
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString       = M_TR_ATRIB +  String("  bgcolor=\"#FFFFB7\" ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString  = _Dict.getMasterKod();
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger  = M_DET_IDX;
	m_Client->FieldByName("KOD_WARSZTATU")->AsString = _Dict.getKod();
	m_Client->FieldByName("WARSZTAT_IDX")->AsInteger = M_HEAD_IDX;
	m_Client->FieldByName("LP")->AsString            = _Dict.getKod() + String(" - ")+ _Dict.getName();
	m_Client->FieldByName("tdatrib_LP")->AsString    =m_Pars.Info ? M_HEAD_SPAN_EXT : M_HEAD_SPAN;
   m_Client->Post();
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = M_TR_ATRIB +  String("   bgcolor=\"#FFFFB7\" ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString = _Dict.getMasterKod();
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("KOD_WARSZTATU")->AsString = _Dict.getKod();
	m_Client->FieldByName("WARSZTAT_IDX")->AsInteger = M_FOOT_IDX;
	m_Client->FieldByName("LP")->AsString           = String("Razem ") + _Dict.getName() + String(": ");
	m_Client->FieldByName("tdatrib_LP")->AsString = M_FOOT_SPAN;

	_Proc =_Val.IloscP >0;
	insToClient(&_Val,_Proc);

   m_Client->Post();
   addU(_Dict.getMasterID(),_Dict.getMasterKod(),_Dict.getID(),_Dict.getKod(),_Buff);
  }
  _Dict.next();
 }
}

//---------------------------------------------------------------------------
void  SprRoczne1DAO::addU(const int _IdWydz, const String & _KodW, const int _IdKom, const String& _KodK, const msg::Sprz4Spr & _Buff)
{
 msg::Sprz4Spr::Key _Key;
 msg::Sprz4Spr::Val _Val;
 dict::KodyUslugDICT & _Dict = dict::KodyUslugDICT::instance();
 _Dict.first();
 bool _Proc;
 while(!_Dict.isEof())
 {
  _Key.IdWydz = _IdWydz;
  _Key.IdKom  = _IdKom;
  _Key.Pozycja  = _Dict.getID2();
  _Val = _Buff.sum(_Key);
  if(!_Val.isEmpty())
  {
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = M_TR_ATRIB +  String("  bgcolor=\"#7DD9FF\" ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString = _KodW;
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("KOD_WARSZTATU")->AsString = _KodK;
	m_Client->FieldByName("WARSZTAT_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("POZYCJA")->AsInteger      = _Dict.getID2();
	m_Client->FieldByName("POZYCJA_IDX")->AsInteger  = M_HEAD_IDX;
	if(_Key.Pozycja ==999)
	{
	 m_Client->FieldByName("LP")->AsString  = "Pozosta³e zadania";
	}
	else
	{
	 m_Client->FieldByName("LP")->AsString         = _Dict.getKod() + String(" - ")+ _Dict.getName();
	}
	m_Client->FieldByName("tdatrib_LP")->AsString  = m_Pars.Info ? M_HEAD_SPAN_EXT : M_HEAD_SPAN;
   m_Client->Post();
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = M_TR_ATRIB +  String("   bgcolor=\"#7DD9FF\" ");
	m_Client->FieldByName("KOD_WYDZIALU")->AsString = _KodW;
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("KOD_WARSZTATU")->AsString = _KodK;
	m_Client->FieldByName("WARSZTAT_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("POZYCJA")->AsInteger      = _Dict.getID2();
	m_Client->FieldByName("POZYCJA_IDX")->AsInteger  = M_FOOT_IDX;
	m_Client->FieldByName("LP")->AsString           = String("Razem ")  + _Dict.getName() + String(": ");
	m_Client->FieldByName("tdatrib_LP")->AsString = M_FOOT_SPAN;
	bool _Proc = _Key.Pozycja !=999 ;
	if(_Proc)
	{
	 m_Client->FieldByName("LP")->AsString         = String("Razem ") + _Dict.getKod() + String(" - ")+ _Dict.getName();
	}
	else
	{
	 m_Client->FieldByName("LP")->AsString  = "Razem pozosta³e zadania:";
	}
	insToClient(&_Val,_Proc,false);
   m_Client->Post();
  }
  if(_Key.Pozycja ==999) break;
  _Dict.next();
 }
}
//---------------------------------------------------------------------------
void  SprRoczne1DAO::addDetails(const msg::Sprz4Spr & _Buff)
{
 std::auto_ptr<importmdb::T_WaitFRM> _FWait(new importmdb::T_WaitFRM(NULL) );
 msg::Sprz4Spr::const_iterator _ItB(_Buff.begin() );
 msg::Sprz4Spr::const_iterator _ItE(_Buff.end() );
 TReplaceFlags _RFl;
 _RFl<<rfReplaceAll;
 _FWait->start(_Buff.size());
 for(_ItB; _ItB!=_ItE;++_ItB)
 {
   m_Client->Append();
	m_Client->FieldByName("tratrib")->AsString      = " ";
	m_Client->FieldByName("KOD_WYDZIALU")->AsString =dict::WydzialyDICT::instance().getKod(_ItB->first.IdWydz);
	m_Client->FieldByName("WYDZIAL_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("KOD_WARSZTATU")->AsString =dict::KomorkiDICT::instance().getKod(_ItB->first.IdKom);
	m_Client->FieldByName("WARSZTAT_IDX")->AsInteger = M_DET_IDX;
	m_Client->FieldByName("POZYCJA")->AsInteger      = _ItB->first.Pozycja;
	m_Client->FieldByName("POZYCJA_IDX")->AsInteger  = M_DET_IDX;
	m_Client->FieldByName("LP")->AsString           = "LP";
	m_Client->FieldByName("tdatrib_LP")->AsString = " ";
	if(_ItB->first.IdSprz >= 0)
	{
	 m_Client->FieldByName("NAZWA")->AsString        = dict::SprzetDICT::instance().getNazwa(_ItB->first.IdSprz) + String(" ") + _ItB->second.Zad;
	 m_Client->FieldByName("INDEKS_MAT")->AsString   = dict::SprzetDICT::instance().getJIM(_ItB->first.IdSprz);
	}
	else
	{
	 m_Client->FieldByName("NAZWA")->AsString        = getZadanie( std::abs(_ItB->first.IdSprz) );

	}
	if(m_Pars.Info)
	{
	 m_Client->FieldByName("NAZWA")->AsString = m_Client->FieldByName("NAZWA")->AsString + String(" (")+  String(_ItB->first.IdSprz)+ String(")");
	}
	_FWait->step(m_Client->FieldByName("NAZWA")->AsString);
	m_Client->FieldByName("RODZ_REM")->AsString     = dict::RemontyDICT::instance().getKod(_ItB->first.IdRem);
	if(m_Pars.Info)
	{
	 m_Client->FieldByName("RODZ_REM")->AsString     = m_Client->FieldByName("RODZ_REM")->AsString  + String(" (") + String(_ItB->first.IdRem) +  String(")");
    }
	bool _Proc(_ItB->first.Pozycja !=999);
	msg::Sprz4Spr::Val _Val = _ItB->second;
	insToClient(&_Val,_Proc,false);
	if(m_Pars.Info)
	{
	 m_Client->FieldByName("UWAGI")->AsString        = getInfo(_ItB->second.Info.Plan);
	 m_Client->FieldByName("KUTY")->AsString        = getInfo(_ItB->second.Info.Real);
	}
   m_Client->Post();

 }
 _FWait->Close();
}
//---------------------------------------------------------------------------
void SprRoczne1DAO::fillLP(void)
{
 m_Client->First();
 int _LP(0);
 while(!m_Client->Eof)
 {
  if(m_Client->FieldByName("LP")->AsString =="LP")
  {
   m_Client->Edit();
	m_Client->FieldByName("LP")->AsString = ++_LP;
   m_Client->Post();
  }
  m_Client->Next();
 }
}
//---------------------------------------------------------------------------
String SprRoczne1DAO::getZadanie(const int _IdHarm)
{
  String _Res;
  if(m_ZadSDB->locate("ID_HARMONOGRAMU",_IdHarm) )
  {
	_Res = m_ZadSDB->fieldByName("ZADANIE")->AsString;
  }
  return _Res;
}
//---------------------------------------------------------------------------
String SprRoczne1DAO::getInfo(const String& _Inf)
{
 if(!m_Pars.Info) return String("");
 String  _Res(_Inf);
 TReplaceFlags _RFl;
 _RFl<<rfReplaceAll;
 _Res = StringReplace(_Res," ","&#160;",_RFl);
 _Res = StringReplace(_Res,msg::Sprz4Spr::M_COL_INFO_SEP,"&#160;", _RFl);
 _Res = StringReplace(_Res,msg::Sprz4Spr::M_ROW_INFO_SEP,"<br>", _RFl);
 return _Res;
}

//---------------------------------------------------------------------------
void SprRoczne1DAO::insToClient(void * __Val, const bool _Proc, const bool _Podz)
{
 String _IloscWyr, _IloscWRem;
  msg::Sprz4Spr::Val & _Val = *((msg::Sprz4Spr::Val*) __Val );
	if(_Proc)
	{
	 m_Client->FieldByName("ILOSC_P")->AsCurrency = _Val.IloscP;
	 m_Client->FieldByName("RBH_P")->AsCurrency   = _Val.RBHP;

	 if(_Podz)
	 {
	  _IloscWyr   = String("<span style=\"font-size:10px;\" >z planu: ") + FormatFloat(M_NUMBER_FRMT, _Val.IloscRZPlanu) +String("</span> ");
	  _IloscWyr  += String("ca³oœæ:      ") + FormatFloat(M_NUMBER_FRMT, _Val.IloscR) + String("<br/>");
	 }
	 else
	 {
	  _IloscWyr = FormatFloat(M_NUMBER_FRMT, _Val.IloscR);
	 }
	 m_Client->FieldByName("ILOSC_WYR")->AsString          = _IloscWyr;
	 m_Client->FieldByName("tdatrib_ILOSC_WYR")->AsString  = M_STYLE_RIGHT;
	 m_Client->FieldByName("PROC_WYR")->AsString           = FormatFloat(M_NUMBER_FRMT,_Val.getProcR());
	 m_Client->FieldByName("tdatrib_PROC_WYR")->AsString   = M_STYLE_RIGHT;


	 if(_Podz)
	 {
	  _IloscWRem   = String("<span style=\"font-size:10px;\">z planu: ") + FormatFloat(M_NUMBER_FRMT, _Val.IloscWRZPlanu) +String("</span> ");
	  _IloscWRem  += String("ca³oœæ: ") + FormatFloat(M_NUMBER_FRMT, _Val.IloscWR) + String("<br/>");
	 }
	 else
	 {
	  _IloscWRem = _Val.IloscWR!=0.00 ? FormatFloat(M_NUMBER_FRMT, _Val.IloscWR): String("");
	 }
	 m_Client->FieldByName("ILOSC_WREM")->AsString         = _IloscWRem;
	 m_Client->FieldByName("tdatrib_ILOSC_WREM")->AsString = M_STYLE_RIGHT;
	 m_Client->FieldByName("PROC_WREM")->AsString          = _Val.IloscWR!=0.00 ?  FormatFloat(M_NUMBER_FRMT,_Val.getProcWR()) :String("");
	 m_Client->FieldByName("tdatrib_PROC_WREM")->AsString  = M_STYLE_RIGHT;


	 m_Client->FieldByName("ILOSC_ND")->AsString           = _Val.IloscND != 0.00 ? FormatFloat(M_NUMBER_FRMT,_Val.IloscND) : String("");
	 m_Client->FieldByName("tdatrib_ILOSC_ND")->AsString   = M_STYLE_RIGHT;
	 m_Client->FieldByName("PROC_ND")->AsString            = _Val.IloscND != 0.00 ? FormatFloat(M_NUMBER_FRMT,_Val.getProcND()) :String("");
	 m_Client->FieldByName("tdatrib_PROC_ND")->AsString    = M_STYLE_RIGHT;

	}
	else
	{
	 m_Client->FieldByName("ILOSC_P")->Clear(); //ŒWIADOMIE CLEARUJÊ
	 m_Client->FieldByName("RBH_P")->Clear();

	 m_Client->FieldByName("ILOSC_WYR")->AsString          = _Val.IloscR !=0.0 ? FormatFloat(M_NUMBER_FRMT, _Val.IloscR) :String("");
	 m_Client->FieldByName("tdatrib_ILOSC_WYR")->AsString  = M_STYLE_RIGHT;
	 m_Client->FieldByName("PROC_WYR")->AsString           = M_NULL_VAL;
	 m_Client->FieldByName("tdatrib_PROC_WYR")->AsString   = M_STYLE_CENTER;



	 m_Client->FieldByName("ILOSC_WREM")->AsString         = _Val.IloscWR !=0.0 ? FormatFloat(M_NUMBER_FRMT, _Val.IloscWR) : String("");
	 m_Client->FieldByName("tdatrib_ILOSC_WREM")->AsString = M_STYLE_RIGHT;
	 m_Client->FieldByName("PROC_WREM")->AsString          = M_NULL_VAL;
	 m_Client->FieldByName("tdatrib_PROC_WREM")->AsString  = M_STYLE_CENTER;


	 m_Client->FieldByName("ILOSC_ND")->AsString           = M_NULL_VAL;
	 m_Client->FieldByName("tdatrib_ILOSC_ND")->AsString   = M_STYLE_CENTER;
	 m_Client->FieldByName("PROC_ND")->AsString            = M_NULL_VAL;
	 m_Client->FieldByName("tdatrib_PROC_ND")->AsString    = M_STYLE_CENTER;


	}
 m_Client->FieldByName("RBH_R")->AsCurrency      = _Val.RBHR;
}
//---------------------------------------------------------------------------
void SprRoczne1DAO::close(void)
{
 if(m_Client->Active)
 {
  m_Client->EmptyDataSet();
  m_Client->Close();
 }
}
