//---------------------------------------------------------------------------

#ifndef HarmDostCTRLH
#define HarmDostCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_HarmDostDM;
class T_MozlRemWybFRM;
class HarmDostCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   HarmDostCTRL(void);
		  ~HarmDostCTRL(void);
private:
	   //NARZÊDZIA
		 T_HarmDostDM      * m_DM;
		 T_MozlRemWybFRM  * m_WybFRM;
         jbutils::TMyIni  * m_Ini;
	   //FUNKCJE POMOCNICZE
		 void open(void);
		 void runRep(const bool _Print);
		 void close(void);
		 void __fastcall prevTMIClick(TObject *Sender);
		 void __fastcall printTMIClick(TObject *Sender);
};
}//end namespace progzest

//---------------------------------------------------------------------------
#endif
