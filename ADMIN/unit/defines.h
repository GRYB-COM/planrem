//---------------------------------------------------------------------------

#include <vcl.h>
//#include <manager\connection_info.h>

#ifndef definesH
#define definesH
//---------------------------------------------------------------------------

class Defines
{
   public:

/*   enum statusOper
      {  stAktyw = 'A',
         stZawiesz = 'H',
         stZablok = 'T',
         stUnknown = '#'
      };*/
   enum RodzajAct
      {
         actDodaj = 'D',
         actZmien = 'Z',
         actUsun = 'U',
         actUnknown = '#'
      };

   //! Oznaczenie tabel
   enum TableID
   {
      tidOPR=0,  //!< OP_OPER
      tidSLF,    //!< OP_SLFUN
      tidGRP,    //!< OP_GRUPY
      tidGRF,    //!< OP_GRFUN
      tidOFN,    //!< OP_OPFUN
      tidOGR,    //!< OP_OPERGRUP
      tidIRS     //!< IS_REJESTR
   };

   enum VarriantOfParam
   {
      parGlbLinks=0,
      parLinkApp,
      parApp
   };

   enum VarriantOfLinks
   {
      glbLinks = 0,
      appLinks
   };

   enum TypeOfAction
   {
      actInfo = 'I',
      actAppend = 'D',
      actEdit = 'Z'
   };

   static int statusToInt(char);

   static AnsiString primaryKey(TableID table_id);

   static AnsiString tableName(TableID table_id);

   static AnsiString getStatus(char);

   //static int kindToInt(const mng::ConnectionInfo::DbKind&);

   //static int protocolToInt(const mng::ConnectionInfo::Protocol&);

   //static int libToInt(const mng::ConnectionInfo::LibType&);

   //static AnsiString kindToStr(const mng::ConnectionInfo::DbKind&);

   //static AnsiString protocolToStr(const mng::ConnectionInfo::Protocol&);

   //static AnsiString libToStr(const mng::ConnectionInfo::LibType&);

};

#endif
