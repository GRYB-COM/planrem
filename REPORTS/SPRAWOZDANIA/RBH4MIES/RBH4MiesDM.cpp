//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "RBH4MiesDM.h"
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
__fastcall T_RBH4MiesDM::T_RBH4MiesDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4MiesDM::open(const T_RBH4MiesDM::Pars& _Pars)
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
   _RBHPars.Rok = m_Pars.Rok;
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

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger   =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString  =  _Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString  =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;

	 m_Client->FieldByName("STY")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][1].getSum(msg::rtProd);
	 m_Client->FieldByName("LUT")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][2].getSum(msg::rtProd);
	 m_Client->FieldByName("MAR")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][3].getSum(msg::rtProd);
	 m_Client->FieldByName("KWI")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][4].getSum(msg::rtProd);
	 m_Client->FieldByName("MAJ")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][5].getSum(msg::rtProd);
	 m_Client->FieldByName("CZE")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][6].getSum(msg::rtProd);
	 m_Client->FieldByName("LIP")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][7].getSum(msg::rtProd);
	 m_Client->FieldByName("SIE")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][8].getSum(msg::rtProd);
	 m_Client->FieldByName("WRZE")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][9].getSum(msg::rtProd);
	 m_Client->FieldByName("PAZ")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][10].getSum(msg::rtProd);
	 m_Client->FieldByName("LIS")->AsCurrency    =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][11].getSum(msg::rtProd);
	 m_Client->FieldByName("GRU")->AsCurrency     =  _RBH4War[_Reader.fieldByName("ID_KOMORKI")->AsInteger][12].getSum(msg::rtProd);
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_RBH4MiesDM::getQuery(void)
{
   AnsiString _TableRef("pr_wydzialy wy inner join pr_komorki ko on ko.ID_WYDZIALU = wy.ID_WYDZIALU  LEFT OUTER JOIN pr_osoby os on os.ID_KOMORKI = ko.ID_KOMORKI ");
   AnsiString _ColList("wy.ID_WYDZIALU, wy.KOD AS KOD_WYDZIALU, wy.NAZWA as NAZ_WYDZIALU, ko.ID_KOMORKI, ko.KOD as KOD_KOMORKI, ko.NAZWA as NAZ_KOMORKI,  sum(os.ETAT_PR) AS L_PROD");
   AnsiString _Group("wy.ID_WYDZIALU, wy.KOD, wy.NAZWA , ko.ID_KOMORKI, ko.KOD, ko.NAZWA");
   mng::Query _Q(_TableRef,_ColList);
   _Q.attachWherePred(new mng::ComparePredicate(" ko.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" ko.WARSZTAT "," 'T' "));
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" ko.ID_WARSZTATU", m_Pars.IdWarsztatu));
   _Q.setOrderList(" wy.KOD, ko.KOD ");
   _Q.setGroupList(_Group);
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4MiesDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4MiesDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_RBH4MiesADO->Open();
 m_Client->First();
 while(!m_Client->Eof)
 {
  m_RBH4MiesADO->Append();
   m_RBH4MiesADO->FieldByName("Kod wydzia³u")->AsString               = m_Client->FieldByName("KOD_WYDZIALU")->AsString;
   m_RBH4MiesADO->FieldByName("Nazwa wydzia³u")->AsString             = m_Client->FieldByName("NAZ_WYDZIALU")->AsString;
   m_RBH4MiesADO->FieldByName("Kod warsztatu")->AsString              = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
   m_RBH4MiesADO->FieldByName("Nazwa warsztatu")->AsString            = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;

	m_RBH4MiesADO->FieldByName("Styczeñ")->AsCurrency     = m_Client->FieldByName("STY")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Luty")->AsCurrency        = m_Client->FieldByName("LUT")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Marzec")->AsCurrency      = m_Client->FieldByName("MAR")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Kwiecieñ")->AsCurrency    = m_Client->FieldByName("KWI")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Maj")->AsCurrency         = m_Client->FieldByName("MAJ")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Czerwiec")->AsCurrency    = m_Client->FieldByName("CZE")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Lipiec")->AsCurrency      = m_Client->FieldByName("LIP")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Sierpieñ")->AsCurrency    = m_Client->FieldByName("SIE")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Wrzesieñ")->AsCurrency    = m_Client->FieldByName("WRZE")->AsCurrency;
	m_RBH4MiesADO->FieldByName("PaŸdziernik")->AsCurrency = m_Client->FieldByName("PAZ")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Listopad")->AsCurrency    = m_Client->FieldByName("LIS")->AsCurrency;
	m_RBH4MiesADO->FieldByName("Grudzieñ")->AsCurrency    = m_Client->FieldByName("GRU")->AsCurrency;
  m_RBH4MiesADO->Post();
  m_Client->Next();
 }
 m_RBH4MiesADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_RBH4MiesDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------

