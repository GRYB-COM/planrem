//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "RBH4OSDM.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\queries.h"
#include "model_readers_RBHReader.h"
#include "model_messengers_RBH4Os.h"
#include "isvaria.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_RBH4OSDM::T_RBH4OSDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OSDM::open(const T_RBH4OSDM::Pars& _Pars)
{
  m_Pars = _Pars;
  int _IdOsoby;
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
 //OGCZYTANIE GODZIN
   msg::RBH4Os _RBH4Os;
   readers::RBHReader::Pars _P;
   _P.AddPlan   = false;
   _P.Rok       = _Pars.Rok;
   _P.IdKomorki = _Pars.IdWarsztatu;
   readers::RBHReader _ReadRBH;
   _ReadRBH.read(_RBH4Os,_P);
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();
	 _IdOsoby = _Reader.fieldByName("ID_OSOBY")->AsInteger;
	 m_Client->FieldByName("ID_KOMORKI")->AsInteger     =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString   =  _Reader.fieldByName("KOD_WARSZTATU")->AsString;
	 m_Client->FieldByName("NAZWA")->AsString           =  _Reader.fieldByName("NAZWA")->AsString;

	 m_Client->FieldByName("ID_OSOBY")->AsInteger       =  _IdOsoby;
	 m_Client->FieldByName("STOPIEN")->AsString         =  _Reader.fieldByName("STOPIEN")->AsString;
	 m_Client->FieldByName("STANOWISKO")->AsString      =  _Reader.fieldByName("STANOWISKO")->AsString;
	 m_Client->FieldByName("KIEROWNIK")->AsInteger      =   _Reader.fieldByName("STANOWISKO")->AsString == "Kierownik warsztatu" ? 1 :0 ;
	 m_Client->FieldByName("IMIE")->AsString            =  _Reader.fieldByName("IMIE")->AsString;
	 m_Client->FieldByName("NAZWISKO")->AsString        =  _Reader.fieldByName("NAZWISKO")->AsString;

	 m_Client->FieldByName("ETAT_PR")->AsString        =  _RBH4Os[_IdOsoby].EtatPr.SubString(1,20);
	 m_Client->FieldByName("RBH_NOM")->AsCurrency       =  ISRound(_RBH4Os[_IdOsoby].RBH_Nom,2);
	 m_Client->FieldByName("RBH_URLOP")->AsCurrency     =  ISRound(_RBH4Os[_IdOsoby].RBH_Ur,2);
	 m_Client->FieldByName("RBH_PRZERWA")->AsCurrency   =  ISRound(_RBH4Os[_IdOsoby].RBH_Prz,2);
	 m_Client->FieldByName("RBH_CHOROBA")->AsCurrency   =  ISRound(_RBH4Os[_IdOsoby].RBH_Ch,2);
	 m_Client->FieldByName("RBH_SLUZBA")->AsCurrency    =  ISRound(_RBH4Os[_IdOsoby].RBH_Sl,2);
	 m_Client->FieldByName("RBH_SZKOLENIE")->AsCurrency =  ISRound(_RBH4Os[_IdOsoby].RBH_Szk,2);
	 m_Client->FieldByName("RBH_NPROD")->AsCurrency     =  ISRound(_RBH4Os[_IdOsoby].RBH_NProd,2);
	 m_Client->FieldByName("RBH_PROD")->AsCurrency      =  ISRound(_RBH4Os[_IdOsoby].RBH_Prod,2);
	 m_Client->FieldByName("RBH_EFF")->AsCurrency       =  ISRound(_RBH4Os[_IdOsoby].RBH_Prod,2);

	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
const AnsiString T_RBH4OSDM::M_COL_LIST("\
war.ID_KOMORKI, war.KOD AS KOD_WARSZTATU, war.NAZWA,os.ID_OSOBY,s.NAZWA AS STOPIEN, os.IMIE, os.NAZWISKO, \
os.ETAT_PR, STA.NAZWA AS STANOWISKO,  \
sum( os.ETAT_PR * os.ETAT_NPR * mies.DNI_ROB) AS RBH_NOM, \
sum( os.ETAT_PR * os.ETAT_NPR * ur.URLOP/os.ETAT_KOR )  AS RBH_URLOP,\
sum( os.ETAT_PR * os.ETAT_NPR * zw.LICZBA_DNI/os.ETAT_KOR ) AS RBH_ZW, \
sum( (os.ETAT_PR * mies.DNI_ROB - os.ETAT_PR/os.ETAT_KOR*(case when ur.Urlop is NULL then 0 else ur.URLOP end + case when zw.LICZBA_DNI is NULL then 0 else zw.LICZBA_DNI end))  * ka.PRZERWA) AS RBH_PRZERWA, \
sum( os.ETAT_PR * ka.CHOROBA) AS RBH_CHOROBA, \
sum( os.ETAT_PR * ka.SLUZBA)  AS RBH_SLUZBA, \
sum( os.ETAT_PR *  sz.RBH ) AS RBH_SZKOLENIE \
");
//---------------------------------------------------------------------------
const AnsiString T_RBH4OSDM::M_TABLE_REF("\ PR_komorki war  \
left outer join PR_OSOBY    os   on os.ID_KOMORKI = war.ID_KOMORKI  \
inner join PR_MIESIACE mies on mies.NR_MIES >0  \
left outer join PR_URLOPY   ur   on ur.ID_OSOBY = os.ID_OSOBY and ur.NR_MIES = mies.NR_MIES \
left outer join PR_ZW_DOD   zw   on zw.ID_OSOBY = os.ID_OSOBY and zw.NR_MIES = mies.NR_MIES \
left outer join PR_KADRA    ka   on ka.KOD = os.KADRA \
left outer join PR_SZKOLENIE_RBH sz on sz.KOD = ka.KOD and sz.NR_MIES = mies.NR_MIES \
LEFT OUTER JOIN PR_STOPNIE S  ON S.ID_STOPNIA = OS.ID_STOPNIA \
LEFT OUTER JOIN PR_STANOWISKA STA ON STA.ID_STANOWISKA = OS.ID_STANOWISKA \
");
//---------------------------------------------------------------------------
mng::Query __fastcall T_RBH4OSDM::getQuery(void)
{
   mng::Query _Q(M_TABLE_REF,M_COL_LIST);
   _Q.setGroupList("war.ID_KOMORKI, war.KOD, war.NAZWA,os.ID_OSOBY,s.NAZWA, os.IMIE, os.NAZWISKO, os.ETAT_PR, STA.NAZWA");
   _Q.setOrderList("war.KOD, os.NAZWISKO");
   _Q.attachWherePred(new mng::ComparePredicate(" war.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" war.KOD "," '-1/-1' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" war.WARSZTAT "," 'T' "));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" war.ID_KOMORKI", m_Pars.IdWarsztatu));
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OSDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OSDM::saveToMdb(const String & _Path)
{
 String _ImieNazw, _St;
 Currency _RbhNom;
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_RBH4OSADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_RBH4OSADO->Append();
	 m_RBH4OSADO->FieldByName("Identyfikator warsztatu")->AsInteger  =   m_Client->FieldByName("ID_KOMORKI")->AsInteger;
	 m_RBH4OSADO->FieldByName("Nazwa warsztatu")->AsString           =  m_Client->FieldByName("NAZWA")->AsString;
	 m_RBH4OSADO->FieldByName("Kod warsztatu")->AsString             =  m_Client->FieldByName("KOD_WARSZTATU")->AsString;

	 m_RBH4OSADO->FieldByName("Identyfikator osoby")->AsInteger      =  m_Client->FieldByName("ID_OSOBY")->AsInteger;
	 m_RBH4OSADO->FieldByName("Stopieñ")->AsString                   =  m_Client->FieldByName("STOPIEN")->AsString;
	 m_RBH4OSADO->FieldByName("Stanowisko")->AsString                =  m_Client->FieldByName("STANOWISKO")->AsString;
	 m_RBH4OSADO->FieldByName("Kierownik")->AsInteger                =  m_Client->FieldByName("KIEROWNIK")->AsInteger;
	 m_RBH4OSADO->FieldByName("Imiê")->AsString                  =  m_Client->FieldByName("IMIE")->AsString;
	 m_RBH4OSADO->FieldByName("Nazwisko")->AsString              =  m_Client->FieldByName("NAZWISKO")->AsString;
	 _St =  m_Client->FieldByName("STOPIEN")->AsString.Trim();
	 _ImieNazw = _St =="p" ? String("pan(i) ") : _St + String(" ");
	 _ImieNazw   +=  m_Client->FieldByName("NAZWISKO")->AsString.Trim() + " " +m_Client->FieldByName("IMIE")->AsString.Trim();
	 m_RBH4OSADO->FieldByName("Nazwisko i Imiê")->AsString       = _ImieNazw;

	 m_RBH4OSADO->FieldByName("Etat")->AsString                   =  m_Client->FieldByName("ETAT_PR")->AsString;
	 _RbhNom = m_Client->FieldByName("RBH_NOM")->AsCurrency;
	 if(_RbhNom >0)
	 {
	  m_RBH4OSADO->FieldByName("RBH Nominalne")->AsCurrency       =  _RbhNom;
	  m_RBH4OSADO->FieldByName("Urlop")->AsCurrency               =  m_Client->FieldByName("RBH_URLOP")->AsCurrency;
	  m_RBH4OSADO->FieldByName("Przerwa")->AsCurrency             =  m_Client->FieldByName("RBH_PRZERWA")->AsCurrency;
	  m_RBH4OSADO->FieldByName("Choroba")->AsCurrency             =  m_Client->FieldByName("RBH_CHOROBA")->AsCurrency;
	  m_RBH4OSADO->FieldByName("S³u¿ba")->AsCurrency              =  m_Client->FieldByName("RBH_SLUZBA")->AsCurrency;
	  m_RBH4OSADO->FieldByName("Szkolenie")->AsCurrency           =  m_Client->FieldByName("RBH_SZKOLENIE")->AsCurrency;
	  m_RBH4OSADO->FieldByName("RBH Nieprodukcyjne")->AsCurrency  =  m_Client->FieldByName("RBH_NPROD")->AsCurrency;
	  m_RBH4OSADO->FieldByName("RBH Produkcyjne")->AsCurrency     =  m_Client->FieldByName("RBH_PROD")->AsCurrency;
	  m_RBH4OSADO->FieldByName("RBH Efektywne")->AsCurrency       =  m_Client->FieldByName("RBH_EFF")->AsCurrency;
	 }
	m_RBH4OSADO->Post();
  m_Client->Next();
 }
 m_RBH4OSADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OSDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

