//---------------------------------------------------------------------------

#ifndef StSprzCTRLH
#define StSprzCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_StSprzDM;
class T_StSprzWybFRM;
class StSprzCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   StSprzCTRL(void);
		  ~StSprzCTRL(void);
private:
	   //NARZÊDZIA
		 T_StSprzDM      * m_DM;
		 T_StSprzWybFRM  * m_WybFRM;
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
