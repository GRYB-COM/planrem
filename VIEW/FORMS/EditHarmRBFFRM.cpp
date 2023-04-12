//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditHarmRBFFRM.h"
#include "MANAGER\query_db.h"
#include "model_messengers_RBH4Mies.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_EditHarmRBFFRM::T_EditHarmRBFFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_RBHCD->CreateDataSet();
}
//---------------------------------------------------------------------------
int __fastcall  T_EditHarmRBFFRM::display(const msg::RBH4Mies& _RBH)
{
 int _Res;
  TDataSet * _DS(m_HarmDetDS->DataSet);
  fillRBHCD(_RBH);
  m_MiesCB->KeyValue = -999;
  m_MiesCB->KeyValue = _DS->FieldByName("MIESIAC")->AsInteger ;
  _DS->FieldByName("ILOSC")->OnChange = setRBH;
  _DS->FieldByName("PLAN_RBH")->OnChange = refreshRBHCD;
  _Res = ShowModal();
  _DS->FieldByName("ILOSC")->OnChange = NULL;
  _DS->FieldByName("PLAN_RBH")->OnChange = NULL;
return _Res;
}
//---------------------------------------------------------------------------
void __fastcall  T_EditHarmRBFFRM::fillRBHCD(const msg::RBH4Mies& _RBH)
{
m_RBHCD->Active ? m_RBHCD->EmptyDataSet() : m_RBHCD->CreateDataSet();
 for(msg::RBH4Mies::const_iterator _ItB=_RBH.begin(); _ItB != _RBH.end(); _ItB++)
 {
  m_RBHCD->Append();
  m_RBHCD->FieldByName("NR_MIES")->AsInteger      = _ItB->first;
  m_RBHCD->FieldByName("NAZ_MIES")->AsString      = LongMonthNames[_ItB->first-1];
  m_RBHCD->FieldByName("RBH_MIES")->AsFloat       = _ItB->second.getSum(msg::rtProd);
  m_RBHCD->FieldByName("PLAN_RBH")->AsFloat       = _ItB->second.getSum(msg::rtPlan);
  m_RBHCD->FieldByName("POZOSTALO")->AsFloat      = _ItB->second.getSum(msg::rtProd) - _ItB->second.getSum(msg::rtPlan);
  m_RBHCD->Post();
 }
}
//---------------------------------------------------------------------------
void __fastcall T_EditHarmRBFFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_RBHCD->EmptyDataSet();
 m_RBHCD->Close();
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmRBFFRM::AdvSmoothButton4Click(TObject *Sender)
{
 if(m_HarmDetDS->DataSet->FieldByName("NAZ_MIES")->IsNull)
 {
  m_HarmDetDS->DataSet->FieldByName("NAZ_MIES")->AsString = LongMonthNames[m_HarmDetDS->DataSet->FieldByName("MIESIAC")->AsInteger];
 }
 mng::QueryDB _Q("select first 1 gen_id(PR_HARMONOGRAM_DET_GEN,1) ID_H from PR_HARMONOGRAM_DET");
if(m_HarmDetDS->DataSet->FieldByName("ID_HARMONOGRAMU_DET")->IsNull || m_HarmDetDS->DataSet->FieldByName("ID_HARMONOGRAMU_DET")->AsInteger <=0 )
 {
  _Q.open();
  m_HarmDetDS->DataSet->FieldByName("ID_HARMONOGRAMU_DET")->AsInteger = _Q.fieldByName("ID_H")->AsInteger;
  _Q.close();
 }

 m_HarmDetDS->DataSet->Post();
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmRBFFRM::AdvSmoothButton1Click(TObject *Sender)
{
 m_HarmDetDS->DataSet->Cancel();
 Close();

}
//---------------------------------------------------------------------------
void __fastcall T_EditHarmRBFFRM::m_RBHCDCalcFields(TDataSet *DataSet)
{
 TDataSet * _D =m_HarmDetDS->DataSet;
 double _Bil =  m_RBHCDPOZOSTALO->AsFloat;
 if(m_RBHCDNR_MIES->AsInteger == _D->FieldByName("MIESIAC")->AsInteger)
 {

  _Bil -= StrToFloatDef(m_RBHED->Text.Trim(),0.00);
 }
 m_RBHCDBILANS->AsFloat = _Bil;
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmRBFFRM::m_MiesGRDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State)

{
   if(m_RBHCDBILANS->AsFloat <0.00)
   {
	m_MiesGR->Canvas->Font->Color = clRed;
   }
   else if(m_RBHCDBILANS->AsFloat ==0.00)
   {
	m_MiesGR->Canvas->Font->Color = clBlack;
   }
   else
   {
	m_MiesGR->Canvas->Font->Color = clGreen;
   }
   int _NrMies = m_RBHCDNR_MIES->AsInteger;
   if( (_NrMies <= 3) || (_NrMies >=7 && _NrMies <=9) )
   {
	m_MiesGR->Canvas->Brush->Color = TColor(0x003CF7FB);
   }
   else
   {
	m_MiesGR->Canvas->Brush->Color = TColor(0x0099FBFD);
   }
	m_MiesGR->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall T_EditHarmRBFFRM::setRBH(TField *Sender)
{
 TDataSet * _DS =  m_HarmDetDS->DataSet;
 if((_DS->State == dsEdit || _DS->State==dsInsert) )
 {
  TField   * _F = _DS->FieldByName("PLAN_RBH");
  if(_F->AsCurrency ==0.0)
  {
   _F->AsCurrency = m_HarmDS->DataSet->FieldByName("NORMA_RBH")->AsCurrency * _DS->FieldByName("ILOSC")->AsCurrency;
  }
 }

}
//---------------------------------------------------------------------------
void __fastcall T_EditHarmRBFFRM::refreshRBHCD(TField *Sender)
{
 m_RBHCD->Edit();
 m_RBHCD->Post();
 if(m_HarmDetDS->DataSet->State == dsInsert || m_HarmDetDS->DataSet->State == dsEdit)
 {
  m_HarmDetDS->DataSet->FieldByName("NAZ_MIES")->AsString =  m_RBHCD->FieldByName("NAZ_MIES")->AsString;
 }
}

//---------------------------------------------------------------------------
void __fastcall T_EditHarmRBFFRM::m_RBHEDChange(TObject *Sender)
{
 refreshRBHCD(NULL);
}
//---------------------------------------------------------------------------

