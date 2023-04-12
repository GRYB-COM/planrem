//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "KwMozlWarSprzDM.h"
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
__fastcall T_KwMozlWarSprzDM::T_KwMozlWarSprzDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarSprzDM::open(const T_KwMozlWarSprzDM::Pars& _Pars)
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
	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger     =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString     =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString     =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;

	 m_Client->FieldByName("ID_KOMORKI")->AsInteger    =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString    =  _Reader.fieldByName("KOD_WARSZTATU")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString    =  _Reader.fieldByName("NAZ_WARSZTATU")->AsString;
	 m_Client->FieldByName("ID_REMONTU")->AsString       =  _Reader.fieldByName("ID_REMONTU")->AsInteger;
	 m_Client->FieldByName("NAZ_REMONTU")->AsString      =  _Reader.fieldByName("NAZ_REMONTU")->AsString;
	 m_Client->FieldByName("ID_HARMONOGRAMU")->AsInteger =  _Reader.fieldByName("ID_HARMONOGRAMU")->AsInteger;
	 //m_Client->FieldByName("NAZ_SPRZ")->AsString         =  _Reader.fieldByName("NAZ_SPRZ")->AsString;
	 //m_Client->FieldByName("NR_SPRZ")->AsString          =  _Reader.fieldByName("NR_SPRZ")->AsString;
	 //m_Client->FieldByName("ZADANIE")->AsString          =  _Reader.fieldByName("ZADANIE")->AsString;
	 m_Client->FieldByName("TYP_SPRZ")->AsString         =  _Reader.fieldByName("TYP_SPRZ")->AsString;
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
	 if(_Pars.Diag)
	 {
	  String _Diag = String("Diag: ") + _Reader.fieldByName("TYP_SPRZ")->AsString;
	  _Diag += String(" ") + _Reader.fieldByName("ID_HARMONOGRAMU")->AsString;
	  //_Diag += String(" ") + _Reader.fieldByName("NR_SPRZ")->AsString;
	  //_Diag += String(" ") + _Reader.fieldByName("ZADANIE")->AsString;
      m_Client->FieldByName("TYP_SPRZ")->AsString = _Diag;
	 }
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
const AnsiString T_KwMozlWarSprzDM::M_COL("\
ID_WYDZIALU, \
KOD_WYDZIALU, \
NAZ_WYDZIALU, \
ID_KOMORKI,\
KOD_WARSZTATU, \
NAZ_WARSZTATU, \
ID_REMONTU, \
NAZ_REMONTU, \
TYP_SPRZ, \
INDEKS_MAT, \
KOD_REM,\
ROK, \
ID_HARMONOGRAMU, \
MIN(NORMA_RBH) AS NORMA_RBH, \
SUM(ILOSC) AS ILOSC, \
SUM(ILOSC_KW_I) AS ILOSC_KW_I, \
SUM(ILOSC_KW_II) AS ILOSC_KW_II, \
SUM(ILOSC_KW_III) AS ILOSC_KW_III, \
SUM(ILOSC_KW_IV) AS ILOSC_KW_IV, \
SUM(PLAN_RBH_KW_I) AS PLAN_RBH_KW_I,\
SUM(PLAN_RBH_KW_II) PLAN_RBH_KW_II, \
SUM(PLAN_RBH_KW_III) AS PLAN_RBH_KW_III, \
SUM(PLAN_RBH_KW_IV) AS PLAN_RBH_KW_IV \
");
//---------------------------------------------------------------------------
const AnsiString T_KwMozlWarSprzDM::M_TABLE("\
PR_ROCZNA_REAL_PLANU  \
");
//---------------------------------------------------------------------------
const AnsiString T_KwMozlWarSprzDM::M_GROUP("\
ID_WYDZIALU, \
KOD_WYDZIALU, \
NAZ_WYDZIALU, \
ID_KOMORKI,\
KOD_WARSZTATU, \
NAZ_WARSZTATU, \
ID_REMONTU, \
NAZ_REMONTU, \
TYP_SPRZ, \
INDEKS_MAT, \
KOD_REM,\
ROK, \
ID_HARMONOGRAMU \
");
//---------------------------------------------------------------------------
const AnsiString T_KwMozlWarSprzDM::M_ORDER("KOD_WYDZIALU,KOD_WARSZTATU,ID_REMONTU,ID_HARMONOGRAMU,TYP_SPRZ");
//---------------------------------------------------------------------------
mng::Query __fastcall T_KwMozlWarSprzDM::getQuery(void)
{
 mng::Query _Q(m_Pars.ProcName.IsEmpty() ? M_TABLE : m_Pars.ProcName,M_COL);
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ID_KOMORKI", m_Pars.IdWarsztatu));
   if(m_Pars.Rok >0)         _Q.attachWherePred( new mng::ComparePredicate(" ROK", m_Pars.Rok));
   _Q.setOrderList(M_ORDER);
   _Q.setGroupList(M_GROUP);
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarSprzDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarSprzDM::saveToMdb(const String & _Path)
{
 String _TypSprz;
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_KwMozlWarADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_KwMozlWarADO->Append();
  m_KwMozlWarADO->FieldByName("Id wydzia³u")->AsInteger  = m_Client->FieldByName("ID_WYDZIALU")->AsInteger;
  m_KwMozlWarADO->FieldByName("Kod wydzia³u")->AsString  = m_Client->FieldByName("KOD_WYDZIALU")->AsString;
  m_KwMozlWarADO->FieldByName("Wydzia³")->AsString       = m_Client->FieldByName("NAZ_WYDZIALU")->AsString;
  m_KwMozlWarADO->FieldByName("Id komórki")->AsInteger = m_Client->FieldByName("ID_KOMORKI")->AsInteger;
  m_KwMozlWarADO->FieldByName("Kod warsztatu")->AsString = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
  m_KwMozlWarADO->FieldByName("Warsztat")->AsString      = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;
  m_KwMozlWarADO->FieldByName("Id remontu")->AsInteger   = m_Client->FieldByName("ID_REMONTU")->AsInteger;
  m_KwMozlWarADO->FieldByName("Nazwa remontu")->AsString = m_Client->FieldByName("NAZ_REMONTU")->AsString;
  m_KwMozlWarADO->FieldByName("Typ sprzêtu")->AsString = m_Client->FieldByName("TYP_SPRZ")->AsString;;
  m_KwMozlWarADO->FieldByName("JIM")->AsString  = m_Client->FieldByName("INDEKS_MAT")->AsString;
  m_KwMozlWarADO->FieldByName("Norma RBH")->AsCurrency   = m_Client->FieldByName("NORMA_RBH")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Rodzaj naprawy")->AsString = m_Client->FieldByName("KOD_REM")->AsString;
  m_KwMozlWarADO->FieldByName("Iloœæ")->AsCurrency  = m_Client->FieldByName("ILOSC")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Iloœæ I kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_I")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Iloœæ II kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_II")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Iloœæ III kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_III")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Iloœæ IV kwarta³")->AsCurrency  = m_Client->FieldByName("ILOSC_KW_IV")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Planowane RBH I kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_I")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Planowane RBH II kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_II")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Planowane RBH III kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_III")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Planowane RBH IV kwarta³")->AsCurrency  = m_Client->FieldByName("PLAN_RBH_KW_IV")->AsCurrency;
  m_KwMozlWarADO->FieldByName("Nr harm")->AsInteger = m_Client->FieldByName("ID_HARMONOGRAMU")->AsInteger;


  m_KwMozlWarADO->Post();
  m_Client->Next();
 }
 m_KwMozlWarADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarSprzDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

