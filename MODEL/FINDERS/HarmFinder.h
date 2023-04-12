//---------------------------------------------------------------------------

#ifndef HarmFinderH
#define HarmFinderH
#include <db.hpp>
namespace sgda {class DAReader;}
namespace msg {class MagID; }
namespace finders{
class HarmFinder{
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
		  TDataSet *  getDataSet(void);
		  int         getRecordCount(void);
		  void        open(const Pars& _Pars);
		  int         getCurrHarm(void);
		  void        close(void);

	   //KONSTRUKTOR DESTRUKTOR
		  HarmFinder(void);
		 ~HarmFinder(void);
private:
		//ATRYBUTY
		  Pars m_Pars;
		//NARZÊDZIA
		  sgda::DAReader * m_HarmDAR;
		//STA£E
		  static const String M_COL_LIST_SQL;
		  static const String M_TABLE_REF_SQL;
};
}
//---------------------------------------------------------------------------
#endif
