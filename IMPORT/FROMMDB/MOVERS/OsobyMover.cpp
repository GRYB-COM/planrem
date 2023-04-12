//---------------------------------------------------------------------------
#pragma hdrstop
#include "OsobyMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
 using namespace importmdb;
//---------------------------------------------------------------------------
String OsobyMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_OSOBY WHERE IMIE= :IMIE AND NAZWISKO = :NAZWISKO");

}
//---------------------------------------------------------------------------
String OsobyMover::getInsRecSQL(void)
{

 String _Res("INSERT INTO PR_OSOBY(ID_OSOBY,IMIE, NAZWISKO,ID_STANOWISKA,ID_KOMORKI,ID_STOPNIA,ETAT_PR,ETAT_NPR,KADRA) ");
 _Res += "VALUES(GEN_ID(PR_OSOBY_GEN,1),:IMIE, :NAZWISKO, \
 (SELECT MIN(ID_STANOWISKA) FROM PR_STANOWISKA WHERE UPPER(NAZWA) =UPPER(:STANOWISKO) ) , \
 (SELECT MIN(ID_KOMORKI) FROM PR_KOMORKI WHERE KOD  = :KOD_KOM),  \
 (SELECT MIN(ID_STOPNIA) FROM PR_STOPNIE WHERE NAZWA= :NAZWA_ST), :ETAT_PR, :ETAT_NPR, :KADRA) ";
 return _Res;
}
//---------------------------------------------------------------------------
String OsobyMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_OSOBY SET \
  ID_STANOWISKA = (SELECT MIN(ID_STANOWISKA) FROM PR_STANOWISKA WHERE UPPER(NAZWA) =UPPER(:STANOWISKO) ) , \
  ID_KOMORKI = (SELECT MIN(ID_KOMORKI) FROM PR_KOMORKI WHERE KOD  = :KOD_KOM),  \
  ID_STOPNIA = (SELECT MIN(ID_STOPNIA) FROM PR_STOPNIE WHERE UPPER(NAZWA)= UPPER(:NAZWA_ST)), ETAT_PR = :ETAT_PR,  \
  ETAT_NPR = :ETAT_NPR, KADRA =:KADRA \
  WHERE  IMIE= :IMIE AND NAZWISKO = :NAZWISKO");
 return _Res;
}
//---------------------------------------------------------------------------
String OsobyMover::getLabel(TDataSet* Source)
{
 return Source->FieldByName("imiê")->AsString + String(" ") +  Source->FieldByName("nazwisko")->AsString;
}
//---------------------------------------------------------------------------
void OsobyMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
  Dest->ParamByName("IMIE")->AsAnsiString     =  Source->FieldByName("imiê")->AsAnsiString;
  Dest->ParamByName("NAZWISKO")->AsAnsiString =  Source->FieldByName("nazwisko")->AsAnsiString;
}
//---------------------------------------------------------------------------
void OsobyMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
  setKeyPars(Dest,Source);
  String _St(Source->FieldByName("STANOWISKO")->AsString);
  Dest->ParamByName("KOD_KOM")->AsString    = Source->FieldByName("Symbol komórki")->AsString;
  Dest->ParamByName("STANOWISKO")->AsString = _St.SubString(4, _St.Length());
  Dest->ParamByName("NAZWA_ST")->AsString   = Source->FieldByName("STOPIEÑ")->AsString;
  Dest->ParamByName("ETAT_PR")->AsFloat     = Source->FieldByName("kpr")->AsFloat + Source->FieldByName("cpr")->AsFloat;
  Dest->ParamByName("ETAT_NPR")->AsFloat    = Source->FieldByName("knpr")->AsFloat + Source->FieldByName("cnpr")->AsFloat;
  Dest->ParamByName("KADRA")->AsString      = Source->FieldByName("K/C")->AsString;

}
//---------------------------------------------------------------------------

