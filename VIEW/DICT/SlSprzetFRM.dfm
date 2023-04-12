inherited _SlSprzetFRM: T_SlSprzetFRM
  Left = 679
  Top = 147
  Caption = 'S'#322'ownik sprz'#281'tu'
  ClientHeight = 523
  ClientWidth = 670
  ExplicitWidth = 676
  ExplicitHeight = 548
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 490
    Width = 670
    ExplicitTop = 490
    ExplicitWidth = 670
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 527
      ExplicitLeft = 527
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 599
      ExplicitLeft = 599
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Top = 109
    Width = 670
    Height = 381
    ExplicitTop = 109
    ExplicitWidth = 670
    ExplicitHeight = 381
    inherited m_DBG: TDBGrid
      Width = 670
      Height = 381
      Columns = <
        item
          Expanded = False
          FieldName = 'KOD'
          Title.Caption = 'Warsztat'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'INDEKS_MAT'
          Title.Caption = 'Indeks materia'#322'owy'
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa sprz'#281'tu'
          Width = 220
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'RODZAJ'
          Title.Caption = 'Rodzaj sprz'#281'tu'
          Width = 260
          Visible = True
        end>
    end
  end
  object m_TopPA: TAdvSmoothPanel [2]
    Left = 0
    Top = 0
    Width = 670
    Height = 109
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
      Left = 14
      Top = 11
      Width = 86
      Height = 13
      Caption = 'Warsztat wiod'#261'cy'
      Transparent = True
    end
    object Label2: TLabel
      Left = 14
      Top = 55
      Width = 71
      Height = 13
      Caption = 'Nazwa sprz'#281'tu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 285
      Top = 11
      Width = 68
      Height = 13
      Caption = 'Grupa sprz'#281'tu'
      Transparent = True
    end
    object Label4: TLabel
      Left = 285
      Top = 55
      Width = 72
      Height = 13
      Caption = 'Rodzaj sprz'#281'tu'
      Transparent = True
    end
    object m_JIMFltLB: TLabel
      Left = 539
      Top = 9
      Width = 110
      Height = 13
      Caption = 'Indeks materia'#322'owy'
      Transparent = True
    end
    object m_edFiltr: TEdit
      Left = 14
      Top = 72
      Width = 265
      Height = 21
      TabOrder = 3
      OnChange = m_edFiltrChange
    end
    object m_komCB: TAdvDBLookupComboBox
      Left = 14
      Top = 28
      Width = 265
      Height = 21
      Enabled = True
      LabelPosition = lpLeftTop
      LabelMargin = 4
      LabelTransparent = False
      LabelAlwaysEnabled = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      LabelWidth = 0
      LookupColumn = 1
      LookupMethod = lmNormal
      LookupLoad = llAlways
      TabOrder = 0
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 34
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'KOD'
          Name = 'Column0'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 250
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'Column1'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DropWidth = 306
      DropStretchColumn = -1
      DropHeight = 196
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 16
      GridHeaderHeight = 20
      KeyField = 'KOD'
      ListSource = m_komDS
      SortUpGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080008080
        8000808080008080800080808000808080008080800080808000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000}
      SortDownGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00808080008080
        8000808080008080800080808000808080008080800080808000}
      ShowGridTitleRow = False
      OnCloseUp = m_komCBCloseUp
      Version = '1.8.1.0'
    end
    object m_gspCB: TAdvDBLookupComboBox
      Left = 285
      Top = 28
      Width = 245
      Height = 21
      Enabled = True
      LabelPosition = lpLeftTop
      LabelMargin = 4
      LabelTransparent = False
      LabelAlwaysEnabled = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      LabelWidth = 0
      LookupColumn = 0
      LookupMethod = lmNormal
      LookupLoad = llAlways
      TabOrder = 2
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 256
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'Column0'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DropWidth = 260
      DropStretchColumn = -1
      DropHeight = 196
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 16
      KeyField = 'ID_GR_SPRZ'
      ListSource = m_gspDS
      SortUpGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080008080
        8000808080008080800080808000808080008080800080808000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000}
      SortDownGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00808080008080
        8000808080008080800080808000808080008080800080808000}
      ShowGridTitleRow = False
      OnCloseUp = m_gspCBCloseUp
      Version = '1.8.1.0'
    end
    object m_rspCB: TAdvDBLookupComboBox
      Left = 285
      Top = 72
      Width = 245
      Height = 21
      Enabled = True
      LabelPosition = lpLeftTop
      LabelMargin = 4
      LabelTransparent = False
      LabelAlwaysEnabled = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      LabelWidth = 0
      LookupColumn = 0
      LookupMethod = lmNormal
      LookupLoad = llAlways
      TabOrder = 4
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 256
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'Column0'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DropWidth = 260
      DropStretchColumn = -1
      DropHeight = 196
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 16
      KeyField = 'ID_RODZ_SPRZ'
      ListSource = m_rspDS
      SortUpGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080008080
        8000808080008080800080808000808080008080800080808000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000}
      SortDownGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00808080008080
        8000808080008080800080808000808080008080800080808000}
      ShowGridTitleRow = False
      OnCloseUp = m_rspCBCloseUp
      Version = '1.8.1.0'
    end
    object m_JIMFltED: TEdit
      Left = 539
      Top = 28
      Width = 122
      Height = 21
      NumbersOnly = True
      TabOrder = 1
      OnChange = m_JIMFltEDChange
    end
  end
  inherited m_DS: TDataSource
    Left = 77
    Top = 170
  end
  object m_komDS: TDataSource
    Left = 255
    Top = 169
  end
  object m_gspDS: TDataSource
    Left = 310
    Top = 169
  end
  object m_rspDS: TDataSource
    Left = 365
    Top = 169
  end
end
