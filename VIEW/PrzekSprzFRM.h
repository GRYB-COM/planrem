//---------------------------------------------------------------------------

#ifndef PrzekSprzFRMH
#define PrzekSprzFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include "AdvDateTimePicker.hpp"
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <map>
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
namespace readers { class SPReader; }
namespace mng     { class StreamDB; }
namespace mng     { class QueryDB;  }
namespace jbutils { class TMyIni;   }
class T_PrzekSprzFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_SearchPA;
	TAdvSmoothPanel *m_TopPA;
	TDBAdvGrid *m_AG;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *bbWrite;
	TAdvSmoothButton *m_PrintBB;
	TEdit *m_PrPrzekED;
	TLabel *m_ProtLB;
	TAdvSmoothButton *m_OpenBT;
	TDataSource *m_DetailDS;
	TAdvSmoothButton *m_AddBB;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TLabel *Label2;
	TLabel *m_DataPrzekLB;
	TDBEdit *m_OdbiorcaED;
	TDBEdit *m_DataPrzekED;
	TDataSource *m_MasterDS;
	TAdvSmoothButton *m_EditBB;
	TAdvSmoothButton *m_DelBB;
	TAdvSmoothButton *m_AddBT;
	TAdvSmoothPanel *m_EmptyPA;
	TAdvSmoothButton *m_CloseBB;
	TAdvSmoothButton *m_AdwSearchBT;
	void __fastcall m_OpenBTClick(TObject *Sender);
	void __fastcall m_PrintBBClick(TObject *Sender);
	void __fastcall bbWriteClick(TObject *Sender);
	void __fastcall m_PrPrzekEDKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_AddBTClick(TObject *Sender);
	void __fastcall m_AddBBClick(TObject *Sender);
	void __fastcall m_EditBBClick(TObject *Sender);
	void __fastcall m_DelBBClick(TObject *Sender);
	void __fastcall m_AdwSearchBTClick(TObject *Sender);
	void __fastcall m_AGDblClick(TObject *Sender);

public:
	//INTERFEJS
	//KLASY POMOCNICZE
	  typedef std::map<String,String> Record;
	  typedef std::map<int,Record> RecordSet;
	//STATYCZNE dla MAKR
	  static TDataSet * m_PrintDS;
	  static RecordSet M_RS;  //static ¿eby makra widzia³y
	//KONSTRUKTOR DESTRUKTOR
	  __fastcall  T_PrzekSprzFRM(TComponent* Owner);
	  __fastcall ~T_PrzekSprzFRM(void);
	//STATIKI
	  static int              M_ILOSC;
private:
	//NARZÊDZIA
	  mng::StreamDB    * m_MasterSDB;
	  mng::StreamDB    * m_DetailSDB;
	  jbutils::TMyIni  * m_Ini;
	//ATRYBUTY
	//STATIKI
	  static const AnsiString M_MASTER_SQL;
	  static const AnsiString M_DETAIL_SQL;
	  static const AnsiString M_PRINTER_SQL;
	  static const AnsiString M_PRINTER_MAP;
	//FUNKCJE POMOCNICZE
	  void open(const bool _Msg);
	  bool find(int& IdWydz, int& RokProt, int& IdProt);
	  void openDS(const int& IdWydz, const int& RokProt, const int& IdProt);
	  void openDetDS(const int& IdWydz, const int& RokProt, const int& IdProt);
	  void close(void);
	  void add(void);
	  void fill(TDataSet * _DS);
	  void activate(const bool _Show);
   //KLASY POMOCNICZE
	 class MasterEvents: public mng::EventsDefault{
	 public:
		   virtual void onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name);
		   virtual void beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied);
	 };
	 class DetailEvents: public mng::EventsDefault{
	 public:
		   virtual void onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name);
		   virtual void beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied);
	 };

};
extern AnsiString getMacroPrzek(AnsiString Pars);
extern AnsiString getPrzekIlosc(AnsiString Pars);
extern AnsiString getPrzekIlSlw(AnsiString Pars);
extern AnsiString getPrzekLPoz(AnsiString Pars);
extern AnsiString getPrzekLPSlw(AnsiString Pars);
//---------------------------------------------------------------------------
#endif
