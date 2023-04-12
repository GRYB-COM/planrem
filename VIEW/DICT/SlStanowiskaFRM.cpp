//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlStanowiskaFRM.h"
#include "SlStanowiskaEditFRM.h"
#include "MANAGER\stream_db.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlStanowiskaFRM::T_SlStanowiskaFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlStanowiskaFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_STANOWISKA ORDER BY KOD, NAZWA");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlStanowiskaFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlStanowiskaEditFRM> editForm(new T_SlStanowiskaEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_STANOWISKA");

  afterAdd(editForm->ModalResult, "KOD", m_SDB->fieldByName("KOD")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlStanowiskaFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlStanowiskaEditFRM> editForm(new T_SlStanowiskaEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

