//---------------------------------------------------------------------------

#ifndef KwMozlWarDMH
#define KwMozlWarDMH
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
class T_KwMozlWarDM : public TDataModule
{
__published:	// IDE-managed Components
	TClientDataSet *m_Client;
	TADOQuery *m_WorkADO;
	TADOTable *m_KwMozlWarADO;
	TADOConnection *m_Conn;
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
			  __fastcall T_KwMozlWarDM(TComponent* Owner);
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
