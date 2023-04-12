//---------------------------------------------------------------------------

#ifndef SlSprzetEditFRMH
#define SlSprzetEditFRMH
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
#include "AdvDBLookupComboBox.hpp"
//---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}

class T_SlSprzetEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TDBEdit *DBEdit2;
    TDataSource *m_komDS;
	TLabel *Label5;
	TLabel *Label3;
    TDataSource *m_rspDS;
    TLabel *Label1;
    TAdvDBLookupComboBox *m_komCB;
    TAdvDBLookupComboBox *m_gspCB;
    TDataSource *m_gspDS;
    TAdvDBLookupComboBox *m_rspCB;
	TDBEdit *DBEdit1;
	TLabel *Label4;
    void __fastcall m_komCBCloseUp(TObject *Sender);
    void __fastcall m_gspCBCloseUp(TObject *Sender);
    void __fastcall m_rspCBCloseUp(TObject *Sender);

private:	// User declarations

    mng::StreamDB *m_komSDB;
    mng::StreamDB *m_gspSDB;
    mng::StreamDB *m_rspSDB;

    int m_komID;
    int m_gspID;
    int m_rspID;

    void __fastcall setEnabledBtn(bool enbl);

public:		// User declarations

    void __fastcall setKomID(int val);
    void __fastcall setRspID(int val);
    void __fastcall setGspID(int val);

    void __fastcall setFilterRspSDB(const AnsiString &filter);

    void __fastcall addRecord(TDataSource *ds, AnsiString keyField);

	__fastcall T_SlSprzetEditFRM(TComponent* Owner);
	__fastcall ~T_SlSprzetEditFRM();
};
//---------------------------------------------------------------------------
#endif
