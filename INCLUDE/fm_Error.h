//---------------------------------------------------------------------------

#ifndef fm_ErrorH
#define fm_ErrorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "fm_base_dlg.h"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include "is_exceptions.h"
#include <jpeg.hpp>
//---------------------------------------------------------------------------

namespace mng
{

   /*! \brief Okno dialogowe do wyświetlania informacji o błędzie
   */
   class TfmError : public TfmBaseDlg
   {
   __published:	// IDE-managed Components
      TLabel *laDetails;
      TBitBtn *btDrukuj;
      TBitBtn *btSzczegoly;
      TBitBtn *bbWrite;
      TPanel *paInformation;
      TBitBtn *bbSend;
      TPanel *paTitleLabel;
      TLabel *laTitle;
      void __fastcall btSzczegolyClick(TObject *Sender);
      void __fastcall btDrukujClick(TObject *Sender);
      void __fastcall bbWriteClick(TObject *Sender);
      void __fastcall FormShow(TObject *Sender);
      void __fastcall bbSendClick(TObject *Sender);
   private:	// User declarations
      TFrame*                  m_frame;
      const ISException::Info* m_excInfo;


      //! Zastąpienie znaków podziału wierszy przez spacje
      AnsiString __fastcall replace_carriage(const AnsiString& text);

      //! Określenie treści komunikatów
      void __fastcall set_messages(const AnsiString& msg,const AnsiString& details);

      //! Określenie ramki do wyświetlania szczegółowych danych o błędzie
      void __fastcall load_frame(const ISException::Info& exc_info);

   public:		// User declarations
      __fastcall TfmError(TComponent* Owner);

      __fastcall ~TfmError();


      void __fastcall Display(const ISException::Info& exc_info,const AnsiString& msg,const AnsiString& details);

      void __fastcall Display(const ISException::Info& exc_info);

   };

} // namespace mng

#endif
