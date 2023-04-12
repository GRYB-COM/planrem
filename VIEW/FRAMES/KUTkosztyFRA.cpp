//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KUTkosztyFRA.h"
#include "isManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "manager\utils_db.h"
#include "manager\grid_drawer.h"
#include "ZlecID.h"
#include "KUTkosztyEdFRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothButton"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_KUTkosztyFRA::T_KUTkosztyFRA(TComponent* Owner)
	: TFrame(Owner),m_idKosztow(-1)
{
  m_QDB = new mng::QueryDB();
  m_QDB->setQuery(" SELECT PR_KOSZTY.*,PR_SLOW_KOSZTOW.KOD,PR_SLOW_KOSZTOW.NAZWA \
	 FROM PR_KOSZTY,PR_SLOW_KOSZTOW \
	 WHERE PR_KOSZTY.ID_ZLECENIA = :ID_ZLECENIA AND PR_KOSZTY.ID_KOMORKI = :ID_KOMORKI  AND PR_KOSZTY.ROK = :ROK \
		AND PR_KOSZTY.ID_SLOW_KOSZTOW = PR_SLOW_KOSZTOW.ID_SLOW_KOSZTOW " );
  dspKoszty->DataSet = m_QDB->getDataSet();
}
//---------------------------------------------------------------------------
__fastcall T_KUTkosztyFRA::~T_KUTkosztyFRA()
{
  cdsKoszty->Close();
  delete m_QDB;
}
//---------------------------------------------------------------------------
TDataSet * __fastcall T_KUTkosztyFRA::getDataSet(void)
{
  return cdsKoszty;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTkosztyFRA::show(const msg::ZlecID& _ZlecID)
{
 cdsKoszty->Close();
 m_QDB->paramByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
 m_QDB->paramByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
 m_QDB->paramByName("ROK")->AsInteger         = _ZlecID.Rok;
 cdsKoszty->Open();

 mng::UtilsDB::setNumericMask(cdsKoszty,"ILOSC","###,###,##0.00");
}
//---------------------------------------------------------------------------
void __fastcall T_KUTkosztyFRA::apply(msg::ZlecID* _ZlecID)
{
  if(_ZlecID != NULL)
  {
	 cdsKoszty->First();
	 //mng::QueryDB q;
	 while(!cdsKoszty->Eof)
	 {
	  cdsKoszty->Edit();
	  cdsKoszty->FieldByName("ID_ZLECENIA")->AsInteger = _ZlecID->IdZlecenia;
	  cdsKoszty->FieldByName("ID_KOMORKI")->AsInteger  = _ZlecID->IdKomorki;
	  cdsKoszty->FieldByName("ROK")->AsInteger         = _ZlecID->Rok;

	  /*if(cdsKoszty->FieldByName("ID_KOSZTU")->AsInteger <= -1)
	  {
		q.open("SELECT MAX(ID_KOSZTU), GEN_ID(PR_KOSZTY_GEN,1) ID FROM PR_KOSZTY ");
		cdsKoszty->FieldByName("ID_KOSZTU")->AsInteger = q.fieldByName("ID")->AsInteger;
		q.close();
	  } */

	  cdsKoszty->Post();
	  cdsKoszty->Next();
	 }
  }

  cdsKoszty->ApplyUpdates(0);
}
//---------------------------------------------------------------------------


void __fastcall T_KUTkosztyFRA::m_UsunBBClick(TObject *Sender)
{
 if(mng::MessageDialog::messageBox("Czy na pewno usun¹æ wybrany koszt?", "Pytanie", MB_ICONQUESTION | MB_YESNO) == ID_NO) return;;
 cdsKoszty->Delete();
 cdsKoszty->ApplyUpdates(0);
}
//---------------------------------------------------------------------------

void __fastcall T_KUTkosztyFRA::m_DodajBBClick(TObject *Sender)
{
 std::auto_ptr<T_KUTkosztyEdFRM> fm(new T_KUTkosztyEdFRM(this));

 int zlec(-1);
 int kom(-1);
 int rok(-1);
 if(!cdsKoszty->IsEmpty())
 {
	 zlec = cdsKoszty->FieldByName("ID_ZLECENIA")->AsInteger;
	 kom = cdsKoszty->FieldByName("ID_KOMORKI")->AsInteger ;
	 rok = cdsKoszty->FieldByName("ROK")->AsInteger        ;
 }

 cdsKoszty->Append();
 cdsKoszty->FieldByName("ID_KOSZTU")->AsInteger = m_idKosztow;
 --m_idKosztow;
 cdsKoszty->FieldByName("ID_ZLECENIA")->AsInteger = zlec;
 cdsKoszty->FieldByName("ID_KOMORKI")->AsInteger  = kom;
 cdsKoszty->FieldByName("ROK")->AsInteger         = rok;
 fm->edit(cdsKoszty);
}
//---------------------------------------------------------------------------

void __fastcall T_KUTkosztyFRA::m_EdytujBBClick(TObject *Sender)
{
 std::auto_ptr<T_KUTkosztyEdFRM> fm(new T_KUTkosztyEdFRM(this));
 cdsKoszty->Edit();
 fm->edit(cdsKoszty);
}
//---------------------------------------------------------------------------

void __fastcall T_KUTkosztyFRA::dspKosztyGetTableName(TObject *Sender, TDataSet *DataSet,
		  WideString &TableName)
{
  TableName = "PR_KOSZTY";
}
//---------------------------------------------------------------------------

void __fastcall T_KUTkosztyFRA::dspKosztyBeforeUpdateRecord(TObject *Sender, TDataSet *SourceDS,
          TCustomClientDataSet *DeltaDS, TUpdateKind UpdateKind, bool &Applied)

{
 TProviderFlags pf  = TProviderFlags();
 TProviderFlags pfu = TProviderFlags() << pfInUpdate;
 TProviderFlags pfw = TProviderFlags() << pfInUpdate << pfInWhere << pfInKey;


 for(int i = 0; i < DeltaDS->FieldCount; i++)
 {
		AnsiString fn = DeltaDS->Fields->Fields[i]->FieldName.UpperCase();
		if(fn == "ID_KOSZTU") DeltaDS->FieldByName(fn)->ProviderFlags = pfw;
		else if(fn == "KOD" || fn == "NAZWA") DeltaDS->FieldByName(fn)->ProviderFlags = pf;
		else DeltaDS->FieldByName(fn)->ProviderFlags = pfu;
 }
}
//---------------------------------------------------------------------------

