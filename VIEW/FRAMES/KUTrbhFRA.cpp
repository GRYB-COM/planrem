//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KUTrbhFRA.h"
#include "isManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "manager\utils_db.h"
#include "manager\grid_drawer.h"
#include "ZlecID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_KUTrbhFRA::T_KUTrbhFRA(TComponent* Owner)
	: TFrame(Owner)
{
  m_RbhSDB = new mng::StreamDB();
  m_RbhSDB->setQuery(" SELECT * FROM PR_ZLECENIA_RBH WHERE ID_ZLECENIA = :ID_ZLECENIA AND ID_KOMORKI = :ID_KOMORKI  AND ROK = :ROK ");
  m_RbhSDB->getClient()->IndexFieldNames = "MIESIAC";
  m_RbhSDB->setKeyFields("ID_ZLECENIA_RBH");
  m_RbhSDB->setIndexFieldNames("MIESIAC");
  m_RbhSDB->setUpdateMode(upWhereKeyOnly);
  TClientDataSet* _Cl = m_RbhSDB->getClient();
  TAggregate *_Agg = _Cl->Aggregates->Add();
  _Agg->AggregateName =m_SumIlPED->Name;
  _Agg->Expression =" SUM(PLAN_ILOSC) ";
  _Agg->Active = true;
  _Cl->AggregatesActive = true;
  _Agg = _Cl->Aggregates->Add();
  _Agg->AggregateName =m_SumIlRED->Name;
  _Agg->Expression =" SUM(ILOSC) ";
  _Agg->Active = true;
  _Cl->AggregatesActive = true;

  _Agg = _Cl->Aggregates->Add();
  _Agg->AggregateName =m_SumRBHPED->Name;
  _Agg->Expression =" SUM(PLAN_RBH) ";
  _Agg->Active = true;
  _Cl->AggregatesActive = true;

  _Agg = _Cl->Aggregates->Add();
  _Agg->AggregateName =m_SumRBHRED->Name;
  _Agg->Expression =" SUM(LICZBA_RBH) ";
  _Agg->Active = true;
  _Cl->AggregatesActive = true;


}
//---------------------------------------------------------------------------
__fastcall T_KUTrbhFRA::~T_KUTrbhFRA()
{
  m_RbhSDB->close();
  delete m_RbhSDB;
}
//---------------------------------------------------------------------------
TDataSet * __fastcall T_KUTrbhFRA::getDataSet(void)
{
  return m_RbhSDB->getClient();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::show(const msg::ZlecID& _ZlecID)
{
 m_RbhSDB->getClient()->AfterInsert = NULL;
 m_RbhDS->DataSet = m_RbhSDB->getClient();
 m_RbhSDB->paramByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
 m_RbhSDB->paramByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
 m_RbhSDB->paramByName("ROK")->AsInteger         = _ZlecID.Rok;
 m_RbhSDB->open();
 TClientDataSet* _Cl = m_RbhSDB->getClient();
 if(_Cl->RecordCount <12)
 {
	mng::QueryDB q;
	for(int i = 1; i <= 12; ++i)
	{
	 if(!m_RbhSDB->locate("MIESIAC",i))
	 {
	  m_RbhSDB->append();
	  q.open("SELECT MAX(ID_ZLECENIA), GEN_ID(PR_ZLECENIA_RBH_GEN,1) ID FROM PR_ZLECENIA_RBH ");
	  m_RbhSDB->fieldByName("ID_ZLECENIA_RBH")->AsInteger = q.fieldByName("ID")->AsInteger;
	  int id = m_RbhSDB->fieldByName("ID_ZLECENIA_RBH")->AsInteger;

	  q.close();
	  m_RbhSDB->fieldByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
	  m_RbhSDB->fieldByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
	  m_RbhSDB->fieldByName("ROK")->AsInteger         = _ZlecID.Rok;
	  m_RbhSDB->fieldByName("MIESIAC")->AsInteger = i;
	  m_RbhSDB->fieldByName("ILOSC")->AsInteger = 0;
	  m_RbhSDB->fieldByName("LICZBA_RBH")->AsInteger = 0;
	  m_RbhSDB->fieldByName("PLAN_ILOSC")->AsInteger = 0;
	  m_RbhSDB->fieldByName("PLAN_RBH")->AsInteger = 0;
	  m_RbhSDB->post();
	}
	}
 }
 mng::UtilsDB::setNumericMask(m_RbhSDB->getClient(),"LICZBA_RBH;ILOSC;PLAN_ILOSC;PLAN_RBH","###,###,##0.00");

 afterPost(m_RbhSDB->getClient());
 m_RbhSDB->getClient()->AfterInsert = afterInsert;
 m_RbhSDB->getClient()->AfterPost = afterPost;
 m_RbhSDB->edit();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::apply(msg::ZlecID* _ZlecID)
{
  if(_ZlecID != NULL)
  {
	 m_RbhSDB->first();
	 while(!m_RbhSDB->isEof())
	 {
	  m_RbhSDB->edit();
	  m_RbhSDB->fieldByName("ID_ZLECENIA")->AsInteger = _ZlecID->IdZlecenia;
	  m_RbhSDB->fieldByName("ID_KOMORKI")->AsInteger  = _ZlecID->IdKomorki;
	  m_RbhSDB->fieldByName("ROK")->AsInteger         = _ZlecID->Rok;
	  m_RbhSDB->post();
	  m_RbhSDB->next();
	 }
  }

  m_RbhSDB->applyUpdates();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::m_DBGDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
 if(Column->FieldName == "MIESIAC")
 {
	 int okres = m_RbhSDB->fieldByName("MIESIAC")->AsInteger;
	 AnsiString nazwa;

	 switch(okres)
			{
				case 1: nazwa  = "Styczeñ";break;
				case 2: nazwa  = "Luty";break;
				case 3: nazwa  = "Marzec";break;
				case 4: nazwa  = "Kwiecieñ";break;
				case 5: nazwa  = "Maj";break;
				case 6: nazwa  = "Czerwiec";break;
				case 7: nazwa  = "Lipiec";break;
				case 8: nazwa  = "Sierpieñ";break;
				case 9: nazwa  = "Wrzesieñ";break;
				case 10: nazwa  = "PaŸdziernik";break;
				case 11: nazwa = "Listopad";break;
				case 12: nazwa = "Grudzieñ";break;
				default : nazwa = IntToStr(okres);
			}

	 mng::GridDrawer::drawColumn(m_DBG,nazwa ,Rect,DataCol,Column,State);
 }
}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::afterInsert(TDataSet *DataSet)
{
  DataSet->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::afterPost(TDataSet *DataSet)
{
 suma(m_SumIlPED);
 suma(m_SumIlRED);
 suma(m_SumRBHPED);
 suma(m_SumRBHRED);

}
//---------------------------------------------------------------------------
void __fastcall T_KUTrbhFRA::suma(TEdit* _SumED)
{
 if(m_RbhSDB->isOpen())
 {
  TClientDataSet* _Cl = m_RbhSDB->getClient();
  TAggregate*  _Agg = m_RbhSDB->getClient()->Aggregates->Find(_SumED->Name);
  if(_Agg && _Agg->Active && !_Agg->Value().IsNull() )
  {
   double _Val =  _Agg->Value();
   _SumED->Text = FormatFloat("###,###,##0.00", _Val);
  }
 }

}


