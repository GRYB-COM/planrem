//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZlecRbhMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
#include <DateUtils.hpp>
#include "COMMON\Tools.h"
#include "MANAGER\query_db.h"
#include "KomorkiDICT.h"
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
ZlecRbhMover::ZlecRbhMover(void)
{
 String _SQL("\
  SELECT Z.* FROM PR_ZLECENIA Z INNER JOIN PR_KOMORKI K ON K.ID_KOMORKI = Z.ID_KOMORKI \
  WHERE SYGN_ZLECENIA = :SYGN_ZLECENIA AND K.KOD =:KOD \
 ");
 m_ZlecQDB = new mng::QueryDB(_SQL);
}
//---------------------------------------------------------------------------
ZlecRbhMover::~ZlecRbhMover(void)
{
 delete m_ZlecQDB;
}
//---------------------------------------------------------------------------
String ZlecRbhMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_ZLECENIA_RBH WHERE ROK = :ROK AND ID_ZLECENIA = :ID_ZLECENIA AND ID_KOMORKI = :ID_KOMORKI AND MIESIAC = :MIESIAC");
}
//---------------------------------------------------------------------------
String ZlecRbhMover::getInsRecSQL(void)
{
 String _Res("INSERT INTO PR_ZLECENIA_RBH(ID_ZLECENIA_RBH,ID_ZLECENIA, ID_KOMORKI, ROK,  LICZBA_RBH,ILOSC,MIESIAC) ");
 _Res += "VALUES( GEN_ID(PR_ZLECENIA_RBH_GEN,1), ";
 _Res += ":ID_ZLECENIA, ";
 _Res += ":ID_KOMORKI,  ";
 _Res += ":ROK, :LICZBA_RBH, :ILOSC, :MIESIAC) ";
 return _Res;
}
//---------------------------------------------------------------------------
String ZlecRbhMover::getUpdRecSQL(void)
{
 String _Res("UPDATE PR_ZLECENIA_RBH SET ILOSC = :ILOSC, LICZBA_RBH = :LICZBA_RBH \
WHERE ROK = :ROK AND ID_KOMORKI = :ID_KOMORKI AND ID_ZLECENIA = :ID_ZLECENIA AND MIESIAC = :MIESIAC ");
 return _Res;
}
//---------------------------------------------------------------------------
String ZlecRbhMover::getLabel(TDataSet* Source)
{
 String _Res("RBH z Karty - KUT nr: ");
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 _Res += progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUT")->AsString,false,_KodWydz);
 return _Res;
}
//---------------------------------------------------------------------------
void ZlecRbhMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 setKeyPars(Dest,Source);
 Dest->ParamByName("LICZBA_RBH")->AsFloat  = Source->FieldByName("Iloœæ przepracowanych rbh")->AsFloat;
 Dest->ParamByName("ILOSC")->AsFloat       = Source->FieldByName("iloœæ wyremontowanych")->AsFloat;

}
//---------------------------------------------------------------------------
void ZlecRbhMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
 String _KodWydz(dict::KomorkiDICT::instance().getKodWydzialu(Source->FieldByName("ID_WYDZIALU_DEF")->AsInteger,true));
 m_ZlecQDB->paramByName("SYGN_ZLECENIA")->AsString = progcommon::Tools::prepareNewSygnKUT(Source->FieldByName("Nr KUT")->AsString,false,_KodWydz);
 m_ZlecQDB->paramByName("KOD")->AsString           = Source->FieldByName("Warsztat")->AsString;
 m_ZlecQDB->open();
 if(m_ZlecQDB->fieldByName("ROK")->AsInteger >0)
 {
  Dest->ParamByName("ROK")->AsInteger               = m_ZlecQDB->fieldByName("ROK")->AsInteger;
  Dest->ParamByName("ID_ZLECENIA")->AsInteger       = m_ZlecQDB->fieldByName("ID_ZLECENIA")->AsInteger;
  Dest->ParamByName("ID_KOMORKI")->AsInteger        = m_ZlecQDB->fieldByName("ID_KOMORKI")->AsInteger;
  Dest->ParamByName("MIESIAC")->AsInteger           = MonthOf(Source->FieldByName("Data wpisu")->AsDateTime);
 }
 else
 {
  AnsiString _Mess("Nie znaleziono KUTa o numerze: ");
  _Mess += m_ZlecQDB->paramByName("SYGN_ZLECENIA")->AsString;
  _Mess += String("\n Nr KUTa z accessa: ") +  Source->FieldByName("Nr KUT")->AsString;
  _Mess += String("\n Kod warsztatu z accessa: ") +  Source->FieldByName("Warsztat")->AsString;
  _Mess += "\nCzy kontynuowaæ przenoszenie danych?";
  if(mng::MessageDialog::critical(_Mess,"B£¥D",MB_YESNO) == IDNO)
  {
   Source->Last();
   Source->Next();
  }
 }
 m_ZlecQDB->close();

}
//---------------------------------------------------------------------------

