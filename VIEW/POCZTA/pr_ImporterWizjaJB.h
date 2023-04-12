//---------------------------------------------------------------------------

#ifndef pr_ImporterWizjaJBH
#define pr_ImporterWizjaJBH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothProgressBar.hpp"
#include <Dialogs.hpp>
#include "AdvGlowButton.hpp"

//---------------------------------------------------------------------------
class T_ImporterWizjaJB : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *m_OpenDialog;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothProgressBar *m_progressBar;
	TAdvGlowButton *bbPrepareData;
	TLabel *m_CaptLB;
	TLabel *m_WarLB;
	TAdvGlowButton *bbClose;
	TLabel *m_DataLB;
	void __fastcall bbPrepareDataClick(TObject *Sender);
	void __fastcall bbCloseClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_ImporterWizjaJB(TComponent* Owner);
	static void __fastcall execute(TComponent* Owner);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
