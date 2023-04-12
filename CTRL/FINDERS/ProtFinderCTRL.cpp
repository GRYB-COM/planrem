//---------------------------------------------------------------------------
#pragma hdrstop
#include "ProtFinderCTRL.h"
#include "ProtFinder.h"
#include "MANAGER\message_dlg.h"
#include "FindProtFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace finders;
//---------------------------------------------------------------------------
ProtFinderCTRL::Pars::Pars(void)
:IdProtokolu(-1),
 Rok(-1),
 IdWydzialu(-1)
{

}
//---------------------------------------------------------------------------
ProtFinderCTRL::ProtFinderCTRL(void)
{
 m_Finder      = new ProtFinder();

 m_SearchForm  = new T_FindProtFRM(NULL);
 m_SearchForm->setDataSet(m_Finder->getDataSet());
 m_SearchForm->setSearchClictEvet( searchBTClick);

}
//---------------------------------------------------------------------------
ProtFinderCTRL::~ProtFinderCTRL(void)
{
 delete m_Finder;
 delete m_SearchForm;
}
//---------------------------------------------------------------------------
int ProtFinderCTRL::find(int & _Rok, int& _IdWydz,int & _IdProt, const ProtFinderCTRL::Pars & _Pars)
{
 m_Pars = _Pars;
 open();
 int _Res  = find( _Rok,_IdWydz,_IdProt);
 close();
 return _Res;
}
//---------------------------------------------------------------------------
void ProtFinderCTRL::open(void)
{
 ProtFinder::Pars _ParsF;
 _ParsF.Rok        = m_Pars.Rok;
 _ParsF.IdWydzialu = m_Pars.IdWydzialu;
 m_Finder->open(_ParsF);
}
//---------------------------------------------------------------------------
int ProtFinderCTRL::find(int & _Rok, int& _IdWydz,int & _IdProt)
{
 int _Res(mrOk);
 int _RecCount(m_Finder->getRecordCount());
 if(_RecCount <1)
 {
  mng::MessageDialog::warning("Nie znaleziono ¿adnego protoko³u","OSTRZE¯ENIE");
  _Res = mrCancel;
 }
 else if(_RecCount == 1)
 {
  _Rok    = m_Finder->getCurrRok();
  _IdWydz = m_Finder->getCurrWydz();
  _IdProt = m_Finder->getCurrProt();
 }
 else if( _RecCount >1)
 {
  T_ListaProtFRA::Pars _ParsFRA;
  m_SearchForm->setPars(_ParsFRA);
  _Res = m_SearchForm->ShowModal();
  if(_Res == mrOk)
  {
   _IdProt = m_Finder->getCurrProt();
   _Rok    = m_Finder->getCurrRok();
   _IdWydz = m_Finder->getCurrWydz();
  }
 }
 return _Res;
}
//---------------------------------------------------------------------------
void ProtFinderCTRL::close(void)
{
 m_Finder->close();
}
//---------------------------------------------------------------------------
void __fastcall ProtFinderCTRL::searchBTClick(TObject *Sender)
{
}
