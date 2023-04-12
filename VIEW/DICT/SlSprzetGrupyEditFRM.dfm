inherited _SlSprzetGrupyEditFRM: T_SlSprzetGrupyEditFRM
  Left = 471
  Top = 404
  ActiveControl = edNazwa
  Caption = '_SlSprzetGrupyEditFRM'
  ClientHeight = 100
  ClientWidth = 304
  ExplicitLeft = 471
  ExplicitTop = 404
  ExplicitWidth = 320
  ExplicitHeight = 137
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 67
    Width = 304
    ExplicitTop = 67
    ExplicitWidth = 321
    inherited m_CancelBB: TAdvSmoothButton
      Left = 160
      ExplicitLeft = 177
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 232
      ExplicitLeft = 249
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 304
    Height = 67
    ExplicitWidth = 321
    ExplicitHeight = 67
    object Label2: TLabel
      Left = 12
      Top = 12
      Width = 63
      Height = 13
      Caption = 'Nazwa grupy'
      Transparent = True
    end
    object edNazwa: TDBEdit
      Left = 12
      Top = 28
      Width = 280
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 0
    end
  end
  inherited m_DS: TDataSource
    Left = 23
    Top = 59
  end
end
