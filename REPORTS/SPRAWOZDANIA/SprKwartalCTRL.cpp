//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprKwartalCTRL.h"
#include "SprKwartalQR.h"
#include "SprKwartalWybFrm.h"
#include <DateUtils.hpp>
#include <SQR.h>
#pragma package(smart_init)
//NAMESPACES
//---------------------------------------------------------------------------
  using namespace progzest;
//---------------------------------------------------------------------------
SprKwartalCTRL::SprKwartalCTRL(void)
{
  m_Raport     = new T_SprKwartalneQR(NULL);
  m_WybFrm     = new T_SprKwartalWybFRM(NULL);
  //USTAWIENIA RAPORTU
  //USTAWIENIA FORMATKI WYBORU
	m_WybFrm->m_PrevTMI->OnClick      = preview;
	m_WybFrm->m_PrintTMI->OnClick     = print;
	m_WybFrm->m_RapSQRTMI->OnClick    = runSQR;
	m_WybFrm->m_RapXLSTMI->OnClick    = runSQRXLS;

}
//---------------------------------------------------------------------------
SprKwartalCTRL::~SprKwartalCTRL(void)
{
 delete m_Raport;
 delete m_WybFrm;
}
//---------------------------------------------------------------------------
void SprKwartalCTRL::run(void)
{
 show();
}
//---------------------------------------------------------------------------
void SprKwartalCTRL::show(void)
{
 prepareWybFrm();
 m_WybFrm->ShowModal();
}
//---------------------------------------------------------------------------
void SprKwartalCTRL::prepareWybFrm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall SprKwartalCTRL::print(TObject* Sender)
{
 prepareDM();
 m_Raport->print();
}
//---------------------------------------------------------------------------
void __fastcall  SprKwartalCTRL::preview(TObject* Sender)
{
 prepareDM();
 m_Raport->preview();
}
//---------------------------------------------------------------------------
void __fastcall  SprKwartalCTRL::runSQR(TObject* Sender)
{
 prepareDM();
 m_Raport->runSQR();
 sqr::SQRScript _Skrypt;
 sqr::SQRMan  _SqrMan;
 AnsiString _Path( ExtractFileDir(Application->ExeName) );
 _Path += "\\SQR_DED\\Sprawozdanie kwartalne.sqr";
 if(FileExists(_Path) )
 {
 _Skrypt.load(_Path);
 }
 _SqrMan.ShowRap(m_Raport->m_Data4SQR,_Skrypt);
 m_Raport->m_Data4SQR->EmptyDataSet();
 m_Raport->m_Data4SQR->Close();
}
//---------------------------------------------------------------------------
void __fastcall  SprKwartalCTRL::runSQRXLS(TObject* Sender)
{
 prepareDM();
 m_Raport->runSQR();
 sqr::SQRScript _Skrypt;
 sqr::SQRMan  _SqrMan;
 _SqrMan.setShowFile(false);
 AnsiString _Path( ExtractFileDir(Application->ExeName) );
 AnsiString _XlsRap, _HtmlRap;
 _Path += "\\SQR_DED\\Sprawozdanie kwartalne.sqr";
 if(FileExists(_Path) )
 {
 _Skrypt.load(_Path);
 }

 _HtmlRap =  _SqrMan.ShowRap(m_Raport->m_Data4SQR,_Skrypt);
 _XlsRap  =  _HtmlRap + ".xls";
 sqr::SQRMan::convertHTML2XLS(_HtmlRap,_XlsRap);
 m_Raport->m_Data4SQR->EmptyDataSet();
 m_Raport->m_Data4SQR->Close();
 ShellExecute(GetDesktopWindow(), "open",_XlsRap.c_str(), NULL, NULL,SW_SHOWNORMAL);



}
//---------------------------------------------------------------------------
void SprKwartalCTRL::prepareDM(void)
{
 m_Raport->setKomorka(m_WybFrm->edKomorka->Text);
 m_Raport->setOkres(m_WybFrm->cbOkres->ItemIndex + 1, StrToIntDef(m_WybFrm->edRok->Text,YearOf(Date())) );
 m_Raport->setZalacznik(m_WybFrm->edZalacznik->Text);
 m_Raport->setStrona( StrToIntDef(m_WybFrm->m_StronaED->Text,-1));
 m_Raport->m_Filtr1 = m_WybFrm->m_Filtr1CB->Checked;
 m_Raport->m_Sort   = m_WybFrm->m_SortRG->ItemIndex;
}
//---------------------------------------------------------------------------
