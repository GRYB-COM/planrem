// ---------------------------------------------------------------------------
#ifndef SlEditFRMH
#define SlEditFRMH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include "AdvSmoothPanel.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AsgLinks.hpp"
#include "BaseGrid.hpp"
#include "ccedlink.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include "AdvSmoothButton.hpp"

// ---------------------------------------------------------------------------
  namespace mng{class StreamDB;}
  class T_SlEditFRM : public TForm
  {
  __published: // IDE-managed Components
	TPanel* Panel1;
	TDBGrid* m_DBG;
	TDataSource* m_DS;
	TAdvSmoothPanel* m_BottomASP;
	TAdvSmoothButton *m_DodajBB;
	TAdvSmoothButton *m_EdytujBB;
	TAdvSmoothButton *m_UsunBB;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothButton *m_PrintBB;
	TAdvSmoothPanel *m_TopPA;
	TComboBox *m_RokCB;
	TLabel *Label1;

	void __fastcall m_SaveBBClick(TObject* Sender);
	void __fastcall m_DodajBBClick(TObject* Sender);
	void __fastcall m_EdytujBBClick(TObject* Sender);
	void __fastcall m_UsunBBClick(TObject* Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_AnulujBBClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_CancelBBClick(TObject *Sender);
	void __fastcall m_PrintBBClick(TObject *Sender);
	void __fastcall m_RokCBCloseUp(TObject *Sender);

  public:
		//KLASY WEWNÊTRZNE
			enum DicType {
							dtUnknown =-1, dtStopnie = 0, dtRemonty, dtOddzialy,
							dtGrSprzet, dtStanowiska, dtRodzPow,dtKodyUslug,
							dtJednostki, dtSprzet,dtWarsztaty,dtWydzialy,dtRodzSprz,
							dtMiesiace, dtNazwyZw, dtDokumenty, dtKoszty
			};
		//INTERFEJS
			void setDict(DicType _Dict);
		//KONSTRUKTOR DESTRUKTOR
					__fastcall  T_SlEditFRM(TComponent* Owner);
			virtual __fastcall ~T_SlEditFRM();
  protected:
		//NARZÊDIA
		  mng::StreamDB*	m_SDB;
		  TForm        *    m_EditFRM;
		//ATRYBUTY
		  DicType m_Dic;
		  bool    m_ShowAddBB;
		  bool    m_ShowEditBB;
		  bool    m_ShowDelBB;
		//ZDARZENIA
		  virtual void __fastcall onShow(void) {};
		  virtual void __fastcall onClose(void){}
		  virtual void __fastcall afterOpen(void);
		  virtual void __fastcall afterAppend(void);
		         void __fastcall  getNazMies(TField *Sender, UnicodeString &Text, bool DisplayText);

  };

// ---------------------------------------------------------------------------
#endif
