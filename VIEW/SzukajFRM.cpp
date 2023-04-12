//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SzukajFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "ListaMAGFRA"
#pragma resource "*.dfm"
T_SzukajFRM *_SzukajFRM;
//---------------------------------------------------------------------------
__fastcall T_SzukajFRM::T_SzukajFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRM::AdvSmoothButton6Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall T_SzukajFRM::AdvSmoothButton3Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
