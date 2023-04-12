//---------------------------------------------------------------------------

#ifndef SprzetFinderH
#define SprzetFinderH
#include <db.hpp>
namespace sgda {class DAReader;}
namespace msg {class MagID; }
namespace finders{
class SprzetFinder{
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		  public:
		   String SygnMag;
		   int    Rok;
		   int    IdWydzialu;
           Pars(void);
		  };
		//INTERFEJS
		  TDataSet *  getDataSet(void);
		  int         getRecordCount(void);
		  void        open(const Pars& _Pars);
		  msg::MagID  getCurrID(void);
		  void        close(void);

	   //KONSTRUKTOR DESTRUKTOR
		  SprzetFinder(void);
		 ~SprzetFinder(void);
private:
		//NARZÊDZIA
		  sgda::DAReader * m_SprzetDAR;
};
}
//---------------------------------------------------------------------------
#endif
