//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_messengers_RBH4Os.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
RBH & RBH4Os::operator[](const int _IdOsoby)
{
  return m_Cont[_IdOsoby];
}
//---------------------------------------------------------------------------
void RBH4Os::clear(void)
{
  m_Cont.clear();
}
//---------------------------------------------------------------------------
RBH4Os::const_iterator RBH4Os::begin(void) const
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Os::const_iterator RBH4Os::end(void) const
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
RBH4Os::iterator RBH4Os::begin(void)
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Os::iterator RBH4Os::end(void)
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
void  RBH4Os::add(const int _IdOsoby, const RBH& _RBH)
{
 m_Cont[_IdOsoby] +=_RBH;
}
//---------------------------------------------------------------------------
Currency RBH4Os::getSum(const RBHType & _Type) const
{
 Currency _Res;
 for(const_iterator _ItB=begin(); _ItB!=end(); _ItB++)
 {
  _Res += _ItB->second.getAsType(_Type);;
 }
 return _Res;
}


