//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprzetFinder.h"
#include "SGTOOLS\DATAACCESS\DAREader.h"
#include "MANAGER\queries.h"
#include "MagID.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
SprzetFinder::Pars::Pars(void)
:Rok(-1),
 IdWydzialu(-1)
{

}
//---------------------------------------------------------------------------
SprzetFinder::SprzetFinder(void)
{
 m_SprzetDAR = new sgda::DAReader(sgda::ctStreamDB);
}
//---------------------------------------------------------------------------
SprzetFinder::~SprzetFinder(void)
{
 delete m_SprzetDAR;
}
//---------------------------------------------------------------------------
TDataSet* SprzetFinder::getDataSet(void)
{
	return m_SprzetDAR->getDataSet();
}
//---------------------------------------------------------------------------
int SprzetFinder::getRecordCount(void)
{
 return  m_SprzetDAR->getRecordCount();
}
//---------------------------------------------------------------------------
void SprzetFinder::open(const SprzetFinder::Pars& _Pars)
{
 String _ColList("  w.KOD AS KOD_WARSZTATU, m.SYGN_MAG || '/' || WY.KOD AS SYGN_MAG,   ");
		_ColList+=("  m.*, s.*, j.JW || ' ' || j.MIEJSCOWOSC AS JW_MIEJSCOWOSC, wy.KOD as KOD_WYDZIALU, ");
		_ColList+=("  m.NR_FABR, m.NR_REJ,");
		_ColList+=("  cast(m.ILOSC as varchar(20)) as ILOSC_STR, ");
		_ColList+=("  cast(m.ID_HARM as varchar(6)) as ID_HARM_STR, ");
		_ColList+=("  (SELECT RES FROM PR_KOM4ZLEC(M.ROK,M.ID_KOMORKI,M.DEPOZYT,M.ID_MAG) ) AS KODY_WARSZTATOW " );
 String _TRef(" pr_magazyn m left outer join pr_sprzet s  on (s.ID_SPRZETU = m.ID_SPRZETU)");
		_TRef += " left outer join pr_jednostki j on (j.ID_JEDNOSTKI = m.ID_JEDNOSTKI) ";
		_TRef +="  left outer join PR_KOMORKI w on (w.ID_KOMORKI = m.ID_KOMORKI) ";
		_TRef +="  left outer join pr_wydzialy  wy on (wy.id_wydzialu = w.id_wydzialu) ";
 mng::Query _Q(_TRef, _ColList);
if(_Pars.Rok >0)             _Q.attachWherePred( new mng::ComparePredicate(" m.ROK", _Pars.Rok ));
if(_Pars.IdWydzialu >0)      _Q.attachWherePred( new mng::ComparePredicate(" wy.ID_WYDZIALU", _Pars.IdWydzialu ));
if(!_Pars.SygnMag.IsEmpty()) _Q.attachWherePred(new mng::LikePredicate(" M.SYGN_MAG ", _Pars.SygnMag));
 _Q.setOrderList(" m.SYGN_MAG");
 m_SprzetDAR->setQuery(_Q);
 m_SprzetDAR->open();
}
//---------------------------------------------------------------------------
msg::MagID SprzetFinder::getCurrID(void)
{
 msg::MagID _ID;
 if(m_SprzetDAR->getDataSet()->Active && !m_SprzetDAR->getDataSet()->IsEmpty() )
 {
  _ID.fillFromDS(m_SprzetDAR->getDataSet());
 }
 return _ID;
}
//---------------------------------------------------------------------------
void SprzetFinder::close(void)
{
  m_SprzetDAR->close();
}
//---------------------------------------------------------------------------

