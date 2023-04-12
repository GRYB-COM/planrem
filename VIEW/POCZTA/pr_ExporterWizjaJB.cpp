//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <memory>
#include "ismanager.h"
#include "pr_ExporterWizjaJB.h"
#include "pr_kCopierDataSet.h"
#include "pr_pocztaSmtpFra.h"
#include "jbutils.h"
#include "zlib.hpp"
#include "globfunc.h"
#include "GlownyReader.h"
#include "GlownyID.h"
#include "EksportCfg.h"
#include "EksportCfgReader.h"
#include "EksportCfgWriter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothProgressBar"
#pragma link "AdvGlowButton"
#pragma link "IdBaseComponent"
#pragma link "IdCompressorZLib"
#pragma link "IdZLibCompressorBase"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_ExporterWizjaJB::T_ExporterWizjaJB(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall T_ExporterWizjaJB::bbPrepareDataClick(TObject* Sender)
{
 msg::GlownyID _GlID = readers::GlownyReader::read();
 String _IdsK        = _GlID.getKomIDS();
 String _BaseCode    = _GlID.getBaseCode("_");
  mng::QueryDB q;
  jbutils::TMyIni _IniFile;
  AnsiString _ExpPath;
  AnsiString _ExpFile;
  AnsiString _PostFix;
  msg::EksportCfg _Cfg = readers::EksportCfgReader::instance().run();
  if(_Cfg.isDefined() )
  {
   _ExpFile = _Cfg.getPath();
   _PostFix = _Cfg.getFileName();
  }
  else
  {
  _ExpPath =  IncludeTrailingPathDelimiter(ExtractFileDir(Application->ExeName)) + AnsiString("_EXPORT");
  _ExpFile =  IncludeTrailingPathDelimiter(_ExpPath) + AnsiString("export.ini");
  _ExpFile = _IniFile.ReadIniString("EKSPORT","Plik eksportu",_ExpFile);
  _PostFix = _IniFile.ReadIniString("EKSPORT","Nazwa pliku eksportu","dane_pdrj");
  _Cfg.setPath(_ExpFile);
  _Cfg.setFileName(_PostFix);
  writers::EksportCfgWriter::instance().run(_Cfg);
  }
  _ExpPath =IncludeTrailingPathDelimiter(ExtractFileDir(_ExpFile));
  jbutils::TMyIni  _Exp(_ExpFile);
  m_SaveDialog->InitialDir = _Exp.ReadIniString("Eksport", "katalog", _ExpPath);
  //m_SaveDialog->
  m_SaveDialog->FileName = _BaseCode + _GlID.getWydzCode()+ "_" + Date().DateString() + String("_") +  _PostFix;
  String _ExportFile;
  if(m_SaveDialog->Execute())
  {
	_ExportFile = m_SaveDialog->FileName ;
	//jeœli nie ma rozszerzenia
	 if(_ExportFile.Pos(".pdrj") < 1 )  _ExportFile += ".pdrj";
	//jesli plik juz istnije to go usunac
	if(FileExists(_ExportFile))
	{
	  if(mng::MessageDialog::messageBox("Plik o wskazanej nazwie ju¿ istnieje! Czy nadpisaæ dane?", "Uwaga", MB_ICONWARNING | MB_YESNO) == IDNO)
	  {
		return;
	  }
	  else
		DeleteFile(_ExportFile);
	}

	paMain->Enabled = false;

	TStringList* dane = new TStringList;

	CopierDataSet copyDS;

	dane->Add(Now());
	dane->Add(_IdsK);
	dane->Add(_BaseCode);

	AnsiString _Tabelki = _Exp.ReadIniString("Eksport", "Tabele", "");

	Globfunc::StringContainer _Tables = Globfunc::explode(_Tabelki,";");
	m_progressBar->Minimum  = 0;
	m_progressBar->Maximum  = _Tables.size()-2;
	m_progressBar->Position = 0;
	m_progressBar->Visible  = true;


	int _Rok, _IdWydz;

	AnsiString _Tab,_Alias, _Where, _SQL, _Proc, _Matching, _DelSQL;
	TReplaceFlags _Flag;
	_Flag<<rfReplaceAll;
	for(unsigned i=0; i < _Tables.size(); ++i)
	{
	 _Tab         = _Tables[i].Trim();
	 _SQL         = _Exp.ReadIniString("Eksport - " + _Tab, "SQL", "");
	 _Proc        = _Exp.ReadIniString("Eksport - " + _Tab, "Procedura", "");
	 _DelSQL      = _Exp.ReadIniString("Eksport - " + _Tab, "DEL SQL", "");
	 _Rok    = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
	 _IdWydz = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
	  if(_SQL.IsEmpty())
	  {
	   _Where    = _Exp.ReadIniString("Eksport - " + _Tab, "Warunek", "");
	   _Alias    = _Exp.ReadIniString("Eksport - " + _Tab, "Alias", "");
	   _SQL      = AnsiString("SELECT * FROM ") + _Tab + AnsiString("  ") + _Alias;
		if(!_Where.IsEmpty())_SQL += AnsiString(" WHERE ") + _Where;
	  }
	  _Matching = _Exp.ReadIniString("Eksport - " + _Tab, "Matching", "");;
	  _SQL   = ReplaceStr(_SQL, "@ROK#",_Rok);
	  _SQL   = ReplaceStr(_SQL, "@WYDZIAL#",_IdWydz);
	  _SQL   = ReplaceStr(_SQL, "@GLOWNE#",_IdsK);
	  _DelSQL= ReplaceStr(_DelSQL, "@ROK#",_Rok);
	  _DelSQL= ReplaceStr(_DelSQL, "@WYDZIAL#",_IdWydz);
	  _DelSQL= ReplaceStr(_DelSQL, "@GLOWNE#",_IdsK);
	  if(!_DelSQL.IsEmpty() ) dane->Add(_DelSQL);
	  q.open(_SQL);
	  if(_Proc.IsEmpty() )
	  {
	   copyDS.exportData(dane, q.getDataSet(), _Tab, _Matching);
	  }
	  else
	  {
	   copyDS.exportDataByProc(dane, q.getDataSet(), _Proc);
      }
	  q.close();
	  m_progressBar->Position = m_progressBar->Position + 1;
	  Application->ProcessMessages();
	}

	dane->SaveToFile(_ExportFile);

	TFileStream* input = new TFileStream(_ExportFile, fmOpenRead);
	TFileStream* output = new TFileStream(_ExportFile + ".zip", fmCreate);
	TZCompressionStream* zip = new TZCompressionStream(output, zcMax);

	/* Compress data. */
	zip->CopyFrom(input, input->Size);

	/* Free the streams. */
	zip->Free();
	input->Free();
	output->Free();

	delete dane;
    mng::MessageDialog::information("Eksport wykonany prawid³owo","POTWIERDZENIE");
	//czy wyslac poczt¹...
	/*
	if(mng::MessageDialog::messageBox("Czy wys³aæ dane poczt¹ elektroniczn¹?", "Pytanie", MB_ICONQUESTION | MB_YESNO) == IDYES)
	{
	  jbutils::TMyIni _Ini;
	  AnsiString _Adresy = _Ini.ReadIniString("Eksport", "Adresy", "");

	  while (_Adresy != "")
	  {

		std::auto_ptr<T_pocztaSmtpFra>mailWnd(new T_pocztaSmtpFra(Owner));
		//mailWnd->m_MessageGroup->Enabled = false;

		AnsiString _Mail = _Adresy.SubString(0, _Adresy.Pos(";")- 1);
		mailWnd->edDo->Text = _Mail;
		mailWnd->edTemat->Text = "Dane z systemu Rejestr Remontów";
		mailWnd->m_wiadomosc->Lines->Clear();
		AnsiString plikZalacznika = _ExportFile + ".zip"; //m_SaveDialog->FileName
		mailWnd->m_wiadomosc->Lines->Add("Za³¹czony plik z danymi: " + plikZalacznika);
		mailWnd->m_wiadomosc->Lines->Add("Od : " + mng::Manager::instance().getSystemInfo().getOwner());
		/* mailWnd->m_wiadomosc->Lines->Add("Komórki organizacyjne : ");
		for(int w = 0; w < wydzialy->Count; ++w)
		mailWnd->m_wiadomosc->Lines->Add(wydzialy->Strings[w]); */
		/*
		mailWnd->m_zalaczniki->Items->Clear();
		mailWnd->m_zalaczniki->Items->Add(plikZalacznika);
		//mailWnd->setReceivePasswd(true);
		mailWnd->ShowModal();
		_Adresy = _Adresy.SubString(_Adresy.Pos(";")+ 1, _Adresy.Length());
	  }
	}*/
  }

  m_progressBar->Visible = false;
  paMain->Enabled = true;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall T_ExporterWizjaJB::bbCloseClick(TObject* Sender)
{
 Close();

}
//---------------------------------------------------------------------------
void __fastcall T_ExporterWizjaJB::FormShow(TObject *Sender)
{
 msg::GlownyID _GlID = readers::GlownyReader::read();
 Caption = "Eksport danych z " + _GlID.getBaseCode();
 m_WarLB->Caption = _GlID.getKomCM(" - ","\n");
 jbutils::TMyIni _IniFile;
 Width  = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE",Name + " - szerokoœæ",Width);
 Height = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE",Name + " - wysokoœæ",Height);

}
//---------------------------------------------------------------------------

void __fastcall T_ExporterWizjaJB::FormClose(TObject *Sender, TCloseAction &Action)
{
 jbutils::TMyIni _IniFile;
 _IniFile.WriteIniInteger("WARTOŒCI DOMYŒLNE",Name + " - szerokoœæ",Width);
 _IniFile.WriteIniInteger("WARTOŒCI DOMYŒLNE",Name + " - wysokoœæ",Height);


}
//---------------------------------------------------------------------------

