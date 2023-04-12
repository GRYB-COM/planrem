//---------------------------------------------------------------------------
#pragma hdrstop
#include "KomID.h"
#include "KomorkiDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
KomID::KomID(void)
:m_ID(-1)
{
}
//---------------------------------------------------------------------------
KomID::KomID(const KomID& _ID)
:m_ID(_ID.m_ID)
{
}
//---------------------------------------------------------------------------
KomID::operator int(void)
{
 return m_ID;
}
//---------------------------------------------------------------------------
KomID::KomID(const int _ID)
:m_ID(_ID)
{
}
//---------------------------------------------------------------------------
KomID& KomID::operator=(const KomID& _ID)
{
 m_ID =_ID.m_ID;
 return *this;
}
//---------------------------------------------------------------------------
int KomID::getID(void)const
{
 return m_ID;
}
//---------------------------------------------------------------------------
bool KomID::isDefined(void)const
{
 return m_ID >0 ;
}
//---------------------------------------------------------------------------
String KomID::getCode(void)const
{
 return dict::KomorkiDICT::instance().getKod(m_ID);
}
//---------------------------------------------------------------------------
String KomID::getName(void) const
{
 return dict::KomorkiDICT::instance().getName(m_ID);
}
//---------------------------------------------------------------------------
String KomID::getCM(const String& _Pause) const
{
 return dict::KomorkiDICT::instance().getKod(m_ID)+ _Pause + dict::KomorkiDICT::instance().getName(m_ID);
}

