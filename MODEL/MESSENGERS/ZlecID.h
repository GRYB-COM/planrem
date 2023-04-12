//---------------------------------------------------------------------------

#ifndef ZlecIDH
#define ZlecIDH
#include <system.hpp>
namespace Db{ class TDataSet;}
namespace msg{
class MagID;
class ZlecID{
public:
		//ATRYBUTY
		  bool    IsDefined;
		  int     IdZlecenia;
		  int     IdKomorki;
          int     IdKomorkiGlw;
		  int     Rok;
		  int     NrKol;
		  int     RokMag;
		  int     NrMag;
		  String  getKodWydz(void) const;
		  String  getSygn(const String& _Depozyt="" ) const;
		  void    fillFromDS(Db::TDataSet* _DS);
		  void    setToDS(Db::TDataSet* _DS);
		//KONSTRUKTOR
		  ZlecID(void);
		  ZlecID(const MagID& _MagID);
		//OPERATORY
		  ZlecID& operator=(const MagID& _MagID);
};
}//end namespace
//---------------------------------------------------------------------------
#endif
