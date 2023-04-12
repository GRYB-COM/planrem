//---------------------------------------------------------------------------

#ifndef ZlecRbhMoverH
#define ZlecRbhMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace mng { class QueryDB; }
namespace importmdb{
class ZlecRbhMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel(TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
						   ZlecRbhMover(void);
				  virtual ~ZlecRbhMover(void);
	private:
			   //NARZÊDZIA
				 mng::QueryDB * m_ZlecQDB;
};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
