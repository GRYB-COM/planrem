//---------------------------------------------------------------------------

#ifndef ProtFinderH
#define ProtFinderH
#include <db.hpp>
namespace sgda {class DAReader;}
namespace msg {class MagID; }
namespace finders{
class ProtFinder{
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		  public:
		   int IdProtokolu;
		   int Rok;
		   int IdWydzialu;
           Pars(void);
		  };
		//INTERFEJS
		  TDataSet *  getDataSet(void);
		  int         getRecordCount(void);
		  void        open(const Pars& _Pars);
		  int         getCurrProt(void);
		  int         getCurrRok(void);
		  int         getCurrWydz(void);
		  void        close(void);

	   //KONSTRUKTOR DESTRUKTOR
		  ProtFinder(void);
		 ~ProtFinder(void);
private:
		//ATRYBUTY
		  Pars m_Pars;
		//NARZÊDZIA
		  sgda::DAReader * m_ProtDAR;
		//STA£E
		  static const String M_COL_LIST_SQL;
		  static const String M_TABLE_REF_SQL;
};
}
//---------------------------------------------------------------------------
#endif
