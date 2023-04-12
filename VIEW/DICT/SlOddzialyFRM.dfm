inherited _SlOddzialyFRM: T_SlOddzialyFRM
  Left = 721
  Top = 334
  Caption = 'S'#322'ownik oddzia'#322#243'w'
  ClientWidth = 474
  ExplicitWidth = 480
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 474
    ExplicitWidth = 386
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 330
      ExplicitLeft = 242
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 402
      ExplicitLeft = 314
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 474
    ExplicitWidth = 386
    inherited m_DBG: TDBGrid
      Width = 474
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
          Title.Caption = 'Nazwa oddzia'#322'u'
          Width = 300
          Visible = True
        end>
    end
  end
end
