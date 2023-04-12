inherited _SlStanFRM: T_SlStanFRM
  Left = 514
  Top = 174
  Caption = 'Stanowiska'
  ClientWidth = 575
  ExplicitLeft = 514
  ExplicitTop = 174
  ExplicitWidth = 591
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    Width = 575
    inherited m_DBG: TDBGrid
      Width = 575
      Columns = <
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Alignment = taCenter
          Title.Caption = 'Stanowisko'
          Width = 468
          Visible = True
        end>
    end
  end
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 575
    inherited m_EdytujBB: TAdvSmoothButton
      Enabled = True
    end
    inherited m_UsunBB: TAdvSmoothButton
      Left = 77
      Enabled = True
      ExplicitLeft = 77
    end
  end
end
