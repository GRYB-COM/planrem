//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pr_pocztaPopFra.h"
#include "isManager.h"
#include "pr_pocztaSmtpFra.h"
#include "jbutils.h"
#include "Idtext.hpp"
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
#pragma link "AdvSplitter"
#pragma resource "*.dfm"

using namespace jbutils;
using namespace mng;
//---------------------------------------------------------------------------
__fastcall T_pocztaPopFra::T_pocztaPopFra(TComponent* Owner)
	: TprBase0FRM(Owner),on_zapisz(NULL)
{
 TMyIni mi;
 m_pocztaLoginFrm->setKonto(mi.ReadIniString(this->Name,"KontoPOP",""));
 m_pocztaLoginFrm->setSerwer(mi.ReadIniString(this->Name,"SerwerPOP",""));
 m_pocztaLoginFrm->setPort(mi.ReadIniString(this->Name,"PortPOP","110"));
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::FormClose(TObject *Sender, TCloseAction &Action)
{
 TMyIni mi;
 mi.WriteIniString(this->Name,"KontoPOP",m_pocztaLoginFrm->getKonto());
 mi.WriteIniString(this->Name,"SerwerPOP",m_pocztaLoginFrm->getSerwer());
 mi.WriteIniString(this->Name,"PortPOP",m_pocztaLoginFrm->getPort());

  if(m_pocztaLoginFrm->getIdPOP3()->Connected()) m_pocztaLoginFrm->getIdPOP3()->Disconnect();

  m_pocztaLoginFrm->setHaslo("");

  m_listaWiadomosci->Items->Clear();
  m_zalaczniki->Items->Clear();
  m_wiadomosc->Lines->Clear();

}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::registerOnZapisz(bool (__closure *src)(const AnsiString &aFileName,TIdMessage *aMsg,int anItem))
{
	on_zapisz = src;
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::prepLaczePOP3(void)
{
 m_pocztaLoginFrm->getIdPOP3()->Host = m_pocztaLoginFrm->getSerwer();
 m_pocztaLoginFrm->getIdPOP3()->Port = m_pocztaLoginFrm->getPort();
 m_pocztaLoginFrm->getIdPOP3()->Username = m_pocztaLoginFrm->getKonto();
 m_pocztaLoginFrm->getIdPOP3()->Password = m_pocztaLoginFrm->getHaslo();
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::sprawdzPOP3(void)
{
  int iloscWiad;
  prepLaczePOP3();

  if(!m_pocztaLoginFrm->getIdPOP3()->Connected())
  {
	try
    {
	  m_statusBar->SimpleText = "Odbieranie poczty - zestawianie po³¹czenia...";

	  m_pocztaLoginFrm->getIdPOP3()->Connect();
	  m_statusBar->SimpleText = "Odbieranie poczty - po³¹czony";
    }
	catch (...)
	{
	  Beep();
	  m_statusBar->SimpleText = "Odbieranie poczty - b³¹d po³¹czenia";
	  m_statusBar->SimpleText = "B³¹d po³¹czenia z serwerem "+ m_pocztaLoginFrm->getIdPOP3()->Host;
	  mng::Manager::instance().showException();
    }
 }

  if(m_pocztaLoginFrm->getIdPOP3()->Connected())
  {
	iloscWiad = m_pocztaLoginFrm->getIdPOP3()->CheckMessages();

	m_pocztaLoginFrm->getIdPOP3()->Disconnect();
	m_statusBar->SimpleText="Roz³¹czony";

	if(iloscWiad) m_statusBar->SimpleText = "W Twojej skrzynce jest "+IntToStr(iloscWiad)+" wiadomosci";
	else m_statusBar->SimpleText = "Brak wiadomosci w skrzynce";

  }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::pobierzPOP3(bool anOnlyHeaders)
{
 int iloscWiad, iloscZal,zalaczniki;
 TListItem *ListItem;

 m_listaWiadomosci->Items->Clear();
 m_zalaczniki->Items->Clear();
 m_wiadomosc->Lines->Clear();
 IdMessage1->Clear();

 prepLaczePOP3();

 if(!m_pocztaLoginFrm->getIdPOP3()->Connected())
 {
	try
	{
	  m_statusBar->SimpleText="Odbieranie poczty - zestawianie po³¹czenia...";

	  m_pocztaLoginFrm->getIdPOP3()->Connect();
	  m_statusBar->SimpleText="Odbieranie poczty - po³¹czony";
	}
	 catch (Exception &e)
	{
	  Beep();
	  Manager::instance().showException();
	  m_statusBar->SimpleText = "Odbieranie poczty - b³¹d po³¹czenia z serwerem "+ m_pocztaLoginFrm->getIdPOP3()->Host;
	}
 }

 if(m_pocztaLoginFrm->getIdPOP3()->Connected())
 {
	m_pocztaLoginFrm->setReadOnly(true);

	iloscWiad = m_pocztaLoginFrm->getIdPOP3()->CheckMessages();

	for(int i = 0; i < m_listaWiadomosci->Items->Count; ++i)
	{
		delete m_listaWiadomosci->Items->Item[i]->Data;
		m_listaWiadomosci->Items->Item[i]->Data = NULL;
	}

	for(int i = 1; i <= iloscWiad; ++i)
	{
	  TIdMessage *idMess = NULL;
	  idMess = new TIdMessage(m_listaWiadomosci);
	  m_statusBar->SimpleText="Odbieranie poczty - po³¹czony ("+IntToStr(i)+"/"+IntToStr(iloscWiad)+")";
	  Application->ProcessMessages();
	  idMess->Clear();

	  if(anOnlyHeaders) m_pocztaLoginFrm->getIdPOP3()->RetrieveHeader(i,idMess);
	  else m_pocztaLoginFrm->getIdPOP3()->Retrieve(i,idMess);

	  int rozmiar = m_pocztaLoginFrm->getIdPOP3()->RetrieveMsgSize(i);

	  iloscZal = idMess->MessageParts->Count;

	  ListItem = m_listaWiadomosci->Items->Add();
	  ListItem->Caption = idMess->From->Address;
	  ListItem->SubItems->Add(idMess->Subject);
	  ListItem->SubItems->Add(idMess->Date.DateTimeString());

	  zalaczniki = 0;
	  for(int j = 0; j < iloscZal; ++j)
	  {
		 if(idMess->MessageParts->Items[j]->DisplayName == "TIdAttachmentFile"
		   || idMess->MessageParts->Items[j]->DisplayName == "TIdAttachmentMemory") ++zalaczniki;
	  }
	  ListItem->SubItems->Add(IntToStr(zalaczniki));

	  ListItem->SubItems->Add(IntToStr(rozmiar/(int)1024)+"KB");

	  ListItem->Data = idMess;
	}

	m_statusBar->SimpleText = "Poczta odebrana - po³¹czony z serwerem";

  }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::rozlaczPOP3(void)
{

 if(m_pocztaLoginFrm->getIdPOP3()->Connected())
 {
  m_listaWiadomosci->Items->Clear();
  m_zalaczniki->Items->Clear();
  m_wiadomosc->Lines->Clear();
  m_pocztaLoginFrm->setReadOnly(false);

  m_pocztaLoginFrm->getIdPOP3()->Disconnect();
  m_statusBar->SimpleText="Roz³¹czony";
  }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::m_listaWiadomosciSelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
  TListItem *myItem = m_listaWiadomosci->Selected;
  // if(Selected && Item)
   if(myItem)
   {
		m_wiadomosc->Lines->Clear();
		m_zalaczniki->Clear();

		IdMessage1 = (TIdMessage*)myItem->Data;

		for(int i = 0; i < IdMessage1->MessageParts->Count; ++i)
		{
			if(IdMessage1->MessageParts->Items[i]->DisplayName=="TIdText")
			{
			   TIdText *IdText = (TIdText*)IdMessage1->MessageParts->Items[i];
			   m_wiadomosc->Lines->AddStrings(IdText->Body);
			}

			if(IdMessage1->MessageParts->Items[i]->DisplayName == "TIdAttachmentFile"
			   || IdMessage1->MessageParts->Items[i]->DisplayName == "TIdAttachmentMemory")
			{
			  TIdAttachment *zal = (TIdAttachment*)IdMessage1->MessageParts->Items[i];
			  m_zalaczniki->Items->Add(zal->FileName);
            }
        }

   }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::saveZalacznik(const AnsiString &aFileName)
{
 int j = 0;
 /*biorê z IdMessage1 który jest wype³niany m_listaWiadomosciSelectItem*/
 for(int i = 0; i < IdMessage1->MessageParts->Count; ++i)
 {
	if(IdMessage1->MessageParts->Items[i]->DisplayName=="TIdAttachmentFile"
	  || IdMessage1->MessageParts->Items[i]->DisplayName=="TIdAttachmentMemory")
	{
	  TIdAttachment *zal = (TIdAttachment*)IdMessage1->MessageParts->Items[i];
	  if(m_zalaczniki->ItemIndex==j) zal->SaveToFile(aFileName);

	  j++;
	}
 }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::m_saveDialogCanClose(TObject *Sender, bool &CanClose)

{
 saveZalacznik(m_saveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::bbZapiszClick(TObject *Sender)
{
	if(m_zalaczniki->ItemIndex != -1)
	{
	   bool kontynuuj = true;

	   if(on_zapisz != NULL)
	   	kontynuuj = on_zapisz(m_zalaczniki->Items->Strings[m_zalaczniki->ItemIndex],IdMessage1,m_zalaczniki->ItemIndex);

	   if(kontynuuj)
	   {
		   m_saveDialog->FileName = m_zalaczniki->Items->Strings[m_zalaczniki->ItemIndex];
		   m_saveDialog->Execute();  /*m_saveDialogCanClose zajmuje sie reszt¹*/
       }
	}
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaPopFra::bbUsunClick(TObject *Sender)
{
  bool flaga=false;

  if(! m_pocztaLoginFrm->getIdPOP3()->Connected())
  {
    try
    {
	  m_statusBar->SimpleText="Zestawianie po³¹czenia z serwerem...";

	  m_pocztaLoginFrm->getIdPOP3()->Connect();
	  m_statusBar->SimpleText="Po³¹czony";
    }
     catch (Exception &e)
    {
	  Beep();
	  m_statusBar->SimpleText="B³¹d po³¹czenia z serwerem";
	  Manager::instance().showException();
	}
 }
	try
	{
	  if(m_pocztaLoginFrm->getIdPOP3()->Connected())
		for(int i = 0; i< m_listaWiadomosci->Items->Count; ++i)
		  if(m_listaWiadomosci->Items->Item[i]->Checked)
		  {
			m_pocztaLoginFrm->getIdPOP3()->Delete(i+1);
			flaga=true;
		  }
    }
     catch (Exception &e)
    {
      Beep();
	  m_statusBar->SimpleText = "Usuwanie wiadomoœci - b³¹d po³¹czenia";
	  Manager::instance().showException();
    }

  if(flaga)
  {
   m_pocztaLoginFrm->getIdPOP3()->Disconnect();
   bbOdbierzClick(Sender);
  }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::bbOdpowiedzClick(TObject *Sender)
{
 bool flaga = false;
 int i = 0;

 for(int i = 0; i< m_listaWiadomosci->Items->Count; ++i)
	if(m_listaWiadomosci->Items->Item[i]->Checked)
	{
		flaga = true;
		break;
	}

 T_pocztaSmtpFra *odpFm = new T_pocztaSmtpFra(this);
 try
 {
	if(flaga)
	 {
		//--- pola formularza ---
		odpFm->edDo->Text = m_listaWiadomosci->Items->Item[i]->Caption;
		odpFm->edTemat->Text="ODP: "+(*(*m_listaWiadomosci->Items)[i]->SubItems)[0];

		//--- ustawienia serwera ---
		odpFm->m_pocztaLoginFrm->setKonto(m_pocztaLoginFrm->getKonto());
		odpFm->m_pocztaLoginFrm->setHaslo(m_pocztaLoginFrm->getHaslo());

     	odpFm->ShowModal();
	  }
	  else
	  {
		ShowMessage("Nie wybrano wiadomoœci");
	  }
  }
  __finally
  {
	delete odpFm;
  }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::bbPrzeslijClick(TObject *Sender)
{
 bool flaga = false;
 int i;

 for(int i = 0; i< m_listaWiadomosci->Items->Count; ++i)
	if(m_listaWiadomosci->Items->Item[i]->Checked)
	{
		flaga = true;
		break;
	}

 T_pocztaSmtpFra *odpFm = new T_pocztaSmtpFra(this);
 try
 {
   if(flaga)
   {
	//--- pola formularza ---
	 odpFm->m_wiadomosc->Lines->Add(" ");
	 odpFm->m_wiadomosc->Lines->Add(" ----------------------------- ");
	 odpFm->edTemat->Text="ODP: "+(*(*m_listaWiadomosci->Items)[i]->SubItems)[0];
	 odpFm->m_wiadomosc->Lines->Add("Dnia  "+((*(*m_listaWiadomosci->Items)[i]->SubItems)[1])+"  "+m_listaWiadomosci->Items->Item[i]->Caption+"  napisal(a):");
	 odpFm->m_wiadomosc->Lines->Add(" ");
	 odpFm->m_wiadomosc->Lines->Add(m_wiadomosc->Text);
	 odpFm->m_wiadomosc->Lines->Add(" ");
	 odpFm->m_wiadomosc->Lines->Add(" ----------------------------- ");
	 odpFm->m_wiadomosc->Lines->Add(" ");


	 for(int i = 0; i < IdMessage1->MessageParts->Count; ++i)
	 {
		if(IdMessage1->MessageParts->Items[i]->DisplayName=="TIdAttachmentFile"
				|| IdMessage1->MessageParts->Items[i]->DisplayName=="TIdAttachmentMemory")
		{
		  TIdAttachment *zal = (TIdAttachment*)IdMessage1->MessageParts->Items[i];
		  zal->SaveToFile(zal->FileName);
		}
	 }

	 odpFm->m_zalaczniki->Items->Text = m_zalaczniki->Items->Text;

	 //--- ustawienia serwera ---
	 odpFm->m_pocztaLoginFrm->setKonto(m_pocztaLoginFrm->getKonto());
	 odpFm->m_pocztaLoginFrm->setHaslo(m_pocztaLoginFrm->getHaslo());


	 odpFm->ShowModal();
   }
   else
   {
	 ShowMessage("Nie wybrano wiadomosci");
   }
 }
 __finally
 {
	delete odpFm;
 }
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::bbRozlaczClick(TObject *Sender)
{
 rozlaczPOP3();
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaPopFra::bbOdbierzClick(TObject *Sender)
{
 pobierzPOP3();
}
//---------------------------------------------------------------------------

void __fastcall T_pocztaPopFra::bbSprawdzClick(TObject *Sender)
{
// sprawdzPOP3();
 pobierzPOP3(true);
}
//---------------------------------------------------------------------------
void __fastcall T_pocztaPopFra::bbNowaClick(TObject *Sender)
{
 T_pocztaSmtpFra *odpFm = new T_pocztaSmtpFra(this);
 try
 {
	 //--- ustawienia serwera ---
	 odpFm->m_pocztaLoginFrm->setKonto(m_pocztaLoginFrm->getKonto());
	 odpFm->m_pocztaLoginFrm->setHaslo(m_pocztaLoginFrm->getHaslo());
	 odpFm->ShowModal();
 }
 __finally
 {
	delete odpFm;
 }
}
//---------------------------------------------------------------------------

