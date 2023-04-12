//---------------------------------------------------------------------------
#pragma hdrstop
#include "WarsztatyMover.h"
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
String WarsztatyMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_KOMORKI WHERE KOD = :KOD");
}
//---------------------------------------------------------------------------
String WarsztatyMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_KOMORKI(ID_KOMORKI,KOD,NAZWA,ID_WYDZIALU,ID_ODDZIALU,WARSZTAT) VALUES(");
		_Res +="GEN_ID(PR_KOMORKI_GEN,1), :KOD, :NAZWA,";
		_Res +=" (SELECT MIN(WY.ID_WYDZIALU) FROM PR_WYDZIALY WY WHERE WY.KOD = :KOD_WYDZ ), ";
		_Res +=" (SELECT MIN(OD.ID_ODDZIALU) FROM PR_ODDZIALY OD WHERE OD.KOD = :KOD_ODDZ ), ";
		_Res +=" :CZY_WARSZTAT) ";
  return _Res;
}
//---------------------------------------------------------------------------
String WarsztatyMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_KOMORKI SET NAZWA = :NAZWA, WARSZTAT = :CZY_WARSZTAT,  ");
		_Res +="ID_WYDZIALU = (SELECT MIN(WY.ID_WYDZIALU) FROM PR_WYDZIALY WY WHERE WY.KOD = :KOD_WYDZ ), ";
		_Res +="ID_ODDZIALU = (SELECT MIN(OD.ID_ODDZIALU) FROM PR_ODDZIALY OD WHERE OD.KOD = :KOD_ODDZ )   ";
		_Res +=" WHERE KOD= :KOD ";
  return _Res;
}
//---------------------------------------------------------------------------
String WarsztatyMover::getLabel( TDataSet* Source)
{
 String _Res("S³ownik warsztatów - warsztat: ");
		_Res +=Source->FieldByName("Warsztat")->AsString;;
  return _Res;
}
//---------------------------------------------------------------------------
void WarsztatyMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 sgda::ParamFacade(Dest->ParamByName("KOD_WYDZ")).AsString  = Source->FieldByName("Wydzia³")->AsString;
 sgda::ParamFacade(Dest->ParamByName("KOD_ODDZ")).AsString  = Source->FieldByName("Oddzia³")->AsString;
 sgda::ParamFacade(Dest->ParamByName("NAZWA")).AsString    = Source->FieldByName("Nazwa pe³na")->AsString;
 bool _CzyWar(!Source->FieldByName("Kierownik w-tu")->IsNull);
 sgda::ParamFacade(Dest->ParamByName("CZY_WARSZTAT")).AsString  = _CzyWar ? "T" : "N" ;

}
//---------------------------------------------------------------------------
void WarsztatyMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 sgda::ParamFacade(Dest->ParamByName("KOD")).AsString  = Source->FieldByName("Warsztat")->AsString;
}
//---------------------------------------------------------------------------

