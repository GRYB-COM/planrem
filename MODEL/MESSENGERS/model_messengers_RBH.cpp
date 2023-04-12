//---------------------------------------------------------------------------
#pragma hdrstop
#include "model_messengers_RBH.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace msg;
int RBH::Licznik(0);
//---------------------------------------------------------------------------
RBH::RBH(void)
:RBH_Nom(0.00),
 RBH_Prod(0.00),
 RBH_ProdW(0.00),
 RBH_NProd(0.00),
 RBH_Ef(0.00),
 RBH_Ur(0.00),
 RBH_Prz(0.00),
 RBH_Szk(0.00),
 RBH_Sl(0.00),
 RBH_Ch(0.00)
{
  ++Licznik;

}
//---------------------------------------------------------------------------
RBH& RBH::operator+=(const RBH& _RBH)
{
 RBH_Nom   += _RBH.RBH_Nom;
 RBH_Prod  += _RBH.RBH_Prod;
 RBH_ProdW += _RBH.RBH_ProdW;
 RBH_NProd += _RBH.RBH_NProd;
 RBH_Ef    += _RBH.RBH_Ef;
 RBH_Ur    += _RBH.RBH_Ur;
 RBH_Szk   += _RBH.RBH_Szk;
 RBH_Prz   += _RBH.RBH_Prz;
 RBH_Sl    += _RBH.RBH_Sl;
 RBH_Ch    += _RBH.RBH_Ch;
 if(EtatPr.Pos(_RBH.EtatPr) ==0)
 {
  if(!EtatPr.IsEmpty() ) EtatPr += String("/");
  EtatPr    +=  _RBH.EtatPr;
 }
 return *this;
}
//---------------------------------------------------------------------------
Currency RBH::getAsType(const RBHType& _Type) const
{
 Currency _Res;
 switch(_Type)
 {
   case rtNom:   _Res = RBH_Nom;  break;
   case rtProd:  _Res = RBH_Prod;  break;
   case rtProdW: _Res = RBH_ProdW; break;
   case rtNProd: _Res = RBH_NProd; break;
   case rtEf:    _Res = RBH_Ef;    break;
   case rtUr:    _Res = RBH_Ur;    break;
   case rtPrz:   _Res = RBH_Prz;   break;
   case rtSzk:   _Res = RBH_Szk;   break;
   case rtSl:    _Res = RBH_Sl;    break;
   case rtCh:    _Res = RBH_Ch;    break;
 }
 return _Res;
}

