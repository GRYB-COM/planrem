//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZlecMover.h"
#include <dateutils.hpp>
#include "MANAGER\stream_db.h"
#include "MANAGER\message_dlg.h"
#include "COMMON\Tools.h"
#include "MoversTools.h"
#include "MagID.h"
#include "KomorkiDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
ZlecMover::ZlecMover(void)
{
 m_JednSDB = new mng::StreamDB();
 m_JednSDB->setQuery("SELECT * FROM PR_JEDNOSTKI");


 m_KomorkiSDB = new mng::StreamDB();
 m_KomorkiSDB->setQuery("SELECT * FROM PR_KOMORKI");

 m_MagazynSDB = new mng::StreamDB();
 m_MagazynSDB->setQuery("SELECT * FROM PR_MAGAZYN");

 m_HarmSDB = new mng::StreamDB();
 m_HarmSDB->setQuery("SELECT * FROM PR_HARMONOGRAM where ROK=:ROK");


}
//---------------------------------------------------------------------------
ZlecMover::~ZlecMover(void)
{
 delete m_JednSDB;
 delete m_KomorkiSDB;
 delete m_MagazynSDB;
 delete m_HarmSDB;
}
//---------------------------------------------------------------------------
String ZlecMover::getIsRecSQL(void)
{
 return "SELECT * FROM PR_ZLECENIA WHERE SYGN_ZLECENIA = :SYGN_ZLECENIA AND ID_KOMORKI = :ID_KOMORKI";
}
//---------------------------------------------------------------------------
String ZlecMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_ZLECENIA(ROK,ID_ZLECENIA,ID_MAG,DEPOZYT,ID_KOMORKI_GLW,SYGN_ZLECENIA,DATA_WYST,DATA_PROP_ZAK,LICZBA_RBH, \
 DATA_ZAK,UWAGI,ZADANIE,ID_KOMORKI,ID_HARM,NR_HARM,SYGN_MAG,STATUS,ID_JEDNOSTKI,ROK_MAG, NR_KOL,NR_MAG) ");
 _Res +=" VALUES(:ROK,GEN_ID(PR_ZLECENIA_GEN,1), ";
 _Res +=" :ID_MAG, :DEPOZYT, :ID_KOMORKI_GLW,";
 _Res +=" :SYGN_ZLECENIA,:DATA_WYST,:DATA_PROP_ZAK,:LICZBA_RBH,:DATA_ZAK,:UWAGI,:ZADANIE, ";
 _Res +=" :ID_KOMORKI, ";
 _Res +=" :ID_HARM,  :ID_HARM, :SYGN_MAG, :STATUS, ";
 _Res += ":ID_JEDNOSTKI, :ROK_MAG, :NR_KOL, :NR_MAG)";
 return _Res;
}
//---------------------------------------------------------------------------
String ZlecMover::getUpdRecSQL(void)
{
 String _Res(" UPDATE PR_ZLECENIA SET  ROK = :ROK, ");
 _Res += " ID_MAG =  :ID_MAG, ";
 _Res += " ID_KOMORKI_GLW =  :ID_KOMORKI_GLW, ";
 _Res += " DEPOZYT =  :DEPOZYT, ";
 _Res += " DATA_WYST = :DATA_WYST, DATA_PROP_ZAK = :DATA_PROP_ZAK, LICZBA_RBH = :LICZBA_RBH, DATA_ZAK = :DATA_ZAK, UWAGI=:UWAGI ,ZADANIE =:ZADANIE, ";
 _Res += " ID_HARM = :ID_HARM, ";
 _Res += " NR_HARM = :ID_HARM,  ";
 _Res += " SYGN_MAG  = :SYGN_MAG,  ";
 _Res += " STATUS = :STATUS, ";
 _Res += " ID_JEDNOSTKI = :ID_JEDNOSTKI, ";
 _Res += " ROK_MAG = :ROK_MAG, ";
 _Res += " NR_KOL  = :NR_KOL, ";
 _Res += " NR_MAG  = :NR_MAG ";
 _Res += " WHERE SYGN_ZLECENIA = :SYGN_ZLECENIA AND  ID_KOMORKI =  :ID_KOMORKI ";
 return _Res;
}
//---------------------------------------------------------------------------
String ZlecMover::getLabel(TDataSet* Source)
{
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 String _Res("Karty - KUT nr:  ");
 _Res += progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUTa")->AsString,false,_KodWydz);
 _Res += " Nr harm.";
 _Res += Source->FieldByName("Nr harm")->AsString;
 return _Res;
}
//---------------------------------------------------------------------------
void ZlecMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 String _Statusy("SD0");
 String _St(Source->FieldByName("Pozycja")->AsString);
 int _NrKol = _St.ToIntDef(0);
 _St = _Statusy.Pos(_St) > 0 ? "G" : "K";
 setKeyPars(Dest,Source);
 Dest->ParamByName("DATA_WYST")->AsDateTime     = Source->FieldByName("Data wystawienia")->AsDateTime;
 Dest->ParamByName("DATA_ZAK")->AsDateTime      = Source->FieldByName("Data zakoñczenia")->AsDateTime;
 Dest->ParamByName("DATA_PROP_ZAK")->AsDateTime = Source->FieldByName("Prop termin zak")->AsDateTime;
 if(Source->FieldByName("p rbh")->AsString.IsEmpty() )
 {
  Dest->ParamByName("LICZBA_RBH")->AsFloat     = 0.00;
 }
 else
 {
  Dest->ParamByName("LICZBA_RBH")->AsFloat     = Source->FieldByName("p rbh")->AsFloat;
 }
 Dest->ParamByName("UWAGI")->AsString         = Source->FieldByName("UWAGI")->AsString.SubString(1,250);
 Dest->ParamByName("ZADANIE")->AsString       = Source->FieldByName("ZADANIE")->AsString.SubString(1,250);

 Dest->ParamByName("ID_HARM")->AsInteger      = Source->FieldByName("nr harm")->AsInteger;
 Dest->ParamByName("STATUS")->AsString        = _St;
 Dest->ParamByName("NR_KOL")->AsInteger       = _NrKol;
 setJedn(Dest,Source);
 setMag(Dest,Source);
 setHarm(Dest,Source);
 TParam * _Par(Dest->FindParam("ROK"));
 if(_Par) _Par->AsInteger = 2014;

}
//---------------------------------------------------------------------------
 void   ZlecMover::setJedn(TParams * Dest, TDataSet* Source)
 {
  if(!m_JednSDB->isOpen())    m_JednSDB->open();
  int _IdJedn(-1);
  if(m_JednSDB->locate("JW",Source->FieldByName("Nr JW/ dla kogo")->AsString))
  {
   _IdJedn = m_JednSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
  }
  else
  {
   AnsiString _Mess("Nie znaleziono jednostki o nastêpuj¹cym kodzie: ");
   _Mess += Source->FieldByName("Nr JW/ dla kogo")->AsAnsiString + AnsiString(" \n");
   _Mess += "Czy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  Dest->ParamByName("ID_JEDNOSTKI")->AsInteger = _IdJedn;
 }
//---------------------------------------------------------------------------
 void   ZlecMover::setKom(TParams * Dest, TDataSet* Source)
 {
  if(!m_KomorkiSDB->isOpen())	m_KomorkiSDB->open();
  int _IdKom(-1);
  if(m_KomorkiSDB->locate("KOD",Source->FieldByName("Warsztat")->AsAnsiString))
  {
   _IdKom = m_KomorkiSDB->fieldByName("ID_KOMORKI")->AsInteger;
  }
  else
  {
   AnsiString _Mess("Nie znaleziono warsztatu o nastêpuj¹cym kodzie: ");
   _Mess += Source->FieldByName("Warsztat")->AsAnsiString + AnsiString(" \n");
   _Mess += "Czy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  Dest->ParamByName("ID_KOMORKI")->AsInteger = _IdKom;
 }
//---------------------------------------------------------------------------
 void   ZlecMover::setHarm(TParams * Dest, TDataSet* Source)
 {
  if(!m_HarmSDB->isOpen())
  {
   m_HarmSDB->paramByName("ROK")->AsInteger =  2014;
   m_HarmSDB->open();
  }
  int _IdHarm(-1);
  if(m_HarmSDB->locate("ID_HARMONOGRAMU",Source->FieldByName("nr harm")->AsInteger))
  {
   _IdHarm = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
  }
  else
  {
   AnsiString _Mess("Nie znaleziono pozycji harmonogramu nr: ");
   _Mess += Source->FieldByName("nr harm")->AsAnsiString + AnsiString(" \n");
   _Mess += "Czy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  Dest->ParamByName("ID_HARM")->AsInteger = _IdHarm;
 }
//---------------------------------------------------------------------------
 void   ZlecMover::setMag(TParams * Dest, TDataSet* Source)
 {
   int _NrMag = Source->FieldByName("Nr kut")->AsInteger;
   int _Lp    = Source->FieldByName("Lp")->AsInteger;

  if(!m_MagazynSDB->isOpen() )   m_MagazynSDB->open();
  int _IdMag(-1),_IdKom(-1), _RokMag(-1);
  msg::MagID _MagID = MoversTools::makeMagID(Source);
  String _SygnMag, _Dep;
  if(m_MagazynSDB->getClient()->RecordCount ==0)
  {
   m_MagazynSDB->close();
   m_MagazynSDB->open();
  }
  TLocateOptions _LOpt;
  Variant _Pars[4];
  _Pars[0] = _MagID.IdKomorki;
  _Pars[1] = _MagID.Rok;
  _Pars[2] = _MagID.Depozyt;
  _Pars[3] = _MagID.NrMag;
  if(m_MagazynSDB->locate("ID_KOMORKI;ROK;DEPOZYT;NR_MAG",VarArrayOf(_Pars,3),_LOpt)  )
  {
   _IdMag  = m_MagazynSDB->fieldByName("ID_MAG")->AsInteger;
   _IdKom  = m_MagazynSDB->fieldByName("ID_KOMORKI")->AsInteger;
   _Dep    = m_MagazynSDB->fieldByName("DEPOZYT")->AsString;
   _RokMag = m_MagazynSDB->fieldByName("ROK")->AsInteger;
   _SygnMag = m_MagazynSDB->fieldByName("SYGN_MAG")->AsString;
   Dest->ParamByName("ID_MAG")->AsInteger         = _IdMag;
   Dest->ParamByName("ROK_MAG")->AsInteger        = _RokMag;
   Dest->ParamByName("ID_KOMORKI_GLW")->AsInteger = _IdKom;
   Dest->ParamByName("DEPOZYT")->AsString         = _Dep;
   Dest->ParamByName("SYGN_MAG")->AsString        = _SygnMag;
   Dest->ParamByName("NR_MAG")->AsString         =  _MagID.NrMag;;
  }
  else
  {
   Dest->ParamByName("ID_MAG")->Clear();
   Dest->ParamByName("ID_KOMORKI_GLW")->Clear();
   Dest->ParamByName("DEPOZYT")->Clear();
   Dest->ParamByName("nr_mag")->Clear();
   AnsiString _Mess("Nie znaleziono pozycji magazynowej o sygnaturze: ");
   _Mess += _MagID.getSygnMag();
   _Mess += String("\n Nr KUTa z accessa: ") +  Source->FieldByName("Nr KUTa")->AsString;
   _Mess += String("\t Nr harm: ") +  Source->FieldByName("nr harm")->AsString;
   _Mess += "\nCzy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  if(Source->RecNo == Source->RecordCount) m_MagazynSDB->close();


  /*
  String _Dep, _St;
  String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
  String _Sygn(Source->FieldByName("Nr KUTa")->AsString);
  _Sygn = progcommon::Tools::prepareNewSygnKUT(_Sygn,true,_KodWydz);
  String _SygnMag;
  if(m_MagazynSDB->locate("GLOWNY_KUT",_Sygn,_LOpt)  )
  {
   _IdMag  = m_MagazynSDB->fieldByName("ID_MAG")->AsInteger;
   _IdKom  = m_MagazynSDB->fieldByName("ID_KOMORKI")->AsInteger;
   _Dep    = m_MagazynSDB->fieldByName("DEPOZYT")->AsString;
   _RokMag = m_MagazynSDB->fieldByName("ROK")->AsInteger;
   _SygnMag = m_MagazynSDB->fieldByName("SYGN_MAG")->AsString;
  }
  else
  {
   _St = Dest->ParamByName("STATUS")->AsString;
   String _War = _St =="G" ? Source->FieldByName("Warsztat")->AsString : Source->FieldByName("Warsztat wiod¹cy")->AsString;
   if(_War.IsEmpty() ) _War =  Source->FieldByName("Serwis")->AsString;
   if(_War.IsEmpty() ) _War =  Source->FieldByName("Warsztat")->AsString;
   if(m_KomorkiSDB->locate("KOD",_War) )
   {
	_IdKom = m_KomorkiSDB->fieldByName("ID_KOMORKI")->AsInteger;
	 msg::MagID _MagID = MoversTools::makeMagID(Source);
	if(_SygnMag.IsEmpty()) _SygnMag = _MagID.getSygnMag();
	Variant _Vals[4];
	_Vals[0] = _IdKom;
	_Vals[1] = _MagID.Depozyt;
	_Vals[2] = _MagID.Rok;
	_Vals[3] = _SygnMag;
	if(m_MagazynSDB->locate("ID_KOMORKI;DEPOZYT;ROK;SYGN_MAG",VarArrayOf(_Vals,3)))
	{
	 _IdMag = m_MagazynSDB->fieldByName("ID_MAG")->AsInteger;
	 _Dep   = m_MagazynSDB->fieldByName("DEPOZYT")->AsString;
	 _RokMag = m_MagazynSDB->fieldByName("ROK")->AsInteger;
	}
   }
  }
  if(_IdMag >0)
  {
   Dest->ParamByName("ID_MAG")->AsInteger         = _IdMag;
   Dest->ParamByName("ROK_MAG")->AsInteger        = _RokMag;
   Dest->ParamByName("ID_KOMORKI_GLW")->AsInteger = _IdKom;
   Dest->ParamByName("DEPOZYT")->AsString         = _Dep;
   Dest->ParamByName("NR_MAG")->AsString          = _SygnMag;
  }
  else
  {
   Dest->ParamByName("ID_MAG")->Clear();
   Dest->ParamByName("ID_KOMORKI_GLW")->Clear();
   Dest->ParamByName("DEPOZYT")->Clear();
   Dest->ParamByName("nr_mag")->Clear();
   AnsiString _Mess("Nie znaleziono pozycji magazynowej z KUTem o sygnaturze: ");
   _Mess += _Sygn;
   _Mess += String("\n Nr KUTa z accessa: ") +  Source->FieldByName("Nr KUTa")->AsString;
   _Mess += String("\t Nr harm: ") +  Source->FieldByName("nr harm")->AsString;
   _Mess += "\nCzy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  if(Source->RecNo == Source->RecordCount) m_MagazynSDB->close();
  */
 }
//---------------------------------------------------------------------------
void ZlecMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 String  _NrKuta( progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUTa")->AsString,false,_KodWydz));
 Dest->ParamByName("SYGN_ZLECENIA")->AsString  = _NrKuta;
  setKom(Dest,Source);
 int _NrMag = Source->FieldByName("Nr kut")->AsInteger;
 int _Lp    = Source->FieldByName("Lp")->AsInteger;

}
//---------------------------------------------------------------------------

