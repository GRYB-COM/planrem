//---------------------------------------------------------------------------
#pragma hdrstop
#include "KodyUslugMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String KodyUslugMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_KODY_USLUG WHERE P_N = :P_N");

}
//---------------------------------------------------------------------------
String KodyUslugMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_KODY_USLUG(ID_USLUGI,P_N,NAZ_REMONTU,NAZ_KUT) ");
 _Res += "VALUES( GEN_ID(PR_KODY_USLUG_GEN,1), :P_N, :NAZ_REMONTU, :NAZ_KUT) ";
 return _Res;
}
//---------------------------------------------------------------------------
String KodyUslugMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_KODY_USLUG SET ");
 _Res += "P_N = :P_N, NAZ_REMONTU =:NAZ_REMONTU, NAZ_KUT = :NAZ_KUT WHERE P_N = :P_N ";
 return _Res;
}
//---------------------------------------------------------------------------
String KodyUslugMover::getLabel(TDataSet* Source)
{
 return Source->FieldByName("Nazwa remontu")->AsString;;
}
//---------------------------------------------------------------------------
void KodyUslugMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 Dest->ParamByName("NAZ_REMONTU")->AsString = Source->FieldByName("Nazwa remontu")->AsString;
 Dest->ParamByName("NAZ_KUT")->AsString     = Source->FieldByName("Nazwa KUT")->AsString;
}
//---------------------------------------------------------------------------
void KodyUslugMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
  Dest->ParamByName("P_N")->AsString = Source->FieldByName("P/N")->AsString;
}
//---------------------------------------------------------------------------

