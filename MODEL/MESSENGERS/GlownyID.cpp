//---------------------------------------------------------------------------
#pragma hdrstop
#include "GlownyID.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
GlownyID::GlownyID(void)
:m_WydzID(-1)
{

}
//---------------------------------------------------------------------------
GlownyID::GlownyID(const GlownyID& _ID)
{
 operator=(_ID);
}
//---------------------------------------------------------------------------
GlownyID& GlownyID::operator=(const GlownyID& _ID)
{
 m_WydzID   = _ID.m_WydzID;
 m_KomIDS   = _ID.m_KomIDS;
 m_BaseCode = _ID.m_BaseCode;
 return *this;
}
//---------------------------------------------------------------------------
bool  GlownyID::isDefined(void)
{
 return m_WydzID.isDefined();
}
//---------------------------------------------------------------------------
GlownyID::iterator GlownyID::begin(void)
{
 return m_KomIDS.begin();
}
//---------------------------------------------------------------------------
GlownyID::const_iterator GlownyID::begin(void)const
{
 return m_KomIDS.begin();
}
//---------------------------------------------------------------------------
GlownyID::iterator GlownyID::end(void)
{
 return m_KomIDS.end();
}
//---------------------------------------------------------------------------
GlownyID::const_iterator GlownyID::end(void)const
{
 return m_KomIDS.end();
}
//---------------------------------------------------------------------------
WydzID GlownyID::getWydzID(void)const
{
 return m_WydzID;
}
//---------------------------------------------------------------------------
String GlownyID::getWydzCode(void)const
{
 return m_WydzID.getCode();
}
//---------------------------------------------------------------------------
String GlownyID::getWydzName(void)const
{
 return m_WydzID.getName();
}
//---------------------------------------------------------------------------
String GlownyID::getKomIDS(const String& _Sep)const
{
 String _Res;
 const_iterator _It= begin();
 for(_It;_It != end(); ++_It)
 {
  if(!_Res.IsEmpty()) _Res += _Sep;
  _Res += _It->getID();
 }
 return _Res;
}
//---------------------------------------------------------------------------
String GlownyID::getKomCodes(const String& _Sep)const
{
 String _Res;
 const_iterator _It= begin();
 for(_It;_It != end(); ++_It)
 {
  if(!_Res.IsEmpty()) _Res += _Sep;
  _Res += _It->getCode();
 }
 return _Res;
}
//---------------------------------------------------------------------------
String GlownyID::getKomNames(const String& _Sep)const
{
 String _Res;
 const_iterator _It= begin();
 for(_It;_It != end(); ++_It)
 {
  if(!_Res.IsEmpty()) _Res += _Sep;
  _Res += _It->getName();
 }
 return _Res;

}
//---------------------------------------------------------------------------
String GlownyID::getKomCM(const String& _Pause, const String& _Sep)const
{
 String _Res;
 const_iterator _It= begin();
 for(_It;_It != end(); ++_It)
 {
  if(!_Res.IsEmpty()) _Res += _Sep;
  _Res += _It->getCM(_Pause);
 }
 return _Res;

}
//---------------------------------------------------------------------------
String GlownyID::getWydzCM(const String& _Pause)const
{
 return  m_WydzID.getCM(_Pause);
}
//---------------------------------------------------------------------------
String GlownyID::getBaseCode(const String& _PostFix)const
{
 String _Res;
 if(!m_BaseCode.IsEmpty() ) _Res =  m_BaseCode+ _PostFix;
 return _Res;
}
//---------------------------------------------------------------------------

