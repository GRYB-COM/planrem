// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlWarsztatyFRM.h"
#include "isManager.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma link "AsgLinks"
#pragma resource "*.dfm"
T_SlWarsztatyFRM* _SlWarsztatyFRM;

// ---------------------------------------------------------------------------
__fastcall T_SlWarsztatyFRM::T_SlWarsztatyFRM(TComponent* Owner) : TForm(Owner)
{
  m_SDB = new mng::StreamDB;
  m_SDB->setQuery("SELECT w.ID_KOMORKI, w.KOD, w.NAZWA, w.ID_ODDZIALU, w.ID_WYDZIALU, w.TELEFON, o.KOD AS KOD_O FROM PR_KOMORKI w , PR_ODDZIALY o");
  m_DS->DataSet = m_SDB->getClient();
  // m_DBG->AdvGridDropDown->
}

// ---------------------------------------------------------------------------
__fastcall T_SlWarsztatyFRM::~T_SlWarsztatyFRM()
{
  delete m_SDB;
}

// ---------------------------------------------------------------------------
void __fastcall T_SlWarsztatyFRM::FormShow(TObject* Sender)
{
  m_SDB->open();
}

// ---------------------------------------------------------------------------
void T_SlWarsztatyFRM::fillOddzialyEL()
{
  mng::QueryDB _QDB;
  _QDB.open("select * from PR_ODDZIALY");
  // m_WydzialyLUEL->Items->       38 strona
}
// ---------------------------------------------------------------------------

void __fastcall T_SlWarsztatyFRM::m_DBGGetEditorProp(TObject* Sender, int ACol, int ARow, TEditLink* AEditLink)
{
  Advcustomgriddropdown::TDropDownItem *_I;
  switch(ACol)
  {

  case 7:
	mng::QueryDB _QDB;
	_QDB.open("select * from PR_ODDZIALY");
	m_DBG->AdvGridDropDown->Columns->Clear();
	m_DBG->AdvGridDropDown->Columns->Add();
	m_DBG->AdvGridDropDown->Columns->Items[0]->Header= "Numer oddzia³u";
	m_DBG->AdvGridDropDown->Columns->Items[0]->ColumnType = Advcustomgriddropdown::ctText;
//	m_DBG->AdvGridDropDown->Columns->Add()->Header = 'AAA';
///	m_DBG->AdvGridDropDown->Columns->Add()->ColumnType = Advmulticolumndropdown::ctText;

	m_DBG->AdvGridDropDown->Columns->Add();
	m_DBG->AdvGridDropDown->Columns->Items[1]->Header= "Kod";
	m_DBG->AdvGridDropDown->Columns->Items[1]->ColumnType = Advcustomgriddropdown::ctText;

	m_DBG->AdvGridDropDown->Columns->Add();
	m_DBG->AdvGridDropDown->Columns->Items[2]->Header= "Nazwa";
	m_DBG->AdvGridDropDown->Columns->Items[2]->ColumnType = Advcustomgriddropdown::ctText;

	while (!_QDB.isEof())
	{
	  _I = m_DBG->AdvGridDropDown->Items->Add();
	  _I->Text->Add(_QDB.fieldByName("ID_ODDZIALU")->AsAnsiString);
	  _I->Text->Add(_QDB.fieldByName("KOD")->AsAnsiString);
	  _I->Text->Add(_QDB.fieldByName("NAZWA")->AsAnsiString);
	  _QDB.next();
	}
    m_DBG->AdvGridDropDown->LookupColumn = 1;
	break;
  }
}
// ---------------------------------------------------------------------------

void __fastcall T_SlWarsztatyFRM::m_DBGGetEditorType(TObject* Sender, int ACol, int ARow, TEditorType& AEditor)
{
  switch(ACol)
  {

  case 7:
  m_DBG->MaxEditLength = 0 ;
  break;
  }
}
// ---------------------------------------------------------------------------
void __fastcall T_SlWarsztatyFRM::m_SaveBBClick(TObject *Sender)
{
 m_SDB->applyUpdates();
}
//---------------------------------------------------------------------------

void __fastcall T_SlWarsztatyFRM::m_DBGComboCloseUp(TObject *Sender, int ARow, int ACol)

{
AnsiString aaa   = m_DBG->AdvGridDropDown->Items->Items[2]->ToString();
m_DBG->AdvGridDropDown->Grid->SelectedText()
}
//---------------------------------------------------------------------------

void __fastcall T_SlWarsztatyFRM::m_DBGComboChange(TObject *Sender, int ACol, int ARow,
          int AItemIndex, UnicodeString ASelection)
{
;
}
//---------------------------------------------------------------------------

void __fastcall T_SlWarsztatyFRM::m_DBGComboObjectChange(TObject *Sender, int ACol,
          int ARow, int AItemIndex, UnicodeString ASelection, TObject *AObject)
{
;
}
//---------------------------------------------------------------------------

