//---------------------------------------------------------------------------

#ifndef KUTkosztySumFRAH
#define KUTkosztySumFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include "MagID.h"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
namespace mng{class StreamDB; class QueryDB; }
class T_KUTkosztySumFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TDataSource *m_DS;
	TDBGrid *DBGrid1;
public:		// User declarations
	__fastcall T_KUTkosztySumFRA(TComponent* Owner);
	__fastcall ~T_KUTkosztySumFRA(void);
	void __fastcall open(msg::MagID aMag);
	void __fastcall close(void);
	static mng::QueryDB * m_PrintQDB;
private:	// User declarations
	mng::StreamDB *m_SDB;
	msg::MagID m_MagID;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
