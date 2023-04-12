//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_rej_operat.h"
#include "Data_modul\dm_operat.h"
#include "unit\defines.h"
#include "fm_uprawnienia.h"
//#include "rv_lines.h"
//#include "report\fm_admin_uprawnienia.h"
//#include "report\fm_grupy_rap.h"
//#include "report\fm_operator_rap.h"
//#include "unit\right_checker.h"
#include <manager\sys_rights.h>
#include <manager\user.h>
#include <manager\is_manager.h>
#include <manager\message_dlg.h>
#include <manager\is_utilities.h>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "fr_rv_navigator_ext"
#pragma link "fr_rv_navigator_full"
#pragma link "fr_rv_navigator_smpl"
#pragma link "fr_rv_navigator_ext"
#pragma link "fr_rv_navigator_full"
#pragma link "fr_rv_navigator_smpl"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: TRejOperat
**********/


__fastcall TRejOperat::TRejOperat(TComponent* Owner)
   : TForm(Owner), m_operat(NULL), m_czyupdate(false), m_idOper(0),
      m_rodzfun(Defines::actUnknown), m_czyEdit(false)
{
   try
   {
      allocate();

      dsOperat->DataSet = m_operat->cdsOperat;

      m_operat->OpenOperat();

      frmNavig->SetSource(dsOperat);


      mng::ControlSetterVec controls;

      controls.push_back(mng::ControlSetterBase::createRO3D(dbeKodOper));
      controls.push_back(mng::ControlSetterBase::createRO3D(dbeDateZmH));

      controls.prepareTo(mng::ControlSetterVec::otsView);
   }
   catch(...)
   {
      free();

      throw;
   }
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::Display(bool p_rightToEdit)
{
   m_rightToEdit = p_rightToEdit;

   loadControl();

   initAcces();

   setZamknijBut();

   setViewControl();
}
//---------------------------------------------------------------------------

__fastcall TRejOperat::~TRejOperat()
{
   free();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::allocate()
{
   m_operat = new TDMOperator(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::free()
{
    delete m_operat;
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actZamknijExecute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actDodajExecute(TObject *Sender)
{
   rgStatus->ItemIndex =0;

   m_idOper = m_operat->GetIdOper();

   setEditControl();

   m_operat->AppendOperat();

   m_rodzfun = Defines::actDodaj;

   dbeNazwaOp->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actAnulujExecute(TObject *Sender)
{

   m_operat->CancelEdit();

   setViewControl();

   m_operat->Locate(m_idOper);

   setZamknijBut();

   clearHaslo();

   showPassword();

   dbgOperat->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actDrukujExecute(TObject *Sender)
{
   int x = Left + bbDrukuj->Width + 20;

   int y = Top + Height - 130;

   pmWydruki->Popup(x,y);
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actUpraExecute(TObject *Sender)
{
   if(m_operat->cdsOperat->FieldByName("NAZWA")->AsString.IsEmpty())
   {
      mng::MessageDialog::warning("Wype³nij pole (Nazwa operatora)",Caption,MB_OK);

      return;
   }

   std::auto_ptr<TUprawDlg> ekr (new TUprawDlg(NULL));

   ekr->SetDataSource(m_operat);

   ekr->SetEditMode(m_czyEdit);

   ekr->ShowModal();

   if(ekr->GetStateUpdate())
   {
      m_czyupdate = true;
   }

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actZapiszExecute(TObject *Sender)
{
   if(rgStatus->ItemIndex == -1)
   {
      mng::MessageDialog::warning("Nie zosta³ okreœlony status operatora",Caption,MB_OK);

      rgStatus->SetFocus();

      return;
   }

   if(!validatePassword())
   {
      edHaslo->SetFocus();

      return;
   }
   String _Stat;
   switch(rgStatus->ItemIndex)
   {

	case 0: _Stat ="A"; break;
	case 1: _Stat ="B"; break;
	case 2: _Stat ="T"; break;
   }

   m_operat->cdsOperat->FieldByName("STATUS")->AsString = _Stat;

   if(!edHaslo->Text.IsEmpty())
   {
      m_operat->cdsOperat->FieldByName("HASLO")->AsString = mng::Utilities::calculatePasswordDigest(edHaslo->Text);
      m_operat->cdsOperat->FieldByName("DATA_ZMH")->AsDateTime = Date();
   }


   try
   {
      m_operat->Post();

      m_czyupdate = true;
   }
   catch(...)
   {
      m_operat->CancelEdit();

      m_operat->Locate(m_idOper);

      mng::Manager::instance().showException("B³¹d podczas zapisywania do bazy");
   }

      setZamknijBut();

      setViewControl();

      clearHaslo();

      showPassword();

      dbgOperat->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actZmienExecute(TObject *Sender)
{
   if(!m_rightToEdit)
   {
      return;
   }

   m_rodzfun = Defines::actZmien;

   m_idOper = m_operat->GetIdOper();

   m_operat->EditOperat();

   setEditControl();

   clearHaslo();

   dbeNazwaOp->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::showStatus()
{

   switch(m_operat->GetStatus())
   {
	case 'A': rgStatus->ItemIndex =0; break;
	case 'B': rgStatus->ItemIndex =1; break;
	case 'T': rgStatus->ItemIndex =2; break;
   }
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::dbgOperatCellClick(TColumn *Column)
{
   showStatus();
}
//---------------------------------------------------------------------------


void __fastcall TRejOperat::FormCloseQuery(TObject *Sender, bool &CanClose)
{
   CanClose = true;

   m_operat->CloseOperat();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::FormShow(TObject *Sender)
{
   showStatus();

   dbgOperat->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actFirstExecute(TObject *Sender)
{
   frmNavig->First();

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actPreviousExecute(TObject *Sender)
{
   frmNavig->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actNextExecute(TObject *Sender)
{
   frmNavig->Next();

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actLastExecute(TObject *Sender)
{
   frmNavig->Last();

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::initAcces()
{
//   frmNavig->sbFirst->Enabled = true;

   frmNavig->sbNext->Enabled = true;

//   frmNavig->sbPrior->Enabled = true;

   frmNavig->sbLast->Enabled = true;

   frmNavig->sbInfo->Visible = false;

   frmNavig->sbAppend->Enabled = true;

   frmNavig->sbEdit->Enabled = true;

   frmNavig->sbRemove->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::dsOperatDataChange(TObject *Sender,TField *Field)
{
   if(Field == NULL)
   {
      showStatus();

      showPassword();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::showPassword()
{
   edHaslo->Text = dsOperat->DataSet->FieldByName("HASLO")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::setEditControl()
{
   frmNavig->EnableEditing();
   frmNavig->sbInfo->Visible = false;
   frmNavig->sbAppend->Visible = false;
   frmNavig->sbEdit->Visible = false;
   frmNavig->sbRemove->Visible = false;

   m_controls.prepareTo(mng::ControlSetterVec::otsEdit);
   m_buttons.prepareTo(mng::ControlSetterVec::otsView);
   bbUpraw->Caption = "Edycja uprawnieñ";
   m_applyupd.prepareTo(mng::ControlSetterVec::otsView);


   dbgOperat->Enabled = false;

//   bbUpraw->Enabled = true;

   dbeNazwaOp->SetFocus();

   m_czyEdit = true;

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::loadControl()
{
   m_controls.push_back(mng::ControlSetterBase::createRO3D(dbeNazwaOp));
   m_controls.push_back(mng::ControlSetterBase::createBTN(rgStatus));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(dbeNazwaZewn));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(dbeOpis));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(dbeKodWydz));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(dbeKodSkrocony));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(edHaslo));
   m_controls.push_back(mng::ControlSetterBase::createRO3D(edConfHaslo));

//   m_buttons.push_back(mng::ControlSetterBase::createBTN(bbUpraw));
   m_buttons.push_back(mng::ControlSetterBase::createBTN(bbDrukuj));
   m_applyupd.push_back(mng::ControlSetterBase::createBTN(bbAnulujAll));
   m_applyupd.push_back(mng::ControlSetterBase::createBTN(bbZamknij));


}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actGrupyExecute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::FormKeyPress(TObject *Sender, char &Key)
{
   if(Key == '\r')
   {
      Perform(WM_NEXTDLGCTL,0,0);

      Key = 0;
   }

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actAnulujAllExecute(TObject *Sender)
{
   m_operat->CancelAllUpd();

   m_czyupdate = false;

   setZamknijBut();

   dbgOperat->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::setZamknijBut()
{
   bbZamknij->Action = NULL;

   bbZamknij->Glyph->Assign(NULL);

   bbZamknij->Action = m_czyupdate ?  actZapiszDB : actZamknij;

//   bbZamknij->Hint = m_czyupdate ? "Zapisanie danych do bazy" : "Zamknij okno" ;

   bbAnulujAll->Visible = m_czyupdate;

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actZapiszDBExecute(TObject *Sender)
{
   try
   {
      m_operat->UpdateAll();
   }
   catch(const Exception& exc)
   {
      mng::Manager::instance().showException(exc.Message);
   }

   m_czyupdate = false;

   setZamknijBut();

   dbgOperat->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::setViewControl()
{

   frmNavig->DisableEditing();
   frmNavig->sbInfo->Visible = false;
   frmNavig->sbAppend->Visible = m_rightToEdit;
   frmNavig->sbEdit->Visible =  m_rightToEdit;
   frmNavig->sbRemove->Visible = m_rightToEdit;

   m_controls.prepareTo(mng::ControlSetterVec::otsView);

   m_buttons.prepareTo(mng::ControlSetterVec::otsEdit);
   bbUpraw->Caption = "Podgl¹d uprawnieñ";

   m_applyupd.prepareTo(mng::ControlSetterVec::otsEdit);

//   bbUpraw->Enabled = false;

   dbgOperat->Enabled = true;

   showStatus();

   m_czyEdit = false;

}
//---------------------------------------------------------------------------
bool __fastcall TRejOperat::validatePassword()
{
   bool zwr_war(true);

   if(m_rodzfun == Defines::actDodaj)
   {
      if(edHaslo->Text.IsEmpty())
      {
         mng::MessageDialog::warning("Brak wprowadzonego has³a","ADMIN",MB_OK);

         zwr_war = false;

         return zwr_war;
      }

      if(edHaslo->Text.Trim() != edConfHaslo->Text.Trim())
      {
         mng::MessageDialog::warning("Has³o i has³o powtórzone nie s¹ jednakowe","ADMIN",MB_OK);

         zwr_war = false;
      }
      return zwr_war;
   }

   if(m_rodzfun == Defines::actZmien)
   {
      if(!edHaslo->Text.IsEmpty())
      {
         if(edHaslo->Text.Trim() != edConfHaslo->Text.Trim())
         {
            mng::MessageDialog::warning("Has³o i has³o powtórzone nie s¹ jednakowe",Caption,MB_OK);

            zwr_war = false;
         }

      }
   }

   return zwr_war;
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::clearHaslo()
{
   edHaslo->Text = "";
   edConfHaslo->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actDeleteExecute(TObject *Sender)
{
   int czy_del(mng::MessageDialog::question("Czy usun¹æ wybranego operatora z bazy ?",Caption,MB_YESNO));

   if(czy_del == IDYES)
   {
      try
      {
         AnsiString  ev = "Operator: " + dsOperat->DataSet->FieldByName("NAZWA")->AsString.Trim();

         m_operat->DeleteOperat();

         m_czyupdate = true;

         frmNavig->First();
      }
      catch(...)
      {
         mng::Manager::instance().showException("B³¹d podczas usuwania");
      }

      setZamknijBut();

      dbgOperat->SetFocus();

   }
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::actPrintUpraAllExecute(TObject *Sender)
{
 /*  std::auto_ptr<TQRUprawnienia> rep( new TQRUprawnienia(NULL));

   if(rep->IsEmptyDataSource())
   {
	  mng::MessageDialog::warning("Brak danych",Caption,MB_OK);

	  return;
   }

   rep->Preview(); */
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::pmPrintCurrOperUpraClick(TObject *Sender)
{
 /*  std::auto_ptr<TQRUprawnienia> rep( new TQRUprawnienia(NULL));

   rep->SetFilterDataSource(m_operat->cdsOperat->FieldByName("KOD_OPER")->AsInteger);

   if(rep->IsEmptyDataSource())
   {
	  mng::MessageDialog::warning("Brak danych","ADMIN",MB_OK);

	  return;
   }

   rep->Preview();*/
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::pmPrintOperatClick(TObject *Sender)
{
 /*  std::auto_ptr<TQROperator> rep( new TQROperator(NULL));

   rep->Preview();*/
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::pmPrintAllOperRolesClick(TObject *Sender)
{

 /*  std::auto_ptr<TQROperGrup> rep( new TQROperGrup(NULL));

   if(rep->IsEmptyDataSource())
   {
	  mng::MessageDialog::warning("Brak danych","ADMIN",MB_OK);

	  return;
   }

   rep->Preview();*/
}
//---------------------------------------------------------------------------

void __fastcall TRejOperat::pmPrintCurrOperRolesClick(TObject *Sender)
{
 /*  std::auto_ptr<TQROperGrup> rep( new TQROperGrup(NULL));

   rep->SetFilter(m_operat->cdsOperat->FieldByName("KOD_OPER")->AsInteger);

   if(rep->IsEmptyDataSource())
   {
	  mng::MessageDialog::warning("Brak danych","ADMIN",MB_OK);

	  return;
   }

   rep->Preview();*/

}
//---------------------------------------------------------------------------

