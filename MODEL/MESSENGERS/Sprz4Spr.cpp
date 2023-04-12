//---------------------------------------------------------------------------
#pragma hdrstop
#include <db.hpp> //MUSI BYÆ PRZED G£ÓWNYM HEADEREM bo maniana z deklaracj¹
#include "Sprz4Spr.h"
#include <ISVARIA\varia.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
const int Sprz4Spr::M_ID_NP(999);
//---------------------------------------------------------------------------
Sprz4Spr::Key::Key(void)
 :IdWydz(-1),
  IdKom(-1),
  IdUsl(-1),
  Pozycja(-1),
  IdSprz(-1),
  IdRem(-1),
  IdHarm(-1)
 {

}
//---------------------------------------------------------------------------
bool Sprz4Spr::Key::operator<(const Key& _Key)const
{
 bool _Res;
 if(IdWydz == _Key.IdWydz)
 {
  if(IdKom == _Key.IdKom)
  {
   if(Pozycja == _Key.Pozycja)
   {
	if(IdUsl == _Key.IdUsl)
	{
	 if(IdSprz == _Key.IdSprz)
	 {
	  if(IdRem == _Key.IdRem)
	  {
			_Res = IdHarm   < _Key.IdHarm;
	  }
	  else  _Res = IdRem    < _Key.IdRem;
	 }
	 else   _Res = IdSprz   < _Key.IdSprz;
	}
	else    _Res = IdUsl    < _Key.IdUsl;
   }
   else     _Res = Pozycja  < _Key.Pozycja;
  }
  else      _Res = IdKom    < _Key.IdKom;
 }
 else       _Res = IdWydz   < _Key.IdWydz;
 return     _Res;
}
//---------------------------------------------------------------------------
Sprz4Spr::Key& Sprz4Spr::Key::fromDS(Db::TDataSet* _Ds)
{
 TField * _F;
 _F= _Ds->FindField("ID_WYDZIALU");
 if(_F) IdWydz = _F->AsInteger;
 _F= _Ds->FindField("ID_KOMORKI");
 if(_F) IdKom = _F->AsInteger;
 _F= _Ds->FindField("POZYCJA");
 if(_F) Pozycja = _F->AsInteger;
 _F= _Ds->FindField("ID_USLUGI");
 if(_F) IdUsl = _F->AsInteger;
 _F= _Ds->FindField("ID_SPRZETU");
 if(_F) IdSprz = _F->AsInteger;
 _F= _Ds->FindField("ID_REMONTU");
 if(_F) IdRem = _F->AsInteger;
 _F= _Ds->FindField("ID_HARMONOGRAMU");
 if(_F) IdHarm = _F->AsInteger;
 return *this;
}
//---------------------------------------------------------------------------
String Sprz4Spr::Key::toStr(void)
{
 String _Res("(");
 _Res +=String("W") + IdWydz + String(", ");
 _Res +=String("K") + IdKom  + String(", ");
 _Res +=String("P") + Pozycja+ String(", ");
 _Res +=String("U") + IdUsl  + String(", ");
 _Res +=String("S") + IdSprz + String(", ");
 _Res +=String("R") + IdRem  + String(", ");
 _Res +=String("H") + IdHarm + String(") ");
 return _Res;
}
//---------------------------------------------------------------------------
Sprz4Spr::Val& Sprz4Spr::Val::operator+=(const Val& _Val)
{
 IloscP  += _Val.IloscP;
 IloscR  += _Val.IloscR;
 IloscD  += _Val.IloscD;
 IloscND += _Val.IloscND;
 IloscRZPlanu  += _Val.IloscRZPlanu;
 IloscDZPlanu  += _Val.IloscDZPlanu;
 IloscNDZPlanu += _Val.IloscNDZPlanu;
 RBHP    += _Val.RBHP;
 RBHR    += _Val.RBHR;
 Info    += _Val.Info;
 if(Zad.Pos(_Val.Zad) == 0 ) Zad += _Val.Zad + " ";
 Info    += _Val.Info;
 IloscWR += _Val.IloscWR;
 IloscWRZPlanu += _Val.IloscWRZPlanu;
 if(IloscWRZPlanu < 0.00) IloscWRZPlanu = 0.0;
 return *this;
}
//---------------------------------------------------------------------------
Sprz4Spr::InfoBuff& Sprz4Spr::InfoBuff::operator+=(const InfoBuff& _Info)
{
 if(Plan.Pos(_Info.Plan)==0)
 {
  if(!Plan.IsEmpty() ) Plan += M_ROW_INFO_SEP;
  Plan +=  _Info.Plan;
 }
 if(Real.Pos(_Info.Real)==0)
 {
  if(!Real.IsEmpty()) Real += M_ROW_INFO_SEP;
  Real +=  _Info.Real;
 }
 return *this;
}
//---------------------------------------------------------------------------
Sprz4Spr::Val& Sprz4Spr::Val::fromDS(Db::TDataSet* _Ds, const bool _Plan)
{
 TField * _F;
 _F= _Ds->FindField("ILOSC_P");
 if(_F) IloscP = _F->AsCurrency;
 _F= _Ds->FindField("RBH_P");
 if(_F) RBHP = _F->AsCurrency;
 _F= _Ds->FindField("ILOSC_R");
 if(_F) IloscR = _F->AsCurrency;
 _F= _Ds->FindField("ILOSC_D");
 if(_F) IloscD = _F->AsCurrency;
 _F= _Ds->FindField("RBH_R");
 if(_F) RBHR = _F->AsCurrency;
 _F= _Ds->FindField("ZADANIE");
 if(_F) Zad = _F->AsString;
  //TUTAJ NIE MO¯E BYÆ IloscWR = IloscD - IloscR;
 //if(IloscWR < 0.00) IloscWR = 0.0;
 if(_Plan)
 {
  IloscDZPlanu =IloscD;
  IloscRZPlanu =IloscR;
 }
 else
 {
  IloscP       =0.0;
  IloscDZPlanu =0.0;
  IloscRZPlanu =0.0;
  //TUTAJ NIE MO¯E BYÆ IloscWRZPlanu=0.0;
  RBHP=0.0;
  Zad="";
 }
 Info.fromDS(_Ds);

 return *this;
}
//---------------------------------------------------------------------------
String Sprz4Spr::Val::toStr(void)
{
 String _Res("(");
 _Res += CurrToStr(IloscP) +String(", ");
 _Res += CurrToStr(RBHP)   +String(", ");
 _Res += CurrToStr(IloscR) +String(", ");
 _Res += CurrToStr(IloscRZPlanu) +String(", ");
 _Res += CurrToStr(IloscD) +String(", ");
 _Res += CurrToStr(IloscDZPlanu) +String(", ");
 _Res += CurrToStr(IloscND) +String(", ");
 _Res += CurrToStr(IloscNDZPlanu) +String(", ");
 _Res += CurrToStr(RBHR)   +String(") ");
 return _Res;
}
//---------------------------------------------------------------------------
bool Sprz4Spr::Val::isEmpty(void)
{
 return IloscP == 0.0 && RBHP==0.0 && IloscR ==0.0  && IloscD ==0.0  && IloscND ==0.0 && RBHR ==0.0;
}
//---------------------------------------------------------------------------
Currency Sprz4Spr::Val::getProcWR(void) const
{
 Currency _Res(0.00);
 if(IloscP !=0.00 && IloscWRZPlanu >0.00)
 {
  _Res = IloscWRZPlanu* 100/IloscP;
 }
 return _Res;
};
//---------------------------------------------------------------------------
Currency Sprz4Spr::Val::getProc(void) const
{
 Currency _Res(0.00);
 if(IloscP !=0.00 && IloscWR >0.00)
 {
  _Res = IloscWR* 100/IloscP;
 }
 return _Res;
};
//---------------------------------------------------------------------------
Currency Sprz4Spr::Val::getProcND(void) const
{
 Currency _Res(0.00);
 if(IloscP !=0.00 && IloscNDZPlanu >0.00)
 {
  _Res = IloscNDZPlanu* 100/IloscP;
 }
 return _Res;
};
//---------------------------------------------------------------------------
Currency Sprz4Spr::Val::getProcR(void) const
{
 Currency _Res(0.00);
 if(IloscP !=0.00 && IloscRZPlanu >0.00)
 {
  _Res = IloscRZPlanu* 100/IloscP;
 }
 return _Res;
};
//---------------------------------------------------------------------------
Currency Sprz4Spr::Val::getIloscWR(void)const
{
 return IloscWR;
}
//---------------------------------------------------------------------------
Sprz4Spr::InfoBuff& Sprz4Spr::InfoBuff::fromDS(Db::TDataSet* _DS)
{
 TField * _F;
 //PLAN
  _F = _DS->FindField("ID_HARMONOGRAMU");
  if(!_F) _F = _DS->FindField("ID_HARM");
  if(_F) Plan = _F->AsString + M_COL_INFO_SEP;
  _F = _DS->FindField("ILOSC_P");
  if(_F) Plan += PadLeft(FormatFloat("###,###,##0.00",_F->AsCurrency ),10) + M_COL_INFO_SEP;
  _F = _DS->FindField("RBH_P");
  if(_F) Plan += PadLeft(FormatFloat("###,###,##0.00",_F->AsCurrency),10 ) + M_COL_INFO_SEP;
 //REAL
   _F = _DS->FindField("SYGN_MAG");
   if(_F) Real += _F->AsString + String("    ") + M_COL_INFO_SEP;
   _F = _DS->FindField("SYGN_ZLECENIA");
   if(_F) Real += _F->AsString + String("    ") + M_COL_INFO_SEP;
   _F = _DS->FindField("ILOSC_R");
   if(_F) Real += PadLeft(FormatFloat("###,###,##0.00",_F->AsCurrency ),10) + M_COL_INFO_SEP;
   _F = _DS->FindField("RBH_R");
   if(_F) Real += PadLeft(FormatFloat("###,###,##0.00",_F->AsCurrency ),10) + M_COL_INFO_SEP;
  return *this;
}
//---------------------------------------------------------------------------
Sprz4Spr::iterator Sprz4Spr::begin(void)
{
  return m_Kont.begin();
}
//---------------------------------------------------------------------------
Sprz4Spr::const_iterator Sprz4Spr::begin(void) const
{
  return m_Kont.begin();
}
//---------------------------------------------------------------------------
Sprz4Spr::iterator Sprz4Spr::end(void)
{
  return m_Kont.end();
}
//---------------------------------------------------------------------------
Sprz4Spr::const_iterator Sprz4Spr::end(void) const
{
  return m_Kont.end();
}
//---------------------------------------------------------------------------
void Sprz4Spr::add(const Key& _Key, const Val& _Val,const InfoBuff& _Info)
{
 m_Kont[_Key]+=_Val;
}
//---------------------------------------------------------------------------
void Sprz4Spr::add(Db::TDataSet * _Ds, const InfoBuff& _Info)
{
 Key _Key;
 _Key.fromDS(_Ds);
 Val  _Val;
 _Val.fromDS(_Ds, _Key.getPlan());
 if(!_Val.isEmpty())
 {
  _Val.Info = _Info;
  add(_Key,_Val);
 }
}
//---------------------------------------------------------------------------
Sprz4Spr::Val& Sprz4Spr::operator[](const Key& _Key)
{
 return m_Kont[_Key];
}
//---------------------------------------------------------------------------
Sprz4Spr::Val& Sprz4Spr::operator[](TDataSet* _Ds)
{
 Key _Key;
 _Key.fromDS(_Ds);
 Val& _Val = m_Kont[_Key];
 _Val.fromDS(_Ds, _Key.getPlan());
 return _Val;
}
//---------------------------------------------------------------------------
Sprz4Spr::Val Sprz4Spr::sum(const  Key& _Key) const
{
 const_iterator _ItB = begin();
 const_iterator _ItE = end();
 bool _C;
 Val _Val;
 Currency _IlWR;
 for(_ItB;_ItB!=_ItE;++_ItB)
 {
  _C = _Key.IdUsl <0 || _Key.IdUsl == _ItB->first.IdUsl;
  _C = _C &&  (_Key.Pozycja <0 || _Key.Pozycja == _ItB->first.Pozycja);
  _C = _C &&  (_Key.IdWydz  <0 || _Key.IdWydz  == _ItB->first.IdWydz);
  _C = _C &&  (_Key.IdKom   <0 || _Key.IdKom   == _ItB->first.IdKom);
  _C = _C &&  (_Key.IdSprz  <0 || _Key.IdSprz  == _ItB->first.IdSprz);
  _C = _C &&  (_Key.IdRem   <0 || _Key.IdRem   == _ItB->first.IdRem);
  _C = _C &&  (_Key.IdHarm  <0 || _Key.IdHarm  == _ItB->first.IdHarm);
  if(_C)
  {
	_IlWR += _ItB->second.IloscWR;
	_Val  += _ItB->second;
  }
 }
 _Val.IloscWR = _IlWR;
 return _Val;
}
//---------------------------------------------------------------------------
int Sprz4Spr::size(void) const
{
 return m_Kont.size();
}
//---------------------------------------------------------------------------
void Sprz4Spr::clear(void)
{
  return m_Kont.clear();
}
//---------------------------------------------------------------------------
void Sprz4Spr::setWR(void)
{
 for(iterator _It(begin());_It!=end();++_It)
 {
  _It->second.IloscWR = _It->second.IloscD - _It->second.IloscR;
  if(_It->second.IloscWR <0.0) _It->second.IloscWR =0.0;
  if(_It->first.getPlan())
  {
   _It->second.IloscWRZPlanu = _It->second.IloscWR;
   _It->second.IloscND = _It->second.IloscP - _It->second.IloscD;
   if(_It->second.IloscND <0.00) _It->second.IloscND=0.00;
  _It->second.IloscNDZPlanu=   _It->second.IloscND;
  }
  else
  {
   _It->second.IloscND       = 0.0;
   _It->second.IloscWRZPlanu = 0.0;
   _It->second.IloscRZPlanu  =0.00;
   _It->second.IloscDZPlanu  =0.00;
   _It->second.IloscNDZPlanu =0.00;
  }
 }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//STA£E
const String Sprz4Spr::M_COL_INFO_SEP("@@@");
const String Sprz4Spr::M_ROW_INFO_SEP("###");

