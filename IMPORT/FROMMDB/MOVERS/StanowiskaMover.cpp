//---------------------------------------------------------------------------
#pragma hdrstop
#include "StanowiskaMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String StanowiskaMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_STANOWISKA WHERE NAZWA= :NAZWA");

}
//---------------------------------------------------------------------------
String StanowiskaMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_STANOWISKA(NAZWA,KOD) ");
 _Res += "VALUES( :NAZWA, :KOD) ";
 return _Res;
}
//---------------------------------------------------------------------------
String StanowiskaMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_STANOWISKA SET ");
 _Res += "KOD = :KOD  WHERE NAZWA = :NAZWA";
 return _Res;
}
//---------------------------------------------------------------------------
String StanowiskaMover::getLabel(TDataSet* Source)
{
 return Source->FieldByName("Stanowisko")->AsString;;
}
//---------------------------------------------------------------------------
void StanowiskaMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
  AnsiString _St(Source->FieldByName("Stanowisko")->AsAnsiString);
  setKeyPars(Dest,Source);
  Dest->ParamByName("KOD")->AsString = _St.SubString(1, 2);
}
//---------------------------------------------------------------------------
void StanowiskaMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
  AnsiString _St(Source->FieldByName("Stanowisko")->AsAnsiString);
  Dest->ParamByName("NAZWA")->AsString = _St.SubString(4, _St.Length());
}
//---------------------------------------------------------------------------

