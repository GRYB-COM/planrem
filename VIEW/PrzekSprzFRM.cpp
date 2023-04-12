//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrzekSprzFRM.h"
#include "iswzorce62.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "Globfunc.h"
#include "isVaria.h"
#include "MANAGER\message_dlg.h"
#include "EdProtPrzekFRM.h"
#include <memory>
#include "EdProtPrzekDetFRM.h"
#include <memory>
#include "MANAGER\various_man.h"
#include "MANAGER\bookmark_man.h"
#include "ProtFinderCTRL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma link "AdvDateTimePicker"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//STATIKI
  TDataSet*  T_PrzekSprzFRM::m_PrintDS(NULL);
  T_PrzekSprzFRM::RecordSet  T_PrzekSprzFRM::M_RS;
  int T_PrzekSprzFRM::M_ILOSC(0);
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::MasterEvents::onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name)
{
 tab_name= "PR_PROTOKOLY";
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::MasterEvents::beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied)
{
 TProviderFlags _PrFl;
 _PrFl.Clear();
 delta->FieldByName("JW_MIEJSC")->ProviderFlags = _PrFl;
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::DetailEvents::onGetTableName(mng::StreamDB* str_db,TDataSet* ds,WideString &tab_name)
{
 tab_name= "PR_PROTOKOLY";
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::DetailEvents::beforeUpdateRecord(mng::StreamDB* str_db,TDataSet* source,TCustomClientDataSet* delta,TUpdateKind upd_kind,bool &applied)
{
 TProviderFlags _PrFl;
 _PrFl.Clear();
 delta->FieldByName("SYGN_MAG")->ProviderFlags = _PrFl;
 delta->FieldByName("NAZ_SPRZETU")->ProviderFlags = _PrFl;
 delta->FieldByName("NAZ_WARSZTATU")->ProviderFlags = _PrFl;
}
//---------------------------------------------------------------------------
const AnsiString T_PrzekSprzFRM::M_MASTER_SQL(" \
 SELECT P.ROK, P.ID_PROTOKOLU, P.SYGN_PROTOKOLU, P.DATA_WYST, P.ID_WYDZIALU, J.JW ||' '|| J.MIEJSCOWOSC AS JW_MIEJSC, \
 P.SYGN_PROTOKOLU AS PROT_PRZEKAZ, P.DATA_WYST AS DATA_PRZEKAZ, J.JW, J.MIEJSCOWOSC \
 FROM PR_PROTOKOLY P INNER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = P.ID_JEDNOSTKI \
 WHERE  P.ROK = :ROK AND P.ID_PROTOKOLU = :ID_PROTOKOLU AND P.ID_WYDZIALU = :ID_WYDZIALU \
");
//---------------------------------------------------------------------------
const AnsiString T_PrzekSprzFRM::M_DETAIL_SQL(" \
 SELECT P.ID_PROT2MAG, P.ROK_PROT, P.ID_PROTOKOLU, P.ROK_MAG, P.ID_KOMORKI, P.DEPOZYT, P.ID_MAG, P.ILOSC, P.ID_WYDZIALU_PROT, \
 M.SYGN_MAG, S.NAZWA AS NAZ_SPRZETU, K.NAZWA AS NAZ_WARSZTATU, \
 S.NAZWA, S.INDEKS_MAT \
 FROM PR_PROT2MAG P \
 INNER JOIN PR_MAGAZYN M ON M.ROK = P.ROK_MAG AND M.DEPOZYT = P.DEPOZYT AND M.ID_KOMORKI = P.ID_KOMORKI AND M.ID_MAG = P.ID_MAG \
 LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
 LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = P.ID_KOMORKI \
 WHERE \
 P.ID_WYDZIALU_PROT =:ID_WYDZIALU AND \
 P.ROK_PROT =:ROK AND \
 P.ID_PROTOKOLU =:ID_PROTOKOLU \
");
//---------------------------------------------------------------------------
__fastcall T_PrzekSprzFRM::T_PrzekSprzFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_MasterSDB = new mng::StreamDB();
   m_MasterSDB->setQuery(M_MASTER_SQL);
   m_MasterSDB->setEventsHandler(new MasterEvents());
   m_MasterDS->DataSet = m_MasterSDB->getClient();
 m_DetailSDB = new mng::StreamDB();
   m_DetailSDB->setQuery(M_DETAIL_SQL);
   m_DetailSDB->setEventsHandler(new MasterEvents());
   m_DetailDS->DataSet = m_DetailSDB->getClient();
 m_Ini = new jbutils::TMyIni();

}
//---------------------------------------------------------------------------
__fastcall T_PrzekSprzFRM::~T_PrzekSprzFRM(void)
{
 delete m_MasterSDB;
 delete m_DetailSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall T_PrzekSprzFRM::m_AdwSearchBTClick(TObject *Sender)
{
 int _Rok,_IdWydz,_IdProt;
 finders::ProtFinderCTRL::Pars _Pars;
 finders::ProtFinderCTRL _Find;
 if(_Find.find(_Rok,_IdWydz,_IdProt,_Pars)== mrOk)
 {
  openDS(_IdWydz,_Rok,_IdProt);
  activate(true);
 }
}
//---------------------------------------------------------------------------
void __fastcall T_PrzekSprzFRM::m_OpenBTClick(TObject *Sender)
{
 open(true);
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::open(const bool _Msg)
{
 int _IdWydz, _Rok, _Id;
 if(find(_IdWydz,_Rok,_Id) )
 {
  openDS(_IdWydz,_Rok,_Id);
  activate(true);
 }
 else
 {
  if(_Msg) mng::MessageDialog::critical(String("Nie znaleziono protoko³u o sygnaturze: ") + m_PrPrzekED->Text, "");
  m_PrPrzekED->Text = m_Ini->ReadIniString("PROTOKO£Y PRZEKAZANIA","Ostatnia sygnatura","");
 }
}
//---------------------------------------------------------------------------
bool T_PrzekSprzFRM::find(int& IdWydz, int& RokProt, int& IdProt)
{
 mng::QueryDB _Q("SELECT ROK, ID_PROTOKOLU,  ID_WYDZIALU  FROM PR_PROTOKOLY WHERE SYGN_PROTOKOLU = :SYGN_PROTOKOLU ");
 _Q.paramByName("SYGN_PROTOKOLU")->AsString = m_PrPrzekED->Text;
 _Q.open();
 bool _Res = !_Q.isEmpty();
 if(_Res)
 {
  IdWydz  = _Q.fieldByName("ID_WYDZIALU")->AsInteger;
  RokProt = _Q.fieldByName("ROK")->AsInteger;
  IdProt  = _Q.fieldByName("ID_PROTOKOLU")->AsInteger;
 }
 else
 {
  IdWydz=-1;
  RokProt=-1;
  IdProt= -1;
 }
 return _Res;
}
//---------------------------------------------------------------------------
 void T_PrzekSprzFRM::activate(const bool _Active)
 {
   m_TopPA->Visible    = _Active;
   m_EmptyPA->Visible  = !_Active;
 }
//---------------------------------------------------------------------------
 void T_PrzekSprzFRM::openDS(const int& _IdWydz, const int& _RokProt, const int& _IdProt)
 {
  m_MasterSDB->close();
  m_MasterSDB->paramByName("ID_WYDZIALU")->AsInteger  = _IdWydz;
  m_MasterSDB->paramByName("ROK")->AsInteger          = _RokProt;
  m_MasterSDB->paramByName("ID_PROTOKOLU")->AsInteger = _IdProt;
  m_MasterSDB->open();

  openDetDS(_IdWydz,_RokProt,_IdProt);
  m_PrPrzekED->Text = m_MasterSDB->fieldByName("SYGN_PROTOKOLU")->AsString;
  m_Ini->WriteIniString("PROTOKO£Y PRZEKAZANIA","Ostatnia sygnatura",m_PrPrzekED->Text);

 }
//---------------------------------------------------------------------------
 void T_PrzekSprzFRM::openDetDS(const int& _IdWydz, const int& _RokProt, const int& _IdProt)
 {
  m_DetailSDB->close();
  m_DetailSDB->paramByName("ID_WYDZIALU")->AsInteger  = _IdWydz;
  m_DetailSDB->paramByName("ROK")->AsInteger          = _RokProt;
  m_DetailSDB->paramByName("ID_PROTOKOLU")->AsInteger = _IdProt;
  m_DetailSDB->open();
 }
//---------------------------------------------------------------------------
const AnsiString T_PrzekSprzFRM::M_PRINTER_SQL(" \
SELECT M.*, S.NAZWA AS NAZ_SPRZETU, J.*, K.KOD AS KOD_WARSZTATU, K.NAZWA AS NAZ_WARSZTATU \
FROM PR_MAGAZYN M   \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = M.ID_JEDNOSTKI \
LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = M.ID_KOMORKI WHERE ");
//---------------------------------------------------------------------------
const AnsiString T_PrzekSprzFRM::M_PRINTER_MAP(" \
SELECT M.ILOSC, S.NAZWA, S.INDEKS_MAT \
FROM PR_MAGAZYN M   \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
WHERE ");
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::m_PrintBBClick(TObject *Sender)
{
  ptr::Pattern _Pat;
 _Pat.regMacro("@get", getMacroPrzek, "Pole z bazy");
 _Pat.regMacro("@Ilosc", getPrzekIlosc, "Iloœæ sprzêtu");
 _Pat.regMacro("@IlSlw", getPrzekIlSlw, "Iloœæ sp. s³ownie");
 _Pat.regMacro("@LPoz", getPrzekLPoz, "Iloœæ pozycji");
 _Pat.regMacro("@LPSlw", getPrzekLPSlw, "Iloœæ poz. s³ownie");
 _Pat.setEditMacroFlag(false);
 m_PrintDS = m_MasterSDB->getClient();
 fill(m_DetailSDB->getClient());
 AnsiString _Path(ExtractFileDir(Application->ExeName));
 _Path += "\\WZORCE\\";
 _Path += m_Ini->ReadIniString("WZORCE","Wzorzec SpPrzek","ProtPrzek.dcp");
 _Pat.setPattern(_Path);
 _Pat.edit();
 m_PrintDS = NULL;
}
//---------------------------------------------------------------------------
AnsiString getMacroPrzek(AnsiString _FldName)
{
 AnsiString _Res = "";

 if(_FldName.Pos(",") == 0) {
	if(T_PrzekSprzFRM::m_PrintDS) _Res = T_PrzekSprzFRM::m_PrintDS->FieldByName(_FldName.UpperCase())->AsAnsiString;
 }
 else {

	 Globfunc::StringContainer  _Cont = Globfunc::explode(_FldName,",");
	 unsigned _RecNo    = _Cont[1].ToIntDef(-1);
	 String _FieldName  = _FieldName  = _Cont[0];
	 if(_RecNo > 0 && _RecNo <= T_PrzekSprzFRM::M_RS.size())
	 {
	  //_FieldName  = _Cont[1];
	  _Res = T_PrzekSprzFRM::M_RS[_RecNo][_FieldName];
	 }
}

 return _Res;
}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::bbWriteClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::m_PrPrzekEDKeyPress(TObject *Sender, wchar_t &Key)

{
  if (Key == '\r') {

	m_OpenBTClick(this);
  }
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::fill(TDataSet * _DS)
{
 M_RS.clear();
 mng::ControlsMan _CM(_DS);
 mng::BookmarkMan  _BM(_DS);
 _DS->First();
 M_ILOSC = 0;

 while(!_DS->Eof)
 {
  for(int i = 0; i < _DS->Fields->Count; i++)
  {
	M_RS[_DS->RecNo][_DS->Fields->Fields[i]->FieldName] = _DS->Fields->Fields[i]->AsString;
  }
  M_RS[_DS->RecNo]["LP"] = IntToStr(_DS->RecNo) + ".";
  M_RS[_DS->RecNo]["JM"] = "szt";

  M_ILOSC += _DS->FieldByName("ILOSC")->AsInteger;

  _DS->Next();
 }
}

//---------------------------------------------------------------------------

AnsiString getPrzekIlosc(AnsiString _Pars)
{
 AnsiString _Res = IntToStr(T_PrzekSprzFRM::M_ILOSC);

 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getPrzekIlSlw(AnsiString _Pars)
{
 AnsiString _Res = Slownie(T_PrzekSprzFRM::M_ILOSC);

 TReplaceFlags RF;
 RF << rfReplaceAll;

 _Res = StringReplace(_Res,"gr","",RF).Trim();
 _Res = StringReplace(_Res,"zero","",RF).Trim();
 _Res = StringReplace(_Res,"z³","",RF).Trim();

 return _Res;
}
//---------------------------------------------------------------------------

AnsiString getPrzekLPoz(AnsiString _Pars)
{
 AnsiString _Res = IntToStr((int)T_PrzekSprzFRM::M_RS.size());

 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getPrzekLPSlw(AnsiString _Pars)
{
 AnsiString _Res = Slownie((int)T_PrzekSprzFRM::M_RS.size());

 TReplaceFlags RF;
 RF << rfReplaceAll;

 _Res = StringReplace(_Res,"gr","",RF).Trim();
 _Res = StringReplace(_Res,"zero","",RF).Trim();
 _Res = StringReplace(_Res,"z³","",RF).Trim();

 return _Res;
}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::FormShow(TObject *Sender)
{
 activate(false);
 m_PrPrzekED->Text = m_Ini->ReadIniString("PROTOKO£Y PRZEKAZANIA","Ostatnia sygnatura","");
}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::m_AddBTClick(TObject *Sender)
{
add();
}
//---------------------------------------------------------------------------
void T_PrzekSprzFRM::add(void)
{
 std::auto_ptr<T_EdProtPrzekFRM> _EdFrm(new T_EdProtPrzekFRM(NULL));
 int _IdWydz,_RokProt,_IdProt;
 if(_EdFrm->run(_IdWydz,_RokProt,_IdProt))
 {
  openDS(_IdWydz,_RokProt,_IdProt);
  activate(true);
 }

}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::m_AddBBClick(TObject *Sender)
{
 int _IdWydz,_RokProt,_IdProt, _IdProtDet(-1);
 _IdWydz    = m_MasterSDB->fieldByName("ID_WYDZIALU")->AsInteger;
 _RokProt   = m_MasterSDB->fieldByName("ROK")->AsInteger;
 _IdProt    = m_MasterSDB->fieldByName("ID_PROTOKOLU")->AsInteger;
 std::auto_ptr<T_EdProtPrzekDetFRM> _F(new T_EdProtPrzekDetFRM(NULL) );
 _F->run(_IdWydz,_RokProt,_IdProt,_IdProtDet);
 openDetDS(_IdWydz,_RokProt,_IdProt);
 m_DetailSDB->locate("ID_PROT2MAG", _IdProtDet);
}
//---------------------------------------------------------------------------


void __fastcall T_PrzekSprzFRM::m_EditBBClick(TObject *Sender)
{
 int _IdWydz,_RokProt,_IdProt, _IdProtDet(-1);
 _IdWydz    = m_DetailSDB->fieldByName("ID_WYDZIALU_PROT")->AsInteger;
 _RokProt   = m_DetailSDB->fieldByName("ROK_PROT")->AsInteger;
 _IdProt    = m_DetailSDB->fieldByName("ID_PROTOKOLU")->AsInteger;
 _IdProtDet = m_DetailSDB->fieldByName("ID_PROT2MAG")->AsInteger;
 std::auto_ptr<T_EdProtPrzekDetFRM> _F(new T_EdProtPrzekDetFRM(NULL) );
 _F->run(_IdWydz,_RokProt,_IdProt,_IdProtDet);
 openDetDS(_IdWydz,_RokProt,_IdProt);
 m_DetailSDB->locate("ID_PROT2MAG", _IdProtDet);

}
//---------------------------------------------------------------------------

void __fastcall T_PrzekSprzFRM::m_DelBBClick(TObject *Sender)
{
 if( mng::MessageDialog::question("Czy usun¹æ ten element?","POTWIERDZENIE",MB_YESNO) == IDYES)
 {
  int _IdWydz,_RokProt,_IdProt, _IdProtDet(-1);
  _IdWydz    = m_DetailSDB->fieldByName("ID_WYDZIALU_PROT")->AsInteger;
  _RokProt   = m_DetailSDB->fieldByName("ROK_PROT")->AsInteger;
  _IdProt    = m_DetailSDB->fieldByName("ID_PROTOKOLU")->AsInteger;
  _IdProtDet = m_DetailSDB->fieldByName("ID_PROT2MAG")->AsInteger;
  mng::QueryDB _Q("DELETE FROM PR_PROT2MAG WHERE ID_PROT2MAG = :ID_PROT2MAG");
  _Q.paramByName("ID_PROT2MAG")->AsInteger = _IdProtDet;
  _Q.execute();
  openDetDS(_IdWydz,_RokProt,_IdProt);
  m_DetailSDB->first();
 }
}
//---------------------------------------------------------------------------


void __fastcall T_PrzekSprzFRM::m_AGDblClick(TObject *Sender)
{
 if(m_DetailSDB->isOpen() && !m_DetailSDB->isEmpty())
 {
  m_EditBBClick(Sender);
 }
}
//---------------------------------------------------------------------------

