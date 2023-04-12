//---------------------------------------------------------------------------

#ifndef MagPOZH
#define MagPOZH
#include <system.hpp>
#include <db.hpp>
namespace readers { class MagPOZReader;  }
namespace finders { class SprzetFinder;  }
namespace msg{
class MagID;
class MagPOZ
{
 public:
		//INTERFEJS
		  bool    isDefined(void) const;
		  MagID   getIdMag(void) const;
		  int     getNrMag(void) const;
		  int     getRokMag(void) const;
		  String  getSygnMag(void) const;
		  String  getWydzial(void) const;
		  int     getNrHarm(void) const;
		//KONSTRUKTORY  OPERATORY DESTRUKTOR
		   MagPOZ(void);
		   MagPOZ(const MagPOZ& _MagPOZ);
		  ~MagPOZ(void);
		   MagPOZ& operator=(const MagPOZ& _MagPOZ);

 private:
		//ATRYBUTY
		  bool    m_IsDefined;
		  MagID*  m_MagID;
		  int     m_NrMag;
		  int     m_RokMag;
		  String  m_SygnMag;
		  String  m_Wydzial;
		  int     m_NrHarm;
		//METODY POMOCNICZE
		  void set(const MagID& _MagID,const String& _SygnMag,  const String& _Wydz, const int _NrHarm);
		  void set(TDataSet * _DS);
		//PRZYJACIELE
		  friend readers::MagPOZReader;
		  friend finders::SprzetFinder;
};
}
//---------------------------------------------------------------------------
#endif
