//---------------------------------------------------------------------------
#ifndef fm_base_dlgH
#define fm_base_dlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------

namespace mng
{

   class Manager;


   /*! \brief Podstawowe okno dialogowe u¿ywane do tworzenia okien z informacj¹ o systemie i numerze
   *          wersji
   */
   class TfmBaseDlg : public TForm
   {
   __published:	// IDE-managed Components
      TPanel *paMain;
      TPanel *paBottom;
      TPanel *paImage;
      TImage *imgLogo;
      TLabel *laSysName;
      TLabel *laVersion;
      void __fastcall FormKeyPress(TObject *Sender, char &Key);
   private:	// User declarations

   protected:

      void __fastcall set_labels(const AnsiString& sys_name,const AnsiString& sys_ver);

      void __fastcall set_labels(const mng::Manager& man);

   public:		// User declarations
      __fastcall TfmBaseDlg(TComponent* Owner);
   };

} // namespace mng

#endif
