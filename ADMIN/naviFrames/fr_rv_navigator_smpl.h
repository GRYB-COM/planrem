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
   bool             m_changing;         //!< Do chwilowego blokowania zdarze�

   //!
   void __fastcall onStateChange(TObject* sender);

   //!
   void __fastcall onDataChange(TObject* sender,TField* field);

protected:

   //! Czy zbi�r danych jest pod��czony ?
   bool __fastcall isLinked();

   //! Czy zbi�r danych jest otwarty ?
   bool __fastcall isOpen();

   /*! \brief Ustawia w�a�ciwo�� Enabled przycisku albo akcji zwi�zanej z przyciskiem
   */
   void __fastcall setEnabled(TSpeedButton* button,bool enabled);

   /*! \brief Ustawia w�a�ciwo�� Visible przycisku albo akcji zwi�zanej z przyciskiem
   */
   void __fastcall setVisible(TSpeedButton* button,bool visible);

   //! Zbi�r danych
   TDataSet* __fastcall getDataSet();

   //! Aktualizacja przycisk�w
   virtual void __fastcall onUpdateButtons(bool has_data,bool is_edited);

public:		// User declarations
   __fastcall TRVFrmNavigatorSmpl(TComponent* Owner);
   
   __fastcall TRVFrmNavigatorSmpl(TComponent* Owner,TDataSource* source);

   
   void __fastcall SetSource(TDataSource* source);

   /*! \brief Zablokowanie wszystkich przycisk�w
   *
   * Je�eli z przyciskami zwi�zane s� zdarzenia, to one s� blokowane.
   */
   void __fastcall DisableButtons();

   /*! \brief Udost�pnienie wszytkich przycisk�w niezale�nie od stanu �r�d�a danych
   *
   * Je�eli z przyciskami zwi�zane s� zdarzenia, to one s� udost�pniane.
   * Je�eli konieczne jest ustawienie dost�pno�ci przycisk�w zgodne ze stanem �r�d�a danych, to
   * nale�y wywo�a� funkcj� UpdateButtons().
   */
   void __fastcall EnableButtons();

   /*! \brief Ustawienie dost�pno�ci kontrolek zale�nie od stanu �r�d�a danych
   */
   void __fastcall UpdateButtons();

   void __fastcall First();

   void __fastcall Prior();

   void __fastcall Next();

   void __fastcall Last();
};

#endif
