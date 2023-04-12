//---------------------------------------------------------------------------

#ifndef RemontyDICTH
#define RemontyDICTH
#include <system.hpp>
#include <db.hpp>
namespace mng{ class StreamDB; }
namespace dict{
class DictMNG;
 class RemontyDICT{
	public:
			//INTERFEJS
			  static RemontyDICT &  instance(void);
			  String  getNazwa(const int _Id )const;
			  String  getNazwa(const String& _Kod )const;
			  String  getKod(const int _Id)const;
			  TField* fieldByName(const int _Id,const AnsiString& _FieldName, const bool _IdP=true);
			//DESTRUKTOR
			  ~RemontyDICT(void);
	private:
			//METODY POMOCNICZE
			  void       open(void);
			  void       close(void);
			//NARZÊDZIA
			  mng::StreamDB * m_Stream;
			//KONSTRUKTORY
			  RemontyDICT(void);
			  RemontyDICT(RemontyDICT&);
			  RemontyDICT& operator=(RemontyDICT&) ;
 friend DictMNG;
 };
}
//---------------------------------------------------------------------------
#endif
