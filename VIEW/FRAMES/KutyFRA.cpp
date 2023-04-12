//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KutyFRA.h"
#include "KUTReader.h"
#include "KUTFRM.h"
#include <memory>
#include "iswzorce62.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
mng::QueryDB*  T_KutyFRA::m_PrintQDB(NULL);
//---------------------------------------------------------------------------
__fastcall T_KutyFRA::T_KutyFRA(TComponent* Owner)
	: TFrame(Owner)
{
 m_Reader = new readers::KUTReader();
  m_DS->DataSet = m_Reader->getDataSet();
}
//---------------------------------------------------------------------------
__fastcall T_KutyFRA::~T_KutyFRA()
{
  delete m_Reader;
}
//---------------------------------------------------------------------------
 void __fastcall T_KutyFRA::open(const msg::MagID& _IdMag)
{
 m_MagID = _IdMag;
 m_Reader->open(_IdMag);
 m_ZlecMain = m_Reader->getMainKUT();
 Visible = true;
}
// ---------------------------------------------------------------------------
void __fastcall T_KutyFRA::close(void)
{
 Visible = false;
 m_ZlecMain.IsDefined = false;
 m_Reader->close();
}
// ---------------------------------------------------------------------------
void __fastcall T_KutyFRA::m_NewBTClick(TObject *Sender)
{
  std::auto_ptr<T_KUTFRM>_F(new T_KUTFRM(NULL));
  _F->Caption = "Nowy KUT";
  msg::ZlecID _ZlecID;
  _F->show(_ZlecID,m_MagID,m_ZlecMain);
  open(m_MagID);

}
//---------------------------------------------------------------------------


void __fastcall T_KutyFRA::m_EditBTClick(TObject *Sender)
{
  std::auto_ptr<T_KUTFRM>_F(new T_KUTFRM(NULL));
  _F->Caption = "Edycja KUT-a";
  msg::ZlecID _ZlecID;
  _ZlecID.fillFromDS(m_Reader->getDataSet());
  _F->show(_ZlecID,m_MagID,m_ZlecMain);
  open(m_MagID);
}
//---------------------------------------------------------------------------
 const AnsiString T_KutyFRA::M_PRINTER_SQL(" \
SELECT K.KOD AS KOD_WARSZTATU, REM.KOD_REM, Z.DATA_PROP_ZAK,  M.ILOSC AS ILOSC_DOST, \
KU.*, Z.*, M.*, S.NAZWA AS NAZ_SPRZETU, J.*,  K.NAZWA AS NAZ_WARSZTATU  \
FROM PR_ZLECENIA Z   \
LEFT OUTER JOIN PR_MAGAZYN     M   ON M.ROK = Z.ROK_MAG AND M.ID_KOMORKI = Z.ID_KOMORKI_GLW AND M.ID_MAG = Z.ID_MAG AND M.DEPOZYT =Z.DEPOZYT  \
LEFT OUTER JOIN PR_SPRZET      S   ON S.ID_SPRZETU = z.ID_SPRZETU \
LEFT OUTER JOIN PR_JEDNOSTKI   J   ON J.ID_JEDNOSTKI = Z.ID_JEDNOSTKI  \
LEFT OUTER JOIN PR_KOMORKI     K   ON K.ID_KOMORKI = Z.ID_KOMORKI  \
LEFT OUTER JOIN PR_HARMONOGRAM HA  ON HA.ROK = Z.ROK AND HA.ID_HARMONOGRAMU = Z.ID_HARM \
LEFT OUTER JOIN PR_REMONTY     REM ON REM.ID_REMONTU   = M.ID_REMONTU \
LEFT OUTER JOIN PR_KODY_USLUG  KU  ON KU.ID_USLUGI = HA.ID_USLUGI   \
WHERE Z.ROK = :ROK AND Z.ID_ZLECENIA =:ID_ZLECENIA  AND Z.ID_KOMORKI = :ID_KOMORKI\
");

//---------------------------------------------------------------------------
 const AnsiString T_KutyFRA::M_WYDANIE_SQL(" \
 UPDATE  PR_ZLECENIA Z  SET WYDANY ='T'\
 WHERE Z.ROK = :ROK AND Z.ID_ZLECENIA =:ID_ZLECENIA  AND Z.ID_KOMORKI = :ID_KOMORKI\
");

//---------------------------------------------------------------------------
void __fastcall T_KutyFRA::m_PrintBTClick(TObject *Sender)
{
  msg::ZlecID _ZlecID;
  AnsiString _Path, _KUTTyp, _KUTTpl;
  _ZlecID.fillFromDS(m_Reader->getDataSet());
  ptr::Pattern _Pat;
 _Pat.setEditMacroFlag(false);
 _Pat.regMacro("@get", getMacroZlec, "Pole z bazy");
 mng::QueryDB _Q(M_PRINTER_SQL);
 m_PrintQDB = &_Q;
 _Q.paramByName("ROK")->AsInteger         = _ZlecID.Rok;
 _Q.paramByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
 _Q.paramByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
 _Q.open();
 if(m_MagID.Depozyt =="S" && _ZlecID.NrKol == 0)
 {
  _KUTTyp ="Wzorzec KUTa - notatki serwisowej";
  _KUTTpl ="KUT-SERW.dcp";
 }
 else if(_ZlecID.NrKol >0)
 {
  _KUTTyp ="Wzorzec KUTa - polecenia kooperacji";
  _KUTTpl ="KUT-KOOP.dcp";
 }
 else
 {
  _KUTTyp ="Wzorzec KUTa";
  _KUTTpl ="KUT.dcp";
 }

 _Path =ExtractFileDir(Application->ExeName) ;
 _Path += "\\WZORCE\\";
 _Path += jbutils::TMyIni().ReadIniString("WZORCE",_KUTTyp,_KUTTpl);
_Pat.setPattern(_Path);
_Pat.edit();
 _Q.close();
 m_PrintQDB = NULL;
 bool _Wyd = m_Reader->getDataSet()->FieldByName("WYDANY")->AsString =="T";
 if( !_Wyd && mng::MessageDialog::question("Czy oznaczyæ wydrukowany KUT jako wydany?","POTWIERDZENIE",MB_YESNO) == IDYES)
 {
  msg::ZlecID _ZlecID;
  _ZlecID.fillFromDS(m_Reader->getDataSet());
  mng::QueryDB _Q(M_WYDANIE_SQL);
  _Q.paramByName("ROK")->AsInteger         = _ZlecID.Rok;
  _Q.paramByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
  _Q.paramByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
  _Q.execute();
  open(m_MagID);

 }
}
//---------------------------------------------------------------------------
const AnsiString T_KutyFRA::M_ILOSC_SQL("\
select \
	coalesce(m.ILOSC,0) - coalesce(sum(case when r.ROK < :ROK_ZLEC then r.ILOSC else 0 end),0) AS ILOSC \
from PR_MAGAZYN m  \
left join PR_ZLECENIA z \
	on z.ID_MAG = m.ID_MAG and z.ROK_MAG=m.ROK and z.ID_KOMORKI_GLW = m.ID_KOMORKI and z.DEPOZYT = m.DEPOZYT and z.NR_KOL= 0 \
left join PR_ZLECENIA_RBH r \
	on r.ID_ZLECENIA = z.ID_ZLECENIA and r.ROK = z.ROK and r.ID_KOMORKI = z.ID_KOMORKI \
where \
	m.ID_MAG =:ID_MAG and \
	m.ID_KOMORKI = :ID_KOMORKI and \
	m.ROK = :ROK and \
	m.DEPOZYT = :DEPOZYT  \
group by  \
	m.ILOSC \
");
//---------------------------------------------------------------------------
AnsiString getIlosc(AnsiString Arg)
{
  AnsiString _Res;
 if(T_KutyFRA::m_PrintQDB)
 {
  mng::QueryDB _Q(T_KutyFRA::M_ILOSC_SQL);
  _Q.paramByName("ID_MAG")->AsInteger      = T_KutyFRA::m_PrintQDB->fieldByName("ID_MAG")->AsInteger;
  _Q.paramByName("ID_KOMORKI")->AsInteger  = T_KutyFRA::m_PrintQDB->fieldByName("ID_KOMORKI_GLW")->AsInteger;
  _Q.paramByName("ROK")->AsInteger         = T_KutyFRA::m_PrintQDB->fieldByName("ROK_MAG")->AsInteger;
  _Q.paramByName("DEPOZYT")->AsString      = T_KutyFRA::m_PrintQDB->fieldByName("DEPOZYT")->AsString;
  _Q.paramByName("ROK_ZLEC")->AsInteger    = T_KutyFRA::m_PrintQDB->paramByName("ROK")->AsInteger;
  _Q.open();
  _Res =_Q.fieldByName("ILOSC")->AsAnsiString;
  _Q.close();
 }
 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getMacroZlec(AnsiString _FieldName)
{
 AnsiString _Res;
 if(T_KutyFRA::m_PrintQDB)
 {
  if(_FieldName.UpperCase() =="ILOSC") _Res = getIlosc(_FieldName);
  else  _Res =T_KutyFRA::m_PrintQDB->fieldByName(_FieldName.UpperCase())->AsAnsiString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
 const AnsiString T_KutyFRA::M_DEL_SQL(" \
 DELETE FROM PR_ZLECENIA Z \
 WHERE Z.ROK = :ROK AND Z.ID_ZLECENIA =:ID_ZLECENIA  AND Z.ID_KOMORKI = :ID_KOMORKI\
");
//---------------------------------------------------------------------------
 const AnsiString T_KutyFRA::M_DEL_WARNING("Operacja usuniêcia karty jest operacj¹ nieodwracaln¹.\nCzy kontynuowaæ?");
//---------------------------------------------------------------------------
void __fastcall T_KutyFRA::m_DelBTClick(TObject *Sender)
{
 if(mng::MessageDialog::warning(M_DEL_WARNING,"OSTRZE¯ENIE!",MB_YESNO)==IDYES)
 {
  msg::ZlecID _ZlecID;
  _ZlecID.fillFromDS(m_Reader->getDataSet());
  mng::QueryDB _Q(M_DEL_SQL);
  _Q.paramByName("ROK")->AsInteger         = _ZlecID.Rok;
  _Q.paramByName("ID_KOMORKI")->AsInteger  = _ZlecID.IdKomorki;
  _Q.paramByName("ID_ZLECENIA")->AsInteger = _ZlecID.IdZlecenia;
  _Q.execute();
  open(m_MagID);
 }
}
//---------------------------------------------------------------------------

