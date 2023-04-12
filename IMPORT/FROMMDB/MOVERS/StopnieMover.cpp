//---------------------------------------------------------------------------
#pragma hdrstop
#include "StopnieMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String StopnieMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_STOPNIE WHERE NAZWA= Trim(:NAZWA)");

}
//---------------------------------------------------------------------------
String StopnieMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_STOPNIE(NAZWA) ");
 _Res += "VALUES( Trim(:NAZWA)) ";
 return _Res;
}
//---------------------------------------------------------------------------
String StopnieMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_STOPNIE SET ");
 _Res += "NAZWA = :NAZWA WHERE NAZWA = :NAZWA";
 return _Res;
}
//---------------------------------------------------------------------------
String StopnieMover::getLabel(TDataSet* Source)
{
 return Source->FieldByName("stopieñ")->AsString;;
}
//---------------------------------------------------------------------------
void StopnieMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
}
//---------------------------------------------------------------------------
void StopnieMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
  Dest->ParamByName("NAZWA")->AsString = Source->FieldByName("Stopieñ")->AsString.Trim();
}
//---------------------------------------------------------------------------

