//---------------------------------------------------------------------------

#ifndef wi_SlZalEditFRMH
#define wi_SlZalEditFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothPanel.hpp"
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
namespace widict { class iSlModel; }
class T_SlZalEditFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TBitBtn *m_CloseBB;
	TBitBtn *BitBtn1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvSmoothPanel *AdvSmoothPanel2;
	TAdvSmoothPanel *AdvSmoothPanel3;
	TAdvSmoothPanel *AdvSmoothPanel4;
	TDBGrid *m_DBG;
	TBitBtn *m_DodajBB;
	TBitBtn *m_EdytujBB;
	TBitBtn *m_ZatwierdzBB;
	TDataSource *m_DS;
	TDBEdit *m_RokDBE;
	TLabel *m_RokTL;
	TDBEdit *m_WartoscDBE;
	TLabel *m_WartoscTL;
	TBitBtn *m_UsunBB;
	void __fastcall m_CloseBBClick(TObject *Sender);
	void __fastcall m_DodajBBClick(TObject *Sender);
	void __fastcall m_EdytujBBClick(TObject *Sender);
	void __fastcall m_ZatwierdzBBClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall m_DSDataChange(TObject *Sender, TField *Field);
	void __fastcall m_DBGTitleClick(TColumn *Column);
	void __fastcall m_RokDBEKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall m_UsunBBClick(TObject *Sender);
private:	// User declarations
	void		setEditEnable(bool _Enable);

	bool								m_InsMode;
	widict::iSlModel*   m_Model;
public:		// User declarations
	void 					  	 setModel(widict::iSlModel * _Model);
  bool							 m_Kod;
	__fastcall T_SlZalEditFRM(TComponent* Owner);
	__fastcall ~T_SlZalEditFRM();
};
//---------------------------------------------------------------------------
extern PACKAGE T_SlZalEditFRM *_SlZalEditFRM;
//---------------------------------------------------------------------------
#endif
