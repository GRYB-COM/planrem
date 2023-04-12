//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "PlanKwartZadWybFRM.h"
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
__fastcall T_PlanKwartZadWybFRM::T_PlanKwartZadWybFRM(TComponent* Owner)
	: T_FCUSTWYB(Owner)
{

 AnsiString _SQL="select -1 AS ID_KOMORKI, -1 AS ID_WYDZIALU, '0/0' AS KOD, 'Wszystkie warsztaty' AS NAZWA, COUNT(*) as COUNTER   from pr_komorki ko  UNION ALL \
select ko.ID_KOMORKI, ko.ID_WYDZIALU, ko.KOD, ko.NAZWA, 1 as COUNTER   from pr_komorki ko   where ko.WARSZTAT='T'  and kod <>'0/0' ";

 m_WarSDB = new mng::StreamDB();
 m_WarSDB->setQuery(_SQL);
 m_WarSDB->getClient()->IndexFieldNames = "KOD";
 m_WarDS->DataSet = m_WarSDB->getClient();

 m_Ini = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
__fastcall T_PlanKwartZadWybFRM::~T_PlanKwartZadWybFRM(void)
{
 delete m_WarSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------

void __fastcall T_PlanKwartZadWybFRM::FormShow(TObject *Sender)
{
 m_WarSDB->open();
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 6;
 m_RokED->Text          = m_Ini->ReadIniInteger("ZESTAWIENIA - Plan kwartalny", "ROK", CurrentYear());
 m_WarCB->KeyValue      = -9999;
 m_WarCB->KeyValue      = m_Ini->ReadIniInteger("ZESTAWIENIA - Plan kwartalny", "Warsztat", -1);
 m_MiesOdCB->ItemIndex  = m_Ini->ReadIniInteger("ZESTAWIENIA - Plan kwartalny", "Miesi¹c od", 1)-1;
 m_MiesDoCB->ItemIndex  = m_Ini->ReadIniInteger("ZESTAWIENIA - Plan kwartalny", "Miesi¹c do", 12)-1;
}
//---------------------------------------------------------------------------

void __fastcall T_PlanKwartZadWybFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_WarSDB->close();
 m_Ini->WriteIniInteger("ZESTAWIENIA - Plan kwartalny", "ROK", m_RokED->Text.ToIntDef(CurrentYear()));
 m_Ini->WriteIniInteger("ZESTAWIENIA - Plan kwartalny", "Warsztat", m_WarCB->KeyValue.IsNull() ? -1 : m_WarCB->KeyValue);
 m_Ini->WriteIniInteger("ZESTAWIENIA - Plan kwartalny", "Miesi¹c od", m_MiesOdCB->ItemIndex +1);
 m_Ini->WriteIniInteger("ZESTAWIENIA - Plan kwartalny", "Miesi¹c do", m_MiesDoCB->ItemIndex +1);

}
//---------------------------------------------------------------------------


void __fastcall T_PlanKwartZadWybFRM::m_MiesOdCBCloseUp(TObject *Sender)
{
 m_MiesDoCB->ItemIndex = m_MiesDoCB->ItemIndex + 3;
}
//---------------------------------------------------------------------------

