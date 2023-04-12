//---------------------------------------------------------------------------

#ifndef ZlecMoverH
#define ZlecMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
namespace mng { class StreamDB;}
namespace importmdb{
class ZlecMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel(TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
						   ZlecMover(void);
				  virtual ~ZlecMover(void);
	private:
				//METODY POMOCNICZE
				  void   setJedn(TParams * Dest, TDataSet* Source);
				  void   setMag(TParams * Dest, TDataSet* Source);
				  void   setKom(TParams * Dest, TDataSet* Source);
				  void   setHarm(TParams * Dest, TDataSet* Source);
				//NARZÊDZIA
                  mng::StreamDB * m_JednSDB;
				  mng::StreamDB * m_KomorkiSDB;
				  mng::StreamDB * m_MagazynSDB;
				  mng::StreamDB * m_HarmSDB;
};
};  //end importmdb
//---------------------------------------------------------------------------
#endif
