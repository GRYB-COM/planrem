//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pr_kBase0FRM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TprBase0FRM::TprBase0FRM(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TprBase0FRM::TprBase0FRM(HWND ParentWindow)
	: TForm(ParentWindow)
{
}
//---------------------------------------------------------------------------
bool __fastcall TprBase0FRM::GoToNextCtrl(TObject *Sender,WORD &Key )
{
  TWinControl *Objekt;
  TCustomEdit *EditField;
  TDBComboBox *DBComboBox;
  TComboBox *ComboBox;

  EditField = dynamic_cast<TCustomEdit *>(Sender);
  if(EditField) {
     try  {
         if (Key == VK_RIGHT && EditField->SelStart == EditField->Text.Length() && EditField->SelLength <= 1)
                ActiveControl = FindNextControl(EditField,true,true,false);
         if (Key == VK_LEFT && EditField->SelStart == 0 && EditField->SelLength <= 1)
                ActiveControl = FindNextControl(EditField,false,true,false);
         if (Key == VK_RETURN) {Key = 0;ActiveControl = FindNextControl(EditField,true,true,false);}

         return true;
     }
     catch (...){ Key = 0;return false;}
  }
  else if( (ComboBox = dynamic_cast<TComboBox *>(Sender)) != NULL ) {
      try  {
         if (Key == VK_RIGHT && ComboBox->SelStart == ComboBox->Text.Length() && ComboBox->SelLength <= 1)
                ActiveControl = FindNextControl(ComboBox,true,true,false);
         if (Key == VK_LEFT && ComboBox->SelStart == 0 && ComboBox->SelLength <= 1)
                ActiveControl = FindNextControl(ComboBox,false,true,false);
         if (Key == VK_RETURN) {Key = 0;ActiveControl = FindNextControl(ComboBox,true,true,false);}

         return true;
      }
      catch (...){ Key = 0;return false;}
  }
  else if( (DBComboBox = dynamic_cast<TDBComboBox *>(Sender)) != NULL ) {
      try  {
         if (Key == VK_RIGHT && DBComboBox->SelStart == DBComboBox->Text.Length() && DBComboBox->SelLength <= 1)
                ActiveControl = FindNextControl(DBComboBox,true,true,false);
         if (Key == VK_LEFT && DBComboBox->SelStart == 0 && DBComboBox->SelLength <= 1)
                ActiveControl = FindNextControl(DBComboBox,false,true,false);
         if (Key == VK_RETURN) {Key = 0;ActiveControl = FindNextControl(DBComboBox,true,true,false);}

         return true;
      }
      catch (...){ Key = 0;return false;}
  }
  else {
     Objekt = dynamic_cast<TWinControl *>(Sender);
     if(Objekt) {
        try {
           if (Key == VK_RIGHT ) ActiveControl = FindNextControl(Objekt,true,true,false);
           if (Key == VK_LEFT )  ActiveControl = FindNextControl(Objekt,false,true,false);
           if (Key == VK_RETURN) {Key=0;ActiveControl = FindNextControl(Objekt,true,true,false);}

           return true;
        }
        catch (...){ Key = 0;return false;}
     }
  }

 return true;

}
//---------------------------------------------------------------------------
void __fastcall TprBase0FRM::setEnabled(TWinControl *aControl, bool aEnabled)
{
  TWinControl *ctrl;
  for(int i = 0; i < aControl->ControlCount; ++i)
  {
	aControl->Controls[i]->Enabled = aEnabled;
  }
}
//---------------------------------------------------------------------------
