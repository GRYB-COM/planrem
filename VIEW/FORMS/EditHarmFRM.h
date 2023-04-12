//---------------------------------------------------------------------------

#ifndef EditHarmFRMH
#define EditHarmFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "AdvDateTimePicker.hpp"
#include "AdvDBDateTimePicker.hpp"
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include "HarmID.h"
#include "model_messengers_RBH4Mies.h"
#include "AdvDBLookupComboBox.hpp"
#include <DBClient.hpp>
namespace mng       { class StreamDB; }
namespace jbutils   { class TMyIni;   }
namespace msg       { class RBH4Mies; }
//---------------------------------------------------------------------------
class T_EditHarmFRM : public TForm
{

__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvSmoothButton *m_CancelBT;
	TAdvSmoothButton *m_SaveBT;
	TDBEdit *m_NrHarmED;
	TLabel *Label1;
	TAdvDBLookupComboBox *m_UslCB;
	TLabel *Label2;
	TLabel *Label3;
	TAdvDBLookupComboBox *m_RemCB;
	TLabel *Label4;
	TAdvDBLookupComboBox *m_DostCB;
	TLabel *Label5;
	TAdvDBLookupComboBox *m_WarCB;
	TLabel *Label6;
	TDBEdit *m_NrSprzED;
	TLabel *Label7;
	TDBGrid *m_RBHGR;
	TLabel *Label8;
	TDBMemo *m_ZadanieED;
	TAdvDBDateTimePicker *m_DataOdED;
	TLabel *Label9;
	TDataSource *m_HarmDS;
	TDataSource *m_UslDS;
	TDataSource *m_RemDS;
	TDataSource *m_JWDS;
	TDataSource *m_WarDS;
	TDataSource *m_HarmDetDS;
	TLabel *Label11;
	TAdvDBLookupComboBox *m_NazSprzED;
	TDataSource *m_SprzetDS;
	TAdvSmoothButton *m_AddBT;
	TAdvSmoothButton *m_EditBT;
	TAdvSmoothButton *m_DelBT;
	TLabel *Label12;
	TDBEdit *m_NormaRBHED;
	TLabel *Label10;
	TAdvDBDateTimePicker *m_DataDoED;
	TLabel *Label13;
	TAdvDBLookupComboBox *m_TypCB;
	TClientDataSet *m_TypyCD;
	TDataSource *m_TypyDS;
	TAdvSmoothButton *m_CountRBHBT;
	TDBCheckBox *m_KontCB;
	TLabel *Label14;
	void __fastcall m_AddBTClick(TObject *Sender);
	void __fastcall m_EditBTClick(TObject *Sender);
	void __fastcall m_DelBTClick(TObject *Sender);
	void __fastcall m_SaveBTClick(TObject *Sender);
	void __fastcall m_CancelBTClick(TObject *Sender);
	void __fastcall clearIfEmpty(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_CountRBHBTClick(TObject *Sender);
 public:
		//KLASY WEWNÊTR¯NE
		  class Pars{
		   public:
		   msg::HarmID HarmId;
		   int NrMies;
		   int IdWarsztatu;
		   msg::RBH4Mies RBHMies;
		   Pars(void);
		  };
		//INTERFEJS
		  int __fastcall display(const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_EditHarmFRM(TComponent* Owner);
		  __fastcall ~T_EditHarmFRM(void);
private:
		//ATRYBUTY
		  int   m_NrHarm;
		  Pars  m_Pars;
		//NARZÊDZIA
		  mng::StreamDB   * m_HarmSDB;
		  mng::StreamDB   * m_HarmDetSDB;
		  mng::StreamDB   * m_UslSDB;
		  mng::StreamDB   * m_RemSDB;
		  mng::StreamDB   * m_JWSDB;
		  mng::StreamDB   * m_WarSDB;
		  mng::StreamDB   * m_SprzetSDB;
		  jbutils::TMyIni * m_Ini;

		//FUNKCJE POMOCNICZE
		  virtual int   __fastcall ShowModal(void) { return TForm::ShowModal();}
				  void  __fastcall open(const Pars& _Pars);
				  void  __fastcall insert(const Pars& _Pars);
				  void  __fastcall edit(void);
				  void  __fastcall close(void);
};

//---------------------------------------------------------------------------
#endif