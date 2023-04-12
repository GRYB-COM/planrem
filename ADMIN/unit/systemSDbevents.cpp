//---------------------------------------------------------------------------


#pragma hdrstop

#include "systemSDbevents.h"
#include <manager\sys_id.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: SystemsSDB
**********/
//---------------------------------------------------------------------------

SystemsSDB::SystemsSDB()
: m_czyApplied(false)
{
}
//---------------------------------------------------------------------------

SystemsSDB::~SystemsSDB()
{
}
//---------------------------------------------------------------------------

void SystemsSDB::beforeUpdateRecord(mng::StreamDB* str_db, TDataSet* source, TCustomClientDataSet* delta, TUpdateKind upd_kind, bool& applied)
{
  if(upd_kind == ukInsert && m_czyApplied == true)
  {
//      m_tabMan->execute(ukModify, delta, true, false, m_trans);

      applied = true;
   }
}
//---------------------------------------------------------------------------

void SystemsSDB::SetApplied(bool p_app)
{
   m_czyApplied = p_app;
}
//---------------------------------------------------------------------------

