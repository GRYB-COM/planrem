//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagID.h"
#include "SysUtils.hpp"
#include "KomorkiDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
MagID::MagID(void)
:IsDefined(false),
 IdMag(-1),
 NrMag(-1),
 IdKomorki(-1),
 Rok(-1)
{

}
//---------------------------------------------------------------------------
String  MagID::getSygnMag(void) const
{
 String _Res;
 if(IsDefined)
 {
  _Res = FormatFloat("#000",NrMag)  + String("/") + String(Rok) +  String("/") + Depozyt;
 }
 return _Res;
}
//---------------------------------------------------------------------------
int MagID::getIdWydzialu(void) const
{
 int _Res(-1);
 if(IsDefined)
 {
  _Res = dict::KomorkiDICT::instance().getIdWydzialu(IdKomorki);
 }
 return _Res;
}
//---------------------------------------------------------------------------
void    MagID::fillFromDS(TDataSet* _DS)
{
 IsDefined = true;
 if(_DS->FindField("ID_MAG") )     IdMag     = _DS->FieldByName("ID_MAG")->AsInteger;
 if(_DS->FindField("ROK") )        Rok       = _DS->FieldByName("ROK")->AsInteger;
 if(_DS->FindField("DEPOZYT") )    Depozyt   = _DS->FieldByName("DEPOZYT")->AsString;
 if(_DS->FindField("ID_KOMORKI") ) IdKomorki = _DS->FieldByName("ID_KOMORKI")->AsInteger;
 if(_DS->FindField("NR_MAG") )
 {
  String StrNrMag     = _DS->FieldByName("NR_MAG")->AsString;
  NrMag = StrNrMag.ToIntDef(-1);
  if(NrMag == -1 && StrNrMag.Pos("/") >0 )
  {
	StrNrMag = StrNrMag.SubString(1,StrNrMag.Pos("/")-1);
    NrMag = StrNrMag.ToIntDef(-1);
  }
 }
 if(_DS->FindField("ID_HARM") ) IdHarm = _DS->FieldByName("ID_HARM")->AsInteger;
}
//---------------------------------------------------------------------------
void    MagID::setToDS(TDataSet* _DS) const
{
 if(_DS->FindField("ID_MAG") )     _DS->FieldByName("ID_MAG")->AsInteger     = IdMag;
 if(_DS->FindField("ROK") )        _DS->FieldByName("ROK")->AsInteger        = Rok;
 if(_DS->FindField("DEPOZYT") )    _DS->FieldByName("DEPOZYT")->AsString     = Depozyt;
 if(_DS->FindField("ID_KOMORKI") ) _DS->FieldByName("ID_KOMORKI")->AsInteger = IdKomorki;
 if(_DS->FindField("NR_MAG") )     _DS->FieldByName("NR_MAG")->AsInteger     = NrMag;

}
//---------------------------------------------------------------------------
void    MagID::setToPars(TParams* _Pars) const
{
 if(_Pars->FindParam("ID_MAG") )     _Pars->ParamByName("ID_MAG")->AsInteger     = IdMag;
 if(_Pars->FindParam("ROK") )        _Pars->ParamByName("ROK")->AsInteger        = Rok;
 if(_Pars->FindParam("DEPOZYT") )    _Pars->ParamByName("DEPOZYT")->AsString     = Depozyt;
 if(_Pars->FindParam("ID_KOMORKI") ) _Pars->ParamByName("ID_KOMORKI")->AsInteger = IdKomorki;
 if(_Pars->FindParam("NR_MAG") )     _Pars->ParamByName("NR_MAG")->AsInteger     = NrMag;

}
//---------------------------------------------------------------------------
String  MagID::getKodWydz(void)
{
  String _Res;
 if(IsDefined)
 {
   _Res = dict::KomorkiDICT::instance().getKodWydzialu(IdKomorki);
 }
 return _Res;
}


