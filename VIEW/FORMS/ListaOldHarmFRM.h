//---------------------------------------------------------------------------

#ifndef ListaOldHarmFRMH
#define ListaOldHarmFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
namespace mng      { class StreamDB; }
namespace jbutils  { class TMyIni;   }
namespace msg      { class HarmID; }
//---------------------------------------------------------------------------
class T_ListaOldHarmFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDBGrid *m_HarmGR;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TLabel *Label1;
	TDBLookupComboBox *m_WarCB;
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_SaveBB;
	TDataSource *m_HarmDS;
	TDataSource *m_WarDS;
	TAdvSmoothButton *m_MoveBB;
	void __fastcall m_MiesCDAfterScroll(TDataSet *DataSet);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_WarCBCloseUp(TObject *Sender);
public:		// User declarations
		//INTERFEJS
		  void __fastcall setRok(const int _Rok);
		//KONSTRUKTOR DESTRUKTOR
			__fastcall  T_ListaOldHarmFRM(TComponent* Owner);
			__fastcall ~T_ListaOldHarmFRM(void);

private:
		//METODY POMOCNICZE
		  void 	  __fastcall openHarm(const int _IdKomorki);
		//NARZÊDZIA
		  mng::StreamDB   * m_HarmSDB;
		  mng::StreamDB   * m_WarSDB;
		  jbutils::TMyIni * m_Ini;
		//ATRYBUTY
		  int            m_Rok;
};
//---------------------------------------------------------------------------
#endif
