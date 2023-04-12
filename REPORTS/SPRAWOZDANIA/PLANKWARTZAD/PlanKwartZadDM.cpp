//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "PlanKwartZadDM.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\queries.h"
#include "model_readers_RBHReader.h"
#include "model_messengers_RBH4War.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_PlanKwartZadDM::T_PlanKwartZadDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartZadDM::open(const T_PlanKwartZadDM::Pars& _Pars)
{
  m_Pars = _Pars;
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();

	 m_Client->FieldByName("KOD_USLUGI")->AsString       =  _Reader.fieldByName("KOD_USLUGI")->AsString;
	 m_Client->FieldByName("NAZ_USLUGI")->AsString       =  _Reader.fieldByName("NAZ_USLUGI")->AsString;

	 m_Client->FieldByName("KOD_REMONTU")->AsString      =  _Reader.fieldByName("KOD_REMONTU")->AsString;
	 m_Client->FieldByName("NAZ_REMONTU")->AsString      =  _Reader.fieldByName("NAZ_REMONTU")->AsString;

	 m_Client->FieldByName("NAZ_SPRZETU")->AsString      =  _Reader.fieldByName("NAZ_SPRZETU")->AsString.Trim() + " " + _Reader.fieldByName("NR_ZADANIA")->AsString.Trim();
	 m_Client->FieldByName("JW_MIASTO")->AsString        =  _Reader.fieldByName("JW")->AsString + " " +_Reader.fieldByName("MIEJSCOWOSC")->AsString.Trim();
	 m_Client->FieldByName("JIM")->AsString              =  _Reader.fieldByName("INDEKS_MAT")->AsString;

	 m_Client->FieldByName("NR_HARM")->AsInteger         =  _Reader.fieldByName("ID_HARMONOGRAMU")->AsInteger;

	 m_Client->FieldByName("ILOSC")->AsCurrency          =  _Reader.fieldByName("ILOSC")->AsCurrency;
	 m_Client->FieldByName("RBH_NORMA")->AsCurrency      =  _Reader.fieldByName("RBH_NORMA")->AsCurrency;

	 m_Client->FieldByName("RBH_I")->AsCurrency          =  _Reader.fieldByName("RBH_I")->AsCurrency;
	 m_Client->FieldByName("ILOSC_I")->AsCurrency        =  _Reader.fieldByName("ILOSC")->AsCurrency;

	 m_Client->FieldByName("RBH_II")->AsCurrency         =  _Reader.fieldByName("RBH_II")->AsCurrency;
	 m_Client->FieldByName("ILOSC_II")->AsCurrency       =  _Reader.fieldByName("ILOSC_II")->AsCurrency;

	 m_Client->FieldByName("RBH_III")->AsCurrency        =  _Reader.fieldByName("RBH_III")->AsCurrency;
	 m_Client->FieldByName("ILOSC_III")->AsCurrency      =  _Reader.fieldByName("ILOSC_III")->AsCurrency;
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
 const AnsiString T_PlanKwartZadDM::M_COL_LIST_SQL("\
CASE WHEN U.POZYCJA = 999 THEN U.POZYCJA ELSE   U.P_N END  as KOD_USLUGI, \
CASE WHEN U.POZYCJA = 999 THEN 'POZOSTA£E ZADANIA' ELSE  U.NAZ_REMONTU  END AS NAZ_USLUGI, \
h.ID_HARMONOGRAMU, s.NAZWA as NAZ_SPRZETU, H.ZADANIE, H.NR_ZADANIA, S.INDEKS_MAT, \
R.KOD_REM AS KOD_REMONTU,R.NAZWA AS NAZ_REMONTU, J.JW, J.MIEJSCOWOSC,  \
(select sum(hd.PLAN_RBH)/SUM(HD.ILOSC) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok) AS RBH_NORMA, \
(select SUM(HD.ILOSC) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok) AS ILOSC, \
(select sum(hd.PLAN_RBH) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD) AS RBH_I, \
(select sum(hd.ilosc) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD) AS ILOSC_I,  \
(select sum(hd.PLAN_RBH) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD+1) AS RBH_II, \
(select sum(hd.ilosc) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD+1) AS ILOSC_II,  \
(select sum(hd.PLAN_RBH) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD+2) AS RBH_III,\
(select sum(hd.ilosc) from PR_HARMONOGRAM_DET hd  where hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.rok and hd.MIESIAC = :MIES_OD+2) AS ILOSC_III \
");
//---------------------------------------------------------------------------
const AnsiString T_PlanKwartZadDM::M_TABLE_REF_SQL("\
pr_harmonogram  h \
LEFT OUTER JOIN PR_KODY_USLUG U ON U.ID_USLUGI    = H.ID_USLUGI  \
LEFT OUTER JOIN PR_REMONTY    R ON R.ID_REMONTU   = H.ID_REMONTU \
LEFT OUTER JOIN PR_SPRZET     S ON S.ID_SPRZETU   = H.ID_SPRZETU  \
LEFT OUTER JOIN PR_JEDNOSTKI  J ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI \
");
//---------------------------------------------------------------------------
mng::Query __fastcall T_PlanKwartZadDM::getQuery(void)
{
  mng::Query _Q(M_TABLE_REF_SQL,M_COL_LIST_SQL);
   _Q.attachWherePred(new mng::ComparePredicate(" H.ROK  "," :ROK ") );
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred(new mng::ComparePredicate(" H.ID_KOMORKI  "," :ID_WARSZTATU ") );
   _Q.attachWherePred(new mng::ExplicitPredicate(" ( EXTRACT(MONTH FROM h.DATA_OD) <= :MIES_OD+2 OR  EXTRACT(MONTH FROM h.DATA_DO) <=:MIES_OD+2) "));
   _Q.attachWherePred(new mng::ExplicitPredicate(" ( EXTRACT(MONTH FROM h.DATA_OD) >= :MIES_OD OR  EXTRACT(MONTH FROM h.DATA_DO) >=:MIES_OD) "));
   _Q.setOrderList("U.POZYCJA, H.ID_HARMONOGRAMU");
   _Q.paramByName("ROK")->AsInteger = m_Pars.Rok;
   _Q.paramByName("MIES_OD")->AsInteger = m_Pars.MiesOd;
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartZadDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartZadDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_PlanKwartZadADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_PlanKwartZadADO->Append();
	 m_PlanKwartZadADO->FieldByName("Kod us³ugi")->AsString                =  m_Client->FieldByName("KOD_USLUGI")->AsString;
	 m_PlanKwartZadADO->FieldByName("Nazwa us³ugi")->AsString              =  m_Client->FieldByName("NAZ_USLUGI")->AsString;

	 m_PlanKwartZadADO->FieldByName("Kod remontu")->AsString               =  m_Client->FieldByName("KOD_REMONTU")->AsString;
	 m_PlanKwartZadADO->FieldByName("Nazwa remontu")->AsString             =  m_Client->FieldByName("NAZ_REMONTU")->AsString;

	 m_PlanKwartZadADO->FieldByName("Sprzêt")->AsString                    =  m_Client->FieldByName("NAZ_SPRZETU")->AsString;
	 m_PlanKwartZadADO->FieldByName("JW miejsce")->AsString                =  m_Client->FieldByName("JW_MIASTO")->AsString;
	 m_PlanKwartZadADO->FieldByName("Indeks materia³owy")->AsString        =  m_Client->FieldByName("JIM")->AsString;

	 m_PlanKwartZadADO->FieldByName("Nr harmonogramu")->AsInteger          =  m_Client->FieldByName("NR_HARM")->AsInteger;

	 m_PlanKwartZadADO->FieldByName("Planowana iloœæ sprzêtu")->AsCurrency =  m_Client->FieldByName("ILOSC")->AsCurrency;
	 m_PlanKwartZadADO->FieldByName("Norma RBH")->AsCurrency               =  m_Client->FieldByName("RBH_NORMA")->AsCurrency;

	 m_PlanKwartZadADO->FieldByName("Iloœæ sztuk I")->AsCurrency           =  m_Client->FieldByName("ILOSC_I")->AsCurrency;
	 m_PlanKwartZadADO->FieldByName("RBH I")->AsCurrency                   =  m_Client->FieldByName("RBH_I")->AsCurrency;

	 m_PlanKwartZadADO->FieldByName("Iloœæ sztuk II")->AsCurrency           =  m_Client->FieldByName("ILOSC_II")->AsCurrency;
	 m_PlanKwartZadADO->FieldByName("RBH II")->AsCurrency                   =  m_Client->FieldByName("RBH_II")->AsCurrency;

	 m_PlanKwartZadADO->FieldByName("Iloœæ sztuk III")->AsCurrency           =  m_Client->FieldByName("ILOSC_III")->AsCurrency;
	 m_PlanKwartZadADO->FieldByName("RBH III")->AsCurrency                   =  m_Client->FieldByName("RBH_III")->AsCurrency;

  m_PlanKwartZadADO->Post();
  m_Client->Next();
 }
 m_PlanKwartZadADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartZadDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

