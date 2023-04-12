//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "RBH4OneMiesDM.h"
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
__fastcall T_RBH4OneMiesDM::T_RBH4OneMiesDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OneMiesDM::open(const T_RBH4OneMiesDM::Pars& _Pars)
{
  m_Pars = _Pars;
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
 //PRZYGOTOWANIE READERA RBH
   readers::RBHReader::Pars _RBHPars;
   _RBHPars.AddPlan = false;
   _RBHPars.Rok     = m_Pars.Rok;
   _RBHPars.Miesiac = m_Pars.Miesiac;
   readers::RBHReader _RBHReader;
   msg::RBH4War _RBH4War;
   _RBHReader.read(_RBH4War,_RBHPars);
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger   =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString   =  String(m_Pars.ToMdb ? "":"&#160;") +_Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString   =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;

	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger    =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString    =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString    =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;


	 m_Client->FieldByName("ETAT_PR")->AsCurrency       = _RBH4War.getEtPr(_Reader.fieldByName("ID_KOMORKI")->AsInteger);
	 m_Client->FieldByName("RBH_NOM")->AsCurrency       = _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtNom);
	 m_Client->FieldByName("RBH_URLOP")->AsCurrency     = _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtUr);
	 m_Client->FieldByName("RBH_PRZERWA")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtPrz);
	 m_Client->FieldByName("RBH_CHOROBA")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtCh);
	 m_Client->FieldByName("RBH_SLUZBA")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtSl);
	 m_Client->FieldByName("RBH_SZKOLENIE")->AsCurrency =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtSzk);
	 m_Client->FieldByName("RBH_NPROD")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtNProd);
	 m_Client->FieldByName("RBH_PROD")->AsCurrency      = _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][m_Pars.Miesiac].getSum(msg::rtProd);






	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_RBH4OneMiesDM::getQuery(void)
{
   AnsiString _TableRef("pr_wydzialy wy inner join pr_komorki ko on ko.ID_WYDZIALU = wy.ID_WYDZIALU ");
   AnsiString _ColList(" wy.ID_WYDZIALU, wy.KOD AS KOD_WYDZIALU, wy.NAZWA as NAZ_WYDZIALU,  ko.ID_KOMORKI, ko.KOD as KOD_KOMORKI, ko.NAZWA as NAZ_KOMORKI ");
   mng::Query _Q(_TableRef,_ColList);
   _Q.attachWherePred(new mng::ComparePredicate(" ko.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" ko.WARSZTAT "," 'T' "));
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_KOMORKI", m_Pars.IdWarsztatu));

   _Q.setOrderList(" ko.KOD ");
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OneMiesDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OneMiesDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_RBH4OneMiesADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_RBH4OneMiesADO->Append();
   m_RBH4OneMiesADO->FieldByName("Identyfikator warsztatu")->AsString    = m_Client->FieldByName("ID_WARSZTATU")->AsString;
   m_RBH4OneMiesADO->FieldByName("Kod warsztatu")->AsString              = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
   m_RBH4OneMiesADO->FieldByName("Nazwa warsztatu")->AsString            = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;

   m_RBH4OneMiesADO->FieldByName("Identyfikator wydzia³u")->AsString     = m_Client->FieldByName("ID_WYDZIALU")->AsString;
   m_RBH4OneMiesADO->FieldByName("Kod wydzia³u")->AsString               = m_Client->FieldByName("KOD_WYDZIALU")->AsString;
   m_RBH4OneMiesADO->FieldByName("Nazwa wydzia³u")->AsString             = m_Client->FieldByName("NAZ_WYDZIALU")->AsString;

	 Currency _RbhNom = m_Client->FieldByName("RBH_NOM")->AsCurrency;
	 if(_RbhNom >0)
	 {
	  m_RBH4OneMiesADO->FieldByName("Etat Produkcyjny")->AsCurrency    =  m_Client->FieldByName("ETAT_PR")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("RBH Nominalne")->AsCurrency       =  _RbhNom;
	  m_RBH4OneMiesADO->FieldByName("Urlop")->AsCurrency               =  m_Client->FieldByName("RBH_URLOP")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("Przerwa")->AsCurrency             =  m_Client->FieldByName("RBH_PRZERWA")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("Choroba")->AsCurrency             =  m_Client->FieldByName("RBH_CHOROBA")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("S³u¿ba")->AsCurrency              =  m_Client->FieldByName("RBH_SLUZBA")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("Szkolenie")->AsCurrency           =  m_Client->FieldByName("RBH_SZKOLENIE")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("RBH Nieprodukcyjne")->AsCurrency  =  m_Client->FieldByName("RBH_NPROD")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("RBH Produkcyjne")->AsCurrency     =  m_Client->FieldByName("RBH_PROD")->AsCurrency;
	  m_RBH4OneMiesADO->FieldByName("Miesi¹c")->AsString               =  LongMonthNames[m_Pars.Miesiac-1];
	 }
  m_RBH4OneMiesADO->Post();
  m_Client->Next();
 }
 m_RBH4OneMiesADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4OneMiesDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\RBH4OneMies.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

