//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlDelegacjeEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlDelegacjeEditFRM::T_SlDelegacjeEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_MiesSDB = new mng::StreamDB();
  m_KomSDB  = new mng::StreamDB();

  m_MiesSDB->open("SELECT * FROM PR_MIESIACE ORDER BY NR_MIES");
  m_KomSDB->open("SELECT * FROM PR_KOMORKI WHERE KOD <> '0/0' ORDER BY KOD, NAZWA");

  m_MiesDS->DataSet = m_MiesSDB->getClient();
  m_komDS->DataSet  = m_KomSDB->getClient();

  m_KomSDB->fieldByName("KOD")->DisplayWidth = 5;
}
//---------------------------------------------------------------------------
__fastcall T_SlDelegacjeEditFRM::~T_SlDelegacjeEditFRM()
{
  delete m_MiesSDB;
  delete m_KomSDB;
}
//---------------------------------------------------------------------------

void __fastcall T_SlDelegacjeEditFRM::FormActivate(TObject *Sender)
{
 m_MiesCB->SetFocus();
}
//---------------------------------------------------------------------------

