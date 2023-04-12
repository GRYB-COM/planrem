//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImportPlanFromMdbFRM.h"
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
__fastcall T_ImportPlanFromMdbFRM::T_ImportPlanFromMdbFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Ini      = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
__fastcall T_ImportPlanFromMdbFRM::~T_ImportPlanFromMdbFRM()
{
 delete m_Ini;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall T_ImportPlanFromMdbFRM::FormShow(TObject *Sender)
{
 m_PathOD->InitialDir = m_Ini->ReadIniString("IMPORT MDB","Init dir","");
 m_PathED->Text       = m_Ini->ReadIniString("IMPORT MDB","File name","");
 m_RokED->Text        = m_Ini->ReadIniInteger("IMPORT MDB","Rok",CurrentYear() +1 );
 enableRun(NULL);

}
//---------------------------------------------------------------------------

void __fastcall T_ImportPlanFromMdbFRM::m_OpenBTClick(TObject *Sender)
{
 if(m_PathOD->Execute())
 {
  m_PathED->Text = m_PathOD->FileName;
  m_Ini->WriteIniString("IMPORT MDB","Init dir",ExtractFileDir(m_PathOD->FileName));
  m_Ini->WriteIniString("IMPORT MDB","File name", m_PathOD->FileName);
 }
}
//---------------------------------------------------------------------------

void __fastcall T_ImportPlanFromMdbFRM::m_CloseBBClick(TObject *Sender)
{
 ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

int __fastcall T_ImportPlanFromMdbFRM::getRok(void)
{
 return m_RokED->Text.ToIntDef(-1);
}
//---------------------------------------------------------------------------
String __fastcall T_ImportPlanFromMdbFRM::getPath(void)
{
 return m_PathED->Text;
}
//---------------------------------------------------------------------------
void __fastcall T_ImportPlanFromMdbFRM::enableRun(TObject *Sender)
{
 m_RunBB->Enabled = isRun();
}
//---------------------------------------------------------------------------
 bool __fastcall T_ImportPlanFromMdbFRM::isRun(void)
 {
  return isPath() && isRok();
}
//---------------------------------------------------------------------------
bool __fastcall T_ImportPlanFromMdbFRM::isPath(void)
{
 return  FileExists(m_PathED->Text);
}
//---------------------------------------------------------------------------
bool __fastcall T_ImportPlanFromMdbFRM::isRok(void)
{
 return m_RokED->Text.ToIntDef(-1) >2000;
}


