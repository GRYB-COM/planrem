//---------------------------------------------------------------------------

#ifndef FindProtFRMH
#define FindProtFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ListaProtFRA.h"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include "ListaHarmFRA.h"

//---------------------------------------------------------------------------
namespace mng { class StreamDB; }
namespace finders{
class T_FindProtFRM : public TForm
{
__published:	// IDE-managed Components
	T_ListaProtFRA *m_ListaProtFRA;
	TAdvSmoothPanel *m_BottomPA;
	TAdvSmoothButton *m_OKBT;
	TAdvSmoothButton *m_CancelBT;
	TDataSource *m_DS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_OKBTClick(TObject *Sender);
public:
		//INTERFEJS
		  T_ListaProtFRA::Pars __fastcall getPars(void);
		  void __fastcall setPars(const T_ListaProtFRA::Pars& _Pars);
		  void __fastcall setSearchClictEvet(TNotifyEvent Event);
		  void __fastcall setDataSet(TDataSet* _DataSet);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_FindProtFRM(TComponent* Owner);
		  __fastcall ~T_FindProtFRM(void);

private:
	  //ZDARZENIA
		void __fastcall m_AGDblClick(TObject *Sender);
};

}//end namespace
//---------------------------------------------------------------------------
#endif
