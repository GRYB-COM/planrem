//---------------------------------------------------------------------------
 #include <vcl.h>
#pragma hdrstop
 #include "SlStanEdFRM.h"
 #include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGlowButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_SlStanEdFRM::T_SlStanEdFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_OddzSDB = new mng::StreamDB();
 m_WydzSDB = new mng::StreamDB();
 m_OddzDS->DataSet = m_OddzSDB->getClient();
 m_WydzDS->DataSet = m_WydzSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_SlStanEdFRM::~T_SlStanEdFRM(void)
{
 delete m_WydzSDB;
 delete m_OddzSDB;
}
//---------------------------------------------------------------------------

void __fastcall T_SlStanEdFRM::FormShow(TObject *Sender)
{
 m_OddzSDB->open("SELECT * FROM PR_ODDZIALY");
 m_WydzSDB->open("SELECT * FROM PR_WYDZIALY");
 if(m_DS->DataSet->State == dsInsert)
 {
  m_DS->DataSet->FieldByName("ID_KOMORKI")->AsInteger = -99999;
 }

}
//---------------------------------------------------------------------------

void __fastcall T_SlStanEdFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_DS->DataSet->Cancel();
 m_OddzSDB->close();
 m_WydzSDB->close();
}
//---------------------------------------------------------------------------

void __fastcall T_SlStanEdFRM::m_SaveBBClick(TObject *Sender)
{
 m_DS->DataSet->Post();
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_SlStanEdFRM::m_CancelBBClick(TObject *Sender)
{
 m_DS->DataSet->Cancel();
 Close();
}
//---------------------------------------------------------------------------

