inherited _SlSprzetGrupyFRM: T_SlSprzetGrupyFRM
  Left = 645
  Top = 275
  Caption = 'Grupy sprz'#281'tu'
  ClientWidth = 507
  ExplicitWidth = 513
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 507
    ExplicitWidth = 386
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 363
      ExplicitLeft = 242
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 435
      ExplicitLeft = 314
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 507
    ExplicitWidth = 386
    inherited m_DBG: TDBGrid
      Width = 507
      Columns = <
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
          Title.Caption = 'Nazwa grupy'
          Width = 300
          Visible = True
        end>
    end
  end
end
