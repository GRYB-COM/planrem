//---------------------------------------------------------------------------

#ifndef PlanMoverH
#define PlanMoverH
#include "SGTOOLS\DATAACCESS\IRecMover.h"
#include <system.hpp>
#include <map>
namespace sgda { class DAReader; }
namespace importmdb{
class PlanMover:public sgda::IRecMover{
	public:
			//INTERFEJS
				  virtual String getIsRecSQL(void);
				  virtual String getInsRecSQL(void);
				  virtual String getUpdRecSQL(void);
				  virtual String getLabel( TDataSet* Source);
				  virtual void   setPars(TParams * Dest, TDataSet* Source, const bool _IsIns=false);
				  virtual void   setKeyPars(TParams * Dest, TDataSet* Source);
				//KONSTRUKTOR DESTRUKTOR
						   PlanMover(void);
				  virtual ~PlanMover(void);
	private:
				//METODY POMOCNICZE;
				  void   setIloscPars(TParams * Dest, const int _Kwart, const double& IlKW);
				  bool   setIloscPars(double& _Il, double& IlKW);
				  int    findJW(const String & _Dostawca);
				  int    findKU(const String & _PN);
			  //NARZÊDZIA
				  sgda::DAReader        * m_JWDAR;
				  sgda::DAReader        * m_KodyUslugDAR;
				  std::map<String,String> m_JWBuff;
				  std::map<String,String> m_PNBuff;
};
}  //end importmdb
//---------------------------------------------------------------------------
#endif
