//---------------------------------------------------------------------------
#pragma hdrstop
#include "SPReader.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\Queries.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------
SPReader::SPReader(void)
{
 m_Reader = new sgda::DAReader(sgda::ctStreamDB);
}
//---------------------------------------------------------------------------
SPReader::~SPReader(void)
{
 delete m_Reader;
}
//---------------------------------------------------------------------------
TDataSet* SPReader::getDataSet(void)
{
  return m_Reader->getDataSet();
}
//---------------------------------------------------------------------------
void SPReader::open(bool spIn, AnsiString sgn)
{
AnsiString _Column("M.*, S.NAZWA AS NAZ_SPRZETU, J.*, K.KOD AS KOD_WARSZTATU, K.NAZWA AS NAZ_WARSZTATU ");

AnsiString _Table("PR_MAGAZYN M LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
 LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = M.ID_JEDNOSTKI  \
 LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = M.ID_KOMORKI ");

 mng::Query _Query(_Table,_Column);
 _Query.attachWherePred(new mng::ComparePredicate((spIn ? "M.PROT_PRZYJ" : "M.PROT_PRZEKAZ"),String("'") + sgn + String("'")));

 m_Reader->setQuery(_Query);
 m_Reader->prepare();
 m_Reader->open();

}
//---------------------------------------------------------------------------
void SPReader::close(void)
{
 m_Reader->close();
}

