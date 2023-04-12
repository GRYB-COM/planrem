//---------------------------------------------------------------------------

#ifndef KUTFRMH
#define KUTFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBCtrls.hpp>
#include "DBAdvSmoothDatePicker.hpp"
#include <Mask.hpp>
#include <DB.hpp>
#include "MagID.h"
#include "ZlecID.h"
#include "ZlecREC.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "KUTrbhFRA.h"
#include "AdvDBLookupComboBox.hpp"
#include <DBClient.hpp>
#include <Provider.hpp>
#include "KUTkosztyFRA.h"
#include <Buttons.hpp>
#include "AdvOfficeButtons.hpp"
#include "DBAdvOfficeButtons.hpp"
//---------------------------------------------------------------------------
namespace mng {class StreamDB; class QueryDB; class TransactionDB ;}
class T_KUTFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_WriteBB;
	TAdvSmoothButton *AdvSmoothButton1;
	TDataSource *m_DS;
	TDataSource *m_WarsztatDS;
	TAdvSmoothPanel *_NowyKUTFRM;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label1;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label32;
	TDBMemo *m_ZadED;
	TDBMemo *m_UwagiED;
	TDBAdvSmoothDatePicker *m_DataWystDTP;
	TDataSource *m_SprzetDS;
	TLabel *Label3;
	TLabel *Label6;
	TDataSource *m_HarmonogramDS;
	TDataSource *m_JednostkaDS;
	T_KUTrbhFRA *m_KUTRBHFRA;
	TAdvDBLookupComboBox *m_JWCB;
	TAdvDBLookupComboBox *m_KodCB;
	TAdvDBLookupComboBox *m_HarmCB;
	TDBAdvSmoothDatePicker *m_DataZak;
	TDBAdvSmoothDatePicker *m_DataZadaDTP;
	TDBAdvSmoothDatePicker *m_PrzestojODDTP;
	TDBAdvSmoothDatePicker *m_DataPropZakDTP;
	T_KUTkosztyFRA *m_KUTkosztyFRA;
	TSpeedButton *m_FindHarmBB;
	TDBEdit *m_RBHED;
	TLabel *Label2;
	TEdit *m_NrMagED;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TDBEdit *m_NrKolED;
	TLabel *Label11;
	TDBEdit *m_RokED;
	TLabel *Label12;
	TEdit *m_WydzED;
	TSpeedButton *m_RBHBB;
	TLabel *Label13;
	TDBLookupComboBox *m_SprzetCB;
	TDBCheckBox *m_WydCB;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TDBEdit *m_IloscED;
	TLabel *Label14;
	void __fastcall m_WriteBBClick(TObject *Sender);
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
	void __fastcall DBEdit8KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBEdit10KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBEdit11KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBEdit13KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_HarmonogramDSDataChange(TObject *Sender, TField *Field);
	void __fastcall m_FindHarmBBClick(TObject *Sender);
	void __fastcall m_WarsztatDSDataChange(TObject *Sender, TField *Field);
	void __fastcall m_DSDataChange(TObject *Sender, TField *Field);
	void __fastcall m_HarmCBExit(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_DataWystDTPKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_RBHBBClick(TObject *Sender);



public:
		//INTERFEJS
		  void __fastcall show(const msg::ZlecID& _KutID, const msg::MagID & _MagID, const msg::ZlecREC& _MainKUT);
		  void __fastcall getZlecID(msg::ZlecID& _ZledID);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall T_KUTFRM(TComponent* Owner);
		  __fastcall ~T_KUTFRM();
private:
		//FUNKCJE POMOCNICZE
		  void 		__fastcall open(const bool _Append);
		  void 		__fastcall openHarm(const bool _Append);
		  void 		__fastcall openMag(void);
		  void 		__fastcall close(void);
		  void 		__fastcall append(void);
		  void 		__fastcall edit(void);
		  void 		__fastcall complete(void);
		  int  		__fastcall getNextNrKol(void);
		  int  		__fastcall getNextIdZlec(void);
		  int  		__fastcall getIdJedn(const int _NrKol);
		  int  		__fastcall getMagHarm(void);
		  int  		__fastcall getIdKom(const int _NrKol);
		  int  		__fastcall getIdHarm(const int _NrKol, const int _IdKom);
		  void 		__fastcall prepareView(void);
		  Currency  __fastcall getRBH(void);
          bool      __fastcall valid(void);
          bool      __fastcall validZak(void);
		  bool      __fastcall validZakGl(void);
          bool      __fastcall validZakK(void);
		//NARZÊDZIA
		  mng::StreamDB* m_SDB;
		  mng::StreamDB* m_WarsztatSDB;
		  mng::StreamDB* m_SprzetSDB;
		  mng::StreamDB* m_HarmonogramSDB;
		  mng::StreamDB* m_JednostkaSDB;
		  mng::StreamDB* m_MagSDB;

		//ATRYBUTY
		  msg::MagID			m_MagID;
		  msg::ZlecID			m_ZlecID;
		  msg::ZlecREC          m_MainKUT;
		  int                   m_BiezRok;
		  bool                  m_Append;
		//ZABRONIONE
		  virtual int __fastcall ShowModal(void) { return TForm::ShowModal(); }
		//STA£E
		  static const String M_RBH_SQL;
		  static const String M_HARM_FUND_SQL;
		  static const String M_CHECK_DATA_ZAK_SQL;
		  static const String M_CHECK_GLW_DATA_ZAK_SQL;
		  static const String M_NO_DATA_ZAK_MSG;
		  static const String M_BAD_DATA_ZAK_MSG;
		  static const String M_BAD_GLW_DATA_ZAK_MSG;
};
//---------------------------------------------------------------------------
#endif
