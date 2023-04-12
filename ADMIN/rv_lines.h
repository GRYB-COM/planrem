//---------------------------------------------------------------------------
#ifndef rv_linesH
#define rv_linesH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <vector>
//---------------------------------------------------------------------------


   /*! Tablica z ³añcuchami znaków
   */
   class Lines
   {
   public:

	  typedef std::vector<AnsiString>   __Container;
	  typedef __Container::const_iterator ConstIterator;
      typedef __Container::iterator       Iterator;

      
      Lines();

      /*! \brief Utworzenie obiektu z podzia³em przekazanego ³añcucha znaków na elementy o
      *          rozmiarze max_len
      *
      * Podzia³ ³añcucha znaków wykonywany jest za pomoc¹ funkcji split(). 
      */
      Lines(const AnsiString& str,int max_len,char filler=' ');


      ConstIterator begin() const;

      Iterator begin();

      ConstIterator end() const;

      Iterator end();

      //! Czy tablica jest pusta ?
      bool empty() const;

      //! Liczba ³añcuchów znaków w tablicy
      int size() const;

      /*! \brief Dodanie nowego elementu do tablicy
      *
      * Je¿eli argument at_front jest równy true, to element dodawany jest na pocz¹tek tabelicy.
      * W przeciwnym przypadku argument dodawany jest na jej koniec.
      */
      void append(const AnsiString& str,bool at_front=false);

      /*! \brief Dodanie na koniec tablicy elementów wchodz¹cych w sk³ad przekazanego
      *          argumentu
      */
      void attach(const Lines& lines);

      /*! \brief Dopisanie 
      */
      void merge(const Lines& lines,const AnsiString& sep);

      //! Usuniêcie wszystkich elementów z tablicy
      void clear();

      /*! \brief Rozbicie przekazanego ³ancucha znaków na pod³añcuchy o d³ugoœci 
      *          nie wiêkszej ni¿ max_len znaków i umieszczenie ich w tablicy
      *
      * Funkcja, je¿eli nie musi, nie dzieli wyrazów na czêœci. Wyraz zostanie
      * podzielony na czêœci, je¿eli jego d³ugoœæ jest wiêksza od max_len. Jako
      * separator rozdzielaj¹cy wyrazy przyjêto spacjê.
      * Wszystkie ³añcuchy znaków umieszczone w kontenerze maj¹ d³ugoœæ równ¹ max_len.
      */
      void split(const AnsiString& str,int max_len,char filler=' ');

      /*! \brief Zwraca wiersze w postaci pojedynczego ³añcucha znaków z zakoñczeniem ka¿dego
      *          wiersza przekazanym w wywo³aniu znaku
      *
      * \param carriage znak przejœcia do nowego wiersza
      * \param trim czy usuwaæ spacjê z pocz¹tku i koñca ka¿dego wiersza ?
      */
      AnsiString asText(const AnsiString& carriage="\n",bool trim=false) const;

      /*! \brief Dostêp do kopii elementu tablicy za poœrednictwem indeksu
      *
      * Nie jest kontrolowana poprawnoœæ indeksu
      */
      AnsiString operator[](int index) const;

      /*! \brief Dostêp do elementu tablicy za poœrednictwem indeksu
      *
      * Nie jest kontrolowana poprawnoœæ indeksu
      */
      AnsiString& operator[](int index);

   private:
      __Container m_lines;  //!< Tablica z ³añcuchami znaków
   };

#endif
