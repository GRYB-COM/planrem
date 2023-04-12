// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "SlEditFRM.h"
#include "isManager.h"
#include "MANAGER\various_man.h"
#include <math.h>
#include <dateutils.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AsgLinks"
#pragma link "BaseGrid"
#pragma link "ccedlink"
#pragma link "DBAdvGrid"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"
#include <sqr.h>
// ---------------------------------------------------------------------------
// #include "wi_iSlModel.h"

// ---------------------------------------------------------------------------
__fastcall T_SlEditFRM::T_SlEditFRM(TComponent* Owner)
: TForm(Owner),
  m_EditFRM(NULL)
{
  m_SDB = new mng::StreamDB;
  m_DS->DataSet = m_SDB->getClient();
}

// ---------------------------------------------------------------------------
__fastcall T_SlEditFRM::~T_SlEditFRM()
{
  delete m_SDB;
}

// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_SaveBBClick(TObject* Sender)
{
 if(mng::Manager::instance().checkRight("RRDIC") )  m_SDB->applyUpdates();
 Close();
}

// ---------------------------------------------------------------------------
void T_SlEditFRM::setDict(DicType _Dict)
{
 mng::QueryDB _QDB("SELECT MAX(M.ROK) MAX_ROK, MIN(M.ROK) MIN_ROK FROM PR_MIES4RBH M");
 _QDB.open();
 m_RokCB->Items->Clear();
 for(int i = _QDB.fieldByName("MIN_ROK")->AsInteger; i < _QDB.fieldByName("MAX_ROK")->AsInteger +4; i++)
 {
  m_RokCB->Items->Add(i);
 }
 _QDB.close();


 m_Dic = _Dict;
 mng::Query _Q;
 m_ShowAddBB = true;
 m_ShowEditBB = true;
 m_ShowDelBB = true;
 m_TopPA->Visible = false;
  switch(_Dict)
  {
  case dtStopnie:
	Caption = "Stopnie wojskowe";
	_Q.setColumnList("ID_STOPNIA AS ID, NAZWA");
	_Q.setTableRef("PR_STOPNIE");

	// if(_IdMag!="" && _IdMag != NULL)_Q.attachWherePred(new mng::ComparePredicate("m.ID_MAG", _IdMag));
	// if(_IdHarm!="" && _IdHarm != NULL)_Q.attachWherePred(new mng::ComparePredicate("m.ID_HARM", _IdHarm));
	break;
  case dtRemonty:
	Caption = "Remonty";
	_Q.setColumnList("ID_REMONTU, KOD_REM, NAZWA");
	_Q.setTableRef("PR_REMONTY");
	break;
  case dtOddzialy:
	Caption = "Oddzia³y";
	_Q.setColumnList("ID_ODDZIALU AS ID, KOD, NAZWA");
	_Q.setTableRef("PR_ODDZIALY");
	break;
  case dtGrSprzet:
	Caption = "Grupy sprzêtu";
	_Q.setColumnList("ID_GR_SPRZ AS ID, NAZWA");
	_Q.setTableRef("PR_GRUPY_SPRZETU");
	break;
  case dtStanowiska:
	Caption = "Stanowiska";
	_Q.setColumnList("ID_STANOWISKA AS ID, NAZWA");
	_Q.setTableRef("PR_STANOWISKA");
	break;
  case dtRodzPow:
	Caption = "Rodzaje powiadomieñ";
	_Q.setColumnList("ID_RODZ_POW AS ID, NAZWA");
	_Q.setTableRef("PR_RODZAJE_POWIADOMIEN");
	break;
  case dtKodyUslug:
	Caption = "Kody us³ug";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_KODY_USLUG");
    WindowState = wsMaximized;
	break;
  case dtJednostki:
	Caption = "S³ownik jednostek i oddzia³ów";
    WindowState = wsMaximized;
	_Q.setColumnList("*");
	_Q.setTableRef("PR_JEDNOSTKI");
	break;
  case dtSprzet:
	Caption = "";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_SPRZET");
	break;
  case dtRodzSprz:
	Caption = "";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_RODZAJE_SPRZETU ");
	break;
  case dtWarsztaty:
	Caption = "";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_KOMORKI");
	break;
  case dtWydzialy:
	Caption = "";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_WYDZIALY");
	break;
  case dtMiesiace:
	Caption = "Dni i godziny robocze";
	_Q.setColumnList(" 'Wszystkie miesi¹ce' as NAZ_MIES, M.* ");
	_Q.setTableRef("PR_MIES4RBH M ");
	_Q.setOrderList(" M.NR_MIES ");
	m_ShowAddBB         = false;
	m_ShowEditBB        = false;
	m_ShowDelBB         = false;
	m_PrintBB->Left     = 6;
	Height = 330;
	Width  = 350;
	m_RokCB->Text = YearOf(Date());
	m_RokCBCloseUp(NULL);
	m_TopPA->Visible = true;
	break;
  case dtNazwyZw:
	Caption = "Rodzaje zwolnieñ";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_SLOW_ZW");
	m_ShowAddBB  = true;
	m_ShowDelBB  = true;
	m_ShowEditBB = false;
	m_UsunBB->Left      = 77;
	m_PrintBB->Left     = 170;
	Height = 250;
	Width  = 400;
	break;
  case dtDokumenty:
	Caption = "S³ownik dokumentów";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_SLOW_DOK");
	m_ShowAddBB    = true;
	m_ShowDelBB    = true;
	m_ShowEditBB   = false;
	m_UsunBB->Left = 77;
	m_PrintBB->Left= 170;
	Height = 250;
	Width  = 600;
	break;
  case dtKoszty:
	Caption = "S³ownik kosztów";
	_Q.setColumnList("*");
	_Q.setTableRef("PR_SLOW_KOSZTOW");
	m_ShowAddBB     = true;
	m_ShowDelBB     = true;
	m_ShowDelBB     = true;
	m_ShowEditBB    = false;
	m_UsunBB->Left  = 77;
	m_PrintBB->Left= 170;
	Height = 250;
	Width  = 450;

	break;

  }
  m_SDB->setQuery(_Q);
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_RokCBCloseUp(TObject *Sender)
{
m_SDB->getClient()->Filtered = false;
 String _Filter("NR_MIES <> 0 and ROK = ");
 if(m_RokCB->ItemIndex >-1)
 {
  _Filter +=  m_RokCB->Items->operator[](m_RokCB->ItemIndex);
 }
 else
 {
  _Filter += YearOf(Date());
 }
m_SDB->getClient()->Filter = _Filter;
m_SDB->getClient()->Filtered = true;

}
//---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::afterOpen(void)
{
   switch(m_Dic)
  {

  case dtMiesiace:
	m_SDB->fieldByName("NR_MIES")->Visible = false;
	m_SDB->fieldByName("ROK")->Visible = false;
	m_SDB->fieldByName("NAZ_MIES")->OnGetText = getNazMies;
	m_SDB->fieldByName("NAZ_MIES")->DisplayLabel = "Miesi¹c";
	m_SDB->fieldByName("NAZ_MIES")->DisplayWidth = 10;
	m_SDB->fieldByName("NAZ_MIES")->ReadOnly     = true;
	m_SDB->fieldByName("DNI_ROB")->DisplayLabel  =  "Dni robocze";
	m_SDB->fieldByName("DNI_ROB")->Index = 2;
	m_RokCBCloseUp(NULL);
	break;
   case dtNazwyZw:
	m_SDB->fieldByName("ID_SLOW_ZW")->Visible = false;
   break;
   case dtDokumenty:
	m_SDB->fieldByName("ID_SLOW_DOK")->Visible = false;
   break;
   case dtRemonty:
	m_SDB->fieldByName("ID_REMONTU")->Visible = false;
	m_SDB->fieldByName("KOD_REM")->DisplayLabel = "Kod remontu";
	m_SDB->fieldByName("NAZWA")->DisplayLabel = "Nazwa";
   break;
   case dtJednostki:
	m_SDB->fieldByName("ID_JEDNOSTKI")->Visible = false;
   break;
   case dtKoszty:
	m_SDB->fieldByName("ID_SLOW_KOSZTOW")->Visible = false;
   break;
  }
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::afterAppend(void)
{
   switch(m_Dic)
  {
   case dtNazwyZw:
	m_SDB->fieldByName("ID_SLOW_ZW")->AsInteger = rand()* (-1);
	break;
   case dtDokumenty:
	m_SDB->fieldByName("ID_SLOW_DOK")->AsInteger = rand()* (-1);
	break;
   case dtRemonty:
	m_SDB->fieldByName("ID_REMONTU")->AsInteger = rand()* (-1);
	break;
   case dtJednostki:
	m_SDB->fieldByName("ID_JEDNOSTKI")->AsInteger = rand()* (-1);
   break;
   case dtKoszty:
	m_SDB->fieldByName("ID_SLOW_KOSZTOW")->AsInteger = rand()* (-1);
   break;
  }
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_DodajBBClick(TObject* Sender)
{
	m_SDB->last();
	m_SDB->append();
	afterAppend();
	if(m_EditFRM) m_EditFRM->ShowModal();
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_EdytujBBClick(TObject* Sender)
{
 m_SDB->edit();
 if(m_EditFRM) m_EditFRM->ShowModal();
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_UsunBBClick(TObject* Sender)
{
  m_SDB->erase();
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::FormShow(TObject* Sender)
{
  onShow();
  m_SDB->open();
  afterOpen();
  bool _Right =mng::Manager::instance().checkRight("RRDIC");
  m_DodajBB->Visible   = m_ShowAddBB  && _Right;
  m_EdytujBB->Visible  = m_ShowEditBB && _Right;
  m_UsunBB->Visible    = m_ShowDelBB  && _Right;
  m_DodajBB->Enabled   = m_ShowAddBB  && _Right;
  m_EdytujBB->Enabled  = m_ShowEditBB && _Right;
  m_UsunBB->Enabled    = m_ShowDelBB  && _Right;
  m_CancelBB->Visible  = _Right;
  m_SaveBB->Caption    = _Right ? "Zapisz" : "Zamknij";
  m_DBG->ReadOnly      = !_Right;
}
// ---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::m_AnulujBBClick(TObject *Sender)
{
 m_SDB->cancel();
 Close();
}
//---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_SDB->close();

}
//---------------------------------------------------------------------------

void __fastcall T_SlEditFRM::m_CancelBBClick(TObject *Sender)
{
 m_SDB->cancelUpdates();
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_SlEditFRM::m_PrintBBClick(TObject *Sender)
{
 mng::ControlsMan _CoMan(m_DBG->DataSource->DataSet);
 sqr::SQRMan sm ;
 sm.ShowRap(m_DBG,Caption,"","-", "|", NULL) ;

}
//---------------------------------------------------------------------------
void __fastcall T_SlEditFRM::getNazMies(TField *Sender, UnicodeString &Text, bool DisplayText)
{
 int _NrMies(-1);
 TField * _F = m_SDB->getClient()->FindField("NR_MIES");
 if(_F)
 {
  _NrMies = _F->AsInteger;
  if(_NrMies ==0) Text ="Wszystkie miesi¹ce";
  else
  {
   Text = LongMonthNames[_NrMies -1];
  }
 }
}
//---------------------------------------------------------------------------

