//---------------------------------------------------------------------------

#ifndef KUTReaderH
#define KUTReaderH
#include <db.hpp>
namespace msg{     class MagID; class ZlecREC; }
namespace sgda{    class DAReader; }
namespace jbutils{ class TMyIni;}
namespace readers{
class KUTReader{
 public:
		//INTERFEJS
		  TDataSet*    getDataSet(void);
		  void         open(const msg::MagID & _MagID);
		  msg::ZlecREC getMainKUT(void);
		  void         close(void);
		//KONSTRUKTOR DESTRUKTOR
		   KUTReader(void);
		  ~KUTReader(void);
	   //NARZÊDZIA
		 sgda::DAReader   * m_Reader;
		 jbutils::TMyIni  * m_Ini;
	   //ATRYBUTY
		 int m_BiezRok;

};
}
//---------------------------------------------------------------------------
#endif
