//---------------------------------------------------------------------------

#ifndef SprKwartalCTRLH
#define SprKwartalCTRLH
#include <System.hpp>
namespace progzest{
class T_SprKwartalneQR;
class T_SprKwartalWybFRM;
class T_SprKwartalDM;
class SprKwartalCTRL{
	public:
			//INTERFEJS
			  void run(void);
			//KONSTRUKTOR DESTRUKTOR
			   SprKwartalCTRL(void);
			  ~SprKwartalCTRL(void);
	private:
			//METODY POMOCNICZE
			  void show();
			  void            prepareWybFrm(void);
			  void __fastcall print(TObject* );
			  void __fastcall preview(TObject*);
			  void __fastcall runSQR(TObject*);
			  void __fastcall runSQRXLS(TObject*);
			  void            prepareDM(void);
			//NARZÊDZIA
			  T_SprKwartalneQR     * m_Raport;
			  T_SprKwartalWybFRM  * m_WybFrm;
			  T_SprKwartalDM      * m_DM;
};
}//end namspace progzest
//---------------------------------------------------------------------------
#endif
