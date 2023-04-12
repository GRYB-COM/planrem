//---------------------------------------------------------------------------

#ifndef SprzIDH
#define SprzIDH
#include <system.hpp>
namespace msg{
class SprzID{
public:
		//ATRYBUTY
		  bool    IsDefined;
		  int     IdSprzetu;
		  String  SygnSprzetu;
		//KONSTRUKTOR
		  SprzID(void);
};
}//end namespace
//---------------------------------------------------------------------------
#endif
