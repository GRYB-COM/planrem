//---------------------------------------------------------------------------

#ifndef EksportCfgWriterH
#define EksportCfgWriterH
namespace msg {class  EksportCfg; }
namespace writers{
class EksportCfgWriter{
public:
	//INTERFEJS
	  static EksportCfgWriter& instance(void);
	  void   run(const msg::EksportCfg& _Cfg);
private:
	//KONSTRUKTOR
	  EksportCfgWriter(void);
	//ZABRONIONE
	  EksportCfgWriter(EksportCfgWriter&);
	  EksportCfgWriter& operator=(EksportCfgWriter&);
};
}

//---------------------------------------------------------------------------
#endif
