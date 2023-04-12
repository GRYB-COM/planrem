//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_messengers_RBH4Mies.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
RBH4Kadra & RBH4Mies::operator[](const int _Mies)
{
  return m_Cont[_Mies];
}
//---------------------------------------------------------------------------
void RBH4Mies::clear(void)
{
  m_Cont.clear();
}
RBH4Mies::const_iterator RBH4Mies::begin(void) const
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Mies::const_iterator RBH4Mies::end(void) const
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
RBH4Mies::iterator RBH4Mies::begin(void)
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Mies::iterator RBH4Mies::end(void)
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
void  RBH4Mies::add(const int _NrMies, const Currency& _PlanRBH)
{
 m_Cont[_NrMies].add(_PlanRBH);
}
//---------------------------------------------------------------------------
void  RBH4Mies::add(const int _Mies, const String& _Kadra, const RBH& _RBH)
{
  m_Cont[_Mies].add(_Kadra,_RBH);
}
//---------------------------------------------------------------------------
Currency RBH4Mies::getSum(const RBHType & _Type, const String& _Kadra, const int _MiesOd, const int _MiesDo) const
{
 Currency _Res;
 bool _C;
 for(const_iterator _ItB=begin(); _ItB!=end(); _ItB++)
 {
  _C = _MiesOd ==0 || _ItB->first >= _MiesOd;
  _C = _C && (_MiesDo ==0 || _ItB->first <= _MiesDo);
  if(_C) _Res += _ItB->second.getSum(_Type,_Kadra);
 }
 return _Res;
}



