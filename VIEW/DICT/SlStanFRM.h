//---------------------------------------------------------------------------

#ifndef SlStanFRMH
#define SlStanFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SlEditFRM.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class T_SlStanEdFRM;
class T_SlStanFRM : public T_SlEditFRM
{
__published:	// IDE-managed Components
	void __fastcall m_DodajBBClick(TObject *Sender);
public:
		//KONSTRUKTOR DESTRUKTOR
				  __fastcall  T_SlStanFRM(TComponent* Owner);
		  virtual __fastcall ~T_SlStanFRM(void);
private:
		//NARZÊDZIA
		  T_SlStanEdFRM * m_StanEdFRM;
		//ZDARZENIA
		  virtual void __fastcall onShow(void);
};
//---------------------------------------------------------------------------
#endif
