//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WaitFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace importmdb;
//---------------------------------------------------------------------------
__fastcall T_WaitFRM::T_WaitFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_WaitFRM::start(const int _Max)
{
  m_LabelLB->Caption ="";
  m_ProgressPB->Min =0;
  m_ProgressPB->Max = _Max;
  Update();
  Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall T_WaitFRM::step (const AnsiString & _Capt)
{
 m_LabelLB->Caption = _Capt;
 m_ProgressPB->StepIt();
 BringToFront();
 Update();
 Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void __fastcall T_WaitFRM::stop(void)
{
 start(0);
}
//---------------------------------------------------------------------------
void __fastcall T_WaitFRM::FormShow(TObject *Sender)
{
start(0);
}
//---------------------------------------------------------------------------
