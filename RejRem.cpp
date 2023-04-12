//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("ADMIN\naviFrames\fr_rv_navigator_smpl.cpp", RVFrmNavigatorSmpl); /* TFrame: File Type */
USEFORM("ADMIN\naviFrames\fr_rv_navigator_ext.cpp", RVFrmNavigatorExt); /* TFrame: File Type */
USEFORM("ADMIN\naviFrames\fr_rv_navigator_full.cpp", RVFrmNavigatorFull); /* TFrame: File Type */
USEFORM("ADMIN\Data_modul\dm_operat.cpp", DMOperator); /* TDataModule: File Type */
USEFORM("ADMIN\fm_rej_operat.cpp", RejOperat);
USEFORM("ADMIN\fm_uprawnienia.cpp", UprawDlg);
USEFORM("IMPORT\FROMMDB\DMODS\AccessDM.cpp", _AccessDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\PLANKWART\PlanKwartDM.cpp", _PlanKwartDM); /* TDataModule: File Type */
USEFORM("IMPORT\FROMMDB\VIEW\WaitFRM.cpp", _WaitFRM);
USEFORM("REPORTS\SPRAWOZDANIA\BILMOZLPROD\BilMozlProdWybFRM.cpp", _BilMozlProdWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\KWMOZLWAR\KwMozlWarDM.cpp", _KwMozlWarDM); /* TDataModule: File Type */
USEFORM("REPORTS\MELD\TYG\MeldTygWybFRM.cpp", _MeldTygWybFRM);
USEFORM("REPORTS\MELD\TYG\MeldTygDM.cpp", _MeldTygDM); /* TDataModule: File Type */
USEFORM("REPORTS\MELD\TYG\MeldTygQRP.cpp", _MeldTygQRP);
USEFORM("REPORTS\SPRAWOZDANIA\HARMDOST\HarmDostDM.cpp", _HarmDostDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\BILMOZLPROD\BilMozlProdDM.cpp", _BilMozlProdDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\SprKwartalQR.cpp", _SprKwartalneQR);
USEFORM("REPORTS\SPRAWOZDANIA\KWMOZLWAR\KwMozlWarSprzDM.cpp", _KwMozlWarSprzDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\RBH4MIES\RBH4OneMiesDM.cpp", _RBH4OneMiesDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\MOZLREM\MozlRemWybFRM.cpp", _MozlRemWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\KWMOZLWAR\KwMozlWarWybFRM.cpp", _KwMozlWarWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\PLANKWARTZAD\PlanKwartZadDM.cpp", _PlanKwartZadDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\PLANKWARTZAD\PlanKwartZadWybFRM.cpp", _PlanKwartZadWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\PotrzRem\PotrzRemWybFRM.cpp", _PotrzRemWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\RBH4MIES\RBH4OneMiesWybFRM.cpp", _RBH4OneMiesWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\PLANKWART\PlanKwartWybFRM.cpp", _PlanKwartWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\PotrzRem\PotrzRemDM.cpp", _PotrzRemDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\RBH4OS\RBH4OSWybFRM.cpp", _RBH4OSWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\RBH4MIES\RBH4MiesDM.cpp", _RBH4MiesDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\RBH4OS\RBH4OSDM.cpp", _RBH4OSDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\MOZLREM\MozlRemDM.cpp", _MozlRemDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\ROCZNE\SprRoczneWybFRM.cpp", _SprRoczneWybFRM);
USEFORM("REPORTS\SPRAWOZDANIA\STSPRZ\StSprzDM.cpp", _StSprzDM); /* TDataModule: File Type */
USEFORM("REPORTS\SPRAWOZDANIA\SprKwartalWybFRM.cpp", _SprKwartalWybFRM);
USEFORM("VIEW\DICT\SlDelegacjeEditFRM.cpp", _SlDelegacjeEditFRM);
USEFORM("VIEW\DICT\SlEtatyEditFRM.cpp", _SlEtatyEditFRM);
USEFORM("VIEW\DICT\SlJednostkiEditFRM.cpp", _SlJednostkiEditFRM);
USEFORM("VIEW\DICT\SlJednostkiFRM.cpp", _SlJednostkiFRM);
USEFORM("VIEW\DICT\SlKadraEditFRM.cpp", _SlKadraEditFRM);
USEFORM("VIEW\DICT\SlKadraFRM.cpp", _SlKadraFRM);
USEFORM("VIEW\DICT\SlKomorkiEditFRM.cpp", _SlKomorkiEditFRM);
USEFORM("VIEW\DICT\SlKomorkiFRM.cpp", _SlKomorkiFRM);
USEFORM("VIEW\DICT\SlOddzialyEditFRM.cpp", _SlOddzialyEditFRM);
USEFORM("VIEW\DICT\SlOddzialyFRM.cpp", _SlOddzialyFRM);
USEFORM("VIEW\DICT\SlPracEdFRM.cpp", _SlPracEdFRM);
USEFORM("VIEW\DICT\SlPracFRM.cpp", _SlPracFRM);
USEFORM("VIEW\DICT\SlPracownicyEditFRM.cpp", _SlPracownicyEditFRM);
USEFORM("VIEW\DICT\SlPracownicyFRM.cpp", _SlPracownicyFRM);
USEFORM("VIEW\DICT\SlSprzetEditFRM.cpp", _SlSprzetEditFRM);
USEFORM("VIEW\DICT\SlSprzetFRM.cpp", _SlSprzetFRM);
USEFORM("VIEW\DICT\SlSprzetGrupyEditFRM.cpp", _SlSprzetGrupyEditFRM);
USEFORM("VIEW\DICT\SlSprzetGrupyFRM.cpp", _SlSprzetGrupyFRM);
USEFORM("VIEW\DICT\SlSprzetRodzajeEditFRM.cpp", _SlSprzetRodzajeEditFRM);
USEFORM("VIEW\DICT\SlSprzetRodzajeFRM.cpp", _SlSprzetRodzajeFRM);
USEFORM("VIEW\DICT\SlStanEdFRM.cpp", _SlStanEdFRM);
USEFORM("VIEW\DICT\SlStanFRM.cpp", _SlStanFRM);
USEFORM("VIEW\DICT\SlStanowiskaEditFRM.cpp", _SlStanowiskaEditFRM);
USEFORM("VIEW\DICT\SlStanowiskaFRM.cpp", _SlStanowiskaFRM);
USEFORM("VIEW\DICT\SlSzkoleniaEditFRM.cpp", _SlSzkoleniaEditFRM);
USEFORM("VIEW\DICT\SlUrlopyEditFRM.cpp", _SlUrlopyEditFRM);
USEFORM("VIEW\DICT\SlWarEdFRM.cpp", _SlWarEdFRM);
USEFORM("VIEW\DICT\SlWarFRM.cpp", _SlWarFRM);
USEFORM("VIEW\DICT\SlWydzialyEditFRM.cpp", _SlWydzialyEditFRM);
USEFORM("VIEW\DICT\SlWydzialyFRM.cpp", _SlWydzialyFRM);
USEFORM("VIEW\DICT\SlZwolnieniaEditFRM.cpp", _SlZwolnieniaEditFRM);
USEFORM("VIEW\DICT\SL_BASE_FRM.cpp", _SL_BASE_FRM);
USEFORM("VIEW\DICT\SL_EDIT_FRM.cpp", _SL_EDIT_FRM);
USEFORM("VIEW\DokWeFRM.cpp", _DokWeFRM);
USEFORM("VIEW\EdProtPrzekDetFRM.cpp", _EdProtPrzekDetFRM);
USEFORM("VIEW\EdProtPrzekFRM.cpp", _EdProtPrzekFRM);
USEFORM("VIEW\FORMS\AddRbhFRM.cpp", _AddRbhFRM);
USEFORM("VIEW\FORMS\DelHarmFRM.cpp", _DelHarmFRM);
USEFORM("VIEW\FORMS\EditHarmFRM.cpp", _EditHarmFRM);
USEFORM("VIEW\FORMS\EditHarmRBFFRM.cpp", _EditHarmRBFFRM);
USEFORM("VIEW\FORMS\FindHarmFRM.cpp", _FindHarmFRM);
USEFORM("VIEW\FORMS\FindProtFRM.cpp", _FindProtFRM);
USEFORM("VIEW\FORMS\ListaHarmFRM.cpp", _ListaHarmFRM);
USEFORM("VIEW\FORMS\ListaMagFRM.cpp", _ListaMagFRM);
USEFORM("VIEW\FORMS\ListaOldHarmFRM.cpp", _ListaOldHarmFRM);
USEFORM("VIEW\FORMS\MoveHarmRBFFRM.cpp", _MoveHarmRBHFRM);
USEFORM("VIEW\FORMS\PowDostFRM.cpp", _PowDostFRM);
USEFORM("VIEW\FRAMES\DokFRA.cpp", _DokFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\KosztyFRA.cpp", _KosztyFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\KUTkosztyFRA.cpp", _KUTkosztyFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\KUTkosztySumFRA.cpp", _KUTkosztySumFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\KUTrbhFRA.cpp", _KUTrbhFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\KutyFRA.cpp", _KutyFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\ListaHarmFRA.cpp", _ListaHarmFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\ListaMAGFRA.cpp", _ListaMAGFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\ListaProtFRA.cpp", _ListaProtFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\NaglMagFRA.cpp", _NaglMagFRA); /* TFrame: File Type */
USEFORM("VIEW\FRAMES\PowiadomFRA.cpp", _PowiadomFRA); /* TFrame: File Type */
USEFORM("VIEW\KonfigFRM.cpp", _KonfigFRM);
USEFORM("VIEW\FRAMES\SzukajFRA.cpp", _SzukajFRA); /* TFrame: File Type */
USEFORM("VIEW\ImportFromMdbFRM.cpp", _ImportFromMdbFRM);
USEFORM("VIEW\MagFRM.cpp", _MagFRM);
USEFORM("VIEW\TestAcc.cpp", TestFRM);
USEFORM("VIEW\KUTFRM.cpp", _KUTFRM);
USEFORM("VIEW\KUTkosztyEdFRM.cpp", _KUTkosztyEdFRM);
USEFORM("VIEW\ImportPlanFromMdbFRM.cpp", _ImportPlanFromMdbFRM);
USEFORM("VIEW\POCZTA\pr_FromWizjaJB.cpp", _FromWizjaJBFRM);
USEFORM("VIEW\NowyKosztFRM.cpp", _NowyKosztFRM);
USEFORM("VIEW\NowyMagFRM.cpp", _NowyMagFRM);
USEFORM("VIEW\POCZTA\pr_kBase0FRM.cpp", prBase0FRM);
USEFORM("VIEW\NowePowiadFRM.cpp", _NowePowiadFRM);
USEFORM("VIEW\POCZTA\pr_ImporterWizjaJB.cpp", _ImporterWizjaJB);
USEFORM("VIEW\POCZTA\pr_pocztaPopFra.cpp", _pocztaPopFra);
USEFORM("VIEW\POCZTA\pr_pocztaSmtpFra.cpp", _pocztaSmtpFra);
USEFORM("MainMenu.cpp", _MainMenu);
USEFORM("VIEW\PrzyjSprzFRM.cpp", _PrzyjSprzFRM);
USEFORM("REPORTS\SPRAWOZDANIA\STSPRZ\StSprzWybFRM.cpp", _StSprzWybFRM);
USEFORM("VIEW\PrzekSprzFRM.cpp", _PrzekSprzFRM);
USEFORM("VIEW\POCZTA\pr_pocztaLoginFrm.cpp", _pocztaLoginFrm); /* TFrame: File Type */
USEFORM("VIEW\wi_SlZalEditFRM.cpp", _SlZalEditFRM);
USEFORM("VIEW\WystWezwFRM.cpp", _WystWezwFRM);
USEFORM("VIEW\POCZTA\pr_ToWizjaJB.cpp", _ToWizjaJBFRM);
USEFORM("P:\_COMMON\FORMS\_FEDIT01.cpp", _FEDITONE);
USEFORM("VIEW\SlEditFRM.cpp", _SlEditFRM);
USEFORM("P:\_COMMON\FORMS\_FBASE00.cpp", _FBASE);
USEFORM("VIEW\POCZTA\pr_ExporterWizjaJB.cpp", _ExporterWizjaJB);
USEFORM("P:\_COMMON\_SLAWEK\FORMS\FORMS60\FCSWYB.cpp", _FCUSTWYB);
USEFORM("P:\_COMMON\_SLAWEK\FORMS\FORMS60\PopupButton.cpp", _PopupButton); /* TFrame: File Type */
USEFORM("P:\_COMMON\FORMS\_fedit02.cpp", _FEDITEXT);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Title = "Rejestr Remontów";
		Application->CreateForm(__classid(T_MainMenu), &_MainMenu);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
