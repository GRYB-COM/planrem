//---------------------------------------------------------------------------
#pragma hdrstop
#include "SprzetFinderCTRL.h"
#include "SprzetFinder.h"
#include "MagID.h"
#include "MANAGER\message_dlg.h"
#include "ListaMagFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
SprzetFinderCTRL::Pars::Pars(void)
:IdMag(),
 IdWydzialu(-1),
 IsFilter(true)
 {

 }
//---------------------------------------------------------------------------
SprzetFinderCTRL::SprzetFinderCTRL(void)
{
 m_Finder      = new SprzetFinder();

 m_SearchForm  = new T_ListaMagFRM(NULL);
 m_SearchForm->setDataSet(m_Finder->getDataSet());
 m_SearchForm->setSearchClictEvet( searchBTClick);

}
//---------------------------------------------------------------------------
SprzetFinderCTRL::~SprzetFinderCTRL(void)
{
 delete m_Finder;
 delete m_SearchForm;
}
//---------------------------------------------------------------------------
int SprzetFinderCTRL::find(msg::MagID& _MagID, const SprzetFinderCTRL::Pars & _Pars)
{
 m_Pars = _Pars;
 open();
 int _Res  = find(_MagID);
 close();
 return _Res;
}
//---------------------------------------------------------------------------
void SprzetFinderCTRL::open(void)
{
 SprzetFinder::Pars _ParsF;
 _ParsF.SygnMag    = m_Pars.IdMag.getSygnMag();
 _ParsF.Rok        = m_Pars.IdMag.Rok;
 _ParsF.IdWydzialu = m_Pars.IdWydzialu;
 m_Finder->open(_ParsF);
}
//---------------------------------------------------------------------------
int SprzetFinderCTRL::find(msg::MagID& _MagID)
{
 int _Res(mrOk);
 int _RecCount(m_Finder->getRecordCount());
 m_SearchForm->m_ListaMagFRA->m_SearchPA->Visible = !m_Pars.IdMag.IsDefined;
 if(_RecCount == 1)
 {
  _MagID = m_Finder->getCurrID();
 }
 else if( _RecCount >1)
 {
  T_ListaMAGFRA::Pars _ParsFRA;
  _ParsFRA.IdMag = m_Pars.IdMag;
  m_SearchForm->setPars(_ParsFRA);
  m_SearchForm->setIsFilter(m_Pars.IsFilter && !m_Pars.IdMag.IsDefined);
  _Res = m_SearchForm->ShowModal();
  if(_Res == mrOk)
  {
   _MagID = m_Finder->getCurrID();
  }
 }
 return _Res;
}
//---------------------------------------------------------------------------
void SprzetFinderCTRL::close(void)
{
 m_Finder->close();
}
//---------------------------------------------------------------------------
void __fastcall SprzetFinderCTRL::searchBTClick(TObject *Sender)
{
 T_ListaMAGFRA::Pars _ParsFRA(m_SearchForm->getPars());
 SprzetFinder::Pars _ParsF;
 _ParsF.SygnMag = _ParsFRA.IdMag.getSygnMag();
 m_Finder->close();
 m_Finder->open(_ParsF);
}
