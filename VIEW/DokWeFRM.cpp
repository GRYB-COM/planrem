//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DokWeFRM.h"
#include "manager\stream_db.h"
#include "manager\query_db.h"
#include "MagID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvDBLookupComboBox"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_DokWeFRM::T_DokWeFRM(TComponent* Owner)
	: TForm(Owner),
	onPrint(NULL),
	m_IsPrint(false)
{
 m_DokSDB = new mng::StreamDB;
 m_DokDS->DataSet = m_DokSDB->getClient();
 m_DokSDB->setQuery("SELECT * FROM PR_SLOW_DOK ");
}
//---------------------------------------------------------------------------
__fastcall T_DokWeFRM::~T_DokWeFRM()
{
  m_DokSDB->close();
  delete m_DokSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::edit(TCustomClientDataSet *aCds)
{
 m_DS->DataSet = aCds;
 m_cds = aCds;
 m_DokSDB->open();
 onOpen();
 m_cds->Edit();

 ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::append(TCustomClientDataSet *aCds, msg::MagID *_Mag)
{
 m_DS->DataSet = aCds;
 m_cds = aCds;
 m_DokSDB->open();
 onOpen();
 m_cds->Append();
 m_cds->FieldByName("SYGNATURA")->AsString = _Mag->getSygnMag();
 m_cds->FieldByName("ID_DOKUM")->AsInteger = -1;
 m_cds->FieldByName("ROK")->AsInteger = _Mag->Rok;
 m_cds->FieldByName("DEPOZYT")->AsString = _Mag->Depozyt;
 m_cds->FieldByName("ID_KOMORKI")->AsInteger = _Mag->IdKomorki;
 m_cds->FieldByName("ID_MAG")->AsInteger = _Mag->IdMag;
 m_cds->FieldByName("DATA_WYST")->AsDateTime = Date();
 ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::onOpen(void)
{
;
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::bbCancelClick(TObject *Sender)
{
 m_cds->CancelUpdates();
 Close();
}
//---------------------------------------------------------------------------
int __fastcall T_DokWeFRM::newId(void)
{
	 mng::QueryDB q("SELECT MAX(D.ID_DOKUM) MX FROM PR_DOKUM  D INNER JOIN PR_KOMORKI K ON  K.ID_KOMORKI = D.ID_KOMORKI WHERE K.ID_WYDZIALU = (SELECT K1.ID_WYDZIALU FROM PR_KOMORKI K1 WHERE K1.ID_KOMORKI =:ID_KOMORKI)");
	 q.paramByName("ID_KOMORKI")->AsInteger =m_cds->FieldByName("ID_KOMORKI")->AsInteger;
	 q.open();
	 int id = q.fieldByName("MX")->AsInteger +1;
	 q.close();

 return id;
}
//---------------------------------------------------------------------------
bool __fastcall T_DokWeFRM::valid(TDataSet* _DS)
{
 bool _Res(true);
 if(_DS->FieldByName("SYGNATURA")->IsNull)
 {
   ShowMessage("Podaj sygnaturê!");
   _Res = false;
 }
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::bbWriteClick(TObject *Sender)
{
 if(m_cds->FieldByName("ID_DOKUM")->AsInteger == -1)
 {
   m_cds->FieldByName("ID_DOKUM")->AsInteger = newId();
 }
 if(valid(m_cds))
 {
  m_cds->ApplyUpdates(0);
  if(!m_IsPrint) Close();
 }
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::m_DokCBKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
 if(Key == VK_DELETE && Shift.Contains(ssCtrl)) m_cds->FieldByName("ID_SLO_DOK")->Clear();
}
//---------------------------------------------------------------------------
void __fastcall T_DokWeFRM::m_PrintBBClick(TObject *Sender)
{
 m_IsPrint = true;
 bbWriteClick(Sender);
 if(onPrint) onPrint(Sender);
  m_IsPrint =false;
  bbCancel->Visible = false;
  bbWrite->Caption ="Zamknij";
}
//---------------------------------------------------------------------------


void __fastcall T_DokWeFRM::m_DokDSDataChange(TObject *Sender, TField *Field)
{
  bbCancel->Visible = true;
  bbWrite->Caption ="Zapisz";
}
//---------------------------------------------------------------------------


void __fastcall T_DokWeFRM::FormShow(TObject *Sender)
{
 m_DokDSDataChange(m_DokDS,NULL);
}
//---------------------------------------------------------------------------

