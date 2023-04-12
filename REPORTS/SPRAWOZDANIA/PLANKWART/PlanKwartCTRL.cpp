//---------------------------------------------------------------------------
#pragma hdrstop
#include "PlanKwartCTRL.h"
#include "PlanKwartDM.h"
#include "PlanKwartWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
PlanKwartCTRL::PlanKwartCTRL(void)
{
 m_DM      = new T_PlanKwartDM(NULL);
 m_WybFRM  = new T_PlanKwartWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
PlanKwartCTRL::~PlanKwartCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void PlanKwartCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall PlanKwartCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall PlanKwartCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void PlanKwartCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_PlanKwartDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars.MiesOd         = m_WybFRM->m_MiesOdCB->ItemIndex +1;
 _Pars.MiesDo         = m_WybFRM->m_MiesDoCB->ItemIndex +1;
	  if(_Pars.MiesOd == 1 && _Pars.MiesDo ==3) _Pars.Kw ="I";
 else if(_Pars.MiesOd == 4 && _Pars.MiesDo ==6) _Pars.Kw ="II";
 else if(_Pars.MiesOd == 7 && _Pars.MiesDo ==9) _Pars.Kw ="III";
 else if(_Pars.MiesOd == 10&& _Pars.MiesDo ==12) _Pars.Kw ="IV";
 else _Pars.Kw ="DD";
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void PlanKwartCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Kwartalny plan remontów", _Print );
}
//---------------------------------------------------------------------------
void PlanKwartCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

