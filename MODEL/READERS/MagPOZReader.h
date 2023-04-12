//---------------------------------------------------------------------------

#ifndef MagPOZReaderH
#define MagPOZReaderH
#include <system.hpp>
namespace msg  { class MagID; class MagPOZ;}
namespace readers{
class MagPOZReader{
public:
		//INTERFEJS
		  msg::MagPOZ read(const msg::MagID& _MagID);
		//KONSTRUKTOR DESTRUKTOR
private:

};

}//end namespace readers
//---------------------------------------------------------------------------
#endif
