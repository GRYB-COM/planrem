//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "HarmDostDM.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\queries.h"
#include "model_readers_RBHReader.h"
#include "model_messengers_RBH4War.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_HarmDostDM::T_HarmDostDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_HarmDostDM::open(const T_HarmDostDM::Pars& _Pars)
{
  m_Pars = _Pars;
  TDateTime _NullD(0.0);
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
   TDateTime _Plan;
   int _Kw;
   int _YearDost;
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();
	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger     =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString     =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString     =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;

	 m_Client->FieldByName("ID_KOMORKI")->AsInteger      =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString    =  _Reader.fieldByName("KOD_WARSZTATU")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString    =  _Reader.fieldByName("NAZ_WARSZTATU")->AsString;
	 m_Client->FieldByName("ID_REMONTU")->AsString       =  _Reader.fieldByName("ID_REMONTU")->AsInteger;
	 m_Client->FieldByName("NAZ_REMONTU")->AsString      =  _Reader.fieldByName("NAZ_REMONTU")->AsString;
	 m_Client->FieldByName("ID_HARMONOGRAMU")->AsInteger =  _Reader.fieldByName("ID_HARMONOGRAMU")->AsInteger;

	 m_Client->FieldByName("DATA_FAKT")->AsDateTime      =  _Reader.fieldByName("DATA_FAKT")->AsDateTime;
	 m_Client->FieldByName("DATA_PLAN")->AsDateTime      = _Reader.fieldByName("DATA_OD")->AsDateTime;
	 m_Client->FieldByName("DATA_PRZEKAZ")->AsDateTime   =  _Reader.fieldByName("DATA_PRZEKAZ")->AsDateTime;

	 if(m_Client->FieldByName("DATA_FAKT")->AsDateTime == _NullD && _Reader.fieldByName("KONT")->AsString == "T" )
	 {//DOROBIONA FLAGA KONTYNUACJA ALE I TAK PIERWSZEÑSTWO MA FAKTYCZNE DOSTARCZENIE
	  m_Client->FieldByName("DATA_FAKT")->AsDateTime = _Reader.fieldByName("DATA_OD")->AsDateTime;
	 }

	 if(m_Client->FieldByName("DATA_FAKT")->AsDateTime == _NullD) m_Client->FieldByName("DATA_FAKT")->Clear();
	 if(m_Client->FieldByName("DATA_PLAN")->AsDateTime == _NullD) m_Client->FieldByName("DATA_PLAN")->Clear();
	 if(m_Client->FieldByName("DATA_PRZEKAZ")->AsDateTime == _NullD) m_Client->FieldByName("DATA_PRZEKAZ")->Clear();

	 m_Client->FieldByName("DOSTAWCA")->AsString         =	_Reader.fieldByName("JW")->AsString + " " + _Reader.fieldByName("MIEJSCOWOSC")->AsString;
	 m_Client->FieldByName("NAZ_SPRZ")->AsString         =  _Reader.fieldByName("NAZ_SPRZ")->AsString;
	 m_Client->FieldByName("NR_SPRZ")->AsString          =  _Reader.fieldByName("NR_SPRZ")->AsString;
	 m_Client->FieldByName("ZADANIE")->AsString          =  _Reader.fieldByName("ZADANIE")->AsString;
	 m_Client->FieldByName("INDEKS_MAT")->AsString       =  _Reader.fieldByName("INDEKS_MAT")->AsString;
	 m_Client->FieldByName("KOD_REM")->AsString          =  _Reader.fieldByName("KOD_REM")->AsString;
	 m_Client->FieldByName("NORMA_RBH")->AsCurrency      =  _Reader.fieldByName("NORMA_RBH")->AsCurrency;
	 m_Client->FieldByName("ILOSC")->AsCurrency          =  _Reader.fieldByName("ILOSC")->AsCurrency;
	 m_Client->FieldByName("ILOSC_KW_I")->AsCurrency     =  _Reader.fieldByName("ILOSC_KW_I")->AsCurrency;
	 m_Client->FieldByName("ILOSC_KW_II")->AsCurrency    =  _Reader.fieldByName("ILOSC_KW_II")->AsCurrency;
	 m_Client->FieldByName("ILOSC_KW_III")->AsCurrency   =  _Reader.fieldByName("ILOSC_KW_III")->AsCurrency;
	 m_Client->FieldByName("ILOSC_KW_IV")->AsCurrency    =  _Reader.fieldByName("ILOSC_KW_IV")->AsCurrency;

	 m_Client->FieldByName("PLAN_RBH_KW_I")->AsCurrency  =  _Reader.fieldByName("PLAN_RBH_KW_I")->AsCurrency;
	 m_Client->FieldByName("PLAN_RBH_KW_II")->AsCurrency =  _Reader.fieldByName("PLAN_RBH_KW_II")->AsCurrency;
	 m_Client->FieldByName("PLAN_RBH_KW_III")->AsCurrency=  _Reader.fieldByName("PLAN_RBH_KW_III")->AsCurrency;
	 m_Client->FieldByName("PLAN_RBH_KW_IV")->AsCurrency =  _Reader.fieldByName("PLAN_RBH_KW_IV")->AsCurrency;
	 m_Client->FieldByName("ILOSC_PRZ")->AsCurrency      =  _Reader.fieldByName("ILOSC_PRZ")->AsCurrency;
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
const AnsiString T_HarmDostDM::M_COL("\
WY.ID_WYDZIALU, WY.KOD AS KOD_WYDZIALU, WY.NAZWA AS NAZ_WYDZIALU, \
KO.ID_KOMORKI, KO.KOD as KOD_WARSZTATU, KO.NAZWA AS NAZ_WARSZTATU, \
U.POZYCJA AS ID_REMONTU, \
CASE WHEN U.POZYCJA < 999 THEN U.NAZ_REMONTU ELSE 'POZOSTA£E ZADANIA' END AS NAZ_REMONTU, \
H.ID_HARMONOGRAMU, H.TYP,H.ZADANIE, H.NR_ZADANIA AS NR_SPRZ, H.NORMA_RBH, H.DATA_OD, H.DATA_DO, H.KONT, \
S.NAZWA AS NAZ_SPRZ, S.INDEKS_MAT, \
J.JW, J.MIEJSCOWOSC,  \
R.KOD_REM,\
case  \
	   when	h.TYP='J' then (SELECT MIN(M.DATA_PRZYJ)    FROM PR_MAGAZYN M  inner join pr_zlecenia z on z.ID_KOMORKI_GLW = m.ID_KOMORKI and z.ROK_MAG = m.ROK and z.DEPOZYT = m.DEPOZYT and z.ID_MAG = m.ID_MAG and z.NR_KOL =0  WHERE z.ROK = H.ROK AND z.ID_HARM = H.ID_HARMONOGRAMU)  \
end AS DATA_FAKT, \
(SELECT MIN(M.DATA_PRZEKAZ)  FROM PR_MAGAZYN M  inner join pr_zlecenia z on z.ID_KOMORKI_GLW = m.ID_KOMORKI and z.ROK_MAG = m.ROK and z.DEPOZYT = m.DEPOZYT and z.ID_MAG = m.ID_MAG and z.NR_KOL =0   WHERE z.ROK = H.ROK AND z.ID_HARM = H.ID_HARMONOGRAMU) AS DATA_PRZEKAZ, \
(SELECT SUM(Z.ILOSC)  FROM PR_ZLECENIA Z WHERE Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU   and z.nr_kol=0) AS ILOSC_PRZ, \
SUM(D.ILOSC) AS ILOSC, \
SUM(CASE WHEN D.MIESIAC BETWEEN 1  AND 3  THEN D.ILOSC ELSE 0.00 END) AS ILOSC_KW_I, \
SUM(CASE WHEN D.MIESIAC BETWEEN 4  AND 6  THEN D.ILOSC ELSE 0.00 END) AS ILOSC_KW_II, \
SUM(CASE WHEN D.MIESIAC BETWEEN 7  AND 9  THEN D.ILOSC ELSE 0.00 END) AS ILOSC_KW_III, \
SUM(CASE WHEN D.MIESIAC BETWEEN 10 AND 12 THEN D.ILOSC ELSE 0.00 END) AS ILOSC_KW_IV, \
SUM(CASE WHEN D.MIESIAC BETWEEN 1  AND 3  THEN D.PLAN_RBH ELSE 0.00 END) AS PLAN_RBH_KW_I,\
SUM(CASE WHEN D.MIESIAC BETWEEN 4  AND 6  THEN D.PLAN_RBH ELSE 0.00 END) AS PLAN_RBH_KW_II, \
SUM(CASE WHEN D.MIESIAC BETWEEN 7  AND 9  THEN D.PLAN_RBH ELSE 0.00 END) AS PLAN_RBH_KW_III, \
SUM(CASE WHEN D.MIESIAC BETWEEN 10 AND 12 THEN D.PLAN_RBH ELSE 0.00 END) AS PLAN_RBH_KW_IV,  \
MIN(D.MIESIAC) AS MIN_MIES \
");
//---------------------------------------------------------------------------
const AnsiString T_HarmDostDM::M_TABLE("\
PR_HARMONOGRAM H \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU \
LEFT OUTER JOIN PR_HARMONOGRAM_DET D ON D.ROK = H.ROK AND D.ID_HARMONOGRAMU=H.ID_HARMONOGRAMU \
LEFT OUTER JOIN PR_REMONTY R ON R.ID_REMONTU = H.ID_REMONTU \
LEFT OUTER JOIN PR_KOMORKI KO ON KO.ID_KOMORKI = H.ID_KOMORKI \
LEFT OUTER JOIN PR_WYDZIALY WY ON WY.ID_WYDZIALU = KO.ID_WYDZIALU \
LEFT OUTER JOIN PR_KODY_USLUG U ON U.ID_USLUGI = H.ID_USLUGI  \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI \
");
//---------------------------------------------------------------------------
const AnsiString T_HarmDostDM::M_GROUP("\
WY.ID_WYDZIALU, WY.KOD, WY.NAZWA, KO.ID_KOMORKI, KO.KOD, KO.NAZWA, \
U.POZYCJA, U.NAZ_REMONTU, \
H.ROK, H.ID_HARMONOGRAMU, H.TYP, S.NAZWA, H.NR_ZADANIA, H.ZADANIE, \
S.INDEKS_MAT, R.KOD_REM, H.NORMA_RBH, H.DATA_OD,H.DATA_DO, H.KONT, J.JW, J.MIEJSCOWOSC \
");
//---------------------------------------------------------------------------
const AnsiString T_HarmDostDM::M_ORDER("H.ROK, U.POZYCJA, H.ID_HARMONOGRAMU ");
//---------------------------------------------------------------------------
mng::Query __fastcall T_HarmDostDM::getQuery(void)
{
 mng::Query _Q(M_TABLE,M_COL);
 _Q.attachWherePred(new mng::ComparePredicate(" ko.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
 _Q.attachWherePred(new mng::ComparePredicate(" ko.WARSZTAT "," 'T' "));
 _Q.attachWherePred(new mng::ComparePredicate(" H.ROK ", m_Pars.Rok) );
 _Q.attachWherePred(new mng::ComparePredicate(" U.POZYCJA "," 999 ", mng::ComparePredicate::copLess ) );
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_KOMORKI", m_Pars.IdWarsztatu));
   if(m_Pars.Rok >0)         _Q.attachWherePred( new mng::ComparePredicate(" H.ROK", m_Pars.Rok));
  _Q.setOrderList(M_ORDER);
  _Q.setGroupList(M_GROUP);
  _Q.saveToFile("query.sql");
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_HarmDostDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_HarmDostDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_HarmDostADO->Open();
 m_Client->First();
 String _NazSprz, _Zad, _Uwagi;
 TDateTime _NullD(0.0);
 while(!m_Client->Eof)
 {
  m_HarmDostADO->Append();
  m_HarmDostADO->FieldByName("LP")->AsInteger           =1;
  m_HarmDostADO->FieldByName("nr harm")->AsInteger      = m_Client->FieldByName("ID_HARMONOGRAMU")->AsInteger;
  m_HarmDostADO->FieldByName("Id wydzia³u")->AsInteger  = m_Client->FieldByName("ID_WYDZIALU")->AsInteger;
  m_HarmDostADO->FieldByName("Kod wydzia³u")->AsString  = m_Client->FieldByName("KOD_WYDZIALU")->AsString;
  m_HarmDostADO->FieldByName("Wydzia³")->AsString       = m_Client->FieldByName("NAZ_WYDZIALU")->AsString;
  m_HarmDostADO->FieldByName("Id komórki")->AsInteger = m_Client->FieldByName("ID_KOMORKI")->AsInteger;
  m_HarmDostADO->FieldByName("Kod warsztatu")->AsString = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
  m_HarmDostADO->FieldByName("Warsztat")->AsString      = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;
  m_HarmDostADO->FieldByName("Id remontu")->AsInteger   = m_Client->FieldByName("ID_REMONTU")->AsInteger;
  m_HarmDostADO->FieldByName("Nazwa remontu")->AsString = m_Client->FieldByName("NAZ_REMONTU")->AsString;
  _NazSprz = m_Client->FieldByName("NAZ_SPRZ")->AsString.Trim();
  _Zad     =  m_Client->FieldByName("ZADANIE")->AsString.Trim();
  if(!_NazSprz.IsEmpty() && !_Zad.IsEmpty() ) _NazSprz += " ";
  _NazSprz += _Zad;

  m_HarmDostADO->FieldByName("Nazwa sprzêtu")->AsString  = _NazSprz;
  m_HarmDostADO->FieldByName("Numer sprzêtu")->AsString    = m_Client->FieldByName("NR_SPRZ")->AsString.Trim();
  m_HarmDostADO->FieldByName("JIM")->AsString  = m_Client->FieldByName("INDEKS_MAT")->AsString;
  m_HarmDostADO->FieldByName("Norma RBH")->AsCurrency   = m_Client->FieldByName("NORMA_RBH")->AsCurrency;
  m_HarmDostADO->FieldByName("Rodzaj naprawy")->AsString = m_Client->FieldByName("KOD_REM")->AsString;
  m_HarmDostADO->FieldByName("Iloœæ")->AsCurrency  = m_Client->FieldByName("ILOSC")->AsCurrency;
  m_HarmDostADO->FieldByName("Iloœæ I kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_I")->AsCurrency;
  m_HarmDostADO->FieldByName("Iloœæ II kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_II")->AsCurrency;
  m_HarmDostADO->FieldByName("Iloœæ III kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_III")->AsCurrency;
  m_HarmDostADO->FieldByName("Iloœæ IV kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_IV")->AsCurrency;
  m_HarmDostADO->FieldByName("Planowane RBH I kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_I")->AsCurrency;
  m_HarmDostADO->FieldByName("Planowane RBH II kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_II")->AsCurrency;
  m_HarmDostADO->FieldByName("Planowane RBH III kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_III")->AsCurrency;
  m_HarmDostADO->FieldByName("Planowane RBH IV kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_IV")->AsCurrency;
  if( m_Client->FieldByName("DATA_PLAN")->IsNull)
  {
   m_HarmDostADO->FieldByName("Planowany termin dostarczenia")->Clear();
  }
  else
  {
   m_HarmDostADO->FieldByName("Planowany termin dostarczenia")->AsDateTime =  m_Client->FieldByName("DATA_PLAN")->AsDateTime;
  }
  if(m_Client->FieldByName("DATA_FAKT")->IsNull)
  {
   m_HarmDostADO->FieldByName("Faktyczny termin dostarczenia")->Clear();
  }
  else
  {
   m_HarmDostADO->FieldByName("Faktyczny termin dostarczenia")->AsDateTime =  m_Client->FieldByName("DATA_FAKT")->AsDateTime;
  }
  if(m_Client->FieldByName("DATA_PRZEKAZ")->IsNull)
  {
   m_HarmDostADO->FieldByName("Data przekazania")->Clear();
   _Uwagi="";
  }
  else
  {
   m_HarmDostADO->FieldByName("Data przekazania")->AsDateTime              =  m_Client->FieldByName("DATA_PRZEKAZ")->AsDateTime;
   _Uwagi                                                                  =  m_Client->FieldByName("DATA_PRZEKAZ")->AsString;
  }
  m_HarmDostADO->FieldByName("Dostawca")->AsString                        =	m_Client->FieldByName("DOSTAWCA")->AsString;
  if(m_Pars.Info && m_Client->FieldByName("ILOSC_PRZ")->AsCurrency >0.0)
  {
   _Uwagi                                                                 += String(" iloœæ: ") + m_Client->FieldByName("ILOSC_PRZ")->AsString;
  }
   m_HarmDostADO->FieldByName("Uwagi")->AsString                           =  _Uwagi;

  m_HarmDostADO->Post();
  m_Client->Next();
 }
 m_HarmDostADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_HarmDostDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------
TDateTime  __fastcall T_HarmDostDM::getPlan(const int _Mies)
{
 TDateTime _Res(CurrentYear(),1,1);
  AnsiString _Kwart("Kwarta³ ");
  jbutils::TMyIni _Ini;
 if(_Mies <4)
 {
  _Res  = _Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart + 1, TDateTime(CurrentYear(),12,15));
 }
 else if( _Mies >3 && _Mies < 7)
 {
  _Res = _Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart + 2, TDateTime(CurrentYear()+1,2,15));
 }
 else if(_Mies >6 && _Mies <10)
 {
  _Res = _Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart + 3, TDateTime(CurrentYear()+1,5,15));
 }
 else
 {
   _Res  = _Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart + 4, TDateTime(CurrentYear()+1,8,16));
 }
 return _Res;
}
