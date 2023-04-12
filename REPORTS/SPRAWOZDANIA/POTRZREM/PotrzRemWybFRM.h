//---------------------------------------------------------------------------

#ifndef PotrzRemWybFRMH
#define PotrzRemWybFRMH
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

class T_PotrzRemWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *m_RokLB;
	TEdit *m_RokED;
	TLabel *m_WydzialLB;
	TDBLookupComboBox *m_WydzialCB;
	TLabel *m_WarLB;
	TDBLookupComboBox *m_WarCB;
	TDataSource *m_WydzialDS;
	TDataSource *m_WarDS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_WydzialCBCloseUp(TObject *Sender);
public:
		//ITERFEJS
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_PotrzRemWybFRM(TComponent* Owner);
		  __fastcall ~T_PotrzRemWybFRM(void);
private:
		//NARZEDZIA
		  mng::StreamDB    * m_WydzialSDB;
		  mng::StreamDB    * m_WarSDB;
		  jbutils::TMyIni  * m_Ini;
};
}//end namespace porgzest
//---------------------------------------------------------------------------
#endif
