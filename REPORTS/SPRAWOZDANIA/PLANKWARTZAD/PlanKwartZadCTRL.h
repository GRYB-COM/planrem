//---------------------------------------------------------------------------

#ifndef PlanKwartZadCTRLH
#define PlanKwartZadCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_PlanKwartZadDM;
class T_PlanKwartZadWybFRM;
class PlanKwartZadCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   PlanKwartZadCTRL(void);
		  ~PlanKwartZadCTRL(void);
private:
	   //NARZÊDZIA
		 T_PlanKwartZadDM      * m_DM;
		 T_PlanKwartZadWybFRM  * m_WybFRM;
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
