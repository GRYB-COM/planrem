//---------------------------------------------------------------------------

#ifndef EdProtPrzekFRMH
#define EdProtPrzekFRMH
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
//---------------------------------------------------------------------------
class T_EdProtPrzekFRM : public TForm
{
__published:	// IDE-managed Components
	TAdvSmoothPanel *m_BottomASP;
	TAdvSmoothButton *m_CancelBB;
	TAdvSmoothButton *m_SaveBB;
	TAdvSmoothPanel *m_TopP;
	TDataSource *m_ProtDS;
	TDataSource *m_JednDS;
	TDataSource *m_WydzDS;
	TDBLookupComboBox *m_WydzCB;
	TLabel *m_WydzLB;
	TDBLookupComboBox *m_JednCB;
	TLabel *Label1;
	TDBEdit *m_SygnED;
	TLabel *Label2;
	TAdvDBDateTimePicker *AdvDBDateTimePicker1;
	TLabel *Label3;
	TLabel *Label4;
	TDBEdit *m_PrzekED;
	TLabel *Label5;
	TDBEdit *DBEdit1;
	void __fastcall m_SaveBBClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall m_CancelBBClick(TObject *Sender);
public:
	   //INTERFEJS
		 bool __fastcall run(int& IdWydz, int& RokProt, int& IdProt);
	   //KONSTRUKTOR DESTRUKTOR
	__fastcall T_EdProtPrzekFRM(TComponent* Owner);
	__fastcall ~T_EdProtPrzekFRM(void);
private:
	//NARZÊDZIA
	  mng::StreamDB   * m_ProtSDB;
	  mng::StreamDB   * m_JednSDB;
	  mng::StreamDB   * m_WydzSDB;
	  jbutils::TMyIni * m_Ini;
	//FUNKCJE ZABRONIONE
	  virtual int __fastcall ShowModal(void) { return TForm::ShowModal();}
	//FUNKCJE POMOCNICZE
	  void __fastcall open(int& IdWydz, int& RokProt, int& IdProt);
	  void __fastcall append(int& IdWydz, int& RokProt, int& IdProt);
	  int __fastcall getNewIdProt(const int& IdWydz, const int& RokProt, int& IdProt);
	  int  __fastcall getRokProt(void);
	  int  __fastcall getIdWydz(void);
	//STA£E
	  static const String M_WYDZ_SQL;
	  static const String M_JEDN_SQL;
	  static const String M_ID_PROT_SQL;
};
//---------------------------------------------------------------------------
#endif
