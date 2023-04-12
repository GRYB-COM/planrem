inherited _SlStanowiskaEditFRM: T_SlStanowiskaEditFRM
  Left = 387
  Top = 390
  ActiveControl = edKod
  Caption = 'Stanowiska'
  ClientHeight = 100
  ClientWidth = 319
  ExplicitLeft = 387
  ExplicitTop = 390
  ExplicitWidth = 335
  ExplicitHeight = 137
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 67
    Width = 319
    ExplicitTop = 67
    ExplicitWidth = 319
    inherited m_CancelBB: TAdvSmoothButton
      Left = 175
      ExplicitLeft = 175
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 247
      ExplicitLeft = 247
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 319
    Height = 67
    ExplicitWidth = 319
    ExplicitHeight = 67
    object Label1: TLabel
      Left = 12
      Top = 12
      Width = 18
      Height = 13
      Caption = 'Kod'
      Transparent = True
    end
    object Label2: TLabel
      Left = 68
      Top = 12
      Width = 88
      Height = 13
      Caption = 'Nazwa stanowiska'
      Transparent = True
    end
    object edKod: TDBEdit
      Left = 12
      Top = 28
      Width = 50
      Height = 21
      DataField = 'KOD'
      DataSource = m_DS
      TabOrder = 0
    end
    object DBEdit2: TDBEdit
      Left = 68
      Top = 28
      Width = 240
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
  end
  inherited m_DS: TDataSource
    Top = 56
  end
end
