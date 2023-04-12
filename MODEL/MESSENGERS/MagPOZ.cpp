//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagPOZ.h"
#include <sysutils.hpp>
#include "MagID.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
MagPOZ::MagPOZ(void)
:m_IsDefined(false),
 m_NrMag(-1),
 m_SygnMag(""),
 m_Wydzial(""),
 m_NrHarm(-1),
 m_MagID(new MagID() )
{


}
//---------------------------------------------------------------------------
MagPOZ::MagPOZ(const MagPOZ& _M)
:m_IsDefined(_M.m_IsDefined),
 m_NrMag(_M.m_NrMag),
 m_Wydzial(_M.m_Wydzial),
 m_NrHarm(_M.m_NrHarm),
 m_MagID(new MagID(*(_M.m_MagID )) )
{


}
//---------------------------------------------------------------------------
MagPOZ& MagPOZ:: operator=(const MagPOZ& _M)
{
 m_IsDefined =_M.m_IsDefined;
 m_NrMag     =_M.m_NrMag;
 m_Wydzial   =_M.m_Wydzial;
 m_NrHarm    =_M.m_NrHarm;
 *m_MagID    =*(_M.m_MagID );
 return * this;
}
//---------------------------------------------------------------------------
MagPOZ::~MagPOZ(void)
{
 delete m_MagID;
}
//---------------------------------------------------------------------------
 bool    MagPOZ::isDefined(void) const
{
  return m_IsDefined;
}
//---------------------------------------------------------------------------
MagID     MagPOZ::getIdMag(void) const
{
  return * m_MagID;
}
//---------------------------------------------------------------------------
int     MagPOZ::getNrMag(void) const
 {
  return m_NrMag;
 }
//---------------------------------------------------------------------------
int     MagPOZ::getRokMag(void) const
 {
  return m_RokMag;
 }
//---------------------------------------------------------------------------
String  MagPOZ::getSygnMag(void) const
 {
  return m_SygnMag;
 }
//---------------------------------------------------------------------------
String  MagPOZ::getWydzial(void) const
 {
  return m_Wydzial;
 }
//---------------------------------------------------------------------------
int     MagPOZ::getNrHarm(void) const
 {
  return m_NrHarm;
 }
 //---------------------------------------------------------------------------
void MagPOZ::set(const MagID& _MagID, const String& _SygnMag, const String& _Wydz, const int _NrHarm)
{
 *m_MagID    = _MagID;
 m_NrMag     = StrToIntDef(_SygnMag.SubString(1, _SygnMag.Pos("/") -1),0);
 m_RokMag    = StrToIntDef(_SygnMag.SubString(_SygnMag.Pos("/") +1, _SygnMag.Length() - _SygnMag.Pos("/") ),0);
 m_Wydzial   = _Wydz;
 m_NrHarm    = _NrHarm;
 m_IsDefined = true;

}
 //---------------------------------------------------------------------------
void MagPOZ::set(TDataSet* _DS)
{
  MagID _MagID;
  _MagID.IdMag      = _DS->FieldByName("ID_MAG")->AsInteger;
  _MagID.IdKomorki  = _DS->FieldByName("ID_KOMORKI")->AsInteger;
  _MagID.Rok        = _DS->FieldByName("ROK")->AsInteger;
  _MagID.Depozyt    = _DS->FieldByName("DEPOZYT")->AsString;
  _MagID.IsDefined  = true;
  set(
		_MagID,
		_DS->FieldByName("SYGN_MAG")->AsString,
		_DS->FieldByName("KOD_WYDZIALU")->AsString,
		_DS->FieldByName("NR_HARM")->AsInteger
	 );


}
 //---------------------------------------------------------------------------
