//---------------------------------------------------------------------------
#pragma hdrstop
#include "EksportToMdbCTRL.h"
#include "DMODS\AccessDM.h"
#include <Dialogs.hpp>
#include "MANAGER\stream_db.h"
#include "VIEW\WaitFRMFCD.h"
#include "MANAGER\message_dlg.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace eksportmdb;
//---------------------------------------------------------------------------
const AnsiString EksportToMdbCTRL::M_PLAN_SQL(" \
SELECT \
K.KOD AS WARSZTAT_WYKONUJACY, \
U.P_N AS P_N, \
H.ID_HARMONOGRAMU AS NR_HARM, \
R.KOD_REM AS RODZAJ_REM, \
S.NAZWA AS NAZ_SPRZETU, \
H.ZADANIE, \
H.NR_ZADANIA AS NUMER_SPRZETU,  \
J.JW,  \
J.MIEJSCOWOSC,   \
H.DATA_OD AS TERMIN,  \
H.DATA_DO AS TERMIN_ZAKONCZENIA,   \
S.INDEKS_MAT AS JIM,  \
H.NORMA_RBH AS PLAN_RBH,    \
SUM(D.ILOSC) AS ILOSC,  \
SUM(CASE WHEN D.MIESIAC BETWEEN 1 AND 3 THEN D.ILOSC END) AS I_KW, \
SUM(CASE WHEN D.MIESIAC BETWEEN 4 AND 6 THEN D.ILOSC END) AS II_KW, \
SUM(CASE WHEN D.MIESIAC BETWEEN 7 AND 9 THEN D.ILOSC END) AS III_KW,  \
SUM(CASE WHEN D.MIESIAC BETWEEN 10 AND 12 THEN D.ILOSC END) AS IV_KW   \
FROM PR_HARMONOGRAM H \
LEFT OUTER JOIN PR_KOMORKI         K ON K.ID_KOMORKI   = H.ID_KOMORKI \
LEFT OUTER JOIN PR_KODY_USLUG      U ON U.ID_USLUGI    = H.ID_USLUGI  \
LEFT OUTER JOIN PR_REMONTY         R ON R.ID_REMONTU   = H.ID_REMONTU  \
LEFT OUTER JOIN PR_SPRZET          S ON S.ID_SPRZETU   = H.ID_SPRZETU  \
LEFT OUTER JOIN PR_JEDNOSTKI       J ON J.ID_JEDNOSTKI = H.ID_JEDNOSTKI  \
LEFT OUTER JOIN PR_HARMONOGRAM_DET D ON D.ROK          = H.ROK AND D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU  \
WHERE H.ROK = :ROK   \
GROUP BY   \
K.KOD,U.P_N, H.ID_HARMONOGRAMU,R.KOD_REM,S.NAZWA,H.ZADANIE,H.NR_ZADANIA,   \
J.JW,J.MIEJSCOWOSC,H.DATA_OD,H.DATA_DO,S.INDEKS_MAT,H.NORMA_RBH  \
");
//---------------------------------------------------------------------------
EksportToMdbCTRL::EksportToMdbCTRL(void)
{
 m_OpenDLG  = new Dialogs::TOpenDialog(NULL);
 m_DM       = new importmdb::T_AccessDM(NULL);
 m_WaitFRM  = new importmdb::WaitFRMFCD();
 m_HarmSDB  = new mng::StreamDB();
 m_HarmSDB->setQuery(M_PLAN_SQL);
}
//---------------------------------------------------------------------------
EksportToMdbCTRL::~EksportToMdbCTRL(void)
{
 delete m_DM;
 delete m_OpenDLG;
 delete m_WaitFRM;
 delete m_HarmSDB;
}
//---------------------------------------------------------------------------
void EksportToMdbCTRL::run(void)
{
 if(setDBPath())
 {
  m_DM->m_PlanADO->Open();
  m_HarmSDB->paramByName("ROK")->AsInteger = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
  m_HarmSDB->open();
  addorupd();
  del();
  m_HarmSDB->close();
  m_DM->m_PlanADO->Close();
  mng::MessageDialog::information("Eksport planu przebieg³ prawid³owo","");
 }
}
//---------------------------------------------------------------------------
bool EksportToMdbCTRL::setDBPath(void)
{
 m_OpenDLG->Filter = "Pliki  (*.mdb)|*.mdb";
 bool _Res =m_OpenDLG->Execute();
 if(_Res)
 {
  m_DM->setDBPath(m_OpenDLG->FileName);
 }
 return _Res;
}
//---------------------------------------------------------------------------
void EksportToMdbCTRL::addorupd(void)
{
 m_HarmSDB->first();
 m_WaitFRM->display();
 m_WaitFRM->start(m_HarmSDB->getClient()->RecordCount);
 while(!m_HarmSDB->isEof())
 {
  m_WaitFRM->step(AnsiString("Przenoszenie: nr harmonogramu: ")+ m_HarmSDB->fieldByName("NR_HARM")->AsAnsiString);
  if(findHarm() ) m_DM->m_PlanADO->Edit();
  else
  {
   m_DM->m_PlanADO->Append();
   m_DM->m_PlanADO->FieldByName("Lp")->AsInteger = m_DM->m_PlanADO->RecordCount +1;
  }
  fillFields();
  m_DM->m_PlanADO->Post();
  m_HarmSDB->next();
 }
 m_WaitFRM->hide();
}
//---------------------------------------------------------------------------
bool EksportToMdbCTRL::findHarm(void)
{
 TLocateOptions _LOpt;
 bool _Res;
 _Res = m_DM->m_PlanADO->Locate("nr harm",m_HarmSDB->fieldByName("NR_HARM")->AsInteger,_LOpt);
 return _Res;
}
//---------------------------------------------------------------------------
void EksportToMdbCTRL::fillFields(void)
{

 m_DM->m_PlanADO->FieldByName("Warsztat wykonuj¹cy")->AsString  = m_HarmSDB->fieldByName("WARSZTAT_WYKONUJACY")->AsString;
 m_DM->m_PlanADO->FieldByName("P/N")->AsString                  = m_HarmSDB->fieldByName("P_N")->AsString;
 m_DM->m_PlanADO->FieldByName("Zadania")->AsString              = m_HarmSDB->fieldByName("P_N")->AsString;
 m_DM->m_PlanADO->FieldByName("nr harm")->AsString              = m_HarmSDB->fieldByName("NR_HARM")->AsInteger;
 m_DM->m_PlanADO->FieldByName("Nazwa sprzetu")->AsString        = getNazSprz();
 m_DM->m_PlanADO->FieldByName("Numer sprzêtu")->AsString        = m_HarmSDB->fieldByName("NUMER_SPRZETU")->AsString;
 m_DM->m_PlanADO->FieldByName("Dostawca")->AsString             = getDostawca();
 m_DM->m_PlanADO->FieldByName("Rodzaj rem")->AsString           = m_HarmSDB->fieldByName("RODZAJ_REM")->AsString;
 m_DM->m_PlanADO->FieldByName("iloœæ")->AsCurrency              = m_HarmSDB->fieldByName("ILOSC")->AsCurrency;
 m_DM->m_PlanADO->FieldByName("I kw")->AsCurrency               = m_HarmSDB->fieldByName("I_KW")->AsCurrency;
 m_DM->m_PlanADO->FieldByName("II kw")->AsCurrency              = m_HarmSDB->fieldByName("II_KW")->AsCurrency;
 m_DM->m_PlanADO->FieldByName("III kw")->AsCurrency             = m_HarmSDB->fieldByName("III_KW")->AsCurrency;
 m_DM->m_PlanADO->FieldByName("IV kw")->AsCurrency              = m_HarmSDB->fieldByName("IV_KW")->AsCurrency;
 m_DM->m_PlanADO->FieldByName("termin")->AsDateTime             = m_HarmSDB->fieldByName("TERMIN")->AsDateTime;
 m_DM->m_PlanADO->FieldByName("termin zakoñczenia")->AsDateTime = m_HarmSDB->fieldByName("TERMIN_ZAKONCZENIA")->AsDateTime;
 m_DM->m_PlanADO->FieldByName("JIM")->AsString                  = m_HarmSDB->fieldByName("JIM")->AsString;
 m_DM->m_PlanADO->FieldByName("warsztat")->AsString             = m_HarmSDB->fieldByName("WARSZTAT_WYKONUJACY")->AsString;
 m_DM->m_PlanADO->FieldByName("Plan rbh")->AsCurrency           = m_HarmSDB->fieldByName("PLAN_RBH")->AsCurrency;
}
//---------------------------------------------------------------------------
String EksportToMdbCTRL::getDostawca(void)
{
 String _Res  = m_HarmSDB->fieldByName("JW")->AsString;
		_Res += String(" ") + m_HarmSDB->fieldByName("MIEJSCOWOSC")->AsString;
 return _Res;
}
//---------------------------------------------------------------------------
String EksportToMdbCTRL::getNazSprz(void)
{
 String _Res  = m_HarmSDB->fieldByName("RODZAJ_REM")->AsString;
		_Res += String(" ") + m_HarmSDB->fieldByName("NAZ_SPRZETU")->AsString;
		_Res += String(" ") + m_HarmSDB->fieldByName("NUMER_SPRZETU")->AsString;
		_Res += String(" ") + m_HarmSDB->fieldByName("ZADANIE")->AsString;
 return _Res;
}

//---------------------------------------------------------------------------
void EksportToMdbCTRL::del(void)
{
 TDataSet * _Plan = m_DM->m_PlanADO;
 _Plan->First();
 m_WaitFRM->display();
  m_WaitFRM->start(_Plan->RecordCount);
 while(!_Plan->Eof)
 {
   int _IdHarm =_Plan->FieldByName("nr harm")->AsInteger;
  m_WaitFRM->step(AnsiString("Kontrola: nr harmonogramu: ")+ _Plan->FieldByName("nr harm")->AsAnsiString);
  if(!m_HarmSDB->locate("NR_HARM",_Plan->FieldByName("nr harm")->AsInteger))
  {

   _Plan->Delete();
  }
  _Plan->Next();
 }
  m_WaitFRM->hide();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
