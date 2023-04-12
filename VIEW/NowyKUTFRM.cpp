//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NowyKUTFRM.h"
#include "isManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "DBAdvSmoothDatePicker"
#pragma resource "*.dfm"
T_NowyKUTFRM *_NowyKUTFRM;
//---------------------------------------------------------------------------
__fastcall T_NowyKUTFRM::T_NowyKUTFRM(TComponent* Owner)
	: TForm(Owner)
{
  m_SDB = new mng::StreamDB;
  m_DS->DataSet = m_SDB->getClient();
  m_SDB->setQuery("SELECT * FROM PR_ZADANIA WHERE ID_MAG = :ID_MAG");
	m_WarsztatSDB = new mng::StreamDB;
  m_WarsztatDS->DataSet = m_WarsztatSDB->getClient();
  m_WarsztatSDB->setQuery("SELECT * FROM PR_KOMORKI");
}
//---------------------------------------------------------------------------
__fastcall T_NowyKUTFRM::~T_NowyKUTFRM()
{
  delete m_SDB;
  delete m_WarsztatSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_NowyKUTFRM::AdvSmoothButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall T_NowyKUTFRM::AdvSmoothButton1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void T_NowyKUTFRM::setIdMag(int _Id)
{
m_IdMag = _Id;
}
//---------------------------------------------------------------------------
void __fastcall T_NowyKUTFRM::FormShow(TObject *Sender)
{
m_SDB->paramByName("ID_MAG")->AsInteger = m_IdMag;
m_SDB->open();
m_WarsztatSDB->open();
}
//---------------------------------------------------------------------------

