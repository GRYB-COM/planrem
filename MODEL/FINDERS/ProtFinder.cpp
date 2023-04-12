//---------------------------------------------------------------------------
#pragma hdrstop
#include "ProtFinder.h"
#include "SGTOOLS\DATAACCESS\DAREader.h"
#include "MANAGER\queries.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
ProtFinder::Pars::Pars(void)
:IdProtokolu(-1),
 Rok(-1),
 IdWydzialu(-1)
{

}
//---------------------------------------------------------------------------
ProtFinder::ProtFinder(void)
{
 m_ProtDAR = new sgda::DAReader(sgda::ctStreamDB);
}
//---------------------------------------------------------------------------
ProtFinder::~ProtFinder(void)
{
 delete m_ProtDAR;
}
//---------------------------------------------------------------------------
TDataSet* ProtFinder::getDataSet(void)
{
	return m_ProtDAR->getDataSet();
}
//---------------------------------------------------------------------------
int ProtFinder::getRecordCount(void)
{
 return  m_ProtDAR->getRecordCount();
}
//---------------------------------------------------------------------------
const String ProtFinder::M_COL_LIST_SQL("\
p.*, cast(p.DATA_WYST as varchar(15) ) as DATA_WYST_STR, J.*  \
");
//---------------------------------------------------------------------------
const String ProtFinder::M_TABLE_REF_SQL("\
pr_protokoly p  \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = P.ID_JEDNOSTKI\
");
//---------------------------------------------------------------------------
void ProtFinder::open(const ProtFinder::Pars& _Pars)
{
 m_Pars = _Pars;
 mng::Query _Q(M_TABLE_REF_SQL, M_COL_LIST_SQL);
 m_ProtDAR->setQuery(_Q);
 m_ProtDAR->open();
}
//---------------------------------------------------------------------------
int ProtFinder::getCurrProt(void)
{
 int _ID(-1);
 if(m_ProtDAR->getDataSet()->Active && !m_ProtDAR->getDataSet()->IsEmpty() )
 {
  _ID = m_ProtDAR->fieldByName("ID_PROTOKOLU")->AsInteger;
 }
 return _ID;
}
//---------------------------------------------------------------------------
int ProtFinder::getCurrRok(void)
{
 int _ID(-1);
 if(m_ProtDAR->getDataSet()->Active && !m_ProtDAR->getDataSet()->IsEmpty() )
 {
  _ID = m_ProtDAR->fieldByName("ROK")->AsInteger;
 }
 return _ID;
}
//---------------------------------------------------------------------------
int ProtFinder::getCurrWydz(void)
{
 int _ID(-1);
 if(m_ProtDAR->getDataSet()->Active && !m_ProtDAR->getDataSet()->IsEmpty() )
 {
  _ID = m_ProtDAR->fieldByName("ID_WYDZIALU")->AsInteger;
 }
 return _ID;
}
//---------------------------------------------------------------------------
void ProtFinder::close(void)
{
  m_ProtDAR->close();
}
//---------------------------------------------------------------------------

