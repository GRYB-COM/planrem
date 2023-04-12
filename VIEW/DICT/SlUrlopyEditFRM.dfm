inherited _SlUrlopyEditFRM: T_SlUrlopyEditFRM
  Left = 718
  Top = 177
  ActiveControl = m_miesCB
  Caption = 'Urlopy'
  ClientHeight = 100
  ClientWidth = 237
  ExplicitWidth = 243
  ExplicitHeight = 125
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 67
    Width = 237
    ExplicitTop = 67
    ExplicitWidth = 237
    inherited m_CancelBB: TAdvSmoothButton
      Left = 93
      ExplicitLeft = 93
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 165
      ExplicitLeft = 165
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 237
    Height = 67
    ExplicitWidth = 237
    ExplicitHeight = 67
    object Label1: TLabel
      Left = 155
      Top = 12
      Width = 25
      Height = 13
      Caption = 'Urlop'
      Transparent = True
    end
    object Label3: TLabel
      Left = 12
      Top = 12
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object DBEdit1: TDBEdit
      Left = 155
      Top = 28
      Width = 69
      Height = 21
      DataField = 'URLOP'
      DataSource = m_DS
      TabOrder = 0
    end
    object m_miesCB: TDBLookupComboBox
      Left = 12
      Top = 28
      Width = 137
      Height = 21
      DataField = 'NR_MIES'
      DataSource = m_DS
      DropDownRows = 13
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_miesDS
      TabOrder = 1
    end
  end
  inherited m_DS: TDataSource
    Left = 8
    Top = 56
  end
  object m_miesDS: TDataSource
    Left = 56
    Top = 56
  end
end
