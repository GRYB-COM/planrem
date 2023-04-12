//---------------------------------------------------------------------------


#pragma hdrstop
#include "KomorkiStreamEvents.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
void KomorkiStreamEvents::beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied)
{
 TProviderFlags _Fl;
 delta->FieldByName("KOD_WYD")->ProviderFlags = _Fl;
 delta->FieldByName("KOD_ODD")->ProviderFlags = _Fl;
}
