//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlOddzialyFRM.h"
#include "SlOddzialyEditFRM.h"
#include "MANAGER\stream_db.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlOddzialyFRM::T_SlOddzialyFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlOddzialyFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_ODDZIALY ORDER BY KOD");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlOddzialyFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlOddzialyEditFRM> editForm(new T_SlOddzialyEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_ODDZIALU");

  afterAdd(editForm->ModalResult, "KOD", m_SDB->fieldByName("KOD")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlOddzialyFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlOddzialyEditFRM> editForm(new T_SlOddzialyEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

