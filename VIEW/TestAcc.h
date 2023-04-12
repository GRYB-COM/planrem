//---------------------------------------------------------------------------

#ifndef TestAccH
#define TestAccH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Access_2K_SRVR.h"
#include <OleServer.hpp>
#include <OleCtnrs.hpp>
#include "Numedit.h"
//---------------------------------------------------------------------------
class TTestFRM : public TForm
{
__published:	// IDE-managed Components
	TNumEdit *NumEdit1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TTestFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTestFRM *TestFRM;
//---------------------------------------------------------------------------
#endif
