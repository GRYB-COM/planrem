//---------------------------------------------------------------------------
#pragma hdrstop
#include "RBH4OneMiesCTRL.h"
#include "RBH4OneMiesDM.h"
#include "SGTOOLS\OFFICETOOLS\MdbManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "Access_2K_SRVR.h"
#include "SysUtils.hpp"
#include "RBH4OneMiesWybFRM.h"
#include <SQR.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
RBH4OneMiesCTRL::RBH4OneMiesCTRL(void)
{
 m_DM      = new T_RBH4OneMiesDM(NULL);
 m_WybFRM  = new T_RBH4OneMiesWybFRM(NULL);
 m_Ini     = new jbutils::TMyIni();

 m_WybFRM->m_PrevTMI->OnClick  = prevTMIClick;
 m_WybFRM->m_PrintTMI->OnClick = printTMIClick;
 m_WybFRM->m_RapSQRTMI->OnClick    = runSQR;
 m_WybFRM->m_RapXLSTMI->OnClick    = runSQRXLS;

}
//---------------------------------------------------------------------------
RBH4OneMiesCTRL::~RBH4OneMiesCTRL(void)
{
 delete m_DM;
 delete m_WybFRM;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void RBH4OneMiesCTRL::run(void)
{
 m_WybFRM->ShowModal();;
}
//---------------------------------------------------------------------------
void __fastcall RBH4OneMiesCTRL::prevTMIClick(TObject *Sender)
{
 open();
 runRep(false);
 close();
}
//---------------------------------------------------------------------------
void __fastcall RBH4OneMiesCTRL::printTMIClick(TObject *Sender)
{
 open();
 runRep(true);
 close();
}
//---------------------------------------------------------------------------
void __fastcall  RBH4OneMiesCTRL::runSQR(TObject* Sender)
{
 sqr::SQRScript _Skrypt;
 sqr::SQRMan  _SqrMan;
 AnsiString _Path( ExtractFileDir(Application->ExeName) );
 _Path += "\\SQR_DED\\RBH na warsztaty miesiêczne.sqr";
 if(FileExists(_Path) )
 {
 _Skrypt.load(_Path);
 _Skrypt.setHeaderExt(AnsiString("Miesi¹c: ") + LongMonthNames[m_WybFRM->m_MiesOdCB->ItemIndex] );
  open();
 _SqrMan.ShowRap(m_DM->m_Client,_Skrypt);
 close();
 }
}
//---------------------------------------------------------------------------
void __fastcall  RBH4OneMiesCTRL::runSQRXLS(TObject* Sender)
{
 sqr::SQRScript _Skrypt;
 sqr::SQRMan  _SqrMan;
 _SqrMan.setShowFile(false);
 AnsiString _Path( ExtractFileDir(Application->ExeName) );
 AnsiString _XlsRap, _HtmlRap;
 _Path += "\\SQR_DED\\RBH na warsztaty miesiêczne.sqr";
 if(FileExists(_Path) )
 {
  open(false);
  _Skrypt.load(_Path);
 _Skrypt.setHeaderExt(AnsiString("Miesi¹c: ") + LongMonthNames[m_WybFRM->m_MiesOdCB->ItemIndex] );
  _HtmlRap =  _SqrMan.ShowRap(m_DM->m_Client,_Skrypt);
 _XlsRap  =  _HtmlRap + ".xls";
 sqr::SQRMan::convertHTML2XLS(_HtmlRap,_XlsRap);
 close();
 ShellExecute(GetDesktopWindow(), "open",_XlsRap.c_str(), NULL, NULL,SW_SHOWNORMAL);
 }
}
//---------------------------------------------------------------------------
void RBH4OneMiesCTRL::open(const bool _ToMdb)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\RBH4OneMies.mdb");
 T_RBH4OneMiesDM::Pars  _Pars;
 _Pars.Rok            = m_WybFRM->m_RokED->Text.ToIntDef(CurrentYear());
 _Pars.IdWydzialu     = m_WybFRM->m_WydzialCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WydzialCB->KeyValue;;
 _Pars.IdWarsztatu    = m_WybFRM->m_WarCB->KeyValue.IsNull() ? -1 : m_WybFRM->m_WarCB->KeyValue;
 _Pars.Miesiac        = m_WybFRM->m_MiesOdCB->ItemIndex +1;
 _Pars.ToMdb          = _ToMdb;
 m_DM->open(_Pars);
 if(_ToMdb) m_DM->saveToMdb(_Path);
}
//---------------------------------------------------------------------------
void RBH4OneMiesCTRL::runRep(const bool _Print)
{
 WideString _Path = m_Ini->ReadIniString("HURTOWNIE DANYCH", "MS Access", ExtractFileDir(Application->ExeName)+ "\\MDB\\RBH4OneMies.mdb");
 sgda::MdbManager::runReport(_Path, "RBH w jednym miesi¹cu", _Print );
}
//---------------------------------------------------------------------------
void RBH4OneMiesCTRL::close(void)
{
 m_DM->close();
}
//---------------------------------------------------------------------------

