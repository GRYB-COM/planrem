//---------------------------------------------------------------------------

#ifndef SlKadraEditFRMH
#define SlKadraEditFRMH
//---------------------------------------------------------------------------
#include "MANAGER\stream_db.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_EDIT_FRM.h"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class T_SlKadraEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TDBGrid *m_szkolGrid;
	TAdvSmoothButton *m_Dodaj;
	TAdvSmoothButton *m_Edytuj;
	TAdvSmoothButton *m_Usun;
	TLabel *Label7;
	TDBEdit *edKod;
	TDBEdit *edNazwa;
	TLabel *Label1;
	TDBEdit *DBEdit2;
	TLabel *Label2;
	TDBEdit *DBEdit5;
	TLabel *Label4;
	TDBEdit *DBEdit6;
	TLabel *Label5;
	TDBEdit *DBEdit7;
	TLabel *Label6;
	TLabel *Label10;
	TDataSource *m_szkolDS;
	TLabel *Label3;
	void __fastcall m_DodajClick(TObject *Sender);
	void __fastcall m_EdytujClick(TObject *Sender);
	void __fastcall m_UsunClick(TObject *Sender);
private:	// User declarations

	int m_valueID;

	mng::StreamDB *m_szkolSDB;

public:		// User declarations

	void __fastcall addRecord(TDataSource *ds, AnsiString keyField);
	void __fastcall editRecord(TDataSource *ds);

	void __fastcall applyDetails(AnsiString keyValue);
	void __fastcall applyDetails();
	void __fastcall cancelDetails();

	__fastcall T_SlKadraEditFRM(TComponent* Owner);
	__fastcall ~T_SlKadraEditFRM();
};

class SzkolStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};

//---------------------------------------------------------------------------
#endif
