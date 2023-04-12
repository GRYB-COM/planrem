//---------------------------------------------------------------------------
#pragma hdrstop
#include "MozlRemCTRL.h"
#include "MozlRemDM.h"
#include "MozlRemWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
MozlRemCTRL::MozlRemCTRL(void)
{
 m_DM      = new T_MozlRemDM(NULL);
 m_WybFRM  = new T_MozlRemWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
MozlRemCTRL::~MozlRemCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void MozlRemCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall MozlRemCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall MozlRemCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void MozlRemCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_MozlRemDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void MozlRemCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Mo¿liwoœci remontowe 3OWT", _Print );
}
//---------------------------------------------------------------------------
void MozlRemCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

