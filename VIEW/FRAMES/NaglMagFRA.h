// ---------------------------------------------------------------------------

#ifndef NaglMagFRAH
#define NaglMagFRAH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>

// ---------------------------------------------------------------------------
namespace readers { class MagNaglReader; }
namespace msg     { class MagID; }
// ---------------------------------------------------------------------------
class T_NaglMagFRA : public TFrame
{
__published: // IDE-managed Components
  TAdvSmoothPanel* m_TopP;
  TAdvSmoothPanel* AdvSmoothPanel1;
  TLabel* Label10;
  TLabel* Label11;
  TLabel* Label12;
  TLabel* Label13;
  TLabel* Label14;
  TLabel* Label15;
  TAdvSmoothPanel* AdvSmoothPanel2;
  TLabel* Label17;
  TLabel* Label20;
  TLabel* Label16;
  TAdvSmoothPanel* AdvSmoothPanel4;
  TAdvSmoothButton* AdvSmoothButton1;
  TAdvSmoothButton* AdvSmoothButton2;
  TDataSource* m_DS;
	TDBEdit *m_IloscDBE;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit3;
	TAdvSmoothPanel *AdvSmoothPanel5;
	TDBMemo *m_UwagiDBM;
	TLabel *Label21;
	TDBEdit *DBEdit6;
	TDBEdit *DBEdit7;
	TDBEdit *DBEdit8;
	TDBEdit *DBEdit9;
	TDBEdit *DBEdit10;
	TLabel *Label2;
	TDBEdit *DBEdit5;
	TLabel *Label1;
	TDBEdit *DBEdit4;
	TLabel *Label3;
	TDBEdit *DBEdit11;

public:
		//INTERFEJS
		  void __fastcall open(const msg::MagID&  _MagID);
		  void __fastcall close(void);
		  int  __fastcall getIdHarm(void);
		//KONSTRUKTOR DESTRUKTOR
		  __fastcall T_NaglMagFRA(TComponent* Owner);
		  __fastcall ~T_NaglMagFRA();
private:
		//NARZÊDZIA
		  readers::MagNaglReader*  m_Reader;
};

// ---------------------------------------------------------------------------
extern PACKAGE T_NaglMagFRA* _NaglMagFRA;
// ---------------------------------------------------------------------------
#endif
