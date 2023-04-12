//---------------------------------------------------------------------------

#ifndef ZlecRECH
#define ZlecRECH
#include <db.hpp>
#include "ZlecID.h"
#include "MagID.h"
namespace msg{
class ZlecREC{
 public:
 bool      IsDefined;
 ZlecID    IdZlec;
 MagID     IdMag;
 int       IdHarm;
 int       IdJedn;
 TDateTime DataWyst;
 void fillFromDS(TDataSet * DS);
 ZlecREC(void);
 ZlecREC(const ZlecREC& _ZlRec);
 ZlecREC& operator=(const ZlecREC& _ZlecREC);
};
}//end namespace msg
//---------------------------------------------------------------------------
#endif
