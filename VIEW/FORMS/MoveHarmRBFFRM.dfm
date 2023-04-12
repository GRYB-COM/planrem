object _MoveHarmRBHFRM: T_MoveHarmRBHFRM
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Przenoszenie roboczogodzin na inny miesi'#261'c'
  ClientHeight = 275
  ClientWidth = 460
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
    Options = [dgTitles, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgTitleClick, dgTitleHotTrack]
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
    Width = 460
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
      460
      31)
    object AdvSmoothButton1: TAdvSmoothButton
      Left = 313
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
      Left = 387
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
    Left = 165
    Top = 0
    Width = 295
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
      Top = 90
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label2: TLabel
      Left = 97
      Top = 90
      Width = 61
      Height = 13
      Caption = 'Ilo'#347#263' sprz'#281'tu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 203
      Top = 90
      Width = 52
      Height = 13
      Caption = 'Liczba RBH'
      Transparent = True
    end
    object Label5: TLabel
      Left = 11
      Top = 15
      Width = 149
      Height = 13
      Caption = 'Okres wa'#380'no'#347'ci harmonogramu'
      Transparent = True
    end
    object Label4: TLabel
      Left = 87
      Top = 36
      Width = 4
      Height = 13
      Caption = '-'
      Transparent = True
    end
    object Label6: TLabel
      Left = 11
      Top = 75
      Width = 133
      Height = 13
      Caption = 'Dost'#281'pne do przeniesienia: '
      Transparent = True
    end
    object Label7: TLabel
      Left = 11
      Top = 173
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label8: TLabel
      Left = 97
      Top = 173
      Width = 61
      Height = 13
      Caption = 'Ilo'#347#263' sprz'#281'tu'
      Transparent = True
    end
    object Label9: TLabel
      Left = 203
      Top = 173
      Width = 52
      Height = 13
      Caption = 'Liczba RBH'
      Transparent = True
    end
    object Label10: TLabel
      Left = 11
      Top = 159
      Width = 65
      Height = 13
      Caption = 'Przenoszone:'
      Transparent = True
    end
    object m_IloscED: TDBEdit
      Left = 97
      Top = 109
      Width = 78
      Height = 19
      Ctl3D = False
      DataField = 'ILOSC'
      DataSource = m_HarmDetDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 0
    end
    object m_RBHED: TDBEdit
      Left = 203
      Top = 109
      Width = 78
      Height = 19
      Ctl3D = False
      DataField = 'PLAN_RBH'
      DataSource = m_HarmDetDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 1
    end
    object m_DataOdED: TDBEdit
      Left = 11
      Top = 34
      Width = 70
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'DATA_OD'
      DataSource = m_HarmDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 2
    end
    object m_DataDO: TDBEdit
      Left = 97
      Top = 34
      Width = 70
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'DATA_DO'
      DataSource = m_HarmDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 3
    end
    object m_MiesCB: TDBLookupComboBox
      Left = 11
      Top = 192
      Width = 78
      Height = 21
      DataField = 'MIESIAC'
      DataSource = m_PrzenDS
      DropDownRows = 12
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_RBHDS
      TabOrder = 4
    end
    object DBEdit1: TDBEdit
      Left = 97
      Top = 192
      Width = 78
      Height = 21
      DataField = 'ILOSC'
      DataSource = m_PrzenDS
      TabOrder = 5
    end
    object DBEdit2: TDBEdit
      Left = 203
      Top = 192
      Width = 78
      Height = 21
      DataField = 'PLAN_RBH'
      DataSource = m_PrzenDS
      TabOrder = 6
    end
    object DBEdit3: TDBEdit
      Left = 11
      Top = 109
      Width = 78
      Height = 19
      Ctl3D = False
      DataField = 'NAZ_MIES'
      DataSource = m_HarmDetDS
      Enabled = False
      ParentCtl3D = False
      TabOrder = 7
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
        DataType = ftFMTBcd
        Precision = 32
        Size = 4
      end
      item
        Name = 'PLAN_RBH'
        DataType = ftFMTBcd
        Precision = 32
        Size = 4
      end
      item
        Name = 'POZOSTALO'
        DataType = ftFMTBcd
        Precision = 32
        Size = 4
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
    object m_RBHCDRBH_MIES: TFMTBCDField
      FieldName = 'RBH_MIES'
      Precision = 32
      Size = 4
    end
    object m_RBHCDPLAN_RBH: TFMTBCDField
      FieldName = 'PLAN_RBH'
      Precision = 32
      Size = 4
    end
    object m_RBHCDPOZOSTALO: TFMTBCDField
      FieldName = 'POZOSTALO'
      Precision = 32
      Size = 4
    end
    object m_RBHCDBILANS: TFMTBCDField
      FieldKind = fkCalculated
      FieldName = 'BILANS'
      Size = 0
      Calculated = True
    end
  end
  object m_RBHDS: TDataSource
    AutoEdit = False
    DataSet = m_RBHCD
    Left = 16
    Top = 136
  end
  object m_HarmDetDS: TDataSource
    Left = 88
    Top = 120
  end
  object m_HarmDS: TDataSource
    Left = 88
    Top = 48
  end
  object m_PrzenCD: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'MIESIAC'
        DataType = ftInteger
      end
      item
        Name = 'ILOSC'
        DataType = ftFMTBcd
        Precision = 32
        Size = 4
      end
      item
        Name = 'PLAN_RBH'
        DataType = ftFMTBcd
        Precision = 32
        Size = 4
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 16
    Top = 192
  end
  object m_PrzenDS: TDataSource
    DataSet = m_PrzenCD
    Left = 96
    Top = 184
  end
end
