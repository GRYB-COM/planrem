//---------------------------------------------------------------------------

#ifndef KomorkiDICTH
#define KomorkiDICTH
#include <system.hpp>
#include <db.hpp>
namespace mng{ class StreamDB; }
namespace dict{
class DictMNG;
 class KomorkiDICT{
	public:
			//INTERFEJS
			  static KomorkiDICT &  instance(void);
			  String  getKodWydzialu(const int _Id, const bool _IdWydz=false)const;
			  int     getIdWydzialu(const int _IdKomorki)const;
			  int     getIdKomorki(const String& _KodWydz)const;
			  TField* fieldByName(const int _IdKomorki,const AnsiString& _FieldName);
			  void    first(void);
			  void    next(void);
			  bool    isEof(void);
			  void    close(void);
			  String  getKod(void);
			  String  getKod(const int _IdKomorki);
			  String  getMasterKod(void);
			  String  getName(void);
			  String  getName(const int _IdKomorki);
			  int     getID(void);
			  int     getMasterID(void);
			//DESTRUKTOR
			  ~KomorkiDICT(void);
	private:
			//METODY POMOCNICZE
			  void       open(void);
			//NARZÊDZIA
			  mng::StreamDB * m_Stream;
			//KONSTRUKTORY
			  KomorkiDICT(void);
			  KomorkiDICT(KomorkiDICT&);
			  KomorkiDICT& operator=(KomorkiDICT&) ;
  friend DictMNG;
 };
}
//---------------------------------------------------------------------------
#endif
