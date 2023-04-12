//---------------------------------------------------------------------------
#pragma hdrstop
#include "DictMNG.h"
#include "KomorkiDICT.h"
#include "WydzialyDICT.h"
#include "KodyUslugDICT.h"
#include "SprzetDICT.h"
#include "RemontyDICT.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
void DictMNG::close(void)
{
  dict::SprzetDICT::instance().close();
  dict::KomorkiDICT::instance().close();
  dict::WydzialyDICT::instance().close();
  dict::KodyUslugDICT::instance().close();
  dict::RemontyDICT::instance().close();

}
