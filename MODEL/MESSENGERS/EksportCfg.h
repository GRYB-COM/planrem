//---------------------------------------------------------------------------
#ifndef EksportCfgH
#define EksportCfgH
#include <system.hpp>

namespace msg{
class EksportCfg{
public:
	//INTERFEJS
	  AnsiString getPath(void)const;
	  void   setPath(const AnsiString& _Path);
	  AnsiString getFileName(void)const;
	  void   setFileName(const AnsiString& _Path);
	  AnsiString getXML(void)const;
	  void   setXML(const AnsiString& _Xml);
	  bool   isDefined(void);
 private:
	//ATRYBUTY
	  AnsiString m_Path;
	  AnsiString m_FileName;
};
}
//---------------------------------------------------------------------------
#endif
