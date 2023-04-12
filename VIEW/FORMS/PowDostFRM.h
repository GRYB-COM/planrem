//---------------------------------------------------------------------------

#ifndef PowDostFRMH
#define PowDostFRMH
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
#include "AdvCombo.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}

class T_PowDostFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_SearchPA;
	TLabel *m_ProtLB;
    TAdvSmoothButton *m_Szukaj;
    TAdvComboBox *m_cbOkres;
    TDataSource *m_DS;
    TAdvSmoothPanel *AdvSmoothPanel1;
    TAdvSmoothButton *bbWrite;
	TAdvSmoothButton *m_PrintSingleBB;
    TDBAdvGrid *m_AG;
    TAdvSmoothPanel *AdvSmoothPanel2;
    TLabel *Label2;
    TEdit *m_edFilter;
	TAdvSmoothButton *m_PrintAlBB;
    void __fastcall m_SzukajClick(TObject *Sender);
    void __fastcall m_edFilterChange(TObject *Sender);
    void __fastcall m_PrintSingleBBClick(TObject *Sender);
    void __fastcall bbWriteClick(TObject *Sender);
	void __fastcall m_PrintAlBBClick(TObject *Sender);
private:	// User declarations

    mng::StreamDB *m_SDB;
    int m_rok;
    int m_miesOd;
    int m_miesDo;

public:		// User declarations

    AnsiString __fastcall getKodJW();
    AnsiString __fastcall getMiejscJW();
    AnsiString __fastcall getFaxJW();

	int  __fastcall getIdJW();
	int  __fastcall getMiesOd();
	int  __fastcall getMiesDo();
	void __fastcall setMiesOd(const int _Mies) { m_miesOd = _Mies; }
	void __fastcall setMiesDo(const int _Mies) { m_miesDo = _Mies; }
	int  __fastcall getRok();

	__fastcall T_PowDostFRM(TComponent* Owner);

	__fastcall ~T_PowDostFRM();

};
//---------------------------------------------------------------------------
#endif
