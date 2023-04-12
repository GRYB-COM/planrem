//---------------------------------------------------------------------------
#pragma hdrstop
#include "RBH4OSCTRL.h"
#include "RBH4OSDM.h"
#include "RBH4OSWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
RBH4OSCTRL::RBH4OSCTRL(void)
{
 m_DM      = new T_RBH4OSDM(NULL);
 m_WybFRM  = new T_RBH4OSWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
RBH4OSCTRL::~RBH4OSCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void RBH4OSCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall RBH4OSCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall RBH4OSCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void RBH4OSCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_RBH4OSDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void RBH4OSCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Obsada sekcji produkcji", _Print );
}
//---------------------------------------------------------------------------
void RBH4OSCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

