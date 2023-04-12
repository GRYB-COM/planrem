//---------------------------------------------------------------------------

#ifndef SlKomorkiEditFRMH
#define SlKomorkiEditFRMH
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

class T_SlKomorkiEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBEdit *edKod;
	TLabel *Label2;
	TDBEdit *DBEdit2;
	TDataSource *m_wDS;
	TDataSource *m_oDS;
	TDBLookupComboBox *m_wCB;
	TDBLookupComboBox *m_oCB;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TDBEdit *DBEdit3;
	TDBComboBox *DBComboBox1;
private:	// User declarations

	mng::StreamDB *m_oSDB;
	mng::StreamDB *m_wSDB;

public:		// User declarations

	__fastcall T_SlKomorkiEditFRM(TComponent* Owner);
	__fastcall ~T_SlKomorkiEditFRM();
};
//---------------------------------------------------------------------------
#endif
