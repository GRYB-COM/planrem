//---------------------------------------------------------------------------
#ifndef model_messengers_RBH4WarH
#define model_messengers_RBH4WarH
#include "model_messengers_RBH4Mies.h"
#include <system.hpp>
namespace msg{
class RBH4War{
public:
		//KLASY POMOCNICZE
		  typedef std::map<int,RBH4Mies>::const_iterator const_iterator;
		  typedef std::map<int,RBH4Mies>::const_iterator iterator;
		//INTEFEJS
		  RBH4Mies &      operator[](const int _War);
		  const_iterator  begin(void) const;
		  const_iterator  end(void) const;
		  iterator        begin(void);
		  iterator        end(void);
		  void            clear(void);
		  void            add(const int _War, const int _Mies, const bool _AddEt, const String& _Kadra, const RBH& _RBH, const Currency& _EtatPr);
		  Currency        getSum( const RBHType & _Type, const String& _Kadra="", const int _MiesOd=0, const int _MiesDo=0)const;
		  Currency        getEtPr(const int _War);
private:
		//ATRYBUTY
		  std::map<int,RBH4Mies> m_Cont;
		  std::map<int,Currency> m_EtatyPr;
};
}
#endif
