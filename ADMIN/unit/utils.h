//---------------------------------------------------------------------------
#ifndef utilsH
#define utilsH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <Controls.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------

/*! \brief Funkcje pomocnicze modu³u
*/
class Utils
{
public:

   /*! \brief Zwraca katalog, w którym znajduje siê aplikacja.
   *
   * Je¿eli argument sub_dir nie jest pusty, to jest on doklejany do
   * nazwy katalogu (z dodaniem ukoœnika)
   */
   static AnsiString applicationDir(const AnsiString& sub_dir="");

   /*! \brief Wykonuje przejœcie do nastêpnej kontrolki, gdy naciœniêto klawisz Enter
   *
   * \param parent wskaŸnik do rodzica odpowiedzialnego za wyœwietlenie kontrolki
   * \param Sender wskaŸnik do obiektu wysy³aj¹cego komunikat
   * \param key kod naciœniêtego klawisza
   * \return Wartoœæ true, gdy obs³u¿ono klawisz, a false w przeciwnym razie
   */
   static bool onKeyPressEnter(TWinControl* parent,TObject *sender,char &key);

   /*! \brief Zamienia pierwsz¹ literê na du¿¹
   *
   * Dzia³a tylko na kontrolkach edycyjnych, które s¹ pochodnymi klas TCustomEdit lub
   * TCustomComboBox.
   *
   * \param Sender wskaŸnik do obiektu wysy³aj¹cego komunikat
   * \param key kod naciœniêtego klawisza
   * \return Wartoœæ true, je¿eli znak zosta³ zamieniony
   */
   static bool onKeyPressUpperCase(TObject *sender,char &key);

   //! Uworzenie maski do wyœwietlania wartoœci liczbowych
   static AnsiString buildMask(int digits,int decimal,bool thousand_sep=true);

   //! Okno dialogowe do wyboru katalogu
   static AnsiString selectDirectory(const AnsiString& init_dir,const AnsiString& mask="*.*",bool file_must_exists=false);

   /*! \brief Wyœwietla okno dialogowe do wybrania pliku
   *
   * \return Wartoœæ true, gdy u¿ytkownik wybra³ plik (nazwa wybranego pliku
   *         zwracana jest poprzez pierwszy argument wywo³ania)
   */
   static bool selectFile(AnsiString& file_nm,const AnsiString& title,const AnsiString& filter="",const AnsiString& initial_dir="",bool file_must_exist=true);

   /*! \brief Wyzerowanie flag zapisanych we w³aœciwoœæ ProviderFlags dla pól o podanych nazwach
   *
   * Nazwy pól musz¹ byæ rozdzielone œrednikiem
   */
   static void clearFlags(TDataSet* dset,const AnsiString& fields);

   /*! \brief Okreœlenie pól, które tworz¹ klucz g³ówny
   *
   * Nazwy pól musz¹ byæ rozdzielone œrednikiem
   */
   static void markPrimaryKey(TDataSet* dset,const AnsiString& fields);

   /*! \brief Przypisanie maski polu numerycznemu
   *
   * Maska jest przypisywana tylko wtedy, gdy pole uda siê zrzutowaæ na
   * typ TNumericField
   */
   static void setNumericMask(TField* field,const AnsiString& mask);

   /*! \brief Przypisanie maski polu numerycznemu
   *
   * Maska jest przypisywana tylko wtedy, gdy pole uda siê zrzutowaæ na
   * typ TNumericField
   */
   static void setNumericMask(TDataSet* data_set,const AnsiString& fields,const AnsiString& mask);
   
};

#endif
