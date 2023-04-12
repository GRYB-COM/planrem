//---------------------------------------------------------------------------

#ifndef DokFRAH
#define DokFRAH
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
class T_DokFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_NewBT;
	TAdvSmoothButton *m_EditBT;
	TAdvSmoothButton *m_PrintBT;
	TDataSource *m_DS;
	TDBAdvGrid *DBAdvGrid1;
	TAdvSmoothButton *m_DelBT;
	void __fastcall m_DelBTClick(TObject *Sender);
	void __fastcall m_NewBTClick(TObject *Sender);
	void __fastcall m_EditBTClick(TObject *Sender);
	void __fastcall m_PrintBTClick(TObject *Sender);
public:		// User declarations
	__fastcall T_DokFRA(TComponent* Owner);
	__fastcall ~T_DokFRA(void);
	void __fastcall open(msg::MagID aMag);
	void __fastcall close(void);
	static mng::QueryDB * m_PrintQDB;
private:	// User declarations
	mng::StreamDB *m_SDB;
	msg::MagID m_MagID;
	static const AnsiString M_PRINTER_SQL;
};
//---------------------------------------------------------------------------
extern AnsiString getMacro(AnsiString Pars);
extern AnsiString getZadanie(AnsiString Pars);
extern AnsiString getKUT(AnsiString Pars);
//---------------------------------------------------------------------------
#endif
