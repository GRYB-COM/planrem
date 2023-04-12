//---------------------------------------------------------------------------

#pragma hdrstop
#include "SlKomorkiStreamEvents.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void SlKomorkiStreamEvents::beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied)
{
  TProviderFlags pf;
  delta->FieldByName("KOD_WYD")->ProviderFlags = pf;
  delta->FieldByName("KOD_ODD")->ProviderFlags = pf;
}
//---------------------------------------------------------------------------

