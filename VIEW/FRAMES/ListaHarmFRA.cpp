// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ListaHarmFRA.h"
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
__fastcall T_ListaHarmFRA::T_ListaHarmFRA(TComponent* Owner) : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall T_ListaHarmFRA::~T_ListaHarmFRA(void)
{
}
// ---------------------------------------------------------------------------
T_ListaHarmFRA::Pars __fastcall T_ListaHarmFRA::getPars(void)
{
 Pars _Pars;
 return _Pars;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRA::setPars(const T_ListaHarmFRA::Pars& _Pars)
{
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRA::open(void)
{
 clearFilter(NULL);
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRA::setSearchClickEvent(TNotifyEvent Event)
{

}
// ---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRA::setDataSet(TDataSet* _DataSet)
{
 m_DS->DataSet = _DataSet;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRA::setFilter(TObject *Sender)
{
 String _Filter, _Det;

 TDataSet *_DS = m_DS->DataSet;
 if(_DS)
 {
  if(!m_NrHarmED->Text.IsEmpty() )
  {
   _Filter  = String(" ID_HARM_STR LIKE '%") + m_NrHarmED->Text.UpperCase() + String("%'");
   _Det     = String("Nr Harm.: ") + m_NrHarmED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_NazSprzED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NazSprzED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(SPRZ_ZAD) LIKE '%") + m_NazSprzED->Text.UpperCase() + String("%'");
   _Det    += String("Nazwa sprzêtu: ") + m_NazSprzED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_PodstED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_PodstED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(PODSTAWA) LIKE '%") + m_PodstED->Text.UpperCase() + String("%'");
   _Det    += String("Podstawa: ") + m_PodstED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_DostED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_DostED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(DOSTAWCA) LIKE '%") + m_DostED->Text.UpperCase() + String("%'");
   _Det    += String("Dostawca: ") + m_DostED->Text.UpperCase();
  }
	if(!_Filter.IsEmpty() && !m_WarED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_WarED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(WARSZTAT) LIKE '%") + m_WarED->Text.UpperCase() + String("%'");
   _Det    += String("Kod warsztatu: ") +  m_WarED->Text.UpperCase();
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

void __fastcall T_ListaHarmFRA::clearFilter(TObject *Sender)
{
 m_ClearFilterBT->Enabled = false;
 m_NrHarmED->Text   = "";
 m_NazSprzED->Text = "";
 m_PodstED->Text   = "";
 m_WarED->Text     = "";
 m_DostED->Text    = "";
 m_FilterLB->Caption     = "WY£¥CZONY";
 m_FilterLB->Font->Color = clWindowText;
 m_DS->DataSet->Filtered = false;
 m_DS->DataSet->Filter   = "";
 m_FilterDetLB->Visible  = false;
}
//---------------------------------------------------------------------------

