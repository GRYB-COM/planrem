//---------------------------------------------------------------------------

#ifndef HarmIDH
#define HarmIDH
namespace msg{
 class HarmID{
  public:
		//INTERFEJS
		  int NrHarm;
		  int Rok;
		//KONSTRUKTOR
          HarmID(void) :NrHarm(-1), Rok(-1){}
		  HarmID(const int _NrHarm, const int _Rok) :NrHarm(_NrHarm), Rok(_Rok){}
 };
}
//---------------------------------------------------------------------------
#endif
