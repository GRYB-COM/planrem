//---------------------------------------------------------------------------

#ifndef SlJednostkiEditFRMH
#define SlJednostkiEditFRMH
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
class T_SlJednostkiEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TDBEdit *edKod;
    TLabel *Label2;
    TDBEdit *edNazwa;
    TDBEdit *edNazwaP;
    TLabel *Label3;
    TLabel *Label4;
    TDBEdit *edMiasto;
    TLabel *Label5;
    TDBEdit *edTel;
    TLabel *Label6;
    TDBEdit *edFax;
    TDBEdit *edNrOdGsp;
    TLabel *Label7;
private:	// User declarations
public:		// User declarations
    __fastcall T_SlJednostkiEditFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
