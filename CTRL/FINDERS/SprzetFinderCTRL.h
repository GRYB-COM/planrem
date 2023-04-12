//---------------------------------------------------------------------------

#ifndef SprzetFinderCTRLH
#define SprzetFinderCTRLH
#include <system.hpp>
#include "MagID.h"
namespace finders{
class  SprzetFinder;
class  T_ListaMagFRM;
class SprzetFinderCTRL{
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		   public:
		   msg::MagID IdMag;
		   int   IdWydzialu;
		   bool  IsFilter;
           Pars(void);
		  };
		//INTERFEJS
		  int find(msg::MagID& _MagPOZ, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   SprzetFinderCTRL(void);
		  ~SprzetFinderCTRL(void);
private:
		//ATRYBUTY
		  Pars m_Pars;
		//METODY POMOCNICZE
		  void        open(void);
		  int         find(msg::MagID& _MagPOZ);
		  void        close(void);

		//ZDARZENIA
		  void __fastcall searchBTClick(TObject *Sender);
		//MARZÊDZIA
		  SprzetFinder   * m_Finder;
		  T_ListaMagFRM  * m_SearchForm;
};

}//end namespace finders
//---------------------------------------------------------------------------
#endif
