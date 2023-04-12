//---------------------------------------------------------------------------

#ifndef SL_BASE_FRMH
#define SL_BASE_FRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
namespace mng
{
	class StreamDB;
}

class T_SL_BASE_FRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_DodajBB;
	TAdvSmoothButton *m_EdytujBB;
	TAdvSmoothButton *m_UsunBB;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothPanel *m_TopP;
	TDataSource *m_DS;
	TDBGrid *m_DBG;
	TAdvSmoothButton *m_PrintBB;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_CancelBBClick(TObject *Sender);
	void __fastcall m_UsunBBClick(TObject *Sender);
	void __fastcall m_DBGDblClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall m_PrintBBClick(TObject *Sender);

private:	// User declarations

protected:
	mng::StreamDB *m_SDB;
	AnsiString     m_SQRPath;
	void __fastcall afterAdd(TModalResult mResult, const AnsiString &fName, const Variant &fValue);
	void __fastcall afterEdit(TModalResult mResult);

public:		// User declarations
	__fastcall T_SL_BASE_FRM(TComponent* Owner);
	__fastcall ~T_SL_BASE_FRM();

};
//---------------------------------------------------------------------------
#endif
