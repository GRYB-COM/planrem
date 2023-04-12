//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DelHarmFRM.h"
#include "MANAGER\query_db.h"
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGroupBox"
#pragma link "AdvOfficeButtons"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
T_DelHarmFRM::Pars::Pars(void)
 :NrMies(-1)
 {

 }
//---------------------------------------------------------------------------
__fastcall T_DelHarmFRM::T_DelHarmFRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall T_DelHarmFRM::display(const Pars& _Pars)
{
 m_Pars = _Pars;
 return ShowModal();
}
void __fastcall T_DelHarmFRM::m_DelBTClick(TObject *Sender)
{
 AnsiString _Mess("Operacja usuniêcia harmonogramu jest nieodwracalna!\nCZY KONTYNUOWAÆ?");
 if(mng::MessageDialog::question(_Mess,"UWAGA!!!",MB_YESNO) == IDYES)
 {
  mng::QueryDB _Q;
  AnsiString _SQL;
  switch(m_DelRG->ItemIndex)
  {
   case 0:
	 _SQL  = AnsiString("DELETE FROM PR_HARMONOGRAM H WHERE H.ID_HARMONOGRAMU = ");
	 _SQL += AnsiString(m_Pars.HarmId.NrHarm);
	 _SQL += AnsiString(" AND H.ROK = ") + AnsiString(m_Pars.HarmId.Rok);
   break;
   case 1:
	_SQL  = AnsiString("DELETE FROM PR_HARMONOGRAM_DET H WHERE H.ID_HARMONOGRAMU = ");
	_SQL += AnsiString(m_Pars.HarmId.NrHarm);
	_SQL += AnsiString(" AND H.ROK = ") + AnsiString(m_Pars.HarmId.Rok);
	_SQL += AnsiString(" AND H.MIESIAC = ") + AnsiString(m_Pars.NrMies);
   break;
  }
  _Q.execute(_SQL);
  ModalResult = mrOk;
 }
}
//---------------------------------------------------------------------------

