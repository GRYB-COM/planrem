//---------------------------------------------------------------------------

#ifndef AddRbhFRMH
#define AddRbhFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_BASE_FRM.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include "Numedit.h"
#include <Mask.hpp>
namespace mng     { class QueryDB;  class StreamDB;}
namespace jbutils { class TMyIni; }
//---------------------------------------------------------------------------
class T_AddRbhFRM : public T_SL_BASE_FRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TDBLookupComboBox *m_WarsztatCB;
	TLabel *m_WarsztatLB;
	TDBLookupComboBox *m_MiesCB;
	TLabel *m_MiesLB;
	TDataSource *m_MiesDS;
	TDataSource *m_WarsztatDS;
	TLabel *Label1;
	TDBLookupComboBox *m_ZlecCB;
	TDataSource *m_ZlecDS;
	TNumEdit *m_IlSprzED;
	TLabel *Label2;
	TLabel *Label3;
	TNumEdit *m_IlRBHEd;
	TAdvSmoothButton *m_AddBB;
	TLabel *Label4;
	TNumEdit *m_PlanRBHED;
	TLabel *Label5;
	TDBLookupComboBox *m_HarmCB;
	TDataSource *m_HarmDS;
	TLabel *Label6;
	TNumEdit *m_PlanIlED;
	TDBEdit *m_SumPlanIlTE;
	TDBEdit *m_SumPlanRBHTE;
	TDBEdit *m_SumIlSprzTE;
	TDBEdit *m_SumRBHTE;
	TLabel *Label7;
	TDataSource *m_SumDS;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall refreshDane(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall m_AddBBClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall m_ZlecCBCloseUp(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_HarmCBCloseUp(TObject *Sender);
	void __fastcall m_DBGDblClick(TObject *Sender);
public:		// User declarations
	  //INTERFEJS
		int __fastcall showModal(void);
	  //KONSTRUKTOR DESTRUKTOR
		__fastcall  T_AddRbhFRM(TComponent* Owner);
		__fastcall ~T_AddRbhFRM(void);

private:
	  //NARZÊDZIA
		mng::StreamDB   * m_WarsztatSDB;
		mng::StreamDB   * m_MiesSDB;
		mng::StreamDB   * m_ZlecSDB;
		mng::StreamDB   * m_HarmSDB;
		mng::StreamDB   * m_SumSDB;
        mng::QueryDB    * m_PlanQDB;
		jbutils::TMyIni * m_Ini;
	  //ATRYBUTY
		int m_Rok;
	  //ZAKAZANE
		virtual int __fastcall ShowModal(void) {return T_SL_BASE_FRM::ShowModal();}
	  //POMOCNICZE
		void __fastcall openZlec(void);
		int  __fastcall getIdDet(void);
		void __fastcall update(const int _IdDet);
		void __fastcall insert(void);
        void __fastcall clear(void);

	 //STA£E
       static const String M_PLAN_WYK_SQL;

};
//---------------------------------------------------------------------------
#endif
