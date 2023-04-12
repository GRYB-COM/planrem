//---------------------------------------------------------------------------

#ifndef WarsztatyMoverH
#define WarsztatyMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace importmdb{
class WarsztatyMover :public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel( TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
				           WarsztatyMover(void){};
				  virtual ~WarsztatyMover(void){}

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
