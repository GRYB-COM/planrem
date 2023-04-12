//---------------------------------------------------------------------------
#pragma hdrstop
#include "PlanKwartZadCTRL.h"
#include "PlanKwartZadDM.h"
#include "PlanKwartZadWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
PlanKwartZadCTRL::PlanKwartZadCTRL(void)
{
 m_DM      = new T_PlanKwartZadDM(NULL);
 m_WybFRM  = new T_PlanKwartZadWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
PlanKwartZadCTRL::~PlanKwartZadCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void PlanKwartZadCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall PlanKwartZadCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall PlanKwartZadCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void PlanKwartZadCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_PlanKwartZadDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars.MiesOd         = m_WybFRM->m_MiesOdCB->ItemIndex +1;
 _Pars.MiesDo         = m_WybFRM->m_MiesDoCB->ItemIndex +1;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void PlanKwartZadCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Kwartalny plan zadañ", _Print );
}
//---------------------------------------------------------------------------
void PlanKwartZadCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

