//---------------------------------------------------------------------------
#ifndef model_readers_RBHPlanReaderH
#define model_readers_RBHPlanReaderH
#include <System.hpp>
namespace msg { class RBH4War; class RBH4Mies; class RBH; }
namespace sgda{ class DAReader;}
namespace readers{
 class RBHPlanReader{
  public:
		//INTERFEJS
		  struct Pars{
		   int  Rok;
		   Pars(void);
          };
		  void read(msg::RBH4War& _Buff, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   RBHPlanReader(void);
		  ~RBHPlanReader(void);
  private:
		//NARZÊDZIA
		  sgda::DAReader * m_Reader;
		//ATRYBUTY
          Pars m_Pars;
		  static const AnsiString M_COL_LIST;
		  static const AnsiString M_TABLE_REF;
		  static const AnsiString M_GROUP_BY_LIST;
		//FUNKCJE POMOCNICZE
		  void openReader(void);
		  void prepareReader(void);
		  void add(msg::RBH4Mies& _Val);
		  void closeReader(void);

 };
}
//---------------------------------------------------------------------------
#endif
