//---------------------------------------------------------------------------
#pragma hdrstop
#include "RozlGodzSQRHdlr.h"
#include "..\EDITORS\RozlGodzEditor.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace handlers;
//---------------------------------------------------------------------------
RozlGodzSQRHdlr::RozlGodzSQRHdlr(void)
{
}
//---------------------------------------------------------------------------
RozlGodzSQRHdlr::~RozlGodzSQRHdlr(void)
{
}
//---------------------------------------------------------------------------
bool RozlGodzSQRHdlr::execute(const sqr::SQRScript &aSkrypt)
{
 editors::RozlGodzEditor::Pars _Pars;
 editors::RozlGodzEditor::instance().run(_Pars);
 return true;
}
//---------------------------------------------------------------------------
bool RozlGodzSQRHdlr::checkCode(AnsiString code)
{
 return code == "ROZL_GODZ";
}
//---------------------------------------------------------------------------

