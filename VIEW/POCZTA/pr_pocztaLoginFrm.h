//---------------------------------------------------------------------------

#ifndef pr_pocztaLoginFrmH
#define pr_pocztaLoginFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdExplicitTLSClientServerBase.hpp"
#include "IdMessage.hpp"
#include "IdMessageClient.hpp"
#include "IdPOP3.hpp"
#include "IdSMTP.hpp"
#include "IdSMTPBase.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include "AdvGroupBox.hpp"
#include "AdvSmoothPanel.hpp"

//---------------------------------------------------------------------------

class T_pocztaLoginFrm : public TFrame
{
__published:	// IDE-managed Components
	TIdPOP3 *IdPOP31;
	TIdSMTP *IdSMTP1;
	TAdvSmoothPanel *AdvSmoothPanel1;
	TAdvGroupBox *m_ZRokuAGB;
	TAdvGroupBox *AdvGroupBox1;
	TLabel *Label1;
	TEdit *edSerwer;
	TEdit *edPort;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *edKonto;
	TEdit *edHaslo;
	TLabel *Label4;
private:	// User declarations
public:		// User declarations
	__fastcall T_pocztaLoginFrm(TComponent* Owner);

	void __fastcall setSerwer(const AnsiString& aTxt);
	void __fastcall setPort(const AnsiString& aTxt);
	void __fastcall setKonto(const AnsiString& aTxt);
	void __fastcall setHaslo(const AnsiString& aTxt);

	AnsiString __fastcall getSerwer(void);
	int __fastcall getPort(void);
	AnsiString __fastcall getKonto(void);
	AnsiString __fastcall getHaslo(void);

	TIdPOP3* __fastcall getIdPOP3(void);
	TIdSMTP* __fastcall getIdSMTP(void);

	void __fastcall setReadOnly(bool aState);
};

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
