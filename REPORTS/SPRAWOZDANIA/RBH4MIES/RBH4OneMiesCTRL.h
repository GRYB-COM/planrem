//---------------------------------------------------------------------------

#ifndef RBH4OneMiesCTRLH
#define RBH4OneMiesCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_RBH4OneMiesDM;
class T_RBH4OneMiesWybFRM;
class RBH4OneMiesCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   RBH4OneMiesCTRL(void);
		  ~RBH4OneMiesCTRL(void);
private:
	   //NARZÊDZIA
		 T_RBH4OneMiesDM      * m_DM;
		 T_RBH4OneMiesWybFRM  * m_WybFRM;
		 jbutils::TMyIni  * m_Ini;
	   //FUNKCJE POMOCNICZE
		 void open(const bool _ToMdb=true);
		 void runRep(const bool _Print);
		 void close(void);
		 void __fastcall prevTMIClick(TObject *Sender);
		 void __fastcall printTMIClick(TObject *Sender);
		 void __fastcall runSQR(TObject* Sender);
		 void __fastcall runSQRXLS(TObject* Sender);
};
}//end namespace progzest

//---------------------------------------------------------------------------
#endif
