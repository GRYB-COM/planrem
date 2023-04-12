//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ListaHarmFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include <memory>
#include "EditHarmFRM.h"
#include "MANAGER\queries.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
#include "HarmID.h"
#include "MANAGER\bookmark_man.h"
#include "MANAGER\various_man.h"
#include "MANAGER\grid_drawer.h"
#include "MoveHarmRBFFRM.h"
#include "model_messengers_RBH4War.h"
#include "model_readers_RBHReader.h"
#include "ListaOldHarmFRM.h"
#include "DelHarmFRM.h"
#include "MANAGER\is_manager.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_ListaHarmFRM::T_ListaHarmFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Ini = new jbutils::TMyIni();
 m_HarmSDB = new mng::StreamDB();
 m_HarmDS->DataSet = m_HarmSDB->getClient();
 m_WarSDB = new mng::StreamDB();
 m_WarSDB->setQuery("SELECT W.ID_KOMORKI,  W.KOD, W.NAZWA \
FROM PR_KOMORKI W \
INNER  JOIN PR_OSOBY O ON O.ID_KOMORKI = W.ID_KOMORKI \
WHERE  W.WARSZTAT='T' \
GROUP BY W.ID_KOMORKI, W.KOD, W.NAZWA \
ORDER BY KOD");
 m_WarDS->DataSet = m_WarSDB->getClient();
 fillMiesCD();
 m_RokPA->Enabled = false;
 m_Rok = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
 m_RokED->Text = m_Rok;
 m_RBH4War = new msg::RBH4War();
}
//---------------------------------------------------------------------------
__fastcall T_ListaHarmFRM::~T_ListaHarmFRM(void)
{
 delete m_HarmSDB;
 delete m_WarSDB;
 delete m_Ini;
 delete m_RBH4War;
}
//---------------------------------------------------------------------------
void __fastcall  T_ListaHarmFRM::fillMiesCD(void)
{
 m_MiesCD->Close();
 m_MiesCD->CreateDataSet();
 for(int i=-1; i <13; i++)
 {
  m_MiesCD->Append();
	m_MiesCD->FieldByName("NR_MIES")->AsInteger =  i;
		 if(i==-1) m_MiesCD->FieldByName("MIESIAC")->AsString = "NIEPRZYDZIELONE";
	else if(i== 0) m_MiesCD->FieldByName("MIESIAC")->AsString = "CA£Y ROK";
	else           m_MiesCD->FieldByName("MIESIAC")->AsString = LongMonthNames[i-1].UpperCase();
 }
 m_MiesCD->SaveToFile("Mies.xml");
}
//---------------------------------------------------------------------------
void __fastcall __fastcall T_ListaHarmFRM::setRok(const int _Rok)
{
 int _BiezRok = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
 m_Rok = _Rok;
 m_RokED->Text = fabs((double) m_Rok);
 m_ImportBB->Visible = false;
 if(m_Rok >_BiezRok)
 {
   m_RokED->Font->Color = clGreen;
   m_ImportBB->Visible = true;
 }
 else if(m_Rok == _BiezRok)
 {
   m_RokED->Font->Color = clBlack;
 }
 else if(m_Rok <_BiezRok)
 {
   m_RokED->Font->Color = clRed;
 }
 if(m_Rok < 0)
 {
  m_RokLB->Caption = "KOREKTA ZA ROK:";
  m_RokLB->Font->Color = clRed;
  TFontStyles _St = m_RokLB->Font->Style;
  _St << fsBold;
  m_RokLB->Font->Style   = _St;
  m_ReadPlanBB->Visible  = mng::Manager::instance().checkRight("RRZKP");
  m_ZatwBB->Visible      = mng::Manager::instance().checkRight("RRZKP");
 }
 else
 {
  m_ReadPlanBB->Visible = false;
  m_ZatwBB->Visible     = false;

 }
}
//---------------------------------------------------------------------------
void __fastcall  T_ListaHarmFRM::fillRBHCD(void)
{
 readers::RBHReader::Pars _Pars;
 _Pars.AddPlan = true;
 _Pars.Rok     = abs(m_Rok);
 _Pars.RokPlan = m_Rok;
  m_RBH4War->clear();
 readers::RBHReader _RBHReader;
 _RBHReader.read(*m_RBH4War,_Pars);
 m_RBHCD->Active ? m_RBHCD->EmptyDataSet() : m_RBHCD->CreateDataSet();
 for(msg::RBH4War::const_iterator _ItW = m_RBH4War->begin(); _ItW != m_RBH4War->end(); _ItW++)
 {
  for(msg::RBH4Mies::const_iterator _ItM = _ItW->second.begin(); _ItM != _ItW->second.end(); _ItM++)
  {
   m_RBHCD->Append();
	m_RBHCD->FieldByName("ID_KOMORKI")->AsInteger = _ItW->first;
	m_RBHCD->FieldByName("NR_MIES")->AsInteger    = _ItM->first;
	m_RBHCD->FieldByName("RBH_MIES")->AsCurrency     = _ItM->second.getSum(msg::rtProd);
	m_RBHCD->FieldByName("PLAN_RBH")->AsCurrency     = _ItM->second.getSum(msg::rtPlan);
	m_RBHCD->FieldByName("POZOSTALO")->AsCurrency    = _ItM->second.getSum(msg::rtProd) - _ItM->second.getSum(msg::rtPlan);
   m_RBHCD->Post();
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall  T_ListaHarmFRM::fillMiesCD(const int _IdKomorki)
{
 mng::BookmarkMan  _MiesCDB(m_MiesCD);
 mng::ControlsMan  _MiesCDC(m_MiesCD);
 m_MiesCD->AfterScroll = NULL;
 m_MiesCD->First();
 int _NrMies;
 while(!m_MiesCD->Eof)
 {
  _NrMies = m_MiesCD->FieldByName("NR_MIES")->AsInteger;
  if(_NrMies >=0)
  {
   filter(_NrMies,_IdKomorki);
   m_MiesCD->Edit();
	m_MiesCD->FieldByName("RBH_MIES")->AsFloat  = getAggSum("SUM_RBH_MIES");
	m_MiesCD->FieldByName("PLAN_RBH")->AsFloat  = getAggSum("SUM_PLAN_RBH");
	m_MiesCD->FieldByName("POZOSTALO")->AsFloat = getAggSum("SUM_POZOSTALO");
   m_MiesCD->Post();
  }
   m_MiesCD->Next();
 }
 m_MiesCD->AfterScroll = m_MiesCDAfterScroll;

}
//---------------------------------------------------------------------------
double __fastcall T_ListaHarmFRM::getAggSum(const String& _FieldName)
{
 double _Res(0.00);
 String _ResS;
 _ResS = m_RBHCD->FieldByName(_FieldName)->Text.Trim();
 _Res = StrToFloatDef(_ResS,0.00);
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::openHarm(const int _Mies, const int _IdKomorki)
{
 AnsiString _ColList1("H.ID_HARMONOGRAMU, D.MIESIAC, SUM(D.ILOSC) AS ILOSC , SUM(D.PLAN_RBH) AS PLAN_RBH,  \
(CASE WHEN J.JW IS NULL THEN ' ' ELSE J.JW END) || ' ' ||  (CASE WHEN J.MIEJSCOWOSC IS NULL THEN ' ' ELSE J.MIEJSCOWOSC END ) AS JW_MIEJSCOWOSC, \
R.NAZWA AS NAZ_REMONTU, SPR.NAZWA AS NAZ_SPRZETU,  H.ZADANIE, H.DATA_OD, H.DATA_DO , H.ID_KOMORKI, 'AAA' AS FLAGA  ");
AnsiString _TabRef(" PR_HARMONOGRAM H LEFT OUTER JOIN PR_JEDNOSTKI J ON (J.ID_JEDNOSTKI = H.ID_JEDNOSTKI ) \
LEFT OUTER JOIN PR_REMONTY R ON (R.ID_REMONTU = H.ID_REMONTU)  \
LEFT OUTER JOIN PR_HARMONOGRAM_DET D ON D.ROK = H.ROK AND  D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU \
LEFT OUTER JOIN PR_SPRZET SPR ON SPR.ID_SPRZETU = H.ID_SPRZETU ");
 AnsiString _ColList2("H.ID_HARMONOGRAMU, SUM(D.ILOSC) AS ILOSC , SUM(D.PLAN_RBH) AS PLAN_RBH,  \
(CASE WHEN J.JW IS NULL THEN ' ' ELSE J.JW END) || ' ' ||  (CASE WHEN J.MIEJSCOWOSC IS NULL THEN ' ' ELSE J.MIEJSCOWOSC END ) AS JW_MIEJSCOWOSC, \
R.NAZWA AS NAZ_REMONTU,  SPR.NAZWA AS NAZ_SPRZETU, H.ZADANIE, H.DATA_OD, H.DATA_DO , H.ID_KOMORKI, 'AAA' AS FLAGA  ");
AnsiString _GroupList1("H.ID_HARMONOGRAMU, D.MIESIAC, J.JW, J.MIEJSCOWOSC, R.NAZWA, SPR.NAZWA, H.ZADANIE, H.DATA_OD, H.DATA_DO , H.ID_KOMORKI");
AnsiString _GroupList2("H.ID_HARMONOGRAMU,  J.JW, J.MIEJSCOWOSC, R.NAZWA, SPR.NAZWA, H.ZADANIE, H.DATA_OD, H.DATA_DO , H.ID_KOMORKI");
mng::Query _Q(_TabRef,_ColList1);
_Q.setGroupList(_GroupList1);
_Q.attachWherePred( new mng::ComparePredicate( "H.ROK", m_Rok ));
if(_Mies <0)
{
 _Q.attachWherePred(mng::ExplicitPredicate(" D.MIESIAC IS NULL"));
}
else if(_Mies==0)
{
 _Q.setColumnList(_ColList2);
 _Q.setGroupList(_GroupList2);
}
else if( _Mies >0)
{
 _Q.attachWherePred(mng::ComparePredicate(" D.MIESIAC", _Mies));
}
 _Q.attachWherePred(new mng::ComparePredicate(" H.ID_KOMORKI", _IdKomorki ));
m_HarmSDB->open(_Q);
TField * _F = m_HarmSDB->fieldByName("PLAN_RBH");
TNumericField* _NF = dynamic_cast<TNumericField*>(_F);
if(_NF)
{
 _NF->DisplayFormat = "########0.00";
}
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::filter(const int _Mies, const int _IdKomorki)
{
 m_RBHCD->Filtered = false;
 AnsiString _FilterRBH;
 if(_Mies != 0)
 {
  _FilterRBH = AnsiString(" NR_MIES = ") + _Mies;
  _FilterRBH += AnsiString(" AND ");
 }

 _FilterRBH += AnsiString(" ID_KOMORKI = ");
 _FilterRBH += _IdKomorki;

 m_RBHCD->Filter   = _FilterRBH;
 m_RBHCD->Filtered = true;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::m_MiesCDAfterScroll(TDataSet *DataSet)
{
 int _Mies      = m_MiesCD->FieldByName("NR_MIES")->AsInteger;
 int _IdKomorki = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 openHarm(_Mies,_IdKomorki);
 filter(_Mies,_IdKomorki);
 colPoz();
 m_MoveBB->Enabled  = _Mies > 0;

}
//---------------------------------------------------------------------------

void __fastcall T_ListaHarmFRM::m_WarCBCloseUp(TObject *Sender)
{
 fillMiesCD(m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger);
 m_MiesCDAfterScroll(m_MiesCD);
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::FormShow(TObject *Sender)
{
  setEdit();//MUSI BYÆ NA POCZ¥TKU BO M_mOVEbb
 m_MiesCD->AfterScroll = NULL;
 m_WarSDB->open();
 m_WarCB->KeyValue = -999;
 m_WarCB->KeyValue = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator komórki",1);
 TLocateOptions _Lop;
 int _Mies =  m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Miesi¹c",1);
 m_MiesCD->Locate("NR_MIES",_Mies,_Lop);
 fillRBHCD();
 m_WarCBCloseUp(m_WarCB);
 m_MiesCD->AfterScroll = m_MiesCDAfterScroll;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::setEdit(void)
{
 int _BiezRok(m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date())));
 bool _Enabled = mng::Manager::instance().checkRight("RRPLA");
 m_DodajBB->Visible  = _Enabled;
 m_EdytujBB->Visible = _Enabled;
 m_UsunBB->Visible   = _Enabled;
 m_MoveBB->Visible   = _Enabled;
 m_ImportBB->Visible = _Enabled &&  m_Rok == _BiezRok+1;
 m_DodajBB->Enabled  = _Enabled;
 m_EdytujBB->Enabled = _Enabled;
 m_UsunBB->Enabled   = _Enabled;
 m_MoveBB->Enabled   = _Enabled;
 m_ImportBB->Enabled = _Enabled &&  m_Rok == _BiezRok+1;

}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
  m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator komórki",m_WarCB->KeyValue);
  m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Miesi¹c",m_MiesCD->FieldByName("NR_MIES")->AsInteger);
 m_WarSDB->close();
 m_HarmSDB->close();
}
//---------------------------------------------------------------------------

void __fastcall T_ListaHarmFRM::m_SaveBBClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::colPoz(void)
{
 if(!m_RBHCDSUM_POZOSTALO->Text.Trim().IsEmpty())
 {
  double _Poz = m_RBHCDSUM_POZOSTALO->Text.ToDouble();
  if(_Poz ==0.00)
  {
   m_PozostaloLB->Font->Color  = clBlack;
   m_PozostaloDBT->Font->Color = clBlack;
  }
  else if(_Poz > 0.00)
  {
   m_PozostaloLB->Font->Color  = clGreen;
   m_PozostaloDBT->Font->Color = clGreen;
  }
  else if(_Poz < 0.00)
  {
   m_PozostaloLB->Font->Color  = clRed;
   m_PozostaloDBT->Font->Color = clRed;
  }
 }

}

void __fastcall T_ListaHarmFRM::m_DodajBBClick(TObject *Sender)
{
 msg::HarmID _Id(-1,m_Rok);
 displayDet(_Id);
 m_WarCBCloseUp(m_WarCB);
  m_HarmSDB->last();
}
//---------------------------------------------------------------------------

void __fastcall T_ListaHarmFRM::m_EdytujBBClick(TObject *Sender)
{
mng::ControlsMan _HarmCtrl(m_HarmSDB->getClient());
 msg::HarmID _Id(m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger,m_Rok);
 int _RecNo = m_HarmSDB->getClient()->RecNo;
 displayDet(_Id);
 m_HarmSDB->locate("ID_HARMONOGRAMU",_Id.NrHarm);
 m_WarCBCloseUp(m_WarCB);
 m_HarmSDB->getClient()->RecNo = _RecNo;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::displayDet(const msg::HarmID& _HarmId)
{
 int _IdHarm = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 T_EditHarmFRM::Pars _Pars;
 _Pars.HarmId      = _HarmId;
 _Pars.NrMies      = m_MiesCD->FieldByName("NR_MIES")->AsInteger;
 _Pars.IdWarsztatu = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Pars.RBHMies     = m_RBH4War->operator[](_Pars.IdWarsztatu);
 std::auto_ptr<T_EditHarmFRM> _F( new T_EditHarmFRM(NULL) );
 _F->display(_Pars);
 fillRBHCD();
 m_MiesCDAfterScroll(m_MiesCD);
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::m_MoveBBClick(TObject *Sender)
{
 mng::ControlsMan _HarmCtrl(m_HarmSDB->getClient());
 int _IdHarm = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 int _RecNo = m_HarmSDB->getClient()->RecNo;
 mng::StreamDB _HarmDetSDB;
 const AnsiString _SQL("select hd.*, m.NAZ_MIES from  pr_harmonogram h \
 inner join PR_HARMONOGRAM_DET hd on hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok \
 inner join pr_miesiace m on m.NR_MIES = hd.MIESIAC \
where h.ID_HARMONOGRAMU =:ID_HARM and h.ROK = :ROK and hd.MIESIAC = :MIESIAC ");

 _HarmDetSDB.setQuery(_SQL);
 _HarmDetSDB.paramByName("ID_HARM")->AsInteger = _IdHarm;
 _HarmDetSDB.paramByName("ROK")->AsInteger     = m_Rok;
 _HarmDetSDB.paramByName("MIESIAC")->AsInteger = m_MiesCD->FieldByName("NR_MIES")->AsInteger;
 _HarmDetSDB.open();
  _HarmDetSDB.edit();
 std::auto_ptr<T_MoveHarmRBHFRM> _F(new T_MoveHarmRBHFRM(NULL) );
 _F->m_HarmDS->DataSet    = m_HarmSDB->getClient();
 _F->m_HarmDetDS->DataSet = _HarmDetSDB.getClient();
 _F->display(m_RBH4War->operator[](m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger));
 fillRBHCD();
 m_MiesCDAfterScroll(m_MiesCD);
 m_HarmSDB->locate("ID_HARMONOGRAMU",_IdHarm);
 m_WarCBCloseUp(m_WarCB);
 m_HarmSDB->getClient()->RecNo = _RecNo;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::m_MiesGRDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State)

{

   if(Column->FieldName =="POZOSTALO" &&  m_MiesCDPOZOSTALO->AsFloat <0.00)
   {
	m_MiesGR->Canvas->Font->Color = clRed;
   }
   else if(State.Contains(gdSelected))
   {
	if(Column->FieldName =="POZOSTALO" &&  m_MiesCDPOZOSTALO->AsFloat >0.00)
	{
	 m_MiesGR->Canvas->Font->Color = clYellow;
	}
	else
	{
	 m_MiesGR->Canvas->Font->Color = clWhite;
	}
   }
   else
   {
	if(Column->FieldName =="POZOSTALO" &&  m_MiesCDPOZOSTALO->AsFloat >0.00)
	{
	 m_MiesGR->Canvas->Font->Color = clGreen;
	}
	else
	{
	 m_MiesGR->Canvas->Font->Color = clBlack;
	}

   }
   m_MiesGR->Canvas->Brush->Color  =  State.Contains(gdSelected) ? clHotLight : clInfoBk;
   mng::GridDrawer::drawColumnGrid(m_MiesGR,Column->Field != NULL ?Column->Field->Text : UnicodeString(), Rect,DataCol,Column,State );
}
//---------------------------------------------------------------------------

void __fastcall T_ListaHarmFRM::m_ImportBBClick(TObject *Sender)
{
 std::auto_ptr<T_ListaOldHarmFRM> _Lst(new T_ListaOldHarmFRM(NULL)) ;
 _Lst->setRok(m_Rok -1);
 _Lst->ShowModal();
  fillRBHCD();
 m_MiesCDAfterScroll(m_MiesCD);
 m_WarCBCloseUp(m_WarCB);
 m_HarmSDB->first();
}
//---------------------------------------------------------------------------

void __fastcall T_ListaHarmFRM::m_UsunBBClick(TObject *Sender)
{
 mng::ControlsMan _HarmCtrl(m_HarmSDB->getClient());
 msg::HarmID _Id(m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger,m_Rok);
 int _RecNo = m_HarmSDB->getClient()->RecNo;
 T_DelHarmFRM::Pars _Pars;
 _Pars.HarmId  = _Id;
 _Pars.NrMies  = m_MiesCD->FieldByName("NR_MIES")->AsInteger;
 std::auto_ptr<T_DelHarmFRM> _DelF(new T_DelHarmFRM(NULL));
 if(_DelF->display(_Pars)==mrOk)
 {
  fillRBHCD();
  m_WarCBCloseUp(m_WarCB);
  m_MiesCDAfterScroll(m_MiesCD);
  if(_RecNo <= m_HarmSDB->getClient()->RecordCount) m_HarmSDB->getClient()->RecNo = _RecNo;
 }
}
//---------------------------------------------------------------------------
const String T_ListaHarmFRM::M_GET_PLAN_SQL(
"INSERT INTO PR_HARMONOGRAM(ROK, ID_USLUGI, ID_KOMORKI, NR_ZADANIA, ZADANIE, ID_JEDNOSTKI, ID_REMONTU, \
ID_HARMONOGRAMU_GL, DATA_OD, DATA_DO, ID_HARMONOGRAMU, ID_SPRZETU, NORMA_RBH, TYP) \
SELECT -ROK, ID_USLUGI, ID_KOMORKI, NR_ZADANIA, ZADANIE, ID_JEDNOSTKI, ID_REMONTU, ID_HARMONOGRAMU_GL, DATA_OD, \
DATA_DO, ID_HARMONOGRAMU, ID_SPRZETU, NORMA_RBH, TYP FROM PR_HARMONOGRAM \
WHERE ID_KOMORKI = :ID_KOMORKI AND ROK= :ROK"
);
const String T_ListaHarmFRM::M_DEL_PLAN_SQL(
 "DELETE FROM PR_HARMONOGRAM WHERE ID_KOMORKI = :ID_KOMORKI AND ROK= :ROK"
);
const String T_ListaHarmFRM::M_GET_DET_PLAN_SQL(
"INSERT INTO PR_HARMONOGRAM_DET(ROK, ID_HARMONOGRAMU, MIESIAC, ILOSC, PLAN_RBH, UWAGI) \
SELECT -HD.ROK,  HD.ID_HARMONOGRAMU, HD.MIESIAC, HD.ILOSC, HD.PLAN_RBH, HD.UWAGI FROM PR_HARMONOGRAM_DET hd \
inner join PR_HARMONOGRAM h on h.ROK = hd.ROK and h.ID_HARMONOGRAMU = hd.ID_HARMONOGRAMU \
WHERE H.ROK=:ROK AND H.ID_KOMORKI = :ID_KOMORKI"
);
//---------------------------------------------------------------------------
void __fastcall T_ListaHarmFRM::m_ReadPlanBBClick(TObject *Sender)
{
 if(m_Rok >=0 ) return;
 mng::QueryDB _Q;
_Q.setQuery(M_DEL_PLAN_SQL);
_Q.prepare();
_Q.paramByName("ROK")->AsInteger = m_Rok;
_Q.paramByName("ID_KOMORKI")->AsInteger = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
_Q.execute();
_Q.setQuery(M_GET_PLAN_SQL);
_Q.prepare();
_Q.paramByName("ROK")->AsInteger = abs(m_Rok);
_Q.paramByName("ID_KOMORKI")->AsInteger = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
_Q.execute();
_Q.setQuery(M_GET_DET_PLAN_SQL);
_Q.prepare();
_Q.paramByName("ROK")->AsInteger = abs(m_Rok);
_Q.paramByName("ID_KOMORKI")->AsInteger = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
_Q.execute();
 m_MiesCD->AfterScroll = NULL;
 fillRBHCD();
 m_WarCBCloseUp(m_WarCB);
 m_MiesCD->AfterScroll = m_MiesCDAfterScroll;

}
//---------------------------------------------------------------------------
const String T_ListaHarmFRM::M_SEL_KOR_SQL(
"SELECT * FROM PR_HARMONOGRAM WHERE ROK=:ROK AND ID_KOMORKI = :ID_KOMORKI"
);
const String T_ListaHarmFRM::M_ZATW_KOR_SQL(
"UPDATE OR INSERT INTO PR_HARMONOGRAM \
 (ROK, ID_USLUGI, ID_KOMORKI, NR_ZADANIA, ZADANIE, ID_JEDNOSTKI, ID_REMONTU, ID_HARMONOGRAMU_GL, DATA_OD, DATA_DO, \
  ID_HARMONOGRAMU, ID_SPRZETU, NORMA_RBH, TYP) \
VALUES(:ROK, :ID_USLUGI, :ID_KOMORKI, :NR_ZADANIA, :ZADANIE, :ID_JEDNOSTKI, :ID_REMONTU, :ID_HARMONOGRAMU_GL, \
:DATA_OD, :DATA_DO, :ID_HARMONOGRAMU, :ID_SPRZETU, :NORMA_RBH, :TYP)"
);
const String T_ListaHarmFRM::M_DEL_DET_PLAN_SQL(
"delete from PR_HARMONOGRAM_DET hd where \
exists (SELECT null FROM PR_HARMONOGRAM h \
WHERE h.ID_HARMONOGRAMU= hd.ID_HARMONOGRAMU and h.ROK= hd.rok and h.ROK=:ROK AND h.ID_KOMORKI = :ID_KOMORKI) "
);

void __fastcall T_ListaHarmFRM::m_ZatwBBClick(TObject *Sender)
{
 if(m_Rok >=0 ) return;
 mng::StreamDB _S;
 _S.setQuery(M_SEL_KOR_SQL);
 _S.paramByName("ROK")->AsInteger = m_Rok;
 _S.paramByName("ID_KOMORKI")->AsInteger = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 mng::QueryDB _Q(M_ZATW_KOR_SQL);
 _Q.prepare();
 _S.open();
 while(!_S.isEof())
 {
  _Q.paramByName("ROK")->AsInteger                = abs(m_Rok);
  _Q.paramByName("ID_USLUGI")->AsInteger         = _S.fieldByName("ID_USLUGI")->AsInteger;
  _Q.paramByName("ID_KOMORKI")->AsInteger         = _S.fieldByName("ID_KOMORKI")->AsInteger;
  _Q.paramByName("NR_ZADANIA")->AsString          = _S.fieldByName("NR_ZADANIA")->AsString;
  _Q.paramByName("ZADANIE")->AsString             = _S.fieldByName("ZADANIE")->AsString;
  _Q.paramByName("ID_JEDNOSTKI")->AsInteger       = _S.fieldByName("ID_JEDNOSTKI")->AsInteger;
  _Q.paramByName("ID_REMONTU")->AsInteger         = _S.fieldByName("ID_REMONTU")->AsInteger;
  _Q.paramByName("ID_HARMONOGRAMU_GL")->AsInteger = _S.fieldByName("ID_HARMONOGRAMU_GL")->AsInteger;
  _Q.paramByName("DATA_OD")->AsDateTime           = _S.fieldByName("DATA_OD")->AsDateTime;
  _Q.paramByName("DATA_DO")->AsDateTime           = _S.fieldByName("DATA_DO")->AsDateTime;
  _Q.paramByName("ID_HARMONOGRAMU")->AsInteger    = _S.fieldByName("ID_HARMONOGRAMU")->AsInteger;
  _Q.paramByName("ID_SPRZETU")->AsInteger         = _S.fieldByName("ID_SPRZETU")->AsInteger;
  if(_S.fieldByName("ID_SPRZETU")->AsInteger ==0 ) _Q.paramByName("ID_SPRZETU")->Clear();
  _Q.paramByName("NORMA_RBH")->AsCurrency         = _S.fieldByName("NORMA_RBH")->AsCurrency;
  _Q.paramByName("TYP")->AsString                 = _S.fieldByName("TYP")->AsString;
  _Q.execute();
  _S.next();
 }
 _Q.setQuery(M_DEL_DET_PLAN_SQL);
 _Q.prepare();
 _Q.paramByName("ROK")->AsInteger                = abs(m_Rok);
 _Q.paramByName("ID_KOMORKI")->AsInteger         = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.execute();
 _Q.setQuery(M_GET_DET_PLAN_SQL);
 _Q.prepare();
 _Q.paramByName("ROK")->AsInteger                = m_Rok;
 _Q.paramByName("ID_KOMORKI")->AsInteger         = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.execute();
  _Q.setQuery(M_DEL_PLAN_SQL);
 _Q.prepare();
 _Q.paramByName("ROK")->AsInteger                = m_Rok;
 _Q.paramByName("ID_KOMORKI")->AsInteger         = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.execute();
 m_MiesCD->AfterScroll = NULL;
 fillRBHCD();
 m_WarCBCloseUp(m_WarCB);
 m_MiesCD->AfterScroll = m_MiesCDAfterScroll;

 }
//---------------------------------------------------------------------------
/* delete from PR_HARMONOGRAM h where h.ROK =:rok and h.ID_KOMORKI = :ID_KOMORKI and
not exists(select null from pr_harmonogram hw where hw.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hw.ROK =  - h.ROK) and
not exists(select null from PR_MAGAZYN m where m.ROK = h.ROK and m.ID_HARM = h.ID_HARMONOGRAMU)  and
not exists(select null from PR_zlecenia z where z.ROK = h.ROK and z.ID_HARM = h.ID_HARMONOGRAMU)*/
