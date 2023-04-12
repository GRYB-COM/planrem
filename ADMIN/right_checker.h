//---------------------------------------------------------------------------

#ifndef right_checkerH
#define right_checkerH
#include <vcl.h>
//---------------------------------------------------------------------------

class RightsChecker

{
   private:

   public:

   RightsChecker();

   static bool rightToInfo(bool);

   static bool rightToEdit(bool, const AnsiString&);

   static bool rightToSPT(bool _DispMsg=true);

   static bool rightToDelMag(void);


};
//---------------------------------------------------------------------------
#endif
