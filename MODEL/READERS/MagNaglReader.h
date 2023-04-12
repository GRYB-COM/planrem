//---------------------------------------------------------------------------

#ifndef MagNaglReaderH
#define MagNaglReaderH
#include <db.hpp>
namespace msg   { class MagID; }
namespace sgda  { class DAReader; }
namespace readers{
class MagNaglReader{
 public:
		//INTERFEJS
		  TDataSet * getDataSet(void);
		  void       open(const msg::MagID& _MagID);
		  void       close(void);
		//KONSTRUKTOR DESTRUKTOR
			MagNaglReader(void);
		   ~MagNaglReader(void);
 private:
		//NARZÊDZIA
		  sgda::DAReader * m_Reader;
};
}
//---------------------------------------------------------------------------
#endif
