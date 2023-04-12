//---------------------------------------------------------------------------

#ifndef pr_pocztaPopFraH
#define pr_pocztaPopFraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "pr_kBase0FRM.h"
#include "pr_pocztaLoginFrm.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include "IdBaseComponent.hpp"
#include "IdMessage.hpp"
#include "AdvGlowButton.hpp"
#include "AdvGroupBox.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvOfficeStatusBar.hpp"
#include "AdvSplitter.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------

class T_pocztaPopFra : public TprBase0FRM
{
__published:	// IDE-managed Components
	TSaveDialog *m_saveDialog;
	TIdMessage *IdMessage1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	T_pocztaLoginFrm *m_pocztaLoginFrm;
	TAdvGroupBox *AdvGroupBox1;
	TAdvGlowButton *bbSprawdz;
	TAdvGlowButton *bbOdbierz;
	TAdvGlowButton *bbRozlacz;
	TAdvGroupBox *AdvGroupBox2;
	TAdvGlowButton *bbOdpowiedz;
	TAdvGlowButton *bbPrzeslij;
	TAdvGlowButton *bbNowa;
	TAdvGlowButton *bbUsun;
	TAdvOfficeStatusBar *m_statusBar;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvSmoothPanel *AdvSmoothPanel3;
	TLabel *Label1;
	TAdvGlowButton *bbZapisz;
	TListBox *m_zalaczniki;
	TAdvSmoothPanel *AdvSmoothPanel4;
	TListView *m_listaWiadomosci;
	TMemo *m_wiadomosc;
	TAdvSplitter *AdvSplitter1;
	void __fastcall m_listaWiadomosciSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall m_saveDialogCanClose(TObject *Sender, bool &CanClose);
	void __fastcall bbZapiszClick(TObject *Sender);
	void __fastcall bbUsunClick(TObject *Sender);
	void __fastcall bbOdpowiedzClick(TObject *Sender);
	void __fastcall bbPrzeslijClick(TObject *Sender);
	void __fastcall bbRozlaczClick(TObject *Sender);
	void __fastcall bbOdbierzClick(TObject *Sender);
	void __fastcall bbSprawdzClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall bbNowaClick(TObject *Sender);

private:	// User declarations
	void __fastcall saveZalacznik(const AnsiString &aFileName);
	void __fastcall prepLaczePOP3(void);
	void __fastcall sprawdzPOP3(void);
	void __fastcall pobierzPOP3(bool anOnlyHeaders = false);
	void __fastcall rozlaczPOP3(void);
	//typedef void __fastcall (__closure *TNotifyEvent)(System::TObject* Sender);
	bool (__closure *on_zapisz)(const AnsiString &aFileName,TIdMessage *aMsg,int anItem);
public:		// User declarations

	__fastcall T_pocztaPopFra(TComponent* Owner);
	void __fastcall registerOnZapisz(bool (__closure *src)(const AnsiString &aFileName,TIdMessage *aMsg,int anItem));
};

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
