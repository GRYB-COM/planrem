//---------------------------------------------------------------------------

#ifndef SlUrlopyEditFRMH
#define SlUrlopyEditFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_EDIT_FRM.h"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}

class T_SlUrlopyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBEdit *DBEdit1;
	TLabel *Label3;
	TDBLookupComboBox *m_miesCB;
	TDataSource *m_miesDS;
private:	// User declarations

	mng::StreamDB *m_miesSDB;

public:		// User declarations

	__fastcall T_SlUrlopyEditFRM(TComponent* Owner);
	__fastcall ~T_SlUrlopyEditFRM();

};
//---------------------------------------------------------------------------
#endif
