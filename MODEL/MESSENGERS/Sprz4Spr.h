//---------------------------------------------------------------------------

#ifndef Sprz4SprH
#define Sprz4SprH
#include <map>
#include <system.hpp>
namespace Db { class TDataSet;}
namespace readers{ class Sprz4SprReader;}
namespace msg{
class Sprz4Spr{
public:

	//KLASY WEWNÊTRZNE
	  static const int M_ID_NP;
	  struct Key{
		int IdWydz;
		int IdKom;
		int Pozycja;
		int IdUsl;
		int IdSprz;
		int IdRem;
		int IdHarm;
		Key(void);
		bool operator<(const Key& _Key)const ;
		bool getPlan(void)const {return Pozycja != M_ID_NP;}
		Key& fromDS(Db::TDataSet* _DS);
		String toStr(void);
	  };
	  struct InfoBuff{
	   String Plan;
	   String Real;
	   InfoBuff& operator+=(const InfoBuff& _Info);
       InfoBuff& fromDS(Db::TDataSet* _DS);

	  };
	  struct Val{
		Currency IloscP;
		Currency IloscR;
		Currency IloscRZPlanu;
		Currency IloscWR;
		Currency IloscWRZPlanu;
		Currency IloscD;
		Currency IloscDZPlanu;
		Currency IloscND;
		Currency IloscNDZPlanu;
		Currency RBHP;
		Currency RBHR;
		InfoBuff Info;
        String   Zad;
		Val& operator+=(const Val& _Val);
		Val& fromDS(Db::TDataSet* _Ds, const bool _Plan);
		bool isEmpty(void);
		Currency getIloscWR(void)const;
		Currency getProcWR(void) const;
		Currency getProcND(void) const;
		Currency getProcR(void) const;
		Currency getProc(void) const;
		String   toStr(void);
	  };
	  typedef std::map<Key,Val>::iterator       iterator;
	  typedef std::map<Key,Val>::const_iterator const_iterator;
	//INTERFEJS
	  iterator         begin(void);
	  const_iterator   begin(void) const;
	  iterator         end(void);
	  const_iterator   end(void) const;
	  void             add(const Key& _Key, const Val& _Val, const InfoBuff& _Info =InfoBuff());
	  void             add(Db::TDataSet* _Ds, const InfoBuff& _Info =InfoBuff());
	  Val&             operator[](const Key& _Key);
	  Val&             operator[](Db::TDataSet* _Ds);
	  Val              sum(const Key& _Key) const;
      int              size(void) const;
	  void             clear(void);
	//STA£E
	  static const String M_COL_INFO_SEP;
	  static const String M_ROW_INFO_SEP;
private:
	//ATRYBUTY
	  std::map<Key,Val> m_Kont;
	//PRZYJACIELE
	  friend readers::Sprz4SprReader;
	//FUNKCJE POMOCNICZE
      void setWR(void);
};
}
//---------------------------------------------------------------------------
#endif
