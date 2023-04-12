//---------------------------------------------------------------------------
#pragma hdrstop
#include "WezwMNG.h"
#include "WystWezwFRM.h"
#include "WystWezwWaitForm.h"
#include "PowiadEditor.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
WezwMNG::WezwMNG(void)
{
 m_PowEd     = new editors::PowiadEditor();
 m_ParsFRM   =  new T_WystWezwFRM(NULL);
 m_ParsFRM->setOnChange(open);
 m_ParsFRM->m_DodajBB->OnClick = print;
 m_ParsFRM->m_DelBB->OnClick   = del;
 m_ParsFRM->m_ListaSprzDS->DataSet = m_PowEd->getListaSprz()->getClient();
 m_WaitForm  =  new WystWezwWaitForm(m_ParsFRM);
}
//---------------------------------------------------------------------------
WezwMNG::~WezwMNG(void)
{
 delete m_ParsFRM;
 delete m_WaitForm;
 delete m_PowEd;
}
//---------------------------------------------------------------------------
void WezwMNG::run(void)
{
  m_ParsFRM->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall WezwMNG::open(TObject *Sender)
{
 editors::PowiadEditor::Pars _Pars;
 _Pars.NrPowiad   = m_ParsFRM->m_FiltrWezwRG->ItemIndex;
 _Pars.DataWyst   = m_ParsFRM->m_DataWystDCP->Date;
 _Pars.DataZakDo  = m_ParsFRM->m_DataZakDoDCP->Date;
 _Pars.DataWystOd = m_ParsFRM->m_DataWystOdDCP->Date;
 _Pars.DataWystDo = m_ParsFRM->m_DataWystDoDCP->Date;
 _Pars.Tryb       = m_ParsFRM->m_ModeRG->ItemIndex;
 m_PowEd->close();
 m_PowEd->setPars(_Pars);
 m_PowEd->open();
}
//---------------------------------------------------------------------------
void __fastcall WezwMNG::print(TObject *Sender)
{
 m_PowEd->wystaw();
}
//---------------------------------------------------------------------------
void __fastcall WezwMNG::del(TObject *Sender)
{
 m_PowEd->usun();
}
//---------------------------------------------------------------------------

