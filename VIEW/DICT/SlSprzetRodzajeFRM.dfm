inherited _SlSprzetRodzajeFRM: T_SlSprzetRodzajeFRM
  Left = 919
  Top = 173
  Caption = 'Rodzaje sprz'#281'tu'
  ClientWidth = 493
  ExplicitWidth = 499
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 493
    ExplicitWidth = 419
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 349
      ExplicitLeft = 275
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 421
      ExplicitLeft = 347
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 493
    ExplicitWidth = 419
    inherited m_DBG: TDBGrid
      Width = 493
      Columns = <
        item
          Expanded = False
          FieldName = 'ID_RODZ_SPRZ'
          Title.Caption = 'ID'
          Width = 32
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ID_GR_SPRZ'
          Title.Caption = 'ID grupy'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa'
          Width = 300
          Visible = True
        end>
    end
  end
end
