//---------------------------------------------------------------------------

#ifndef MainMenuH
#define MainMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "AdvSmoothPanel.hpp"
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <pngimage.hpp>
#include <ToolWin.hpp>
#include <StdCtrls.hpp>
#include "Numedit.h"
#include <InvokeRegistry.hpp>
#include <Rio.hpp>
#include <SOAPHTTPClient.hpp>
#include "rtflabel.hpp"
#include "MANAGER\is_exceptions.h"
#include <Dialogs.hpp>
/*#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothMegaMenu.hpp"
#include <Menus.hpp>
#include "IBDatabase.hpp"
#include <DB.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <pngimage.hpp> */
//---------------------------------------------------------------------------
namespace Wordcs { class TWordApplication; }
class T_MainMenu : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TMainMenu *MainMenu1;
	TMenuItem *Konfiguracja1;
	TMenuItem *m_ParsTMI;
	TMenuItem *S1;
	TMenuItem *Koniec1;
	TMenuItem *Zmianaroku1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *Osoby1;
	TMenuItem *Stopniewojskowe1;
	TMenuItem *Stanowiska1;
	TMenuItem *JednostkiWojskowe1;
	TMenuItem *Oddzia1;
	TMenuItem *Wydzialy1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *Rodzajepowiadomien1;
	TMenuItem *Sprzet1;
	TMenuItem *Rodzajesprzetu1;
	TMenuItem *Grupysprzetu1;
	TMenuItem *Sprzet2;
	TMenuItem *Dodaj1;
	TMenuItem *Kartoteka1;
	TMenuItem *Zestawienia1;
	TMenuItem *m_PlanZestTMI;
	TMenuItem *m_MeldTygTMI;
	TMenuItem *m_FunPomTMI;
	TMenuItem *N7;
	TMenuItem *m_ImportMdbTMI;
	TMenuItem *m_SprawTMI;
	TMenuItem *m_SprawKwartTMI;
	TImageList *ImageList1;
	TControlBar *ControlBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton5;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolBar *ToolBar2;
	TToolButton *ToolButton4;
	TToolButton *ToolButton6;
	TImage *Image1;
	TMenuItem *m_GenSQRTMI;
	TMenuItem *Kodyusug1;
	TMenuItem *m_PlanTMI;
	TMenuItem *m_EwidPlanTMI;
	TMenuItem *m_ProjPlanuTMI;
	TMenuItem *m_PlanArchTMI;
	TMenuItem *m_PlanArch2010TMI;
	TMenuItem *Komorki1;
	TMenuItem *est1;
	TMenuItem *m_MozlRemTMI;
	TMenuItem *m_PotrzRemTMI;
	TMenuItem *m_RBH4OsTMI;
	TMenuItem *m_KadraTMI;
	TMenuItem *m_PlanKwartTMI;
	TMenuItem *m_BilMozlProdTMI;
	TMenuItem *Kwartalnyplanzada1;
	TMenuItem *m_SprMiesTMI;
	TMenuItem *m_PowiadGroupTMI;
	TMenuItem *m_MiesTMI;
	TMenuItem *m_SlowZwTMI;
	TMenuItem *N8;
	TMenuItem *m_SlowDokTMI;
	TMenuItem *Bilansmoliwociwarsztatu1;
	TMenuItem *m_KwMozlWarSprzTMI;
	TMenuItem *m_RBH4MiesTMI;
	TMenuItem *m_HarmDostTMI;
	TMenuItem *m_PrzyjSprzTMI;
	TMenuItem *m_WydSprzTMI;
	TMenuItem *m_RemTMI;
	TMenuItem *N9;
	TMenuItem *m_AdmTMI;
	TMenuItem *m_RejTMI;
	TMenuItem *m_SynchTMI;
	TMenuItem *N10;
	TMenuItem *m_PowDostTMI;
	TMenuItem *m_PowRemTMI;
	TRTFLabel *RTFLabel1;
	TMenuItem *m_ExpTMI;
	TMenuItem *m_ImpTMI;
	TMenuItem *m_SlowKosztTMI;
	TMenuItem *m_ChangeOpTMI;
	TMenuItem *m_QRPPrevTMI;
	TMenuItem *N11;
	TMenuItem *EksportplanudobazydanychMSAccess1;
	TMenuItem *UruchaminieskryptwSPT1;
	TOpenDialog *odNaprSpt;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *m_RozlRBHTMI;
	TMenuItem *N20101;
	TMenuItem *N20091;
	TMenuItem *N20081;
	TMenuItem *N20071;
	TMenuItem *N20061;
	TMenuItem *N20051;
	TMenuItem *m_RozlMiesGodzTMI;
	TLabel *m_RokLB;
	TMenuItem *m_SprRoczTMI;
	TMenuItem *m_SprPolTMI;
	TMenuItem *m_PlanFromMdbTMI;
	TMenuItem *Korektaplanu1;
	TLabel *m_GlownyLB;
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
	void __fastcall Kartoteka1Click(TObject *Sender);
	void __fastcall m_MeldTygTMIClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_ImportMdbTMIClick(TObject *Sender);
	void __fastcall m_SprawKwartTMIClick(TObject *Sender);
	void __fastcall ToolButton4Click(TObject *Sender);
	void __fastcall Stopniewojskowe1Click(TObject *Sender);
	void __fastcall Stanowiska1Click(TObject *Sender);
	void __fastcall Oddzia1Click(TObject *Sender);
	void __fastcall Rodzajepowiadomien1Click(TObject *Sender);
	void __fastcall Grupysprzetu1Click(TObject *Sender);
	void __fastcall m_GenSQRTMIClick(TObject *Sender);
	void __fastcall JednostkiWojskowe1Click(TObject *Sender);
	void __fastcall Wydzialy1Click(TObject *Sender);
	void __fastcall Rodzajesprzetu1Click(TObject *Sender);
	void __fastcall Sprzet1Click(TObject *Sender);
	void __fastcall Kodyusug1Click(TObject *Sender);
	void __fastcall Osoby1Click(TObject *Sender);
	void __fastcall m_EwidPlanTMIClick(TObject *Sender);
	void __fastcall m_ProjPlanuTMIClick(TObject *Sender);
	void __fastcall m_PlanArch2010TMIClick(TObject *Sender);
	void __fastcall Komorki1Click(TObject *Sender);
	void __fastcall est1Click(TObject *Sender);
	void __fastcall m_MozlRemTMIClick(TObject *Sender);
	void __fastcall m_PotrzRemTMIClick(TObject *Sender);
	void __fastcall m_RBH4OsTMIClick(TObject *Sender);
	void __fastcall m_KadraTMIClick(TObject *Sender);
	void __fastcall m_PlanKwartTMIClick(TObject *Sender);
	void __fastcall m_BilMozlProdTMIClick(TObject *Sender);
	void __fastcall Kwartalnyplanzada1Click(TObject *Sender);
	void __fastcall m_SprMiesTMIClick(TObject *Sender);
	void __fastcall Dodaj1Click(TObject *Sender);
	void __fastcall m_PowRemTMIClick(TObject *Sender);
	void __fastcall m_MiesTMIClick(TObject *Sender);
	void __fastcall m_SlowZwTMIClick(TObject *Sender);
	void __fastcall m_SlowDokTMIClick(TObject *Sender);
	void __fastcall Bilansmoliwociwarsztatu1Click(TObject *Sender);
	void __fastcall m_KwMozlWarSprzTMIClick(TObject *Sender);
	void __fastcall m_RBH4MiesTMIClick(TObject *Sender);
	void __fastcall m_HarmDostTMIClick(TObject *Sender);
	void __fastcall m_PrzyjSprzTMIClick(TObject *Sender);
	void __fastcall m_WydSprzTMIClick(TObject *Sender);
	void __fastcall m_RemTMIClick(TObject *Sender);
	void __fastcall m_RejTMIClick(TObject *Sender);
	void __fastcall m_PowDostTMIClick(TObject *Sender);
	void __fastcall m_ParsTMIClick(TObject *Sender);
	void __fastcall m_ImpTMIClick(TObject *Sender);
	void __fastcall m_ExpTMIClick(TObject *Sender);
	void __fastcall m_SlowKosztTMIClick(TObject *Sender);
	void __fastcall m_ChangeOpTMIClick(TObject *Sender);
	void __fastcall m_QRPPrevTMIClick(TObject *Sender);
	void __fastcall EksportplanudobazydanychMSAccess1Click(TObject *Sender);
	void __fastcall UruchaminieskryptwSPT1Click(TObject *Sender);
	void __fastcall m_RozlRBHTMIClick(TObject *Sender);
	void __fastcall ShowArchPlan(TObject *Sender);
	void __fastcall m_RozlMiesGodzTMIClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall runRoczneSpr(TObject *Sender);
	void __fastcall m_PlanFromMdbTMIClick(TObject *Sender);
	void __fastcall Korektaplanu1Click(TObject *Sender);
private:	// User declarations
void __fastcall avEventsException(TObject* Sender, Exception * E);
void __fastcall setMngForms(TObject *Sender);
void __fastcall btDrukujErrClick(TObject *Sender);
Wordcs::TWordApplication * m_Word;
public:		// User declarations

	__fastcall T_MainMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_MainMenu *_MainMenu;
//---------------------------------------------------------------------------
#endif
