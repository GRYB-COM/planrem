//---------------------------------------------------------------------------
#ifndef SprRoczneWybFRMH
#define SprRoczneWybFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FCSWYB.h"
#include "PopupButton.h"
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
namespace mng      { class StreamDB; }
namespace jbutils  { class TMyIni;   }
//---------------------------------------------------------------------------
namespace progzest{

class T_SprRoczneWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *m_RokLB;
	TEdit *m_RokED;
	TLabel *Label1;
	TRadioGroup *m_SprRG;
	TComboBox *m_PolRokCB;
	TCheckBox *m_InfoCB;
	TCheckBox *m_NewZestCB;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_SprRGClick(TObject *Sender);
public:
		//KLASY WEWNÊTRZNE
          enum RodzSpr {rsPRok=0, rsRok };
		//ITERFEJS
          int __fastcall display(const RodzSpr& _RodzSpr);
		  int __fastcall getRok(void);
		  int __fastcall getMiesOd(void);
		  int __fastcall getMiesDo(void);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_SprRoczneWybFRM(TComponent* Owner);
		  __fastcall ~T_SprRoczneWybFRM(void);
private:
		//NARZEDZIA
		  jbutils::TMyIni  * m_Ini;
		//ZABRONIONE
		  virtual int __fastcall ShowModal(void) {return T_FCUSTWYB::ShowModal(); }
};
}//end namespace porgzest
//---------------------------------------------------------------------------
#endif
