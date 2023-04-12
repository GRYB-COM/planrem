object _EdProtPrzekFRM: T_EdProtPrzekFRM
  Left = 0
  Top = 0
  Caption = 'Protok'#243#322' przekazania'
  ClientHeight = 293
  ClientWidth = 426
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
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 260
    Width = 426
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
    TabOrder = 0
    DesignSize = (
      426
      33)
    object m_CancelBB: TAdvSmoothButton
      Left = 282
      Top = 6
      Width = 66
      Height = 21
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
      Left = 354
      Top = 6
      Width = 66
      Height = 21
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
  object m_TopP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 426
    Height = 260
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
    TabOrder = 1
    object m_WydzLB: TLabel
      Left = 16
      Top = 11
      Width = 38
      Height = 13
      Caption = 'Wydzia'#322
      Transparent = True
    end
    object Label1: TLabel
      Left = 18
      Top = 60
      Width = 108
      Height = 13
      Caption = 'Sprz'#281't przekazany do:'
      Transparent = True
    end
    object Label2: TLabel
      Left = 16
      Top = 104
      Width = 99
      Height = 13
      Caption = 'Sygnatura protoko'#322'u'
      Transparent = True
    end
    object Label3: TLabel
      Left = 152
      Top = 104
      Width = 85
      Height = 13
      Caption = 'Data wystawienia'
      Transparent = True
    end
    object Label4: TLabel
      Left = 18
      Top = 155
      Width = 50
      Height = 13
      Caption = 'Przekaza'#322':'
      Transparent = True
    end
    object Label5: TLabel
      Left = 18
      Top = 201
      Width = 43
      Height = 13
      Caption = 'Odebra'#322':'
      Transparent = True
    end
    object m_WydzCB: TDBLookupComboBox
      Left = 16
      Top = 27
      Width = 404
      Height = 21
      DataField = 'ID_WYDZIALU'
      DataSource = m_ProtDS
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD_NAZWA'
      ListSource = m_WydzDS
      TabOrder = 0
    end
    object m_JednCB: TDBLookupComboBox
      Left = 16
      Top = 76
      Width = 404
      Height = 21
      DataField = 'ID_JEDNOSTKI'
      DataSource = m_ProtDS
      KeyField = 'ID_JEDNOSTKI'
      ListField = 'JW_MIEJSC'
      ListSource = m_JednDS
      TabOrder = 1
    end
    object m_SygnED: TDBEdit
      Left = 18
      Top = 120
      Width = 121
      Height = 21
      DataField = 'SYGN_PROTOKOLU'
      DataSource = m_ProtDS
      TabOrder = 2
    end
    object AdvDBDateTimePicker1: TAdvDBDateTimePicker
      Left = 152
      Top = 120
      Width = 89
      Height = 21
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 3
      BorderStyle = bsSingle
      Ctl3D = True
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
    end
    object m_PrzekED: TDBEdit
      Left = 18
      Top = 171
      Width = 402
      Height = 21
      DataField = 'PRZEKAZAL'
      DataSource = m_ProtDS
      TabOrder = 4
    end
    object DBEdit1: TDBEdit
      Left = 16
      Top = 217
      Width = 402
      Height = 21
      DataField = 'PRZYJAL'
      DataSource = m_ProtDS
      TabOrder = 5
    end
  end
  object m_ProtDS: TDataSource
    Left = 24
    Top = 240
  end
  object m_JednDS: TDataSource
    Left = 80
    Top = 240
  end
  object m_WydzDS: TDataSource
    Left = 136
    Top = 248
  end
end
