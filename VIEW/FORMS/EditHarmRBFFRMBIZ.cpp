//---------------------------------------------------------------------------
#pragma hdrstop
#include "EditHarmRBFFRMBIZ.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void EditHarmRBFFRMBIZ::beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied)
{
 TProviderFlags _Fl;
 _Fl.Clear();
 _Fl << pfInUpdate;
 for(int i =0; i < delta->Fields->Count;++i)
 {
  delta->Fields->Fields[i]->ProviderFlags = _Fl;
 }
 _Fl.Clear();
 delta->FieldByName("NAZ_MIES")->ProviderFlags = _Fl;
 _Fl << pfInWhere <<pfInKey;
 delta->FieldByName("ID_HARMONOGRAMU_DET")->ProviderFlags = _Fl;


}
//---------------------------------------------------------------------------
void EditHarmRBFFRMBIZ::onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name)
{
 tab_name = "PR_HARMONOGRAM_DET";
}

