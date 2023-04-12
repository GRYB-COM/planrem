//---------------------------------------------------------------------------
#pragma hdrstop
#include "RBH4MiesCTRL.h"
#include "RBH4MiesDM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
RBH4MiesCTRL::RBH4MiesCTRL(void)
{
 m_DM      = new T_RBH4MiesDM(NULL);
 m_Ini     = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
RBH4MiesCTRL::~RBH4MiesCTRL(void)
{
 delete m_DM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void RBH4MiesCTRL::run(void)
{
 prevTMIClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall RBH4MiesCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall RBH4MiesCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void RBH4MiesCTRL::open(void)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 T_RBH4MiesDM::Pars _Pars;
 _Pars.Rok            =CurrentYear();
 _Pars.IdWydzialu     = -1;
 _Pars.IdWarsztatu    = -1;
 m_DM->open(_Pars);
 m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void RBH4MiesCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\spr.mdb");
 sgda::MdbManager::runReport(_Path, "Miesiêczny bilans mo¿liwoœci", _Print );
}
//---------------------------------------------------------------------------
void RBH4MiesCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

