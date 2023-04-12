//---------------------------------------------------------------------------

#ifndef WystWezwWaitFormH
#define WystWezwWaitFormH
#include "IWaitForm.h"
class T_WystWezwFRM;
class WystWezwWaitForm :public IWaitForm{
 public:
		//INTERFEJS
		  virtual void start(const int _Max);
		  virtual void step(const AnsiString& _Capt);
		  virtual void stop(void);
		//kostruktor destruktror
					WystWezwWaitForm(T_WystWezwFRM* _Frm);
		  virtual ~ WystWezwWaitForm(void);
 private:
		//NARZÊDZIA
		  T_WystWezwFRM * m_WaitForm;
};
//---------------------------------------------------------------------------
#endif
