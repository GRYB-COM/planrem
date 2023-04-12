//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "SlWarFRM.h"
#include "MANAGER\queries.h"
#include "MANAGER\stream_db.h"
#include "SlWarEdFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "SlEditFRM"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlWarFRM::T_SlWarFRM(TComponent* Owner)
	: T_SlEditFRM(Owner)
{
 m_WarEdFRM = new T_SlWarEdFRM(NULL);
 m_WarEdFRM->m_DS->DataSet = m_SDB->getClient();
 m_EditFRM = m_WarEdFRM;
}
//---------------------------------------------------------------------------
__fastcall T_SlWarFRM::~T_SlWarFRM(void)
{
 delete m_WarEdFRM;
}
//---------------------------------------------------------------------------
void __fastcall T_SlWarFRM::onShow(void)
{
 mng::Query _Q("PR_KOMORKI", " *" );
 _Q.setOrderList(" KOD ");
 m_SDB->setQuery(_Q);
}



