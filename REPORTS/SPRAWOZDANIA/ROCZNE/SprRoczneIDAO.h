//---------------------------------------------------------------------------

#ifndef SprRoczneIDAOH
#define SprRoczneIDAOH
#include <db.hpp>
#include "SprRocznePars.h"
namespace readers  { class Sprz4SprReader; }
namespace msg      { class Sprz4Spr;       }
namespace mng      { class StreamDB;       }
namespace progzest{
 class SprRoczneIDAO{
 public:
	//INTERFEJS
	  virtual TClientDataSet* getDataSet(void)=0;
	  virtual void            open(const SprRocznePars& _Pars)=0;
	  virtual void            close(void)=0;
	//DESTRUKTOR
	  virtual  ~SprRoczneIDAO(void){};

 };
}
//---------------------------------------------------------------------------
#endif
