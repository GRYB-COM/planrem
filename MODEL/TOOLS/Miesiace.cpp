//---------------------------------------------------------------------------
 #pragma hdrstop
#include "Miesiace.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
Miesiace::SlownieSTR::SlownieSTR(const String& _M, const String& _D)
:Mianownik(_M),
 Dopelniacz(_D)
{

}
//---------------------------------------------------------------------------
Miesiace::SlownieSTR::SlownieSTR(const SlownieSTR& _Sl)
:Mianownik(_Sl.Mianownik),
 Dopelniacz(_Sl.Dopelniacz)
{

}
//---------------------------------------------------------------------------
Miesiace::Miesiac::Miesiac(void)
:Slownie("nieustawiony","nieustawiony"),
 LiczbaDni(-1)
{

}
//---------------------------------------------------------------------------
Miesiace::Miesiac::Miesiac(const SlownieSTR& _Sl,const int _LDni)
:Slownie(_Sl),
 LiczbaDni(_LDni)
{

}
//---------------------------------------------------------------------------
Miesiace::Miesiac::Miesiac(const Miesiac & _Mies)
:Slownie(_Mies.Slownie),
 LiczbaDni(_Mies.LiczbaDni)
{

}
//---------------------------------------------------------------------------
Miesiace::Miesiace(void)
{
 m_Mies[1]  = Miesiac(SlownieSTR("styczeñ","stycznia"),31);
 m_Mies[2]  = Miesiac(SlownieSTR("luty","lutego"),28);
 m_Mies[3]  = Miesiac(SlownieSTR("marzec","marca"),31);
 m_Mies[4]  = Miesiac(SlownieSTR("kwiecieñ","kwietnia"),30);
 m_Mies[5]  = Miesiac(SlownieSTR("maj","maja"),31);
 m_Mies[6]  = Miesiac(SlownieSTR("czerwiec","czerwca"),30);
 m_Mies[7]  = Miesiac(SlownieSTR("lipiec","lipca"),31);
 m_Mies[8]  = Miesiac(SlownieSTR("sierpieñ","sierpnia"),31);
 m_Mies[9]  = Miesiac(SlownieSTR("wrzesieñ","wrzeœnia"),30);
 m_Mies[10] = Miesiac(SlownieSTR("paŸdziernik","paŸdziernika"),31);
 m_Mies[11] = Miesiac(SlownieSTR("listopad","listopada"),30);
 m_Mies[12] = Miesiac(SlownieSTR("grudzieñ","grudnia"),31);
}
//---------------------------------------------------------------------------
Miesiace::Miesiac  Miesiace::operator[](const int _Mies) const
{
 Miesiac _Miesiac;
 if(_Mies > 0 && _Mies <=12)
 {
  std::map<int,Miesiac>::const_iterator _ItF(m_Mies.find(_Mies));
  if(_ItF != m_Mies.end())
  {
   _Miesiac = _ItF->second;
  }
 }
 return _Miesiac;
}

