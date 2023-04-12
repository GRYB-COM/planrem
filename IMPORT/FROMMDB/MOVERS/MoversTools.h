//---------------------------------------------------------------------------

#ifndef MoversToolsH
#define MoversToolsH
#include <db.hpp>
namespace msg { class MagID;  class ZlecID;}
namespace importmdb{
class MoversTools{
public:
		//INTERFEJS
		  static msg::MagID makeMagID(TDataSet* _Source);
		  static msg::ZlecID MoversTools::makeZlecID(TDataSet* _Source);
};

}
//---------------------------------------------------------------------------
#endif
