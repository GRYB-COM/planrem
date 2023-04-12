//---------------------------------------------------------------------------

#ifndef pr_pocztaSmtpFraH
#define pr_pocztaSmtpFraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pr_kBase0FRM.h"
#include "pr_pocztaLoginFrm.h"
#include <Buttons.hpp>
#include "IdBaseComponent.hpp"
#include "IdMessage.hpp"
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <AppEvnts.hpp>
#include "AdvGlowButton.hpp"
#include "AdvGroupBox.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvOfficeStatusBar.hpp"
//---------------------------------------------------------------------------
class T_pocztaSmtpFra : public TprBase0FRM
{
__published:	// IDE-managed Components
	TIdMessage *IdMessage1;
	TOpenDialog *m_openDialog;
	TApplicationEvents *ApplicationEvents1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	T_pocztaLoginFrm *m_pocztaLoginFrm;
	TAdvGroupBox *AdvGroupBox1;
	TAdvGlowButton *bbWyslij;
	TAdvGroupBox *m_MessageGroup;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *edDo;
	TEdit *edTemat;
	TListBox *m_zalaczniki;
	TLabel *Label1;
	TLabel *Label5;
	TMemo *m_wiadomosc;
	TAdvOfficeStatusBar *m_statusBar;
	TAdvGlowButton *bbDodaj;
	TAdvGlowButton *bbUsun;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bbDodajClick(TObject *Sender);
	void __fastcall bbWyslijClick(TObject *Sender);
	void __fastcall bbUsunClick(TObject *Sender);
	void __fastcall ApplicationEvents1Message(tagMSG &Msg, bool &Handled);
private:	// User declarations
	void __fastcall prepLaczeSMTP(void);
	bool m_receivePasswd;
public:		// User declarations
	__fastcall T_pocztaSmtpFra(TComponent* Owner);
	__fastcall ~T_pocztaSmtpFra();

	void setReceivePasswd(bool aVal);
};

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
