//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlKadraFRM.h"
#include "SlKadraEditFRM.h"
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
__fastcall T_SlKadraFRM::T_SlKadraFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_KADRA ORDER BY KOD");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlKadraEditFRM> editForm(new T_SlKadraEditFRM(NULL));

  editForm->addRecord(m_DS, "KOD");

  if (editForm->ModalResult == mrOk)
  {
	AnsiString kod = m_SDB->fieldByName("KOD")->AsString;

	m_SDB->applyUpdates();

	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->refresh();

	m_SDB->locate("KOD", kod);

	editForm->applyDetails(kod);
  }
  else
  {
	m_SDB->cancelUpdates();
	editForm->cancelDetails();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlKadraEditFRM> editForm(new T_SlKadraEditFRM(NULL));

  editForm->editRecord(m_DS);

  if (editForm->ModalResult == mrOk)
  {
	AnsiString kod = m_SDB->fieldByName("KOD")->AsString;

	m_SDB->applyUpdates();

	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->refresh();

	m_SDB->locate("KOD", kod);

	editForm->applyDetails();
  }
  else
  {
	m_SDB->cancelUpdates();
	editForm->cancelDetails();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraFRM::m_UsunBBClick(TObject *Sender)
{
  mng::QueryDB qu("DELETE FROM PR_SZKOLENIE_RBH WHERE KOD = :KOD");

  qu.paramByName("KOD")->AsString = m_SDB->fieldByName("KOD")->AsString;
  qu.execute();

  m_DS->DataSet->Delete();

}
//---------------------------------------------------------------------------

