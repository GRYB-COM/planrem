//---------------------------------------------------------------------------
#ifndef model_readers_RBHReaderH
#define model_readers_RBHReaderH
#include <system.hpp>

namespace msg     { class RBH4War; class RBH4Os; class RBH4Mies; class RBH; }
namespace sgda    { class DAReader;}
namespace jbutils { class TMyIni;  }
namespace readers{
 class RBHReader{
  public:
		//INTERFEJS
		  struct Pars{
		   bool AddPlan;
		   int  Rok;
		   int  RokPlan;
		   int  IdKomorki;
		   int  Miesiac;
		   Pars(void);
		  };
		  void read(msg::RBH4War& _Buff, const Pars& _Pars);
		  void read(msg::RBH4Os& _Buff, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   RBHReader(void);
		  ~RBHReader(void);
  private:
		//NARZÊDZIA
		  sgda::DAReader  * m_Reader;
		  sgda::DAReader  * m_ReaderDel;
		  sgda::DAReader  * m_EtatyDAR;
		  jbutils::TMyIni * m_Ini;
		//ATRYBUTY
		  Pars m_Pars;

		  static const AnsiString M_COL_LIST;
		  static const AnsiString M_TABLE_REF;
		  static const AnsiString M_ORDER_LIST;
		  static const AnsiString M_COL_LIST_DEL;
		  static const AnsiString M_TABLE_REF_DEL;
		  static const AnsiString M_ORDER_LIST_DEL;
		//KLASY POMOCNICZE
		  class Etaty{
           public:
		   Currency Pr;
		   Currency Npr;
		   Currency Kor;
          };
		//FUNKCJE POMOCNICZE
		  void readKom(msg::RBH4War& _Buff, const Pars& _Pars);
		  void readKom(msg::RBH4Os& _Buff, const Pars& _Pars);
		  void readDel(msg::RBH4War& _Buff, const Pars& _Pars);
		  void readDel(msg::RBH4Os& _Buff, const Pars& _Pars);
		  void prepareReader(void);
		  void prepareReaderDel(void);
		  void prepareEtatyDAR(void);
		  void add(msg::RBH4Mies& _Val, Etaty& _Et);
		  void add(msg::RBH& _Val, Etaty& _Et);
		  void set(msg::RBH& _Val, Etaty& _Et);
		  void setEtat(Etaty& _Et);

 };
}
//---------------------------------------------------------------------------
#endif
