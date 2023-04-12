//---------------------------------------------------------------------------

#ifndef PlanKwartZadDMH
#define PlanKwartZadDMH
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
class T_PlanKwartZadDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_PlanKwartZadADO;
	TADOConnection *m_Conn;
public:
		//KLASY POMOCNICZE
		  struct Pars{
		   int Rok;
		   int IdWarsztatu;
		   int MiesOd;
           int MiesDo;
		  };
		//INTERFEJS
		  void __fastcall open(const Pars& _Pars);
		  void __fastcall saveToMdb(const String & _Path);
		  void __fastcall close(void);
		//KONSTRUKTOR
			  __fastcall T_PlanKwartZadDM(TComponent* Owner);
private:
		//FUNKCJE POMOCNICZE
		  void       __fastcall setMdbPath(const WideString& _Path);
		  mng::Query __fastcall getQuery(void);
		//ATRYBUTY
		  Pars m_Pars;
		//STA£E
		  static const AnsiString M_TABLE_REF_SQL;
		  static const AnsiString M_COL_LIST_SQL;
};
}// end namespace progzest
//---------------------------------------------------------------------------
#endif
