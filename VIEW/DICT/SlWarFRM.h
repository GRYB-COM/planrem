//---------------------------------------------------------------------------

#ifndef SlWarFRMH
#define SlWarFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include "SlEditFRM.h"
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "AdvSmoothButton.hpp"
//---------------------------------------------------------------------------
class T_SlWarEdFRM;
class T_SlWarFRM : public T_SlEditFRM
{
__published:	// IDE-managed Components
public:
		//KONSTRUKTOR DESTRUKTOR
				  __fastcall  T_SlWarFRM(TComponent* Owner);
		  virtual __fastcall ~T_SlWarFRM(void);
private:
		//NARZÊDZIA
          T_SlWarEdFRM * m_WarEdFRM;
		//ZDARZENIA
		  virtual void __fastcall onShow(void);
};
//---------------------------------------------------------------------------
#endif
