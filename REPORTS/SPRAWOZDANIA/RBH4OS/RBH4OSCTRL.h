//---------------------------------------------------------------------------

#ifndef RBH4OSCTRLH
#define RBH4OSCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_RBH4OSDM;
class T_RBH4OSWybFRM;
class RBH4OSCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   RBH4OSCTRL(void);
		  ~RBH4OSCTRL(void);
private:
	   //NARZÊDZIA
		 T_RBH4OSDM      * m_DM;
		 T_RBH4OSWybFRM  * m_WybFRM;
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
