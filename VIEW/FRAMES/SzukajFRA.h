//---------------------------------------------------------------------------

#ifndef SzukajFRAH
#define SzukajFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothButton.hpp"
#include <DB.hpp>
#include "AdvCombo.hpp"
#include "AdvDBComboBox.hpp"
#include "AdvDBLookupComboBox.hpp"
#include "dblucomb.hpp"
#include "Lucombo.hpp"
#include <DBClient.hpp>
#include <dblookup.hpp>
#include "AdvControlDropDown.hpp"
#include "AdvDropDown.hpp"
#include "AdvSmoothComboBox.hpp"
#include "AdvSmoothListBox.hpp"
#include "DBAdvControlDropDown.hpp"
#include "DBAdvGlowNavigator.hpp"
#include "DBAdvSmoothComboBox.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DBCtrls.hpp>

//---------------------------------------------------------------------------
namespace msg      { class MagID; }
namespace jbutils  { class TMyIni;}
typedef void __fastcall (__closure *OnFindSprzet)(const msg::MagID& _MagID);
namespace finders {class SprzetFinderCTRL; }
namespace mng { class StreamDB; class QueryDB;}
class T_SzukajFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopP;
	TAdvSmoothButton *m_FindNrMagBT;
	TLabel *Label1;
	TEdit *m_IdMagTE;
	TLabel *m_NrMagLB;
	TAdvSmoothButton *AdvSmoothButton2;
	TAdvSmoothButton *m_AdwSearchBT;
	TDataSource *m_DS;
	TEdit *m_RokMagTE;
	TLabel *Label4;
	TDataSource *m_SerwisDS;
	TClientDataSet *m_SerwisCD;
	TLabel *Label12;
	TDBLookupComboBox *m_SerwisCB;
	TDataSource *m_WydzDS;
	TDBLookupComboBox *m_WydzCB;
	TLabel *Label21;
	TAdvSmoothButton *m_DecrBT;
	TAdvSmoothButton *m_IncBT;
	void __fastcall m_FindNrMagBTClick(TObject *Sender);
	void __fastcall NrMagKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall m_AdwSearchBTClick(TObject *Sender);
	void __fastcall m_DecrBTMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall m_IncBTMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall freeArrowBT(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

public:
		//INTERFEJS
		  void __fastcall setOnFindSprzet(OnFindSprzet _OnFS);
		  void __fastcall prepare(void);
		  void __fastcall open(const msg::MagID& _MagID);

		//KONSTRUKTOR DESTRUKTOR
			__fastcall  T_SzukajFRA(TComponent* Owner);
			__fastcall ~T_SzukajFRA();

private:
		//ATRYBUTY
		  int  m_BiezRok;
		  bool m_IsArrowBT;
		  int  m_Sleep;
		//NARZÊDZIA
		  finders::SprzetFinderCTRL * m_SprzFind;
		  jbutils::TMyIni           * m_Ini;
		  mng::StreamDB             * m_WydzSDB;
		  mng::QueryDB              * m_IdyIncQDB;
		  mng::QueryDB              * m_IdyDecQDB;
		  mng::QueryDB              * m_IdyMaxQDB;
		  mng::QueryDB              * m_IdyMinQDB;
		//ZDARZENIA
		  OnFindSprzet m_OnFind;
		//METODY POMOCNICZE
		  void __fastcall readIni(void);
          void __fastcall openStreams(void);
		  void __fastcall writeIni(void);
		  void __fastcall runOnFind(const msg::MagID& _MagID);
		//STA£E
		  static const AnsiString M_WYDZ_SQL;
		  static const AnsiString M_NEXT_MAG_SQL;
		  static const AnsiString M_MAX_MAG_SQL;
		  static const AnsiString M_PRIOR_MAG_SQL;
		  static const AnsiString M_MIN_MAG_SQL;
};
//---------------------------------------------------------------------------
#endif
