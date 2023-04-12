//---------------------------------------------------------------------------
#ifndef model_messengers_RBH4OsH
#define model_messengers_RBH4OsH
#include "model_messengers_RBH.h"
#include <system.hpp>
#include <map>
namespace msg{
class RBH4Os{
public:
		//KLASY POMOCNICZE
		  typedef std::map<int,RBH>::const_iterator const_iterator;
		  typedef std::map<int,RBH>::const_iterator iterator;
		//INTEFEJS
		  RBH &           operator[](const int _IdOsoby);
		  const_iterator  begin(void) const;
		  const_iterator  end(void) const;
		  iterator        begin(void);
		  iterator        end(void);
		  void            clear(void);
		  void            add(const int _IdOsoby, const RBH& _RBH);
		  Currency        getSum( const RBHType & _Type )const;
private:
		//ATRYBUTY
		  std::map<int,RBH> m_Cont;
};
}
#endif
