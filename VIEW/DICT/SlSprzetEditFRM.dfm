inherited _SlSprzetEditFRM: T_SlSprzetEditFRM
  Left = 418
  Top = 355
  Caption = 'Sprz'#281't'
  ClientHeight = 143
  ClientWidth = 516
  ExplicitWidth = 522
  ExplicitHeight = 168
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 110
    Width = 516
    ExplicitTop = 110
    ExplicitWidth = 516
    inherited m_CancelBB: TAdvSmoothButton
      Left = 372
      ExplicitLeft = 372
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 444
      ExplicitLeft = 444
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 516
    Height = 110
    ExplicitWidth = 516
    ExplicitHeight = 110
    object Label2: TLabel
      Left = 12
      Top = 12
      Width = 71
      Height = 13
      Caption = 'Nazwa sprz'#281'tu'
      Transparent = True
    end
    object Label5: TLabel
      Left = 418
      Top = 12
      Width = 86
      Height = 13
      Caption = 'Warsztat wiod'#261'cy'
      Transparent = True
    end
    object Label3: TLabel
      Left = 268
      Top = 56
      Width = 72
      Height = 13
      Caption = 'Rodzaj sprz'#281'tu'
      Transparent = True
    end
    object Label1: TLabel
      Left = 12
      Top = 55
      Width = 68
      Height = 13
      Caption = 'Grupa sprz'#281'tu'
      Transparent = True
    end
    object Label4: TLabel
      Left = 318
      Top = 10
      Width = 94
      Height = 13
      Caption = 'Indeks materia'#322'owy'
      Transparent = True
    end
    object DBEdit2: TDBEdit
      Left = 12
      Top = 28
      Width = 300
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 0
    end
    object m_komCB: TAdvDBLookupComboBox
      Left = 418
      Top = 28
      Width = 86
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
          Width = 32
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
          Width = 245
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
      DataField = 'ID_KOMORKI'
      DataSource = m_DS
      DropWidth = 299
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
      KeyField = 'ID_KOMORKI'
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
      Left = 12
      Top = 72
      Width = 250
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
      TabOrder = 3
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 30
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'ID_GR_SPRZ'
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
          Width = 247
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
      DataField = 'ID_GR_SPRZ'
      DataSource = m_DS
      DropWidth = 299
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
      Left = 268
      Top = 72
      Width = 236
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
      TabOrder = 4
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 30
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'ID_RODZ_SPRZ'
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
          Width = 247
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
      DataField = 'ID_RODZ_SPRZ'
      DataSource = m_DS
      DropWidth = 299
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
    object DBEdit1: TDBEdit
      Left = 318
      Top = 29
      Width = 94
      Height = 21
      DataField = 'INDEKS_MAT'
      DataSource = m_DS
      TabOrder = 1
    end
  end
  inherited m_DS: TDataSource
    Left = 10
    Top = 192
  end
  object m_komDS: TDataSource
    Left = 54
    Top = 192
  end
  object m_rspDS: TDataSource
    Left = 101
    Top = 192
  end
  object m_gspDS: TDataSource
    Left = 148
    Top = 192
  end
end
