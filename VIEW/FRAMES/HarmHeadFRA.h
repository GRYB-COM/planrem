//---------------------------------------------------------------------------

#ifndef HarmHeadFRAH
#define HarmHeadFRAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class T_HarmHeadFRA : public TFrame
{
__published:	// IDE-managed Components
	TDBLookupComboBox *m_Combo;
	TClientDataSet    *m_Client;
	TDBEdit           *m_Edit;
	TDataSource       *m_DataSource;
public:
		//INTERFEJS
		  void   __fastcall open(void);
		  int    __fastcall getID(void)const;
		  void   __fastcall setID(const int _ID);
		  String __fastcall getOpis(void) const;
		//KONSTRUKTOR
		  __fastcall T_HarmHeadFRA(TComponent* Owner);
private:

};
//---------------------------------------------------------------------------
extern PACKAGE T_HarmHeadFRA *_HarmHeadFRA;
//---------------------------------------------------------------------------
#endif
