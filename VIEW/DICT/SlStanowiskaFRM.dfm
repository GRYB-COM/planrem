inherited _SlStanowiskaFRM: T_SlStanowiskaFRM
  Left = 508
  Top = 222
  Caption = 'S'#322'ownik stanowisk'
  ClientWidth = 470
  ExplicitWidth = 476
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 470
    ExplicitWidth = 386
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 326
      ExplicitLeft = 242
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 398
      ExplicitLeft = 314
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 470
    ExplicitWidth = 386
    inherited m_DBG: TDBGrid
      Width = 470
      Columns = <
        item
          Expanded = False
          FieldName = 'KOD'
          Title.Caption = 'Kod'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa stanowiska'
          Width = 300
          Visible = True
        end>
    end
  end
end
