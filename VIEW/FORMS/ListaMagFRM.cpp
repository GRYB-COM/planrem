//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ListaMagFRM.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ListaMAGFRA"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace finders;

//---------------------------------------------------------------------------
__fastcall T_ListaMagFRM::T_ListaMagFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_ListaMagFRA->m_AG->OnDblClick  = m_AGDblClick;
}
//---------------------------------------------------------------------------
__fastcall T_ListaMagFRM::~T_ListaMagFRM(void)
{
}
//---------------------------------------------------------------------------
T_ListaMAGFRA::Pars __fastcall T_ListaMagFRM::getPars(void)
{
 return m_ListaMagFRA->getPars();
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::setPars(const T_ListaMAGFRA::Pars& _Pars)
{
 m_ListaMagFRA->setPars(_Pars);
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::setSearchClictEvet(TNotifyEvent Event)
{
 m_ListaMagFRA->setSearchClickEvent(Event);
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::setDataSet(TDataSet* _DataSet)
{
 m_ListaMagFRA->setDataSet(_DataSet);
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::FormShow(TObject *Sender)
{

 m_OKBT->Enabled = m_ListaMagFRA->m_DS->DataSet && m_ListaMagFRA->m_DS->DataSet->RecordCount >0;
 m_ListaMagFRA->open();
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::m_AGDblClick(TObject *Sender)
{
 if(m_OKBT->Enabled) m_OKBTClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall T_ListaMagFRM::m_OKBTClick(TObject *Sender)
{
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall T_ListaMagFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_ListaMagFRA->close();
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMagFRM::setIsFilter(const bool _IsFilter)
{
  m_ListaMagFRA->setIsFilter(_IsFilter);
}
