//---------------------------------------------------------------------------


#pragma hdrstop

#include "radios.h"
#include <dictionary_combo.h>
#include <dictionary_radio.h>
#include <manager\query_db.h>

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
**********/


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


