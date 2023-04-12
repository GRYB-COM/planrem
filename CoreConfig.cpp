// ---------------------------------------------------------------------------
#pragma hdrstop
#include "CoreConfig.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------
#include "..\_INCLUDE\MANAGER\Stream_DB.h"

// ---------------------------------------------------------------------------
CoreConfig::CoreConfig(void)
{

}

// ---------------------------------------------------------------------------
void CoreConfig::initialize(void)
{
  terminate();
}

// ---------------------------------------------------------------------------
CoreConfig::~CoreConfig(void)
{
  terminate();
}

// ---------------------------------------------------------------------------
void CoreConfig::terminate(void)
{

}

// ---------------------------------------------------------------------------
CoreConfig& CoreConfig::instance(void)
{
  static CoreConfig _CC;
  return _CC;
}

// ---------------------------------------------------------------------------
void CoreConfig::suckKUTa(TDataSet* _DS)
{
  m_Depozyt = _DS->FieldByName("DEPOZYT")->AsAnsiString;
  m_IdMag = _DS->FieldByName("ID_MAG")->AsInteger;
  m_SygnMag = _DS->FieldByName("SYGN_MAG")->AsAnsiString;
  m_IdHarm = _DS->FieldByName("ID_HARM")->AsInteger;
  m_IdSprzetu = _DS->FieldByName("ID_SPRZETU")->AsInteger;
  m_Uwagi = _DS->FieldByName("UWAGI")->AsAnsiString;
  m_Ilosc = _DS->FieldByName("ILOSC")->AsCurrency;
  m_DataPrzekaz = _DS->FieldByName("DATA_PRZEKAZ")->AsDateTime;
  m_Status = _DS->FieldByName("STATUS")->AsAnsiString;
  m_DataPrzyj = _DS->FieldByName("DATA_PRZYJ")->AsDateTime;
  m_NrRej = _DS->FieldByName("NR_REJ")->AsAnsiString;
  m_NrFabr = _DS->FieldByName("NR_FABR")->AsAnsiString;
  m_IdJednostki = _DS->FieldByName("ID_JEDNOSTKI")->AsInteger;
  m_Podstawa = _DS->FieldByName("PODSTAWA")->AsAnsiString;
  m_ProtPrzekaz = _DS->FieldByName("PROT_PRZEKAZ")->AsAnsiString;
  m_ProtPrzyj = _DS->FieldByName("PROT_PRZYJ")->AsAnsiString;
  m_IdRemontu = _DS->FieldByName("ID_REMONTU")->AsInteger;
  m_NrHarm = _DS->FieldByName("NR_HARM")->AsInteger;
  m_IdWarsztatu = _DS->FieldByName("ID_KOMORKI")->AsInteger;
  m_KodWarsztatu = _DS->FieldByName("KOD_WARSZTATU")->AsInteger;
}

// ---------------------------------------------------------------------------
namespace printKut
{ /*
  // -------------------   MAKRA -----------------------------------------------
  AnsiString Depozyt(AnsiString Arg){return CoreConfig::instance().m_Depozyt;}

  // ---------------------------------------------------------------------------
  AnsiString IdMag(AnsiString Arg){return CoreConfig::instance().m_IdMag;}

  // ---------------------------------------------------------------------------
  AnsiString SygnMag(AnsiString Arg){return CoreConfig::instance().m_SygnMag;}

  // ---------------------------------------------------------------------------
  AnsiString IdHarm(AnsiString Arg){return CoreConfig::instance().m_IdHarm;}

  // ---------------------------------------------------------------------------
  AnsiString IdSprzetu(AnsiString Arg){return CoreConfig::instance().m_IdSprzetu;}

  // ---------------------------------------------------------------------------
  AnsiString Uwagi(AnsiString Arg){return CoreConfig::instance().m_Uwagi;}

  // ---------------------------------------------------------------------------
  AnsiString Ilosc(AnsiString Arg){return CoreConfig::instance().m_Ilosc;}

  // ---------------------------------------------------------------------------
  AnsiString DataPrzekaz(AnsiString Arg){return CoreConfig::instance().m_DataPrzekaz;}

  // ---------------------------------------------------------------------------
  AnsiString Status(AnsiString Arg){return m_Status;}

  // ---------------------------------------------------------------------------
  AnsiString DataPrzyj(AnsiString Arg){return m_DataPrzyj;}

  // ---------------------------------------------------------------------------
  AnsiString NrRej(AnsiString Arg){return m_NrRej;}

  // ---------------------------------------------------------------------------
  AnsiString NrFabr(AnsiString Arg){return m_NrFabr;}

  // ---------------------------------------------------------------------------
  AnsiString IdJednostki(AnsiString Arg){return m_IdJednostki;}

  // ---------------------------------------------------------------------------
  AnsiString Podstawa(AnsiString Arg){return m_Podstawa;}

  // ---------------------------------------------------------------------------
  AnsiString ProtPrzekaz(AnsiString Arg){return m_ProtPrzekaz;}

  // ---------------------------------------------------------------------------
  AnsiString ProtPrzyj(AnsiString Arg){return m_ProtPrzyj;}

  // ---------------------------------------------------------------------------
  AnsiString IdRemontu(AnsiString Arg){return m_IdRemontu;}

  // ---------------------------------------------------------------------------
  AnsiString NrHarm(AnsiString Arg){return m_NrHarm;}

  // ---------------------------------------------------------------------------
  AnsiString IdWarsztatu(AnsiString Arg){return m_IdWarsztatu;}

  // ---------------------------------------------------------------------------
  AnsiString KodWarsztatu(AnsiString Arg){return m_KodWarsztatu;}
  // ---------------------------------------------------------------------------
*/}
