//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KosztyFRA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"
T_KosztyFRA *_KosztyFRA;
//---------------------------------------------------------------------------
__fastcall T_KosztyFRA::T_KosztyFRA(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_KosztyFRA::open(const msg::MagID& _MagID)
{
  Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall T_KosztyFRA::close(void)
{
 Visible = false;
}

