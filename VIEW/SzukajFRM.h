//---------------------------------------------------------------------------

#ifndef SzukajFRMH
#define SzukajFRMH
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
#include "ListaMAGFRA.h"
//---------------------------------------------------------------------------
class T_SzukajFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit1;
	TEdit *Edit2;
	TAdvSmoothDatePicker *AdvSmoothDatePicker1;
	TAdvSmoothDatePicker *AdvSmoothDatePicker2;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TAdvSmoothPanel *m_BottP;
	TAdvSmoothButton *AdvSmoothButton3;
	TAdvSmoothButton *AdvSmoothButton6;
	TAdvSmoothPanel *m_Center;
	T_ListaMAGFRA *_ListaMAGFRA1;
	void __fastcall AdvSmoothButton6Click(TObject *Sender);
	void __fastcall AdvSmoothButton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall T_SzukajFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_SzukajFRM *_SzukajFRM;
//---------------------------------------------------------------------------
#endif
