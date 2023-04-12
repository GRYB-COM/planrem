//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_uprawnienia.h"
#include "Data_modul\dm_operat.h"
#include "unit\slownikos.h"
#include <manager\stream_db.h>
#include <manager\various_man.h>
#include <manager\message_dlg.h>
#include <manager\is_manager.h>
#include <manager\controls_setter.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fr_rv_navigator_ext"
#pragma link "fr_rv_navigator_smpl"
#pragma link "fr_rv_navigator_full"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TUprawDlg
**********/


__fastcall TUprawDlg::TUprawDlg(TComponent* Owner)
   : TForm(Owner), m_operat(NULL), m_slowUpr(NULL), m_czyupdate(false),
     m_czyEdit(false)
{
   try
   {
      allocate();

      m_slowUpr->setLink(dsSlowUpr);

      m_slowGrp->setLink(dsSlowGrp);



      linkDataSource();

      mng::ControlSetterVec controls;

      controls.push_back(mng::ControlSetterBase::createRO3D(dbeID));
      controls.push_back(mng::ControlSetterBase::createRO3D(dbeNazwa));
      controls.push_back(mng::ControlSetterBase::createRO3D(dbeOpis));

      controls.prepareTo(mng::ControlSetterVec::otsView);
   }
   catch(...)
   {
      free();
   }
}
//---------------------------------------------------------------------------

__fastcall TUprawDlg::~TUprawDlg()
{
   free();
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::allocate()
{
   m_slowUpr = new mng::StreamDB();

   AnsiString moje_query;

   moje_query = "select a.*, cast('N' as CHAR(1)) as UZYTE, b.NAZWA from OP_SLFUN a inner join IS_REJESTR b on (a.kod_systemu = b.id_systemu) order by a.kod_systemu, a.kod_funsys";

   m_slowUpr->open(moje_query);


   m_slowGrp = new mng::StreamDB();

   moje_query = "select nazwa, kod_grupy, cast('N' as CHAR(1)) as UZYTE from OP_GRUPY order by nazwa";

   m_slowGrp->open(moje_query);
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::free()
{
   delete m_slowUpr;
   delete m_slowGrp;
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::setFilterForDict(const mng::SysID& selected_sys)
{
   AnsiString filtr_sys("UZYTE='N'");

   if(selected_sys.isDefined())
   {
      filtr_sys += " AND KOD_SYSTEMU = "+IntToStr(selected_sys.getID());
   }

   m_slowUpr->setFilter(filtr_sys);

   m_slowUpr->first();

 }
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actZamknijExecute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::setFilterForUpra()
{
   mng::SysID selected_sys;

   AnsiString filtr_sys;

   if(selected_sys.isDefined())
   {
      filtr_sys = "KOD_SYSTEMU = "+IntToStr(selected_sys.getID());
   }

   m_operat->cdsUpraw->Filter = filtr_sys;

   m_operat->cdsUpraw->Filtered = selected_sys.isDefined();

   m_operat->cdsUpraw->First();
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actWczytajExecute(TObject *Sender)
{
   mng::SysID selected_sys;

   setFilterForUpra();

   setFilterForDict(selected_sys.getID());
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::SetDataSource(TDMOperator* p_source)
{
   m_operat = p_source;

   dsUpra->DataSet = m_operat->cdsUpraw;

   dsOperat->DataSet = m_operat->cdsOperat;

   dsGrupy->DataSet = m_operat->cdsGrupy;

}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   CanClose = true;

   m_operat->cdsUpraw->Filtered = false;
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::FormShow(TObject *Sender)
{
   checkBusUpra();

   checkBussyGrp();

   setButtonsMode();

   dbgSlowUpra->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::checkBusUpra()
{
    mng::ControlsMan cm(m_slowUpr->getClient());

   m_operat->cdsUpraw->Filtered = false;

   m_slowUpr->setFiltered(false);

   m_slowUpr->first();

   while(!m_slowUpr->isEof())
   {
      m_slowUpr->edit();
      m_slowUpr->fieldByName("UZYTE")->AsString = "N";
      m_slowUpr->post();

      m_slowUpr->next();
   }

   m_operat->cdsUpraw->First();

   while(!m_operat->cdsUpraw->Eof)
   {
      Variant values[2];
      values[0] = m_operat->cdsUpraw->FieldByName("KOD_SYSTEMU")->AsInteger;
      values[1] = m_operat->cdsUpraw->FieldByName("KOD_FUNSYS")->AsString;

      if(m_slowUpr->locate("KOD_SYSTEMU;KOD_FUNSYS",VarArrayOf(values, 1)))
      {
         m_slowUpr->edit();
         m_slowUpr->fieldByName("UZYTE")->AsString = "T";
         m_slowUpr->post();
      }

      m_operat->cdsUpraw->Next();
   }

   m_slowUpr->setFiltered(true);

   m_slowUpr->first();

   setFilterForUpra();

   mng::SysID selected_sys;

   setFilterForDict(selected_sys.getID());
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::linkDataSource()
{
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actDodajExecute(TObject *Sender)
{
   m_operat->AppendUpraw();

   m_operat->cdsUpraw->FieldByName("KOD_OPER")->AsInteger =
      m_operat->cdsOperat->FieldByName("KOD_OPER")->AsInteger;

   m_operat->cdsUpraw->FieldByName("KOD_FUNSYS")->AsString =
      m_slowUpr->fieldByName("KOD_FUNSYS")->AsString;

   m_operat->cdsUpraw->FieldByName("KOD_SYSTEMU")->AsInteger =
      m_slowUpr->fieldByName("KOD_SYSTEMU")->AsInteger;

   m_operat->cdsUpraw->FieldByName("NAZWA")->AsString =
      m_slowUpr->fieldByName("NAZWA")->AsString;

   m_operat->cdsUpraw->FieldByName("OPIS")->AsString =
      m_slowUpr->fieldByName("OPIS")->AsString;

   m_operat->PostUpraw();

   m_slowUpr->edit();
   m_slowUpr->fieldByName("UZYTE")->AsString = "T";
   m_slowUpr->post();

   m_czyupdate = true;

}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actUsunExecute(TObject *Sender)
{
   Variant values[2];
   values[0] = m_operat->cdsUpraw->FieldByName("KOD_SYSTEMU")->AsInteger;
   values[1] = m_operat->cdsUpraw->FieldByName("KOD_FUNSYS")->AsString;

   m_slowUpr->setFiltered(false);

   if(m_slowUpr->locate("KOD_SYSTEMU;KOD_FUNSYS",VarArrayOf(values, 1)))
   {
      m_slowUpr->edit();
      m_slowUpr->fieldByName("UZYTE")->AsString = "N";
      m_slowUpr->post();
   }

   m_operat->DeleteUpraw();

   m_slowUpr->setFiltered(true);

   m_czyupdate = true;

}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::dsSlowUprDataChange(TObject *Sender,
      TField *Field)
{
   sbAppendUpra->Enabled = m_czyEdit && !dsSlowUpr->DataSet->IsEmpty();
}
//---------------------------------------------------------------------------

bool __fastcall TUprawDlg::GetStateUpdate()
{
   return m_czyupdate;
}
//---------------------------------------------------------------------------
void __fastcall TUprawDlg::checkBussyGrp()
{
   mng::ControlsMan cm(m_slowGrp->getClient());

   m_slowGrp->setFiltered(false);

   m_slowGrp->first();

   while(!m_slowGrp->isEof())
   {
      m_slowGrp->edit();
      m_slowGrp->fieldByName("UZYTE")->AsString = "N";
      m_slowGrp->post();

      m_slowGrp->next();
   }

   m_operat->cdsGrupy->First();

   while(!m_operat->cdsGrupy->Eof)
   {
      Variant values[1];
      values[0] = m_operat->cdsGrupy->FieldByName("KOD_GRUPY")->AsInteger;

      if(m_slowGrp->locate("KOD_GRUPY",VarArrayOf(values, 0)))
      {
         m_slowGrp->edit();
         m_slowGrp->fieldByName("UZYTE")->AsString = "T";
         m_slowGrp->post();
      }

      m_operat->cdsGrupy->Next();
   }

   m_slowGrp->setFiltered(true);

   m_slowGrp->first();

   setFilterForGrp();

   m_operat->cdsGrupy->First();

}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::setFilterForGrp()
{
   m_slowGrp->setFilter("UZYTE = 'N'");
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::dsSlowGrpDataChange(TObject *Sender,
      TField *Field)
{
   sbAppendGrp->Enabled = m_czyEdit && !dsSlowGrp->DataSet->IsEmpty();
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actDodajGrpExecute(TObject *Sender)
{
   m_operat->AppendGrp();

   m_operat->cdsGrupy->FieldByName("KOD_OPER")->AsInteger =
      m_operat->cdsOperat->FieldByName("KOD_OPER")->AsInteger;

   m_operat->cdsGrupy->FieldByName("KOD_GRUPY")->AsInteger =
      m_slowGrp->fieldByName("KOD_GRUPY")->AsInteger;

   m_operat->cdsGrupy->FieldByName("NAZWA")->AsString =
      m_slowGrp->fieldByName("NAZWA")->AsString;

   m_operat->PostGrp();

   m_slowGrp->edit();

   m_slowGrp->fieldByName("UZYTE")->AsString = "T";

   m_slowGrp->post();

   m_czyupdate = true;
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::actUsunGrpExecute(TObject *Sender)
{
   try
   {
     m_slowGrp->setFiltered(false);

     Variant values[1];
     int kod_grupy = m_operat->cdsGrupy->FieldByName("KOD_GRUPY")->AsInteger;

     values[0] =kod_grupy;


    if(m_slowGrp->locate("KOD_GRUPY",VarArrayOf(values, 0)))
    {
        m_slowGrp->edit();

        m_slowGrp->fieldByName("UZYTE")->AsString = "N";

        m_slowGrp->post();
    }

     m_slowGrp->setFiltered(true);

     AnsiString naz_grp = dsGrupy->DataSet->FieldByName("NAZWA")->AsString.Trim();

     m_operat->DeleteGrp();

     m_czyupdate = true;
   }
   catch(...)
   {
      mng::Manager::instance().showException("B³¹d podczas usuwania grupy uprawnieñ");
   }
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::SetEditMode(bool p_mode)
{
   m_czyEdit = p_mode;
}
//---------------------------------------------------------------------------

void __fastcall TUprawDlg::setButtonsMode()
{
   sbAppendUpra->Enabled = m_czyEdit && !dsSlowUpr->DataSet->IsEmpty();

   sbRemoveUpra->Enabled = m_czyEdit && !dsUpra->DataSet->IsEmpty();

   sbAppendGrp->Enabled = m_czyEdit && !dsSlowGrp->DataSet->IsEmpty();

   sbRemoveGrp->Enabled = m_czyEdit && !dsGrupy->DataSet->IsEmpty();
}
//---------------------------------------------------------------------------


void __fastcall TUprawDlg::dsUpraDataChange(TObject *Sender, TField *Field)
{
   sbRemoveUpra->Enabled = m_czyEdit && !dsUpra->DataSet->IsEmpty();
}
//---------------------------------------------------------------------------


void __fastcall TUprawDlg::dsGrupyDataChange(TObject *Sender,
      TField *Field)
{
   sbRemoveGrp->Enabled = m_czyEdit && !dsGrupy->DataSet->IsEmpty();
}
//---------------------------------------------------------------------------



