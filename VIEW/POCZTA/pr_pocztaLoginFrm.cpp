//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pr_pocztaLoginFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdExplicitTLSClientServerBase"
#pragma link "IdMessage"
#pragma link "IdMessageClient"
#pragma link "IdPOP3"
#pragma link "IdSMTP"
#pragma link "IdSMTPBase"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "AdvGroupBox"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_pocztaLoginFrm::T_pocztaLoginFrm(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaLoginFrm::setSerwer(const AnsiString& aTxt)
{
 edSerwer->Text = aTxt;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaLoginFrm::setPort(const AnsiString& aTxt)
{
 edPort->Text = aTxt;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaLoginFrm::setKonto(const AnsiString& aTxt)
{
 edKonto->Text = aTxt;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaLoginFrm::setHaslo(const AnsiString& aTxt)
{
 edHaslo->Text = aTxt;
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_pocztaLoginFrm::getSerwer(void)
{
 return AnsiString(edSerwer->Text);
}
//---------------------------------------------------------------------------
int __fastcall T_pocztaLoginFrm::getPort(void)
{
 return StrToInt(edPort->Text);
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_pocztaLoginFrm::getKonto(void)
{
 return AnsiString(edKonto->Text);
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_pocztaLoginFrm::getHaslo(void)
{
 return AnsiString(edHaslo->Text);
}
//---------------------------------------------------------------------------
TIdPOP3* __fastcall T_pocztaLoginFrm::getIdPOP3(void)
{
 return IdPOP31;
}
//---------------------------------------------------------------------------
TIdSMTP* __fastcall T_pocztaLoginFrm::getIdSMTP(void)
{
 return IdSMTP1;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaLoginFrm::setReadOnly(bool aState)
{
   edSerwer->ReadOnly = aState;
   edPort->ReadOnly = aState;
   edKonto->ReadOnly = aState;
   edHaslo->ReadOnly = aState;
}
//---------------------------------------------------------------------------
