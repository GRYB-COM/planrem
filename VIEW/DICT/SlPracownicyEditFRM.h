//---------------------------------------------------------------------------

#ifndef SlPracownicyEditFRMH
#define SlPracownicyEditFRMH
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
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include "AdvDateTimePicker.hpp"
#include "AdvDBDateTimePicker.hpp"
#include <ComCtrls.hpp>
#include "AdvSmoothTabPager.hpp"
//---------------------------------------------------------------------------
class T_SlPracownicyEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
	TDataSource *m_urlopDS;
	TLabel *Label1;
	TDBEdit *m_NazED;
	TLabel *Label2;
	TDBEdit *m_ImED;
	TLabel *Label3;
	TDBLookupComboBox *m_stpCB;
	TDataSource *m_stpDS;
	TDataSource *m_stnDS;
	TDataSource *m_komDS;
	TDataSource *m_kdrDS;
	TLabel *Label4;
	TDBLookupComboBox *m_stnCB;
	TLabel *Label6;
	TDBLookupComboBox *m_kdrCB;
	TLabel *Label5;
	TDBLookupComboBox *m_komCB;
	TLabel *Label7;
	TDBEdit *m_EtataPrED;
	TDBEdit *m_StawkaGodzED;
	TLabel *Label8;
	TDataSource *m_delDS;
	TLabel *Label12;
	TDBEdit *m_EtatED;
	TAdvDBDateTimePicker *m_DataOdDTP;
	TLabel *Label13;
	TAdvDBDateTimePicker *m_DataDoDTP;
	TAdvSmoothTabPager *m_WolneTPC;
	TAdvSmoothTabPage *AdvSmoothTabPager11;
	TAdvSmoothTabPage *AdvSmoothTabPager12;
	TAdvSmoothTabPage *AdvSmoothTabPager13;
	TDBGrid *m_urlopGrid;
	TAdvSmoothButton *m_Dodaj;
	TAdvSmoothButton *m_Edytuj;
	TAdvSmoothButton *m_Usun;
	TDBGrid *m_delGrid;
	TAdvSmoothButton *m_DodajD;
	TAdvSmoothButton *m_EdytujD;
	TAdvSmoothButton *m_UsunD;
	TAdvSmoothButton *m_DodajZ;
	TAdvSmoothButton *m_EdytujZ;
	TAdvSmoothButton *m_UsunZ;
	TDBGrid *m_WolneGR;
	TLabel *Label9;
	TDataSource *m_zwDS;
	TAdvSmoothTabPage *AdvSmoothTabPage1;
	TDBGrid *m_EtatyGR;
	TAdvSmoothButton *m_AddEtatBT;
	TAdvSmoothButton *m_EdEtatBT;
	TAdvSmoothButton *m_DelEtatBB;
	TDataSource *m_EtatyDS;
	void __fastcall m_DodajClick(TObject *Sender);
	void __fastcall m_UsunClick(TObject *Sender);
	void __fastcall m_EdytujClick(TObject *Sender);
	void __fastcall m_DodajDClick(TObject *Sender);
	void __fastcall m_EdytujDClick(TObject *Sender);
	void __fastcall m_UsunDClick(TObject *Sender);
	void __fastcall m_DodajZClick(TObject *Sender);
	void __fastcall m_EdytujZClick(TObject *Sender);
	void __fastcall m_UsunZClick(TObject *Sender);
	void __fastcall m_DataDoDTPKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_AddEtatBTClick(TObject *Sender);
	void __fastcall m_EdEtatBTClick(TObject *Sender);
	void __fastcall m_DelEtatBBClick(TObject *Sender);
private:	// User declarations

	int m_idUrlpu;
	int m_idDelegacji;
    int m_idZwolnienia;
    int m_idEtatu;
	mng::StreamDB *m_urlopSDB;
	mng::StreamDB *m_delSDB;
	mng::StreamDB *m_zwSDB;
	mng::StreamDB *m_stpSDB;
	mng::StreamDB *m_stnSDB;
	mng::StreamDB *m_komSDB;
	mng::StreamDB *m_kdrSDB;
	mng::StreamDB *m_EtatySDB;

	void __fastcall openUrlopySDB(int idos);
	void __fastcall openEtatySDB(int idos);
	void __fastcall openDelegacjeSDB(int idos);
	void __fastcall openZwolnieniaSDB(int idos);

	void __fastcall applyUrlopySDB(int keyValue);
	void __fastcall applyDelegacjeSDB(int keyValue);
	void __fastcall applyZwolnieniaSDB(int keyValue);

public:		// User declarations

	void __fastcall addRecord(TDataSource *ds, AnsiString keyField, int komFilter);
	void __fastcall editRecord(TDataSource *ds);

	void __fastcall applyDetails(int keyValue);
	void __fastcall applyDetails();
	void __fastcall cancelDetails();

	__fastcall T_SlPracownicyEditFRM(TComponent* Owner);
	__fastcall ~T_SlPracownicyEditFRM();
};

class UrlopyStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};

class DelegacjeStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};

class ZwolnieniaStreamEvents : public mng::EventsDefault
{
  virtual void beforeUpdateRecord(mng::StreamDB *str_db, TDataSet *source, TCustomClientDataSet *delta, TUpdateKind upd_kind, bool &applied);
};

class EtatyStreamEvents : public mng::EventsDefault
{
  virtual void afterInsert(mng::StreamDB* str_db);
};

//---------------------------------------------------------------------------
#endif
