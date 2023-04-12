//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AccessDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
__fastcall T_AccessDM::T_AccessDM(TComponent* Owner)
	: TDataModule(Owner),
      m_IdWydz(0)
{

}
//---------------------------------------------------------------------------
__fastcall T_AccessDM::~T_AccessDM(void)
{

}
//---------------------------------------------------------------------------
void __fastcall T_AccessDM::setDBPath(const String& _Path)
{
 m_DBPath = _Path;
 WideString _ConnStr("Provider=Microsoft.Jet.OLEDB.4.0;");
 _ConnStr += WideString("Data Source=") + _Path +WideString(";Persist Security Info=False");
 m_Conn->ConnectionString = _ConnStr;
}
//---------------------------------------------------------------------------
void __fastcall T_AccessDM::setIdWydz(const int _IdWydz)
{
 m_IdWydz = _IdWydz;
 m_MagazynADO->Parameters->ParamByName("ID_WYDZ")->Value  = _IdWydz;
 m_ZleceniaADO->Parameters->ParamByName("ID_WYDZ")->Value = _IdWydz;
 m_ZlecRbhADO->Parameters->ParamByName("ID_WYDZ")->Value   = _IdWydz;
}
//---------------------------------------------------------------------------
void __fastcall T_AccessDM::setRok(const int _Rok)
{
 m_Rok = _Rok;
}
//---------------------------------------------------------------------------

void __fastcall T_AccessDM::m_PlanADOAfterOpen(TDataSet *DataSet)
{
 DataSet->FieldByName("ROK")->OnGetText = m_PlanADOROKGetText;
}
//---------------------------------------------------------------------------


void __fastcall T_AccessDM::m_PlanADOAfterClose(TDataSet *DataSet)
{
 DataSet->AutoCalcFields = false;
  DataSet->OnCalcFields = NULL;

}
//---------------------------------------------------------------------------

void __fastcall T_AccessDM::m_PlanADOROKGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
 Text = m_Rok;
}
//---------------------------------------------------------------------------

