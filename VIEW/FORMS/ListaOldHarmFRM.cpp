//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ListaOldHarmFRM.h"
#include "MANAGER\stream_db.h"
#include "MANAGER\query_db.h"
#include <memory>
#include "MANAGER\queries.h"
#include "JBUTILS\jb_ini_my.h"
#include <dateutils.hpp>
#include "HarmID.h"
#include "MANAGER\bookmark_man.h"
#include "MANAGER\various_man.h"
#include "MANAGER\grid_drawer.h"
#include "model_messengers_RBH4War.h"
#include "model_readers_RBHReader.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall T_ListaOldHarmFRM::T_ListaOldHarmFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_Ini = new jbutils::TMyIni();
 m_HarmSDB = new mng::StreamDB();
 m_HarmDS->DataSet = m_HarmSDB->getClient();
 m_WarSDB = new mng::StreamDB();
 m_WarSDB->setQuery("SELECT W.ID_KOMORKI,  W.KOD, W.NAZWA \
FROM PR_KOMORKI W \
INNER  JOIN PR_OSOBY O ON O.ID_KOMORKI = W.ID_KOMORKI \
WHERE  W.WARSZTAT='T' \
GROUP BY W.ID_KOMORKI, W.KOD, W.NAZWA \
ORDER BY KOD");
 m_WarDS->DataSet = m_WarSDB->getClient();
 m_Rok = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date())) -1;
}
//---------------------------------------------------------------------------
__fastcall T_ListaOldHarmFRM::~T_ListaOldHarmFRM(void)
{
 delete m_HarmSDB;
 delete m_WarSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------
void __fastcall __fastcall T_ListaOldHarmFRM::setRok(const int _Rok)
{
 m_Rok = _Rok;
}
//---------------------------------------------------------------------------
void __fastcall T_ListaOldHarmFRM::openHarm(const int _IdKomorki)
{
 AnsiString _ColList1("H.ID_HARMONOGRAMU, D.MIESIAC, SUM(D.ILOSC) AS ILOSC , SUM(D.PLAN_RBH)  - SUM(ZR.LICZBA_RBH) PLAN_RBH,  \
(CASE WHEN J.JW IS NULL THEN ' ' ELSE J.JW END) || ' ' ||  (CASE WHEN J.MIEJSCOWOSC IS NULL THEN ' ' ELSE J.MIEJSCOWOSC END ) AS JW_MIEJSCOWOSC, \
R.NAZWA AS NAZ_REMONTU, SPR.NAZWA AS NAZ_SPRZETU,  H.ZADANIE,  H.ID_KOMORKI, 'AAA' AS FLAGA  ");
AnsiString _TabRef("  PR_HARMONOGRAM H LEFT OUTER JOIN PR_JEDNOSTKI J ON (J.ID_JEDNOSTKI = H.ID_JEDNOSTKI ) \
LEFT OUTER JOIN PR_REMONTY R ON (R.ID_REMONTU = H.ID_REMONTU) \
LEFT OUTER JOIN PR_HARMONOGRAM_DET D ON D.ROK = H.ROK AND  D.ID_HARMONOGRAMU = H.ID_HARMONOGRAMU  \
LEFT OUTER JOIN PR_SPRZET SPR ON SPR.ID_SPRZETU = H.ID_SPRZETU   \
LEFT OUTER JOIN PR_ZLECENIA Z ON Z.ID_HARM = H.ID_HARMONOGRAMU AND  Z.ID_KOMORKI =H.ID_KOMORKI AND Z.ROK = H.ROK \
LEFT OUTER JOIN PR_ZLECENIA_RBH ZR ON ZR.ID_ZLECENIA =Z.ID_ZLECENIA AND ZR.ID_KOMORKI = Z.ID_KOMORKI ");
AnsiString _GroupList1("H.ID_HARMONOGRAMU, D.MIESIAC, J.JW, J.MIEJSCOWOSC, R.NAZWA, SPR.NAZWA, H.ZADANIE, H.DATA_OD, H.DATA_DO , H.ID_KOMORKI ");
mng::Query _Q(_TabRef,_ColList1);
_Q.setGroupList(_GroupList1);
_Q.setHaving("SUM(D.PLAN_RBH)  - SUM(ZR.LICZBA_RBH) > 0" );
_Q.attachWherePred( new mng::ComparePredicate( "H.ROK", m_Rok ));
_Q.attachWherePred(new mng::ComparePredicate(" H.ID_KOMORKI", _IdKomorki ));
m_HarmSDB->open(_Q);
TField * _F = m_HarmSDB->fieldByName("PLAN_RBH");
TNumericField* _NF = dynamic_cast<TNumericField*>(_F);
if(_NF)
{
 _NF->DisplayFormat = "###,###,##0.00";
}
}
//---------------------------------------------------------------------------
void __fastcall T_ListaOldHarmFRM::m_MiesCDAfterScroll(TDataSet *DataSet)
{
 int _IdKomorki = m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger;
 openHarm(_IdKomorki);
}
//---------------------------------------------------------------------------

void __fastcall T_ListaOldHarmFRM::FormShow(TObject *Sender)
{
 m_WarSDB->open();
 m_WarCB->KeyValue = -999;
 m_WarCB->KeyValue = m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator komórki",1);
 m_WarCBCloseUp(m_WarCB);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall T_ListaOldHarmFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
  m_Ini->WriteIniInteger("WARTOŒCI DOMYŒLNE","Identyfikator komórki",m_WarCB->KeyValue);
 m_WarSDB->close();
 m_HarmSDB->close();
}
//---------------------------------------------------------------------------

void __fastcall T_ListaOldHarmFRM::m_SaveBBClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------


void __fastcall T_ListaOldHarmFRM::m_WarCBCloseUp(TObject *Sender)
{
 openHarm(m_WarSDB->fieldByName("ID_KOMORKI")->AsInteger);
}
//---------------------------------------------------------------------------

