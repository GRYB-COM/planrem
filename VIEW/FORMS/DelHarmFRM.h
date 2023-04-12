//---------------------------------------------------------------------------

#ifndef DelHarmFRMH
#define DelHarmFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGroupBox.hpp"
#include "AdvOfficeButtons.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "HarmID.h"
//---------------------------------------------------------------------------
class T_DelHarmFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvSmoothButton *m_CancelBT;
	TAdvSmoothButton *m_DelBT;
	TAdvOfficeRadioGroup *m_DelRG;
	void __fastcall m_DelBTClick(TObject *Sender);
public:
 public:
		//KLASY WEWNÊTR¯NE
		  class Pars{
		   public:
		   msg::HarmID HarmId;
		   int NrMies;
		   Pars(void);
		  };
		//INTERFEJS
		  int __fastcall display(const Pars& _Pars);
		//KONSTRUKTOR
		  __fastcall T_DelHarmFRM(TComponent* Owner);
		//FUNKCJE PRYWATNE
		  virtual int __fastcall ShowModal(void){return TForm::ShowModal();}
private:
	   //ATRYBUTY
		 Pars m_Pars;

};
//---------------------------------------------------------------------------
#endif
