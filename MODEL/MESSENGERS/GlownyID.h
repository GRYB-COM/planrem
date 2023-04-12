//---------------------------------------------------------------------------

#ifndef GlownyIDH
#define GlownyIDH
#include <vector>
#include "WydzID.h"
#include "KomID.h"
namespace readers { class GlownyReader; }
namespace msg{
class GlownyID{
public:
	//KLASY POMOCNICZE
	  typedef std::vector<KomID>::iterator iterator;
	  typedef std::vector<KomID>::const_iterator const_iterator;
	//INTERFEJS
	  msg::WydzID getWydzID(void)const;
	  String      getWydzCode(void)const;
	  String      getWydzName(void)const;
	  String      getWydzCM(const String& _Pause=" - ")const;
	  String      getBaseCode(const String& _Prefiks= "")const;

	  String      getKomIDS(const String& _Sep=",")const;
	  String      getKomCodes(const String& _Sep=",")const;
	  String      getKomNames(const String& _Sep=",")const;
	  String      getKomCM(const String& _Pause, const String& _Sep)const;

	  iterator       begin(void);
	  const_iterator begin(void) const;
	  iterator       end(void);
	  const_iterator end(void) const;

	  bool isDefined(void);
	 //KONSTRUKTORY I OPERATORY
	  GlownyID(void);
	  GlownyID(const GlownyID& );
	  GlownyID& operator=(const GlownyID& );

private:
	//ATRYBUTY
	  msg::WydzID        m_WydzID;
	  String             m_BaseCode;
	  std::vector<KomID> m_KomIDS;
	//PRZYJACIELE
	  friend  readers::GlownyReader;
};
}
//---------------------------------------------------------------------------
#endif
