//---------------------------------------------------------------------------
#pragma hdrstop
#include "KUTReader.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MagID.h"
#include "MANAGER\Queries.h"
#include "ZlecREC.h"
#include "MANAGER\bookmark_man.h"
#include "MANAGER\various_man.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
KUTReader::KUTReader(void)
{
 m_Reader = new sgda::DAReader(sgda::ctStreamDB);
 m_Ini    = new jbutils::TMyIni();
 m_BiezRok = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
}
//---------------------------------------------------------------------------
KUTReader::~KUTReader(void)
{
 delete m_Reader;
 delete m_Ini;
}
//---------------------------------------------------------------------------
TDataSet* KUTReader::getDataSet(void)
{
  return m_Reader->getDataSet();
}
//---------------------------------------------------------------------------
void KUTReader::open(const msg::MagID& _MagID)
{
  m_BiezRok = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  AnsiString _Table("PR_ZLECENIA z LEFT OUTER JOIN PR_JEDNOSTKI j ON z.ID_JEDNOSTKI = j.ID_JEDNOSTKI INNER JOIN PR_KOMORKI w ON z.ID_KOMORKI = w.ID_KOMORKI ");
  AnsiString _Column("z.*, j.NAZWA_PELNA, w.NAZWA AS WARSZTAT, w.KOD AS KOD_WARSZTATU, \
  (SELECT SUM(R.LICZBA_RBH) FROM PR_ZLECENIA_RBH R WHERE R.ROK = Z.ROK AND R.ID_KOMORKI =Z.ID_KOMORKI AND R.ID_ZLECENIA =Z.ID_ZLECENIA) AS WYK_RBH, \
  (SELECT SUM(R.ILOSC) FROM PR_ZLECENIA_RBH R WHERE R.ROK = Z.ROK AND R.ID_KOMORKI =Z.ID_KOMORKI AND R.ID_ZLECENIA =Z.ID_ZLECENIA) AS WYK_IL");
  mng::Query _Query(_Table,_Column);
  _Query.setOrderList( " Z.NR_KOL ");
 _Query.attachWherePred(new mng::ComparePredicate("z.ID_MAG", _MagID.IdMag));
 _Query.attachWherePred(new mng::ComparePredicate("z.DEPOZYT",String("'") +  _MagID.Depozyt +String("'") ));
 _Query.attachWherePred(new mng::ComparePredicate("z.ROK_MAG", _MagID.Rok));
 _Query.attachWherePred(new mng::ComparePredicate("z.ID_KOMORKI_GLW", _MagID.IdKomorki));
 _Query.setOrderList("z.ROK desc, NR_KOL");
 m_Reader->setQuery(_Query);
 m_Reader->open();
}
//---------------------------------------------------------------------------
msg::ZlecREC KUTReader::getMainKUT(void)
{
 msg::ZlecREC _Zl;
 mng::BookmarkMan _Book(m_Reader->getDataSet() );
 mng::ControlsMan _CMan(m_Reader->getDataSet() );
 TLocateOptions _LOpt;
 Variant _Vals[2];
 _Vals[0] = m_BiezRok;
 _Vals[1] = 0;
 if(m_Reader->getDataSet()->Locate("ROK;NR_KOL",VarArrayOf(_Vals,1),_LOpt ) ) _Zl.fillFromDS(m_Reader->getDataSet());
 return _Zl;
}
//---------------------------------------------------------------------------
void KUTReader::close(void)
{
 m_Reader->close();
}

