//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MeldTygWybFRM.h"
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FCSWYB"
#pragma link "PopupButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_MeldTygWybFRM::T_MeldTygWybFRM(TComponent* Owner)
	: T_FCUSTWYB(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygWybFRM::FormShow(TObject *Sender)
{
 TDateTime _CurrDate(Date());
 m_DataOdDTP->Date = _CurrDate - DayOfTheWeek(_CurrDate) +1;
 m_DataOdDTPChange(Sender);
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygWybFRM::m_DataOdDTPChange(TObject *Sender)
{
 m_DataDoDTP->Date = m_DataOdDTP->Date + 4;
}
//---------------------------------------------------------------------------
