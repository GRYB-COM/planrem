//---------------------------------------------------------------------------
#pragma hdrstop
#include "JWMover.h"
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String JWMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_JEDNOSTKI WHERE JW = :JW");
}
//---------------------------------------------------------------------------
String JWMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_JEDNOSTKI(ID_JEDNOSTKI,JW,NAZWA,NAZWA_PELNA,NR_ODDZ_GOSP,MIEJSCOWOSC,FAX) ");
 _Res += " VALUES(:ID_JEDNOSTKI,:JW,:NAZWA,:NAZWA_PELNA,:NR_ODDZ_GOSP,:MIEJSCOWOSC,:FAX) ";
 return _Res;
}
//---------------------------------------------------------------------------
String JWMover::getUpdRecSQL(void)
{
 String _Res; /*
 ("UPDATE PR_JEDNOSTKI SET JW=:JW,NAZWA=:NAZWA,NAZWA_PELNA=:NAZWA_PELNA,NR_ODDZ_GOSP=:NR_ODDZ_GOSP,MIEJSCOWOSC=:MIEJSCOWOSC,FAX=:FAX ");
 _Res += " WHERE JW = :JW ";*/
 return _Res;

}
//---------------------------------------------------------------------------
String JWMover::getLabel(TDataSet* Source)
{
 String _Res("Jednostka: ");
 _Res += Source->FieldByName("JW")->AsString;
 return _Res;

}
//---------------------------------------------------------------------------
void   JWMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{

 TParam *_P = Dest->FindParam("ID_JEDNOSTKI");
 if(_P)
 {
  sgda::ParamFacade(_P).AsInteger = -1;
 }
 sgda::ParamFacade(Dest->ParamByName("JW")).AsString            = Source->FieldByName("JW")->AsString;
 sgda::ParamFacade(Dest->ParamByName("NAZWA")).AsString         = Source->FieldByName("Nazwa")->AsString;
 sgda::ParamFacade(Dest->ParamByName("NAZWA_PELNA")).AsString   = Source->FieldByName("Nazwa pe³na")->AsString;
 sgda::ParamFacade(Dest->ParamByName("NR_ODDZ_GOSP")).AsString  = Source->FieldByName("Nr oddzia³u gospodarczego")->AsString;
 sgda::ParamFacade(Dest->ParamByName("MIEJSCOWOSC")).AsString   = Source->FieldByName("Miejscowoœæ")->AsString;
 sgda::ParamFacade(Dest->ParamByName("FAX")).AsString           = Source->FieldByName("Nr fax")->AsString;
}
//---------------------------------------------------------------------------
void   JWMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 sgda::ParamFacade(Dest->ParamByName("JW")).AsString = Source->FieldByName("JW")->AsString;
}
//---------------------------------------------------------------------------

