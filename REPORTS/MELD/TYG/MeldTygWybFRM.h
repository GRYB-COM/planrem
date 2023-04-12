//---------------------------------------------------------------------------

#ifndef MeldTygWybFRMH
#define MeldTygWybFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FCSWYB.h"
#include "PopupButton.h"
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace progzest{
class T_MeldTygWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TDateTimePicker *m_DataOdDTP;
	TLabel *Label1;
	TDateTimePicker *m_DataDoDTP;
	TMenuItem *m_SQRTMI;
	TMenuItem *m_ExcellTMI;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_DataOdDTPChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_MeldTygWybFRM(TComponent* Owner);
};

}; //end namespace progzest
//---------------------------------------------------------------------------
#endif
