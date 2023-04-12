//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dm_konfig.h"
#include <manager\configuration.h>
#include <manager\is_manager.h>
#include <manager\configuration_io.h>
#include <manager\sys_id.h>
#include <manager\connection_info.h>
#include "unit\defines.h"
#include <manager\is_cipher.h>
#include <manager\sys_id.h>
#include <memory.h>
#include <manager\message_dlg.h>
#include <manager\various_man.h>
#include <manager\connection_db.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TDMEditConfig
**********/


__fastcall TDMEditConfig::TDMEditConfig(TComponent* Owner)
   : TDataModule(Owner), m_file(mng::Manager::instance().getConfigFile()),
   m_konfig(mng::Manager::instance().getConfiguration())
{
   mng::ConfigurationIO(m_file, m_konfig).load();

   cdsConfiguration->CreateDataSet();

   cdsGlbLinks->CreateDataSet();

   cdsParamGlbLink->CreateDataSet();

   cdsLinks->CreateDataSet();

   cdsParamLink->CreateDataSet();

   cdsParam->CreateDataSet();

   cdsApplications->CreateDataSet();

   loadConfig();

   loadLinks(m_konfig.getLinks(), cdsGlbLinks, cdsParamGlbLink, NULL, Defines::parGlbLinks);

   loadApp();

   cdsGlbLinks->First();

   cdsApplications->First();

}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::loadConfig()
{
   cdsConfiguration->Append();

   cdsConfiguration->FieldByName("TITLE")->AsString = m_konfig.getTitle();

   cdsConfiguration->FieldByName("OWNER")->AsString = m_konfig.getOwner();

   cdsConfiguration->FieldByName("VERSION")->AsString = m_konfig.getVersion();

   cdsConfiguration->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::loadLinks(const mng::Configuration::Links& p_link, TClientDataSet* p_data, TClientDataSet* p_dataP, const int& p_idApp, const Defines::VarriantOfParam& p_variant)
{
   int count_links = p_link.size();

   for(int curr_link = 0; curr_link < count_links;++curr_link)
   {
      p_data->Append();

      mng::ConnectionInfo con_info = p_link.operator[](curr_link)->getConnection();

      if(p_variant == Defines::parLinkApp)
      {
         p_data->FieldByName("IDAPP")->AsInteger = p_idApp;

         p_data->FieldByName("ISREFER")->AsBoolean = p_link.operator[](curr_link)->isReference();
      }

      p_data->FieldByName("ID")->AsString = con_info.getID();

      p_data->FieldByName("NAME")->AsString = con_info.getName();

      p_data->FieldByName("KIND")->AsString = Defines::kindToStr(con_info.getKind());

      p_data->FieldByName("PROTOCOL")->AsString = Defines::protocolToStr(con_info.getProtocol());

      p_data->FieldByName("ALIAS")->AsString = con_info.getAlias();

      p_data->FieldByName("USER")->AsString = con_info.getUser();

      p_data->FieldByName("PASSWORD")->AsString = mng::CipherBase::instance().decipher(con_info.getPassw());

      p_data->FieldByName("CHARSET")->AsString = con_info.getCharSet();

      p_data->FieldByName("DIALECT")->AsString = con_info.getDialect();

      p_data->FieldByName("VENDORLIB")->AsString = con_info.getVendorLib();

      p_data->FieldByName("OWNER")->AsString = con_info.getOwner();

      loadParam(con_info.getParameters(), p_dataP, con_info.getID(), p_idApp, p_variant);

      p_data->Post();
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::loadParam(const mng::Parameters& p_par, TClientDataSet* p_data, const AnsiString& p_idLink, const int& p_idApp, const Defines::VarriantOfParam& p_variant)
{
   int count_par = p_par.size();

   for(int curr_param = 0;curr_param < count_par;++curr_param)
   {
      mng::Parameter par = p_par.operator[](curr_param);

      p_data->Append();

      if(p_variant == Defines::parGlbLinks || p_variant == Defines::parLinkApp)
      {
         p_data->FieldByName("IDLINK")->AsString = p_idLink;
      }

      if(p_variant == Defines::parLinkApp || p_variant == Defines::parApp)
      {
         p_data->FieldByName("IDAPP")->AsInteger = p_idApp;
      }

      p_data->FieldByName("KEY")->AsString = par.getKey();

      p_data->FieldByName("VALUE")->AsString = par.getValue();

      p_data->FieldByName("NAME")->AsString = par.getName();

      p_data->FieldByName("FORCE")->AsBoolean  = par.forceWrite();

      p_data->FieldByName("LIBTYPE")->AsString = Defines::libToStr(par.getLibType());

      p_data->Post();
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::loadApp()
{
   mng::Configuration::Applications xml_app = m_konfig.getApplications();

   int count_app = xml_app.size();

   for(int curr_app = 0;curr_app < count_app;++curr_app)
   {
      cdsApplications->Append();

      mng::SysID sys_id = xml_app[curr_app].getID();

      cdsApplications->FieldByName("SYSID")->AsInteger = sys_id.getID();

      cdsApplications->FieldByName("NAME")->AsString = xml_app[curr_app].getName();

      cdsApplications->FieldByName("KEY")->AsString = xml_app[curr_app].getKey();

      loadLinks(xml_app[curr_app].getLinks(), cdsLinks, cdsParamLink, xml_app[curr_app].getID(), Defines::parLinkApp);

      loadParam(xml_app[curr_app].getParameters(), cdsParam, NULL, xml_app[curr_app].getID(), Defines::parApp);

      cdsApplications->Post();
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::DeleteLink()
{
   try
   {
      int id_app = cdsLinks->FieldByName("IDAPP")->AsInteger;

      AnsiString id_link = cdsLinks->FieldByName("ID")->AsString;

      cdsLinks->Delete();

      AnsiString filter = "IDAPP = "+IntToStr(id_app);

      filter += " AND IDLINK = '"+id_link+"'";

      cdsParamLink->Filter = filter;

      cdsParamLink->Filtered = true;

      cdsParamLink->First();

      while(!cdsParamLink->Eof)
      {
         cdsParamLink->Delete();
      }

      cdsParamLink->Filtered = false;

      cdsParamLink->First();

//      cdsLinks->First();
   }
   catch(...)
   {
      mng::Manager::instance().showException("B³¹d podczas usuwania ³¹cza");
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::LocateGlbLinks(const AnsiString& p_idLink)
{
   Variant arr[1];
   arr[0] = p_idLink;

   TLocateOptions opt;
   opt.Clear();

   cdsGlbLinks->Locate("ID", VarArrayOf(arr,0), opt);

}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::AppendGlbLinks()
{
   cdsLinks->Append();

   cdsLinks->FieldByName("ISREFER")->AsBoolean = true;
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::DeleteGlbLink()
{
   AnsiString id_link = cdsGlbLinks->FieldByName("ID")->AsString;

   AnsiString filter = "IDLINK = '"+id_link+"'";

   cdsParamGlbLink->Filter = filter;

   cdsParamGlbLink->Filtered = true;

   cdsParamGlbLink->First();

   while(!cdsParamGlbLink->Eof)
   {
      cdsParamGlbLink->Delete();
   }

   cdsParamGlbLink->Filtered = false;

   filter = "ID = '"+id_link+"'";

   filter += " AND ISREFER = true";

   cdsLinks->Filter = filter;

   cdsLinks->Filtered = true;

   cdsLinks->First();

   while(!cdsLinks->Eof)
   {
      cdsLinks->Delete();
   }

   cdsLinks->Filtered = false;

   cdsGlbLinks->Delete();

}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::DeleteApp()
{
   try
   {
      AnsiString filter;

      filter = "IDAPP = " + IntToStr(cdsApplications->FieldByName("SYSID")->AsInteger);

      cdsLinks->Filter = filter;

      cdsLinks->Filtered = true;

      cdsLinks->First();

      while(!cdsLinks->Eof)
      {
         DeleteLink();
      }

      cdsLinks->Filtered = false;

      cdsLinks->First();

      cdsParam->Filter = filter;

      cdsParam->Filtered = true;

      cdsParam->First();

      while(!cdsParam->Eof)
      {
         cdsParam->Delete();
      }

      cdsParam->Filtered = false;

      cdsParam->First();

      cdsApplications->Delete();

      cdsApplications->First();
   }

   catch(const Exception& exc)
   {
      mng::Manager::instance().showException(exc.Message);
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::SaveAll()
{
   try
   {
      copyConfToKonfig();

      mng::Configuration::Applications& xml_app = m_konfig.getApplications();

      mng::Configuration::Links& glb_links= m_konfig.getLinks();

      copyAppToKonfig(xml_app);

      copyLinkToKonf(Defines::glbLinks, cdsGlbLinks, glb_links);

      mng::ConfigurationIO(m_file, m_konfig).save();
   }

   catch(...)
   {
      mng::Manager::instance().showException("B³¹d podczas zapisywania danych konfiguracyjnych");
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::copyConfToKonfig()
{
   m_konfig.setOwner(cdsConfiguration->FieldByName("OWNER")->AsString);

   m_konfig.setTitle(cdsConfiguration->FieldByName("TITLE")->AsString);

   m_konfig.setVersion(cdsConfiguration->FieldByName("VERSION")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::copyAppToKonfig(mng::Configuration::Applications& my_app)
{
   cdsApplications->First();

   my_app.clear();

   int curr_app(0);

   while(!cdsApplications->Eof)
   {
      mng::SysID sys_id(cdsApplications->FieldByName("SYSID")->AsInteger);

      my_app.append(sys_id);

      my_app[curr_app].setKey(cdsApplications->FieldByName("KEY")->AsString);

      my_app[curr_app].setName(cdsApplications->FieldByName("NAME")->AsString);

      mng::Configuration::Links& link_app =  my_app[curr_app].getLinks();

      int id_app = sys_id.getID();

      cdsLinks->Filter = "IDAPP = " + IntToStr(id_app);

      cdsLinks->Filtered = true;

      copyLinkToKonf(Defines::appLinks, cdsLinks, link_app);

      cdsLinks->Filtered = false;

      cdsParam->Filter = "IDAPP = " + IntToStr(id_app);

      cdsParam->Filtered = true;

      mng::Parameters& par_app = my_app[curr_app].getParameters();

      copyParamToKonf(cdsParam, par_app);

      cdsParam->Filtered = false;

      cdsApplications->Next();

      ++curr_app;
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::copyLinkToKonf(const Defines::VarriantOfLinks& p_vlink, TClientDataSet* p_cdata, mng::Configuration::Links& p_link)
{
   p_link.clear();

   p_cdata->First();

   std::auto_ptr<mng::Configuration::Link> my_link (new mng::Configuration::Link());

   while(!p_cdata->Eof)
   {
      mng::ConnectionInfo con_info = my_link->getConnection();

      my_link->setID(p_cdata->FieldByName("ID")->AsString);

      setConnection(con_info, p_cdata);

      mng::Parameters& param = con_info.getParameters();

      if(p_vlink == Defines::glbLinks)
      {
         cdsParamGlbLink->Filter = "IDLINK = '" + p_cdata->FieldByName("ID")->AsString +"'";

         cdsParamGlbLink->Filtered = true;

         copyParamToKonf(cdsParamGlbLink, param);

         cdsParamGlbLink->Filtered = false;
      }
      else
      {
         int id_app = cdsApplications->FieldByName("SYSID")->AsInteger;

         AnsiString id_link = p_cdata->FieldByName("ID")->AsString;

         AnsiString filter = "IDAPP = " + IntToStr(id_app);

         filter += " AND IDLINK = '" + id_link + "'";

         cdsParamLink->Filter = filter;

         cdsParamLink->Filtered = true;

         copyParamToKonf(cdsParamLink, param);

         cdsParamLink->Filtered = false;
      }

      my_link->setConnection(con_info);

      if(p_vlink == Defines::appLinks && p_cdata->FieldByName("ISREFER")->AsBoolean == true)
      {
         AnsiString id_link = p_cdata->FieldByName("ID")->AsString;

         AnsiString name_link = p_cdata->FieldByName("NAME")->AsString;

         mng::Configuration::LinkRef* my_linkRef = new mng::Configuration::LinkRef(id_link, name_link, my_link->clone());

         p_link.append(my_linkRef->clone());

         delete my_linkRef;
      }
      else
      {
         p_link.append(my_link->clone());
      }

      p_cdata->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::copyParamToKonf(TClientDataSet* p_data, mng::Parameters& p_param)
{
   p_param.clear();

   p_data->First();

   while(!p_data->Eof)
   {
      AnsiString key = p_data->FieldByName("KEY")->AsString;

      AnsiString value = p_data->FieldByName("VALUE")->AsString;

      AnsiString name = p_data->FieldByName("NAME")->AsString;

      bool force = p_data->FieldByName("FORCE")->AsBoolean;

      AnsiString lib_type = p_data->FieldByName("LIBTYPE")->AsString;

      mng::Parameter curr_par(key, value, name, force, lib_type);

      p_param.append(curr_par);

      p_data->Next();
   }
}
//---------------------------------------------------------------------------

bool __fastcall TDMEditConfig::ValidateApp()
{
   bool zwr_war(true);

   int id_app = cdsApplications->FieldByName("SYSID")->AsInteger;

   mng::ControlsMan cm(cdsApplications);

   cdsApplications->First();

   while(!cdsApplications->Eof)
   {
      AnsiString filter = "IDAPP = "+IntToStr(cdsApplications->FieldByName("SYSID")->AsInteger);

      cdsLinks->Filter = filter;

      cdsLinks->Filtered = true;

      cdsLinks->First();

      bool is_found = cdsLinks->Eof ? false : true;

      cdsLinks->Filtered = false;

      if(!is_found)
      {
         zwr_war = false;

         mng::MessageDialog::warning("Brak ³¹cz dla aplikacji: "+cdsApplications->FieldByName("NAME")->AsString.Trim(),"Kontrola poprawnoœci danych",MB_OK);

         break;
      }

      cdsApplications->Next();
   }

   LocateApp(id_app);


   return zwr_war;
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::LocateApp(int p_idApp)
{
   Variant app[1];

   app[0] = Variant(p_idApp);

   TLocateOptions opts;

   opts.Clear();

   opts << loPartialKey;

   cdsApplications->Locate("SYSID", VarArrayOf(app,0), opts);
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::setConnection(mng::ConnectionInfo& p_conInfo, TClientDataSet* p_cdata)
{
   p_conInfo.setName(p_cdata->FieldByName("NAME")->AsString);

   p_conInfo.setKind(mng::ConnectionInfo::convertToDbKind(p_cdata->FieldByName("KIND")->AsString));

   p_conInfo.setProtocol(mng::ConnectionInfo::convertToProtocol(p_cdata->FieldByName("PROTOCOL")->AsString));

   p_conInfo.setAlias(p_cdata->FieldByName("ALIAS")->AsString);

   p_conInfo.setUser(p_cdata->FieldByName("USER")->AsString);

   p_conInfo.setPassw(mng::CipherBase::instance().cipher(p_cdata->FieldByName("PASSWORD")->AsString));

   p_conInfo.setCharSet(p_cdata->FieldByName("CHARSET")->AsString);

   p_conInfo.setDialect(p_cdata->FieldByName("DIALECT")->AsString);

   AnsiString ve_lib = p_cdata->FieldByName("VENDORLIB")->AsString;

   if(ve_lib == "Nieokreœlony")
   {
      ve_lib = "";
   }

   p_conInfo.setVendorLib(ve_lib);

   p_conInfo.setOwner(p_cdata->FieldByName("OWNER")->AsString);

}
//---------------------------------------------------------------------------

bool __fastcall TDMEditConfig::ValidateLink(TClientDataSet* p_data)
{
   bool zwr_war = true;

   mng::ConnectionInfo con_info;

   setConnection(con_info, p_data);

   try
   {
      std::auto_ptr<mng::ConnectionDB> conn(mng::ConnectionDB::create(mng::ConnectionInfo::cltDBX));

      conn->connect(con_info);

      conn->disconnect();
   }
   catch(const Exception& exc)
   {

//      mng::Manager::instance().showException("B³¹d podczas zapisu ³¹cza");

      if(mng::MessageDialog::warning("Nieudana próba po³¹czenia z baz¹ danych.\n" + exc.Message + "\nCzy zapisaæ ³¹cze mimo zg³oszonego b³êdu ?","Kontrola danych",MB_YESNO)==ID_NO)
      {
         zwr_war = false;
      }

   }


   return zwr_war;
}
//---------------------------------------------------------------------------

AnsiString __fastcall TDMEditConfig::GetFileName()
{
   return m_file;
}
//---------------------------------------------------------------------------


void __fastcall TDMEditConfig::dsLinksDataChange(TObject *Sender,
      TField *Field)
{
   AnsiString filter;

   if(cdsLinks->FieldByName("ISREFER")->AsBoolean)
   {
      filter = "IDLINK = '" + cdsLinks->FieldByName("ID")->AsString + "'";
   }
   else
   {
      filter = "IDAPP = " + IntToStr(cdsLinks->FieldByName("IDAPP")->AsInteger);

      filter += " AND IDLINK = '" + cdsLinks->FieldByName("ID")->AsString + "'";
   }

   if(Field == NULL)
   {
      // zmiana rekordu (kursor przeszed³ na inny rekord)
      // nale¿y zmieniæ warunek filtruj¹cy rekordy z parametrami
      if(cdsLinks->FieldByName("ISREFER")->AsBoolean)
      {
         cdsParamGlbLink->Filter = filter;

         cdsParamGlbLink->Filtered = true;
      }
      else
      {
         cdsParamLink->Filter = filter;

         cdsParamLink->Filtered = true;

         m_idLacza = cdsLinks->FieldByName("ID")->AsString;
      }

   }
   else
   {
      if(Field->FieldName.CompareIC("ID") == 0)
      {
         // zmiana identyfikatora ³¹cza - zmodyfikowaæ rekordy z parametrami,
         // zastosowaæ nowy filtr

         if(!cdsLinks->FieldByName("ISREFER")->AsBoolean)
         {

            mng::ControlsMan mn(cdsParamLink);

            cdsParamLink->Filtered =  false;

            AnsiString id_link = cdsLinks->FieldByName("ID")->AsString;

            cdsParamLink->First();

            while(!cdsParamLink->Eof)
            {
               if(cdsParamLink->FieldByName("IDLINK")->AsString == m_idLacza)
               {
                  cdsParamLink->Edit();

                  cdsParamLink->FieldByName("IDLINK")->AsString = id_link;

                  cdsParamLink->Post();
               }

                  cdsParamLink->Next();
            }

            m_idLacza = cdsLinks->FieldByName("ID")->AsString;

            cdsParamLink->Filter = filter;

            cdsParamLink->Filtered = true;

            cdsParamLink->First();
         }
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TDMEditConfig::dsLaczaGlbDataChange(TObject *Sender,
      TField *Field)
{
   AnsiString filter = "IDLINK = '" + cdsGlbLinks->FieldByName("ID")->AsString + "'";

   if(Field == NULL)
   {
      cdsParamGlbLink->Filter = filter;

      cdsParamGlbLink->Filtered = true;

      m_idLaczaGlb = cdsGlbLinks->FieldByName("ID")->AsString;
   }
   else
   {
      if(Field->FieldName.CompareIC("ID") == 0)
      {
         mng::ControlsMan mng(cdsParamGlbLink);

         cdsParamGlbLink->Filtered = false;

         cdsParamGlbLink->First();

         while(!cdsParamGlbLink->Eof)
         {
            if(cdsParamGlbLink->FieldByName("IDLINK")->AsString == m_idLaczaGlb)
            {
               cdsParamGlbLink->Edit();

               cdsParamGlbLink->FieldByName("IDLINK")->AsString = cdsGlbLinks->FieldByName("ID")->AsString;

               cdsParamGlbLink->Post();
            }

            cdsParamGlbLink->Next();

         }

         cdsParamGlbLink->Filter = filter;

         cdsParamGlbLink->Filtered = true;

         cdsParamGlbLink->First();

         mng::ControlsMan mnd(cdsLinks);

         AnsiString filtr_ref = cdsLinks->Filter;

         bool czy_filtr = cdsLinks->Filtered;

         cdsLinks->First();

         while(!cdsLinks->Eof)
         {
            if(cdsLinks->FieldByName("ID")->AsString == m_idLaczaGlb && cdsLinks->FieldByName("ISREFER")->AsBoolean)
            {
               cdsLinks->Edit();

               cdsLinks->FieldByName("ID")->AsString = cdsGlbLinks->FieldByName("ID")->AsString;

               cdsLinks->Post();
            }

            cdsLinks->Next();
         }

         cdsLinks->Filter = filtr_ref;

         cdsLinks->Filtered = czy_filtr;

         cdsLinks->First();

         m_idLaczaGlb = cdsGlbLinks->FieldByName("ID")->AsString;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMEditConfig::ChangesInGlbLink()
{
   mng::ControlsMan mn(cdsLinks);

   AnsiString id_lacza = cdsGlbLinks->FieldByName("ID")->AsString;

   AnsiString filter = cdsLinks->Filter;

   bool is_filtered = cdsLinks->Filtered;

   cdsLinks->Filtered = false;

   cdsLinks->First();

   while(!cdsLinks->Eof)
   {
      if(cdsLinks->FieldByName("ISREFER")->AsBoolean && cdsLinks->FieldByName("ID")->AsString == id_lacza)
      {
         cdsLinks->Edit();

         cdsLinks->FieldByName("ID")->AsString = cdsGlbLinks->FieldByName("ID")->AsString;

         cdsLinks->FieldByName("NAME")->AsString = cdsGlbLinks->FieldByName("NAME")->AsString;

         cdsLinks->FieldByName("KIND")->AsString = cdsGlbLinks->FieldByName("KIND")->AsString;

         cdsLinks->FieldByName("PROTOCOL")->AsString = cdsGlbLinks->FieldByName("PROTOCOL")->AsString;

         cdsLinks->FieldByName("ALIAS")->AsString = cdsGlbLinks->FieldByName("ALIAS")->AsString;

         cdsLinks->FieldByName("USER")->AsString = cdsGlbLinks->FieldByName("USER")->AsString;

         cdsLinks->FieldByName("PASSWORD")->AsString = cdsGlbLinks->FieldByName("PASSWORD")->AsString;

         cdsLinks->FieldByName("CHARSET")->AsString = cdsGlbLinks->FieldByName("CHARSET")->AsString;

         cdsLinks->FieldByName("DIALECT")->AsString = cdsGlbLinks->FieldByName("DIALECT")->AsString;

         cdsLinks->FieldByName("VENDORLIB")->AsString = cdsGlbLinks->FieldByName("VENDORLIB")->AsString;

         cdsLinks->FieldByName("OWNER")->AsString = cdsGlbLinks->FieldByName("OWNER")->AsString;

         cdsLinks->Post();

      }

      cdsLinks->Next();

   }

   cdsLinks->Filter = filter;

   cdsLinks->Filtered = is_filtered;

   cdsLinks->First();

   mn.restore();
}
//---------------------------------------------------------------------------


void __fastcall TDMEditConfig::dsApplicationDataChange(TObject *Sender,
      TField *Field)
{
   mng::ControlsMan cmLinks(cdsLinks);

   mng::ControlsMan cmParamLinks(cdsParamLink);

   mng::ControlsMan cmParams(cdsParam);

   AnsiString filter = "IDAPP = " + IntToStr(cdsApplications->FieldByName("SYSID")->AsInteger);

   if(Field == NULL)
   {
      cdsLinks->Filter = filter;

      cdsParam->Filter = filter;

      cdsLinks->Filtered = true;

      cdsParam->Filtered = true;

      filter += " AND IDLINK = '" + cdsLinks->FieldByName("ID")->AsString + "'";

      cdsParamLink->Filter = filter;

      cdsParamLink->Filtered = true;

      m_idApp = cdsApplications->FieldByName("SYSID")->AsInteger;

      cdsLinks->First();

      cdsParamLink->First();

      cdsParam->First();
   }
   else
   {
      if(Field->FieldName.CompareIC("SYSID") == 0)
      {
        int id_app = cdsApplications->FieldByName("SYSID")->AsInteger;

        cdsLinks->Filtered = false;

        cdsLinks->First();

        while(!cdsLinks->Eof)
        {
           if(cdsLinks->FieldByName("IDAPP")->AsInteger == m_idApp)
           {
              cdsLinks->Edit();

              cdsLinks->FieldByName("IDAPP")->AsInteger = id_app;

              cdsLinks->Post();
           }
         cdsLinks->Next();
      }

        cdsParamLink->Filtered = false;

        cdsParamLink->First();

        while(!cdsParamLink->Eof)
        {
           if(cdsParamLink->FieldByName("IDAPP")->AsInteger == m_idApp)
           {
              cdsParamLink->Edit();

              cdsParamLink->FieldByName("IDAPP")->AsInteger = id_app;

              cdsParamLink->Post();
           }

           cdsParamLink->Next();
      }

        cdsParam->Filtered = false;

        cdsParam->First();

        while(!cdsParam->Eof)
        {
           if(cdsParam->FieldByName("IDAPP")->AsInteger == m_idApp)
           {
              cdsParam->Edit();

              cdsParam->FieldByName("IDAPP")->AsInteger = id_app;

              cdsParam->Post();
           }

           cdsParam->Next();
        }
          cdsLinks->Filter = filter;

          cdsParam->Filter = filter;

          cdsLinks->Filtered = true;

          cdsParam->Filtered = true;

          filter += " AND IDLINK = '" + cdsLinks->FieldByName("ID")->AsString + "'";

          cdsParamLink->Filter = filter;

          cdsParamLink->Filtered = true;

          m_idApp = cdsApplications->FieldByName("SYSID")->AsInteger;

          cdsLinks->First();

          cdsParamLink->First();

          cdsParam->First();

      }
   }

}
//---------------------------------------------------------------------------

