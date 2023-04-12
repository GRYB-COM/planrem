//---------------------------------------------------------------------------

#ifndef pr_kBase0FRMH
#define pr_kBase0FRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------

class TprBase0FRM : public TForm
{
__published:	// IDE-managed Components
protected:
	bool __fastcall GoToNextCtrl(TObject *Sender,WORD &Key );
	void __fastcall setEnabled(TWinControl *aControl, bool aEnabled);
private:	// User declarations

public:		// User declarations
	__fastcall TprBase0FRM(TComponent* Owner);
	__fastcall TprBase0FRM(HWND ParentWindow);
};

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
