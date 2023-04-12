//---------------------------------------------------------------------------
#pragma hdrstop
#include "ImportFromMdbCTRL.h"
#include "SGTOOLS\DATAACCESS\DataMovers.h"
#include "SGTOOLS\DATAACCESS\DataMover.h"
#include "DMODS\AccessDM.h"
#include "MOVERS\JWMover.h"
#include "MOVERS\OddzMover.h"
#include "MOVERS\WydzMover.h"
#include "MOVERS\WarsztatyMover.h"
#include "MOVERS\GrSprzMover.h"
#include "MOVERS\RodzSprzMover.h"
#include "MOVERS\RodzRemMover.h"
#include "MOVERS\SprzMover.h"
#include "KodyUslugMover.h"
#include "PlanMover.h"
#include "MagazynMover.h"
#include "ZlecMover.h"
#include "MANAGER\query_db.h"
#include "ZlecRbhMover.h"
#include "VIEW\WaitFRMFCD.h"
#include "MOVERS\StopnieMover.h"
#include "MOVERS\StanowiskaMover.h"
#include "MOVERS\OsobyMover.h"
#include "MOVERS\PlanMover.h"
#include "ImportFromMdbFRM.h"
#include "ImportPlanFromMdbFRM.h"
#include "platform.h"
#include "DictMNG.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
ImportFromMdbCTRL::ImportFromMdbCTRL(void)
{
 m_DM       = new importmdb::T_AccessDM(NULL);
 m_ParsFRM  = new T_ImportFromMdbFRM(NULL);
 m_ParsFRM->m_RunBB->OnClick = runClick;
 m_ParsPlanFRM  = new T_ImportPlanFromMdbFRM(NULL);
 m_ParsPlanFRM->m_RunBB->OnClick = runPlanClick;
}
//---------------------------------------------------------------------------
ImportFromMdbCTRL::~ImportFromMdbCTRL(void)
{
 delete m_DM;
 delete m_ParsFRM;
 delete m_ParsPlanFRM;
}
//---------------------------------------------------------------------------
void ImportFromMdbCTRL::run(void)
{
 m_ParsFRM->ShowModal();
}
//---------------------------------------------------------------------------
void ImportFromMdbCTRL::runPlan(void)
{
 m_ParsPlanFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall ImportFromMdbCTRL::runClick(TObject *Sender)
{
 try{
 if(setPars())
 {
  try
  {
   sgda::DataMovers _Movers;
   WaitFRMFCD _WaitFRM;
   addMovers(_Movers,&_WaitFRM);
   _WaitFRM.display();
   Application->ProcessMessages();
   _Movers.run();
   _WaitFRM.hide();
  }
  catch(Exception & exc)
  {
	Platform::showException(m_ParsFRM,&exc);

  }
 }
 }__finally{ close(); }
}
//---------------------------------------------------------------------------
void __fastcall ImportFromMdbCTRL::runPlanClick(TObject *Sender)
{
 try{
 if(setPlanPars())
 {
  try
  {
   sgda::DataMovers _Movers;
   WaitFRMFCD _WaitFRM;
   sgda::DataMover::Pars _Pars;
   _Pars.WaitForm = &_WaitFRM;
   _Pars.DataSet = m_DM->m_PlanADO;
   _Movers.add( new sgda::DataMover(new importmdb::PlanMover(),_Pars));

   _WaitFRM.display();
   Application->ProcessMessages();
   _Movers.run();
   _WaitFRM.hide();
   close();
  }
  catch(Exception & exc)
  {
	Platform::showException(m_ParsFRM,&exc);

  }
 }
 }__finally{ close(); }
}
//---------------------------------------------------------------------------
bool ImportFromMdbCTRL::setPars(void)
{
 bool _Res =m_ParsFRM->isRun();
 if(_Res)
 {
  m_DM->setDBPath(m_ParsFRM->getPath());
  m_DM->setIdWydz(m_ParsFRM->getIdWydz());
 }
 return _Res;
}
//---------------------------------------------------------------------------
bool ImportFromMdbCTRL::setPlanPars(void)
{
 bool _Res =m_ParsPlanFRM->isRun();
 if(_Res)
 {
  m_DM->setDBPath(m_ParsPlanFRM->getPath());
  m_DM->setRok(m_ParsPlanFRM->getRok() );
 }
 return _Res;
}
//---------------------------------------------------------------------------
void ImportFromMdbCTRL::addMovers(sgda::DataMovers& _Movers, WaitFRMFCD * _WaitFRM)
{
 std::vector<bool> _Flags = m_ParsFRM->getFlags();
 sgda::DataMover::Pars _Pars;
 _Pars.WaitForm = _WaitFRM;
 if(_Flags[0] )
 {
  _Pars.WaitFormLabel = "Jednostki i komórki organizacyjne";
  _Pars.DataSet = m_DM->m_JWADO;
  _Movers.add( new sgda::DataMover(new importmdb::JWMover(),_Pars));
 }
 if(_Flags[1])
 {
  _Pars.WaitFormLabel = "S³ownik sprzêtu";
  _Pars.DataSet =m_DM->m_SprzetADO;
  _Movers.add( new sgda::DataMover(new importmdb::SprzMover(),_Pars));
 }
 if(_Flags[2])
 {
  _Pars.WaitFormLabel = "Lista przyjêtego sprzêtu";
  _Pars.DataSet =m_DM->m_MagazynADO;
  _Movers.add( new sgda::DataMover(new importmdb::MagazynMover(),_Pars));
 }
 if(_Flags[3])
 {
 _Pars.WaitFormLabel = "Karty us³ug technicznych";
 _Pars.DataSet =m_DM->m_ZleceniaADO;
 _Movers.add( new sgda::DataMover(new importmdb::ZlecMover(),_Pars));
 _Pars.WaitFormLabel = "Wykorzystane roboczogodziny";
 _Pars.DataSet =m_DM->m_ZlecRbhADO;
 _Movers.add( new sgda::DataMover(new importmdb::ZlecRbhMover(),_Pars));
 }
}
//---------------------------------------------------------------------------
void ImportFromMdbCTRL::close(void)
{
  dict::DictMNG::close();
}
//---------------------------------------------------------------------------

