//---------------------------------------------------------------------------


#pragma hdrstop

#include "client_tree.h"
#include <manager\is_exceptions.h>
#include <manager\transaction_db.h>
#include <manager\query_db.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)



/**********
*  Funkcje sk³adowe klasy: ClientTree
**********/

ClientTree::ClientTree()
   : m_trans(new mng::TransactionDB()), m_adopt(true), m_root(NULL)
{
}
//------------------------------------------------------------------------------

ClientTree::ClientTree(mng::TransactionDB* trans,bool adopt)
   : m_trans(trans), m_adopt(adopt), m_root(NULL)
{
}
//------------------------------------------------------------------------------

ClientTree::~ClientTree()
{
   delete m_root;

   if(m_adopt)
   {
      delete m_trans;
   }
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::find(int id) const
{
   return (m_root != NULL) ? m_root->find(id) : NULL;
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::find(TDataSet* dset) const
{
   return (m_root != NULL) ? m_root->find(dset) : NULL;;
}
//------------------------------------------------------------------------------

mng::QueryDB* ClientTree::getMainDataSet() const
{
   return (m_root != NULL) ? m_root->getDataSet() : NULL;
}
//------------------------------------------------------------------------------

mng::TransactionDB* ClientTree::getTransaction() const
{
   return m_trans;
}
//------------------------------------------------------------------------------

bool ClientTree::inTransaction() const
{
   return m_trans->inTransaction();
}
//------------------------------------------------------------------------------

void ClientTree::startTransaction()
{
   m_trans->startTransaction();
}
//------------------------------------------------------------------------------

void ClientTree::commit()
{
   m_trans->commit();
}
//------------------------------------------------------------------------------

void ClientTree::rollback()
{
   m_trans->rollback();
}
//------------------------------------------------------------------------------

void ClientTree::buildTree(const ClientTree::ItemDescp& root)
{
   delete m_root;

   m_root = new ItemGroup(root,m_trans,NULL,NULL);
}
//------------------------------------------------------------------------------

bool ClientTree::attachClient(int id) const
{
   bool attached=false;

   const Item* item=find(id);

   if(item != NULL)
   {
      item->attachClient();

      attached = true;
   }

   return attached;
}
//------------------------------------------------------------------------------

void ClientTree::detachClient(int id) const
{
   const Item* item=find(id);

   if(item != NULL)
   {
      item->detachClient();
   }
}
//------------------------------------------------------------------------------

void ClientTree::attachClients() const
{
   if(m_root != NULL)
   {
      m_root->attachClient();
   }
}
//------------------------------------------------------------------------------

void ClientTree::attachClientsEx(int skip_ids[],int size) const
{
   if(m_root != NULL)
   {
      m_root->attachClientEx(skip_ids,size);
   }
}
//------------------------------------------------------------------------------

void ClientTree::detachClients() const
{
   if(m_root != NULL)
   {
      m_root->detachClient();
   }
}
//------------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: ClientTree::ItemDescp
**********/


ClientTree::ItemDescp::ItemDescp(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info)
   : m_ID(id), m_query(query), m_table(table_name), m_client(client),
     m_attachErr(exc_info), m_descps()
{
}
//------------------------------------------------------------------------------

ClientTree::ItemDescp& ClientTree::ItemDescp::add(const ItemDescp& descp)
{
   m_descps.push_back(descp);

   return *this;
}
//------------------------------------------------------------------------------

ClientTree::ItemDescp& ClientTree::ItemDescp::add(int id,const AnsiString& query,const AnsiString& table_name,TClientDataSet* client,const AnsiString& exc_info)
{
   return add(ItemDescp(id,query,table_name,client,exc_info));
}
//------------------------------------------------------------------------------

void ClientTree::ItemDescp::clear()
{
   m_descps.clear();
}
//------------------------------------------------------------------------------

bool ClientTree::ItemDescp::empty() const
{
   return m_descps.empty();
}
//------------------------------------------------------------------------------

int ClientTree::ItemDescp::size() const
{
   return m_descps.size();
}
//------------------------------------------------------------------------------

ClientTree::ItemDescp ClientTree::ItemDescp::operator[](int index) const
{
   return m_descps[index];
}
//------------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: ClientTree::Item
**********/


ClientTree::Item* ClientTree::Item::createItem(const ClientTree::ItemDescp& descp,mng::TransactionDB* trans,TDataSource* source,ClientTree::Item* parent)
{
   if(descp.empty())
   {
      return new ItemLeaf(descp,trans,source,parent);
   }
   else
   {
      return new ItemGroup(descp,trans,source,parent);
   }
}
//------------------------------------------------------------------------------

ClientTree::Item::Item(const ClientTree::ItemDescp& descp,ClientTree::Item* parent)
   : m_ID(descp.m_ID), m_query(descp.m_query), m_table(descp.m_table),
     m_client(descp.m_client), m_attachErr(descp.m_attachErr), m_dataSet(NULL),
     m_parent(parent)
{
}
//------------------------------------------------------------------------------

ClientTree::Item::~Item()
{
   m_client->DataSetField = NULL;

   delete m_dataSet;
}
//------------------------------------------------------------------------------

void ClientTree::Item::createQuery(mng::TransactionDB* trans,TDataSource* master)
{
   delete m_dataSet;

   m_dataSet = trans->createQuery(m_query,master);
}
//------------------------------------------------------------------------------

void ClientTree::Item::doAttaching() const
{
   TDataSetField* ds_field=dynamic_cast<TDataSetField*>( m_parent->getClient()->FindField(m_dataSet->getName()) );

   if(ds_field == NULL)
   {
      AnsiString comm((m_attachErr.IsEmpty() ? AnsiString("Nie zosta³o znalezione pole zwi¹zane z tabel¹ ")+m_table : AnsiString("Nie zosta³o znalezione pole z ")+m_attachErr));

      ThrowExcOf(mng::ISException,comm);
   }

   m_client->DataSetField = ds_field;

   if(!m_client->Active)
   {
      m_client->Open();
   }
}
//------------------------------------------------------------------------------

int ClientTree::Item::getID() const
{
   return m_ID;
}
//------------------------------------------------------------------------------

AnsiString ClientTree::Item::getQuery() const
{
   return m_query;
}
//------------------------------------------------------------------------------

AnsiString ClientTree::Item::getTable() const
{
   return m_table;
}
//------------------------------------------------------------------------------

TClientDataSet* ClientTree::Item::getClient() const
{
   return m_client;
}
//------------------------------------------------------------------------------

mng::QueryDB* ClientTree::Item::getDataSet() const
{
   return (m_dataSet != NULL) ? m_dataSet : NULL;
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::Item::find(int id) const
{
   return (m_ID == id) ? this : NULL;
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::Item::find(TDataSet* dset) const
{
   return (dset != NULL && m_dataSet->getDataSet() == dset) ? this : NULL;
}
//------------------------------------------------------------------------------

void ClientTree::Item::attachClient() const
{
#ifdef _DEBUG

   if(m_dataSet == NULL)
   {
      ThrowExcOf(mng::ISException,"Nie zosta³ okreœlony zbiór danych, z którym ma byæ zwi¹zany TClientDataSet");
   }

#endif

   if(m_parent != NULL && m_client->DataSetField == NULL)
   {
      doAttaching();
   }
}
//------------------------------------------------------------------------------

void ClientTree::Item::attachClientEx(int skip_ids[],int size) const
{
#ifdef _DEBUG

   if(m_dataSet == NULL)
   {
      ThrowExcOf(mng::ISException,"Nie zosta³ okreœlony zbiór danych, z którym ma byæ zwi¹zany TClientDataSet");
   }

#endif

   if(m_parent != NULL && m_client->DataSetField == NULL)
   {
      bool skip=false;

      for(int ii=0;ii < size;++ii)
      {
         if(skip_ids[ii] == m_ID)
         {
            skip = true;

            break;
         }
      }

      if(!skip)
      {
         doAttaching();
      }
   }
}
//------------------------------------------------------------------------------

void ClientTree::Item::detachClient() const
{
   m_client->DataSetField = NULL;
}
//------------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: ClientTree::ItemLeaf
**********/


ClientTree::ItemLeaf::ItemLeaf(const ClientTree::ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent)
   : Item(descp,parent)
{
   createQuery(trans,master);
}
//------------------------------------------------------------------------------



/**********
*  Funkcje sk³adowe klasy: ClientTree::ItemGroup
**********/


ClientTree::ItemGroup::ItemGroup(const ClientTree::ItemDescp& descp,mng::TransactionDB* trans,TDataSource* master,ClientTree::Item* parent)
   : Item(descp,parent), m_items(), m_source(new TDataSource(NULL))
{
   createQuery(trans,master);

   m_source->DataSet = m_dataSet->getDataSet();

   for(int ii=0;ii < descp.size();++ii)
   {
      m_items.push_back( Item::createItem(descp[ii],trans,m_source,this) );
   }
}
//------------------------------------------------------------------------------

ClientTree::ItemGroup::~ItemGroup()
{
   for(Iterator it(m_items.begin());it != m_items.end();++it)
   {
      delete *it;
   }

   m_source->DataSet = NULL;

   delete m_source;
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::ItemGroup::find(int id) const
{
   const Item* item=Item::find(id);

   if(item == NULL)
   {
      for(ConstIterator it(m_items.begin());it != m_items.end() && item == NULL;++it)
      {
         item = (*it)->find(id);
      }
   }

   return item;
}
//------------------------------------------------------------------------------

const ClientTree::Item* ClientTree::ItemGroup::find(TDataSet* dset) const
{
   const Item* item=Item::find(dset);

   if(item == NULL)
   {
      for(ConstIterator it(m_items.begin());it != m_items.end() && item == NULL;++it)
      {
         item = (*it)->find(dset);
      }
   }

   return item;
}
//------------------------------------------------------------------------------

void ClientTree::ItemGroup::attachClient() const
{
   Item::attachClient();

   for(ConstIterator it(m_items.begin());it != m_items.end();++it)
   {
      (*it)->attachClient();
   }
}
//------------------------------------------------------------------------------

void ClientTree::ItemGroup::attachClientEx(int skip_ids[],int size) const
{
   Item::attachClientEx(skip_ids,size);

   for(ConstIterator it(m_items.begin());it != m_items.end();++it)
   {
      (*it)->attachClientEx(skip_ids,size);
   }
}
//------------------------------------------------------------------------------

void ClientTree::ItemGroup::detachClient() const
{
   for(ConstIterator it(m_items.begin());it != m_items.end();++it)
   {
      (*it)->detachClient();
   }

   Item::detachClient();
}
//------------------------------------------------------------------------------

