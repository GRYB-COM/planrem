//---------------------------------------------------------------------------

#ifndef SlWarsztatyFRMH
#define SlWarsztatyFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include "AsgLinks.hpp"
//---------------------------------------------------------------------------
  namespace mng{class StreamDB;}
class T_SlWarsztatyFRM : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TAdvSmoothPanel *m_BottomASP;
	TBitBtn *m_CancelBB;
	TBitBtn *m_SaveBB;
	TDataSource *m_DS;
	TDBAdvGrid *m_DBG;
	TLUComboEditLink *m_WydzialyLUEL;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall m_DBGGetEditorProp(TObject *Sender, int ACol, int ARow, TEditLink *AEditLink);
	void __fastcall m_DBGGetEditorType(TObject *Sender, int ACol, int ARow, TEditorType &AEditor);
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall m_DBGComboCloseUp(TObject *Sender, int ARow, int ACol);
	void __fastcall m_DBGComboChange(TObject *Sender, int ACol, int ARow, int AItemIndex,
          UnicodeString ASelection);
	void __fastcall m_DBGComboObjectChange(TObject *Sender, int ACol, int ARow, int AItemIndex,
          UnicodeString ASelection, TObject *AObject);


private:	// User declarations
void fillOddzialyEL();

	mng::StreamDB*	m_SDB;
public:		// User declarations
	__fastcall T_SlWarsztatyFRM(TComponent* Owner);
		__fastcall ~T_SlWarsztatyFRM();
};
//---------------------------------------------------------------------------
extern PACKAGE T_SlWarsztatyFRM *_SlWarsztatyFRM;
//---------------------------------------------------------------------------
#endif
