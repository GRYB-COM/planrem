//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImportFromMdbFRM.h"
#include "manager\stream_db.h"
#include "manager\query_db.h"
#include "MagID.h"
#include "JBUTILS\jb_ini_my.h"
#include <sysutils.hpp>
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvDBLookupComboBox"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma link "AdvGroupBox"
#pragma link "AdvOfficeButtons"
#pragma link "DBAdvOfficeButtons"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
 using namespace importmdb;
//---------------------------------------------------------------------------
__fastcall T_ImportFromMdbFRM::T_ImportFromMdbFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Ini      = new jbutils::TMyIni();
 m_WydzSDB  = new mng::StreamDB();
 m_WydzSDB->setQuery("SELECT W.ID_WYDZIALU, W.KOD, W.KOD || ' - ' ||  RTRIM(W.NAZWA) AS NAZ_WYDZ  FROM PR_WYDZIALY W");
 m_WydzDS->DataSet = m_WydzSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_ImportFromMdbFRM::~T_ImportFromMdbFRM()
{
 delete m_Ini;
 delete m_WydzSDB;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall T_ImportFromMdbFRM::FormShow(TObject *Sender)
{
 m_WydzSDB->open();
 m_WydzSDB->fieldByName("NAZ_WYDZ")->DisplayWidth = 20;
 m_WydzCB->KeyValue = 999;
 m_WydzCB->KeyValue   = m_Ini->ReadIniInteger("IMPORT MDB","Id wydz",6);
 m_DaneCG->Checked[0] = m_Ini->ReadIniBool("IMPORT MDB","S這wnik jednostek",true);
 m_DaneCG->Checked[1] = m_Ini->ReadIniBool("IMPORT MDB","S這wnik sprz皻u",true);
 m_DaneCG->Checked[2] = m_Ini->ReadIniBool("IMPORT MDB","Lista przyj皻ego sprz皻u",true);
 m_DaneCG->Checked[3] = m_Ini->ReadIniBool("IMPORT MDB","Dane z KUT",true);
 m_PathOD->InitialDir = m_Ini->ReadIniString("IMPORT MDB","Init dir","");
 m_PathED->Text       = m_Ini->ReadIniString("IMPORT MDB","File name","");
 enableRun(NULL);

}
//---------------------------------------------------------------------------

void __fastcall T_ImportFromMdbFRM::m_OpenBTClick(TObject *Sender)
{
 if(m_PathOD->Execute())
 {
  m_PathED->Text = m_PathOD->FileName;
  m_Ini->WriteIniString("IMPORT MDB","Init dir",ExtractFileDir(m_PathOD->FileName));
  m_Ini->WriteIniString("IMPORT MDB","File name", m_PathOD->FileName);
 }
}
//---------------------------------------------------------------------------

void __fastcall T_ImportFromMdbFRM::m_CloseBBClick(TObject *Sender)
{
 ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall T_ImportFromMdbFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_WydzSDB->close();
 m_Ini->WriteIniBool("IMPORT MDB","S這wnik jednostek",m_DaneCG->Checked[0]);
 m_Ini->WriteIniBool("IMPORT MDB","S這wnik sprz皻u",m_DaneCG->Checked[1]);
 m_Ini->WriteIniBool("IMPORT MDB","Lista przyj皻ego sprz皻u",m_DaneCG->Checked[2]);
 m_Ini->WriteIniBool("IMPORT MDB","Dane z KUT",m_DaneCG->Checked[3]);
 m_Ini->WriteIniInteger("IMPORT MDB","Id wydz", m_WydzCB->KeyValue);
}
//---------------------------------------------------------------------------
std::vector<bool>  __fastcall T_ImportFromMdbFRM::getFlags(void)
{
 std::vector<bool> _Flags;
 for(int  i = 0; i< m_DaneCG->Items->Count;++i)
 {
   _Flags.push_back(m_DaneCG->Checked[i]);
 }
 return _Flags;
}
//---------------------------------------------------------------------------
bool __fastcall T_ImportFromMdbFRM::isAnyFlag(void)
{
 bool _Res;
 for(int  i = 0; i< m_DaneCG->Items->Count;++i)
 {
  _Res  =  m_DaneCG->Checked[i];
  if(_Res) break;
 }
 return _Res;
}
//---------------------------------------------------------------------------
int __fastcall T_ImportFromMdbFRM::getIdWydz(void)
{
 int _IdWydz(-1);
 if( !m_WydzCB->KeyValue.IsNull() && m_WydzCB->KeyValue >0)
 {
   _IdWydz = m_WydzCB->KeyValue;
 }
 return _IdWydz;
}
//---------------------------------------------------------------------------
bool __fastcall T_ImportFromMdbFRM::isWydz(void)
{
 bool _Res(-1);
 _Res = !m_WydzCB->KeyValue.IsNull() && m_WydzCB->KeyValue >0;
 return _Res;
}
//---------------------------------------------------------------------------
String __fastcall T_ImportFromMdbFRM::getPath(void)
{
 return m_PathED->Text;
}
//---------------------------------------------------------------------------
bool __fastcall T_ImportFromMdbFRM::isPath(void)
{
 return !m_PathED->Text.IsEmpty();
}
//---------------------------------------------------------------------------
void __fastcall T_ImportFromMdbFRM::enableRun(TObject *Sender)
{

 if(m_PathED->Text.Pos("D3") >0 || m_PathED->Text.Pos("D 3") || m_PathED->Text.Pos("D-3") >0)
 {
  m_WydzCB->KeyValue =999;
  m_WydzCB->KeyValue=3;
 }
 else if(m_PathED->Text.Pos("D6") >0 || m_PathED->Text.Pos("D 6") || m_PathED->Text.Pos("D-6") >0)
 {
  m_WydzCB->KeyValue =999;
  m_WydzCB->KeyValue=6;
 }
 m_RunBB->Enabled = isRun();
}
//---------------------------------------------------------------------------
 bool __fastcall T_ImportFromMdbFRM::isRun(void)
 {
  return isPath() && isWydz() && isAnyFlag();
}

