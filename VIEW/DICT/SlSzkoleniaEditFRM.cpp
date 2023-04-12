//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSzkoleniaEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSzkoleniaEditFRM::T_SlSzkoleniaEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_miesSDB = new mng::StreamDB();

  m_miesSDB->open("SELECT * FROM PR_MIESIACE ORDER BY NR_MIES");

  m_miesDS->DataSet = m_miesSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_SlSzkoleniaEditFRM::~T_SlSzkoleniaEditFRM()
{
  delete m_miesSDB;
}
//---------------------------------------------------------------------------
