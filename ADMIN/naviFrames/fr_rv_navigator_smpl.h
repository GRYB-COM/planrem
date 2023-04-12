//---------------------------------------------------------------------------


#ifndef fr_rv_navigator_smplH
#define fr_rv_navigator_smplH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------

/*!
*/
class TRVFrmNavigatorSmpl : public TFrame
{
__published:	// IDE-managed Components
   TSpeedButton *sbFirst;
   TSpeedButton *sbPrior;
   TSpeedButton *sbNext;
   TSpeedButton *sbLast;
   void __fastcall sbFirstClick(TObject *Sender);
   void __fastcall sbPriorClick(TObject *Sender);
   void __fastcall sbNextClick(TObject *Sender);
   void __fastcall sbLastClick(TObject *Sender);
private:	// User declarations
   TNotifyEvent     m_onStateChange;
   TDataChangeEvent m_onDataChange;
   TDataSource*     m_source;
   bool             m_changing;         //!< Do chwilowego blokowania zdarzeñ

   //!
   void __fastcall onStateChange(TObject* sender);

   //!
   void __fastcall onDataChange(TObject* sender,TField* field);

protected:

   //! Czy zbiór danych jest pod³¹czony ?
   bool __fastcall isLinked();

   //! Czy zbiór danych jest otwarty ?
   bool __fastcall isOpen();

   /*! \brief Ustawia w³aœciwoœæ Enabled przycisku albo akcji zwi¹zanej z przyciskiem
   */
   void __fastcall setEnabled(TSpeedButton* button,bool enabled);

   /*! \brief Ustawia w³aœciwoœæ Visible przycisku albo akcji zwi¹zanej z przyciskiem
   */
   void __fastcall setVisible(TSpeedButton* button,bool visible);

   //! Zbiór danych
   TDataSet* __fastcall getDataSet();

   //! Aktualizacja przycisków
   virtual void __fastcall onUpdateButtons(bool has_data,bool is_edited);

public:		// User declarations
   __fastcall TRVFrmNavigatorSmpl(TComponent* Owner);
   
   __fastcall TRVFrmNavigatorSmpl(TComponent* Owner,TDataSource* source);

   
   void __fastcall SetSource(TDataSource* source);

   /*! \brief Zablokowanie wszystkich przycisków
   *
   * Je¿eli z przyciskami zwi¹zane s¹ zdarzenia, to one s¹ blokowane.
   */
   void __fastcall DisableButtons();

   /*! \brief Udostêpnienie wszytkich przycisków niezale¿nie od stanu Ÿród³a danych
   *
   * Je¿eli z przyciskami zwi¹zane s¹ zdarzenia, to one s¹ udostêpniane.
   * Je¿eli konieczne jest ustawienie dostêpnoœci przycisków zgodne ze stanem Ÿród³a danych, to
   * nale¿y wywo³aæ funkcjê UpdateButtons().
   */
   void __fastcall EnableButtons();

   /*! \brief Ustawienie dostêpnoœci kontrolek zale¿nie od stanu Ÿród³a danych
   */
   void __fastcall UpdateButtons();

   void __fastcall First();

   void __fastcall Prior();

   void __fastcall Next();

   void __fastcall Last();
};

#endif
