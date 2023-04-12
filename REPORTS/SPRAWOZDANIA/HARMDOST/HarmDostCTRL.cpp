//---------------------------------------------------------------------------
#pragma hdrstop
#include "HarmDostCTRL.h"
#include "HarmDostDM.h"
#include "MozlRemWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
HarmDostCTRL::HarmDostCTRL(void)
{
 m_DM      = new T_HarmDostDM(NULL);
 m_WybFRM  = new T_MozlRemWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_WybFRM->Caption = "Harmonogram dostaw";
 m_WybFRM->m_InfoCB->Visible = true;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
HarmDostCTRL::~HarmDostCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void HarmDostCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall HarmDostCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall HarmDostCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void HarmDostCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_HarmDostDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars.Info           = m_WybFRM->m_InfoCB->Checked;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void HarmDostCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Harmonogram dostaw", _Print );
}
//---------------------------------------------------------------------------
void HarmDostCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

