//---------------------------------------------------------------------------

#ifndef ImportFromMdbFRMH
#define ImportFromMdbFRMH
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
#include <Dialogs.hpp>
#include "AdvGroupBox.hpp"
#include "AdvOfficeButtons.hpp"
#include "DBAdvOfficeButtons.hpp"
#include <vector>
//---------------------------------------------------------------------------
namespace jbutils { class TMyIni;    }
namespace mng     { class StreamDB;  }
//---------------------------------------------------------------------------
namespace importmdb{
class ImportFromMdbCTRL;
class T_ImportFromMdbFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CloseBB;
	TEdit *m_PathED;
	TLabel *m_PathLB;
	TAdvSmoothButton *m_OpenBT;
	TOpenDialog *m_PathOD;
	TDBLookupComboBox *m_WydzCB;
	TLabel *Label1;
	TDataSource *m_WydzDS;
	TAdvOfficeCheckGroup *m_DaneCG;
	TAdvSmoothButton *m_RunBB;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_OpenBTClick(TObject *Sender);
	void __fastcall m_CloseBBClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall enableRun(TObject *Sender);

public:
	  //KONSTRUKTOR DESTRUKTOR
		__fastcall T_ImportFromMdbFRM(TComponent* Owner);
		__fastcall ~T_ImportFromMdbFRM(void);
private:
		//NARZÊDZIA
		  jbutils::TMyIni * m_Ini;
		  mng::StreamDB   * m_WydzSDB;
		//FUNKCJE POMOCNICZE
		  std::vector<bool>      __fastcall getFlags(void);
		  bool                   __fastcall isAnyFlag(void);
		  int                    __fastcall getIdWydz(void);
		  bool                   __fastcall isWydz(void);
		  String                 __fastcall getPath(void);
		  bool                   __fastcall isPath(void);
		  bool                   __fastcall isRun(void);
friend ImportFromMdbCTRL;
};

}//end namespace importmdb
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
