//---------------------------------------------------------------------------
#pragma hdrstop
#include "HarmFinder.h"
#include "SGTOOLS\DATAACCESS\DAREader.h"
#include "MANAGER\queries.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
HarmFinder::Pars::Pars(void)
:IdHarmonogramu(-1),
 Rok(-1),
 IdWydzialu(-1)
{

}
//---------------------------------------------------------------------------
HarmFinder::HarmFinder(void)
{
 m_HarmDAR = new sgda::DAReader(sgda::ctStreamDB);
}
//---------------------------------------------------------------------------
HarmFinder::~HarmFinder(void)
{
 delete m_HarmDAR;
}
//---------------------------------------------------------------------------
TDataSet* HarmFinder::getDataSet(void)
{
	return m_HarmDAR->getDataSet();
}
//---------------------------------------------------------------------------
int HarmFinder::getRecordCount(void)
{
 return  m_HarmDAR->getRecordCount();
}
//---------------------------------------------------------------------------
const String HarmFinder::M_COL_LIST_SQL("\
H.ID_HARMONOGRAMU, \
CAST( H.ID_HARMONOGRAMU AS VARCHAR(10) ) AS ID_HARM_STR, \
CASE WHEN S.NAZWA IS NULL THEN '' ELSE S.NAZWA END || \
CASE WHEN H.ZADANIE IS NULL THEN '' ELSE ' '||H.ZADANIE END AS SPRZ_ZAD,  \
H.NR_ZADANIA AS PODSTAWA,  \
J.JW || ' ' || J.MIEJSCOWOSC AS DOSTAWCA,  \
K.KOD AS WARSZTAT  \
");
//---------------------------------------------------------------------------
const String HarmFinder::M_TABLE_REF_SQL("\
pr_harmonogram h \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI \
LEFT OUTER JOIN PR_SPRZET    S ON S.ID_SPRZETU   = H.ID_SPRZETU  \
LEFT OUTER JOIN PR_KOMORKI   K ON K.ID_KOMORKI   = H.ID_KOMORKI \
");
//---------------------------------------------------------------------------
void HarmFinder::open(const HarmFinder::Pars& _Pars)
{
 m_Pars = _Pars;
 mng::Query _Q(M_TABLE_REF_SQL, M_COL_LIST_SQL);
 _Q.setOrderList(" H.ID_HARMONOGRAMU ");
 if(_Pars.Rok >0)        _Q.attachWherePred( new mng::ComparePredicate(" H.ROK ",         _Pars.Rok) );
 if(_Pars.IdWydzialu >0) _Q.attachWherePred( new mng::ComparePredicate(" K.ID_WYDZIALU ", _Pars.IdWydzialu) );
 m_HarmDAR->setQuery(_Q);
 m_HarmDAR->open();
}
//---------------------------------------------------------------------------
int HarmFinder::getCurrHarm(void)
{
 int _ID(-1);
 if(m_HarmDAR->getDataSet()->Active && !m_HarmDAR->getDataSet()->IsEmpty() )
 {
  _ID = m_HarmDAR->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 }
 return _ID;
}
//---------------------------------------------------------------------------
void HarmFinder::close(void)
{
  m_HarmDAR->close();
}
//---------------------------------------------------------------------------

