//---------------------------------------------------------------------------

#ifndef DokWeFRMH
#define DokWeFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBClient.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "AdvDBLookupComboBox.hpp"
#include "AdvDateTimePicker.hpp"
#include "AdvDBDateTimePicker.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace msg {class MagID;}
namespace mng{class StreamDB;}
class T_DokWeFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *bbWrite;
	TAdvSmoothButton *bbCancel;
	TDataSource *m_DS;
	TLabel *m_SygnaturaLB;
	TDBEdit *m_SygnED;
	TLabel *m_Uwagi1LB;
	TDBMemo *m_Uwagi1ED;
	TLabel *m_Uwagi2LB;
	TDBMemo *m_Uwagi2ED;
	TLabel *m_Uwagi3LB;
	TDBMemo *m_Uwagi3ED;
	TLabel *m_DokLB;
	TAdvDBLookupComboBox *m_DokCB;
	TDataSource *m_DokDS;
	TAdvSmoothButton *m_PrintBB;
	TAdvDBDateTimePicker *m_DataWystED;
	TLabel *Label1;
	void __fastcall bbCancelClick(TObject *Sender);
	void __fastcall bbWriteClick(TObject *Sender);
	void __fastcall m_DokCBKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_PrintBBClick(TObject *Sender);
	void __fastcall m_DokDSDataChange(TObject *Sender, TField *Field);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
	TCustomClientDataSet *m_cds;
	mng::StreamDB *m_DokSDB;
	bool m_IsPrint;
    void __fastcall onOpen(void);
public:		// User declarations
	__fastcall T_DokWeFRM(TComponent* Owner);
	__fastcall ~T_DokWeFRM();
	int  __fastcall newId(void);
	bool __fastcall valid(TDataSet* _DS);
	void __fastcall edit(TCustomClientDataSet *aCds);
	void __fastcall append(TCustomClientDataSet *aCds, msg::MagID *aMag);
    TNotifyEvent onPrint;
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
