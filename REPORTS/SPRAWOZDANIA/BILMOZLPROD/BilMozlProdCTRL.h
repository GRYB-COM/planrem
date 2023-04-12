//---------------------------------------------------------------------------

#ifndef BilMozlProdCTRLH
#define BilMozlProdCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_BilMozlProdDM;
class T_BilMozlProdWybFRM;
class BilMozlProdCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   BilMozlProdCTRL(void);
		  ~BilMozlProdCTRL(void);
private:
	   //NARZÊDZIA
		 T_BilMozlProdDM      * m_DM;
		 T_BilMozlProdWybFRM  * m_WybFRM;
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
