//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <memory>
#include "manager\query_db.h"
#include "manager\message_dlg.h"
#include "pr_ImporterWizjaJB.h"
#include "zlib.hpp"
#include "JBUTILS\jb_ini_my.h"
#include "GlownyID.h"
#include "GlownyReader.h"
#include "MANAGER\is_exceptions.h"
#include "Globfunc.h"
#include "KomorkiDICT.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothProgressBar"
#pragma link "AdvGlowButton"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_ImporterWizjaJB::T_ImporterWizjaJB(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall T_ImporterWizjaJB::execute(TComponent* Owner)
{
  std::auto_ptr<T_ImporterWizjaJB>fm(new T_ImporterWizjaJB(Owner));


  jbutils::TMyIni mi;
  fm->m_OpenDialog->InitialDir = mi.ReadIniString("Import", "katalog", AnsiString(IncludeTrailingPathDelimiter(ExtractFileDir(Application->ExeName)) + "_Import"));
  if(fm->m_OpenDialog->Execute())
  {
	AnsiString aExt = ExtractFileExt(UpperCase(fm->m_OpenDialog->FileName));
	bool checkFile = (aExt == ".ZIP");
	if(checkFile)
	{

	  /* Create the Input, Output, and Decompressed streams. */
	  TFileStream* input = new TFileStream(fm->m_OpenDialog->FileName, fmOpenRead);
	  TFileStream* output = new TFileStream(ChangeFileExt(fm->m_OpenDialog->FileName, ""), fmCreate);
	  TZDecompressionStream* unzip = new TZDecompressionStream(input);

	  /* Decompress data. */
	  output->CopyFrom(unzip, 0);
	  fm->m_OpenDialog->FileName = fm->m_OpenDialog->FileName.SubString(0, fm->m_OpenDialog->FileName.Pos(".zip"));
	  /* Free the streams. */
	  unzip->Free();
	  input->Free();
	  output->Free();
	}
	std::auto_ptr<TStringList> _DaneSTR(new TStringList);
	_DaneSTR->LoadFromFile(fm->m_OpenDialog->FileName);
	if(_DaneSTR->Count >1)
	{
	 fm->Caption = "Import danych z " + _DaneSTR->Strings[2];
	 fm->m_DataLB->Caption = "Data pliku eksportu: " + _DaneSTR->Strings[0];
	 fm->m_WarLB->Caption  = readers::GlownyReader::read(_DaneSTR->Strings[1]).getKomCM(" - ","\n");
    }
	fm->ShowModal();
  }
}
//---------------------------------------------------------------------------
void __fastcall T_ImporterWizjaJB::bbPrepareDataClick(TObject *Sender)
{
 bool _Cont(true);

 try{
 std::auto_ptr<TStringList> _DaneSTR(new TStringList);
 _DaneSTR->LoadFromFile(m_OpenDialog->FileName);

 m_progressBar->Position = 0;
 m_progressBar->Maximum  = _DaneSTR->Count;

 mng::QueryDB _QDB;

 if(_DaneSTR->Count > 3)
 {
  msg::GlownyID _GlID = readers::GlownyReader::read(_DaneSTR->Strings[1]);
  String _Msg("Czy wczytaæ dane z ");
  _Msg += _DaneSTR->Strings[0] + " z warsztatów:\n";
  _Msg += _GlID.getKomCodes();
  if(mng::MessageDialog::messageBox(_Msg, "POTWIERDZENIE", MB_ICONQUESTION | MB_YESNO) == IDNO) return;
  m_progressBar->Position = 1;
  AnsiString _SQL;
  for(int i = 3; i < _DaneSTR->Count; ++i)
  {
   _SQL = AnsiString(_DaneSTR->Strings[i]);
   if(_SQL.UpperCase().Pos("KOMPUTER N CORE 2,2/2/320") ) _SQL = _SQL + " ";
   if(_SQL.UpperCase().Pos("EXECUTE PROCEDURE")==0  && _SQL.UpperCase().Pos("DELETE FROM")==0)
   {
	_SQL = AnsiString("UPDATE OR INSERT INTO ") + _SQL;
   }
   _QDB.setQuery( _SQL );
   try
   {

	_QDB.execute();
   }
   catch(mng::ISEDatabase & exc)
   {

	if(exc.Message.Pos("PR_NO_HARM") >0 )
	{
	 _Msg =exc.Message;
	 TReplaceFlags _Rf;
	 _Rf<<rfReplaceAll<<rfIgnoreCase;
	 _Msg = StringReplace(_Msg,"\r\n", "!!!!",_Rf);
	 Globfunc::StringContainer _MsgC;
	 _Msg =_Msg.SubString(_Msg.Pos("BRAK HARMONOGRAMU"), _Msg.Length());
	 _Msg = StringReplace(_Msg,"!!!!", "!",_Rf);
	 _MsgC = Globfunc::explode(_Msg,"!");
	 _Msg  = "Brak harmonogramu o numerze: " + _MsgC[2];
	 _Msg += String(" z ") + _MsgC[1] + String(" roku, który jest przypisany do pozycji magazynowej nr: ");
	 _Msg += _MsgC[3] + String(" w bazie Ÿród³owej!");
	}
	else
	{
	 _Msg = exc.Message;
	}
	_Msg += "\nCzy pomimo tego b³êdu kontynuowaæ przenoszenie danych?";
	_Cont = mng::MessageDialog::question(_Msg,"B³¹d",MB_YESNO)==IDYES;

   }
   if(!_Cont) break;
   m_progressBar->Position = i + 1;
   Application->ProcessMessages();
  }
 }
 }__finally{
  String _Msg = _Cont ? "Dane zosta³y wczytane." : "Dane nie zosta³y wczytane prawid³owo!";
  mng::MessageDialog::messageBox(_Msg, "Informacja",_Cont ? MB_ICONINFORMATION : MB_ICONERROR);
  dict::KomorkiDICT::instance().close();
  Close();
 }
}

//---------------------------------------------------------------------------

void __fastcall T_ImporterWizjaJB::bbCloseClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------

void __fastcall T_ImporterWizjaJB::FormClose(TObject *Sender, TCloseAction &Action)
{
 jbutils::TMyIni _IniFile;
 _IniFile.WriteIniInteger("WARTOŒCI DOMYŒLNE",Name + " - szerokoœæ",Width);
 _IniFile.WriteIniInteger("WARTOŒCI DOMYŒLNE",Name + " - wysokoœæ",Height);
}
//---------------------------------------------------------------------------

void __fastcall T_ImporterWizjaJB::FormShow(TObject *Sender)
{
 jbutils::TMyIni _IniFile;
 Width  = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE",Name + " - szerokoœæ",Width);
 Height = _IniFile.ReadIniInteger("WARTOŒCI DOMYŒLNE",Name + " - wysokoœæ",Height);

}
//---------------------------------------------------------------------------

