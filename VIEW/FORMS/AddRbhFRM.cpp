//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "AddRbhFRM.h"
#include "MANAGER\query_db.h"
#include "MANAGER\stream_db.h"
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_BASE_FRM"
#pragma link "Numedit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_AddRbhFRM::T_AddRbhFRM(TComponent* Owner)
	: T_SL_BASE_FRM(Owner)
{
 m_WarsztatSDB = new mng::StreamDB();
 m_MiesSDB = new mng::StreamDB();
 m_HarmSDB = new mng::StreamDB();
 m_ZlecSDB = new mng::StreamDB();
 m_SumSDB  = new mng::StreamDB();
 m_PlanQDB = new mng::QueryDB();
 m_WarsztatSDB->setQuery(AnsiString("SELECT * FROM PR_KOMORKI WHERE WARSZTAT='T' AND KOD NOT IN ('0/0','-1/-1')  ORDER BY KOD"));
 m_ZlecSDB->setQuery(" \
	 SELECT Z.*, S.NAZWA AS NAZ_SPRZETU, Z.ID_HARM FROM PR_ZLECENIA  Z \
		LEFT OUTER JOIN PR_MAGAZYN M ON M.ROK = Z.ROK_MAG AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT = Z.DEPOZYT AND M.ID_MAG = Z.ID_MAG \
		LEFT OUTER JOIN PR_SPRZET S  ON S.ID_SPRZETU = M.ID_SPRZETU \
		WHERE Z.ID_KOMORKI = :ID_KOMORKI AND Z.ROK = :ROK ORDER BY Z.SYGN_ZLECENIA \
 ");
 m_MiesSDB->setQuery("SELECT * FROM PR_MIESIACE WHERE NR_MIES BETWEEN 1 AND 12  ORDER BY NR_MIES");
 m_SDB->setQuery(\
 "SELECT z.ID_ZLECENIA, z.SYGN_ZLECENIA, z.ID_HARM, s.NAZWA, sum(r.PLAN_ILOSC) AS PLAN_ILOSC, sum(r.PLAN_RBH) AS PLAN_RBH, sum(r.ILOSC) AS ILOSC, sum(r.LICZBA_RBH) AS RBH FROM PR_ZLECENIA Z   \
  INNER JOIN PR_ZLECENIA_RBH R ON R.ID_ZLECENIA = Z.ID_ZLECENIA AND R.ROK = Z.ROK AND R.ID_KOMORKI = Z.ID_KOMORKI \
  LEFT OUTER JOIN PR_MAGAZYN M ON M.ROK = Z.ROK_MAG AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT = Z.DEPOZYT AND M.ID_MAG = Z.ID_MAG \
  LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
  WHERE Z.ID_KOMORKI = :ID_KOMORKI AND Z.ROK =:ROK   and r.MIESIAC = :MIESIAC \
  group by z.ID_ZLECENIA, z.sygn_zlecenia, z.id_harm, s.NAZWA HAVING sum(r.PLAN_ILOSC)<>0 OR sum(r.PLAN_RBH)<>0 OR sum(r.ILOSC)<>0 OR sum(r.LICZBA_RBH)<> 0 \
  ORDER BY Z.SYGN_ZLECENIA \
  ");
 m_SumSDB->setQuery("SELECT sum(r.PLAN_ILOSC) AS PLAN_ILOSC, sum(r.PLAN_RBH) AS PLAN_RBH, sum(r.ILOSC) AS ILOSC, sum(r.LICZBA_RBH) AS RBH FROM PR_ZLECENIA Z   \
  INNER JOIN PR_ZLECENIA_RBH R ON R.ID_ZLECENIA = Z.ID_ZLECENIA AND R.ROK = Z.ROK AND R.ID_KOMORKI = Z.ID_KOMORKI \
  LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = Z.ID_SPRZETU \
  WHERE Z.ID_KOMORKI = :ID_KOMORKI AND Z.ROK =:ROK   and r.MIESIAC = :MIESIAC");

 m_HarmSDB->setQuery("select NULL AS ID_HARMONOGRAMU, 'Wszystkie harmonogramy' AS ZADANIE, count(*) as counter from pr_harmonogram where ID_KOMORKI = :ID_KOMORKI  \
  union \
  select ID_HARMONOGRAMU, ZADANIE, 1 as counter from pr_harmonogram where ID_KOMORKI = :ID_KOMORKI    ");
 m_PlanQDB->setQuery("\
  select z.liczba_rbh as PLAN_RBH, SUM(case when r.liczba_rbh is null then 0.0 else r.LICZBA_RBH end) AS RBH , \
   m.ILOSC as PLAN_ILOSC, sum(r.ILOSC) AS ILOSC \
  from pr_zlecenia z \
   inner join pr_magazyn m on m.ROK = z.ROK_MAG and m.ID_KOMORKI = z.ID_KOMORKI_GLW and m.DEPOZYT  =z.DEPOZYT and m.ID_MAG = z.ID_MAG \
   INNER JOIN PR_ZLECENIA_RBH R ON R.ROK = Z.ROK AND R.ID_KOMORKI = Z.ID_KOMORKI AND R.ID_ZLECENIA = Z.ID_ZLECENIA \
   WHERE Z.ROK = :ROK AND Z.ID_KOMORKI =:ID_KOMORKI AND Z.ID_ZLECENIA = :ID_ZLECENIA AND r.MIESIAC <> :MIESIAC \
   group by z.LICZBA_RBH, m.ILOSC \
 ");

 m_WarsztatDS->DataSet = m_WarsztatSDB->getClient();
 m_MiesDS->DataSet     = m_MiesSDB->getClient();
 m_ZlecDS->DataSet     = m_ZlecSDB->getClient();
 m_HarmDS->DataSet     = m_HarmSDB->getClient();
 m_SumDS->DataSet      = m_SumSDB->getClient();
 m_Ini = new jbutils::TMyIni();

}
//---------------------------------------------------------------------------
__fastcall T_AddRbhFRM::~T_AddRbhFRM(void)
{
 delete m_WarsztatSDB;
 delete m_MiesSDB;
 delete m_ZlecSDB;
 delete m_HarmSDB;
 delete m_SumSDB;
 delete m_PlanQDB;
 delete m_Ini;

}
//---------------------------------------------------------------------------
int __fastcall T_AddRbhFRM::showModal(void)
{
 m_Rok =m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
 m_WarsztatSDB->open();
 m_WarsztatSDB->fieldByName("KOD")->DisplayWidth = 5;
 m_MiesSDB->open();
 m_WarsztatCB->KeyValue = 99999;
 m_WarsztatCB->KeyValue = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Warsztat", 1);
 m_MiesCB->KeyValue = 99999;
 m_MiesCB->KeyValue = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Miesi¹c", 1);
 openZlec();
 WindowState = wsMaximized;
 return ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::openZlec(void)
{
 m_ZlecSDB->close();
  m_ZlecSDB->paramByName("ROK")->AsInteger            = m_Rok;
  m_ZlecSDB->paramByName("ID_KOMORKI")->AsInteger   = m_WarsztatCB->KeyValue;
 m_ZlecSDB->open();
 m_ZlecSDB->fieldByName("SYGN_ZLECENIA")->DisplayWidth = 15;
 m_ZlecSDB->fieldByName("NAZ_SPRZETU")->DisplayWidth   = 35;
 m_ZlecSDB->fieldByName("ID_HARM")->DisplayWidth       = 5;
 if(m_HarmSDB->paramByName("ID_KOMORKI")->AsInteger != m_WarsztatCB->KeyValue)
 {
  m_HarmSDB->close();
   m_HarmSDB->paramByName("ID_KOMORKI")->AsInteger   = m_WarsztatCB->KeyValue;
  m_HarmSDB->open();
  m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->DisplayWidth = 5;
 }
 m_SDB->close();
  m_SDB->paramByName("ROK")->AsInteger             = m_Rok;
  m_SDB->paramByName("ID_KOMORKI")->AsInteger      = m_WarsztatCB->KeyValue;
  m_SDB->paramByName("miesiac")->AsInteger         = m_MiesCB->KeyValue;
 m_SDB->open();
 m_SDB->last();
 m_SDB->fieldByName("ID_ZLECENIA")->Visible        = false;
 m_SDB->fieldByName("SYGN_ZLECENIA")->DisplayLabel = "Nr KUT";
 m_SDB->fieldByName("NAZWA")->DisplayLabel         = "Nazwa sprzêtu";
 m_SDB->fieldByName("ID_HARM")->DisplayLabel       = "Harmonogram";
 m_SDB->fieldByName("ILOSC")->DisplayLabel         = "Iloœæ sprzêtu";
 m_SDB->fieldByName("RBH")->DisplayLabel           = "Liczba RBH";
 m_SDB->fieldByName("PLAN_RBH")->DisplayLabel      = "Planowane RBH";
 m_SDB->fieldByName("PLAN_ILOSC")->DisplayLabel    = "Planowana iloœæ";

 m_SDB->fieldByName("SYGN_ZLECENIA")->DisplayWidth = 20;
 m_SDB->fieldByName("NAZWA")->DisplayWidth         = 60;
 m_SDB->fieldByName("ILOSC")->DisplayWidth         = 4;
 m_SDB->fieldByName("RBH")->DisplayWidth           = 4;
 m_SDB->fieldByName("PLAN_RBH")->DisplayWidth      = 4;
 m_SDB->fieldByName("PLAN_ILOSC")->DisplayWidth    = 4;


 m_SumSDB->close();
  m_SumSDB->paramByName("ROK")->AsInteger          = m_Rok;
  m_SumSDB->paramByName("ID_KOMORKI")->AsInteger   = m_WarsztatCB->KeyValue;
  m_SumSDB->paramByName("miesiac")->AsInteger      = m_MiesCB->KeyValue;
 m_SumSDB->open();
 m_SumSDB->last();
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::m_SaveBBClick(TObject *Sender)
{
 m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Warsztat", m_WarsztatCB->KeyValue);
 m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Miesi¹c", m_MiesCB->KeyValue);
 Close();
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::refreshDane(TObject *Sender)
{
 openZlec();
 FormActivate(Sender);
 m_HarmCBCloseUp(Sender);
}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::FormActivate(TObject *Sender)
{
 clear();
 m_ZlecCB->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::m_AddBBClick(TObject *Sender)
{
 Variant _KeyVal = m_ZlecCB->KeyValue;
 int _IdDet = getIdDet();
 if(_IdDet > 0)
 {
  update(_IdDet);
 }
 else
 {
  insert();
 }
 openZlec();
 FormActivate(Sender);
 m_ZlecCB->KeyValue = _KeyVal;
 m_ZlecCBCloseUp(Sender);
 m_ZlecCB->KeyValue = -999;
}
//---------------------------------------------------------------------------
int __fastcall T_AddRbhFRM::getIdDet(void)
{
 int _Res(-1);
 mng::QueryDB _Q(" SELECT ID_ZLECENIA_RBH FROM PR_ZLECENIA_RBH WHERE ID_KOMORKI = :ID_KOMORKI AND ID_ZLECENIA = :ID_ZLECENIA AND ROK = :ROK  AND MIESIAC = :MIESIAC ");
 _Q.paramByName("ID_KOMORKI")->AsInteger  = m_ZlecSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.paramByName("ID_ZLECENIA")->AsInteger = m_ZlecSDB->fieldByName("ID_ZLECENIA")->AsInteger;
 _Q.paramByName("ROK")->AsInteger         = m_ZlecSDB->fieldByName("ROK")->AsInteger;
 _Q.paramByName("MIESIAC")->AsInteger     = m_MiesSDB->fieldByName("NR_MIES")->AsInteger;
 _Q.open();
 if(!_Q.isEmpty()) _Res = _Q.fieldByName("ID_ZLECENIA_RBH")->AsInteger;
 _Q.close();
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::update(const int _IdDet)
{
 int _Res(-1);
 mng::QueryDB _Q("UPDATE PR_ZLECENIA_RBH SET ILOSC = :ILOSC, LICZBA_RBH = :LICZBA_RBH, PLAN_ILOSC =:PLAN_ILOSC, PLAN_RBH =:PLAN_RBH WHERE ID_ZLECENIA_RBH = :ID_ZLECENIA_RBH");
 _Q.paramByName("ILOSC")->AsCurrency          = m_IlSprzED->AsCurrency;
 _Q.paramByName("LICZBA_RBH")->AsCurrency     = m_IlRBHEd->AsCurrency;
  _Q.paramByName("PLAN_RBH")->AsCurrency      = m_PlanRBHED->AsCurrency;
  _Q.paramByName("PLAN_ILOSC")->AsCurrency    = m_PlanIlED->AsCurrency;
 _Q.paramByName("ID_ZLECENIA_RBH")->AsInteger = _IdDet;
 _Q.execute();
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::insert(void)
{
 int _Res(-1);
 mng::QueryDB _Q("INSERT INTO PR_ZLECENIA_RBH(MIESIAC, ID_ZLECENIA_RBH, ID_ZLECENIA, LICZBA_RBH, ROK, ILOSC, ID_KOMORKI, PLAN_RBH, PLAN_ILOSC) \
				  VALUES(:MIESIAC, GEN_ID(PR_ZLECENIA_RBH_GEN,1),:ID_ZLECENIA, :LICZBA_RBH, :ROK, :ILOSC, :ID_KOMORKI, :PLAN_RBH, :PLAN_ILOSC)");
 _Q.paramByName("ID_KOMORKI")->AsInteger  = m_ZlecSDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.paramByName("ID_ZLECENIA")->AsInteger = m_ZlecSDB->fieldByName("ID_ZLECENIA")->AsInteger;
 _Q.paramByName("ROK")->AsInteger         = m_ZlecSDB->fieldByName("ROK")->AsInteger;
 _Q.paramByName("MIESIAC")->AsInteger     = m_MiesSDB->fieldByName("NR_MIES")->AsInteger;
 _Q.paramByName("ILOSC")->AsCurrency           = m_IlSprzED->AsCurrency;
 _Q.paramByName("LICZBA_RBH")->AsCurrency      = m_IlRBHEd->AsCurrency;
 _Q.paramByName("PLAN_RBH")->AsCurrency        = m_PlanRBHED->AsCurrency;
 _Q.paramByName("PLAN_ILOSC")->AsCurrency      = m_PlanIlED->AsCurrency;
 _Q.execute();
}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::FormKeyPress(TObject *Sender, wchar_t &Key)
{
 if(ActiveControl != m_AddBB && Key =='\r')
 {
  Key=0;
  SelectNext(ActiveControl,true,true);
 }
 else if(ActiveControl != m_AddBB && Key == VK_ESCAPE)
 {
  Key=0;
  SelectNext(ActiveControl,false,true);

 }
}
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::clear(void)
{
 m_IlSprzED->Clear();
 m_IlRBHEd->Clear();
 m_PlanRBHED->Clear();
 m_PlanIlED->Clear();
 m_ZlecCB->KeyValue =9999;
}
//---------------------------------------------------------------------------
const String T_AddRbhFRM::M_PLAN_WYK_SQL("\
  select \
  SUM(case when r.liczba_rbh is null then 0.0 else r.LICZBA_RBH end) AS RBH , \
  sum(r.ILOSC) AS ILOSC \
  from pr_zlecenia z \
   INNER JOIN PR_ZLECENIA_RBH R ON R.ROK = Z.ROK AND R.ID_KOMORKI = Z.ID_KOMORKI AND R.ID_ZLECENIA = Z.ID_ZLECENIA   AND NR_KOL =:NR_KOL  \
   WHERE Z.ROK_MAG = :ROK_MAG AND Z.ID_KOMORKI_GLW =:ID_KOMORKI_GLW AND Z.ID_MAG = :ID_MAG AND Z.DEPOZYT = :DEPOZYT AND Z.ROK <:ROK \
");
//---------------------------------------------------------------------------
void __fastcall T_AddRbhFRM::m_ZlecCBCloseUp(TObject *Sender)
{
  Variant _Pars[2];
  _Pars[0] = m_ZlecSDB->fieldByName("SYGN_ZLECENIA")->AsString;
  _Pars[1] = m_ZlecSDB->fieldByName("ID_ZLECENIA")->AsInteger;
  if(m_SDB->locate("SYGN_ZLECENIA;ID_ZLECENIA",VarArrayOf(_Pars,1)))
  {
   m_IlSprzED->AsCurrency  = m_SDB->fieldByName("ILOSC")->AsCurrency;
   m_IlRBHEd->AsCurrency   = m_SDB->fieldByName("RBH")->AsCurrency;
   m_PlanRBHED->AsCurrency = m_SDB->fieldByName("PLAN_RBH")->AsCurrency;
   m_PlanIlED->AsCurrency  = m_SDB->fieldByName("PLAN_ILOSC")->AsCurrency;
  }
  else
  {
   m_PlanQDB->close();
	m_PlanQDB->paramByName("ROK")->AsInteger         = m_ZlecSDB->fieldByName("ROK")->AsInteger;
	m_PlanQDB->paramByName("ID_KOMORKI")->AsInteger  = m_ZlecSDB->fieldByName("ID_KOMORKI")->AsInteger;
	m_PlanQDB->paramByName("ID_ZLECENIA")->AsInteger = m_ZlecSDB->fieldByName("ID_ZLECENIA")->AsInteger;
	m_PlanQDB->paramByName("MIESIAC")->AsInteger     = m_MiesCB->KeyValue;;
   m_PlanQDB->open();
   mng::QueryDB _Q(M_PLAN_WYK_SQL);
	_Q.paramByName("ROK_MAG")->AsInteger        = m_ZlecSDB->fieldByName("ROK_MAG")->AsInteger;
	_Q.paramByName("ID_KOMORKI_GLW")->AsInteger = m_ZlecSDB->fieldByName("ID_KOMORKI_GLW")->AsInteger;
	_Q.paramByName("ID_MAG")->AsInteger         = m_ZlecSDB->fieldByName("ID_MAG")->AsInteger;
	_Q.paramByName("DEPOZYT")->AsString         = m_ZlecSDB->fieldByName("DEPOZYT")->AsString;
	_Q.paramByName("ROK")->AsInteger            = m_ZlecSDB->fieldByName("ROK")->AsInteger;
	_Q.paramByName("NR_KOL")->AsInteger         = m_ZlecSDB->fieldByName("NR_KOL")->AsInteger;
   _Q.open();
   Currency _IlWyk = _Q.fieldByName("ILOSC")->AsCurrency;
   Currency _RBHWyk = _Q.fieldByName("RBH")->AsCurrency;
   _Q.close();
	m_PlanRBHED->AsCurrency = m_PlanQDB->fieldByName("PLAN_RBH")->AsCurrency - m_PlanQDB->fieldByName("RBH")->AsCurrency;
	m_PlanIlED->AsCurrency  = m_PlanQDB->fieldByName("PLAN_ILOSC")->AsCurrency -  m_PlanQDB->fieldByName("ILOSC")->AsCurrency - _IlWyk;
   m_PlanQDB->close();
  }
}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Warsztat", m_WarsztatCB->KeyValue);

 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE - DODAWANIE GODZIN","Miesi¹c", m_MiesCB->KeyValue);

}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::m_HarmCBCloseUp(TObject *Sender)
{
 if(!m_HarmCB->KeyValue.IsNull() && !m_HarmCB->KeyValue.IsEmpty() && m_HarmCB->KeyValue !=0 )
 {
  m_SDB->setFilter(String(" ID_HARM = ") + m_HarmCB->KeyValue);
  m_SDB->setFiltered(true);
  m_ZlecSDB->setFilter(String(" ID_HARM = ") + m_HarmCB->KeyValue);
  m_ZlecSDB->setFiltered(true);
 }
 else
 {
  m_SDB->setFilter("");
  m_SDB->setFiltered(false);
  m_ZlecSDB->setFilter("");
  m_ZlecSDB->setFiltered(false);
 }

}
//---------------------------------------------------------------------------

void __fastcall T_AddRbhFRM::m_DBGDblClick(TObject *Sender)
{
 m_ZlecCB->KeyValue =  m_SDB->fieldByName("ID_ZLECENIA")->AsInteger;
 m_ZlecCBCloseUp(Sender);
 m_PlanIlED->SetFocus();
}
//---------------------------------------------------------------------------


