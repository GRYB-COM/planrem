//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprzMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
#include "MANAGER\query_db.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String SprzMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_SPRZET WHERE NAZWA = :NAZWA");
}
//---------------------------------------------------------------------------
String SprzMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_SPRZET(ID_SPRZETU,NAZWA,ID_GR_SPRZ,ID_RODZ_SPRZ,ID_KOMORKI,INDEKS_MAT) VALUES( ");
 _Res += " GEN_ID(PR_SPRZET_GEN,1), :NAZWA, ";
 _Res += "(SELECT MIN(ID_GR_SPRZ) FROM PR_GRUPY_SPRZETU WHERE NAZWA = :GRUPA_SPRZ), ";
 _Res += "(SELECT MIN(ID_RODZ_SPRZ) FROM PR_RODZAJE_SPRZETU WHERE NAZWA = :RODZAJ_SPRZ), ";
 _Res += "(SELECT MIN(ID_KOMORKI) FROM PR_KOMORKI WHERE KOD = :WARSZTAT), :INDEKS_MAT ) ";
 return _Res;
}
//---------------------------------------------------------------------------
String SprzMover::getUpdRecSQL(void)
{
 String _Res;/*
 ("UPDATE PR_SPRZET SET ");
 _Res += "ID_GR_SPRZ   =  (SELECT MIN(ID_GR_SPRZ) FROM PR_GRUPY_SPRZETU WHERE NAZWA = :GRUPA_SPRZ), ";
 _Res += "ID_RODZ_SPRZ =  (SELECT MIN(ID_RODZ_SPRZ) FROM PR_RODZAJE_SPRZETU WHERE NAZWA = :RODZAJ_SPRZ), ";
 _Res += "ID_KOMORKI =  (SELECT MIN(ID_KOMORKI) FROM PR_KOMORKI WHERE KOD = :WARSZTAT),  INDEKS_MAT = :INDEKS_MAT ";
 _Res += " WHERE  NAZWA = :NAZWA ";*/
 return _Res;
}
//---------------------------------------------------------------------------
String SprzMover::getLabel(TDataSet* Source)
{
 String _Res("S³ownik sprzêtu ");
 _Res += Source->FieldByName("Nazwa sprzêtu")->AsString;
 return _Res;
}
//---------------------------------------------------------------------------
void SprzMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 sgda::ParamFacade(Dest->ParamByName("GRUPA_SPRZ")).AsString  = Source->FieldByName("Grupa sprzêtu")->AsString;
 sgda::ParamFacade(Dest->ParamByName("RODZAJ_SPRZ")).AsString = Source->FieldByName("Rodzaj sprzêtu")->AsString;
 sgda::ParamFacade(Dest->ParamByName("WARSZTAT")).AsString    = Source->FieldByName("Warsztat wiod¹cy")->AsString;
 if(Source->FieldByName("indeks JIM")->AsString.Trim().IsEmpty() )
 {
  mng::QueryDB _Q("SELECT INDEKS_MAT FROM PR_SPRZET WHERE NAZWA = :NAZWA");
  _Q.paramByName("NAZWA")->AsString = Source->FieldByName("Nazwa sprzêtu")->AsString;
  _Q.open();
  if(!_Q.isEmpty() )
  {
   sgda::ParamFacade(Dest->ParamByName("INDEKS_MAT")).AsString = _Q.fieldByName("INDEKS_MAT")->AsString;
  }
 }
 else
 {
  sgda::ParamFacade(Dest->ParamByName("INDEKS_MAT")).AsString  = Source->FieldByName("indeks JIM")->AsString;
 }

}
//---------------------------------------------------------------------------
void SprzMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 sgda::ParamFacade(Dest->ParamByName("NAZWA")).AsString = Source->FieldByName("Nazwa sprzêtu")->AsString;
}
//---------------------------------------------------------------------------

