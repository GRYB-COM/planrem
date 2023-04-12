//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlStanFRM.h"
#include "SlStanEdFRM.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\queries.h"
#include "MANAGER\stream_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "SlEditFRM"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_SlStanFRM::T_SlStanFRM(TComponent* Owner)
	: T_SlEditFRM(Owner)
{
/* m_StanEdFRM = new T_SlStanEdFRM(NULL);
 m_StanEdFRM->m_DS->DataSet = m_SDB->getClient();
 m_EditFRM = m_StanEdFRM;*/
}
//---------------------------------------------------------------------------
__fastcall T_SlStanFRM::~T_SlStanFRM(void)
{
 //delete m_StanEdFRM;
}
//---------------------------------------------------------------------------
void __fastcall T_SlStanFRM::onShow(void)
{

 mng::Query _Q("PR_STANOWISKA", " *" );
 m_SDB->setQuery(_Q);
}
//---------------------------------------------------------------------------


void __fastcall T_SlStanFRM::m_DodajBBClick(TObject *Sender)
{
 T_SlEditFRM::m_DodajBBClick(Sender);
 m_SDB->fieldByName("ID_STANOWISKA")->AsInteger =-9999;
}
//---------------------------------------------------------------------------

