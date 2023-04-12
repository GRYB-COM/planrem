//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindProtFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ListaHarmFRA"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "ListaHarmFRA"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace finders;

//---------------------------------------------------------------------------
__fastcall T_FindProtFRM::T_FindProtFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_ListaProtFRA->m_AG->OnDblClick  = m_AGDblClick;
}
//---------------------------------------------------------------------------
__fastcall T_FindProtFRM::~T_FindProtFRM(void)
{
}
//---------------------------------------------------------------------------
T_ListaProtFRA::Pars __fastcall T_FindProtFRM::getPars(void)
{
 return m_ListaProtFRA->getPars();
}
// ---------------------------------------------------------------------------
void __fastcall T_FindProtFRM::setPars(const T_ListaProtFRA::Pars& _Pars)
{
 m_ListaProtFRA->setPars(_Pars);
}
// ---------------------------------------------------------------------------
void __fastcall T_FindProtFRM::setSearchClictEvet(TNotifyEvent Event)
{
 m_ListaProtFRA->setSearchClickEvent(Event);
}
// ---------------------------------------------------------------------------
void __fastcall T_FindProtFRM::setDataSet(TDataSet* _DataSet)
{
 m_ListaProtFRA->setDataSet(_DataSet);
}
//---------------------------------------------------------------------------
void __fastcall T_FindProtFRM::FormShow(TObject *Sender)
{

 m_ListaProtFRA->open();
 m_OKBT->Enabled = m_ListaProtFRA->m_DS->DataSet && m_ListaProtFRA->m_DS->DataSet->RecordCount >0;
}
//---------------------------------------------------------------------------
void __fastcall T_FindProtFRM::m_AGDblClick(TObject *Sender)
{
 if(m_OKBT->Enabled) m_OKBTClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall T_FindProtFRM::m_OKBTClick(TObject *Sender)
{
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

