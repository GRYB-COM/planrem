//---------------------------------------------------------------------------

#ifndef RBH4MiesCTRLH
#define RBH4MiesCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_RBH4MiesDM;
class RBH4MiesCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   RBH4MiesCTRL(void);
		  ~RBH4MiesCTRL(void);
private:
	   //NARZÊDZIA
		 T_RBH4MiesDM      * m_DM;
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
