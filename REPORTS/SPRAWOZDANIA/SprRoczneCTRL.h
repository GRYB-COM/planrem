//---------------------------------------------------------------------------

#ifndef SprRoczneCtrlH
#define SprRoczneCtrlH
#include <system.hpp>
namespace sqr { class SQRScript; }
namespace progzest{
class T_SprRoczneWybFRM;
class SprRoczneIDAO;
class SprRoczneDAO;
class SprRoczne1DAO;
class SprRoczneCTRL{
public:
	//INTERFEJS
	  void run(const int _RodzRem);
	//KONSTRUKTOR DESTRUKTOR
	   SprRoczneCTRL(void);
	  ~SprRoczneCTRL(void);
private:
	//NARZÊDZIA
	  T_SprRoczneWybFRM *  m_WybFRM;
	  SprRoczneDAO      *  m_DAO;
	  SprRoczne1DAO      * m_1DAO;
	//FUNKCJE POMOCNICZE
	  void __fastcall runSQR(TObject *Sender);
	  void __fastcall runXLS(TObject *Sender);
	  SprRoczneIDAO*  prepare(sqr::SQRScript & _Scr);
};

}
//---------------------------------------------------------------------------
#endif
