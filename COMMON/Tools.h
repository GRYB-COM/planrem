//---------------------------------------------------------------------------
#ifndef ToolsH
#define ToolsH
#include <system.hpp>
namespace progcommon{
class Tools{
 public:
		//INTERFEJS
		  static String prepareSygnKUT(const String & _Sygn);
		  static String prepareNewSygnKUT(const String & _Sygn, const bool _Main=false, const String & _KodWydz="");
		  static String getMainSygnKUT(const String & _Sygn);

};
}//end namespace

//---------------------------------------------------------------------------
#endif
