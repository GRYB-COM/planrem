//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Test.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Access_2K_SRVR"
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
  AccessApplication1->Connect();
  AccessApplication1->Visible = true;
  String _Path("C:\BAZA\PLAN_REM.MDB");
  Variant _NazRep("Magazyn");
  Variant EmptyParam;
  AccessApplication1->OpenCurrentDatabase(_Path.w_str(), true);
  AccessApplication1->DoCmd->OpenReport(_NazRep, 1, EmptyParam, EmptyParam);
}
//---------------------------------------------------------------------------
