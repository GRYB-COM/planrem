//---------------------------------------------------------------------------

#ifndef FindHarmFRMH
#define FindHarmFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ListaHarmFRA.h"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>

//---------------------------------------------------------------------------
namespace mng { class StreamDB; }
namespace finders{
class T_FindHarmFRM : public TForm
{
__published:	// IDE-managed Components
	T_ListaHarmFRA *m_ListaHarmFRA;
	TAdvSmoothPanel *m_BottomPA;
	TAdvSmoothButton *m_OKBT;
	TAdvSmoothButton *m_CancelBT;
	TDataSource *m_DS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_OKBTClick(TObject *Sender);
public:
		//INTERFEJS
		  T_ListaHarmFRA::Pars __fastcall getPars(void);
		  void __fastcall setPars(const T_ListaHarmFRA::Pars& _Pars);
		  void __fastcall setSearchClictEvet(TNotifyEvent Event);
		  void __fastcall setDataSet(TDataSet* _DataSet);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_FindHarmFRM(TComponent* Owner);
		  __fastcall ~T_FindHarmFRM(void);

private:
	  //ZDARZENIA
		void __fastcall m_AGDblClick(TObject *Sender);
};

}//end namespace
//---------------------------------------------------------------------------
#endif
