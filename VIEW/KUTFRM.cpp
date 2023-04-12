//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "KUTFRM.h"
#include "isManager.h"
#include "JBUTILS\jb_ini_my.h"
#include "manager\utils_db.h"
#include "HarmFinderCTRL.h"
#include "KomorkiDICT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "DBAdvSmoothDatePicker"
#pragma link "KUTrbhFRA"
#pragma link "AdvDBLookupComboBox"
#pragma link "KUTkosztyFRA"
#pragma link "AdvOfficeButtons"
#pragma link "DBAdvOfficeButtons"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_KUTFRM::T_KUTFRM(TComponent* Owner)
	: TForm(Owner)
{
  m_SDB = new mng::StreamDB();
  m_SDB->setQuery(" SELECT * FROM PR_ZLECENIA WHERE ID_ZLECENIA = :ID_ZLECENIA AND ID_KOMORKI = :ID_KOMORKI  AND ROK = :ROK ");
  m_DS->DataSet = m_SDB->getClient();
  m_SDB->setKeyFields("ROK;ID_KOMORKI;ID_ZLECENIA");
  m_SDB->setUpdateMode(upWhereKeyOnly);

  m_WarsztatSDB = new mng::StreamDB();
  m_WarsztatDS->DataSet = m_WarsztatSDB->getClient();
  m_WarsztatSDB->setQuery(" SELECT * FROM PR_KOMORKI WHERE WARSZTAT ='T' AND ID_KOMORKI > 0 ");

  m_SprzetSDB = new mng::StreamDB();
  m_SprzetDS->DataSet = m_SprzetSDB->getClient();
  m_SprzetSDB->setQuery(" SELECT * FROM PR_SPRZET ORDER BY NAZWA");

  m_HarmonogramSDB = new mng::StreamDB();
  m_HarmonogramDS->DataSet = m_HarmonogramSDB->getClient();
  m_HarmonogramSDB->setQuery(" SELECT * FROM PR_HARMONOGRAM");

  m_JednostkaSDB = new mng::StreamDB();
  m_JednostkaDS->DataSet = m_JednostkaSDB->getClient();
  m_JednostkaSDB->setQuery(" SELECT * FROM PR_JEDNOSTKI order by JW");

  m_MagSDB = new mng::StreamDB();


}
//---------------------------------------------------------------------------
__fastcall T_KUTFRM::~T_KUTFRM()
{
  m_SDB->close();
  m_WarsztatSDB->close();
  m_SprzetSDB->close();
  m_HarmonogramSDB->close();
  m_JednostkaSDB->close();
  m_MagSDB->close();

  delete m_SDB;
  delete m_WarsztatSDB;
  delete m_SprzetSDB;
  delete m_HarmonogramSDB;
  delete m_JednostkaSDB;
  delete m_MagSDB;
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::show(const msg::ZlecID& _ZlecID, const msg::MagID & _MagID,const  msg::ZlecREC& _MainKUT)
{
 m_ZlecID  = _ZlecID;
 m_MagID   = _MagID;
 m_MainKUT = _MainKUT;
 m_BiezRok = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
 m_HarmonogramDS->OnDataChange = NULL;
 m_Append  = !m_ZlecID.IsDefined;
 if(m_Append)
 {
  append();
 }
 else
 {
  edit();
 }
 prepareView();
 m_HarmonogramDS->OnDataChange = m_HarmonogramDSDataChange;
 ShowModal();
 m_HarmonogramDS->OnDataChange = NULL;
 close();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::open(const bool _Append)
{

 m_KUTRBHFRA->show(m_ZlecID);
 m_KUTkosztyFRA->show(m_ZlecID);
 m_WarsztatSDB->open();
 m_SprzetSDB->open();
 m_JednostkaSDB->open();
 openMag();
 openHarm(_Append);
 m_SDB->close();
 m_SDB->paramByName("ID_ZLECENIA")->AsInteger = m_ZlecID.IdZlecenia;
 m_SDB->paramByName("ID_KOMORKI")->AsInteger  = m_ZlecID.IdKomorki;
 m_SDB->paramByName("ROK")->AsInteger         = m_ZlecID.Rok;
 m_SDB->open();



 AnsiString We = ShortDateFormat;
 AnsiString EditDateFormat = "!";
 for (int i = 1; i <= We.Length(); ++i)
		if (!isalpha(We[i])) EditDateFormat += "/";
		else EditDateFormat += "9";
 EditDateFormat += ";1;_";

 mng::UtilsDB::setDateMask(m_SDB->getClient(),ShortDateFormat,EditDateFormat);
 mng::UtilsDB::setNumericMask(m_SDB->getClient(),"LICZBA_RBH","###,###,##0.00");
 m_IloscED->ReadOnly = m_ZlecID.NrKol ==0;
 m_IloscED->Ctl3D    = m_ZlecID.NrKol !=0;
 m_IloscED->Color    = m_ZlecID.NrKol ==0 ? clInfoBk:clWhite;

}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::openMag(void)
{
 AnsiString _SQL("SELECT M.NR_MAG, M.DATA_PRZYJ, M.ID_SPRZETU, M.ID_HARM, M.ID_KOMORKI, M.ID_JEDNOSTKI, M.DATA_PROP_ZAK, \
 H.ROK, H.ZADANIE, m.ILOSC, GEN_ID(PR_ZLECENIA_GEN,1) AS ID_ZLECENIA, KOM.ID_WYDZIALU \
 FROM PR_MAGAZYN M \
 LEFT OUTER JOIN PR_HARMONOGRAM H ON H.ID_HARMONOGRAMU = M.ID_HARM AND H.ROK = M.ROK\
 LEFT OUTER JOIN PR_KOMORKI KOM ON  KOM.ID_KOMORKI = M.ID_KOMORKI \
 WHERE M.ID_MAG = :ID_MAG AND M.ROK =:ROK AND M.ID_KOMORKI = :ID_KOMORKI AND M.DEPOZYT = :DEPOZYT ");
 m_MagSDB->setQuery(_SQL);
 m_MagSDB->paramByName("ID_MAG")->AsInteger     = m_MagID.IdMag;
 m_MagSDB->paramByName("ROK")->AsInteger        = m_MagID.Rok;
 m_MagSDB->paramByName("ID_KOMORKI")->AsInteger = m_MagID.IdKomorki;
 m_MagSDB->paramByName("DEPOZYT")->AsString     = m_MagID.Depozyt;
 m_MagSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::openHarm(const bool _Append)
{
  AnsiString _SQL;
 /*if(!m_MainKUT.IsDefined && _Append && m_MagID.Rok < m_BiezRok)
 {
  _SQL  = AnsiString("SELECT H.*, COALESCE( TRIM(S.NAZWA),' ') || ' ' || COALESCE( TRIM(H.ZADANIE),' ') AS NAZ_ZAD  FROM PR_HARMONOGRAM H ");
  _SQL += AnsiString(" LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU ");
  _SQL += AnsiString(" WHERE H.ID_KOMORKI = ") + AnsiString(m_MagID.IdKomorki) ;
  _SQL += AnsiString(" AND H.ROK = ") + m_BiezRok;
  _SQL += AnsiString(" ORDER BY H.ID_HARMONOGRAMU ");

 }
 else if(!m_MainKUT.IsDefined && _Append)
 {
  _SQL  = AnsiString("SELECT H.*, COALESCE( TRIM(S.NAZWA),' ') || ' ' || COALESCE( TRIM(H.ZADANIE),' ') AS NAZ_ZAD  FROM PR_HARMONOGRAM H ");
  _SQL += AnsiString(" LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU ");
  _SQL += AnsiString(" WHERE H.ID_HARMONOGRAMU = ") + getMagHarm() ;
  _SQL += AnsiString(" AND H.ROK = ") + m_BiezRok;
  _SQL += AnsiString(" ORDER BY H.ID_HARMONOGRAMU ");

 }
 else if(m_MainKUT.IsDefined && m_ZlecID.IsDefined && m_ZlecID.NrKol ==0 && m_ZlecID.Rok == m_MagID.Rok)
 {
  _SQL  = AnsiString("SELECT H.*, COALESCE( TRIM(S.NAZWA),' ') || ' ' || COALESCE( TRIM(H.ZADANIE),' ') AS NAZ_ZAD FROM PR_HARMONOGRAM H ");
  _SQL += AnsiString(" LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU ");
  _SQL += AnsiString(" WHERE H.ID_HARMONOGRAMU = ") + AnsiString(m_MagID.IdHarm) ;
  _SQL += AnsiString(" AND H.ROK = ") + m_MainKUT.IdZlec.Rok;
  _SQL += AnsiString(" ORDER BY H.ID_HARMONOGRAMU ");

 }
 else
 {  */
  _SQL += " SELECT H.*, COALESCE( TRIM(S.NAZWA),' ') || ' ' || COALESCE( TRIM(H.ZADANIE),' ') AS NAZ_ZAD FROM PR_HARMONOGRAM H ";
  _SQL += AnsiString(" LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = H.ID_SPRZETU ");
  _SQL += " LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = H.ID_KOMORKI ";
  _SQL += AnsiString(" WHERE   H.ROK = ") ;
  _SQL  += _Append ?  AnsiString(m_BiezRok) : AnsiString(m_ZlecID.Rok);
  _SQL += AnsiString(" ORDER BY H.ID_HARMONOGRAMU ");

 m_HarmonogramSDB->open(_SQL);
}
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getMagHarm(void)
{
 int _IdHarm = m_MagSDB->fieldByName("ID_HARM")->AsInteger;
 return _IdHarm;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::append(void)
{
 open(true);
 m_SDB->append();
 int _NrKol  = getNextNrKol();
 int _IdZlec = getNextIdZlec();
 int _IdKom  = getIdKom(_NrKol);
 int _IdJedn = getIdJedn(_NrKol);
 int _IdHarm = getIdHarm(_NrKol,_IdKom);
 m_SDB->fieldByName("ROK")->AsInteger             = m_BiezRok;
 m_SDB->fieldByName("ID_HARM")->AsInteger         = _IdHarm;
 m_SDB->fieldByName("NR_HARM")->AsInteger         = m_SDB->fieldByName("ID_HARM")->AsInteger;
 m_SDB->fieldByName("ID_MAG")->AsInteger          = m_MagID.IdMag;
 m_SDB->fieldByName("NR_MAG")->AsInteger          = m_MagID.NrMag;
 m_SDB->fieldByName("ROK_MAG")->AsInteger         = m_MagID.Rok;
 m_SDB->fieldByName("DEPOZYT")->AsString          = m_MagID.Depozyt;
 m_SDB->fieldByName("ID_KOMORKI_GLW")->AsInteger  = m_MagID.IdKomorki;
 m_SDB->fieldByName("ID_KOMORKI")->AsInteger      = _IdKom;
 m_SDB->fieldByName("SYGN_MAG")->AsString           = m_MagID.getSygnMag();
 m_SDB->fieldByName("ZADANIE")->AsString          = "";
 m_SDB->fieldByName("ID_JEDNOSTKI")->AsInteger    = _IdJedn;
 m_SDB->fieldByName("NR_KOL")->AsInteger          = _NrKol;
 m_SDB->fieldByName("STATUS")->AsAnsiString       = "K";
 m_SDB->fieldByName("ID_ZLECENIA")->AsInteger     = _IdZlec;
 m_SDB->fieldByName("DATA_WYST")->AsDateTime      = m_MainKUT.DataWyst;
 m_SDB->fieldByName("ID_SPRZETU")->AsInteger      = m_MagSDB->fieldByName("ID_SPRZETU")->AsInteger;
 m_SDB->fieldByName("DATA_PROP_ZAK")->AsDateTime  = m_MagSDB->fieldByName("DATA_PROP_ZAK")->AsDateTime;
 m_SDB->fieldByName("ILOSC")->AsCurrency          = m_MagSDB->fieldByName("ILOSC")->AsCurrency;
 m_SDB->fieldByName("LICZBA_RBH")->AsCurrency     = getRBH();
 if(_NrKol ==0)
 {
  m_SDB->fieldByName("ZADANIE")->AsString         = m_MagSDB->fieldByName("ZADANIE")->AsString;
 }
}
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getNextNrKol(void)
{
 int _NrKol(0);
 if(m_MainKUT.IsDefined)
 {
  mng::QueryDB q;
   q.setQuery("SELECT MAX(NR_KOL) NR_KOL FROM PR_ZLECENIA WHERE ID_MAG=:ID_MAG AND ROK_MAG=:ROK_MAG AND ID_KOMORKI_GLW=:ID_KOMORKI and ROK =:ROK");
   q.paramByName("ID_MAG")->AsInteger      = m_MagID.IdMag;
   q.paramByName("ROK_MAG")->AsInteger     = m_MagID.Rok;
   q.paramByName("ROK")->AsInteger         = m_BiezRok;
   q.paramByName("ID_KOMORKI")->AsInteger  = m_MagID.IdKomorki;
   q.open();

  if(!q.fieldByName("NR_KOL")->IsNull)
  {
   _NrKol = q.fieldByName("NR_KOL")->AsInteger + 1;
  }
  q.close();
 }
 return _NrKol;
}
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getNextIdZlec(void)
{
  mng::QueryDB q;
 q.open("SELECT MAX(ID_ZLECENIA), GEN_ID(PR_ZLECENIA_GEN,1) ID FROM PR_ZLECENIA ");
 int _IdZlec = q.fieldByName("ID")->AsInteger;
 q.close();
 return _IdZlec;
}
//---------------------------------------------------------------------------
const String T_KUTFRM::M_HARM_FUND_SQL("\
	select first 1 ID_HARMONOGRAMU from pr_harmonogram  \
	where ID_KOMORKI = :ID_KOMORKI AND (ID_HARMONOGRAMU - (ID_HARMONOGRAMU/1000)*1000) =5 \
");
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getIdHarm(const int _NrKol, const int _IdKom)
{
 int _IdHarm(-2);
 if(_NrKol ==0 && m_BiezRok > m_MagID.Rok)
 {
  mng::QueryDB _Q(M_HARM_FUND_SQL);
  _Q.paramByName("ID_KOMORKI")->AsInteger = _IdKom;
  _Q.open();
  _IdHarm = _Q.fieldByName("ID_HARMONOGRAMU")->AsInteger;

 }
 else if(m_HarmonogramSDB->getClient()->RecordCount ==1)
 {
  _IdHarm = m_HarmonogramSDB->fieldByName("ID_HARMONOGRAMU")->AsInteger;
 }
 return _IdHarm;
}
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getIdKom(const int _NrKol)
{
 int _IdKom(m_MagID.IdKomorki);
 if(_NrKol >0) _IdKom = -2;
 return _IdKom;
}
//---------------------------------------------------------------------------
int __fastcall T_KUTFRM::getIdJedn(const int _NrKol)
{
 int _IdJedn;
 if(_NrKol >0)
 {
  m_WarsztatSDB->locate("ID_KOMORKI",m_MagID.IdKomorki);
  AnsiString _KdWar =AnsiString("W") + m_WarsztatSDB->fieldByName("KOD")->AsAnsiString;
  m_JednostkaSDB->locate("JW",_KdWar);
  _IdJedn = m_JednostkaSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
 }
 else
 {
  _IdJedn = m_MagSDB->fieldByName("ID_JEDNOSTKI")->AsInteger;
 }
 return _IdJedn;
}
//---------------------------------------------------------------------------
const String T_KUTFRM::M_RBH_SQL("\
	SELECT COALESCE( Z.LICZBA_RBH,0 ) - COALESCE(SUM(R.lICZBA_RBH),0)  AS RBH \
	FROM PR_ZLECENIA_RBH R  \
	INNER JOIN PR_ZLECENIA Z ON Z.ROK = R.ROK AND Z.ID_KOMORKI = R.ID_KOMORKI AND Z.ID_ZLECENIA = R.ID_ZLECENIA \
	WHERE  Z.ROK_MAG = :ROK_MAG AND Z.ID_KOMORKI_GLW = :ID_KOMORKI_GLW AND Z.ID_MAG = :ID_MAG AND \
	Z.DEPOZYT = :DEPOZYT AND Z.ROK <:ROK AND Z.ID_KOMORKI = :ID_KOMORKI AND Z.NR_KOL = :NR_KOL  \
	GROUP BY Z.LICZBA_RBH  \
");
//---------------------------------------------------------------------------
Currency __fastcall T_KUTFRM::getRBH(void)
{
 mng::QueryDB _Q(M_RBH_SQL);
 _Q.paramByName("ROK_MAG")->AsInteger        =m_MagID.Rok;
 _Q.paramByName("ID_KOMORKI_GLW")->AsInteger =m_MagID.IdKomorki;
 _Q.paramByName("ID_MAG")->AsInteger         =m_MagID.IdMag;
 _Q.paramByName("DEPOZYT")->AsString         =m_MagID.Depozyt;
 _Q.paramByName("ROK")->AsInteger            =m_SDB->fieldByName("ROK")->AsInteger;
 _Q.paramByName("ID_KOMORKI")->AsInteger     =m_SDB->fieldByName("ID_KOMORKI")->AsInteger;
 _Q.paramByName("NR_KOL")->AsInteger         =m_SDB->fieldByName("NR_KOL")->AsInteger;
 _Q.open();
 Currency _Res = _Q.fieldByName("RBH")->AsCurrency;
 _Q.close();
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::edit(void)
{
 open(false);
 m_SDB->edit();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::prepareView(void)
{
 m_WriteBB->Enabled = m_Append || m_BiezRok <= m_ZlecID.Rok;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::complete(void)
{
 m_ZlecID.IsDefined     = true;
 m_ZlecID.IdZlecenia    = m_SDB->fieldByName("ID_ZLECENIA")->AsInteger;
 m_ZlecID.IdKomorki     = m_SDB->fieldByName("ID_KOMORKI")->AsInteger;
 m_ZlecID.IdKomorkiGlw  = m_SDB->fieldByName("ID_KOMORKI_GLW")->AsInteger;
 m_ZlecID.Rok           = m_SDB->fieldByName("ROK")->AsInteger;
 m_ZlecID.NrKol         = m_SDB->fieldByName("NR_KOL")->AsInteger;
 m_ZlecID.NrMag         = m_MagID.NrMag;
 String _Dep(m_MagID.Depozyt == "R" ? String("") : m_MagID.Depozyt );
 if(m_Append)
 {
  if(! m_SDB->isEdited() ) m_SDB->edit();
   m_SDB->fieldByName("SYGN_ZLECENIA")->AsAnsiString = m_ZlecID.getSygn(_Dep);
   m_SDB->post();
 }
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::m_WriteBBClick(TObject *Sender)
{
 m_SDB->post();
 if(!valid()) return;
 complete();
 Currency rbh(0);
 m_KUTRBHFRA->getDataSet()->First();
 /*while(!m_KUTRBHFRA->getDataSet()->Eof)
 {
	 rbh = rbh + m_KUTRBHFRA->getDataSet()->FieldByName("LICZBA_RBH")->AsCurrency;
	 m_KUTRBHFRA->getDataSet()->Next();
 }

 if(m_SDB->fieldByName("LICZBA_RBH")->AsCurrency != rbh)
 {
   if(Application->MessageBox(String("Liczba RBH ogó³em jest niezgodna z sum¹ RBH miesiêczn¹.\nCzy powróciæ do edycji zlecenia?").c_str(),
	 String("Ostrze¿enie").c_str(), MB_ICONWARNING | MB_YESNO) == IDYES)  return;
 }*/

 AnsiString sygn = m_SDB->fieldByName("SYGN_ZLECENIA")->AsAnsiString;

 m_SDB->applyUpdates();
 m_KUTRBHFRA->apply(&m_ZlecID);
 m_KUTkosztyFRA->apply(&m_ZlecID);

 if(m_Append) ShowMessage("Nr sygnatury: " + sygn);

 if(m_SDB->fieldByName("NR_KOL")->AsInteger ==0)
 {
  mng::QueryDB _Q("UPDATE PR_MAGAZYN SET GLOWNY_KUT = :SYGN_ZLEC WHERE ID_MAG = :ID_MAG AND ROK =:ROK AND ID_KOMORKI = :ID_KOMORKI AND DEPOZYT = :DEPOZYT ");
  m_MagID.setToPars(_Q.getParams());
  _Q.paramByName("SYGN_ZLEC")->AsString =  m_SDB->fieldByName("SYGN_ZLECENIA")->AsString;
  try{ _Q.execute();} catch(...){}
 }
 Close();
}
//---------------------------------------------------------------------------
bool __fastcall T_KUTFRM::valid(void)
{

  if(m_SDB->fieldByName("ID_HARM")->IsNull || m_SDB->fieldByName("ID_HARM")->AsInteger < 1)
 {
   ShowMessage("Podaj harmonogram!");
   if(m_HarmCB->CanFocus() ) m_HarmCB->SetFocus();
   return false;
 }
 if(m_SDB->fieldByName("ID_KOMORKI")->IsNull || m_SDB->fieldByName("ID_KOMORKI")->AsInteger < 1)
 {
   ShowMessage("Podaj warsztat!");
   if(m_KodCB->CanFocus() ) m_KodCB->SetFocus();
   return false;
 }
 if(m_SDB->fieldByName("ID_JEDNOSTKI")->IsNull || m_SDB->fieldByName("ID_JEDNOSTKI")->AsInteger == -2)
 {
   ShowMessage("Podaj jednostkê!");
   if(m_JWCB->CanFocus() ) m_JWCB->SetFocus();
   return false;
 }
 if(m_SDB->fieldByName("ZADANIE")->AsAnsiString.Trim() == "")
 {
  if(m_ZadED->CanFocus() ) m_ZadED->SetFocus();
  ShowMessage("Podaj zadanie!");
   return false;
 }
 if(!validZak()) return false;
 return true;
}
//---------------------------------------------------------------------------
bool __fastcall T_KUTFRM::validZak(void)
{
 if(m_SDB->fieldByName("NR_KOL")->AsInteger ==0)
 {
  if(!validZakGl()) return false;
 }
 else
 {
  if(!validZakK()) return false;
 }
 return true;
}
//---------------------------------------------------------------------------
const String T_KUTFRM::M_CHECK_DATA_ZAK_SQL("\
select \
COUNT(CASE WHEN Z.DATA_ZAK IS NULL OR Z.DATA_ZAK <'1900-01-01' THEN 1 END) AS NZAK, \
MAX(Z.DATA_ZAK) AS MAX_DATA \
from pr_zlecenia z where z.ROK_MAG =:ROK_MAG AND ROK =:ROK AND  z.DEPOZYT = :DEPOZYT AND \
Z.ID_KOMORKI_GLW = :ID_KOMORKI_GLW AND Z.ID_MAG = :ID_MAG AND Z.NR_KOL <> 0\
");
//---------------------------------------------------------------------------
const String T_KUTFRM::M_NO_DATA_ZAK_MSG("\
Nie wszystkie KUTy kooperacyjne zosta³y zakoñczone\n\
Czy pomimo to zapisaæ zmiany?\
");
//---------------------------------------------------------------------------
const String T_KUTFRM::M_BAD_DATA_ZAK_MSG("\
Na tej pozycji s¹ KUTy z dat¹ zakoñczenia wiêksz¹ ni¿ %s \n\
Czy pomimo to zapisaæ zmiany?\
");
//---------------------------------------------------------------------------
bool __fastcall T_KUTFRM::validZakGl(void)
{
 TDateTime _DataZak = m_SDB->fieldByName("DATA_ZAK")->AsDateTime;
 if(_DataZak > TDateTime(0.0))
 {
  mng::QueryDB _Q(M_CHECK_DATA_ZAK_SQL);
  _Q.paramByName("ROK")->AsInteger = m_SDB->fieldByName("ROK")->AsInteger;
  _Q.paramByName("ROK_MAG")->AsInteger = m_SDB->fieldByName("ROK_MAG")->AsInteger;
  _Q.paramByName("ID_KOMORKI_GLW")->AsInteger = m_SDB->fieldByName("ID_KOMORKI_GLW")->AsInteger;
  _Q.paramByName("ID_MAG")->AsInteger = m_SDB->fieldByName("ID_MAG")->AsInteger;
  _Q.paramByName("DEPOZYT")->AsString = m_SDB->fieldByName("DEPOZYT")->AsString;
  _Q.open();
  if(_Q.fieldByName("NZAK")->AsInteger > 0)
  {
   return mng::MessageDialog::critical(M_NO_DATA_ZAK_MSG,"B£¥D", MB_YESNO)==IDYES;
  }
  if(_Q.fieldByName("MAX_DATA")->AsDateTime > _DataZak)
  {
   return mng::MessageDialog::critical(Format(M_BAD_DATA_ZAK_MSG, ARRAYOFCONST((DateToStr(_DataZak)))),"B£¥D", MB_YESNO)==IDYES;
  }

 }
 return true;
}
//---------------------------------------------------------------------------
const String T_KUTFRM::M_CHECK_GLW_DATA_ZAK_SQL("\
select Z.DATA_ZAK \
from pr_zlecenia z where z.ROK_MAG =:ROK_MAG AND ROK =:ROK AND  z.DEPOZYT = :DEPOZYT AND \
Z.ID_KOMORKI_GLW = :ID_KOMORKI_GLW AND Z.ID_MAG = :ID_MAG AND Z.NR_KOL = 0  \
");
//---------------------------------------------------------------------------
const String T_KUTFRM::M_BAD_GLW_DATA_ZAK_MSG("\
G³ówny KUT ma datê zakoñczenia mniejsz¹ ni¿ %s tj %s\n\
Czy pomimo to zapisaæ zmiany?\
");
//---------------------------------------------------------------------------
bool __fastcall T_KUTFRM::validZakK(void)
{
 TDateTime _DataZak = m_SDB->fieldByName("DATA_ZAK")->AsDateTime;
 if(_DataZak > TDateTime(0.0))
 {
  mng::QueryDB _Q(M_CHECK_GLW_DATA_ZAK_SQL);
  _Q.paramByName("ROK")->AsInteger = m_SDB->fieldByName("ROK")->AsInteger;
  _Q.paramByName("ROK_MAG")->AsInteger = m_SDB->fieldByName("ROK_MAG")->AsInteger;
  _Q.paramByName("ID_KOMORKI_GLW")->AsInteger = m_SDB->fieldByName("ID_KOMORKI_GLW")->AsInteger;
  _Q.paramByName("ID_MAG")->AsInteger = m_SDB->fieldByName("ID_MAG")->AsInteger;
  _Q.paramByName("DEPOZYT")->AsString = m_SDB->fieldByName("DEPOZYT")->AsString;
  _Q.open();
  TDateTime _GlwDataZak = _Q.fieldByName("DATA_ZAK")->AsDateTime;
  if(_GlwDataZak > TDateTime(0.0) &&  _GlwDataZak < _DataZak)
  {
   return mng::MessageDialog::critical(Format(M_BAD_GLW_DATA_ZAK_MSG, ARRAYOFCONST((DateToStr(_DataZak),DateToStr(_GlwDataZak)))),"B£¥D", MB_YESNO)==IDYES;
  }

 }
 return true;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::AdvSmoothButton1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::close(void)
{
 m_SDB->close();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::getZlecID(msg::ZlecID& _ZlecID)
{
 _ZlecID.fillFromDS(m_SDB->getClient());
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::DBEdit8KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key == VK_DELETE && Shift.Contains(ssCtrl)) m_SDB->fieldByName("DATA_PROP_ZAK")->Clear();
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::DBEdit10KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key == VK_DELETE && Shift.Contains(ssCtrl)) m_SDB->fieldByName("PRZESTOJ_OD")->Clear();
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::DBEdit11KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key == VK_DELETE && Shift.Contains(ssCtrl)) m_SDB->fieldByName("DATA_ZDA_KUT")->Clear();
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::DBEdit13KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key == VK_DELETE && Shift.Contains(ssCtrl)) m_SDB->fieldByName("DATA_ZAK")->Clear();
}
//---------------------------------------------------------------------------
void __fastcall T_KUTFRM::m_HarmonogramDSDataChange(TObject *Sender, TField *Field)
{
 //
}
//---------------------------------------------------------------------------


void __fastcall T_KUTFRM::m_FindHarmBBClick(TObject *Sender)
{
 finders::HarmFinderCTRL _Fi;
 finders::HarmFinderCTRL::Pars _Pars;
 int _IdHarm;
 _Pars.Rok        = m_SDB->fieldByName("ROK")->AsInteger;
 if(_Fi.find(_IdHarm,_Pars) == mrOk)
 {
  m_SDB->fieldByName("ID_HARM")->AsInteger = _IdHarm;
 }
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::m_WarsztatDSDataChange(TObject *Sender, TField *Field)
{
 //m_WydzED->Text = dict::KomorkiDICT::instance().getKodWydzialu( m_WarsztatSDB->fieldByName("ID_KOMORKI")->AsInteger);
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::m_DSDataChange(TObject *Sender, TField *Field)
{
 if(m_ZlecID.IsDefined)
 {
  //m_RokED->Text   = m_ZlecID.Rok;
 }
 else if(m_MagID.IsDefined)
 {
  //m_RokED->Text   = m_MagID.Rok;
 }
 m_NrMagED->Text = FormatFloat("0000",m_MagID.NrMag);
 m_WydzED->Text = m_MagID.getKodWydz();
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::m_HarmCBExit(TObject *Sender)
{
 if(m_HarmonogramSDB->isOpen() && m_SDB->isOpen() && m_SDB->isEdited() )
 {
  int _IdKH(m_HarmonogramSDB->fieldByName("ID_KOMORKI")->AsInteger);
  int _IdKK(m_SDB->fieldByName("ID_KOMORKI")->AsInteger );
  if(_IdKH !=_IdKK)
  {
   m_SDB->fieldByName("ID_KOMORKI")->AsInteger  = _IdKH;
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::FormShow(TObject *Sender)
{
 m_HarmCB->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::m_DataWystDTPKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
 if(Key == VK_DELETE)
 {
  TDBAdvSmoothDatePicker* _C = dynamic_cast<TDBAdvSmoothDatePicker*>(Sender);
  if(_C)
  {
   if(_C->DataSource)
   {
	if(_C->DataSource->DataSet)
	{
	 if(!_C->DataField.IsEmpty())
	 {
	  _C->DataSource->DataSet->FieldByName(_C->DataField)->Clear();
	  _C->Update();
     }
    }
   }
  }
 }

}
//---------------------------------------------------------------------------

void __fastcall T_KUTFRM::m_RBHBBClick(TObject *Sender)
{
 m_SDB->fieldByName("LICZBA_RBH")->AsCurrency     = getRBH();
}
//---------------------------------------------------------------------------

