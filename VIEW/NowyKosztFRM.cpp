//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NowyKosztFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
T_NowyKosztFRM *_NowyKosztFRM;
//---------------------------------------------------------------------------
__fastcall T_NowyKosztFRM::T_NowyKosztFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_NowyKosztFRM::AdvSmoothButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall T_NowyKosztFRM::AdvSmoothButton1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

