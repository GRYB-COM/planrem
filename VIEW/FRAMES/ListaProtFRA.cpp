// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ListaProtFRA.h"
#include "isManager.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma link "AdvCombo"
#pragma link "AdvDBComboBox"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
using namespace finders;
// ---------------------------------------------------------------------------
__fastcall T_ListaProtFRA::T_ListaProtFRA(TComponent* Owner) : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall T_ListaProtFRA::~T_ListaProtFRA(void)
{
}
// ---------------------------------------------------------------------------
T_ListaProtFRA::Pars __fastcall T_ListaProtFRA::getPars(void)
{
 Pars _Pars;
 return _Pars;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaProtFRA::setPars(const T_ListaProtFRA::Pars& _Pars)
{
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaProtFRA::open(void)
{
 clearFilter(NULL);
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaProtFRA::setSearchClickEvent(TNotifyEvent Event)
{

}
// ---------------------------------------------------------------------------
void __fastcall T_ListaProtFRA::setDataSet(TDataSet* _DataSet)
{
 m_DS->DataSet = _DataSet;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaProtFRA::setFilter(TObject *Sender)
{
 String _Filter, _Det;

 TDataSet *_DS = m_DS->DataSet;
 if(_DS)
 {
  if(!m_DataWystED->Text.IsEmpty() )
  {
   _Filter  = String(" DATA_WYST_STR LIKE '%") + m_DataWystED->Text.UpperCase() + String("%'");
   _Det     = String("Data wyst.: ") + m_DataWystED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_NrProtED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NrProtED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(SYGN_PROTOKOLU) LIKE '%") + m_NrProtED->Text.UpperCase() + String("%'");
   _Det    += String("Nr protoko³u: ") + m_NrProtED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_JWED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_JWED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(JW) LIKE '%") + m_JWED->Text.UpperCase() + String("%'");
   _Det    += String("JW: ") + m_JWED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_MiejscED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_MiejscED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(MIEJSCOWOSC) LIKE '%") + m_MiejscED->Text.UpperCase() + String("%'");
   _Det    += String("Miejscowoœæ: ") + m_MiejscED->Text.UpperCase();
  }

  _DS->Filter    = _Filter;
  _DS->Filtered  = !_Filter.IsEmpty();
 }
 if(_DS->Filtered)
 {
  m_ClearFilterBT->Enabled = true;
  m_FilterLB->Caption = "W£¥CZONY";
  m_FilterLB->Font->Color = clRed;
  m_FilterDetLB->Caption  = _Det;
  m_FilterDetLB->Visible  = true;
 }
}
//---------------------------------------------------------------------------

void __fastcall T_ListaProtFRA::clearFilter(TObject *Sender)
{
 m_ClearFilterBT->Enabled = false;
 m_DataWystED->Text   = "";
 m_NrProtED->Text = "";
 m_JWED->Text   = "";
 m_MiejscED->Text    = "";
 m_FilterLB->Caption     = "WY£¥CZONY";
 m_FilterLB->Font->Color = clWindowText;
 m_DS->DataSet->Filtered = false;
 m_DS->DataSet->Filter   = "";
 m_FilterDetLB->Visible  = false;
}
//---------------------------------------------------------------------------

