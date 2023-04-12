//---------------------------------------------------------------------------


#pragma hdrstop

#include "slownikos.h"
#include <dictionary_combo.h>
#include <dictionary_radio.h>
#include <manager\query_db.h>
#include <manager\configuration.h>
#include <manager\connection_info.h>
#include "data_modul\dm_konfig.h"
#include <memory.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

Dictionary<char> StatusOper::buildDictionary()
{
   Dictionary<char> dict;

   dict.append('T',"Aktywny");
   dict.append('N',"Zawieszony");
   dict.append('B',"Zablokowany");

   return dict;
}
//---------------------------------------------------------------------------

StatusOper::RadioGrp::RadioGrp(TRadioGroup* p_radio)
   : DictionaryRadio<char>(p_radio, buildDictionary(), false)
{
}
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: WybSystem
**********


WybSystem::ComboSys::ComboSys(TComboBox* p_combo)
   :  DictionaryCombo<mng::SysID>(p_combo, buildDictionary(), false)
{
}
//---------------------------------------------------------------------------

Dictionary<mng::SysID> WybSystem::buildDictionary()
{
   Dictionary<mng::SysID> dict;

   dict.append(mng::SysID(),"Wszystkie systemy");

   mng::QueryDB query_sys;

   query_sys.open("SELECT ID_SYSTEMU, NAZWA, OPIS FROM IS_REJESTR");

   while(!query_sys.isEof())
   {
      dict.append(query_sys.fieldByName("ID_SYSTEMU")->AsInteger, query_sys.fieldByName("NAZWA")->AsString);

      query_sys.next();
   }

   return dict;
}
//---------------------------------------------------------------------------

/**********
*  Funkcje sk³adowe klasy: SystemyKonfig



SystemyKonfig::ComboSys::ComboSys(TComboBox* p_combo, const mng::Configuration& p_konfig)
   :  DictionaryCombo<mng::SysID>(p_combo, buildDictionary(p_konfig), false)
{
}
//---------------------------------------------------------------------------

Dictionary<mng::SysID> SystemyKonfig::buildDictionary(const mng::Configuration& p_konfig)
{
   Dictionary<mng::SysID> dict;

   dict.clear();

   mng::QueryDB query_sys;

   query_sys.open("SELECT ID_SYSTEMU, NAZWA, OPIS FROM IS_REJESTR");

   while(!query_sys.isEof())
   {
	  int id_sys = query_sys.fieldByName("ID_SYSTEMU")->AsInteger;

	  if(!p_konfig.hasApplication(id_sys))
	  {
		 dict.append(id_sys, query_sys.fieldByName("NAZWA")->AsString);
	  }

	  query_sys.next();
   }

   return dict;
}
//---------------------------------------------------------------------------

void SystemyKonfig::ComboSys::rebuildDictionary(const mng::Configuration& p_konfig)
{
   mng::QueryDB query_sys;

   query_sys.open("SELECT ID_SYSTEMU, NAZWA, OPIS FROM IS_REJESTR");

   while(!query_sys.isEof())
   {
	  int id_sys = query_sys.fieldByName("ID_SYSTEMU")->AsInteger;

	  if(p_konfig.hasApplication(id_sys))
	  {
		 reset();
	  }

	  query_sys.next();
   }
 }
//---------------------------------------------------------------------------

DataBaseKonfig::ComboDB::ComboDB(TComboBox* p_combo)
   : DictionaryCombo<mng::ConnectionInfo::DbKind>(p_combo, buildDictionary(), false)
{
}
//---------------------------------------------------------------------------

Dictionary<mng::ConnectionInfo::DbKind> DataBaseKonfig::buildDictionary()
{
   Dictionary<mng::ConnectionInfo::DbKind> dict;

   dict.append(mng::ConnectionInfo::dbkNone, mng::ConnectionInfo::toString(mng::ConnectionInfo::dbkNone));

   dict.append(mng::ConnectionInfo::dbkInterbase, mng::ConnectionInfo::toString(mng::ConnectionInfo::dbkInterbase));

   dict.append(mng::ConnectionInfo::dbkOracle, mng::ConnectionInfo::toString(mng::ConnectionInfo::dbkOracle));

   return dict;
}
//---------------------------------------------------------------------------

ProtocolKonfig::Protocol::Protocol(TComboBox* p_combo)
   : DictionaryCombo<mng::ConnectionInfo::Protocol>(p_combo, buildDictionary(), false)
{
}
//---------------------------------------------------------------------------

Dictionary<mng::ConnectionInfo::Protocol> ProtocolKonfig::buildDictionary()
{
   Dictionary<mng::ConnectionInfo::Protocol> dict;

   dict.append(mng::ConnectionInfo::prkNone, mng::ConnectionInfo::toString(mng::ConnectionInfo::prkNone));

   dict.append(mng::ConnectionInfo::prkTCPIP, mng::ConnectionInfo::toString(mng::ConnectionInfo::prkTCPIP));

   dict.append(mng::ConnectionInfo::prkNetBUI, mng::ConnectionInfo::toString(mng::ConnectionInfo::prkNetBUI));

   dict.append(mng::ConnectionInfo::prkFile, mng::ConnectionInfo::toString(mng::ConnectionInfo::prkFile));

   return  dict;
}
//---------------------------------------------------------------------------

LibraryKonfig::Library::Library(TComboBox* p_combo)
   : DictionaryCombo<mng::ConnectionInfo::LibType>(p_combo, buildDictionary(), false)
{
}
//---------------------------------------------------------------------------

Dictionary<mng::ConnectionInfo::LibType> LibraryKonfig::buildDictionary()
{
   Dictionary<mng::ConnectionInfo::LibType> dict;

   dict.append(mng::ConnectionInfo::cltNone, mng::ConnectionInfo::toString(mng::ConnectionInfo::cltNone));

   dict.append(mng::ConnectionInfo::cltDBX, mng::ConnectionInfo::toString(mng::ConnectionInfo::cltDBX));

   dict.append(mng::ConnectionInfo::cltIBX, mng::ConnectionInfo::toString(mng::ConnectionInfo::cltIBX));

   dict.append(mng::ConnectionInfo::cltADO, mng::ConnectionInfo::toString(mng::ConnectionInfo::cltADO));

   dict.append(mng::ConnectionInfo::cltBDE, mng::ConnectionInfo::toString(mng::ConnectionInfo::cltBDE));

   return dict;
}
//---------------------------------------------------------------------------

GlbLacza::Lacza::Lacza(TComboBox* p_combo, TDMEditConfig* p_konf)
   : DictionaryCombo<AnsiString>(p_combo, buildDictionary(p_konf), false)
{
}
//---------------------------------------------------------------------------

Dictionary<AnsiString> GlbLacza::buildDictionary(TDMEditConfig* p_konfig)
{
   Dictionary<AnsiString> dict;

   AnsiString ident, nazwa;

   p_konfig->cdsGlbLinks->First();

   while(!p_konfig->cdsGlbLinks->Eof)
   {
      ident = p_konfig->cdsGlbLinks->FieldByName("ID")->AsString;

      nazwa = p_konfig->cdsGlbLinks->FieldByName("NAME")->AsString;

      dict.append(ident,nazwa);

      p_konfig->cdsGlbLinks->Next();
   }

   return dict;

}
//---------------------------------------------------------------------------
*/

