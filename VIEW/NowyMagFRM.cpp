// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NowyMagFRM.h"
#include "isManager.h"
#include "MagID.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "DateUtils.hpp"
#include "ZlecID.h"
#include "HarmFinderCTRL.h"
#include "MANAGER\message_dlg.h"
#include "MagREC.h"
#include "KomorkiDICT.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "DBAdvSmoothDatePicker"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
// ---------------------------------------------------------------------------
__fastcall T_NowyMagFRM::T_NowyMagFRM(TComponent* Owner) : TForm(Owner)
{
 m_SerwisDS->OnDataChange = NULL;
 m_RokPlDS->OnDataChange = NULL;

  m_SDB = new mng::StreamDB;
  m_DS->DataSet = m_SDB->getClient();
  m_SDB->setQuery("SELECT * FROM PR_MAGAZYN WHERE ROK =:ROK AND ID_KOMORKI = :ID_KOMORKI AND DEPOZYT = :DEPOZYT AND ID_MAG = :ID_MAG ");

  m_SprzetSDB = new mng::StreamDB;
  m_SprzetDS->DataSet = m_SprzetSDB->getClient();
  m_SprzetSDB->setQuery("SELECT * FROM PR_SPRZET ORDER BY NAZWA ");

  m_WarsztatSDB = new mng::StreamDB;
  m_WarsztatDS->DataSet = m_WarsztatSDB->getClient();
  m_WarsztatSDB->setQuery("SELECT * FROM PR_KOMORKI WHERE WARSZTAT ='T'  AND ID_KOMORKI >0 ORDER BY KOD ");

  m_PlanSDB = new mng::StreamDB;
  m_PlanDS->DataSet = m_PlanSDB->getClient();
  m_PlanSDB->setQuery("SELECT H.*, S.NAZWA AS NAZ_SPRZETU, K.ID_WYDZIALU, \
  CASE WHEN S.NAZWA IS NULL THEN '' ELSE S.NAZWA END || ' '||    \
  CASE WHEN H.ZADANIE IS NULL THEN '' ELSE H.ZADANIE END AS NAZ_ZAD, \
  H.id_harmonogramu as id_harm,    \
  (select coalesce(sum(d.ILOSC),0) from pr_harmonogram_det d  where d.ROK = h.rok and d.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU) as ilosc,   \
  (select coalesce(sum(d.ILOSC),0) from pr_harmonogram_det d  where d.ROK = h.rok and d.ID_HARMONOGRAMU = h.ID_HARMONOGRAMU)-  \
  (select coalesce(sum(m.ILOSC),0) from pr_magazyn         m  where m.ROK = h.ROK and m.ID_HARM = h.ID_HARMONOGRAMU) as ilosc_dost   \
  FROM PR_HARMONOGRAM H LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU   \
  LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI    \
  WHERE H.ROK = :ROK   \
  ORDER BY H.ID_HARMONOGRAMU ");

  m_JWSDB = new mng::StreamDB;
  m_JWDS->DataSet = m_JWSDB->getClient();
  m_JWSDB->setQuery("SELECT J.*, RTRIM(J.NAZWA_PELNA) || ' ' || RTRIM(J.MIEJSCOWOSC)  AS JEDNOSTKA FROM PR_JEDNOSTKI J ORDER BY J.JW ");

  m_RemSDB = new mng::StreamDB;
  m_RemDS->DataSet = m_RemSDB->getClient();
  m_RemSDB->setQuery(" SELECT * FROM PR_REMONTY ");

  m_WydzSDB = new mng::StreamDB();
  m_WydzDS->DataSet = m_WydzSDB->getClient();
  m_WydzSDB->setQuery("SELECT distinct  WY.*  FROM PR_WYDZIALY WY INNER JOIN PR_KOMORKI KO ON KO.ID_WYDZIALU = WY.ID_WYDZIALU WHERE KO.WARSZTAT ='T'");

  m_RokPlSDB = new mng::StreamDB();
  m_RokPlDS->DataSet = m_RokPlSDB->getClient();
  m_RokPlSDB->setQuery("select rok, count(id_harmonogramu) from pr_harmonogram group by rok");


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
  m_Ini    = new jbutils::TMyIni();
  m_Pars   = new msg::MagREC();
  m_MagID  = new msg::MagID();
 m_SerwisDS->OnDataChange = przeliczNrMag;
 m_RokPlDS->OnDataChange = przeliczNrMag;
}

// ---------------------------------------------------------------------------
__fastcall T_NowyMagFRM::~T_NowyMagFRM()
{
  delete m_SDB;
  m_WydzDS->OnDataChange = NULL;
  delete m_WydzSDB;//MUSI BYÆ PIERWSZE
  delete m_SprzetSDB;
  delete m_WarsztatSDB;
  delete m_PlanSDB;
  delete m_JWSDB;
  delete m_RemSDB;
  delete m_Ini;
  delete m_Pars;
  delete m_MagID;

}
// ---------------------------------------------------------------------------
int __fastcall T_NowyMagFRM::show(msg::MagID& _Mag, const msg::MagREC& _Pars)
{
  *m_Pars  = _Pars;
  *m_MagID = _Mag;
  open(_Mag);
  setControls(_Mag);
  int _Res = ShowModal();
  if(_Res == mrOk) setMag(_Mag);
  close();
  return _Res;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::open(const msg::MagID& _Mag)
{
  int _Rok;
  int _IdWydz;
  String _WyFi;

  m_RokPlSDB->open();
  if(_Mag.IsDefined)
  {
   _Rok     = _Mag.Rok;
   _IdWydz  = dict::KomorkiDICT::instance().getIdWydzialu(_Mag.IdKomorki);
   _WyFi = String(" ID_WYDZIALU = ") + String(_IdWydz);
  }
  else
  {
   _Rok     =  m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Rok dostawy", CurrentYear());
   _IdWydz  =  m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
   _WyFi    = m_Ini->ReadIniString("WARTOŒCI DOMYŒLNE","Filtr wydzia³ów",String(" ID_WYDZIALU = ") + String(_IdWydz) );
   m_RokPlCB->KeyValue = -9999;
   m_RokPlCB->KeyValue = _Rok;

  }
  m_WydzDS->OnDataChange = NULL;
  m_WydzSDB->setFilter(_WyFi);
  m_WydzSDB->setFiltered(!_WyFi.IsEmpty());
  m_WydzSDB->open();
  if(!_Mag.IsDefined)
  {
   m_WydzCB->KeyValue  = _IdWydz;
   m_Wydz1CB->KeyValue = _IdWydz;
  }
  m_SprzetSDB->open();

  m_WarsztatSDB->open();
  m_WarsztatSDB->fieldByName("KOD")->DisplayWidth = 4;

  m_PlanSDB->paramByName("ROK")->AsInteger = _Rok;
  m_PlanSDB->open();

  m_JWSDB->open();
  m_RemSDB->open();
  if(_Mag.IsDefined)
  {
   m_SDB->paramByName("ROK")->AsInteger        = _Mag.Rok;
   m_SDB->paramByName("ID_KOMORKI")->AsInteger = _Mag.IdKomorki;
   m_SDB->paramByName("DEPOZYT")->AsString     = _Mag.Depozyt;
   m_SDB->paramByName("ID_MAG")->AsInteger     = _Mag.IdMag;
  }
  else
  {
   m_SDB->paramByName("ROK")->AsInteger        = -1;
   m_SDB->paramByName("ID_KOMORKI")->AsInteger = -1;
   m_SDB->paramByName("DEPOZYT")->AsString     = "";
   m_SDB->paramByName("ID_MAG")->AsInteger     = -1;
  }
  m_SDB->open();
  if(_Mag.IsDefined)
  {
   m_SDB->edit();
  }
  else
  {
   m_SDB->append();
   m_RokPlCB->KeyValue = -9999;
   m_RokPlCB->KeyValue = _Rok;
   m_SDB->fieldByName("ROK")->AsString     = _Rok;
   m_SDB->fieldByName("DEPOZYT")->AsString = "R";
   m_SDB->fieldByName("PROT_PRZYJ")->AsString   = m_Pars->ProtPrzyj;
   m_SDB->fieldByName("DATA_PRZYJ")->AsDateTime = m_Pars->DataPrzyj;
  }
 m_SDB->fieldByName("ID_HARM")->OnChange      = filLPlan;
 m_SDB->fieldByName("ROK")->OnChange          =onRokChange;
 m_WydzDSDataChange(m_WydzDS, m_WydzSDB->fieldByName("ID_WYDZIALU"));
 m_WydzDS->OnDataChange = m_WydzDSDataChange;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::setControls(const msg::MagID& _MagID)
{
 bool _Ed  = !_MagID.IsDefined;
 setControls(m_NrMagED,_Ed);
 setControls(m_RokED,_Ed);
 setControls(m_RokPlCB,_Ed);
 setControls(m_WydzCB,_Ed);
 setControls(m_Wydz1CB,_Ed);
 setControls(m_SerwisCB,_Ed);


 m_NrMagBT->Visible  = !_Ed;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::setControls(TDBLookupComboBox* _Ctrl, bool _Ed)
{
 _Ctrl->ReadOnly = !_Ed;
 _Ctrl->TabStop  =  _Ed;
 _Ctrl->Ctl3D    =  _Ed;
 _Ctrl->Color    = _Ed ? clWindow : clInfoBk;
 _Ctrl->DropDownRows  = _Ed ? 7 :0 ;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::setControls(TDBEdit* _Ctrl, bool _Ed)
{
 _Ctrl->ReadOnly = !_Ed;
 _Ctrl->TabStop =  _Ed;
 _Ctrl->Ctl3D    = _Ed;
 _Ctrl->Color    = _Ed ? clWindow : clInfoBk;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::setMag(msg::MagID& _Mag)
{
 _Mag.IsDefined = true;
 _Mag.Rok       = m_SDB->fieldByName("ROK")->AsInteger;
 _Mag.IdKomorki = m_SDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Mag.Depozyt   = m_SDB->fieldByName("DEPOZYT")->AsString;
 _Mag.NrMag     = m_SDB->fieldByName("NR_MAG")->AsInteger;
  _Mag.IdMag    = m_SDB->fieldByName("ID_MAG")->AsInteger;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::close(void)
{
  m_SprzetSDB->close();
  m_WarsztatSDB->close();
  m_PlanSDB->close();
  m_JWSDB->close();
  m_SDB->close();
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::AdvSmoothButton4Click(TObject* Sender)
{
  if(valid())
  {
   msg::MagID _MagID;
   setMag(_MagID);
   complete(_MagID);
   m_SDB->post();
   m_SDB->applyUpdates();
   ModalResult = mrOk;
  }
}
// ---------------------------------------------------------------------------
bool __fastcall T_NowyMagFRM::valid(void)
{
 bool _Res;
 _Res =  validIlosc();
 return _Res;
}
// ---------------------------------------------------------------------------
bool __fastcall T_NowyMagFRM::validIlosc(void)
{
 bool _Res(true);
 Currency _IlPlan = m_PlanSDB->fieldByName("ILOSC")->AsCurrency;
 Currency _IlDost = m_SDB->fieldByName("ILOSC")->AsCurrency;
 if(_IlDost == 0)
 {
  AnsiString _Mess("Pole iloœæ musi mieæ wartoœæ! ");
  mng::MessageDialog::critical(_Mess,"B³¹d");
  _Res = false;

 }
 else if(_IlPlan >0 && _IlPlan < _IlDost)
 {
  AnsiString _Mess("Wprowadzona iloœæ przekracza iloœæ zaplanowan¹! ");
  mng::MessageDialog::critical(_Mess,"B³¹d");
  _Res = false;
 }
 if(!_Res && m_IloscED->CanFocus()) m_IloscED->SetFocus();
 return _Res;
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::complete(const msg::MagID& _Mag)
{
 mng::QueryDB _Q("select gen_id(pr_magazyn_gen,1) AS LICZNIK, max(id_mag) AS MAKS from pr_magazyn ");
 _Q.open();
 m_SDB->fieldByName("ID_MAG")->AsInteger  = _Q.fieldByName("LICZNIK")->AsInteger;
 m_SDB->fieldByName("SYGN_MAG")->AsString = _Mag.getSygnMag();
 m_SDB->fieldByName("STATUS")->AsString  = "N";
 msg::ZlecID _ZlecID(_Mag);
 String _Dep(_Mag.Depozyt == "R" ? String("") : _Mag.Depozyt );
 m_SDB->fieldByName("GLOWNY_KUT")->AsString  = _ZlecID.getSygn(_Dep);
 _Q.close();
}
// ---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::AdvSmoothButton1Click(TObject* Sender)
{
 m_SDB->cancel();
 m_SDB->cancelUpdates();
 ModalResult = mrCancel;
}

// ---------------------------------------------------------------------------
const AnsiString T_NowyMagFRM::M_NOWY_NR_SQL("SELECT  \
MIN(M.NR_MAG) AS NR_MAG  FROM PR_MAGAZYN M  \
INNER JOIN  PR_KOMORKI K ON K.ID_KOMORKI =M.ID_KOMORKI \
WHERE M.ROK = :ROK and m.DEPOZYT = :DEPOZYT and K.ID_WYDZIALU = :ID_WYDZIALU  \
AND NOT EXISTS ( SELECT NULL FROM PR_MAGAZYN M1  \
INNER JOIN PR_KOMORKI K1 ON K1.ID_KOMORKI =M1.ID_KOMORKI  \
WHERE M1.ROK = M.ROK  and M1.DEPOZYT = :DEPOZYT  AND K1.ID_WYDZIALU = K.ID_WYDZIALU AND M1.NR_MAG = M.NR_MAG +1)  \
");
// ---------------------------------------------------------------------------
const AnsiString T_NowyMagFRM::M_MIN_NR_SQL("SELECT min(M.NR_MAG) NR_MAG \
FROM PR_MAGAZYN M INNER JOIN PR_KOMORKI K ON K.ID_KOMORKI =M.ID_KOMORKI \
 where M.ROK=:ROK and m.DEPOZYT = :DEPOZYT and k.id_wydzialu=:ID_WYDZIALU \
 ");
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::m_NrMagBTClick(TObject *Sender)
{
 if(m_MagID->IsDefined || !m_SDB->isOpen()) return;
 int _Rok        = m_SDB->fieldByName("ROK")->AsInteger;
 int _IdWydz     = m_WydzSDB->fieldByName("ID_WYDZIALU")->AsInteger;
 String _Serwis  = m_SerwisCD->FieldByName("KOD_SERWISU")->AsString;
 int _NrMag;
 mng::QueryDB _Q(M_MIN_NR_SQL);
 _Q.paramByName("ID_WYDZIALU")->AsInteger =  _IdWydz;
 _Q.paramByName("ROK")->AsInteger         =  _Rok;
 _Q.paramByName("DEPOZYT")->AsString      =  _Serwis;
 _Q.open();
 _NrMag = _Q.fieldByName("NR_MAG")->AsInteger;
 if(_NrMag != 1) _NrMag = 1;
 else
 {
  _Q.setQuery(M_NOWY_NR_SQL);
  _Q.paramByName("ID_WYDZIALU")->AsInteger =  _IdWydz;
  _Q.paramByName("DEPOZYT")->AsString      =  _Serwis;
  _Q.paramByName("ROK")->AsInteger     =  _Rok;
  _Q.open();
  _NrMag = _Q.fieldByName("NR_MAG")->AsInteger +1;
  _Q.close();
 }
 m_NrMagED->Text = _NrMag;
 m_SDB->fieldByName("NR_MAG")->AsInteger = _NrMag;
}
//---------------------------------------------------------------------------

void __fastcall T_NowyMagFRM::m_PlanCBKeyPress(TObject *Sender, wchar_t &Key)
{
 Key;
 Key =Key;
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::filLPlan(TField *Sender)
{
 if(m_PlanSDB->locate("ID_HARMONOGRAMU",m_SDB->fieldByName("ID_HARM")->AsInteger) )
 {
  m_SDB->fieldByName("ID_KOMORKI")->AsInteger     =   m_PlanSDB->fieldByName("ID_KOMORKI")->AsInteger;
  m_SDB->fieldByName("ID_REMONTU")->AsInteger     =   m_PlanSDB->fieldByName("ID_REMONTU")->AsInteger;
  m_SDB->fieldByName("ID_JEDNOSTKI")->AsInteger   =   m_PlanSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
  m_SDB->fieldByName("ID_SPRZETU")->AsInteger     =   m_PlanSDB->fieldByName("ID_SPRZETU")->AsInteger;
  m_SDB->fieldByName("NR_REJ")->AsString          =   m_PlanSDB->fieldByName("NR_ZADANIA")->AsString;
  m_SDB->fieldByName("DATA_PROP_ZAK")->AsDateTime =   m_PlanSDB->fieldByName("DATA_DO")->AsDateTime;
  if(m_PlanSDB->fieldByName("DATA_OD")->AsDateTime != TDateTime(0.0) )
  {
   m_SDB->fieldByName("DATA_PRZYJ")->AsDateTime    =   m_PlanSDB->fieldByName("DATA_OD")->AsDateTime;
  }
  if(m_PlanSDB->fieldByName("ILOSC")->AsCurrency == 1.00) m_SDB->fieldByName("ILOSC")->AsInteger =1;
  m_NrMagBTClick(NULL);
 }
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::filterPlan(TField *Sender)
{
 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Rok dostawy", m_SDB->fieldByName("ROK")->AsInteger);
 m_PlanSDB->close();
 m_PlanSDB->paramByName("ROK")->AsInteger = m_SDB->fieldByName("ROK")->AsInteger;
 m_PlanSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::onRokChange(TField *Sender)
{
 m_NrMagBTClick(Sender);
 filterPlan(Sender);
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::m_WarsztatCBKeyPress(TObject *Sender, wchar_t &Key)
{
 if(isdigit(Key) || Key =='/')
 {
  m_WarKeyBuff += Key;
  TLocateOptions _LocOpt;
  _LocOpt<<loCaseInsensitive;
  if(m_WarsztatSDB->locate("KOD",m_WarKeyBuff,_LocOpt))
  {
   m_SDB->fieldByName("ID_KOMORKI")->AsInteger = m_WarsztatSDB->fieldByName("ID_KOMORKI")->AsInteger;
   m_WarsztatCB->KeyValue = -1;
   m_WarsztatCB->KeyValue = m_WarsztatSDB->fieldByName("ID_KOMORKI")->AsInteger;
   m_WarKeyBuff = "";
  }

 }
  if(m_WarKeyBuff.Length() > 2) m_WarKeyBuff ="";
}
//---------------------------------------------------------------------------

void __fastcall T_NowyMagFRM::clearWarKeyBuff(TObject *Sender)
{
 m_WarKeyBuff ="";
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::m_DostCBKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
 if( m_DostCB->Text.IsEmpty() ) m_SDB->fieldByName("ID_JEDNOSTKI")->Clear();
}
//---------------------------------------------------------------------------

void __fastcall T_NowyMagFRM::m_WydzDSDataChange(TObject *Sender, TField *Field)
{
 int _IdWydz(m_WydzSDB->fieldByName("ID_WYDZIALU")->AsInteger);
 String _F(" ID_WYDZIALU = ");
 _F += String(_IdWydz);
 m_WarsztatSDB->setFilter(_F);
 m_WarsztatSDB->setFiltered(true);
 m_PlanSDB->setFilter(_F);
 m_PlanSDB->setFiltered(true);
 int _IdH  = m_SDB->fieldByName("ID_HARM")->AsInteger;
 int _IdHP = m_PlanSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 if(_IdH != _IdHP)
 {
  bool _Loc = m_PlanSDB->locate("ID_HARMONOGRAMU",m_SDB->fieldByName("ID_HARM")->AsInteger);
 }

 m_WydzCB->KeyValue  = _IdWydz;
 m_Wydz1CB->KeyValue = _IdWydz;
 przeliczNrMag(Sender,Field);
}
//---------------------------------------------------------------------------
void __fastcall T_NowyMagFRM::przeliczNrMag(TObject *Sender, TField *Field)
{
 m_NrMagBTClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall T_NowyMagFRM::m_FindHarmBBClick(TObject *Sender)
{
 finders::HarmFinderCTRL _Fi;
 finders::HarmFinderCTRL::Pars _Pars;
 int _IdHarm;
 _Pars.Rok        = m_SDB->fieldByName("ROK")->AsInteger;
 _Pars.IdWydzialu = m_WydzSDB->fieldByName("ID_WYDZIALU")->AsInteger;
 if(_Fi.find(_IdHarm,_Pars) == mrOk)
 {
  m_SDB->fieldByName("ID_HARM")->AsInteger = _IdHarm;
 }
}
//---------------------------------------------------------------------------

void __fastcall T_NowyMagFRM::DBAdvSmoothDateclearData(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
 if(Key == VK_DELETE)
 {
  TDBAdvSmoothDatePicker* _C = dynamic_cast<TDBAdvSmoothDatePicker*>(Sender);
  if(_C)
  {
   if(_C->DataSource)
   {
	if(_C->DataSource->DataSet)
	{
	 if(!_C->DataField.IsEmpty())
	 {
	  _C->DataSource->DataSet->FieldByName(_C->DataField)->Clear();
	  _C->Update();
     }
    }
   }
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall T_NowyMagFRM::FormShow(TObject *Sender)
{
 if(m_RokPlCB->CanFocus()) m_RokPlCB->SetFocus();
}
//---------------------------------------------------------------------------

