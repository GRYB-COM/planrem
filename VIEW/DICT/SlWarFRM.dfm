inherited _SlWarFRM: T_SlWarFRM
  Left = 398
  Top = 175
  ExplicitLeft = 398
  ExplicitTop = 175
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited m_DBG: TDBGrid
      Height = 377
      Align = alNone
      Columns = <
        item
          Expanded = False
          FieldName = 'KOD'
          Title.Caption = 'Warsztat'
          Width = 97
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa'
          Width = 490
          Visible = True
        end>
    end
  end
  inherited m_BottomASP: TAdvSmoothPanel
    inherited m_EdytujBB: TAdvSmoothButton
      Visible = True
      Enabled = True
    end
    inherited m_UsunBB: TAdvSmoothButton
      Visible = True
      Enabled = True
    end
  end
end
