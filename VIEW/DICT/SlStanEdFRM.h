//---------------------------------------------------------------------------

#ifndef SlStanEdFRMH
#define SlStanEdFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGlowButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <Buttons.hpp>
#include "AdvSmoothButton.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
namespace mng{ class StreamDB; }
//---------------------------------------------------------------------------
class T_SlStanEdFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TLabel *m_NazwaLB;
	TDataSource *m_DS;
	TDBEdit *DBEdit1;
	TDataSource *m_WydzDS;
	TDataSource *m_OddzDS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_CancelBBClick(TObject *Sender);
public:		// User declarations
	__fastcall T_SlStanEdFRM(TComponent* Owner);
	__fastcall ~T_SlStanEdFRM(void);
private:
		//NARZÊDZIA
		  mng::StreamDB * m_OddzSDB;
		  mng::StreamDB * m_WydzSDB;

};
//---------------------------------------------------------------------------
#endif
