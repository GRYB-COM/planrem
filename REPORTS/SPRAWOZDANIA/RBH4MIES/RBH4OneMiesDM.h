//---------------------------------------------------------------------------

#ifndef RBH4OneMiesDMH
#define RBH4OneMiesDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <ADODB.hpp>
namespace mng { class Query; }
//---------------------------------------------------------------------------
namespace progzest{
class T_RBH4OneMiesDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOQuery *m_WorkADO;
	TADOTable *m_RBH4OneMiesADO;
	TADOConnection *m_Conn;
	TClientDataSet *m_Client;
	TIntegerField *m_ClientID_KOMORKI;
	TStringField *m_ClientKOD_WARSZTATU;
	TStringField *m_ClientNAZWA;
	TCurrencyField *m_ClientRBH_NOM;
	TCurrencyField *m_ClientRBH_URLOP;
	TCurrencyField *m_ClientRBH_PRZERWA;
	TCurrencyField *m_ClientRBH_CHOROBA;
	TCurrencyField *m_ClientRBH_SLUZBA;
	TCurrencyField *m_ClientRBH_SZKOLENIE;
	TCurrencyField *m_ClientRBH_NPROD;
	TCurrencyField *m_ClientRBH_PROD;
	TCurrencyField *m_ClientETAT_PR;
	TIntegerField *m_ClientID_WYDZIALU;
	TStringField *m_ClientKOD_WYDZIALU;
	TStringField *m_ClientNAZ_WYDZIALU;
public:
		//KLASY POMOCNICZE
		  struct Pars{
		   int  IdWydzialu;
		   int  IdWarsztatu;
		   int  Rok;
		   int  Miesiac;
		   bool ToMdb;
		  };
		//INTERFEJS
		  void __fastcall open(const Pars& _Pars);
		  void __fastcall saveToMdb(const String & _Path);
		  void __fastcall close(void);
		//KONSTRUKTOR
			  __fastcall T_RBH4OneMiesDM(TComponent* Owner);
private:
		//FUNKCJE POMOCNICZE
		  void       __fastcall setMdbPath(const WideString& _Path);
		  mng::Query __fastcall getQuery(void);
		//ATRYBUTY
          Pars m_Pars;
};
}// end namespace progzest
//---------------------------------------------------------------------------
#endif
