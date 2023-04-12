//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PowiadomFRA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"
T_PowiadomFRA *_PowiadomFRA;
//---------------------------------------------------------------------------
__fastcall T_PowiadomFRA::T_PowiadomFRA(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_PowiadomFRA::open(const msg::MagID& _MagID)
{
  Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall T_PowiadomFRA::close(void)
{
  Visible = false;
}

