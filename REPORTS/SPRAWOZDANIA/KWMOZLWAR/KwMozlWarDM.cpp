//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "KwMozlWarDM.h"
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
__fastcall T_KwMozlWarDM::T_KwMozlWarDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarDM::open(const T_KwMozlWarDM::Pars& _Pars)
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
   readers::RBHReader _RBHReader;
   msg::RBH4War _RBH4War;
   _RBHReader.read(_RBH4War,_RBHPars);
 //PÊTLA WPISUJ¥CA DO KLIENTA
   if(! m_Client->Active) m_Client->CreateDataSet();
   while(!_Reader.isEof())
   {
	 m_Client->Append();
	 m_Client->FieldByName("ID_WYDZIALU")->AsInteger     =  _Reader.fieldByName("ID_WYDZIALU")->AsInteger;
	 m_Client->FieldByName("KOD_WYDZIALU")->AsString     =  _Reader.fieldByName("KOD_WYDZIALU")->AsString;
	 m_Client->FieldByName("NAZ_WYDZIALU")->AsString     =  _Reader.fieldByName("NAZ_WYDZIALU")->AsString;

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger    =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString    =  _Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString    =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;
     m_Client->FieldByName("L_PROD")->AsCurrency         =  _Reader.fieldByName("L_PROD")->AsCurrency;
	 m_Client->FieldByName("RBH_NOM_I")->AsCurrency      =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"",1,3);
	 m_Client->FieldByName("RBH_NOM_II")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"",4,6);
	 m_Client->FieldByName("RBH_NOM_III")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"",7,9);
	 m_Client->FieldByName("RBH_NOM_IV")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom,"",10,12);
	 m_Client->FieldByName("RBH_NOM_R")->AsCurrency      =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNom);
	 m_Client->FieldByName("RBH_PROD_I")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"",1,3);
	 m_Client->FieldByName("RBH_PROD_II")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"",4,6);
	 m_Client->FieldByName("RBH_PROD_III")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"",7,9);
	 m_Client->FieldByName("RBH_PROD_IV")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd,"",10,12);
	 m_Client->FieldByName("RBH_PROD_R")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtProd);
	 m_Client->FieldByName("RBH_NPROD_I")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"",1,3);
	 m_Client->FieldByName("RBH_NPROD_II")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"",4,6);
	 m_Client->FieldByName("RBH_NPROD_III")->AsCurrency  =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"",7,9);
	 m_Client->FieldByName("RBH_NPROD_IV")->AsCurrency   =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd,"",10,12);
	 m_Client->FieldByName("RBH_NPROD_R")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtNProd);
	 m_Client->FieldByName("RBH_EF_I")->AsCurrency       =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"",1,3);
	 m_Client->FieldByName("RBH_EF_II")->AsCurrency      =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"",4,6);
	 m_Client->FieldByName("RBH_EF_III")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"",7,9);
	 m_Client->FieldByName("RBH_EF_IV")->AsCurrency      =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf,"",10,12);
	 m_Client->FieldByName("RBH_EF_R")->AsCurrency       =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger].getSum(msg::rtEf);
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_KwMozlWarDM::getQuery(void)
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
void __fastcall T_KwMozlWarDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_KwMozlWarADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_KwMozlWarADO->Append();
  m_KwMozlWarADO->FieldByName("Identyfikator warsztatu")->AsInteger    = m_Client->FieldByName("ID_WARSZTATU")->AsInteger;
  m_KwMozlWarADO->FieldByName("Kod warsztatu")->AsString    = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
  m_KwMozlWarADO->FieldByName("Nazwa warsztatu")->AsString  = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;

	m_KwMozlWarADO->FieldByName("Fundusz nominalny I kw")->AsCurrency   = m_Client->FieldByName("RBH_NOM_I")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nominalny II kw")->AsCurrency  = m_Client->FieldByName("RBH_NOM_II")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nominalny III kw")->AsCurrency = m_Client->FieldByName("RBH_NOM_III")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nominalny IV kw")->AsCurrency  = m_Client->FieldByName("RBH_NOM_IV")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nominalny")->AsCurrency        = m_Client->FieldByName("RBH_NOM_R")->AsCurrency;

	m_KwMozlWarADO->FieldByName("Fundusz nieprodukcyjny I kw")->AsCurrency   = m_Client->FieldByName("RBH_NPROD_I")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nieprodukcyjny II kw")->AsCurrency  = m_Client->FieldByName("RBH_NPROD_II")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nieprodukcyjny III kw")->AsCurrency = m_Client->FieldByName("RBH_NPROD_III")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nieprodukcyjny IV kw")->AsCurrency  = m_Client->FieldByName("RBH_NPROD_IV")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz nieprodukcyjny")->AsCurrency        = m_Client->FieldByName("RBH_NPROD_R")->AsCurrency;

	m_KwMozlWarADO->FieldByName("Fundusz produkcyjny I kw")->AsCurrency   = m_Client->FieldByName("RBH_PROD_I")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz produkcyjny II kw")->AsCurrency  = m_Client->FieldByName("RBH_PROD_II")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz produkcyjny III kw")->AsCurrency = m_Client->FieldByName("RBH_PROD_III")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz produkcyjny IV kw")->AsCurrency  = m_Client->FieldByName("RBH_PROD_IV")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz produkcyjny")->AsCurrency        = m_Client->FieldByName("RBH_PROD_R")->AsCurrency;

	m_KwMozlWarADO->FieldByName("Fundusz efektywny I kw")->AsCurrency   = m_Client->FieldByName("RBH_EF_I")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz efektywny II kw")->AsCurrency  = m_Client->FieldByName("RBH_EF_II")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz efektywny III kw")->AsCurrency = m_Client->FieldByName("RBH_EF_III")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz efektywny IV kw")->AsCurrency  = m_Client->FieldByName("RBH_EF_IV")->AsCurrency;
	m_KwMozlWarADO->FieldByName("Fundusz efektywny")->AsCurrency        = m_Client->FieldByName("RBH_EF_R")->AsCurrency;



  m_KwMozlWarADO->Post();
  m_Client->Next();
 }
 m_KwMozlWarADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KwMozlWarDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

