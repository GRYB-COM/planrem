//---------------------------------------------------------------------------
#pragma hdrstop
#include <db.hpp>
#include "ZlecID.h"
#include "SysUtils.hpp"
#include "KomorkiDICT.h"
#include "MagID.h"
#include "KomorkiDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
ZlecID::ZlecID(void)
:IsDefined(false),
 IdZlecenia(-1),
 IdKomorki(-1),
 IdKomorkiGlw(-1),
 NrKol(-1),
 Rok(-1),
 RokMag(-1),
 NrMag(-1)
{

}
//---------------------------------------------------------------------------
ZlecID::ZlecID(const MagID& _MagID)
:IsDefined(true),
 IdZlecenia(-1),
 IdKomorki(_MagID.IdKomorki),
 IdKomorkiGlw(_MagID.IdKomorki),
 NrKol(0),
 Rok(_MagID.Rok),
 RokMag(_MagID.Rok),
 NrMag(_MagID.NrMag)
{

}
//---------------------------------------------------------------------------
String  ZlecID::getSygn(const String& _Depozyt) const
{
 String _Res;
 if(IsDefined)
 {
  _Res = FormatFloat("#0000",NrMag)  + String("/") + String(NrKol)+   String("/") + String(Rok) +  String("/") + getKodWydz();
  if(!_Depozyt.IsEmpty())
  {
   _Res += String("/") + _Depozyt;
  }

 }
 return _Res;
}
//---------------------------------------------------------------------------
String ZlecID::getKodWydz(void) const
{
 String _Res;
 if(IdKomorkiGlw >0)
 {
   _Res = dict::KomorkiDICT::instance().getKodWydzialu(IdKomorkiGlw);
 }
 return _Res;
}
//---------------------------------------------------------------------------
void    ZlecID::fillFromDS(Db::TDataSet* _DS)
{
 IsDefined  = true;
 if(_DS->FindField("ID_ZLECENIA"))     IdZlecenia    = _DS->FieldByName("ID_ZLECENIA")->AsInteger;
 if(_DS->FindField("ID_KOMORKI"))      IdKomorki     = _DS->FieldByName("ID_KOMORKI")->AsInteger;
 if(_DS->FindField("ID_KOMORKI_GLW"))  IdKomorkiGlw  = _DS->FieldByName("ID_KOMORKI_GLW")->AsInteger;
 if(_DS->FindField("NR_KOL"))          NrKol         = _DS->FieldByName("NR_KOL")->AsInteger;
 if(_DS->FindField("ROK"))             Rok           = _DS->FieldByName("ROK")->AsInteger;
 if(_DS->FindField("ROK_MAG"))         RokMag        = _DS->FieldByName("ROK_MAG")->AsInteger;

 TField *_Fld;
 _Fld       = _DS->FindField("NR_MAG");
 if(_Fld)
 {
  int _NrMag;
  _NrMag = _Fld->AsString.ToIntDef(-1); //NR_MAG MO¯E BYÆ
  if(_NrMag >= 0) NrMag = _NrMag;
  else
  {
   NrMag = _Fld->AsString.SubString(1,3).ToIntDef(-1);
  }
 }
}
//---------------------------------------------------------------------------
void    ZlecID::setToDS(Db::TDataSet* _DS)
{
 if(IsDefined)
 {
  if(_DS->FindField("ID_ZLECENIA"))   _DS->FieldByName("ID_ZLECENIA")->AsInteger    = IdZlecenia;
  if(_DS->FindField("ID_KOMORKI"))    _DS->FieldByName("ID_KOMORKI")->AsInteger     = IdKomorki;
 if(_DS->FindField("ID_KOMORKI_GLW")) _DS->FieldByName("ID_KOMORKI_GLW")->AsInteger = IdKomorkiGlw;
  if(_DS->FindField("NR_KOL"))        _DS->FieldByName("NR_KOL")->AsInteger         = NrKol;
  if(_DS->FindField("ROK"))           _DS->FieldByName("ROK")->AsInteger            = Rok;
  if(_DS->FindField("ROK_MAG"))       _DS->FieldByName("ROK_MAG")->AsInteger        = Rok;
  TField * _Fld       = _DS->FindField("NR_MAG");
  if(_Fld) NrMag = _Fld->AsInteger;
 }
}
//---------------------------------------------------------------------------
ZlecID& ZlecID::operator=(const MagID& _MagID)
{
 IsDefined    = true;
 IdKomorki    = _MagID.IdKomorki;
 IdKomorkiGlw = _MagID.IdKomorki;
 Rok          = _MagID.Rok;
 RokMag       = _MagID.Rok;
 NrMag        = _MagID.NrMag;

  return * this;
}

