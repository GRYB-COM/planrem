//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprRoczneCtrl.h"
#include "ROCZNE\SprRoczneDAO.h"
#include "ROCZNE\SprRoczne1DAO.h"
#include <SQR.h>

#include "ROCZNE\SprRoczneWybFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
SprRoczneCTRL::SprRoczneCTRL(void)
{
 m_WybFRM = new T_SprRoczneWybFRM(NULL);
 m_WybFRM->m_PrevTMI->OnClick = runSQR;
 m_WybFRM->m_PrintTMI->OnClick = runXLS;
 m_1DAO    = new SprRoczne1DAO;
 m_DAO     = new SprRoczneDAO;
}
//---------------------------------------------------------------------------
SprRoczneCTRL::~SprRoczneCTRL(void)
{
 delete m_WybFRM;
 delete m_1DAO;
 delete m_DAO;
}
//---------------------------------------------------------------------------
void SprRoczneCTRL::run(const int _RodzRem)
{
 T_SprRoczneWybFRM::RodzSpr _RR;
 _RR  =static_cast<T_SprRoczneWybFRM::RodzSpr>( _RodzRem);
 m_WybFRM->display(_RR);
}
//---------------------------------------------------------------------------
void __fastcall SprRoczneCTRL::runSQR(TObject *Sender)
{
 //WCZYTANIE DANYCH i PRZYGOTOWANIE SQRa
  sqr::SQRScript _Skrypt;
  sqr::SQRMan  _SqrMan;
  SprRoczneIDAO * _DAO =prepare(_Skrypt);
 //WYŒWIETLENIE RAPORTU
   _SqrMan.ShowRap(_DAO->getDataSet(),_Skrypt);
 //PORZ¥DKI KOÑCOWE
   _DAO->close();
}
//---------------------------------------------------------------------------
void __fastcall SprRoczneCTRL::runXLS(TObject *Sender)
{
 //WCZYTANIE DANYCH i PRZYGOTOWANIE SQRa
  sqr::SQRScript _Skrypt;
  sqr::SQRMan  _SqrMan;
  _SqrMan.setShowFile(false);

  SprRoczneIDAO * _DAO =prepare(_Skrypt);
 //WYŒWIETLENIE RAPORTU
 AnsiString _HtmlRap =  _SqrMan.ShowRap(_DAO->getDataSet(),_Skrypt);
 AnsiString _XlsRap  =  _HtmlRap + ".xls";
 sqr::SQRMan::convertHTML2XLS(_HtmlRap,_XlsRap);
 ShellExecute(GetDesktopWindow(), "open",_XlsRap.c_str(), NULL, NULL,SW_SHOWNORMAL);
 //PORZ¥DKI KOÑCOWE
   _DAO->close();
}
//---------------------------------------------------------------------------
SprRoczneIDAO* SprRoczneCTRL::prepare(sqr::SQRScript& _Skrypt)
{
 //WCZYTANIE DANYCH
   SprRocznePars _DPars;
   _DPars.Rok     = m_WybFRM->getRok();
   _DPars.MiesOd  = m_WybFRM->getMiesOd();
   _DPars.MiesDo  = m_WybFRM->getMiesDo();
   _DPars.Info    = m_WybFRM->m_InfoCB->Checked;
   bool _New      = m_WybFRM->m_NewZestCB->Checked;

   SprRoczneIDAO * _DAO =  m_DAO;
   if(_New) _DAO = m_1DAO;
   _DAO->open(_DPars);
 //PRZYGOTOWANIE SQRA

  AnsiString _Path( ExtractFileDir(Application->ExeName) );
  if(_New)
  {
   _Path += _DPars.Info ?  "\\SQR_DED\\Sprawozdanie polroczne nowe - ext.sqr" : "\\SQR_DED\\Sprawozdanie polroczne nowe.sqr";
  }
  else
  {
   _Path += _DPars.Info ?  "\\SQR_DED\\Sprawozdanie polroczne - ext.sqr" : "\\SQR_DED\\Sprawozdanie polroczne.sqr";
  }

  if(FileExists(_Path) )
  {
   _Skrypt.load(_Path);
   AnsiString _Head("Sprawozdanie za ");
   if(m_WybFRM->m_SprRG->ItemIndex ==0 ) _Head += m_WybFRM->m_PolRokCB->Text;
   _Head += String(" ") + _DPars.Rok + String("r.");
   _Skrypt.setHeader(_Head);
  }
  return _DAO;
}



