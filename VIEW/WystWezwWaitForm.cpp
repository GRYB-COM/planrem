//---------------------------------------------------------------------------
#pragma hdrstop
#include "WystWezwWaitForm.h"
#include "WystWezwFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
WystWezwWaitForm::WystWezwWaitForm(T_WystWezwFRM * _Form)
{
 m_WaitForm = _Form;
}
//---------------------------------------------------------------------------
WystWezwWaitForm::~WystWezwWaitForm(void)
{

}
//---------------------------------------------------------------------------
void WystWezwWaitForm::start(const int _Max)
{
 if(m_WaitForm) m_WaitForm->start(_Max);
}
//---------------------------------------------------------------------------
void WystWezwWaitForm::step(const AnsiString& _Capt)
{
  if(m_WaitForm) m_WaitForm->step(_Capt);
}
//---------------------------------------------------------------------------
void WystWezwWaitForm::stop(void)
{
  if(m_WaitForm) m_WaitForm->stop();
}


