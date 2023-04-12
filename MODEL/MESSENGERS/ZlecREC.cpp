//---------------------------------------------------------------------------
#pragma hdrstop
#include "ZlecREC.h"
#include <dateutils.hpp>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
ZlecREC::ZlecREC(void)
:IsDefined(false),
 IdMag(),
 IdZlec(),
 IdHarm(-1),
 IdJedn(-1),
 DataWyst(Date())
{

}
//---------------------------------------------------------------------------
ZlecREC::ZlecREC(const ZlecREC& _ZlecRec)
:IsDefined(_ZlecRec.IsDefined),
 IdMag(_ZlecRec.IdMag),
 IdZlec(_ZlecRec.IdZlec),
 IdHarm(_ZlecRec.IdHarm),
 IdJedn(_ZlecRec.IdJedn),
 DataWyst(_ZlecRec.DataWyst)
{

}
//---------------------------------------------------------------------------
ZlecREC& ZlecREC::operator=(const ZlecREC& _ZlecRec)
{
 IsDefined = _ZlecRec.IsDefined;
 IdMag     = _ZlecRec.IdMag;
 IdZlec    = _ZlecRec.IdZlec;
 IdHarm    = _ZlecRec.IdHarm;
 IdJedn    = _ZlecRec.IdJedn;
 DataWyst  = _ZlecRec.DataWyst;
 return * this;
}
//---------------------------------------------------------------------------
void ZlecREC::fillFromDS(TDataSet * DS)
{
 IsDefined = true;
 IdMag.fillFromDS(DS);
 IdZlec.fillFromDS(DS);
 if(IdZlec.RokMag >0) IdMag.Rok = IdZlec.RokMag;
 if(DS->FindField("ID_HARM") ) IdHarm = DS->FieldByName("ID_HARM")->AsInteger;
 else if(DS->FindField("ID_HARMONOGRAMU") ) IdHarm  = DS->FieldByName("ID_HARMONOGRAMU")->AsInteger;
 if(DS->FindField("DATA_WYST")) DataWyst = DS->FieldByName("DATA_WYST")->AsDateTime;
 else if(DS->FindField("DATA_PRZYJ")) DataWyst = DS->FieldByName("DATA_PRZYJ")->AsDateTime;
 else DataWyst = Date();
}
