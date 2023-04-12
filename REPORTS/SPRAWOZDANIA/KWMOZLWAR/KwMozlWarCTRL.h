//---------------------------------------------------------------------------

#ifndef KwMozlWarCTRLH
#define KwMozlWarCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_KwMozlWarDM;
class T_KwMozlWarWybFRM;
class KwMozlWarCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   KwMozlWarCTRL(const String& _Caption);
		  ~KwMozlWarCTRL(void);
private:
	   //NARZÊDZIA
		 T_KwMozlWarDM      * m_DM;
		 T_KwMozlWarWybFRM  * m_WybFRM;
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
