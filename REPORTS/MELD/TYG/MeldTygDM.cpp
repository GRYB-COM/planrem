//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MeldTygDM.h"
#include "MANAGER\query_db.h"
#include "SGTOOLS\DATAACCESS\ParamsFacade.h"
#include "MANAGER\stream_db.h"
#include "SQR\SQRTools.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
//NAMESPACES
  using namespace progzest;
//---------------------------------------------------------------------------
__fastcall T_MeldTygDM::T_MeldTygDM(TComponent* Owner)
	: TDataModule(Owner)
{
 m_SprzNDostSDB    = new mng::StreamDB();
 m_SprzPrzyjPlSDB  = new mng::StreamDB();
 m_SprzPrzyjNplSDB = new mng::StreamDB();
 m_SprzRemRBHSDB   = new mng::StreamDB();
 m_SprzRemSDB      = new mng::StreamDB();
 m_SprzPrzekSDB    = new mng::StreamDB();
 m_SprzDepSDB      = new mng::StreamDB();
}
//---------------------------------------------------------------------------
__fastcall T_MeldTygDM::~T_MeldTygDM(void)
{
 delete m_SprzNDostSDB;
 delete m_SprzPrzyjPlSDB;
 delete m_SprzPrzyjNplSDB;
 delete m_SprzRemRBHSDB;
 delete m_SprzRemSDB;
 delete m_SprzPrzekSDB;
 delete m_SprzDepSDB;
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygDM::setPars(const T_MeldTygDM::Pars& _Pars)
{
 m_Pars = _Pars;
}
//---------------------------------------------------------------------------
TDataSet* __fastcall T_MeldTygDM::getSprzNDostDS(void)
{
 return m_SprzNDostSDB->getClient();
}
//---------------------------------------------------------------------------
TDataSet* __fastcall T_MeldTygDM::getSprzPrzyjPlDS(void)
{
 return m_SprzPrzyjPlSDB->getClient();
}
//---------------------------------------------------------------------------
TDataSet* __fastcall T_MeldTygDM::getSprzPrzyjNplDS(void)
{
 return m_SprzPrzyjNplSDB->getClient();
}
//---------------------------------------------------------------------------
TDataSet*__fastcall T_MeldTygDM::getSprzPrzekDS(void)
{
 return m_SprzPrzekSDB->getClient();

}
//---------------------------------------------------------------------------
TDataSet*__fastcall T_MeldTygDM::getSprzRemDS(void)
{
 return m_SprzRemSDB->getClient();

}
//---------------------------------------------------------------------------
TDataSet*__fastcall T_MeldTygDM::getSprzRemRBHDS(void)
{
 return m_SprzRemRBHSDB->getClient();

}
//---------------------------------------------------------------------------
TDataSet* __fastcall T_MeldTygDM::getSprzDepDS(void)
{
 return m_SprzDepSDB->getClient();
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygDM::open(void)
{
 openStream("Sprzêt niedostarczony.sqr",m_SprzNDostSDB);
 openStream("Sprzêt przyjêty spoza planu.sqr",m_SprzPrzyjNplSDB);
 openStream("Sprzêt przyjêty zgodnie z planem.sqr",m_SprzPrzyjPlSDB);
 openStream("Sprzêt wyremontowany 1.sqr",m_SprzRemRBHSDB);
 openStream("Sprzêt wyremontowany.sqr",m_SprzRemSDB);
 openStream("Sprzêt przekazany.sqr",m_SprzPrzekSDB);
 openStream("Sprzêt przyjêty do depozytu.sqr",m_SprzDepSDB);
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygDM::openStream(const String& _SQR, mng::StreamDB* _Stream)
{
 String _SQRPath(ExtractFileDir(Application->ExeName));
 _SQRPath += String("\\SQR\\");
 _SQRPath += _SQR;
 _Stream->setQuery( sgtools::SQRTools::getSQL(_SQRPath));
 sgda::ParamsFacade _ParsFcd(_Stream->getParams());
 _ParsFcd.setVal("DATA_OD",m_Pars.DataOd);
 _ParsFcd.setVal("DATA_DO",m_Pars.DataDo);
 _ParsFcd.setVal("MIES_OD",m_Pars.MiesOd);
 _ParsFcd.setVal("MIES_DO",m_Pars.MiesDo);
 _Stream->open();
}
//---------------------------------------------------------------------------
void __fastcall T_MeldTygDM::close(void)
{
 m_SprzNDostSDB->close();
 m_SprzPrzyjPlSDB->close();
 m_SprzPrzyjNplSDB->close();
 m_SprzPrzekSDB->close();
 m_SprzRemSDB->close();
 m_SprzRemRBHSDB->close();
  m_SprzDepSDB->close();

}
//---------------------------------------------------------------------------

