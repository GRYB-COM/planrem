//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EdProtPrzekFRM.h"
#include "MANAGER\stream_DB.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\query_db.h"
#include <dateutils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//STATIKI
const String T_EdProtPrzekFRM::M_WYDZ_SQL("\
SELECT  WY.ID_WYDZIALU, WY.KOD || ' - ' ||  WY.NAZWA  AS KOD_NAZWA \
FROM PR_WYDZIALY WY WHERE EXISTS (SELECT NULL FROM PR_KOMORKI KO WHERE KO.ID_WYDZIALU = WY.ID_WYDZIALU AND KO.WARSZTAT ='T') \
");
//---------------------------------------------------------------------------
const String T_EdProtPrzekFRM::M_JEDN_SQL("\
SELECT ID_JEDNOSTKI, JW || ' ' || MIEJSCOWOSC AS JW_MIEJSC  FROM PR_JEDNOSTKI J ORDER BY JW \
");
//---------------------------------------------------------------------------
__fastcall T_EdProtPrzekFRM::T_EdProtPrzekFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_ProtSDB = new mng::StreamDB();
 m_JednSDB = new mng::StreamDB();
 m_WydzSDB = new mng::StreamDB();
 m_Ini     = new jbutils::TMyIni();

 m_ProtSDB->setQuery("SELECT P.* FROM PR_PROTOKOLY P WHERE  P.ROK = :ROK AND P.ID_PROTOKOLU = :ID_PROTOKOLU AND P.ID_WYDZIALU = :ID_WYDZIALU");
 m_JednSDB->setQuery(M_JEDN_SQL);
 m_WydzSDB->setQuery(M_WYDZ_SQL);

 m_ProtDS->DataSet  = m_ProtSDB->getClient();
 m_JednDS->DataSet  = m_JednSDB->getClient();
 m_WydzDS->DataSet  = m_WydzSDB->getClient();
}
//---------------------------------------------------------------------------
__fastcall T_EdProtPrzekFRM::~T_EdProtPrzekFRM(void)
{
 delete m_ProtSDB;
 delete m_JednSDB;
 delete m_WydzSDB;
 delete m_Ini;
}
//---------------------------------------------------------------------------
bool __fastcall T_EdProtPrzekFRM::run(int& IdWydz, int& RokProt, int& IdProt)
{
 open(IdWydz,RokProt,IdProt);
 if(m_ProtSDB->isEmpty())
 {
  append(IdWydz,RokProt,IdProt);
 }
 else m_ProtSDB->edit();
 return ShowModal() == mrOk;
}
//---------------------------------------------------------------------------
void __fastcall T_EdProtPrzekFRM::open(int& IdWydz, int& RokProt, int& IdProt)
{
 m_JednSDB->open();
 m_WydzSDB->open();
 m_ProtSDB->close();
  m_ProtSDB->paramByName("ID_WYDZIALU")->AsInteger  = IdWydz;
  m_ProtSDB->paramByName("ROK")->AsInteger          = RokProt;
  m_ProtSDB->paramByName("ID_PROTOKOLU")->AsInteger = IdProt;
 m_ProtSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_EdProtPrzekFRM::append(int& IdWydz, int& RokProt, int& IdProt)
{
 RokProt      = getRokProt();
 IdWydz       = getIdWydz();
 int _NrKol   = getNewIdProt(IdWydz,RokProt,IdProt);
 String _Sygn = FormatFloat("0000",_NrKol) + String("/") + String(RokProt);
 m_ProtSDB->append();
  m_ProtSDB->fieldByName("ID_WYDZIALU")->AsInteger   = IdWydz;
  m_ProtSDB->fieldByName("ROK")->AsInteger           = RokProt;
  m_ProtSDB->fieldByName("ID_PROTOKOLU")->AsInteger  = IdProt;
  m_ProtSDB->fieldByName("DATA_WYST")->AsDateTime    = Date();
  m_ProtSDB->fieldByName("SYGN_PROTOKOLU")->AsString = _Sygn;


}
//---------------------------------------------------------------------------
int __fastcall T_EdProtPrzekFRM::getRokProt(void)
{
  return m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Bie¿¹cy rok", YearOf(Date()));
}
//---------------------------------------------------------------------------
int __fastcall T_EdProtPrzekFRM::getIdWydz(void)
{
  return m_Ini->ReadIniInteger("WARTOŒCI DOMYŒLNE","Domyœlny wydzia³", YearOf(Date()));
}
//---------------------------------------------------------------------------
const String T_EdProtPrzekFRM::M_ID_PROT_SQL("\
SELECT COUNT(*) AS NR_KOL, GEN_ID(PR_PROTOKOLY_GEN,1) AS ID_PROTOKOLU FROM PR_PROTOKOLY WHERE ROK = :ROK AND ID_WYDZIALU = :ID_WYDZIALU \
");
//---------------------------------------------------------------------------
int __fastcall T_EdProtPrzekFRM::getNewIdProt(const int& IdWydz, const int& RokProt, int& IdProt)
{
 mng::QueryDB _Q(M_ID_PROT_SQL);
  _Q.paramByName("ID_WYDZIALU")->AsInteger = IdWydz;
  _Q.paramByName("ROK")->AsInteger = RokProt;
 _Q.open();
 int _NrKol = _Q.fieldByName("NR_KOL")->AsInteger;
 IdProt     = _Q.fieldByName("ID_PROTOKOLU")->AsInteger;
 ++_NrKol;
 return _NrKol;
}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekFRM::m_SaveBBClick(TObject *Sender)
{
 m_ProtSDB->applyUpdates();
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_JednSDB->close();
 m_WydzSDB->close();
 m_ProtSDB->close();

}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekFRM::m_CancelBBClick(TObject *Sender)
{
  m_ProtSDB->cancelUpdates();
 ModalResult = mrCancel;

}
//---------------------------------------------------------------------------

