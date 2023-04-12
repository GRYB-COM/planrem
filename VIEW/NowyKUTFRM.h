//---------------------------------------------------------------------------

#ifndef NowyKUTFRMH
#define NowyKUTFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothDatePicker.hpp"
#include "AdvSmoothEdit.hpp"
#include "AdvSmoothEditButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DBCtrls.hpp>
#include "DBAdvSmoothDatePicker.hpp"
#include <Mask.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
namespace mng {class StreamDB;}
class T_NowyKUTFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *AdvSmoothButton4;
	TAdvSmoothButton *AdvSmoothButton1;
	TDataSource *m_DS;
	TDataSource *m_WarsztatDS;
	TAdvSmoothPanel *_NowyKUTFRM;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label1;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TDBAdvSmoothDatePicker *DBAdvSmoothDatePicker2;
	TDBEdit *DBEdit8;
	TDBLookupComboBox *DBLookupComboBox5;
	TDBEdit *DBEdit9;
	TDBEdit *DBEdit10;
	TDBEdit *DBEdit11;
	TDBEdit *DBEdit12;
	TDBEdit *DBEdit13;
	void __fastcall AdvSmoothButton4Click(TObject *Sender);
	void __fastcall AdvSmoothButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
  mng::StreamDB* m_SDB;
  mng::StreamDB* m_WarsztatSDB;

  int			m_IdMag;
public:		// User declarations
void setIdMag(int _Id);
	__fastcall T_NowyKUTFRM(TComponent* Owner);
		__fastcall ~T_NowyKUTFRM();
};
//---------------------------------------------------------------------------
extern PACKAGE T_NowyKUTFRM *_NowyKUTFRM;
//---------------------------------------------------------------------------
#endif
