//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlWydzialyFRM.h"
#include "SlWydzialyEditFRM.h"
#include "MANAGER\stream_db.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlWydzialyFRM::T_SlWydzialyFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlWydzialyFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_WYDZIALY ORDER BY KOD");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_SlWydzialyFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlWydzialyEditFRM> editForm(new T_SlWydzialyEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_WYDZIALU");

  afterAdd(editForm->ModalResult, "KOD", m_SDB->fieldByName("KOD")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlWydzialyFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlWydzialyEditFRM> editForm(new T_SlWydzialyEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

