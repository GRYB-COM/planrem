// ---------------------------------------------------------------------------
#ifndef NowyMagFRMH
#define NowyMagFRMH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "DBAdvSmoothDatePicker.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <DBClient.hpp>
#include "AdvDBLookupComboBox.hpp"
// ---------------------------------------------------------------------------
namespace mng     {class StreamDB;}
namespace msg     {class MagID;   class MagREC; }
namespace jbutils {class TMyIni;  }
class T_NowyMagFRM : public TForm
{
__published: // IDE-managed Components
	TAdvSmoothPanel *m_BottomPA;
	TAdvSmoothPanel *m_MainPA;
  TLabel* Label2;
  TLabel* Label4;
  TLabel* Label5;
  TLabel* Label7;
  TAdvSmoothButton* AdvSmoothButton4;
  TAdvSmoothButton* AdvSmoothButton1;
	TDBLookupComboBox *m_SprzetCB;
  TDataSource* m_SprzetDS;
  TDataSource* m_DS;
	TDBEdit *m_IloscED;
	TDBEdit *m_UwagiED;
  TDataSource* m_PlanDS;
	TDBAdvSmoothDatePicker *m_DataPrzDTP;
	TDBEdit *m_NrRejED;
  TLabel* Label1;
	TDBEdit *m_NrFabrED;
  TLabel* Label13;
  TLabel* Label14;
  TDataSource* m_JWDS;
	TDBEdit *m_PodstED;
  TLabel* Label9;
	TDBEdit *m_ProtPrzyjCB;
  TLabel* Label16;
  TDataSource* m_WarsztatDS;
	TDataSource *m_RemDS;
	TLabel *Label3;
	TDBLookupComboBox *m_RodzRemCB;
	TAdvSmoothPanel *m_TopPA;
	TAdvSmoothPanel *m_Bottom1PA;
	TClientDataSet *m_SerwisCD;
	TDataSource *m_SerwisDS;
	TLabel *Label17;
	TDBLookupComboBox *m_WarsztatCB;
	TAdvDBLookupComboBox *m_DostCB;
	TLabel *Label18;
	TDBAdvSmoothDatePicker *DBAdvSmoothDatePicker1;
	TLabel *Label8;
	TDBAdvSmoothDatePicker *DBAdvSmoothDatePicker2;
	TLabel *Label19;
	TDBAdvSmoothDatePicker *DBAdvSmoothDatePicker3;
	TLabel *Label20;
	TDBEdit *DBEdit2;
	TAdvDBLookupComboBox *m_PlanCB;
	TDBEdit *m_PlanSprzetED;
	TLabel *Label15;
	TLabel *Label11;
	TDataSource *m_WydzDS;
	TSpeedButton *m_FindHarmBB;
	TDBLookupComboBox *m_Wydz1CB;
	TLabel *Label22;
	TDBEdit *DBEdit3;
	TLabel *Label23;
	TDBLookupComboBox *m_RokPlCB;
	TDataSource *m_RokPlDS;
	TSpeedButton *m_NrMagBT;
	TLabel *Label12;
	TLabel *Label10;
	TLabel *Label6;
	TLabel *Label21;
	TDBLookupComboBox *m_SerwisCB;
	TDBEdit *m_RokED;
	TDBEdit *m_NrMagED;
	TDBLookupComboBox *m_WydzCB;
	TDBEdit *DBEdit1;

  void __fastcall AdvSmoothButton4Click(TObject* Sender);
  void __fastcall AdvSmoothButton1Click(TObject* Sender);
	void __fastcall m_NrMagBTClick(TObject *Sender);
	void __fastcall m_PlanCBKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall m_WarsztatCBKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall clearWarKeyBuff(TObject *Sender);
	void __fastcall m_DostCBKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_WydzDSDataChange(TObject *Sender, TField *Field);
	void __fastcall m_FindHarmBBClick(TObject *Sender);
	void __fastcall przeliczNrMag(TObject *Sender, TField *Field);
	void __fastcall DBAdvSmoothDateclearData(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormShow(TObject *Sender);

public:
		//INTERFEJS
		  int __fastcall show(msg::MagID& _MagID, const msg::MagREC& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall T_NowyMagFRM(TComponent* Owner);
		  __fastcall ~T_NowyMagFRM();
private:
		//FUNKCJE POMOCNICZE
		  void __fastcall open(const msg::MagID& _MagID);
		  void __fastcall setControls(const msg::MagID& _MagID);
		  void __fastcall setControls(TDBEdit* _Ctrl, bool _Ed);
		  void __fastcall setControls(TDBLookupComboBox* _Ctrl, bool _Ed);
		  void __fastcall close(void);
		  void __fastcall setMag(msg::MagID& _MagID);
		  void __fastcall complete(const msg::MagID& _MagID);
		  bool __fastcall valid(void);
		  bool __fastcall validIlosc(void);
		//ZDARZENIA
		  void __fastcall filterPlan(TField *Sender);
		  void __fastcall onRokChange(TField *Sender);
		  void __fastcall filLPlan(TField *Sender);
		//NARZÊDZIA
		  mng::StreamDB*   m_SDB;
		  mng::StreamDB*   m_SprzetSDB;
		  mng::StreamDB*   m_WarsztatSDB;
		  mng::StreamDB*   m_WydzSDB;
		  mng::StreamDB*   m_PlanSDB;
		  mng::StreamDB*   m_JWSDB;
		  mng::StreamDB*   m_RemSDB;
		  mng::StreamDB*   m_RokPlSDB;
		  jbutils::TMyIni* m_Ini;
		//ZABRONIONE
		  virtual int __fastcall ShowModal(void) { return TForm::ShowModal(); }
		//ZMIENNE POMOCNICZE
		  msg::MagREC   * m_Pars;
          msg::MagID    * m_MagID;
		  String          m_WarKeyBuff;
		//sta³e
		  static const AnsiString M_NOWY_NR_SQL;
          static const AnsiString M_MIN_NR_SQL;

};

// ---------------------------------------------------------------------------
#endif
