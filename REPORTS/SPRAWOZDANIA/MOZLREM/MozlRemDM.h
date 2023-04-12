//---------------------------------------------------------------------------

#ifndef MozlRemDMH
#define MozlRemDMH
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
class T_MozlRemDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_MozlRemADO;
	TADOConnection *m_Conn;
	TADOTable *m_MozlRemParsADO;
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
			  __fastcall T_MozlRemDM(TComponent* Owner);
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
