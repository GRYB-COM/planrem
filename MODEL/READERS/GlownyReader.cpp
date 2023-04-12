//---------------------------------------------------------------------------
#pragma hdrstop
#include "GlownyReader.h"
#include "GlownyID.h"
#include "MANAGER\QUERY_DB.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
msg::GlownyID  GlownyReader::read(void)
{
 mng::QueryDB _Q(" select * from pr_komorki where GLOWNY_K='T'   and  WARSZTAT='T'  order by KOD");
 _Q.open();
 if(_Q.isEmpty())
 {
  _Q.setQuery(" select k.* from pr_komorki k inner join pr_wydzialy w on w.ID_WYDZIALU=k.ID_WYDZIALU   where w.GLOWNY='T'  and k.WARSZTAT='T' and k.kod not in ('0/0', '-1/-1')  order by k.KOD");
  _Q.open();
 }
 if(_Q.isEmpty())  throw Exception("Brak ustawienia g³ównego wydzia³u. Nie mo¿na tworzyæ eksportów.\nKonieczny jest natychmiastowy kontakt z administratorem!");

 msg::GlownyID _Res;
 while(!_Q.isEof())
 {
  if(!_Res.isDefined()) _Res.m_WydzID = _Q.fieldByName("ID_WYDZIALU")->AsInteger;
  _Res.m_KomIDS.push_back(_Q.fieldByName("ID_KOMORKI")->AsInteger);
  _Q.next();
 }
 _Q.setQuery("select * from IS_PARAMS where ID_SYSTEMU=256 and SET_ID=1");
 _Q.open();
 _Res.m_BaseCode = _Q.fieldByName("SET_NAME")->AsString;
 _Q.close();
 return _Res;
}
//---------------------------------------------------------------------------
msg::GlownyID  GlownyReader::read(const String & _Ids, const String& _BaseCode)
{
 String _SQL(" select * from pr_komorki where  ");
		_SQL += " ID_KOMORKI IN ("  + _Ids + ") ORDER BY KOD ";
 mng::QueryDB _Q(_SQL);
 _Q.open();
 if(_Q.isEmpty())  throw Exception("Brak ustawienia g³ównego wydzia³u. Nie mo¿na tworzyæ eksportów.\nKonieczny jest natychmiastowy kontakt z administratorem!");

 msg::GlownyID _Res;
 while(!_Q.isEof())
 {
  if(!_Res.isDefined()) _Res.m_WydzID = _Q.fieldByName("ID_WYDZIALU")->AsInteger;
  _Res.m_KomIDS.push_back(_Q.fieldByName("ID_KOMORKI")->AsInteger);
  _Q.next();
 }
 _Res.m_BaseCode = _BaseCode;
 return _Res;
}
//---------------------------------------------------------------------------

