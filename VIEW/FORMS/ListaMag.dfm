object _ListaMagFRM: T_ListaMagFRM
  Left = 0
  Top = 0
  Caption = '_ListaMagFRM'
  ClientHeight = 429
  ClientWidth = 788
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  inline m_ListaMAgFRA: T_ListaMAGFRA
    Left = 0
    Top = 0
    Width = 788
    Height = 429
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 788
    inherited AdvSmoothPanel1: TAdvSmoothPanel
      Width = 788
      ExplicitTop = 394
      ExplicitWidth = 788
      DesignSize = (
        788
        29)
      inherited AdvSmoothButton1: TAdvSmoothButton
        Left = 717
        ExplicitLeft = 717
      end
    end
    inherited m_TopP: TAdvSmoothPanel
      Width = 788
      ExplicitWidth = 788
      ExplicitHeight = 239
      inherited m_AG: TDBAdvGrid
        Width = 788
        ExplicitWidth = 788
        ExplicitHeight = 239
      end
    end
    inherited AdvSmoothPanel2: TAdvSmoothPanel
      Width = 788
      ExplicitWidth = 788
      DesignSize = (
        788
        81)
    end
  end
end
