//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlKomorkiFRM.h"
#include "SlKomorkiEditFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\various_man.h"
#include <memory>
#include "SlKomorkiStreamEvents.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlKomorkiFRM::T_SlKomorkiFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
  m_SDB->setEventsHandler(new SlKomorkiStreamEvents());
}
//---------------------------------------------------------------------------
void __fastcall T_SlKomorkiFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT K.*, W.KOD AS KOD_WYD, O.KOD AS KOD_ODD FROM PR_KOMORKI K left join PR_WYDZIALY W on w.ID_WYDZIALU = k.ID_WYDZIALU left join  PR_ODDZIALY O on o.ID_ODDZIALU= k.ID_ODDZIALU where k.KOD not in ('0/0','-1/-1') ORDER BY KOD");
  m_SDB->open();

  m_SDB->setFilter("KOD<>'0/0'");
  m_SDB->setFiltered(true);

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKomorkiFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlKomorkiEditFRM> editForm(new T_SlKomorkiEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_KOMORKI");

  m_SDB->fieldByName("KOD_WYD")->AsString = editForm->m_wDS->DataSet->FieldByName("KOD")->AsString;
  m_SDB->fieldByName("KOD_ODD")->AsString = editForm->m_oDS->DataSet->FieldByName("KOD")->AsString;

  afterAdd(editForm->ModalResult, "KOD", m_SDB->fieldByName("KOD")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlKomorkiFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlKomorkiEditFRM> editForm(new T_SlKomorkiEditFRM(NULL));

  editForm->editRecord(m_DS);

  AnsiString kod = m_SDB->fieldByName("KOD")->AsString;

  afterEdit(editForm->ModalResult);

  if (editForm->ModalResult == mrOk)
  {
	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->refresh();

	m_SDB->locate("KOD", kod);
  }
}
//---------------------------------------------------------------------------

