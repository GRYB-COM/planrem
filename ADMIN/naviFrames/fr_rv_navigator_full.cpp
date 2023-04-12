//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fr_rv_navigator_full.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fr_rv_navigator_ext"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TRVFrmNavigatorFull
**********/


__fastcall TRVFrmNavigatorFull::TRVFrmNavigatorFull(TComponent* Owner)
   : TRVFrmNavigatorExt(Owner)
{
}
//---------------------------------------------------------------------------

__fastcall TRVFrmNavigatorFull::TRVFrmNavigatorFull(TComponent* Owner,TDataSource* source)
   : TRVFrmNavigatorExt(Owner,source)
{
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorFull::onUpdateButtons(bool has_data,bool is_editing)
{
   TRVFrmNavigatorExt::onUpdateButtons(has_data,is_editing);

   setVisible(sbCancel,m_visible && is_editing);
   setEnabled(sbCancel,is_editing);

   setVisible(sbPost,m_visible && is_editing);
   setEnabled(sbPost,is_editing);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorFull::DisableEditing()
{
   TRVFrmNavigatorExt::DisableEditing();

   setVisible(sbCancel,false);
   setVisible(sbPost,false);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorFull::EnableEditing()
{
   TRVFrmNavigatorExt::EnableEditing();

   setVisible(sbCancel,true);
   setVisible(sbPost,true);
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorFull::Post()
{
   if(sbPost->Enabled && isLinked())
   {
      getDataSet()->Post();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRVFrmNavigatorFull::Cancel()
{
   if(sbCancel->Enabled && isLinked())
   {
      getDataSet()->Cancel();
   }
}
//---------------------------------------------------------------------------


