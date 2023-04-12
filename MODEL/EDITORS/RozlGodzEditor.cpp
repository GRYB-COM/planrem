//---------------------------------------------------------------------------
#pragma hdrstop
#include "RozlGodzEditor.h"
#pragma package(smart_init)
#include "MANAGER\query_db.h"
#include "MANAGER\STREAM_db.h"
#include "model_readers_RBHReader.h"
#include "model_messengers_RBH4War.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
using namespace editors;
//---------------------------------------------------------------------------
RozlGodzEditor& RozlGodzEditor::instance(void)
{
  static RozlGodzEditor _Item;
  return _Item;
}
//---------------------------------------------------------------------------
RozlGodzEditor::Pars::Pars(void)
:IdKomorki(-1),
Rok(YearOf(Date()))
{

}
//---------------------------------------------------------------------------
RozlGodzEditor::RozlGodzEditor(void)
{

}
//---------------------------------------------------------------------------
RozlGodzEditor::~RozlGodzEditor(void)
{

}
//---------------------------------------------------------------------------
void RozlGodzEditor::run(const Pars& _Pars)
{
 //SPRZ¥TANIE PO POPRZEDNIE SESJI
   mng::QueryDB().execute("DELETE FROM PR_ROZL_GODZIN");
 //PRZYGOTOWANIE READERA
   readers::RBHReader::Pars _RBHPars;
   _RBHPars.AddPlan = false;
   _RBHPars.Rok     = _Pars.Rok;
   readers::RBHReader _RBHReader;
   msg::RBH4War _RBH4War;
 //ZAPIS DO BAZY
	mng::StreamDB _RozlGodzSDB, _KomSDB;
   _RozlGodzSDB.open("SELECT * FROM PR_ROZL_GODZIN");
   _KomSDB.setQuery("select * from pr_komorki where (:ID_KOMORKI < 0 OR ID_KOMORKI = :ID_KOMORKI) AND WARSZTAT='T'  and kod not in ('0/0','-1/-1')  order by kod");
   _KomSDB.paramByName("ID_KOMORKI")->AsInteger = _Pars.IdKomorki;
   _KomSDB.open();
   int _Id(1);
   while(!_KomSDB.isEof())
   {
	for(int _Mies=1; _Mies <=12; ++_Mies)
	{
	 _RBH4War.clear();
	 _RBHPars.IdKomorki = _KomSDB.fieldByName("ID_KOMORKI")->AsInteger;
	 _RBHPars.Miesiac   = _Mies;
	 _RBHReader.read(_RBH4War,_RBHPars);
	 _RozlGodzSDB.append();
	 _RozlGodzSDB.fieldByName("ID")->AsInteger         = ++_Id;
	 _RozlGodzSDB.fieldByName("ID_KOMORKI")->AsInteger = _RBHPars.IdKomorki;
	 _RozlGodzSDB.fieldByName("MIESIAC")->AsInteger    = _Mies;
	 _RozlGodzSDB.fieldByName("ETAT_PR")->AsCurrency   = _RBH4War.getEtPr(_KomSDB.fieldByName("ID_KOMORKI")->AsInteger);
	 _RozlGodzSDB.fieldByName("RBH_NOM")->AsCurrency   = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtNom);
	 _RozlGodzSDB.fieldByName("URLOP")->AsCurrency     = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtUr);
	 _RozlGodzSDB.fieldByName("PRZERWA")->AsCurrency   = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtPrz);
	 _RozlGodzSDB.fieldByName("CHOROBA")->AsCurrency   = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtCh);
	 _RozlGodzSDB.fieldByName("SLUZBA")->AsCurrency    = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtSl);
	 _RozlGodzSDB.fieldByName("SZKOLENIE")->AsCurrency = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtSzk);
	 _RozlGodzSDB.fieldByName("RBH_NPROD")->AsCurrency = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtNProd);
	 _RozlGodzSDB.fieldByName("RBH_PROD")->AsCurrency  = _RBH4War[_KomSDB.fieldByName("ID_KOMORKI")->AsInteger][_Mies].getSum(msg::rtProd);
	 _RozlGodzSDB.post();
	}
	_KomSDB.next();
   }
   _RozlGodzSDB.applyUpdates();

}

