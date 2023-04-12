//---------------------------------------------------------------------------

#ifndef KUTkosztyEdFRMH
#define KUTkosztyEdFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
namespace mng {class StreamDB;}
class T_KUTkosztyEdFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopP;
	TLabel *m_KodLB;
	TLabel *m_WydzLB;
	TDBEdit *m_KodED;
	TDBLookupComboBox *m_OddzCB;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TDataSource *m_DS;
	TDataSource *m_DSSlow;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_CancelBBClick(TObject *Sender);
private:	// User declarations
	mng::StreamDB *m_SDBSlow;
	bool m_retValue;
public:		// User declarations
	__fastcall T_KUTkosztyEdFRM(TComponent* Owner);
	__fastcall ~T_KUTkosztyEdFRM();
	bool __fastcall edit(TDataSet *ds);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
