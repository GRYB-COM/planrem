//---------------------------------------------------------------------------
#pragma hdrstop
#include "OddzMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String OddzMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_ODDZIALY WHERE KOD=:KOD ");
}
//---------------------------------------------------------------------------
String OddzMover::getInsRecSQL(void)
{
 return String("INSERT INTO PR_ODDZIALY(ID_ODDZIALU,KOD,NAZWA) VALUES(GEN_ID(PR_ODDZIALY_GEN,1),:KOD,' ')");
}
//---------------------------------------------------------------------------
String OddzMover::getUpdRecSQL(void)
{
 return String("UPDATE PR_ODDZIALY SET KOD= :KOD WHERE KOD =:OLD_KOD");
}
//---------------------------------------------------------------------------
String OddzMover::getLabel(TDataSet* Source)
{
 return String("Oddzia³: ") + Source->FieldByName("Oddzia³")->AsString;
}
//---------------------------------------------------------------------------
void OddzMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
  TParam * _P = Dest->FindParam("OLD_KOD");
 if(_P)
 {
  sgda::ParamFacade(_P).AsString = Source->FieldByName("Oddzia³")->AsString;

 }
 sgda::ParamFacade(Dest->ParamByName("KOD")).AsString = Source->FieldByName("Oddzia³")->AsString;
}
//---------------------------------------------------------------------------
void OddzMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 sgda::ParamFacade(Dest->ParamByName("KOD")).AsString = Source->FieldByName("Oddzia³")->AsString;
}
//---------------------------------------------------------------------------

