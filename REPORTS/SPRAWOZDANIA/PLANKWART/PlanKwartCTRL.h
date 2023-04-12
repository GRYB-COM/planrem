//---------------------------------------------------------------------------

#ifndef PlanKwartCTRLH
#define PlanKwartCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_PlanKwartDM;
class T_PlanKwartWybFRM;
class PlanKwartCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   PlanKwartCTRL(void);
		  ~PlanKwartCTRL(void);
private:
	   //NARZÊDZIA
		 T_PlanKwartDM      * m_DM;
		 T_PlanKwartWybFRM  * m_WybFRM;
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
