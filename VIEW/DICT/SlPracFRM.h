//---------------------------------------------------------------------------

#ifndef SlPracFRMH
#define SlPracFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SlEditFRM.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
class T_SlPracEdFRM;
namespace mng { class StreamDB; }
//---------------------------------------------------------------------------
class T_SlPracFRM : public T_SlEditFRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TLabel *Label1;
	TDataSource *m_WarDS;
	TDBLookupComboBox *m_WarCB;
	void __fastcall m_WarCBCloseUp(TObject *Sender);
public:
		//KONSTRUKTOR DESTRUKTOR
				  __fastcall  T_SlPracFRM(TComponent* Owner);
		  virtual __fastcall ~T_SlPracFRM(void);
private:
		//NARZÊDZIA
		  T_SlPracEdFRM * m_PracEdFRM;
		  mng::StreamDB * m_WarSDB;
		//ZDARZENIA
		  virtual void __fastcall onShow(void);
		  virtual void __fastcall onClose(void);
};
//---------------------------------------------------------------------------
#endif
