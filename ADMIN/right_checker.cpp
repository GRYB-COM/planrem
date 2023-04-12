//---------------------------------------------------------------------------


#pragma hdrstop

#include "right_checker.h"
#include <manager\user.h>
#include <manager\is_manager.h>
#include <manager\message_dlg.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

RightsChecker::RightsChecker()
{
}
//---------------------------------------------------------------------------

bool RightsChecker::rightToInfo(bool p_dispComm)
{
   bool is_right = mng::Manager::instance().getUser().checkRight(mng::SI_Admin, "ADINF");

   if(!is_right && p_dispComm)
   {
      mng::MessageDialog::warning("Brak uprawnie� do przegl�dania", "Sprawdzanie uprawnie�", MB_OK);
   }

   return is_right;
}
//---------------------------------------------------------------------------

bool RightsChecker::rightToEdit(bool p_dispComm, const AnsiString& p_right)
{
   bool is_right = mng::Manager::instance().getUser().checkRight(mng::SI_Admin, p_right);

   if(!is_right && p_dispComm)
   {
      mng::MessageDialog::warning("Brak uprawnie� do edycji", "Sprawdzanie uprawnie�", MB_OK);
   }

   return is_right;
}
//---------------------------------------------------------------------------
bool RightsChecker::rightToSPT(bool p_dispComm)
{
   bool is_right = mng::Manager::instance().checkRight("RRADM");

   if(!is_right && p_dispComm)
   {
	  mng::MessageDialog::warning("Do wykonywania skrypt�w SPT nale�y mie� uprawnienia administratora", "Brak uprawnie�", MB_OK);
   }

   return is_right;
}
//---------------------------------------------------------------------------
bool RightsChecker::rightToDelMag(void)
{
   bool is_right = mng::Manager::instance().checkRight("RRDSP");

   return is_right;
}
//---------------------------------------------------------------------------

