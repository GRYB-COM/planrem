//---------------------------------------------------------------------------

#ifndef MeldTygDMH
#define MeldTygDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
//---------------------------------------------------------------------------
namespace mng { class StreamDB; }
namespace progzest{
class T_MeldTygDM : public TDataModule
{
__published:	// IDE-managed Components
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
			  public:
					TDateTime DataOd;
					TDateTime DataDo;
					int       MiesOd;
					int       MiesDo;
                    int       Rok;
		  };
		//INTERFEJS
		  TDataSet* __fastcall getSprzNDostDS(void);
		  TDataSet* __fastcall getSprzPrzyjPlDS(void);
		  TDataSet* __fastcall getSprzPrzyjNplDS(void);
		  TDataSet* __fastcall getSprzPrzekDS(void);
		  TDataSet* __fastcall getSprzRemRBHDS(void);
		  TDataSet* __fastcall getSprzRemDS(void);
		  TDataSet* __fastcall getSprzDepDS(void);
		  void  	__fastcall setPars(const Pars& _Pars);
		  void  	__fastcall open(void);
		  void  	__fastcall close(void);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall  T_MeldTygDM(TComponent* Owner);
		  __fastcall ~T_MeldTygDM(void);
private:
		//NARZÊDZIA
		  mng::StreamDB * m_SprzNDostSDB;
		  mng::StreamDB * m_SprzPrzyjPlSDB;
		  mng::StreamDB * m_SprzPrzyjNplSDB;
		  mng::StreamDB * m_SprzRemSDB;
		  mng::StreamDB * m_SprzRemRBHSDB;
		  mng::StreamDB * m_SprzPrzekSDB;
		  mng::StreamDB * m_SprzDepSDB;
		//ATRYBUTY
		  Pars m_Pars;
		//FUNKCJE POMOCNICZE
		  void __fastcall openStream(const String& _SQR, mng::StreamDB* _Stream);
		//PRZYJACIELLE
		//SK£ADOWE STATYCZNE

};

}//end namespace progzest
//---------------------------------------------------------------------------
#endif
