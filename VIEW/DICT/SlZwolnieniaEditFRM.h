//---------------------------------------------------------------------------

#ifndef SlZwolnieniaEditFRMH
#define SlZwolnieniaEditFRMH
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

class T_SlZwolnieniaEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TDBLookupComboBox *m_miesCB;
	TDBEdit *DBEdit1;
	TLabel *Label1;
	TDBLookupComboBox *m_zwCB;
	TLabel *Label5;
	TDataSource *m_zwDS;
	TDataSource *m_miesDS;
private:	// User declarations

	mng::StreamDB *m_miesSDB;
	mng::StreamDB *m_slzwSDB;

public:		// User declarations

	__fastcall T_SlZwolnieniaEditFRM(TComponent* Owner);
	__fastcall ~T_SlZwolnieniaEditFRM();
};
//---------------------------------------------------------------------------
#endif
