//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DokFRA.h"
#include "DokWeFRM.h"
#include "manager\stream_db.h"
#include "manager\message_dlg.h"
#include <memory>
#include "iswzorce62.h"
#include "manager\query_db.h"
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
mng::QueryDB*  T_DokFRA::m_PrintQDB(NULL);
//---------------------------------------------------------------------------
__fastcall T_DokFRA::T_DokFRA(TComponent* Owner)
	: TFrame(Owner)
{
 m_SDB = new mng::StreamDB;
 m_DS->DataSet = m_SDB->getClient();
 m_SDB->setQuery("SELECT * FROM PR_DOKUM WHERE ROK =:ROK AND ID_KOMORKI = :ID_KOMORKI AND DEPOZYT = :DEPOZYT AND ID_MAG = :ID_MAG ");
}
//---------------------------------------------------------------------------
__fastcall T_DokFRA::~T_DokFRA(void)
{
  m_SDB->close();
  delete m_SDB;
}
//---------------------------------------------------------------------------
void __fastcall T_DokFRA::open(msg::MagID _Mag)
{
  m_MagID = _Mag;

  m_SDB->close();

  m_SDB->paramByName("ROK")->DataType        = ftInteger;
  m_SDB->paramByName("ID_KOMORKI")->DataType = ftInteger;
  m_SDB->paramByName("DEPOZYT")->DataType     = ftString;
  m_SDB->paramByName("ID_MAG")->DataType     = ftInteger;

  m_SDB->paramByName("ROK")->AsInteger        = _Mag.Rok;
  m_SDB->paramByName("ID_KOMORKI")->AsInteger = _Mag.IdKomorki;
  m_SDB->paramByName("DEPOZYT")->AsAnsiString     = _Mag.Depozyt;
  m_SDB->paramByName("ID_MAG")->AsInteger     = _Mag.IdMag;
  m_SDB->open();
  Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall T_DokFRA::m_DelBTClick(TObject *Sender)
{
 if(mng::MessageDialog::messageBox("Czy na pewno usun¹æ wybrany dokument?.", "Pytanie", MB_ICONQUESTION | MB_YESNO) == ID_NO) return;;
 m_SDB->erase();
 m_SDB->applyUpdates();
}
//---------------------------------------------------------------------------

void __fastcall T_DokFRA::m_NewBTClick(TObject *Sender)
{
 std::auto_ptr<T_DokWeFRM> fm(new T_DokWeFRM(this));
 fm->onPrint = m_PrintBTClick;
 fm->append(m_SDB->getClient(),&m_MagID);
}
//---------------------------------------------------------------------------

void __fastcall T_DokFRA::m_EditBTClick(TObject *Sender)
{
 std::auto_ptr<T_DokWeFRM> fm(new T_DokWeFRM(this));
 fm->onPrint = m_PrintBTClick;
 fm->edit(m_SDB->getClient());
}
//---------------------------------------------------------------------------
 void __fastcall T_DokFRA::close(void)
 {
  m_SDB->close();
  Visible = false;
 }
 const AnsiString T_DokFRA::M_PRINTER_SQL(" \
 SELECT D.*, S.*, M.*,J.*, KU.*, HA.*, K.*, SP.NAZWA AS NAZ_SPRZETU, R.KOD_REM, k.KOD as KOD_WAR    \
 FROM PR_DOKUM D INNER JOIN PR_SLOW_DOK S ON D.ID_SLOW_DOK = S.ID_SLOW_DOK  \
 INNER JOIN PR_MAGAZYN M ON M.ROK = D.ROK AND M.DEPOZYT  = D.DEPOZYT AND M.ID_KOMORKI = D.ID_KOMORKI AND M.ID_MAG = D.ID_MAG  \
 LEFT OUTER JOIN PR_SPRZET SP ON SP.ID_SPRZETU =M.ID_SPRZETU \
 LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = M.ID_JEDNOSTKI  \
 LEFT OUTER JOIN PR_REMONTY R ON R.ID_REMONTU = M.ID_REMONTU  \
 LEFT OUTER JOIN PR_HARMONOGRAM HA  ON HA.ROK = m.ROK AND HA.ID_HARMONOGRAMU = m.ID_HARM  \
 LEFT OUTER JOIN PR_KODY_USLUG  KU  ON KU.ID_USLUGI = HA.ID_USLUGI   \
 LEFT OUTER JOIN PR_KOMORKI     K   ON K.ID_KOMORKI = m.ID_KOMORKI  \
 WHERE D.ID_DOKUM = :ID_DOK  AND D.ID_KOMORKI = :ID_KOMORKI \
 ");
//---------------------------------------------------------------------------
void __fastcall T_DokFRA::m_PrintBTClick(TObject *Sender)
{
 ptr::Pattern _Pat;
 _Pat.regMacro("@get", getMacro, "Pole z bazy");
 _Pat.regMacro("@Zadanie", getZadanie, "Pole z bazy");
 _Pat.regMacro("@KUT", getKUT, "Sygnatura zlecenia");
 mng::QueryDB _Q(M_PRINTER_SQL);
 m_PrintQDB = &_Q;
 _Q.paramByName("ID_DOK")->AsInteger     = m_SDB->fieldByName("ID_DOKUM")->AsInteger;
 _Q.paramByName("ID_KOMORKI")->AsInteger = m_SDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.open();
 AnsiString _Path(ExtractFileDir(Application->ExeName));
 _Path += "\\WZORCE\\";
 _Path += _Q.fieldByName("WZORZEC")->AsString;
_Pat.setPattern(_Path);
_Pat.edit();
 _Q.close();
 m_PrintQDB = NULL;
}
//---------------------------------------------------------------------------
AnsiString getMacro(AnsiString _FieldName)
{
 AnsiString _Res;
 if(T_DokFRA::m_PrintQDB) _Res =T_DokFRA::m_PrintQDB->fieldByName(_FieldName)->AsAnsiString;
 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getZadanie(AnsiString _Par)
{
 AnsiString _Res;
 int _NrKol(_Par.ToIntDef(0));
 AnsiString _Sql(" SELECT Z.ZADANIE FROM PR_ZLECENIA Z WHERE ");
 _Sql+= AnsiString(" Z.ROK_MAG = ")  + T_DokFRA::m_PrintQDB->fieldByName("ROK")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.ID_KOMORKI = ")+ T_DokFRA::m_PrintQDB->fieldByName("ID_KOMORKI")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.ID_MAG = ")    + T_DokFRA::m_PrintQDB->fieldByName("ID_MAG")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.DEPOZYT =  '") + T_DokFRA::m_PrintQDB->fieldByName("DEPOZYT")->AsAnsiString+ AnsiString("' AND ");
 _Sql+=AnsiString(" Z.NR_KOL = ") + AnsiString(_NrKol);
 mng::QueryDB _Q(_Sql);
 _Q.open();
 _Res =_Q.fieldByName("ZADANIE")->AsAnsiString;
 _Q.close();
 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getKUT(AnsiString _Par)
{
 AnsiString _Res;
 int _NrKol(_Par.ToIntDef(0));
 AnsiString _Sql(" SELECT Z.SYGN_ZLECENIA FROM PR_ZLECENIA Z WHERE ");
 _Sql+= AnsiString(" Z.ROK_MAG = ")  + T_DokFRA::m_PrintQDB->fieldByName("ROK")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.ID_KOMORKI = ")+ T_DokFRA::m_PrintQDB->fieldByName("ID_KOMORKI")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.ID_MAG = ")    + T_DokFRA::m_PrintQDB->fieldByName("ID_MAG")->AsAnsiString + AnsiString(" AND ");
 _Sql+=AnsiString(" Z.DEPOZYT =  '") + T_DokFRA::m_PrintQDB->fieldByName("DEPOZYT")->AsAnsiString+ AnsiString("' AND ");
 _Sql+=AnsiString(" Z.NR_KOL = ") + AnsiString(_NrKol);
 mng::QueryDB _Q(_Sql);
 _Q.open();
 _Res =_Q.fieldByName("SYGN_ZLECENIA")->AsAnsiString;
 _Q.close();
 return _Res;
}
