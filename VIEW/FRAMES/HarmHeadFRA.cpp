//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HarmHeadFRA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
T_HarmHeadFRA *_HarmHeadFRA;
//---------------------------------------------------------------------------
__fastcall T_HarmHeadFRA::T_HarmHeadFRA(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void   __fastcall open(void);
//---------------------------------------------------------------------------
int    __fastcall getID(void)const;
//---------------------------------------------------------------------------
void   __fastcall setID(const int _ID);
//---------------------------------------------------------------------------
String __fastcall getOpis(void) const;
