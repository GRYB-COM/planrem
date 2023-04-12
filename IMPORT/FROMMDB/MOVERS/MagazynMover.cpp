//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagazynMover.h"
#include "globfunc.h"
#include "COMMON\Tools.h"
#include <dateutils.hpp>
#include "MagID.h"
#include "MoversTools.h"
#include <dialogs.hpp>
#include "MANAGER\stream_db.h"
#include "MANAGER\message_dlg.h"
#include "KomorkiDICT.h"
#include "MANAGER\query_db.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
MagazynMover::MagazynMover(void)
{
 m_HarmSDB = new mng::StreamDB();
 m_HarmSDB->setQuery("SELECT * FROM PR_HARMONOGRAM");

 m_KomSDB = new mng::StreamDB();
 m_KomSDB->setQuery("SELECT * FROM PR_KOMORKI WHERE WARSZTAT ='T' ");

}
MagazynMover::~MagazynMover(void)
{
 delete m_HarmSDB;
 delete m_KomSDB;
}
//---------------------------------------------------------------------------
String MagazynMover::getIsRecSQL(void)
{
 return "SELECT M.* FROM PR_MAGAZYN M INNER JOIN PR_KOMORKI W ON(W.ID_KOMORKI = M.ID_KOMORKI ) \
 WHERE M.SYGN_MAG = :SYGN_MAG AND W.KOD = :WARSZTAT";
}
//---------------------------------------------------------------------------
String MagazynMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_MAGAZYN(ROK,ID_MAG,ID_HARM,DEPOZYT,ID_KOMORKI,SYGN_MAG,ILOSC,PODSTAWA,DATA_PRZEKAZ,UWAGI,ID_REMONTU,ID_SPRZETU, \
			  PROT_PRZEKAZ,ID_JEDNOSTKI,STATUS,PROT_PRZYJ,DATA_PRZYJ,NR_REJ,NR_HARM,KOD_WARSZTATU,GLOWNY_KUT,NR_MAG, DATA_PROP_ZAK, DATA_ZAK)");
 _Res += " VALUES(:ROK, GEN_ID(PR_MAGAZYN_GEN,1), ";
 _Res += ":ID_HARM, ";
 _Res += " :DEPOZYT,";//" CASE WHEN :P_N ='D' THEN 'T' ELSE 'N' END, ";
 _Res += " (SELECT  MIN(W.ID_KOMORKI) FROM PR_KOMORKI W WHERE W.KOD =:WARSZTAT), ";
 _Res += " :SYGN_MAG, :ILOSC, :PODSTAWA, :DATA_PRZEKAZ, :UWAGI, ";
 _Res += " (SELECT MIN(R.ID_REMONTU) FROM PR_REMONTY R WHERE R.KOD_REM = :RODZAJ_REM), ";
 _Res += " (SELECT MIN(S.ID_SPRZETU) FROM PR_SPRZET S WHERE S.NAZWA = :NAZWA_SPRZ), ";
 _Res += " :PROT_PRZEKAZ, ";
 _Res += " (SELECT MIN(J.ID_JEDNOSTKI) FROM PR_JEDNOSTKI J WHERE  J.JW = :JW), ";
 _Res += " 'N',:PROT_PRZYJ,:DATA_PRZYJ,:NR_REJ,:ID_HARM, :WARSZTAT, :GLOWNY_KUT, :NR_MAG, :DATA_PROP_ZAK, :DATA_ZAK )";
 return _Res;
}
//---------------------------------------------------------------------------
String MagazynMover::getUpdRecSQL(void)
{
 String _Res("UPDATE  PR_MAGAZYN M SET ");
 _Res += " M.ID_HARM        = :ID_HARM,  ";
 _Res += " M.ROK            = :ROK,  ";
 _Res += " M.DEPOZYT        = :DEPOZYT, ";
 _Res += " M.ID_KOMORKI     = (SELECT  MIN(W.ID_KOMORKI) FROM PR_KOMORKI W WHERE W.KOD =:WARSZTAT), ";
 _Res += " M.ILOSC          = :ILOSC,M.PODSTAWA= :PODSTAWA, M.DATA_PRZEKAZ= :DATA_PRZEKAZ, M.UWAGI =:UWAGI, ";
 _Res += " M.ID_REMONTU     = (SELECT MIN(R.ID_REMONTU) FROM PR_REMONTY R WHERE R.KOD_REM = :RODZAJ_REM), ";
 _Res += " M.ID_SPRZETU     = (SELECT MIN(S.ID_SPRZETU) FROM PR_SPRZET S WHERE S.NAZWA = :NAZWA_SPRZ), ";
 _Res += " M.PROT_PRZEKAZ   = :PROT_PRZEKAZ, ";
 _Res += " M.ID_JEDNOSTKI   = (SELECT MIN(J.ID_JEDNOSTKI) FROM PR_JEDNOSTKI J WHERE  J.JW = :JW), ";
 _Res += " M.PROT_PRZYJ     = :PROT_PRZYJ, DATA_PRZYJ = :DATA_PRZYJ,NR_REJ = :NR_REJ, ";
 _Res += " NR_HARM = :ID_HARM, KOD_WARSZTATU = :WARSZTAT, GLOWNY_KUT = :GLOWNY_KUT, NR_MAG = :NR_MAG, DATA_PROP_ZAK =:DATA_PROP_ZAK, DATA_ZAK = :DATA_ZAK ";
 _Res += " WHERE M.SYGN_MAG = :SYGN_MAG AND EXISTS ( SELECT * FROM PR_KOMORKI W WHERE W.ID_KOMORKI = M.ID_KOMORKI AND W.KOD = :WARSZTAT )";
 return _Res;

}
//---------------------------------------------------------------------------
String MagazynMover::getLabel(TDataSet* Source)
{
 String _Res("Nr mag: ");
 _Res += Source->FieldByName("nr mag")->AsString;
 _Res += " Nr harm. ";
 _Res += Source->FieldByName("nr harm")->AsInteger;
 _Res += " kut: ";
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 String  _NrKuta( progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUTa")->AsString,false,_KodWydz));
 _Res += _NrKuta;
 return _Res;

}
//---------------------------------------------------------------------------
void   MagazynMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 String  _NrKuta( progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUTa")->AsString,true,_KodWydz));
 TParam * _Par;
 setKeyPars(Dest,Source);
 msg::MagID _MagID = MoversTools::makeMagID(Source);
 _Par = Dest->FindParam("ID_HARM");       if(_Par) _Par->AsInteger  = Source->FieldByName("nr harm")->AsInteger;
 _Par = Dest->FindParam("ILOSC");         if(_Par) _Par->AsFloat    = Source->FieldByName("Iloœæ")->AsFloat;
 _Par = Dest->FindParam("PODSTAWA");      if(_Par) _Par->AsString   = Source->FieldByName("Podstawa/PST")->AsString;
 _Par = Dest->FindParam("DATA_PRZEKAZ");
 if(_Par && Source->FieldByName("Data przekazania")->AsDateTime >TDateTime(0.0))
 {
  _Par->AsDateTime = Source->FieldByName("Data przekazania")->AsDateTime;
 }
 else
 {
  _Par->Clear();
 }
 _Par = Dest->FindParam("UWAGI");         if(_Par) _Par->AsString   = Source->FieldByName("UWAGI dla POW")->AsString;
 _Par = Dest->FindParam("RODZAJ_REM");    if(_Par) _Par->AsString   = Source->FieldByName("Rodzaj remontu")->AsString;
 _Par = Dest->FindParam("NAZWA_SPRZ");    if(_Par) _Par->AsString   = Source->FieldByName("Nazwa sprzêtu")->AsAnsiString;
 _Par = Dest->FindParam("PROT_PRZEKAZ");  if(_Par) _Par->AsString   = Source->FieldByName("Nr prot przek")->AsString;
 _Par = Dest->FindParam("JW");            if(_Par) _Par->AsString   = Source->FieldByName("Nr JW/ dla kogo")->AsString;
 _Par = Dest->FindParam("PROT_PRZYJ");    if(_Par) _Par->AsString   = Source->FieldByName("Nr prot przyj")->AsString;
 _Par = Dest->FindParam("DATA_PRZYJ");    if(_Par) _Par->AsDateTime = Source->FieldByName("Data dostarczenia")->AsDateTime;
 _Par = Dest->FindParam("NR_REJ");        if(_Par) _Par->AsString   = Source->FieldByName("Nr")->AsString;
 _Par = Dest->FindParam("GLOWNY_KUT");    if(_Par) _Par->AsString   = _NrKuta;
 _Par = Dest->FindParam("NR_MAG");        if(_Par) _Par->AsInteger  = Source->FieldByName("Nr kut")->AsInteger;
 _Par = Dest->FindParam("DEPOZYT");       if(_Par) _Par->AsString   = _MagID.Depozyt;
 _Par = Dest->FindParam("ROK");           if(_Par) _Par->AsInteger  = _MagID.Rok;
 _Par = Dest->FindParam("DATA_PROP_ZAK"); if(_Par) _Par->AsDateTime = Source->FieldByName("Prop termin zak")->AsDateTime;
 _Par = Dest->FindParam("DATA_ZAK");
 if(_Par && Source->FieldByName("Data zakoñczenia")->AsDateTime >TDateTime(0.0) )
 {
   _Par->AsDateTime = Source->FieldByName("Data zakoñczenia")->AsDateTime;
 }
 else
 {
  _Par->Clear();
 }
 checkHarm(Dest,Source);
 checkKom(Dest,Source);
 if(_IsIns) checkSygn(Dest,Source);
}
//---------------------------------------------------------------------------
void   MagazynMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 msg::MagID _MagID = MoversTools::makeMagID(Source);
 Dest->ParamByName("SYGN_MAG")->AsString = _MagID.getSygnMag();
 Dest->ParamByName("WARSZTAT")->AsString  = Source->FieldByName("Warsztat")->AsString;
 int _NrMag = Source->FieldByName("Nr kut")->AsInteger;
 int _Lp    = Source->FieldByName("Lp")->AsInteger;

}
//---------------------------------------------------------------------------
 void  MagazynMover::checkHarm(TParams * Dest, TDataSet* Source)
 {
  if(!m_HarmSDB->isOpen())	m_HarmSDB->open();
  int _IdHarm(Dest->ParamByName("ID_HARM")->AsInteger);
  int _Rok(Dest->ParamByName("ROK")->AsInteger);
  Variant _Vals[2];
  _Vals[0] = _Rok;
  _Vals[1] = _IdHarm;
  if(!m_HarmSDB->locate("ROK;ID_HARMONOGRAMU",VarArrayOf(_Vals, 1)))
  {
   AnsiString _Mess= AnsiString("Nie znaleziono pozycji harmonogramu nr: ") + AnsiString(_IdHarm);
   _Mess += AnsiString(" w roku: ") + AnsiString(_Rok) 	+ AnsiString(" \n");
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
 void  MagazynMover::checkKom(TParams * Dest, TDataSet* Source)
 {
  if(!m_KomSDB->isOpen())	m_KomSDB->open();
  String _KodWar(Source->FieldByName("Warsztat")->AsString);
  if(!m_KomSDB->locate("KOD",_KodWar) )
  {
   AnsiString _Mess= AnsiString("Nie znaleziono warsztatu o kodzie: ") + _KodWar;
   _Mess += "\nCzy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
 }
//---------------------------------------------------------------------------
 void  MagazynMover::checkSygn(TParams * Dest, TDataSet* Source)
 {
  mng::QueryDB _MagQDB("SELECT * FROM PR_MAGAZYN WHERE GLOWNY_KUT = :GLOWNY_KUT");
  _MagQDB.paramByName("GLOWNY_KUT")->AsString = Dest->ParamByName("GLOWNY_KUT")->AsString;
  _MagQDB.open();
  if(!_MagQDB.isEmpty() )
  {
   AnsiString _Mess= AnsiString("KUT o sygnaturze: ") +  Dest->ParamByName("GLOWNY_KUT")->AsAnsiString + AnsiString(" jest ju¿ w bazie");
   _Mess += AnsiString("\nNr KUT z accessa: ") +  Source->FieldByName("Nr KUTa")->AsString;
   _Mess += "\nCzy kontynuowaæ przenoszenie danych?";
   if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
   {
	Source->Last();
	Source->Next();
   }
  }
  _MagQDB.close();
 }
//---------------------------------------------------------------------------

