//---------------------------------------------------------------------------

#ifndef PlanKwartWybFRMH
#define PlanKwartWybFRMH
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

class T_PlanKwartWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *m_RokLB;
	TEdit *m_RokED;
	TLabel *m_WarLB;
	TDBLookupComboBox *m_WarCB;
	TDataSource *m_WarDS;
	TLabel *m_MiesOdLB;
	TComboBox *m_MiesOdCB;
	TLabel *m_MiesDoLB;
	TComboBox *m_MiesDoCB;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_MiesOdCBCloseUp(TObject *Sender);
public:
		//ITERFEJS
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_PlanKwartWybFRM(TComponent* Owner);
		  __fastcall ~T_PlanKwartWybFRM(void);
private:
		//NARZEDZIA
		  mng::StreamDB    * m_WarSDB;
		  jbutils::TMyIni  * m_Ini;
};
}//end namespace porgzest
//---------------------------------------------------------------------------
#endif
