// ---------------------------------------------------------------------------
#ifndef CoreConfigH
#define CoreConfigH
// ---------------------------------------------------------------------------
#include <DBClient.HPP>

// ---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}


  class CoreConfig
  {
  public:
	// INTERFEJS
	AnsiString m_Depozyt;
	int m_IdMag;
	AnsiString m_SygnMag;
	int m_IdHarm;
	int m_IdSprzetu;
	AnsiString m_Uwagi;
	Currency m_Ilosc;
	TDateTime m_DataPrzekaz;
	AnsiString m_Status;
	TDateTime m_DataPrzyj;
	AnsiString m_NrRej;
	AnsiString m_NrFabr;
	int m_IdJednostki;
	AnsiString m_Podstawa;
	AnsiString m_ProtPrzekaz;
	AnsiString m_ProtPrzyj;
	int m_IdRemontu;
	int m_NrHarm;
	int m_IdWarsztatu;
	int m_KodWarsztatu;

	static CoreConfig& instance(void);
	void initialize(void);

	void suckKUTa(TDataSet* _DS);


	// DESTRUKTOR
	void terminate(void);
	~CoreConfig(void);

  private:
	// ATRYBUTY
	int m_Rok;

	mng::StreamDB* m_SDB;
	// KONSTRUKTOR
	CoreConfig(void);
  };
#endif
