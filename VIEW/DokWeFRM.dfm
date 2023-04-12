object _DokWeFRM: T_DokWeFRM
  Left = 225
  Top = 221
  Caption = '_DokWeFRM'
  ClientHeight = 424
  ClientWidth = 664
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 664
    Height = 393
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
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alClient
    TabOrder = 0
    object m_SygnaturaLB: TLabel
      Left = 20
      Top = 12
      Width = 54
      Height = 13
      Caption = 'Sygnatura:'
      Transparent = True
    end
    object m_Uwagi1LB: TLabel
      Left = 20
      Top = 60
      Width = 42
      Height = 13
      Caption = 'Uwagi 1:'
      Transparent = True
    end
    object m_Uwagi2LB: TLabel
      Left = 342
      Top = 60
      Width = 42
      Height = 13
      Caption = 'Uwagi 2:'
      Transparent = True
    end
    object m_Uwagi3LB: TLabel
      Left = 20
      Top = 220
      Width = 42
      Height = 13
      Caption = 'Uwagi 3:'
      Transparent = True
    end
    object m_DokLB: TLabel
      Left = 168
      Top = 12
      Width = 89
      Height = 13
      Caption = 'Rodzaj dokumentu'
      Transparent = True
    end
    object Label1: TLabel
      Left = 545
      Top = 12
      Width = 85
      Height = 13
      Caption = 'Data wystawienia'
      Transparent = True
    end
    object m_SygnED: TDBEdit
      Left = 20
      Top = 31
      Width = 133
      Height = 21
      CharCase = ecUpperCase
      DataField = 'SYGNATURA'
      DataSource = m_DS
      TabOrder = 0
    end
    object m_Uwagi1ED: TDBMemo
      Left = 20
      Top = 79
      Width = 300
      Height = 130
      DataField = 'MEMO_1'
      DataSource = m_DS
      TabOrder = 3
    end
    object m_Uwagi2ED: TDBMemo
      Left = 342
      Top = 79
      Width = 300
      Height = 130
      DataField = 'MEMO_2'
      DataSource = m_DS
      TabOrder = 4
    end
    object m_Uwagi3ED: TDBMemo
      Left = 20
      Top = 239
      Width = 622
      Height = 130
      DataField = 'MEMO_3'
      DataSource = m_DS
      TabOrder = 5
    end
    object m_DokCB: TAdvDBLookupComboBox
      Left = 168
      Top = 31
      Width = 361
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
      TabOrder = 1
      OnKeyDown = m_DokCBKeyDown
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 300
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'NAZWA'
          Title = 'Nazwa'
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
          Width = 130
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'KOD'
          Name = 'KOD'
          Title = 'Kod'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_SLOW_DOK'
      DataSource = m_DS
      DropWidth = 439
      DropStretchColumn = -1
      DropHeight = 400
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      KeyField = 'ID_SLOW_DOK'
      ListSource = m_DokDS
      ReturnIsTab = True
      SortColumn = 'KOD'
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
      ShowGridTitleRow = True
      Version = '1.8.1.0'
    end
    object m_DataWystED: TAdvDBDateTimePicker
      Left = 545
      Top = 31
      Width = 97
      Height = 21
      Date = 40693.000000000000000000
      Time = 40693.000000000000000000
      ShowCheckbox = True
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 2
      BorderStyle = bsSingle
      Ctl3D = True
      DateTime = 40693.000000000000000000
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_WYST'
      DataSource = m_DS
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 393
    Width = 664
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
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      664
      31)
    object bbWrite: TAdvSmoothButton
      Left = 564
      Top = 4
      Width = 97
      Height = 25
      Anchors = [akTop, akRight]
      Status.Caption = '0'
      Status.Appearance.Fill.Color = clRed
      Status.Appearance.Fill.ColorMirror = clNone
      Status.Appearance.Fill.ColorMirrorTo = clNone
      Status.Appearance.Fill.GradientType = gtSolid
      Status.Appearance.Fill.BorderColor = clGray
      Status.Appearance.Fill.Rounding = 0
      Status.Appearance.Fill.ShadowOffset = 0
      Status.Appearance.Font.Charset = DEFAULT_CHARSET
      Status.Appearance.Font.Color = clWhite
      Status.Appearance.Font.Height = -11
      Status.Appearance.Font.Name = 'Tahoma'
      Status.Appearance.Font.Style = []
      Caption = 'Zapisz'
      Color = 16644337
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = bbWriteClick
    end
    object bbCancel: TAdvSmoothButton
      Left = 461
      Top = 3
      Width = 97
      Height = 25
      Anchors = [akTop, akRight]
      Status.Caption = '0'
      Status.Appearance.Fill.Color = clRed
      Status.Appearance.Fill.ColorMirror = clNone
      Status.Appearance.Fill.ColorMirrorTo = clNone
      Status.Appearance.Fill.GradientType = gtSolid
      Status.Appearance.Fill.BorderColor = clGray
      Status.Appearance.Fill.Rounding = 0
      Status.Appearance.Fill.ShadowOffset = 0
      Status.Appearance.Font.Charset = DEFAULT_CHARSET
      Status.Appearance.Font.Color = clWhite
      Status.Appearance.Font.Height = -11
      Status.Appearance.Font.Name = 'Tahoma'
      Status.Appearance.Font.Style = []
      Caption = 'Anuluj'
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      OnClick = bbCancelClick
    end
    object m_PrintBB: TAdvSmoothButton
      Left = 3
      Top = 3
      Width = 97
      Height = 25
      Anchors = [akTop, akRight]
      Status.Caption = '0'
      Status.Appearance.Fill.Color = clRed
      Status.Appearance.Fill.ColorMirror = clNone
      Status.Appearance.Fill.ColorMirrorTo = clNone
      Status.Appearance.Fill.GradientType = gtSolid
      Status.Appearance.Fill.BorderColor = clGray
      Status.Appearance.Fill.Rounding = 0
      Status.Appearance.Fill.ShadowOffset = 0
      Status.Appearance.Font.Charset = DEFAULT_CHARSET
      Status.Appearance.Font.Color = clWhite
      Status.Appearance.Font.Height = -11
      Status.Appearance.Font.Name = 'Tahoma'
      Status.Appearance.Font.Style = []
      Caption = 'Drukuj'
      Color = 16644337
      TabOrder = 2
      Version = '1.6.9.1'
      OnClick = m_PrintBBClick
    end
  end
  object m_DS: TDataSource
    Left = 424
    Top = 120
  end
  object m_DokDS: TDataSource
    OnDataChange = m_DokDSDataChange
    Left = 376
    Top = 120
  end
end
