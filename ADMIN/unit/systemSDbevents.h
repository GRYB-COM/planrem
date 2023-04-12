//---------------------------------------------------------------------------
#ifndef systemSDbeventsH
#define systemSDbeventsH
#include <manager\stream_db.h>
#include <manager\table_updater.h>

//---------------------------------------------------------------------------
namespace mng
{
   class TransactionDB;
}

class SystemsSDB : public mng::EventsDefault
{
private:
   bool                m_czyApplied;

public:

   SystemsSDB();

   ~SystemsSDB();

   void beforeUpdateRecord(mng::StreamDB* str_db, TDataSet* source, TCustomClientDataSet* delta, TUpdateKind upd_kind, bool& applied);

   void SetApplied(bool);
};
#endif
