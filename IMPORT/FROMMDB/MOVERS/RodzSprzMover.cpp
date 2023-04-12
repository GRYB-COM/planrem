//---------------------------------------------------------------------------
#pragma hdrstop
#include "RodzSprzMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
using namespace importmdb;
String RodzSprzMover::getIsRecSQL(void)
{
 return String("SELECT NAZWA FROM PR_RODZAJE_SPRZETU WHERE NAZWA = :NAZWA ");
}
//---------------------------------------------------------------------------
String RodzSprzMover::getInsRecSQL(void)
{
  String _Res("INSERT INTO PR_RODZAJE_SPRZETU(ID_RODZ_SPRZ,ID_GR_SPRZ,NAZWA) ");
		 _Res += String(" VALUES(GEN_ID(PR_GRUPY_SPRZETU_GEN,1), ");
		 _Res += String("( SELECT MIN(ID_GR_SPRZ) FROM PR_GRUPY_SPRZETU WHERE NAZWA = :NAZ_GRUPY), ");
		 _Res += String(" :NAZWA) ");
   return _Res;
}
//---------------------------------------------------------------------------
String RodzSprzMover::getUpdRecSQL(void)
{
  String _Res("UPDATE  PR_RODZAJE_SPRZETU  ");
		 _Res += String("SET ID_GR_SPRZ = (SELECT MIN(ID_GR_SPRZ) FROM PR_GRUPY_SPRZETU WHERE NAZWA = :NAZ_GRUPY) ");
		 _Res += String("WHERE NAZWA = :NAZWA ");

 return _Res;
}
//---------------------------------------------------------------------------
String RodzSprzMover::getLabel(TDataSet* Source)
{
 return Source->FieldByName("Rodzaj sprzêtu")->AsAnsiString;
}
//---------------------------------------------------------------------------
void   RodzSprzMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 sgda::ParamFacade(Dest->ParamByName("NAZ_GRUPY")).AsString = Source->FieldByName("Grupa sprzêtu")->AsAnsiString;
}
//---------------------------------------------------------------------------
void   RodzSprzMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 sgda::ParamFacade(Dest->ParamByName("NAZWA")).AsString = Source->FieldByName("Rodzaj sprzêtu")->AsAnsiString;
}
//---------------------------------------------------------------------------

