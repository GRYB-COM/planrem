//---------------------------------------------------------------------------

#ifndef model_messengers_RBH4KadraH
#define model_messengers_RBH4KadraH
#include <map>
#include "model_messengers_RBH.h"
namespace msg{
class RBH4Kadra{
public:
		//KLASY POMOCNICZE
		  typedef std::map<String,RBH>::const_iterator const_iterator;
		  typedef std::map<String,RBH>::const_iterator iterator;
		//INTEFEJS
		  RBH  & operator[](const String& _Kadra);
		  void  add(const String& _Kadra, const RBH& _RBH);
		  void  add(const Currency& _PlanRBH);
		  const_iterator  begin(void) const;
		  const_iterator  end(void) const;
		  iterator        begin(void);
		  iterator        end(void);
		  void clear(void);
		  Currency        getSum(const RBHType & _Type, const String& _Kadra ="") const;
private:
		//ATRYBUTY
		  std::map<String,RBH> m_Cont;
		  Currency             m_PlanRBH;
};
}//end namespace msg
//---------------------------------------------------------------------------
#endif
