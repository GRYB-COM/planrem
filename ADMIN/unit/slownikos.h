//---------------------------------------------------------------------------

#ifndef slownikosH
#define slownikosH
//#include <dictionary_combo.h>
#include <dictionary_radio.h>
//#include <manager\configuration.h>
#include <manager\sys_id.h>

//---------------------------------------------------------------------------

class TDMEditConfig;

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
/*
class SystemyKonfig
{
   public:

   //static Dictionary<mng::SysID> buildDictionary(const mng::Configuration&);

   class ComboSys : public DictionaryCombo<mng::SysID>
   {
	  public:

	  ComboSys(TComboBox*, const mng::Configuration&);

	  void rebuildDictionary(const mng::Configuration&);
   };
};
//---------------------------------------------------------------------------

class DataBaseKonfig
{
   public:

   static Dictionary<mng::ConnectionInfo::DbKind> buildDictionary();

   class ComboDB : public DictionaryCombo<mng::ConnectionInfo::DbKind>
   {
	  public:

	  ComboDB(TComboBox*);
   };
};
//---------------------------------------------------------------------------

class ProtocolKonfig
{
   public:

   static Dictionary<mng::ConnectionInfo::Protocol> buildDictionary();

   class Protocol : public DictionaryCombo<mng::ConnectionInfo::Protocol>
   {
	  public:

	  Protocol(TComboBox*);
   };
};
//---------------------------------------------------------------------------

class LibraryKonfig
{
   public:

   static Dictionary<mng::ConnectionInfo::LibType> buildDictionary();

   class Library : public DictionaryCombo<mng::ConnectionInfo::LibType>
   {
	  public:

	  Library(TComboBox*);
   };
}; */
//---------------------------------------------------------------------------

class GlbLacza
{
   public:


   static Dictionary<AnsiString> buildDictionary(TDMEditConfig*);

//   void allocate();

   class Lacza : public DictionaryCombo<AnsiString>
   {
      public:

      Lacza(TComboBox*, TDMEditConfig*);
   };
};
//---------------------------------------------------------------------------

#endif
