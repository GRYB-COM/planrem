//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_messengers_RBH4War.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
RBH4Mies & RBH4War::operator[](const int _War)
{
  return m_Cont[_War];
}
//---------------------------------------------------------------------------
void RBH4War::clear(void)
{
  m_Cont.clear();
  m_EtatyPr.clear();
}
//---------------------------------------------------------------------------
RBH4War::const_iterator RBH4War::begin(void) const
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4War::const_iterator RBH4War::end(void) const
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
RBH4War::iterator RBH4War::begin(void)
{
	return m_Cont.begin();
}
//---------------------------------------------------------------------------
RBH4War::iterator RBH4War::end(void)
{
	return m_Cont.end();
}
//---------------------------------------------------------------------------
void  RBH4War::add(const int _War, const int _Mies, const bool _AddEt, const String& _Kadra, const RBH& _RBH, const Currency& _EtPr)
{
 m_Cont[_War].add(_Mies,_Kadra,_RBH);
 if(_AddEt) m_EtatyPr[_War] += _EtPr;
}
//---------------------------------------------------------------------------
Currency RBH4War::getSum(const RBHType & _Type, const String& _Kadra, const int _MiesOd, const int _MiesDo) const
{
 Currency _Res;
 for(const_iterator _ItB=begin(); _ItB!=end(); _ItB++)
 {
  _Res += _ItB->second.getSum(_Type,_Kadra,_MiesOd,_MiesDo);
 }
 return _Res;
}
//---------------------------------------------------------------------------
Currency RBH4War::getEtPr(const int _War)
{
 return m_EtatyPr[_War];
}


