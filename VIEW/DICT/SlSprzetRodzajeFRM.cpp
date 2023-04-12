//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSprzetRodzajeFRM.h"
#include "SlSprzetRodzajeEditFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\various_man.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSprzetRodzajeFRM::T_SlSprzetRodzajeFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetRodzajeFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_RODZAJE_SPRZETU WHERE ID_GR_SPRZ > 0 AND ID_RODZ_SPRZ > 0 ORDER BY ID_GR_SPRZ, ID_RODZ_SPRZ");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetRodzajeFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetRodzajeEditFRM> editForm(new T_SlSprzetRodzajeEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_RODZ_SPRZ");

  afterAdd(editForm->ModalResult, "NAZWA", m_SDB->fieldByName("NAZWA")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetRodzajeFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetRodzajeEditFRM> editForm(new T_SlSprzetRodzajeEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

