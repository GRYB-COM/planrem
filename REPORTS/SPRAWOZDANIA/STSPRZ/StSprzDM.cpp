//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "StSprzDM.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\queries.h"
#include <dateutils.hpp>
#include <isvaria\varia.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_StSprzDM::T_StSprzDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_StSprzDM::open(const T_StSprzDM::Pars& _Pars)
{
  m_Pars = _Pars;
  Currency _SprzWRem, _SprzWRemPlan, _SprzZal,_SprzWRemGot, _SprzZalGot, _SprzPrzyj;
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

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger     =  _Reader.fieldByName("ID_WARSZTATU")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString     =  _Reader.fieldByName("KOD_WARSZTATU")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString     =  _Reader.fieldByName("NAZ_WARSZTATU")->AsString;
	 m_Client->FieldByName("TYP_SPRZ")->AsString          =  _Reader.fieldByName("TYP_SPRZ")->AsString;;
	 m_Client->FieldByName("RODZ_NAPR")->AsString         =  _Reader.fieldByName("REMONT")->AsString;
	 m_Client->FieldByName("SPRZ_PRZYJ")->AsCurrency      =  _Reader.fieldByName("SPRZ_PRZYJ")->AsCurrency;
	 m_Client->FieldByName("SPRZ_PLAN")->AsCurrency       =  _Reader.fieldByName("SPRZ_PLAN")->AsCurrency;
	 m_Client->FieldByName("SPRZ_REM_KW_I")->AsCurrency   =  _Reader.fieldByName("SPRZ_REM_KW_I")->AsCurrency;
	 m_Client->FieldByName("SPRZ_REM_KW_II")->AsCurrency  =  _Reader.fieldByName("SPRZ_REM_KW_II")->AsCurrency;
	 m_Client->FieldByName("SPRZ_REM_KW_III")->AsCurrency =  _Reader.fieldByName("SPRZ_REM_KW_III")->AsCurrency;
	 m_Client->FieldByName("SPRZ_REM_KW_IV")->AsCurrency  =  _Reader.fieldByName("SPRZ_REM_KW_IV")->AsCurrency;
	 m_Client->FieldByName("SPRZ_REM")->AsCurrency        =  _Reader.fieldByName("SPRZ_REM")->AsCurrency;
	 _SprzPrzyj    = _Reader.fieldByName("SPRZ_PRZYJ")->AsCurrency;
	 _SprzWRem     = _SprzPrzyj - _Reader.fieldByName("SPRZ_REM")->AsCurrency;
	 _SprzZal      =  _Reader.fieldByName("SPRZ_WREM_ZAL")->AsCurrency;
	 if(_SprzZal <0.00) _SprzZal  = 0.0;
	 _SprzWRemPlan =  _SprzWRem -  _SprzZal;
	 if(_SprzWRemPlan <0.0) _SprzWRem = 0.0;
	 m_Client->FieldByName("SPRZ_WREM_PLAN")->AsCurrency  =  _SprzWRemPlan;
	 m_Client->FieldByName("SPRZ_WREM_ZAL")->AsCurrency   =  _SprzZal;

	 _SprzWRemGot = _Reader.fieldByName("SPRZ_WREM_PLAN_GOTOWE")->AsCurrency;
	 _SprzZalGot     = _Reader.fieldByName("SPRZ_WREM_ZAL_GOTOWE")->AsCurrency;

	 if(_SprzWRemPlan !=0.0 ) m_Client->FieldByName("SPRZ_WREM_PLAN_PROC")->AsCurrency  =  ISRound(_SprzWRemGot/_SprzWRemPlan*100,2);
	 if(_SprzZal  !=0.0 ) m_Client->FieldByName("SPRZ_WREM_ZAL_PROC")->AsCurrency   =  ISRound(_SprzZalGot/_SprzZal*100,2);


	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
void __fastcall T_StSprzDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_StSprzADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_StSprzADO->Append();
   m_StSprzADO->FieldByName("Kod warsztatu")->AsString                    = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
   m_StSprzADO->FieldByName("Nazwa warsztatu")->AsString                  = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;
	m_StSprzADO->FieldByName("Typ sprzêtu")->AsString                     = m_Client->FieldByName("TYP_SPRZ")->AsString;
	m_StSprzADO->FieldByName("Sprzêt planowany")->AsCurrency              = m_Client->FieldByName("SPRZ_PLAN")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt przyjêty")->AsCurrency              = m_Client->FieldByName("SPRZ_PRZYJ")->AsCurrency;
	m_StSprzADO->FieldByName("Rodzaj naprawy")->AsString                  = m_Client->FieldByName("RODZ_NAPR")->AsString;
	m_StSprzADO->FieldByName("Sprzêt wyremontowany I kw")->AsCurrency     = m_Client->FieldByName("SPRZ_REM_KW_I")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt wyremontowany II kw")->AsCurrency    = m_Client->FieldByName("SPRZ_REM_KW_II")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt wyremontowany III kw")->AsCurrency   = m_Client->FieldByName("SPRZ_REM_KW_III")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt wyremontowany IV kw")->AsCurrency    = m_Client->FieldByName("SPRZ_REM_KW_IV")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt wyremontowany")->AsCurrency          = m_Client->FieldByName("SPRZ_REM")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt w remoncie planowym")->AsCurrency    = m_Client->FieldByName("SPRZ_WREM_PLAN")->AsCurrency;
	m_StSprzADO->FieldByName("% sprzêtu w remoncie planowym")->AsCurrency = m_Client->FieldByName("SPRZ_WREM_PLAN_PROC")->AsCurrency;
	m_StSprzADO->FieldByName("Sprzêt w remoncie zaleg³ym")->AsCurrency    = m_Client->FieldByName("SPRZ_WREM_ZAL")->AsCurrency;
	m_StSprzADO->FieldByName("% sprzêtu w remoncie zaleg³ym")->AsCurrency = m_Client->FieldByName("SPRZ_WREM_ZAL_PROC")->AsCurrency;
  m_StSprzADO->Post();
  m_Client->Next();
 }
 m_StSprzADO->Close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_StSprzDM::getQuery(void)
{
AnsiString _ColList("   \
k.KOD as KOD_WARSZTATU,   \
k.ID_KOMORKI AS ID_WARSZTATU,   \
k.NAZWA AS NAZ_WARSZTATU,   \
RS.NAZWA TYP_SPRZ,   \
P.REMONT, \
sum(p.ILOSC) SPRZ_PLAN,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N' AND M.ID_HARM = P.ID_HARM)) AS SPRZ_PRZYJ,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and  Z.STATUS='G' AND  Z.DATA_ZAK IS NOT NULL AND Z.DATA_ZAK <>'1899-12-30' AND Z.DATA_ZAK <=:DATA_DO))) AS SPRZ_REM,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and  Z.STATUS='G' AND  (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK ='1899-12-30' OR DATA_ZAK > :DATA_DO) AND Z.DATA_PROP_ZAK IS NOT NULL AND Z.DATA_PROP_ZAK <>'1899-12-30' AND Z.DATA_PROP_ZAK <:DATA_DO))) AS SPRZ_WREM_ZAL,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and  Z.STATUS='G' AND  Z.DATA_ZAK IS NOT NULL AND Z.DATA_ZAK <>'1899-12-30' AND Z.DATA_ZAK <=:DATA_DO AND EXTRACT(MONTH FROM Z.DATA_ZAK) BETWEEN 1 AND 3))) AS SPRZ_REM_KW_I,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and  Z.STATUS='G' AND  Z.DATA_ZAK IS NOT NULL AND Z.DATA_ZAK <>'1899-12-30' AND Z.DATA_ZAK <=:DATA_DO AND EXTRACT(MONTH FROM Z.DATA_ZAK) BETWEEN 4 AND 6))) AS SPRZ_REM_KW_II,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and  Z.STATUS='G' AND  Z.DATA_ZAK IS NOT NULL AND Z.DATA_ZAK <>'1899-12-30' AND Z.DATA_ZAK <=:DATA_DO AND EXTRACT(MONTH FROM Z.DATA_ZAK) BETWEEN 7 AND 9))) AS SPRZ_REM_KW_III,   \
SUM((select sum(m.ilosc) from pr_magazyn m where m.DATA_PRZYJ <= :DATA_DO  and m.DEPOZYT='N'  AND M.ID_HARM = P.ID_HARM    \
AND EXISTS (SELECT NULL FROM PR_ZLECENIA Z  WHERE z.id_mag= m.ID_MAG and z.ID_KOMORKI_GLW = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and z.ROK_MAG = m.ROK and  Z.STATUS='G' AND  Z.DATA_ZAK IS NOT NULL AND Z.DATA_ZAK <>'1899-12-30' AND Z.DATA_ZAK <=:DATA_DO AND EXTRACT(MONTH FROM Z.DATA_ZAK) BETWEEN 10 AND 12))) AS SPRZ_REM_KW_IV,   \
SUM((SELECT SUM(R.ILOSC) FROM PR_ZLECENIA_RBH R INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = R.ID_KOMORKI AND Z.ID_ZLECENIA = R.ID_ZLECENIA   AND Z.ROK =R.ROK \
WHERE Z.STATUS = 'G' AND Z.ID_HARM = P.ID_HARM AND (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK ='1899-12-30' OR DATA_ZAK > :DATA_DO) AND R.MIESIAC <= :MIES_DO AND Z.DATA_PROP_ZAK IS NOT NULL AND Z.DATA_PROP_ZAK <>'1899-12-30' AND Z.DATA_PROP_ZAK <:DATA_DO)) AS SPRZ_WREM_ZAL_GOTOWE,   \
SUM((SELECT SUM(R.ILOSC) FROM PR_ZLECENIA_RBH R INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = R.ID_KOMORKI AND Z.ID_ZLECENIA = R.ID_ZLECENIA    AND Z.ROK =R.ROK  \
WHERE Z.STATUS = 'G' AND Z.ID_HARM = P.ID_HARM AND (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK ='1899-12-30' OR DATA_ZAK > :DATA_DO) AND R.MIESIAC <= :MIES_DO AND (Z.DATA_PROP_ZAK IS  NULL OR Z.DATA_PROP_ZAK ='1899-12-30' OR Z.DATA_PROP_ZAK >:DATA_DO))) AS SPRZ_WREM_PLAN_GOTOWE    \
");
AnsiString _TableRef("\
	pr_plan p LEFT OUTER JOIN PR_KOMORKI k on k.ID_KOMORKI = p.ID_KOMORKI \
	LEFT OUTER JOIN PR_RODZAJE_SPRZETU RS ON RS.ID_GR_SPRZ = P.ID_GR_SPRZ AND  RS.ID_RODZ_SPRZ = P.ID_RODZ_SPRZ");
AnsiString _Group("K.KOD,k.ID_KOMORKI,k.NAZWA,RS.NAZWA, P.REMONT");
   mng::Query _Q(_TableRef,_ColList);
   _Q.attachWherePred(new mng::ComparePredicate(" k.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ExplicitPredicate("p.id_harm - (p.id_harm/1000)*1000 > 8"));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" k.ID_KOMORKI", m_Pars.IdWarsztatu));
   _Q.paramByName("DATA_DO")->AsDateTime = m_Pars.DataDo;
   _Q.paramByName("MIES_DO")->AsInteger  = MonthOf(m_Pars.DataDo);
   _Q.setGroupList(_Group);
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_StSprzDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_StSprzDM::setMdbPath(const WideString& __Path)
{
 if(!m_Conn->Connected)
 {
  WideString _Path(__Path);
  if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
  WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
  _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
  m_Conn->ConnectionString = _ConnStr;
 }
}
//---------------------------------------------------------------------------

