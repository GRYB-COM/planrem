//---------------------------------------------------------------------------

#ifndef PlanKwartZadWybFRMH
#define PlanKwartZadWybFRMH
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

class T_PlanKwartZadWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *m_RokLB;
	TEdit *m_RokED;
	TLabel *m_WarLB;
	TDBLookupComboBox *m_WarCB;
	TDataSource *m_WarDS;
	TLabel *Label1;
	TComboBox *m_MiesOdCB;
	TLabel *Label2;
	TComboBox *m_MiesDoCB;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_MiesOdCBCloseUp(TObject *Sender);
public:
		//ITERFEJS
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_PlanKwartZadWybFRM(TComponent* Owner);
		  __fastcall ~T_PlanKwartZadWybFRM(void);
private:
		//NARZEDZIA
		  mng::StreamDB    * m_WarSDB;
		  jbutils::TMyIni  * m_Ini;
};
}//end namespace porgzest
//---------------------------------------------------------------------------
#endif
