//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "platform.h"
#include "isManager.h"
#include "jbutils.h"
#include <isUpdDB.h>
#include "MANAGER\manager_db.h"
#include "MANAGER\various_man.h"
#include <isVaria.h>
#include "globfunc.h"
#include "Translator.h"
//#include <isXml.h>
//#include <xml\xml_serializer.h>
String Platform::m_MessErr;
String Platform::m_DetErr;
String Platform::m_Det1Err;
//---------------------------------------------------------------------------

#pragma package(smart_init)

using namespace mng;


bool Platform::Initialize()
{
  bool       _Res(false);
  AnsiString _ErrMsg;
  try{
   // nale�y pami�ta�, �eby obiekt dmMainIBX by� utworzony przed wywo�aniem
   // funkcji Platform::Initialize()
	 _ErrMsg = "B��d inicjalizacji g��wnego modu�u programu! ";
	 Manager::instance().initialize(mng::SI_KASA,ConnectionInfo::cltIBX);
   // wczytanie konfiguracji
	 AnsiString _Path = ExtractFileDir( Application->ExeName ) + "//Test.xml";
	 _ErrMsg ="B��d wczytania pliku konfiguracyjnego!";
	 Manager::instance().loadConfigurationNC(  _Path );
   //otwarcie po��czenia z baz� danych (zgodnie z tym, co zosta�o wczytane lini� wy�ej)
	 _ErrMsg ="B��d po��czenia z baz� danych!";
	 _Res = Manager::instance().selectLink();
   if(_Res)
   {
   //po��czenie z baz�
	 Manager::instance().connect();
	 _Res = Manager::instance().isConnected();
   //AKTUALIZACJA BAZY
	  if(_Res)
	  {
	   updateIsRejestr();
	   AnsiString files;
	   udb::DatabaseUpdater updater;
	   updater.updateDatabase(files);
	   //AKTYWACJA NETPREVA
		 jbutils::NetPrev() ;
	   //logowanie
		_Res = Manager::instance().login();
      }
	}
   }
   catch(Exception& exc)
   {
	_Res=false;
	showException(NULL,&exc,_ErrMsg);
   }
   return _Res;
}
//---------------------------------------------------------------------------
void Platform::updateIsRejestr(void)
{
   udb::DatabaseUpdater updater;
   QueryDB _Q("select * from is_rejestr where id_systemu = 256");
   _Q.open();
   if(_Q.isEmpty())
   {
	QueryDB().execute("INSERT INTO IS_REJESTR VALUES (NULL, 256, 'Plan remont�w', 'ADMIN', NULL, NULL, NULL, '111025', NULL, NULL)");
   }
   if(!updater.checkVersionFormat())
   {
	 QueryDB().execute("update IS_REJESTR set DBVERSION = '111025' where id_systemu = 256");
   }
}
//---------------------------------------------------------------------------
void Platform::Terminate()
{
   // zako�czenie korzystania z us�ug zarz�dcy
   Manager::instance().terminate();
}
//---------------------------------------------------------------------------
void Platform::showException(TObject* Sender, Exception * E, const AnsiString& __Det)
{
 E->Message = Translator::run(E->Message);
 m_Det1Err = E->Message;
 if(dynamic_cast<EDBEditError*>(E) )
 {
 m_MessErr= "B��d przy edycji pola";
  TDBEdit * _Ed =dynamic_cast<TDBEdit*>(Sender);
  if(_Ed)
  {
   m_MessErr +=": ";
   m_MessErr +=_Ed->Field->DisplayLabel;
  }
   mng::MessageDialog::warning(m_MessErr, "B��D EDYCJI");

 }
 else if(dynamic_cast<EConvertError*>(E))
 {
  m_MessErr ="Niepoprawna warto��";
  TDBEdit * _Ed =dynamic_cast<TDBEdit*>(Sender);
  if(_Ed)
  {
   m_MessErr =_Ed->Text;
   m_MessErr += " nie jest poprawn� warto�ci� dla pola: ";
   m_MessErr +=_Ed->Field->DisplayLabel;
  }
   mng::MessageDialog::warning(m_MessErr, "B��D EDYCJI");
  }
  else
  {
	TComponent* _C = dynamic_cast<TComponent*>(Sender);
	if(_C)
	{
	 E->Message = E->Message + AnsiString("\nSender: ") + _C->Name;
	 if(_C->Owner) E->Message = E->Message + AnsiString("\nOwner: ") + _C->Owner->Name;
	}
	mng::ISException::Info ise(Sender,E);
	mng::Manager::instance().logException(ise);
   m_MessErr = ise.getMessage();
	if(__Det.IsEmpty())
	{
	 m_DetErr = ise.getDetails();
	 int _Pos = m_DetErr.Pos('\n');
	 if(_Pos >0 )
	 {
	  m_DetErr = m_DetErr.SubString(1,_Pos);
	 }

	}
	else
	{
	 m_DetErr = __Det;
	}
	ise.display(m_MessErr,m_DetErr);
  }

 }
 bool Platform::printErr(void)
 {

	bool printed=true;

   mng::CursorMan cm(crHourGlass);

   try
   {
	  // Drukowanie szczeg�owego opisu b��du celem przefaksowania do nas
	  TPrinter* prn=Printer();
	  TCanvas*  cv=prn->Canvas;

	  prn->BeginDoc();

      // Og�lny nag��wek
	  cv->Font->Name    = "Arial";
	  cv->Font->Size    = 12;
      cv->Font->Charset = EASTEUROPE_CHARSET;
      cv->Font->Style   = cv->Font->Style << fsBold;

      int row_height=abs(cv->Font->Height) + 20;
      int x_pos=200;
      int y_pos=300;

	  cv->TextOut(x_pos,y_pos,"Rejestr Remont�w");
	  y_pos += row_height;
	  cv->TextOut(x_pos,y_pos,"OPIS B��DU");
	  y_pos += row_height;
	  const SystemInfo& si=Manager::instance().getSystemInfo();
	  cv->TextOut(x_pos,y_pos,String("Wersja aplikacji:") +si.getSysVersion());
	  y_pos += row_height;
	  cv->TextOut(x_pos,y_pos,String("Szczeg�owy opis b��du: ") +si.getDbVersion());
	  y_pos += row_height;



      // Szczeg�owa tre�� opisu
      cv->Font->Style = cv->Font->Style >> fsBold;
      cv->Font->Size  = 10;

	  row_height = abs(cv->Font->Height) + 10;
	  cv->TextOut(x_pos,y_pos,m_MessErr);
	  y_pos += row_height;
	  cv->TextOut(x_pos,y_pos,m_DetErr);
	  y_pos += row_height;
	  Globfunc::StringContainer _Cont = Globfunc::explode(m_Det1Err,"\n");
	  x_pos +=40;
	  for(Globfunc::StringContainer::const_iterator _It = _Cont.begin(); _It !=_Cont.end(); _It++)
	  {
	   cv->TextOut(x_pos,y_pos,*_It);
	   y_pos += row_height;
	  }

	  y_pos += 2*row_height;
	  cv->TextOut(x_pos,y_pos,"Kontakt w sprawie b��du:  chor. Adam Jaworski nr tel. 862272");
	  prn->EndDoc();
   }
   catch(...)
   {
      printed = false;
   }
 return printed;
}


