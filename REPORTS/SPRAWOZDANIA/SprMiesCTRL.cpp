//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprMiesCTRL.h"
#include <SQR.h>

#include "PlanKwartWybFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
SprMiesCTRL::SprMiesCTRL(void)
{
 m_WybFRM = new T_PlanKwartWybFRM(NULL);
 m_WybFRM->m_PrevTMI->Caption  = "Wersja HRML";
 m_WybFRM->m_PrevTMI->OnClick  = runSQR;
 m_WybFRM->m_PrintTMI->Caption  = "Wersja XLS";
 m_WybFRM->m_PrintTMI->OnClick = runXLS;
 //m_DAO    = new SprRoczneDAO;
}
//---------------------------------------------------------------------------
SprMiesCTRL::~SprMiesCTRL(void)
{
 delete m_WybFRM;

}
//---------------------------------------------------------------------------
void SprMiesCTRL::run(void)
{
 m_WybFRM->Caption ="Sprawozdanie miesiêczne";
 m_WybFRM->m_MiesDoCB->Visible=false;
 m_WybFRM->m_MiesOdLB->Caption = "Miesi¹c";
 m_WybFRM->m_MiesDoLB->Visible = false;
 m_WybFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall SprMiesCTRL::runSQR(TObject *Sender)
{
 //WCZYTANIE DANYCH i PRZYGOTOWANIE SQRa
  sqr::SQRScript _Skrypt;
  sqr::SQRMan  _SqrMan;
  prepare(_Skrypt);
 //WYŒWIETLENIE RAPORTU
   _SqrMan.ShowRap(_Skrypt);
}
//---------------------------------------------------------------------------
void __fastcall SprMiesCTRL::runXLS(TObject *Sender)
{
 //WCZYTANIE DANYCH i PRZYGOTOWANIE SQRa
  sqr::SQRScript _Skrypt;
  sqr::SQRMan  _SqrMan;
  _SqrMan.setShowFile(false);
  prepare(_Skrypt);
 //WYŒWIETLENIE RAPORTU
 AnsiString _HtmlRap =  _SqrMan.ShowRap(_Skrypt);
 AnsiString _XlsRap  =  _HtmlRap + ".xls";
 sqr::SQRMan::convertHTML2XLS(_HtmlRap,_XlsRap);
 ShellExecute(GetDesktopWindow(), "open",_XlsRap.c_str(), NULL, NULL,SW_SHOWNORMAL);
 //PORZ¥DKI KOÑCOWE

}
//---------------------------------------------------------------------------
void __fastcall SprMiesCTRL::prepare(sqr::SQRScript& _Skrypt)
{
 //PRZYGOTOWANIE SQRA

  AnsiString _Path( ExtractFileDir(Application->ExeName) );
  _Path +=  "\\SQR_DED\\Sprawozdanie miesieczne.sqr";
  if(FileExists(_Path) )
  {
   _Skrypt.load(_Path);
   _Skrypt.getDefParams()->Values["ROK"]        = m_WybFRM->m_RokED->Text;
   _Skrypt.getDefParams()->Values["MIES"]       = m_WybFRM->m_MiesOdCB->ItemIndex ==-1 ? -1 : m_WybFRM->m_MiesOdCB->ItemIndex +1;
   _Skrypt.getDefParams()->Values["ID_KOMORKI"] = m_WybFRM->m_WarCB->KeyValue;


   AnsiString _Head("Sprawozdanie za ");
   //if(m_WybFRM->m_SprRG->ItemIndex ==0 ) _Head += m_WybFRM->m_PolRokCB->Text;
   //_Head += String(" ") + _DPars.Rok + String("r.");
   _Skrypt.setHeader(_Head);
  }
}
