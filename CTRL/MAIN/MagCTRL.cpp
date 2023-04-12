//---------------------------------------------------------------------------
#pragma hdrstop
#include "MagCTRL.h"
#include "MagFRM.h"
#include "NowyMagFRM.h"
#include <memory>
#include "MagID.h"
#include "KUTEditor.h"
#include "PrzyjSprzFRM.h"
#include "PrzekSprzFRM.h"
#include "MagREC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace main;
//---------------------------------------------------------------------------
MagCTRL::MagCTRL(void)
{
 m_NowyMagFRM = new T_NowyMagFRM(NULL) ;
 m_MagFRM     = new T_MagFRM(NULL);
 m_MagFRM->m_NewMagBT->OnClick  = onNewMagClick;
 m_MagFRM->m_EditMagBT->OnClick = onEditMagClick;

 m_PrzyjFRM  = new T_PrzyjSprzFRM(NULL);
 m_PrzekFRM  = new T_PrzekSprzFRM(NULL);
}
//---------------------------------------------------------------------------
MagCTRL::~MagCTRL(void)
{
 delete m_NowyMagFRM;
 delete m_MagFRM;
 delete m_PrzyjFRM;
 delete m_PrzekFRM;
}
//---------------------------------------------------------------------------
void __fastcall MagCTRL::onNewMagClick(TObject *Sender)
{
 add();
}
//---------------------------------------------------------------------------
void MagCTRL::add(void)
{
 msg::MagID  _MagID;
 msg::MagREC _Pars;
 _Pars.DataPrzyj = Date();
 if(m_NowyMagFRM->show(_MagID,_Pars) == mrOk)
 {
  editors::KUTEditor::create(_MagID);
  m_MagFRM->show(_MagID);
 }
}
//---------------------------------------------------------------------------
void MagCTRL::edit(void)
{
 msg::MagID _MagID;
 m_MagFRM->show(_MagID);
 editors::KUTEditor::updateDost(_MagID);
}
//---------------------------------------------------------------------------
void MagCTRL::edit(const msg::MagID& _Mag)
{
 msg::MagID _MagID(_Mag);
 msg::MagREC _Pars;
 m_NowyMagFRM->show(_MagID,_Pars);
 m_MagFRM->show(_MagID);
 editors::KUTEditor::updateDost(_MagID);
}
//---------------------------------------------------------------------------
void __fastcall MagCTRL::onEditMagClick(TObject *Sender)
{
  msg::MagID _MagID(m_MagFRM->getID());
  edit(_MagID);
   editors::KUTEditor::updateDost(_MagID);
}
//---------------------------------------------------------------------------
void MagCTRL::receive(void)
{
 m_PrzyjFRM->Caption = "Przyjêcie sprzêtu";
 m_PrzyjFRM->m_ProtLB->Caption = "Nr protoko³u przyjêcia:";
 m_PrzyjFRM->setSpIn(true);
 m_PrzyjFRM->m_AddBB->Visible = true;
 m_PrzyjFRM->m_AddBB->OnClick = onAddProtPrzyjClick;
 m_PrzyjFRM->ShowModal();
 m_PrzyjFRM->m_AddBB->OnClick = NULL;
 m_PrzyjFRM->m_AddBB->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall MagCTRL::onAddProtPrzyjClick(TObject *Sender)
{
 msg::MagREC _Pars;
 msg::MagID  _MagID;
 _Pars.ProtPrzyj = m_PrzyjFRM->m_PrPrzyjED->Text;
 _Pars.DataPrzyj = m_PrzyjFRM->m_DataPrzyjDTP->DateTime;
 if(m_NowyMagFRM->show(_MagID,_Pars) == mrOk)
 {
  editors::KUTEditor::create(_MagID);
  m_PrzyjFRM->m_OpenBTClick(m_PrzyjFRM->m_OpenBT);
 }
}
//---------------------------------------------------------------------------
void MagCTRL::issue(void)
{
 m_PrzekFRM->Caption = "Wydanie sprzêtu";
 m_PrzekFRM->m_ProtLB->Caption = "Nr protoko³u przekazania:";


 m_PrzekFRM->ShowModal();
}


