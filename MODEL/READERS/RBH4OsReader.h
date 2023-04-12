//---------------------------------------------------------------------------

#ifndef RBH4OsReaderH
#define RBH4OsReaderH
#include <system.hpp>
namespace msg { class RBH4War; class RBH4Mies; class RBH; }
namespace sgda{ class DAReader;}
namespace readers{
 class RBH4OsReader{
  public:
		//INTERFEJS
		  struct Pars{
		   int  Rok;
		   Pars(void);
          };
		  void read(msg::RBH4War& _Buff, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   RBH4OsReader(void);
		  ~RBH4OsReader(void);
  private:
		//NARZÊDZIA
		  sgda::DAReader * m_Reader;
		//ATRYBUTY
		  Pars m_Pars;
		  static const AnsiString M_COL_LIST;
		  static const AnsiString M_TABLE_REF;
		  static const AnsiString M_GROUP_BY_LIST;
		//FUNKCJE POMOCNICZE
		  void prepareReader(void);
		  void add(msg::RBH4Mies& _Val);
		  void add(msg::RBH& _Val);
		  void set(msg::RBH& _Val);

 };
}
//---------------------------------------------------------------------------
#endif
