// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wi_SlZalEditFRM.h"
//#include "wi_iSlModel.h"
#include "isManager.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
T_SlZalEditFRM* _SlZalEditFRM;

// ---------------------------------------------------------------------------
__fastcall T_SlZalEditFRM::T_SlZalEditFRM(TComponent* Owner) : TForm(Owner)
{
}

// ---------------------------------------------------------------------------
__fastcall T_SlZalEditFRM::~T_SlZalEditFRM()
{
}

// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::m_CloseBBClick(TObject* Sender)
{
  try
  {
	// m_Model->applyUpdates();
	Close();
  }
  catch(...)
  {
	setEditEnable(false);
  }
}

// ---------------------------------------------------------------------------
void T_SlZalEditFRM::setModel(widict::iSlModel* _Model)
{
  m_Model = _Model;
 // m_DS->DataSet = m_Model->getDataSet();
}

// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::m_DodajBBClick(TObject* Sender)
{
  try
  {
  //	m_Model->append();
  //	m_Model->setNewIds();
	m_InsMode = true;
	setEditEnable(true);
	m_DodajBB->Enabled = false;
	m_EdytujBB->Enabled = false;
	m_UsunBB->Enabled = false;
	m_RokDBE->SetFocus();
  }
  catch(...)
  {
	setEditEnable(false);
  }
}

// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::m_EdytujBBClick(TObject* Sender)
{
  try
  {
  //	m_Model->edit();
	m_InsMode = false;
	setEditEnable(true);
	m_DodajBB->Enabled = false;
	m_EdytujBB->Enabled = false;
	m_RokDBE->Enabled = false;
	m_UsunBB->Enabled = false;
	m_WartoscDBE->SetFocus();
  }
  catch(...)
  {
	setEditEnable(false);
  }
}

// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::m_ZatwierdzBBClick(TObject* Sender)
{
  try
  {
	if(m_InsMode)
	{
	  // m_Model->setNewIds();
   //	  m_Model->post();
	}
	else
	{
  //	  m_Model->post();
	}
	m_DodajBB->Enabled = true;
	m_EdytujBB->Enabled = true;
	m_ZatwierdzBB->Enabled = false;
   //	m_Model->applyUpdates();
	setEditEnable(false);
  }
  catch(...)
  {
  //	mng::MessageDialog::messageBox("Niemo¿na wprowadziæ dwa razy tego samego roku! \n WprowadŸ inny rok.", "Informacja", MB_ICONINFORMATION | MB_OK);
	// setEditEnable(false);
	// m_Model->refresh();
	m_RokDBE->SetFocus();
  }
}

// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::BitBtn1Click(TObject* Sender)
{
 // m_Model->cancelUpdates();
  Close();
}

// ---------------------------------------------------------------------------
void T_SlZalEditFRM::setEditEnable(bool _Enable)
{
  m_WartoscTL->Enabled = _Enable;
  m_WartoscDBE->Enabled = _Enable;
  m_RokTL->Enabled = _Enable;
  m_RokDBE->Enabled = _Enable;
}
// ---------------------------------------------------------------------------

void __fastcall T_SlZalEditFRM::m_DSDataChange(TObject* Sender, TField* Field)
{
  if(m_DS->DataSet->IsEmpty())
  {
	m_EdytujBB->Enabled = false;
	m_UsunBB->Enabled = false;
  }

}
// ---------------------------------------------------------------------------

void __fastcall T_SlZalEditFRM::m_DBGTitleClick(TColumn* Column)
{;
}
// ---------------------------------------------------------------------------

void __fastcall T_SlZalEditFRM::m_RokDBEKeyUp(TObject* Sender, WORD& Key, TShiftState Shift)

{
  if(m_RokDBE->Text != "")
  {
	if(m_WartoscDBE->Text == "" && m_WartoscDBE->Visible == true)
	{
	  m_ZatwierdzBB->Enabled = false;
	}
	else
	{
	  m_ZatwierdzBB->Enabled = true;
	}
  }
  else
  {
	m_ZatwierdzBB->Enabled = false;
  }

  if(Key == VK_RETURN)
  {
	if(m_RokDBE->Text != "")
	{
	  if(m_WartoscDBE->Text == "" && m_WartoscDBE->Visible == true)
	  {
		m_ZatwierdzBB->Enabled = false;
		m_WartoscDBE->SetFocus();
	  }
	  else
	  {
		m_ZatwierdzBB->Enabled = true;
		m_ZatwierdzBB->SetFocus();
	  }
	}
	else
	{
	  m_ZatwierdzBB->Enabled = false;
	}
  }
}
// ---------------------------------------------------------------------------
void __fastcall T_SlZalEditFRM::m_UsunBBClick(TObject *Sender)
{
  try
  {
 //	m_Model->erase();
	m_InsMode = false;
	setEditEnable(false);
	m_DodajBB->Enabled = false;
	m_EdytujBB->Enabled = false;
	m_RokDBE->Enabled = false;
	m_ZatwierdzBB->Enabled = true;
	m_ZatwierdzBB->SetFocus();
  }
  catch(...)
  {
	setEditEnable(false);
  }
}
//---------------------------------------------------------------------------

