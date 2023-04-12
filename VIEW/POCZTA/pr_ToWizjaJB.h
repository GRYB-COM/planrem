//---------------------------------------------------------------------------

#ifndef pr_ToWizjaJBH
#define pr_ToWizjaJBH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pr_kBase0FRM.h"
#include "AdvGlowButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include "AdvSmoothProgressBar.hpp"
//---------------------------------------------------------------------------
class T_ToWizjaJBFRM : public TprBase0FRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvGlowButton *bbClose;
	TLabel *Label1;
	TLabel *Label2;
	TListView *m_lvWydzialy;
	TEdit *edKatalog;
	TSpeedButton *sbWybierz;
	TSpeedButton *sbOtworz;
	TAdvGlowButton *bbPrepareData;
	TAdvGlowButton *AdvGlowButton2;
	TAdvGlowButton *AdvGlowButton3;
	TAdvGlowButton *AdvGlowButton4;
	TAdvGlowButton *AdvGlowButton5;
	TAdvGlowButton *AdvGlowButton6;
	TAdvSmoothProgressBar *m_progressBar;
	void __fastcall bbCloseClick(TObject *Sender);
	void __fastcall sbOtworzClick(TObject *Sender);
	void __fastcall AdvGlowButton3Click(TObject *Sender);
	void __fastcall AdvGlowButton5Click(TObject *Sender);
	void __fastcall AdvGlowButton4Click(TObject *Sender);
	void __fastcall AdvGlowButton6Click(TObject *Sender);
	void __fastcall sbWybierzClick(TObject *Sender);
	void __fastcall bbPrepareDataClick(TObject *Sender);
	void __fastcall AdvGlowButton2Click(TObject *Sender);
private:	// User declarations
	bool __fastcall prepDir(AnsiString aDir);
	bool __fastcall prepData(int aID,AnsiString aFileName);
	void __fastcall sendEmails(void);
public:		// User declarations
	__fastcall T_ToWizjaJBFRM(TComponent* Owner);
	__fastcall ~T_ToWizjaJBFRM();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
