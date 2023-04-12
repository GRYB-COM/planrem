//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_readers_RBHPlanReader.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "model_messengers_RBH4War.h"
#include "model_messengers_RBH4Mies.h"
#include "model_messengers_RBH.h"
#include "model_readers_RBHPlanReader.h"
#include "MANAGER\queries.h"
#include "isvaria.h"
//---------------------------------------------------------------------------
using namespace readers;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
RBHPlanReader::Pars::Pars(void)
:Rok(CurrentYear())
{

}
//---------------------------------------------------------------------------
RBHPlanReader::RBHPlanReader(void)
{
 m_Reader = new sgda::DAReader(sgda::ctQueryDB);
}
//---------------------------------------------------------------------------
RBHPlanReader::~RBHPlanReader(void)
{
 delete m_Reader;
}
//---------------------------------------------------------------------------
void RBHPlanReader::read(msg::RBH4War& _BuffWar, const Pars& _Pars)
{
 m_Pars = _Pars;
 prepareReader();
 int _War;
 int _Mies;
 Currency _PlanRBH;
 m_Reader->open();
 while(!m_Reader->isEof() )
 {
  _War     = m_Reader->fieldByName("ID_KOMORKI")->AsInteger;
  _Mies    = m_Reader->fieldByName("MIESIAC")->AsInteger;
  _PlanRBH = m_Reader->fieldByName("PLAN_RBH")->AsCurrency;
  _BuffWar[_War].add(_Mies, _PlanRBH);
  m_Reader->next();
 }
 m_Reader->close();
}
//---------------------------------------------------------------------------
void RBHPlanReader::prepareReader(void)
{
 mng::Query _Q(M_TABLE_REF,M_COL_LIST);
 _Q.attachWherePred( new mng::ComparePredicate("h.ROK", m_Pars.Rok) );
 _Q.setGroupList(M_GROUP_BY_LIST);
 m_Reader->setQuery(_Q);

}
//---------------------------------------------------------------------------
const AnsiString RBHPlanReader::M_COL_LIST("h.ID_KOMORKI, hd.MIESIAC, sum(hd.PLAN_RBH) as PLAN_RBH ");
//---------------------------------------------------------------------------
const AnsiString RBHPlanReader::M_TABLE_REF("\
pr_harmonogram h \
inner join PR_HARMONOGRAM_DET hd on hd.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU and hd.ROK = h.ROK ");
//---------------------------------------------------------------------------
const AnsiString RBHPlanReader::M_GROUP_BY_LIST("h.ID_KOMORKI, hd.MIESIAC ");
//---------------------------------------------------------------------------
void RBHPlanReader::add(msg::RBH4Mies& _BuffMies)
{
 int      _Mies        = m_Reader->fieldByName("MIESIAC")->AsInteger;
 Currency _PlanRBH     = ISRound(m_Reader->fieldByName("PLAN_RBH")->AsCurrency,2);
 msg::RBH4Kadra & _RBH = _BuffMies[0];
 _RBH.add(_PlanRBH);
 _RBH = _BuffMies[_Mies];
 _RBH.add(_PlanRBH);
}
//---------------------------------------------------------------------------

