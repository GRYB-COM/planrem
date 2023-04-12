//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSprzetGrupyFRM.h"
#include "SlSprzetGrupyEditFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include "MANAGER\various_man.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSprzetGrupyFRM::T_SlSprzetGrupyFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetGrupyFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_GRUPY_SPRZETU WHERE ID_GR_SPRZ > 0 ORDER BY ID_GR_SPRZ");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetGrupyFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetGrupyEditFRM> editForm(new T_SlSprzetGrupyEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_GR_SPRZ");

  afterAdd(editForm->ModalResult, "NAZWA", m_SDB->fieldByName("NAZWA")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetGrupyFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetGrupyEditFRM> editForm(new T_SlSprzetGrupyEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

