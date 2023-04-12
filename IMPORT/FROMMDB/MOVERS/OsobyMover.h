//---------------------------------------------------------------------------

#ifndef OsobyMoverH
#define OsobyMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace importmdb{
class OsobyMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel( TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
				           OsobyMover(void){};
				  virtual ~OsobyMover(void){}

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
