//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "StSprzWybFRM.h"
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
__fastcall T_StSprzWybFRM::T_StSprzWybFRM(TComponent* Owner)
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
__fastcall T_StSprzWybFRM::~T_StSprzWybFRM(void)
{
 delete m_WarSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------

void __fastcall T_StSprzWybFRM::FormShow(TObject *Sender)
{
 m_WarSDB->open();
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 6;
 m_WarCB->KeyValue      = -9999;
 m_WarCB->KeyValue      = m_Ini->ReadIniInteger("ZESTAWIENIA - Stan sprzêtu", "Warsztat", -1);
 m_DataDoDTP->DateTime  = m_Ini->ReadIniDateTime("ZESTAWIENIA - Stan sprzêtu", "DataDo", Date());
}
//---------------------------------------------------------------------------

void __fastcall T_StSprzWybFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_Ini->WriteIniInteger("ZESTAWIENIA - Stan sprzêtu", "Warsztat", m_WarCB->KeyValue.IsNull() ? -1 : m_WarCB->KeyValue);
 m_Ini->WriteIniDateTime("ZESTAWIENIA - Stan sprzêtu", "DataDo", m_DataDoDTP->DateTime);
 m_WarSDB->close();

}
//---------------------------------------------------------------------------


