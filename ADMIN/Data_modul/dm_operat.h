//---------------------------------------------------------------------------

#ifndef dm_operatH
#define dm_operatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
#include "unit\defines.h"
//---------------------------------------------------------------------------

namespace mng
{
   class StoredProcDB;
}

class ClientTree;

class TDMOperator : public TDataModule
{
__published:	// IDE-managed Components
   TDataSetProvider *dspOperat;
   TClientDataSet *cdsOperat;
   TClientDataSet *cdsUpraw;
   TClientDataSet *cdsGrupy;
   void __fastcall cdsOperatAfterOpen(TDataSet *DataSet);
   void __fastcall dspOperatBeforeUpdateRecord(TObject *Sender,
          TDataSet *SourceDS, TCustomClientDataSet *DeltaDS,
          TUpdateKind UpdateKind, bool &Applied);
   void __fastcall cdsOperatAfterInsert(TDataSet *DataSet);
   void __fastcall dspOperatUpdateError(TObject *Sender,
          TCustomClientDataSet *DataSet, EUpdateError *E,
          TUpdateKind UpdateKind, TResolverResponse &Response);
   void __fastcall dspOperatGetTableName(TObject *Sender,
          TDataSet *DataSet, WideString &TableName);
private:	// User declarations
   mng::StoredProcDB* m_operatorGenID;
   ClientTree*        m_clientTree;
   AnsiString         m_errorStr;

   void __fastcall allocate();

   void __fastcall free();

public:		// User declarations
   __fastcall TDMOperator(TComponent* Owner);

   __fastcall ~TDMOperator();

   void __fastcall OpenOperat();

   char __fastcall GetStatus();

   void __fastcall CloseOperat();

   int __fastcall GetMaxKod();

   void __fastcall AppendOperat();

   void __fastcall Post();

   void __fastcall CancelEdit();

   int __fastcall GetIdOper();

   void __fastcall Locate(int);

   void __fastcall CancelAllUpd();

   void __fastcall UpdateAll();

   void __fastcall EditOperat();

   void __fastcall DeleteOperat();

   void __fastcall AppendUpraw();

   void __fastcall PostUpraw();

   void __fastcall DeleteUpraw();

   void __fastcall AppendGrp();

   void __fastcall PostGrp();

   void __fastcall DeleteGrp();
};
//---------------------------------------------------------------------------
#endif
