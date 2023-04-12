#pragma hdrstop
#include "PowiadEditor.h"
#include "IWaitForm.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include <dateutils.hpp>
#include "printer62\PrinterIS.h"
#include "IsWzorce62.h"
#include "JBUTILS\jb_ini_my.h"
#include <SysUtils.hpp>
#include "isvaria.h"
#include "MANAGER\transaction_db.h"
#include "MANAGER\message_dlg.h"
#include <memory>
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace editors;
//---------------------------------------------------------------------------
const String PowiadEditor::M_MAGAZYN_SQL("\
SELECT M.DEPOZYT, M.SYGN_MAG, M.ID_MAG, M.ID_SPRZETU, M.ID_HARM, M.UWAGI, M.ILOSC, M.DATA_PRZEKAZ, M.STATUS, M.DATA_PRZYJ, M.NR_FABR, M.PODSTAWA, M.ID_JEDNOSTKI, \
M.NR_HARM, M.ID_REMONTU, M.KOD_WARSZTATU, M.NR_REJ, M.ID_KOMORKI, M.GLOWNY_KUT, M.ROK, M.NR_MAG, M.PROT_PRZEKAZ, M.PROT_PRZYJ, M.DATA_PROP_ZAK, M.DATA_ZAK,  \
K.ID_WYDZIALU, MAX(PW.NR_KOL) AS NR_KOL  \
FROM PR_MAGAZYN M \
LEFT OUTER JOIN PR_POWIAD2MAGAZYN P ON P.ROK =M.ROK AND P.DEPOZYT = M.DEPOZYT AND P.ID_KOMORKI = M.ID_KOMORKI AND P.ID_MAG =M.ID_MAG \
LEFT OUTER JOIN PR_POWIAD PW ON PW.ID_POWIAD = P.ID_POWIAD \
LEFT OUTER JOIN PR_KOMORKI K ON  K.ID_KOMORKI = M.ID_KOMORKI \
");
const String PowiadEditor::M_MAGAZYN_GROUP_SQL("\
GROUP BY  M.DEPOZYT, M.SYGN_MAG, M.ID_MAG, M.ID_SPRZETU, M.ID_HARM, M.UWAGI, M.ILOSC, M.DATA_PRZEKAZ, M.STATUS, M.DATA_PRZYJ, M.NR_FABR, M.PODSTAWA, M.ID_JEDNOSTKI, \
M.NR_HARM, M.ID_REMONTU, M.KOD_WARSZTATU, M.NR_REJ, M.ID_KOMORKI, M.GLOWNY_KUT, M.ROK, M.NR_MAG, M.PROT_PRZEKAZ, M.PROT_PRZYJ, M.DATA_PROP_ZAK, M.DATA_ZAK, K.ID_WYDZIALU  \
");
const String PowiadEditor::M_MASTER_READ_SQL("SELECT P.*, J.JW, J.NAZWA AS NAZ_JEDNOSTKI, J.MIEJSCOWOSC, j.FAX FROM PR_POWIAD P INNER JOIN PR_JEDNOSTKI J ON P.ID_JEDNOSTKI = J.ID_JEDNOSTKI WHERE ID_SESJI = :ID_SESJI");
const String PowiadEditor::M_DETAILS_READ_SQL("SELECT M.*, S.NAZWA AS NAZ_SPRZETU  FROM PR_POWIAD2MAGAZYN P \
INNER JOIN PR_MAGAZYN M ON M.DEPOZYT = P.DEPOZYT AND M.ROK = P.ROK AND M.ID_KOMORKI = P.ID_KOMORKI AND M.ID_MAG = P.ID_MAG \
INNER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
WHERE P.ID_POWIAD = :ID_POWIAD AND P.ROK_POW = :ROK AND P.ID_WYDZIALU = :ID_WYDZIALU");
const String PowiadEditor::M_MASTER_INS_SQL("SELECT * FROM PR_POWIAD WHERE ID_POWIAD = -1");
const String PowiadEditor::M_DETAILS_INS_SQL("SELECT P.* FROM PR_POWIAD2MAGAZYN P WHERE P.ID_POWIAD2MAGAZ  = - 1");
//---------------------------------------------------------------------------
const String PowiadEditor::M_READ_SQL("\
SELECT  cast('today' as date)  AS DATA_WYST, J.JW ||' ' || J.MIEJSCOWOSC AS JW_MIEJSC, J.ID_JEDNOSTKI, \
SUM(M.ILOSC) AS ILOSC, \
J.JW, J.NAZWA AS NAZ_JEDNOSTKI, J.MIEJSCOWOSC  \
FROM PR_JEDNOSTKI J INNER JOIN PR_MAGAZYN M ON M.ID_JEDNOSTKI = J.ID_JEDNOSTKI   \
");
//---------------------------------------------------------------------------
const String PowiadEditor::M_READ_WEZW_SQL("\
SELECT P.id_sesji, P.DATA_WYST, J.JW || ' ' || J.MIEJSCOWOSC AS JW_MIEJSC, SUM(M.ILOSC)  AS ILOSC \
FROM PR_POWIAD P \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = P.ID_JEDNOSTKI \
LEFT OUTER JOIN PR_POWIAD2MAGAZYN PM ON PM.ROK_POW = P.ROK AND PM.ID_POWIAD = P.ID_POWIAD \
LEFT OUTER JOIN PR_MAGAZYN M ON M.ID_KOMORKI = PM.ID_KOMORKI AND M.ID_MAG = PM.ID_MAG AND M.ROK = PM.ROK AND M.DEPOZYT = PM.DEPOZYT \
WHERE P.ROK =:ROK AND P.DATA_WYST BETWEEN :DATA_OD AND :DATA_DO AND P.NR_KOL =:NR_KOL \
GROUP BY P.ID_SESJI,P.DATA_WYST, J.JW, J.MIEJSCOWOSC \
");
//---------------------------------------------------------------------------
const String PowiadEditor::M_READ_BP_WHERE_SQL("\
WHERE (M.DATA_ZAK >'1899-12-30' AND  M.DATA_ZAK <=:DATA_DO)  AND   (M.DATA_PRZEKAZ IS NULL  OR DATA_PRZEKAZ = '1899-12-30') AND NOT EXISTS    \
(    \
 SELECT null    \
 FROM PR_POWIAD P INNER JOIN PR_POWIAD2MAGAZYN PM ON PM.ID_WYDZIALU= P.ID_WYDZIALU AND PM.ROK_POW =P.ROK AND PM.ID_POWIAD=P.ID_POWIAD  \
 WHERE PM.ROK = M.ROK AND PM.ID_KOMORKI = M.ID_KOMORKI AND PM.DEPOZYT = M.DEPOZYT AND PM.ID_MAG = M.ID_MAG   \
)  \
");
//---------------------------------------------------------------------------
const String PowiadEditor::M_READ_GROUP_SQL("GROUP BY J.JW, J.ID_JEDNOSTKI, J.MIEJSCOWOSC,J.NAZWA");
//---------------------------------------------------------------------------
const String PowiadEditor::M_READ_ZP_WHERE_SQL("\
WHERE  (M.DATA_ZAK >'1899-12-30' AND  M.DATA_ZAK <=:DATA_DO)   AND   (M.DATA_PRZEKAZ IS NULL  OR DATA_PRZEKAZ = '1899-12-30') AND  EXISTS           \
(                                                                               \
 SELECT null                                                                     \
 FROM PR_POWIAD P INNER JOIN PR_POWIAD2MAGAZYN PM ON PM.ID_WYDZIALU= P.ID_WYDZIALU AND PM.ROK_POW =P.ROK AND PM.ID_POWIAD=P.ID_POWIAD \
 WHERE PM.ROK = M.ROK AND PM.ID_KOMORKI = M.ID_KOMORKI AND PM.DEPOZYT = M.DEPOZYT AND PM.ID_MAG = M.ID_MAG  AND  P.DATA_WYST + 14 <= :DATA_DO \
) \
");
//---------------------------------------------------------------------------
PowiadEditor::PowiadEditor(void)
:m_IdSesji(-1)
{
 m_Trans         = new mng::TransactionDB();
 m_ListaSprzSDB  = new mng::StreamDB(*m_Trans);
 m_ReaderSDB     = new mng::StreamDB(*m_Trans);
 m_ReaderSDB->setQuery(M_MAGAZYN_SQL);
 m_PowReSDB      = new mng::StreamDB(*m_Trans);
 m_PowReSDB->setQuery(M_MASTER_READ_SQL);
 m_Pow2MagReSDB  = new mng::StreamDB(*m_Trans);
 m_Pow2MagReSDB->setQuery(M_DETAILS_READ_SQL);
 m_PowInsSDB     = new mng::StreamDB(*m_Trans);
 m_PowInsSDB->setQuery(M_MASTER_INS_SQL);
 m_Pow2MagInsSDB = new mng::StreamDB(*m_Trans);
 m_Pow2MagInsSDB->setQuery(M_DETAILS_INS_SQL);
 m_Pattern       = new ptr::Pattern();
 m_PatternDet    = new ptr::Pattern();
 m_Ini           = new jbutils::TMyIni();
}
//---------------------------------------------------------------------------
PowiadEditor::~PowiadEditor(void)
{
 delete m_ListaSprzSDB;
 delete m_ReaderSDB;
 delete m_PowReSDB;
 delete m_Pow2MagReSDB;
 delete m_PowInsSDB;
 delete m_Pow2MagInsSDB;
 delete m_Trans;
 delete m_Pattern;
 delete m_PatternDet;
 delete m_Ini;
}
//---------------------------------------------------------------------------
mng::StreamDB* PowiadEditor::getListaSprz(void)
{
 return m_ListaSprzSDB;
}
//---------------------------------------------------------------------------
void PowiadEditor::setPars(const PowiadEditor::Pars& _Pars)
{
  m_Pars = _Pars;
}
//---------------------------------------------------------------------------
void PowiadEditor::open(void)
{
 m_Trans->startTransaction();
 m_ListaSprzSDB->setQuery(getQuery());
 m_ListaSprzSDB->paramByName("DATA_DO")->AsDateTime = m_Pars.DataZakDo;
 if(m_Pars.Tryb ==1)
 {
  m_ListaSprzSDB->paramByName("DATA_OD")->AsDateTime = m_Pars.DataWystOd;
  m_ListaSprzSDB->paramByName("DATA_DO")->AsDateTime = m_Pars.DataWystDo;
  m_ListaSprzSDB->paramByName("ROK")->AsInteger      = YearOf(m_Pars.DataWystOd);
  m_ListaSprzSDB->paramByName("NR_KOL")->AsInteger   = m_Pars.NrPowiad + 1;

 }
 m_ListaSprzSDB->setIndexFieldNames("DATA_WYST;JW_MIEJSC");
 m_ListaSprzSDB->open();
 if(m_Pars.Tryb ==0)
 {
  m_ListaSprzSDB->fieldByName("DATA_WYST")->OnGetText = getDataWyst;
 }
 else
 {
	m_ListaSprzSDB->fieldByName("DATA_WYST")->OnGetText = NULL;
 }
}
//---------------------------------------------------------------------------
String PowiadEditor::getQuery(void)
{
 String _Res;
 int _Mod = m_Pars.Tryb * 10 + m_Pars.NrPowiad;
 switch( _Mod )
 {
	 case  0: _Res = M_READ_SQL + M_READ_BP_WHERE_SQL + M_READ_GROUP_SQL;  break;
	 case  1: _Res = M_READ_SQL + M_READ_ZP_WHERE_SQL + M_READ_GROUP_SQL;  break;
	 default: _Res = M_READ_WEZW_SQL;
 }
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall PowiadEditor::getDataWyst(TField *Sender, UnicodeString &Text, bool DisplayText)
{
 Text = DateToStr(m_Pars.DataWyst);
}
//---------------------------------------------------------------------------
void PowiadEditor::close(void)
{
 m_Trans->rollback();
 m_ListaSprzSDB->close();
 m_IdSesji = -1;
}
 //---------------------------------------------------------------------------
void PowiadEditor::make(void)
{
 m_IdSesji= getNewIdSesji();
 set2Cont();
 save2DB();
 m_IdSesji=-1;
}
//---------------------------------------------------------------------------
 int  PowiadEditor::getNewIdSesji(void)
 {
  int _IdSesji;
  if(m_Pars.Tryb == 1)
  {
   _IdSesji = m_ListaSprzSDB->fieldByName("ID_SESJI")->AsInteger;
  }
  else
  {
   mng::QueryDB _Q("SELECT GEN_ID(PR_POWIAD_SESJA_GEN,1) AS ID_SESJI,  MAX(ID_POWIAD) AS MAKS  FROM PR_POWIAD");
   _Q.open();
  _IdSesji = _Q.fieldByName("ID_SESJI")->AsInteger;
  _Q.close();
  }
  return _IdSesji;
 }
//---------------------------------------------------------------------------
 int  PowiadEditor::getNewIdPowiad(void)
 {
  mng::QueryDB _Q("SELECT GEN_ID(PR_POWIAD_GEN,1) AS ID_POWIAD,  MAX(ID_SYSTEMU) AS MAKS  FROM IS_REJESTR");
  _Q.open();
  int _IdSesji(_Q.fieldByName("ID_POWIAD")->AsInteger);
  _Q.close();
  return _IdSesji;
 }
//---------------------------------------------------------------------------
 int  PowiadEditor::getNewIdPowiad2Mag(void)
 {
  mng::QueryDB _Q("SELECT GEN_ID(PR_POWIADWMAGAZYN_GEN,1) AS ID_POWIADMAG,  MAX(ID_SYSTEMU) AS MAKS  FROM IS_REJESTR");
  _Q.open();
  int _IdSesji(_Q.fieldByName("ID_POWIADMAG")->AsInteger);
  _Q.close();
  return _IdSesji;
 }
//---------------------------------------------------------------------------
void PowiadEditor::wystaw(void)
{
 if(m_Pars.Tryb >0 || m_Pars.DataWyst >= m_Pars.DataZakDo || mng::MessageDialog::question("Data wystawienia jest mniejsza ni¿ data zakoñczenia\nCzy kontynuowaæ?","POTWIERDZENIE",MB_YESNO) == IDYES)
 {
  m_IdSesji = getNewIdSesji();
  if(m_Pars.Tryb !=1)
  {
   set2Cont();
   save2DB();
  }
  print();
  if(m_Pars.Tryb !=1)
  {
   if(mng::MessageDialog::question("Czy zatwierdziæ wystawione wezwanie?","POTWIERDZENIE",MB_YESNO) == IDYES)
   {
	m_Trans->commit();
   }
   else
   {
	m_Trans->rollback();
   }
   open();
  }
 }
}
//---------------------------------------------------------------------------
void PowiadEditor::set2Cont(void)
{
 m_ReaderSDB->setQuery(getMagQuery());
 m_ReaderSDB->paramByName("DATA_DO")->AsDateTime     = m_Pars.DataZakDo;
 m_ReaderSDB->paramByName("ID_JEDNOSTKI")->AsInteger =  m_ListaSprzSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
 m_ReaderSDB->open();
 m_Cont.clear();
 while(! m_ReaderSDB->isEof())
 {
  add2Cont();
  m_ReaderSDB->next();
 }
 m_ReaderSDB->close();

}
//---------------------------------------------------------------------------
String PowiadEditor::getMagQuery(void)
{
  String _Res;
 switch( m_Pars.NrPowiad )
 {
	 case  0: _Res = M_MAGAZYN_SQL + M_READ_BP_WHERE_SQL + String(" AND M.ID_JEDNOSTKI = :ID_JEDNOSTKI ") + M_MAGAZYN_GROUP_SQL;  break;
	 default: _Res = M_MAGAZYN_SQL + M_READ_ZP_WHERE_SQL + String(" AND M.ID_JEDNOSTKI = :ID_JEDNOSTKI ") +M_MAGAZYN_GROUP_SQL;  break;
 }
 return _Res;

}
//---------------------------------------------------------------------------
bool PowiadEditor::Key::operator<(const PowiadEditor::Key& _Key) const
{
 bool _Res(false);
 if(IdJednostki == _Key.IdJednostki)
 {
  _Res = NrKol < _Key.NrKol;
 }
 else _Res = IdJednostki < _Key.IdJednostki;
 return _Res;
}
//---------------------------------------------------------------------------
void PowiadEditor::add2Cont(void)
{
 Key _Key;
 Val _Val;
 _Key.IdJednostki = m_ReaderSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
 if(_Key.IdJednostki > 0)
 {
  _Key.NrKol       = m_Pars.NrPowiad +1;
  _Val.IdWydzialu  = m_ReaderSDB->fieldByName("ID_WYDZIALU")->AsInteger;
  _Val.IdMag       = m_ReaderSDB->fieldByName("ID_MAG")->AsInteger;
  _Val.Rok         = m_ReaderSDB->fieldByName("ROK")->AsInteger;
  _Val.IdKomorki   = m_ReaderSDB->fieldByName("ID_KOMORKI")->AsInteger;
  _Val.Depozyt     = m_ReaderSDB->fieldByName("DEPOZYT")->AsString;
  m_Cont[_Key].push_back(_Val);
 }
}
//---------------------------------------------------------------------------
void PowiadEditor::save2DB(void)
{
 Cont::const_iterator _ItB = m_Cont.begin();
 Cont::const_iterator _ItE = m_Cont.end();
 m_PowInsSDB->open();
 m_Pow2MagInsSDB->open();
 while(_ItB != _ItE)
 {
  add2PowSDB(_ItB->first);
  add2Pow2MagSDB(_ItB->second);
  ++_ItB;
 }
 m_PowInsSDB->applyUpdates();
 m_Pow2MagInsSDB->applyUpdates();
 m_PowInsSDB->close();
 m_Pow2MagInsSDB->close();
}
//---------------------------------------------------------------------------
void PowiadEditor::add2PowSDB(const PowiadEditor::Key& _Key)
{
 m_IdPowiad = getNewIdPowiad();
 m_PowInsSDB->append();
  m_PowInsSDB->fieldByName("ID_WYDZIALU")->AsInteger  = 1;
  m_PowInsSDB->fieldByName("ROK")->AsInteger          = YearOf(m_Pars.DataWyst);
  m_PowInsSDB->fieldByName("ID_POWIAD")->AsInteger    = m_IdPowiad;
  m_PowInsSDB->fieldByName("ID_JEDNOSTKI")->AsInteger = _Key.IdJednostki;
  m_PowInsSDB->fieldByName("NR_KOL")->AsInteger       = _Key.NrKol;
  m_PowInsSDB->fieldByName("DATA_WYST")->AsDateTime   = m_Pars.DataWyst;
  m_PowInsSDB->fieldByName("ID_SESJI")->AsInteger     = m_IdSesji;
  m_PowInsSDB->fieldByName("SYGNATURA")->AsString     = FormatFloat("0000",m_IdPowiad)+ String("/") + String(CurrentYear());
 m_PowInsSDB->post();
}
//---------------------------------------------------------------------------
void PowiadEditor::add2Pow2MagSDB(const PowiadEditor::Vals& _Vals)
{
 Vals::const_iterator _ItB(_Vals.begin());
 Vals::const_iterator _ItE(_Vals.end());
 while(_ItB!=_ItE)
 {
  m_Pow2MagInsSDB->append();
   m_Pow2MagInsSDB->fieldByName("ID_POWIAD2MAGAZ")->AsInteger = getNewIdPowiad2Mag();
   m_Pow2MagInsSDB->fieldByName("ROK")->AsInteger             = _ItB->Rok;
   m_Pow2MagInsSDB->fieldByName("ID_MAG")->AsInteger          = _ItB->IdMag;
   m_Pow2MagInsSDB->fieldByName("ID_KOMORKI")->AsInteger      = _ItB->IdKomorki;
   m_Pow2MagInsSDB->fieldByName("DEPOZYT")->AsString          = _ItB->Depozyt;
   m_Pow2MagInsSDB->fieldByName("ID_POWIAD")->AsInteger       = m_PowInsSDB->fieldByName("ID_POWIAD")->AsInteger;
   m_Pow2MagInsSDB->fieldByName("ID_WYDZIALU")->AsInteger     = m_PowInsSDB->fieldByName("ID_WYDZIALU")->AsInteger;
   m_Pow2MagInsSDB->fieldByName("ROK_POW")->AsInteger         =m_PowInsSDB->fieldByName("ROK")->AsInteger ;
  m_Pow2MagInsSDB->post();
  ++_ItB;
 }
}
//---------------------------------------------------------------------------
void PowiadEditor::print(void)
{
 m_PowReSDB->close();
 m_PowReSDB->paramByName("ID_SESJI")->AsInteger = m_IdSesji;
 m_PowReSDB->open();
 m_READER     = m_PowReSDB;
 m_READER_DET = m_Pow2MagReSDB;
 preparePrinter();
 while(!m_PowReSDB->isEof())
 {
  m_Pow2MagReSDB->close();
  m_Pow2MagReSDB->paramByName("ROK")->AsInteger         = m_PowReSDB->fieldByName("ROK")->AsInteger;
  m_Pow2MagReSDB->paramByName("ID_WYDZIALU")->AsInteger = m_PowReSDB->fieldByName("ID_WYDZIALU")->AsInteger;
  m_Pow2MagReSDB->paramByName("ID_POWIAD")->AsInteger   = m_PowReSDB->fieldByName("ID_POWIAD")->AsInteger;
  m_Pow2MagReSDB->open();

  buffer();
  m_PowReSDB->next();
 }
 m_PowReSDB->close();
 edit();
}
//---------------------------------------------------------------------------
void PowiadEditor::preparePrinter(void)
{
 m_Path      = ExtractFileDir(Application->ExeName);
 m_PathDet   = m_Path;
 m_PathHead  = m_Path;

 m_Path     +="\\WZORCE\\PowRem.dcp";
 m_PathHead +="\\WZORCE\\PowiadDetHead.dok";
 m_PathDet  +="\\WZORCE\\PowiadDet.dok";

 m_Path     = m_Ini->ReadIniString("POWIADOMIENIA","Wzorzec powiadomienia",m_Path);
 m_PathHead = m_Ini->ReadIniString("POWIADOMIENIA","Wzorzec nag³ówka listy powiadomienia",m_PathHead);
 m_PathDet  = m_Ini->ReadIniString("POWIADOMIENIA","Wzorzec listy powiadomienia",m_PathDet);

 m_Pattern->regMacro("@get",       get,  "Pole z tabelki PR_POWIAD");
 m_Pattern->regMacro("@KodJW",     KodJW,  "Pole z tabelki PR_POWIAD");
 m_Pattern->regMacro("@MiejscJW",  MiejscJW,  "Pole z tabelki PR_POWIAD");
 m_Pattern->regMacro("@FaxJW",     FaxJW,  "Pole z tabelki PR_POWIAD");
 m_Pattern->regMacro("@ListaSprz", ListaSprz,  "Pole z tabelki PR_POWIAD");
 m_Pattern->setPattern(m_Path);

 m_PatternDet->regMacro("@getDet",  getDet,   "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->regMacro("@NrHarm",  NrHarm,   "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->regMacro("@NrMag",   NrMag,    "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->regMacro("@NazSprz", NazSprz,  "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->regMacro("@NrSprz",  NrSprz,    "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->regMacro("@Ilosc",  Ilosc,    "Pole z tabelki PR_POWIAD2mag");
 m_PatternDet->setPattern(m_PathDet);
 m_PATTERN_DET = m_PatternDet;
}
//---------------------------------------------------------------------------
void PowiadEditor::buffer(void)
{
 String  _Buff(m_Pattern->parse()->Text);
 prn::PrinterBase::buffer(_Buff, m_Pattern->getPattern() );
}
//---------------------------------------------------------------------------
void PowiadEditor::edit(void)
{
 prn::PrinterBase::editBuff(m_Pattern->getPattern());
}
//---------------------------------------------------------------------------
mng::StreamDB* PowiadEditor::getMaster(void)
{
 return m_PowReSDB;
}
//---------------------------------------------------------------------------
mng::StreamDB* PowiadEditor::getDetail(void)
{
 return m_Pow2MagReSDB;
}
//---------------------------------------------------------------------------
void PowiadEditor::usun(void)
{
 if(mng::MessageDialog::question("Czy usun¹æ zaznaczone powiadomienie?","PTWIERDZENIE",MB_YESNO)==IDYES)
 {
  std::auto_ptr<mng::QueryDB> _Q(m_Trans->createQuery( "delete from pr_powiad where id_sesji = :id_sesji"));
  _Q->paramByName("ID_SESJI")->AsInteger = m_ListaSprzSDB->fieldByName("ID_SESJI")->AsInteger;
  _Q->execute();
  m_Trans->commit();
  open();
 }
}






//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//MAKRA
  mng::StreamDB * PowiadEditor::m_READER(NULL);
  mng::StreamDB * PowiadEditor::m_READER_DET(NULL);
  ptr::Pattern  * PowiadEditor::m_PATTERN_DET;
  String  PowiadEditor::m_Path;
  String  PowiadEditor::m_PathHead;
  String  PowiadEditor::m_PathDet;

  AnsiString editors::get(AnsiString Par)
  {
   AnsiString _Res;
   if(PowiadEditor::m_READER)
   {
	if(!PowiadEditor::m_READER->isOpen())
	{
	 _Res = "B³¹d makra - zamkniêty dataset";
	}
	else if(! PowiadEditor::m_READER->findField(Par) )
	{
	 _Res = AnsiString("B³¹d makra - brak pola: ") + Par;
	}
	else
	{
	 _Res = PowiadEditor::m_READER->fieldByName(Par)->AsString;
	}
   }
   return _Res;
  }
//---------------------------------------------------------------------------
 AnsiString editors::KodJW(AnsiString Par)
 {
  AnsiString _Res;
  _Res = editors::get("JW");
  return _Res;
 }
//---------------------------------------------------------------------------
 AnsiString editors::MiejscJW(AnsiString Par)
 {
  AnsiString _Res;
  _Res = editors::get("MIEJSCOWOSC");
 return _Res;

 }
//---------------------------------------------------------------------------
 AnsiString editors::FaxJW(AnsiString Par)
 {
  AnsiString _Res;
  _Res = editors::get("FAX");
  return _Res;

 }
//---------------------------------------------------------------------------
 AnsiString editors::ListaSprz(AnsiString Par)
 {
  AnsiString _Res;
  if(PowiadEditor::m_READER_DET && PowiadEditor::m_READER_DET->isOpen())
  {
   PowiadEditor::m_PATTERN_DET->setPattern(PowiadEditor::m_PathHead);
   _Res = PowiadEditor::m_PATTERN_DET->parse()->Text;
   PowiadEditor::m_PATTERN_DET->setPattern(PowiadEditor::m_PathDet);
   while(!PowiadEditor::m_READER_DET->isEof() )
   {
	_Res += PowiadEditor::m_PATTERN_DET->parse()->Text;
	PowiadEditor::m_READER_DET->next();
   }
  }
  return _Res;
 }
//---------------------------------------------------------------------------
  AnsiString editors::getDet(AnsiString Par)
  {
   AnsiString _Res;
   if(PowiadEditor::m_READER_DET)
   {
	if(!PowiadEditor::m_READER_DET->isOpen())
	{
	 _Res = "B³¹d makra - zamkniêty dataset";
	}
	else if(! PowiadEditor::m_READER_DET->findField(Par) )
	{
	 _Res = AnsiString("B³¹d makra - brak pola: ") + Par;
	}
	else
	{
	 _Res = PowiadEditor::m_READER_DET->fieldByName(Par)->AsString;
	}
   }
   return _Res;
  }
//---------------------------------------------------------------------------
 AnsiString editors::NrHarm(AnsiString Par)
 {
  return PadLeft(getDet("ID_HARM"),7);
 }
//---------------------------------------------------------------------------
 AnsiString editors::NrMag(AnsiString Par)
 {
  return getDet("SYGN_MAG");
 }
//---------------------------------------------------------------------------
 AnsiString editors::NazSprz(AnsiString Par)
 {
  return PadRight(getDet("NAZ_SPRZETU"),40);
 }
//---------------------------------------------------------------------------
 AnsiString editors::NrSprz(AnsiString Par)
 {
  return PadRight(getDet("NR_FABR"),10);
 }
//---------------------------------------------------------------------------
 AnsiString editors::Ilosc(AnsiString Par)
 {
  return PadLeft(getDet("ILOSC"),5);
 }
//---------------------------------------------------------------------------

