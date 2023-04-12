//---------------------------------------------------------------------------

#ifndef xml_configurationH
#define xml_configurationH
//---------------------------------------------------------------------------
#include <manager\configuration.h>
#include <manager\is_manager.h>
#include <manager\configuration_io.h>
#include <manager\sys_id.h>
#include "unit\slownikos.h"
//---------------------------------------------------------------------------

class XmlConfigManager
{
public:

   XmlConfigManager();
   ~XmlConfigManager();

   mng::Configuration getConfig();

   AnsiString getTitle();

   AnsiString getOwner();

   AnsiString getVersion();

   mng::Configuration::Applications getApplications();

   void saveIO();

   void appendApplication(const SystemyKonfig::ComboSys&);

   int getCountOfApp();

   AnsiString getNameOfApp(int);

   void setTitle(const AnsiString&);

   void setOwner(const AnsiString&);

   void setVersion(const AnsiString&);

private:

   mng::Configuration*               m_config;
   mng::ConfigurationIO*             m_configIO;
   AnsiString                        m_fileName;
   mng::Configuration::Applications  m_confApp; 

   void allocate();

   void free();

   void loadConfigIO();
};

#endif
