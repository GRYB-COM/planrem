//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "PotrzRemDM.h"
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
__fastcall T_PotrzRemDM::T_PotrzRemDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_PotrzRemDM::open(const T_PotrzRemDM::Pars& _Pars)
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

	 m_Client->FieldByName("ID_WARSZTATU")->AsInteger  =  _Reader.fieldByName("ID_KOMORKI")->AsInteger;
	 m_Client->FieldByName("KOD_WARSZTATU")->AsString  =  _Reader.fieldByName("KOD_KOMORKI")->AsString;
	 m_Client->FieldByName("NAZ_WARSZTATU")->AsString  =  _Reader.fieldByName("NAZ_KOMORKI")->AsString;

	 m_Client->FieldByName("JW")->AsString             =  _Reader.fieldByName("JW")->AsString.Trim() + String(" ") + _Reader.fieldByName("JW_MIASTO")->AsString.Trim();
	 m_Client->FieldByName("ZADANIE")->AsString        =  _Reader.fieldByName("ZADANIE")->AsString.Trim();
	 m_Client->FieldByName("NAZ_SPRZ")->AsString       =  _Reader.fieldByName("NAZ_SPRZ")->AsString.Trim();
	 m_Client->FieldByName("ILOSC")->AsCurrency        =  _Reader.fieldByName("ILOSC")->AsCurrency;
	 m_Client->FieldByName("NORMA_RBH")->AsCurrency    =  _Reader.fieldByName("NORMA_RBH")->AsCurrency;
	 m_Client->FieldByName("ILOSC_RBH")->AsCurrency    =  _Reader.fieldByName("ILOSC_RBH")->AsCurrency;
	m_Client->Post();
	_Reader.next();
   }
 //SPRZ¥TANIE
  _Reader.close();
}
//---------------------------------------------------------------------------
mng::Query __fastcall T_PotrzRemDM::getQuery(void)
{
   AnsiString _TableRef("PR_HARMONOGRAM H LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU LEFT OUTER JOIN PR_HARMONOGRAM_DET HD ON HD.ROK = H.ROK AND HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU");
   AnsiString _ColList("K.ID_KOMORKI, K.KOD AS KOD_KOMORKI, K.NAZWA AS NAZ_KOMORKI, J.JW, J.MIEJSCOWOSC AS JW_MIASTO, S.NAZWA AS NAZ_SPRZ , H.ZADANIE, SUM(HD.ILOSC) AS ILOSC,   H.NORMA_RBH,  SUM(HD.PLAN_RBH) AS ILOSC_RBH");
   AnsiString _Group("K.ID_KOMORKI, K.KOD, K.NAZWA , J.JW, J.MIEJSCOWOSC, S.NAZWA , H.ZADANIE, H.NORMA_RBH");
   mng::Query _Q(_TableRef,_ColList);
   _Q.attachWherePred(new mng::ComparePredicate(" k.KOD "," '0/0' ", mng::ComparePredicate::copNotEqual) );
   _Q.attachWherePred(new mng::ComparePredicate(" k.WARSZTAT "," 'T' "));
   if(m_Pars.IdWydzialu >0)  _Q.attachWherePred( new mng::ComparePredicate(" k.ID_WYDZIALU", m_Pars.IdWydzialu));
   if(m_Pars.IdWarsztatu >0) _Q.attachWherePred( new mng::ComparePredicate(" k.ID_WARSZTATU", m_Pars.IdWarsztatu));
   if(m_Pars.Rok >0)         _Q.attachWherePred( new mng::ComparePredicate(" H.ROK", m_Pars.Rok));
   _Q.setGroupList(_Group);
 return _Q;
}
//---------------------------------------------------------------------------
void __fastcall T_PotrzRemDM::close(void)
{
 m_Client->EmptyDataSet();
 m_Client->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PotrzRemDM::saveToMdb(const String & _Path)
{
 setMdbPath(_Path);
 m_WorkADO->ExecSQL();
 m_PotrzRemADO->Open();
 m_Client->First();
 int i(0);
 String Buff;
 while(!m_Client->Eof)
 {
  try
  {
  i =    m_Client->RecNo;
  m_PotrzRemADO->Append();

   m_PotrzRemADO->FieldByName("Kod warsztatu")->AsString              = m_Client->FieldByName("KOD_WARSZTATU")->AsString;
   m_PotrzRemADO->FieldByName("Nazwa warsztatu")->AsString            = m_Client->FieldByName("NAZ_WARSZTATU")->AsString;
   m_PotrzRemADO->FieldByName("JW")->AsString = m_Client->FieldByName("JW")->AsString;

   Buff =m_Client->FieldByName("NAZ_SPRZ")->AsString.Trim() ;
   if(!Buff.IsEmpty() ) Buff += String(" / ");
   Buff += m_Client->FieldByName("ZADANIE")->AsString.Trim();
   m_PotrzRemADO->FieldByName("Nazwa sprzêtu/zadanie")->AsString      = Buff;
   m_PotrzRemADO->FieldByName("Iloœæ")->AsCurrency    = m_Client->FieldByName("ILOSC")->AsCurrency;
   m_PotrzRemADO->FieldByName("Norma RBH")->AsCurrency      = m_Client->FieldByName("NORMA_RBH")->AsCurrency;
   m_PotrzRemADO->FieldByName("Iloœæ RBH")->AsCurrency      = m_Client->FieldByName("ILOSC_RBH")->AsCurrency;
  m_PotrzRemADO->Post();
  m_Client->Next();
 }
 catch(...)
 {
  Buff += String("Nr rec: ") +i;
 }
 }
 m_PotrzRemADO->Close();
}
//---------------------------------------------------------------------------
void __fastcall T_PotrzRemDM::setMdbPath(const WideString& __Path)
{
 WideString _Path(__Path);
 if(_Path.IsEmpty()) _Path = ExtractFileDir(Application->ExeName) + "\\MDB\\spr.mdb";
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Mode=ReadWrite;Persist Security Info=False");
m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------


