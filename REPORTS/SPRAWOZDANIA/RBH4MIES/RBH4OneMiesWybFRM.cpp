//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "RBH4OneMiesWybFRM.h"
#include "MANAGER\stream_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "SysUtils.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FCSWYB"
#pragma link "PopupButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_RBH4OneMiesWybFRM::T_RBH4OneMiesWybFRM(TComponent* Owner)
	: T_FCUSTWYB(Owner)
{
 AnsiString _SQL("select distinct  -1 AS ID_WYDZIALU, ' ' AS KOD, 'Wszystkie wydzialy' AS NAZWA, count(*) AS COUNTER from pr_wydzialy union  all \
 select distinct  wy.ID_WYDZIALU, wy.KOD, wy.NAZWA, 1 as COUNTER \
 from pr_wydzialy wy inner join pr_komorki ko on  ko.ID_WYDZIALU = wy.ID_WYDZIALU  where ko.WARSZTAT ='T' ");

 m_WydzialSDB = new mng::StreamDB();
 m_WydzialSDB->setQuery(_SQL);
 m_WydzialSDB->getClient()->IndexFieldNames = "KOD";
 m_WydzialDS->DataSet = m_WydzialSDB->getClient();

 _SQL="select -1 AS ID_KOMORKI, -1 AS ID_WYDZIALU, '0/0' AS KOD, 'Wszystkie warsztaty' AS NAZWA, COUNT(*) as COUNTER   from pr_komorki ko  UNION ALL \
select ko.ID_KOMORKI, ko.ID_WYDZIALU, ko.KOD, ko.NAZWA, 1 as COUNTER   from pr_komorki ko   where ko.WARSZTAT='T'  and kod <>'0/0' ";

 m_WarSDB = new mng::StreamDB();
 m_WarSDB->setQuery(_SQL);
 m_WarSDB->getClient()->IndexFieldNames = "KOD";
 m_WarDS->DataSet = m_WarSDB->getClient();

 m_Ini = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
__fastcall T_RBH4OneMiesWybFRM::~T_RBH4OneMiesWybFRM(void)
{
 delete m_WydzialSDB;
 delete m_WarSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------

void __fastcall T_RBH4OneMiesWybFRM::FormShow(TObject *Sender)
{
 m_WydzialSDB->open();
 m_WydzialSDB->fieldByName("KOD")->DisplayWidth = 3;
 m_WarSDB->open();
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 6;
 m_RokED->Text          = m_Ini->ReadIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "ROK", CurrentYear());
 m_WydzialCB->KeyValue  = -9999;
 m_WydzialCB->KeyValue  = m_Ini->ReadIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Wydzia³", -1);
 m_WydzialCBCloseUp(m_WydzialCB);
 m_WarCB->KeyValue      = -9999;
 m_WarCB->KeyValue      = m_Ini->ReadIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Warsztat", -1);
 m_MiesOdCB->ItemIndex  = m_Ini->ReadIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Miesi¹c od", 1)-1;
 m_MiesDoCB->ItemIndex  = m_Ini->ReadIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Miesi¹c do", 12)-1;

}
//---------------------------------------------------------------------------

void __fastcall T_RBH4OneMiesWybFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
  m_WydzialSDB->close();
 m_WarSDB->close();
 m_Ini->WriteIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "ROK", m_RokED->Text.ToIntDef(CurrentYear()));
 m_Ini->WriteIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Wydzia³",  m_WydzialCB->KeyValue.IsNull() ? -1 : m_WydzialCB->KeyValue );
 m_Ini->WriteIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Warsztat", m_WarCB->KeyValue.IsNull() ? -1 : m_WarCB->KeyValue);
 m_Ini->WriteIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Miesi¹c od", m_MiesOdCB->ItemIndex +1);
 m_Ini->WriteIniInteger("ZESTAWIENIA - Rozliczenie miesiêczne godzin", "Miesi¹c do", m_MiesDoCB->ItemIndex +1);

}
//---------------------------------------------------------------------------

void __fastcall T_RBH4OneMiesWybFRM::m_WydzialCBCloseUp(TObject *Sender)
{
 if(!m_WydzialCB->KeyValue.IsNull() && m_WydzialCB->KeyValue >0)
 {
  m_WarSDB->getClient()->Filter = String("ID_WYDZIALU = -1 OR ID_WYDZIALU = ") + m_WydzialCB->KeyValue;
  m_WarSDB->getClient()->Filtered = true;
 }
 else
 {
  m_WarSDB->getClient()->Filter = "";
  m_WarSDB->getClient()->Filtered = false;
 }
 if(m_WarCB->KeyValue.IsNull()) m_WarCB->KeyValue = -1;
}
//---------------------------------------------------------------------------


