//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KonfigFRM.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\stream_db.h""
#include "MANAGER\is_manager.h"
#include "EksportCfgWriter.h"
#include "EksportCfgReader.h"
#include "EksportCfg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvDateTimePicker"
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothTabPager"
#pragma link "AdvDBLookupComboBox"
#pragma link "AdvTabSet"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_KonfigFRM::T_KonfigFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Ini     = new jbutils::TMyIni();
 m_WydzSDB = new mng::StreamDB();
 m_WydzSDB->setQuery("select distinct w.id_wydzialu, w.kod, w.NAZWA from pr_wydzialy w inner join pr_komorki k on k.ID_WYDZIALU =w.ID_WYDZIALU");
 m_WydzDS->DataSet = m_WydzSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_KonfigFRM::~T_KonfigFRM(void)
{
 delete m_Ini;
 delete m_WydzSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_KonfigFRM::FormShow(TObject *Sender)
{
  m_PageCTRL->ActivePage = m_WartDOmPG;
 //UPRAWNIENIA
   bool _Right =mng::Manager::instance().checkRight("RRADM");
   m_PowPA->Enabled       = _Right;
   m_WartDomPA->Enabled   = _Right;
   m_EkspPathED->ReadOnly = ! _Right;
   m_EkspPathED->Ctl3D    = _Right;
   m_EkspPathED->Color    = _Right ? clWindow : clInfoBk;
   m_EkspPathBB->Visible   = _Right;
 //POWIADOMIENIA
   AnsiString _Kwart("Kwarta³ ");
   m_IKWDateDTP->Date   = m_Ini->ReadIniDateTime("POWIADOMIENIA",_Kwart + 1, TDateTime(CurrentYear(),12,15));
   m_IIKWDateDTP->Date  = m_Ini->ReadIniDateTime("POWIADOMIENIA",_Kwart + 2, TDateTime(CurrentYear()+1,2,15));
   m_IIIKWDateDTP->Date = m_Ini->ReadIniDateTime("POWIADOMIENIA",_Kwart + 3, TDateTime(CurrentYear()+1,5,15));
   m_IVKWDateDTP->Date  = m_Ini->ReadIniDateTime("POWIADOMIENIA",_Kwart + 4, TDateTime(CurrentYear()+1,8,16));
 //WARTOŒCI DOMYŒLNE
   //WYDZIA£
	 m_WydzSDB->open();
	 m_WydzSDB->fieldByName("KOD")->DisplayWidth =3;
	 m_WydzSDB->fieldByName("NAZWA")->DisplayWidth =70;
	 String _WyFi = m_Ini->ReadIniString("WARTOŒCI DOMYŒLNE","Filtr wydzia³ów",String(""));
	 m_WydzSDB->setFilter(_WyFi);
		 m_WydzSDB->setFiltered(!_WyFi.IsEmpty());
	 m_WydzCB->KeyValue = -9999;
	 m_WydzCB->KeyValue = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
   //BIE¯¥CY ROK
	 m_RokED->Text = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
   //ŒCIE¯KA DO PLIKU EKSPORTU
	 msg::EksportCfg _Cfg = readers::EksportCfgReader::instance().run();
	 if(_Cfg.isDefined())
	 {
	  m_EkspPathED->Text     = _Cfg.getPath();
	  m_EkspFileNameED->Text = _Cfg.getFileName();

	 }
	 else
	 {
	  AnsiString _ExpPath    = IncludeTrailingPathDelimiter(ExtractFileDir(Application->ExeName)) + AnsiString("_EXPORT");
	  AnsiString _ExpFile    = IncludeTrailingPathDelimiter(_ExpPath) + AnsiString("export.ini");
	  m_EkspPathED->Text     = m_Ini->ReadIniString("EKSPORT","Plik eksportu",_ExpFile);
	  m_EkspFileNameED->Text = m_Ini->ReadIniString("EKSPORT","Nazwa pliku eksportu", "dane.pdrj" );
	 }

}
//---------------------------------------------------------------------------

void __fastcall T_KonfigFRM::m_SaveBBClick(TObject *Sender)
{
 bool _Right =mng::Manager::instance().checkRight("RRADM");
 if(!_Right)
 {
  Close();
  return;
 }
 AnsiString _Kwart("Kwarta³ ");
 m_Ini->WriteIniDateTime("POWIADOMIENIA",_Kwart + 1, m_IKWDateDTP->Date);
 m_Ini->WriteIniDateTime("POWIADOMIENIA",_Kwart + 2, m_IIKWDateDTP->Date);
 m_Ini->WriteIniDateTime("POWIADOMIENIA",_Kwart + 3, m_IIIKWDateDTP->Date);
 m_Ini->WriteIniDateTime("POWIADOMIENIA",_Kwart + 4, m_IVKWDateDTP->Date);
 //WARTOŒCI DOMYŒLNE
   //WYDZIA£
	 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",m_WydzSDB->fieldByName("ID_WYDZIALU")->AsInteger);
	 m_WydzSDB->close();
   //BIE¯¥CY ROK
	 m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok",m_RokED->Text.Trim().ToIntDef(CurrentYear()));
   //ŒCIE¯KA DO PLIKU EKSPORTU i NAZWA WYNIKOWEGO
	 msg::EksportCfg _Cfg;
	 _Cfg.setPath(m_EkspPathED->Text);
	 _Cfg.setFileName(m_EkspFileNameED->Text);
	 writers::EksportCfgWriter::instance().run(_Cfg);

 Close();
}
//---------------------------------------------------------------------------


void __fastcall T_KonfigFRM::m_EkspPathBBClick(TObject *Sender)
{
 m_EkspPathOD->InitialDir = IncludeTrailingPathDelimiter(ExtractFileDir(m_EkspPathED->Text));
 if(m_EkspPathOD->Execute()	)
 {
   m_EkspPathED->Text = m_EkspPathOD->FileName;
 }
}
//---------------------------------------------------------------------------

