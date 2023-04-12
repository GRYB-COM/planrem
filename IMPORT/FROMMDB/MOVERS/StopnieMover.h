//---------------------------------------------------------------------------

#ifndef StopnieMoverH
#define StopnieMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace importmdb{
class StopnieMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel( TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
				           StopnieMover(void){};
				  virtual ~StopnieMover(void){}

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
