//---------------------------------------------------------------------------

#ifndef MoveHarmRBFFRMH
#define MoveHarmRBFFRMH
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
#include <Grids.hpp>
#include <Mask.hpp>
namespace msg { class RBH4Mies;}
//---------------------------------------------------------------------------
class T_MoveHarmRBHFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel2;
	TDBGrid *m_MiesGR;
	TClientDataSet *m_RBHCD;
	TDataSource *m_RBHDS;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothButton *AdvSmoothButton4;
	TLabel *Label1;
	TLabel *Label2;
	TDBEdit *m_IloscED;
	TLabel *Label3;
	TDBEdit *m_RBHED;
	TLabel *Label5;
	TDBEdit *m_DataOdED;
	TDBEdit *m_DataDO;
	TLabel *Label4;
	TIntegerField *m_RBHCDNR_MIES;
	TFMTBCDField *m_RBHCDRBH_MIES;
	TFMTBCDField *m_RBHCDPLAN_RBH;
	TFMTBCDField *m_RBHCDPOZOSTALO;
	TFMTBCDField *m_RBHCDBILANS;
	TDataSource *m_HarmDetDS;
	TStringField *m_RBHCDNAZ_MIES;
	TDataSource *m_HarmDS;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TDBLookupComboBox *m_MiesCB;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TLabel *Label10;
	TDBEdit *DBEdit3;
	TClientDataSet *m_PrzenCD;
	TDataSource *m_PrzenDS;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AdvSmoothButton4Click(TObject *Sender);
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
	void __fastcall m_RBHCDCalcFields(TDataSet *DataSet);
	void __fastcall m_MiesGRDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State);
public:
		//INTERFEJS
		  int __fastcall display(const msg::RBH4Mies& _RBH);
		// KONSTRUKTOR
		  __fastcall T_MoveHarmRBHFRM(TComponent* Owner);
private:	// User declarations
			//METODY POMOCNICZE
			  void __fastcall  fillRBHCD(const msg::RBH4Mies& _RBH);
			  void __fastcall  fillPrzenCD(void);
			//METODY ZABRONIONE
			  virtual int __fastcall ShowModal(void) { return TForm::ShowModal();}
};
//---------------------------------------------------------------------------
#endif
