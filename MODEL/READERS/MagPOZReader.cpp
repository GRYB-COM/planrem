//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagPOZReader.h"
#include "MANAGER\queries.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MagID.h"
#include "MagPOZ.h"
#include "globfunc.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
msg::MagPOZ MagPOZReader::read(const msg::MagID& _MagID)
{
 mng::Query _Q(" pr_magazyn m ", " m.*");
 _Q.attachWherePred(new mng::ComparePredicate( " m.ID_MAG ",     _MagID.IdMag ));
 _Q.attachWherePred(new mng::ComparePredicate( " m.ROK ",        _MagID.Rok ));
 _Q.attachWherePred(new mng::ComparePredicate( " m.ID_KOMORKI ", _MagID.IdKomorki ));
 _Q.attachWherePred(new mng::ComparePredicate( " m.DEPOZYT ",   AnsiString("'") +  _MagID.Depozyt + AnsiString("'")  ));
 sgda::DAReader _R(sgda::ctQueryDB);
 _R.setQuery(_Q);
 _R.open();
 msg::MagPOZ _Res;
 _Res.m_IsDefined = true;
 _Res.set(_R.getDataSet());
 return _Res;
}
//---------------------------------------------------------------------------
