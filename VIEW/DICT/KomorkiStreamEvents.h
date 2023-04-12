//---------------------------------------------------------------------------

#ifndef KomorkiStreamEventsH
#define KomorkiStreamEventsH
#include "MANAGER\stream_db.h"
class KomorkiStreamEvents :public mng::EventsDefault{
virtual void beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied);
};
//---------------------------------------------------------------------------
#endif
