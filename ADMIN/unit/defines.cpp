//---------------------------------------------------------------------------

#pragma hdrstop

#include "defines.h"
#include <manager\connection_info.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------


class TableDescp
{
public:
   Defines::TableID m_id;
   AnsiString       m_name;
   AnsiString       m_key;

   TableDescp(Defines::TableID id,const AnsiString& name,const AnsiString& key)
      : m_id(id), m_name(name), m_key(key)
   {
   }
   //---------------------------------------------------------------------------
   
};


static TableDescp s_TableDescp[]=
{
   TableDescp(Defines::tidOPR,"OP_OPER","KOD_OPER"),
   TableDescp(Defines::tidSLF,"OP_SLFUN","KOD_SYSTEMU;KOD_FUNSYS"),
   TableDescp(Defines::tidGRP,"OP_GRUPY","KOD_GRUPY"),
   TableDescp(Defines::tidGRF,"OP_GRFUN","KOD_SYSTEMU;KOD_FUNSYS;KOD_GRUPY"),
   TableDescp(Defines::tidOFN,"OP_OPFUN","KOD_SYSTEMU;KOD_FUNSYS;KOD_OPER"),
   TableDescp(Defines::tidOGR,"OP_OPERGRUP","KOD_GRUPY;KOD_OPER"),
   TableDescp(Defines::tidIRS,"IS_REJESTR","ID_SYSTEMU")
};




/**********
*  Funkcje sk³adowe klasy: Defines
**********/


int Defines::statusToInt(char p_status)
{
   int war_zwr(-1);

   switch(p_status)
   {
      case 'T':
      war_zwr = 0;
      break;

      case 'N':
      war_zwr = 1;
      break;

      case 'B':
      war_zwr = 2;
      break;
   }

   return war_zwr;
}
//---------------------------------------------------------------------------

AnsiString Defines::primaryKey(TableID table_id)
{
   for(int ii=0;ii < sizeof(s_TableDescp)/sizeof(s_TableDescp[0]);++ii)
   {
      if(s_TableDescp[ii].m_id == table_id)
      {
         return s_TableDescp[ii].m_key;
      }
   }

   return "";
}
//---------------------------------------------------------------------------

AnsiString Defines::tableName(TableID table_id)
{
   for(int ii=0;ii < sizeof(s_TableDescp)/sizeof(s_TableDescp[0]);++ii)
   {
      if(s_TableDescp[ii].m_id == table_id)
      {
         return s_TableDescp[ii].m_name;
      }
   }

   return "";
}
//---------------------------------------------------------------------------

AnsiString Defines::getStatus(char p_status)
{
   AnsiString zwr_war = "";

   switch(p_status)
   {
      case 'T':
      zwr_war = "Aktywny";
      break;

      case 'N':
      zwr_war = "Zawieszony";
      break;

      case 'B':
      zwr_war = "Zablokowany";
      break;

      default:
      zwr_war = "Nieokreœlony";
      break;
   }

   return zwr_war;
}
//---------------------------------------------------------------------------
/*
int Defines::kindToInt(const mng::ConnectionInfo::DbKind& p_con)
{
   int zwr_war;

   switch(p_con)
   {
      case  mng::ConnectionInfo::dbkNone:
      zwr_war = 0;
      break;

      case mng::ConnectionInfo::dbkInterbase:
      zwr_war = 1;
      break;

      case mng::ConnectionInfo::dbkOracle:
      zwr_war = 2;
      break;
      default:
      zwr_war = 0;
      break;
   }
   return zwr_war;
}
//---------------------------------------------------------------------------

int Defines::protocolToInt(const mng::ConnectionInfo::Protocol& p_protokol)
{
   int zwr_war;

   switch(p_protokol)
   {
      case mng::ConnectionInfo::prkNone:
      zwr_war = 0;
      break;

      case mng::ConnectionInfo::prkTCPIP:
      zwr_war = 1;
      break;

      case mng::ConnectionInfo::prkNetBUI:
      zwr_war = 2;
      break;

      case mng::ConnectionInfo::prkFile:
      zwr_war = 3;
      break;

      default:
      zwr_war = 0;
      break;
   }
   return zwr_war;
}
//---------------------------------------------------------------------------

int Defines::libToInt(const mng::ConnectionInfo::LibType& p_par)
{
   int zwr_war;

   switch(p_par)
   {
      case mng::ConnectionInfo::cltNone:
      zwr_war = 0;
      break;

      case mng::ConnectionInfo::cltDBX:
      zwr_war = 1;
      break;

      case mng::ConnectionInfo::cltIBX:
      zwr_war = 2;
      break;

      case mng::ConnectionInfo::cltADO:
      zwr_war = 3;
      break;

      case mng::ConnectionInfo::cltBDE:
      zwr_war = 4;
      break;

      default:
      zwr_war = 0;
      break;
   }

   return zwr_war;
}
//---------------------------------------------------------------------------

AnsiString Defines::kindToStr(const mng::ConnectionInfo::DbKind& p_con)
{
   AnsiString zwr_war;

   switch(p_con)
   {
     case mng::ConnectionInfo::dbkNone:
     zwr_war = "nieokreœlona";
     break;

     case mng::ConnectionInfo::dbkInterbase:
     zwr_war = "interbase";
     break;

     case mng::ConnectionInfo::dbkOracle:
     zwr_war = "oracle";
     break;
   }
   return zwr_war;
}
//---------------------------------------------------------------------------
AnsiString Defines::protocolToStr(const mng::ConnectionInfo::Protocol& p_protokol)
{
   AnsiString zwr_war;

   switch(p_protokol)
   {
      case mng::ConnectionInfo::prkNone:
      zwr_war = "nieokreœlony";
      break;

      case mng::ConnectionInfo::prkTCPIP:
      zwr_war = "tcpip";
      break;

      case mng::ConnectionInfo::prkNetBUI:
      zwr_war = "netbui";
      break;

      case mng::ConnectionInfo::prkFile:
      zwr_war = "lokalny";
      break;

      default:
      zwr_war = "nieokreœlony";
      break;
   }
   return zwr_war;
}
//---------------------------------------------------------------------------

AnsiString Defines::libToStr(const mng::ConnectionInfo::LibType& p_par)
{
   AnsiString zwr_war;

   switch(p_par)
   {
      case mng::ConnectionInfo::cltNone:
      zwr_war = "nieokreœlona";
      break;

      case mng::ConnectionInfo::cltDBX:
      zwr_war = "dbexpress";
      break;

      case mng::ConnectionInfo::cltIBX:
      zwr_war = "ibexpress";
      break;

      case mng::ConnectionInfo::cltADO:
      zwr_war = "ADO";
      break;

      case mng::ConnectionInfo::cltBDE:
      zwr_war = "BDE";
      break;
   }

   return zwr_war;
}
//---------------------------------------------------------------------------
*/
