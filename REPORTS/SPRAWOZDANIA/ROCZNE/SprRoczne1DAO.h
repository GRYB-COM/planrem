//---------------------------------------------------------------------------

#ifndef SprRoczne1DAOH
#define SprRoczne1DAOH
#include <db.hpp>
#include <dbclient.hpp>
#include "SprRoczneIDAO.h"
namespace readers  { class Sprz4SprReader; }
namespace msg      { class Sprz4Spr;       }
namespace mng      { class StreamDB;       }
namespace progzest{
 class SprRoczne1DAO :public SprRoczneIDAO{
 public:
	//INTERFEJS
	  virtual TClientDataSet* getDataSet(void);
	  virtual void            open(const SprRocznePars& _Pars);
	  virtual void           close(void);
	//KONSTRUKTOR DESTRUKTOR
	   SprRoczne1DAO(void);
	   virtual ~SprRoczne1DAO(void);
  private:
	//FUNKCJE POMOCNICZE
	  void   createClient(void);
	  void   addHF(const msg::Sprz4Spr & _Buff);
	  void   addW(const msg::Sprz4Spr & _Buff);
	  void   addK( const msg::Sprz4Spr & _Buff);
	  void   addU(const int _IdWydz, const String & _KodW, const int _IdKom, const String& _KodK, const msg::Sprz4Spr & _Buff);
	  void   addDetails(const msg::Sprz4Spr & _Buff);
	  void   fillLP(void);
	  void   insToClient(void * _Val, const bool _Proc, const bool _Podz=true);
	  String getZadanie(const int _IdHarm);
	  String getInfo(const String& _Pl);
	//NARZÊDZIA
	  TClientDataSet          * m_Client;
	  readers::Sprz4SprReader * m_Reader;
	  mng::StreamDB           * m_ZadSDB;
	//ATRYBUTY
	  SprRocznePars m_Pars;
	//ZABRONIONE
	  SprRoczne1DAO(const SprRoczne1DAO& );
	  SprRoczne1DAO& operator=(const SprRoczne1DAO& );
   //STA£E
	 static const int M_HEAD_IDX;
	 static const int M_FOOT_IDX;
	 static const int M_DET_IDX;
	 static const String M_HEAD_SPAN;
	 static const String M_HEAD_SPAN_EXT;
	 static const String M_FOOT_SPAN;
     static const String M_TR_ATRIB;
	 static const String M_STYLE_CENTER;
	 static const String M_STYLE_RIGHT;
	 static const String M_NUMBER_FRMT;
	 static const String M_NULL_VAL;
 };
}
//---------------------------------------------------------------------------
#endif
