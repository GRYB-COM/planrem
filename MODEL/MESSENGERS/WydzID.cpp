//---------------------------------------------------------------------------
#pragma hdrstop
#include "WydzID.h"
#include "WydzialyDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
WydzID::WydzID(void)
:m_ID(-1)
{
}
//---------------------------------------------------------------------------
WydzID::WydzID(const WydzID& _ID)
:m_ID(_ID.m_ID)
{
}
//---------------------------------------------------------------------------
WydzID::operator int(void)
{
 return m_ID;
}
//---------------------------------------------------------------------------
WydzID::WydzID(const int _ID)
:m_ID(_ID)
{
}
//---------------------------------------------------------------------------
WydzID& WydzID::operator=(const WydzID& _ID)
{
 m_ID =_ID.m_ID;
 return *this;
}
//---------------------------------------------------------------------------
int WydzID::getID(void)const
{
 return m_ID;
}
//---------------------------------------------------------------------------
bool WydzID::isDefined(void)const
{
 return m_ID >0 ;
}
//---------------------------------------------------------------------------
String WydzID::getCode(void)const
{
 return dict::WydzialyDICT::instance().getKod(m_ID);
}
//---------------------------------------------------------------------------
String WydzID::getName(void) const
{
 return dict::WydzialyDICT::instance().getName(m_ID);
}
//---------------------------------------------------------------------------
String WydzID::getCM(const String& _Pause) const
{
 return getCode() + _Pause + getName();
}
