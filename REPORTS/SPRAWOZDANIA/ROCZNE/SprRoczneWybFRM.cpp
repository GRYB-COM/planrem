//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "SprRoczneWybFRM.h"
#include "MANAGER\stream_db.h"
#include "jbutils\jb_ini_my.h"
#include "SysUtils.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FCSWYB"
#pragma link "PopupButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_SprRoczneWybFRM::T_SprRoczneWybFRM(TComponent* Owner)
	: T_FCUSTWYB(Owner)
{
 m_Ini = new jbutils::TMyIni();
 m_PrevTMI->Caption ="Zestawienie HTML";
 m_PrintTMI->Caption ="Zestawienie XLS";
 m_PrintSetupTMI->Visible = false;
}
//---------------------------------------------------------------------------
__fastcall T_SprRoczneWybFRM::~T_SprRoczneWybFRM(void)
{
 delete m_Ini;
}
//---------------------------------------------------------------------------
int __fastcall T_SprRoczneWybFRM::display(const RodzSpr& _RodzSpr)
{
 m_Ini->WriteIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "Rodzaj", _RodzSpr);
 return ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_SprRoczneWybFRM::FormShow(TObject *Sender)
{
 m_RokED->Text          = m_Ini->ReadIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "ROK", CurrentYear());
 m_SprRG->ItemIndex     = m_Ini->ReadIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "Rodzaj", 0);
 m_PolRokCB->ItemIndex  = m_Ini->ReadIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "Pó³rocze", 1)-1;
 m_InfoCB->Checked      = m_Ini->ReadIniBool("ZESTAWIENIA - G³ówne sprawozdane",m_InfoCB->Caption, false);
 m_NewZestCB->Checked   = m_Ini->ReadIniBool("ZESTAWIENIA - G³ówne sprawozdane",m_NewZestCB->Caption, false);
 m_SprRGClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall T_SprRoczneWybFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_Ini->WriteIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "ROK", m_RokED->Text.ToIntDef(CurrentYear()));
 m_Ini->WriteIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "Rodzaj", m_SprRG->ItemIndex);
 m_Ini->WriteIniInteger("ZESTAWIENIA - G³ówne sprawozdane", "Pólrocze",m_PolRokCB->ItemIndex+1);
 m_Ini->WriteIniBool("ZESTAWIENIA - G³ówne sprawozdane",m_InfoCB->Caption, m_InfoCB->Checked);
 m_Ini->WriteIniBool("ZESTAWIENIA - G³ówne sprawozdane",m_NewZestCB->Caption, m_NewZestCB->Checked);

}
//---------------------------------------------------------------------------


void __fastcall T_SprRoczneWybFRM::m_SprRGClick(TObject *Sender)
{
 m_PolRokCB->Enabled = false;
 switch(m_SprRG->ItemIndex)
 {
  case 0: m_PolRokCB->Enabled = true; break;
 }
}
//---------------------------------------------------------------------------
int __fastcall T_SprRoczneWybFRM::getRok(void)
{
 return m_RokED->Text.ToIntDef(CurrentYear());
}
//---------------------------------------------------------------------------
int __fastcall T_SprRoczneWybFRM::getMiesOd(void)
{
 int _Res(0);
  switch(m_SprRG->ItemIndex)
 {
  case 0:   _Res = m_PolRokCB->ItemIndex * 6 + 1; break;
  default:  _Res = 1;                             break;
 }
 return _Res;
}
//---------------------------------------------------------------------------
int __fastcall T_SprRoczneWybFRM::getMiesDo(void)
{
 int _Res(0);
  switch(m_SprRG->ItemIndex)
 {
  case 0:   _Res = (m_PolRokCB->ItemIndex+1) * 6 ; break;
  default:  _Res = 12; 		   					   break;
 }
 return _Res;
}
//---------------------------------------------------------------------------


