//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlJednostkiFRM.h"
#include "SlJednostkiEditFRM.h"
#include "MANAGER\stream_db.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlJednostkiFRM::T_SlJednostkiFRM(TComponent* Owner) : T_SL_BASE_FRM(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SlJednostkiFRM::MyShowModal()
{
  m_SDB->setQuery("SELECT * FROM PR_JEDNOSTKI WHERE ID_JEDNOSTKI >= 0 ORDER BY JW, MIEJSCOWOSC");
  m_SDB->open();

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SlJednostkiFRM::edKodJWChange(TObject *Sender)
{
  if (!edKodJW->Text.Trim().IsEmpty())
  {
    m_kodFilter = String("UPPER(JW) LIKE '%") + edKodJW->Text.UpperCase() + String("%'");
  }
  else
  {
    m_kodFilter = "";
  }

  setFilter();
}
//---------------------------------------------------------------------------
void __fastcall T_SlJednostkiFRM::edMiastoChange(TObject *Sender)
{
  if (!edMiasto->Text.Trim().IsEmpty())
  {
    m_mstFilter = String("UPPER(MIEJSCOWOSC) LIKE '%") + edMiasto->Text.UpperCase() + String("%'");
  }
  else
  {
    m_mstFilter = "";
  }

  setFilter();
}
//---------------------------------------------------------------------------
void __fastcall T_SlJednostkiFRM::setFilter()
{
  m_SDB->setFiltered(false);

  AnsiString filter = "";

  if (m_kodFilter != "")
  {
    filter += m_kodFilter + " AND ";
  }

  if (m_mstFilter != "")
  {
    filter += m_mstFilter + " AND ";
  }

  if (!filter.IsEmpty())
  {
    filter = filter.SubString(1, filter.Length() - 5);

    m_SDB->setFilter(filter);
    m_SDB->setFiltered(true);
  }
}
//---------------------------------------------------------------------------

void __fastcall T_SlJednostkiFRM::m_DodajBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlJednostkiEditFRM> editForm(new T_SlJednostkiEditFRM(NULL));

  editForm->ActiveControl = editForm->edKod;

  editForm->addRecord(m_DS, "ID_JEDNOSTKI");

  afterAdd(editForm->ModalResult, "JW", m_SDB->fieldByName("JW")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall T_SlJednostkiFRM::m_EdytujBBClick(TObject *Sender)
{
  std::auto_ptr<T_SlJednostkiEditFRM> editForm(new T_SlJednostkiEditFRM(NULL));

  editForm->editRecord(m_DS);

  afterEdit(editForm->ModalResult);
}
//---------------------------------------------------------------------------

