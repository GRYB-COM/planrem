//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pr_pocztaSmtpFra.h"
#include <IdAttachmentFile.hpp>
#include "jbutils.h"
#include "pr_pocztaPopFra.h"
#include "ismanager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "pr_kBase0FRM"
#pragma link "pr_pocztaLoginFrm"
#pragma link "IdBaseComponent"
#pragma link "IdMessage"
#pragma link "AdvGlowButton"
#pragma link "AdvGroupBox"
#pragma link "AdvSmoothPanel"
#pragma link "AdvOfficeStatusBar"
#pragma resource "*.dfm"
using namespace jbutils;
using namespace mng;
//---------------------------------------------------------------------------
__fastcall T_pocztaSmtpFra::T_pocztaSmtpFra(TComponent* Owner)
	: TprBase0FRM(Owner),m_receivePasswd(false)
{
 TMyIni mi;
 m_pocztaLoginFrm->setKonto(mi.ReadIniString(this->Name,"KontoSMTP",""));
 m_pocztaLoginFrm->setSerwer(mi.ReadIniString(this->Name,"SerwerSMTP",""));
 m_pocztaLoginFrm->setPort(mi.ReadIniString(this->Name,"PortSMTP","25"));


 DragAcceptFiles(this->Handle, true);
}
//---------------------------------------------------------------------------
__fastcall T_pocztaSmtpFra::~T_pocztaSmtpFra()
{
 DragAcceptFiles (this->Handle, false);
}
//---------------------------------------------------------------------------
void T_pocztaSmtpFra::setReceivePasswd(bool aVal)
{
  m_receivePasswd = aVal;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaSmtpFra::prepLaczeSMTP(void)
{
 m_pocztaLoginFrm->getIdSMTP()->Host = m_pocztaLoginFrm->getSerwer();
 m_pocztaLoginFrm->getIdSMTP()->Port = m_pocztaLoginFrm->getPort();
 m_pocztaLoginFrm->getIdSMTP()->Username = m_pocztaLoginFrm->getKonto();
 m_pocztaLoginFrm->getIdSMTP()->Password = m_pocztaLoginFrm->getHaslo();
// m_pocztaLoginFrm->getIdSMTP()->AuthenticationType = atLogin;
 m_pocztaLoginFrm->getIdSMTP()->AuthType = satDefault;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaSmtpFra::FormClose(TObject *Sender, TCloseAction &Action)

{
 TMyIni mi;
 mi.WriteIniString(this->Name,"KontoSMTP",m_pocztaLoginFrm->getKonto());
 mi.WriteIniString(this->Name,"SerwerSMTP",m_pocztaLoginFrm->getSerwer());
 mi.WriteIniString(this->Name,"PortSMTP",m_pocztaLoginFrm->getPort());

 if(!m_receivePasswd) m_pocztaLoginFrm->setHaslo("");

  m_zalaczniki->Items->Clear();
  m_wiadomosc->Lines->Clear();

  edDo->Text="";
  edTemat->Text="";
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaSmtpFra::bbDodajClick(TObject *Sender)
{
 if(m_openDialog->Execute())
	 m_zalaczniki->Items->Add(m_openDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaSmtpFra::bbWyslijClick(TObject *Sender)
{
 IdMessage1->Clear();

 if(m_pocztaLoginFrm->getSerwer() == "" /*|| m_pocztaLoginFrm->getPort() == ""*/
	 || m_pocztaLoginFrm->getKonto() == "" || edDo->Text == ""
	 /*|| edNadawca->Text==""*/)
 {
	ShowMessage("Prosze wypelnic wszystkie pola...");
 }
 else
 {
  prepLaczeSMTP();

  if(!m_pocztaLoginFrm->getIdSMTP()->Connected())
  {
    try
    {
	  m_statusBar->SimpleText = "Zestawienie po³¹czenia z serwerem...";

	  m_pocztaLoginFrm->getIdSMTP()->Connect();
	  m_statusBar->SimpleText="Po³¹czony...";
    }
     catch (Exception &e)
    {
      Beep();
	  Manager::instance().showException();
	  m_statusBar->SimpleText="B³¹d po³¹czenia z serwerem "+ m_pocztaLoginFrm->getIdSMTP()->Host;
    }
 }

  if(m_pocztaLoginFrm->getIdSMTP()->Connected())
  {
	IdMessage1->From->Text = m_pocztaLoginFrm->getKonto();//edNadawca->Text;
	IdMessage1->Subject = edTemat->Text;
	IdMessage1->Recipients->EMailAddresses = edDo->Text;
	IdMessage1->Body->Text = m_wiadomosc->Lines->Text;

	for(int i = 1; i <= m_zalaczniki->Items->Count; ++i)
	{
	   TIdAttachmentFile(IdMessage1->MessageParts,m_zalaczniki->Items->Strings[i-1]);
	}

	//IdMessage1->ContentType = "text/plain";
    //IdMessage1->CharSet     = "charset=iso-8859-1";

	m_statusBar->SimpleText = "Wysy³anie wiadomoœci ...";

    try
    {
	  m_pocztaLoginFrm->getIdSMTP()->Send(IdMessage1);

	  m_statusBar->SimpleText = "Wiadomoœæ wys³ana";
      IdMessage1->Clear();

	  edDo->Clear();
	  edTemat->Clear();
	  m_wiadomosc->Clear();


	  m_pocztaLoginFrm->getIdSMTP()->Disconnect();
	  m_statusBar->SimpleText="Roz³¹czony";

	  T_pocztaPopFra *pop = dynamic_cast<T_pocztaPopFra *>(Owner);
	  if(pop != NULL)
	  {
		  for(int i = 0; i < m_zalaczniki->Items->Count; ++i)
		  {
			bool flaga = false;
			for(int j = 0; j < pop->m_zalaczniki->Items->Count; ++j)
				if(m_zalaczniki->Items->Strings[i] == pop->m_zalaczniki->Items->Strings[j]) flaga=true;

			if(flaga==true)
			  DeleteFile(m_zalaczniki->Items->Strings[i]);
		  }
	  }

	  m_zalaczniki->Clear();

      Close();
	  //ShowMessage("Wiadomoœæ wys³ana");

    }
     catch (Exception &e)
    {
       Beep();
	   Manager::instance().showException();
	   m_statusBar->SimpleText = "B³¹d przy wysy³aniu wiadomoœci !!!";
       IdMessage1->Clear();
    }
  }
}
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaSmtpFra::bbUsunClick(TObject *Sender)
{
 m_zalaczniki->DeleteSelected();//ItemIndex
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaSmtpFra::ApplicationEvents1Message(tagMSG &Msg, bool &Handled)

{
 DWORD wParam = Msg.wParam;
 switch (Msg.message)
 {
  case WM_DROPFILES:
  {
	//Iloœæ przesy³anych plików
	int TotalNumberOfFiles = DragQueryFile ((HDROP)wParam, 0xFFFFFFFF, NULL, 0);
	for(int i=0; i<TotalNumberOfFiles; i++)
	{
	char * buffer;
	int nFileLength=0;
	//Dla ka¿dego z plików pobie¿ jego d³ugoœæ
	nFileLength = DragQueryFile ((HDROP)wParam, i , NULL, 0)+1;
	buffer = new char[nFileLength];
	//Zapisz nazwe pliku do zmiennej buffer
	DragQueryFile ((HDROP)wParam , i, buffer, nFileLength);
	m_zalaczniki->Items->Add(buffer);
	delete[] buffer;
	}
  break;
  }
 }
}
//---------------------------------------------------------------------------

