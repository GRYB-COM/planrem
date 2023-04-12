//---------------------------------------------------------------------------

#ifndef KwMozlWarSprzCTRLH
#define KwMozlWarSprzCTRLH
#include <system.hpp>
namespace jbutils { class TMyIni; }
namespace progzest{
class T_KwMozlWarDM;
class T_KwMozlWarSprzDM;
class T_KwMozlWarWybFRM;
class KwMozlWarSprzCTRL{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   KwMozlWarSprzCTRL(const String & _Caption);
		  ~KwMozlWarSprzCTRL(void);
private:
	   //NARZÊDZIA
		 T_KwMozlWarDM      * m_DM;
		 T_KwMozlWarSprzDM  * m_DM1;
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
