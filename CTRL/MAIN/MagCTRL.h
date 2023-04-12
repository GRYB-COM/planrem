//---------------------------------------------------------------------------

#ifndef MagCTRLH
#define MagCTRLH
#include <system.hpp>
class T_NowyMagFRM;
class T_MagFRM;
class T_PrzyjSprzFRM;
class T_PrzekSprzFRM;
namespace msg { class MagID; };
namespace main{
 class  MagCTRL{
  public:
		//INTERFEJS
		  void receive(void);
		  void add(void);
		  void edit(void);
		  void edit(const msg::MagID& _MagID);
		  void issue(void);
		//KONSTRUKTOR DESTRUKTOR
		   MagCTRL(void);
		  ~MagCTRL(void);
  private:
		//NARZÊDZIA
		  T_NowyMagFRM   * m_NowyMagFRM;
		  T_MagFRM       * m_MagFRM;
		  T_PrzyjSprzFRM * m_PrzyjFRM;
		  T_PrzekSprzFRM * m_PrzekFRM;
		//ZDARZENIA
		  void __fastcall onNewMagClick(TObject *Sender);
		  void __fastcall onEditMagClick(TObject *Sender);
		  void __fastcall onAddProtPrzyjClick(TObject *Sender);
 };

}
//---------------------------------------------------------------------------
#endif
