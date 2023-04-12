//---------------------------------------------------------------------------
#pragma hdrstop
#include "HarmFinderCTRL.h"
#include "HarmFinder.h"
#include "MANAGER\message_dlg.h"
#include "FindHarmFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
HarmFinderCTRL::Pars::Pars(void)
:IdHarmonogramu(-1),
 Rok(-1),
 IdWydzialu(-1)
{

}
//---------------------------------------------------------------------------
HarmFinderCTRL::HarmFinderCTRL(void)
{
 m_Finder      = new HarmFinder();

 m_SearchForm  = new T_FindHarmFRM(NULL);
 m_SearchForm->setDataSet(m_Finder->getDataSet());
 m_SearchForm->setSearchClictEvet( searchBTClick);

}
//---------------------------------------------------------------------------
HarmFinderCTRL::~HarmFinderCTRL(void)
{
 delete m_Finder;
 delete m_SearchForm;
}
//---------------------------------------------------------------------------
int HarmFinderCTRL::find(int & _IdHarm, const HarmFinderCTRL::Pars & _Pars)
{
 m_Pars = _Pars;
 open();
 int _Res  = find(_IdHarm);
 close();
 return _Res;
}
//---------------------------------------------------------------------------
void HarmFinderCTRL::open(void)
{
 HarmFinder::Pars _ParsF;
 _ParsF.Rok        = m_Pars.Rok;
 _ParsF.IdWydzialu = m_Pars.IdWydzialu;
 m_Finder->open(_ParsF);
}
//---------------------------------------------------------------------------
int HarmFinderCTRL::find(int & _IdHarm)
{
 int _Res(mrOk);
 int _RecCount(m_Finder->getRecordCount());
 if(_RecCount <1)
 {
  mng::MessageDialog::warning("Nie znaleziono ¿adnego harmonogramu","OSTRZE¯ENIE");
 }
 else if(_RecCount == 1)
 {
  _IdHarm = m_Finder->getCurrHarm();
 }
 else if( _RecCount >1)
 {
  T_ListaHarmFRA::Pars _ParsFRA;
  m_SearchForm->setPars(_ParsFRA);
  _Res = m_SearchForm->ShowModal();
  if(_Res == mrOk)
  {
   _IdHarm = m_Finder->getCurrHarm();
  }
 }
 return _Res;
}
//---------------------------------------------------------------------------
void HarmFinderCTRL::close(void)
{
 m_Finder->close();
}
//---------------------------------------------------------------------------
void __fastcall HarmFinderCTRL::searchBTClick(TObject *Sender)
{
}
