//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KUTkosztySumFRA.h"
#include "DokWeFRM.h"
#include "manager\stream_db.h"
#include "manager\message_dlg.h"
#include <memory>
#include "iswzorce62.h"
#include "manager\query_db.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothButton"
#pragma link "AdvSmoothPanel"
#pragma link "AdvGrid"
#pragma link "AdvObj"
#pragma link "BaseGrid"
#pragma link "DBAdvGrid"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall T_KUTkosztySumFRA::T_KUTkosztySumFRA(TComponent* Owner)
	: TFrame(Owner)
{
 m_SDB = new mng::StreamDB;
 m_DS->DataSet = m_SDB->getClient();
 m_SDB->setQuery(" SELECT SUM(PR_KOSZTY.ILOSC) SUMA,PR_SLOW_KOSZTOW.NAZWA \
	 FROM PR_KOSZTY,PR_SLOW_KOSZTOW,PR_ZLECENIA \
	 WHERE PR_KOSZTY.ID_SLOW_KOSZTOW = PR_SLOW_KOSZTOW.ID_SLOW_KOSZTOW \
	   AND PR_KOSZTY.ID_ZLECENIA = PR_ZLECENIA.ID_ZLECENIA AND PR_KOSZTY.ID_KOMORKI = PR_ZLECENIA.ID_KOMORKI  AND PR_KOSZTY.ROK = PR_ZLECENIA.ROK \
	   AND PR_ZLECENIA.ROK_MAG =:ROK AND PR_ZLECENIA.ID_KOMORKI_GLW = :ID_KOMORKI AND PR_ZLECENIA.DEPOZYT = :DEPOZYT AND PR_ZLECENIA.ID_MAG = :ID_MAG \
	 GROUP BY PR_SLOW_KOSZTOW.NAZWA");
}
//---------------------------------------------------------------------------
__fastcall T_KUTkosztySumFRA::~T_KUTkosztySumFRA(void)
{
  m_SDB->close();
  delete m_SDB;
}
//---------------------------------------------------------------------------
void __fastcall T_KUTkosztySumFRA::open(msg::MagID _Mag)
{
  m_MagID = _Mag;

  m_SDB->close();

  m_SDB->paramByName("ROK")->DataType        = ftInteger;
  m_SDB->paramByName("ID_KOMORKI")->DataType = ftInteger;
  m_SDB->paramByName("DEPOZYT")->DataType     = ftString;
  m_SDB->paramByName("ID_MAG")->DataType     = ftInteger;

  m_SDB->paramByName("ROK")->AsInteger        = _Mag.Rok;
  m_SDB->paramByName("ID_KOMORKI")->AsInteger = _Mag.IdKomorki;
  m_SDB->paramByName("DEPOZYT")->AsAnsiString     = _Mag.Depozyt;
  m_SDB->paramByName("ID_MAG")->AsInteger     = _Mag.IdMag;
  m_SDB->open();
  TField *      _SumF   = m_SDB->fieldByName("SUMA");
  TFloatField * _SumFF  = dynamic_cast<TFloatField*>(_SumF);
  if(_SumFF) _SumFF->currency = true;
  else
  {
	TBCDField * _SumFBCD  = dynamic_cast<TBCDField*>(_SumF);
	if(_SumFBCD) _SumFBCD->currency = true;
	else
	{
	 TFMTBCDField * _SumFFMTBCD  = dynamic_cast<TFMTBCDField*>(_SumF);
	 if(_SumFFMTBCD) _SumFFMTBCD->currency = true;
	}

  }
  Visible = true;
}
//---------------------------------------------------------------------------
 void __fastcall T_KUTkosztySumFRA::close(void)
 {
  m_SDB->close();
  Visible = false;
 }
//---------------------------------------------------------------------------

