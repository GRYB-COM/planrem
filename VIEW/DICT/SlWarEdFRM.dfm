object _SlWarEdFRM: T_SlWarEdFRM
  Left = 860
  Top = 170
  Caption = 'Edycja danych warsztatu'
  ClientHeight = 181
  ClientWidth = 446
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
  object m_TopP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 446
    Height = 148
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
    Caption.ColorStart = 11563548
    Caption.ColorEnd = 10446362
    Fill.Color = 16445929
    Fill.ColorTo = 15587527
    Fill.ColorMirror = 15587527
    Fill.ColorMirrorTo = 16773863
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 14922381
    Fill.Rounding = 0
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alClient
    TabOrder = 0
    object m_KodLB: TLabel
      Left = 24
      Top = 16
      Width = 18
      Height = 13
      Caption = 'Kod'
      Transparent = True
    end
    object m_NazwaLB: TLabel
      Left = 64
      Top = 16
      Width = 32
      Height = 13
      Caption = 'Nazwa'
      Transparent = True
    end
    object m_OddzLB: TLabel
      Left = 24
      Top = 77
      Width = 38
      Height = 13
      Caption = 'Wydzia'#322
      Transparent = True
    end
    object m_WydzLB: TLabel
      Left = 88
      Top = 77
      Width = 36
      Height = 13
      Caption = 'Oddzia'#322
      Transparent = True
    end
    object m_TelLB: TLabel
      Left = 152
      Top = 77
      Width = 36
      Height = 13
      Caption = 'Telefon'
      Transparent = True
    end
    object m_KodED: TDBEdit
      Left = 24
      Top = 35
      Width = 25
      Height = 21
      DataField = 'KOD'
      DataSource = m_DS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 64
      Top = 35
      Width = 361
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_WydzCB: TDBLookupComboBox
      Left = 24
      Top = 96
      Width = 49
      Height = 21
      DataField = 'ID_WYDZIALU'
      DataSource = m_DS
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD;NAZWA'
      ListSource = m_WydzDS
      TabOrder = 2
    end
    object m_OddzCB: TDBLookupComboBox
      Left = 88
      Top = 96
      Width = 49
      Height = 21
      DataField = 'ID_ODDZIALU'
      DataSource = m_DS
      KeyField = 'ID_ODDZIALU'
      ListField = 'KOD;NAZWA'
      ListSource = m_OddzDS
      TabOrder = 3
    end
    object m_TelED: TDBEdit
      Left = 152
      Top = 96
      Width = 138
      Height = 21
      DataField = 'TELEFON'
      DataSource = m_DS
      TabOrder = 4
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 148
    Width = 446
    Height = 33
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
    Caption.ColorStart = 11563548
    Caption.ColorEnd = 10446362
    Fill.Color = 16445929
    Fill.ColorTo = 15587527
    Fill.ColorMirror = 15587527
    Fill.ColorMirrorTo = 16773863
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 14922381
    Fill.Rounding = 0
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      446
      33)
    object m_CancelBB: TAdvSmoothButton
      Left = 322
      Top = 6
      Width = 53
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
      OnClick = m_CancelBBClick
    end
    object m_SaveBB: TAdvSmoothButton
      Left = 381
      Top = 6
      Width = 53
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
      OnClick = m_SaveBBClick
    end
  end
  object m_DS: TDataSource
    Left = 24
    Top = 128
  end
  object m_WydzDS: TDataSource
    Left = 80
    Top = 128
  end
  object m_OddzDS: TDataSource
    Left = 152
    Top = 128
  end
end
