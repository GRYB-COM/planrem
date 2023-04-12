//---------------------------------------------------------------------------
#ifndef utilsH
#define utilsH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <Controls.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------

/*! \brief Funkcje pomocnicze modu�u
*/
class Utils
{
public:

   /*! \brief Zwraca katalog, w kt�rym znajduje si� aplikacja.
   *
   * Je�eli argument sub_dir nie jest pusty, to jest on doklejany do
   * nazwy katalogu (z dodaniem uko�nika)
   */
   static AnsiString applicationDir(const AnsiString& sub_dir="");

   /*! \brief Wykonuje przej�cie do nast�pnej kontrolki, gdy naci�ni�to klawisz Enter
   *
   * \param parent wska�nik do rodzica odpowiedzialnego za wy�wietlenie kontrolki
   * \param Sender wska�nik do obiektu wysy�aj�cego komunikat
   * \param key kod naci�ni�tego klawisza
   * \return Warto�� true, gdy obs�u�ono klawisz, a false w przeciwnym razie
   */
   static bool onKeyPressEnter(TWinControl* parent,TObject *sender,char &key);

   /*! \brief Zamienia pierwsz� liter� na du��
   *
   * Dzia�a tylko na kontrolkach edycyjnych, kt�re s� pochodnymi klas TCustomEdit lub
   * TCustomComboBox.
   *
   * \param Sender wska�nik do obiektu wysy�aj�cego komunikat
   * \param key kod naci�ni�tego klawisza
   * \return Warto�� true, je�eli znak zosta� zamieniony
   */
   static bool onKeyPressUpperCase(TObject *sender,char &key);

   //! Uworzenie maski do wy�wietlania warto�ci liczbowych
   static AnsiString buildMask(int digits,int decimal,bool thousand_sep=true);

   //! Okno dialogowe do wyboru katalogu
   static AnsiString selectDirectory(const AnsiString& init_dir,const AnsiString& mask="*.*",bool file_must_exists=false);

   /*! \brief Wy�wietla okno dialogowe do wybrania pliku
   *
   * \return Warto�� true, gdy u�ytkownik wybra� plik (nazwa wybranego pliku
   *         zwracana jest poprzez pierwszy argument wywo�ania)
   */
   static bool selectFile(AnsiString& file_nm,const AnsiString& title,const AnsiString& filter="",const AnsiString& initial_dir="",bool file_must_exist=true);

   /*! \brief Wyzerowanie flag zapisanych we w�a�ciwo�� ProviderFlags dla p�l o podanych nazwach
   *
   * Nazwy p�l musz� by� rozdzielone �rednikiem
   */
   static void clearFlags(TDataSet* dset,const AnsiString& fields);

   /*! \brief Okre�lenie p�l, kt�re tworz� klucz g��wny
   *
   * Nazwy p�l musz� by� rozdzielone �rednikiem
   */
   static void markPrimaryKey(TDataSet* dset,const AnsiString& fields);

   /*! \brief Przypisanie maski polu numerycznemu
   *
   * Maska jest przypisywana tylko wtedy, gdy pole uda si� zrzutowa� na
   * typ TNumericField
   */
   static void setNumericMask(TField* field,const AnsiString& mask);

   /*! \brief Przypisanie maski polu numerycznemu
   *
   * Maska jest przypisywana tylko wtedy, gdy pole uda si� zrzutowa� na
   * typ TNumericField
   */
   static void setNumericMask(TDataSet* data_set,const AnsiString& fields,const AnsiString& mask);
   
};

#endif
