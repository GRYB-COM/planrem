//---------------------------------------------------------------------------

#ifndef KonfigFRMH
#define KonfigFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvDateTimePicker.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothTabPager.hpp"
#include <ComCtrls.hpp>
#include "AdvDBLookupComboBox.hpp"
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include "AdvTabSet.hpp"
#include <Buttons.hpp>
#include <Dialogs.hpp>
namespace jbutils{ class TMyIni; }
namespace mng { class StreamDB; }
//---------------------------------------------------------------------------
class T_KonfigFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_SearchPA;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothTabPager *m_PageCTRL;
	TAdvSmoothTabPage *m_PowiadPG;
	TAdvSmoothTabPage *m_WartDOmPG;
	TDataSource *m_WydzDS;
	TAdvSmoothPanel *m_PowPA;
	TLabel *m_TermDostLB;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TAdvDateTimePicker *m_IKWDateDTP;
	TAdvDateTimePicker *m_IIKWDateDTP;
	TAdvDateTimePicker *m_IIIKWDateDTP;
	TAdvDateTimePicker *m_IVKWDateDTP;
	TAdvSmoothPanel *m_WartDomPA;
	TLabel *Label11;
	TLabel *Label5;
	TDBLookupComboBox *m_WydzCB;
	TEdit *m_RokED;
	TAdvTabSet *AdvTabSet1;
	TAdvSmoothTabPage *m_EksportPA;
	TSpeedButton *m_EkspPathBB;
	TEdit *m_EkspPathED;
	TOpenDialog *m_EkspPathOD;
	TEdit *m_EkspFileNameED;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_EkspPathBBClick(TObject *Sender);
public:
	   // User declarations
		  __fastcall  T_KonfigFRM(TComponent* Owner);
		  __fastcall ~T_KonfigFRM(void);
private:
		//NARZÊDZIA
		  jbutils::TMyIni * m_Ini;
          mng::StreamDB   * m_WydzSDB;
};
//---------------------------------------------------------------------------
#endif
