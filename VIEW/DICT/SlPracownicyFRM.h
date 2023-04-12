//---------------------------------------------------------------------------

#ifndef SlPracownicyFRMH
#define SlPracownicyFRMH
//---------------------------------------------------------------------------
#include "MANAGER\stream_db.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_BASE_FRM.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class T_SlPracownicyFRM : public T_SL_BASE_FRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TDBLookupComboBox *m_komCB;
	TLabel *Label1;
	TDataSource *m_komDS;
	void __fastcall m_komCBCloseUp(TObject *Sender);
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
	void __fastcall m_UsunBBClick(TObject *Sender);
private:	// User declarations

	mng::StreamDB *m_komSDB;

public:		// User declarations

	void __fastcall MyShowModal();

	__fastcall T_SlPracownicyFRM(TComponent* Owner);
	__fastcall ~T_SlPracownicyFRM();
};

class PracownicyStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};

//---------------------------------------------------------------------------
#endif
