//---------------------------------------------------------------------------

#ifndef KutyFRAH
#define KutyFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "MagID.h"
#include "ZlecREC.h"
//---------------------------------------------------------------------------
namespace readers {class KUTReader;}
namespace msg     {class MagID;    }
namespace mng     {class QueryDB;  }
class T_KutyFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomPA;
	TAdvSmoothButton *m_NewBT;
	TAdvSmoothButton *m_EditBT;
	TAdvSmoothButton *m_PrintBT;
	TAdvSmoothPanel *m_TopP;
	TDBGrid *m_DBG;
	TDBAdvGrid *m_AG;
	TDataSource *m_DS;
	TAdvSmoothButton *m_DelBT;
	void __fastcall m_NewBTClick(TObject *Sender);
	void __fastcall m_EditBTClick(TObject *Sender);
	void __fastcall m_PrintBTClick(TObject *Sender);
	void __fastcall m_DelBTClick(TObject *Sender);

public:
		//INTERFEJS
		  void __fastcall open(const msg::MagID& _IdMag);
          void __fastcall close(void);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall T_KutyFRA(TComponent* Owner);
		  __fastcall ~T_KutyFRA();
		//STATIKI
		   static mng::QueryDB * m_PrintQDB;

private:
		//NARZÊDZIA
		  readers::KUTReader* m_Reader;
		//ATRYBUTY
		  msg::MagID    m_MagID;
		  msg::ZlecREC  m_ZlecMain;
		//STATIKI
public:
		  static const AnsiString M_PRINTER_SQL;
		  static const AnsiString M_DEL_SQL;
		  static const AnsiString M_DEL_WARNING;
		  static const AnsiString M_ILOSC_SQL;
		  static const AnsiString M_WYDANIE_SQL;
};
extern AnsiString getMacroZlec(AnsiString Pars);
extern AnsiString getIlosc(AnsiString Pars);
//---------------------------------------------------------------------------
#endif
