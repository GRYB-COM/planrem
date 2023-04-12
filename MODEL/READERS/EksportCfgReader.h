//---------------------------------------------------------------------------

#ifndef EksportCfgReaderH
#define EksportCfgReaderH
namespace msg {class  EksportCfg; }
namespace readers{
class EksportCfgReader{
public:
	//INTERFEJS
	  static EksportCfgReader& instance(void);
	  msg::EksportCfg   run(void);
private:
	//KONSTRUKTOR
	  EksportCfgReader(void);
	//ZABRONIONE
	  EksportCfgReader(EksportCfgReader&);
	  EksportCfgReader& operator=(EksportCfgReader&);
};
}

//---------------------------------------------------------------------------
#endif
