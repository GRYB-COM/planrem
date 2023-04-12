inherited _SlSzkoleniaEditFRM: T_SlSzkoleniaEditFRM
  Left = 923
  Top = 168
  ActiveControl = m_miesCB
  Caption = 'Szkolenia'
  ClientHeight = 100
  ClientWidth = 237
  ExplicitLeft = 923
  ExplicitTop = 168
  ExplicitWidth = 253
  ExplicitHeight = 137
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
    object Label3: TLabel
      Left = 12
      Top = 12
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label1: TLabel
      Left = 155
      Top = 12
      Width = 38
      Height = 13
      Caption = 'Godziny'
      Transparent = True
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
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 155
      Top = 28
      Width = 69
      Height = 21
      DataField = 'RBH'
      DataSource = m_DS
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
