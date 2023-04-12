// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ListaMAGFRA.h"
#include "isManager.h"
#include "JBUTILS\jb_ini_my.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothDatePicker"
#pragma link "AdvSmoothEdit"
#pragma link "AdvSmoothEditButton"
#pragma link "AdvSmoothPanel"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma link "AdvCombo"
#pragma link "AdvDBComboBox"
#pragma link "AdvDBLookupComboBox"
#pragma resource "*.dfm"
using namespace finders;
// ---------------------------------------------------------------------------
__fastcall T_ListaMAGFRA::T_ListaMAGFRA(TComponent* Owner) : TFrame(Owner), m_IsFilter(true)
{
 m_HarmSDB   = new mng::StreamDB();
 m_SprzetSDB = new mng::StreamDB();
 m_JednSDB   = new mng::StreamDB();
 m_WarSDB    = new mng::StreamDB();
 m_Ini       = new jbutils::TMyIni();

 m_HarmSDB->setQuery("select -1 as id_harmonogramu, 'BRAK' as zadanie, max(id_systemu) from is_rejestr union select h.id_harmonogramu, h.zadanie, 0 as maks from pr_harmonogram h where rok = 2011  order by 1  ");
 m_SprzetSDB->setQuery("select * from pr_sprzet order by case when id_sprzetu < 1 then '' else nazwa end");
 m_JednSDB->setQuery("select* from pr_jednostki order by case when id_jednostki < 1 then id_jednostki else jw end");
 m_WarSDB->setQuery("select * from pr_komorki where WARSZTAT='T' and kod <>'0/0' order by kod");

 m_HarmDS->DataSet   = m_HarmSDB->getClient();
 m_SprzetDS->DataSet = m_SprzetSDB->getClient();
 m_JednDS->DataSet   = m_JednSDB->getClient();
 m_WarDS->DataSet    = m_WarSDB->getClient();


}
//---------------------------------------------------------------------------
__fastcall T_ListaMAGFRA::~T_ListaMAGFRA(void)
{
  delete m_HarmSDB;
  delete m_SprzetSDB;
  delete m_JednSDB;
  delete m_WarSDB;
  delete m_Ini;
}
// ---------------------------------------------------------------------------
T_ListaMAGFRA::Pars __fastcall T_ListaMAGFRA::getPars(void)
{
 Pars _Pars;
 return _Pars;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::setPars(const T_ListaMAGFRA::Pars& _Pars)
{
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::open(void)
{
 bool _Flt =m_Ini->ReadIniBool("WYSZUKIWANIE SPRZÊTU","Filtr",m_DS->DataSet->Filtered);
 if(_Flt)
 {
  readFilter();
  setFilter(NULL);
 }
 else
 {
  clearFilter(NULL);
 }
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::close(void)
{
 saveFilter();
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::setSearchClickEvent(TNotifyEvent Event)
{

}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::setDataSet(TDataSet* _DataSet)
{
 m_DS->DataSet = _DataSet;
}
// ---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::setFilter(TObject *Sender)
{
 String _Filter, _Det;

 TDataSet *_DS = m_DS->DataSet;
 if(_DS)
 {
  if(!m_ProtPrzyjED->Text.IsEmpty() )
  {
   _Filter  = String(" TRIM(UPPER(PROT_PRZYJ)) = '") + m_ProtPrzyjED->Text.UpperCase() + String("'");
   _Det     = String("Prot przyj.: ") + m_NrMagED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_NrMagED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NrMagED->Text.IsEmpty() )
  {
   _Filter  += String(" UPPER(SYGN_MAG) LIKE '%") + m_NrMagED->Text.UpperCase() + String("%'");
   _Det     += String("Nr mag.: ") + m_NrMagED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_HarmED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_HarmED->Text.IsEmpty() )
  {
   _Filter  += String(" UPPER(ID_HARM_STR) LIKE '%") + m_HarmED->Text + String("%'");
   _Det     += String("Nr harm.: ") + m_HarmED->Text;
  }
  if(!_Filter.IsEmpty() && !m_NazSprzED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NazSprzED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(NAZWA) LIKE '%") + m_NazSprzED->Text.UpperCase() + String("%'");
   _Det    += String("Nazwa sprzêtu: ") + m_NazSprzED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_NrRejED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NrRejED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(NR_REJ) LIKE '%") + m_NrRejED->Text.UpperCase() + String("%'");
   _Det    += String("Nr rej.: ") + m_NrRejED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_NrFabrED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_NrFabrED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(NR_FABR) LIKE '%") + m_NrFabrED->Text.UpperCase() + String("%'");
   _Det    += String("Nr fabr.: ") + m_NrFabrED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_IloscED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_IloscED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(ILOSC_STR) LIKE '%") + m_IloscED->Text.UpperCase() + String("%'");
   _Det    += String("Iloœæ: ") + m_IloscED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_DostED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_DostED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(JW_MIEJSCOWOSC) LIKE '%") + m_DostED->Text.UpperCase() + String("%'");
   _Det    += String("Dostawca: ") + m_DostED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_WarED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_WarED->Text.IsEmpty() )
  {
   _Filter += String(" UPPER(KODY_WARSZTATOW) LIKE '%") + m_WarED->Text.UpperCase() + String("%'");
   _Det    += String("Kod warsztatu: ") +  m_WarED->Text.UpperCase();
  }
  if(!_Filter.IsEmpty() && !m_ProtPrzekED->Text.IsEmpty() )
  {
   _Filter += " AND ";
   _Det    += ", ";
  }
  if(!m_ProtPrzekED->Text.IsEmpty() )
  {
   _Filter += String(" TRIM(UPPER(PROT_PRZEKAZ)) LIKE '") + m_ProtPrzekED->Text.UpperCase() + String("'");
   _Det    += String("Prot. przek.: ") +  m_WarED->Text.UpperCase();
  }
  _DS->Filter    = _Filter;
  _DS->Filtered  = !_Filter.IsEmpty();
 }
 if(_DS->Filtered)
 {
  m_ClearFilterBT->Enabled = true;
  m_FilterLB->Caption = "W£¥CZONY";
  m_FilterLB->Font->Color = clRed;
  m_FilterDetLB->Caption  = _Det;
  m_FilterDetLB->Visible  = true;
 }
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::clearFilter(TObject *Sender)
{
 m_ClearFilterBT->Enabled = false;
 m_HarmED->Text      = "";
 m_NrMagED->Text     = "";
 m_NazSprzED->Text   = "";
 m_IloscED->Text     = "";
 m_DostED->Text      = "";
 m_NrRejED->Text     = "";
 m_NrFabrED->Text    = "";
 m_WarED->Text       = "";
 m_ProtPrzekED->Text = "";
 m_ProtPrzyjED->Text = "";

 m_FilterLB->Caption     = "WY£¥CZONY";
 m_FilterLB->Font->Color = clWindowText;
 m_DS->DataSet->Filtered = false;
 m_DS->DataSet->Filter   = "";
 m_FilterDetLB->Visible  = false;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::setIsFilter(const bool _IsFilter)
{
  m_IsFilter = _IsFilter;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::saveFilter(void)
{
 if(m_IsFilter)
 {
  m_Ini->WriteIniBool("WYSZUKIWANIE SPRZÊTU","Filtr",m_DS->DataSet->Filtered);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - prot przyj",m_ProtPrzyjED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr mag",m_NrMagED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - naz sprz",m_NazSprzED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr rej",m_NrRejED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr fabr",m_NrFabrED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - ilosc",m_IloscED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - dost",m_DostED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - warsztat",m_WarED->Text);
  m_Ini->WriteIniString("WYSZUKIWANIE SPRZÊTU","Filtr - prot przek",m_ProtPrzekED->Text);
 }
}
//---------------------------------------------------------------------------
void __fastcall T_ListaMAGFRA::readFilter(void)
{
 if(m_IsFilter)
 {
  m_ProtPrzyjED->Text =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - prot przyj","");
  m_NrMagED->Text     =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr mag","");
  m_NazSprzED->Text   =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - naz sprz","");
  m_NrRejED->Text     =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr rej","");
  m_NrFabrED->Text    =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - nr fabr","");
  m_IloscED->Text     =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - ilosc","");
  m_DostED->Text      =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - dost","");
  m_WarED->Text       =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - warsztat","");
  m_ProtPrzekED->Text =m_Ini->ReadIniString("WYSZUKIWANIE SPRZÊTU","Filtr - prot przek","");
 }
}
//---------------------------------------------------------------------------

void __fastcall T_ListaMAGFRA::MainKeyPress(TObject *Sender, wchar_t &Key)
{
 if(Key =='\r')
 {
  Key=0;
  setFilter(Sender);
 }
}
//---------------------------------------------------------------------------

