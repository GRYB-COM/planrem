//---------------------------------------------------------------------------

#ifndef PowiadomFRAH
#define PowiadomFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "AdvSmoothButton.hpp"
//---------------------------------------------------------------------------
namespace msg{ class MagID;}
//---------------------------------------------------------------------------
class T_PowiadomFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *m_TopP;
	TDBGrid *m_DBG;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothButton *AdvSmoothButton2;
	TAdvSmoothButton *AdvSmoothButton3;
	TAdvSmoothPanel *AdvSmoothPanel2;
public:
	//INTERFEJS
	  void __fastcall open(const msg::MagID& _MagID);
	  void __fastcall close(void);
	//KONSTRUKTOR DESTRUKTOR
	  __fastcall T_PowiadomFRA(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_PowiadomFRA *_PowiadomFRA;
//---------------------------------------------------------------------------
#endif
