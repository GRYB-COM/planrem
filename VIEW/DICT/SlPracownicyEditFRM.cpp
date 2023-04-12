//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlPracownicyEditFRM.h"
#include "SlUrlopyEditFRM.h"
#include "SlZwolnieniaEditFRM.h"
#include "SlDelegacjeEditFRM.h"
#include "SlEtatyEditFRM.h"
#include "MANAGER\various_man.h"
#include <memory>
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma link "AdvSmoothTabPager"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlPracownicyEditFRM::T_SlPracownicyEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
  m_urlopSDB = new mng::StreamDB();
  m_delSDB   = new mng::StreamDB();
  m_zwSDB   = new mng::StreamDB();
  m_stpSDB	 = new mng::StreamDB();
  m_stnSDB	 = new mng::StreamDB();
  m_komSDB	 = new mng::StreamDB();
  m_kdrSDB	 = new mng::StreamDB();
  m_EtatySDB = new mng::StreamDB();

  m_urlopSDB->setEventsHandler(new UrlopyStreamEvents());
  m_delSDB->setEventsHandler(new DelegacjeStreamEvents());
  m_zwSDB->setEventsHandler(new ZwolnieniaStreamEvents());
  m_EtatySDB->setEventsHandler(new EtatyStreamEvents());

  m_stpSDB->open("SELECT * FROM PR_STOPNIE ORDER BY ID_STOPNIA");
  m_stnSDB->open("SELECT * FROM PR_STANOWISKA ORDER BY KOD, NAZWA");
  m_komSDB->open("SELECT * FROM PR_KOMORKI WHERE KOD <> '0/0' ORDER BY KOD, NAZWA");
  m_kdrSDB->open("SELECT * FROM PR_KADRA ORDER BY NAZWA");

  m_urlopDS->DataSet = m_urlopSDB->getClient();
  m_delDS->DataSet   = m_delSDB->getClient();
  m_zwDS->DataSet    = m_zwSDB->getClient();
  m_stpDS->DataSet   = m_stpSDB->getClient();
  m_stnDS->DataSet   = m_stnSDB->getClient();
  m_komDS->DataSet   = m_komSDB->getClient();
  m_kdrDS->DataSet   = m_kdrSDB->getClient();
  m_EtatyDS->DataSet = m_EtatySDB->getClient();
  m_stnSDB->fieldByName("NAZWA")->DisplayWidth = 34;
  m_komSDB->fieldByName("KOD")->DisplayWidth = 5;

  m_idUrlpu      = -1;
  m_idDelegacji  = -1;
  m_idZwolnienia = -1;
}
//---------------------------------------------------------------------------
__fastcall T_SlPracownicyEditFRM::~T_SlPracownicyEditFRM()
{
  delete m_urlopSDB;
  delete m_delSDB;
  delete m_zwSDB;
  delete m_stpSDB;
  delete m_stnSDB;
  delete m_komSDB;
  delete m_kdrSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::addRecord(TDataSource *ds, AnsiString keyField, int komFilter)
{
  Caption = "Nowy wpis";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Append();

  m_DS->DataSet->FieldByName(keyField)->AsInteger = -1;
  TField * _F = m_DS->DataSet->FindField("ROK");
  if(_F) _F->AsInteger = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
  m_DS->DataSet->FieldByName("ID_KOMORKI")->AsInteger = komFilter;

  openUrlopySDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openEtatySDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openDelegacjeSDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openZwolnieniaSDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);


  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::editRecord(TDataSource *ds)
{
  Caption = String("Edycja pracownika o identyfikatorze: ") +ds->DataSet->FieldByName("ID_OSOBY")->AsString;

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Edit();

  openUrlopySDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openEtatySDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openDelegacjeSDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);

  openZwolnieniaSDB(m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger);
  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::openUrlopySDB(int idos)
{
  m_urlopSDB->setQuery("SELECT U.*, M.NAZ_MIES FROM PR_URLOPY U, PR_MIESIACE M WHERE U.ID_OSOBY = :ID AND U.NR_MIES = M.NR_MIES ORDER BY NR_MIES");
  m_urlopSDB->paramByName("ID")->AsInteger = idos;
  m_urlopSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::openEtatySDB(int idos)
{
  m_EtatySDB->setQuery("SELECT * FROM PR_ETATY_PRAC WHERE ID_OSOBY = :ID");
  m_EtatySDB->paramByName("ID")->AsInteger = idos;
  m_EtatySDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::openDelegacjeSDB(int idos)
{
  m_delSDB->setQuery("SELECT D.*, K.KOD, M.NAZ_MIES FROM PR_DELEGACJE D, PR_KOMORKI K, PR_MIESIACE M WHERE D.ID_OSOBY = :ID AND D.ID_KOMORKI = K.ID_KOMORKI AND D.MIESIAC = M.NR_MIES ORDER BY NR_MIES, KOD");
  m_delSDB->paramByName("ID")->AsInteger = idos;
  m_delSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::openZwolnieniaSDB(int idos)
{
  m_zwSDB->setQuery("select z.*, M.NAZ_MIES, s.KOD as KOD_ZW from pr_zw_dod z inner join pr_miesiace m on m.NR_MIES = z.NR_MIES  inner join pr_slow_zw s on s.id_slow_zw = z.id_slow_zw where z.ID_OSOBY=:ID_OSOBY");
  m_zwSDB->paramByName("ID_OSOBY")->AsInteger = idos;
  m_zwSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::applyDetails(int keyValue)
{
  applyUrlopySDB(keyValue);

  applyDelegacjeSDB(keyValue);

  applyZwolnieniaSDB(keyValue);
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::applyUrlopySDB(int keyValue)
{
  if (!m_urlopSDB->isEmpty())
  {
	m_urlopSDB->first();

	while (!m_urlopSDB->isEof())
	{
	  m_urlopSDB->edit();
	  m_urlopSDB->fieldByName("ID_OSOBY")->AsInteger = keyValue;
	  m_urlopSDB->post();

	  m_urlopSDB->next();
	}

	m_urlopSDB->applyUpdates();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::applyDelegacjeSDB(int keyValue)
{
  if (!m_delSDB->isEmpty())
  {
	m_delSDB->first();

	while (!m_delSDB->isEof())
	{
	  m_delSDB->edit();
	  m_delSDB->fieldByName("ID_OSOBY")->AsInteger = keyValue;
	  m_delSDB->post();

	  m_delSDB->next();
	}

	m_delSDB->applyUpdates();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::applyZwolnieniaSDB(int keyValue)
{
  if (!m_zwSDB->isEmpty())
  {
	m_zwSDB->first();

	while (!m_zwSDB->isEof())
	{
	  m_zwSDB->edit();
	  m_zwSDB->fieldByName("ID_OSOBY")->AsInteger = keyValue;
	  m_zwSDB->post();

	  m_zwSDB->next();
	}

	m_zwSDB->applyUpdates();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::applyDetails()
{
  m_urlopSDB->applyUpdates();

  m_delSDB->applyUpdates();

  m_zwSDB->applyUpdates();

  m_EtatySDB->applyUpdates();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::cancelDetails()
{
  m_urlopSDB->cancelUpdates();

  m_delSDB->cancelUpdates();

  m_zwSDB->cancelUpdates();

  m_EtatySDB->cancelUpdates();

}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_DodajClick(TObject *Sender)
{
  std::auto_ptr<T_SlUrlopyEditFRM> editForm(new T_SlUrlopyEditFRM(NULL));

  editForm->addRecord(m_urlopDS, "ID_URLOPU", true, rand()*-1);

  if (editForm->ModalResult == mrOk)
  {
	m_urlopSDB->fieldByName("ID_OSOBY")->AsInteger = m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger;
	m_urlopSDB->fieldByName("NAZ_MIES")->AsString  = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;

	m_urlopSDB->post();

	m_idUrlpu = m_idUrlpu - 1;
  }
  else
  {
	m_urlopSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_EdytujClick(TObject *Sender)
{
  std::auto_ptr<T_SlUrlopyEditFRM> editForm(new T_SlUrlopyEditFRM(NULL));

  editForm->editRecord(m_urlopDS);

  if (editForm->ModalResult == mrOk)
  {
	m_urlopSDB->fieldByName("NAZ_MIES")->AsString = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;

	m_urlopSDB->post();
  }
  else
  {
	m_urlopSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_UsunClick(TObject *Sender)
{
  m_urlopDS->DataSet->Delete();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_DodajDClick(TObject *Sender)
{
  std::auto_ptr<T_SlDelegacjeEditFRM> editForm(new T_SlDelegacjeEditFRM(NULL));

  editForm->addRecord(m_delDS, "ID_DELEGACJI", m_idDelegacji);

  if (editForm->ModalResult == mrOk)
  {
	m_delSDB->fieldByName("ID_OSOBY")->AsInteger = m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger;
	m_delSDB->fieldByName("NAZ_MIES")->AsString  = editForm->m_MiesDS->DataSet->FieldByName("NAZ_MIES")->AsString;
	m_delSDB->fieldByName("KOD")->AsString       = editForm->m_komDS->DataSet->FieldByName("KOD")->AsString;

	m_delSDB->post();

	m_idDelegacji = m_idDelegacji - 1;
  }
  else
  {
	m_delSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_EdytujDClick(TObject *Sender)
{
  std::auto_ptr<T_SlDelegacjeEditFRM> editForm(new T_SlDelegacjeEditFRM(NULL));

  editForm->editRecord(m_delDS);

  if (editForm->ModalResult == mrOk)
  {
	m_delSDB->fieldByName("NAZ_MIES")->AsString = editForm->m_MiesDS->DataSet->FieldByName("NAZ_MIES")->AsString;
	m_delSDB->fieldByName("KOD")->AsString      = editForm->m_komDS->DataSet->FieldByName("KOD")->AsString;

	m_delSDB->post();
  }
  else
  {
	m_delSDB->cancel();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_UsunDClick(TObject *Sender)
{
  m_delDS->DataSet->Delete();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_DodajZClick(TObject *Sender)
{
   std::auto_ptr<T_SlZwolnieniaEditFRM> editForm(new T_SlZwolnieniaEditFRM(NULL));

  editForm->addRecord(m_zwDS, "ID_ZW_DOD", m_idZwolnienia);

  if (editForm->ModalResult == mrOk)
  {
	m_zwSDB->fieldByName("ID_OSOBY")->AsInteger = m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger;
	m_zwSDB->fieldByName("NAZ_MIES")->AsString  = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;
	m_zwSDB->fieldByName("KOD_ZW")->AsString    = editForm->m_zwDS->DataSet->FieldByName("KOD")->AsString;

	m_zwSDB->post();

	m_idZwolnienia = m_idZwolnienia - 1;
  }
  else
  {
	m_zwSDB->cancel();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracownicyEditFRM::m_EdytujZClick(TObject *Sender)
{
  std::auto_ptr<T_SlZwolnieniaEditFRM> editForm(new T_SlZwolnieniaEditFRM(NULL));

  editForm->editRecord(m_zwDS);

  if (editForm->ModalResult == mrOk)
  {
	m_zwSDB->fieldByName("NAZ_MIES")->AsString = editForm->m_miesDS->DataSet->FieldByName("NAZ_MIES")->AsString;

	m_zwSDB->post();
  }
  else
  {
	m_zwSDB->cancel();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracownicyEditFRM::m_UsunZClick(TObject *Sender)
{
 m_zwDS->DataSet->Delete();
}
//---------------------------------------------------------------------------
void __fastcall T_SlPracownicyEditFRM::m_AddEtatBTClick(TObject *Sender)
{
  std::auto_ptr<T_SlEtatyEditFRM> editForm(new T_SlEtatyEditFRM(NULL));

  editForm->addRecord(m_EtatyDS, "ID_ETAT_PRAC", m_idEtatu);

  if (editForm->ModalResult == mrOk)
  {
	m_EtatySDB->fieldByName("ID_ETAT_PRAC")->AsInteger   =  -1 * rand();
	m_EtatySDB->fieldByName("ID_OSOBY")->AsInteger   = m_DS->DataSet->FieldByName("ID_OSOBY")->AsInteger;
	m_EtatySDB->post();
  }
  else
  {
	m_EtatySDB->cancel();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracownicyEditFRM::m_EdEtatBTClick(TObject *Sender)
{
  std::auto_ptr<T_SlEtatyEditFRM> editForm(new T_SlEtatyEditFRM(NULL));

  editForm->editRecord(m_EtatyDS);

  if (editForm->ModalResult == mrOk)
  {
	m_EtatySDB->post();
  }
  else
  {
	m_EtatySDB->cancel();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SlPracownicyEditFRM::m_DelEtatBBClick(TObject *Sender)
{
 m_EtatySDB->erase();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void UrlopyStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("NAZ_MIES")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------
void DelegacjeStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("KOD")->ProviderFlags = pf;
  delta->FieldByName("NAZ_MIES")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------
void ZwolnieniaStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("KOD_ZW")->ProviderFlags = pf;
  delta->FieldByName("NAZ_MIES")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------
void EtatyStreamEvents::afterInsert(mng::StreamDB* str_db)
{
 str_db->fieldByName("DATA_OD")->AsDateTime = Date();
 str_db->fieldByName("ETAT")->AsInteger      = 1;
 str_db->fieldByName("ETAT_PROD")->AsInteger = 1;
  str_db->fieldByName("DNIOWKA")->AsInteger  = 8;

}

void __fastcall T_SlPracownicyEditFRM::m_DataDoDTPKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
 if(Key == VK_DELETE)
 {
	   if(Sender == m_DataOdDTP) m_DS->DataSet->FieldByName("DATA_OD")->Clear();
  else if(Sender == m_DataDoDTP) m_DS->DataSet->FieldByName("DATA_DO")->Clear();
 }

}
//---------------------------------------------------------------------------
