//---------------------------------------------------------------------------
#ifndef KomIDH
#define KomIDH
namespace readers { class GlownyReader; }
namespace msg{
 class KomID{
 public:
		//INTERFEJS
		  int    getID(void)const;
		  bool   isDefined(void)const;
		  String getCode(void)const;
		  String getName(void)const;
		  String getCM(const String& _Pause =" ")const;
		//KONSTRUKTORY
		  KomID(void);
		  KomID(const KomID&);
		  KomID(const int);
		//OPERATORY
		  KomID & operator=(const KomID&);
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
