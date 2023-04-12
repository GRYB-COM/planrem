//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pr_ToWizjaJB.h"
#include "jbutils.h"
#include "ismanager.h"
//#include "wi_CoreConfig.h"
#include "pr_kCopierDataSet.h"
#include "pr_pocztaSmtpFra.h"
#include "zlib.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pr_kBase0FRM"
#pragma link "AdvGlowButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvSmoothProgressBar"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall T_ToWizjaJBFRM::T_ToWizjaJBFRM(TComponent* Owner) : TprBase0FRM(Owner)
{
  jbutils::TMyIni mi;
  edKatalog->Text = mi.ReadIniString("Eksport", "katalog", AnsiString(IncludeTrailingPathDelimiter(ExtractFileDir(Application->ExeName)) + "_Eksport"));

  m_lvWydzialy->Items->Clear();
  TListItem* ListItem;
}

//---------------------------------------------------------------------------
__fastcall T_ToWizjaJBFRM::~T_ToWizjaJBFRM()
{
  jbutils::TMyIni mi;
  mi.WriteIniString("Eksport", "katalog", edKatalog->Text);
}

//---------------------------------------------------------------------------
bool __fastcall T_ToWizjaJBFRM::prepDir(AnsiString aDir)
{
  bool isDir;
  isDir = DirectoryExists(aDir);
  if(!isDir)
	isDir = CreateDir(aDir);

  return isDir;
}

//---------------------------------------------------------------------------
void __fastcall T_ToWizjaJBFRM::sendEmails(void)
{
  std::auto_ptr<T_pocztaSmtpFra>mailWnd(new T_pocztaSmtpFra(this));
  mailWnd->m_MessageGroup->Enabled = false;

  jbutils::TMyIni mi;
  AnsiString _Adresy = mi.ReadIniString("Eksport", "Adresy", "");

  while (_Adresy != "")
  {
	AnsiString _Mail = _Adresy.SubString(0, _Adresy.Pos(";")- 1);
	AnsiString fileName = "dane.pdr.zip";

	mailWnd->edDo->Text = _Mail;
	mailWnd->edTemat->Text = "Dane do systemu PlanRem";
	mailWnd->m_wiadomosc->Lines->Clear();
	mailWnd->m_wiadomosc->Lines->Add("Za³¹czony plik z danymi: " + fileName);
	mailWnd->m_wiadomosc->Lines->Add("Od : " + mng::Manager::instance().getSystemInfo().getOwner());
	mailWnd->m_zalaczniki->Items->Clear();
	mailWnd->m_zalaczniki->Items->Add(IncludeTrailingPathDelimiter(edKatalog->Text) + fileName);
	mailWnd->setReceivePasswd(true);
	mailWnd->ShowModal();
	_Adresy = _Adresy.SubString(_Adresy.Pos(";")+ 1, _Adresy.Length());
  }
}

//---------------------------------------------------------------------------
bool __fastcall T_ToWizjaJBFRM::prepData(int aID, AnsiString aFileName)
{
  prepDir(edKatalog->Text);

  mng::QueryDB q;
  TStringList* outputData = new TStringList;
  CopierDataSet copyDS;

  outputData->Add(Date());
  outputData->Add(IntToStr(aID));

  jbutils::TMyIni mi;
  AnsiString _Tabelki = mi.ReadIniString("Eksport", "Tabele", "");

  while (_Tabelki != "")
  {
	AnsiString _Tab = _Tabelki.SubString(0, _Tabelki.Pos(";")- 1);
	q.open("SELECT * FROM " + _Tab);
	copyDS.exportData(outputData, q.getDataSet(), _Tab);
	q.close();
	_Tabelki = _Tabelki.SubString(_Tabelki.Pos(";")+ 1, _Tabelki.Length());
	m_progressBar->Position = m_progressBar->Position + 1;
	Application->ProcessMessages();
  }
  if(FileExists(aFileName))
	DeleteFile(aFileName);

  outputData->SaveToFile(aFileName);

  delete outputData;

  return true;
}

//---------------------------------------------------------------------------
void __fastcall T_ToWizjaJBFRM::bbPrepareDataClick(TObject* Sender)
{
  m_progressBar->Visible = true;
  m_progressBar->Maximum = m_lvWydzialy->Items->Count;
  m_progressBar->Position = 0;

  AnsiString fileName = "dane.pdr";
  fileName = IncludeTrailingPathDelimiter(edKatalog->Text) + fileName;

  bool isOK = prepData(0, fileName);

  TFileStream* input = new TFileStream(fileName, fmOpenRead);
  TFileStream* output = new TFileStream(fileName + ".zip", fmCreate);
  TZCompressionStream* zip = new TZCompressionStream(output, zcMax);

  /* Compress data. */
  zip->CopyFrom(input, input->Size);

  /* Free the streams. */
  zip->Free();
  input->Free();
  output->Free();

  m_progressBar->Visible = false;

  mng::MessageDialog::messageBox("Dane zosta³y przygotowane", "Informacja", MB_ICONINFORMATION);
}

//---------------------------------------------------------------------------
void __fastcall T_ToWizjaJBFRM::bbCloseClick(TObject* Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::sbOtworzClick(TObject* Sender)
{
  ShellExecute(GetDesktopWindow(), "open", AnsiString(edKatalog->Text).c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::AdvGlowButton3Click(TObject* Sender)
{
  for(int i = 0; i < m_lvWydzialy->Items->Count; ++i)
	m_lvWydzialy->Items->Item[i]->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::AdvGlowButton5Click(TObject* Sender)
{
  for(int i = 0; i < m_lvWydzialy->Items->Count; ++i)
	m_lvWydzialy->Items->Item[i]->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::AdvGlowButton4Click(TObject* Sender)
{
  for(int i = 0; i < m_lvWydzialy->Items->Count; ++i)
	m_lvWydzialy->Items->Item[i]->Checked = !m_lvWydzialy->Items->Item[i]->Checked;
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::AdvGlowButton6Click(TObject* Sender)
{
  for(int i = 0; i < m_lvWydzialy->Items->Count; ++i)
	m_lvWydzialy->Items->Item[i]->Checked = (m_lvWydzialy->Items->Item[i]->Data == (void*)1);
}
//---------------------------------------------------------------------------

void __fastcall T_ToWizjaJBFRM::sbWybierzClick(TObject* Sender)
{
  edKatalog->Text = jbutils::JBVaria::OpenDir(edKatalog->Text);
}

//---------------------------------------------------------------------------
void __fastcall T_ToWizjaJBFRM::AdvGlowButton2Click(TObject* Sender)
{
  sendEmails();
}
//---------------------------------------------------------------------------
