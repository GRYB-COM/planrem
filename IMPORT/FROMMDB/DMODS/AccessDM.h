//---------------------------------------------------------------------------

#ifndef AccessDMH
#define AccessDMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>

//---------------------------------------------------------------------------
namespace importmdb{
class T_AccessDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *m_Conn;
	TADOQuery *m_JWADO;
	TADOQuery *m_OddDAO;
	TADOQuery *m_GrupySPrzADO;
	TADOQuery *m_RodzajeSprzêtuADO;
	TADOQuery *m_WydzDAO;
	TADOQuery *m_KomorkiADO;
	TADOQuery *m_SprzetADO;
	TADOQuery *m_KodyUslugADO;
	TADOQuery *m_PlanADO;
	TADOQuery *m_MagazynADO;
	TADOQuery *m_ZleceniaADO;
	TADOQuery *m_ZlecRbhADO;
	TADOQuery *m_RodzRemADO;
	TADOQuery *m_StopnieADO;
	TADOQuery *m_StanowiskaADO;
	TADOQuery *m_OsobyADO;
	void __fastcall m_PlanADOAfterOpen(TDataSet *DataSet);
	void __fastcall m_PlanADOAfterClose(TDataSet *DataSet);
	void __fastcall m_PlanADOROKGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
public:
	//INTERFFEJS
	  void __fastcall setDBPath(const String& _Path);
	  void __fastcall setIdWydz(const int _IdWydz);
	  void __fastcall setRok(const int Rok);
	//KONSTRUKTOR
	__fastcall  T_AccessDM(TComponent* Owner);
	__fastcall ~T_AccessDM(void);

private:
	//ATRYBUTY
	  String m_DBPath;
	  int    m_IdWydz;
	  int    m_Rok;
};

};  //endnamespace import
//---------------------------------------------------------------------------
#endif
