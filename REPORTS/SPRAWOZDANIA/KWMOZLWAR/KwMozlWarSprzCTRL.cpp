//---------------------------------------------------------------------------
#pragma hdrstop
#include "KwMozlWarSprzCTRL.h"
#include "KwMozlWarDM.h"
#include "KwMozlWarSprzDM.h"
#include "KwMozlWarWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
KwMozlWarSprzCTRL::KwMozlWarSprzCTRL(const String & _Caption)
{
 m_DM      = new T_KwMozlWarDM(NULL);
 m_DM1     = new T_KwMozlWarSprzDM(NULL);
 m_WybFRM  = new T_KwMozlWarWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_WybFRM->Caption = _Caption;
 m_WybFRM->m_SumCB->Visible = true;
 m_WybFRM->m_DiagCB->Visible = true;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
KwMozlWarSprzCTRL::~KwMozlWarSprzCTRL(void)
{
 delete m_DM;
 delete m_DM1;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void KwMozlWarSprzCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall KwMozlWarSprzCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall KwMozlWarSprzCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void KwMozlWarSprzCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_KwMozlWarDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
 T_KwMozlWarSprzDM::Pars _Pars1;
 _Pars1.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars1.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars1.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars1.ProcName       = m_WybFRM->m_SumCB->Checked ? "PR_ROCZNA_REAL_PLANU_GRUPOWANA" : "PR_ROCZNA_REAL_PLANU";
 _Pars1.Diag           = m_WybFRM->m_DiagCB->Checked;
 m_DM1->open(_Pars1);
 m_DM1->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void KwMozlWarSprzCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Roczny plan remontów", _Print );
}
//---------------------------------------------------------------------------
void KwMozlWarSprzCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

