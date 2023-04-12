//---------------------------------------------------------------------------

#ifndef MagazynMoverH
#define MagazynMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace msg { class MagID; }
namespace mng { class StreamDB; }
namespace importmdb{
class MagazynMover :public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel(TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
						   MagazynMover(void);
				  virtual ~MagazynMover(void);
	private:
				//NARZÊDZIA
				  mng::StreamDB * m_HarmSDB;
				  mng::StreamDB * m_KomSDB;
				//FUNKCJE POMOCNICZE
				   void  checkHarm(TParams * Dest, TDataSet* Source);
				   void  checkKom(TParams * Dest, TDataSet* Source);
				   void  checkSygn(TParams * Dest, TDataSet* Source);

};

};  //end importmdb
//---------------------------------------------------------------------------
#endif
