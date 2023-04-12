//---------------------------------------------------------------------------

#ifndef SprKwartalWybFRMH
#define SprKwartalWybFRMH
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
class T_SprKwartalWybFRM : public T_FCUSTWYB
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *cbOkres;
	TEdit *edRok;
	TLabel *Label2;
	TEdit *edKomorka;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *edZalacznik;
	TEdit *m_StronaED;
	TLabel *Label5;
	TCheckBox *m_Filtr1CB;
	TRadioGroup *m_SortRG;
	TMenuItem *N1;
	TMenuItem *m_RapSQRTMI;
	TMenuItem *m_RapXLSTMI;
private:	// User declarations
public:		// User declarations
	__fastcall T_SprKwartalWybFRM(TComponent* Owner);
	__fastcall ~T_SprKwartalWybFRM();
};

}; //end namespace progzest
//---------------------------------------------------------------------------
#endif
