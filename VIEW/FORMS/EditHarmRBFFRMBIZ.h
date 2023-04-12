//---------------------------------------------------------------------------

#ifndef EditHarmRBFFRMBIZH
#define EditHarmRBFFRMBIZH
#include "MANAGER\stream_db.h"
class EditHarmRBFFRMBIZ :public mng::EventsDefault{
 public:
	  virtual void beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied);
	  virtual void onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name);

};
//---------------------------------------------------------------------------
#endif
