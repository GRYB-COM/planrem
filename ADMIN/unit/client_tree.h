//---------------------------------------------------------------------------
#ifndef client_treeH
#define client_treeH
//---------------------------------------------------------------------------
#include <DbClient.hpp>
#include <vector>
//---------------------------------------------------------------------------

namespace mng
{
   class TransactionDB;
   class QueryDB;
}


/*! Zadaniem klasy jest przechowywanie drzewiastej struktury zapyta�, kt�re
*   s�u�� do pod��czenia do providera i zwi�zania obiekt�w TClientDataSet z
*   w�a�ciwymi polami typu TDataSetField
*/
class ClientTree
{
public:

   class Item;
      

   /*! Opis elementu tworz�cego pojedyncze zapytanie wraz z zale�nymi od niego
   *    zapytaniami (opcjonalnie)
   */
   class ItemDescp
   {
   public:

      ItemDescp(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info="");


      /*! Dodanie opisu elementu tworz�cego podzapytanie
      */
      ItemDescp& add(const ItemDescp& descp);

      /*! Dodanie opisu elementu tworz�cego podzapytanie
      */
      ItemDescp& add(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info="");

      //! Usuni�cie wszystkich podzapyta�
      void clear();

      //! Czy zbi�r podzapyta� jest pusty ?
      bool empty() const;

      //! Liczba podzapyta�
      int size() const;

      //! Pobranie podzapytania o podanym indeksie
      ItemDescp operator[](int index) const;

   private:

      typedef std::vector<ItemDescp> __Container;

      int             m_ID;         //!< Identyfikator elementu
      AnsiString      m_query;      //!< Tre�� zapytania
      AnsiString      m_table;      //!< Nazwa tabeli
      TClientDataSet* m_client;     //!< Wska�nik do klienta pod��czanego do
                                    //!< pola zwi�zanego z definiowanym zapytaniem
      AnsiString      m_attachErr;  //!< Ko�cowa cz�� komunikatu do wy�wietlania
      __Container       m_descps;     //!< Tablica z elemetami zale�nymi od definiowanego zapytania

      friend Item;
   };


   /*! Zapytanie wchodz�ce w sk�ad drzewa
   */
   class Item
   {
   public:

      //! Utworzenie zapytania zgodnego z przekazanym opisem
      static Item* createItem(const ItemDescp& descp,mng::TransactionDB* trans,TDataSource* source,ClientTree::Item* parent);


      Item(const ItemDescp& descp,Item* parent);

      virtual ~Item();


      //! Identyfikator zapytania
      int getID() const;

      //! Tre�� zapytania
      AnsiString getQuery() const;

      //! Nazwa tabeli, kt�rej dotyczy zapytanie
      AnsiString getTable() const;

      //! Wska�nik do klienta zwi�zanego z zapytaniem
      TClientDataSet* getClient() const;

      //! Wska�nik do zbioru danych otwieraj�cego zapytanie
      mng::QueryDB* getDataSet() const;

      /*! Odszukanie zapytania po identyfikatorze
      */
      virtual const Item* find(int id) const;

      /*! Odszukanie zapytania po zbiorze danych otwieraj�cym zapytanie
      */
      virtual const Item* find(TDataSet* dset) const;

      //! Pod��czenie klienta do pola (tak�e klient�w zwi�zanych z podzapytaniami)
      virtual void attachClient() const;

      /*! Pod��czenie klienta do pola (tak�e klient�w zwi�zanych z podzapytaniami)
      *   z pomini�ciem zapyta� o podanch identyfikatorach
      */
      virtual void attachClientEx(int skip_ids[],int size) const;

      //! Od��czenie klienta od pola
      virtual void detachClient() const;

   protected:
      int             m_ID;         //!< Identyfikator elementu
      AnsiString      m_query;      //!< Tre�� zapytania
      AnsiString      m_table;      //!< Nazwa tabeli
      TClientDataSet* m_client;     //!< Wska�nik do klienta pod��czanego do
                                    //!< pola zwi�zanego z definiowanym zapytaniem
      AnsiString      m_attachErr;  //!< Ko�cowa cz�� komunikatu do wy�wietlania
      Item*           m_parent;     //!< Rodzic
      mng::QueryDB*   m_dataSet;    //!< Zbi�r danych otwieraj�cy zapytanie

      void createQuery(mng::TransactionDB* trans,TDataSource* master);

      void doAttaching() const;

   private:
      //! Bez implementacji
      Item(const Item&);

      //! Bez implementacji
      Item& operator=(const Item&);
   };


   ClientTree();

   ClientTree(mng::TransactionDB* trans,bool adopt);

   ~ClientTree();


   /*! \brief Odszukanie w drzewie zapyta� elementu o podanym identyfikatorze
   *
   * \return Wska�nik do znalezionego elementu lub NULL, je�eli element nie istnieje
   */
   const Item* find(int id) const;

   /*! \brief Odszukanie w drzewie zapyta� elementu
   *
   * \return Wska�nik do znalezionego elementu lub NULL, je�eli element nie istnieje
   */
   const Item* find(TDataSet* dset) const;

   //! G��wny zbi�r danych obs�uguj�cy zapytanie do pod��czenia do providera
   mng::QueryDB* getMainDataSet() const;

   //! Transakcja
   mng::TransactionDB* getTransaction() const;

   //! Czy transakcja jest otwarta ?
   bool inTransaction() const;

   //! Otwarcie transakcji
   void startTransaction();

   //! Zatwierdzenie transakcji
   void commit();

   //! Wycofanie transakcji
   void rollback();

   //! Utworzenie drzewa na podstawie opisu
   void buildTree(const ItemDescp& root);

   //! Pod��czenie wskazanego klienta
   bool attachClient(int id) const;

   //! Pod��czenie wszystkich klient�w
   void attachClients() const;

   /*! \brief Pod��czenie wszystkich klient�w z  wyj�tkiem wskazanych w wywo�aniu
   *
   * \param skip_ids identyfikatory pomijanych zapyta�
   * \param size rozmiar przekazanej tablicy
   */
   void attachClientsEx(int skip_ids[],int size) const;

   //! Od��czenie wskazanego klienta
   void detachClient(int id) const;

   //! Od��czenie wszystkich klient�w
   void detachClients() const;


private:

   /*! Zapytanie b�d�ce li�ciem drzewa (bez podzapyta�)
   */
   class ItemLeaf : public Item
   {
   public:

      ItemLeaf(const ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent);

   };


   /*! Zapytanie b�d�ce w�z�em drzewa (zawiera podzapytania)
   */
   class ItemGroup : public Item
   {
   public:

      ItemGroup(const ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent);

      virtual ~ItemGroup();


      //! Nadpisanie funkcji wyszukuj�cej (musi uwzgl�dnia� podzapytania)
      virtual const Item* find(int id) const;

      //! Nadpisanie funkcji wyszukuj�cej (musi uwzgl�dnia� podzapytania)
      virtual const Item* find(TDataSet* dset) const;

      //! Nadpisanie funkcji pod��czaj�cej klienty (musi uwzgl�dnia� podzapytania)
      virtual void attachClient() const;

      /*! Nadpisanie funkcji pod��czaj�cej klienty z pomini�ciem wskazanych
      *   podzapyta�
      */
      virtual void attachClientEx(int skip_ids[],int size) const;

      //! Nadpisanie funkcji od��czaj�cej klienty (musi uwzgl�dnia� podzapytania)
      virtual void detachClient() const;

   private:

      typedef std::vector<Item*>    Items;
      typedef Items::const_iterator ConstIterator;
      typedef Items::iterator       Iterator;

      TDataSource*  m_source; //!< �r�d�o danych do pod��czania podzapyta�
      Items         m_items;  //!< Tablica z podzapytaniami


      //! Bez implementacji
      ItemGroup(const ItemGroup&);

      //! Bez implementacji
      ItemGroup& operator=(const ItemGroup&);
   };


   mng::TransactionDB* m_trans; //!< Transakcja
   bool                m_adopt; //!< Czy obiekt jest odpowiedzialny za usuni�cie transakcji ?
   ItemGroup*          m_root;  //!< G��wny korze� drzewa zapyta�
};

#endif
