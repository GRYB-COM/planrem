//---------------------------------------------------------------------------

#ifndef ListaMagH
#define ListaMagH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ListaMAGFRA.h"
//---------------------------------------------------------------------------
class T_ListaMagFRM : public TForm
{
__published:	// IDE-managed Components
	T_ListaMAGFRA *m_ListaMAgFRA;
private:	// User declarations
public:		// User declarations
	__fastcall T_ListaMagFRM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE T_ListaMagFRM *_ListaMagFRM;
//---------------------------------------------------------------------------
#endif
