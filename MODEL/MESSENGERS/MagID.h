//---------------------------------------------------------------------------

#ifndef MagIDH
#define MagIDH
#include <system.hpp>
#include <db.hpp>
namespace msg{
class MagID{
public:
		//ATRYBUTY
		  bool    IsDefined;
		  int     IdMag;
		  int     NrMag;
		  int     IdKomorki;
		  int     Rok;
          int     IdHarm;
		  String  Depozyt;
		  String  Wydzial;
		  String  getSygnMag(void) const;
		  int     getIdWydzialu(void) const;
		  void    fillFromDS(TDataSet* _DS);
		  void    setToDS(TDataSet* _DS)const;
		  void    setToPars(TParams* _Pars) const;
		  String  getKodWydz(void);
		//KONSTRUKTOR
		  MagID(void);
};
}//end namespace
//---------------------------------------------------------------------------
#endif
