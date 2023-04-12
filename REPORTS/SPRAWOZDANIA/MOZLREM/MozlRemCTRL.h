//---------------------------------------------------------------------------

#ifndef MozlRemCTRLH
#define MozlRemCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_MozlRemDM;
class T_MozlRemWybFRM;
class MozlRemCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   MozlRemCTRL(void);
		  ~MozlRemCTRL(void);
private:
	   //NARZÊDZIA
		 T_MozlRemDM      * m_DM;
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
