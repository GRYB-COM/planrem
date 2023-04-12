//---------------------------------------------------------------------------

#ifndef model_messengers_RBH4MiesH
#define model_messengers_RBH4MiesH
#include <map>
#include "model_messengers_RBH4Kadra.h"
namespace msg{
class RBH4Mies{
public:
		//KLASY POMOCNICZE
		  typedef std::map<int,RBH4Kadra>::const_iterator const_iterator;
		  typedef std::map<int,RBH4Kadra>::const_iterator iterator;
		//INTEFEJS
		  RBH4Kadra & operator[](const int _Mies);
		  void  add(const int _Mies, const String& _Kadra, const RBH& _RBH);
          void  add(const int _NrMies,const Currency& _PlanRBH);
		  const_iterator  begin(void) const;
		  const_iterator  end(void) const;
		  iterator        begin(void);
		  iterator        end(void);
		  void clear(void);
		  Currency        getSum(const RBHType & _Type, const String& _Kadra="", const int _MiesOd=0, const int _MiesDo=0) const;
private:
		//ATRYBUTY
		  std::map<int,RBH4Kadra> m_Cont;
};
}//end namespace msg
//---------------------------------------------------------------------------
#endif
