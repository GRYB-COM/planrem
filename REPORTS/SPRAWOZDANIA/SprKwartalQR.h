//---------------------------------------------------------------------------

#ifndef SprKwartalQRH
#define SprKwartalQRH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "QuickRpt.hpp"
#include <ExtCtrls.hpp>
#include "QRCtrls.hpp"
#include <DB.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
#include "RpDefine.hpp"
#include "RpRender.hpp"
#include "RpRenderText.hpp"
#include <map>
namespace mng
{
  class QueryDB;
};

namespace progzest{
//---------------------------------------------------------------------------
class T_SprKwartalneQR : public TForm
{
__published:	// IDE-managed Components
	TQuickRep *m_Raport;
	TQRBand *TitleBand1;
	TQRBand *m_DetailQRB;
	TQRBand *PageFooterBand1;
	TQRBand *SummaryBand1;
	TQRGroup *grPoziom;
	TQRGroup *grPodPoziom;
	TQRBand *ftPoziom;
	TQRBand *ftPodPoziom;
	TQRLabel *lbZalacznik;
	TQRLabel *lbTytul;
	TQRLabel *lbOkres;
	TQRLabel *lbKomorka;
	TQRShape *QRShape30;
	TQRShape *QRShape31;
	TQRShape *QRShape32;
	TQRShape *QRShape33;
	TQRShape *QRShape34;
	TQRShape *QRShape35;
	TQRShape *QRShape36;
	TQRShape *QRShape37;
	TQRShape *QRShape38;
	TQRShape *QRShape39;
	TQRShape *QRShape40;
	TQRShape *QRShape41;
	TQRShape *QRShape42;
	TQRShape *QRShape43;
	TQRShape *QRShape44;
	TQRShape *QRShape45;
	TQRShape *QRShape46;
	TQRShape *QRShape49;
	TQRShape *QRShape50;
	TQRShape *QRShape51;
	TQRShape *QRShape52;
	TQRShape *QRShape53;
	TQRShape *QRShape54;
	TQRShape *QRShape55;
	TQRShape *QRShape56;
	TQRShape *QRShape57;
	TQRShape *QRShape58;
	TQRShape *QRShape59;
	TQRShape *QRShape60;
	TQRShape *QRShape61;
	TQRShape *QRShape62;
	TQRShape *QRShape63;
	TQRShape *QRShape64;
	TQRShape *QRShape65;
	TQRShape *QRShape66;
	TQRShape *QRShape67;
	TQRShape *QRShape68;
	TQRShape *QRShape69;
	TQRShape *QRShape70;
	TQRShape *QRShape71;
	TQRShape *QRShape72;
	TQRShape *QRShape73;
	TQRShape *QRShape74;
	TQRShape *QRShape75;
	TQRShape *QRShape76;
	TQRShape *QRShape77;
	TQRShape *QRShape78;
	TQRShape *QRShape79;
	TQRShape *QRShape80;
	TQRShape *QRShape81;
	TQRShape *QRShape82;
	TQRShape *QRShape83;
	TQRShape *QRShape84;
	TQRShape *QRShape85;
	TQRShape *QRShape86;
	TQRShape *QRShape87;
	TQRShape *QRShape88;
	TQRShape *QRShape89;
	TQRShape *QRShape90;
	TQRShape *QRShape91;
	TQRShape *QRShape92;
	TQRShape *QRShape93;
	TQRShape *QRShape94;
	TQRShape *QRShape95;
	TQRShape *QRShape96;
	TQRShape *QRShape97;
	TQRShape *QRShape98;
	TQRShape *QRShape99;
	TQRShape *QRShape100;
	TQRShape *QRShape101;
	TQRShape *QRShape102;
	TQRLabel *m_StronaQRL;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRExpr *QRExpr1;
	TQRExpr *QRExpr3;
	TQRExpr *QRExpr4;
	TQRExpr *QRExpr5;
	TQRExpr *m_JWQRE;
	TQRExpr *QRExpr7;
	TQRExpr *QRExpr8;
	TQRExpr *QRExpr9;
	TQRExpr *QRExpr10;
	TQRExpr *QRExpr11;
	TQRExpr *QRExpr12;
	TQRExpr *QRExpr13;
	TQRExpr *QRExpr14;
	TQRExpr *QRExpr15;
	TQRExpr *QRExpr16;
	TQRExpr *QRExpr17;
	TQRExpr *QRExpr18;
	TQRExpr *QRExpr19;
	TQRExpr *QRExpr20;
	TQRExpr *m_UwagiQRE;
	TQRExpr *m_Proc25QRE;
	TQRExpr *QRExpr23;
	TQRExpr *m_Proc23QRE;
	TQRExpr *QRExpr25;
	TQRExpr *QRExpr26;
	TQRExpr *QRExpr27;
	TQRExpr *QRExpr28;
	TQRExpr *QRExpr29;
	TQRExpr *QRExpr30;
	TQRExpr *QRExpr31;
	TQRExpr *QRExpr32;
	TQRExpr *QRExpr33;
	TQRExpr *QRExpr34;
	TQRExpr *QRExpr35;
	TQRExpr *QRExpr36;
	TQRExpr *m_SumUsl22QRE;
	TQRExpr *m_ProcUsl23QRE;
	TQRExpr *m_SumUsl24QRE;
	TQRExpr *m_ProcUsl25QRE;
	TQRExpr *QRExpr41;
	TQRExpr *QRExpr42;
	TQRExpr *QRExpr43;
	TQRExpr *QRExpr44;
	TQRExpr *QRExpr45;
	TQRExpr *QRExpr46;
	TQRExpr *QRExpr47;
	TQRExpr *QRExpr48;
	TQRExpr *QRExpr49;
	TQRExpr *QRExpr50;
	TQRExpr *m_SumWar22QRE;
	TQRExpr *m_ProcWar23QRE;
	TQRExpr *m_SumWar24QRE;
	TQRExpr *m_ProcWar25QRE;
	TQRExpr *QRExpr55;
	TQRExpr *QRExpr56;
	TQRExpr *QRExpr57;
	TQRExpr *QRExpr58;
	TQRExpr *QRExpr59;
	TQRExpr *QRExpr60;
	TQRExpr *QRExpr61;
	TQRExpr *QRExpr62;
	TQRExpr *QRExpr63;
	TQRExpr *QRExpr64;
	TQRExpr *m_SumOg22QRE;
	TQRExpr *m_ProcOg23QRE;
	TQRExpr *m_SumOg24QRE;
	TQRExpr *m_ProcOg25QRE;
	TClientDataSet *cdsData;
	TDataSetProvider *dspData;
	TQRExpr *m_SumKodUslQRE;
	TQRExpr *m_SumWarQRE;
	TQRLabel *QRLabel61;
	TQRChildBand *ChildBand1;
	TQRLabel *QRLabel62;
	TQRChildBand *ChildBand2;
	TQRChildBand *ChildBand3;
	TQRExpr *QRExpr2;
	TQRChildBand *m_LabelsQRCB;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel24;
	TQRLabel *QRLabel25;
	TQRLabel *QRLabel26;
	TQRLabel *QRLabel27;
	TQRLabel *QRLabel28;
	TQRLabel *QRLabel29;
	TQRLabel *QRLabel30;
	TQRLabel *QRLabel31;
	TQRLabel *QRLabel32;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel17;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel20;
	TQRLabel *QRLabel21;
	TQRLabel *QRLabel22;
	TQRLabel *QRLabel23;
	TQRLabel *QRLabel19;
	TQRLabel *QRLabel16;
	TQRShape *QRShape4;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *QRShape10;
	TQRShape *QRShape11;
	TQRShape *QRShape12;
	TQRShape *QRShape13;
	TQRShape *QRShape14;
	TQRShape *QRShape16;
	TQRShape *QRShape17;
	TQRShape *QRShape19;
	TQRShape *QRShape18;
	TQRShape *QRShape15;
	TQRShape *QRShape24;
	TQRShape *QRShape25;
	TQRShape *QRShape26;
	TQRShape *QRShape27;
	TQRShape *QRShape28;
	TQRShape *QRShape29;
	TQRShape *QRShape22;
	TQRShape *QRShape23;
	TQRShape *QRShape20;
	TQRShape *QRShape21;
	TQRBand *m_PageHeadQRB;
	TQRLabel *QRLabel34;
	TQRShape *QRShape126;
	TQRShape *QRShape125;
	TQRShape *QRShape124;
	TQRShape *QRShape123;
	TQRShape *QRShape122;
	TQRShape *QRShape121;
	TQRShape *QRShape120;
	TQRShape *QRShape119;
	TQRShape *QRShape118;
	TQRShape *QRShape117;
	TQRShape *QRShape116;
	TQRShape *QRShape115;
	TQRShape *QRShape114;
	TQRShape *QRShape113;
	TQRShape *QRShape112;
	TQRShape *QRShape111;
	TQRShape *QRShape110;
	TQRShape *QRShape109;
	TQRShape *QRShape108;
	TQRShape *QRShape107;
	TQRShape *QRShape106;
	TQRShape *QRShape105;
	TQRShape *QRShape104;
	TQRShape *QRShape103;
	TQRShape *QRShape3;
	TQRLabel *QRLabel58;
	TQRLabel *QRLabel57;
	TQRLabel *QRLabel56;
	TQRLabel *QRLabel55;
	TQRLabel *QRLabel54;
	TQRLabel *QRLabel53;
	TQRLabel *QRLabel52;
	TQRLabel *QRLabel51;
	TQRLabel *QRLabel50;
	TQRLabel *QRLabel49;
	TQRLabel *QRLabel48;
	TQRLabel *QRLabel47;
	TQRLabel *QRLabel46;
	TQRLabel *QRLabel45;
	TQRLabel *QRLabel44;
	TQRLabel *QRLabel43;
	TQRLabel *QRLabel42;
	TQRLabel *QRLabel41;
	TQRLabel *QRLabel40;
	TQRLabel *QRLabel39;
	TQRLabel *QRLabel38;
	TQRLabel *QRLabel37;
	TQRLabel *QRLabel36;
	TQRLabel *QRLabel35;
	TQRLabel *QRLabel33;
	TQRChildBand *ChildBand4;
	TQRLabel *QRLabel65;
	TQRShape *QRShape127;
	TQRShape *QRShape128;
	TQRShape *QRShape129;
	TQRShape *QRShape130;
	TQRShape *QRShape131;
	TQRShape *QRShape132;
	TQRShape *QRShape133;
	TQRShape *QRShape134;
	TQRShape *QRShape135;
	TQRShape *QRShape136;
	TQRShape *QRShape137;
	TQRShape *QRShape138;
	TQRShape *QRShape139;
	TQRShape *QRShape140;
	TQRShape *QRShape141;
	TQRShape *QRShape142;
	TQRShape *QRShape143;
	TQRShape *QRShape144;
	TQRShape *QRShape145;
	TQRShape *QRShape146;
	TQRShape *QRShape147;
	TQRShape *QRShape148;
	TQRShape *QRShape149;
	TQRShape *QRShape150;
	TQRShape *QRShape151;
	TQRLabel *QRLabel66;
	TQRLabel *QRLabel67;
	TQRLabel *QRLabel68;
	TQRLabel *QRLabel69;
	TQRLabel *QRLabel70;
	TQRLabel *QRLabel71;
	TQRLabel *QRLabel72;
	TQRLabel *QRLabel73;
	TQRLabel *QRLabel74;
	TQRLabel *QRLabel75;
	TQRLabel *QRLabel76;
	TQRLabel *QRLabel77;
	TQRLabel *QRLabel78;
	TQRLabel *QRLabel79;
	TQRLabel *QRLabel80;
	TQRLabel *QRLabel81;
	TQRLabel *QRLabel82;
	TQRLabel *QRLabel83;
	TQRLabel *QRLabel84;
	TQRLabel *QRLabel85;
	TQRLabel *QRLabel86;
	TQRLabel *QRLabel87;
	TQRLabel *QRLabel88;
	TQRLabel *QRLabel89;
	TQRLabel *QRLabel90;
	TQRExpr *m_SumUsl4QRE;
	TQRExpr *m_SumWar4QRE;
	TQRExpr *m_SumOgQRE;
	TQRLabel *QRLabel60;
	TQRLabel *QRLabel94;
	TQRLabel *QRLabel98;
	TQRShape *QRShape153;
	TQRShape *QRShape154;
	TQRShape *QRShape155;
	TQRShape *QRShape156;
	TQRLabel *QRLabel91;
	TQRLabel *QRLabel92;
	TQRLabel *QRLabel93;
	TQRLabel *QRLabel95;
	TQRLabel *QRLabel96;
	TQRLabel *QRLabel97;
	TQRLabel *QRLabel99;
	TQRShape *QRShape152;
	TQRShape *QRShape157;
	TQRLabel *QRLabel100;
	TWideStringField *cdsDataKOD_WARSZTATU;
	TWideStringField *cdsDataNAZ_WARSZTATU;
	TIntegerField *cdsDataPOZYCJA;
	TWideStringField *cdsDataNAZ_REMONTU;
	TWideStringField *cdsDataNAZ_SPRZETU;
	TWideStringField *cdsDataINDEKS_MAT;
	TIntegerField *cdsDataID_HARM;
	TWideStringField *cdsDataJW;
	TWideStringField *cdsDataMIEJSCOWOSC;
	TWideStringField *cdsDataDOSTAWCA;
	TWideStringField *cdsDataNAZ_RODZ_REM;
	TWideStringField *cdsDataSYGN_ZLECENIA;
	TDateField *cdsDataDATA_WYST;
	TDateField *cdsDataDATA_ZAK;
	TWideStringField *cdsDataREM;
	TWideStringField *cdsDataZAL;
	TDateField *cdsDataDATA_PRZEKAZ;
	TDateField *cdsDataDATA_PRZYJ;
	TBCDField *cdsDataILOSC;
	TBCDField *cdsDataLICZBA_RBH;
	TBCDField *cdsDataR1;
	TBCDField *cdsDataR2;
	TBCDField *cdsDataR3;
	TBCDField *cdsDataR4;
	TWideStringField *cdsDataUWAGI;
	TWideStringField *cdsDataDEPOZYT;
	TStringField *cdsDataPO_TERMINIE;
	TDateField *cdsDataDATA_PROP_ZAK;
	TBCDField *cdsDataILOSC_REM;
	TBCDField *cdsDataILOSC_PLAN;
	TBCDField *cdsDataILOSC_ZAL;
	TBCDField *cdsDataILOSC_M1;
	TStringField *cdsDataPROC_PLAN;
	TStringField *cdsDataPROC_ZAL;
	TBCDField *cdsDataRBH_1;
	TBCDField *cdsDataRBH_2;
	TBCDField *cdsDataRBH_3;
	TIntegerField *cdsDataID_KOMORKI;
	TBCDField *cdsDataILOSC_M2;
	TBCDField *cdsDataILOSC_M3;
	TBCDField *cdsDataILOSC_P;
	TBCDField *cdsDataIP;
	TBCDField *cdsDataIP4;
	TBCDField *cdsDataIK1;
	TBCDField *cdsDataIK2;
	TBCDField *cdsDataIK3;
	TBCDField *cdsDataIK4;
	TBCDField *cdsDataRK0;
	TBCDField *cdsDataRK1;
	TBCDField *cdsDataRK2;
	TBCDField *cdsDataRK3;
	TBCDField *cdsDataRK4;
	TBCDField *cdsDataRH0;
	TBCDField *cdsDataRH1;
	TBCDField *cdsDataRH2;
	TBCDField *cdsDataRH3;
	TBCDField *cdsDataRH4;
	TCurrencyField *cdsDataPLAN_LICZBA_RBH;
	TBCDField *cdsDataIP3;
	TBCDField *cdsDataIP2;
	TBCDField *cdsDataIP1;
	TIntegerField *cdsDataHEAD_WARSZTATU;
	TIntegerField *cdsDataHEAD_REMONTU;
	TClientDataSet *m_Data4SQR;
	TWideStringField *m_Data4SQR_K2;
	TWideStringField *m_Data4SQR_K3;
	TIntegerField *m_Data4SQR_K5;
	TWideStringField *m_Data4SQR_K6;
	TWideStringField *m_Data4SQR_K21;
	TWideStringField *m_Data4SQR_K7;
	TWideStringField *m_Data4SQR_K9;
	TDateField *m_Data4SQR_K10;
	TBCDField *m_Data4SQR_K14;
	TBCDField *m_Data4SQR_K15;
	TBCDField *m_Data4SQR_K16;
	TWideStringField *m_Data4SQR_K26;
	TBCDField *m_Data4SQR_K22;
	TBCDField *m_Data4SQR_K24;
	TBCDField *m_Data4SQR_K17;
	TBCDField *m_Data4SQR_K18;
	TBCDField *m_Data4SQR_K19;
	TBCDField *m_Data4SQR_K20;
	TStringField *m_Data4SQR_K23;
	TStringField *m_Data4SQR_K25;
	TBCDField *m_Data4SQR_K11;
	TBCDField *m_Data4SQR_K12;
	TBCDField *m_Data4SQR_K13;
	TBCDField *m_Data4SQR_K4;
	TCurrencyField *m_Data4SQR_K8;
	TStringField *m_Data4SQRLP;
	TStringField *m_Data4SQRtdatrib_LP;
	TIntegerField *m_Data4SQRID_KOMORKI;
	TIntegerField *m_Data4SQRHEAD_KOMORKI;
	TStringField *m_Data4SQRKOD_WARSZTATU;
	TIntegerField *m_Data4SQRPOZYCJA;
	TIntegerField *m_Data4SQRHEAD_REMONTU;
	TAggregateField *m_Data4SQRSUM_REM_ILOSC_P;
	TStringField *m_Data4SQRtdatrib_ID_HARM;
	void __fastcall lbOkresPrint(TObject *sender, UnicodeString &Value);
	void __fastcall lbKomorkaPrint(TObject *sender, UnicodeString &Value);
	void __fastcall lbZalacznikPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_RaportBeforePrint(TCustomQuickRep *Sender, bool &PrintReport);
	void __fastcall QRExpr1Print(TObject *sender, UnicodeString &Value);
	void __fastcall m_DetailQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_Proc23QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_Proc25QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall ftPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall SummaryBand1BeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall ftPodPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_UwagiQREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall QRExpr26Print(TObject *sender, UnicodeString &Value);
	void __fastcall m_JWQREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_PageHeadChildQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_PageHeadQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall ftPoziomAfterPrint(TQRCustomBand *Sender, bool BandPrinted);
	void __fastcall ChildBand4AfterPrint(TQRCustomBand *Sender, bool BandPrinted);
	void __fastcall ChildBand3AfterPrint(TQRCustomBand *Sender, bool BandPrinted);
	void __fastcall grPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_ProcUsl23QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_ProcUsl25QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumUsl22QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumWar22QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumOg22QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumUsl24QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumWar24QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SumOg24QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_ProcWar23QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_ProcWar25QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_ProcOg23QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_ProcOg25QREPrint(TObject *sender, UnicodeString &Value);
	void __fastcall ftPodPoziomAfterPrint(TQRCustomBand *Sender, bool BandPrinted);
	void __fastcall SummaryBand1AfterPrint(TQRCustomBand *Sender, bool BandPrinted);
	void __fastcall grPodPoziomBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_RaportAfterPrint(TObject *Sender);
	void __fastcall m_RaportAfterPreview(TObject *Sender);
	void __fastcall m_StronaQRLPrint(TObject *sender, UnicodeString &Value);
	void __fastcall printPierwszyMies(TObject *sender, UnicodeString &Value);
	void __fastcall printDrugiMies(TObject *sender, UnicodeString &Value);
	void __fastcall printTrzeciMies(TObject *sender, UnicodeString &Value);
	void __fastcall cdsDataCalcFields(TDataSet *DataSet);
	void __fastcall cdsDataPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall cdsDataReconcileError(TCustomClientDataSet *DataSet, EReconcileError *E,
          TUpdateKind UpdateKind, TReconcileAction &Action);










public:
	//INTERFEJS
	  void __fastcall print(void);
	  void __fastcall preview(void);
	  void __fastcall runSQR(void);
	  void __fastcall setKomorka(AnsiString aVal);
	  void __fastcall setOkres(int aKwartal, int aRok);
	  void __fastcall setZalacznik(AnsiString aVal);
	  void __fastcall setStrona(const int _Str);

	  bool m_Filtr1;
	  int  m_Sort;
	//KONSTRUKTOR
		__fastcall T_SprKwartalneQR(TComponent* Owner);
		__fastcall ~T_SprKwartalneQR();


private:	// User declarations

	int m_rok;
	int m_kwartal;
	AnsiString m_komorka;
	AnsiString m_zalacznik;
	mng::QueryDB *m_qData;
	bool prnFtPodPoziom;
	int lp;
	bool m_PrintPageHeader;
	bool m_NewCol;
	Currency __fastcall getExprDblValue(TQRExpr *expr);
	int poziom;
	TStringList * m_SQL;
	Currency  m_SumIl4;
	Currency  m_SumUslIl;
	Currency  m_SumWarIl;
	Currency  m_SumOgIl;
	Currency  m_SumUsl22;
	Currency  m_SumWar22;
	Currency  m_SumOg22;
	Currency  m_SumUsl24;
	Currency  m_SumWar24;
	Currency  m_SumOg24;
	int       MaxCY;
	int       Strona;
	class Rec{
	public:
	 Currency IloscP;
	 Currency PlanLiczbaRBH;
	 Currency RBH1;
	 Currency RBH2;
	 Currency RBH3;
	 Currency R1;
	 Currency R2;
	 Currency R3;
	 Currency IloscM1;
	 Currency IloscM2;
	 Currency IloscM3;
	 Currency IloscRem;
	 Currency IloscPlan;
	 Currency IloscZal;
	};
	std::map<int,int> m_LP;
	std::map<int,Rec> m_SumWar;
	std::map<String,Rec> m_SumWarRem;
	bool      isPoTer(TDataSet *DataSet);
	bool      isZPlanu(TDataSet *DataSet);
	void      planIlSprz(TDataSet *DataSet,bool _ZPlanu);
	void      planLiczbaRBH(TDataSet *DataSet,bool _ZPlanu);
	void      planRBH(TDataSet *DataSet,bool _ZPlanu,bool _PoTer);
	void      realIl(TDataSet *DataSet,bool _PoTer);
	void      wRem(TDataSet *DataSet, bool _ZPlanu, bool _PoTer);
	void      fillWarHead(void);
	void      fillRemHead(const int _IdKomorki, const String& _KodWar);
	void      sumuj(void);

	static const String M_WARSZTAT_SQL;
	static const String M_REMONT_SQL;
  //KLASY WEWNĘTRZNE
};

}; //end namespace progzest
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
