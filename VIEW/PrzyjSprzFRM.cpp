//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrzyjSprzFRM.h"
#include "SPReader.h"
#include "iswzorce62.h"
#include "MANAGER\query_db.h"
#include "JBUTILS\jb_ini_my.h"
#include "Globfunc.h"
#include "isVaria.h"
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
mng::QueryDB*  T_PrzyjSprzFRM::m_PrintQDB(NULL);
T_PrzyjSprzFRM::RecordSet  T_PrzyjSprzFRM::M_RS;
int T_PrzyjSprzFRM::M_ILOSC(0);
//---------------------------------------------------------------------------
__fastcall T_PrzyjSprzFRM::T_PrzyjSprzFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Reader = new readers::SPReader();
 m_DS->DataSet = m_Reader->getDataSet();

 edDost->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall T_PrzyjSprzFRM::m_OpenBTClick(TObject *Sender)
{
 m_Reader->open(m_spIN,m_PrPrzyjED->Text);
 edDost->Text = m_DS->DataSet->FieldByName("NAZWA_PELNA")->AsString + " " + m_DS->DataSet->FieldByName("MIEJSCOWOSC")->AsString;
}
//---------------------------------------------------------------------------

const AnsiString T_PrzyjSprzFRM::M_PRINTER_SQL(" \
SELECT M.*, S.NAZWA AS NAZ_SPRZETU, J.*, K.KOD AS KOD_WARSZTATU, K.NAZWA AS NAZ_WARSZTATU \
FROM PR_MAGAZYN M   \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
LEFT OUTER JOIN PR_JEDNOSTKI J ON J.ID_JEDNOSTKI = M.ID_JEDNOSTKI \
LEFT OUTER JOIN PR_KOMORKI K ON K.ID_KOMORKI = M.ID_KOMORKI WHERE ");


const AnsiString T_PrzyjSprzFRM::M_PRINTER_MAP(" \
SELECT M.ILOSC, S.NAZWA, S.INDEKS_MAT \
FROM PR_MAGAZYN M   \
LEFT OUTER JOIN PR_SPRZET S ON S.ID_SPRZETU = M.ID_SPRZETU \
WHERE ");

//---------------------------------------------------------------------------

void __fastcall T_PrzyjSprzFRM::m_PrintBBClick(TObject *Sender)
{
  ptr::Pattern _Pat;
 _Pat.regMacro("@get", getMacroPrzyj, "Pole z bazy");
 _Pat.regMacro("@Ilosc", getPrzyjIlosc, "Iloœæ sprzêtu");
 _Pat.regMacro("@IlSlw", getPrzyjIlSlw, "Iloœæ sp. s³ownie");
 _Pat.regMacro("@LPoz", getPrzyjLPoz, "Iloœæ pozycji");
 _Pat.regMacro("@LPSlw", getPrzyjLPSlw, "Iloœæ poz. s³ownie");
 _Pat.setEditMacroFlag(false);
 mng::QueryDB _Q(M_PRINTER_MAP + (m_spIN ? "M.PROT_PRZYJ" : "M.PROT_PRZEKAZ") + " = '" + m_PrPrzyjED->Text + "'" );
 m_PrintQDB = &_Q;

 _Q.open();

 fill(m_PrintQDB->getDataSet());

 _Q.close();

 _Q.setQuery(M_PRINTER_SQL + (m_spIN ? "M.PROT_PRZYJ" : "M.PROT_PRZEKAZ") + " = '" + m_PrPrzyjED->Text + "'" );

  _Q.open();

 AnsiString _Path(ExtractFileDir(Application->ExeName));
 _Path += "\\WZORCE\\";
 _Path += (m_spIN ? jbutils::TMyIni().ReadIniString("WZORCE","Wzorzec SpPrzyj","ProtPrzyj.dcp") :
			jbutils::TMyIni().ReadIniString("WZORCE","Wzorzec SpPrzek","ProtPrzek.dcp") );
 _Pat.setPattern(_Path);
 _Pat.edit();
 _Q.close();
 m_PrintQDB = NULL;
}
//---------------------------------------------------------------------------
AnsiString getMacroPrzyj(AnsiString _FldName)
{
 AnsiString _Res = "";

 if(_FldName.Pos(",") == 0) {
	if(T_PrzyjSprzFRM::m_PrintQDB) _Res = T_PrzyjSprzFRM::m_PrintQDB->fieldByName(_FldName.UpperCase())->AsAnsiString;
 }
 else {

	 Globfunc::StringContainer  _Cont = Globfunc::explode(_FldName,",");
	 int _RecNo         = _Cont[1].ToIntDef(-1);
	 String _FieldName  = _FieldName  = _Cont[0];
	 if(_RecNo > 0 && _RecNo <= (int) T_PrzyjSprzFRM::M_RS.size())
	 {
	  //_FieldName  = _Cont[1];
	  _Res = T_PrzyjSprzFRM::M_RS[_RecNo][_FieldName];
	 }
}

 return _Res;
}
//---------------------------------------------------------------------------

void __fastcall T_PrzyjSprzFRM::bbWriteClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_PrzyjSprzFRM::m_PrPrzyjEDKeyPress(TObject *Sender, wchar_t &Key)

{
  if (Key == '\r') {

	m_OpenBTClick(this);
  }
}
//---------------------------------------------------------------------------
void T_PrzyjSprzFRM::fill(TDataSet * _DS)
{
 M_RS.clear();
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

AnsiString getPrzyjIlosc(AnsiString _Pars)
{
 AnsiString _Res = IntToStr(T_PrzyjSprzFRM::M_ILOSC);

 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getPrzyjIlSlw(AnsiString _Pars)
{
 AnsiString _Res = Slownie(T_PrzyjSprzFRM::M_ILOSC);

 TReplaceFlags RF;
 RF << rfReplaceAll;

 _Res = StringReplace(_Res,"gr","",RF).Trim();
 _Res = StringReplace(_Res,"zero","",RF).Trim();
 _Res = StringReplace(_Res,"z³","",RF).Trim();

 return _Res;
}
//---------------------------------------------------------------------------

AnsiString getPrzyjLPoz(AnsiString _Pars)
{
 AnsiString _Res = IntToStr((int)T_PrzyjSprzFRM::M_RS.size());

 return _Res;
}
//---------------------------------------------------------------------------
AnsiString getPrzyjLPSlw(AnsiString _Pars)
{
 AnsiString _Res = Slownie((int)T_PrzyjSprzFRM::M_RS.size());

 TReplaceFlags RF;
 RF << rfReplaceAll;

 _Res = StringReplace(_Res,"gr","",RF).Trim();
 _Res = StringReplace(_Res,"zero","",RF).Trim();
 _Res = StringReplace(_Res,"z³","",RF).Trim();

 return _Res;
}
//---------------------------------------------------------------------------

void __fastcall T_PrzyjSprzFRM::FormShow(TObject *Sender)
{
 m_DataPrzyjDTP->DateTime = Date();
}
//---------------------------------------------------------------------------

