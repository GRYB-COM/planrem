//---------------------------------------------------------------------------
#pragma hdrstop
#include "KUTEditor.h"
#include "MagID.h"
#include "MANAGER\query_db.h"
#include "MANAGER\stream_db.h"
#include "ZlecID.h"
#include "JBUTILS\jb_ini_my.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace editors;
//---------------------------------------------------------------------------
void KUTEditor::create(const msg::MagID & _MagID)
{

 mng::QueryDB _MA("SELECT M.NR_MAG, M.DATA_PRZYJ,M.ILOSC, M.ID_SPRZETU, M.ID_HARM, M.ID_KOMORKI, M.ID_JEDNOSTKI, H.ROK, H.ZADANIE, GEN_ID(PR_ZLECENIA_GEN,1) AS ID_ZLECENIA FROM PR_MAGAZYN M \
 LEFT OUTER JOIN PR_HARMONOGRAM H ON H.ID_HARMONOGRAMU = M.ID_HARM AND H.ROK = M.ROK\
 WHERE M.ID_MAG = :ID_MAG AND M.ROK =:ROK AND M.ID_KOMORKI = :ID_KOMORKI AND M.DEPOZYT = :DEPOZYT ");
 _MA.paramByName("ID_MAG")->AsInteger     = _MagID.IdMag;
 _MA.paramByName("ROK")->AsInteger        = _MagID.Rok;
 _MA.paramByName("ID_KOMORKI")->AsInteger = _MagID.IdKomorki;
 _MA.paramByName("DEPOZYT")->AsString     = _MagID.Depozyt;
 _MA.open();

 msg::ZlecID _ZlecID;
 _ZlecID.fillFromDS(_MA.getDataSet());
 _ZlecID.NrKol        = 0;
 _ZlecID.Rok          = jbutils::TMyIni().ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", CurrentYear()) ;
 _ZlecID.NrMag        = _MagID.NrMag;
 _ZlecID.IdKomorkiGlw = _ZlecID.IdKomorki;
String _Dep(_MagID.Depozyt == "R" ? String("") : _MagID.Depozyt );
 mng::StreamDB _KU;
 _KU.setQuery("SELECT * FROM PR_ZLECENIA WHERE ID_ZLECENIA =-1 AND ROK = -1  AND ID_KOMORKI = -1");
 _KU.open();
  _KU.append();
   _KU.fieldByName("ID_ZLECENIA")->AsInteger    = _ZlecID.IdZlecenia;
   _KU.fieldByName("SYGN_ZLECENIA")->AsString   = _ZlecID.getSygn(_Dep);
   _KU.fieldByName("ID_KOMORKI")->AsInteger     = _ZlecID.IdKomorki;
   _KU.fieldByName("ID_KOMORKI_GLW")->AsInteger = _ZlecID.IdKomorki;
   _KU.fieldByName("NR_MAG")->AsInteger         = _MagID.NrMag;
   _KU.fieldByName("ID_MAG")->AsInteger         = _MagID.IdMag;
   _KU.fieldByName("ROK")->AsInteger            = _ZlecID.Rok;
   _KU.fieldByName("ROK_MAG")->AsInteger        = _MagID.Rok;
   _KU.fieldByName("NR_KOL")->AsInteger         = 0;
   _KU.fieldByName("SYGN_MAG")->AsString          = _MagID.getSygnMag();
   _KU.fieldByName("DEPOZYT")->AsString         = _MagID.Depozyt;
   _KU.fieldByName("STATUS")->AsString          = "K";
   _KU.fieldByName("DATA_WYST")->AsDateTime     = _MA.fieldByName("DATA_PRZYJ")->AsDateTime;
   _KU.fieldByName("ID_SPRZETU")->AsInteger     = _MA.fieldByName("ID_SPRZETU")->AsInteger;
   _KU.fieldByName("ID_HARM")->AsInteger        = _MA.fieldByName("ID_HARM")->AsInteger;
   _KU.fieldByName("NR_HARM")->AsInteger        = _MA.fieldByName("ID_HARM")->AsInteger;
   _KU.fieldByName("ZADANIE")->AsString         = _MA.fieldByName("ZADANIE")->AsString;
   _KU.fieldByName("ID_JEDNOSTKI")->AsInteger   = _MA.fieldByName("ID_JEDNOSTKI")->AsInteger;
   _KU.fieldByName("ILOSC")->AsInteger          = _MA.fieldByName("ILOSC")->AsInteger;

 _KU.post();
 _KU.applyUpdates();
 _KU.close();
}
//---------------------------------------------------------------------------
void KUTEditor::updateDost(const msg::MagID & _MagID)
{
 mng::QueryDB _Q("\
UPDATE PR_ZLECENIA Z SET \
ID_JEDNOSTKI = (select min(m.ID_JEDNOSTKI) from pr_magazyn m where m.DEPOZYT =:DEPOZYT AND M.ID_KOMORKI = :ID_KOMORKI AND M.ROK = :ROK AND M.ID_MAG = :ID_MAG) \
WHERE Z.DEPOZYT =:DEPOZYT AND Z.ID_KOMORKI_GLW = :ID_KOMORKI AND Z.ROK_MAG = :ROK AND Z.ID_MAG = :ID_MAG AND Z.NR_KOL =0 \
");
_MagID.setToPars(_Q.getParams());
_Q.execute();
}
