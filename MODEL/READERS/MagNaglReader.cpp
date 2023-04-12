//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagNaglReader.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MagID.h"
#include "MANAGER\Queries.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
MagNaglReader::MagNaglReader(void)
{
 m_Reader = new sgda::DAReader(sgda::ctStreamDB);
}
//---------------------------------------------------------------------------
MagNaglReader::~MagNaglReader(void)
{
 delete m_Reader;
}
//---------------------------------------------------------------------------
void MagNaglReader::open(const msg::MagID& _MagID)
{
 AnsiString _Ta(" pr_magazyn m \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = M.ID_JEDNOSTKI \
LEFT OUTER JOIN PR_KOMORKI W ON W.ID_KOMORKI = M.ID_KOMORKI  \
LEFT OUTER JOIN PR_REMONTY   R ON R.ID_REMONTU = M.ID_REMONTU     \
LEFT OUTER JOIN PR_ZLECENIA   Z ON (\
									Z.ID_MAG = M.ID_MAG AND Z.DEPOZYT = M.DEPOZYT AND \
									Z.ID_KOMORKI_GLW = M.ID_KOMORKI AND Z.ROK_MAG = M.ROK AND Z.STATUS = 'G') \
			 ");
AnsiString _C("S.NAZWA AS SPRZET, \
J.JW || ' ' || J.MIEJSCOWOSC AS JW_MIEJSCOWOSC, \
M.PODSTAWA, M.NR_FABR, M.DATA_PRZYJ, M.PROT_PRZYJ, M.PROT_PRZEKAZ, M.UWAGI, M.ILOSC, M.ID_HARM,\
W.NAZWA AS NAZWA_WAR, \
R.NAZWA AS RODZAJ_REM, \
'W REMONCIE' AS STATUS, \
M.DATA_PROP_ZAK AS DATA_ZAK ");
 mng::Query _Q(_Ta,_C);
 _Q.attachWherePred( new mng::ComparePredicate("m.ID_MAG", _MagID.IdMag )) ;
 m_Reader->setQuery(_Q);
 m_Reader->open();
}
//---------------------------------------------------------------------------
void MagNaglReader::close(void)
{
 m_Reader->close();
}
//---------------------------------------------------------------------------
TDataSet* MagNaglReader::getDataSet(void)
{
    return m_Reader->getDataSet();
}

