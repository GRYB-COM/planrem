//---------------------------------------------------------------------------

#ifndef SprRoczneDAOH
#define SprRoczneDAOH
#include <db.hpp>
#include <dbclient.hpp>
#include "SprRoczneIDAO.h"

namespace readers  { class Sprz4SprReader; }
namespace msg      { class Sprz4Spr;       }
namespace mng      { class StreamDB;       }
namespace progzest{
 class SprRoczneDAO :public SprRoczneIDAO{
 public:
	//INTERFEJS
	  virtual TClientDataSet* getDataSet(void);
	  virtual void            open(const SprRocznePars& _Pars);
	  virtual void            close(void);
	//KONSTRUKTOR DESTRUKTOR
	   SprRoczneDAO(void);
	   virtual ~SprRoczneDAO(void);
  private:
	//FUNKCJE POMOCNICZE
	  void   createClient(void);
	  void   addHF(const msg::Sprz4Spr & _Buff);
	  void   addW(const msg::Sprz4Spr & _Buff);
	  void   addK( const msg::Sprz4Spr & _Buff);
	  void   addU(const int _IdWydz, const String & _KodW, const int _IdKom, const String& _KodK, const msg::Sprz4Spr & _Buff);
	  void   addDetails(const msg::Sprz4Spr & _Buff);
	  void   fillLP(void);
	  String getZadanie(const int _IdHarm);
	  String getInfo(const String& _Pl);
	//NARZÊDZIA
	  TClientDataSet          * m_Client;
	  readers::Sprz4SprReader * m_Reader;
	  mng::StreamDB           * m_ZadSDB;
	//ATRYBUTY
      SprRocznePars m_Pars;
	//ZABRONIONE
	  SprRoczneDAO(const SprRoczneDAO& );
	  SprRoczneDAO& operator=(const SprRoczneDAO& );
   //STA£E
	 static const int M_HEAD_IDX;
	 static const int M_FOOT_IDX;
	 static const int M_DET_IDX;
	 static const String M_HEAD_SPAN;
	 static const String M_HEAD_SPAN_EXT;
	 static const String M_FOOT_SPAN;
     static const String M_TR_ATRIB;
 };
}
//---------------------------------------------------------------------------
#endif
