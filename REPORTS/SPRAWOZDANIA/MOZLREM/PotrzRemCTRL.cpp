//---------------------------------------------------------------------------
#pragma hdrstop
#include "PotrzRemCTRL.h"
#include "PotrzRemDM.h"
#include "PotrzRemWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
PotrzRemCTRL::PotrzRemCTRL(void)
{
 m_DM      = new T_PotrzRemDM(NULL);
 m_WybFRM  = new T_PotrzRemWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
PotrzRemCTRL::~PotrzRemCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void PotrzRemCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall PotrzRemCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall PotrzRemCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void PotrzRemCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_PotrzRemDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void PotrzRemCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Potrzeby JW", _Print );
}
//---------------------------------------------------------------------------
void PotrzRemCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

