//---------------------------------------------------------------------------

#ifndef MagFRMH
#define MagFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothMegaMenu.hpp"
#include "NaglMagFRA.h"
#include "SzukajFRA.h"
#include "KosztyFRA.h"
#include "PowiadomFRA.h"
#include "AdvSmoothButton.hpp"
#include "KutyFRA.h"
#include "ListaMAGFRA.h"
#include "AdvSmoothTabPager.hpp"
#include "DokFRA.h"
#include "KUTkosztySumFRA.h"
#include "KUTkosztyFRA.h"
//---------------------------------------------------------------------------
class T_MagFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottP;
	T_SzukajFRA *m_SzukajFRA;
	TAdvSmoothButton *AdvSmoothButton3;
	TAdvSmoothPanel *m_MainP;
	TAdvSmoothPanel *m_RightP;
	T_KosztyFRA *m_KosztyFRA;
	T_PowiadomFRA *m_PowiadomFRA;
	T_KutyFRA *m_KutyFRA;
	TAdvSmoothPanel *m_LeftP;
	TAdvSmoothButton *m_KUTBT;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothButton *AdvSmoothButton4;
	TAdvSmoothPanel *m_TopP;
	T_NaglMagFRA *m_NaglMagFRA;
	TAdvSmoothButton *m_NewMagBT;
	TAdvSmoothButton *m_EditMagBT;
	TAdvSmoothButton *m_CloseMagBT;
	T_DokFRA *m_DokFRA;
	TAdvSmoothPanel *AdvSmoothPanel5;
	T_KUTkosztySumFRA *m_SumKosztyFRA;
	TLabel *Label21;
	TAdvSmoothButton *m_DelSprzBB;
	void __fastcall _KosztyFRA1AdvSmoothButton1Click(TObject *Sender);
	void __fastcall _PowiadomFRA1AdvSmoothButton1Click(TObject *Sender);
	void __fastcall m_MegaMenuClick(TObject *Sender);
	void __fastcall _KosztyFRA1AdvSmoothButton2Click(TObject *Sender);
	void __fastcall _PowiadomFRA1AdvSmoothButton2Click(TObject *Sender);
	void __fastcall AdvSmoothButton3Click(TObject *Sender);
	void __fastcall m_KUTBTClick(TObject *Sender);
	void __fastcall AdvSmoothButton4Click(TObject *Sender);
	void __fastcall m_DelSprzBBClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_KutyFRAm_NewBTClick(TObject *Sender);
	void __fastcall m_KutyFRAm_EditBTClick(TObject *Sender);
	void __fastcall m_KutyFRAm_DelBTClick(TObject *Sender);
public:
		//INTERFEJS
		  void       __fastcall show(const msg::MagID& _MagID);
		  msg::MagID __fastcall getID(void) const;
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall T_MagFRM(TComponent* Owner);
		  __fastcall ~T_MagFRM();
private:
		//METODY POMOCNICZE
		  void __fastcall runOnFindSprzet(const msg::MagID& _MagID);
		  void __fastcall closeFrames(void);
	   //ATRYBUTY
		 msg::MagID * m_MagID;
	   //ZABRONIONE
		 virtual int __fastcall ShowModal(void) { return TForm::ShowModal(); }

};
//---------------------------------------------------------------------------
#endif
