//---------------------------------------------------------------------------
#ifndef WezwMNGH
#define WezwMNGH
#include <system.hpp>
class T_WystWezwFRM;
class WystWezwWaitForm;
namespace editors {class PowiadEditor; }
class WezwMNG{
public:
		//INTERFEJS
		  void run(void);
		//KONSTRUKTOR DESTRUKTOR
		   WezwMNG(void);
		  ~WezwMNG(void);

private:
		//NARZÊDZIA
          editors::PowiadEditor * m_PowEd;
		  T_WystWezwFRM     * m_ParsFRM;
		  WystWezwWaitForm  * m_WaitForm;
		//ZDARZENIA
		  void __fastcall print(TObject *Sender);
		  void __fastcall del(TObject *Sender);
		  void __fastcall open(TObject *Sender);
};
//---------------------------------------------------------------------------
#endif
