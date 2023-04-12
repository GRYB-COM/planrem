//---------------------------------------------------------------------------

#ifndef KosztyFRAH
#define KosztyFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "AdvSmoothButton.hpp"
#include "KUTkosztySumFRA.h"
//---------------------------------------------------------------------------
namespace msg{ class MagID;}
//---------------------------------------------------------------------------
class T_KosztyFRA : public TFrame
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopP;
	TDBGrid *m_DBG;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *AdvSmoothButton1;
	TAdvSmoothButton *AdvSmoothButton2;
	TAdvSmoothButton *AdvSmoothButton3;
	TAdvSmoothPanel *AdvSmoothPanel2;
public:
	//INTERFEJS
	  void __fastcall open(const msg::MagID& _MagID);
	  void __fastcall close(void);
	  T_KUTkosztySumFRA * m_SumKosztyFRA;
	//KONSTRUKTOR i DESTRUKTOR
	  __fastcall T_KosztyFRA(TComponent* Owner);
private:	// User declarations
};
//---------------------------------------------------------------------------
extern PACKAGE T_KosztyFRA *_KosztyFRA;
//---------------------------------------------------------------------------
#endif
