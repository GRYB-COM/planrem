//---------------------------------------------------------------------------
#pragma hdrstop
#include "WaitFRMFCD.h"
#include "WaitFRM.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace importmdb;
//---------------------------------------------------------------------------
WaitFRMFCD::WaitFRMFCD(void)
{
  m_Form = new T_WaitFRM(NULL);
}
//---------------------------------------------------------------------------
WaitFRMFCD::~WaitFRMFCD(void)
{
  delete m_Form;
}
//---------------------------------------------------------------------------
void WaitFRMFCD::start(const int _Max)
{
 m_Form->start(_Max);
}
//---------------------------------------------------------------------------
void WaitFRMFCD::step(const AnsiString& _Capt)
{
  m_Form->step(_Capt);
}
//---------------------------------------------------------------------------
void WaitFRMFCD::stop(void)
{
 m_Form->stop();
}
//---------------------------------------------------------------------------
void WaitFRMFCD::display(void)
{

 m_Form->Show();
}
//---------------------------------------------------------------------------
void WaitFRMFCD::hide(void)
{
 m_Form->Close();
}

