//---------------------------------------------------------------------------

#ifndef SlSprzetRodzajeEditFRMH
#define SlSprzetRodzajeEditFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include "SL_EDIT_FRM.h"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
namespace mng
{
  class StreamDB;
}

class T_SlSprzetRodzajeEditFRM : public T_SL_EDIT_FRM
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TDBEdit *DBEdit2;
    TLabel *Label3;
    TDBLookupComboBox *m_grCB;
    TDataSource *m_grDS;
private:	// User declarations

    mng::StreamDB *m_grSDB;

public:		// User declarations

    __fastcall T_SlSprzetRodzajeEditFRM(TComponent* Owner);
    __fastcall ~T_SlSprzetRodzajeEditFRM();
};
//---------------------------------------------------------------------------
#endif
