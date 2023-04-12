//---------------------------------------------------------------------------

#ifndef SlSprzetFRMH
#define SlSprzetFRMH
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
#include "AdvDBLookupComboBox.hpp"
//---------------------------------------------------------------------------
class T_SlSprzetFRM : public T_SL_BASE_FRM
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_TopPA;
	TLabel *Label1;
    TEdit *m_edFiltr;
    TAdvDBLookupComboBox *m_komCB;
    TLabel *Label2;
    TLabel *Label3;
    TAdvDBLookupComboBox *m_gspCB;
    TLabel *Label4;
    TAdvDBLookupComboBox *m_rspCB;
    TDataSource *m_komDS;
    TDataSource *m_gspDS;
    TDataSource *m_rspDS;
	TLabel *m_JIMFltLB;
	TEdit *m_JIMFltED;
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
	void __fastcall m_edFiltrChange(TObject *Sender);
    void __fastcall m_komCBCloseUp(TObject *Sender);
    void __fastcall m_gspCBCloseUp(TObject *Sender);
    void __fastcall m_rspCBCloseUp(TObject *Sender);
	void __fastcall m_JIMFltEDChange(TObject *Sender);

private:	// User declarations

    mng::StreamDB *m_komSDB;
    mng::StreamDB *m_gspSDB;
    mng::StreamDB *m_rspSDB;

    int m_komIndex;
    int m_komID;

    int m_rspIndex;
    int m_rspID;

    int m_gspIndex;
    int m_gspID;

	AnsiString m_nameFilter;
	AnsiString m_JIMFilter;
	AnsiString m_komFilter;
    AnsiString m_gspFilter;
    AnsiString m_rspFilter;

    AnsiString __fastcall getFilter();

    void __fastcall setFilterSDB(bool filtered = true);

    void __fastcall setFilterRspSDB(int gr);

public:		// User declarations

    void __fastcall MyShowModal();

	__fastcall T_SlSprzetFRM(TComponent* Owner);
};

class SprzetStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};
//---------------------------------------------------------------------------
#endif
