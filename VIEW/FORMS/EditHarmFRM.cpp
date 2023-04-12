//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "EditHarmFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "DateUtils.hpp"
#include "EditHarmRBFFRMBIZ.h"
#include "EditHarmRBFFRM.h"
#include <memory>
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
T_EditHarmFRM::Pars::Pars(void)
 :NrMies(-1),
 IdWarsztatu(-1)
 {

 }
//---------------------------------------------------------------------------
__fastcall T_EditHarmFRM::T_EditHarmFRM(TComponent* Owner)
	: TForm(Owner),
	  m_NrHarm(-1)
{
  m_HarmSDB = new mng::StreamDB();
  m_HarmSDB->setQuery("SELECT * FROM PR_HARMONOGRAM WHERE ID_HARMONOGRAMU = :ID_HARM and ROK = :ROK");
  m_HarmDS->DataSet = m_HarmSDB->getClient();

  m_HarmDetSDB = new mng::StreamDB();
  m_HarmDetSDB->setQuery("SELECT D.*, M.NAZ_MIES FROM PR_HARMONOGRAM_DET D  INNER JOIN PR_MIESIACE M ON M.NR_MIES = D.MIESIAC  WHERE D.ID_HARMONOGRAMU = :ID_HARM  AND D.ROK = :ROK");
  m_HarmDetSDB->setEventsHandler(new EditHarmRBFFRMBIZ() );
  m_HarmDetDS->DataSet = m_HarmDetSDB->getClient();
  m_HarmDetSDB->getClient()->IndexFieldNames = "MIESIAC";
  m_UslSDB = new mng::StreamDB();
  m_UslSDB->setQuery("SELECT * FROM PR_KODY_USLUG ");
  m_UslDS->DataSet = m_UslSDB->getClient();

  m_RemSDB = new mng::StreamDB();
  m_RemSDB->setQuery("SELECT * FROM PR_REMONTY ");
  m_RemDS->DataSet = m_RemSDB->getClient();

  m_JWSDB = new mng::StreamDB();
  m_JWSDB->setQuery("SELECT J.*, J.JW ||' '||  J.MIEjSCOWOSC AS JW_MIEJSCOWOSC FROM PR_JEDNOSTKI J  ORDER BY JW");
  m_JWDS->DataSet = m_JWSDB->getClient();

  m_WarSDB = new mng::StreamDB();
  m_WarSDB->setQuery("SELECT *  FROM PR_KOMORKI WHERE WARSZTAT ='T' AND ID_KOMORKI >0  ORDER BY KOD ");
  m_WarDS->DataSet = m_WarSDB->getClient();

  m_SprzetSDB = new mng::StreamDB();
  m_SprzetSDB->setQuery("SELECT *  FROM PR_SPRZET ");
  m_SprzetDS->DataSet = m_SprzetSDB->getClient();

  m_Ini = new jbutils::TMyIni();
 }
//---------------------------------------------------------------------------
__fastcall T_EditHarmFRM::~T_EditHarmFRM(void)
{
 delete m_HarmSDB;
 delete m_HarmDetSDB;
 delete m_JWSDB;
 delete m_UslSDB;
 delete m_RemSDB;
 delete m_WarSDB;
 delete m_SprzetSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------
int _fastcall T_EditHarmFRM::display(const Pars& _Pars)
{
 m_Pars = _Pars;
 int _Res;
  open(_Pars);
 if(_Pars.HarmId.NrHarm <0)
 {
  insert(_Pars);
 }
 else
 {
  edit();
 }
 _Res = ShowModal();
 if(_Res == mrOk)
 {
  m_HarmSDB->applyUpdates();
  m_HarmDetSDB->applyUpdates();
 }
 close();
 return _Res;
}
//---------------------------------------------------------------------------
void _fastcall T_EditHarmFRM::open(const T_EditHarmFRM::Pars& _Pars)
{
 m_HarmSDB->paramByName("ID_HARM")->AsInteger    =  _Pars.HarmId.NrHarm;
 m_HarmDetSDB->paramByName("ID_HARM")->AsInteger =  _Pars.HarmId.NrHarm;
 m_HarmSDB->paramByName("ROK")->AsInteger        =  _Pars.HarmId.Rok;
 m_HarmDetSDB->paramByName("ROK")->AsInteger     =  _Pars.HarmId.Rok;

 m_HarmSDB->open();
 m_HarmDetSDB->open();
 m_UslSDB->open();
 m_RemSDB->open();
 m_JWSDB->open();
 m_WarSDB->open();
 m_SprzetSDB->open();
 m_WarSDB->fieldByName("KOD")->DisplayWidth = 5;
 m_WarSDB->fieldByName("NAZWA")->DisplayWidth = 345;
 m_UslCB->DropHeight    = (m_UslSDB->getClient()->RecordCount+1) * m_UslCB->GridRowHeight;
 //m_RemCB->DropDownRows  = m_RemSDB->getClient()->RecordCount;
 m_WarCB->DropHeight  = (m_WarSDB->getClient()->RecordCount+2) * m_WarCB->GridRowHeight;

}
//---------------------------------------------------------------------------
void  __fastcall T_EditHarmFRM::insert(const T_EditHarmFRM::Pars& _Pars)
{
  m_HarmSDB->append();
  m_HarmSDB->fieldByName("ID_KOMORKI")->AsInteger  = _Pars.IdWarsztatu;
  m_HarmSDB->fieldByName("DATA_OD")->AsDateTime    = TDateTime(abs(_Pars.HarmId.Rok),1,1);
  m_HarmSDB->fieldByName("DATA_DO")->AsDateTime    = TDateTime(abs(_Pars.HarmId.Rok),12,31);
  m_HarmSDB->fieldByName("ROK")->AsInteger           = _Pars.HarmId.Rok;

}
//---------------------------------------------------------------------------
void _fastcall T_EditHarmFRM::edit(void)
{
 m_HarmSDB->edit();
}
//---------------------------------------------------------------------------
void _fastcall T_EditHarmFRM::close(void)
{
 m_HarmSDB->close();
 m_HarmDetSDB->close();
 m_UslSDB->close();
 m_RemSDB->close();
 m_JWSDB->close();
 m_WarSDB->close();
 m_SprzetSDB->close();
}
//---------------------------------------------------------------------------
void __fastcall T_EditHarmFRM::m_AddBTClick(TObject *Sender)
{
 if( m_HarmDetSDB->getClient()->State == dsBrowse) m_HarmDetSDB->append();
 m_HarmDetSDB->fieldByName("ROK")->AsInteger = m_HarmSDB->fieldByName("ROK")->AsInteger;
 m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU_DET")->AsInteger = -1;
 m_HarmDetSDB->fieldByName("ILOSC")->AsCurrency =0;
 m_HarmDetSDB->fieldByName("PLAN_RBH")->AsCurrency =0;
 std::auto_ptr<T_EditHarmRBFFRM> _F(new T_EditHarmRBFFRM(NULL) );
 _F->m_HarmDS->DataSet    = m_HarmSDB->getClient();
 _F->m_HarmDetDS->DataSet = m_HarmDetSDB->getClient();
 _F->display(m_Pars.RBHMies);
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::m_EditBTClick(TObject *Sender)
{
 if( m_HarmDetSDB->getClient()->State == dsBrowse) m_HarmDetSDB->edit();
 std::auto_ptr<T_EditHarmRBFFRM> _F(new T_EditHarmRBFFRM(NULL) );
 _F->m_HarmDS->DataSet    = m_HarmSDB->getClient();
 _F->m_HarmDetDS->DataSet = m_HarmDetSDB->getClient();
 _F->display(m_Pars.RBHMies);
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::m_DelBTClick(TObject *Sender)
{
 m_HarmDetSDB->erase();
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::m_SaveBTClick(TObject *Sender)
{
 TDateTime _NullD(0.0);
 if(m_HarmSDB->fieldByName("DATA_OD")->AsDateTime <= _NullD)
 {
  mng::MessageDialog::critical("Proszê podaæ datê dostarczenia","B£¥D");
  m_DataOdED->SetFocus();
  return;
 }
 if(m_HarmSDB->fieldByName("DATA_DO")->AsDateTime <= _NullD)
 {
  mng::MessageDialog::critical("Proszê podaæ planowan¹ datê zakoñczenia","B£¥D");
  m_DataDoED->SetFocus();
  return;
 }
 if(!m_HarmSDB->isEdited() ) m_HarmSDB->edit();
 m_HarmSDB->fieldByName("ID_HARMONOGRAMU_GL")->AsInteger = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 m_HarmSDB->applyUpdates();
 m_HarmDetSDB->first();
 Currency _SumIl,_SumRBH;
 mng::QueryDB _Q("select first 1 gen_id(PR_HARMONOGRAM_DET_GEN,1) ID_H from PR_HARMONOGRAM_DET");
 while(!m_HarmDetSDB->isEof())
 {
  m_HarmDetSDB->edit();
  if(m_HarmDetSDB->fieldByName("ROK")->IsNull)
  {
   m_HarmDetSDB->fieldByName("ROK")->AsInteger = m_HarmSDB->fieldByName("ROK")->AsInteger;
  }
  if(m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU")->IsNull)
  {
   m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger = m_HarmSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
  }
  if(m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU_DET")->IsNull || m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU_DET")->AsInteger <=0 )
  {
   _Q.open();
   m_HarmDetSDB->fieldByName("ID_HARMONOGRAMU_DET")->AsInteger = _Q.fieldByName("ID_H")->AsInteger;
   _Q.close();
  }
  m_HarmDetSDB->post();
  _SumIl  += m_HarmDetSDB->fieldByName("ILOSC")->AsCurrency;
  _SumRBH += m_HarmDetSDB->fieldByName("PLAN_RBH")->AsCurrency;
  m_HarmDetSDB->next();
 }
 bool _App(true);
 if(_SumRBH != _SumIl * m_HarmSDB->fieldByName("NORMA_RBH")->AsCurrency)
 {
  AnsiString _M("Iloczyn iloœci sprzêtu i normy godzinowej nie jest równy iloœci przypisanych godzin.\n Czy pomimo tego zapisaæ zmiany?");
  _App = mng::MessageDialog::warning(_M,"UWAGA",MB_YESNO) == IDYES;
 }
 if(_App)
 {
  m_HarmDetSDB->applyUpdates();
  ModalResult = mrOk;
 }
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::m_CancelBTClick(TObject *Sender)
{
 m_HarmSDB->cancelUpdates();
 m_HarmDetSDB->cancelUpdates();
}
//---------------------------------------------------------------------------



void __fastcall T_EditHarmFRM::clearIfEmpty(TObject *Sender)
{
 TAdvDBLookupComboBox * _Ctrl(dynamic_cast<TAdvDBLookupComboBox *>(Sender) );
 if(_Ctrl)
 {
  if(_Ctrl->Text.IsEmpty()) m_HarmSDB->fieldByName(_Ctrl->DataField)->Clear();
 }
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::FormShow(TObject *Sender)
{
if(m_NrHarmED->CanFocus() ) m_NrHarmED->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall T_EditHarmFRM::m_CountRBHBTClick(TObject *Sender)
{
 m_HarmDetSDB->first();
 while(!m_HarmDetSDB->isEof())
 {
  m_HarmDetSDB->edit();
  m_HarmDetSDB->fieldByName("PLAN_RBH")->AsCurrency = m_HarmDetSDB->fieldByName("ILOSC")->AsCurrency * m_HarmSDB->fieldByName("NORMA_RBH")->AsCurrency;
  m_HarmDetSDB->next();
 }
}
//---------------------------------------------------------------------------

