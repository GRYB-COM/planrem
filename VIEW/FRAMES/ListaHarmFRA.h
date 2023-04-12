//---------------------------------------------------------------------------

#ifndef ListaHarmFRAH
#define ListaHarmFRAH
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
#include "HarmID.h"
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include "AdvCombo.hpp"
#include "AdvDBComboBox.hpp"
#include "AdvDBLookupComboBox.hpp"
//---------------------------------------------------------------------------
namespace mng {class StreamDB;}
namespace finders{
class T_ListaHarmFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopPA;
	TDBAdvGrid *m_AG;
	TAdvSmoothPanel *m_SearchPA;
	TDataSource *m_DS;
	TLabel *m_NrHarmLB;
	TLabel *Label1;
	TEdit *m_NrHarmED;
	TEdit *m_NazSprzED;
	TEdit *m_PodstED;
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
	void __fastcall setFilter(TObject *Sender);
	void __fastcall clearFilter(TObject *Sender);
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		   public:
		   int IdHarm;
		  };
		//INTERFEJS
		  Pars __fastcall getPars(void);
		  void __fastcall setPars(const Pars& _Pars);
		  void __fastcall setSearchClickEvent(TNotifyEvent Event);
		  void __fastcall setDataSet(TDataSet* _DataSet);
          void __fastcall open(void);
		//KONSTRUKTOR
		 __fastcall  T_ListaHarmFRA(TComponent* Owner);
		 __fastcall ~T_ListaHarmFRA(void);
private:
	  //ATRYBUTY
	  //NARZÊDZIA
};

}//end namespace
//---------------------------------------------------------------------------
#endif
