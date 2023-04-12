inherited _AddRbhFRM: T_AddRbhFRM
  BorderStyle = bsSingle
  Caption = 'Zapis RBH'
  ClientHeight = 1018
  ClientWidth = 884
  KeyPreview = True
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  ExplicitTop = -363
  ExplicitWidth = 890
  ExplicitHeight = 1043
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 986
    Width = 884
    Height = 32
    ExplicitTop = 986
    ExplicitWidth = 884
    ExplicitHeight = 32
    inherited m_DodajBB: TAdvSmoothButton
      Left = -1000
      Top = -1000
      Visible = False
      ExplicitLeft = -1000
      ExplicitTop = -1000
    end
    inherited m_EdytujBB: TAdvSmoothButton
      Left = -1000
      Top = -1000
      Visible = False
      ExplicitLeft = -1000
      ExplicitTop = -1000
    end
    inherited m_UsunBB: TAdvSmoothButton
      Left = -1000
      Top = -1000
      Visible = False
      ExplicitLeft = -1000
      ExplicitTop = -1000
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = -668
      Top = -1000
      Visible = False
      ExplicitLeft = -668
      ExplicitTop = -1000
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 805
      Caption = 'Zamknij'
      ExplicitLeft = 805
    end
    inherited m_PrintBB: TAdvSmoothButton
      Left = -1000
      Top = -1000
      Visible = False
      ExplicitLeft = -1000
      ExplicitTop = -1000
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Top = 46
    Width = 884
    Height = 858
    ExplicitTop = 46
    ExplicitWidth = 884
    ExplicitHeight = 858
    inherited m_DBG: TDBGrid
      Width = 884
      Height = 858
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel [2]
    Left = 0
    Top = 0
    Width = 884
    Height = 46
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
    object m_WarsztatLB: TLabel
      Left = 12
      Top = 3
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_MiesLB: TLabel
      Left = 316
      Top = 4
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label5: TLabel
      Left = 395
      Top = 5
      Width = 67
      Height = 13
      Caption = 'Harmonogram'
      Transparent = True
    end
    object m_WarsztatCB: TDBLookupComboBox
      Left = 12
      Top = 18
      Width = 297
      Height = 21
      DropDownRows = 25
      DropDownWidth = 390
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarsztatDS
      TabOrder = 0
      OnCloseUp = refreshDane
    end
    object m_MiesCB: TDBLookupComboBox
      Left = 316
      Top = 18
      Width = 73
      Height = 21
      DropDownRows = 12
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_MiesDS
      TabOrder = 1
      OnCloseUp = refreshDane
    end
    object m_HarmCB: TDBLookupComboBox
      Left = 395
      Top = 19
      Width = 73
      Height = 21
      DropDownRows = 40
      DropDownWidth = 200
      KeyField = 'ID_HARMONOGRAMU'
      ListField = 'ID_HARMONOGRAMU;ZADANIE'
      ListSource = m_HarmDS
      TabOrder = 2
      OnCloseUp = m_HarmCBCloseUp
    end
  end
  object AdvSmoothPanel2: TAdvSmoothPanel [3]
    Left = 0
    Top = 904
    Width = 884
    Height = 82
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
    TabOrder = 3
    object Label1: TLabel
      Left = 12
      Top = 30
      Width = 19
      Height = 13
      Caption = 'KUT'
      Transparent = True
    end
    object Label2: TLabel
      Left = 298
      Top = 30
      Width = 64
      Height = 13
      Caption = 'Ilo'#347#263'  sprz'#281'tu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 378
      Top = 30
      Width = 48
      Height = 13
      Caption = 'Ilo'#347#263'  RBH'
      Transparent = True
    end
    object Label4: TLabel
      Left = 214
      Top = 30
      Width = 75
      Height = 13
      Caption = 'Planowane RBH'
      Transparent = True
    end
    object Label6: TLabel
      Left = 129
      Top = 30
      Width = 75
      Height = 13
      Caption = 'Planowana ilo'#347#263
      Transparent = True
    end
    object Label7: TLabel
      Left = 517
      Top = 2
      Width = 49
      Height = 16
      Alignment = taRightJustify
      Caption = 'RAZEM:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object m_ZlecCB: TDBLookupComboBox
      Left = 12
      Top = 43
      Width = 113
      Height = 21
      DropDownRows = 25
      DropDownWidth = 400
      KeyField = 'ID_ZLECENIA'
      ListField = 'SYGN_ZLECENIA;NAZ_SPRZETU;ID_HARM'
      ListSource = m_ZlecDS
      NullValueKey = 46
      TabOrder = 0
      OnCloseUp = m_ZlecCBCloseUp
      OnExit = m_ZlecCBCloseUp
    end
    object m_IlSprzED: TNumEdit
      Left = 298
      Top = 43
      Width = 73
      Height = 21
      TabOrder = 3
    end
    object m_IlRBHEd: TNumEdit
      Left = 378
      Top = 43
      Width = 73
      Height = 21
      TabOrder = 4
    end
    object m_AddBB: TAdvSmoothButton
      Left = 463
      Top = 43
      Width = 66
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
      Caption = 'Dodaj'
      Color = 16644337
      TabOrder = 5
      Version = '1.6.9.1'
      OnClick = m_AddBBClick
    end
    object m_PlanRBHED: TNumEdit
      Left = 216
      Top = 43
      Width = 73
      Height = 21
      TabOrder = 2
    end
    object m_PlanIlED: TNumEdit
      Left = 133
      Top = 43
      Width = 73
      Height = 21
      TabOrder = 1
    end
    object m_SumPlanIlTE: TDBEdit
      Left = 575
      Top = 0
      Width = 81
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'PLAN_ILOSC'
      DataSource = m_SumDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 6
    end
    object m_SumPlanRBHTE: TDBEdit
      Left = 656
      Top = 0
      Width = 78
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'PLAN_RBH'
      DataSource = m_SumDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 7
    end
    object m_SumIlSprzTE: TDBEdit
      Left = 734
      Top = 0
      Width = 68
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC'
      DataSource = m_SumDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 8
    end
    object m_SumRBHTE: TDBEdit
      Left = 802
      Top = 0
      Width = 57
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'RBH'
      DataSource = m_SumDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 9
    end
  end
  object m_MiesDS: TDataSource
    Left = 368
    Top = 48
  end
  object m_WarsztatDS: TDataSource
    Left = 288
    Top = 48
  end
  object m_ZlecDS: TDataSource
    Left = 32
    Top = 288
  end
  object m_HarmDS: TDataSource
    Left = 440
    Top = 56
  end
  object m_SumDS: TDataSource
    Left = 632
    Top = 960
  end
end
