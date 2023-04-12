//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlEtatyEditFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SL_EDIT_FRM"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlEtatyEditFRM::T_SlEtatyEditFRM(TComponent* Owner) : T_SL_EDIT_FRM(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall T_SlEtatyEditFRM::~T_SlEtatyEditFRM(void)
{
}
//---------------------------------------------------------------------------

void __fastcall T_SlEtatyEditFRM::FormShow(TObject *Sender)
{
 m_DataOdDCP->SetFocus();
}
//---------------------------------------------------------------------------

