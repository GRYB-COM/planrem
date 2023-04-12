//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSprzetRodzajeEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSprzetRodzajeEditFRM::T_SlSprzetRodzajeEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_grSDB = new mng::StreamDB();

  m_grSDB->open("SELECT * FROM PR_GRUPY_SPRZETU WHERE ID_GR_SPRZ >= 0 ORDER BY ID_GR_SPRZ");

  m_grDS->DataSet = m_grSDB->getClient();

  m_grSDB->fieldByName("ID_GR_SPRZ")->DisplayWidth = 5;
}
//---------------------------------------------------------------------------
__fastcall T_SlSprzetRodzajeEditFRM::~T_SlSprzetRodzajeEditFRM()
{
  delete m_grSDB;
}
//---------------------------------------------------------------------------

