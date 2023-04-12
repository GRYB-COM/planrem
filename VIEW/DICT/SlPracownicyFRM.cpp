//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlPracownicyFRM.h"
#include "SlPracownicyEditFRM.h"
#include "MANAGER\various_man.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlPracownicyFRM::T_SlPracownicyFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
  m_SDB->setEventsHandler(new PracownicyStreamEvents());

  m_komSDB = new mng::StreamDB();
  m_komSDB->setQuery("SELECT * FROM PR_KOMORKI ORDER BY KOD, NAZWA");

  m_komDS->DataSet = m_komSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_SlPracownicyFRM::~T_SlPracownicyFRM()
{
  delete m_komSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT O.*, S.NAZWA AS STOPIEN, K.KOD AS KOMORKA FROM PR_OSOBY O, PR_KOMORKI K, PR_STOPNIE S WHERE O.ID_KOMORKI = K.ID_KOMORKI AND O.ID_STOPNIA = S.ID_STOPNIA ORDER BY O.NAZWISKO, O.IMIE");
  m_SDB->open();

  jbutils::TMyIni ini;
  m_komCB->KeyValue = ini.ReadIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", 1 );

  m_komSDB->open();
  m_komSDB->fieldByName("KOD")->DisplayWidth = 6;

  m_komCBCloseUp(NULL);

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyFRM::m_komCBCloseUp(TObject *Sender)
{
  m_SDB->setFiltered(false);

  if(!m_komCB->KeyValue.IsNull())
  {
	if (m_komSDB->fieldByName("KOD")->AsString == "0/0")
	{
	  m_SDB->setFilter("");
	  m_SDB->setFiltered(false);
	}
	else
	{
	  AnsiString filtr = "ID_KOMORKI=" + m_komCB->KeyValue;
	  m_SDB->setFilter(filtr);
	  m_SDB->setFiltered(true);
	}

	jbutils::TMyIni ini;
	ini.WriteIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator warsztatu", m_komCB->KeyValue);
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlPracownicyEditFRM> editForm(new T_SlPracownicyEditFRM(NULL));

  editForm->addRecord(m_DS, "ID_OSOBY", m_SDB->fieldByName("ID_KOMORKI")->AsInteger);

  if (editForm->ModalResult == mrOk)
  {
	Variant locvalues[5];
	locvalues[0] = Variant(m_SDB->fieldByName("NAZWISKO")->AsString);
	locvalues[1] = Variant(m_SDB->fieldByName("IMIE")->AsString);
	locvalues[2] = Variant(m_SDB->fieldByName("ID_STOPNIA")->AsInteger);
	locvalues[3] = Variant(m_SDB->fieldByName("ID_STANOWISKA")->AsInteger);
	locvalues[4] = Variant(m_SDB->fieldByName("ID_KOMORKI")->AsInteger);

	m_SDB->fieldByName("STOPIEN")->AsString = editForm->m_stpDS->DataSet->FieldByName("NAZWA")->AsString;
	m_SDB->fieldByName("KOMORKA")->AsString = editForm->m_komDS->DataSet->FieldByName("KOD")->AsString;
	m_SDB->applyUpdates();

	mng::ControlsMan cm(m_SDB->getClient());

	AnsiString filtr = m_SDB->getFilter();
	m_SDB->setFiltered(false);

	m_SDB->refresh();

	m_SDB->locate("NAZWISKO;IMIE;ID_STOPNIA;ID_STANOWISKA;ID_KOMORKI", VarArrayOf(locvalues, 4));

	editForm->applyDetails(m_SDB->fieldByName("ID_OSOBY")->AsInteger);

	m_SDB->setFilter(filtr);
	m_SDB->setFiltered(true);
  }
  else
  {
	m_SDB->cancelUpdates();
	editForm->cancelDetails();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlPracownicyEditFRM> editForm(new T_SlPracownicyEditFRM(NULL));

  editForm->editRecord(m_DS);

  if (editForm->ModalResult == mrOk)
  {
	int id = m_SDB->fieldByName("ID_OSOBY")->AsInteger;

	m_SDB->applyUpdates();

	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->refresh();

	m_SDB->locate("ID_OSOBY", id);

	editForm->applyDetails();
  }
  else
  {
	m_SDB->cancelUpdates();
	editForm->cancelDetails();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyFRM::m_UsunBBClick(TObject *Sender)
{
  mng::QueryDB qu("DELETE FROM PR_URLOPY WHERE ID_OSOBY = :ID");

  qu.paramByName("ID")->AsInteger = m_SDB->fieldByName("ID_OSOBY")->AsInteger;
  qu.execute();

  m_DS->DataSet->Delete();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void PracownicyStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("STOPIEN")->ProviderFlags = pf;
  delta->FieldByName("KOMORKA")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------

