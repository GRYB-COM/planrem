//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fr_rv_navigator_ext.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fr_rv_navigator_smpl"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TRVFrmNavigatorExt
**********/


__fastcall TRVFrmNavigatorExt::TRVFrmNavigatorExt(TComponent* Owner)
   : TRVFrmNavigatorSmpl(Owner), m_visible(true)
{
}
//---------------------------------------------------------------------------

__fastcall TRVFrmNavigatorExt::TRVFrmNavigatorExt(TComponent* Owner,TDataSource* source)
   : TRVFrmNavigatorSmpl(Owner,source)
{
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::onUpdateButtons(bool has_data,bool is_editing)
{
   setEnabled(sbInfo,has_data && !is_editing);
   setEnabled(sbAppend,isOpen() && !is_editing);
   setEnabled(sbEdit,has_data && !is_editing);
   setEnabled(sbRemove,has_data && !is_editing);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::DisableEditing()
{
   setVisible(sbAppend,false);
   setVisible(sbEdit,false);
   setVisible(sbRemove,false);

   m_visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::EnableEditing()
{
   setVisible(sbAppend,true);
   setVisible(sbEdit,true);
   setVisible(sbRemove,true);

   m_visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::Append()
{
   if(sbAppend->Enabled && isLinked())
   {
      getDataSet()->Append();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::Edit()
{
   if(sbEdit->Enabled && isLinked())
   {
      getDataSet()->Edit();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorExt::Remove()
{
   if(sbRemove->Enabled && isLinked())
   {
      getDataSet()->Delete();
   }
}
//---------------------------------------------------------------------------

