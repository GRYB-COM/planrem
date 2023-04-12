//---------------------------------------------------------------------------
#pragma hdrstop
#include "GrSprzMover.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String GrSprzMover::getIsRecSQL(void)
{
 return String("SELECT NAZWA FROM PR_GRUPY_SPRZETU WHERE NAZWA = :NAZWA ");
}
//---------------------------------------------------------------------------
String GrSprzMover::getInsRecSQL(void)
{
 return String("INSERT INTO PR_GRUPY_SPRZETU(ID_GR_SPRZ,NAZWA) VALUES(GEN_ID(PR_GRUPY_SPRZETU_GEN,1), :NAZWA) ");
}
//---------------------------------------------------------------------------
String GrSprzMover::getUpdRecSQL(void)
{
 return String();
}
//---------------------------------------------------------------------------
String GrSprzMover::getLabel(TDataSet* Source)
{
 return String("Grypy sprzêtu - ") + Source->FieldByName("Grupa sprzêtu")->AsString;
}

//---------------------------------------------------------------------------
void   GrSprzMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
}
//---------------------------------------------------------------------------
void   GrSprzMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 Dest->ParamByName("NAZWA")->AsString = Source->FieldByName("Grupa sprzêtu")->AsString;
}
//---------------------------------------------------------------------------

