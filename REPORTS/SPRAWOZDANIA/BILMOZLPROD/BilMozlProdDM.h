//---------------------------------------------------------------------------

#ifndef BilMozlProdDMH
#define BilMozlProdDMH
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
class T_BilMozlProdDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_MozlRemADO;
	TADOConnection *m_Conn;
	TIntegerField *m_ClientID_WYDZIALU;
	TStringField *m_ClientKOD_WYDZIALU;
	TStringField *m_ClientNAZ_WYDZIALU;
	TIntegerField *m_ClientID_WARSZTATU;
	TStringField *m_ClientKOD_WARSZTATU;
	TStringField *m_ClientNAZ_WARSZTATU;
	TCurrencyField *m_ClientL_PROD_CYWIL;
	TCurrencyField *m_ClientL_PROD_KADRA;
	TCurrencyField *m_ClientRBH_NOM_CYWIL;
	TCurrencyField *m_ClientRBH_NOM_KADRA;
	TCurrencyField *m_ClientRBH_PROD_CYWIL;
	TCurrencyField *m_ClientRBH_PROD_KADRA;
	TCurrencyField *m_ClientRBH_NPROD_CYWIL;
	TCurrencyField *m_ClientRBH_NPROD_KADRA;
	TCurrencyField *m_ClientRBH_EF_CYWIL;
	TCurrencyField *m_ClientRBH_EF_KADRA;
	TCurrencyField *m_ClientRBH_NOM_RAZEM;
	TCurrencyField *m_ClientRBH_NPROD_RAZEM;
	TCurrencyField *m_ClientRBH_PROD_RAZEM;
	TADOTable *m_MozlRemParADO;
	TAggregateField *m_ClientL_CYWIL_SUM;
	TAggregateField *m_ClientL_KADRA_SUM;
	TAggregateField *m_ClientRBH_NPROD_KADRA_SUM;
	TAggregateField *m_ClientRBH_NPROD_CYWIL_SUM;
	TCurrencyField *m_ClientL_CYWIL;
	TCurrencyField *m_ClientL_KADRA;
	void __fastcall m_ClientCalcFields(TDataSet *DataSet);
public:
		//KLASY POMOCNICZE
		  struct Pars{
		   int Rok;
		   int IdWarsztatu;
		   int IdWydzialu;
		   int MiesOd;
		   int MiesDo;
		  };
		//INTERFEJS
		  void __fastcall open(const Pars& _Pars);
		  void __fastcall saveToMdb(const String & _Path);
		  void __fastcall close(void);
		//KONSTRUKTOR
			  __fastcall T_BilMozlProdDM(TComponent* Owner);
private:
		//FUNKCJE POMOCNICZE
		  void       __fastcall setMdbPath(const WideString& _Path);
		  mng::Query __fastcall getQuery(void);
		  void       __fastcall saveParsToMdb(void);
		  String     __fastcall getTytul(void);
		  String     __fastcall getPodTytul(void);
		  int        __fastcall getKwartal(void);
		  String     __fastcall getKwartal(const int _Nr);
		//ATRYBUTY
		  Pars m_Pars;
		//STA£E
		  static const AnsiString M_COL_LIST_SQL;
		  static const AnsiString M_TABLE_REF_SQL;
		  static const AnsiString M_GROUP_LIST_SQL;
};
}// end namespace progzest
//---------------------------------------------------------------------------
#endif
