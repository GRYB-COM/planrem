//---------------------------------------------------------------------------

#ifndef model_messengers_RBHH
#define model_messengers_RBHH
#include <system.hpp>
namespace msg{
enum RBHType {rtNom=0, rtProd, rtProdW, rtNProd, rtPlan, rtEf, rtUr, rtPrz,rtSzk, rtSl, rtCh };
 class RBH{
 public:
		//INTERFEJS
		  Currency RBH_Nom;
		  Currency RBH_Prod;
		  Currency RBH_ProdW;//inne warsztaty
		  Currency RBH_NProd;
		  Currency RBH_Ef;
		  Currency RBH_Ur;
		  Currency RBH_Prz;
		  Currency RBH_Szk;
		  Currency RBH_Sl;
		  Currency RBH_Ch;
          String   EtatPr;
		  static int Licznik;
		  Currency getAsType(const RBHType& _Type) const;
		//KONSTRUKTOR
		  RBH(void);
		//operatory
		  RBH& operator+=(const RBH& _RBH);
 };
}//end namespace msg
//---------------------------------------------------------------------------
#endif
