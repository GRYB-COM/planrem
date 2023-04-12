inherited _SlKadraFRM: T_SlKadraFRM
  Left = 689
  Top = 290
  Caption = 'Kadra'
  ClientHeight = 147
  ClientWidth = 466
  ExplicitWidth = 472
  ExplicitHeight = 172
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 114
    Width = 466
    ExplicitTop = 114
    ExplicitWidth = 466
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 322
      ExplicitLeft = 322
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 394
      ExplicitLeft = 394
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 466
    Height = 114
    ExplicitWidth = 466
    ExplicitHeight = 114
    inherited m_DBG: TDBGrid
      Width = 466
      Height = 114
      Columns = <
        item
          Expanded = False
          FieldName = 'KOD'
          Title.Caption = 'Kod'
          Width = 40
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa'
          Width = 72
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PELNA_NAZWA'
          Title.Caption = 'Pe'#322'na nazwa'
          Width = 120
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'URLOP'
          Title.Caption = 'Urlop'
          Width = -1
          Visible = False
        end
        item
          Expanded = False
          FieldName = 'PRZERWA'
          Title.Caption = 'Przerwa'
          Width = 48
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SLUZBA'
          Title.Caption = 'S'#322'u'#380'ba'
          Width = 48
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CHOROBA'
          Title.Caption = 'Choroba'
          Width = 48
          Visible = True
        end>
    end
  end
  inherited m_DS: TDataSource
    Left = 32
    Top = 64
  end
end
