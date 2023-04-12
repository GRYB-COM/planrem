//---------------------------------------------------------------------------

#ifndef PowiadEditorH
#define PowiadEditorH
#include <system.hpp>
#include <map>
#include <vector>
#include <db.hpp>
class IWaitForm;
namespace ptr     { class Pattern;  }
namespace mng     { class StreamDB; class TransactionDB; }
namespace jbutils { class TMyIni;   }
namespace editors{
 class PowiadEditor{
 public:
		//KLASY WEWNÊTRZNE
		  class Pars{
		  public:
			int        NrPowiad;
			int        Tryb;
			TDateTime  DataWystOd;
			TDateTime  DataWystDo;
			TDateTime  DataWyst;
			TDateTime  DataZakDo;

		  };
		//INTERFEJS
		  void setPars(const Pars& _Pars);
		  void open(void);
		  void wystaw(void);
          void usun(void);
 		  void print(void);
		  void close(void);
          mng::StreamDB  * getListaSprz(void);
		  mng::StreamDB  * getMaster(void);
		  mng::StreamDB  * getDetail(void);
		  ptr::Pattern   * getPatternDet(void);
		//STATIKI
		  static mng::StreamDB * m_READER;
		  static mng::StreamDB * m_READER_DET;
		  static ptr::Pattern  * m_PATTERN_DET;
		  static String  m_Path;
		  static String  m_PathHead;
		  static String  m_PathDet;

		//KONSTRUKTOR DESTRUKTOR
		   PowiadEditor(void);
		  ~PowiadEditor(void);
 private:
		//ATRYBUTY
		  Pars    m_Pars;
		  int     m_IdSesji;
		  int     m_IdPowiad;
		//NARZÊDZIA
		  mng::TransactionDB * m_Trans;
		  mng::StreamDB      * m_ListaSprzSDB;
		  mng::StreamDB      * m_ReaderSDB;
		  mng::StreamDB      * m_PowReSDB;
		  mng::StreamDB      * m_Pow2MagReSDB;
		  mng::StreamDB      * m_PowInsSDB;
		  mng::StreamDB      * m_Pow2MagInsSDB;
		  ptr::Pattern       * m_Pattern;
		  ptr::Pattern       * m_PatternDet;
		  jbutils::TMyIni    * m_Ini;
		//STA£E
		  static const String M_MAGAZYN_SQL;
		  static const String M_MAGAZYN_GROUP_SQL;
		  static const String M_MASTER_READ_SQL;
		  static const String M_DETAILS_READ_SQL;
		  static const String M_MASTER_INS_SQL;
		  static const String M_DETAILS_INS_SQL;
		  static const String M_READ_SQL;
		  static const String M_READ_BP_WHERE_SQL;
		  static const String M_READ_GROUP_SQL;
		  static const String M_READ_ZP_WHERE_SQL;
		  static const String M_READ_WEZW_SQL;
		//KLASY POMOCNICZE
		  class Key{
		   public:
		   int IdJednostki;
		   int NrKol;

		   bool operator<(const Key& _Key) const;
		  };
		  class Val{
		   public:
		   int    IdMag;
		   int    IdKomorki;
		   int    Rok;
		   String Depozyt;
   		   int    IdWydzialu;
		  };
		  typedef std::vector<Val> Vals;
		  typedef std::map<Key,Vals> Cont;
		//FUNKCJE POMOCNICZE
          String getQuery(void);
		  int  getNewIdSesji(void);
		  void make(void);
		  String getMagQuery(void);
		  void set2Cont(void);
		  void add2Cont(void);
		  void save2DB(void);
		  void add2PowSDB(const Key& _Key);
		  void add2Pow2MagSDB(const Vals& _Vals);
		  int  getNewIdPowiad(void);
		  int  getNewIdPowiad2Mag(void);
		  void preparePrinter(void);
		  void buffer();
		  void edit();
		  void __fastcall getDataWyst(TField *Sender, UnicodeString &Text, bool DisplayText);
		//ATRYBUTY
		  Cont m_Cont;
 };
 extern  AnsiString get(AnsiString Par);
 extern  AnsiString KodJW(AnsiString Par);
 extern  AnsiString MiejscJW(AnsiString Par);
 extern  AnsiString FaxJW(AnsiString Par);
 extern  AnsiString MiejscJW(AnsiString Par);
 extern  AnsiString ListaSprz(AnsiString Par);

 extern  AnsiString getDet(AnsiString Par);
 extern  AnsiString NrHarm(AnsiString Par);
 extern  AnsiString NrMag(AnsiString Par);
 extern  AnsiString NazSprz(AnsiString Par);
extern  AnsiString NrSprz(AnsiString Par);
extern  AnsiString Ilosc(AnsiString Par);


}//END NAMESPACE
//---------------------------------------------------------------------------
#endif
