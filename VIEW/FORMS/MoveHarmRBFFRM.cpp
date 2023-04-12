//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MoveHarmRBFFRM.h"
#include "MANAGER\query_db.h"
#include "model_messengers_RBH4Mies.h"
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_MoveHarmRBHFRM::T_MoveHarmRBHFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_RBHCD->CreateDataSet();
 m_PrzenCD->CreateDataSet();
}
//---------------------------------------------------------------------------
int __fastcall  T_MoveHarmRBHFRM::display(const msg::RBH4Mies& _RBH)
{
  fillRBHCD(_RBH);
  fillPrzenCD();
  m_MiesCB->KeyValue = -999;
  m_MiesCB->KeyValue = m_HarmDetDS->DataSet->FieldByName("MIESIAC")->AsInteger ;

  return ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall  T_MoveHarmRBHFRM::fillPrzenCD(void)
{
 m_PrzenCD->Active ? m_PrzenCD->EmptyDataSet() : m_PrzenCD->CreateDataSet();
 m_PrzenCD->Append();
  m_PrzenCD->FieldByName("MIESIAC")->AsInteger  = m_HarmDetDS->DataSet->FieldByName("MIESIAC")->AsInteger;
  m_PrzenCD->FieldByName("ILOSC")->AsFloat      = m_HarmDetDS->DataSet->FieldByName("ILOSC")->AsFloat;
  m_PrzenCD->FieldByName("PLAN_RBH")->AsFloat   = m_HarmDetDS->DataSet->FieldByName("PLAN_RBH")->AsFloat;
 m_PrzenCD->Post();
}
//---------------------------------------------------------------------------
void __fastcall  T_MoveHarmRBHFRM::fillRBHCD(const msg::RBH4Mies& _RBH)
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
void __fastcall T_MoveHarmRBHFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_RBHCD->EmptyDataSet();
 m_PrzenCD->EmptyDataSet();
}
//---------------------------------------------------------------------------

void __fastcall T_MoveHarmRBHFRM::AdvSmoothButton4Click(TObject *Sender)
{
 int    _MiesOld, _MiesNew, _IdHarm,_IdHarmDet, _Rok;
 double _IlOld, _IlNew, _ROld, _RNew;

 _IdHarm    =  m_HarmDetDS->DataSet->FieldByName("ID_HARMONOGRAMU")->AsInteger;
 _IdHarmDet =  m_HarmDetDS->DataSet->FieldByName("ID_HARMONOGRAMU_DET")->AsInteger;
 _Rok       =  m_HarmDetDS->DataSet->FieldByName("ROK")->AsInteger;
 _MiesOld   = m_HarmDetDS->DataSet->FieldByName("MIESIAC")->AsInteger;
 _MiesNew   =   m_PrzenCD->FieldByName("MIESIAC")->AsInteger;

 _IlOld = m_HarmDetDS->DataSet->FieldByName("ILOSC")->AsFloat;
 _IlNew = m_PrzenCD->FieldByName("ILOSC")->AsFloat;

 _ROld = m_HarmDetDS->DataSet->FieldByName("PLAN_RBH")->AsFloat;
 _RNew = m_PrzenCD->FieldByName("PLAN_RBH")->AsFloat;

 if(_MiesOld == _MiesNew)
 {
   mng::MessageDialog::warning("Nie mo¿na przenosiæ na ten sam miesi¹c", "B£¥D");
 }
 else if(_IlNew <0)
 {
   mng::MessageDialog::warning("Wprowadzona ujemna iloœæ sprzêtu", "B£¥D");
 }
 else if(_RNew <0)
 {
   mng::MessageDialog::warning("Wprowadzona ujemna iloœæ roboczogodzin", "B£¥D");
 }
 else if(_IlNew > _IlOld)
 {
   mng::MessageDialog::warning("Wprowadzona iloœæ sprzêtu jest wiêksza\n od dostêpnej do przeniesienia", "B£¥D");
 }
 else if(_RNew > _ROld)
 {
   mng::MessageDialog::warning("Wprowadzona iloœæ roboczogodzin jest wiêksza\n od dostêpnej do przeniesienia", "B£¥D");
 }
 else
 {
  mng::QueryDB _Q;
  mng::QueryDB _QS;
  AnsiString   _SQL;
  if(_IlOld == _IlNew && _RNew == _ROld)
  {
   _SQL =  " UPDATE PR_HARMONOGRAM_DET SET MIESIAC = :MIESIAC WHERE  ID_HARMONOGRAMU_DET = :ID_DET ";
   _Q.setQuery(_SQL);
   _Q.paramByName("MIESIAC")->AsInteger =_MiesNew;
   _Q.paramByName("ID_DET")->AsInteger  =_IdHarmDet;
   _Q.execute();
  }
  else
  {
   _SQL  ="SELECT ID_HARMONOGRAMU_DET, ILOSC, PLAN_RBH  FROM PR_HARMONOGRAM_DET WHERE ";
   _SQL += AnsiString(" ID_HARMONOGRAMU = ") + AnsiString(_IdHarm) + AnsiString(" AND ");
   _SQL += AnsiString(" ROK = ") + AnsiString(_Rok) + AnsiString(" AND ");
   _SQL += AnsiString(" MIESIAC = ") + AnsiString(_MiesNew);
   _QS.setQuery(_SQL);
   _QS.open();
   if(_QS.isEmpty() )
   {
	_SQL  = "INSERT INTO PR_HARMONOGRAM_DET(ID_HARMONOGRAMU, ROK, MIESIAC, ILOSC, PLAN_RBH) VALUES(:ID_HARMONOGRAMU, :ROK, :MIESIAC, :ILOSC, :PLAN_RBH) ";
	_Q.setQuery(_SQL);
	_Q.paramByName("ID_HARMONOGRAMU")->AsInteger  = _IdHarm;
	_Q.paramByName("ROK")->AsInteger              = _Rok;
	_Q.paramByName("MIESIAC")->AsInteger          = _MiesNew;
	_Q.paramByName("ILOSC")->AsFloat              = _IlNew;
	_Q.paramByName("PLAN_RBH")->AsFloat           = _RNew;
	_Q.execute();
   }
   else
   {
   _SQL =  " UPDATE PR_HARMONOGRAM_DET SET ILOSC = :ILOSC, PLAN_RBH =:PLAN_RBH WHERE ID_HARMONOGRAMU_DET = :ID_DET";
   _Q.setQuery(_SQL);
   _Q.paramByName("ILOSC")->AsFloat    = _QS.fieldByName("ILOSC")->AsFloat + _IlNew;
   _Q.paramByName("PLAN_RBH")->AsFloat = _QS.fieldByName("PLAN_RBH")->AsFloat+ _RNew;
   _Q.paramByName("ID_DET")->AsInteger = _QS.fieldByName("ID_HARMONOGRAMU_DET")->AsInteger;
   _Q.execute();
   }
   _SQL =  " UPDATE PR_HARMONOGRAM_DET SET ILOSC = :ILOSC, PLAN_RBH =:PLAN_RBH WHERE ID_HARMONOGRAMU_DET = :ID_DET";
   _Q.setQuery(_SQL);
   _Q.paramByName("ILOSC")->AsFloat    = _IlOld - _IlNew;
   _Q.paramByName("PLAN_RBH")->AsFloat = _ROld  -  _RNew;
   _Q.paramByName("ID_DET")->AsInteger = _IdHarmDet;
   _Q.execute();
  }
  Close();
 }
}
//---------------------------------------------------------------------------

void __fastcall T_MoveHarmRBHFRM::AdvSmoothButton1Click(TObject *Sender)
{
 m_HarmDetDS->DataSet->Cancel();
 Close();

}
//---------------------------------------------------------------------------
void __fastcall T_MoveHarmRBHFRM::m_RBHCDCalcFields(TDataSet *DataSet)
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

void __fastcall T_MoveHarmRBHFRM::m_MiesGRDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State)

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
	m_MiesGR->DefaultDrawColumnCell(Rect,DataCol,Column,State);

}
//---------------------------------------------------------------------------

