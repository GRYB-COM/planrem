//---------------------------------------------------------------------------
#pragma hdrstop
#include "WydzMover.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String WydzMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_WYDZIALY WHERE KOD=:KOD");
}
//---------------------------------------------------------------------------
String WydzMover::getInsRecSQL(void)
{
 return String("INSERT INTO PR_WYDZIALY(ID_WYDZIALU,KOD,NAZWA) VALUES(GEN_ID(PR_WYDZIALY_GEN,1),:KOD,:NAZWA)");
}
//---------------------------------------------------------------------------
String WydzMover::getUpdRecSQL(void)
{
 return String("UPDATE PR_WYDZIALY SET NAZWA = :NAZWA WHERE KOD= :KOD");
}
//---------------------------------------------------------------------------
String WydzMover::getLabel(TDataSet* Source)
{
 return String("S�ownik wydzia��w - wydzia�: ")+ Source->FieldByName("Wydzia�")->AsAnsiString;
}
//---------------------------------------------------------------------------
void WydzMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 Dest->ParamByName("NAZWA")->AsAnsiString = Source->FieldByName("Nazwa pe�na")->AsAnsiString;
}
//---------------------------------------------------------------------------
void WydzMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 Dest->ParamByName("KOD")->AsAnsiString = Source->FieldByName("Wydzia�")->AsAnsiString;
}
//---------------------------------------------------------------------------

