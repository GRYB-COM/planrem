//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pr_FromWizjaJB.h"
#include "manager\message_dlg.h"
#include "manager\query_db.h"
#include "pr_pocztaPopFra.h"
#include <memory>
#include "zlib.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pr_kBase0FRM"
#pragma link "AdvGlowButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothProgressBar"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_FromWizjaJBFRM::T_FromWizjaJBFRM(TComponent* Owner) : TprBase0FRM(Owner)
{

}

//---------------------------------------------------------------------------
__fastcall T_FromWizjaJBFRM::~T_FromWizjaJBFRM()
{

}

//---------------------------------------------------------------------------
bool T_FromWizjaJBFRM::zapiszZalacznik(const AnsiString& aFileName, TIdMessage* aMsg, int anItem)
{
  AnsiString aExt = ExtractFileExt(UpperCase(aFileName));
  bool checkFile = (aExt == ".PDRJ" || aExt == ".ZIP");

  if(checkFile)
  {
	AnsiString saveDir;
	char tmp[256];
	DWORD result = GetTempPath(256, tmp);
	if(result == 0)
	  saveDir = ExtractFilePath(Application->ExeName);
	else
	  saveDir = tmp;

	saveDir = IncludeTrailingBackslash(saveDir);

	if(FileExists(saveDir + aFileName))
	  DeleteFile(saveDir + aFileName);

	int j = 0;

	for(int i = 0; i < aMsg->MessageParts->Count; ++i)
	{
	  if(aMsg->MessageParts->Items[i]->DisplayName == "TIdAttachmentFile" || aMsg->MessageParts->Items[i]->DisplayName == "TIdAttachmentMemory")
	  {
		TIdAttachment* zal = (TIdAttachment*)aMsg->MessageParts->Items[i];
		if(anItem == j)
		  zal->SaveToFile(saveDir + aFileName);

		j++;
	  }
	}

	if(addFile(saveDir + aFileName, false))
	{
	  mng::MessageDialog::messageBox("Dodano dane z za³¹cznika: " + aFileName, "Informacja", MB_ICONINFORMATION | MB_OK);
	  return false;
	}
  }

  return true;
}

//---------------------------------------------------------------------------
bool __fastcall T_FromWizjaJBFRM::checkUchwala(AnsiString aRok, AnsiString aUchwala)
{
  return false;
}

//---------------------------------------------------------------------------
bool __fastcall T_FromWizjaJBFRM::addFile(const AnsiString& aFileName, bool aShowProgresss)
{
  TStringList* dane = new TStringList;
  dane->LoadFromFile(aFileName);

  m_progressBar->Position = 0;
  m_progressBar->Maximum = dane->Count;

  bool ret = false;

  if(dane->Count < 3)
  {
	mng::MessageDialog::messageBox("Brak danych w pliku:" + AnsiString(m_openDialog->FileName), "Informacja", MB_ICONINFORMATION | MB_OK);
	ret = false;
  }
  else
  {

	AnsiString rok = dane->Strings[0];
	AnsiString uchwala = "-1";

	bool isOK = false;
	mng::QueryDB q;
	for(int i = 1; i < dane->Count; ++i)
	{
	  /* if(StrToIntDef(dane->Strings[i],-1) >=0 ) isOK = checkUchwala(rok,AnsiString(dane->Strings[i]));
	  else if(isOK) */
	  q.execute("UPDATE OR INSERT INTO " + AnsiString(dane->Strings[i]));

	  m_progressBar->Position = i + 1;
	  Application->ProcessMessages();
	}
	ret = true;
  }
  delete dane;

  return ret;
}

//---------------------------------------------------------------------------
void __fastcall T_FromWizjaJBFRM::bbSaveDataClick(TObject* Sender)
{
  if(m_openDialog->Execute())
  {
	m_plik->Caption = m_openDialog->FileName;
	AnsiString aExt = ExtractFileExt(UpperCase(m_openDialog->FileName));
	bool checkFile = (aExt == ".ZIP");
	if(checkFile)
	{

	  /* Create the Input, Output, and Decompressed streams. */
	  TFileStream* input = new TFileStream(m_openDialog->FileName, fmOpenRead);
	  TFileStream* output = new TFileStream(ChangeFileExt(m_openDialog->FileName, ""), fmCreate);
	  TZDecompressionStream* unzip = new TZDecompressionStream(input);

	  /* Decompress data. */
	  output->CopyFrom(unzip, 0);
	  m_openDialog->FileName = m_openDialog->FileName.SubString(0, m_openDialog->FileName.Pos(".zip"));
	  /* Free the streams. */
	  unzip->Free();
	  input->Free();
	  output->Free();
	}

	addFile(m_openDialog->FileName);
	m_plik->Caption = "";
	mng::MessageDialog::messageBox("Dodano dane z pliku:" + AnsiString(m_openDialog->FileName), "Informacja", MB_ICONINFORMATION | MB_OK);
  }
}
//---------------------------------------------------------------------------

void __fastcall T_FromWizjaJBFRM::bbCheckMailsClick(TObject* Sender)
{
  std::auto_ptr<T_pocztaPopFra>fm(new T_pocztaPopFra(this));
  fm->registerOnZapisz(zapiszZalacznik);
  fm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall T_FromWizjaJBFRM::bbCloseClick(TObject* Sender)
{
  Close();
}
//---------------------------------------------------------------------------
