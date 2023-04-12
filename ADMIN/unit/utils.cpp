//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "utils.h"
#include <isvaria\tokens.h>
#include <algorithm>
#include <memory>
#include <DateUtils.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------

#pragma package(smart_init)

// maska tysiêcy
const char* const cc_ThousandGrp = "###";



/**********
*  Funkcje sk³adowe klasy: Utils
**********/


AnsiString Utils::applicationDir(const AnsiString& sub_dir)
{
   AnsiString ret( ExtractFileDir(Application->ExeName) );

   if(!sub_dir.IsEmpty())
   {
      if(sub_dir[1] != '\\')
      {
         ret += "\\";
      }
      
      ret += sub_dir;
   }

   return ret;
}
//---------------------------------------------------------------------------

bool Utils::onKeyPressEnter(TWinControl* parent,TObject *sender,char &key)
{
   bool processed=false;

   if(key == '\r')
   {
      TWinControl* wcp=parent;

      // odszukanie 'pierwszego' rodzica ...
      while(wcp->Parent)
      {
         wcp = wcp->Parent;
      }

      // i wys³anie za jego pomoc¹ komunikatu 'ustaw fokus na nastêpn¹ kontrolkê'
      wcp->Perform(WM_NEXTDLGCTL,0,0);

      key = 0;

      processed = true;
   }

   return processed;
}
//---------------------------------------------------------------------------

bool Utils::onKeyPressUpperCase(TObject *sender,char &key)
{
   if(key != '\r')
   {
      TCustomEdit* ce=dynamic_cast<TCustomEdit*>(sender);

      if(ce != NULL)
      {
         if(ce->GetTextLen() == 0 || ce->GetTextLen() == ce->SelLength)
         {
            key = AnsiUpperCase(key)[1];
         }

         return true;
      }


      TCustomComboBox* cc=dynamic_cast<TCustomComboBox*>(sender);

      if(cc != NULL)
      {
         if(cc->GetTextLen() == 0 || cc->GetTextLen() == cc->SelLength)
         {
            key = AnsiUpperCase(key)[1];
         }

         return true;
      }
   }

   return false;
}
//---------------------------------------------------------------------------

AnsiString Utils::buildMask(int digits,int decimal,bool thousand_sep)
{
   decimal = std::max(0,decimal);
   digits  = std::max(decimal,digits);

   AnsiString mask;
   AnsiString tp( (thousand_sep ? AnsiString(',') : AnsiString()) );

   if(digits > decimal)
   {
      int size=digits-decimal;
      int groups=size/3;

      for(int ii=0;ii < groups-1;++ii)
      {
         mask += cc_ThousandGrp + tp;
      }

      if(groups > 0)
      {
         mask += cc_ThousandGrp;
      }

      if((size % 3) != 0)
      {
         if(mask.IsEmpty())
         {
            mask = AnsiString::StringOfChar('#',size % 3);
         }
         else
         {
            mask = AnsiString::StringOfChar('#',size % 3) + tp + mask;
         }
      }

      // ostatnia maska - na zero, gdy brak cyfry
      mask[ mask.Length() ] = '0';
   }

   if(decimal > 0)
   {
      mask += AnsiString('.') + AnsiString::StringOfChar('0',decimal);
   }

   return mask;
}
//---------------------------------------------------------------------------

AnsiString Utils::selectDirectory(const AnsiString& init_dir,const AnsiString& mask,bool file_must_exists)
{
   /*
   std::auto_ptr<TRVDirSelect> dlg( new TRVDirSelect(NULL,mask,file_must_exists) );

   AnsiString dir_name;

   if(dlg->SelectDirectory(init_dir,""))
   {
      dir_name = dlg->GetSelectedDir();
   }

   return dir_name;
   */
   return "";
}
//---------------------------------------------------------------------------

bool Utils::selectFile(AnsiString& file_nm,const AnsiString& title,const AnsiString& filter,const AnsiString& initial_dir,bool file_must_exist)
{
   return ""; //dmCommons->SelectFile(file_nm,title,filter,initial_dir,file_must_exist);
}
//---------------------------------------------------------------------------

void Utils::clearFlags(TDataSet* dset,const AnsiString& fields)
{
   Tokens tk(fields,";");

   while(!tk.IsEOT())
   {
      TField* field=dset->FindField(tk.Token());

      if(field != NULL)
      {
         field->ProviderFlags.Clear();
      }

      tk.Next();
   }
}
//------------------------------------------------------------------------------

void Utils::markPrimaryKey(TDataSet* dset,const AnsiString& fields)
{
   Tokens tk(fields,";");

   while(!tk.IsEOT())
   {
      TField* field=dset->FindField(tk.Token());

      if(field != NULL)
      {
         field->ProviderFlags = field->ProviderFlags << pfInKey;
      }

      tk.Next();
   }
}
//------------------------------------------------------------------------------

void Utils::setNumericMask(TField* field,const AnsiString& mask)
{
   TNumericField* num_field=dynamic_cast<TNumericField*>(field);

   if(num_field != NULL)
   {
      num_field->DisplayFormat = mask;
      num_field->EditFormat    = mask;
   }
}
//---------------------------------------------------------------------------

void Utils::setNumericMask(TDataSet* data_set,const AnsiString& fields,const AnsiString& mask)
{
   Tokens names(fields,";");

   while(!names.IsEOT())
   {
      setNumericMask(data_set->FieldByName(names.Token()),mask);

      names.Next();
   }
}
//------------------------------------------------------------------------------

