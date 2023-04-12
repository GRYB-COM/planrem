//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindHarmFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ListaHarmFRA"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace finders;

//---------------------------------------------------------------------------
__fastcall T_FindHarmFRM::T_FindHarmFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_ListaHarmFRA->m_AG->OnDblClick  = m_AGDblClick;
}
//---------------------------------------------------------------------------
__fastcall T_FindHarmFRM::~T_FindHarmFRM(void)
{
}
//---------------------------------------------------------------------------
T_ListaHarmFRA::Pars __fastcall T_FindHarmFRM::getPars(void)
{
 return m_ListaHarmFRA->getPars();
}
// ---------------------------------------------------------------------------
void __fastcall T_FindHarmFRM::setPars(const T_ListaHarmFRA::Pars& _Pars)
{
 m_ListaHarmFRA->setPars(_Pars);
}
// ---------------------------------------------------------------------------
void __fastcall T_FindHarmFRM::setSearchClictEvet(TNotifyEvent Event)
{
 m_ListaHarmFRA->setSearchClickEvent(Event);
}
// ---------------------------------------------------------------------------
void __fastcall T_FindHarmFRM::setDataSet(TDataSet* _DataSet)
{
 m_ListaHarmFRA->setDataSet(_DataSet);
}
//---------------------------------------------------------------------------
void __fastcall T_FindHarmFRM::FormShow(TObject *Sender)
{

 m_ListaHarmFRA->open();
 m_OKBT->Enabled = m_ListaHarmFRA->m_DS->DataSet && m_ListaHarmFRA->m_DS->DataSet->RecordCount >0;
}
//---------------------------------------------------------------------------
void __fastcall T_FindHarmFRM::m_AGDblClick(TObject *Sender)
{
 if(m_OKBT->Enabled) m_OKBTClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall T_FindHarmFRM::m_OKBTClick(TObject *Sender)
{
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

