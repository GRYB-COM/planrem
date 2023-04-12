//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_messengers_RBH4Kadra.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
RBH & RBH4Kadra::operator[](const String& _Kadra)
{
  return m_Cont[_Kadra];
}
//---------------------------------------------------------------------------
void RBH4Kadra::clear(void)
{
  m_Cont.clear();
  m_PlanRBH = 0.0;
}
//---------------------------------------------------------------------------
RBH4Kadra::const_iterator RBH4Kadra::begin(void) const
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Kadra::const_iterator RBH4Kadra::end(void) const
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
RBH4Kadra::iterator RBH4Kadra::begin(void)
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4Kadra::iterator RBH4Kadra::end(void)
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
void  RBH4Kadra::add(const Currency& _PlanRBH)
{
 m_PlanRBH  += _PlanRBH;
}
//---------------------------------------------------------------------------
void  RBH4Kadra::add(const String& _Kadra, const RBH& _RBH)
{
 m_Cont[_Kadra] += _RBH;
}
//---------------------------------------------------------------------------
Currency RBH4Kadra::getSum(const RBHType & _Type,const String& _Kadra) const
{
 Currency _Res;
 if(_Type ==msg::rtPlan)
 {
  _Res = m_PlanRBH;
 }
 else
 {
  bool _C;
  for(const_iterator _ItB=begin(); _ItB!=end(); _ItB++)
  {
   _C = _Kadra.IsEmpty() ||  _ItB->first == _Kadra;
   if(_C) _Res += _ItB->second.getAsType(_Type);
  }
 }
 return _Res;
}



