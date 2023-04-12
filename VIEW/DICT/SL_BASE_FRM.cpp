//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SL_BASE_FRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\various_man.h"
#include "MANAGER\is_manager.h"
#include <sqr.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SL_BASE_FRM::T_SL_BASE_FRM(TComponent* Owner) : TForm(Owner)
{
  m_SDB = new mng::StreamDB;

  m_DS->DataSet = m_SDB->getClient();
}
//---------------------------------------------------------------------------

__fastcall T_SL_BASE_FRM::~T_SL_BASE_FRM()
{
  delete m_SDB;
}
//---------------------------------------------------------------------------

void __fastcall T_SL_BASE_FRM::m_SaveBBClick(TObject *Sender)
{
  if(mng::Manager::instance().checkRight("RRDIC") )  m_SDB->applyUpdates();

  Close();
}
//---------------------------------------------------------------------------

void __fastcall T_SL_BASE_FRM::m_CancelBBClick(TObject *Sender)
{
  m_SDB->cancelUpdates();

  Close();
}
//---------------------------------------------------------------------------
void __fastcall T_SL_BASE_FRM::m_UsunBBClick(TObject *Sender)
{
  m_DS->DataSet->Delete();
}
//---------------------------------------------------------------------------
void __fastcall T_SL_BASE_FRM::m_DBGDblClick(TObject *Sender)
{
  if(mng::Manager::instance().checkRight("RRDIC") ) m_EdytujBB->Click();
}
//---------------------------------------------------------------------------
void __fastcall T_SL_BASE_FRM::afterAdd(TModalResult mResult, const AnsiString &fName, const Variant &fValue)
{
  if (mResult == mrOk)
  {
	m_SDB->applyUpdates();

	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->close();
	m_SDB->open();

	m_SDB->locate(fName, fValue);
  }
  else
  {
	m_SDB->cancelUpdates();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SL_BASE_FRM::afterEdit(TModalResult mResult)
{
  if (mResult == mrOk)
  {
	m_SDB->applyUpdates();
  }
  else
  {
	m_SDB->cancelUpdates();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SL_BASE_FRM::FormActivate(TObject *Sender)
{
  bool _Right =mng::Manager::instance().checkRight("RRDIC");
  m_DodajBB->Visible   = _Right;
  m_EdytujBB->Visible  = _Right;
  m_UsunBB->Visible    = _Right;
  m_CancelBB->Visible  = _Right;
  m_SaveBB->Caption    = _Right ? "Zapisz" : "Zamknij";

}
//---------------------------------------------------------------------------

void __fastcall T_SL_BASE_FRM::m_PrintBBClick(TObject *Sender)
{
 mng::ControlsMan _CoMan(m_DBG->DataSource->DataSet);
 sqr::SQRMan sm ;
 sm.ShowRap(m_DBG,Caption,"","-", "|", NULL) ;

}
//---------------------------------------------------------------------------

