//---------------------------------------------------------------------------

#ifndef SlStanowiskaEditFRMH
#define SlStanowiskaEditFRMH
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
class T_SlStanowiskaEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBEdit *edKod;
	TLabel *Label2;
	TDBEdit *DBEdit2;
private:	// User declarations
public:		// User declarations
	__fastcall T_SlStanowiskaEditFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
