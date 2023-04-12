// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MagFRM.h"
#include "SzukajFRA.h"
#include "NaglMagFRA.h"
#include "NowyMagFRM.h"
#include <memory>
#include "NowyKosztFRM.h"
#include "NowePowiadFRM.h"
#include "MagID.h"
#include "ZlecID.h"
#include "MANAGER\message_dlg.h"
#include "MANAGER\query_db.h"
#include "right_checker.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothMegaMenu"
#pragma link "NaglMagFRA"
#pragma link "SzukajFRA"
#pragma link "KosztyFRA"
#pragma link "PowiadomFRA"
#pragma link "AdvSmoothButton"
#pragma link "KutyFRA"
#pragma link "ListaMAGFRA"
#pragma link "AdvSmoothTabPager"
#pragma link "DokFRA"
#pragma link "KUTkosztySumFRA"
#pragma link "KUTkosztyFRA"
#pragma resource "*.dfm"
// ---------------------------------------------------------------------------
__fastcall T_MagFRM::T_MagFRM(TComponent* Owner) : TForm(Owner)
{
 m_MagID = new msg::MagID();
 m_SzukajFRA->setOnFindSprzet(runOnFindSprzet);
}
// ---------------------------------------------------------------------------
__fastcall T_MagFRM::~T_MagFRM()
{
 delete m_MagID;
}
// ---------------------------------------------------------------------------
void __fastcall T_MagFRM::show(const msg::MagID& _MagID=msg::MagID())
{
 if(_MagID.IsDefined)
 {
  *m_MagID = _MagID;
  m_SzukajFRA->open(_MagID);
 }
 else
 {
  m_SzukajFRA->prepare();
  m_MainP->Visible = false;
  m_DelSprzBB->Visible = false;
 }
 if(!Active) ShowModal();
}
// ---------------------------------------------------------------------------


// ------------------------s---------------------------------------------------

void __fastcall T_MagFRM::_KosztyFRA1AdvSmoothButton1Click(TObject* Sender)
{
  std::auto_ptr<T_NowyKosztFRM>_F(new T_NowyKosztFRM(NULL));
  _F->Caption = "Nowy koszt";
  _F->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall T_MagFRM::_PowiadomFRA1AdvSmoothButton1Click(TObject* Sender)
{
  std::auto_ptr<T_NowePowiadFRM>_F(new T_NowePowiadFRM(NULL));
  _F->Caption = "Nowe powiadomienie";
  _F->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall T_MagFRM::m_MegaMenuClick(TObject* Sender)
{
  /* m_MegaMenu->
  m_MegaMenu->MenuItems->Items->;
  String sass = m_MegaMenu->MenuItems->ToString();
  int as =m_MegaMenu->GetFirstMenu()->SelectedItem;
  m_MegaMenu->GetHashCode();
  int a; */
}
// ---------------------------------------------------------------------------
void __fastcall T_MagFRM::_KosztyFRA1AdvSmoothButton2Click(TObject* Sender)
{
  std::auto_ptr<T_NowyKosztFRM>_F(new T_NowyKosztFRM(NULL));
  _F->Caption = "Edycja kosztu";
  _F->ShowModal();
}
// ---------------------------------------------------------------------------
void __fastcall T_MagFRM::_PowiadomFRA1AdvSmoothButton2Click(TObject* Sender)
{
  std::auto_ptr<T_NowePowiadFRM>_F(new T_NowePowiadFRM(NULL));
  _F->Caption = "Edycja powiadomienia";
  _F->ShowModal();

}
// ---------------------------------------------------------------------------
void __fastcall T_MagFRM::AdvSmoothButton3Click(TObject* Sender)
{
  Close();
}
// ---------------------------------------------------------------------------
void __fastcall T_MagFRM::runOnFindSprzet(const msg::MagID& _MagID)
{
 if(m_MainP->Visible)
 {
   m_MainP->Visible =false;
   Sleep(100);
 }
 *m_MagID = _MagID;
 m_NaglMagFRA->open(_MagID);
 m_SumKosztyFRA->open(_MagID);
 m_KUTBTClick(NULL);
 m_MainP->Visible = true;
 m_DelSprzBB->Visible = RightsChecker::rightToDelMag();

}
//---------------------------------------------------------------------------
void __fastcall T_MagFRM::closeFrames(void)
{
 m_KutyFRA->close();
 m_PowiadomFRA->close();
 m_KosztyFRA->close();
 m_DokFRA->close();
}
//---------------------------------------------------------------------------
void __fastcall T_MagFRM::m_KUTBTClick(TObject *Sender)
{
 closeFrames();
 int _IdHarm = m_NaglMagFRA->getIdHarm();
 if(_IdHarm > 0) m_MagID->IdHarm = _IdHarm;
 m_KutyFRA->open(*m_MagID);
}
//---------------------------------------------------------------------------
msg::MagID __fastcall T_MagFRM::getID(void) const
{
 return *m_MagID;
}


void __fastcall T_MagFRM::AdvSmoothButton4Click(TObject *Sender)
{
 closeFrames();
 m_DokFRA->open(*m_MagID);
}
//---------------------------------------------------------------------------
void __fastcall T_MagFRM::m_DelSprzBBClick(TObject *Sender)
{
 AnsiString _Msg("Operacja usuniêcia sprzêtu JEST NIEODWRACALNA!\nCzy kontynuowaæ?");
 if(mng::MessageDialog::warning(_Msg,"OSTZRE¯ENIE",MB_YESNO) ==IDYES)
 {
  mng::QueryDB _Q("DELETE FROM PR_ZLECENIA WHERE ROK_MAG=:ROK AND DEPOZYT = :DEPOZYT AND ID_KOMORKI_GLW = :ID_KOMORKI AND ID_MAG = :ID_MAG");
  m_MagID->setToPars(_Q.getParams());
  _Q.execute();
  _Q.setQuery("DELETE FROM PR_MAGAZYN WHERE ROK=:ROK AND DEPOZYT = :DEPOZYT AND ID_KOMORKI = :ID_KOMORKI AND ID_MAG = :ID_MAG");
  m_MagID->setToPars(_Q.getParams());
  _Q.execute();
 }
 mng::MessageDialog::information(AnsiString("Trwale usuniêto pozycjê magazynow¹ o sygnaturze:") + m_MagID->getSygnMag(),"" );
 show();
}
//---------------------------------------------------------------------------

void __fastcall T_MagFRM::FormShow(TObject *Sender)
{
 m_SzukajFRA->m_IdMagTE->SetFocus();
}
//---------------------------------------------------------------------------



void __fastcall T_MagFRM::m_KutyFRAm_NewBTClick(TObject *Sender)
{
  m_KutyFRA->m_NewBTClick(Sender);
  m_SumKosztyFRA->open(*m_MagID);

}
//---------------------------------------------------------------------------

void __fastcall T_MagFRM::m_KutyFRAm_EditBTClick(TObject *Sender)
{
  m_KutyFRA->m_EditBTClick(Sender);
   m_SumKosztyFRA->open(*m_MagID);

}
//---------------------------------------------------------------------------

void __fastcall T_MagFRM::m_KutyFRAm_DelBTClick(TObject *Sender)
{
  m_KutyFRA->m_DelBTClick(Sender);
   m_SumKosztyFRA->open(*m_MagID);

}
//---------------------------------------------------------------------------


