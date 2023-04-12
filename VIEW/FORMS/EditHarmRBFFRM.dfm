object _EditHarmRBFFRM: T_EditHarmRBFFRM
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Ilo'#347#263' i roboczogodziny'
  ClientHeight = 275
  ClientWidth = 309
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object m_MiesGR: TDBGrid
    Left = 0
    Top = 0
    Width = 213
    Height = 244
    Align = alLeft
    BorderStyle = bsNone
    Color = clInfoBk
    Ctl3D = False
    DataSource = m_RBHDS
    DrawingStyle = gdsGradient
    Enabled = False
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [dgEditing, dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = m_MiesGRDrawColumnCell
    Columns = <
      item
        Expanded = False
        FieldName = 'NAZ_MIES'
        Title.Caption = 'Miesi'#261'c'
        Width = 55
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'BILANS'
        Title.Alignment = taRightJustify
        Title.Caption = 'Dost'#281'pne RBH'
        Width = 80
        Visible = True
      end>
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 244
    Width = 309
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
    TabOrder = 2
    DesignSize = (
      309
      31)
    object AdvSmoothButton1: TAdvSmoothButton
      Left = 162
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
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = AdvSmoothButton1Click
    end
    object AdvSmoothButton4: TAdvSmoothButton
      Left = 236
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
      TabOrder = 1
      Version = '1.6.9.1'
      OnClick = AdvSmoothButton4Click
    end
  end
  object AdvSmoothPanel2: TAdvSmoothPanel
    Left = 139
    Top = 0
    Width = 170
    Height = 244
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
    Align = alRight
    TabOrder = 0
    object Label1: TLabel
      Left = 11
      Top = 73
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label2: TLabel
      Left = 11
      Top = 129
      Width = 61
      Height = 13
      Caption = 'Ilo'#347#263' sprz'#281'tu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 11
      Top = 189
      Width = 101
      Height = 13
      Caption = 'Liczba roboczogodzin'
      Transparent = True
    end
    object Label5: TLabel
      Left = 11
      Top = 15
      Width = 54
      Height = 13
      Caption = 'Norma RBH'
      Transparent = True
    end
    object Label4: TLabel
      Left = 81
      Top = 36
      Width = 4
      Height = 13
      Caption = '-'
      Transparent = True
      Visible = False
    end
    object m_MiesCB: TDBLookupComboBox
      Left = 11
      Top = 92
      Width = 145
      Height = 21
      DataField = 'MIESIAC'
      DataSource = m_HarmDetDS
      DropDownRows = 12
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_RBHDS
      TabOrder = 0
    end
    object m_IloscED: TDBEdit
      Left = 11
      Top = 148
      Width = 145
      Height = 21
      DataField = 'ILOSC'
      DataSource = m_HarmDetDS
      TabOrder = 1
    end
    object m_RBHED: TDBEdit
      Left = 11
      Top = 208
      Width = 145
      Height = 21
      DataField = 'PLAN_RBH'
      DataSource = m_HarmDetDS
      TabOrder = 2
      OnChange = m_RBHEDChange
    end
    object m_DataOdED: TDBEdit
      Left = 11
      Top = 34
      Width = 61
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NORMA_RBH'
      DataSource = m_HarmDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 3
    end
    object m_DataDO: TDBEdit
      Left = 94
      Top = 34
      Width = 62
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'DATA_DO'
      DataSource = m_HarmDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 4
      Visible = False
    end
  end
  object m_RBHCD: TClientDataSet
    Aggregates = <>
    Filter = 'NR_MIES >0'
    Filtered = True
    FieldDefs = <
      item
        Name = 'NR_MIES'
        Attributes = [faUnNamed]
        DataType = ftInteger
      end
      item
        Name = 'NAZ_MIES'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RBH_MIES'
        Attributes = [faUnNamed]
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH'
        DataType = ftCurrency
      end
      item
        Name = 'POZOSTALO'
        DataType = ftCurrency
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    OnCalcFields = m_RBHCDCalcFields
    Left = 24
    Top = 40
    object m_RBHCDNR_MIES: TIntegerField
      FieldName = 'NR_MIES'
    end
    object m_RBHCDNAZ_MIES: TStringField
      FieldName = 'NAZ_MIES'
    end
    object m_RBHCDBILANS: TFMTBCDField
      FieldKind = fkCalculated
      FieldName = 'BILANS'
      Size = 0
      Calculated = True
    end
    object m_RBHCDRBH_MIES: TCurrencyField
      FieldName = 'RBH_MIES'
    end
    object m_RBHCDPLAN_RBH: TCurrencyField
      FieldName = 'PLAN_RBH'
    end
    object m_RBHCDPOZOSTALO: TCurrencyField
      FieldName = 'POZOSTALO'
    end
  end
  object m_RBHDS: TDataSource
    DataSet = m_RBHCD
    Left = 16
    Top = 136
  end
  object m_HarmDetDS: TDataSource
    Left = 248
    Top = 128
  end
  object m_HarmDS: TDataSource
    Left = 264
    Top = 40
  end
end
