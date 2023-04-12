//---------------------------------------------------------------------------

#ifndef WaitFRMH
#define WaitFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "AdvSmoothPanel.hpp"
//---------------------------------------------------------------------------
namespace importmdb{
class T_WaitFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *AdvSmoothPanel1;
	TProgressBar *m_ProgressPB;
	TLabel *m_LabelLB;
	void __fastcall FormShow(TObject *Sender);
public:
	//INTERFEJS
	  void __fastcall start(const int _Max);
	  void __fastcall step (const AnsiString & _Capt);
	  void __fastcall stop(void);
	//KONSTRUKTOR DESTRUKTOR
	  __fastcall T_WaitFRM(TComponent* Owner);

	private:	// User declarations
};

};  //end namespace
//---------------------------------------------------------------------------
#endif
