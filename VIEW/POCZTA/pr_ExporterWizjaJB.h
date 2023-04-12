//---------------------------------------------------------------------------

#ifndef pr_ExporterWizjaJBH
#define pr_ExporterWizjaJBH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothProgressBar.hpp"
#include <Dialogs.hpp>
#include "AdvGlowButton.hpp"
#include <ComCtrls.hpp>
#include "IdBaseComponent.hpp"
#include "IdCompressorZLib.hpp"
#include "IdZLibCompressorBase.hpp"

//---------------------------------------------------------------------------
class T_ExporterWizjaJB : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothProgressBar *m_progressBar;
	TSaveDialog *m_SaveDialog;
	TAdvGlowButton *bbClose;
	TAdvSmoothPanel *paMain;
	TLabel *m_CaptLB;
	TAdvGlowButton *bbPrepareData;
	TLabel *m_WarLB;
	void __fastcall bbPrepareDataClick(TObject *Sender);
	void __fastcall bbCloseClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall T_ExporterWizjaJB(TComponent* Owner);
};


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
