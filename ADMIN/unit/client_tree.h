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


/*! Zadaniem klasy jest przechowywanie drzewiastej struktury zapytañ, które
*   s³u¿¹ do pod³¹czenia do providera i zwi¹zania obiektów TClientDataSet z
*   w³aœciwymi polami typu TDataSetField
*/
class ClientTree
{
public:

   class Item;
      

   /*! Opis elementu tworz¹cego pojedyncze zapytanie wraz z zale¿nymi od niego
   *    zapytaniami (opcjonalnie)
   */
   class ItemDescp
   {
   public:

      ItemDescp(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info="");


      /*! Dodanie opisu elementu tworz¹cego podzapytanie
      */
      ItemDescp& add(const ItemDescp& descp);

      /*! Dodanie opisu elementu tworz¹cego podzapytanie
      */
      ItemDescp& add(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info="");

      //! Usuniêcie wszystkich podzapytañ
      void clear();

      //! Czy zbiór podzapytañ jest pusty ?
      bool empty() const;

      //! Liczba podzapytañ
      int size() const;

      //! Pobranie podzapytania o podanym indeksie
      ItemDescp operator[](int index) const;

   private:

      typedef std::vector<ItemDescp> __Container;

      int             m_ID;         //!< Identyfikator elementu
      AnsiString      m_query;      //!< Treœæ zapytania
      AnsiString      m_table;      //!< Nazwa tabeli
      TClientDataSet* m_client;     //!< WskaŸnik do klienta pod³¹czanego do
                                    //!< pola zwi¹zanego z definiowanym zapytaniem
      AnsiString      m_attachErr;  //!< Koñcowa czêœæ komunikatu do wyœwietlania
      __Container       m_descps;     //!< Tablica z elemetami zale¿nymi od definiowanego zapytania

      friend Item;
   };


   /*! Zapytanie wchodz¹ce w sk³ad drzewa
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

      //! Treœæ zapytania
      AnsiString getQuery() const;

      //! Nazwa tabeli, której dotyczy zapytanie
      AnsiString getTable() const;

      //! WskaŸnik do klienta zwi¹zanego z zapytaniem
      TClientDataSet* getClient() const;

      //! WskaŸnik do zbioru danych otwieraj¹cego zapytanie
      mng::QueryDB* getDataSet() const;

      /*! Odszukanie zapytania po identyfikatorze
      */
      virtual const Item* find(int id) const;

      /*! Odszukanie zapytania po zbiorze danych otwieraj¹cym zapytanie
      */
      virtual const Item* find(TDataSet* dset) const;

      //! Pod³¹czenie klienta do pola (tak¿e klientów zwi¹zanych z podzapytaniami)
      virtual void attachClient() const;

      /*! Pod³¹czenie klienta do pola (tak¿e klientów zwi¹zanych z podzapytaniami)
      *   z pominiêciem zapytañ o podanch identyfikatorach
      */
      virtual void attachClientEx(int skip_ids[],int size) const;

      //! Od³¹czenie klienta od pola
      virtual void detachClient() const;

   protected:
      int             m_ID;         //!< Identyfikator elementu
      AnsiString      m_query;      //!< Treœæ zapytania
      AnsiString      m_table;      //!< Nazwa tabeli
      TClientDataSet* m_client;     //!< WskaŸnik do klienta pod³¹czanego do
                                    //!< pola zwi¹zanego z definiowanym zapytaniem
      AnsiString      m_attachErr;  //!< Koñcowa czêœæ komunikatu do wyœwietlania
      Item*           m_parent;     //!< Rodzic
      mng::QueryDB*   m_dataSet;    //!< Zbiór danych otwieraj¹cy zapytanie

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


   /*! \brief Odszukanie w drzewie zapytañ elementu o podanym identyfikatorze
   *
   * \return WskaŸnik do znalezionego elementu lub NULL, je¿eli element nie istnieje
   */
   const Item* find(int id) const;

   /*! \brief Odszukanie w drzewie zapytañ elementu
   *
   * \return WskaŸnik do znalezionego elementu lub NULL, je¿eli element nie istnieje
   */
   const Item* find(TDataSet* dset) const;

   //! G³ówny zbiór danych obs³uguj¹cy zapytanie do pod³¹czenia do providera
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

   //! Pod³¹czenie wskazanego klienta
   bool attachClient(int id) const;

   //! Pod³¹czenie wszystkich klientów
   void attachClients() const;

   /*! \brief Pod³¹czenie wszystkich klientów z  wyj¹tkiem wskazanych w wywo³aniu
   *
   * \param skip_ids identyfikatory pomijanych zapytañ
   * \param size rozmiar przekazanej tablicy
   */
   void attachClientsEx(int skip_ids[],int size) const;

   //! Od³¹czenie wskazanego klienta
   void detachClient(int id) const;

   //! Od³¹czenie wszystkich klientów
   void detachClients() const;


private:

   /*! Zapytanie bêd¹ce liœciem drzewa (bez podzapytañ)
   */
   class ItemLeaf : public Item
   {
   public:

      ItemLeaf(const ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent);

   };


   /*! Zapytanie bêd¹ce wêz³em drzewa (zawiera podzapytania)
   */
   class ItemGroup : public Item
   {
   public:

      ItemGroup(const ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent);

      virtual ~ItemGroup();


      //! Nadpisanie funkcji wyszukuj¹cej (musi uwzglêdniaæ podzapytania)
      virtual const Item* find(int id) const;

      //! Nadpisanie funkcji wyszukuj¹cej (musi uwzglêdniaæ podzapytania)
      virtual const Item* find(TDataSet* dset) const;

      //! Nadpisanie funkcji pod³¹czaj¹cej klienty (musi uwzglêdniaæ podzapytania)
      virtual void attachClient() const;

      /*! Nadpisanie funkcji pod³¹czaj¹cej klienty z pominiêciem wskazanych
      *   podzapytañ
      */
      virtual void attachClientEx(int skip_ids[],int size) const;

      //! Nadpisanie funkcji od³¹czaj¹cej klienty (musi uwzglêdniaæ podzapytania)
      virtual void detachClient() const;

   private:

      typedef std::vector<Item*>    Items;
      typedef Items::const_iterator ConstIterator;
      typedef Items::iterator       Iterator;

      TDataSource*  m_source; //!< ród³o danych do pod³¹czania podzapytañ
      Items         m_items;  //!< Tablica z podzapytaniami


      //! Bez implementacji
      ItemGroup(const ItemGroup&);

      //! Bez implementacji
      ItemGroup& operator=(const ItemGroup&);
   };


   mng::TransactionDB* m_trans; //!< Transakcja
   bool                m_adopt; //!< Czy obiekt jest odpowiedzialny za usuniêcie transakcji ?
   ItemGroup*          m_root;  //!< G³ówny korzeñ drzewa zapytañ
};

#endif
