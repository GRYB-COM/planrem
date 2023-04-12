//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PowDostFRM.h"
#include "iswzorce62.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include "MANAGER\message_dlg.h"
#include "isvaria\varia.h"
#include "JBUTILS\jb_ini_my.h"
#include "globfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma link "AdvCombo"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
T_PowDostFRM *TPDFRM;
//---------------------------------------------------------------------------
static AnsiString getMacroKodJW(AnsiString par)
{
  return TPDFRM->getKodJW();
}
//---------------------------------------------------------------------------
static AnsiString getMacroMiejscJW(AnsiString par)
{
  return TPDFRM->getMiejscJW();
}
//---------------------------------------------------------------------------
static AnsiString getMacroFaxJW(AnsiString par)
{
  return TPDFRM->getFaxJW();
}
//---------------------------------------------------------------------------
static AnsiString getMacroDataDost(AnsiString par)
{
 AnsiString _Res;
 if(TPDFRM->m_cbOkres->ItemIndex >0)
 {
  jbutils::TMyIni _Ini;
  int _Mies = 3 * TPDFRM->m_cbOkres->ItemIndex -2;
  AnsiString _Kwart("Kwarta³ ");
  _Kwart += TPDFRM->m_cbOkres->ItemIndex;
  TDateTime _D = _Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart, TDateTime(CurrentYear(),_Mies,1));
  _Res = DateToStr(_D);
 }
  return _Res;
}
//---------------------------------------------------------------------------
AnsiString getMacroListaSprz(AnsiString par)
{
  if (TPDFRM->getIdJW() >= 0)
  {
	mng::QueryDB qu("SELECT H.ID_HARMONOGRAMU, S.NAZWA AS NAZ_SPRZETU, H.NR_ZADANIA AS NR_SPRZETU, \
	SUM(HD.ILOSC) AS SUMA FROM PR_HARMONOGRAM H \
	INNER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU \
	INNER JOIN PR_HARMONOGRAM_DET HD ON HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND HD.ROK = H.ROK \
	WHERE H.ROK = :ROK AND HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO AND H.ID_JEDNOSTKI = :ID_JED AND (H.DATA_OD IS  NULL OR H.DATA_OD >= :DATA_OD ) \
	GROUP BY H.ID_HARMONOGRAMU, S.NAZWA, H.NR_ZADANIA");

	qu.paramByName("ROK")->AsInteger      = TPDFRM->getRok();
	qu.paramByName("MIES_OD")->AsInteger  = TPDFRM->getMiesOd();
	qu.paramByName("MIES_DO")->AsInteger  = TPDFRM->getMiesDo();
	qu.paramByName("ID_JED")->AsInteger   = TPDFRM->getIdJW();
	qu.paramByName("DATA_OD")->AsDateTime = TDateTime(TPDFRM->getRok(),1,1);

	qu.open();

	if (!qu.isEmpty())
	{
					   //          12                                      40                18
	  AnsiString res  = "Nr harm.    Nazwa sprzêtu                           Numer sprzêtu     Iloœæ\n";
				 res += "---------------------------------------------------------------------------\n";

	  while (!qu.isEof())
	  {
		res += PadRight(qu.fieldByName("ID_HARMONOGRAMU")->AsString, 12);
		res += PadRight(qu.fieldByName("NAZ_SPRZETU")->AsString, 40);
		res += PadRight(qu.fieldByName("NR_SPRZETU")->AsString, 18);
		res += qu.fieldByName("SUMA")->AsString;
		res += "\n";

		qu.next();
	  }
	  return res;
	}
	return "";
  }
  return "";
}
//---------------------------------------------------------------------------
static AnsiString getMacroListaSprzKw(AnsiString par)
{
 AnsiString _Res;
 if (TPDFRM->getIdJW() < 0) return _Res;
 int _AllLines(par.ToIntDef(0));
 int _Lines;
 AnsiString _Sql("\
 SELECT  distinct  \
	  CASE \
	   WHEN HD.MIESIAC BETWEEN 1 AND 3   THEN 1 \
	   WHEN HD.MIESIAC BETWEEN 4 AND 6   THEN 2 \
	   WHEN HD.MIESIAC BETWEEN 7 AND 9   THEN 3 \
	   WHEN HD.MIESIAC BETWEEN 10 AND 12 THEN 4  \
  END AS KWARTAL_LICZBA, \
	  CASE \
	   WHEN HD.MIESIAC BETWEEN 1 AND 3   THEN 1 \
	   WHEN HD.MIESIAC BETWEEN 4 AND 6   THEN 4 \
	   WHEN HD.MIESIAC BETWEEN 7 AND 9   THEN 7 \
	   WHEN HD.MIESIAC BETWEEN 10 AND 12 THEN 10 \
  END AS MIES_OD, \
  CASE   \
	   WHEN HD.MIESIAC BETWEEN 1 AND 3   THEN 3   \
	   WHEN HD.MIESIAC BETWEEN 4 AND 6   THEN 6 \
	   WHEN HD.MIESIAC BETWEEN 7 AND 9   THEN 9  \
	   WHEN HD.MIESIAC BETWEEN 10 AND 12 THEN 12  \
  END AS MIES_DO, \
  CASE  \
	   WHEN HD.MIESIAC BETWEEN 1 AND 3   THEN 'I'   \
	   WHEN HD.MIESIAC BETWEEN 4 AND 6   THEN 'II' \
	   WHEN HD.MIESIAC BETWEEN 7 AND 9   THEN 'III'  \
	   WHEN HD.MIESIAC BETWEEN 10 AND 12 THEN 'IV' \
  END \
  AS KWARTAL FROM PR_HARMONOGRAM H  \
	INNER JOIN PR_HARMONOGRAM_DET HD ON HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND HD.ROK = H.ROK   \
	WHERE H.ROK = :ROK AND HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO AND H.ID_JEDNOSTKI = :ID_JEDNOSTKI  \
	AND (H.DATA_OD IS  NULL OR H.DATA_OD >= :DATA_OD) \
 ");
 mng::QueryDB _Qu(_Sql);
 jbutils::TMyIni _Ini;
 const int _MiesOd = TPDFRM->getMiesOd();
 const int _MiesDo = TPDFRM->getMiesDo();
 int _NrKwart;
 const AnsiString _Kwart("Kwarta³ ");
 _Qu.paramByName("ROK")->AsInteger          =TPDFRM->getRok();
 _Qu.paramByName("MIES_OD")->AsInteger      =_MiesOd;
 _Qu.paramByName("MIES_DO")->AsInteger      =_MiesDo;
 _Qu.paramByName("ID_JEDNOSTKI")->AsInteger =TPDFRM->getIdJW();
 _Qu.paramByName("DATA_OD")->AsDateTime      = TDateTime(TPDFRM->getRok(),1,1);

 _Qu.open();
 while(!_Qu.isEof())
 {
  _Res += AnsiString("Sprzêt planowany do remontu w ") + _Qu.fieldByName("KWARTAL")->AsAnsiString.Trim() + AnsiString(" kwartale:\n");
  TPDFRM->setMiesOd(_Qu.fieldByName("MIES_OD")->AsInteger);
  TPDFRM->setMiesDo(_Qu.fieldByName("MIES_DO")->AsInteger);
  _Res += getMacroListaSprz(_Sql);
  _NrKwart = _Qu.fieldByName("KWARTAL_LICZBA")->AsInteger;
  _Res += AnsiString("Termin dostarczenia sprzêtu: ") + DateToStr(_Ini.ReadIniDateTime("POWIADOMIENIA",_Kwart + _NrKwart, TDateTime(CurrentYear(),12,15)));
  _Res += "\n\n";
  _Qu.next();
 }
  TPDFRM->setMiesOd(_MiesOd);
  TPDFRM->setMiesDo(_MiesDo);
  _Lines = Globfunc::countChar(_Res,'\n');
  for(int i= _Lines;i<=_AllLines;++i) _Res += "\n";
 return _Res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall T_PowDostFRM::T_PowDostFRM(TComponent* Owner) : TForm(Owner)
{
  TPDFRM = this;

  m_SDB = new mng::StreamDB();

  m_SDB->setQuery("SELECT J.ID_JEDNOSTKI, J.JW, J.MIEJSCOWOSC, J.FAX, \
	 J.JW ||' '|| J.MIEJSCOWOSC AS Jednostka, SUM(HD.ILOSC) AS CNT \
     FROM PR_JEDNOSTKI J \
     INNER JOIN PR_HARMONOGRAM H ON H.ID_JEDNOSTKI = J.ID_JEDNOSTKI \
     INNER JOIN PR_HARMONOGRAM_DET HD ON HD.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU AND HD.ROK = H.ROK \
	 WHERE H.ROK =:ROK AND HD.MIESIAC BETWEEN :MIES_OD AND :MIES_DO \
	 AND (H.DATA_OD IS  NULL OR H.DATA_OD > :DATA_OD) \
     GROUP BY J.ID_JEDNOSTKI, J.JW, J.MIEJSCOWOSC, J.FAX");

  m_DS->DataSet = m_SDB->getClient();

  m_miesOd = 0;
  m_miesDo = 0;
}
//---------------------------------------------------------------------------
__fastcall T_PowDostFRM::~T_PowDostFRM()
{
  delete m_SDB;
}
//---------------------------------------------------------------------------
void __fastcall T_PowDostFRM::m_SzukajClick(TObject *Sender)
{
  m_SDB->close();

  m_miesOd = 1;
  m_miesDo = 12;
  m_rok    = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());

  if (m_cbOkres->ItemIndex > 0)
  {
	m_miesDo = 3 * m_cbOkres->ItemIndex;
    m_miesOd = m_miesDo - 2;
  }

  m_SDB->paramByName("ROK")->AsInteger      = m_rok;
  m_SDB->paramByName("MIES_OD")->AsInteger  = m_miesOd;
  m_SDB->paramByName("MIES_DO")->AsInteger  = m_miesDo;
  m_SDB->paramByName("DATA_OD")->AsDateTime = TDateTime(m_rok,1,1);

  m_SDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_PowDostFRM::m_edFilterChange(TObject *Sender)
{
  m_SDB->setFiltered(false);

  if (!m_edFilter->Text.Trim().IsEmpty())
  {
    m_SDB->setFilter(String("UPPER(JEDNOSTKA) LIKE '%") + m_edFilter->Text.UpperCase() + String("%'"));
    m_SDB->setFiltered(true);
  }
  else
  {
    m_SDB->setFilter("");
  }
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_PowDostFRM::getKodJW()
{
  if(!m_SDB->isEmpty())
  {
    return m_SDB->fieldByName("JW")->AsString;
  }

  return "";
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_PowDostFRM::getMiejscJW()
{
  if(!m_SDB->isEmpty())
  {
    return m_SDB->fieldByName("MIEJSCOWOSC")->AsString;
  }

  return "";
}
//---------------------------------------------------------------------------
AnsiString __fastcall T_PowDostFRM::getFaxJW()
{
  if(!m_SDB->isEmpty())
  {
    return m_SDB->fieldByName("FAX")->AsString;
  }

  return "";
}
//---------------------------------------------------------------------------
int __fastcall T_PowDostFRM::getIdJW()
{
  if(!m_SDB->isEmpty())
  {
    return m_SDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
  }

  return -1;
}
//---------------------------------------------------------------------------
int __fastcall T_PowDostFRM::getMiesOd()
{
  return m_miesOd;
}
//---------------------------------------------------------------------------
int __fastcall T_PowDostFRM::getMiesDo()
{
  return m_miesDo;
}
//---------------------------------------------------------------------------
int __fastcall T_PowDostFRM::getRok()
{
  return m_rok;
}
//---------------------------------------------------------------------------
void __fastcall T_PowDostFRM::m_PrintSingleBBClick(TObject *Sender)
{
  ptr::Pattern pattern;
  pattern.setEditMacroFlag(false);
  pattern.regMacro("@KodJW",     getMacroKodJW,     "Kod jednostki");
  pattern.regMacro("@MiejscJW",  getMacroMiejscJW,  "Miejscowoœæ");
  pattern.regMacro("@FaxJW",     getMacroFaxJW,     "Numer faxu");
  pattern.regMacro("@ListaSprz", getMacroListaSprz, "Lista sprzêtu");
  pattern.regMacro("@ListaSprzKw", getMacroListaSprzKw, "Lista sprzêtu podzielona na kwarta³y");
  pattern.regMacro("@DataDost",  getMacroDataDost,  "Data dostarczenia");

  AnsiString path(ExtractFileDir(Application->ExeName));
  path += m_cbOkres->ItemIndex == 0 ?"\\WZORCE\\InfDost.dcp" :  "\\WZORCE\\PowDost.dcp";

  pattern.setPattern(path);
  pattern.setEditMacroFlag(false);
  Sender == m_PrintSingleBB ? pattern.edit() : pattern.print();
}
//---------------------------------------------------------------------------
void __fastcall T_PowDostFRM::bbWriteClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall T_PowDostFRM::m_PrintAlBBClick(TObject *Sender)
{
 m_SDB->first();
 while(!m_SDB->isEof())
 {
  m_PrintSingleBBClick(Sender);
  Sleep(1000);
  m_SDB->next();
 }
}
//---------------------------------------------------------------------------

