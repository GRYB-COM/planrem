//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSprzetEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSprzetEditFRM::T_SlSprzetEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_komSDB = new mng::StreamDB();
  m_gspSDB = new mng::StreamDB();
  m_rspSDB = new mng::StreamDB();

  m_komSDB->open("SELECT * FROM PR_KOMORKI WHERE WARSZTAT = 'T' AND KOD <> '0/0' AND KOD <> '-1/-1' ORDER BY KOD");
  m_gspSDB->open("SELECT * FROM PR_GRUPY_SPRZETU WHERE ID_GR_SPRZ >= 0 ORDER BY NAZWA");
  m_rspSDB->open("SELECT * FROM PR_RODZAJE_SPRZETU WHERE ID_RODZ_SPRZ >= 0 ORDER BY NAZWA");

  m_komDS->DataSet = m_komSDB->getClient();
  m_gspDS->DataSet = m_gspSDB->getClient();
  m_rspDS->DataSet = m_rspSDB->getClient();

  m_komID = -1;
  m_gspID = -1;
  m_rspID = -1;
}
//---------------------------------------------------------------------------
__fastcall T_SlSprzetEditFRM::~T_SlSprzetEditFRM()
{
  delete m_komSDB;
  delete m_rspSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::setEnabledBtn(bool enbl)
{
  m_CancelBB->Enabled = enbl;
  m_SaveBB->Enabled   = enbl;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::setKomID(int val)
{
  m_komID = val;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::setGspID(int val)
{
  m_gspID = val;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::setRspID(int val)
{
  m_rspID = val;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::addRecord(TDataSource *ds, AnsiString keyField)
{
  Caption = "Nowy wpis";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Append();

  m_DS->DataSet->FieldByName(keyField)->AsInteger = -1*rand();

  if (m_komID >= 0)
  {
    m_DS->DataSet->FieldByName("ID_KOMORKI")->AsInteger = m_komID;
  }

  if (m_gspID >= 0)
  {
    m_DS->DataSet->FieldByName("ID_GR_SPRZ")->AsInteger = m_gspID;

    m_rspSDB->setFilter("ID_GR_SPRZ=" + IntToStr(m_gspID));
    m_rspSDB->setFiltered(true);
  }
  else
  {
    m_rspSDB->setFilter("ID_GR_SPRZ = -1");
    m_rspSDB->setFiltered(true);
  }

  if (m_rspID >= 0)
  {
    m_DS->DataSet->FieldByName("ID_RODZ_SPRZ")->AsInteger = m_rspID;
  }

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::setFilterRspSDB(const AnsiString &filter)
{
  m_rspSDB->setFilter(filter);
  m_rspSDB->setFiltered(true);
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::m_komCBCloseUp(TObject *Sender)
{
  Sleep(200);
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::m_gspCBCloseUp(TObject *Sender)
{
  Sleep(200);

  m_rspSDB->setFiltered(false);

  int idGr = m_gspSDB->fieldByName("ID_GR_SPRZ")->AsInteger;

  if(idGr >= 0)
  {
	m_rspSDB->setFilter("ID_GR_SPRZ=" + IntToStr(idGr));
	m_rspSDB->setFiltered(true);
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetEditFRM::m_rspCBCloseUp(TObject *Sender)
{
  Sleep(200);
}
//---------------------------------------------------------------------------


