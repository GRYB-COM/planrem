//---------------------------------------------------------------------------

#ifndef SL_EDIT_FRMH
#define SL_EDIT_FRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
namespace mng
{
	class StreamDB;
}

class T_SL_EDIT_FRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothPanel *m_TopP;
	TDataSource *m_DS;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_CancelBBClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	void __fastcall addRecord(TDataSource *ds, AnsiString keyField, bool initID = true, int initVal = -1* rand());
	void __fastcall editRecord(TDataSource *ds);

	__fastcall T_SL_EDIT_FRM(TComponent* Owner);
	__fastcall ~T_SL_EDIT_FRM();

};
//---------------------------------------------------------------------------
#endif
