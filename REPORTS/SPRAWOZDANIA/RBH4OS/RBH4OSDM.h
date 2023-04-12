//---------------------------------------------------------------------------

#ifndef RBH4OSDMH
#define RBH4OSDMH
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
class T_RBH4OSDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_RBH4OSADO;
	TADOConnection *m_Conn;
	TIntegerField *m_ClientID_KOMORKI;
	TStringField *m_ClientNAZWA;
	TIntegerField *m_ClientID_OSOBY;
	TStringField *m_ClientSTOPIEN;
	TStringField *m_ClientIMIE;
	TStringField *m_ClientNAZWISKO;
	TCurrencyField *m_ClientRBH_NOM;
	TCurrencyField *m_ClientRBH_URLOP;
	TCurrencyField *m_ClientRBH_PRZERWA;
	TCurrencyField *m_ClientRBH_CHOROBA;
	TCurrencyField *m_ClientRBH_SLUZBA;
	TCurrencyField *m_ClientRBH_SZKOLENIE;
	TCurrencyField *m_ClientRBH_NPROD;
	TCurrencyField *m_ClientRBH_PROD;
	TCurrencyField *m_ClientRBH_EFF;
	TStringField *m_ClientKOD_WARSZTATU;
	TStringField *m_ClientSTANOWISKO;
	TIntegerField *m_ClientKIEROWNIK;
	TStringField *m_ClientETAT_PR;
public:
		//KLASY POMOCNICZE
		  struct Pars{
		   int Rok;
		   int IdWarsztatu;
		   int IdWydzialu;
		  };
		//INTERFEJS
		  void __fastcall open(const Pars& _Pars);
		  void __fastcall saveToMdb(const String & _Path);
		  void __fastcall close(void);
		//KONSTRUKTOR
			  __fastcall T_RBH4OSDM(TComponent* Owner);
private:
		//FUNKCJE POMOCNICZE
		  void       __fastcall setMdbPath(const WideString& _Path);
		  mng::Query __fastcall getQuery(void);
		//ATRYBUTY
		  Pars m_Pars;
		//STA£E
		  static const AnsiString M_COL_LIST;
		  static const AnsiString M_TABLE_REF;
};
}// end namespace progzest
//---------------------------------------------------------------------------
#endif
