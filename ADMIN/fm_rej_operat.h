//---------------------------------------------------------------------------

#ifndef fm_rej_operatH
#define fm_rej_operatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "fr_rv_navigator_ext.h"
#include "fr_rv_navigator_full.h"
#include "fr_rv_navigator_smpl.h"
#include <Menus.hpp>

#include <manager\controls_setter.h>
#include "unit\defines.h"
//---------------------------------------------------------------------------

class TDMOperator;

class TRejOperat : public TForm
{
__published:	// IDE-managed Components
   TActionList *akcje;
   TPanel *paBottom;
   TPanel *paTop;
   TDataSource *dsOperat;
   TImageList *imgLista;
   TAction *actZamknij;
   TBitBtn *bbZamknij;
   TAction *actGrupy;
   TAction *actUpra;
   TBitBtn *bbUpraw;
   TAction *actDodaj;
   TAction *actZmien;
   TAction *actDrukuj;
   TBitBtn *bbDrukuj;
   TAction *actZapisz;
   TAction *actAnuluj;
   TAction *actFirst;
   TAction *actPrevious;
   TAction *actNext;
   TAction *actLast;
   TPanel *paEdit;
   TPanel *paGrid;
   TDBGrid *dbgOperat;
   TLabel *Label1;
   TDBEdit *dbeNazwaOp;
   TDBEdit *dbeNazwaZewn;
   TLabel *Label2;
   TDBEdit *dbeKodOper;
   TLabel *Label3;
   TLabel *Label5;
   TDBEdit *dbeKodWydz;
   TDBEdit *dbeOpis;
   TLabel *Label4;
   TRadioGroup *rgStatus;
   TLabel *Label6;
   TEdit *edHaslo;
   TEdit *edConfHaslo;
   TLabel *Label7;
   TPanel *paNavigator;
   TDBEdit *dbeKodSkrocony;
   TLabel *Label8;
   TAction *actAnulujAll;
   TBitBtn *bbAnulujAll;
   TAction *actZapiszDB;
   TRVFrmNavigatorFull *frmNavig;
   TAction *actDelete;
   TPopupMenu *pmWydruki;
   TMenuItem *pmPrintOperat;
   TMenuItem *pmPrintCurrOperUpra;
   TMenuItem *pmPrintAllOperUpra;
   TMenuItem *pmPrintCurrOperRoles;
   TMenuItem *pmPrintAllOperRoles;
   TAction *actPrintUpraAll;
   TDBEdit *dbeDateZmH;
   TLabel *Label9;
   void __fastcall actZamknijExecute(TObject *Sender);
   void __fastcall actDodajExecute(TObject *Sender);
   void __fastcall actAnulujExecute(TObject *Sender);
   void __fastcall actDrukujExecute(TObject *Sender);
   void __fastcall actUpraExecute(TObject *Sender);
   void __fastcall actZapiszExecute(TObject *Sender);
   void __fastcall actZmienExecute(TObject *Sender);
   void __fastcall dbgOperatCellClick(TColumn *Column);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall actFirstExecute(TObject *Sender);
   void __fastcall actPreviousExecute(TObject *Sender);
   void __fastcall actNextExecute(TObject *Sender);
   void __fastcall actLastExecute(TObject *Sender);
   void __fastcall dsOperatDataChange(TObject *Sender, TField *Field);
   void __fastcall actGrupyExecute(TObject *Sender);
   void __fastcall FormKeyPress(TObject *Sender, char &Key);
   void __fastcall actAnulujAllExecute(TObject *Sender);
   void __fastcall actZapiszDBExecute(TObject *Sender);
   void __fastcall actDeleteExecute(TObject *Sender);
   void __fastcall actPrintUpraAllExecute(TObject *Sender);
   void __fastcall pmPrintCurrOperUpraClick(TObject *Sender);
   void __fastcall pmPrintOperatClick(TObject *Sender);
   void __fastcall pmPrintAllOperRolesClick(TObject *Sender);
   void __fastcall pmPrintCurrOperRolesClick(TObject *Sender);
private:	// User declarations
    TDMOperator*          m_operat;
	mng::ControlSetterVec m_controls;
	mng::ControlSetterVec m_buttons;
	mng::ControlSetterVec m_applyupd;
	bool                  m_czyupdate;
	int                   m_idOper;
	Defines::RodzajAct    m_rodzfun;
    bool                  m_czyEdit;
    bool                  m_rightToEdit;

    void __fastcall allocate();

    void __fastcall free();

    void __fastcall initAcces();

    void __fastcall showStatus();

    void __fastcall setEditControl();

    void __fastcall loadControl();

    void __fastcall setZamknijBut();

    void __fastcall setViewControl();

    bool __fastcall validatePassword();

    void __fastcall clearHaslo();

    void __fastcall showPassword();

public:		// User declarations
   __fastcall TRejOperat(TComponent* Owner);

   __fastcall ~TRejOperat();

   void __fastcall Display(bool);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
