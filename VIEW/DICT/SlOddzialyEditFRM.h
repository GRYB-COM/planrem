//---------------------------------------------------------------------------

#ifndef SlOddzialyEditFRMH
#define SlOddzialyEditFRMH
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
class T_SlOddzialyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TDBEdit *edKod;
	TDBEdit *DBEdit2;
	TLabel *Label1;
	TLabel *Label2;
private:	// User declarations
public:		// User declarations
	__fastcall T_SlOddzialyEditFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
