inherited _SlKomorkiEditFRM: T_SlKomorkiEditFRM
  Left = 461
  Top = 413
  ActiveControl = edKod
  Caption = 'Kom'#243'rki'
  ClientHeight = 146
  ClientWidth = 364
  ExplicitLeft = 461
  ExplicitTop = 413
  ExplicitWidth = 380
  ExplicitHeight = 183
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 113
    Width = 364
    ExplicitTop = 113
    ExplicitWidth = 364
    inherited m_CancelBB: TAdvSmoothButton
      Left = 220
      ExplicitLeft = 220
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 292
      ExplicitLeft = 292
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 364
    Height = 113
    ExplicitWidth = 364
    ExplicitHeight = 113
    object Label1: TLabel
      Left = 12
      Top = 12
      Width = 18
      Height = 13
      Caption = 'Kod'
      Transparent = True
    end
    object Label2: TLabel
      Left = 75
      Top = 12
      Width = 71
      Height = 13
      Caption = 'Nazwa kom'#243'rki'
      Transparent = True
    end
    object Label3: TLabel
      Left = 12
      Top = 56
      Width = 38
      Height = 13
      Caption = 'Wydzia'#322
      Transparent = True
    end
    object Label4: TLabel
      Left = 75
      Top = 56
      Width = 36
      Height = 13
      Caption = 'Oddzia'#322
      Transparent = True
    end
    object Label5: TLabel
      Left = 138
      Top = 56
      Width = 36
      Height = 13
      Caption = 'Telefon'
      Transparent = True
    end
    object Label6: TLabel
      Left = 273
      Top = 56
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object edKod: TDBEdit
      Left = 12
      Top = 28
      Width = 57
      Height = 21
      DataField = 'KOD'
      DataSource = m_DS
      TabOrder = 0
    end
    object DBEdit2: TDBEdit
      Left = 75
      Top = 28
      Width = 277
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_wCB: TDBLookupComboBox
      Left = 12
      Top = 72
      Width = 57
      Height = 21
      DataField = 'ID_WYDZIALU'
      DataSource = m_DS
      DropDownWidth = 340
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD;NAZWA'
      ListSource = m_wDS
      TabOrder = 2
    end
    object m_oCB: TDBLookupComboBox
      Left = 75
      Top = 72
      Width = 57
      Height = 21
      DataField = 'ID_ODDZIALU'
      DataSource = m_DS
      DropDownWidth = 280
      KeyField = 'ID_ODDZIALU'
      ListField = 'KOD;NAZWA'
      ListSource = m_oDS
      TabOrder = 3
    end
    object DBEdit3: TDBEdit
      Left = 138
      Top = 72
      Width = 129
      Height = 21
      DataField = 'TELEFON'
      DataSource = m_DS
      TabOrder = 4
    end
    object DBComboBox1: TDBComboBox
      Left = 273
      Top = 72
      Width = 79
      Height = 21
      DataField = 'WARSZTAT'
      DataSource = m_DS
      Items.Strings = (
        'Tak'
        'Nie')
      TabOrder = 5
    end
  end
  inherited m_DS: TDataSource
    Left = 8
    Top = 104
  end
  object m_wDS: TDataSource
    Left = 48
    Top = 104
  end
  object m_oDS: TDataSource
    Left = 88
    Top = 104
  end
end
