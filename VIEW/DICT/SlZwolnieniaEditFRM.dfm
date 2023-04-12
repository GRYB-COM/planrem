inherited _SlZwolnieniaEditFRM: T_SlZwolnieniaEditFRM
  Left = 633
  Top = 597
  Caption = 'Zwolnienia'
  ClientHeight = 99
  ClientWidth = 293
  ExplicitWidth = 299
  ExplicitHeight = 124
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 66
    Width = 293
    ExplicitTop = 66
    inherited m_CancelBB: TAdvSmoothButton
      Left = 149
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 221
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 293
    Height = 66
    ExplicitHeight = 66
    object Label3: TLabel
      Left = 103
      Top = 12
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label1: TLabel
      Left = 220
      Top = 12
      Width = 46
      Height = 13
      Caption = 'Liczba dni'
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 12
      Width = 70
      Height = 13
      Caption = 'Kod zwolnienia'
      Transparent = True
    end
    object m_miesCB: TDBLookupComboBox
      Left = 103
      Top = 28
      Width = 111
      Height = 21
      DataField = 'NR_MIES'
      DataSource = m_DS
      DropDownRows = 13
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_miesDS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 220
      Top = 28
      Width = 61
      Height = 21
      DataField = 'LICZBA_DNI'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_zwCB: TDBLookupComboBox
      Left = 12
      Top = 28
      Width = 85
      Height = 21
      DataField = 'ID_SLOW_ZW'
      DataSource = m_DS
      DropDownWidth = 300
      KeyField = 'ID_SLOW_ZW'
      ListField = 'KOD;NAZWA'
      ListSource = m_zwDS
      TabOrder = 2
    end
  end
  inherited m_DS: TDataSource
    Top = 56
  end
  object m_zwDS: TDataSource
    Left = 76
    Top = 56
  end
  object m_miesDS: TDataSource
    Left = 128
    Top = 56
  end
end
