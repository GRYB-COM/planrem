//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EdProtPrzekDetFRM.h"
#include "MANAGER\stream_DB.h"
#include "JBUTILS\jb_ini_my.h"
#include "MANAGER\query_db.h"
#include <dateutils.hpp>
#include "SprzetFinderCTRL.h"
#include "MagID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvDateTimePicker"
#pragma link "AdvDBDateTimePicker"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//STATIKI
const String T_EdProtPrzekDetFRM::M_PROT_DET_SQL("\
select * FROM PR_PROT2MAG WHERE ID_PROT2MAG = :ID_PROT2MAG \
");
//---------------------------------------------------------------------------
const String T_EdProtPrzekDetFRM::M_MAG_SQL("\
select \
m.SYGN_MAG, m.NR_REJ, m.NR_FABR, m.ILOSC AS ILOSC_PRZYJ, \
S.NAZWA AS NAZ_SPRZETU, K.NAZWA AS NAZ_WARSZTATU, \
		(SELECT SUM(R.ILOSC) \
		 FROM PR_ZLECENIA_RBH R INNER JOIN PR_ZLECENIA Z ON Z.ROK = R.ROK AND Z.ID_KOMORKI = R.ID_KOMORKI AND Z.ID_ZLECENIA = R.ID_ZLECENIA \
		 WHERE Z.DEPOZYT = M.DEPOZYT AND Z.ROK_MAG = M.ROK AND Z.ID_KOMORKI_GLW = M.ID_KOMORKI AND Z.ID_MAG = M.ID_MAG) AS ILOSC_REM, \
		(SELECT SUM(PM.ILOSC) \
		 FROM PR_PROT2MAG PM WHERE PM.DEPOZYT = M.DEPOZYT AND PM.ROK_MAG = M.ROK AND PM.ID_KOMORKI = M.ID_KOMORKI AND PM.ID_MAG = M.ID_MAG ) AS ILOSC_WYD \
from pr_magazyn m \
INNER JOIN PR_SPRZET  S  ON S.ID_SPRZETU = M.ID_SPRZETU \
INNER JOIN PR_KOMORKI K  ON K.ID_KOMORKI = K.ID_KOMORKI \
WHERE \
m.DEPOZYT     = :DEPOZYT    AND \n\
m.ROK         = :ROK        AND \n\
m.ID_KOMORKI  = :ID_KOMORKI AND \n\
m.ID_MAG      = :ID_MAG \n\
");
//---------------------------------------------------------------------------
__fastcall T_EdProtPrzekDetFRM::T_EdProtPrzekDetFRM(TComponent* Owner)
	: TForm(Owner)
{
 m_ProtDetSDB = new mng::StreamDB();
 m_MagSDB     = new mng::StreamDB();
 m_Ini        = new jbutils::TMyIni();
 m_SprzFind   = new finders::SprzetFinderCTRL();

 m_ProtDetSDB->setQuery(M_PROT_DET_SQL);
 m_MagSDB->setQuery(M_MAG_SQL);

 m_ProtDetDS->DataSet  = m_ProtDetSDB->getClient();
 m_MagDS->DataSet  = m_MagSDB->getClient();

}
//---------------------------------------------------------------------------
__fastcall T_EdProtPrzekDetFRM::~T_EdProtPrzekDetFRM(void)
{
 delete m_ProtDetSDB;
 delete m_MagSDB;
 delete m_Ini;
 delete m_SprzFind;
}
//---------------------------------------------------------------------------
bool __fastcall T_EdProtPrzekDetFRM::run(const  int& IdWydz, const  int& RokProt, const  int& IdProt, int & IdProtDet)
{
 open(IdProtDet);
 if(m_ProtDetSDB->isEmpty())
 {
  append(IdWydz,RokProt,IdProt,IdProtDet);
 }
 else m_ProtDetSDB->edit();
 openMag();
 return ShowModal() == mrOk;
}
//---------------------------------------------------------------------------
void __fastcall T_EdProtPrzekDetFRM::open(const int& IdProtDet)
{
 m_ProtDetSDB->close();
  m_ProtDetSDB->paramByName("ID_PROT2MAG")->AsInteger = IdProtDet;
 m_ProtDetSDB->open();
}
//---------------------------------------------------------------------------
void __fastcall T_EdProtPrzekDetFRM::append(const int& IdWydz,const int& RokProt,const int& IdProt, int & IdProtDet)
{
 getNewIdProtDet(IdProtDet);
 m_ProtDetSDB->append();
 m_ProtDetSDB->fieldByName("ID_WYDZIALU_PROT")->AsInteger  = IdWydz;
 m_ProtDetSDB->fieldByName("ROK_PROT")->AsInteger          = RokProt;
 m_ProtDetSDB->fieldByName("ID_PROTOKOLU")->AsInteger      = IdProt;
 m_ProtDetSDB->fieldByName("ID_PROT2MAG")->AsInteger       = IdProtDet;

}
//---------------------------------------------------------------------------
const String T_EdProtPrzekDetFRM::M_ID_PROT_SQL("\
SELECT COUNT(*) AS NR_KOL, GEN_ID(PR_PROT2MAG_GEN,1) AS ID_PROT2MAG FROM PR_PROT2MAG  \
");
//---------------------------------------------------------------------------
int __fastcall T_EdProtPrzekDetFRM::getNewIdProtDet(int & IdProtDet)
{
 mng::QueryDB _Q(M_ID_PROT_SQL);
 _Q.open();
 IdProtDet     = _Q.fieldByName("ID_PROT2MAG")->AsInteger;
 _Q.close();
 return IdProtDet;
}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekDetFRM::m_SaveBBClick(TObject *Sender)
{
 m_ProtDetSDB->applyUpdates();
 ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekDetFRM::FormClose(TObject *Sender, TCloseAction &Action)
{
 m_MagSDB->close();
 m_ProtDetSDB->close();

}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekDetFRM::m_CancelBBClick(TObject *Sender)
{
  m_ProtDetSDB->cancelUpdates();
 ModalResult = mrCancel;

}
//---------------------------------------------------------------------------
void __fastcall T_EdProtPrzekDetFRM::openMag(void)
{
 m_MagSDB->close();
  m_MagSDB->paramByName("DEPOZYT")->AsString     = m_ProtDetSDB->fieldByName("DEPOZYT")->AsString;
  m_MagSDB->paramByName("ID_KOMORKI")->AsInteger = m_ProtDetSDB->fieldByName("ID_KOMORKI")->AsInteger;
  m_MagSDB->paramByName("ROK")->AsInteger        = m_ProtDetSDB->fieldByName("ROK_MAG")->AsInteger;
  m_MagSDB->paramByName("ID_MAG")->AsInteger     = m_ProtDetSDB->fieldByName("ID_MAG")->AsInteger;
 m_MagSDB->open();
}
//---------------------------------------------------------------------------

void __fastcall T_EdProtPrzekDetFRM::m_OpenBTClick(TObject *Sender)
{
 finders::SprzetFinderCTRL::Pars _Pars;
 msg::MagID _MagID;
 _Pars.IsFilter =false;
 int _Res = m_SprzFind->find(_MagID,_Pars) ;
 if(_Res ==mrOk  && _MagID.IsDefined)
 {

  m_ProtDetSDB->fieldByName("DEPOZYT")->AsString      = _MagID.Depozyt;
  m_ProtDetSDB->fieldByName("ID_KOMORKI")->AsInteger  = _MagID.IdKomorki;
  m_ProtDetSDB->fieldByName("ROK_MAG")->AsInteger     = _MagID.Rok;
  m_ProtDetSDB->fieldByName("ID_MAG")->AsInteger      = _MagID.IdMag;
  openMag();
  m_ProtDetSDB->fieldByName("ILOSC")->AsCurrency        = m_MagSDB->fieldByName("ILOSC_REM")->AsCurrency - m_MagSDB->fieldByName("ILOSC_WYD")->AsCurrency;
 }

}
//---------------------------------------------------------------------------

