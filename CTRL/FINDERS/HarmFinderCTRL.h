//---------------------------------------------------------------------------

#ifndef HarmFinderCTRLH
#define HarmFinderCTRLH
#include <system.hpp>
namespace finders{
class  HarmFinder;
class  T_FindHarmFRM;
class HarmFinderCTRL{
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		   public:
		   int IdHarmonogramu;
		   int Rok;
           int IdWydzialu;
		   Pars(void);
		  };
		//INTERFEJS
		  int find(int& _IdHarm, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   HarmFinderCTRL(void);
		  ~HarmFinderCTRL(void);
private:
		//ATRYBUTY
		  Pars m_Pars;
		//METODY POMOCNICZE
		  void        open(void);
		  int         find(int& _IdHarm);
		  void        close(void);

		//ZDARZENIA
		  void __fastcall searchBTClick(TObject *Sender);
		//MARZÊDZIA
		  HarmFinder     * m_Finder;
		  T_FindHarmFRM  * m_SearchForm;
};

}//end namespace finders
//---------------------------------------------------------------------------
#endif
