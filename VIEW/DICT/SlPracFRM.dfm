inherited _SlPracFRM: T_SlPracFRM
  Caption = 'Pracownicy'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    Top = 31
    Height = 517
    ExplicitTop = 31
    ExplicitHeight = 517
    inherited m_DBG: TDBGrid
      Height = 517
      Columns = <
        item
          Expanded = False
          FieldName = 'NAZWISKO'
          Title.Caption = 'Nazwisko'
          Width = 188
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IMIE'
          Title.Caption = 'Imi'#281
          Width = 186
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
  object AdvSmoothPanel1: TAdvSmoothPanel [2]
    Left = 0
    Top = 0
    Width = 591
    Height = 31
    Cursor = crDefault
    Caption.HTMLFont.Charset = DEFAULT_CHARSET
    Caption.HTMLFont.Color = clWindowText
    Caption.HTMLFont.Height = -11
    Caption.HTMLFont.Name = 'Tahoma'
    Caption.HTMLFont.Style = []
    Caption.Font.Charset = DEFAULT_CHARSET
    Caption.Font.Color = clWindowText
    Caption.Font.Height = -16
    Caption.Font.Name = 'Tahoma'
    Caption.Font.Style = []
    Caption.ColorStart = clBlack
    Caption.ColorEnd = clBlack
    Caption.LineColor = 13542013
    Fill.Color = 16575452
    Fill.ColorTo = 16571329
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 13542013
    Fill.BorderWidth = 0
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alTop
    TabOrder = 2
    object Label1: TLabel
      Left = 3
      Top = 9
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_WarCB: TDBLookupComboBox
      Left = 53
      Top = 4
      Width = 484
      Height = 21
      DropDownRows = 30
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarDS
      NullValueKey = 46
      TabOrder = 0
      OnCloseUp = m_WarCBCloseUp
    end
  end
  object m_WarDS: TDataSource
    Left = 72
    Top = 96
  end
end
