//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "SlPracFRM.h"
#include "MANAGER\queries.h"
#include "MANAGER\stream_db.h"
#include "SlPracEdFRM.h"
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "SlEditFRM"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlPracFRM::T_SlPracFRM(TComponent* Owner)
	: T_SlEditFRM(Owner)
{
 m_PracEdFRM = new T_SlPracEdFRM(NULL);
 m_PracEdFRM->m_DS->DataSet = m_SDB->getClient();
 m_EditFRM = m_PracEdFRM;
 m_WarSDB = new mng::StreamDB();
 m_WarSDB->setQuery("SELECT * FROM PR_KOMORKI ORDER BY KOD ");
 m_WarDS->DataSet = m_WarSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_SlPracFRM::~T_SlPracFRM(void)
{
 delete m_PracEdFRM;
 delete m_WarSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracFRM::onShow(void)
{
 jbutils::TMyIni _Ini;
 m_WarCB->KeyValue = -77;
 m_WarCB->KeyValue = _Ini.ReadIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", 1 );
 mng::Query _Q("PR_OSOBY", " *" );
 _Q.setOrderList(" NAZWISKO,IMIE ");
 m_SDB->setQuery(_Q);
 m_WarSDB->open();
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 6;
 m_WarCBCloseUp(NULL);

}
//---------------------------------------------------------------------------
void __fastcall T_SlPracFRM::onClose(void)
{
 jbutils::TMyIni _Ini;
 if(!m_WarCB->KeyValue.IsNull())
 {
  _Ini.WriteIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", m_WarCB->KeyValue);
 }
 m_WarSDB->close();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracFRM::m_WarCBCloseUp(TObject *Sender)
{
 m_SDB->setFiltered(false);
 if(!m_WarCB->KeyValue.IsNull())
 {
  AnsiString _Filtr( " ID_KOMORKI = ");
  _Filtr += m_WarCB->KeyValue;
  m_SDB->setFilter(_Filtr);
  m_SDB->setFiltered(true);
  jbutils::TMyIni _Ini;
  _Ini.WriteIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", m_WarCB->KeyValue);
 }
}
//---------------------------------------------------------------------------


