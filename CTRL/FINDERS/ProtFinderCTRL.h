//---------------------------------------------------------------------------

#ifndef ProtFinderCTRLH
#define ProtFinderCTRLH
#include <system.hpp>
namespace finders{
class  ProtFinder;
class  T_FindProtFRM;
class ProtFinderCTRL{
public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		   public:
		   int IdProtokolu;
		   int Rok;
           int IdWydzialu;
		   Pars(void);
		  };
		//INTERFEJS
		  int find(int & _Rok, int& _IdWydz, int& _IdProt, const Pars& _Pars);
		//KONSTRUKTOR DESTRUKTOR
		   ProtFinderCTRL(void);
		  ~ProtFinderCTRL(void);
private:
		//ATRYBUTY
		  Pars m_Pars;
		//METODY POMOCNICZE
		  void        open(void);
		  int         find(int & _Rok, int& _IdWydz,int& _IdProt);
		  void        close(void);

		//ZDARZENIA
		  void __fastcall searchBTClick(TObject *Sender);
		//MARZÊDZIA
		  ProtFinder     * m_Finder;
		  T_FindProtFRM  * m_SearchForm;
};

}//end namespace finders
//---------------------------------------------------------------------------
#endif
