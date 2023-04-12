//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KUTkosztyEdFRM.h"
#include "isManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_KUTkosztyEdFRM::T_KUTkosztyEdFRM(TComponent* Owner)
	: TForm(Owner) , m_retValue(false)
{
  m_SDBSlow = new mng::StreamDB();
  m_SDBSlow->open("SELECT * FROM PR_SLOW_KOSZTOW");
  m_DSSlow->DataSet = m_SDBSlow->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_KUTkosztyEdFRM::~T_KUTkosztyEdFRM()
{
  m_SDBSlow->close();
  delete m_SDBSlow;
}
//---------------------------------------------------------------------------
bool __fastcall T_KUTkosztyEdFRM::edit(TDataSet *ds)
{
  m_retValue = false;
  m_DS->DataSet = ds;
  m_DS->DataSet->Edit();

  ShowModal();

  return m_retValue;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTkosztyEdFRM::m_SaveBBClick(TObject *Sender)
{
 m_DS->DataSet->FieldByName("KOD")->AsAnsiString = m_SDBSlow->fieldByName("KOD")->AsAnsiString;
 m_DS->DataSet->FieldByName("NAZWA")->AsAnsiString = m_SDBSlow->fieldByName("NAZWA")->AsAnsiString;
 m_DS->DataSet->Post();
 m_retValue = true;
 Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTkosztyEdFRM::m_CancelBBClick(TObject *Sender)
{
 m_DS->DataSet->Cancel();
 m_retValue = false;
 Close();
}
//---------------------------------------------------------------------------
