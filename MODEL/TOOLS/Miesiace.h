//---------------------------------------------------------------------------

#ifndef MiesiaceH
#define MiesiaceH
#include <system.hpp>
#include <map>
class Miesiace{
public:
	   //KLASY WEWNÊTRZNIE
		 struct SlownieSTR{
		  String Mianownik;
		  String Dopelniacz;
		  SlownieSTR(const String& _M, const String& _D);
		  SlownieSTR(const SlownieSTR & _Sl);
		 };
		 struct Miesiac{
		 SlownieSTR Slownie;
		 int        LiczbaDni;
		 Miesiac(void);
		 Miesiac(const SlownieSTR& _Sl, const int _LDni);
		 Miesiac(const Miesiac& _Mies);
		 };
	   //INTERFEJS
		 Miesiac  operator[](const int _Mies) const;
	   //KONSTRUKTOR
		 Miesiace(void);
private:
	  //ATRYBUTY
		std::map<int,Miesiac> m_Mies;

};
//---------------------------------------------------------------------------
#endif
