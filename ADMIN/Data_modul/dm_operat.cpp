//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dm_operat.h"
#include "unit\defines.h"
#include "unit\utils.h"
#include "unit\client_tree.h"
#include <manager\is_manager.h>
#include <manager\message_dlg.h>
#include <manager\query_db.h>
#include <manager\stored_proc_db.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

const char* const cc_UprawSQL=
"select opf.*, rej.nazwa, fun.opis from OP_OPFUN opf\
 inner join IS_REJESTR rej on (opf.kod_systemu = rej.id_systemu)\
 inner join OP_SLFUN fun on (opf.kod_funsys = fun.kod_funsys)\
 where opf.kod_oper = :KOD_OPER";

const char* const cc_GrupySQL=
"select opf.*, grp.nazwa from OP_OPERGRUP opf\
 inner join OP_GRUPY grp on (grp.kod_grupy = opf.kod_grupy)\
 where opf.kod_oper = :KOD_OPER";


 
__fastcall TDMOperator::TDMOperator(TComponent* Owner)
   : TDataModule(Owner), m_operatorGenID(NULL), m_clientTree(NULL), m_errorStr()
{
   try
   {
      allocate();

      dspOperat->DataSet = m_clientTree->getMainDataSet()->getDataSet();
   }
   catch(...)
   {
      free();

      throw;
   }
}
//---------------------------------------------------------------------------

__fastcall TDMOperator::~TDMOperator()
{
   free();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::allocate()
{
   m_operatorGenID = new mng::StoredProcDB("ADM_PR_KOD_OPER");

   ClientTree::ItemDescp descp(Defines::tidOPR,"select * from OP_OPER","OP_OPER",cdsOperat);

   descp.add(Defines::tidOFN,cc_UprawSQL,"OP_OPFUN",cdsUpraw);
   descp.add(Defines::tidOGR,cc_GrupySQL,"OP_OPERGRUP",cdsGrupy);

   m_clientTree = new ClientTree();

   m_clientTree->buildTree(descp);
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::free()
{
   delete m_operatorGenID;
   delete m_clientTree;
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::dspOperatGetTableName(TObject *Sender,TDataSet *DataSet,WideString &TableName)
{
   TableName = m_clientTree->find(DataSet)->getTable();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::dspOperatBeforeUpdateRecord(TObject *Sender,TDataSet *SourceDS,
   TCustomClientDataSet *DeltaDS,TUpdateKind UpdateKind,bool &Applied)
{
   Defines::TableID table_id=static_cast<Defines::TableID>(m_clientTree->find(SourceDS)->getID());

   switch(table_id)
   {
      case Defines::tidOPR:
         break;

      case Defines::tidOFN:
         Utils::clearFlags(SourceDS,"NAZWA;OPIS");
         Utils::clearFlags(DeltaDS,"NAZWA;OPIS");
         break;

      case Defines::tidOGR:
         Utils::clearFlags(SourceDS,"NAZWA");
         Utils::clearFlags(DeltaDS,"NAZWA");
         break;
   }

   AnsiString key_fields=Defines::primaryKey(table_id);

   Utils::markPrimaryKey(SourceDS,key_fields);
   Utils::markPrimaryKey(DeltaDS,key_fields);
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::dspOperatUpdateError(TObject *Sender,TCustomClientDataSet *DataSet,
   EUpdateError *E,TUpdateKind UpdateKind,TResolverResponse &Response)
{
   m_errorStr = E->Message;

   Response = rrAbort;
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::cdsOperatAfterOpen(TDataSet *DataSet)
{
   m_clientTree->attachClients();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::cdsOperatAfterInsert(TDataSet *DataSet)
{
   cdsOperat->FieldByName("KOD_OPER")->AsInteger = GetMaxKod();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::OpenOperat()
{
   m_errorStr = "";
   
   cdsOperat->Close();

   cdsOperat->Open();
}
//---------------------------------------------------------------------------

char __fastcall TDMOperator::GetStatus()
{
   char znak = ' ';

   if(!cdsOperat->FieldByName("STATUS")->AsString.IsEmpty())
   {
      znak = cdsOperat->FieldByName("STATUS")->AsString[1];
   }

   return znak;
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::CloseOperat()
{
   cdsOperat->Close();
}
//---------------------------------------------------------------------------

int __fastcall TDMOperator::GetMaxKod()
{
   m_operatorGenID->execute();

   int zwr_war(m_operatorGenID->paramByName("ID_OPER")->AsInteger);

   return zwr_war;
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::AppendOperat()
{
   cdsOperat->Edit();

   cdsOperat->Append();
}

//---------------------------------------------------------------------------

void __fastcall TDMOperator::Post()
{
   cdsOperat->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::CancelEdit()
{
   cdsOperat->Cancel();
}
//---------------------------------------------------------------------------

int __fastcall TDMOperator::GetIdOper()
{
   return cdsOperat->FieldByName("KOD_OPER")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::Locate(int p_id)
{
   TLocateOptions opcje;

   opcje.Clear();

   opcje << loPartialKey;

   cdsOperat->Locate("KOD_OPER", p_id, opcje);

}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::CancelAllUpd()
{
   m_errorStr = "";

   cdsOperat->CancelUpdates();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::UpdateAll()
{
   m_errorStr = "";

   if(cdsOperat->ApplyUpdates(-1) > 0)
   {
      throw Exception("B³¹d podczas zapisywania operatorów\n\n" + m_errorStr);
   }

   cdsOperat->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::EditOperat()
{
   cdsOperat->Edit();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::DeleteOperat()
{
   cdsOperat->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::AppendUpraw()
{
   cdsUpraw->Edit();

   cdsUpraw->Append();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::PostUpraw()
{
   cdsUpraw->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::DeleteUpraw()
{
   cdsUpraw->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::AppendGrp()
{
   cdsGrupy->Edit();

   cdsGrupy->Append();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::PostGrp()
{
   cdsGrupy->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMOperator::DeleteGrp()
{
   cdsGrupy->Delete();
}
//---------------------------------------------------------------------------

