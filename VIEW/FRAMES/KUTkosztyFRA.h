//---------------------------------------------------------------------------

#ifndef KUTkosztyFRAH
#define KUTkosztyFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBClient.hpp>
#include "AdvSmoothButton.hpp"
#include <Provider.hpp>
//---------------------------------------------------------------------------
namespace mng {class QueryDB;}
namespace msg {class ZlecID;}

class T_KUTkosztyFRA : public TFrame
{
__published:	// IDE-managed Components
	TDataSource *m_KosztyDS;
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_DodajBB;
	TAdvSmoothButton *m_EdytujBB;
	TAdvSmoothButton *m_UsunBB;
	TAdvSmoothPanel *m_ClientP;
	TDBGrid *m_DBG;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TLabel *Label1;
	TClientDataSet *cdsKoszty;
	TDataSetProvider *dspKoszty;
	void __fastcall m_UsunBBClick(TObject *Sender);
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
	void __fastcall dspKosztyGetTableName(TObject *Sender, TDataSet *DataSet, WideString &TableName);
	void __fastcall dspKosztyBeforeUpdateRecord(TObject *Sender, TDataSet *SourceDS,
          TCustomClientDataSet *DeltaDS, TUpdateKind UpdateKind, bool &Applied);


private:	// User declarations
	mng::QueryDB* m_QDB;
	int m_idKosztow;
public:		// User declarations
	__fastcall T_KUTkosztyFRA(TComponent* Owner);
	__fastcall ~T_KUTkosztyFRA();
	void __fastcall show(const msg::ZlecID& _ZlecID);
	void __fastcall apply(msg::ZlecID* _ZlecID);
	TDataSet * __fastcall getDataSet(void);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
