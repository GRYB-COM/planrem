//---------------------------------------------------------------------------

#ifndef dm_konfigH
#define dm_konfigH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <manager\configuration.h>
#include <manager\configuration_io.h>
#include "unit\defines.h"
//---------------------------------------------------------------------------

namespace mng
{
   class Configuration;

   class ConnectionInfo;

   class Parameters;

   class ConfigurationIO;
}

class Defines;

class TDMEditConfig : public TDataModule
{
__published:	// IDE-managed Components
   TClientDataSet *cdsConfiguration;
   TClientDataSet *cdsGlbLinks;
   TClientDataSet *cdsApplications;
   TClientDataSet *cdsLinks;
   TClientDataSet *cdsParamLink;
   TClientDataSet *cdsParam;
   TClientDataSet *cdsParamGlbLink;
   TDataSource *dsLinks;
   TDataSource *dsLaczaGlb;
   TDataSource *dsApplication;
   void __fastcall dsLinksDataChange(TObject *Sender, TField *Field);
   void __fastcall dsLaczaGlbDataChange(TObject *Sender, TField *Field);
   void __fastcall dsApplicationDataChange(TObject *Sender, TField *Field);
private:	// User declarations
   mng::Configuration m_konfig;
   AnsiString         m_file;
   AnsiString         m_idLacza;
   AnsiString         m_idLaczaGlb;
   int                m_idApp;

   void __fastcall loadConfig();

   void __fastcall loadLinks(const mng::Configuration::Links&, TClientDataSet*, TClientDataSet*, const int&, const Defines::VarriantOfParam&);

   void __fastcall loadParam(const mng::Parameters&, TClientDataSet*, const AnsiString&, const int&, const Defines::VarriantOfParam&);

   void __fastcall loadApp();

   void __fastcall copyConfToKonfig();

   void __fastcall copyAppToKonfig(mng::Configuration::Applications&);

   void __fastcall copyLinkToKonf(const Defines::VarriantOfLinks&, TClientDataSet*, mng::Configuration::Links&);

   void __fastcall copyParamToKonf(TClientDataSet*, mng::Parameters&);

   void __fastcall setConnection(mng::ConnectionInfo&, TClientDataSet*);

public:		// User declarations
   __fastcall TDMEditConfig(TComponent* Owner);

   void __fastcall DeleteLink();

   void __fastcall LocateGlbLinks(const AnsiString&);

   void __fastcall AppendGlbLinks();

   void __fastcall DeleteGlbLink();

   void __fastcall DeleteApp();

   void __fastcall SaveAll();

   bool __fastcall ValidateApp();

   void __fastcall LocateApp(int);

   bool __fastcall ValidateLink(TClientDataSet*);

   AnsiString __fastcall GetFileName();

   void __fastcall ChangesInGlbLink();

};
//---------------------------------------------------------------------------
#endif
