//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlZwolnieniaEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlZwolnieniaEditFRM::T_SlZwolnieniaEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_miesSDB = new mng::StreamDB();
  m_slzwSDB  = new mng::StreamDB();

  m_miesSDB->open("SELECT * FROM PR_MIESIACE ORDER BY NR_MIES");
  m_slzwSDB->open("SELECT * FROM PR_SLOW_ZW ORDER BY KOD, NAZWA");

  m_miesDS->DataSet = m_miesSDB->getClient();
  m_zwDS->DataSet  = m_slzwSDB->getClient();

  m_slzwSDB->fieldByName("KOD")->DisplayWidth = 5;
}
//---------------------------------------------------------------------------
__fastcall T_SlZwolnieniaEditFRM::~T_SlZwolnieniaEditFRM()
{
  delete m_miesSDB;
  delete m_slzwSDB;
}
//---------------------------------------------------------------------------

