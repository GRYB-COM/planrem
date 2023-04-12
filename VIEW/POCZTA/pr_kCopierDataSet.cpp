//---------------------------------------------------------------------------


#pragma hdrstop

#include "pr_kCopierDataSet.h"
#include <DBTables.hpp>
#include <Provider.hpp>
#include "ismanager.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


void CopierDataSet::createCopy(TDataSet *src, TClientDataSet *dst, bool create_ds, bool create_fields)
{
 if(create_fields)
 {
   dst->Params->Clear();
   createFields(src,dst);
 }

 TStringList* Fields = new TStringList;
 src->GetFieldNames(Fields);

 if(create_ds)
 {
   dst->CreateDataSet();
   dst->LogChanges = false;
 }

 execute(Fields,Fields,src,dst,false);

 delete Fields;
}
//---------------------------------------------------------------------------
void CopierDataSet::createFields(TDataSet *src, TDataSet *dst)
{
 dst->Close();
 dst->Fields->Clear();
 dst->FieldDefs->Clear();

 for(int i = 0; i < src->Fields->Count; ++i)
 {
	dst->FieldDefs->Add(src->Fields->Fields[i]->FieldName,src->Fields->Fields[i]->DataType,src->Fields->Fields[i]->Size,false);
 }

}
//---------------------------------------------------------------------------
bool CopierDataSet::execute(TStringList* FieldsSrc,TStringList* FieldsDst,TDataSet* Src,TClientDataSet* Dst,const bool &apply)
{
 MovedCount = 0;
 ProblemCount=0;
 ChangedCount=0;
 KeyViolCount=0;

 bool IsSrcActive = Src->Active;
 bool IsDstActive = Dst->Active;
 if (!Src->Active) Src->Open();
 if (!Dst->Active) Dst->Open();
 Src->First();

 TField *fieldSrc(NULL);
 TField *fieldDst(NULL);

 while (!Src->Eof)
 {
   try
   {
		  Dst->Append();
		  for (int i=0;i<FieldsDst->Count;i++)
		  {
			fieldDst = Dst->FindField(FieldsDst->Strings[i]);
			fieldSrc = Src->FindField(FieldsSrc->Strings[i]);
			if(fieldDst != NULL && fieldSrc != NULL && !Src->FieldByName(FieldsSrc->Strings[i])->IsNull)
			  Dst->FieldByName(FieldsDst->Strings[i])->Value = Src->FieldByName(FieldsSrc->Strings[i])->Value;
          }
          Dst->Post();
          ++ChangedCount;
   }
   catch (Exception &E)
   {
            Dst->Cancel();

			if(dynamic_cast<EDatabaseError*>(&E) != NULL)
			{
			  if(dynamic_cast<EDBEngineError*>(&E) != NULL)
			  {
				 EDBEngineError* pEngErr=dynamic_cast<EDBEngineError*>(&E);
				 TDBError* pDBErr;

				 pDBErr = pEngErr->Errors[ pEngErr->ErrorCount - 1 ];

				 if(pDBErr->ErrorCode == 13059)  ++KeyViolCount;
			   }
			 }
			 else  ++ProblemCount;
   }

   ++MovedCount;
   Src->Next();
 }//edn while

 if(apply) ProblemCount = Dst->ApplyUpdates(-1);

 Src->Active = IsSrcActive;
 Dst->Active = IsDstActive;

 return true;
}
//---------------------------------------------------------------------------
void CopierDataSet::createCopySum(TDataSet *src, TClientDataSet *dst,
		bool create_ds, AnsiString fieldList, TStringList *valuesFields, bool create_fields)
{
 if(create_fields) createFields(src,dst);

 TStringList* Fields = new TStringList;
 TStringList* locateFields = new TStringList;

 AnsiString f;
 AnsiString tmp = fieldList;
 if(tmp.Length() > 0 && tmp[tmp.Length()] != ';') tmp += ";";
 for(int i = 1; i <= tmp.Length(); ++i)
 {
   if(tmp[i] != ';') f += AnsiString(tmp[i]);
   else
   {
    locateFields->Add(f);
    f = "";
   }
 }

 src->GetFieldNames(Fields);

 if(create_ds)
 {
   dst->CreateDataSet();
   dst->LogChanges = false;
 }

 TLocateOptions SearchOptions ;
 SearchOptions.Clear() ;
 Variant locValues[100];
 TField *field;
 try
 {
   while(!src->Eof)
   {
	   for(int i = 0; i < locateFields->Count; ++i)
		 locValues[i] = Variant(src->FieldByName(locateFields->Strings[i])->AsVariant);

	   if(dst->Locate(fieldList, VarArrayOf(locValues,locateFields->Count-1),SearchOptions))
	   {
		   dst->Edit();
		   for(int i = 0; i < valuesFields->Count; ++i)
		   {
			   field = dst->FindField(valuesFields->Strings[i]);
			   if(field != NULL) dst->FieldByName(valuesFields->Strings[i])->AsCurrency = dst->FieldByName(valuesFields->Strings[i])->AsCurrency
									 + src->FieldByName(valuesFields->Strings[i])->AsCurrency;
		   }
		}
		else
		{
		   dst->Append();
		   for(int i = 0; i < Fields->Count; ++i)
		   {
			 field = dst->FindField(Fields->Strings[i]);
			 if(field != NULL)	 dst->FieldByName(Fields->Strings[i])->Assign(src->FieldByName(Fields->Strings[i]));
		   }
        }

        dst->Post();

        src->Next();
     }
 }
 __finally
 {
	 delete Fields;
     delete locateFields;
 }
}
//---------------------------------------------------------------------------
AnsiString CopierDataSet::insOrUpd1Line(TDataSet *srcDataSet, const AnsiString &dstTableName, const AnsiString & _Match)
{
 AnsiString sql = "UPDATE OR INSERT INTO " + dataLine(srcDataSet,dstTableName);

 return sql;
}
//---------------------------------------------------------------------------
void CopierDataSet::insOrUpd(TCustomClientDataSet *srcDataSet, const AnsiString &dstTableName, mng::QueryDB *executer)
{
 MovedCount = -1;
 ProblemCount = -1;
 ChangedCount = -1;
 KeyViolCount = -1;

 AnsiString fieldsList;
 for(int i = 0; i < srcDataSet->FieldCount; ++i)
	if(i == 0) fieldsList = srcDataSet->Fields->Fields[i]->FieldName;
	else fieldsList += "," + srcDataSet->Fields->Fields[i]->FieldName;

 AnsiString paramsList;
 for(int i = 0; i < srcDataSet->FieldCount; ++i)
	if(i == 0) paramsList = ":" + srcDataSet->Fields->Fields[i]->FieldName;
	else paramsList += ",:" + srcDataSet->Fields->Fields[i]->FieldName;

 AnsiString sql = "UPDATE OR INSERT INTO "
	+ dstTableName + "(" + fieldsList + ")"
	+ " VALUES(" + paramsList + ")";

 executer->setQuery(sql);

 srcDataSet->First();
 while(!srcDataSet->Eof)
 {
	for(int i = 0; i < srcDataSet->FieldCount; ++i)
		executer->paramByName(srcDataSet->Fields->Fields[i]->FieldName)->Assign(srcDataSet->FieldByName(srcDataSet->Fields->Fields[i]->FieldName));
	executer->execute();
	srcDataSet->Next();
 }

}
//---------------------------------------------------------------------------
void CopierDataSet::exportDataXML(const AnsiString &dstFileName, TDataSet *srcDataSet)
{
  TClientDataSet *cds = new TClientDataSet(NULL);
  TDataSetProvider *dsp = new TDataSetProvider(NULL);

  cds->ProviderName = "dsp";
  dsp->DataSet = srcDataSet;
  cds->Open();
  cds->SaveToFile(dstFileName,dfXML);
  cds->Close();

  delete dsp;
  delete cds;
}
//---------------------------------------------------------------------------
void CopierDataSet::exportDataInsOrUpd(const AnsiString &dstFileName, TDataSet *srcDataSet, const AnsiString &dstTableName)
{
  TStringList *daneOut = new  TStringList;

  while(!srcDataSet->Eof)
  {
	daneOut->Add(insOrUpd1Line(srcDataSet,dstTableName));
	srcDataSet->Next();
  }

  daneOut->SaveToFile(dstFileName);

  delete daneOut;
}
//---------------------------------------------------------------------------
void CopierDataSet::exportDataInsOrUpd(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName)
{
  while(!srcDataSet->Eof)
  {
	daneOut->Add(insOrUpd1Line(srcDataSet,dstTableName));
	srcDataSet->Next();
  }
}
//---------------------------------------------------------------------------
void CopierDataSet::exportData(const AnsiString &dstFileName, TDataSet *srcDataSet, const AnsiString &dstTableName)
{
  TStringList *daneOut = new  TStringList;

  while(!srcDataSet->Eof)
  {
	daneOut->Add(dataLine(srcDataSet,dstTableName));
	srcDataSet->Next();
  }

  daneOut->SaveToFile(dstFileName);

  delete daneOut;
}
//---------------------------------------------------------------------------
void CopierDataSet::exportData(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName, const AnsiString &_Matching)
{
  while(!srcDataSet->Eof)
  {
	daneOut->Add(dataLine(srcDataSet,dstTableName,_Matching));
	srcDataSet->Next();
  }
}
//---------------------------------------------------------------------------
void CopierDataSet::exportDataByProc(TStringList *daneOut, TDataSet *srcDataSet, const AnsiString &dstTableName)
{
  while(!srcDataSet->Eof)
  {
	daneOut->Add(dataLineProc(srcDataSet,dstTableName));
	srcDataSet->Next();
  }
}
//---------------------------------------------------------------------------
AnsiString CopierDataSet::dataLineProc(TDataSet *srcDataSet, const AnsiString &_ProcName)
{
  return AnsiString(" EXECUTE PROCEDURE ") + _ProcName + valsLine(srcDataSet);
}
//---------------------------------------------------------------------------
AnsiString CopierDataSet::valsLine(TDataSet *srcDataSet)
{
 String ShortDateFormatBuff = ShortDateFormat;
 ShortDateFormat = "yyyy-mm-dd";
 TReplaceFlags Flags;
 Flags << rfReplaceAll;
 AnsiString oldPtr, newPtr;
 if(mng::Manager::instance().getSystemInfo().getConnectionInfo().getKind() == mng::ConnectionInfo::dbkOracle)
	   { oldPtr = "."; newPtr = ","; }
 else	   { oldPtr = ","; newPtr = "."; }

 TNumericField *nf;
 AnsiString valuesList;
 for(int i = 0; i < srcDataSet->FieldCount; ++i)
 {
	AnsiString value;
	if(srcDataSet->Fields->Fields[i]->IsNull) value = "NULL";
	else if( (nf = dynamic_cast<TNumericField *>(srcDataSet->Fields->Fields[i])) != NULL)
	   value = "'" + StringReplace(srcDataSet->Fields->Fields[i]->AsAnsiString,oldPtr,newPtr,Flags) + "'";
	else
	{
	 value = StringReplace(srcDataSet->Fields->Fields[i]->AsAnsiString,"\n"," ",Flags);
	 value = StringReplace(value,"\r","  ",Flags);
	 value = StringReplace(value,"'","\"",Flags);
	 value =  "'" + value + "'";

	}
    value ="/*" + srcDataSet->Fields->Fields[i]->FieldName+ "*/  "+ value + "  ";
	if(i == 0) valuesList = value;
	else valuesList += "," + value;
 }

 AnsiString ret = "(" + valuesList + ")";
 ShortDateFormat = ShortDateFormatBuff;
 return ret;
}
//---------------------------------------------------------------------------
AnsiString CopierDataSet::dataLine(TDataSet *srcDataSet, const AnsiString &dstTableName,const AnsiString &_Mat)
{
 String ShortDateFormatBuff = ShortDateFormat;
 ShortDateFormat = "yyyy-mm-dd";

 AnsiString fieldsList;
 for(int i = 0; i < srcDataSet->FieldCount; ++i)
	if(i == 0) fieldsList = srcDataSet->Fields->Fields[i]->FieldName;
	else fieldsList += "," + srcDataSet->Fields->Fields[i]->FieldName;

 TReplaceFlags Flags;
 Flags << rfReplaceAll;
 AnsiString oldPtr, newPtr;
 if(mng::Manager::instance().getSystemInfo().getConnectionInfo().getKind() == mng::ConnectionInfo::dbkOracle)
	   { oldPtr = "."; newPtr = ","; }
 else	   { oldPtr = ","; newPtr = "."; }

 TNumericField *nf;
 AnsiString valuesList;
 for(int i = 0; i < srcDataSet->FieldCount; ++i)
 {
	AnsiString value;
	if(srcDataSet->Fields->Fields[i]->IsNull) value = "NULL";
	else if( (nf = dynamic_cast<TNumericField *>(srcDataSet->Fields->Fields[i])) != NULL)
	   value = "'" + StringReplace(srcDataSet->Fields->Fields[i]->AsAnsiString,oldPtr,newPtr,Flags) + "'";
	else
	{
	 value = StringReplace(srcDataSet->Fields->Fields[i]->AsAnsiString,"\n"," ",Flags);
	 value = StringReplace(value,"\r","  ",Flags);
	 value = StringReplace(value,"'","\"",Flags);
	 value = "'" + value + "'";
	}

	if(i == 0) valuesList = value;
	else valuesList += "," + value;
 }

 AnsiString ret = dstTableName + "(" + fieldsList + ")"
	+ " VALUES(" + valuesList + ")";
 ret+=_Mat;
 ShortDateFormat = ShortDateFormatBuff;

 return ret;
}
//---------------------------------------------------------------------------

