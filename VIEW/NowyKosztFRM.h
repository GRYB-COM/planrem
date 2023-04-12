//---------------------------------------------------------------------------

#ifndef NowyKosztFRMH
#define NowyKosztFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
//---------------------------------------------------------------------------
class T_NowyKosztFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *AdvSmoothButton4;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TLabel *Label5;
	TLabel *Label9;
	TEdit *Edit4;
	TEdit *Edit5;
	void __fastcall AdvSmoothButton4Click(TObject *Sender);
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_NowyKosztFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_NowyKosztFRM *_NowyKosztFRM;
//---------------------------------------------------------------------------
#endif
