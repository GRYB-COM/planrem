//---------------------------------------------------------------------------
#ifndef WydzIDH
#define WydzIDH
namespace readers { class GlownyReader; }
namespace msg{
 class WydzID{
 public:
		//INTERFEJS
		  int    getID(void)const;
		  bool   isDefined(void)const;
		  String getCode(void)const;
		  String getName(void)const;
		  String getCM(const String & _Pause)const;
		//KONSTRUKTORY
		  WydzID(void);
		  WydzID(const WydzID&);
		  WydzID(const int);
		//OPERATORY
		  WydzID & operator=(const WydzID&);
				   operator int(void);
 private:
		//ATRYBUTY
		  int m_ID;
		//PRZYJACIELE
		  readers::GlownyReader;
 };
}
//---------------------------------------------------------------------------
#endif
