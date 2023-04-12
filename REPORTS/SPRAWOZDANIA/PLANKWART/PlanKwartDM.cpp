//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "PlanKwartDM.h"
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
__fastcall T_PlanKwartDM::T_PlanKwartDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartDM::open(const T_PlanKwartDM::Pars& _Pars)
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

	 m_Client->FieldByName("KOD_WARSZTATU")->AsString    =  _Reader.fieldByName("KOD_WARSZTATU")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString    =  _Reader.fieldByName("NAZ_WARSZTATU")->AsString;

	 m_Client->FieldByName("KOD_USLUGI")->AsString       =  _Reader.fieldByName("KOD_USLUGI")->AsString;
	 m_Client->FieldByName("NAZ_USLUGI")->AsString       =  _Reader.fieldByName("NAZ_USLUGI")->AsString;

	 m_Client->FieldByName("KOD_REMONTU")->AsString      =  _Reader.fieldByName("KOD_REMONTU")->AsString;
	 m_Client->FieldByName("NAZ_REMONTU")->AsString      =  _Reader.fieldByName("NAZ_REMONTU")->AsString;

	 m_Client->FieldByName("NAZ_SPRZETU")->AsString      =  _Reader.fieldByName("NAZ_SPRZETU")->AsString.Trim() + " " + _Reader.fieldByName("ZADANIE")->AsString.Trim();
	 m_Client->FieldByName("JW_MIASTO")->AsString        =  _Reader.fieldByName("JW")->AsString + " " +_Reader.fieldByName("MIEJSCOWOSC")->AsString.Trim();
	 m_Client->FieldByName("JIM")->AsString              =  _Reader.fieldByName("INDEKS_MAT")->AsString;

	 m_Client->FieldByName("NR_HARM")->AsInteger         =  _Reader.fieldByName("ID_HARMONOGRAMU")->AsInteger;

	 m_Client->FieldByName("ILOSC")->AsCurrency          =  _Reader.fieldByName("ILOSC")->AsCurrency;
	 m_Client->FieldByName("ILOSC_KW")->AsCurrency       =  _Reader.fieldByName("ILOSC_KW")->AsCurrency;
	 m_Client->FieldByName("RBH_NORMA")->AsCurrency      =  _Reader.fieldByName("RBH_NORMA")->AsCurrency;
//	 m_Client->FieldByName("RBH_ROK")->AsCurrency        =  _Reader.fieldByName("RBH_NORMA")->AsCurrency;
	 m_Client->FieldByName("RBH_KW")->AsCurrency         =  _Reader.fieldByName("RBH_KW")->AsCurrency;
	 m_Client->FieldByName("DATA_ZAK")->AsDateTime       =  _Reader.fieldByName("DATA_ZAK")->AsDateTime;
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
/*SELECT  W.KOD AS KOD_WARSZTATU, W.NAZWA AS NAZ_WARSZTATU, U.P_N AS KOD_USLUGI, U.NAZ_REMONTU AS NAZ_USLUGI,  H.ID_HARMONOGRAMU, S.NAZWA AS NAZ_SPRZETU, S.INDEKS_MAT, H.ZADANIE, H.DATA_DO,
 R.KOD_REM AS KOD_REMONTU,R.NAZWA AS NAZ_REMONTU, J.JW, J.MIEJSCOWOSC,  H.NORMA_RBH AS RBH_NORMA,
 SUM(HD.PLAN_RBH)  ASRBH_KW,
 SUM(HD.ILOSC) AS ILOSC
   FROM  PR_HARMONOGRAM  H
   LEFT OUTER JOIN PR_KOMORKI         W  ON W.ID_KOMORKI   = H.ID_KOMORKI
   LEFT OUTER JOIN PR_KODY_USLUG      U  ON U.ID_USLUGI    = H.ID_USLUGI
   LEFT OUTER JOIN PR_REMONTY         R  ON R.ID_REMONTU   = H.ID_REMONTU
   LEFT OUTER JOIN PR_SPRZET          S  ON S.ID_SPRZETU   = H.ID_SPRZETU
   LEFT OUTER JOIN PR_JEDNOSTKI       J  ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI
   LEFT OUTER JOIN PR_HARMONOGRAM_DET HD ON HD.ROK = H.ROK AND HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU
    WHERE  ( H.ROK   =  :ROK ) AND HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO
GROUP BY W.KOD, W.NAZWA, U.P_N, U.NAZ_REMONTU,  H.ID_HARMONOGRAMU, S.NAZWA, S.INDEKS_MAT, H.ZADANIE, H.DATA_DO, R.KOD_REM,R.NAZWA, J.JW, J.MIEJSCOWOSC,  H.NORMA_RBH
ORDER BY W.KOD, U.P_N, R.KOD_REM, H.ID_HARMONOGRAMU  */
//---------------------------------------------------------------------------
 const AnsiString T_PlanKwartDM::M_COL_LIST_SQL("\
W.KOD AS KOD_WARSZTATU, W.NAZWA AS NAZ_WARSZTATU, \
U.POZYCJA AS KOD_USLUGI, \
CASE WHEN U.POZYCJA < 999 THEN U.NAZ_REMONTU ELSE 'POZOSTA£E ZADANIA' END AS NAZ_USLUGI, \
  H.ID_HARMONOGRAMU, S.NAZWA AS NAZ_SPRZETU, S.INDEKS_MAT, H.ZADANIE, H.DATA_DO AS DATA_ZAK, \
 R.KOD_REM AS KOD_REMONTU,R.NAZWA AS NAZ_REMONTU, J.JW, J.MIEJSCOWOSC,  H.NORMA_RBH AS RBH_NORMA, \
 SUM(CASE WHEN HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO THEN HD.PLAN_RBH ELSE 0.0 END)  AS RBH_KW, \
 SUM(HD.ILOSC) AS ILOSC, \
 SUM(CASE WHEN HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO THEN HD.ILOSC ELSE 0.0 END ) AS ILOSC_KW ");
//---------------------------------------------------------------------------
const AnsiString T_PlanKwartDM::M_TABLE_REF_SQL("\
  PR_HARMONOGRAM  H  \
   LEFT OUTER JOIN PR_KOMORKI         W  ON W.ID_KOMORKI   = H.ID_KOMORKI   \
   LEFT OUTER JOIN PR_KODY_USLUG      U  ON U.ID_USLUGI    = H.ID_USLUGI    \
   LEFT OUTER JOIN PR_REMONTY         R  ON R.ID_REMONTU   = H.ID_REMONTU   \
   LEFT OUTER JOIN PR_SPRZET          S  ON S.ID_SPRZETU   = H.ID_SPRZETU   \
   LEFT OUTER JOIN PR_JEDNOSTKI       J  ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI \
   LEFT OUTER JOIN PR_HARMONOGRAM_DET HD ON HD.ROK = H.ROK AND HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU \
");
//---------------------------------------------------------------------------
 const AnsiString T_PlanKwartDM::M_GROUP_LIST_SQL("\
 W.KOD, W.NAZWA, U.POZYCJA, U.NAZ_REMONTU,  H.ID_HARMONOGRAMU, S.NAZWA, S.INDEKS_MAT, H.ZADANIE, H.DATA_DO, \
 R.KOD_REM,R.NAZWA, J.JW, J.MIEJSCOWOSC,  H.NORMA_RBH \
 ");
//---------------------------------------------------------------------------
mng::Query __fastcall T_PlanKwartDM::getQuery(void)
{
  mng::Query _Q(M_TABLE_REF_SQL,M_COL_LIST_SQL);
   _Q.setGroupList(M_GROUP_LIST_SQL);
   _Q.attachWherePred(new mng::ComparePredicate(" H.ROK  "," :ROK ") );
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred(new mng::ComparePredicate(" H.ID_KOMORKI  "," :ID_WARSZTATU ") );
   _Q.attachWherePred(new mng::BetweenPredicate(" HD.MIESIAC", " :MIES_OD ", " :MIES_DO "));
   _Q.setOrderList("W.KOD, U.POZYCJA, R.KOD_REM, H.ID_HARMONOGRAMU");
   _Q.paramByName("ROK")->AsInteger = m_Pars.Rok;
   if(m_Pars.IdWarsztatu >0) _Q.paramByName("ID_WARSZTATU")->AsInteger = m_Pars.IdWarsztatu;
   _Q.paramByName("MIES_OD")->AsInteger = m_Pars.MiesOd;
   _Q.paramByName("MIES_DO")->AsInteger = m_Pars.MiesDo;
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartDM::saveToMdb(const String & _Path)
{
 try
 {
   setMdbPath(_Path);
   m_WorkADO->ExecSQL();
   m_PlanKwartADO->Open();
   m_Client->First();
   int i(0);
   while(!m_Client->Eof)
   {
	m_PlanKwartADO->Append();
	   m_PlanKwartADO->FieldByName("Kod warsztatu")->AsString                  =  m_Client->FieldByName("KOD_WARSZTATU")->AsString;
	   m_PlanKwartADO->FieldByName("Warsztat wykonuj¹cy")->AsString            =  m_Client->FieldByName("NAZ_WARSZTATU")->AsString;

	   m_PlanKwartADO->FieldByName("Kod us³ugi")->AsString                     =  m_Client->FieldByName("KOD_USLUGI")->AsString;
	   m_PlanKwartADO->FieldByName("Nazwa us³ugi")->AsString                   =  m_Client->FieldByName("NAZ_USLUGI")->AsString;

	   m_PlanKwartADO->FieldByName("Kod remontu")->AsString                    =  m_Client->FieldByName("KOD_REMONTU")->AsString;
	   m_PlanKwartADO->FieldByName("Nazwa remontu")->AsString                  =  m_Client->FieldByName("NAZ_REMONTU")->AsString;

	   m_PlanKwartADO->FieldByName("Nazwa sprzêtu")->AsString                  =  m_Client->FieldByName("NAZ_SPRZETU")->AsString;
	   m_PlanKwartADO->FieldByName("Dostawca")->AsString                       =  m_Client->FieldByName("JW_MIASTO")->AsString;
	   m_PlanKwartADO->FieldByName("JIM")->AsString                            =  m_Client->FieldByName("JIM")->AsString;

	   m_PlanKwartADO->FieldByName("Nr harmonogramu")->AsInteger            =  m_Client->FieldByName("NR_HARM")->AsInteger;

	   if(m_Client->FieldByName("ILOSC")->AsCurrency >0.00)
	   {
		m_PlanKwartADO->FieldByName("Iloœæ")->AsCurrency                        =  m_Client->FieldByName("ILOSC")->AsCurrency;
	   }
	   else m_PlanKwartADO->FieldByName("Iloœæ")->Clear();
	   if(m_Client->FieldByName("ILOSC_KW")->AsCurrency >0.00)
	   {
		m_PlanKwartADO->FieldByName("Iloœæ na kwarta³")->AsCurrency             =  m_Client->FieldByName("ILOSC_KW")->AsCurrency;
	   }
	   else m_PlanKwartADO->FieldByName("Iloœæ na kwarta³")->Clear();
	   m_PlanKwartADO->FieldByName("Norma RBH")->AsCurrency                    =  m_Client->FieldByName("RBH_NORMA")->AsCurrency;
	   //m_PlanKwartADO->FieldByName("RBH w roku")->AsCurrency                   =  m_Client->FieldByName("RBH_NORMA")->AsCurrency;
	   m_PlanKwartADO->FieldByName("RBH na kwarta³")->AsCurrency               =  m_Client->FieldByName("RBH_KW")->AsCurrency;
	   m_PlanKwartADO->FieldByName("Planowany termin zakoñczenia")->AsDateTime =  m_Client->FieldByName("DATA_ZAK")->AsDateTime;;
	m_PlanKwartADO->Post();
	++i;
	m_Client->Next();
   }
  }
  catch(...)
  {
   m_PlanKwartADO->Close();
   m_Conn->RollbackTrans();
   m_Conn->Connected = false;
   throw;
  }
 m_PlanKwartADO->Close();
 try{
  m_ParsADO->Open();
   m_ParsADO->IsEmpty() ?  m_ParsADO->Append() :  m_ParsADO->Edit();
   m_ParsADO->FieldByName("Rok")->AsInteger     = m_Pars.Rok;
   m_ParsADO->FieldByName("Kwarta³")->AsString  = m_Pars.Kw;
 }
 catch(...)
 {
  m_ParsADO->Close();
  throw;
 }
  m_ParsADO->Post();
  m_ParsADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PlanKwartDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

