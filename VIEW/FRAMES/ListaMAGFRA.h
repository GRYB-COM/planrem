//---------------------------------------------------------------------------

#ifndef ListaMAGFRAH
#define ListaMAGFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <DBGrids.hpp>
#include <Graphics.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include "MagID.h"
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include "AdvCombo.hpp"
#include "AdvDBComboBox.hpp"
#include "AdvDBLookupComboBox.hpp"
//---------------------------------------------------------------------------
namespace mng {class StreamDB;}
namespace jbutils { class TMyIni; }
namespace finders{
class T_ListaMAGFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopPA;
	TDBAdvGrid *m_AG;
	TAdvSmoothPanel *m_SearchPA;
	TDataSource *m_DS;
	TLabel *m_NrMagLB;
	TLabel *Label1;
	TDataSource *m_HarmDS;
	TDataSource *m_SprzetDS;
	TDataSource *m_JednDS;
	TDataSource *m_WarDS;
	TEdit *m_NrMagED;
	TEdit *m_NazSprzED;
	TEdit *m_IloscED;
	TEdit *m_DostED;
	TEdit *m_WarED;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TAdvSmoothButton *m_setFilterBT;
	TAdvSmoothButton *m_ClearFilterBT;
	TLabel *Label5;
	TLabel *m_FilterLB;
	TLabel *m_FilterDetLB;
	TLabel *Label6;
	TEdit *m_ProtPrzyjED;
	TLabel *Label7;
	TEdit *m_ProtPrzekED;
	TEdit *m_NrFabrED;
	TEdit *m_NrRejED;
	TLabel *Label9;
	TLabel *Label8;
	TLabel *Label10;
	TEdit *m_HarmED;
	void __fastcall setFilter(TObject *Sender);
	void __fastcall clearFilter(TObject *Sender);
	void __fastcall MainKeyPress(TObject *Sender, wchar_t &Key);
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		   public:
           msg::MagID IdMag;
		  };
		//INTERFEJS
		  Pars __fastcall getPars(void);
		  void __fastcall setPars(const Pars& _Pars);
		  void __fastcall setSearchClickEvent(TNotifyEvent Event);
		  void __fastcall setDataSet(TDataSet* _DataSet);
		  void __fastcall setIsFilter(const bool _IsFilter);
		  void __fastcall open(void);
		  void __fastcall close(void);
		//KONSTRUKTOR
		 __fastcall  T_ListaMAGFRA(TComponent* Owner);
		 __fastcall ~T_ListaMAGFRA(void);
private:
	  //ATRYBUTY
		bool m_IsFilter;
	  //NARZÊDZIA
		mng::StreamDB   * m_HarmSDB;
		mng::StreamDB   * m_SprzetSDB;
		mng::StreamDB   * m_JednSDB;
		mng::StreamDB   * m_WarSDB;
		jbutils::TMyIni * m_Ini;
	  //FUNKCJE POMOCNICZE
		void __fastcall saveFilter(void);
		void __fastcall readFilter(void);
};

}//end namespace
//---------------------------------------------------------------------------
#endif
