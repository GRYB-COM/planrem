//---------------------------------------------------------------------------
 #include <vcl.h>
#pragma hdrstop
 #include "MeldTygQRP.h"
#include "CUSTRAP\MODEL\QRBandMng.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
//STA£E
const int T_MeldTygQRP::M_BAND_HEIGHT(18);
const int T_MeldTygQRP::M_BAND_OFFSET(1);
const int T_MeldTygQRP::M_EXPR_HEIGHT(16);
const int T_MeldTygQRP::M_SHAPE_HEIGHT(19);

//---------------------------------------------------------------------------
__fastcall T_MeldTygQRP::T_MeldTygQRP(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall T_MeldTygQRP::~T_MeldTygQRP(void)
{

}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygQRP::preview(void)
{
 prepare();
 m_CompQR->Preview();
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygQRP::prepare(void)
{
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygQRP::print(void)
{
 prepare();
 m_CompQR->Print();
}
//---------------------------------------------------------------------------
void  __fastcall T_MeldTygQRP::setSprzPrzyjDS(TDataSet* _DS)
{
  m_SprzPrzyjQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall T_MeldTygQRP::setSprzPrzyjNplDS(TDataSet* _DS)
{
  m_SprzPrzyjNplQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall T_MeldTygQRP::setSprzPrzekDS(TDataSet* _DS)
{
 m_SprzPrzekQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall T_MeldTygQRP::setSprzRemDS(TDataSet* _DS)
{
 m_SprzRemQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall T_MeldTygQRP::setSprzDepDS(TDataSet* _DS)
{
 m_SprzDepQR->DataSet = _DS;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_CompQRAddReports(TObject *Sender)
{
 m_CompQR->Reports->Add(m_TitleQR);
 m_CompQR->Reports->Add(m_SprzPrzyjQR);
 m_CompQR->Reports->Add(m_SprzPrzyjNplQR);
 m_CompQR->Reports->Add(m_SprzDepQR);
 m_CompQR->Reports->Add(m_SprzRemQR);
 m_CompQR->Reports->Add(m_SprzPrzekQR);
 m_CompQR->Reports->Add(m_PodsumQR);
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygQRP::m_DetailPrzyjQBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 TQuickRep* _Rep = dynamic_cast<TQuickRep*>(Sender->ParentReport);

 int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzPrzyjQRE,_Rep->DataSet->FieldByName("NAZ_SPRZ")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_JWPrzyjQRE,_Rep->DataSet->FieldByName("NAZ_JEDNOSTKI")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_PodstawaQRE,_Rep->DataSet->FieldByName("PODSTAWA")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtPrzyjQRE,_Rep->DataSet->FieldByName("PROT_PRZYJ")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_NrFabrQRE,_Rep->DataSet->FieldByName("NR_FABR")->AsAnsiString);

  QRBandMng::setBandHeight(Sender, (M_BAND_HEIGHT* _Lines) + M_BAND_OFFSET, M_EXPR_HEIGHT*_Lines,(M_SHAPE_HEIGHT*_Lines) + M_BAND_OFFSET);
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::QRBand3BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 int _Lines(0);
 //QRBandMng::countBandLines(_Lines,m_NazSprzPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("NAZ_SPRZ_PRZEK")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_JWPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("JW_PRZEK")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_ProtPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("PROT_PRZEK")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_UwagiPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("UWAGI_PRZEK")->AsAnsiString);

  //QRBandMng::setBandHeight(Sender, (M_BAND_HEIGHT* _Lines) + M_BAND_OFFSET, M_EXPR_HEIGHT*_Lines,(M_SHAPE_HEIGHT*_Lines) + M_BAND_OFFSET);

}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::QRBand9BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
  int _Lines(0);
 //QRBandMng::countBandLines(_Lines,m_NazSprzRemQRE,m_SprzRemQR->DataSet->FieldByName("NAZ_SPRZ_REM")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_JWRemQRE,m_SprzRemQR->DataSet->FieldByName("JW_REM")->AsAnsiString);

 //QRBandMng::setBandHeight(Sender, (M_BAND_HEIGHT* _Lines) + M_BAND_OFFSET, M_EXPR_HEIGHT*_Lines,(M_SHAPE_HEIGHT*_Lines) + M_BAND_OFFSET);

}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::QRBand15BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 int _Lines(0);
 //QRBandMng::countBandLines(_Lines,m_NazSprzDepQRE,m_SprzDepQR->DataSet->FieldByName("NAZ_SPRZ_DEP")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_JWDepQRE,m_SprzDepQR->DataSet->FieldByName("JW_DEP")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_ProtStTechDepQRE,m_SprzDepQR->DataSet->FieldByName("PROT_ST_TECH_DEP")->AsAnsiString);
 //QRBandMng::countBandLines(_Lines,m_ProtDepQRE,m_SprzDepQR->DataSet->FieldByName("PROT_DEP")->AsAnsiString);

  //QRBandMng::setBandHeight(Sender, (M_BAND_HEIGHT* _Lines) + M_BAND_OFFSET, M_EXPR_HEIGHT*_Lines,(M_SHAPE_HEIGHT*_Lines) + M_BAND_OFFSET);

}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::clearLP(TCustomQuickRep *Sender, bool &PrintReport)
{
 m_LP=0;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::getLP(TObject *sender, UnicodeString &Value)
{
 Value = ++m_LP;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_NrMagQEPrint(TObject *sender, UnicodeString &Value)
{
 TReplaceFlags _RFl;
 _RFl<<rfReplaceAll;
 Value = StringReplace(Value,"&nbsp","",_RFl);
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::QRExpr4Print(TObject *sender, UnicodeString &Value)
{
 Value = m_Title;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_SprzPrzyjPHPrint(TObject *sender, UnicodeString &Value)

{
 Value = m_Title + String(" - ") +m_SprzPrzyjLB->Caption;
}
//---------------------------------------------------------------------------


void __fastcall T_MeldTygQRP::m_SprzPrzyjNplPHPrint(TObject *sender, UnicodeString &Value)

{
 Value = m_Title + String(" - ") +m_SprzPrzyjNplLB->Caption;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_SprzDepHPPrint(TObject *sender, UnicodeString &Value)

{
 Value = m_Title + String(" - ") +m_SprzDepLB->Caption;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_SprzRemDetailQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 TQuickRep* _Rep = dynamic_cast<TQuickRep*>(Sender->ParentReport);

 int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzRemQRE,_Rep->DataSet->FieldByName("NAZ_SPRZ")->AsAnsiString.UpperCase());
 QRBandMng::countBandLines(_Lines,m_JWRemQRE,_Rep->DataSet->FieldByName("NAZ_JEDNOSTKI")->AsAnsiString.UpperCase());
 QRBandMng::countBandLines(_Lines,m_PodstRemQRE,_Rep->DataSet->FieldByName("PODSTAWA")->AsAnsiString.UpperCase());
 QRBandMng::countBandLines(_Lines,m_ProtPrzyjRemQRE,_Rep->DataSet->FieldByName("PROT_PRZYJ")->AsAnsiString.UpperCase());
 QRBandMng::countBandLines(_Lines,m_NrFabrRemQRE,_Rep->DataSet->FieldByName("NR_FABR")->AsAnsiString.UpperCase());

  QRBandMng::setBandHeight(Sender, (15* _Lines) + 1,14*_Lines,(M_SHAPE_HEIGHT*_Lines) + 1);
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_SprzRemQRPHPrint(TObject *sender, UnicodeString &Value)
{
 Value = m_Title+ " - " + m_SprzRemQRLB->Caption;
}
//---------------------------------------------------------------------------

void __fastcall T_MeldTygQRP::m_SprzPrzekPHLBPrint(TObject *sender, UnicodeString &Value)
{
 Value = m_Title+ " - " + m_SprzPrzekPHLB->Caption;
}
//---------------------------------------------------------------------------

