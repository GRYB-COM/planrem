//---------------------------------------------------------------------------
#ifndef MeldTygCTRLH
#define MeldTygCTRLH
#include <system.hpp>
#include <map>
namespace jbutils { class TMyIni;     }
namespace sqr     { class SQRScript;  }
namespace progzest{
class T_MeldTygQRP;
class T_MeldTygWybFRM;
class T_MeldTygDM;
class MeldTygCTRL{
	public:
			//INTERFEJS
			  void run(void);
			//KONSTRUKTOR DESTRUKTOR
			   MeldTygCTRL(void);
			  ~MeldTygCTRL(void);
	private:
			//KLASY POMOCNICZE
			  enum SQRy { sqrSprzPrzyjPl, sqrSprzPrzyjNpl, sqrSprzRem, sqrSprzPrzek};
			//METODY POMOCNICZE
			  void show(void);
			  void            prepareWybFrm(void);
			  void __fastcall print(TObject* );
			  void __fastcall preview(TObject*);
			  void __fastcall runSQR(TObject*);
			  void __fastcall runXLS(TObject*);
			  void            prepareDM(void);
			  void            prepareQR(void);
			  String          getTitle(void);
              void            loadSQR(sqr::SQRScript &aSkrypt,const String& _SQR);
			//NARZÊDZIA
			  T_MeldTygQRP     * m_Raport;
			  T_MeldTygWybFRM  * m_WybFrm;
			  T_MeldTygDM      * m_DM;
              jbutils::TMyIni  * m_Ini;


};
};//end namespace progzest
//---------------------------------------------------------------------------
#endif
