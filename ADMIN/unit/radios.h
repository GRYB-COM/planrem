//---------------------------------------------------------------------------

#ifndef radiosH
#define radiosH
#include <dictionary_combo.h>
#include <dictionary_radio.h>
#include <manager\sys_id.h>
//---------------------------------------------------------------------------

class StatusOper
{
public:

   static Dictionary<char> buildDictionary();


   class RadioGrp : public DictionaryRadio<char>
   {
   public:

      RadioGrp(TRadioGroup*);

   };

};
//---------------------------------------------------------------------------

class WybSystem
{
   public:

   static Dictionary<mng::SysID> buildDictionary();

   class ComboSys : public DictionaryCombo<mng::SysID>
   {
      public:

      ComboSys(TComboBox*);

    };
};
//---------------------------------------------------------------------------
#endif
