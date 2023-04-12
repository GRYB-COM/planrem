//---------------------------------------------------------------------------

#ifndef ImportFromMdbCTRLH
#define ImportFromMdbCTRLH
#include <system.hpp>
namespace sgda { class DataMovers; }
namespace importmdb{
class T_AccessDM;
class WaitFRMFCD;
class T_ImportFromMdbFRM;
class T_ImportPlanFromMdbFRM;
class ImportFromMdbCTRL{
public:
	//INTERFEJS
	  void run(void);
	  void runPlan(void);
	//KONSTRUKTOR DESTRUKTOR
	   ImportFromMdbCTRL(void);
	  ~ImportFromMdbCTRL(void);
private:
	//METODY PRYWATNE
	  void __fastcall runClick(TObject *Sender);
	  void __fastcall runPlanClick(TObject *Sender);
	  bool            setPars(void);
	  bool            setPlanPars(void);
	  void            addMovers(sgda::DataMovers& _Movers, WaitFRMFCD * _WaitFRM);
	  void            close(void);
	//NARZÊDZIA
	  T_AccessDM                    * m_DM;
	  importmdb::T_ImportFromMdbFRM     * m_ParsFRM;
	  importmdb::T_ImportPlanFromMdbFRM * m_ParsPlanFRM;

};

};  //end namespace importmdb
//---------------------------------------------------------------------------
#endif
