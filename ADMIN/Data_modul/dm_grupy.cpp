//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dm_grupy.h"
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
//TDMGrupyUpr *DMGrupyUpr;

const char* const cc_GrupFunSQL =
"select grf.*, slf.opis, rej.nazwa\
 from OP_GRFUN grf inner join OP_SLFUN slf\
 on (grf.kod_funsys = slf.kod_funsys and grf.kod_systemu = slf.kod_systemu)\
 inner join IS_REJESTR rej on (slf.kod_systemu = rej.id_systemu)\
 where grf.kod_grupy = :KOD_GRUPY";

//---------------------------------------------------------------------------
__fastcall TDMGrupyUpr::TDMGrupyUpr(TComponent* Owner)
   : TDataModule(Owner), m_clientTree(NULL), m_errorStr(), m_grupaGenId(NULL)
{
   try
   {
      allocate();

      dspGrupyUpr->DataSet = m_clientTree->getMainDataSet()->getDataSet();
   }
   catch(...)
   {
      free();

      throw;
   }
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::allocate()
{
   m_grupaGenId = new mng::StoredProcDB("ADM_PR_KOD_GRUPY");

   ClientTree::ItemDescp dscp(Defines::tidGRP,"select * from OP_GRUPY order by kod_grupy","OP_GRUPY",cdsGrupy);

   dscp.add(Defines::tidGRF,cc_GrupFunSQL,"OP_GRFUN",cdsGrupyFun);

   m_clientTree = new ClientTree();

   m_clientTree->buildTree(dscp);
}
//---------------------------------------------------------------------------

__fastcall TDMGrupyUpr::~TDMGrupyUpr()
{
   free();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::free()
{
   delete m_clientTree;
   delete m_grupaGenId;
}
//---------------------------------------------------------------------------
void __fastcall TDMGrupyUpr::dspGrupyUprGetTableName(TObject *Sender,
      TDataSet *DataSet, AnsiString &TableName)
{
   TableName = m_clientTree->find(DataSet)->getTable();
}
//---------------------------------------------------------------------------
void __fastcall TDMGrupyUpr::dspGrupyUprBeforeUpdateRecord(TObject *Sender,
      TDataSet *SourceDS, TCustomClientDataSet *DeltaDS,
      TUpdateKind UpdateKind, bool &Applied)
{
   Defines::TableID table_id=static_cast<Defines::TableID>(m_clientTree->find(SourceDS)->getID());

   switch(table_id)
   {
      case Defines::tidGRP:
         break;

      case Defines::tidGRF:
         Utils::clearFlags(SourceDS,"NAZWA;OPIS");
         Utils::clearFlags(DeltaDS,"NAZWA;OPIS");
         break;

   }

   AnsiString key_fields=Defines::primaryKey(table_id);

   Utils::markPrimaryKey(SourceDS,key_fields);
   Utils::markPrimaryKey(DeltaDS,key_fields);

}
//---------------------------------------------------------------------------
void __fastcall TDMGrupyUpr::dspGrupyUprUpdateError(TObject *Sender,
      TCustomClientDataSet *DataSet, EUpdateError *E,
      TUpdateKind UpdateKind, TResolverResponse &Response)
{
   m_errorStr = E->Message;

   Response = rrAbort;
}
//---------------------------------------------------------------------------
void __fastcall TDMGrupyUpr::cdsGrupyAfterOpen(TDataSet *DataSet)
{
   m_clientTree->attachClients();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::OpenGrupa()
{
   m_errorStr = "";

   cdsGrupy->Close();

   cdsGrupy->Open();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::CloseGrupa()
{
   cdsGrupy->Close();
}
//---------------------------------------------------------------------------

int __fastcall TDMGrupyUpr::GetMaxId()
{
   m_grupaGenId->execute();

   int zwr_war(m_grupaGenId->paramByName("ID_GRUPY")->AsInteger);

   return zwr_war;
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::AppendGrupa()
{
   cdsGrupy->Edit();

   cdsGrupy->Append();

   cdsGrupy->FieldByName("KOD_GRUPY")->AsInteger = GetMaxId();

}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::CancelGrupa()
{
   cdsGrupy->Cancel();
}
//---------------------------------------------------------------------------

int __fastcall TDMGrupyUpr::GetCurrId()
{
   return cdsGrupy->FieldByName("KOD_GRUPY")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::Locate(int p_kodGrupy)
{
   TLocateOptions opcje;

   opcje.Clear();

   opcje << loPartialKey;

   cdsGrupy->Locate("KOD_GRUPY", p_kodGrupy, opcje);

}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::PostGrupa()
{
   cdsGrupy->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::EditGrupa()
{
   cdsGrupy->Edit();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::DeleteGrupa()
{
   cdsGrupy->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::CancelAll()
{
   cdsGrupy->CancelUpdates();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::UpdateAll()
{
   m_errorStr = "";

   if(cdsGrupy->ApplyUpdates(-1) > 0)
   {
      throw Exception("B³¹d podczas zapisyawania grup \n\n "+m_errorStr);
   }

   cdsGrupy->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::SetFilteredFun(bool p_isFiltr)
{
   cdsGrupyFun->Filtered = p_isFiltr;
}
//---------------------------------------------------------------------------

bool __fastcall TDMGrupyUpr::LocateFun(const AnsiString& p_fields, Variant* p_values, int p_ilf)
{
   TLocateOptions opt;

   opt.Clear();

   opt << loCaseInsensitive;

   bool zwr_war = cdsGrupyFun->Locate(p_fields, VarArrayOf(p_values, p_ilf), opt);

   return zwr_war;
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::SetFilterFun(const AnsiString& p_filtr)
{
   cdsGrupyFun->Filter = p_filtr;
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::AppendUpra()
{
   cdsGrupyFun->Edit();

   cdsGrupyFun->Append();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::PostUpra()
{
   cdsGrupyFun->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDMGrupyUpr::DeleteUpra()
{
   cdsGrupyFun->Delete();
}
//---------------------------------------------------------------------------

