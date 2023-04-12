//---------------------------------------------------------------------------

#ifndef MeldTygQRPH
#define MeldTygQRPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
namespace progzest{
class MeldTygCTRL;
class T_MeldTygQRP : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *Tytul;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TQuickRep *m_SprzPrzyjQR;
	TQRBand *m_PageHeaderQB;
	TQRExpr *m_SprzPrzyjPH;
	TQRBand *m_DetailPrzyjQB;
	TQRExpr *m_NrMagQE;
	TQRShape *QRShape11;
	TQRExpr *QRLabel2;
	TQRShape *QRShape12;
	TQRExpr *m_PodstawaQRE;
	TQRShape *QRShape13;
	TQRExpr *m_NazSprzPrzyjQRE;
	TQRShape *QRShape14;
	TQRExpr *m_NrIlQRE;
	TQRShape *QRShape15;
	TQRExpr *m_JWPrzyjQRE;
	TQRShape *QRShape16;
	TQRExpr *m_NrFabrQRE;
	TQRShape *QRShape17;
	TQRExpr *QRLabel8;
	TQRShape *QRShape18;
	TQRExpr *m_ProtPrzyjQRE;
	TQRShape *QRShape19;
	TQRExpr *QRLabel10;
	TQRShape *QRShape20;
	TQRExpr *m_UwagiPrzyjQRE;
	TQRBand *PageFooterBand1;
	TQRChildBand *m_TitleChildQB;
	TQRChildBand *ChildBand1;
	TQRLabel *QRLabel1;
	TQRShape *QRShape21;
	TQRLabel *QRLabel12;
	TQRShape *QRShape22;
	TQRLabel *QRLabel13;
	TQRShape *QRShape23;
	TQRLabel *QRLabel14;
	TQRShape *QRShape24;
	TQRLabel *QRLabel15;
	TQRShape *QRShape25;
	TQRLabel *QRLabel16;
	TQRShape *QRShape26;
	TQRLabel *QRLabel17;
	TQRShape *QRShape27;
	TQRLabel *QRLabel18;
	TQRShape *QRShape28;
	TQRLabel *QRLabel19;
	TQRShape *QRShape29;
	TQRLabel *QRLabel20;
	TQRShape *QRShape30;
	TQRLabel *QRLabel21;
	TQuickRep *m_TitleQR;
	TQRBand *QRBand2;
	TQRExpr *QRExpr4;
	TQRChildBand *QRChildBand5;
	TQRBand *m_Title1BA;
	TQRLabel *m_SprzPrzyjLB;
	TQRBand *m_PrzyjHeadQRB;
	TQRLabel *QRLabel23;
	TQRShape *QRShape1;
	TQRLabel *QRLabel24;
	TQRShape *QRShape2;
	TQRLabel *QRLabel25;
	TQRShape *QRShape3;
	TQRLabel *QRLabel26;
	TQRShape *QRShape4;
	TQRLabel *QRLabel27;
	TQRShape *QRShape5;
	TQRLabel *QRLabel28;
	TQRShape *QRShape6;
	TQRLabel *QRLabel29;
	TQRShape *QRShape7;
	TQRLabel *QRLabel30;
	TQRShape *QRShape8;
	TQRLabel *QRLabel31;
	TQRShape *QRShape9;
	TQRLabel *QRLabel32;
	TQRShape *QRShape10;
	TQRLabel *QRLabel33;
	TQRBand *SummaryBand1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TTabSheet *TabSheet1;
        TTabSheet *TabSheet4;
	TQuickRep *m_SprzDep1QR;
        TQRBand *QRBand14;
        TQRExpr *QRExpr10;
        TQRBand *QRBand15;
        TQRExpr *QRExpr11;
        TQRShape *QRShape32;
        TQRExpr *QRExpr20;
        TQRShape *QRShape33;
	TQRExpr *m_NazSprzDepQRE;
        TQRShape *QRShape48;
        TQRExpr *QRExpr24;
        TQRShape *QRShape57;
	TQRExpr *m_JWDepQRE;
        TQRShape *QRShape58;
	TQRExpr *m_ProtStTechDepQRE;
        TQRShape *QRShape61;
        TQRExpr *QRExpr27;
        TQRShape *QRShape66;
	TQRExpr *m_ProtDepQRE;
        TQRShape *QRShape69;
        TQRExpr *QRExpr29;
        TQRShape *QRShape70;
        TQRExpr *QRExpr30;
        TQRBand *QRBand16;
        TQRSysData *QRSysData7;
        TQRSysData *QRSysData8;
        TQRChildBand *QRChildBand7;
        TQRLabel *QRLabel35;
        TQRShape *QRShape71;
        TQRLabel *QRLabel36;
        TQRShape *QRShape76;
        TQRLabel *QRLabel57;
        TQRShape *QRShape80;
        TQRLabel *QRLabel61;
        TQRShape *QRShape81;
        TQRLabel *QRLabel62;
        TQRShape *QRShape82;
        TQRLabel *QRLabel63;
        TQRShape *QRShape83;
        TQRLabel *QRLabel69;
        TQRShape *QRShape84;
        TQRLabel *QRLabel72;
        TQRShape *QRShape85;
        TQRLabel *QRLabel73;
        TQRShape *QRShape86;
        TQRLabel *QRLabel74;
        TQRBand *QRBand17;
        TQRLabel *QRLabel75;
        TQRBand *QRBand18;
        TQRLabel *QRLabel76;
        TQRShape *QRShape87;
        TQRLabel *QRLabel77;
        TQRShape *QRShape88;
        TQRLabel *QRLabel79;
        TQRShape *QRShape90;
        TQRLabel *QRLabel80;
        TQRShape *QRShape91;
        TQRLabel *QRLabel81;
        TQRShape *QRShape92;
        TQRLabel *QRLabel82;
        TQRShape *QRShape93;
        TQRLabel *QRLabel83;
        TQRShape *QRShape94;
        TQRLabel *QRLabel84;
        TQRShape *QRShape95;
        TQRLabel *QRLabel85;
        TQRShape *QRShape96;
        TQRLabel *QRLabel86;
        TQRBand *QRBand19;
        TTabSheet *TabSheet5;
        TQuickRep *m_PodsumQR;
        TQRBand *QRBand20;
        TQRMemo *m_UwagiWnioskiQRM;
        TQRMemo *QRMemo1;
        TQRCompositeReport *m_CompQR;
	TQRChildBand *ChildBand2;
	TQRLabel *QRLabel4;
	TQRShape *QRShape37;
	TQRLabel *QRLabel5;
	TQRShape *QRShape79;
	TQRExpr *QRExpr7;
	TQRShape *QRShape97;
	TQRLabel *QRLabel6;
	TQRShape *QRShape98;
	TQRShape *QRShape99;
	TQRLabel *QRLabel7;
	TQRExpr *QRExpr9;
	TQRShape *QRShape101;
	TTabSheet *TabSheet6;
	TQuickRep *m_SprzPrzyjNplQR;
	TQRBand *QRBand21;
	TQRExpr *m_SprzPrzyjNplPH;
	TQRBand *m_PrzyjNplDetailQRB;
	TQRExpr *QRExpr14;
	TQRExpr *QRExpr15;
	TQRShape *QRShape89;
	TQRExpr *QRExpr17;
	TQRShape *QRShape100;
	TQRShape *QRShape102;
	TQRExpr *QRExpr18;
	TQRShape *QRShape103;
	TQRExpr *QRExpr21;
	TQRShape *QRShape104;
	TQRExpr *QRExpr23;
	TQRShape *QRShape105;
	TQRExpr *QRExpr25;
	TQRShape *QRShape106;
	TQRExpr *QRExpr26;
	TQRShape *QRShape107;
	TQRExpr *QRExpr28;
	TQRShape *QRShape108;
	TQRExpr *QRExpr31;
	TQRShape *QRShape109;
	TQRExpr *QRExpr32;
	TQRExpr *QRExpr33;
	TQRShape *QRShape110;
	TQRExpr *QRExpr34;
	TQRShape *QRShape111;
	TQRBand *QRBand23;
	TQRSysData *QRSysData9;
	TQRSysData *QRSysData10;
	TQRChildBand *QRChildBand9;
	TQRChildBand *QRChildBand10;
	TQRLabel *QRLabel3;
	TQRShape *QRShape112;
	TQRLabel *QRLabel9;
	TQRShape *QRShape113;
	TQRLabel *QRLabel11;
	TQRShape *QRShape114;
	TQRLabel *QRLabel40;
	TQRShape *QRShape115;
	TQRLabel *QRLabel78;
	TQRShape *QRShape116;
	TQRLabel *QRLabel87;
	TQRShape *QRShape117;
	TQRLabel *QRLabel88;
	TQRShape *QRShape118;
	TQRLabel *QRLabel89;
	TQRShape *QRShape119;
	TQRLabel *QRLabel90;
	TQRShape *QRShape120;
	TQRLabel *QRLabel91;
	TQRShape *QRShape121;
	TQRLabel *QRLabel92;
	TQRLabel *QRLabel93;
	TQRShape *QRShape122;
	TQRLabel *QRLabel94;
	TQRShape *QRShape123;
	TQRBand *QRBand24;
	TQRLabel *m_SprzPrzyjNplLB;
	TQRBand *m_PrzyjNplHeadQRB;
	TQRLabel *QRLabel96;
	TQRShape *QRShape124;
	TQRLabel *QRLabel97;
	TQRShape *QRShape125;
	TQRLabel *QRLabel98;
	TQRShape *QRShape126;
	TQRLabel *QRLabel99;
	TQRShape *QRShape127;
	TQRLabel *QRLabel100;
	TQRShape *QRShape128;
	TQRLabel *QRLabel101;
	TQRShape *QRShape129;
	TQRLabel *QRLabel102;
	TQRShape *QRShape130;
	TQRLabel *QRLabel103;
	TQRShape *QRShape131;
	TQRLabel *QRLabel104;
	TQRShape *QRShape132;
	TQRLabel *QRLabel105;
	TQRShape *QRShape133;
	TQRLabel *QRLabel106;
	TQRLabel *QRLabel107;
	TQRShape *QRShape134;
	TQRShape *QRShape135;
	TQRLabel *QRLabel108;
	TQRBand *QRBand26;
	TTabSheet *TabSheet7;
	TQuickRep *m_SprzDepQR;
	TQRBand *QRBand27;
	TQRExpr *m_SprzDepHP;
	TQRBand *m_SprzDepDetailQRB;
	TQRExpr *QRExpr36;
	TQRExpr *QRExpr37;
	TQRShape *QRShape136;
	TQRExpr *QRExpr38;
	TQRShape *QRShape137;
	TQRShape *QRShape138;
	TQRExpr *QRExpr39;
	TQRShape *QRShape139;
	TQRExpr *QRExpr40;
	TQRShape *QRShape140;
	TQRExpr *QRExpr41;
	TQRShape *QRShape141;
	TQRExpr *QRExpr42;
	TQRShape *QRShape142;
	TQRExpr *QRExpr43;
	TQRShape *QRShape143;
	TQRExpr *QRExpr44;
	TQRShape *QRShape144;
	TQRExpr *QRExpr45;
	TQRShape *QRShape145;
	TQRExpr *QRExpr46;
	TQRExpr *QRExpr47;
	TQRShape *QRShape146;
	TQRExpr *QRExpr48;
	TQRShape *QRShape147;
	TQRBand *QRBand29;
	TQRSysData *QRSysData11;
	TQRSysData *QRSysData12;
	TQRChildBand *QRChildBand11;
	TQRChildBand *QRChildBand12;
	TQRLabel *QRLabel109;
	TQRShape *QRShape148;
	TQRLabel *QRLabel110;
	TQRShape *QRShape149;
	TQRLabel *QRLabel111;
	TQRShape *QRShape150;
	TQRLabel *QRLabel112;
	TQRShape *QRShape151;
	TQRLabel *QRLabel113;
	TQRShape *QRShape152;
	TQRLabel *QRLabel114;
	TQRShape *QRShape153;
	TQRLabel *QRLabel115;
	TQRShape *QRShape154;
	TQRLabel *QRLabel116;
	TQRShape *QRShape155;
	TQRLabel *QRLabel117;
	TQRShape *QRShape156;
	TQRLabel *QRLabel118;
	TQRShape *QRShape157;
	TQRLabel *QRLabel119;
	TQRLabel *QRLabel120;
	TQRShape *QRShape158;
	TQRLabel *QRLabel121;
	TQRShape *QRShape159;
	TQRBand *QRBand30;
	TQRLabel *m_SprzDepLB;
	TQRBand *m_SprzDepHeadQRB;
	TQRLabel *QRLabel123;
	TQRShape *QRShape160;
	TQRLabel *QRLabel124;
	TQRShape *QRShape161;
	TQRLabel *QRLabel125;
	TQRShape *QRShape162;
	TQRLabel *QRLabel126;
	TQRShape *QRShape163;
	TQRLabel *QRLabel127;
	TQRShape *QRShape164;
	TQRLabel *QRLabel128;
	TQRShape *QRShape165;
	TQRLabel *QRLabel129;
	TQRShape *QRShape166;
	TQRLabel *QRLabel130;
	TQRShape *QRShape167;
	TQRLabel *QRLabel131;
	TQRShape *QRShape168;
	TQRLabel *QRLabel132;
	TQRShape *QRShape169;
	TQRLabel *QRLabel133;
	TQRLabel *QRLabel134;
	TQRShape *QRShape170;
	TQRShape *QRShape171;
	TQRLabel *QRLabel135;
	TQRBand *m_SprzDepChildQRB;
	TQuickRep *m_SprzRemQR;
	TQRBand *QRBand8;
	TQRExpr *m_SprzRemQRPH;
	TQRBand *m_SprzRemDetailQRB;
	TQRExpr *m_PodstRemQRE;
	TQRExpr *QRExpr6;
	TQRShape *QRShape38;
	TQRExpr *QRExpr12;
	TQRShape *QRShape42;
	TQRShape *QRShape43;
	TQRExpr *m_NazSprzRemQRE;
	TQRShape *QRShape47;
	TQRExpr *QRExpr19;
	TQRShape *QRShape52;
	TQRExpr *m_JWRemQRE;
	TQRShape *QRShape53;
	TQRExpr *m_NrFabrRemQRE;
	TQRShape *QRShape62;
	TQRExpr *QRExpr49;
	TQRShape *QRShape63;
	TQRExpr *m_ProtPrzyjRemQRE;
	TQRShape *QRShape64;
	TQRExpr *QRExpr51;
	TQRShape *QRShape65;
	TQRExpr *QRExpr52;
	TQRExpr *QRExpr53;
	TQRShape *QRShape67;
	TQRExpr *QRExpr54;
	TQRShape *QRShape68;
	TQRBand *QRBand10;
	TQRSysData *QRSysData5;
	TQRSysData *QRSysData6;
	TQRChildBand *QRChildBand4;
	TQRLabel *QRLabel22;
	TQRShape *QRShape72;
	TQRLabel *QRLabel41;
	TQRShape *QRShape73;
	TQRLabel *QRLabel47;
	TQRShape *QRShape74;
	TQRLabel *QRLabel48;
	TQRShape *QRShape75;
	TQRLabel *QRLabel52;
	TQRShape *QRShape77;
	TQRLabel *QRLabel53;
	TQRShape *QRShape78;
	TQRLabel *QRLabel58;
	TQRShape *QRShape172;
	TQRLabel *QRLabel59;
	TQRShape *QRShape173;
	TQRLabel *QRLabel60;
	TQRShape *QRShape174;
	TQRLabel *QRLabel64;
	TQRShape *QRShape175;
	TQRLabel *QRLabel65;
	TQRLabel *QRLabel66;
	TQRShape *QRShape176;
	TQRLabel *QRLabel67;
	TQRShape *QRShape177;
	TQRBand *QRBand11;
	TQRLabel *m_SprzRemQRLB;
	TQRBand *m_SprzRemHeadQRB;
	TQRLabel *QRLabel70;
	TQRShape *QRShape178;
	TQRLabel *QRLabel71;
	TQRShape *QRShape179;
	TQRLabel *QRLabel95;
	TQRShape *QRShape180;
	TQRLabel *QRLabel122;
	TQRShape *QRShape181;
	TQRLabel *QRLabel136;
	TQRShape *QRShape182;
	TQRLabel *QRLabel137;
	TQRShape *QRShape183;
	TQRLabel *QRLabel138;
	TQRShape *QRShape184;
	TQRLabel *QRLabel139;
	TQRShape *QRShape185;
	TQRLabel *QRLabel140;
	TQRShape *QRShape186;
	TQRLabel *QRLabel141;
	TQRShape *QRShape187;
	TQRLabel *QRLabel142;
	TQRLabel *QRLabel143;
	TQRShape *QRShape188;
	TQRShape *QRShape189;
	TQRLabel *QRLabel144;
	TQRBand *m_SprzRemChildQRB;
	TQRShape *QRShape190;
	TQRLabel *QRLabel145;
	TQRShape *QRShape191;
	TQRLabel *QRLabel146;
	TQRShape *QRShape192;
	TQRExpr *QRExpr55;
	TQRLabel *QRLabel147;
	TQRShape *QRShape193;
	TQRLabel *QRLabel68;
	TQRShape *QRShape194;
	TQRExpr *QRExpr2;
	TQRShape *QRShape195;
	TQRExpr *QRExpr5;
	TQRShape *QRShape196;
	TQRExpr *QRExpr16;
	TQRShape *QRShape197;
	TQRLabel *QRLabel148;
	TQRShape *QRShape198;
	TQRLabel *QRLabel149;
	TQRShape *QRShape199;
	TQRLabel *QRLabel150;
	TQRShape *QRShape200;
	TQRLabel *QRLabel151;
	TQRShape *QRShape201;
	TQuickRep *m_SprzPrzekQR;
	TQRBand *QRBand1;
	TQRExpr *m_SprzPrzekPHLB;
	TQRBand *m_SprzPrzekDetailQRB;
	TQRExpr *QRExpr3;
	TQRExpr *QRExpr8;
	TQRShape *QRShape31;
	TQRExpr *QRExpr13;
	TQRShape *QRShape34;
	TQRShape *QRShape35;
	TQRExpr *QRExpr22;
	TQRShape *QRShape36;
	TQRExpr *QRExpr35;
	TQRShape *QRShape39;
	TQRExpr *QRExpr50;
	TQRShape *QRShape40;
	TQRExpr *QRExpr56;
	TQRShape *QRShape41;
	TQRExpr *QRExpr57;
	TQRShape *QRShape44;
	TQRExpr *QRExpr58;
	TQRShape *QRShape45;
	TQRExpr *QRExpr59;
	TQRShape *QRShape46;
	TQRExpr *QRExpr60;
	TQRExpr *QRExpr61;
	TQRShape *QRShape49;
	TQRExpr *QRExpr62;
	TQRShape *QRShape50;
	TQRShape *QRShape51;
	TQRExpr *QRExpr63;
	TQRExpr *QRExpr64;
	TQRShape *QRShape54;
	TQRExpr *QRExpr65;
	TQRShape *QRShape55;
	TQRExpr *QRExpr66;
	TQRShape *QRShape56;
	TQRBand *QRBand4;
	TQRSysData *QRSysData3;
	TQRSysData *QRSysData4;
	TQRChildBand *QRChildBand2;
	TQRLabel *QRLabel34;
	TQRShape *QRShape59;
	TQRLabel *QRLabel37;
	TQRShape *QRShape60;
	TQRLabel *QRLabel38;
	TQRShape *QRShape202;
	TQRLabel *QRLabel39;
	TQRShape *QRShape203;
	TQRLabel *QRLabel42;
	TQRShape *QRShape204;
	TQRLabel *QRLabel43;
	TQRShape *QRShape205;
	TQRLabel *QRLabel44;
	TQRShape *QRShape206;
	TQRLabel *QRLabel45;
	TQRShape *QRShape207;
	TQRLabel *QRLabel46;
	TQRShape *QRShape208;
	TQRLabel *QRLabel49;
	TQRShape *QRShape209;
	TQRLabel *QRLabel50;
	TQRLabel *QRLabel51;
	TQRShape *QRShape210;
	TQRLabel *QRLabel54;
	TQRShape *QRShape211;
	TQRShape *QRShape212;
	TQRLabel *QRLabel55;
	TQRLabel *QRLabel56;
	TQRShape *QRShape213;
	TQRLabel *QRLabel152;
	TQRShape *QRShape214;
	TQRLabel *QRLabel153;
	TQRShape *QRShape215;
	TQRBand *QRBand5;
	TQRLabel *m_SprzPrzekLB;
	TQRBand *m_SprzPrzekHeadQRB;
	TQRLabel *QRLabel155;
	TQRShape *QRShape216;
	TQRLabel *QRLabel156;
	TQRShape *QRShape217;
	TQRLabel *QRLabel157;
	TQRShape *QRShape218;
	TQRLabel *QRLabel158;
	TQRShape *QRShape219;
	TQRLabel *QRLabel159;
	TQRShape *QRShape220;
	TQRLabel *QRLabel160;
	TQRShape *QRShape221;
	TQRLabel *QRLabel161;
	TQRShape *QRShape222;
	TQRLabel *QRLabel162;
	TQRShape *QRShape223;
	TQRLabel *QRLabel163;
	TQRShape *QRShape224;
	TQRLabel *QRLabel164;
	TQRShape *QRShape225;
	TQRLabel *QRLabel165;
	TQRLabel *QRLabel166;
	TQRShape *QRShape226;
	TQRShape *QRShape227;
	TQRLabel *QRLabel167;
	TQRShape *QRShape228;
	TQRLabel *QRLabel168;
	TQRLabel *QRLabel169;
	TQRShape *QRShape229;
	TQRLabel *QRLabel170;
	TQRShape *QRShape230;
	TQRLabel *QRLabel171;
	TQRShape *QRShape231;
	TQRBand *m_SprzPrzekChildQRB;
	TQRChildBand *ChildBand3;
	TQRBand *QRBand9;
	TQRSysData *QRSysData13;
	TQRSysData *QRSysData14;
	TQRChildBand *ChildBand5;
	TQRChildBand *QRChildBand1;
	TQRChildBand *ChildBand4;
	TQRChildBand *ChildBand6;
	void __fastcall m_CompQRAddReports(TObject *Sender);
	void __fastcall m_DetailPrzyjQBBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall QRBand3BeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall QRBand9BeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall QRBand15BeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall clearLP(TCustomQuickRep *Sender, bool &PrintReport);
	void __fastcall getLP(TObject *sender, UnicodeString &Value);
	void __fastcall m_NrMagQEPrint(TObject *sender, UnicodeString &Value);
	void __fastcall QRExpr4Print(TObject *sender, UnicodeString &Value);
	void __fastcall m_SprzPrzyjPHPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SprzPrzyjNplPHPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SprzDepHPPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SprzRemDetailQRBBeforePrint(TQRCustomBand *Sender, bool &PrintBand);
	void __fastcall m_SprzRemQRPHPrint(TObject *sender, UnicodeString &Value);
	void __fastcall m_SprzPrzekPHLBPrint(TObject *sender, UnicodeString &Value);
public:
		//INTERFEJS
		  void  __fastcall setSprzPrzyjDS(TDataSet* _DS);
		  void  __fastcall setSprzPrzyjNplDS(TDataSet* _DS);
		  void  __fastcall setSprzPrzekDS(TDataSet* _DS);
		  void  __fastcall setSprzRemDS(TDataSet* _DS);
		  void  __fastcall setSprzDepDS(TDataSet* _DS);
		  void 	__fastcall print(void);
		  void 	__fastcall preview(void);
		//KONSTRUKTOR DESTRUKTOR
				__fastcall  T_MeldTygQRP(TComponent* Owner);
				__fastcall ~T_MeldTygQRP(void);
private:
		//PRZYJACIELE
		  friend MeldTygCTRL;
		//METODY POMOCNICZE
		  void __fastcall prepare(void);
		  int  __fastcall countBandLines(int & Lines, TQRExpr* _Ex, const AnsiString& _Val);
		//STA�E
		  static const int M_BAND_HEIGHT;
		  static const int M_BAND_OFFSET;
		  static const int M_EXPR_HEIGHT;
		  static const int M_SHAPE_HEIGHT;
		//ATRYBUTY
		  int     m_LP;
		  String  m_Title;
};
//---------------------------------------------------------------------------

};//end namespace progzest
#endif
