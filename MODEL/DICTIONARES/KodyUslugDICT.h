//---------------------------------------------------------------------------

#ifndef KodyUslugDICTH
#define KodyUslugDICTH
#include <system.hpp>
#include <db.hpp>
namespace mng{ class StreamDB; }
namespace dict{
class DictMNG;
 class KodyUslugDICT{
	public:
			//INTERFEJS
			  static    KodyUslugDICT &  instance(void);
			  String    getNazwa(const int _Id, const bool _IdP=true )const;
			  int       getPozycja(const int _Id)const;
			  TField*   fieldByName(const int _Id,const AnsiString& _FieldName, const bool _IdP=true);
			  void      first(void);
			  void      next(void);
			  bool      isEof(void);
			  String    getKod(void);
			  String    getName(void);
			  int       getID(void);
			  int       getID2(void);
			  TDataSet* getDataSet(void);

			//DESTRUKTOR
			  ~KodyUslugDICT(void);
	private:
			//METODY POMOCNICZE
			  void       open(void);
			  void       close(void);
			//NARZÊDZIA
			  mng::StreamDB * m_Stream;
			//KONSTRUKTORY
			  KodyUslugDICT(void);
			  KodyUslugDICT(KodyUslugDICT&);
			  KodyUslugDICT& operator=(KodyUslugDICT&) ;
 friend DictMNG;
 };
}
//---------------------------------------------------------------------------
#endif
