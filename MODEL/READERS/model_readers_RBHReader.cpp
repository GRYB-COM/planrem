//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_readers_RBHReader.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "model_messengers_RBH4War.h"
#include "model_messengers_RBH4Mies.h"
#include "model_messengers_RBH.h"
#include "model_messengers_RBH4Os.h"
#include "MANAGER\queries.h"
#include "model_readers_RBHPlanReader.h"
#include "isvaria.h"
#include <dbclient.hpp>
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
RBHReader::Pars::Pars(void)
:AddPlan(false),
 Rok(CurrentYear()),
 RokPlan(0),
 IdKomorki(-1),
 Miesiac(-1)
{

}
//---------------------------------------------------------------------------
TDataSet * TESTOWY_DATASET;
RBHReader::RBHReader(void)
{
 m_Reader     = new sgda::DAReader(sgda::ctQueryDB);
 m_ReaderDel  = new sgda::DAReader(sgda::ctQueryDB);
 m_EtatyDAR   = new sgda::DAReader(sgda::ctStreamDB);
 m_Ini        = new jbutils::TMyIni();
 TESTOWY_DATASET = m_Reader->getDataSet();
}
//---------------------------------------------------------------------------
RBHReader::~RBHReader(void)
{
 delete m_Reader;
 delete m_ReaderDel;
 delete m_EtatyDAR;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void RBHReader::read(msg::RBH4War& _BuffWar, const Pars& _Pars)
{
 readKom(_BuffWar,_Pars);
 readDel(_BuffWar,_Pars);

}
//---------------------------------------------------------------------------
int TESTOWY_RecNo;
void RBHReader::readKom(msg::RBH4War& _BuffWar, const Pars& _Pars)
{
 m_Pars = _Pars;
 prepareReader();
 prepareEtatyDAR();
 int    _War;
 int    _Mies, _MiesEt,_DniRob;
 String _Kadra;
 Etaty _Et;
 msg::RBH4Mies& _BuffMies  = _BuffWar[0];
 msg::RBH _RBH;
 m_Reader->open();
 m_EtatyDAR->open();
 m_Pars.Miesiac == -1 ? _MiesEt = 1 : _MiesEt = m_Pars.Miesiac;
 while(!m_Reader->isEof() )
 {
  TESTOWY_RecNo =  m_Reader->getDataSet()->RecNo;
  _War    = m_Reader->fieldByName("ID_KOMORKI")->AsInteger;
  _Mies   = m_Reader->fieldByName("NR_MIES")->AsInteger;
  _Kadra  = m_Reader->fieldByName("KADRA")->AsString;
  _DniRob = m_Reader->fieldByName("DNI_ROB")->AsInteger;
  if(_DniRob >0)
  {
   set(_RBH,_Et);
   _BuffWar.add(_War,_Mies,_Mies == _MiesEt,_Kadra,_RBH,_Et.Pr);
  }
  m_Reader->next();
 }
 if(m_Pars.AddPlan)
 {
  RBHPlanReader _PlanRead;
  RBHPlanReader::Pars _Pars;
  _Pars.Rok = m_Pars.RokPlan ==0 ? m_Pars.Rok : m_Pars.RokPlan;
  _PlanRead.read(_BuffWar,_Pars);
 }
 m_Reader->close();
}
//---------------------------------------------------------------------------
void RBHReader::readDel(msg::RBH4War& _BuffWar, const Pars& _Pars)
{
 m_Pars = _Pars;
 prepareReaderDel();
 prepareEtatyDAR();
 int    _War;
 int    _Mies, _MiesEt,_DniRob;
 String _Kadra;
 Etaty _Et;
 msg::RBH4Mies& _BuffMies  = _BuffWar[0];
 msg::RBH _RBH;
 m_ReaderDel->open();
 m_EtatyDAR->open();
 m_Pars.Miesiac == -1 ? _MiesEt = 1 : _MiesEt = m_Pars.Miesiac;
 while(!m_ReaderDel->isEof() )
 {
  _War    = m_ReaderDel->fieldByName("ID_KOMORKI")->AsInteger;
  _Mies   = m_ReaderDel->fieldByName("NR_MIES")->AsInteger;
  _Kadra  = m_ReaderDel->fieldByName("KADRA")->AsString;
  _DniRob = m_ReaderDel->fieldByName("DNI_ROB")->AsInteger;
  if(_DniRob >0)
  {
   set(_RBH,_Et);
   _BuffWar.add(_War,_Mies,_Mies == _MiesEt,_Kadra,_RBH,_Et.Pr);
  }
  m_ReaderDel->next();
 }
 m_ReaderDel->close();
}
//---------------------------------------------------------------------------
void RBHReader::read(msg::RBH4Os& _BuffOs, const Pars& _Pars)
{
 readKom(_BuffOs,_Pars);
 readDel(_BuffOs,_Pars);
}
//---------------------------------------------------------------------------
void RBHReader::readKom(msg::RBH4Os& _BuffOs, const Pars& _Pars)
{
 int _IdOsoby, _DniRob;
 m_Pars = _Pars;
 prepareReader();
 prepareEtatyDAR();
 m_Reader->open();
 m_EtatyDAR->open();
 msg::RBH _RBH;
 Etaty _Et;
 while(!m_Reader->isEof() )
 {
   TESTOWY_RecNo =  m_Reader->getDataSet()->RecNo;
   if(TESTOWY_RecNo > 1583)
   {
     TESTOWY_RecNo = 1584;
   }
  _IdOsoby   = m_Reader->fieldByName("ID_OSOBY")->AsInteger;
  _DniRob = m_Reader->fieldByName("DNI_ROB")->AsInteger;
  if(_IdOsoby >0 && _DniRob >0)
  {
   set(_RBH,_Et);
   _BuffOs.add(_IdOsoby,_RBH);
  }
  m_Reader->next();
 }
 m_Reader->close();
 m_EtatyDAR->close();
}
//---------------------------------------------------------------------------
void RBHReader::readDel(msg::RBH4Os& _BuffOs, const Pars& _Pars)
{
 int _IdOsoby, _DniRob;
 m_Pars = _Pars;
 prepareReaderDel();
 prepareEtatyDAR();
 m_ReaderDel->open();
 m_EtatyDAR->open();
 msg::RBH _RBH;
 Etaty _Et;
 while(!m_ReaderDel->isEof() )
 {
  _IdOsoby   = m_ReaderDel->fieldByName("ID_OSOBY")->AsInteger;
  _DniRob = m_ReaderDel->fieldByName("DNI_ROB")->AsInteger;
  if(_IdOsoby >0 && _DniRob >0)
  {
   set(_RBH,_Et);
   _BuffOs.add(_IdOsoby,_RBH);
  }
  m_ReaderDel->next();
 }
 m_ReaderDel->close();
 m_EtatyDAR->close();
}
//---------------------------------------------------------------------------
void RBHReader::prepareReader(void)
{
 mng::Query _Q(M_TABLE_REF,M_COL_LIST);
 if(m_Pars.IdKomorki >0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("war.ID_KOMORKI", m_Pars.IdKomorki  ) );
 }
 else
 {
  _Q.attachWherePred( new mng::ComparePredicate("war.ID_KOMORKI", 0, mng::ComparePredicate::copGreat) );
 }
 _Q.attachWherePred( new mng::ExplicitPredicate(" (WAR.WARSZTAT =  'T' )  AND (WAR.KOD NOT IN ('0/0','-1/-1') ) ") );

 if(m_Pars.Miesiac > 0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("mies.NR_MIES", m_Pars.Miesiac) );

 }

 if(m_Pars.Rok > 0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("mies.ROK", m_Pars.Rok) );

 }

 _Q.setOrderList(M_ORDER_LIST);
 m_Reader->setQuery(_Q);

}
//---------------------------------------------------------------------------
void RBHReader::prepareReaderDel(void)
{
 mng::Query _Q(M_TABLE_REF_DEL,M_COL_LIST_DEL);
 if(m_Pars.IdKomorki >0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("del.ID_KOMORKI", m_Pars.IdKomorki  ) );
 }
 else
 {
  _Q.attachWherePred( new mng::ComparePredicate("del.ID_KOMORKI", 0, mng::ComparePredicate::copGreat) );
 }
 _Q.attachWherePred( new mng::ExplicitPredicate(" (WAR.WARSZTAT =  'T' )  AND (WAR.KOD NOT IN ('0/0','-1/-1') ) ") );

 if(m_Pars.Miesiac > 0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("del.MIESIAC", m_Pars.Miesiac) );

 }

 if(m_Pars.Rok > 0)
 {
  _Q.attachWherePred( new mng::ComparePredicate("del.ROK", m_Pars.Rok) );

 }

 _Q.setOrderList(M_ORDER_LIST_DEL);
 m_ReaderDel->setQuery(_Q);

}
//---------------------------------------------------------------------------
const AnsiString RBHReader::M_COL_LIST("\
WAR.ID_KOMORKI, WAR.KOD, \
MIES.NR_MIES, MIES.DNI_ROB - coalesce(del.DNI,0) as DNI_ROB, \
OS.ID_OSOBY, OS.KADRA, OS.DATA_OD, OS.DATA_DO,  OS.ETAT_PR,  OS.ETAT_NPR,  OS.ETAT_KOR,  \
UR.URLOP, \
ZW.LICZBA_DNI,  \
KA.PRZERWA, KA.CHOROBA,KA.SLUZBA, \
SZ.RBH AS SZKOLENIE \
 ");
//ETAT_NPR - LICZBA GODZIN DNIÓWKI
//---------------------------------------------------------------------------
//MA BYÆ INNER JOIN OSOBY BO SIÊ PIEPRZY
const AnsiString RBHReader::M_TABLE_REF("\ PR_komorki war  \
inner join PR_OSOBY    os   on os.ID_KOMORKI = war.ID_KOMORKI  \
inner join PR_MIES4RBH   mies on mies.NR_MIES >0  \
left outer join PR_URLOPY   ur   on ur.ID_OSOBY = os.ID_OSOBY and ur.NR_MIES = mies.NR_MIES \
left outer join PR_ZW_DOD   zw   on zw.ID_OSOBY = os.ID_OSOBY and zw.NR_MIES = mies.NR_MIES \
left outer join PR_KADRA    ka   on ka.KOD = os.KADRA \
left outer join PR_SZKOLENIE_RBH sz on sz.KOD = ka.KOD and sz.NR_MIES = mies.NR_MIES \
LEFT outer join pr_delegacje del    ON del.ROK = mies.ROK and del.MIESIAC = mies.NR_MIES and del.ID_OSOBY = os.ID_OSOBY \
");
//---------------------------------------------------------------------------
const AnsiString RBHReader::M_ORDER_LIST("war.ID_KOMORKI, war.KOD, mies.nr_mies, mies.DNI_ROB,  os.ID_OSOBY, os.KADRA, os.DATA_OD, os.DATA_DO ");
//---------------------------------------------------------------------------
const AnsiString RBHReader::M_COL_LIST_DEL("\
war.ID_KOMORKI, WAR.KOD, 0 as DATA_OD, 0 as DATA_DO,\
del.MIESIAC, del.DNI  as DNI_ROB, del.MIESIAC as NR_MIES,\
OS.ID_OSOBY, OS.KADRA, OS.DATA_OD, OS.DATA_DO,  OS.ETAT_PR,  OS.ETAT_NPR,  OS.ETAT_KOR, \
UR.URLOP, \
ZW.LICZBA_DNI, \
KA.PRZERWA, KA.CHOROBA,KA.SLUZBA, \
SZ.RBH AS SZKOLENIE \
 ");
//ETAT_NPR - LICZBA GODZIN DNIÓWKI
//---------------------------------------------------------------------------
const AnsiString RBHReader::M_TABLE_REF_DEL("\ PR_DELEGACJE del \
inner      join PR_komorki war   on war.ID_KOMORKI = del.ID_KOMORKI \
inner      join PR_OSOBY    os   on os.ID_OSOBY = del.ID_OSOBY \
left outer join PR_URLOPY   ur   on ur.ID_OSOBY = os.ID_OSOBY and ur.NR_MIES = del.MIESIAC \
left outer join PR_ZW_DOD   zw   on zw.ID_OSOBY = os.ID_OSOBY and zw.NR_MIES = del.MIESIAC \
left outer join PR_KADRA    ka   on ka.KOD = os.KADRA \
left outer join PR_SZKOLENIE_RBH sz on sz.KOD = ka.KOD and sz.NR_MIES = del.MIESIAC \
");
//---------------------------------------------------------------------------
const AnsiString RBHReader::M_ORDER_LIST_DEL("del.ID_KOMORKI, war.KOD, del.MIESIAC, del.DNI,  os.ID_OSOBY, os.KADRA, os.DATA_OD, os.DATA_DO ");
//---------------------------------------------------------------------------
void RBHReader::prepareEtatyDAR(void)
{
 mng::Query _Q(" PR_ETATY_PRAC E","EXTRACT(YEAR FROM E.DATA_OD) AS ROK_OD, EXTRACT(MONTH FROM E.DATA_OD) AS MIES_OD, EXTRACT(YEAR FROM E.DATA_OD) * 1000 + EXTRACT(MONTH FROM E.DATA_OD) AS FOR_FILTER, E.*");
 _Q.setOrderList("E.DATA_OD DESC");
 m_EtatyDAR->setQuery(_Q);
}
//---------------------------------------------------------------------------
void RBHReader::add(msg::RBH4Mies& _BuffMies, Etaty& _Et)
{
 int    _Mies  = m_Reader->fieldByName("NR_MIES")->AsInteger;
 String _Kadra = m_Reader->fieldByName("KADRA")->AsString;
 Etaty _Et1;
 msg::RBH & _RBH = _BuffMies[0][_Kadra];
 add(_RBH,_Et1);
 _RBH = _BuffMies[_Mies][_Kadra];
 add(_RBH,_Et);
}
//---------------------------------------------------------------------------
void RBHReader::add(msg::RBH& _RBH, Etaty& _Et)
{
 msg::RBH _Buff;
 Etaty _EtB;
 set(_Buff,_EtB);
 _RBH    += _Buff;
 _Et.Pr  += _EtB.Pr;
 _Et.Npr += _EtB.Npr;
 _Et.Kor += _EtB.Kor;
}
//---------------------------------------------------------------------------
//_Et.Pr  - czêœæ produkcyjna etatu
//_Et.Npr - liczba rbh dniówki
//_Et.Kor - etat zatrudnienia
void RBHReader::set(msg::RBH& _Buff,Etaty& _Et)
{
 sgda::DAReader * _Reader;
 if(m_ReaderDel->getDataSet()->Active) _Reader = m_ReaderDel;
 else _Reader = m_Reader;
double  _Ur, _Zw,_UrP, _ZwP, _Ch, _Sl, _Prz, _Sz;
 int _DniR;
 _Buff.RBH_Nom   = 0.0;
 _Buff.RBH_NProd = 0.0;
 _Buff.RBH_Prod  = 0.0;
 _Buff.RBH_ProdW  = 0.0;
 _Buff.RBH_Ef    = 0.0;
 _Buff.RBH_Ur    = 0.0;
 _Buff.RBH_Ur    = 0.0;
 _Buff.RBH_Prz   = 0.0;
 _Buff.RBH_Ch    = 0.0;
 _Buff.RBH_Sl    = 0.0;
 _Buff.RBH_Szk   = 0.0;
 _Buff.EtatPr    = "";
 _Et.Pr          = 0.0;
 _Et.Npr         = 0.0;
 _Et.Kor         = 0.0;
 TDateTime _DataOd, _DataDo;
 _DataOd = _Reader->fieldByName("DATA_OD")->AsDateTime;
 _DataDo = _Reader->fieldByName("DATA_DO")->AsDateTime;
 TDateTime _BiezData(m_Pars.Rok,_Reader->fieldByName("NR_MIES")->AsInteger, 1);
 if(_DataDo == TDateTime(0.0) )_DataDo = TDateTime(9999,12,31);
 if(_BiezData >= _DataOd && _BiezData<= _DataDo)
 {
  _DniR =_Reader->fieldByName("DNI_ROB")->AsInteger;
  setEtat(_Et);
  _Ur    = ISRound(_Reader->fieldByName("URLOP")->AsDouble,2);
  _UrP   = _Et.Pr < _Et.Kor ? ISRound(_Et.Pr * _Ur,2) : _Ur;
  _Zw    = ISRound(_Reader->fieldByName("LICZBA_DNI")->AsDouble,2);
  _ZwP   = _Et.Pr < _Et.Kor ? ISRound(_Et.Pr * _Zw,2) : _Zw;
  _Ch    = ISRound(_Reader->fieldByName("CHOROBA")->AsDouble,2);
  _Sl    = ISRound(_Reader->fieldByName("SLUZBA")->AsDouble,2);
  _Prz   = ISRound(_Reader->fieldByName("PRZERWA")->AsDouble,2);
  _Sz    = ISRound(_Reader->fieldByName("SZKOLENIE")->AsDouble,2);
  _Buff.RBH_Nom     = ISRound(_DniR * _Et.Pr * _Et.Npr, 2);
  if(_Buff.RBH_Nom >0)
  {
   _Buff.EtatPr   = _Et.Pr;
   _Buff.RBH_Ur   = ISRound(_UrP * _Et.Npr,2);
   _Buff.RBH_Ur  += ISRound(_ZwP * _Et.Npr,2);
   _Buff.RBH_Prz  = ISRound((_Et.Pr*_DniR - _UrP -_ZwP)*_Prz,2);
   _Buff.RBH_Ch   = ISRound(_Et.Pr*_Ch,2);
   _Buff.RBH_Sl   = ISRound(_Et.Pr*_Sl,2);
   _Buff.RBH_Szk  = ISRound(_Et.Pr*_Sz,2);


   _Buff.RBH_NProd  = _Buff.RBH_Ur;
   _Buff.RBH_NProd += _Buff.RBH_Prz;
   _Buff.RBH_NProd += _Buff.RBH_Ch;
   _Buff.RBH_NProd += _Buff.RBH_Sl;
   _Buff.RBH_NProd += _Buff.RBH_Szk;
   _Buff.RBH_Prod   = _Buff.RBH_Nom - _Buff.RBH_NProd;
   _Buff.RBH_Ef     = _Buff.RBH_Prod + _Buff.RBH_ProdW;
  }
 }
 /*
  1 liczba pracowników
  os.ETAT_PR * os.ETAT_NPR * mies.DNI_ROB  AS RBH_NOM, \
sum( os.ETAT_PR * os.ETAT_NPR * ur.URLOP/os.ETAT_KOR )  AS RBH_URLOP,\
sum( os.ETAT_PR * os.ETAT_NPR * zw.LICZBA_DNI/os.ETAT_KOR ) AS RBH_ZW, \
sum( (os.ETAT_PR * mies.DNI_ROB - os.ETAT_PR/os.ETAT_KOR*(case when ur.Urlop is NULL then 0 else ur.URLOP end + case when zw.LICZBA_DNI is NULL then 0 else zw.LICZBA_DNI end))  * ka.PRZERWA) AS RBH_PRZERWA, \
sum( os.ETAT_PR * ka.CHOROBA) AS RBH_CHOROBA, \
sum( os.ETAT_PR * ka.SLUZBA)  AS RBH_SLUZBA, \
sum( os.ETAT_PR *  sz.RBH ) AS RBH_SZKOLENIE \

 */

}
void RBHReader::setEtat(Etaty & _Et)
{
  sgda::DAReader * _Reader;
 if(m_ReaderDel->getDataSet()->Active) _Reader = m_ReaderDel;
 else _Reader = m_Reader;
 _Et.Pr  = ISRound(_Reader->fieldByName("ETAT_PR")->AsDouble,2);
  _Et.Npr = ISRound(_Reader->fieldByName("ETAT_NPR")->AsDouble,2);
  _Et.Kor = ISRound(_Reader->fieldByName("ETAT_KOR")->AsDouble,2);
 if(!m_ReaderDel->getDataSet()->Active)
 {
  TClientDataSet * _Cl = dynamic_cast<TClientDataSet *>(m_EtatyDAR->getDataSet());
  String _Filter;
  _Filter  = String(" ID_OSOBY = ")  + _Reader->fieldByName("ID_OSOBY")->AsInteger /* SPECJALNIE AS INTEGER BO NULL*/  + String(" AND ");
  _Filter += String(" FOR_FILTER <= ") + String(m_Pars.Rok*1000 + _Reader->fieldByName("NR_MIES")->AsInteger );
  _Cl->Filter   = _Filter;
  _Cl->Filtered = true;
  TIndexOptions opts;
  opts << ixCaseInsensitive << ixDescending;
  _Cl->AddIndex("m_DataOdIDX","DATA_OD", opts, "", "",0);
  _Cl->IndexName = "m_DataOdIDX";

  if(! _Cl->IsEmpty() )
  {
   _Et.Pr  = ISRound(_Cl->FieldByName("ETAT_PROD")->AsFloat,2);
   _Et.Npr = ISRound(_Cl->FieldByName("DNIOWKA")->AsFloat,2);
   _Et.Kor = ISRound(_Cl->FieldByName("ETAT")->AsFloat,2);
  }
  _Cl->IndexName ="";
 }
}
//---------------------------------------------------------------------------

