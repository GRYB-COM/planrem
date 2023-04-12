//---------------------------------------------------------------------------

#ifndef EksportToMdbCTRLH
#define EksportToMdbCTRLH
#include <system.hpp>
namespace Dialogs   { class TOpenDialog;}
namespace importmdb { class T_AccessDM; class WaitFRMFCD;}
namespace mng       { class StreamDB;  }
namespace eksportmdb{

class EksportToMdbCTRL{
public:
	//INTERFEJS
	  void run(void);
	//KONSTRUKTOR DESTRUKTOR
	   EksportToMdbCTRL(void);
	  ~EksportToMdbCTRL(void);
private:
	//METODY PRYWATNE
	  bool   setDBPath(void);
	  void   addorupd(void);
	  void   del(void);
	  bool   findHarm(void);
	  void   fillFields(void);
	  String getNazSprz(void);
	  String getDostawca(void);
	//NARZÊDZIA
	  importmdb::T_AccessDM  * m_DM;
	  Dialogs::TOpenDialog   * m_OpenDLG;
	  importmdb::WaitFRMFCD  * m_WaitFRM;
	  mng::StreamDB           * m_HarmSDB;
	//STA£E
	  static const AnsiString M_PLAN_SQL;
};

};  //end namespace import
//---------------------------------------------------------------------------
#endif
