//---------------------------------------------------------------------------

#ifndef WydzialyDICTH
#define WydzialyDICTH
#include <system.hpp>
#include <db.hpp>
namespace mng{ class StreamDB; }
namespace dict{
class DictMNG;
 class WydzialyDICT{
	public:
			//INTERFEJS
			  static WydzialyDICT &  instance(void);
			  TField* fieldByName(const int _IdWydzialu,const AnsiString& _FieldName);
			  bool    isWydzialOk(const String& _KodWydz) const;
			  void    first(void);
			  void    next(void);
			  bool    isEof(void);
			  String  getKod(void);
			  String  getKod(const int _IdWydzialu);
			  String  getName(void);
			  String  getName(const int _IdWydzialu);
			  int     getID(void);
			//DESTRUKTOR
			  ~WydzialyDICT(void);
	private:
			//METODY POMOCNICZE
			  void       open(void);
			  void       close(void);
			//NARZÊDZIA
			  mng::StreamDB * m_Stream;
			//KONSTRUKTORY
			  WydzialyDICT(void);
			  WydzialyDICT(WydzialyDICT&);
			  WydzialyDICT& operator=(WydzialyDICT&) ;
 friend DictMNG;
 };
}
//---------------------------------------------------------------------------
#endif
