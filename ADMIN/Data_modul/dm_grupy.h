//---------------------------------------------------------------------------

#ifndef dm_grupyH
#define dm_grupyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
#include <manager\stored_proc_db.h>

//---------------------------------------------------------------------------

class ClientTree;

class TDMGrupyUpr : public TDataModule
{
__published:	// IDE-managed Components
   TDataSetProvider *dspGrupyUpr;
   TClientDataSet *cdsGrupy;
   TClientDataSet *cdsGrupyFun;
   void __fastcall dspGrupyUprGetTableName(TObject *Sender,
          TDataSet *DataSet, AnsiString &TableName);
   void __fastcall dspGrupyUprBeforeUpdateRecord(TObject *Sender,
          TDataSet *SourceDS, TCustomClientDataSet *DeltaDS,
          TUpdateKind UpdateKind, bool &Applied);
   void __fastcall dspGrupyUprUpdateError(TObject *Sender,
          TCustomClientDataSet *DataSet, EUpdateError *E,
          TUpdateKind UpdateKind, TResolverResponse &Response);
   void __fastcall cdsGrupyAfterOpen(TDataSet *DataSet);
private:	// User declarations

   ClientTree*        m_clientTree;
   AnsiString         m_errorStr;
   mng::StoredProcDB* m_grupaGenId;

   void __fastcall allocate();

   void __fastcall free();
   
public:		// User declarations
   __fastcall TDMGrupyUpr(TComponent* Owner);

   __fastcall ~TDMGrupyUpr();

   void __fastcall OpenGrupa();

   void __fastcall CloseGrupa();

   int __fastcall GetMaxId();

   void __fastcall AppendGrupa();

   void __fastcall CancelGrupa();

   int __fastcall GetCurrId();

   void __fastcall Locate(int);

   void __fastcall PostGrupa();

   void __fastcall EditGrupa();

   void __fastcall DeleteGrupa();

   void __fastcall CancelAll();

   void __fastcall UpdateAll();

   void __fastcall SetFilteredFun(bool);

   bool __fastcall LocateFun(const AnsiString&, Variant*, int);

   void __fastcall SetFilterFun(const AnsiString&);

   void __fastcall AppendUpra();

   void __fastcall PostUpra();

   void __fastcall DeleteUpra();
   
};
//---------------------------------------------------------------------------
//extern PACKAGE TDMGrupyUpr *DMGrupyUpr;
//---------------------------------------------------------------------------
#endif
