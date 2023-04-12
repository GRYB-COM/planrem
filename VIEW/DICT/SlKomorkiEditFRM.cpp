//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlKomorkiEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlKomorkiEditFRM::T_SlKomorkiEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_oSDB = new mng::StreamDB();
  m_wSDB = new mng::StreamDB();

  m_oSDB->open("SELECT * FROM PR_ODDZIALY ORDER BY KOD, NAZWA");
  m_wSDB->open("SELECT * FROM PR_WYDZIALY ORDER BY KOD, NAZWA");

  m_oDS->DataSet = m_oSDB->getClient();
  m_wDS->DataSet = m_wSDB->getClient();

  m_oSDB->fieldByName("KOD")->DisplayWidth = 5;
  m_wSDB->fieldByName("KOD")->DisplayWidth = 5;
}
//---------------------------------------------------------------------------
__fastcall T_SlKomorkiEditFRM::~T_SlKomorkiEditFRM()
{
  delete m_oSDB;
  delete m_wSDB;
}
//---------------------------------------------------------------------------
