//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fr_rv_navigator_smpl.h"
#include <save_rest_man.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TRVFrmNavigatorSmpl
**********/


__fastcall TRVFrmNavigatorSmpl::TRVFrmNavigatorSmpl(TComponent* Owner)
   : TFrame(Owner), m_onStateChange(NULL), m_onDataChange(NULL), m_source(NULL),
     m_changing(false)
{
}
//---------------------------------------------------------------------------

__fastcall TRVFrmNavigatorSmpl::TRVFrmNavigatorSmpl(TComponent* Owner,TDataSource* source)
   : TFrame(Owner), m_onStateChange(NULL), m_onDataChange(NULL), m_source(NULL),
     m_changing(false)
{
   SetSource(source);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::onStateChange(TObject* sender)
{
   if(m_changing)
   {
      return;
   }

   if(m_onStateChange != NULL)
   {
      m_onStateChange(sender);
   }

   UpdateButtons();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::onDataChange(TObject* sender,TField* field)
{
   if(m_changing)
   {
      return;
   }

   if(m_onDataChange != NULL)
   {
      m_onDataChange(sender,field);
   }

   // wykorzystywane jest tylko przejœcie do nowego rekordu
   if(field == NULL)
   {
      UpdateButtons();
   }
}
//---------------------------------------------------------------------------

bool __fastcall TRVFrmNavigatorSmpl::isLinked()
{
   return m_source != NULL && m_source->DataSet != NULL;
}
//---------------------------------------------------------------------------

bool __fastcall TRVFrmNavigatorSmpl::isOpen()
{
   return isLinked() && m_source->DataSet->Active;
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::setEnabled(TSpeedButton* button,bool enabled)
{
   TAction* action=dynamic_cast<TAction*>(button->Action);

   if(action != NULL)
   {
      action->Enabled = enabled;
   }
   else
   {
      button->Enabled = enabled;
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::setVisible(TSpeedButton* button,bool visible)
{
   TAction* action=dynamic_cast<TAction*>(button->Action);

   if(action != NULL)
   {
      action->Visible = visible;
   }
   else
   {
      button->Visible = visible;
   }
}
//---------------------------------------------------------------------------

TDataSet* __fastcall TRVFrmNavigatorSmpl::getDataSet()
{
   return (m_source != NULL) ? m_source->DataSet : NULL;
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::onUpdateButtons(bool has_data,bool is_edited)
{
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::sbFirstClick(TObject *Sender)
{
   First();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::sbPriorClick(TObject *Sender)
{
   Prior();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::sbNextClick(TObject *Sender)
{
   Next();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::sbLastClick(TObject *Sender)
{
   Last();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::SetSource(TDataSource* source)
{
   SaveRestMan<bool> srm(m_changing,true);

   if(m_source != NULL)
   {
      m_source->OnStateChange = m_onStateChange;
      m_source->OnDataChange  = m_onDataChange;

      m_onStateChange = NULL;
      m_onDataChange  = NULL;
   }

   m_source = source;

   if(m_source != NULL)
   {
      m_onStateChange = m_source->OnStateChange;
      m_onDataChange  = m_source->OnDataChange;

      m_source->OnStateChange = onStateChange;
      m_source->OnDataChange  = onDataChange;
   }

   UpdateButtons();
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::DisableButtons()
{
   setEnabled(sbFirst,false);
   setEnabled(sbPrior,false);
   setEnabled(sbNext,false);
   setEnabled(sbLast,false);

   onUpdateButtons(false,false);
}
//------------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::EnableButtons()
{
   setEnabled(sbFirst,true);
   setEnabled(sbPrior,true);
   setEnabled(sbNext,true);
   setEnabled(sbLast,true);

   onUpdateButtons(true,true);
}
//------------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::UpdateButtons()
{
   bool has_data=false;
   bool is_editing=false;
   bool is_first=false;
   bool is_last=false;

   if(isLinked())
   {
      TDataSet* dset=m_source->DataSet;

      has_data   = !dset->IsEmpty();
      is_editing = dset->State == dsInsert || dset->State == dsEdit;
      is_first   = dset->Bof;
      is_last    = dset->Eof;
   }

   setEnabled(sbFirst,has_data && !is_editing && !is_first);
   setEnabled(sbPrior,has_data && !is_editing && !is_first);
   setEnabled(sbNext,has_data && !is_editing && !is_last);
   setEnabled(sbLast,has_data && !is_editing && !is_last);

   onUpdateButtons(has_data,is_editing);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::First()
{
   if(sbFirst->Enabled && isLinked())
   {
      m_source->DataSet->First();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::Prior()
{
   if(sbPrior->Enabled && isLinked())
   {
      m_source->DataSet->Prior();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::Next()
{
   if(sbNext->Enabled && isLinked())
   {
      m_source->DataSet->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorSmpl::Last()
{
   if(sbLast->Enabled && isLinked())
   {
      m_source->DataSet->Last();
   }
}
//---------------------------------------------------------------------------
