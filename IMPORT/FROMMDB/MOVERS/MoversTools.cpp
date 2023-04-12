//---------------------------------------------------------------------------
#pragma hdrstop
#include "MoversTools.h"
#include "MagID.h"
#include "ZlecID.h"
#include <dateutils.hpp>
#include "globfunc.h"
#include "KomorkiDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
msg::MagID MoversTools::makeMagID(TDataSet* _Source)
{
 //DEPOZYT
   String _Dep;
   if(_Source->FieldByName("P/N")->AsString =="D" || _Source->FieldByName("P/N")->AsString =="S")
   {
	_Dep = _Source->FieldByName("P/N")->AsString;
   }
   else
   {
	_Dep ="R";
   }
 //ROK
   int _Rok;
   _Rok = YearOf(_Source->FieldByName("Data dostarczenia")->AsDateTime);
 //NR KOL
   int _NrKol;
   Globfunc::StringContainer _Cont;
   Globfunc::StringContainer _ContMag;
   _Cont    = Globfunc::explode(_Source->FieldByName("Nr KUTa")->AsString,"/");
   _ContMag = Globfunc::explode(_Source->FieldByName("nr mag")->AsString,"/");
   if(_Rok < 2000) _Rok = 2000 + _ContMag[1].ToIntDef(-2001);
   if(_Rok < 2000) _Rok = 2000 + _Cont[2].ToIntDef(-2001);

   _NrKol = _Cont[0].ToIntDef(-1);
   if(_NrKol==-1)   _Source->FieldByName("nr kut")->AsInteger;
 //MAG iD
   msg::MagID _MagID;
   _MagID.NrMag      = _NrKol;
   _MagID.Depozyt    = _Dep;
   _MagID.Rok        = _Rok;
 //ID_KOMORKI
   if(_Cont[1]=="0" ||_Cont[1]=="D" ||_Cont[1]=="S")
   {
	_MagID.IdKomorki =  dict::KomorkiDICT::instance().getIdKomorki(_Source->FieldByName("Warsztat")->AsString);
   }
   else
   {
	String _Kod = _Source->FieldByName("Nr JW/ dla kogo")->AsString.SubString(2,3);
	_MagID.IdKomorki =  dict::KomorkiDICT::instance().getIdKomorki(_Kod);

   }

 _MagID.IsDefined  = true;

 return _MagID;

}
//---------------------------------------------------------------------------
msg::ZlecID MoversTools::makeZlecID(TDataSet* _Source)
{
 msg::MagID _MagID = makeMagID(_Source);
 Globfunc::StringContainer _Cont;
 _Cont = Globfunc::explode(_Source->FieldByName("Nr KUTa")->AsString,"/");
 msg::ZlecID _ZlecID;
	_ZlecID.RokMag       = _MagID.Rok;
	_ZlecID.IdKomorkiGlw = _MagID.IdKomorki;
	_ZlecID.NrMag        = _MagID.NrMag;
	_ZlecID.NrKol        = _Cont[1].ToIntDef(-1);
	_ZlecID.Rok          = 2000 + _Cont[2].ToIntDef(-2001);
	_ZlecID.IdKomorki    =  dict::KomorkiDICT::instance().getIdKomorki(_Source->FieldByName("Warsztat")->AsString);

}
