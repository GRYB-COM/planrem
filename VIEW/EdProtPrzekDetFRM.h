//---------------------------------------------------------------------------

#ifndef EdProtPrzekDetFRMH
#define EdProtPrzekDetFRMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSmoothButton.hpp"
#include "AdvSmoothPanel.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include "AdvDateTimePicker.hpp"
#include "AdvDBDateTimePicker.hpp"
#include <ComCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
namespace mng      { class StreamDB; }
namespace jbutils  { class TMyIni;   }
namespace finders  {class SprzetFinderCTRL; }
//---------------------------------------------------------------------------
class T_EdProtPrzekDetFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothPanel *m_TopP;
	TDataSource *m_ProtDetDS;
	TDBEdit *m_NrMagED;
	TLabel *Label2;
	TLabel *Label4;
	TDBEdit *m_NazSprzED;
	TLabel *Label5;
	TDBEdit *m_NrRejED;
	TAdvSmoothButton *m_OpenBT;
	TLabel *Label1;
	TDBEdit *m_NrFabrED;
	TLabel *Label3;
	TDBEdit *m_WarED;
	TLabel *Label6;
	TDBEdit *m_IlPrzyjED;
	TLabel *Label7;
	TDBEdit *m_IlWydED;
	TLabel *Label8;
	TDBEdit *m_IlDoWydED;
	TLabel *Label9;
	TLabel *Label10;
	TDBEdit *m_IlRemED;
	TDataSource *m_MagDS;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_CancelBBClick(TObject *Sender);
	void __fastcall m_OpenBTClick(TObject *Sender);
public:
	   //INTERFEJS
		 bool __fastcall run(const int& IdWydz,const int& RokProt,const  int& IdProt,  int& IdProtDet);
	   //KONSTRUKTOR DESTRUKTOR
	__fastcall T_EdProtPrzekDetFRM(TComponent* Owner);
	__fastcall ~T_EdProtPrzekDetFRM(void);
private:
	//NARZÊDZIA
	  mng::StreamDB   * m_ProtDetSDB;
	  mng::StreamDB   * m_MagSDB;
	  mng::StreamDB   * m_WydzSDB;
	  jbutils::TMyIni * m_Ini;
	  finders::SprzetFinderCTRL * m_SprzFind;
	//FUNKCJE ZABRONIONE
	  virtual int __fastcall ShowModal(void) { return TForm::ShowModal();}
	//FUNKCJE POMOCNICZE
	  void __fastcall open(const int & _IdProtDet);
	  void __fastcall append(const int& IdWydz, const int& RokProt, const int& IdProt, int & IdProtDet );
	  int  __fastcall getNewIdProtDet(int& IdProtDet);
	  void __fastcall openMag(void);
	//STA£E
	  static const String M_PROT_DET_SQL;
	  static const String M_MAG_SQL;
	  static const String M_ID_PROT_SQL;
};
//---------------------------------------------------------------------------
#endif
