//---------------------------------------------------------------------------

#ifndef SlJednostkiFRMH
#define SlJednostkiFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_BASE_FRM.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class T_SlJednostkiFRM : public T_SL_BASE_FRM
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TEdit *edKodJW;
    TEdit *edMiasto;
    void __fastcall edKodJWChange(TObject *Sender);
    void __fastcall edMiastoChange(TObject *Sender);
    void __fastcall m_DodajBBClick(TObject *Sender);
    void __fastcall m_EdytujBBClick(TObject *Sender);
private:	// User declarations

    AnsiString m_kodFilter;
    AnsiString m_mstFilter;

    void __fastcall setFilter();

public:		// User declarations

	void __fastcall MyShowModal();

    __fastcall T_SlJednostkiFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
