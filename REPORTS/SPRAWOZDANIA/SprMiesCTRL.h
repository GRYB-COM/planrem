//---------------------------------------------------------------------------

#ifndef SprMiesCTRLH
#define SprMiesCTRLH
#include <system.hpp>
namespace sqr { class SQRScript; }
namespace progzest{
class T_PlanKwartWybFRM;
//class SprRoczneDAO;
class SprMiesCTRL{
public:
	//INTERFEJS
	  void run(void);
	//KONSTRUKTOR DESTRUKTOR
	   SprMiesCTRL(void);
	  ~SprMiesCTRL(void);
private:
	//NARZÊDZIA
	  T_PlanKwartWybFRM * m_WybFRM;
	  //SprRoczneDAO      * m_DAO;
	//FUNKCJE POMOCNICZE
	  void __fastcall runSQR(TObject *Sender);
	  void __fastcall runXLS(TObject *Sender);
	  void __fastcall prepare(sqr::SQRScript & _Scr);
};

}
//---------------------------------------------------------------------------
#endif
