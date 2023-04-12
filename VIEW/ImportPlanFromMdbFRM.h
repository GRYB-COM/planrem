//---------------------------------------------------------------------------

#ifndef ImportPlanFromMdbFRMH
#define ImportPlanFromMdbFRMH
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
class T_ImportPlanFromMdbFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CloseBB;
	TEdit *m_PathED;
	TLabel *m_PathLB;
	TAdvSmoothButton *m_OpenBT;
	TOpenDialog *m_PathOD;
	TLabel *Label1;
	TAdvSmoothButton *m_RunBB;
	TEdit *m_RokED;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_OpenBTClick(TObject *Sender);
	void __fastcall m_CloseBBClick(TObject *Sender);
	void __fastcall enableRun(TObject *Sender);

public:
	  //KONSTRUKTOR DESTRUKTOR
		__fastcall T_ImportPlanFromMdbFRM(TComponent* Owner);
		__fastcall ~T_ImportPlanFromMdbFRM(void);
private:
		//NARZÊDZIA
		  jbutils::TMyIni * m_Ini;
		//FUNKCJE POMOCNICZE
		  int    __fastcall getRok(void);
		  String __fastcall getPath(void);
		  bool   __fastcall isPath(void);
		  bool   __fastcall isRun(void);
		  bool   __fastcall isRok(void);
friend ImportFromMdbCTRL;
};

}//end namespace importmdb
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
