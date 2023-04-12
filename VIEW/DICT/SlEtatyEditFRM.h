//---------------------------------------------------------------------------

#ifndef SlEtatyEditFRMH
#define SlEtatyEditFRMH
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
#include "AdvDateTimePicker.hpp"
#include "AdvDBDateTimePicker.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}

class T_SlEtatyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TDBEdit *DBEdit1;
	TLabel *Label1;
	TAdvDBDateTimePicker *m_DataOdDCP;
	TLabel *Label5;
	TLabel *Label2;
	TDBEdit *DBEdit2;
	TLabel *Label3;
	TDBEdit *DBEdit3;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations


public:		// User declarations

	__fastcall T_SlEtatyEditFRM(TComponent* Owner);
	__fastcall ~T_SlEtatyEditFRM(void);
};
//---------------------------------------------------------------------------
#endif
