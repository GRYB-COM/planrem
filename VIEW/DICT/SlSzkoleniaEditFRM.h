//---------------------------------------------------------------------------

#ifndef SlSzkoleniaEditFRMH
#define SlSzkoleniaEditFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_EDIT_FRM.h"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class T_SlSzkoleniaEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TDBLookupComboBox *m_miesCB;
	TLabel *Label1;
	TDBEdit *DBEdit1;
	TDataSource *m_miesDS;
private:	// User declarations

	mng::StreamDB *m_miesSDB;

public:		// User declarations

	__fastcall T_SlSzkoleniaEditFRM(TComponent* Owner);
	__fastcall ~T_SlSzkoleniaEditFRM();
};
//---------------------------------------------------------------------------
#endif
