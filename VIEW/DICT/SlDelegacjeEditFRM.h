//---------------------------------------------------------------------------

#ifndef SlDelegacjeEditFRMH
#define SlDelegacjeEditFRMH
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
namespace mng
{
  class StreamDB;
}

class T_SlDelegacjeEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TDBLookupComboBox *m_MiesCB;
	TDBEdit *DBEdit1;
	TLabel *Label1;
	TDBLookupComboBox *m_komCB;
	TLabel *Label5;
	TDataSource *m_komDS;
	TDataSource *m_MiesDS;
	TLabel *Label2;
	TDBEdit *m_RokED;
	TLabel *Label4;
	TDBEdit *m_DniED;
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations

	mng::StreamDB *m_MiesSDB;
	mng::StreamDB *m_KomSDB;

public:		// User declarations

	__fastcall T_SlDelegacjeEditFRM(TComponent* Owner);
	__fastcall ~T_SlDelegacjeEditFRM();
};
//---------------------------------------------------------------------------
#endif
