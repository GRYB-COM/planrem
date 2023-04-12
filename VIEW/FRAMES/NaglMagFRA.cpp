//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NaglMagFRA.h"
#include "MagNaglReader.h"
#include "MagID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma resource "*.dfm"
T_NaglMagFRA *_NaglMagFRA;
//---------------------------------------------------------------------------
__fastcall T_NaglMagFRA::T_NaglMagFRA(TComponent* Owner)
	: TFrame(Owner)
{
  m_Reader = new readers::MagNaglReader;
  m_DS->DataSet = m_Reader->getDataSet();
}
//---------------------------------------------------------------------------
__fastcall T_NaglMagFRA::~T_NaglMagFRA()
{
  delete m_Reader;
}
//---------------------------------------------------------------------------
void __fastcall T_NaglMagFRA::open(const msg::MagID & _Id)
{
 m_Reader->open(_Id);
}
// ---------------------------------------------------------------------------
void __fastcall T_NaglMagFRA::close(void)
{
 m_Reader->close();
}
// ---------------------------------------------------------------------------
int __fastcall T_NaglMagFRA::getIdHarm(void)
{
  int _IdHarm(-1);
  TDataSet* _DS = m_Reader->getDataSet();
  if(_DS->Active && !_DS->IsEmpty())
  {
   _IdHarm = _DS->FieldByName("ID_HARM")->AsInteger;
  }
 return _IdHarm;
}
// ---------------------------------------------------------------------------

