//---------------------------------------------------------------------------
#pragma hdrstop
#include "PlanMover.h"
#pragma package(smart_init)
#include "SGTOOLS\DATAACCESS\ParamFacade.h"
#include <math.h>
#include <DateUtils.hpp>
#include "MANAGER\Queries.h"
#include "SGTOOLS\DATAACCESS\DAReader.h"
#include "MANAGER\message_dlg.h"
//---------------------------------------------------------------------------
using namespace importmdb;
//---------------------------------------------------------------------------
PlanMover::PlanMover(void)
{
 mng::Query _Q("PR_JEDNOSTKI","*");
 m_JWDAR =  new sgda::DAReader(sgda::ctStreamDB);
 m_JWDAR->setQuery(_Q);
 m_JWDAR->open();
 _Q.setTableRef("PR_KODY_USLUG");
 _Q.setColumnList("*");
 m_KodyUslugDAR =  new sgda::DAReader(sgda::ctStreamDB);
 m_KodyUslugDAR->setQuery(_Q);
 m_KodyUslugDAR->open();

}
//---------------------------------------------------------------------------
PlanMover::~PlanMover(void)
{
 delete m_JWDAR;
 delete m_KodyUslugDAR;
}
//---------------------------------------------------------------------------
String PlanMover::getIsRecSQL(void)
{
 return String("SELECT * FROM PR_HARMONOGRAM WHERE ID_HARMONOGRAMU = :ID_HARM AND ROK =:ROK");

}
//---------------------------------------------------------------------------
String PlanMover::getInsRecSQL(void)
{
 String _Res("EXECUTE PROCEDURE PR_ADD_PLAN(:ROK, :ID_HARM,:ZADANIE,:NR_ZADANIA,:REM,:NAZWA_SPRZ,");
 _Res += ":DOSTAWCA,:NORMA_RBH,:DATA_OD,:DATA_DO,:REMONT,:WARSZTAT,:ID_USLUGI,:INDEKS_MAT,:ID_JEDNOSTKI, ";
 _Res += ":ILOSC,:ILOSC_1,:ILOSC_2,";
 _Res += ":ILOSC_3,:ILOSC_4,:ILOSC_5,:ILOSC_6,:ILOSC_7,:ILOSC_8,";
 _Res += ":ILOSC_9,:ILOSC_10,:ILOSC_11,:ILOSC_12, :KWARTAL_I, :KWARTAL_II,:KWARTAL_III,:KWARTAL_IV)  ";
 return _Res;

}
//---------------------------------------------------------------------------
String PlanMover::getUpdRecSQL(void)
{
 String _Res("EXECUTE PROCEDURE PR_EDIT_PLAN(:ROK,:ID_HARM,:ZADANIE,:NR_ZADANIA,:REM,:NAZWA_SPRZ,");
 _Res += ":DOSTAWCA,:NORMA_RBH,:DATA_OD,:DATA_DO,:REMONT,:WARSZTAT,:ID_USLUGI,:INDEKS_MAT,:ID_JEDNOSTKI, ";
 _Res += ":ILOSC,:ILOSC_1,:ILOSC_2,";
 _Res += ":ILOSC_3,:ILOSC_4,:ILOSC_5,:ILOSC_6,:ILOSC_7,:ILOSC_8,";
 _Res += ":ILOSC_9,:ILOSC_10,:ILOSC_11,:ILOSC_12, :KWARTAL_I, :KWARTAL_II,:KWARTAL_III,:KWARTAL_IV) ";
 return _Res;
}
//---------------------------------------------------------------------------
String PlanMover::getLabel(TDataSet* Source)
{
 String _Res("Nr harm.: ,");
 _Res += Source->FieldByName("nr harm")->AsInteger;;
 return _Res;
}
//---------------------------------------------------------------------------
void PlanMover::setPars(TParams * Dest, TDataSet* Source, const bool _IsIns)
{
 int _MiesOd, _MiesDo;
 int _IdHarm(Source->FieldByName("nr harm")->AsInteger);
 int _IdUslugi = findKU(Source->FieldByName("P/N")->AsString);
 if(_IdUslugi <1)
 {
  mng::MessageDialog::critical("Brak kodu us³ugi: " + Source->FieldByName("P/N")->AsString, "Nieprawid³owy parametr");
  Source->Last();
  return;
 }
 int       _Rok    = Source->FieldByName("ROK")->Text.ToInt();
 TDateTime _DataOd = Source->FieldByName("termin")->AsDateTime;
 TDateTime _DataDo = Source->FieldByName("termin zakoñczenia")->AsDateTime;

 TDateTime _NowyRok(_Rok,1,1);
 TDateTime _Sylwek(_Rok,12,31);
 double  _IKW1   =  Source->FieldByName("I kw")->AsFloat;
 double  _IKW2   =  Source->FieldByName("II kw")->AsFloat;
 double  _IKW3   =  Source->FieldByName("III kw")->AsFloat;
 double  _IKW4   =  Source->FieldByName("IV kw")->AsFloat;
 double  _Razem  = _IKW1+_IKW2+_IKW3+_IKW4;
 if(_DataOd < _NowyRok) _MiesOd =0;
 else _MiesOd = MonthOf(_DataOd);
 if(_DataDo > _Sylwek) _MiesDo =12;
 else _MiesDo = MonthOf(_DataDo);
 String _NazSprz = Source->FieldByName("Nazwa sprzetu")->AsString.Trim();
 setKeyPars(Dest,Source);
 setIloscPars(Dest,0,_IKW1);
 setIloscPars(Dest,3,_IKW2);
 setIloscPars(Dest,6,_IKW3);
 setIloscPars(Dest,9,_IKW4);
Dest->ParamByName("KWARTAL_I")->AsBCD                           = _IKW1;
Dest->ParamByName("KWARTAL_II")->AsBCD                          = _IKW2;
Dest->ParamByName("KWARTAL_III")->AsBCD                         = _IKW3;
Dest->ParamByName("KWARTAL_IV")->AsBCD                          = _IKW4;
Dest->ParamByName("ILOSC")->AsBCD                               = _Razem;
 sgda::ParamFacade(Dest->ParamByName("ZADANIE")).AsString       = _NazSprz;
 sgda::ParamFacade(Dest->ParamByName("NR_ZADANIA")).AsString    = Source->FieldByName("Numer sprzêtu")->AsAnsiString;
 sgda::ParamFacade(Dest->ParamByName("REM")).AsString           = Source->FieldByName("Rodzaj rem")->AsString;
 sgda::ParamFacade(Dest->ParamByName("NAZWA_SPRZ")).AsString    = _NazSprz;
 sgda::ParamFacade(Dest->ParamByName("DOSTAWCA")).AsString      = Source->FieldByName("Dostawca")->AsAnsiString;
 sgda::ParamFacade(Dest->ParamByName("NORMA_RBH")).AsCurrency   = Source->FieldByName("Plan rbh")->AsCurrency;
 sgda::ParamFacade(Dest->ParamByName("DATA_OD")).AsDateTime     = _DataOd;
 sgda::ParamFacade(Dest->ParamByName("DATA_DO")).AsDateTime     = _DataDo;
 if( (int) _DataDo ==0)   Dest->ParamByName("DATA_DO")->Clear();
 sgda::ParamFacade(Dest->ParamByName("WARSZTAT")).AsString      = Source->FieldByName("Warsztat wykonuj¹cy")->AsString;
 sgda::ParamFacade(Dest->ParamByName("ID_USLUGI")).AsString     = _IdUslugi;
 sgda::ParamFacade(Dest->ParamByName("REMONT")).AsString        = Source->FieldByName("Rodzaj rem")->AsString;
 sgda::ParamFacade(Dest->ParamByName("INDEKS_MAT")).AsString    = Source->FieldByName("JIM")->AsString.Trim();
 if(Source->FieldByName("JIM")->AsString.Trim().IsEmpty()) Dest->ParamByName("INDEKS_MAT")->Clear();

 sgda::ParamFacade(Dest->ParamByName("ID_JEDNOSTKI")).AsInteger = findJW(Source->FieldByName("DOSTAWCA")->AsString);
}
//---------------------------------------------------------------------------
void PlanMover::setKeyPars(TParams * Dest, TDataSet* Source)
{
  sgda::ParamFacade(Dest->ParamByName("ID_HARM")).AsInteger = Source->FieldByName("nr harm")->AsInteger;
  sgda::ParamFacade(Dest->ParamByName("ROK")).AsInteger = Source->FieldByName("ROK")->Text.ToInt(); //OnGetText
}
//---------------------------------------------------------------------------
void PlanMover::setIloscPars(TParams * Dest,  const int _Kwart,  const double& __IlKW)
{
  int       _Mies1(_Kwart+1), _Mies2(_Kwart+2), _Mies3(_Kwart+3);
  double  _IlKW(__IlKW), _Il1(0.00), _Il2(0.00),_Il3(0.00);
  String    Par1 = String("ILOSC_") + _Mies1;
  String    Par2 = String("ILOSC_") + _Mies2;
  String    Par3 = String("ILOSC_") + _Mies3;
  while(_IlKW >0)
  {
   if(setIloscPars(_Il1,_IlKW)) break;
   if(setIloscPars(_Il2,_IlKW)) break;
   if(setIloscPars(_Il3,_IlKW)) break;
  }

  sgda::ParamFacade(Dest->ParamByName(Par1)).AsCurrency = _Il1;
  sgda::ParamFacade(Dest->ParamByName(Par2)).AsCurrency = _Il2;
  sgda::ParamFacade(Dest->ParamByName(Par3)).AsCurrency = _Il3;

}
//---------------------------------------------------------------------------
bool PlanMover::setIloscPars(double& _Il, double& _IlKW)
{
  bool _Res(false);
  if(_IlKW <= 1)
  {
   _Il += _IlKW;
   _IlKW =0;
   _Res = true;
  }
  else
  {
	++_Il;
	--_IlKW;
  }
  return _Res;
}
//---------------------------------------------------------------------------
int PlanMover::findJW(const String& _Dostawca)
{
  int _Res = m_JWBuff[_Dostawca].ToIntDef(-1);
  TDataSet * _DS = m_JWDAR->getDataSet();
  if(_Res <0 && !_Dostawca.IsEmpty())
  {
   _DS->First();
   while(!_DS->Eof)
   {
	if(_Dostawca.Pos(_DS->FieldByName("JW")->AsString.Trim())>0)
	{
	 _Res = _DS->FieldByName("ID_JEDNOSTKI")->AsInteger;
	 m_JWBuff[_Dostawca] = _Res;
	 break;
	}
	 _DS->Next();
   }
  }
  return _Res;
}
//---------------------------------------------------------------------------
int PlanMover::findKU(const String& _PN)
{
  int _Res = m_PNBuff[_PN].ToIntDef(-1);
  TDataSet * _DS = m_KodyUslugDAR->getDataSet();
  if(_Res <0 && !_PN.IsEmpty())
  {
   _DS->First();
   while(!_DS->Eof)
   {
	if(_DS->FieldByName("P_N")->AsString.Trim() == _PN.Trim() )
	{
	 _Res = _DS->FieldByName("ID_USLUGI")->AsInteger;
	 m_PNBuff[_PN] = _Res;
	 break;
	}
	 _DS->Next();
   }
  }
  return _Res;
}
