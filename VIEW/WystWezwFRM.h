//---------------------------------------------------------------------------

#ifndef WystWezwFRMH
#define WystWezwFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGroupBox.hpp"
#include "AdvOfficeButtons.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothProgressBar.hpp"
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include <Grids.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class WystWezwWaitForm;
namespace jbutils {class TMyIni; }
class T_WystWezwFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_DodajBB;
	TAdvSmoothButton *m_EdytujBB;
	TAdvSmoothPanel *m_MainPA;
	TAdvOfficeRadioGroup *m_FiltrWezwRG;
	TAdvSmoothDatePicker *m_DataWystDCP;
	TLabel *m_DataWystLB;
	TDBAdvGrid *m_ListaSprzGR;
	TDataSource *m_ListaSprzDS;
	TAdvOfficeRadioGroup *m_ModeRG;
	TAdvSmoothDatePicker *m_DataWystDoDCP;
	TLabel *m_GridHeadLB;
	TLabel *m_DataWystDoLB;
	TAdvSmoothDatePicker *m_DataWystOdDCP;
	TAdvSmoothDatePicker *m_DataZakDoDCP;
	TAdvSmoothButton *m_DelBB;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall OnChange(TObject *Sender);
public:		// User declarations
	__fastcall  T_WystWezwFRM(TComponent* Owner);
	__fastcall ~T_WystWezwFRM(void);
    void __fastcall setOnChange(TNotifyEvent _OnChange);
private:
	//METODY POMOCNICZE
	  void start(const int _Max);
	  void step(const AnsiString& _Capt);
	  void stop(void);
	//NARZÊDZIA
	  jbutils::TMyIni * m_Ini;
	//ZDARZENIA
	  TNotifyEvent m_OnChange;

 friend WystWezwWaitForm;
};
//---------------------------------------------------------------------------
#endif
