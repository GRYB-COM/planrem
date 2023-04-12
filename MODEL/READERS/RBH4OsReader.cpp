//---------------------------------------------------------------------------
#pragma hdrstop
#include "RBH4OsReader.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "model_messengers_RBH4War.h"
#include "model_messengers_RBH4Mies.h"
#include "model_messengers_RBH.h"
#include "model_readers_RBHPlanReader.h"
#include "MANAGER\queries.h"
#include "ISVaria.h"
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
RBH4OsReader::Pars::Pars(void)
 :Rok(CurrentYear())
{

}
//---------------------------------------------------------------------------
RBH4OsReader::RBH4OsReader(void)
{
 m_Reader = new sgda::DAReader(sgda::ctQueryDB);
}
//---------------------------------------------------------------------------
RBH4OsReader::~RBH4OsReader(void)
{
 delete m_Reader;
}
//---------------------------------------------------------------------------
void RBH4OsReader::read(msg::RBH4War& _BuffWar, const Pars& _Pars)
{
 m_Pars = _Pars;
 prepareReader();
 int    _War;
 int    _Mies;
 String _Kadra;
 msg::RBH4Mies& _BuffMies  = _BuffWar[0];
 msg::RBH _RBH;
 m_Reader->open();
 while(!m_Reader->isEof() )
 {
  _War   = m_Reader->fieldByName("ID_KOMORKI")->AsInteger;
  _Mies  = m_Reader->fieldByName("NR_MIES")->AsInteger;
  _Kadra = m_Reader->fieldByName("KADRA")->AsString;
  set(_RBH);
  _BuffWar.add(_War,_Mies,_Kadra,_RBH);
  m_Reader->next();
 }
 m_Reader->close();
}
//---------------------------------------------------------------------------
void RBH4OsReader::prepareReader(void)
{
 mng::Query _Q(M_TABLE_REF,M_COL_LIST);
 _Q.attachWherePred( new mng::ComparePredicate("war.ID_KOMORKI", 0, mng::ComparePredicate::copGreat) );
 _Q.attachWherePred( new mng::ComparePredicate("war.WARSZTAT", " 'T' ") );
 _Q.setGroupList(M_GROUP_BY_LIST);
 m_Reader->setQuery(_Q);

}
//---------------------------------------------------------------------------
const AnsiString RBH4OsReader::M_COL_LIST("\
war.ID_KOMORKI, war.NAZWA,os.ID_OSOBY, os.IMIE, os.NAZWISKO, os.ETAT_PR, os.KADRA\
os.ETAT_PR *  ( select  sum(m.RBH) from pr_miesiace m )  AS RBH_NOM, \
os.ETAT_PR * ka.URLOP * ur.URLOP AS RBH_URLOP, \
os.ETAT_PR * (case when ur.Urlop is NULL then 1 else 1-ur.URLOP end * ( select  sum(m.dni_rob) from pr_miesiace m ) * ka.PRZERWA) AS RBH_PRZERWA, \
os.ETAT_PR * (case when ur.Urlop is NULL then 1 else 1-ur.URLOP end *  ka.CHOROBA) AS RBH_CHOROBA, \
os.ETAT_PR * (case when ur.Urlop is NULL then 1 else 1-ur.URLOP end *  ka.SLUZBA) AS RBH_SLUZBA, \
os.ETAT_PR * (case when ur.Urlop is NULL then 1 else 1-ur.URLOP end *  sz.RBH) AS RBH_SZKOLENIE, \
os.ETAT_PR * 8 * zw.LICZBA_DNI AS RBH_ZW \
");
//---------------------------------------------------------------------------
const AnsiString RBH4OsReader::M_TABLE_REF("\ PR_komorki war \
left outer join PR_OSOBY    os   on os.ID_KOMORKI = war.ID_KOMORKI \
left outer join PR_URLOPY   ur   on ur.ID_OSOBY = os.ID_OSOBY \
left outer join PR_KADRA    ka   on ka.KOD = os.KADRA  \
left outer join PR_SZKOLENIE_RBH sz on sz.KOD = ka.KOD \
left outer join PR_ZW_DOD zw     on zw.ID_OSOBY = os.ID_OSOBY ");
//---------------------------------------------------------------------------
const AnsiString RBH4OsReader::M_GROUP_BY_LIST("war.ID_KOMORKI, war.KOD, mies.nr_mies ");
//---------------------------------------------------------------------------
void RBH4OsReader::add(msg::RBH4Mies& _BuffMies)
{
 msg::RBH4Kadra & _RBH4Kadra = _BuffMies[0];
 msg::RBH _RBH = _RBH4Kadra[m_Reader->fieldByName("KADRA")->AsString];
 add(_RBH);
 int _Mies =m_Reader->fieldByName("NR_MIES")->AsInteger;
 _RBH4Kadra = _BuffMies[_Mies];
 _RBH = _RBH4Kadra[m_Reader->fieldByName("KADRA")->AsString];
 add(_RBH);
}
//---------------------------------------------------------------------------
void RBH4OsReader::add(msg::RBH& _RBH)
{
 msg::RBH _Buff;
 _Buff.RBH_Nom    = ISRound(m_Reader->fieldByName("RBH_NOM")->AsCurrency,2);
 _Buff.RBH_NProd  = ISRound(m_Reader->fieldByName("RBH_URLOP")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_PRZERWA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_CHOROBA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_SLUZBA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_SZKOLENIE")->AsCurrency,2);
 _Buff.RBH_Prod   = _Buff.RBH_Nom - _Buff.RBH_NProd;
 _RBH += _Buff;
}
//---------------------------------------------------------------------------
void RBH4OsReader::set(msg::RBH& _Buff)
{
 _Buff.RBH_Nom    = ISRound(m_Reader->fieldByName("RBH_NOM")->AsCurrency,2);
 _Buff.RBH_NProd  = ISRound(m_Reader->fieldByName("RBH_URLOP")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_PRZERWA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_CHOROBA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_SLUZBA")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_SZKOLENIE")->AsCurrency,2);
 _Buff.RBH_NProd += ISRound(m_Reader->fieldByName("RBH_ZW")->AsCurrency,2);
 _Buff.RBH_Prod   = _Buff.RBH_Nom - _Buff.RBH_NProd;

}
//---------------------------------------------------------------------------

