//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprRoczneDAO.h"
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
SprRoczneDAO::SprRoczneDAO(void)
{
 m_Client = new TClientDataSet(NULL);
 m_Reader = new readers::Sprz4SprReader();
 m_ZadSDB = new mng::StreamDB();
}
//---------------------------------------------------------------------------
SprRoczneDAO::~SprRoczneDAO(void)
{
 delete m_Client;
 delete m_Reader;
 delete m_ZadSDB;
}
//---------------------------------------------------------------------------
TClientDataSet * SprRoczneDAO::getDataSet(void)
{
  return m_Client;
}
//---------------------------------------------------------------------------
void SprRoczneDAO::open(const SprRocznePars& _Pars)
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
void SprRoczneDAO::createClient(void)
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
 m_Client->FieldDefs->Add("tdatrib_LP",ftString, 20);
 m_Client->FieldDefs->Add("NAZWA",ftString, 300);
 m_Client->FieldDefs->Add("INDEKS_MAT",ftString, 20);
 m_Client->FieldDefs->Add("ILOSC_P",ftCurrency);
 m_Client->FieldDefs->Add("RODZ_REM",ftString, 10);
 m_Client->FieldDefs->Add("RBH_P",ftCurrency);
 m_Client->FieldDefs->Add("RBH_R",ftCurrency);
 m_Client->FieldDefs->Add("ILOSC_R",ftCurrency);
 m_Client->FieldDefs->Add("ILOSC_WPS",ftString, 20);
 m_Client->FieldDefs->Add("PROC_WP",ftString, 20);
 m_Client->FieldDefs->Add("ILOSC_WZS",ftString, 20);
 m_Client->FieldDefs->Add("PROC_WZ",ftString, 20);
 m_Client->FieldDefs->Add("tdatrib_ILOSC_WPS",ftString, 100);
 m_Client->FieldDefs->Add("tdatrib_PROC_WP",ftString, 100);
 m_Client->FieldDefs->Add("tdatrib_ILOSC_WZS",ftString, 100);
 m_Client->FieldDefs->Add("tdatrib_PROC_WZ",ftString, 100);
 m_Client->FieldDefs->Add("UWAGI",ftString, 6000);
 if(m_Pars.Info)
 {
  m_Client->FieldDefs->Add("KUTY",ftString, 6000);

 }
 m_Client->IndexFieldNames = "KOD_WYDZIALU; WYDZIAL_IDX; KOD_WARSZTATU; WARSZTAT_IDX; POZYCJA; POZYCJA_IDX; NAZWA";
 m_Client->CreateDataSet();
 m_Client->LogChanges = false;
}
//---------------------------------------------------------------------------
void  SprRoczneDAO::addHF(const msg::Sprz4Spr & _Buff)
{
 addW(_Buff);
 addK(_Buff);
}
//---------------------------------------------------------------------------
const int SprRoczneDAO::M_HEAD_IDX(1);
const int SprRoczneDAO::M_DET_IDX(2);
const int SprRoczneDAO::M_FOOT_IDX(3);
const String SprRoczneDAO::M_HEAD_SPAN("  colspan =\"13\"   ");
const String SprRoczneDAO::M_HEAD_SPAN_EXT("  colspan =\"14\"   ");
const String SprRoczneDAO::M_FOOT_SPAN(" colspan =\"3\" ");
const String SprRoczneDAO::M_TR_ATRIB(" class=\"gruby\"   ");

//---------------------------------------------------------------------------
void  SprRoczneDAO::addW(const msg::Sprz4Spr & _Buff)
{
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
	m_Client->FieldByName("RBH_P")->AsCurrency      = _Val.RBHP;
	m_Client->FieldByName("ILOSC_R")->AsCurrency    = _Val.IloscR;
	m_Client->FieldByName("RBH_R")->AsCurrency      = _Val.RBHR;
	_Proc =_Val.getIloscWR() >0;
	m_Client->FieldByName("ILOSC_WPS")->AsString    = _Proc ? FormatFloat("###,###,##0.00",_Val.getIloscWR()) : String("------");
	m_Client->FieldByName("PROC_WP")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'",_Val.getProc()) : String("------") ;
	m_Client->FieldByName("ILOSC_WZS")->AsString    = _Proc ? FormatFloat("###,###,##0.00",_Val.getIloscWR()) : String("------");
	m_Client->FieldByName("PROC_WZ")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'",_Val.getProc()) : String("------");

	m_Client->FieldByName("tdatrib_ILOSC_WPS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WP")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_ILOSC_WZS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WZ")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";

   m_Client->Post();
  }
  _Dict.next();
 }
}
//---------------------------------------------------------------------------
void  SprRoczneDAO::addK(const msg::Sprz4Spr & _Buff)
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
	m_Client->FieldByName("ILOSC_P")->AsCurrency    = _Val.IloscP;
	m_Client->FieldByName("RBH_P")->AsCurrency      = _Val.RBHP;
	m_Client->FieldByName("ILOSC_R")->AsCurrency    = _Val.IloscR;
	m_Client->FieldByName("RBH_R")->AsCurrency      = _Val.RBHR;
	_IlW    =  _Val.getIloscWR();
	_ProcW  =  _Val.getProc();
	_Proc   = _IlW  >0 ;
	m_Client->FieldByName("ILOSC_WPS")->AsString    = _Proc ? FormatFloat("###,###,##0.00",_IlW)   : String("------");
	m_Client->FieldByName("PROC_WP")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'",_ProcW) : String("------") ;
	m_Client->FieldByName("ILOSC_WZS")->AsString    = _Proc ? FormatFloat("###,###,##0.00",_IlW)   : String("------");
	m_Client->FieldByName("PROC_WZ")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'",_ProcW) : String("------") ;

	m_Client->FieldByName("tdatrib_ILOSC_WPS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WP")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_ILOSC_WZS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WZ")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";

   m_Client->Post();
   addU(_Dict.getMasterID(),_Dict.getMasterKod(),_Dict.getID(),_Dict.getKod(),_Buff);
  }
  _Dict.next();
 }
}

//---------------------------------------------------------------------------
void  SprRoczneDAO::addU(const int _IdWydz, const String & _KodW, const int _IdKom, const String& _KodK, const msg::Sprz4Spr & _Buff)
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
	if(_Key.Pozycja ==999)
	{
	 m_Client->FieldByName("LP")->AsString  = "Razem pozosta³e zadania:";
	 m_Client->FieldByName("ILOSC_P")->Clear();
	 m_Client->FieldByName("RBH_P")->Clear();
	}
	else
	{
	 m_Client->FieldByName("LP")->AsString         = String("Razem ") + _Dict.getKod() + String(" - ")+ _Dict.getName();
	 m_Client->FieldByName("ILOSC_P")->AsCurrency  = _Val.IloscP;
	 m_Client->FieldByName("RBH_P")->AsCurrency     = _Val.RBHP;
	}

	m_Client->FieldByName("ILOSC_R")->AsCurrency    = _Val.IloscR;
	m_Client->FieldByName("RBH_R")->AsCurrency      = _Val.RBHR;
	_Proc = _Val.getIloscWR()>0  && _Key.Pozycja !=999;
	m_Client->FieldByName("ILOSC_WPS")->AsString    = _Proc && _Key.Pozycja !=999 ? FormatFloat("###,###,##0.00",_Val.getIloscWR()) : String("------");
	m_Client->FieldByName("PROC_WP")->AsString      = _Val.getIloscWR() >0 &&  _Key.Pozycja !=999 ? FormatFloat("###,###,##0.00'%'",_Val.getProc()) : String("------") ;
	m_Client->FieldByName("ILOSC_WZS")->AsString    = _Val.getIloscWR() >0 &&  _Key.Pozycja !=999 ? FormatFloat("###,###,##0.00",_Val.getIloscWR()) : String("------");
	m_Client->FieldByName("PROC_WZ")->AsString      = _Val.getIloscWR() >0 &&  _Key.Pozycja !=999 ? FormatFloat("###,###,##0.00'%'",_Val.getProc()) : String("------") ;

   	m_Client->FieldByName("tdatrib_ILOSC_WPS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WP")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_ILOSC_WZS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WZ")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";

   m_Client->Post();
  }
  if(_Key.Pozycja ==999) break;
  _Dict.next();
 }
}
//---------------------------------------------------------------------------
void  SprRoczneDAO::addDetails(const msg::Sprz4Spr & _Buff)
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
	bool _PozZad(_ItB->first.Pozycja ==999);
	bool _Proc(_ItB->second.getIloscWR() >0 && !_PozZad);
	if(!_PozZad)
	{
	 m_Client->FieldByName("ILOSC_P")->AsCurrency    = _ItB->second.IloscP;
	 m_Client->FieldByName("RBH_P")->AsCurrency      = _ItB->second.RBHP;
	}
	m_Client->FieldByName("ILOSC_R")->AsCurrency    = _ItB->second.IloscR;
	m_Client->FieldByName("RBH_R")->AsCurrency      = _ItB->second.RBHR;

	m_Client->FieldByName("ILOSC_WPS")->AsString    = _Proc ? FormatFloat("###,###,##0.00",_ItB->second.getIloscWR())  : String("------");
	m_Client->FieldByName("PROC_WP")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'", _ItB->second.getProc()) : String("------") ;
	m_Client->FieldByName("ILOSC_WZS")->AsString    = _Proc ? FormatFloat("###,###,##0.00", _ItB->second.getIloscWR()) : String("------");
	m_Client->FieldByName("PROC_WZ")->AsString      = _Proc ? FormatFloat("###,###,##0.00'%'", _ItB->second.getProc()) : String("------") ;

	m_Client->FieldByName("tdatrib_ILOSC_WPS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WP")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_ILOSC_WZS")->AsString    = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
	m_Client->FieldByName("tdatrib_PROC_WZ")->AsString      = _Proc ? "style =\"text-align: right; \"  "  : "style =\"text-align: center; \"  ";
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
void SprRoczneDAO::fillLP(void)
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
String SprRoczneDAO::getZadanie(const int _IdHarm)
{
  String _Res;
  if(m_ZadSDB->locate("ID_HARMONOGRAMU",_IdHarm) )
  {
	_Res = m_ZadSDB->fieldByName("ZADANIE")->AsString;
  }
  return _Res;
}
//---------------------------------------------------------------------------
String SprRoczneDAO::getInfo(const String& _Inf)
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
void SprRoczneDAO::close(void)
{
 if(m_Client->Active)
 {
  m_Client->EmptyDataSet();
  m_Client->Close();
 }
}
