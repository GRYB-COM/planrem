//---------------------------------------------------------------------------

#ifndef StSprzWybFRMH
#define StSprzWybFRMH
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
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace mng      { class StreamDB; }
namespace jbutils  { class TMyIni;   }
//---------------------------------------------------------------------------
namespace progzest{

class T_StSprzWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *m_WarLB;
	TDBLookupComboBox *m_WarCB;
	TDataSource *m_WarDS;
	TDateTimePicker *m_DataDoDTP;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
public:
		//ITERFEJS
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_StSprzWybFRM(TComponent* Owner);
		  __fastcall ~T_StSprzWybFRM(void);
private:
		//NARZEDZIA
		  mng::StreamDB    * m_WarSDB;
		  jbutils::TMyIni  * m_Ini;
};
}//end namespace porgzest
//---------------------------------------------------------------------------
#endif
