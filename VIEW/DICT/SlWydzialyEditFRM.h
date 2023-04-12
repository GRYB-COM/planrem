//---------------------------------------------------------------------------

#ifndef SlWydzialyEditFRMH
#define SlWydzialyEditFRMH
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
class T_SlWydzialyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit1;
	TLabel *Label3;
	TDBEdit *DBEdit3;
	TLabel *Label4;
	TDBEdit *DBEdit4;
	TLabel *Label5;
	TDBEdit *DBEdit5;
	TLabel *Label6;
	TDBEdit *DBEdit6;
private:	// User declarations
public:		// User declarations
	__fastcall T_SlWydzialyEditFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
