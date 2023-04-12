//---------------------------------------------------------------------------
#pragma hdrstop
#include "ExportMaker.h"
#include <MANAGER\query_db.h>
#include <jbutils\jb_ini_my.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
void ExportMaker::run(const String& _File )
{
 /* mng::QueryDB q;
  jbutils::TMyIni mi(_File);
  TStringList* dane = new TStringList;

	kCopierDataSet copyDS;

	m_progressBar->Position = 0;

	dane->Add(Date());

	AnsiString _Tabelki = mi.ReadIniString("Eksport", "Tabele", "");

	Globfunc::StringContainer _Tables = Globfunc::explode(_Tabelki,";");

	AnsiString _Tab,_Alias, _Where, _SQL;
	TReplaceFlags _Flag;
	_Flag<<rfReplaceAll;
	for(int i=0; i < _Tables.size(); ++i)
	{
	 _Tab   = _Tables[i];
	 _Where = mi.ReadIniString("Eksport - " + _Tab, "Warunek", "");
	 _Alias = mi.ReadIniString("Eksport - " + _Tab, "Alias", "");
	 int _Rok     = mi.ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear());
	 int _IdWydz  = mi.ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³",1);
	 _Where = ReplaceStr(_Where, "@ROK#",_Rok);
	 _Where = ReplaceStr(_Where, "@WYDZIAL#",_IdWydz);
	 _SQL = AnsiString("SELECT * FROM ") + _Tab + AnsiString("  ") + _Alias;
	 if(!_Where.IsEmpty())_SQL += AnsiString(" WHERE ") + _Where;
		q.open(_SQL);
	  copyDS.exportData(dane, q.getDataSet(), _Tab);
	  q.close();
	  m_progressBar->Position = m_progressBar->Position + 1;
	  Application->ProcessMessages();
	}

	dane->SaveToFile(m_SaveDialog->FileName);

	TFileStream* input = new TFileStream(m_SaveDialog->FileName, fmOpenRead);
	TFileStream* output = new TFileStream(m_SaveDialog->FileName + ".zip", fmCreate);
	TZCompressionStream* zip = new TZCompressionStream(output, zcMax);

	/* Compress data. */ /*
	zip->CopyFrom(input, input->Size);

	/* Free the streams. *//*
	zip->Free();
	input->Free();
	output->Free();

	delete dane;

	//czy wyslac poczt¹...
	if(mng::MessageDialog::messageBox("Czy wys³aæ dane poczt¹ elektroniczn¹?", "Pytanie", MB_ICONQUESTION | MB_YESNO) == IDYES)
	{
	  jbutils::TMyIni mi;
	  AnsiString _Adresy = mi.ReadIniString("Eksport", "Adresy", "");

	  while (_Adresy != "")
	  {

		std::auto_ptr<T_pocztaSmtpFra>mailWnd(new T_pocztaSmtpFra(Owner));
		//mailWnd->m_MessageGroup->Enabled = false;

		AnsiString _Mail = _Adresy.SubString(0, _Adresy.Pos(";")- 1);
		mailWnd->edDo->Text = _Mail;
		mailWnd->edTemat->Text = "Dane z systemu Rejestr Remontów";
		mailWnd->m_wiadomosc->Lines->Clear();
		AnsiString plikZalacznika = m_SaveDialog->FileName + ".zip"; //m_SaveDialog->FileName
		mailWnd->m_wiadomosc->Lines->Add("Za³¹czony plik z danymi: " + plikZalacznika);
		mailWnd->m_wiadomosc->Lines->Add("Od : " + mng::Manager::instance().getSystemInfo().getOwner());
		/* mailWnd->m_wiadomosc->Lines->Add("Komórki organizacyjne : ");
		for(int w = 0; w < wydzialy->Count; ++w)
		mailWnd->m_wiadomosc->Lines->Add(wydzialy->Strings[w]); *//*
		mailWnd->m_zalaczniki->Items->Clear();
		mailWnd->m_zalaczniki->Items->Add(plikZalacznika);
		//mailWnd->setReceivePasswd(true);
		mailWnd->ShowModal();
		_Adresy = _Adresy.SubString(_Adresy.Pos(";")+ 1, _Adresy.Length());
	  }
	}
  }

  m_progressBar->Visible = false;
  paMain->Enabled = true;   */
}
//---------------------------------------------------------------------------