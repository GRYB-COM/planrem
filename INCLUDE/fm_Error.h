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

   /*! \brief Okno dialogowe do wyœwietlania informacji o b³êdzie
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


      //! Zast¹pienie znaków podzia³u wierszy przez spacje
      AnsiString __fastcall replace_carriage(const AnsiString& text);

      //! Okreœlenie treœci komunikatów
      void __fastcall set_messages(const AnsiString& msg,const AnsiString& details);

      //! Okreœlenie ramki do wyœwietlania szczegó³owych danych o b³êdzie
      void __fastcall load_frame(const ISException::Info& exc_info);

   public:		// User declarations
      __fastcall TfmError(TComponent* Owner);

      __fastcall ~TfmError();


      void __fastcall Display(const ISException::Info& exc_info,const AnsiString& msg,const AnsiString& details);

      void __fastcall Display(const ISException::Info& exc_info);

   };

} // namespace mng

#endif
