object _ListaHarmFRM: T_ListaHarmFRM
  Left = 0
  Top = 0
  Caption = 'Plan - harmonogram'
  ClientHeight = 715
  ClientWidth = 1260
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 45
    Width = 1260
    Height = 639
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object m_MiesGR: TDBGrid
      Left = 0
      Top = 0
      Width = 297
      Height = 639
      Align = alLeft
      DataSource = m_MiesDS
      DrawingStyle = gdsGradient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [dgTitles, dgColLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
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
          FieldName = 'MIESIAC'
          Title.Alignment = taCenter
          Title.Caption = 'Wybrany miesi'#261'c'
          Width = 95
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'RBH_MIES'
          Title.Caption = 'Dost. RBH'
          Width = 55
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PLAN_RBH'
          Title.Caption = 'Zapl. RBH'
          Width = 55
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'POZOSTALO'
          Title.Caption = 'Pozost.'
          Width = 55
          Visible = True
        end>
    end
    object m_HarmGR: TDBGrid
      Left = 264
      Top = 0
      Width = 996
      Height = 639
      Align = alRight
      Anchors = [akLeft, akTop, akRight, akBottom]
      Color = clWhite
      DataSource = m_HarmDS
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnDblClick = m_EdytujBBClick
      Columns = <
        item
          Expanded = False
          FieldName = 'ID_HARMONOGRAMU'
          Title.Caption = 'Nr harm.'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'JW_MIEJSCOWOSC'
          Title.Caption = 'Dostawca'
          Width = 151
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZ_REMONTU'
          Title.Caption = 'Rodz. rem.'
          Width = 58
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZ_SPRZETU'
          Title.Caption = 'Sprz'#281't'
          Width = 257
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ZADANIE'
          Title.Caption = 'Zadanie'
          Width = 318
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = 'ILOSC'
          Title.Alignment = taCenter
          Title.Caption = 'Ilo'#347#263
          Width = 57
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = 'PLAN_RBH'
          Title.Alignment = taCenter
          Title.Caption = 'RBH'
          Width = 57
          Visible = True
        end>
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 1260
    Height = 45
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
    TabOrder = 1
    object Label1: TLabel
      Left = 120
      Top = 4
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object Label2: TLabel
      Left = 618
      Top = 4
      Width = 69
      Height = 13
      Caption = 'Dost'#281'pne RBH'
      Transparent = True
    end
    object DBText1: TDBText
      Left = 612
      Top = 22
      Width = 78
      Height = 19
      Alignment = taRightJustify
      Color = clWhite
      DataField = 'SUM_RBH_MIES'
      DataSource = m_RBHDS
      ParentColor = False
      Transparent = True
    end
    object Label3: TLabel
      Left = 713
      Top = 4
      Width = 87
      Height = 13
      Caption = 'Zaplanowane RBH'
      Transparent = True
    end
    object DBText2: TDBText
      Left = 722
      Top = 22
      Width = 78
      Height = 19
      Alignment = taRightJustify
      Color = clWhite
      DataField = 'SUM_PLAN_RBH'
      DataSource = m_RBHDS
      ParentColor = False
      Transparent = True
    end
    object m_PozostaloLB: TLabel
      Left = 851
      Top = 4
      Width = 56
      Height = 13
      Caption = 'Pozosta'#322'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object m_PozostaloDBT: TDBText
      Left = 829
      Top = 22
      Width = 78
      Height = 17
      Alignment = taRightJustify
      Color = clWhite
      DataField = 'SUM_POZOSTALO'
      DataSource = m_RBHDS
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Transparent = True
    end
    object m_RokPA: TAdvSmoothPanel
      Left = 0
      Top = 0
      Width = 116
      Height = 45
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
      Align = alLeft
      TabOrder = 1
      object m_RokLB: TLabel
        Left = 3
        Top = 4
        Width = 18
        Height = 13
        Caption = 'Rok'
        Transparent = True
      end
      object m_RokED: TEdit
        Left = 3
        Top = 21
        Width = 86
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 0
        Text = 'm_RokED'
      end
    end
    object m_WarCB: TDBLookupComboBox
      Left = 122
      Top = 21
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
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 684
    Width = 1260
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
      1260
      31)
    object m_DodajBB: TAdvSmoothButton
      Left = 270
      Top = 6
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
      Color = 16644337
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = m_DodajBBClick
    end
    object m_EdytujBB: TAdvSmoothButton
      Left = 344
      Top = 6
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
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      OnClick = m_EdytujBBClick
    end
    object m_UsunBB: TAdvSmoothButton
      Left = 492
      Top = 6
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
      Color = 16644337
      TabOrder = 2
      Version = '1.6.9.1'
      OnClick = m_UsunBBClick
    end
    object m_SaveBB: TAdvSmoothButton
      Left = 1180
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
      Caption = 'Zamknij'
      Color = 16644337
      TabOrder = 3
      Version = '1.6.9.1'
      OnClick = m_SaveBBClick
    end
    object m_MoveBB: TAdvSmoothButton
      Left = 418
      Top = 6
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
      Caption = 'Przenie'#347
      Color = 16644337
      TabOrder = 4
      Version = '1.6.9.1'
      OnClick = m_MoveBBClick
    end
    object m_ImportBB: TAdvSmoothButton
      Left = 196
      Top = 6
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
      Caption = 'Importuj'
      Color = 16644337
      TabOrder = 5
      Visible = False
      Version = '1.6.9.1'
      OnClick = m_ImportBBClick
    end
    object m_ReadPlanBB: TAdvSmoothButton
      Left = 12
      Top = 6
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
      Caption = 'Wczytaj'
      Color = 16644337
      TabOrder = 6
      Visible = False
      Version = '1.6.9.1'
      OnClick = m_ReadPlanBBClick
    end
    object m_ZatwBB: TAdvSmoothButton
      Left = 86
      Top = 6
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
      Caption = 'Zatwierd'#378
      Color = 16644337
      TabOrder = 7
      Visible = False
      Version = '1.6.9.1'
      OnClick = m_ZatwBBClick
    end
  end
  object m_MiesCD: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'NR_MIES'
        Attributes = [faUnNamed]
        DataType = ftInteger
      end
      item
        Name = 'MIESIAC'
        Attributes = [faUnNamed]
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RBH_MIES'
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
    Left = 24
    Top = 80
    object m_MiesCDNR_MIES: TIntegerField
      FieldName = 'NR_MIES'
    end
    object m_MiesCDMIESIAC: TStringField
      FieldName = 'MIESIAC'
    end
    object m_MiesCDRBH_MIES: TCurrencyField
      FieldName = 'RBH_MIES'
    end
    object m_MiesCDPLAN_RBH: TCurrencyField
      FieldName = 'PLAN_RBH'
    end
    object m_MiesCDPOZOSTALO: TCurrencyField
      FieldName = 'POZOSTALO'
    end
  end
  object m_MiesDS: TDataSource
    DataSet = m_MiesCD
    Left = 24
    Top = 152
  end
  object m_HarmDS: TDataSource
    Left = 176
    Top = 72
  end
  object m_WarDS: TDataSource
    Left = 264
    Top = 72
  end
  object m_RBHCD: TClientDataSet
    Aggregates = <>
    AggregatesActive = True
    AutoCalcFields = False
    FieldDefs = <
      item
        Name = 'ID_KOMORKI'
        Attributes = [faUnNamed]
        DataType = ftInteger
      end
      item
        Name = 'NR_MIES'
        Attributes = [faUnNamed]
        DataType = ftInteger
      end
      item
        Name = 'RBH_MIES'
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
    Left = 352
    Top = 80
    object m_RBHCDID_KOMORKI: TIntegerField
      FieldName = 'ID_KOMORKI'
    end
    object m_RBHCDNR_MIES: TIntegerField
      FieldName = 'NR_MIES'
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
    object m_RBHCDSUM_RBH_MIES: TAggregateField
      FieldName = 'SUM_RBH_MIES'
      Active = True
      DisplayFormat = '#########0.00'
      Expression = 'SUM(RBH_MIES)'
    end
    object m_RBHCDSUM_PLAN_RBH: TAggregateField
      FieldName = 'SUM_PLAN_RBH'
      Active = True
      DisplayFormat = '#########0.00'
      Expression = 'SUM(PLAN_RBH)'
    end
    object m_RBHCDSUM_POZOSTALO: TAggregateField
      FieldName = 'SUM_POZOSTALO'
      Active = True
      DisplayFormat = '#########0.00'
      Expression = 'SUM(POZOSTALO)'
    end
  end
  object m_RBHDS: TDataSource
    DataSet = m_RBHCD
    Left = 456
    Top = 88
  end
end
