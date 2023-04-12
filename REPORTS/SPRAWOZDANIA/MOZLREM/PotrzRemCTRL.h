//---------------------------------------------------------------------------

#ifndef PotrzRemCTRLH
#define PotrzRemCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_PotrzRemDM;
class T_PotrzRemWybFRM;
class PotrzRemCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   PotrzRemCTRL(void);
		  ~PotrzRemCTRL(void);
private:
	   //NARZÊDZIA
		 T_PotrzRemDM      * m_DM;
		 T_PotrzRemWybFRM  * m_WybFRM;
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
