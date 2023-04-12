//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MainMenu.h"
#include <vector.h>
#include "MANAGER\connection_info.h"
#include "dictionary_combo.h"
#include <memory>
#include "MeldTygCTRL.h"
#include "platform.h"
#include "IMPORT\FROMMDB\ImportFromMdbCTRL.h"
#include "SprKwartalCTRL.h"
#include "SlEditFRM.h"
#include <sqr.h>
#include "jbutils\jb_ini_my.h"
#include "ListaHarmFRM.h"
#include "SlPracownicyFRM.h"
#include "SlWydzialyFRM.h"
#include "SlOddzialyFRM.h"
#include "SlStanowiskaFRM.h"
#include "SlKomorkiFRM.h"
#include "TestAcc.h"
#include "MozlRemCTRL.h"
#include "PotrzRemCTRL.h"
#include "fm_rej_operat.h"
#include "RBH4OSCTRL.h"
#include "SlKadraFRM.h"
#include "SlSprzetFRM.h"
#include "SlSprzetRodzajeFRM.h"
#include "SlSprzetGrupyFRM.h"
#include "PlanKwartCTRL.h"
#include "BilMozlProdCTRL.h"
#include "PlanKwartZadCTRL.h"
#include "StSprzCTRL.h"
#include "MagCTRL.h"
#include <dateutils.hpp>
#include "WezwMNG.h"
#include "KwMozlWarCTRL.h"
#include "KwMozlWarSprzCTRL.h"
#include "RBH4MiesCTRL.h"
#include "HarmDostCTRL.h"
#include <vector>
#include "fm_Error.h"
#include "right_checker.h"
#include "PowDostFRM.h"
#include "KonfigFRM.h"
#include "SlJednostkiFRM.h"
#include "pr_PocztaCtrl.h"
#include "MANAGER\message_dlg.h"
#include "MANAGER\is_exceptions.h"
#include "MANAGER\is_manager.h"
#include "QuickRpt.hpp"
#include "EksportToMdbCTRL.h"
#include <isUpdDB.h>
#include "AddRbhFRM.h"
#include "RBH4OneMiesCTRL.h"
#include "SQR\sqr_events_man.h"
#include "RozlGodzSQRHdlr.h"
#include "SprRoczneCTRL.h"
#include "SprMiesCTRL.h"
#include "GlownyReader.h"
#include "GlownyID.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothMegaMenu"
#pragma link "IBDatabase"
#pragma link "Chart"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma link "AdvSmoothPanel"
#pragma link "Numedit"
#pragma link "rtflabel"
#pragma resource "*.dfm"
T_MainMenu* _MainMenu;

// ---------------------------------------------------------------------------
__fastcall T_MainMenu::T_MainMenu(TComponent* Owner) : TForm(Owner)
{
 bool _Min = jbutils::TMyIni().ReadIniBool("ZAAWANSOWANE","Menu ukryte",false);
 Height = _Min ? 90 :300;
 if(!_Min) WindowState = wsMaximized;
 Application->OnException   = avEventsException;
 Forms::Screen->OnActiveFormChange = setMngForms;
}
void __fastcall T_MainMenu::setMngForms(TObject *Sender)
{
 mng::TfmError* _FErr = dynamic_cast<mng::TfmError*>(Forms::Screen->ActiveForm);
 if(_FErr)
 {
  _FErr->btDrukuj->OnClick = btDrukujErrClick;
 }

}
//---------------------------------------------------------------------
void __fastcall T_MainMenu::btDrukujErrClick(TObject *Sender)
{
 bool printed = Platform::printErr() ;
 if(printed) mng::MessageDialog::information("Opis b³êdu zosta³ wydrukowany",Caption,MB_OK) ;
}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::avEventsException(TObject* Sender, Exception * E)
{
 Platform::showException(Sender,E);
}
// ---------------------------------------------------------------------------
void __fastcall T_MainMenu::AdvSmoothButton1Click(TObject* Sender)
{
  Close();
}
// ---------------------------------------------------------------------------

void __fastcall T_MainMenu::Kartoteka1Click(TObject* Sender)
{
 main::MagCTRL _MagCTRL;
 _MagCTRL.edit();
}
// ---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_MeldTygTMIClick(TObject *Sender)
{
 std::auto_ptr<progzest::MeldTygCTRL> _MeldTyg(new progzest::MeldTygCTRL());
 _MeldTyg->run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::FormShow(TObject *Sender)
{

  if(!Platform::Initialize()) Close();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::FormClose(TObject *Sender, TCloseAction &Action)
{
  Platform::Terminate();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_ImportMdbTMIClick(TObject *Sender)
{
  std::auto_ptr<importmdb::ImportFromMdbCTRL> _Imp(new importmdb::ImportFromMdbCTRL());
  _Imp->run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_SprawKwartTMIClick(TObject *Sender)
{
  std::auto_ptr<progzest::SprKwartalCTRL> _SprKwart(new progzest::SprKwartalCTRL());
  _SprKwart->run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::ToolButton4Click(TObject* Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Stopniewojskowe1Click(TObject *Sender)
{
  std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtStopnie);
  _F->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Stanowiska1Click(TObject *Sender)
{
  std::auto_ptr<T_SlStanowiskaFRM> slForm(new T_SlStanowiskaFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Oddzia1Click(TObject *Sender)
{
  std::auto_ptr<T_SlOddzialyFRM> slForm(new T_SlOddzialyFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Rodzajepowiadomien1Click(TObject *Sender)
{
  std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtRodzPow);
  _F->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Grupysprzetu1Click(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetGrupyFRM> slForm(new T_SlSprzetGrupyFRM(NULL));
  slForm->MyShowModal();
}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_GenSQRTMIClick(TObject *Sender)
{
  sqr::SQRMan _SqrMan;
  sqr::T_EventsMan _EvMan;
  handlers::RozlGodzSQRHdlr _RzlGodz;
  _EvMan.regEvent(&_RzlGodz, sqr::T_EventsMan::evBefore);
  AnsiString _Temp = jbutils::TMyIni::getDirIni()+ AnsiString("TEMP");
 _SqrMan.ShowSQR(this, &_EvMan,_Temp,false,false );

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::JednostkiWojskowe1Click(TObject *Sender)
{
 std::auto_ptr<T_SlJednostkiFRM>_F(new T_SlJednostkiFRM(NULL));
 _F->MyShowModal();
/*  std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtJednostki);
  _F->ShowModal();*/
}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_MiesTMIClick(TObject *Sender)
{
 std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtMiesiace);
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Wydzialy1Click(TObject *Sender)
{
  std::auto_ptr<T_SlWydzialyFRM> slForm(new T_SlWydzialyFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Rodzajesprzetu1Click(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetRodzajeFRM> slForm(new T_SlSprzetRodzajeFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Sprzet1Click(TObject *Sender)
{
  std::auto_ptr<T_SlSprzetFRM> slForm(new T_SlSprzetFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Kodyusug1Click(TObject *Sender)
{
   std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtKodyUslug);
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Osoby1Click(TObject *Sender)
{
  std::auto_ptr<T_SlPracownicyFRM> slForm(new T_SlPracownicyFRM(NULL));
  slForm->MyShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_EwidPlanTMIClick(TObject *Sender)
{
  std::auto_ptr<T_ListaHarmFRM>_F(new T_ListaHarmFRM(NULL));
   int _Rok =jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  _F->setRok(_Rok);
 _F->ShowModal();

}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::ShowArchPlan(TObject *Sender)
{
 TMenuItem * _ItM = dynamic_cast<TMenuItem*>(Sender);
 if(_ItM)
 {
  TReplaceFlags _Fl;
  _Fl << rfReplaceAll;
  int _Rok = StringReplace(_ItM->Caption,"&","",_Fl).ToIntDef(-1);
  if(_Rok >0)
  {
	std::auto_ptr<T_ListaHarmFRM>_F(new T_ListaHarmFRM(NULL));
	_F->setRok(_Rok);
	_F->ShowModal();
  }
 }
}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_ProjPlanuTMIClick(TObject *Sender)
{
   std::auto_ptr<T_ListaHarmFRM>_F(new T_ListaHarmFRM(NULL));
  int _Rok =jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  ++_Rok;
  _F->setRok(_Rok);
  _F->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::Korektaplanu1Click(TObject *Sender)
{
   std::auto_ptr<T_ListaHarmFRM>_F(new T_ListaHarmFRM(NULL));
  int _Rok =jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  _Rok*=-1;
  _F->setRok(_Rok);
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::est1Click(TObject *Sender)
{
  std::auto_ptr<TTestFRM>_F(new TTestFRM(NULL));
  _F->ShowModal();

}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_PlanArch2010TMIClick(TObject *Sender)
{
	std::auto_ptr<T_ListaHarmFRM>_F(new T_ListaHarmFRM(NULL));
  int _Rok =jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  --_Rok;
  _F->setRok(_Rok);
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Komorki1Click(TObject *Sender)
{
  std::auto_ptr<T_SlKomorkiFRM> slForm(new T_SlKomorkiFRM(NULL));
  slForm->MyShowModal();
}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_MozlRemTMIClick(TObject *Sender)
{
 progzest::MozlRemCTRL _MozlRem;
 _MozlRem.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_PotrzRemTMIClick(TObject *Sender)
{
 progzest::PotrzRemCTRL _PotrzRem;
 _PotrzRem.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_RBH4OsTMIClick(TObject *Sender)
{
  progzest::RBH4OSCTRL _R;
 _R.run();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_KadraTMIClick(TObject *Sender)
{
  std::auto_ptr<T_SlKadraFRM> slForm(new T_SlKadraFRM(NULL));
  slForm->MyShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_PlanKwartTMIClick(TObject *Sender)
{
   progzest::PlanKwartCTRL PlanKwart;
   PlanKwart.run();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_BilMozlProdTMIClick(TObject *Sender)
{
 progzest::BilMozlProdCTRL _Bil;
 _Bil.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Kwartalnyplanzada1Click(TObject *Sender)
{
 progzest::PlanKwartZadCTRL _Plan;
 _Plan.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_SprMiesTMIClick(TObject *Sender)
{
  progzest::SprMiesCTRL _St;
 _St.run();

}
//---------------------------------------------------------------------------


void __fastcall T_MainMenu::Dodaj1Click(TObject *Sender)
{
 main::MagCTRL _MagCTRL;
 _MagCTRL.add();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_PowRemTMIClick(TObject *Sender)
{
 WezwMNG _WM;
 _WM.run();
}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_SlowZwTMIClick(TObject *Sender)
{
   std::auto_ptr<T_SlEditFRM> _F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtNazwyZw);
  _F->Caption = m_SlowZwTMI->Caption;
  _F->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_SlowDokTMIClick(TObject *Sender)
{
	std::auto_ptr<T_SlEditFRM> _F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtDokumenty);
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::Bilansmoliwociwarsztatu1Click(TObject *Sender)
{
 TMenuItem* _It = dynamic_cast<TMenuItem*>(Sender);
 String _Capt;
 if(_It) _Capt = _It->Caption;
 std::auto_ptr<progzest::KwMozlWarCTRL> _R( new progzest::KwMozlWarCTRL(_Capt));
 _R->run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_KwMozlWarSprzTMIClick(TObject *Sender)
{
 TMenuItem* _It = dynamic_cast<TMenuItem*>(Sender);
 String _Capt;
 if(_It) _Capt = _It->Caption;
 std::auto_ptr<progzest::KwMozlWarSprzCTRL> _R( new progzest::KwMozlWarSprzCTRL(_Capt));
 _R->run();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_RBH4MiesTMIClick(TObject *Sender)
{
  std::auto_ptr<progzest::RBH4MiesCTRL> _R( new progzest::RBH4MiesCTRL());
 _R->run();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_HarmDostTMIClick(TObject *Sender)
{
  std::auto_ptr<progzest::HarmDostCTRL> _R( new progzest::HarmDostCTRL());
 _R->run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_PrzyjSprzTMIClick(TObject *Sender)
{
 main::MagCTRL _MagCTRL;
 _MagCTRL.receive();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_WydSprzTMIClick(TObject *Sender)
{
 main::MagCTRL _MagCTRL;
 _MagCTRL.issue();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_RemTMIClick(TObject *Sender)
{
  std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtRemonty);
  _F->Caption = m_SlowZwTMI->Caption;
  _F->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_RejTMIClick(TObject *Sender)
{
   if(!RightsChecker::rightToInfo(true))
   {
	  return;
   }

   std::auto_ptr<TRejOperat> win(new TRejOperat(NULL));

   bool czy_edit = RightsChecker::rightToEdit(false, "ADRO");

   win->Display(czy_edit);

   win->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall T_MainMenu::m_PowDostTMIClick(TObject *Sender)
{
 std::auto_ptr<T_PowDostFRM>  fm(new T_PowDostFRM(this));
 fm->ShowModal();

}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_ParsTMIClick(TObject* Sender)
{
  std::auto_ptr<T_KonfigFRM>fm(new T_KonfigFRM(this));
  fm->ShowModal();
  FormActivate(Sender);
}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_ImpTMIClick(TObject* Sender)
{
  //T_ImporterWizjaJB::execute(Owner);
  PocztaCtrl::import(this);
}

//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_ExpTMIClick(TObject* Sender)
{
  //Mailer::sendMail("grybki@gmail.com","Test","Dupcia blada","P:\\PLANREM\\EXE\\MDB\\spr.mdb");
  //std::auto_ptr<T_ToWizjaJBFRM>fm(new T_ToWizjaJBFRM(Owner));
  //fm->ShowModal();
  PocztaCtrl::eksport(this);
}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_SlowKosztTMIClick(TObject *Sender)
{
  std::auto_ptr<T_SlEditFRM>_F(new T_SlEditFRM(NULL));
  _F->setDict(T_SlEditFRM::dtKoszty);
  _F->Caption = m_SlowKosztTMI->Caption;
  _F->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_ChangeOpTMIClick(TObject *Sender)
{
 mng::Manager::instance().login();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_QRPPrevTMIClick(TObject *Sender)
{
 TQuickRep * R = new TQuickRep(this);
 R->Preview();
 delete R;

}
//---------------------------------------------------------------------------



void __fastcall T_MainMenu::EksportplanudobazydanychMSAccess1Click(TObject *Sender)

{
 eksportmdb::EksportToMdbCTRL _ECtrl;
 _ECtrl.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::UruchaminieskryptwSPT1Click(TObject *Sender)
{
 odNaprSpt->InitialDir =ExtractFileDir(Application->ExeName) + "\\SPT_NAPR";
 if(RightsChecker::rightToSPT() )
 {
  if (odNaprSpt->Execute())
  {
   AnsiString _Path =  odNaprSpt->FileName ;
   AnsiString _Mess = AnsiString(" Skrypt: " ) + _Path;
   static AnsiString _Capt("WYKONYWANIE SKRYPTÓW SPT");
	udb::DatabaseUpdater updater;

   if( updater.updateDatabaseF(_Path) )
   {
	_Mess += "\rwykona³ siê prawid³owo!";
	mng::MessageDialog::information(_Mess,_Capt);
   }
   else
   {
	_Mess +="\rwykona³ siê z b³êdami!\r Proszê sprawdziæ log b³êdów!";
	mng::MessageDialog::warning(_Mess,_Capt);
   }
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_RozlRBHTMIClick(TObject *Sender)
{
   std::auto_ptr<T_AddRbhFRM>_F(new T_AddRbhFRM(NULL));
  _F->showModal();

}
//---------------------------------------------------------------------------
void __fastcall T_MainMenu::m_RozlMiesGodzTMIClick(TObject *Sender)
{
 progzest::RBH4OneMiesCTRL _Ctrl;
 _Ctrl.run();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::FormActivate(TObject *Sender)
{
 m_RokLB->Caption = String("Bie¿¹cy rok: ") + jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
 msg::GlownyID _GlID = readers::GlownyReader::read();
 m_GlownyLB->Caption = _GlID.getWydzCM() + "(" + _GlID.getBaseCode() + ")";
 Update();
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::runRoczneSpr(TObject *Sender)
{
 progzest::SprRoczneCTRL _Rep;
 int _RSpr(0);
 TMenuItem * _MI(dynamic_cast<TMenuItem*>(Sender));
 _Rep.run(_MI->Tag);
}
//---------------------------------------------------------------------------

void __fastcall T_MainMenu::m_PlanFromMdbTMIClick(TObject *Sender)
{
 importmdb::ImportFromMdbCTRL _Ctrl;
 _Ctrl.runPlan();
}
//---------------------------------------------------------------------------


