//---------------------------------------------------------------------------
#pragma hdrstop
#include "MeldTygCTRL.h"
#pragma package(smart_init)
#include "MeldTygWybFRM.h"
#include "MeldTygDM.h"
#include "MeldTygQRP.h"
#include "..\..\_INCLUDE\SQR.h"
#include <DateUtils.hpp>
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
MeldTygCTRL::MeldTygCTRL(void)
{
  m_Raport     = new T_MeldTygQRP(NULL);
  m_DM         = new T_MeldTygDM(NULL);
  m_WybFrm     = new T_MeldTygWybFRM(NULL);
  m_Ini        = new jbutils::TMyIni();
  //USTAWIENIA RAPORTU
	m_Raport->setSprzPrzyjDS(m_DM->getSprzPrzyjPlDS());
	m_Raport->setSprzPrzyjNplDS(m_DM->getSprzPrzyjNplDS());
	m_Raport->setSprzDepDS(m_DM->getSprzDepDS());
	m_Raport->setSprzPrzekDS(m_DM->getSprzPrzekDS());
	m_Raport->setSprzRemDS(m_DM->getSprzRemDS());
  //USTAWIENIA FORMATKI WYBORU
	m_WybFrm->m_PrevTMI->OnClick  = preview;
	m_WybFrm->m_PrintTMI->OnClick = print;
	m_WybFrm->m_SQRTMI->OnClick   = runSQR;
	m_WybFrm->m_ExcellTMI->OnClick   = runXLS;
}
//---------------------------------------------------------------------------
MeldTygCTRL::~MeldTygCTRL(void)
{
 delete m_Raport;
 delete m_DM;
 delete m_WybFrm;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void MeldTygCTRL::run(void)
{
 show();
}
//---------------------------------------------------------------------------
void MeldTygCTRL::show(void)
{
 prepareWybFrm();
 m_WybFrm->ShowModal();
}
//---------------------------------------------------------------------------
void MeldTygCTRL::prepareWybFrm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall MeldTygCTRL::print(TObject* Sender)
{
 prepareDM();
 prepareQR();
 m_DM->open();
 m_Raport->print();
 m_DM->close();
}
//---------------------------------------------------------------------------
void __fastcall  MeldTygCTRL::preview(TObject* Sender)
{
 prepareDM();
 prepareQR();
 m_DM->open();
 m_Raport->preview();
 m_DM->close();
}
//---------------------------------------------------------------------------
void MeldTygCTRL::prepareDM(void)
{
 T_MeldTygDM::Pars _Pars;
 _Pars.DataOd = m_WybFrm->m_DataOdDTP->Date;
 _Pars.DataDo = m_WybFrm->m_DataDoDTP->Date;
 m_DM->setPars(_Pars);
}
//---------------------------------------------------------------------------
void MeldTygCTRL::prepareQR(void)
{
 m_Raport->m_Title = getTitle();
}
//---------------------------------------------------------------------------
String MeldTygCTRL::getTitle(void)
{
 TDateTime _Od, _Do;
 _Od = m_WybFrm->m_DataOdDTP->Date;
 _Do = m_WybFrm->m_DataDoDTP->Date;
 unsigned short _Rok, _Mies, _Dz, _Rok1, _Mies1, _Dz1;
 _Od.DecodeDate(&_Rok,&_Mies,&_Dz);
 _Do.DecodeDate(&_Rok1,&_Mies1,&_Dz1);
 bool _TenDz  = _Od == _Do;
 bool _ZaTydz = _Rok == _Rok1 && _Mies == _Mies1 && DayOfTheWeek(_Od)==1 && DayOfTheWeek(_Do) > 4 && ((int) _Do - _Od) <=7;
 bool _TenMies = _Rok==_Rok1 && _Mies==_Mies1;
 String _Kier = m_Ini->ReadIniString("MELDUNEK TYGODNIOWY","Kierownik","kierownika ");
 String _Tyt("Meldunek ");
 if(_ZaTydz) _Tyt +="tygodniowy ";
 _Tyt += _Kier;
 if(_TenDz)
 {
  _Tyt += String(" na dzieñ: ") + DateToStr(_Od);
 }
 else if(_TenMies)
 {
  _Tyt += String(" za okres: ");
  _Tyt += FormatFloat("00-",_Dz) + FormatFloat("00",_Dz1) + String(".");
  _Tyt += FormatFloat("00",_Mies) + String(".") + String(_Rok);
 }
 else
 {
  _Tyt += String(" za okres: ");
  _Tyt += DateToStr(_Od) + String(" - ") +DateToStr(_Do);
 }
 return _Tyt;
}
//---------------------------------------------------------------------------
void __fastcall  MeldTygCTRL::runSQR(TObject* Sender)
{
 sqr::SQRScript _Head;
 sqr::SQRScript _PrzyjPl;
 sqr::SQRScript _PrzyjNpl;
 sqr::SQRScript _Dep;
 sqr::SQRScript _Rem;
 sqr::SQRScript _Przek;
 sqr::SQRScript _Foot;
 sqr::SQRMan::Skrypty _Skrypty;
 loadSQR(_Head,"Meld tyg header.sqr");
 _Head.getDefParams()->Values["TYTUL"] = getTitle().UpperCase();
 _Skrypty.push_back(&_Head);
 loadSQR(_PrzyjPl,"Sprzêt przyjêty zgodnie z planem.sqr");
 _Skrypty.push_back(&_PrzyjPl);
 loadSQR(_PrzyjNpl,"Sprzêt przyjêty spoza planu.sqr");
 _Skrypty.push_back(&_PrzyjNpl);
 loadSQR(_Dep,"Sprzêt przyjêty do depozytu.sqr");
 _Skrypty.push_back(&_Dep);
 loadSQR(_Rem,"Sprzêt wyremontowany.sqr");
_Skrypty.push_back(&_Rem);
 loadSQR(_Przek,"Sprzêt przekazany.sqr");
 _Skrypty.push_back(&_Przek);
  sqr::SQRMan _SqrMan;
 loadSQR(_Foot,"Meld tyg footer.sqr");
 _Skrypty.push_back(&_Foot);
 _SqrMan.ShowRap(_Skrypty);

}
//---------------------------------------------------------------------------
void __fastcall  MeldTygCTRL::runXLS(TObject* Sender)
{
 sqr::SQRScript _Head;
 sqr::SQRScript _PrzyjPl;
 sqr::SQRScript _PrzyjNpl;
 sqr::SQRScript _Dep;
 sqr::SQRScript _Rem;
 sqr::SQRScript _Przek;
 sqr::SQRScript _Foot;
 sqr::SQRMan::Skrypty _Skrypty;
 loadSQR(_Head,"Meld tyg header.sqr");
 _Head.getDefParams()->Values["TYTUL"] = getTitle().UpperCase();
 _Skrypty.push_back(&_Head);
 loadSQR(_PrzyjPl,"Sprzêt przyjêty zgodnie z planem.sqr");
 _Skrypty.push_back(&_PrzyjPl);
 loadSQR(_PrzyjNpl,"Sprzêt przyjêty spoza planu.sqr");
 _Skrypty.push_back(&_PrzyjNpl);
 loadSQR(_Dep,"Sprzêt przyjêty do depozytu.sqr");
 _Skrypty.push_back(&_Dep);
 loadSQR(_Rem,"Sprzêt wyremontowany.sqr");
_Skrypty.push_back(&_Rem);
 loadSQR(_Przek,"Sprzêt przekazany.sqr");
 _Skrypty.push_back(&_Przek);
  sqr::SQRMan _SqrMan;
  _SqrMan.setShowFile(false);
 loadSQR(_Foot,"Meld tyg footer.sqr");
 _Skrypty.push_back(&_Foot);
  AnsiString _HtmlRap =  _SqrMan.ShowRap(_Skrypty);
 AnsiString _XlsRap  =  _HtmlRap + ".xls";
 sqr::SQRMan::convertHTML2XLS(_HtmlRap,_XlsRap);
 ShellExecute(GetDesktopWindow(), "open",_XlsRap.c_str(), NULL, NULL,SW_SHOWNORMAL);


}
//---------------------------------------------------------------------------
void MeldTygCTRL::loadSQR(sqr::SQRScript &aSkrypt,const String& _SQR)
{
 String _SQRPath(ExtractFileDir(Application->ExeName));
 _SQRPath += String("\\SQR\\");
 _SQRPath += _SQR;
 aSkrypt.load(_SQRPath);
 aSkrypt.getDefParams()->Values["DATA_OD"] = DateToStr(m_WybFrm->m_DataOdDTP->Date);
 aSkrypt.getDefParams()->Values["DATA_DO"] = DateToStr(m_WybFrm->m_DataDoDTP->Date);
}
//---------------------------------------------------------------------------

