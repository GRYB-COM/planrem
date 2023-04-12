//---------------------------------------------------------------------------

#ifndef pr_FromWizjaJBH
#define pr_FromWizjaJBH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pr_kBase0FRM.h"
#include "AdvGlowButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <Buttons.hpp>
#include <AppEvnts.hpp>
#include <Dialogs.hpp>
#include "AdvSmoothProgressBar.hpp"
#include "IdMessage.hpp"
//---------------------------------------------------------------------------

class T_FromWizjaJBFRM : public TprBase0FRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvGlowButton *bbClose;
	TAdvGlowButton *bbSaveData;
	TAdvGlowButton *bbCheckMails;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TSpeedButton *sbOtworz;
	TAdvGlowButton *AdvGlowButton3;
	TAdvGlowButton *AdvGlowButton4;
	TAdvGlowButton *AdvGlowButton5;
	TAdvGlowButton *AdvGlowButton6;
	TOpenDialog *m_openDialog;
	TAdvSmoothProgressBar *m_progressBar;
	TLabel *Label1;
	TLabel *m_plik;
	void __fastcall bbSaveDataClick(TObject *Sender);
	void __fastcall bbCheckMailsClick(TObject *Sender);
	void __fastcall bbCloseClick(TObject *Sender);

private:	// User declarations
	bool __fastcall addFile(const AnsiString &aFileName,bool aShowProgresss = true);
	bool __fastcall checkUchwala(AnsiString aRok,AnsiString aUchwala);
	bool zapiszZalacznik(const AnsiString &aFileName,TIdMessage *aMsg,int anItem);
public:		// User declarations
	__fastcall T_FromWizjaJBFRM(TComponent* Owner);
	__fastcall ~T_FromWizjaJBFRM();
};

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
