//---------------------------------------------------------------------------
#ifndef platformH
#define platformH
#include <system.hpp>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Platform
{
public:
   static bool Initialize(void);
   static void Terminate();
   static void showException(TObject* Sender, Exception * E, const AnsiString& _Det="");
   static bool printErr(void);
private:
   Platform();
   static void updateIsRejestr(void);
   static String m_MessErr;
   static String m_DetErr;
   static String m_Det1Err;
};

#endif
