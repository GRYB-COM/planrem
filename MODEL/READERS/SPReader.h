//---------------------------------------------------------------------------

#ifndef SPReaderH
#define SPReaderH
#include <db.hpp>
namespace msg{ class MagID; }
namespace sgda{ class DAReader; }
namespace readers{
class SPReader{
 public:
		//INTERFEJS
		  TDataSet* getDataSet(void);
		  void      open(bool,AnsiString);
		  void      close(void);
		//KONSTRUKTOR DESTRUKTOR
		   SPReader(void);
		  ~SPReader(void);
	   //NARZÊDZIA
         sgda::DAReader* m_Reader;
};
}
//---------------------------------------------------------------------------
#endif
