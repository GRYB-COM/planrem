//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlKadraEditFRM.h"
#include "SlSzkoleniaEditFRM.h"
#include "MANAGER\various_man.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlKadraEditFRM::T_SlKadraEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_szkolSDB = new mng::StreamDB();

  m_szkolSDB->setEventsHandler(new SzkolStreamEvents());

  m_szkolDS->DataSet = m_szkolSDB->getClient();

  m_valueID = -1;
}
//---------------------------------------------------------------------------
__fastcall T_SlKadraEditFRM::~T_SlKadraEditFRM()
{
  delete m_szkolSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::addRecord(TDataSource *ds, AnsiString keyField)
{
  Caption = "Nowy wpis";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Append();

  m_DS->DataSet->FieldByName(keyField)->AsInteger = -1* rand();

  m_szkolSDB->setQuery("SELECT S.*, M.NAZ_MIES FROM PR_SZKOLENIE_RBH S, PR_MIESIACE M WHERE S.KOD = :KOD AND S.NR_MIES = M.NR_MIES ORDER BY NR_MIES");
  m_szkolSDB->paramByName("KOD")->AsString = m_DS->DataSet->FieldByName("KOD")->AsString;
  m_szkolSDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::editRecord(TDataSource *ds)
{
  Caption = "Edycja";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Edit();

  m_szkolSDB->setQuery("SELECT S.*, M.NAZ_MIES FROM PR_SZKOLENIE_RBH S, PR_MIESIACE M WHERE S.KOD = :KOD AND S.NR_MIES = M.NR_MIES ORDER BY NR_MIES");
  m_szkolSDB->paramByName("KOD")->AsString = m_DS->DataSet->FieldByName("KOD")->AsString;
  m_szkolSDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::applyDetails(AnsiString keyValue)
{
  if (!m_szkolSDB->isEmpty())
  {
	m_szkolSDB->first();

	while (!m_szkolSDB->isEof())
	{
	  m_szkolSDB->edit();
	  m_szkolSDB->fieldByName("KOD")->AsString = keyValue;
	  m_szkolSDB->post();

	  m_szkolSDB->next();
	}

	m_szkolSDB->applyUpdates();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::applyDetails()
{
  m_szkolSDB->applyUpdates();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::cancelDetails()
{
  m_szkolSDB->cancelUpdates();
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::m_DodajClick(TObject *Sender)
{
  std::auto_ptr<T_SlSzkoleniaEditFRM> editForm(new T_SlSzkoleniaEditFRM(NULL));

  editForm->addRecord(m_szkolDS, "ID_SZKOLENIA",true, rand() * -1 );

  if (editForm->ModalResult == mrOk)
  {
	m_szkolSDB->fieldByName("KOD")->AsString = m_DS->DataSet->FieldByName("KOD")->AsString;
	m_szkolSDB->fieldByName("NAZ_MIES")->AsString = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;

	m_szkolSDB->post();
  }
  else
  {
	m_szkolSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::m_EdytujClick(TObject *Sender)
{
  std::auto_ptr<T_SlSzkoleniaEditFRM> editForm(new T_SlSzkoleniaEditFRM(NULL));

  editForm->editRecord(m_szkolDS);

  if (editForm->ModalResult == mrOk)
  {
	m_szkolSDB->fieldByName("NAZ_MIES")->AsString = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;

	m_szkolSDB->post();
  }
  else
  {
	m_szkolSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlKadraEditFRM::m_UsunClick(TObject *Sender)
{
  m_szkolDS->DataSet->Delete();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void SzkolStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("NAZ_MIES")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------

