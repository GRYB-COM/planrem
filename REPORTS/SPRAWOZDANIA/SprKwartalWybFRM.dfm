inherited _SprKwartalWybFRM: T_SprKwartalWybFRM
  Caption = 'Sprawozdania kwartalne'
  ClientHeight = 319
  ClientWidth = 341
  Position = poOwnerFormCenter
  ExplicitWidth = 347
  ExplicitHeight = 344
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 278
    Width = 341
    ExplicitTop = 278
    ExplicitWidth = 341
    inherited bbCancel: TBitBtn
      Left = 256
      Enabled = False
      Visible = False
      ExplicitLeft = 256
    end
    inherited bbWrite: TBitBtn
      Left = 256
      Caption = 'Zamknij'
      ExplicitLeft = 256
    end
    inherited m_PrintPrevFR: T_PopupButton
      inherited popup: TPopupMenu
        object N1: TMenuItem
          Caption = '-'
        end
        object m_RapSQRTMI: TMenuItem
          Caption = 'Raport SQR'
        end
        object m_RapXLSTMI: TMenuItem
          Caption = 'Raport XLS'
        end
      end
    end
  end
  inherited paMain: TPanel
    Width = 341
    Height = 277
    ExplicitWidth = 341
    ExplicitHeight = 277
    object Label1: TLabel
      Left = 9
      Top = 27
      Width = 84
      Height = 13
      Caption = 'Sprawozdanie za:'
    end
    object Label2: TLabel
      Left = 250
      Top = 27
      Width = 21
      Height = 13
      Caption = 'roku'
    end
    object Label3: TLabel
      Left = 9
      Top = 61
      Width = 110
      Height = 13
      Caption = 'Kom'#243'rka organizacyjna'
    end
    object Label4: TLabel
      Left = 9
      Top = 109
      Width = 48
      Height = 13
      Caption = 'Za'#322#261'cznik'
    end
    object Label5: TLabel
      Left = 277
      Top = 109
      Width = 45
      Height = 13
      Caption = 'Od strony'
    end
    object cbOkres: TComboBox
      Left = 99
      Top = 24
      Width = 134
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = '1. Kwarta'#322
      Items.Strings = (
        '1. Kwarta'#322
        '2. Kwarta'#322
        '3. Kwarta'#322
        '4. Kwarta'#322)
    end
    object edRok: TEdit
      Left = 277
      Top = 24
      Width = 42
      Height = 21
      NumbersOnly = True
      TabOrder = 1
      Text = 'edRok'
    end
    object edKomorka: TEdit
      Left = 6
      Top = 80
      Width = 315
      Height = 21
      TabOrder = 2
      Text = 'edKomorka'
    end
    object edZalacznik: TEdit
      Left = 6
      Top = 128
      Width = 265
      Height = 21
      TabOrder = 3
      Text = 'edKomorka'
    end
    object m_StronaED: TEdit
      Left = 277
      Top = 128
      Width = 42
      Height = 21
      Alignment = taRightJustify
      TabOrder = 4
      Text = '1'
    end
    object m_Filtr1CB: TCheckBox
      Left = 9
      Top = 217
      Width = 291
      Height = 17
      Caption = 'Tylko sprz'#281't z wykorzystanymi godzinami'
      TabOrder = 5
    end
    object m_SortRG: TRadioGroup
      Left = 11
      Top = 152
      Width = 311
      Height = 59
      Caption = 'Spos'#243'b sortowania'
      ItemIndex = 0
      Items.Strings = (
        'Nazwa sprz'#281'tu, nr KUT'
        'Nr KUT, nazwa sprz'#281'tu')
      TabOrder = 6
    end
  end
  inherited paTop: TPanel
    Width = 341
    ExplicitWidth = 341
  end
end
