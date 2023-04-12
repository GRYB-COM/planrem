//---------------------------------------------------------------------------


#pragma hdrstop

#include "xml_configuration.h"
#include <manager\configuration.h>
#include <manager\is_manager.h>
#include <manager\configuration_io.h>
#include <manager\sys_id.h>
#include "unit\slownikos.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

XmlConfigManager::XmlConfigManager()
{
   try
   {
      allocate();

      loadConfigIO();
   }
   catch(...)
   {
      free();
      throw;
   }
}
//---------------------------------------------------------------------------

XmlConfigManager::~XmlConfigManager()
{
   free();
}
//---------------------------------------------------------------------------

void XmlConfigManager::allocate()
{
   m_config = new mng::Configuration(mng::Manager::instance().getConfiguration());

   m_fileName =  mng::Manager::instance().getConfigFile();

   m_configIO = new mng::ConfigurationIO(m_fileName, *m_config);

   m_confApp = m_config->getApplications();
}
//---------------------------------------------------------------------------

void XmlConfigManager::free()
{
   delete m_config;

   delete m_configIO;
}
//---------------------------------------------------------------------------

mng::Configuration XmlConfigManager::getConfig()
{
   return *m_config;
}
//---------------------------------------------------------------------------

void XmlConfigManager::loadConfigIO()
{
   m_configIO->load();
}
//---------------------------------------------------------------------------

AnsiString XmlConfigManager::getTitle()
{
   return m_config->getTitle();
}
//---------------------------------------------------------------------------

AnsiString XmlConfigManager::getOwner()
{
   return m_config->getOwner();
}
//---------------------------------------------------------------------------

AnsiString XmlConfigManager::getVersion()
{
   return m_config->getVersion();
}
//---------------------------------------------------------------------------

mng::Configuration::Applications XmlConfigManager::getApplications()
{
   return m_config->getApplications();
}
//---------------------------------------------------------------------------

void XmlConfigManager::saveIO()
{
   m_configIO->save();
}
//---------------------------------------------------------------------------

int XmlConfigManager::getCountOfApp()
{
   return m_confApp.size();
}
//---------------------------------------------------------------------------

AnsiString XmlConfigManager::getNameOfApp(int p_number)
{
   return m_confApp[p_number].getName();
}
//---------------------------------------------------------------------------

void XmlConfigManager::appendApplication(const SystemyKonfig::ComboSys& p_combo)
{
   m_confApp.append(p_combo.getSelected());
}
//---------------------------------------------------------------------------

void XmlConfigManager::setTitle(const AnsiString& p_title)
{
   m_config->setTitle(p_title);
}
//---------------------------------------------------------------------------

void XmlConfigManager::setOwner(const AnsiString& p_owner)
{
   m_config->setOwner(p_owner);
}
//---------------------------------------------------------------------------

void XmlConfigManager::setVersion(const AnsiString& p_version)
{
   m_config->setVersion(p_version);
}
//---------------------------------------------------------------------------

