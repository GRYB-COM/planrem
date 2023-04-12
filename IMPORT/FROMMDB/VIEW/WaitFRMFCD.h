//---------------------------------------------------------------------------
#ifndef WaitFRMFCDH
#define WaitFRMFCDH
#include "..\_COMMON\_SLAWEK\FORMS\FORMS60\IWaitForm.h"
namespace importmdb{
class T_WaitFRM;
class WaitFRMFCD :public IWaitForm{
 public:
		//INTERFEJS
				  void display(void);
		  virtual void start(const int _Max);
		  virtual void step(const AnsiString& _Capt);
		  virtual void stop(void);
		  		  void hide(void);
		//KONSTRUKTOR DESTRUKTOR
				   WaitFRMFCD(void);
		  virtual ~WaitFRMFCD(void);
 private:
		//NARZÊDZIA
          T_WaitFRM	* m_Form;
};
}//end namespace
//---------------------------------------------------------------------------
#endif
