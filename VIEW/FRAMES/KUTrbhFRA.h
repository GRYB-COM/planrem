//---------------------------------------------------------------------------

#ifndef KUTrbhFRAH
#define KUTrbhFRAH
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
//---------------------------------------------------------------------------
namespace mng {class StreamDB;}
namespace msg {class ZlecID;}

class T_KUTrbhFRA : public TFrame
{
__published:	// IDE-managed Components
	TDataSource *m_RbhDS;
	TAdvSmoothPanel *m_BottomASP;
	TDBGrid *m_DBG;
	TLabel *Label7;
	TEdit *m_SumIlPED;
	TEdit *m_RazemED;
	TEdit *m_SumIlRED;
	TEdit *m_SumRBHPED;
	TEdit *m_SumRBHRED;
	void __fastcall m_DBGDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
private:	// User declarations
	mng::StreamDB* m_RbhSDB;
	void __fastcall afterInsert(TDataSet *DataSet);
	void __fastcall afterPost(TDataSet *DataSet);
	void __fastcall suma(TEdit* _SumED);
public:		// User declarations
	__fastcall T_KUTrbhFRA(TComponent* Owner);
	__fastcall ~T_KUTrbhFRA();
	void __fastcall show(const msg::ZlecID& _ZlecID);
	void __fastcall apply(msg::ZlecID* _ZlecID);
	TDataSet * __fastcall getDataSet(void);
};
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
