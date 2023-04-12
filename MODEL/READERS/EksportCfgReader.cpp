//---------------------------------------------------------------------------
#pragma hdrstop
#include "EksportCfgReader.h"
#include "EksportCfg.h"
#include "..\MANAGER\stream_db.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
EksportCfgReader::EksportCfgReader(void)
{

}
//---------------------------------------------------------------------------
EksportCfgReader& EksportCfgReader::instance(void)
{
 static EksportCfgReader _Wr;
 return _Wr;
}
//---------------------------------------------------------------------------
msg::EksportCfg EksportCfgReader::run(void)
{
 mng::StreamDB _Sdb;
 msg::EksportCfg _Res;
 _Sdb.setQuery("SELECT * FROM IS_PARAMS WHERE ID_SYSTEMU=256 AND SET_ID= 1");
 _Sdb.open();
 Variant _Val(_Sdb.fieldByName("XML")->Value);
 String _XML;
 if(!_Val.IsEmpty() && !_Val.IsNull()) _XML = _Val.VOleStr;
 _Sdb.close();
 if(!_XML.IsEmpty())
 {
  _Res.setXML(_XML);
 }
 return _Res;
}
