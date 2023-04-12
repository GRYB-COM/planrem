//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "Ad_metadane.h"
#include "platform.h"
#include <manager\is_manager.h>
#include <memory>
#include <manager\table_updater.h>
#include <DateUtils.hpp>
#include "unit\systemSDbevents.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace mng;

SystemInstaller::SystemInstaller(int sys_id, const AnsiString& path, const AnsiString& query_str)
   : m_sys_id(sys_id), m_path(path), m_query_str(query_str)
{
}
//---------------------------------------------------------------------------

SystemInstaller::~SystemInstaller()
{
/*
   for (Iterator it(m_systems.begin()); it!=m_systems.end(); ++it)
   {
      delete *it;
      *it = NULL;
   }
*/
}
//---------------------------------------------------------------------------

int SystemInstaller::getSysId()
{
   return m_sys_id.getID();
}
//---------------------------------------------------------------------------

AnsiString SystemInstaller::getPath()
{
   return m_path;
}
//---------------------------------------------------------------------------

AnsiString SystemInstaller::getName()
{
   return m_sys_id.name();
}
//---------------------------------------------------------------------------

bool SystemInstaller::isInstalled(std::vector<int>& p_vectorID)
{
   bool bOk = false;

   for(std::vector<int>::iterator iter = p_vectorID.begin();iter != p_vectorID.end(); ++iter)
   {
      if(*iter == getSysId())
      {
         bOk = true;

         break;
      }
   }
   return bOk;
}
//---------------------------------------------------------------------------

void SystemInstaller::registerSystem(SystemInstaller* sys)
{
   m_systems.push_back(sys);
}
//---------------------------------------------------------------------------

void SystemInstaller::installSystem(std::vector<int>& p_vectorID, int p_sysId, mng::StreamDB* p_source)
{
   if (!isInstalled(p_vectorID))
   {
      //systemy poglegle
      for (ConstIterator it(m_systems.begin()); it!=m_systems.end(); ++it)
         (*it)->installSystem(p_vectorID, p_sysId, p_source);

      if(p_sysId == getSysId())
      {
//         mng::MessageDialog::information(getName()+" "+IntToStr(p_sysId), "UUU",MB_OK);

         std::auto_ptr<mng::TableMan> tab_query (new mng::TableMan("IS_REJESTR", true, "ID_SYSTEMU", "PATH;ACT_KEY", NULL));

         tab_query->execute(ukInsert, p_source->getClient(), false, false, NULL);
      }
      else
      {
         std::auto_ptr<mng::QueryDB> query (new mng::QueryDB(m_query_str));

//         mng::MessageDialog::information(getName()+" "+query->getQuery(), "UUU",MB_OK);
         query->execute();
      }

      appendIdSys(p_vectorID, getSysId());

      try
      {
//         mng::MessageDialog::information(getName()+" "+m_path, "UUU",MB_OK);
         Platform::instance().updateDatabase(getSysId(), AnsiString(ExtractFileDir(Application->ExeName) + "\\" + m_path));
      }
      catch (...)
      {
         mng::Manager::instance().showException("B³¹d podczas tworzenia tabel");
      }
   }
}
//---------------------------------------------------------------------------

void SystemInstaller::appendIdSys(std::vector<int>& p_vectorID, int p_idSys)
{
   std::vector<int>::iterator itor = std::find(p_vectorID.begin(), p_vectorID.end(), p_idSys);

   if(itor == p_vectorID.end())
   {
      p_vectorID.push_back(getSysId());
   }

}
//---------------------------------------------------------------------------

Metadane::Metadane()
{
   int year_sys = YearOf(Date());
   AnsiString year_s = IntToStr(year_sys);
   
   //stworzenie obiektow i rejestracja drzewa
   /*SystemInstaller* */tempsys1 = new SystemInstaller(SI_BO, "bo", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(9999,'Baza Osobowa','Baza Osobowa',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys2 = new SystemInstaller(SI_Rejestr, "rv", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(16384,'Rejestr VAT','Rejestr sprzeda¿y i zakupów',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys3 = new SystemInstaller(SI_EWGIBUD, "eg", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(29,'EWGIBUD','Ewidencja Gruntów i Budynków',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys4 = new SystemInstaller(SI_KsZob, "kz", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(8,'KSZOB','Ksiêgowoœæ podatków i op³at',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys10 = new SystemInstaller(SI_EDG, "edg", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(26,'EDG','Ewidencja dzia³alnoœci gospodarczej',"+year_s+",'060910')");
   /*SystemInstaller* */tempsys11 = new SystemInstaller(SI_DodMieszk, "dm", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(36,'DodMieszk','Dodatki mieszkaniowe',"+year_s+",'060922')");

   tempsys2->registerSystem(tempsys1);
   tempsys3->registerSystem(tempsys1);
   tempsys4->registerSystem(tempsys1);
   tempsys10->registerSystem(tempsys1);
   tempsys11->registerSystem(tempsys1);

   /*SystemInstaller* */tempsys5 = new SystemInstaller(SI_Auta, "au", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(24,'Auta','Podatek transportowy',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys6 = new SystemInstaller(SI_OpLok, "ol", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(22,'OPLOK','Op³aty lokalne',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys7 = new SystemInstaller(SI_Dzierzawy, "dz", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(18,'Dzier¿awy','System wymiaru dzier¿aw, najmu i u¿yczenia',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys8 = new SystemInstaller(SI_JGU, "jgu", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(32,'JGU','Podatek od nieruchomoœci JGU',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys9 = new SystemInstaller(SI_Podatki, "pd", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES(4096,'Podatki','Podatki',"+year_s+",'050511')");

   /*SystemInstaller* */tempsys12 = new SystemInstaller(SI_Budzet, "b", "INSERT INTO IS_REJESTR(id_systemu,nazwa,opis,rok,dbversion) VALUES (128,'Bud¿et','Ksiêgowoœæ bud¿etowa',"+year_s+",'090511')");
   /*SystemInstaller* */tempsys13 = new SystemInstaller(SI_KASA, "ka", "INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) VALUES (256,'Kasa','Kasa',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys14 = new SystemInstaller(SI_Mater, "mat", "INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) VALUES (131072,'Materia³y','Materia³y',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys15 = new SystemInstaller(SI_OpSkarb, "os", "INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) VALUES (512,'OPSKARB','Op³aty skarbowe',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys16 = new SystemInstaller(SI_PrPlan,"pp2","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (2048,'ProjPlan','Projektowanie planu',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys17 = new SystemInstaller(SI_Przelewy,"prz","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (27,'Przelewy','Przelewy',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys18 = new SystemInstaller(SI_Srodek,"st","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (262144,'Œrodki','Œrodki trwa³e',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys19 = new SystemInstaller(SI_IPEPN,"rdk","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (30,'Integracja','Integracyjna Platforma Elektroniczna',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys20 = new SystemInstaller(SI_UPROKS,"upk","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (37,'UPROKS','Uniwersalny Program Ksiêguj¹cy',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys21 = new SystemInstaller(SI_UzytkWiecz,"uw","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (19,'Uz wiecz','U¿ytkowanie wieczyste',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys22 = new SystemInstaller(SI_Inkasent,"zi","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (33,'Inkasent','Rozliczenie inkasentów',"+year_s+",'050511')");
   /*SystemInstaller* */tempsys23 = new SystemInstaller(SI_Woda,"wo","INSERT INTO IS_REJESTR (id_systemu,nazwa,opis,rok,dbversion) values (20,'Woda','Woda',"+year_s+"','050511')");

   tempsys5->registerSystem(tempsys4);
   tempsys6->registerSystem(tempsys4);
   tempsys7->registerSystem(tempsys4);
   tempsys7->registerSystem(tempsys3);
   tempsys8->registerSystem(tempsys4);
   tempsys8->registerSystem(tempsys3);
   tempsys9->registerSystem(tempsys4);
   tempsys9->registerSystem(tempsys3);
   tempsys13->registerSystem(tempsys1);
   tempsys15->registerSystem(tempsys1);
   tempsys18->registerSystem(tempsys10);
   tempsys20->registerSystem(tempsys4);
   tempsys20->registerSystem(tempsys12);
   tempsys20->registerSystem(tempsys19);
   tempsys21->registerSystem(tempsys4);
   tempsys21->registerSystem(tempsys10);
   tempsys21->registerSystem(tempsys2);
   tempsys23->registerSystem(tempsys4);
   tempsys23->registerSystem(tempsys2);
   tempsys23->registerSystem(tempsys22);


   registerSystem(tempsys2);
   registerSystem(tempsys3);
   registerSystem(tempsys5);
   registerSystem(tempsys6);
   registerSystem(tempsys7);
   registerSystem(tempsys10);
   registerSystem(tempsys11);

   registerSystem(tempsys1);
   registerSystem(tempsys4);
   registerSystem(tempsys8);
   registerSystem(tempsys9);
   registerSystem(tempsys12);
   registerSystem(tempsys13);
   registerSystem(tempsys14);
   registerSystem(tempsys15);
   registerSystem(tempsys16);
   registerSystem(tempsys17);
   registerSystem(tempsys18);
   registerSystem(tempsys19);
   registerSystem(tempsys20);
   registerSystem(tempsys21);
   registerSystem(tempsys22);
   registerSystem(tempsys23);
}
//---------------------------------------------------------------------------

Metadane::~Metadane()
{
   delete tempsys1;
   delete tempsys2;
   delete tempsys3;
   delete tempsys4;
   delete tempsys5;
   delete tempsys6;
   delete tempsys7;
   delete tempsys8;
   delete tempsys9;
   delete tempsys10;
   delete tempsys11;

   delete tempsys12;
   delete tempsys13;
   delete tempsys14;
   delete tempsys15;
   delete tempsys16;
   delete tempsys17;
   delete tempsys18;
   delete tempsys19;
   delete tempsys20;
   delete tempsys21;
   delete tempsys22;
   delete tempsys23;

/*
   for (Iterator it(m_systems.begin()); it!=m_systems.end(); ++it)
   {
      delete *it;
      *it = NULL;
   }
*/
}
//---------------------------------------------------------------------------
/*
int Metadane::chooseSystem()
{
   int id = 0;
   TfmChooseSystem* win = new TfmChooseSystem(NULL, this);
   if (win->ShowModal()==mrOk)
   {
      for (ConstIterator it(m_systems.begin()); it!=m_systems.end(); ++it)
         if ((*it)->getName()==win->getSystemName()) return (*it)->getSysId();
   }
   delete win;
   return id;
}
//---------------------------------------------------------------------------

TStrings* Metadane::systemList()
{
   TStringList* lista = new TStringList;
   for (ConstIterator it(m_systems.begin()); it!=m_systems.end(); ++it) lista->Add((*it)->getName());
   lista->Sort();
   return lista;
}                                                                            */
//---------------------------------------------------------------------------

void Metadane::registerSystem(SystemInstaller* sys)
{
   m_systems.push_back(sys);
}
//---------------------------------------------------------------------------

void Metadane::installSystem(int p_sysID, std::vector<int>& p_vectorID, mng::StreamDB* p_source, SystemsSDB* p_sysEvents)
{
   bool czy_applied(false);

   if (p_sysID!=0)
   {
      for (ConstIterator it(m_systems.begin()); it!=m_systems.end(); ++it)
         if ((*it)->getSysId()==p_sysID)
         {
            (*it)->installSystem(p_vectorID, p_sysID, p_source);

            czy_applied = true;
         }
   }

      p_sysEvents->SetApplied(czy_applied); 
}
//---------------------------------------------------------------------------

