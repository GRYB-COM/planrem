//---------------------------------------------------------------------------

#ifndef SlPracEdFRMH
#define SlPracEdFRMH
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
class T_SlPracEdFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TLabel *m_KodLB;
	TLabel *m_NazwaLB;
	TLabel *m_OddzLB;
	TLabel *m_WydzLB;
	TLabel *m_TelLB;
	TDataSource *m_DS;
	TDBEdit *m_KodED;
	TDBEdit *DBEdit1;
	TDBLookupComboBox *m_WarCB;
	TDBLookupComboBox *m_OddzCB;
	TDBEdit *m_RBHED;
	TDataSource *m_WarDS;
	TDataSource *m_StanDS;
	TLabel *Label1;
	TDBLookupComboBox *m_StopCB;
	TDataSource *m_StopDS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_CancelBBClick(TObject *Sender);
public:		// User declarations
	__fastcall T_SlPracEdFRM(TComponent* Owner);
	__fastcall ~T_SlPracEdFRM(void);
private:
		//NARZÊDZIA
		  mng::StreamDB * m_WarSDB;
		  mng::StreamDB * m_StanSDB;
		  mng::StreamDB * m_StopSDB;

};
//---------------------------------------------------------------------------
#endif
