//---------------------------------------------------------------------------

#ifndef fr_rv_navigator_extH
#define fr_rv_navigator_extH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "fr_rv_navigator_smpl.h"
//---------------------------------------------------------------------------

/*!
*/
class TRVFrmNavigatorExt : public TRVFrmNavigatorSmpl
{
__published:	// IDE-managed Components
   TSpeedButton *sbAppend;
   TSpeedButton *sbEdit;
   TSpeedButton *sbRemove;
   TSpeedButton *sbInfo;
private:	// User declarations

protected:
   bool m_visible;  //!< Czy przyciski edycyjne s¹ widoczne ?

   //! Aktualizacja przycisków
   virtual void __fastcall onUpdateButtons(bool has_data,bool is_editing);

public:		// User declarations
   __fastcall TRVFrmNavigatorExt(TComponent* Owner);

   __fastcall TRVFrmNavigatorExt(TComponent* Owner,TDataSource* source);


   /*! \brief Zablokowanie edycji rekordów
   */
   virtual void __fastcall DisableEditing();

   /*! \brief Odblokowanie edycji rekordów
   */
   virtual void __fastcall EnableEditing();

   void __fastcall Append();

   void __fastcall Edit();

   void __fastcall Remove();

};

#endif
