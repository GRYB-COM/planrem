//---------------------------------------------------------------------------

#ifndef fm_uprawnieniaH
#define fm_uprawnieniaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "unit\slownikos.h"
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "fr_rv_navigator_ext.h"
#include "fr_rv_navigator_smpl.h"
#include "fr_rv_navigator_full.h"
//---------------------------------------------------------------------------

namespace mng
{
   class StreamDB;
}

class TDMOperator;


class TUprawDlg : public TForm
{
__published:	// IDE-managed Components
   TPanel *paDown;
   TImageList *imgLista;
   TActionList *akcje;
   TAction *actZamknij;
   TBitBtn *bbZamknij;
   TPanel *paShowOper;
   TDataSource *dsOperat;
   TPanel *paCentral;
   TPageControl *pgUpra;
   TTabSheet *tsUpra;
   TTabSheet *tsGrpUpra;
   TDataSource *dsUpra;
   TAction *actWczytaj;
   TDataSource *dsSlowUpr;
   TAction *actDodaj;
   TGroupBox *grpWybOper;
   TDBEdit *dbeID;
   TLabel *Label1;
   TDBEdit *dbeNazwa;
   TLabel *Label2;
   TDBEdit *dbeOpis;
   TLabel *Label3;
   TAction *actUsun;
   TDataSource *dsGrupy;
   TDataSource *dsSlowGrp;
   TAction *actDodajGrp;
   TAction *actUsunGrp;
   TPanel *paUpraLeft;
   TPanel *paInnerUpra;
   TPanel *paManageUpra;
   TPanel *paRightUpra;
   TPanel *paTitleLeftUpra;
   TPanel *paTitleRightUpra;
   TSpeedButton *sbAppendUpra;
   TSpeedButton *sbRemoveUpra;
   TPanel *paLeftGrp;
   TPanel *paInnerGrp;
   TPanel *paManagGrp;
   TPanel *paRightGrp;
   TPanel *paTitleLeftGrp;
   TPanel *paTitleRightGrp;
   TDBGrid *dbgLeftGrp;
   TDBGrid *dbgRightGrp;
   TSpeedButton *sbAppendGrp;
   TSpeedButton *sbRemoveGrp;
   TPanel *paSlwUprawGrid;
   TDBGrid *dbgSlowUpra;
   TPanel *paUprawGrid;
   TDBGrid *dbgUpra;
   void __fastcall actZamknijExecute(TObject *Sender);
   void __fastcall actWczytajExecute(TObject *Sender);
   void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall actDodajExecute(TObject *Sender);
   void __fastcall actUsunExecute(TObject *Sender);
   void __fastcall dsSlowUprDataChange(TObject *Sender, TField *Field);
   void __fastcall dsSlowGrpDataChange(TObject *Sender, TField *Field);
   void __fastcall actDodajGrpExecute(TObject *Sender);
   void __fastcall actUsunGrpExecute(TObject *Sender);
   void __fastcall dsUpraDataChange(TObject *Sender, TField *Field);
   void __fastcall dsGrupyDataChange(TObject *Sender, TField *Field);
private:	// User declarations

   mng::StreamDB*      m_slowUpr;  //!< S³ownik uprawnieñ
   TDMOperator*        m_operat;
   bool                m_czyupdate;
   mng::StreamDB*      m_slowGrp;
   bool                m_czyEdit;

   void __fastcall allocate();

   void __fastcall free();

   void __fastcall setFilterForDict(const mng::SysID& selected_sys);

   void __fastcall setFilterForUpra();

   void __fastcall checkBusUpra();

   void __fastcall linkDataSource();

   void __fastcall checkBussyGrp();

   void __fastcall setFilterForGrp();

   void __fastcall setButtonsMode();

public:		// User declarations
   __fastcall TUprawDlg(TComponent* Owner);

   __fastcall ~TUprawDlg();

   void __fastcall SetDataSource(TDMOperator*);

   void __fastcall SetEditMode(bool);

   bool __fastcall GetStateUpdate();
   
};
//---------------------------------------------------------------------------
#endif
