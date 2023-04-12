object _SlPracEdFRM: T_SlPracEdFRM
  Left = 755
  Top = 164
  Caption = 'Edycja danych warsztatu'
  ClientHeight = 181
  ClientWidth = 405
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
    Width = 405
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
      Width = 20
      Height = 13
      Caption = 'Imi'#281
      Transparent = True
    end
    object m_NazwaLB: TLabel
      Left = 144
      Top = 16
      Width = 44
      Height = 13
      Caption = 'Nazwisko'
      Transparent = True
    end
    object m_OddzLB: TLabel
      Left = 24
      Top = 77
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_WydzLB: TLabel
      Left = 88
      Top = 77
      Width = 54
      Height = 13
      Caption = 'Stanowisko'
      Transparent = True
    end
    object m_TelLB: TLabel
      Left = 262
      Top = 77
      Width = 52
      Height = 13
      Caption = 'Liczba RBH'
      Transparent = True
    end
    object Label1: TLabel
      Left = 199
      Top = 77
      Width = 36
      Height = 13
      Caption = 'Stopie'#324
      Transparent = True
    end
    object m_KodED: TDBEdit
      Left = 24
      Top = 35
      Width = 105
      Height = 21
      DataField = 'IMIE'
      DataSource = m_DS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 144
      Top = 35
      Width = 170
      Height = 21
      DataField = 'NAZWISKO'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_WarCB: TDBLookupComboBox
      Left = 24
      Top = 96
      Width = 49
      Height = 21
      DataField = 'ID_KOMORKI'
      DataSource = m_DS
      DropDownWidth = 381
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListSource = m_WarDS
      TabOrder = 2
    end
    object m_OddzCB: TDBLookupComboBox
      Left = 88
      Top = 96
      Width = 100
      Height = 21
      DataField = 'ID_STANOWISKA'
      DataSource = m_DS
      KeyField = 'ID_STANOWISKA'
      ListField = 'NAZWA'
      ListSource = m_StanDS
      TabOrder = 3
    end
    object m_RBHED: TDBEdit
      Left = 262
      Top = 96
      Width = 52
      Height = 21
      DataField = 'RBH_MIES'
      DataSource = m_DS
      TabOrder = 4
    end
    object m_StopCB: TDBLookupComboBox
      Left = 199
      Top = 96
      Width = 50
      Height = 21
      DataField = 'ID_STOPNIA'
      DataSource = m_DS
      KeyField = 'ID_STOPNIA'
      ListField = 'NAZWA'
      ListSource = m_StopDS
      TabOrder = 5
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 148
    Width = 405
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
      405
      33)
    object m_CancelBB: TAdvSmoothButton
      Left = 281
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
      Left = 340
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
  object m_WarDS: TDataSource
    Left = 80
    Top = 128
  end
  object m_StanDS: TDataSource
    Left = 152
    Top = 128
  end
  object m_StopDS: TDataSource
    Left = 216
    Top = 128
  end
end
