//---------------------------------------------------------------------------

#ifndef GlownyReaderH
#define GlownyReaderH
namespace msg { class GlownyID; }
namespace readers{
class GlownyReader{
public:
	  //INTERFEJS
		static msg::GlownyID  read(void);
		static msg::GlownyID  read(const String& _Ids, const String& _BaseCode="");

};
}
//---------------------------------------------------------------------------
#endif
