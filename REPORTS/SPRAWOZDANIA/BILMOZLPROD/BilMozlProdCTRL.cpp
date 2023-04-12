//---------------------------------------------------------------------------
#pragma hdrstop
#include "BilMozlProdCTRL.h"
#include "BilMozlProdDM.h"
#include "BilMozlProdWybFRM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
BilMozlProdCTRL::BilMozlProdCTRL(void)
{
 m_DM      = new T_BilMozlProdDM(NULL);
 m_WybFRM  = new T_BilMozlProdWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick  =  prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick =  printTMIClick;
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
BilMozlProdCTRL::~BilMozlProdCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void BilMozlProdCTRL::run(void)
{
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall BilMozlProdCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall BilMozlProdCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void BilMozlProdCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_BilMozlProdDM::Pars _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars.MiesOd         = m_WybFRM->m_MiesOdCB->ItemIndex +1;
 _Pars.MiesDo         = m_WybFRM->m_MiesDoCB->ItemIndex +1;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void BilMozlProdCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Bilans mo¿liwoœci produkcujnych", _Print );
}
//---------------------------------------------------------------------------
void BilMozlProdCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

