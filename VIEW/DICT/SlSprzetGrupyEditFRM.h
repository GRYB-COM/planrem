//---------------------------------------------------------------------------

#ifndef SlSprzetGrupyEditFRMH
#define SlSprzetGrupyEditFRMH
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
class T_SlSprzetGrupyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TDBEdit *edNazwa;
private:	// User declarations
public:		// User declarations
    __fastcall T_SlSprzetGrupyEditFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
