//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestAcc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Access_2K_SRVR"
#pragma link "Numedit"
#pragma resource "*.dfm"
TTestFRM *TestFRM;
//---------------------------------------------------------------------------
__fastcall TTestFRM::TTestFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTestFRM::Button1Click(TObject *Sender)
{

 Variant  Access;
 try
 {
 Access = GetActiveOleObject("Access.Application");
 }
 catch(...)
 {
  Access = CreateOleObject("Access.Application");
 }
 Variant DoCmd = Access.OlePropertyGet("DoCmd");
 DoCmd.OleFunction("Maximize");
 try
 {
  Access.OleFunction("OpenCurrentDatabase","C:\\PLAN_REM.mdb");
 }
 catch(...) {}
 DoCmd.OleFunction("OpenReport","Magazyn",2);
 DoCmd.OleFunction("Maximize");
 Access.OlePropertySet("Visible",True);
}
//---------------------------------------------------------------------------

