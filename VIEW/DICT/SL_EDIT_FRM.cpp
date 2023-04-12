//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SL_EDIT_FRM.h"
#include "MANAGER\stream_db.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SL_EDIT_FRM::T_SL_EDIT_FRM(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall T_SL_EDIT_FRM::~T_SL_EDIT_FRM()
{
}
//---------------------------------------------------------------------------
void __fastcall T_SL_EDIT_FRM::m_SaveBBClick(TObject *Sender)
{
  ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall T_SL_EDIT_FRM::m_CancelBBClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall T_SL_EDIT_FRM::addRecord(TDataSource *ds, AnsiString keyField, bool initID,int initVal)
{
  Caption = "Nowy wpis";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Append();

  if (initID)
  {
	m_DS->DataSet->FieldByName(keyField)->AsInteger = initVal;
  }
	TField * _F = m_DS->DataSet->FindField("ROK");
   if(_F) _F->AsInteger = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());

  ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SL_EDIT_FRM::editRecord(TDataSource *ds)
{
  Caption = "Edycja";

  m_DS->DataSet = ds->DataSet;
  m_DS->DataSet->Edit();

  ShowModal();
}
//---------------------------------------------------------------------------

