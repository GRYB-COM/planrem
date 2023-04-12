inherited _SlKomorkiFRM: T_SlKomorkiFRM
  Left = 472
  Top = 216
  Caption = 'S'#322'ownik kom'#243'rek'
  ClientWidth = 656
  ExplicitLeft = 472
  ExplicitTop = 216
  ExplicitWidth = 672
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 656
    ExplicitWidth = 656
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 512
      ExplicitLeft = 512
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 584
      ExplicitLeft = 584
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 656
    ExplicitWidth = 656
    inherited m_DBG: TDBGrid
      Width = 656
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
          Title.Caption = 'Nazwa kom'#243'rki'
          Width = 300
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'KOD_WYD'
          Title.Caption = 'Kod wydzia'#322'u'
          Width = 70
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'KOD_ODD'
          Title.Caption = 'Kod oddzia'#322'u'
          Width = 70
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'TELEFON'
          Title.Caption = 'Telefon'
          Width = 76
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'WARSZTAT'
          Title.Caption = 'Warsztat'
          Width = 50
          Visible = True
        end>
    end
  end
end
