object _EditHarmFRM: T_EditHarmFRM
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Planowanie pracy warsztatu'
  ClientHeight = 412
  ClientWidth = 553
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
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 553
    Height = 381
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
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 12
      Top = 10
      Width = 42
      Height = 13
      Caption = 'Nr harm.'
      Transparent = True
    end
    object Label2: TLabel
      Left = 126
      Top = 10
      Width = 20
      Height = 13
      Caption = 'Plan'
      Transparent = True
    end
    object Label3: TLabel
      Left = 189
      Top = 10
      Width = 53
      Height = 13
      Caption = 'Rodz. rem.'
      Transparent = True
    end
    object Label4: TLabel
      Left = 256
      Top = 10
      Width = 47
      Height = 13
      Caption = 'Dostawca'
      Transparent = True
    end
    object Label5: TLabel
      Left = 473
      Top = 10
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 63
      Width = 50
      Height = 13
      Caption = 'Nr sprz'#281'tu'
      Transparent = True
    end
    object Label7: TLabel
      Left = 12
      Top = 219
      Width = 38
      Height = 13
      Caption = 'Zadanie'
      Transparent = True
    end
    object Label8: TLabel
      Left = 256
      Top = 63
      Width = 78
      Height = 13
      Caption = 'Planowane  RBH'
      Transparent = True
    end
    object Label9: TLabel
      Left = 155
      Top = 63
      Width = 87
      Height = 13
      Caption = 'Data dostarczenia'
      Transparent = True
    end
    object Label11: TLabel
      Left = 12
      Top = 116
      Width = 71
      Height = 13
      Caption = 'Nazwa sprz'#281'tu'
      Transparent = True
    end
    object Label12: TLabel
      Left = 411
      Top = 10
      Width = 54
      Height = 13
      Caption = 'Norma RBH'
      Transparent = True
    end
    object Label10: TLabel
      Left = 12
      Top = 167
      Width = 100
      Height = 13
      Caption = 'Planowana data zak.'
      Transparent = True
    end
    object Label13: TLabel
      Left = 72
      Top = 10
      Width = 18
      Height = 13
      Caption = 'Typ'
      Transparent = True
    end
    object Label14: TLabel
      Left = 33
      Top = 344
      Width = 203
      Height = 13
      Caption = 'Kontynuacja remontu z poprzedniego roku'
      Transparent = True
    end
    object m_NrHarmED: TDBEdit
      Left = 12
      Top = 27
      Width = 51
      Height = 21
      DataField = 'ID_HARMONOGRAMU'
      DataSource = m_HarmDS
      TabOrder = 0
    end
    object m_UslCB: TAdvDBLookupComboBox
      Left = 126
      Top = 27
      Width = 56
      Height = 21
      AutoSize = False
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
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 50
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'P_N'
          Name = 'P_N'
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
          Width = 300
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZ_REMONTU'
          Name = 'NAZ_REMONTU'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_USLUGI'
      DataSource = m_HarmDS
      DropWidth = 392
      DropStretchColumn = -1
      DropHeight = 260
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 15
      KeyField = 'ID_USLUGI'
      ListSource = m_UslDS
      SortColumn = 'P_N'
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
      Version = '1.8.1.0'
    end
    object m_RemCB: TAdvDBLookupComboBox
      Left = 189
      Top = 27
      Width = 53
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
      TabOrder = 3
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'KOD_REM'
          Name = 'KOD_REM'
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
          Width = 200
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'NAZWA'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_REMONTU'
      DataSource = m_HarmDS
      DropWidth = 305
      DropStretchColumn = -1
      DropHeight = 400
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 15
      KeyField = 'ID_REMONTU'
      ListSource = m_RemDS
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
      Version = '1.8.1.0'
    end
    object m_DostCB: TAdvDBLookupComboBox
      Left = 256
      Top = 27
      Width = 149
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
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'JW_MIEJSCOWOSC'
          Name = 'JW_MIEJSCOWOSC'
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
          Width = 50
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'JW'
          Name = 'JW'
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
          Width = 150
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'MIEJSCOWOSC'
          Name = 'MIEJSCOWOSC'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_JEDNOSTKI'
      DataSource = m_HarmDS
      DropWidth = 209
      DropStretchColumn = -1
      DropHeight = 450
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 15
      KeyField = 'ID_JEDNOSTKI'
      ListSource = m_JWDS
      SortColumn = 'JW'
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
      Version = '1.8.1.0'
    end
    object m_WarCB: TAdvDBLookupComboBox
      Left = 473
      Top = 27
      Width = 68
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
      TabOrder = 6
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 50
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'KOD'
          Name = 'KOD'
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
          Width = 450
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'NAZWA'
          Title = 'NAZWA'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_KOMORKI'
      DataSource = m_HarmDS
      DropWidth = 500
      DropStretchColumn = -1
      DropHeight = 400
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridRowHeight = 15
      KeyField = 'ID_KOMORKI'
      ListSource = m_WarDS
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
      ShowGridTitleRow = False
      Version = '1.8.1.0'
    end
    object m_NrSprzED: TDBEdit
      Left = 12
      Top = 82
      Width = 130
      Height = 21
      DataField = 'NR_ZADANIA'
      DataSource = m_HarmDS
      TabOrder = 7
    end
    object m_RBHGR: TDBGrid
      Left = 258
      Top = 82
      Width = 209
      Height = 255
      TabStop = False
      DataSource = m_HarmDetDS
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 14
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnDblClick = m_EditBTClick
      Columns = <
        item
          Expanded = False
          FieldName = 'NAZ_MIES'
          Title.Caption = 'Miesi'#261'c'
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ILOSC'
          Title.Caption = 'Ilo'#347#263' sprz'#281'tu'
          Width = 70
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PLAN_RBH'
          Title.Alignment = taCenter
          Title.Caption = 'RBH'
          Width = 40
          Visible = True
        end>
    end
    object m_ZadanieED: TDBMemo
      Left = 12
      Top = 240
      Width = 230
      Height = 97
      DataField = 'ZADANIE'
      DataSource = m_HarmDS
      TabOrder = 10
    end
    object m_DataOdED: TAdvDBDateTimePicker
      Left = 155
      Top = 82
      Width = 87
      Height = 21
      Date = 40693.000000000000000000
      Time = 40693.000000000000000000
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 8
      BorderStyle = bsSingle
      Ctl3D = True
      DateTime = 40693.000000000000000000
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_OD'
      DataSource = m_HarmDS
    end
    object m_NazSprzED: TAdvDBLookupComboBox
      Left = 12
      Top = 133
      Width = 230
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
      TabOrder = 9
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 290
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'NAZWA'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_SPRZETU'
      DataSource = m_HarmDS
      DropWidth = 300
      DropStretchColumn = -1
      DropHeight = 410
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 14
      KeyField = 'ID_SPRZETU'
      ListSource = m_SprzetDS
      SortColumn = 'NAZWA'
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
      Version = '1.8.1.0'
    end
    object m_AddBT: TAdvSmoothButton
      Left = 471
      Top = 80
      Width = 68
      Height = 20
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
      Caption = 'Dodaj'
      Color = 16312013
      TabOrder = 11
      Version = '1.6.9.1'
      OnClick = m_AddBTClick
    end
    object m_EditBT: TAdvSmoothButton
      Left = 473
      Top = 106
      Width = 68
      Height = 20
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
      Caption = 'Zmie'#324
      Color = 16312013
      TabOrder = 12
      Version = '1.6.9.1'
      OnClick = m_EditBTClick
    end
    object m_DelBT: TAdvSmoothButton
      Left = 473
      Top = 132
      Width = 68
      Height = 20
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
      Caption = 'Usu'#324
      Color = 16312013
      TabOrder = 13
      Version = '1.6.9.1'
      OnClick = m_DelBTClick
    end
    object m_NormaRBHED: TDBEdit
      Left = 413
      Top = 29
      Width = 54
      Height = 21
      DataField = 'NORMA_RBH'
      DataSource = m_HarmDS
      TabOrder = 5
    end
    object m_DataDoED: TAdvDBDateTimePicker
      Left = 12
      Top = 186
      Width = 100
      Height = 21
      Date = 40693.000000000000000000
      Time = 40693.000000000000000000
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 15
      BorderStyle = bsSingle
      Ctl3D = True
      DateTime = 40693.000000000000000000
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_DO'
      DataSource = m_HarmDS
    end
    object m_TypCB: TAdvDBLookupComboBox
      Left = 71
      Top = 27
      Width = 46
      Height = 21
      AutoSize = False
      DropDownType = ddAuto
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
      OnExit = clearIfEmpty
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 20
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'TYP'
          Name = 'TYP'
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
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZWA'
          Name = 'NAZWA'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'TYP'
      DataSource = m_HarmDS
      DropWidth = 150
      DropStretchColumn = -1
      DropHeight = 55
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      DropSorted = True
      DropSizeable = True
      GridLines = False
      GridColumnSize = False
      GridRowHeight = 15
      KeyField = 'TYP'
      ListSource = m_TypyDS
      SortColumn = 'P_N'
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
      Version = '1.8.1.0'
    end
    object m_CountRBHBT: TAdvSmoothButton
      Left = 472
      Top = 186
      Width = 74
      Height = 21
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
      Caption = 'Przelicz RBH'
      Color = 16312013
      TabOrder = 16
      Version = '1.6.9.1'
      OnClick = m_CountRBHBTClick
    end
    object m_KontCB: TDBCheckBox
      Left = 12
      Top = 343
      Width = 15
      Height = 17
      Color = 15133375
      DataField = 'KONT'
      DataSource = m_HarmDS
      ParentColor = False
      TabOrder = 17
      ValueChecked = 'T'
      ValueUnchecked = 'N'
    end
  end
  object AdvSmoothPanel2: TAdvSmoothPanel
    Left = 0
    Top = 381
    Width = 553
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
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      553
      31)
    object m_CancelBT: TAdvSmoothButton
      Left = 397
      Top = 6
      Width = 68
      Height = 20
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
      ModalResult = 2
      OnClick = m_CancelBTClick
    end
    object m_SaveBT: TAdvSmoothButton
      Left = 471
      Top = 6
      Width = 68
      Height = 20
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
      OnClick = m_SaveBTClick
    end
  end
  object m_HarmDS: TDataSource
    Left = 8
    Top = 360
  end
  object m_UslDS: TDataSource
    Left = 64
    Top = 360
  end
  object m_RemDS: TDataSource
    Left = 112
    Top = 360
  end
  object m_JWDS: TDataSource
    Left = 168
    Top = 360
  end
  object m_WarDS: TDataSource
    Left = 224
    Top = 360
  end
  object m_HarmDetDS: TDataSource
    Left = 344
    Top = 144
  end
  object m_SprzetDS: TDataSource
    Left = 288
    Top = 360
  end
  object m_TypyCD: TClientDataSet
    Active = True
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'TYP'
        Attributes = [faUnNamed]
        DataType = ftString
        Size = 1
      end
      item
        Name = 'NAZWA'
        Attributes = [faUnNamed]
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 352
    Top = 360
    Data = {
      720000009619E0BD0100000018000000020002000000030000004C0003545950
      0100490010000100055749445448020002000100054E415A5741010049001000
      010005574944544802000200140000000400014A0E4A65646E6F706F7A796379
      6A6E79040001570E5769656C6F706F7A7963796A6E79}
  end
  object m_TypyDS: TDataSource
    DataSet = m_TypyCD
    Left = 408
    Top = 360
  end
end
