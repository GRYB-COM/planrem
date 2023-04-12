//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "BilMozlProdDM.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\queries.h"
#include "model_readers_RBHReader.h"
#include "model_messengers_RBH4War.h"
#include "MANAGER\query_db.h"
#include <isvaria.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_BilMozlProdDM::T_BilMozlProdDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_BilMozlProdDM::open(const T_BilMozlProdDM::Pars& _Pars)
{
  m_Pars = _Pars;
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
 //PRZYGOTOWANIE READERA RBH
   readers::RBHReader::Pars _RBHPars;
   _RBHPars.Rok = m_Pars.Rok;
   _RBHPars.AddPlan = false;
   _RBHPars.IdKomorki = m_Pars.IdWarsztatu;
   readers::RBHReader _RBHReader;
   msg::RBH4War _RBH4War;
   _RBHReader.read(_RBH4War,_RBHPars);
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();
	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger      =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString      =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString      =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger     =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString     =  _Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString     =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;

	 m_Client->FieldByName("L_CYWIL")->AsCurrency         =  _Reader.fieldByName("L_CYWIL")->AsCurrency;
	 m_Client->FieldByName("L_KADRA")->AsCurrency         =  _Reader.fieldByName("L_KADRA")->AsCurrency;
	 m_Client->FieldByName("L_PROD_CYWIL")->AsCurrency    =  _Reader.fieldByName("L_PROD_CYWIL")->AsCurrency;
	 m_Client->FieldByName("L_PROD_KADRA")->AsCurrency    =  _Reader.fieldByName("L_PROD_KADRA")->AsCurrency;
	 m_Client->FieldByName("RBH_NOM_CYWIL")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"c",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_NOM_KADRA")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"k",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_PROD_CYWIL")->AsCurrency  =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"c",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_PROD_KADRA")->AsCurrency  =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"k",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_NPROD_CYWIL")->AsCurrency =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"c",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_NPROD_KADRA")->AsCurrency =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"k",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_EF_CYWIL")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"c",m_Pars.MiesOd,m_Pars.MiesDo);
	 m_Client->FieldByName("RBH_EF_KADRA")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"k",m_Pars.MiesOd,m_Pars.MiesDo);
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_BilMozlProdDM::getQuery(void)
{
   mng::Query _Q(M_TABLE_REF_SQL,M_COL_LIST_SQL);
   _Q.attachWherePred(new mng::ComparePredicate(" ko.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" ko.WARSZTAT "," 'T' "));
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_KOMORKI", m_Pars.IdWarsztatu));
   _Q.setOrderList(" wy.KOD, ko.KOD ");
   _Q.setGroupList(M_GROUP_LIST_SQL);
 return _Q;
}
//---------------------------------------------------------------------------
const AnsiString T_BilMozlProdDM::M_COL_LIST_SQL("\
wy.ID_WYDZIALU, wy.KOD AS KOD_WYDZIALU, wy.NAZWA as NAZ_WYDZIALU, ko.ID_KOMORKI, ko.KOD as KOD_KOMORKI, ko.NAZWA as NAZ_KOMORKI, \
 count(case when os.KADRA ='c' then os.kadra else null end) AS L_CYWIL, \
 count(case when os.KADRA <>'c' then os.kadra else null end) AS L_KADRA, \
 sum(case when os.KADRA ='c' then  os.ETAT_PR ELSE 0.0 END ) AS L_PROD_CYWIL, \
 sum(case when os.KADRA <>'c' then  os.ETAT_PR ELSE 0.0 END ) AS L_PROD_KADRA\
 ");
//---------------------------------------------------------------------------
const AnsiString T_BilMozlProdDM::M_TABLE_REF_SQL("\
pr_wydzialy wy inner join pr_komorki ko on ko.ID_WYDZIALU = wy.ID_WYDZIALU  LEFT OUTER JOIN pr_osoby os on os.ID_KOMORKI = ko.ID_KOMORKI \
");
//---------------------------------------------------------------------------
const AnsiString T_BilMozlProdDM::M_GROUP_LIST_SQL(" wy.ID_WYDZIALU, wy.KOD, wy.NAZWA , ko.ID_KOMORKI, ko.KOD, ko.NAZWA ");
//---------------------------------------------------------------------------
void __fastcall T_BilMozlProdDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_BilMozlProdDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 saveParsToMdb();
 m_WorkADO->ExecSQL();
 m_MozlRemADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_MozlRemADO->Append();
   m_MozlRemADO->FieldByName("Kod wydzia³u")->AsString                  = m_ClientKOD_WYDZIALU->AsString;
   m_MozlRemADO->FieldByName("Nazwa wydzia³u")->AsString                = m_ClientNAZ_WYDZIALU->AsString;
   m_MozlRemADO->FieldByName("Kod warsztatu")->AsString                 = m_ClientKOD_WARSZTATU->AsString;
   m_MozlRemADO->FieldByName("Nazwa warsztatu")->AsString               = m_ClientNAZ_WARSZTATU->AsString;

   m_MozlRemADO->FieldByName("Pracownicy wojska")->AsCurrency            = m_ClientL_PROD_CYWIL->AsCurrency;
   m_MozlRemADO->FieldByName("Kadra")->AsCurrency                        = m_ClientL_PROD_KADRA->AsCurrency;

   m_MozlRemADO->FieldByName("Pracownicy wojska RBH nom")->AsCurrency   = m_ClientRBH_NOM_CYWIL->AsCurrency;
   m_MozlRemADO->FieldByName("Kadra RBH nom")->AsCurrency               = m_ClientRBH_NOM_KADRA->AsCurrency;
   m_MozlRemADO->FieldByName("Razem nom")->AsCurrency                   = m_ClientRBH_NOM_RAZEM->AsCurrency;

   m_MozlRemADO->FieldByName("Pracownicy wojska RBH nprod")->AsCurrency   = m_ClientRBH_NPROD_CYWIL->AsCurrency;
   m_MozlRemADO->FieldByName("Kadra RBH nprod")->AsCurrency               = m_ClientRBH_NPROD_KADRA->AsCurrency;
   m_MozlRemADO->FieldByName("Razem nprod")->AsCurrency                   = m_ClientRBH_NPROD_RAZEM->AsCurrency;

   m_MozlRemADO->FieldByName("Razem prod")->AsCurrency                    = m_ClientRBH_PROD_RAZEM->AsCurrency;

  m_MozlRemADO->Post();
  m_Client->Next();
 }
}
//---------------------------------------------------------------------------
void __fastcall T_BilMozlProdDM::saveParsToMdb(void)
{
 double _LKadra = m_Client->FieldByName("L_KADRA_SUM")->AsString.ToIntDef(0);
 double _LCywil = m_Client->FieldByName("L_CYWIL_SUM")->AsString.ToIntDef(0);
 double _RBHK(0);
 if(!m_Client->FieldByName("RBH_NPROD_KADRA_SUM")->Value.IsNull())
 {
   _RBHK = m_Client->FieldByName("RBH_NPROD_KADRA_SUM")->Value;
 }
 double _RBHC(0);
 if(! m_Client->FieldByName("RBH_NPROD_CYWIL_SUM")->Value.IsNull())
 {
  _RBHC = m_Client->FieldByName("RBH_NPROD_CYWIL_SUM")->Value;
 }
 if(_RBHK ==0 || _LKadra ==0) _RBHK =0;
 else  _RBHK = _RBHK/_LKadra;
 if(_RBHC ==0 || _LCywil ==0) _RBHC =0;
 else  _RBHC = _RBHC/_LCywil;
 mng::QueryDB _Q("SELECT * FROM PR_MIES4RBH WHERE NR_MIES =0 AND ROK =:ROK");
 _Q.paramByName("ROK")->AsInteger = m_Pars.Rok;
 _Q.open();
 m_MozlRemADO->Close();
 m_MozlRemParADO->Open();
 m_MozlRemParADO->IsEmpty() ? m_MozlRemParADO->Append() : m_MozlRemParADO->Edit();
  m_MozlRemParADO->FieldByName("Mies od")->AsInteger            =  m_Pars.MiesOd;
  m_MozlRemParADO->FieldByName("Nazwa miesi¹ca od")->AsString   =  LongMonthNames[m_Pars.MiesOd -1];
  m_MozlRemParADO->FieldByName("Mies do")->AsInteger            =  m_Pars.MiesDo;
  m_MozlRemParADO->FieldByName("Nazwa miesi¹ca do")->AsString   =  LongMonthNames[m_Pars.MiesDo -1];
  m_MozlRemParADO->FieldByName("Tytu³")->AsString               =  getTytul();
  m_MozlRemParADO->FieldByName("Podtytu³")->AsString            =  getPodTytul();
  m_MozlRemParADO->FieldByName("Liczba dni")->AsInteger         = _Q.fieldByName("DNI_ROB")->AsInteger;
  m_MozlRemParADO->FieldByName("Liczba godzin")->AsInteger      = 8;
  m_MozlRemParADO->FieldByName("RBH kadra")->AsCurrency         =  ISRound(_RBHK,2) ;
  m_MozlRemParADO->FieldByName("RBH cywil")->AsCurrency         =  ISRound(_RBHC,2);
 m_MozlRemParADO->Post();
 m_MozlRemParADO->Close();
}
//---------------------------------------------------------------------------
String __fastcall T_BilMozlProdDM::getTytul(void)
{
  String _Res;
  int _Kw(getKwartal());
  if(_Kw == 5)
  {
   _Res = "ROCZNY PLAN ZADAÑ PRODUKCYJNYCH I OBS£UGOWO - REMONTOWYCH ";
  }
  else if(_Kw >0)
  {
   _Res = "KWARTALNY PLAN ZADAÑ PRODUKCYJNYCH I OBS£UGOWO - REMONTOWYCH ";
  }
  else
  {
   _Res = "MIESIÊCZNY PLAN ZADAÑ PRODUKCYJNYCH I OBS£UGOWO - REMONTOWYCH ";
  }
 return _Res;
}
//---------------------------------------------------------------------------
String __fastcall T_BilMozlProdDM::getPodTytul(void)
{
 int _Kwart = getKwartal();
 String _Res;
 if(_Kwart  >0 && _Kwart < 5)
 {
  _Res = String("KWARTA£ ") + getKwartal(_Kwart);
 }
 else if(_Kwart == 0)
 {
  _Res = String("MIESI¥CE OD ") + LongMonthNames[m_Pars.MiesOd -1].UpperCase() + String(" DO ") + LongMonthNames[m_Pars.MiesDo -1].UpperCase();
 }

  return _Res;
}
//---------------------------------------------------------------------------
int __fastcall T_BilMozlProdDM::getKwartal(void)
{
 int _Res(0);
	  if(m_Pars.MiesOd ==1  && m_Pars.MiesDo == 3)   _Res = 1;
 else if(m_Pars.MiesOd ==4  && m_Pars.MiesDo == 6)   _Res = 2;
 else if(m_Pars.MiesOd ==7  && m_Pars.MiesDo == 9)   _Res = 3;
 else if(m_Pars.MiesOd ==10 && m_Pars.MiesDo == 12)  _Res = 4;
 else if(m_Pars.MiesOd ==1  && m_Pars.MiesDo == 12)  _Res = 5;
 return _Res;
}
//---------------------------------------------------------------------------
String __fastcall T_BilMozlProdDM::getKwartal(const int _Nr)
{
  String _Res;
  switch(_Nr)
  {
	case 1 : _Res = "I";  break;
	case 2 : _Res = "II";  break;
	case 3 : _Res = "III";  break;
	case 4 : _Res = "IV";  break;
  }
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall T_BilMozlProdDM::setMdbPath(const WideString& __Path)
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

void __fastcall T_BilMozlProdDM::m_ClientCalcFields(TDataSet *DataSet)
{
 m_ClientRBH_NOM_RAZEM->AsCurrency   = m_ClientRBH_NOM_CYWIL->AsCurrency   + m_ClientRBH_NOM_KADRA->AsCurrency;
 m_ClientRBH_NPROD_RAZEM->AsCurrency = m_ClientRBH_NPROD_CYWIL->AsCurrency + m_ClientRBH_NPROD_KADRA->AsCurrency;
 m_ClientRBH_PROD_RAZEM->AsCurrency  = m_ClientRBH_NOM_RAZEM->AsCurrency   - m_ClientRBH_NPROD_RAZEM->AsCurrency;

}
//---------------------------------------------------------------------------

