//---------------------------------------------------------------------------

#ifndef ListaMagFRMH
#define ListaMagFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ListaMAGFRA.h"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>

//---------------------------------------------------------------------------
namespace mng { class StreamDB; }
namespace finders{
class T_ListaMagFRM : public TForm
{
__published:	// IDE-managed Components
	T_ListaMAGFRA *m_ListaMagFRA;
	TAdvSmoothPanel *m_BottomPA;
	TAdvSmoothButton *m_OKBT;
	TAdvSmoothButton *m_CancelBT;
	TDataSource *m_DS;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_OKBTClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
public:
		//INTERFEJS
		  T_ListaMAGFRA::Pars __fastcall getPars(void);
		  void __fastcall setPars(const T_ListaMAGFRA::Pars& _Pars);
		  void __fastcall setSearchClictEvet(TNotifyEvent Event);
		  void __fastcall setDataSet(TDataSet* _DataSet);
		  void __fastcall setIsFilter(const bool _IsFilter);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_ListaMagFRM(TComponent* Owner);
		  __fastcall ~T_ListaMagFRM(void);

private:
	  //ZDARZENIA
		void __fastcall m_AGDblClick(TObject *Sender);


};

}//end namespace
//---------------------------------------------------------------------------
#endif
