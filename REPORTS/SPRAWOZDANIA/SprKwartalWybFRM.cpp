//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SprKwartalWybFRM.h"
#include <DateUtils.hpp>
#include "JBUTILS\jb_ini_my.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FCSWYB"
#pragma link "PopupButton"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_SprKwartalWybFRM::T_SprKwartalWybFRM(TComponent* Owner)
	: T_FCUSTWYB(Owner)
{
 jbutils::TMyIni mi;
 edKomorka->Text = mi.ReadIniString("SPRAWOZDANIA", "komorka", "");
 edZalacznik->Text = mi.ReadIniString("SPRAWOZDANIA", "zalacznik", "");
 edRok->Text  = YearOf(Date());
 m_StronaED->Text= mi.ReadIniInteger("SPRAWOZDANIA", "Od strony", 1);
 m_SortRG->ItemIndex = 0;
}
//---------------------------------------------------------------------------
__fastcall T_SprKwartalWybFRM::~T_SprKwartalWybFRM()
{
 jbutils::TMyIni mi;
 mi.WriteIniString("SPRAWOZDANIA", "komorka", edKomorka->Text);
 mi.WriteIniString("SPRAWOZDANIA", "zalacznik", edZalacznik->Text);
 mi.WriteIniInteger("SPRAWOZDANIA","Od strony",StrToIntDef(m_StronaED->Text,1) );
}
//---------------------------------------------------------------------------
