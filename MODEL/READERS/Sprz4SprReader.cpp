//---------------------------------------------------------------------------
#pragma hdrstop
#include "Sprz4SprReader.h"
#include "MANAGER\query_db.h"
#include "..\MESSENGERS\Sprz4Spr.h"
#include <dateutils.hpp>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
Sprz4SprReader::Sprz4SprReader(void)
{
 m_RealQDB = new mng::QueryDB(M_SQL_REAL);
 m_PlanQDB = new mng::QueryDB(M_SQL_PLAN);

 m_SQL.push_back( Queries(M_SQL_JP,M_SQL_SPRZET_PLAN,M_SQL_SPRZET_REAL));
 m_SQL.push_back( Queries(M_SQL_WP,M_SQL_HARM_PLAN,M_SQL_HARM_REAL));
 m_SQL.push_back( Queries(M_SQL_NP,M_SQL_SPRZET_PLAN,M_SQL_SPRZET_REAL));
}
//---------------------------------------------------------------------------
Sprz4SprReader::~Sprz4SprReader(void)
{
 delete m_RealQDB;
 delete m_PlanQDB;
}
//---------------------------------------------------------------------------
void Sprz4SprReader::read(msg::Sprz4Spr& _Kont, const Pars& _Pars)
{
 //PORZ¥DKI
   m_Pars = _Pars;
   _Kont.clear();
   prepare(m_PlanQDB);
   prepare(m_RealQDB);
 //PLAN
   read(_Kont,m_PlanQDB);
 //REALIZACJA
   read(_Kont,m_RealQDB);
 //W REMONCIE
   _Kont.setWR();
 //PÊTLA
/*   for(unsigned i =0; i <m_SQL.size();++i)
   {
	Queries& _Q = m_SQL[i];
	open(_Q.MainSQL);
	read(_Kont,_Q);
	close();
   }*/
}
//---------------------------------------------------------------------------
void Sprz4SprReader::prepare(mng::QueryDB * _QDB)
{
 _QDB->close();
 _QDB->paramByName("ROK")->AsInteger     = m_Pars.Rok;
 _QDB->paramByName("MIES_OD")->AsInteger = m_Pars.MiesOd;
 _QDB->paramByName("MIES_DO")->AsInteger = m_Pars.MiesDo;
 TParam* _P = _QDB->getParams()->FindParam("DATA_OD");
 if(_P) _P->AsDateTime = TDateTime(m_Pars.Rok,m_Pars.MiesOd,1);
 _P = _QDB->getParams()->FindParam("DATA_DO");
 if(_P) _P->AsDateTime = EndOfAMonth(m_Pars.Rok, m_Pars.MiesDo);

 _QDB->open();
}
//---------------------------------------------------------------------------
void Sprz4SprReader::read(msg::Sprz4Spr& _Kont, mng::QueryDB * _QDB)
{
 _QDB->open();
 while(!_QDB->isEof())
 {
  add(_Kont,_QDB);
  _QDB->next();
 }
 _QDB->close();
}
//---------------------------------------------------------------------------
void Sprz4SprReader::add(msg::Sprz4Spr& _Kont,mng::QueryDB * _QDB)
{
 //ZMIENNE TYMCZASOWE
 String _Typ     = _QDB->fieldByName("TYP")->AsString;
 int    _IdHarm  = _QDB->fieldByName("ID_HARM")->AsInteger;
 int    _Poz     = _QDB->fieldByName("POZYCJA")->AsInteger;
 int    _IdSprzH = _QDB->fieldByName("ID_SPRZETU_H")->AsInteger;
 int    _IdSprzM = _QDB->fieldByName("ID_SPRZETU_Z")->AsInteger;
 //POBRANIE KLUCZA
 msg::Sprz4Spr::Key _Key;
 _Key.fromDS(_QDB->getDataSet());
 _Key.IdSprz  = getIdSprz(_Typ,_Poz,_IdHarm,_IdSprzH,_IdSprzM);
//DODANIE WARTOŒCI
 msg::Sprz4Spr::Val  _Val;
 _Val.fromDS(_QDB->getDataSet(),_Key.getPlan());
 _Kont[_Key] += _Val;
}
//---------------------------------------------------------------------------
int Sprz4SprReader::getIdSprz(const String _Typ, const int _Poz, const int _Harm, const int _IdSprzH, const int _IdSprzM)
{
 int _IdSprzetu;
 if( _Poz == msg::Sprz4Spr::M_ID_NP )
 {
  _IdSprzetu =  _IdSprzM;
 }
 else if(_Typ == M_ID_WP)
 {
  _IdSprzetu = - _Harm;
 }
 else _IdSprzetu =  _IdSprzH;
 return _IdSprzetu;
}
//---------------------------------------------------------------------------
//STA£E
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
const String Sprz4SprReader::M_ID_WP("W");
const String Sprz4SprReader::M_SQL_REAL("\
select \
K.ID_WYDZIALU, H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.TYP,H.ID_SPRZETU as ID_SPRZETU_H, z.ID_SPRZETU as ID_SPRZETU_Z, \
m.DATA_PRZYJ, m.DATA_ZAK,  H.ROK, H.ID_HARMONOGRAMU AS ID_HARM, H.ZADANIE, \
z.SYGN_MAG, z.SYGN_ZLECENIA, \
SUM(zr.ILOSC) AS ILOSC_R, SUM(zr.LICZBA_RBH) AS RBH_R, \
sum(case when u.Pozycja = 999 then m.ILOSC else 0.00 end) as ILOSC_D \
from PR_ZLECENIA_RBH ZR \
INNER JOIN pr_zlecenia z on z.ROK = zr.ROK and z.ID_ZLECENIA = zr.ID_ZLECENIA and z.id_komorki = zr.ID_KOMORKI \
inner JOIN PR_MAGAZYN  m on m.ROK = z.ROK_MAG and m.DEPOZYT = z.DEPOZYT and m.ID_KOMORKI = z.ID_KOMORKI_GLW and m.ID_MAG = z.ID_MAG \
INNER JOIN pr_harmonogram h ON H.ROK = z.ROK AND H.ID_HARMONOGRAMU = z.ID_HARM \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI \
inner JOIN PR_KOMORKI K ON K.ID_KOMORKI = Z.ID_KOMORKI \
where zr.ROK =:ROK AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO   \
AND (ZR.ILOSC <> 0.0 or ZR.LICZBA_RBH <> 0.0) and m.DEPOZYT <>'D' \
AND M.DATA_PRZYJ <= :DATA_DO \
AND (M.DATA_ZAK IS NULL or  M.DATA_ZAK <'1900-01-01' or  M.DATA_ZAK >= :DATA_OD) \
GROUP BY K.ID_WYDZIALU, H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.TYP,H.ID_SPRZETU,z.ID_SPRZETU, m.DATA_PRZYJ, m.DATA_ZAK, \
H.ROK, H.ID_HARMONOGRAMU,H.ZADANIE,  z.SYGN_MAG, z.SYGN_ZLECENIA \
ORDER BY Z.SYGN_MAG \
");

const String Sprz4SprReader::M_SQL_PLAN("\
 select \
 K.ID_WYDZIALU, H.ID_KOMORKI, U.POZYCJA,  h.ID_REMONTU, H.TYP,H.ID_SPRZETU as ID_SPRZETU_H, - 1 as ID_SPRZETU_Z, H.ROK, \
 H.ID_HARMONOGRAMU AS ID_HARM, H.ZADANIE,\
SUM(HD.ILOSC) AS ILOSC_P, \
(select sum(m.ilosc) from pr_magazyn m inner join  pr_zlecenia z on z.ROK_mag = m.ROK and z.DEPOZYT =m.DEPOZYT and z.ID_KOMORKI_GLW= m.ID_KOMORKI and z.id_mag=m.ID_MAG where  z.rok =h.rok and z.id_harm = h.ID_HARMONOGRAMU)  AS ILOSC_D, \
SUM(HD.PLAN_RBH) AS RBH_P    \
from PR_HARMONOGRAM_DET HD \
INNER JOIN pr_harmonogram h ON H.ROK = hd.ROK AND H.ID_HARMONOGRAMU = hd.ID_HARMONOGRAMU  \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI \
inner JOIN PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI \
where HD.ROK =:ROK AND HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO   and u.POZYCJA <>999 AND (HD.ILOSC <> 0.0 or HD.PLAN_RBH <> 0.0) \
GROUP BY K.ID_WYDZIALU, H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.TYP,H.ID_SPRZETU,   H.ROK, H.ID_HARMONOGRAMU, H.ZADANIE  \
ORDER BY H.ID_HARMONOGRAMU \
");


  const String Sprz4SprReader::M_SQL_JP("\
 select K.ID_WYDZIALU,  U.POZYCJA, H.ID_USLUGI, H.ID_REMONTU, H.ID_KOMORKI, H.ID_SPRZETU, 0 AS ID_HARMONOGRAMU, \
(SELECT SUM(D.ILOSC) FROM PR_HARMONOGRAM_DET D WHERE D.ROK = H.ROK AND D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND D.MIESIAC BETWEEN :MIES_OD AND :MIES_DO) AS ILOSC_P, \
(SELECT SUM(ZR.ILOSC) FROM PR_ZLECENIA_RBH ZR \
	INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = ZR.ID_KOMORKI AND Z.ROK = ZR.ROK  AND Z.ID_ZLECENIA = ZR.ID_ZLECENIA  \
	WHERE Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO \
) AS ILOSC_R, \
(SELECT SUM(D.PLAN_RBH) FROM PR_HARMONOGRAM_DET D WHERE D.ROK = H.ROK AND D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND D.MIESIAC BETWEEN :MIES_OD AND :MIES_DO) AS RBH_P, \
(SELECT SUM(ZR.LICZBA_RBH) FROM PR_ZLECENIA_RBH ZR \
	INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = ZR.ID_KOMORKI AND Z.ROK = ZR.ROK  AND Z.ID_ZLECENIA = ZR.ID_ZLECENIA \
	WHERE Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO  AND Z.DEPOZYT <> 'D' \
) AS RBH_R  \
from pr_harmonogram h \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI  \
inner join PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI \
where h.ROK =:ROK AND H.TYP ='J' AND U.POZYCJA <999 \
 ");

const String Sprz4SprReader::M_SQL_WP("\
select K.ID_WYDZIALU, U.POZYCJA,   H.ID_USLUGI, H.ID_REMONTU, H.ID_KOMORKI, - H.ID_HARMONOGRAMU AS ID_SPRZETU, 0 AS ID_HARMONOGRAMU, \
(SELECT SUM(D.ILOSC) FROM PR_HARMONOGRAM_DET D WHERE D.ROK = H.ROK AND D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND D.MIESIAC BETWEEN :MIES_OD AND :MIES_DO) AS ILOSC_P, \
(SELECT SUM(ZR.ILOSC) FROM PR_ZLECENIA_RBH ZR \
	INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = ZR.ID_KOMORKI AND Z.ROK = ZR.ROK  AND Z.ID_ZLECENIA = ZR.ID_ZLECENIA \
	WHERE Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO   AND Z.DEPOZYT <> 'D' \
) AS ILOSC_R, \
(SELECT SUM(D.PLAN_RBH) FROM PR_HARMONOGRAM_DET D WHERE D.ROK = H.ROK AND D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND D.MIESIAC BETWEEN :MIES_OD AND :MIES_DO) AS RBH_P, \
(SELECT SUM(ZR.LICZBA_RBH) FROM PR_ZLECENIA_RBH ZR \
	INNER JOIN PR_ZLECENIA Z ON Z.ID_KOMORKI = ZR.ID_KOMORKI AND Z.ROK = ZR.ROK  AND Z.ID_ZLECENIA = ZR.ID_ZLECENIA \
	WHERE Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO \
) AS RBH_R \
from pr_harmonogram h \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI \
inner join PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI \
where h.ROK =:ROK AND H.TYP ='W' AND U.POZYCJA <999      \
");

const String Sprz4SprReader::M_SQL_NP("\
select K.ID_WYDZIALU, 0 as ID_USLUGI, 999 AS POZYCJA,  H.ID_REMONTU, H.ID_KOMORKI, Z.ID_SPRZETU, 0 AS ID_HARMONOGRAMU, \
0.00 AS ILOSC_P, SUM(ZR.ILOSC) AS ILOSC_R, 0.00 AS RBH_P, SUM(ZR.LICZBA_RBH)  AS RBH_R  \
from pr_harmonogram h \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI \
iNNER JOIN PR_ZLECENIA Z ON Z.ROK = H.ROK AND Z.ID_HARM = H.ID_HARMONOGRAMU \
inner join PR_ZLECENIA_RBH ZR ON ZR.ID_KOMORKI = Z.ID_KOMORKI AND ZR.ROK = Z.ROK  AND ZR.ID_ZLECENIA = Z.ID_ZLECENIA  \
RIGHT JOIN PR_MAGAZYN M ON M.DEPOZYT = Z.DEPOZYT AND M.ROK = Z.ROK_MAG AND  M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.ID_MAG = Z.ID_MAG \
inner join PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI \
where h.ROK =:ROK AND  U.POZYCJA = 999   AND ZR.MIESIAC BETWEEN :MIES_OD AND :MIES_DO    \
AND M.DEPOZYT <> 'D' \
AND M.DATA_PRZYJ <= :DATA_DO \
AND (M.DATA_ZAK IS NULL or  M.DATA_ZAK <'1900-01-01' or  M.DATA_ZAK <= :DATA_OD) \
GROUP BY  K.ID_WYDZIALU, H.ID_REMONTU, H.ID_KOMORKI, Z.ID_SPRZETU \
");

const String Sprz4SprReader::M_SQL_SPRZET_PLAN("\
select H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.ID_SPRZETU,  HD.ROK, HD.ID_HARMONOGRAMU,  HD.MIESIAC, \
SUM(HD.ILOSC), SUM(HD.PLAN_RBH) \
from pr_harmonogram_DET HD       \
INNER JOIN pr_harmonogram h ON H.ROK = HD.ROK AND H.ID_HARMONOGRAMU = HD.ID_HARMONOGRAMU \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI \
where h.ROK =:ROK AND H.TYP ='J' \
GROUP BY H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.ID_SPRZETU, HD.ROK,  HD.ID_HARMONOGRAMU, HD.MIESIAC \
");

const String Sprz4SprReader::M_SQL_SPRZET_REAL("\
select  \
H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.ID_SPRZETU,  H.ROK, H.ID_HARMONOGRAMU,  \
z.SYGN_MAG, z.SYGN_ZLECENIA, zr.MIESIAC, \
SUM(zr.ILOSC), SUM(zr.LICZBA_RBH)  \
from PR_ZLECENIA_RBH ZR     \
INNER JOIN pr_zlecenia z on z.ROK = zr.ROK and z.ID_ZLECENIA = zr.ID_ZLECENIA and z.id_komorki = zr.ID_KOMORKI    \
INNER JOIN pr_harmonogram h ON H.ROK = z.ROK AND H.ID_HARMONOGRAMU = z.ID_HARM   \
inner JOIN PR_KODY_USLUG u on u.ID_USLUGI = h.ID_USLUGI   \
where h.ROK =:ROK AND H.TYP ='J'  \
GROUP BY H.ID_KOMORKI, U.POZYCJA, H.ID_REMONTU, H.ID_SPRZETU,  H.ROK, H.ID_HARMONOGRAMU, z.SYGN_MAG, z.SYGN_ZLECENIA, zr.MIESIAC  \
");

const String Sprz4SprReader::M_SQL_HARM_PLAN("\
 select HD.ROK, HD.ID_HARMONOGRAMU,  HD.MIESIAC, SUM(HD.ILOSC), SUM(HD.PLAN_RBH) \
from pr_harmonogram_DET HD \
INNER JOIN pr_harmonogram h ON H.ROK = HD.ROK AND H.ID_HARMONOGRAMU = HD.ID_HARMONOGRAMU \
where h.ROK =:ROK and h.ID_HARMONOGRAMU = :id_harmonogramu \
GROUP BY HD.ROK,  HD.ID_HARMONOGRAMU, HD.MIESIAC \
");

const String Sprz4SprReader::M_SQL_HARM_REAL("\
select z.SYGN_MAG, z.SYGN_ZLECENIA, zr.MIESIAC, SUM(zr.ILOSC), SUM(zr.LICZBA_RBH) \
from PR_ZLECENIA_RBH ZR \
INNER JOIN pr_zlecenia z on z.ROK = zr.ROK and z.ID_ZLECENIA = zr.ID_ZLECENIA and z.id_komorki = zr.ID_KOMORKI \
where z.ROK =:ROK AND z.ID_HARM = :ID_HARMONOGRAMU  \
GROUP BY z.SYGN_MAG, z.SYGN_ZLECENIA, zr.MIESIAC  \
");



