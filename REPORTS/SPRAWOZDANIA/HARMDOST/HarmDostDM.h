//---------------------------------------------------------------------------

#ifndef HarmDostDMH
#define HarmDostDMH
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
class T_HarmDostDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_HarmDostADO;
	TADOConnection *m_Conn;
public:
		//KLASY POMOCNICZE
		  struct Pars{
		   int  Rok;
		   int  IdWarsztatu;
		   int  IdWydzialu;
		   bool Info;
		  };
		//INTERFEJS
		  void __fastcall open(const Pars& _Pars);
		  void __fastcall saveToMdb(const String & _Path);
		  void __fastcall close(void);
		//KONSTRUKTOR
			  __fastcall T_HarmDostDM(TComponent* Owner);
private:
		//FUNKCJE POMOCNICZE
		  void       __fastcall setMdbPath(const WideString& _Path);
		  mng::Query __fastcall getQuery(void);
		  TDateTime  __fastcall getPlan(const int _Mies);
		//ATRYBUTY
		  Pars m_Pars;
		//STA£E STATYCZNE
		  static const AnsiString M_COL;
		  static const AnsiString M_TABLE;
		  static const AnsiString M_GROUP;
		  static const AnsiString M_ORDER;
};
}// end namespace progzest
//---------------------------------------------------------------------------
#endif
