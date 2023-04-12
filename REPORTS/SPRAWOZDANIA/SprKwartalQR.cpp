//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SprKwartalQR.h"
#include "manager\query_db.h"
#include "QRBandMng.h"
#include <dateutils.hpp>
#include <SysUtils.hpp>
#include <math.h>
#include "JBUTILS\jb_varia.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\Query_db.h"
#include "ISVARIA\varia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "QuickRpt"
#pragma link "QRCtrls"
#pragma link "RpDefine"
#pragma link "RpRender"
#pragma link "RpRenderText"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_SprKwartalneQR::T_SprKwartalneQR(TComponent* Owner)
	: TForm(Owner),m_kwartal(1),m_rok(0)
{
 m_qData = new mng::QueryDB;
 dspData->DataSet = m_qData->getDataSet();
 m_SQL = new TStringList();
}
//---------------------------------------------------------------------------
__fastcall T_SprKwartalneQR::~T_SprKwartalneQR()
{
 delete m_qData;
 delete m_SQL;
}
//---------------------------------------------------------------------------
Currency __fastcall T_SprKwartalneQR::getExprDblValue(TQRExpr *expr)
{
 if(expr->Value.Kind==resDouble) return expr->Value.dblResult;
 else return 0.0;
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::print(void)
{
  m_Raport->Print();
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::preview(void)
{
 m_Raport->Preview();
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::runSQR(void)
{
 bool Preview;
 int _LP;
 m_RaportBeforePrint(NULL,Preview);
 m_Data4SQR->CreateDataSet();
 cdsData->First();
 TField * _Dest;
 TField * _Source;
 m_LP.clear();
 m_SumWar.clear();
 while(!cdsData->Eof)
 {
  m_Data4SQR->Append();
  for(int i =0; i < m_Data4SQR->Fields->Count;++i)
  {
   _Dest   = m_Data4SQR->Fields->Fields[i];
   _Source = cdsData->FindField(_Dest->FieldName);
   if(_Source)
   {
	_Dest->Value = _Source->Value;
   }
  }
  if(m_LP.find(m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger) == m_LP.end())
  {
   _LP=0;
  }
  else
  {
   _LP= m_LP[m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger];
  }
  m_LP[m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger]= ++_LP;
  m_Data4SQR->FieldByName("LP")->AsString = _LP;
  AnsiString aa;
  if(cdsData->FieldByName("JW")->AsAnsiString == "" )
  {
   if(YearOf(cdsData->FieldByName("DATA_PRZEKAZ")->AsDateTime) > 1900)
   {
	aa = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString;
	aa += " " + cdsData->FieldByName("DOSTAWCA")->AsAnsiString;
   }
  }
  else
  {
   if(YearOf(cdsData->FieldByName("DATA_PRZEKAZ")->AsDateTime) > 1900)
   {
	 aa = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString;
	aa += " " + cdsData->FieldByName("JW")->AsAnsiString + " " + cdsData->FieldByName("MIEJSCOWOSC")->AsAnsiString;
   }
  }
  m_Data4SQR->FieldByName("PRZEKAZANO")->AsString =aa;
  m_Data4SQR->Post();
  sumuj();
  cdsData->Next();
 }
 cdsData->Close();
 fillWarHead();
}
//---------------------------------------------------------------------------
const String T_SprKwartalneQR::M_WARSZTAT_SQL("\
select  DISTINCT \
 W.ID_KOMORKI, W.KOD AS KOD_WARSZTATU, \
 (case when w.ID_KOMORKI is null then 'POZOSTA£E ZADANIA' else W.KOD || ' - ' || W.NAZWA end) as naz_warsztatu \
from pr_zlecenia z \
 left outer join PR_KOMORKI       w  on w.ID_KOMORKI       = z.ID_KOMORKI \
 left outer join pr_magazyn       m  on m.ID_MAG           = z.ID_MAG  AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT =Z.DEPOZYT AND M.ROK =Z.ROK_MAG \
 WHERE \
 Z.ROK = :ROK   AND \
 Z.DATA_WYST  <= :DATA_DO and \
 (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK < '1900-01-01' OR  Z.DATA_ZAK   >=  :DATA_OD )  AND \
 m.DEPOZYT <> 'D' \
 ");
//---------------------------------------------------------------------------
void T_SprKwartalneQR::fillWarHead(void)
{
 int m1,m2,m3;
 int _IdKomorki;
 if(m_kwartal == 1) { m1=1; m2=2; m3=3; }
 else if(m_kwartal == 2) { m1=4; m2=5; m3=6; }
 else if(m_kwartal == 3) { m1=7; m2=8; m3=9; }
 else { m1=10; m2=11; m3=12; }

 mng::QueryDB _Q(M_WARSZTAT_SQL);
 _Q.paramByName("ROK")->AsInteger  = m_rok;
 _Q.paramByName("DATA_OD")->AsDate = TDateTime(m_rok,m1,1);
 _Q.paramByName("DATA_DO")->AsDate = EndOfAMonth(m_rok,m3);
 _Q.open();
 while(!_Q.isEof())
 {
  _IdKomorki =  _Q.fieldByName("ID_KOMORKI")->AsInteger;
  m_Data4SQR->Append();
   m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger     = _Q.fieldByName("ID_KOMORKI")->AsInteger;
   m_Data4SQR->FieldByName("HEAD_WARSZTATU")->AsInteger = 1;
   m_Data4SQR->FieldByName("HEAD_REMONTU")->AsInteger   = 1;
   m_Data4SQR->FieldByName("KOD_WARSZTATU")->AsString   = _Q.fieldByName("KOD_WARSZTATU")->AsString;
   m_Data4SQR->FieldByName("LP")->AsString              = _Q.fieldByName("NAZ_WARSZTATU")->AsString;
   m_Data4SQR->FieldByName("tdatrib_LP")->AsString      = " colspan=\"26\" ";
  m_Data4SQR->Post();
  m_Data4SQR->Append();
   m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger     = _Q.fieldByName("ID_KOMORKI")->AsInteger;
   m_Data4SQR->FieldByName("KOD_WARSZTATU")->AsString   = _Q.fieldByName("KOD_WARSZTATU")->AsString;
   m_Data4SQR->FieldByName("HEAD_WARSZTATU")->AsInteger = 9999;
   m_Data4SQR->FieldByName("HEAD_REMONTU")->AsInteger   = 9999;
   m_Data4SQR->FieldByName("LP")->AsString              = " OGÓ£EM ";
   m_Data4SQR->FieldByName("tdatrib_LP")->AsString      = " colspan=\"3\" ";
   m_Data4SQR->FieldByName("tdatrib_ID_HARM")->AsString = " colspan=\"6\" ";
   m_Data4SQR->FieldByName("ILOSC_P")->AsCurrency       = m_SumWar[_IdKomorki].IloscP;
   m_Data4SQR->FieldByName("PLAN_LICZBA_RBH")->AsCurrency=m_SumWar[_IdKomorki].PlanLiczbaRBH;
   m_Data4SQR->FieldByName("RBH_1")->AsCurrency          = m_SumWar[_IdKomorki].RBH1 ;
   m_Data4SQR->FieldByName("RBH_2")->AsCurrency          = m_SumWar[_IdKomorki].RBH2;
   m_Data4SQR->FieldByName("RBH_3")->AsCurrency          = m_SumWar[_IdKomorki].RBH3;
   m_Data4SQR->FieldByName("R1")->AsCurrency            = m_SumWar[_IdKomorki].R1;
   m_Data4SQR->FieldByName("R1")->AsCurrency            = m_SumWar[_IdKomorki].R2 ;
   m_Data4SQR->FieldByName("R3")->AsCurrency            = m_SumWar[_IdKomorki].R3;
   m_Data4SQR->FieldByName("ILOSC_M1")->AsCurrency      = m_SumWar[_IdKomorki].IloscM1;
   m_Data4SQR->FieldByName("ILOSC_M2")->AsCurrency      = m_SumWar[_IdKomorki].IloscM2;
   m_Data4SQR->FieldByName("ILOSC_M3")->AsCurrency      = m_SumWar[_IdKomorki].IloscM3;
   m_Data4SQR->FieldByName("ILOSC_REM")->AsCurrency     = m_SumWar[_IdKomorki].IloscRem;
   m_Data4SQR->FieldByName("ILOSC_PLAN")->AsCurrency    = m_SumWar[_IdKomorki].IloscPlan;
   m_Data4SQR->FieldByName("ILOSC_ZAL")->AsCurrency     = m_SumWar[_IdKomorki].IloscZal;
  m_Data4SQR->Post();
  fillRemHead(_Q.fieldByName("ID_KOMORKI")->AsInteger,_Q.fieldByName("KOD_WARSZTATU")->AsString);

  _Q.next();
 }
}
//---------------------------------------------------------------------------
const String T_SprKwartalneQR::M_REMONT_SQL("\
select DISTINCT \
 (case when ku.pozycja is null then 999 else ku.pozycja end) as pozycja ,  \
 (case when (ku.pozycja is null OR  ku.pozycja = 999) then 'POZOSTA£E ZADANIA' else ku.naz_remontu end ) as naz_remontu  \
from pr_zlecenia z    \
 left outer join pr_HARMONOGRAM   p  on p.ID_HARMONOGRAMU  = z.ID_HARM  and p.ROK=z.ROK \
 left outer join pr_kody_uslug    ku on ku.ID_USLUGI       = p.ID_USLUGI   \
 left outer join pr_magazyn       m  on m.ID_MAG           = z.ID_MAG  AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT =Z.DEPOZYT AND M.ROK =Z.ROK_MAG \
 WHERE \
 Z.ID_KOMORKI = :ID_KOMORKI AND  \
 Z.ROK = :ROK   AND   \
 Z.DATA_WYST  <= :DATA_DO and  \
 (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK < '1900-01-01' OR  Z.DATA_ZAK   >=  :DATA_OD )  AND   \
 m.DEPOZYT <> 'D'    \
");
//---------------------------------------------------------------------------
void T_SprKwartalneQR::fillRemHead(const int _IdKomorki, const String& _KodWar)
{
 int m1,m2,m3;
 if(m_kwartal == 1) { m1=1; m2=2; m3=3; }
 else if(m_kwartal == 2) { m1=4; m2=5; m3=6; }
 else if(m_kwartal == 3) { m1=7; m2=8; m3=9; }
 else { m1=10; m2=11; m3=12; }
 String _WarRem;
 mng::QueryDB _Q(M_REMONT_SQL);
 _Q.paramByName("ROK")->AsInteger  = m_rok;
 _Q.paramByName("DATA_OD")->AsDate = TDateTime(m_rok,m1,1);
 _Q.paramByName("DATA_DO")->AsDate = EndOfAMonth(m_rok,m3);
 _Q.paramByName("ID_KOMORKI")->AsInteger = _IdKomorki;
 _Q.open();
 while(!_Q.isEof())
 {
  m_Data4SQR->Append();
   m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger     = _IdKomorki;
   m_Data4SQR->FieldByName("HEAD_WARSZTATU")->AsInteger = 999;
   m_Data4SQR->FieldByName("HEAD_REMONTU")->AsInteger   = 1;
   m_Data4SQR->FieldByName("KOD_WARSZTATU")->AsString   = _KodWar;
   m_Data4SQR->FieldByName("POZYCJA")->AsInteger        = _Q.fieldByName("POZYCJA")->AsInteger;
   m_Data4SQR->FieldByName("tdatrib_LP")->AsString      =  " colspan=\"26\" ";
   m_Data4SQR->FieldByName("LP")->AsString = _Q.fieldByName("NAZ_REMONTU")->AsString;
  m_Data4SQR->Post();
  m_Data4SQR->Append();
   _WarRem = _KodWar + String("_") + String(_Q.fieldByName("POZYCJA")->AsInteger);
   m_Data4SQR->FieldByName("ID_KOMORKI")->AsInteger     = _IdKomorki;
   m_Data4SQR->FieldByName("HEAD_WARSZTATU")->AsInteger = 999;
   m_Data4SQR->FieldByName("HEAD_REMONTU")->AsInteger   = 9999;
   m_Data4SQR->FieldByName("KOD_WARSZTATU")->AsString   = _KodWar;
   m_Data4SQR->FieldByName("POZYCJA")->AsInteger        = _Q.fieldByName("POZYCJA")->AsInteger;
   m_Data4SQR->FieldByName("LP")->AsString              = "     RAZEM ";
   m_Data4SQR->FieldByName("tdatrib_LP")->AsString      = " colspan=\"3\" ";
   m_Data4SQR->FieldByName("tdatrib_ID_HARM")->AsString = " colspan=\"6\" ";
   m_Data4SQR->FieldByName("ILOSC_P")->AsCurrency       = m_SumWarRem[_WarRem].IloscP;
   m_Data4SQR->FieldByName("PLAN_LICZBA_RBH")->AsCurrency=m_SumWarRem[_WarRem].PlanLiczbaRBH;
   m_Data4SQR->FieldByName("RBH_1")->AsCurrency          = m_SumWarRem[_WarRem].RBH1 ;
   m_Data4SQR->FieldByName("RBH_2")->AsCurrency          = m_SumWarRem[_WarRem].RBH2;
   m_Data4SQR->FieldByName("RBH_3")->AsCurrency          = m_SumWarRem[_WarRem].RBH3;
   m_Data4SQR->FieldByName("R1")->AsCurrency            = m_SumWarRem[_WarRem].R1;
   m_Data4SQR->FieldByName("R1")->AsCurrency            = m_SumWarRem[_WarRem].R2 ;
   m_Data4SQR->FieldByName("R3")->AsCurrency            = m_SumWarRem[_WarRem].R3;
   m_Data4SQR->FieldByName("ILOSC_M1")->AsCurrency      = m_SumWarRem[_WarRem].IloscM1;
   m_Data4SQR->FieldByName("ILOSC_M2")->AsCurrency      = m_SumWarRem[_WarRem].IloscM2;
   m_Data4SQR->FieldByName("ILOSC_M3")->AsCurrency      = m_SumWarRem[_WarRem].IloscM3;
   m_Data4SQR->FieldByName("ILOSC_REM")->AsCurrency     = m_SumWarRem[_WarRem].IloscRem;
   m_Data4SQR->FieldByName("ILOSC_PLAN")->AsCurrency    = m_SumWarRem[_WarRem].IloscPlan;
   m_Data4SQR->FieldByName("ILOSC_ZAL")->AsCurrency     = m_SumWarRem[_WarRem].IloscZal;
  m_Data4SQR->Post();
  _Q.next();
 }
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::sumuj(void)
{
 String _WarRem                 = cdsData->FieldByName("KOD_WARSZTATU")->AsString + String("_") + cdsData->FieldByName("POZYCJA")->AsString;
 int    _IdKom                  = cdsData->FieldByName("ID_KOMORKI")->AsInteger;
 m_SumWarRem[_WarRem].IloscP        += cdsData->FieldByName("ILOSC_P")->AsCurrency;
 m_SumWarRem[_WarRem].PlanLiczbaRBH += cdsData->FieldByName("PLAN_LICZBA_RBH")->AsCurrency;
 m_SumWarRem[_WarRem].RBH1          += cdsData->FieldByName("RBH_1")->AsCurrency;
 m_SumWarRem[_WarRem].RBH2          += cdsData->FieldByName("RBH_2")->AsCurrency;
 m_SumWarRem[_WarRem].RBH3          += cdsData->FieldByName("RBH_3")->AsCurrency;
 m_SumWarRem[_WarRem].R1            += cdsData->FieldByName("R1")->AsCurrency;
 m_SumWarRem[_WarRem].R2            += cdsData->FieldByName("R1")->AsCurrency;
 m_SumWarRem[_WarRem].R3            += cdsData->FieldByName("R3")->AsCurrency;
 m_SumWarRem[_WarRem].IloscM1       += cdsData->FieldByName("ILOSC_M1")->AsCurrency;
 m_SumWarRem[_WarRem].IloscM2       += cdsData->FieldByName("ILOSC_M2")->AsCurrency;
 m_SumWarRem[_WarRem].IloscM3       += cdsData->FieldByName("ILOSC_M3")->AsCurrency;
 m_SumWarRem[_WarRem].IloscRem      += cdsData->FieldByName("ILOSC_REM")->AsCurrency;
 m_SumWarRem[_WarRem].IloscPlan     += cdsData->FieldByName("ILOSC_PLAN")->AsCurrency;
 m_SumWarRem[_WarRem].IloscZal      += cdsData->FieldByName("ILOSC_ZAL")->AsCurrency;

 m_SumWar[_IdKom].IloscP        += cdsData->FieldByName("ILOSC_P")->AsCurrency;
 m_SumWar[_IdKom].PlanLiczbaRBH += cdsData->FieldByName("PLAN_LICZBA_RBH")->AsCurrency;
 m_SumWar[_IdKom].RBH1          += cdsData->FieldByName("RBH_1")->AsCurrency;
 m_SumWar[_IdKom].RBH2          += cdsData->FieldByName("RBH_2")->AsCurrency;
 m_SumWar[_IdKom].RBH3          += cdsData->FieldByName("RBH_3")->AsCurrency;
 m_SumWar[_IdKom].R1            += cdsData->FieldByName("R1")->AsCurrency;
 m_SumWar[_IdKom].R2            += cdsData->FieldByName("R1")->AsCurrency;
 m_SumWar[_IdKom].R3            += cdsData->FieldByName("R3")->AsCurrency;
 m_SumWar[_IdKom].IloscM1       += cdsData->FieldByName("ILOSC_M1")->AsCurrency;
 m_SumWar[_IdKom].IloscM2       += cdsData->FieldByName("ILOSC_M2")->AsCurrency;
 m_SumWar[_IdKom].IloscM3       += cdsData->FieldByName("ILOSC_M3")->AsCurrency;
 m_SumWar[_IdKom].IloscRem      += cdsData->FieldByName("ILOSC_REM")->AsCurrency;
 m_SumWar[_IdKom].IloscPlan     += cdsData->FieldByName("ILOSC_PLAN")->AsCurrency;
 m_SumWar[_IdKom].IloscZal      += cdsData->FieldByName("ILOSC_ZAL")->AsCurrency;
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::setKomorka(AnsiString aVal)
{
  m_komorka = aVal;
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::setOkres(int aKwartal, int aRok)
{
  m_kwartal = aKwartal;
  m_rok = aRok;
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::setZalacznik(AnsiString aVal)
{
  m_zalacznik = aVal;
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::lbOkresPrint(TObject *sender, UnicodeString &Value)

{
 AnsiString aa = "ZA " + IntToStr(m_kwartal) + " KWARTA£ " + IntToStr(m_rok) + " ROKU";
 Value = aa;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::lbKomorkaPrint(TObject *sender, UnicodeString &Value)

{
 Value = m_komorka;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::lbZalacznikPrint(TObject *sender, UnicodeString &Value)

{
 Value = m_zalacznik;
}
//---------------------------------------------------------------------------
/*
select
 W.ID_KOMORKI, W.KOD AS KOD_WARSZTATU,
 (case when w.ID_KOMORKI is null then 'POZOSTA£E ZADANIA' else W.KOD || ' - ' || W.NAZWA end) as naz_warsztatu,
 (case when ku.pozycja is null then 999 else ku.pozycja end) as pozycja ,
 (case when (ku.pozycja is null OR  ku.pozycja = 999) then 'POZOSTA£E ZADANIA' else ku.naz_remontu end ) as naz_remontu
from pr_zlecenia z
 left outer join PR_KOMORKI       w  on w.ID_KOMORKI       = z.ID_KOMORKI
 left outer join pr_HARMONOGRAM   p  on p.ID_HARMONOGRAMU  = z.ID_HARM  and p.ROK=z.ROK
 left outer join pr_kody_uslug    ku on ku.ID_USLUGI       = p.ID_USLUGI
 left outer join pr_magazyn       m  on m.ID_MAG           = z.ID_MAG  AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT =Z.DEPOZYT AND M.ROK =Z.ROK_MAG

 WHERE
 Z.ROK = :ROK   AND
 Z.DATA_WYST  <= :DATA_DO and
 (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK < '1900-01-01' OR  Z.DATA_ZAK   >=  :DATA_OD )  AND
 m.DEPOZYT <> 'D'

select  DISTINCT
 W.ID_KOMORKI, W.KOD AS KOD_WARSZTATU,
 (case when w.ID_KOMORKI is null then 'POZOSTA£E ZADANIA' else W.KOD || ' - ' || W.NAZWA end) as naz_warsztatu
from pr_zlecenia z
 left outer join PR_KOMORKI       w  on w.ID_KOMORKI       = z.ID_KOMORKI
 left outer join pr_magazyn       m  on m.ID_MAG           = z.ID_MAG  AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT =Z.DEPOZYT AND M.ROK =Z.ROK_MAG

 WHERE
 Z.ROK = :ROK   AND
 Z.DATA_WYST  <= :DATA_DO and
 (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK < '1900-01-01' OR  Z.DATA_ZAK   >=  :DATA_OD )  AND
 m.DEPOZYT <> 'D'
 */
void __fastcall T_SprKwartalneQR::m_RaportBeforePrint(TCustomQuickRep *Sender, bool &PrintReport)
{
 lp = 0;
 poziom = 0;
 m_PrintPageHeader = false;
 m_NewCol= false;
 AnsiString okres,m1,m2,m3;
 if(m_kwartal == 1) { okres = "1,2,3"; m1="1"; m2="2"; m3="3"; }
 else if(m_kwartal == 2) { okres = "4,5,6";  m1="4"; m2="5"; m3="6"; }
 else if(m_kwartal == 3) { okres = "7,8,9"; m1="7"; m2="8"; m3="9"; }
 else { okres = "10,11,12"; m1="10"; m2="11"; m3="12"; }
 m_SumIl4 =0;
 m_SumUslIl =0;
 m_SumWarIl =0;
 m_SumOgIl =0;
 m_SumUsl22 =0;
 m_SumWar22 =0;
 m_SumOg22 =0;
 m_SumUsl24 =0;
 m_SumWar24 =0;
 m_SumOg24 =0;
 MaxCY=0;
 AnsiString _SQL;
_SQL = "select  \
999 as HEAD_WARSZTATU, 999 AS HEAD_REMONTU, W.ID_KOMORKI, W.KOD AS KOD_WARSZTATU,   \
 (case when w.ID_KOMORKI is null then 'POZOSTA£E ZADANIA' else W.KOD || ' - ' || W.NAZWA end) as naz_warsztatu, \
 (case when ku.pozycja is null then 999 else ku.pozycja end) as pozycja ,  \
 (case when (ku.pozycja is null OR  ku.pozycja = 999) then 'POZOSTA£E ZADANIA' else ku.naz_remontu end ) as naz_remontu,  \
 case when s.nazwa is null then '' else s.nazwa end || '   '  \
  || case when m.NR_REJ is null then '' else m.NR_REJ end || '   '  \
  || case when m.NR_FABR is null then '' else m.NR_FABR end  as naz_sprzetu,  \
  s.INDEKS_MAT,  \
  p.ID_HARMONOGRAMU AS ID_HARM,  \
  j.jw, j.miejscowosc, J.JW || ' ' || J.MIEJSCOWOSC  AS dostawca ,  \
  re.KOD_REM naz_rodz_rem,  \
  z.SYGN_ZLECENIA,    \
  (case when z.DATA_WYST='1899-12-30' OR Z.DATA_WYST IS NULL then NULL else z.DATA_WYST end) as DATA_WYST,  \
  (case when z.DATA_ZAK ='1899-12-30' OR Z.DATA_ZAK > :DATA_DO then NULL else z.DATA_ZAK end)  as DATA_ZAK,  \
  (case when z.DATA_ZAK ='1899-12-30' OR Z.DATA_ZAK IS NULL OR Z.DATA_ZAK > :DATA_DO then 'T'  ELSE 'N' END)  as REM,  \
  (case when z.DATA_PROP_ZAK ='1899-12-30' OR Z.DATA_PROP_ZAK IS NULL  OR EXTRACT( MONTH FROM Z.DATA_PROP_ZAK) >" + m3 + " then 'N'  WHEN Z.DATA_ZAK IS NULL OR Z.DATA_ZAK ='1899-12-30'   THEN 'T' ELSE 'N'  END)  as ZAL,  \
  (case when m.DATA_PRZEKAZ ='1899-12-30' OR M.DATA_PRZEKAZ IS NULL then NULL else m.DATA_PRZEKAZ end)  as DATA_PRZEKAZ,  \
  (case when m.DATA_PRZYJ ='1899-12-30' OR M.DATA_PRZYJ IS NULL  then NULL else m.DATA_PRZYJ end)  as DATA_PRZYJ,  \
  m.ilosc,  \
  z.liczba_rbh,  \
  sum(case when r.MIESIAC between " + m1 + " and " + m3 + " and  r.PLAN_ILOSC is not null then r.PLAN_ILOSC else 0.0 end) as IP,  \
  sum(case when r.MIESIAC = " + m1 + " and  r.PLAN_ILOSC is not null then R.PLAN_ILOSC else 0.0 end) as IP1,               \
  sum(case when r.MIESIAC = " + m2 + " and  r.PLAN_ILOSC is not null then R.PLAN_ILOSC else 0.0 end) as IP2,               \
  sum(case when r.MIESIAC = " + m3 + " and  r.PLAN_ILOSC is not null then R.PLAN_ILOSC else 0.0 end) as IP3,               \
  sum(case when r.MIESIAC < " + m1 + " and  r.PLAN_ILOSC is not null then R.PLAN_ILOSC else 0.0 end) as IP4,               \
  sum(case when r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end)  as RK0,  \
  sum(case when r.MIESIAC = " + m1 + " and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end)  as RK1,  \
  sum(case when r.MIESIAC = " + m2 + "  and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RK2,  \
  sum(case when r.MIESIAC = " + m3 + "  and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RK3,  \
  sum(case when r.MIESIAC < " + m1 + "  and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RK4,  \
  sum(case when r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RH0,  \
  sum(case when r.MIESIAC = " + m1 + " and  r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RH1,  \
  sum(case when r.MIESIAC = " + m2 + "  and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RH2,  \
  sum(case when r.MIESIAC = " + m3 + "  and r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RH3,  \
  sum(case when r.MIESIAC < " + m1 + " and  r.PLAN_RBH is not null then r.PLAN_RBH else 0.0 end) as RH4,  \
  sum(case when r.miesiac = " + m1 + "  and r.LICZBA_RBH is not null then r.LICZBA_RBH else 0 end)   as R1,  \
  sum(case when r.miesiac = " + m2 + "  and r.LICZBA_RBH is not null then r.LICZBA_RBH else 0 end)   as R2,  \
  sum(case when r.miesiac = " + m3 + "  and r.LICZBA_RBH is not null then r.LICZBA_RBH else 0 end)   as R3,  \
  sum(case when r.miesiac < " + m1 + " and  r.LICZBA_RBH is not null then r.LICZBA_RBH else 0 end)   as R4,  \
  sum(case when r.miesiac = " + m1 + "  and r.ILOSC is not null then r.ILOSC else 0 end)   as IK1,  \
  sum(case when r.miesiac = " + m2 + "  and r.ILOSC is not null then r.ILOSC else 0 end)   as IK2,  \
  sum(case when r.miesiac = " + m3 + "  and r.ILOSC is not null then r.ILOSC else 0 end)   as IK3,  \
  sum(case when r.miesiac < " + m1 + " and  r.ILOSC is not null then r.ILOSC else 0 end)   as IK4,  \
  z.UWAGI ,  z.DEPOZYT, Z.DATA_PROP_ZAK  \
from pr_zlecenia z  \
 left outer join PR_ZLECENIA_RBH r   on r.ID_ZLECENIA      = z.ID_ZLECENIA    AND R.ID_KOMORKI = Z.ID_KOMORKI AND R.ROK = Z.ROK \
 left outer join PR_KOMORKI       w  on w.ID_KOMORKI       = z.ID_KOMORKI  \
 left outer join pr_HARMONOGRAM   p  on p.ID_HARMONOGRAMU  = z.ID_HARM  and p.ROK=z.ROK  \
 left outer join pr_kody_uslug    ku on ku.ID_USLUGI       = p.ID_USLUGI  \
 left outer join pr_magazyn       m  on m.ID_MAG           = z.ID_MAG  AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.DEPOZYT =Z.DEPOZYT AND M.ROK =Z.ROK_MAG  \
 left outer join pr_sprzet        s  on s.ID_SPRZETU       = m.ID_SPRZETU  \
 left outer join pr_jednostki     j  on j.ID_JEDNOSTKI     = z.ID_JEDNOSTKI  \
 left outer join pr_remonty       re on re.ID_REMONTU      = m.id_remontu  \
 WHERE  \
 Z.ROK = :ROK  AND  \
 Z.DATA_WYST  <= :DATA_DO and  \
 (Z.DATA_ZAK IS NULL OR Z.DATA_ZAK < '1900-01-01' OR  Z.DATA_ZAK   >=  :DATA_OD )  AND  \
 m.DEPOZYT <> 'D'  \
 GROUP BY   \
 w.ID_KOMORKI,  \
 w.KOD,   \
 w.NAZWA,  \
 ku.POZYCJA,   \
 ku.NAZ_REMONTU,  \
 s.NAZWA,   \
 p.ZADANIE,  \
 m.NR_REJ,  \
 m.NR_FABR,  \
 s.INDEKS_MAT,  \
 z.ID_MAG,  \
 z.ZADANIE,  \
 m.ILOSC,  \
 z.LICZBA_RBH,  \
 p.ID_HARMONOGRAMU,  \
 j.jw, j.miejscowosc,  \
 RE.KOD_REM,   \
 z.SYGN_ZLECENIA,  \
 z.data_wyst ,  \
 z.data_zak,  \
 z.DATA_PROP_ZAK,  \
 m.DATA_PRZEKAZ,  \
 m.DATA_PRZYJ,  \
 z.UWAGI,   \
 z.DEPOZYT  \
";
if(m_Sort ==0)
 {
  _SQL += " ORDER BY \
  case when W.ID_KOMORKI is null then 999 else W.KOD end,  \
  case when ku.pozycja     is null then 999      else ku.POZYCJA end,  \
  s.nazwa, \
  z.SYGN_ZLECENIA";
 }
 else if(m_Sort ==1)
 {
  _SQL += " ORDER BY \
  case when W.ID_KOMORKI is null then 999 else W.KOD end,  \
  case when ku.pozycja     is null then 999      else ku.POZYCJA end,  \
  z.SYGN_ZLECENIA,  \
  s.nazwa ";

 }

 cdsData->Close();
 m_qData->setQuery(_SQL);
 m_qData->paramByName("ROK")->AsInteger  = m_rok;
 m_qData->paramByName("DATA_OD")->AsDate = TDateTime(m_rok,StrToInt(m1),1);
 m_qData->paramByName("DATA_DO")->AsDate = EndOfAMonth(m_rok,StrToInt(m3));
 cdsData->Open();

 SummaryBand1->Enabled =  jbutils::TMyIni().ReadIniBool("ZAAWANSOWANE","Aktualizacja iloœci",false);
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::cdsDataCalcFields(TDataSet *DataSet)
{
 //PO TERMINIE
   bool _PoTer= isPoTer(DataSet);
 //ZPLANU
   bool _ZPlanu = isZPlanu(DataSet);
 //PLANOWANA ILOŒÆ SPRZÊTU SZT/KPL
   planIlSprz(DataSet,_ZPlanu);
 //PLANOWANA ILOŒÆ RBH OGÓ£EM
   planLiczbaRBH(DataSet,_ZPlanu);
 //PLANOWANA ILOŒÆ RBH W MIESI¥CACH
   planRBH(DataSet,_ZPlanu,_PoTer);
 //WYREMONTOWANY SPRZÊT W MIESI¥CACH
   realIl(DataSet,_PoTer);
 //W TRAKCIE REMONTU
   wRem(DataSet,_ZPlanu,_PoTer);
}
//---------------------------------------------------------------------------
bool T_SprKwartalneQR::isPoTer(TDataSet *DataSet)
{
 int m1 = 3*m_kwartal - 2;
  TDateTime _DataOd(YearOf(Date()),m1,1);
  bool _PoTer= !DataSet->FieldByName("DATA_PROP_ZAK")->IsNull;
 _PoTer = _PoTer && DataSet->FieldByName("DATA_PROP_ZAK")->AsDateTime >TDateTime(0.0);
 _PoTer = _PoTer && DataSet->FieldByName("DATA_PROP_ZAK")->AsDateTime < _DataOd;
 if(_PoTer)
 {
  DataSet->FieldByName("PO_TERMINIE")->AsString = "T";
 }
 else
 {
  DataSet->FieldByName("PO_TERMINIE")->AsString = "N";
 }
 return _PoTer;
}
//---------------------------------------------------------------------------
bool T_SprKwartalneQR::isZPlanu(TDataSet *DataSet)
{
 return DataSet->FieldByName("POZYCJA")->AsInteger !=  999;
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::planIlSprz(TDataSet *DataSet,bool _ZPlanu)
{
  DataSet->FieldByName("ILOSC_P")->AsFloat = DataSet->FieldByName("ILOSC")->AsFloat - DataSet->FieldByName("IK4")->AsFloat; //Sprzêt przyjêty minus ten ju¿ wyremontowany
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::planLiczbaRBH(TDataSet *DataSet,bool _ZPlanu)
{
  DataSet->FieldByName("PLAN_LICZBA_RBH")->AsFloat = DataSet->FieldByName("LICZBA_RBH")->AsFloat - DataSet->FieldByName("R4")->AsFloat; //Godziny z KUTa minus te ju¿ wykorzystane
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::planRBH(TDataSet *DataSet,bool _ZPlanu, bool _PoTer)
{
  DataSet->FieldByName("RBH_1")->AsFloat =  DataSet->FieldByName("RK1")->AsFloat; //GODZINY zaplanowane na dany miesi¹c na danym KUCie
  DataSet->FieldByName("RBH_2")->AsFloat =  DataSet->FieldByName("RK2")->AsFloat;
  DataSet->FieldByName("RBH_3")->AsFloat =  DataSet->FieldByName("RK3")->AsFloat;
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::realIl(TDataSet *DataSet,bool _PoTer)
{
 DataSet->FieldByName("ILOSC_M1")->AsFloat   = DataSet->FieldByName("IK1")->AsFloat;
 DataSet->FieldByName("ILOSC_M2")->AsFloat   = DataSet->FieldByName("IK2")->AsFloat;
 DataSet->FieldByName("ILOSC_M3")->AsFloat   = DataSet->FieldByName("IK3")->AsFloat;
 DataSet->FieldByName("ILOSC_REM")->AsFloat  = DataSet->FieldByName("ILOSC_M1")->AsFloat + DataSet->FieldByName("ILOSC_M2")->AsFloat + DataSet->FieldByName("ILOSC_M3")->AsFloat;
}
//---------------------------------------------------------------------------
void T_SprKwartalneQR::wRem(TDataSet *DataSet,bool _ZPlanu, bool _PoTer)
{
 double _IlWRem(0.0);
 double _IlZal(0.0);
 double _Mian(0.0);
 String PlanProc("-");
 String ZalProc("-");
 //ILOŒCI
	_IlWRem  = DataSet->FieldByName("ILOSC_P")->AsFloat - DataSet->FieldByName("ILOSC_REM")->AsFloat;
		  if(DataSet->FieldByName("IP3")->AsFloat >0) 	_IlZal   = DataSet->FieldByName("IP3")->AsFloat -  DataSet->FieldByName("ILOSC_M3")->AsFloat;
	else  if(DataSet->FieldByName("IP2")->AsFloat >0) 	_IlZal   = DataSet->FieldByName("IP2")->AsFloat -  DataSet->FieldByName("ILOSC_M2")->AsFloat;
	else  if(DataSet->FieldByName("IP1")->AsFloat >0) 	_IlZal   = DataSet->FieldByName("IP1")->AsFloat -  DataSet->FieldByName("ILOSC_M1")->AsFloat;
	if(_IlZal <0.0) _IlZal = 0.0;
	_IlWRem -= _IlZal;
	if(_IlWRem <0.0) _IlWRem =0.0;
 //PROCENTY
   _Mian = DataSet->FieldByName("ILOSC_P")->AsFloat;
   if(_Mian <0.0) _Mian =0.0;
   if(_Mian ==0.00 || _IlZal <=0) ZalProc  ="-";
   else ZalProc = String( 100 - (ceil( _IlZal/_Mian * 100) )) +String("%");

   if(_Mian ==0.00 || _IlWRem ==0) PlanProc  ="-";
   else PlanProc = String(  (100 - ceil( _IlWRem/_Mian * 100) )) +String("%");
 if(_IlWRem >0.0) DataSet->FieldByName("ILOSC_PLAN")->AsFloat  = _IlWRem;
 else  DataSet->FieldByName("ILOSC_PLAN")->Clear();
 if(_IlZal >0.0) DataSet->FieldByName("ILOSC_ZAL")->AsFloat    = _IlZal;
 else DataSet->FieldByName("ILOSC_ZAL")->Clear();
 DataSet->FieldByName("PROC_PLAN")->AsString  =PlanProc;
 DataSet->FieldByName("PROC_ZAL")->AsString   =ZalProc;

}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::QRExpr1Print(TObject *sender, UnicodeString &Value)

{
 Value = IntToStr(++lp);
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_Proc23QREPrint(TObject *sender, UnicodeString &Value)
{

  /* kol 23 = 22 : 4  IF( (REM + ZAL)='TN',ILOSC - W1 - W2 - W3 - W4,0)*/
 double _Mianownik = cdsData->FieldByName("ILOSC")->AsFloat;
 TDateTime _DZ(cdsData->FieldByName("DATA_ZAK")->AsDateTime);
 if(_Mianownik !=0.00 && _DZ == TDateTime(0.0))
 {
 double _Licznik(0.00);
		_Licznik  += cdsData->FieldByName("W1")->AsFloat;
		_Licznik  += cdsData->FieldByName("W2")->AsFloat;
		_Licznik  += cdsData->FieldByName("W3")->AsFloat;
  Value = String( ceil( _Licznik/_Mianownik * 100) ) +String("%");
 }
 else Value = "-";



}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_Proc25QREPrint(TObject *sender, UnicodeString &Value)

{
 double _Mianownik = cdsData->FieldByName("ILOSC")->AsFloat - cdsData->FieldByName("W4")->AsFloat;
 TDateTime _DZ(cdsData->FieldByName("DATA_ZAK")->AsDateTime);
 if(_Mianownik !=0.00 && _DZ == TDateTime(0.0))
 {
 double _Licznik(0.00);
		_Licznik  += cdsData->FieldByName("W1")->AsFloat;
		_Licznik  += cdsData->FieldByName("W2")->AsFloat;
		_Licznik  += cdsData->FieldByName("W3")->AsFloat;
  Value = String( 100 - ceil( _Licznik/_Mianownik * 100) ) +String("%");
 }
 else Value = "-";



}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::m_DetailQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)

{
 if(m_Filtr1)
 {
  TDateTime _DataDo= EndOfAMonth(m_rok,3*m_kwartal);
  PrintBand = cdsDataPROC_PLAN->AsString == String("100%") && (cdsDataDATA_ZAK->IsNull || cdsDataDATA_ZAK->AsDateTime > _DataDo);
  if(!PrintBand) return;
 }
 if(cdsData->FieldByName("REM")->AsString =="T")
 {
  m_SumUsl22 +=cdsDataILOSC_PLAN->AsFloat;
  m_SumWar22 +=cdsDataILOSC_PLAN->AsFloat;
  m_SumOg22  +=cdsDataILOSC_PLAN->AsFloat;
  m_SumUsl24 +=cdsDataILOSC_ZAL->AsFloat;
  m_SumWar24 +=cdsDataILOSC_ZAL->AsFloat;
  m_SumOg24  +=cdsDataILOSC_ZAL->AsFloat;
  double _IlOg = cdsData->FieldByName("ILOSC")->AsFloat;
  if(cdsDataPO_TERMINIE->AsString == "N") _IlOg -=   cdsData->FieldByName("IK4")->AsFloat;
  m_SumUslIl += _IlOg;
  m_SumWarIl += _IlOg;
  m_SumOgIl  += _IlOg;
 }

 m_UwagiQRE->Width = m_DetailQRB->Width - m_UwagiQRE->Left;
 int _Lines(2);

 AnsiString value = cdsData->FieldByName("naz_sprzetu")->AsAnsiString;
 QRBandMng::countBandLines(_Lines,QRExpr2,value);
 value = cdsData->FieldByName("JW")->AsAnsiString + " " + cdsData->FieldByName("MIEJSCOWOSC")->AsAnsiString;
 QRBandMng::countBandLines(_Lines,m_JWQRE,value);
 value = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString + " "
	+ cdsData->FieldByName("JW")->AsAnsiString + " " + cdsData->FieldByName("MIEJSCOWOSC")->AsAnsiString;
 QRBandMng::countBandLines(_Lines,QRExpr26,value);

 QRBandMng::setBandHeight(Sender, (13 * _Lines), 13 * _Lines, ( 13 *_Lines) );
}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::ftPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand)

{
 int _Lines(0);

 AnsiString value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr41));
 QRBandMng::countBandLines(_Lines,QRExpr41,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr42));
 QRBandMng::countBandLines(_Lines,QRExpr42,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr43));
 QRBandMng::countBandLines(_Lines,QRExpr43,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr44));
 QRBandMng::countBandLines(_Lines,QRExpr44,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr45));
 QRBandMng::countBandLines(_Lines,QRExpr45,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr46));
 QRBandMng::countBandLines(_Lines,QRExpr46,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr47));
 QRBandMng::countBandLines(_Lines,QRExpr47,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr48));
 QRBandMng::countBandLines(_Lines,QRExpr48,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr49));
 QRBandMng::countBandLines(_Lines,QRExpr49,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr50));
 QRBandMng::countBandLines(_Lines,QRExpr50,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumUsl22QRE));
 QRBandMng::countBandLines(_Lines,m_SumUsl22QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcUsl23QRE));
 QRBandMng::countBandLines(_Lines,m_ProcUsl23QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumUsl24QRE));
 QRBandMng::countBandLines(_Lines,m_SumUsl24QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcUsl25QRE));
 QRBandMng::countBandLines(_Lines,m_ProcUsl25QRE,value);

 QRBandMng::setBandHeight(Sender, (17 * _Lines), 17 * _Lines, ( 17 *_Lines)-1);// - 1);
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::SummaryBand1BeforePrint(TQRCustomBand *Sender, bool &PrintBand)

{
 int _Lines(0);

 AnsiString value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr55));
 QRBandMng::countBandLines(_Lines,QRExpr55,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr56));
 QRBandMng::countBandLines(_Lines,QRExpr56,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr57));
 QRBandMng::countBandLines(_Lines,QRExpr57,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr58));
 QRBandMng::countBandLines(_Lines,QRExpr58,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr59));
 QRBandMng::countBandLines(_Lines,QRExpr59,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr60));
 QRBandMng::countBandLines(_Lines,QRExpr60,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr61));
 QRBandMng::countBandLines(_Lines,QRExpr61,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr62));
 QRBandMng::countBandLines(_Lines,QRExpr62,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr63));
 QRBandMng::countBandLines(_Lines,QRExpr63,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr64));
 QRBandMng::countBandLines(_Lines,QRExpr64,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumWar22QRE));
 QRBandMng::countBandLines(_Lines,m_SumWar22QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcWar23QRE));
 QRBandMng::countBandLines(_Lines,m_ProcWar23QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumWar24QRE));
 QRBandMng::countBandLines(_Lines,m_SumWar24QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcWar25QRE));
 QRBandMng::countBandLines(_Lines,m_ProcWar25QRE,value);

 QRBandMng::setBandHeight(Sender, (17 * _Lines), 17 * _Lines, ( 17 *_Lines)-1);// - 1);
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::ftPodPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand)

{
 int _Lines(0);
 AnsiString value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr27));
 QRBandMng::countBandLines(_Lines,QRExpr27,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr28));
 QRBandMng::countBandLines(_Lines,QRExpr28,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr29));
 QRBandMng::countBandLines(_Lines,QRExpr29,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr30));
 QRBandMng::countBandLines(_Lines,QRExpr30,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr31));
 QRBandMng::countBandLines(_Lines,QRExpr31,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr32));
 QRBandMng::countBandLines(_Lines,QRExpr32,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr33));
 QRBandMng::countBandLines(_Lines,QRExpr33,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr34));
 QRBandMng::countBandLines(_Lines,QRExpr34,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr35));
 QRBandMng::countBandLines(_Lines,QRExpr35,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(QRExpr36));
 QRBandMng::countBandLines(_Lines,QRExpr36,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumOg22QRE));
 QRBandMng::countBandLines(_Lines,m_SumOg22QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcOg23QRE));
 QRBandMng::countBandLines(_Lines,m_ProcOg23QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_SumOg24QRE));
 QRBandMng::countBandLines(_Lines,m_SumOg24QRE,value);
 value = FormatCurr("###,###,###,###.##",getExprDblValue(m_ProcOg25QRE));
 QRBandMng::countBandLines(_Lines,m_ProcOg25QRE,value);

 QRBandMng::setBandHeight(Sender, (17 * _Lines), 17 * _Lines, ( 17 *_Lines));// - 1);
}
//---------------------------------------------------------------------------
/* AnsiString aa = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString +
   "\n" +  cdsData->FieldByName("JW")->AsAnsiString;

 Value = aa;*/
void __fastcall T_SprKwartalneQR::m_UwagiQREPrint(TObject *sender, UnicodeString &Value)

{
AnsiString aa = cdsData->FieldByName("UWAGI")->AsAnsiString;
if(cdsData->FieldByName("DEPOZYT")->AsAnsiString == "T") aa += " -depozyt";

 //Value = aa;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::QRExpr26Print(TObject *sender, UnicodeString &Value)

{
 AnsiString aa;

 if(cdsData->FieldByName("JW")->AsAnsiString == "" )
 {
	if(YearOf(cdsData->FieldByName("DATA_PRZEKAZ")->AsDateTime) > 1900)
	{
	 aa = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString;
	 aa += " " + cdsData->FieldByName("DOSTAWCA")->AsAnsiString;
	}
 }
 else
 {
	if(YearOf(cdsData->FieldByName("DATA_PRZEKAZ")->AsDateTime) > 1900)
	{
	 aa = cdsData->FieldByName("DATA_PRZEKAZ")->AsAnsiString;
	 aa += " " + cdsData->FieldByName("JW")->AsAnsiString + " " + cdsData->FieldByName("MIEJSCOWOSC")->AsAnsiString;
	}
 }

 Value = aa;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_JWQREPrint(TObject *sender, UnicodeString &Value)

{
 AnsiString aa;

 if(cdsData->FieldByName("JW")->AsAnsiString == "" )
 {
	aa += " " + cdsData->FieldByName("DOSTAWCA")->AsAnsiString;
 }
 else
 {
	aa += "    " + cdsData->FieldByName("JW")->AsAnsiString + "    " + cdsData->FieldByName("MIEJSCOWOSC")->AsAnsiString;
 }

 Value = aa;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_PageHeadChildQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 PrintBand = m_PrintPageHeader;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_PageHeadQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 PrintBand = m_PrintPageHeader;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::ftPoziomAfterPrint(TQRCustomBand *Sender, bool BandPrinted)
{
 m_PrintPageHeader = false;
 m_SumWar22 =0.0;
 m_SumWar24 =0.0;
 m_SumWarIl =0.0;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::ChildBand4AfterPrint(TQRCustomBand *Sender, bool BandPrinted)
{
  m_PrintPageHeader = true;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::ChildBand3AfterPrint(TQRCustomBand *Sender, bool BandPrinted)
{
 //m_Raport->NewColumn();
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::grPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand)
{
 lp = 0;
 if(m_NewCol) m_Raport->NewColumn();
 m_NewCol = true;
}
//---------------------------------------------------------------------------


void __fastcall T_SprKwartalneQR::m_ProcUsl23QREPrint(TObject *sender, UnicodeString &Value)
{
 if(m_SumUslIl !=0.00 )
 {
  Value = String( ceil( m_SumUsl22/m_SumUslIl * 100) ) +String("%");
 }
 else Value = "0%";
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_ProcUsl25QREPrint(TObject *sender, UnicodeString &Value)
{
 if(m_SumUslIl !=0.00 )
 {
  Value = String(100 -   ceil(m_SumUsl22/m_SumUslIl * 100) )+String("%");
 }
 else Value = "0%";
}
//---------------------------------------------------------------------------


void __fastcall T_SprKwartalneQR::m_SumUsl22QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumUsl22);

}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_SumWar22QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumWar22);


}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_SumOg22QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumOg22);

}
//---------------------------------------------------------------------------


void __fastcall T_SprKwartalneQR::m_SumUsl24QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumUsl24);
 m_SumUsl24=0.00;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_SumWar24QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumWar24);
 m_SumWar24=0.00;

}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_SumOg24QREPrint(TObject *sender, UnicodeString &Value)

{
 Value = FormatCurr("###,###,##0.00",m_SumOg24);
 m_SumOg24=0.00;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_ProcWar23QREPrint(TObject *sender, UnicodeString &Value)

{
 if(m_SumWarIl !=0.00 )
 {
  Value = String( ceil( m_SumWar22/m_SumWarIl * 100) ) +String("%");
 }
 else Value = "0%";
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_ProcWar25QREPrint(TObject *sender, UnicodeString &Value)

{
 if(m_SumWarIl !=0.00 )
 {
  Value = String( 100-  ceil(m_SumWar22 /m_SumWarIl * 100) ) +String("%");
 }
 else Value = "0%";

}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_ProcOg23QREPrint(TObject *sender, UnicodeString &Value)

{
 if(m_SumOgIl !=0.00 )
 {
  Value = String( ceil( m_SumOg22/m_SumOgIl * 100) ) +String("%");
 }
 else Value = "0%";
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_ProcOg25QREPrint(TObject *sender, UnicodeString &Value)

{
 if(m_SumOgIl !=0.00 )
 {
  Value = String(100 - ceil(m_SumOg22/m_SumOgIl * 100) ) +String("%");
 }
 else Value = "0%";
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::ftPodPoziomAfterPrint(TQRCustomBand *Sender, bool BandPrinted)

{
 m_SumUsl22 =0.0;
 m_SumUsl24 =0.0;
 m_SumUslIl =0.0;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::SummaryBand1AfterPrint(TQRCustomBand *Sender, bool BandPrinted)

{
 m_SumOg22 =0.0;
 m_SumOg24 =0.0;
 m_SumOgIl =0.0;
 m_SumIl4  =0.0;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::grPodPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand)

{

 if(m_Raport->CurrentY > 1500) m_Raport->NewColumn();


}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_RaportAfterPrint(TObject *Sender)
{
 MaxCY;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_RaportAfterPreview(TObject *Sender)
{
  MaxCY;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::m_StronaQRLPrint(TObject *sender, UnicodeString &Value)
{
 Value = String("Strona: ") + String(m_Raport->PageNumber+Strona -1);
}
//---------------------------------------------------------------------------


void __fastcall T_SprKwartalneQR::printPierwszyMies(TObject *sender, UnicodeString &Value)
{
 AnsiString _Buff = Value;
 int _Mies = 3*m_kwartal -2;
 _Buff = jbutils::JBVaria::arabic2roman(_Buff.c_str(),_Mies);
 Value = _Buff;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::printDrugiMies(TObject *sender, UnicodeString &Value)
{
 AnsiString _Buff = Value;
 int _Mies = 3*m_kwartal -1;
 _Buff = jbutils::JBVaria::arabic2roman(_Buff.c_str(),_Mies);
 Value = _Buff;

}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::printTrzeciMies(TObject *sender, UnicodeString &Value)
{
 AnsiString _Buff = Value;
 int _Mies = 3*m_kwartal;
 _Buff = jbutils::JBVaria::arabic2roman(_Buff.c_str(),_Mies);
 Value = _Buff;

}
//---------------------------------------------------------------------------
void __fastcall T_SprKwartalneQR::setStrona(const int _Str)
{
  m_StronaQRL->Enabled = _Str >0;
  Strona = _Str;
}


void __fastcall T_SprKwartalneQR::cdsDataPostError(TDataSet *DataSet, EDatabaseError *E,
          TDataAction &Action)
{
  int i;
  i++;
}
//---------------------------------------------------------------------------

void __fastcall T_SprKwartalneQR::cdsDataReconcileError(TCustomClientDataSet *DataSet,
          EReconcileError *E, TUpdateKind UpdateKind, TReconcileAction &Action)

{
 int i;
 i++;

}
//---------------------------------------------------------------------------

