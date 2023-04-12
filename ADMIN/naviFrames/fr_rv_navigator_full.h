//---------------------------------------------------------------------------

#ifndef fr_rv_navigator_fullH
#define fr_rv_navigator_fullH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "fr_rv_navigator_ext.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------

/*!
*/
class TRVFrmNavigatorFull : public TRVFrmNavigatorExt
{
__published:	// IDE-managed Components
   TSpeedButton *sbCancel;
   TSpeedButton *sbPost;
private:	// User declarations

protected:

   //! Aktualizacja przycisków
   virtual void __fastcall onUpdateButtons(bool has_data,bool is_editing);

public:		// User declarations
   __fastcall TRVFrmNavigatorFull(TComponent* Owner);

   __fastcall TRVFrmNavigatorFull(TComponent* Owner,TDataSource* source);


   /*! \brief Zablokowanie edycji rekordów
   */
   virtual void __fastcall DisableEditing();

   /*! \brief Odblokowanie edycji rekordów
   */
   virtual void __fastcall EnableEditing();

   void __fastcall Post();

   void __fastcall Cancel();
};

#endif
