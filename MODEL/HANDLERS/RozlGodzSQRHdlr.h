//---------------------------------------------------------------------------

#ifndef RozlGodzSQRHdlrH
#define RozlGodzSQRHdlrH
#include "SQR\sqr_event_v.h"
namespace sqr { class SQRScript; }
namespace handlers {
class RozlGodzSQRHdlr :public sqr::T_Event{
public:
	  virtual bool execute(const sqr::SQRScript &aSkrypt);
	  virtual bool checkCode(AnsiString code);
				   RozlGodzSQRHdlr(void);
	  virtual     ~RozlGodzSQRHdlr(void);
};
}
//---------------------------------------------------------------------------
#endif
