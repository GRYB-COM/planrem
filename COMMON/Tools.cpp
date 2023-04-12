#pragma hdrstop
#include "Tools.h"
#include "globfunc.h"
#include "ISVARIA\varia.h"
#include "WydzialyDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progcommon;
//---------------------------------------------------------------------------
String Tools::prepareSygnKUT(const String & _S)
{
 String _Sygn;
 Globfunc::StringContainer _Cont;
 _Cont = Globfunc::explode(_S,"/");
 for(unsigned i =0; i<_Cont.size();i++)
 {
  if(i==0)
  {
   _Sygn = PadLeft(_Cont[i],4,'0');
  }
  else
  {
   _Sygn += String("/") + _Cont[i];
  }
 }
 return _Sygn;
}
//---------------------------------------------------------------------------
String Tools::prepareNewSygnKUT(const String & _S, const bool _Main, const String& _KodWydz)
{
 String _Sygn;
 String _Wydz;
 String _Rok;
 Globfunc::StringContainer _Cont;
 _Cont = Globfunc::explode(_S,"/");
 _Sygn = PadLeft(_Cont[0],4,'0') + String("/");
 _Sygn += _Main ? AnsiString("0") : _Cont[1];
 _Rok  = _Cont[2];
 if(_Rok.Length() == 2)
 {
  _Rok = String( 2000 + _Rok.ToIntDef(12));
 }
 _Sygn += String("/") + _Rok + String("/");
 TReplaceFlags _Fl;
 _Fl<<rfReplaceAll;
 _Wydz = StringReplace(_Cont[3],"W-","D",_Fl);
 _Wydz = StringReplace(_Wydz,"-","",_Fl);
 if(!_KodWydz.IsEmpty() && !dict::WydzialyDICT::instance().isWydzialOk(_Wydz))
 {
  _Wydz = _KodWydz;
 }
 _Sygn += _Wydz;
  if(_S.Pos("/S/") >0)   _Sygn+=String("/S");
  if(_S.Pos("/D/") >0)   _Sygn+=String("/D");
  if(_S.Pos("D-Z") >0) _Sygn +=  String("/Z");
 return _Sygn;
}
//---------------------------------------------------------------------------
String Tools::getMainSygnKUT(const String & _S)
{
 String _Sygn(_S);
 if(_Sygn[6] !='S' && _Sygn[6]!='D' && _S[6] !='0')
 {
  _Sygn[6]='0';
 }
 return _Sygn;
}
//--------------------------------------------------------------------------
