//---------------------------------------------------------------------------

#ifndef pr_kCopierDataSetH
#define pr_kCopierDataSetH
#include <dbclient.hpp>
//---------------------------------------------------------------------------
namespace mng
{
	class QueryDB;
}
	class CopierDataSet
	{
		public:
		   CopierDataSet() : ChangedCount(0),KeyViolCount(0),MovedCount(0),ProblemCount(0) {}

		   int ChangedCount;
		   int KeyViolCount;
		   int MovedCount;
		   int ProblemCount;

		   bool execute(TStringList* FieldsSrc,TStringList* FieldsDst,
				TDataSet* Src,TClientDataSet* Dst,const bool &apply = false);

		   void createFields(TDataSet *src, TDataSet *dst);
		   void createCopy(TDataSet *src, TClientDataSet *dst, bool create_ds, bool create_fields = true);
		   void createCopySum(TDataSet *src, TClientDataSet *dst,
						bool create_ds, AnsiString fieldList, TStringList *valuesFields, bool create_fields = true);

		   AnsiString dataLine(TDataSet *srcDataSet, const AnsiString &dstTableName,const AnsiString &_Mat="");
		   AnsiString valsLine(TDataSet *srcDataSet);
		   AnsiString insOrUpd1Line(TDataSet *srcDataSet, const AnsiString &dstTableName, const AnsiString& _Matching="");
		   void insOrUpd(TCustomClientDataSet *srcDataSet, const AnsiString &dstTableName, mng::QueryDB *executer);
		   void exportDataXML(const AnsiString &dstFileName, TDataSet *srcDataSet);
		   void exportDataInsOrUpd(const AnsiString &dstFileName, TDataSet *srcDataSet, const AnsiString &dstTableName);
		   void exportDataInsOrUpd(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName);
		   void exportData(const AnsiString &dstFileName, TDataSet *srcDataSet, const AnsiString &dstTableName);
		   void exportData(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName,const AnsiString &_Mat="");
		   void exportDataByProc(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName);
		   AnsiString dataLineProc(TDataSet *srcDataSet, const AnsiString &dstTableName);



		private:


	};
//---------------------------------------------------------------------------
#endif
