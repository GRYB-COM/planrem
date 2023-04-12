//---------------------------------------------------------------------------

#ifndef Sprz4SprReaderH
#define Sprz4SprReaderH
#include <system.hpp>
#include <vector>
namespace msg { class Sprz4Spr; }
namespace mng { class QueryDB;  }
namespace readers{
class Sprz4SprReader{
public:
		//KLASY WEWNETRZNE
		  struct Pars{
			int  Rok;
			int  MiesOd;
			int  MiesDo;
			bool Info;
		  };
		//INTERFEJS
		  void read(msg::Sprz4Spr& _Kont, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   Sprz4SprReader(void);
		  ~Sprz4SprReader(void);
private:

		//KLASY WEWNÊTRZNE
		  struct Queries{
		   String MainSQL;
		   String PlanSQL;
		   String RealSQL;
		   Queries(const String& _M, const String&  _P, const String& _R):MainSQL(_M),PlanSQL(_P),RealSQL(_R){}
		  };
		  struct Info{
		   String Plan;
		   String Real;
          };
		//FUNKCJE POMOCNICZE
		  void   prepare(mng::QueryDB * _QDB);
		  void   read(msg::Sprz4Spr& _Kont,mng::QueryDB * _QDB);
		  void   add(msg::Sprz4Spr& _Kont,mng::QueryDB * _QDB);
		  int    getIdSprz(const String _Typ, const int _Poz, const int _Harm, const int _IdH, const int _IdM);
		//ATRYBUTY
		  Pars m_Pars;
		  std::vector<Queries> m_SQL;
		//NARZÊDZIA
		  mng::QueryDB * m_RealQDB;
		  mng::QueryDB * m_PlanQDB;
		//STA£E
		  static const String M_SQL_REAL;
		  static const String M_SQL_PLAN;
		  static const String M_SQL_DOST;
		  static const String M_SQL_JP;
		  static const String M_SQL_WP;
		  static const String M_SQL_NP;
		  static const String M_SQL_SPRZET_PLAN;
		  static const String M_SQL_SPRZET_REAL;
		  static const String M_SQL_HARM_PLAN;
		  static const String M_SQL_HARM_REAL;
		  static const String M_ID_WP;
		//ZABRONIONE
		  Sprz4SprReader(const Sprz4SprReader&);
		  Sprz4SprReader& operator=(const Sprz4SprReader&);



};

}
//---------------------------------------------------------------------------
#endif
