//---------------------------------------------------------------------------
 #include <vcl.h>
#pragma hdrstop
 #include "MeldTyg.h"
#include "CUSTRAP\MODEL\QRBandMng.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//STA£E
const int TMeldTygQRP::M_BAND_HEIGHT(37);
const int TMeldTygQRP::M_EXPR_HEIGHT(29);
const int TMeldTygQRP::M_SHAPE_HEIGHT(35);

//---------------------------------------------------------------------------
__fastcall TMeldTygQRP::TMeldTygQRP(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TMeldTygQRP::~TMeldTygQRP(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TMeldTygQRP::preview(void)
{
 prepare();
 m_CompQR->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMeldTygQRP::print(void)
{
 prepare();
 m_CompQR->Print();
}
//---------------------------------------------------------------------------
void  __fastcall TMeldTygQRP::setSprzPrzyjDS(TDataSet* _DS)
{
  m_SprzPrzyjQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall TMeldTygQRP::setSprzPrzekDS(TDataSet* _DS)
{
 m_SprzPrzekQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall TMeldTygQRP::setSprzRemDS(TDataSet* _DS)
{
 m_SprzRemQR->DataSet = _DS;
}
//---------------------------------------------------------------------------
void  __fastcall TMeldTygQRP::setSprzDepDS(TDataSet* _DS)
{
 m_SprzDepQR->DataSet = _DS;
}
//---------------------------------------------------------------------------

void __fastcall TMeldTygQRP::m_CompQRAddReports(TObject *Sender)
{
 m_CompQR->Reports->Add(m_TitleQR);
 m_CompQR->Reports->Add(m_SprzPrzyjQR);
 m_CompQR->Reports->Add(m_SprzPrzekQR);
 m_CompQR->Reports->Add(m_SprzRemQR);
 m_CompQR->Reports->Add(m_SprzDepQR);
 m_CompQR->Reports->Add(m_PodsumQR);
}
//---------------------------------------------------------------------------
void __fastcall TMeldTygQRP::m_DetailPrzyjQBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzPrzyjQRE,m_SprzPrzyjQR->DataSet->FieldByName("NAZ_SPRZ_PRZYJ")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_JWPrzyjQRE,m_SprzPrzyjQR->DataSet->FieldByName("JW_PRZYJ")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtStTechPrzyjQRE,m_SprzPrzyjQR->DataSet->FieldByName("PROT_ST_TECH_PRZYJ_PRZYJ")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtPrzyjQRE,m_SprzPrzyjQR->DataSet->FieldByName("PROT_PRZYJ")->AsAnsiString);

 QRBandMng::setBandHeight(Sender, M_BAND_HEIGHT* _Lines, M_EXPR_HEIGHT*_Lines,M_SHAPE_HEIGHT*_Lines);
}
//---------------------------------------------------------------------------

void __fastcall TMeldTygQRP::QRBand3BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("NAZ_SPRZ_PRZEK")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_JWPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("JW_PRZEK")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtPrzekQRE,m_SprzPrzekQR->DataSet->FieldByName("PROT_PRZEK")->AsAnsiString);

 QRBandMng::setBandHeight(Sender, M_BAND_HEIGHT* _Lines, M_EXPR_HEIGHT*_Lines,M_SHAPE_HEIGHT*_Lines);

}
//---------------------------------------------------------------------------

void __fastcall TMeldTygQRP::QRBand9BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
  int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzRemQRE,m_SprzRemQR->DataSet->FieldByName("NAZ_SPRZ_REM")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_JWRemQRE,m_SprzRemQR->DataSet->FieldByName("JW_REM")->AsAnsiString);

 QRBandMng::setBandHeight(Sender, M_BAND_HEIGHT* _Lines, M_EXPR_HEIGHT*_Lines,M_SHAPE_HEIGHT*_Lines);

}
//---------------------------------------------------------------------------

void __fastcall TMeldTygQRP::QRBand15BeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 int _Lines(0);
 QRBandMng::countBandLines(_Lines,m_NazSprzDepQRE,m_SprzDepQR->DataSet->FieldByName("NAZ_SPRZ_DEP")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_JWDepQRE,m_SprzDepQR->DataSet->FieldByName("JW_DEP")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtStTechDepQRE,m_SprzDepQR->DataSet->FieldByName("PROT_ST_TECH_DEP_DEP")->AsAnsiString);
 QRBandMng::countBandLines(_Lines,m_ProtDepQRE,m_SprzDepQR->DataSet->FieldByName("PROT_DEP")->AsAnsiString);

 QRBandMng::setBandHeight(Sender, M_BAND_HEIGHT* _Lines, M_EXPR_HEIGHT*_Lines,M_SHAPE_HEIGHT*_Lines);

}
//---------------------------------------------------------------------------

