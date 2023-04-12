//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MozlRemDM.h"
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
__fastcall T_MozlRemDM::T_MozlRemDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_MozlRemDM::open(const T_MozlRemDM::Pars& _Pars)
{
  m_Pars = _Pars;
 //PRZYGOTOWANIE READERA
   mng::Query _Q(getQuery());
   sgda::DAReader _Reader(sgda::ctQueryDB);
   _Reader.setQuery(_Q);
   _Reader.open();
 //PRZYGOTOWANIE READERA RBH
   readers::RBHReader::Pars _RBHPars;
   _RBHPars.Rok      = m_Pars.Rok;
   _RBHPars.AddPlan  = false;
   _RBHPars.Rok      = m_Pars.Rok;
   _RBHPars.IdKomorki = m_Pars.IdWarsztatu;
   readers::RBHReader _RBHReader;
   msg::RBH4War _RBH4War;
   _RBHReader.read(_RBH4War,_RBHPars);
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();
	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger   =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString   =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString   =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger  =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString  =  _Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString  =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;

	 m_Client->FieldByName("L_PROD")->AsCurrency       =  _RBH4War.getEtPr(_Reader.fieldByName("ID_KOMORKI")->AsInteger);
	 m_Client->FieldByName("RBH_NOM")->AsCurrency      =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom);
	 m_Client->FieldByName("RBH_PROD")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd);
	 m_Client->FieldByName("RBH_NPROD")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd);
	 m_Client->FieldByName("RBH_EF")->AsCurrency       =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf);
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_MozlRemDM::getQuery(void)
{
   AnsiString _TableRef("pr_wydzialy wy inner join pr_komorki ko on ko.ID_WYDZIALU = wy.ID_WYDZIALU  LEFT OUTER JOIN pr_osoby os on os.ID_KOMORKI = ko.ID_KOMORKI ");
   AnsiString _ColList("wy.ID_WYDZIALU, wy.KOD AS KOD_WYDZIALU, wy.NAZWA as NAZ_WYDZIALU, ko.ID_KOMORKI, ko.KOD as KOD_KOMORKI, ko.NAZWA as NAZ_KOMORKI,  sum(os.ETAT_PR) AS L_PROD");
   AnsiString _Group("wy.ID_WYDZIALU, wy.KOD, wy.NAZWA , ko.ID_KOMORKI, ko.KOD, ko.NAZWA");
   mng::Query _Q(_TableRef,_ColList);
   _Q.attachWherePred(new mng::ComparePredicate(" ko.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" ko.WARSZTAT "," 'T' "));
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_KOMORKI", m_Pars.IdWarsztatu));
   _Q.setOrderList(" wy.KOD, ko.KOD ");
   _Q.setGroupList(_Group);
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_MozlRemDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_MozlRemDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_MozlRemADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_MozlRemADO->Append();
   m_MozlRemADO->FieldByName("Kod wydzia³u")->AsString               = m_Client->FieldByName("KOD_WYDZIALU")->AsString;
   m_MozlRemADO->FieldByName("Nazwa wydzia³u")->AsString             = m_Client->FieldByName("NAZ_WYDZIALU")->AsString;
   m_MozlRemADO->FieldByName("Kod warsztatu")->AsString              = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
   m_MozlRemADO->FieldByName("Nazwa warsztatu")->AsString            = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;

	m_MozlRemADO->FieldByName("Pracownicy produkcyjni")->AsCurrency = m_Client->FieldByName("L_PROD")->AsCurrency;
	m_MozlRemADO->FieldByName("Fundusz nominalny")->AsCurrency      = m_Client->FieldByName("RBH_NOM")->AsCurrency;
	m_MozlRemADO->FieldByName("Fundusz nieprodukcyjny")->AsCurrency = m_Client->FieldByName("RBH_NPROD")->AsCurrency;
	m_MozlRemADO->FieldByName("Fundusz produkcyjny")->AsCurrency    = m_Client->FieldByName("RBH_PROD")->AsCurrency;
	m_MozlRemADO->FieldByName("Fundusz efektywny")->AsCurrency      = m_Client->FieldByName("RBH_PROD")->AsCurrency; //m_Client->FieldByName("RBH_EF")->AsCurrency;
  m_MozlRemADO->Post();
  m_Client->Next();
 }
 m_MozlRemADO->Close();
 m_MozlRemParsADO->Open();
 m_MozlRemParsADO->IsEmpty() ?  m_MozlRemParsADO->Append() : m_MozlRemParsADO->Edit();
 m_MozlRemParsADO->FieldByName("ROK")->AsInteger = m_Pars.Rok;
 m_MozlRemParsADO->Post();
 m_MozlRemParsADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_MozlRemDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

