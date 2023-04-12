inherited _BilMozlProdWybFRM: T_BilMozlProdWybFRM
  Caption = 'Bilans mo'#380'liwo'#347'ci produkcujnych'
  ClientHeight = 184
  ClientWidth = 416
  OnClose = FormClose
  OnShow = FormShow
  ExplicitWidth = 422
  ExplicitHeight = 209
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 143
    Width = 416
    ExplicitTop = 143
    ExplicitWidth = 416
    inherited bbCancel: TBitBtn
      Left = 255
      ExplicitLeft = 255
    end
    inherited bbWrite: TBitBtn
      Left = 331
      ExplicitLeft = 331
    end
  end
  inherited paMain: TPanel
    Width = 416
    Height = 142
    ExplicitWidth = 416
    ExplicitHeight = 142
    object m_RokLB: TLabel
      Left = 10
      Top = 91
      Width = 20
      Height = 13
      Caption = 'Rok'
      Transparent = True
    end
    object m_WydzialLB: TLabel
      Left = 10
      Top = 52
      Width = 39
      Height = 13
      Caption = 'Wydzia'#322
      Transparent = True
    end
    object m_WarLB: TLabel
      Left = 10
      Top = 11
      Width = 42
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object Label1: TLabel
      Left = 111
      Top = 91
      Width = 51
      Height = 13
      Caption = 'Miesi'#261'c od'
      Transparent = True
    end
    object Label2: TLabel
      Left = 207
      Top = 91
      Width = 51
      Height = 13
      Caption = 'Miesi'#261'c do'
      Transparent = True
    end
    object m_RokED: TEdit
      Left = 10
      Top = 106
      Width = 86
      Height = 21
      Ctl3D = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 2
      Text = 'm_RokED'
    end
    object m_WydzialCB: TDBLookupComboBox
      Left = 10
      Top = 67
      Width = 391
      Height = 21
      Anchors = [akLeft, akTop, akRight, akBottom]
      DropDownRows = 30
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WydzialDS
      NullValueKey = 46
      TabOrder = 0
      OnCloseUp = m_WydzialCBCloseUp
    end
    object m_WarCB: TDBLookupComboBox
      Left = 10
      Top = 26
      Width = 391
      Height = 21
      Anchors = [akLeft, akTop, akRight, akBottom]
      DropDownRows = 30
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarDS
      NullValueKey = 46
      TabOrder = 1
    end
    object m_MiesOdCB: TComboBox
      Left = 111
      Top = 106
      Width = 83
      Height = 21
      DropDownCount = 12
      ItemIndex = 0
      TabOrder = 3
      Text = 'stycze'#324
      Items.Strings = (
        'stycze'#324
        'luty'
        'marzec'
        'kwiecie'#324
        'maj'
        'czerwiec'
        'lipiec'
        'sierpie'#324
        'wrzesie'#324
        'pa'#378'dziernik'
        'listopad'
        'grudze'#324)
    end
    object m_MiesDoCB: TComboBox
      Left = 207
      Top = 106
      Width = 83
      Height = 21
      DropDownCount = 12
      ItemIndex = 11
      TabOrder = 4
      Text = 'grudze'#324
      Items.Strings = (
        'stycze'#324
        'luty'
        'marzec'
        'kwiecie'#324
        'maj'
        'czerwiec'
        'lipiec'
        'sierpie'#324
        'wrzesie'#324
        'pa'#378'dziernik'
        'listopad'
        'grudze'#324)
    end
  end
  inherited paTop: TPanel
    Width = 416
    ExplicitWidth = 416
  end
  object m_WydzialDS: TDataSource
    Left = 128
    Top = 40
  end
  object m_WarDS: TDataSource
    Left = 200
    Top = 40
  end
end
