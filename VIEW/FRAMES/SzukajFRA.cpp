//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SzukajFRA.h"
#include "SprzetFinderCTRL.h"
#include "classes.hpp"
#include "MagID.h"
#include "MANAGER\message_dlg.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma link "AdvCombo"
#pragma link "AdvDBComboBox"
#pragma link "AdvDBLookupComboBox"
#pragma link "dblucomb"
#pragma link "Lucombo"
#pragma link "AdvControlDropDown"
#pragma link "AdvDropDown"
#pragma link "AdvSmoothComboBox"
#pragma link "AdvSmoothListBox"
#pragma link "DBAdvControlDropDown"
#pragma link "DBAdvGlowNavigator"
#pragma link "DBAdvSmoothComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
const AnsiString T_SzukajFRA::M_WYDZ_SQL("\
SELECT  -1 AS ID_WYDZIALU, ' ' AS KOD,  'Wszystkie warsztaty' AS NAZWA,  COUNT(*) AS COUNTER   FROM PR_WYDZIALY WY \
UNION \
SELECT  WY.ID_WYDZIALU, WY.KOD,  WY.NAZWA,  1 AS COUNTER \
FROM PR_WYDZIALY WY WHERE EXISTS (SELECT NULL FROM PR_KOMORKI KO WHERE KO.ID_WYDZIALU = WY.ID_WYDZIALU AND KO.WARSZTAT ='T') \
");
//---------------------------------------------------------------------------
const AnsiString T_SzukajFRA::M_NEXT_MAG_SQL("\
select m.nr_mag from pr_magazyn m \
inner join pr_komorki k on k.ID_KOMORKI = m.ID_KOMORKI  \
where m.rok=:rok and m.DEPOZYT = :DEPOZYT and k.ID_WYDZIALU = :ID_WYDZIALU  \
and  m.NR_MAG > :NR_MAG \
ORDER BY M.NR_MAG  \
");
//---------------------------------------------------------------------------
const AnsiString T_SzukajFRA::M_MAX_MAG_SQL("\
select MAX(m.nr_mag) AS NR_MAG from pr_magazyn m \
inner join pr_komorki k on k.ID_KOMORKI = m.ID_KOMORKI \
where m.rok=:rok and m.DEPOZYT = :DEPOZYT and k.ID_WYDZIALU = :ID_WYDZIALU \
");
//---------------------------------------------------------------------------
const AnsiString T_SzukajFRA::M_PRIOR_MAG_SQL("\
select m.nr_mag from pr_magazyn m \
inner join pr_komorki k on k.ID_KOMORKI = m.ID_KOMORKI   \
where m.rok=:rok and m.DEPOZYT = :DEPOZYT and k.ID_WYDZIALU = :ID_WYDZIALU   \
and  m.NR_MAG < :NR_MAG  \
ORDER BY M.NR_MAG desc \
");
//---------------------------------------------------------------------------
const AnsiString T_SzukajFRA::M_MIN_MAG_SQL("\
select MIN(m.nr_mag) AS NR_MAG from pr_magazyn m  \
inner join pr_komorki k on k.ID_KOMORKI = m.ID_KOMORKI \
where m.rok=:rok and m.DEPOZYT = :DEPOZYT and k.ID_WYDZIALU = :ID_WYDZIALU  \
");
//---------------------------------------------------------------------------
__fastcall T_SzukajFRA::T_SzukajFRA(TComponent* Owner)
	: TFrame(Owner),
	  m_OnFind(NULL),
	  m_IsArrowBT(false),
	  m_Sleep(400)
{
 m_SprzFind = new finders::SprzetFinderCTRL();
 m_Ini      = new jbutils::TMyIni();
 m_SerwisCD->CreateDataSet();
  m_SerwisCD->Append();
   m_SerwisCD->FieldByName("KOD_SERWISU")->AsString = "R";
   m_SerwisCD->FieldByName("NAZ_SERWISU")->AsString ="Remont";
  m_SerwisCD->Post();
  m_SerwisCD->Append();
   m_SerwisCD->FieldByName("KOD_SERWISU")->AsString ="S";
   m_SerwisCD->FieldByName("NAZ_SERWISU")->AsString ="Serwis";
  m_SerwisCD->Post();
  m_SerwisCD->Append();
   m_SerwisCD->FieldByName("KOD_SERWISU")->AsString ="D";
   m_SerwisCD->FieldByName("NAZ_SERWISU")->AsString ="Depozyt";
  m_SerwisCD->Post();

  m_WydzSDB = new mng::StreamDB();
  m_WydzDS->DataSet = m_WydzSDB->getClient();
  m_WydzSDB->setQuery(M_WYDZ_SQL);

  m_IdyIncQDB  = new mng::QueryDB(M_NEXT_MAG_SQL);
  m_IdyMaxQDB  = new mng::QueryDB(M_MAX_MAG_SQL);
  m_IdyDecQDB  = new mng::QueryDB(M_PRIOR_MAG_SQL);
  m_IdyMinQDB  = new mng::QueryDB(M_MIN_MAG_SQL);

}
//---------------------------------------------------------------------------
__fastcall T_SzukajFRA::~T_SzukajFRA()
{
 delete m_SprzFind;
 delete m_Ini;
 delete m_WydzSDB;
 delete m_IdyIncQDB;
 delete m_IdyMaxQDB;
 delete m_IdyDecQDB;
 delete m_IdyMinQDB;
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::m_FindNrMagBTClick(TObject *Sender)
{
 finders::SprzetFinderCTRL::Pars _Pars;
 _Pars.IdMag.NrMag     = StrToIntDef(m_IdMagTE->Text,0);
 _Pars.IdMag.Rok       = StrToIntDef(m_RokMagTE->Text,m_BiezRok);
 _Pars.IdMag.Depozyt   = m_SerwisCB->KeyValue;
 _Pars.IdWydzialu      = m_WydzCB->KeyValue;
 _Pars.IdMag.IsDefined = true;
 msg::MagID _MagID;
 int _Res = m_SprzFind->find(_MagID, _Pars);
 if(_MagID.IsDefined)
 {
  runOnFind(_MagID);
 }
 else if(_Res ==mrOk)
 {
  AnsiString _Msg("Nie znaleziono pozycji magazynowej o podanym numerze: ");
  _Msg += _Pars.IdMag.getSygnMag();
  mng::MessageDialog::warning(_Msg,"");
 }

}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::runOnFind(const msg::MagID& _MagID)
{
 m_IdMagTE->Text       = FormatFloat("000",_MagID.NrMag);
 m_RokMagTE->Text      = _MagID.Rok;
 m_SerwisCB->KeyValue  = _MagID.Depozyt;
 int _IdWydz           = _MagID.getIdWydzialu();
 int _IdWydzDef        = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
 m_WydzCB->KeyValue    = _IdWydz >0 ? _IdWydz : _IdWydzDef;
 writeIni();
 if(m_OnFind)
 {
   m_OnFind(_MagID);
 }
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::setOnFindSprzet(OnFindSprzet _OnFS)
{
 openStreams();
 m_OnFind = _OnFS;
}
void __fastcall T_SzukajFRA::NrMagKeyPress(TObject *Sender, wchar_t &Key)
{
 if(Key =='\r')
 {
  m_FindNrMagBTClick(Sender);
  Key=0;
 }
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::prepare(void)
{
 readIni();
 openStreams();
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::openStreams(void)
{
  int    _IdWydz  = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
  String _WyFi    = m_Ini->ReadIniString("WARTOŒCI DOMYŒLNE","Filtr wydzia³ów",String(" ID_WYDZIALU = ") + String(_IdWydz) );
  if(!_WyFi.IsEmpty()) _WyFi += " OR ID_WYDZIALU = -1 ";
  m_WydzSDB->setFilter(_WyFi);
  m_WydzSDB->setFiltered(!_WyFi.IsEmpty());
  m_WydzSDB->close();
  m_WydzSDB->open();
 int _IdWydzC = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³ - kartoteka", _IdWydz);
  m_SerwisCB->KeyValue = m_Ini->ReadIniString("WARTOŒCI DOMYŒLNE", "Depozyt","R");
  m_WydzCB->KeyValue   = -9999;
  m_WydzCB->KeyValue   = _IdWydzC;


}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::readIni(void)
{
 m_IdMagTE->Text      = FormatFloat("000",m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE", "Nr mag.",1));
 m_BiezRok            = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE", "Bie¿¹cy rok",CurrentYear());
 m_RokMagTE->Text     = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE", "Rok mag.",m_BiezRok);
 m_SerwisCB->KeyValue = String("");

}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::writeIni(void)
{
 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE", "Nr mag.",StrToIntDef(m_IdMagTE->Text,1));
 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE", "Rok mag.",StrToIntDef(m_RokMagTE->Text,m_BiezRok));
 m_Ini->WriteIniString("WARTOŒCI DOMYŒLNE", "Depozyt",m_SerwisCB->KeyValue);
 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³ - kartoteka",m_WydzCB->KeyValue);
}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::m_AdwSearchBTClick(TObject *Sender)
{
 finders::SprzetFinderCTRL::Pars _Pars;
 msg::MagID _MagID;
 int _Res = m_SprzFind->find(_MagID,_Pars) ;
 if(_MagID.IsDefined)
 {
  runOnFind(_MagID);
 }
 else if(_Res ==mrOk)
 {
  AnsiString _Msg("Nie znaleziono pozycji magazynowej o podanych parametrach");
  mng::MessageDialog::warning(_Msg,"");
 }

}
//---------------------------------------------------------------------------
void __fastcall T_SzukajFRA::open(const msg::MagID& _MagID)
{
 runOnFind(_MagID);
}
//---------------------------------------------------------------------------


void __fastcall T_SzukajFRA::m_DecrBTMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int    _Nr   = m_IdMagTE->Text.ToIntDef(9999);
  int    _Rok  = m_RokMagTE->Text.ToIntDef(m_BiezRok);
  String _Dep  = m_SerwisCB->KeyValue;
  int    _IdW  = m_WydzCB->KeyValue;
  m_IsArrowBT = true;
  m_IdyDecQDB->paramByName("ROK")->AsInteger         = _Rok;
  m_IdyDecQDB->paramByName("DEPOZYT")->AsString      = _Dep;
  m_IdyDecQDB->paramByName("ID_WYDZIALU")->AsInteger = _IdW;
  m_IdyDecQDB->paramByName("NR_MAG")->AsInteger      = _Nr;
  m_IdyDecQDB->open();
  if(!m_IdyDecQDB->isEmpty())
  {
   while(m_IsArrowBT && !m_IdyDecQDB->isEof())
   {
	_Nr = m_IdyDecQDB->fieldByName("NR_MAG")->AsInteger;
	if(_Nr <=0) _Nr=1;
	m_IdMagTE->Text = FormatFloat("000",_Nr);

	Sleep(m_Sleep);
	Update();
	Application->ProcessMessages();
	if(m_Sleep >70) m_Sleep -=70;
	m_IdyDecQDB->next();
   }
  }
  else
  {
   m_IdyMinQDB->paramByName("ROK")->AsInteger         = _Rok;
   m_IdyMinQDB->paramByName("DEPOZYT")->AsString      = _Dep;
   m_IdyMinQDB->paramByName("ID_WYDZIALU")->AsInteger = _IdW;
   m_IdyMinQDB->open();
   _Nr = m_IdyMinQDB->fieldByName("NR_MAG")->AsInteger;
   if(_Nr <=0) _Nr=1;
   m_IdMagTE->Text = FormatFloat("000",_Nr);
   m_IdyMinQDB->close();

  }
  m_IsArrowBT = false;
  m_IdyDecQDB->close();
}
//---------------------------------------------------------------------------

void __fastcall T_SzukajFRA::m_IncBTMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  int    _Nr   = m_IdMagTE->Text.ToIntDef(9999);
  int    _Rok  = m_RokMagTE->Text.ToIntDef(m_BiezRok);
  String _Dep  = m_SerwisCB->KeyValue;
  int    _IdW  = m_WydzCB->KeyValue;
  m_IsArrowBT = true;
  m_IdyIncQDB->paramByName("ROK")->AsInteger         = _Rok;
  m_IdyIncQDB->paramByName("DEPOZYT")->AsString      = _Dep;
  m_IdyIncQDB->paramByName("ID_WYDZIALU")->AsInteger = _IdW;
  m_IdyIncQDB->paramByName("NR_MAG")->AsInteger      = _Nr;
  m_IdyIncQDB->open();
  if(!m_IdyIncQDB->isEmpty())
  {
   while(m_IsArrowBT && !m_IdyIncQDB->isEof())
   {
	_Nr = m_IdyIncQDB->fieldByName("NR_MAG")->AsInteger;
	if(_Nr <=0) _Nr=1;
	m_IdMagTE->Text = FormatFloat("000",_Nr);

	Sleep(m_Sleep);
	Update();
	Application->ProcessMessages();
	if(m_Sleep >50) m_Sleep -=70;
	m_IdyIncQDB->next();
   }
  }
  else
  {
   m_IdyMaxQDB->paramByName("ROK")->AsInteger         = _Rok;
   m_IdyMaxQDB->paramByName("DEPOZYT")->AsString      = _Dep;
   m_IdyMaxQDB->paramByName("ID_WYDZIALU")->AsInteger = _IdW;
   m_IdyMaxQDB->open();
	_Nr = m_IdyMaxQDB->fieldByName("NR_MAG")->AsInteger;
	if(_Nr <=0) _Nr=1;
	m_IdMagTE->Text = FormatFloat("000",_Nr);
   m_IdyMaxQDB->close();
  }
  m_IsArrowBT = false;
  m_IdyIncQDB->close();
}
//---------------------------------------------------------------------------


void __fastcall T_SzukajFRA::freeArrowBT(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
 m_IsArrowBT = false;
 m_Sleep = 400;
 m_IdyIncQDB->close();
 m_IdyDecQDB->close();
 m_IdyMinQDB->close();
 m_IdyMaxQDB->close();
 m_FindNrMagBTClick(Sender);

}
//---------------------------------------------------------------------------


