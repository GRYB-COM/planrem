//---------------------------------------------------------------------------
#pragma hdrstop
#include "EksportCfgWriter.h"
#include "EksportCfg.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\utils_db.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace writers;
//---------------------------------------------------------------------------
EksportCfgWriter::EksportCfgWriter(void)
{

}
//---------------------------------------------------------------------------
EksportCfgWriter& EksportCfgWriter::instance(void)
{
 static EksportCfgWriter _Wr;
 return _Wr;
}
//---------------------------------------------------------------------------
void EksportCfgWriter::run(const msg::EksportCfg& _Cfg)
{
 mng::StreamDB _Sdb;
 _Sdb.setQuery("SELECT * FROM IS_PARAMS WHERE ID_SYSTEMU=256 AND SET_ID= 1");
 _Sdb.open();
 if(_Sdb.isEmpty())
 {
  _Sdb.append();
  _Sdb.fieldByName("ID_SYSTEMU")->AsInteger = 256;
  _Sdb.fieldByName("SET_ID")->AsInteger = 1;
 }
 else _Sdb.edit();
 _Sdb.fieldByName("XML")->Value = _Cfg.getXML();
 _Sdb.post();
 _Sdb.applyUpdates();
 _Sdb.close();

}
