//---------------------------------------------------------------------------

#ifndef ListaHarmFRMH
#define ListaHarmFRMH
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
namespace msg      { class HarmID;  class RBH4War; }

//---------------------------------------------------------------------------
class T_ListaHarmFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TDBGrid *m_HarmGR;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TLabel *Label1;
	TDBLookupComboBox *m_WarCB;
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_DodajBB;
	TAdvSmoothButton *m_EdytujBB;
	TAdvSmoothButton *m_UsunBB;
	TAdvSmoothButton *m_SaveBB;
	TDBGrid *m_MiesGR;
	TClientDataSet *m_MiesCD;
	TDataSource *m_MiesDS;
	TDataSource *m_HarmDS;
	TDataSource *m_WarDS;
	TLabel *Label2;
	TClientDataSet *m_RBHCD;
	TIntegerField *m_RBHCDNR_MIES;
	TFMTBCDField *m_RBHCDRBH_MIES;
	TFMTBCDField *m_RBHCDPLAN_RBH;
	TFMTBCDField *m_RBHCDPOZOSTALO;
	TAggregateField *m_RBHCDSUM_RBH_MIES;
	TAggregateField *m_RBHCDSUM_PLAN_RBH;
	TAggregateField *m_RBHCDSUM_POZOSTALO;
	TDBText *DBText1;
	TDataSource *m_RBHDS;
	TLabel *Label3;
	TDBText *DBText2;
	TLabel *m_PozostaloLB;
	TDBText *m_PozostaloDBT;
	TAdvSmoothPanel *m_RokPA;
	TEdit *m_RokED;
	TLabel *m_RokLB;
	TIntegerField *m_MiesCDNR_MIES;
	TStringField *m_MiesCDMIESIAC;
	TAdvSmoothButton *m_MoveBB;
	TAdvSmoothButton *m_ImportBB;
	TCurrencyField *m_MiesCDRBH_MIES;
	TCurrencyField *m_MiesCDPLAN_RBH;
	TCurrencyField *m_MiesCDPOZOSTALO;
	TAdvSmoothButton *m_ReadPlanBB;
	TAdvSmoothButton *m_ZatwBB;
	void __fastcall m_MiesCDAfterScroll(TDataSet *DataSet);
	void __fastcall m_WarCBCloseUp(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
	void __fastcall m_MiesGRDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall m_MoveBBClick(TObject *Sender);
	void __fastcall m_ImportBBClick(TObject *Sender);
	void __fastcall m_UsunBBClick(TObject *Sender);
	void __fastcall m_ReadPlanBBClick(TObject *Sender);
	void __fastcall m_ZatwBBClick(TObject *Sender);
public:		// User declarations
		//INTERFEJS
		  void __fastcall setRok(const int _Rok);
		//KONSTRUKTOR DESTRUKTOR
			__fastcall  T_ListaHarmFRM(TComponent* Owner);
			__fastcall ~T_ListaHarmFRM(void);

private:
		//METODY POMOCNICZE
		  void 	  __fastcall fillMiesCD(void);
		  void 	  __fastcall fillRBHCD(void);
		  void 	  __fastcall fillMiesCD(const int _IdKomorki);
		  void 	  __fastcall openHarm(const int _Mies, const int _IdKomorki);
		  void 	  __fastcall filter(const int _Mies, const int _IdKomorki);
		  void 	  __fastcall colPoz(void);
		  void 	  __fastcall displayDet(const msg::HarmID & _HarmID);
		  void 	  __fastcall setEdit(void);
		  double  __fastcall getAggSum(const String & _FieldName);
		//NARZÊDZIA
		  mng::StreamDB   * m_HarmSDB;
		  mng::StreamDB   * m_WarSDB;
		  jbutils::TMyIni * m_Ini;
		//ATRYBUTY
		  int            m_Rok;
		  msg::RBH4War * m_RBH4War;
		//STA£E
		  static const String M_DEL_PLAN_SQL;
		  static const String M_GET_PLAN_SQL;
		  static const String M_GET_DET_PLAN_SQL;
		  static const String M_INS_PLAN_SQL;
		  static const String M_SEL_KOR_SQL;
		  static const String M_ZATW_KOR_SQL;
		  static const String M_DEL_DET_PLAN_SQL;


};
//---------------------------------------------------------------------------
#endif
