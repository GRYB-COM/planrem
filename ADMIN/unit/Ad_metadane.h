//---------------------------------------------------------------------------
#ifndef Ad_metadaneH
#define Ad_metadaneH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <Classes.hpp>
#include <idents.h>
#include <vector>
#include "unit\systemSDbevents.h"
//---------------------------------------------------------------------------

namespace mng
{
   class TransactionDB;
   class StreamDB;
}

class SystemInstaller
{
private:
   typedef std::vector<SystemInstaller*> __Container;
   typedef __Container::const_iterator ConstIterator;
   typedef __Container::iterator Iterator;
   __Container m_systems;
   mng::SysID m_sys_id;
   AnsiString m_path;
   AnsiString m_query_str;
   //lista systemow potrzebnych dla tego systemu (z levelu o jeden nizej) ->
   //ma to dzialac na zasadzie drzewa
   //wywolanie metody installSystem dla listy systemow
   bool isInstalled(std::vector<int>&);
   void appendIdSys(std::vector<int>&, int);

public:
   SystemInstaller(int sys_id, const AnsiString& path, const AnsiString& query_str);
   ~SystemInstaller();
   void registerSystem(SystemInstaller* sys);
   void installSystem(std::vector<int>&, int, mng::StreamDB*);
   int getSysId();
   AnsiString getPath();
   AnsiString getName();
};

class Metadane
{
private:
   typedef std::vector<SystemInstaller*> __Container;
   typedef __Container::const_iterator ConstIterator;
   typedef __Container::iterator Iterator;
   __Container m_systems;
   SystemInstaller* tempsys1;
   SystemInstaller* tempsys2;
   SystemInstaller* tempsys3;
   SystemInstaller* tempsys4;
   SystemInstaller* tempsys5;
   SystemInstaller* tempsys6;
   SystemInstaller* tempsys7;
   SystemInstaller* tempsys8;
   SystemInstaller* tempsys9;
   SystemInstaller* tempsys10;
   SystemInstaller* tempsys11;

   SystemInstaller* tempsys12;
   SystemInstaller* tempsys13;
   SystemInstaller* tempsys14;
   SystemInstaller* tempsys15;
   SystemInstaller* tempsys16;
   SystemInstaller* tempsys17;
   SystemInstaller* tempsys18;
   SystemInstaller* tempsys19;
   SystemInstaller* tempsys20;
   SystemInstaller* tempsys21;
   SystemInstaller* tempsys22;
   SystemInstaller* tempsys23;

   void registerSystem(SystemInstaller* sys);
public:
   Metadane();
   ~Metadane();
//   TStrings* systemList();
   void installSystem(int, std::vector<int>&, mng::StreamDB*, SystemsSDB*);
};
//---------------------------------------------------------------------------
#endif
