//---------------------------------------------------------------------------

#ifndef PlanMoverMoverH
#define PlanMoverMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace importmdb{
class PlanMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual void   setPars(TParams * Dest, TDataSet* Source);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
				           PlanMover(void){};
				  virtual ~PlanMover(void){}

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
