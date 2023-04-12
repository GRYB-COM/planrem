//---------------------------------------------------------------------------
 #include <vcl.h>
#pragma hdrstop
 #include "SlPracEdFRM.h"
 #include "MANAGER\stream_db.h"
 #include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_SlPracEdFRM::T_SlPracEdFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_WarSDB = new mng::StreamDB();
 m_StanSDB = new mng::StreamDB();
 m_StopSDB = new mng::StreamDB();
 m_WarDS->DataSet  = m_WarSDB->getClient();
 m_StanDS->DataSet = m_StanSDB->getClient();
 m_StopDS->DataSet = m_StopSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_SlPracEdFRM::~T_SlPracEdFRM(void)
{
 delete m_WarSDB;
 delete m_StanSDB;
 delete m_StopSDB;
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracEdFRM::FormShow(TObject *Sender)
{
 jbutils::TMyIni _Ini;
 m_WarSDB->open("SELECT * FROM PR_KOMORKI");
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 5;
 m_StanSDB->open("SELECT * FROM PR_STANOWISKA");
 m_StopSDB->open("SELECT * FROM PR_STOPNIE");
 if(m_DS->DataSet->State == dsInsert)
 {
  m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger       = -99999;
  m_DS->DataSet->FieldByName("ID_STANOWISKA")->AsInteger  = 1;
  m_DS->DataSet->FieldByName("RBH_MIES")->AsFloat         = 180;
  m_DS->DataSet->FieldByName("ID_KOMORKI")->AsInteger   = _Ini.ReadIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", 1 );
 }
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracEdFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_DS->DataSet->Cancel();
 m_WarSDB->close();
 m_StanSDB->close();
 m_StopSDB->close();
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracEdFRM::m_SaveBBClick(TObject *Sender)
{
 m_DS->DataSet->Post();
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracEdFRM::m_CancelBBClick(TObject *Sender)
{
 m_DS->DataSet->Cancel();
 Close();
}
//---------------------------------------------------------------------------


