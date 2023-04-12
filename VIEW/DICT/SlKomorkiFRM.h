//---------------------------------------------------------------------------

#ifndef SlKomorkiFRMH
#define SlKomorkiFRMH
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
class T_SlKomorkiFRM : public T_SL_BASE_FRM
{
__published:	// IDE-managed Components
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	void __fastcall MyShowModal();

	__fastcall T_SlKomorkiFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif