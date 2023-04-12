//---------------------------------------------------------------------------

#ifndef NowePowiadFRMH
#define NowePowiadFRMH
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
class T_NowePowiadFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *AdvSmoothButton4;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TLabel *Label2;
	TLabel *Label5;
	TLabel *Label9;
	TComboBox *ComboBox1;
	TEdit *Edit5;
	TAdvSmoothDatePicker *AdvSmoothDatePicker1;
	void __fastcall AdvSmoothButton4Click(TObject *Sender);
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_NowePowiadFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_NowePowiadFRM *_NowePowiadFRM;
//---------------------------------------------------------------------------
#endif
