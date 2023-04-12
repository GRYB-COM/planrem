//---------------------------------------------------------------------------

#ifndef WydzMoverH
#define WydzMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace importmdb{
class WydzMover :public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel(TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
				           WydzMover(void){};
				  virtual ~WydzMover(void){}

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
