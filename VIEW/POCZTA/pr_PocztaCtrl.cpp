//---------------------------------------------------------------------------
#pragma hdrstop
#include "pr_PocztaCtrl.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <memory>
#include <isManager.h>
//#include "wi_pocztaPopFra.h"
#include "jbutils.h"
#include "pr_ToWizjaJB.h"
#include "pr_ImporterWizjaJB.h"
#include "pr_ExporterWizjaJB.h"
#include "pr_FromWizjaJB.h"

//---------------------------------------------------------------------------
void PocztaCtrl::eksport(TComponent* Owner)
{
  jbutils::TMyIni mi;
  if(mi.ReadIniBool("Eksport", "GLOWNY", false))
  {
	std::auto_ptr<T_ToWizjaJBFRM>fm(new T_ToWizjaJBFRM(Owner));
	fm->ShowModal();
  }
  else
  {
	std::auto_ptr<T_ExporterWizjaJB>fm(new T_ExporterWizjaJB(Owner));
	fm->ShowModal();
  }

}

//---------------------------------------------------------------------------
void PocztaCtrl::import(TComponent* Owner)
{
  jbutils::TMyIni mi;
  if(mi.ReadIniBool("Eksport", "GLOWNY", false))
  {
	std::auto_ptr<T_FromWizjaJBFRM>fm(new T_FromWizjaJBFRM(Owner));
	fm->ShowModal();
  }
  else
  {
	T_ImporterWizjaJB::execute(Owner);
  }
}
//---------------------------------------------------------------------------
