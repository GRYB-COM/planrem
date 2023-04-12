//---------------------------------------------------------------------------

#ifndef SprzetDICTH
#define SprzetDICTH
#include <system.hpp>
#include <db.hpp>
namespace mng{ class StreamDB; }
namespace dict{
class DictMNG;
class SprzetDICT{
	public:
			//INTERFEJS
			  static SprzetDICT &  instance(void);
			  String  getNazwa(const int _Id)const;
			  String  getJIM(const int _Id)const;
			  TField* fieldByName(const int _Id,const AnsiString& _FieldName);
			//DESTRUKTOR
			  ~SprzetDICT(void);
	private:
			//METODY POMOCNICZE
			  void       open(void);
			  void       close(void);
			//NARZÊDZIA
			  mng::StreamDB * m_Stream;
			//KONSTRUKTORY
			  SprzetDICT(void);
			  SprzetDICT(SprzetDICT&);
			  SprzetDICT& operator=(SprzetDICT&) ;
 friend DictMNG;
 };
}
//---------------------------------------------------------------------------
#endif
