//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlSprzetFRM.h"
#include "SlSprzetEditFRM.h"
#include "MANAGER\query_db.h"
#include "MANAGER\various_man.h"
#include <memory>
#include <isvaria.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlSprzetFRM::T_SlSprzetFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
  m_SDB->setEventsHandler(new SprzetStreamEvents());

  m_komSDB = new mng::StreamDB();
  m_gspSDB = new mng::StreamDB();
  m_rspSDB = new mng::StreamDB();

  m_komSDB->open("SELECT * FROM PR_KOMORKI WHERE WARSZTAT = 'T' ORDER BY KOD, NAZWA");
  m_gspSDB->open("SELECT * FROM PR_GRUPY_SPRZETU ORDER BY ID_GR_SPRZ");
  m_rspSDB->open("SELECT * FROM PR_RODZAJE_SPRZETU ORDER BY ID_RODZ_SPRZ");

  m_komDS->DataSet = m_komSDB->getClient();
  m_gspDS->DataSet = m_gspSDB->getClient();
  m_rspDS->DataSet = m_rspSDB->getClient();

  m_komIndex = -1;
  m_komID    = -1;

  m_rspIndex = -1;
  m_rspID    = -1;

  m_gspIndex = -1;
  m_gspID    = -1;

  m_nameFilter = "";
  m_komFilter  = "";
  m_gspFilter  = "";
  m_rspFilter  = "";

  m_komCB->ItemIndex = 2;
  m_gspCB->ItemIndex = 0;
  m_rspCB->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::MyShowModal()
{
  AnsiString sql = "SELECT S.*, K.KOD, R.NAZWA AS RODZAJ FROM PR_SPRZET S ";
  sql += "LEFT OUTER JOIN PR_KOMORKI K ON S.ID_KOMORKI = K.ID_KOMORKI ";
  sql += "LEFT OUTER JOIN PR_RODZAJE_SPRZETU R ON S.ID_RODZ_SPRZ = R.ID_RODZ_SPRZ ";
  sql += "ORDER BY KOD, NAZWA";

  m_SDB->setQuery(sql);
  m_SDB->open();

  m_edFiltr->Text = "";

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetEditFRM> editForm(new T_SlSprzetEditFRM(NULL));

  editForm->setKomID(m_komID);
  editForm->setGspID(m_gspID);
  editForm->setRspID(m_rspID);

  editForm->addRecord(m_DS, "ID_SPRZETU");

  m_SDB->fieldByName("KOD")->AsString    = editForm->m_komDS->DataSet->FieldByName("KOD")->AsString;
  m_SDB->fieldByName("RODZAJ")->AsString = editForm->m_rspDS->DataSet->FieldByName("NAZWA")->AsString;

  m_edFiltr->Text = "";

  afterAdd(editForm->ModalResult, "NAZWA", m_SDB->fieldByName("NAZWA")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetEditFRM> editForm(new T_SlSprzetEditFRM(NULL));

  bool isGr = !m_SDB->fieldByName("ID_GR_SPRZ")->IsNull;
  int  idGr = m_SDB->fieldByName("ID_GR_SPRZ")->AsInteger;

  if (isGr && idGr >= 0)
  {
    editForm->setFilterRspSDB("ID_GR_SPRZ=" + IntToStr(idGr));
  }
  else
  {
    editForm->setFilterRspSDB("ID_GR_SPRZ = -1");
  }

  editForm->editRecord(m_DS);

  AnsiString id = m_SDB->fieldByName("ID_SPRZETU")->AsInteger;

  m_edFiltr->Text = "";

  afterEdit(editForm->ModalResult);

  if (editForm->ModalResult == mrOk)
  {
	mng::ControlsMan cm(m_SDB->getClient());

	m_SDB->close();
	m_SDB->open();

	m_SDB->locate("ID_SPRZETU", id);
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_edFiltrChange(TObject *Sender)
{
  if (!m_edFiltr->Text.Trim().IsEmpty())
  {
	m_nameFilter = String("UPPER(NAZWA) LIKE '%") + m_edFiltr->Text.UpperCase() + String("%'");
  }
  else
  {
	m_nameFilter = "";
  }

  setFilterSDB();

  m_DBG->Width++;
  m_DBG->Width--;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_JIMFltEDChange(TObject *Sender)
{
   if (!m_JIMFltED->Text.Trim().IsEmpty())
  {
	m_JIMFilter = String("UPPER(NAZWA) LIKE '%") + m_JIMFltED->Text.UpperCase() + "'";
  }
  else
  {
	m_JIMFilter = "";
  }

  setFilterSDB();

  m_DBG->Width++;
  m_DBG->Width--;

}
//---------------------------------------------------------------------------
void SprzetStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("KOD")->ProviderFlags = pf;
  delta->FieldByName("RODZAJ")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
AnsiString __fastcall T_SlSprzetFRM::getFilter()
{
  AnsiString filter = "";

  if (!m_nameFilter.IsEmpty())
  {
    filter += m_nameFilter + " AND ";
  }

  if (!m_komFilter.IsEmpty())
  {
    filter += m_komFilter + " AND ";
  }

  if (!m_gspFilter.IsEmpty())
  {
    filter += m_gspFilter + " AND ";
  }

  if (!m_rspFilter.IsEmpty())
  {
	filter += m_rspFilter + " AND ";
  }

  if (!m_JIMFilter.IsEmpty())
  {
	filter += m_JIMFilter + " AND ";
  }

  if (!filter.IsEmpty())
  {
    filter = filter.SubString(1, filter.Length() - 5);
  }

  return filter;
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::setFilterSDB(bool filtered)
{
  m_SDB->setFiltered(false);

  if (filtered)
  {
    AnsiString filter = getFilter();

    m_SDB->setFilter(filter);

    if (!filter.IsEmpty())
    {
      m_SDB->setFiltered(true);
    }
  }
  else
  {
    m_nameFilter = "";
    m_komFilter  = "";
    m_gspFilter  = "";
    m_rspFilter  = "";

    m_SDB->setFilter("");
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_komCBCloseUp(TObject *Sender)
{
  if (m_komCB->ItemIndex != m_komIndex)
  {
    m_komIndex = m_komCB->ItemIndex;

    m_komID = m_komSDB->fieldByName("ID_KOMORKI")->AsInteger;

    if(m_komID >= 0)
    {
	  if (m_komSDB->fieldByName("KOD")->AsString == "0/0")
	  {
	    m_komFilter = "";
	  }
	  else
	  if (m_komSDB->fieldByName("KOD")->AsString == "-1/-1")
	  {
	    m_komFilter = "ID_KOMORKI IS NULL";
	  }
	  else
	  {
	    m_komFilter = "ID_KOMORKI=" + IntToStr(m_komID);
	  }
    }

    setFilterSDB();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_gspCBCloseUp(TObject *Sender)
{
  if (m_gspCB->ItemIndex != m_gspIndex)
  {
    m_gspIndex = m_gspCB->ItemIndex;

    m_gspID = m_gspSDB->fieldByName("ID_GR_SPRZ")->AsInteger;

    if(m_gspID >= 0)
    {
	  m_gspFilter = "ID_GR_SPRZ=" + IntToStr(m_gspID);
	}
	else
	{
      m_gspFilter = "";
    }

    setFilterRspSDB(m_gspID);

    setFilterSDB();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::m_rspCBCloseUp(TObject *Sender)
{
  if (m_rspCB->ItemIndex != m_rspIndex)
  {
    m_rspIndex = m_rspCB->ItemIndex;

    m_rspID = m_rspSDB->fieldByName("ID_RODZ_SPRZ")->AsInteger;

    if(m_rspID >= 0)
    {
	  m_rspFilter = "ID_RODZ_SPRZ=" + IntToStr(m_rspID);
	}
	else
	{
      m_rspFilter = "";
    }

    setFilterSDB();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_SlSprzetFRM::setFilterRspSDB(int gr)
{
  m_rspSDB->setFiltered(false);

  if (gr >= 0)
  {
    m_rspSDB->setFilter("ID_RODZ_SPRZ=-1 OR ID_GR_SPRZ=" + IntToStr(gr));
    m_rspSDB->setFiltered(true);
  }
  else
  {
    m_rspSDB->setFilter("");
  }
}
//---------------------------------------------------------------------------



