inherited _PlanKwartWybFRM: T_PlanKwartWybFRM
  Caption = 'Plan kwartalny'
  ClientHeight = 161
  ClientWidth = 292
  OnClose = FormClose
  OnShow = FormShow
  ExplicitWidth = 298
  ExplicitHeight = 186
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 120
    Width = 292
    ExplicitTop = 120
    ExplicitWidth = 292
    inherited bbCancel: TBitBtn
      Left = 131
      ExplicitLeft = 131
    end
    inherited bbWrite: TBitBtn
      Left = 207
      ExplicitLeft = 207
    end
  end
  inherited paMain: TPanel
    Width = 292
    Height = 119
    ExplicitWidth = 292
    ExplicitHeight = 119
    object m_RokLB: TLabel
      Left = 10
      Top = 47
      Width = 20
      Height = 13
      Caption = 'Rok'
      Transparent = True
    end
    object m_WarLB: TLabel
      Left = 9
      Top = 3
      Width = 42
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_MiesOdLB: TLabel
      Left = 102
      Top = 45
      Width = 51
      Height = 13
      Caption = 'Miesi'#261'c od'
      Transparent = True
    end
    object m_MiesDoLB: TLabel
      Left = 198
      Top = 45
      Width = 51
      Height = 13
      Caption = 'Miesi'#261'c do'
      Transparent = True
    end
    object m_RokED: TEdit
      Left = 10
      Top = 62
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
      TabOrder = 0
      Text = 'm_RokED'
    end
    object m_WarCB: TDBLookupComboBox
      Left = 9
      Top = 18
      Width = 272
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
      Left = 102
      Top = 64
      Width = 83
      Height = 21
      ItemIndex = 0
      TabOrder = 2
      Text = 'stycze'#324
      OnCloseUp = m_MiesOdCBCloseUp
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
      Left = 198
      Top = 64
      Width = 83
      Height = 21
      ItemIndex = 11
      TabOrder = 3
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
    Width = 292
    ExplicitWidth = 292
  end
  object m_WarDS: TDataSource
    Left = 16
    Top = 104
  end
end
