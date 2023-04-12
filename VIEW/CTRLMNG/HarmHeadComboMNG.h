//---------------------------------------------------------------------------

#ifndef HarmHeadComboMNGH
#define HarmHeadComboMNGH
#include "system.hpp"
namespace ComCtrl{ class TComboBox; }
namespace ctrlmng{
class HarmHeadComboMNG{
 public:
		//INTERFEJS
		   int   getID(void);

		   void  setID(const int _Id);
		//KONSTRUKTOR
		  HarmHeadComboMNG(ComCtrl::TComboBox * _Combo);
 private:
		//NARZÊDZIA
		  ComCtrl::TComboBox * m_Combo;
};
}
//---------------------------------------------------------------------------
#endif
