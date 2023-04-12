//---------------------------------------------------------------------------

#ifndef PrzyjSprzFRMH
#define PrzyjSprzFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "AdvObj.hpp"
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "BaseGrid.hpp"
#include "DBAdvGrid.hpp"
#include <Graphics.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include "AdvDateTimePicker.hpp"
#include <ComCtrls.hpp>
#include <map>
//---------------------------------------------------------------------------
namespace readers {class SPReader;}
namespace mng     {class QueryDB;  }

class T_PrzyjSprzFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_SearchPA;
	TAdvSmoothPanel *m_TopPA;
	TDBAdvGrid *m_AG;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothButton *bbWrite;
	TAdvSmoothButton *m_PrintBB;
	TEdit *m_PrPrzyjED;
	TLabel *m_ProtLB;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TLabel *Label2;
	TEdit *edDost;
	TAdvSmoothButton *m_OpenBT;
	TDataSource *m_DS;
	TLabel *m_DataPrzyjLB;
	TAdvDateTimePicker *m_DataPrzyjDTP;
	TAdvSmoothButton *m_AddBB;
	void __fastcall m_OpenBTClick(TObject *Sender);
	void __fastcall m_PrintBBClick(TObject *Sender);
	void __fastcall bbWriteClick(TObject *Sender);
	void __fastcall m_PrPrzyjEDKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

	bool m_spIN;

	readers::SPReader* m_Reader;

	static const AnsiString M_PRINTER_SQL;
	static const AnsiString M_PRINTER_MAP;

	typedef std::map<String,String> Record;
	typedef std::map<int,Record> RecordSet;

public:		// User declarations

	static mng::QueryDB * m_PrintQDB;
	static RecordSet M_RS;  //static ¿eby makra widzia³y

	void __fastcall setSpIn(bool par) { m_spIN = par; }
	void T_PrzyjSprzFRM::fill(TDataSet * _DS);
	__fastcall T_PrzyjSprzFRM(TComponent* Owner);
  static int M_ILOSC;
};
extern AnsiString getMacroPrzyj(AnsiString Pars);
extern AnsiString getPrzyjIlosc(AnsiString Pars);
extern AnsiString getPrzyjIlSlw(AnsiString Pars);
extern AnsiString getPrzyjLPoz(AnsiString Pars);
extern AnsiString getPrzyjLPSlw(AnsiString Pars);
//---------------------------------------------------------------------------
#endif
