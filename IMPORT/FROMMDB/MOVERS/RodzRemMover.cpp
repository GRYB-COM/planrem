//---------------------------------------------------------------------------
#pragma hdrstop
#include "RodzRemMover.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String RodzRemMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_REMONTY WHERE KOD_REM=:KOD_REM");
}
//---------------------------------------------------------------------------
String RodzRemMover::getInsRecSQL(void)
{
 return String("INSERT INTO PR_REMONTY(ID_REMONTU,NAZWA,KOD_REM) VALUES(GEN_ID(PR_REMONTY_GEN,1),:NAZWA,:KOD_REM)");
}
//---------------------------------------------------------------------------
String RodzRemMover::getUpdRecSQL(void)
{
 return String("UPDATE PR_REMONTY SET NAZWA = :NAZWA WHERE KOD_REM= :KOD_REM");
}
//---------------------------------------------------------------------------
String RodzRemMover::getLabel(TDataSet* Source)
{
 return String("S³ownik remontów: ")+ Source->FieldByName("Rodzaj remontu")->AsAnsiString;
}
//---------------------------------------------------------------------------
void RodzRemMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 Dest->ParamByName("NAZWA")->AsAnsiString = Source->FieldByName("Rodzaj remontu")->AsAnsiString;
}
//---------------------------------------------------------------------------
void RodzRemMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 Dest->ParamByName("KOD_REM")->AsAnsiString = Source->FieldByName("Rodzaj remontu")->AsAnsiString;
}
//---------------------------------------------------------------------------

