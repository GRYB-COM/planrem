//---------------------------------------------------------------------------
#ifndef rv_linesH
#define rv_linesH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <vector>
//---------------------------------------------------------------------------


   /*! Tablica z �a�cuchami znak�w
   */
   class Lines
   {
   public:

	  typedef std::vector<AnsiString>   __Container;
	  typedef __Container::const_iterator ConstIterator;
      typedef __Container::iterator       Iterator;

      
      Lines();

      /*! \brief Utworzenie obiektu z podzia�em przekazanego �a�cucha znak�w na elementy o
      *          rozmiarze max_len
      *
      * Podzia� �a�cucha znak�w wykonywany jest za pomoc� funkcji split(). 
      */
      Lines(const AnsiString& str,int max_len,char filler=' ');


      ConstIterator begin() const;

      Iterator begin();

      ConstIterator end() const;

      Iterator end();

      //! Czy tablica jest pusta ?
      bool empty() const;

      //! Liczba �a�cuch�w znak�w w tablicy
      int size() const;

      /*! \brief Dodanie nowego elementu do tablicy
      *
      * Je�eli argument at_front jest r�wny true, to element dodawany jest na pocz�tek tabelicy.
      * W przeciwnym przypadku argument dodawany jest na jej koniec.
      */
      void append(const AnsiString& str,bool at_front=false);

      /*! \brief Dodanie na koniec tablicy element�w wchodz�cych w sk�ad przekazanego
      *          argumentu
      */
      void attach(const Lines& lines);

      /*! \brief Dopisanie 
      */
      void merge(const Lines& lines,const AnsiString& sep);

      //! Usuni�cie wszystkich element�w z tablicy
      void clear();

      /*! \brief Rozbicie przekazanego �ancucha znak�w na pod�a�cuchy o d�ugo�ci 
      *          nie wi�kszej ni� max_len znak�w i umieszczenie ich w tablicy
      *
      * Funkcja, je�eli nie musi, nie dzieli wyraz�w na cz�ci. Wyraz zostanie
      * podzielony na cz�ci, je�eli jego d�ugo�� jest wi�ksza od max_len. Jako
      * separator rozdzielaj�cy wyrazy przyj�to spacj�.
      * Wszystkie �a�cuchy znak�w umieszczone w kontenerze maj� d�ugo�� r�wn� max_len.
      */
      void split(const AnsiString& str,int max_len,char filler=' ');

      /*! \brief Zwraca wiersze w postaci pojedynczego �a�cucha znak�w z zako�czeniem ka�dego
      *          wiersza przekazanym w wywo�aniu znaku
      *
      * \param carriage znak przej�cia do nowego wiersza
      * \param trim czy usuwa� spacj� z pocz�tku i ko�ca ka�dego wiersza ?
      */
      AnsiString asText(const AnsiString& carriage="\n",bool trim=false) const;

      /*! \brief Dost�p do kopii elementu tablicy za po�rednictwem indeksu
      *
      * Nie jest kontrolowana poprawno�� indeksu
      */
      AnsiString operator[](int index) const;

      /*! \brief Dost�p do elementu tablicy za po�rednictwem indeksu
      *
      * Nie jest kontrolowana poprawno�� indeksu
      */
      AnsiString& operator[](int index);

   private:
      __Container m_lines;  //!< Tablica z �a�cuchami znak�w
   };

#endif
