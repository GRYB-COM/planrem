//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NowePowiadFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
T_NowePowiadFRM *_NowePowiadFRM;
//---------------------------------------------------------------------------
__fastcall T_NowePowiadFRM::T_NowePowiadFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_NowePowiadFRM::AdvSmoothButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall T_NowePowiadFRM::AdvSmoothButton1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

