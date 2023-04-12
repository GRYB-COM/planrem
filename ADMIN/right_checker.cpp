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
      mng::MessageDialog::warning("Brak uprawnieñ do przegl¹dania", "Sprawdzanie uprawnieñ", MB_OK);
   }

   return is_right;
}
//---------------------------------------------------------------------------

bool RightsChecker::rightToEdit(bool p_dispComm, const AnsiString& p_right)
{
   bool is_right = mng::Manager::instance().getUser().checkRight(mng::SI_Admin, p_right);

   if(!is_right && p_dispComm)
   {
      mng::MessageDialog::warning("Brak uprawnieñ do edycji", "Sprawdzanie uprawnieñ", MB_OK);
   }

   return is_right;
}
//---------------------------------------------------------------------------
bool RightsChecker::rightToSPT(bool p_dispComm)
{
   bool is_right = mng::Manager::instance().checkRight("RRADM");

   if(!is_right && p_dispComm)
   {
	  mng::MessageDialog::warning("Do wykonywania skryptów SPT nale¿y mieæ uprawnienia administratora", "Brak uprawnieñ", MB_OK);
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

