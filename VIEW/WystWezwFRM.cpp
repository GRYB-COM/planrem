//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "WystWezwFRM.h"
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGroupBox"
#pragma link "AdvOfficeButtons"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothProgressBar"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_WystWezwFRM::T_WystWezwFRM(TComponent* Owner)
	: TForm(Owner),m_OnChange(NULL)
{
 m_Ini = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
__fastcall T_WystWezwFRM::~T_WystWezwFRM(void)
{
 delete m_Ini;
}
//---------------------------------------------------------------------------
void T_WystWezwFRM::start(const int _Max)
{
 Update();
 Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void T_WystWezwFRM::step(const AnsiString& _Capt)
{
 Update();
 Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void T_WystWezwFRM::stop(void)
{
 Update();
 Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall T_WystWezwFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
  m_Ini->WriteIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia od",m_DataWystOdDCP->Date );
  m_Ini->WriteIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia do",m_DataWystDoDCP->Date );
  m_Ini->WriteIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia",m_DataWystDCP->Date );
  m_Ini->WriteIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data zakoñczenia do",m_DataZakDoDCP->Date );
  m_Ini->WriteIniInteger("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Tryb pracy", m_ModeRG->ItemIndex);
  m_Ini->WriteIniInteger("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Filtr wezwañ", m_FiltrWezwRG->ItemIndex);

}
//---------------------------------------------------------------------------
void __fastcall T_WystWezwFRM::FormShow(TObject *Sender)
{
 m_DataWystOdDCP->OnChange = NULL;
 m_DataWystDoDCP->OnChange = NULL;
 m_DataWystDCP->OnChange   = NULL;
 m_DataZakDoDCP->OnChange  = NULL;
 m_ModeRG->OnClick         = NULL;
 m_FiltrWezwRG->OnClick    = NULL;
 m_ModeRG->ItemIndex       =  m_Ini->ReadIniInteger("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Tryb pracy", 0 );
 m_FiltrWezwRG->ItemIndex  =  m_Ini->ReadIniInteger("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Filtr wezwañ", 0 );
 m_DataWystOdDCP->Date     = m_Ini->ReadIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia od", Date() );
 m_DataWystDoDCP->Date      = m_Ini->ReadIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia do", TDateTime(CurrentYear(),12,31) );
 m_DataWystDCP->Date       = m_Ini->ReadIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data wystawienia", Date() );
 m_DataZakDoDCP->Date      = m_Ini->ReadIniDateTime("WARTOŒCI DOMYSLNE - powiadomienia o wyremontowaniu", "Data zakoñczenia do", TDateTime(CurrentYear(),12,31) );
 m_DataWystOdDCP->OnChange = OnChange;
 m_DataWystDoDCP->OnChange = OnChange;
 m_DataWystDCP->OnChange   = OnChange;
 m_DataZakDoDCP->OnChange  = OnChange;
 m_ModeRG->OnClick         = OnChange;
 m_FiltrWezwRG->OnClick    = OnChange;
 OnChange(Sender);
}
//---------------------------------------------------------------------------


void __fastcall T_WystWezwFRM::OnChange(TObject *Sender)
{
 bool _Ed = m_ModeRG->ItemIndex ==1;
 m_DelBB->Visible         =  _Ed;
 m_DataWystOdDCP->Visible =  _Ed;
 m_DataWystDoDCP->Visible =  _Ed;
 m_DataWystDCP->Visible   = !_Ed;
 m_DataZakDoDCP->Visible  = !_Ed;
 if(_Ed)
 {
  m_DataWystLB->Caption   = "Data wyst. od";
  m_DataWystDoLB->Caption = "Data wyst. do";
  m_GridHeadLB->Caption   = String("Lista wystawionych ") + (m_FiltrWezwRG->ItemIndex ==0 ? String("powiadomieñ") : String("wezwañ"));
  m_DodajBB->Caption      = "Drukuj";
  m_DodajBB->Hint         = "Drukuj wybrane powiadomienie";

 }
 else
 {
  m_DataWystLB->Caption   = "Data wyst.";
  m_DataWystDoLB->Caption = "Data zak. do";
  m_GridHeadLB->Caption   ="Lista dostawców z wyremontowanym sprzêtem";
  m_DodajBB->Caption      ="Wystaw";
  m_DodajBB->Hint         ="Wystaw powiadomienie dla wybranego dostawcy";
 }
 if(m_OnChange) m_OnChange(Sender);

}
//---------------------------------------------------------------------------
void __fastcall T_WystWezwFRM::setOnChange(TNotifyEvent _OnChange)
{
 m_OnChange = _OnChange;
}

