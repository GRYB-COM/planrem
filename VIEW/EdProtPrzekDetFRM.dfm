object _EdProtPrzekDetFRM: T_EdProtPrzekDetFRM
  Left = 0
  Top = 0
  Caption = 'Protok'#243#322' przekazania'
  ClientHeight = 234
  ClientWidth = 534
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
    Top = 201
    Width = 534
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
      534
      33)
    object m_CancelBB: TAdvSmoothButton
      Left = 390
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
      Left = 462
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
    Width = 534
    Height = 201
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
    DesignSize = (
      534
      201)
    object Label2: TLabel
      Left = 13
      Top = 8
      Width = 77
      Height = 13
      Caption = 'Nr magazynowy'
      Transparent = True
    end
    object Label4: TLabel
      Left = 111
      Top = 10
      Width = 71
      Height = 13
      Caption = 'Nazwa sprz'#281'tu'
      Transparent = True
    end
    object Label5: TLabel
      Left = 13
      Top = 56
      Width = 78
      Height = 13
      Caption = 'Nr rejestracyjny'
      Transparent = True
    end
    object Label1: TLabel
      Left = 111
      Top = 56
      Width = 62
      Height = 13
      Caption = 'Nr fabryczny'
      Transparent = True
    end
    object Label3: TLabel
      Left = 211
      Top = 56
      Width = 86
      Height = 13
      Caption = 'Warsztat wiod'#261'cy'
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 129
      Width = 40
      Height = 13
      Caption = 'przyj'#281'ta'
      Transparent = True
    end
    object Label7: TLabel
      Left = 193
      Top = 129
      Width = 72
      Height = 13
      Caption = 'ju'#380' przekazana'
      Transparent = True
    end
    object Label8: TLabel
      Left = 281
      Top = 129
      Width = 55
      Height = 13
      Caption = 'do wydania'
      Transparent = True
    end
    object Label9: TLabel
      Left = 13
      Top = 114
      Width = 28
      Height = 13
      Caption = 'Ilo'#347'ci:'
      Transparent = True
    end
    object Label10: TLabel
      Left = 96
      Top = 129
      Width = 80
      Height = 13
      Caption = 'wyremontowana'
      Transparent = True
    end
    object m_NrMagED: TDBEdit
      Left = 13
      Top = 27
      Width = 91
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'SYGN_MAG'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 0
    end
    object m_NazSprzED: TDBEdit
      Left = 110
      Top = 27
      Width = 378
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NAZ_SPRZETU'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 1
    end
    object m_NrRejED: TDBEdit
      Left = 13
      Top = 72
      Width = 91
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NR_REJ'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 2
    end
    object m_OpenBT: TAdvSmoothButton
      Left = 502
      Top = 26
      Width = 29
      Height = 23
      Hint = 'Otw'#243'rz'
      Anchors = [akTop, akRight]
      Appearance.Spacing = 0
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
      Color = 16644337
      Picture.Data = {
        0000010001001010000001002000680400001600000028000000100000002000
        0000010020000000000000040000120B0000120B000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000808081F1B141471000000190000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000030262693725E5EFF493C3CC90D09094E00000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000A05052F604E4EF5B19C9CFF836F6FFF4F3E3EF6271E1E95000000200000
        0000000000000000000000000000000000000000000000000000000000000000
        0000352929A7998484FF8B7878FF564343FF5D4949FF584545F71410103D0000
        0000000000000000000000000000000000110000001B00000010000000000505
        0533685757F88F7B7BFF584545FF5C4848FF4B3B3BD11511113C000000000000
        000000000000181313346053519F857370D28D7A78DD796967C74238387F2C23
        23C15C4C4CFF614D4DFF594646FF392C2C9B0000001500000000000000000000
        0000352C2C56A28C8AEFC1ACAAFFC1AFB0FFC1AFB1FFC3B1B1FFBFAAA8FF9883
        81FF4C3D3DFF413333E12118185500000000000000000000000000000000160F
        0F22A28C89EFC2AFAEFFC1AFB0FFCFB6A9FFD8BAA5FFCFB6A9FFC1B0B0FFC5B2
        B2FF988482FB100D0D4D0000000000000000000000000000000000000000574C
        4A7BC1ADACFFC4B1AEFFE9C1A0FFFECD99FFFFCD98FFFECC99FFE5BFA1FFC3B0
        AFFFC2AFAEFE4D43408B00000001000000000000000000000000000000008D7B
        7ABAC3B2B3FFE1BDA3FFFFCE96FFFFCC98FFFFCC99FFFFCC99FFFFCE97FFE1BE
        A3FFC6B4B5FF907F7ED800000013000000000000000000000000000000009B8B
        8ABCC6B4B1FFF3C69CFFFFCF9BFFFFCC9AFFFFC993FFFFCB97FFFFCD98FFF5C8
        9CFFC6B3B1FFAB9999F007070721000000000000000000000000000000007C72
        728FCAB6B5FFF3C498FFFFE7CBFFFFF2E5FFFFE6CCFFFFD2A5FFFFCC96FFF5C8
        9CFFC6B3B0FFAC9B9BEC0000001A00000000000000000000000000000000A08B
        8B3EC0AFB0FFE2BDA0FFFFD7A9FFFFFEFCFFFFFFFFFFFFECD8FFFFCC94FFE2BE
        A2FFC8B6B6FF908282C500000006000000000000000000000000000000000000
        0000C0AAAA97C3AFACFFECC29DFFFFECD8FFFFFDF9FFFFE3C6FFE8BF9CFFC4B1
        B0FFC8B6B5FF413C3C5900000000000000000000000000000000000000000000
        0000C6AAAA09BEACACA3C0AEACFFD0B6A9FFD7BEAFFFCFB5A8FFC7B5B4FFC5B3
        B3FC675D5D830000000000000000000000000000000000000000000000000000
        00000000000000000000BEACAC53BCABABB8BBABABE8BEADAEE5938585A43733
        334000000000000000000000000000000000000000000000000000000000FFC7
        0000FFC30000FF800000FF800000F1010000C0030000800F0000001F0000000F
        0000000F0000000F0000000F0000000F0000801F0000803F0000E07F0000}
      TabOrder = 3
      HorizontalSpacing = 0
      Version = '1.6.9.1'
      OnClick = m_OpenBTClick
    end
    object m_NrFabrED: TDBEdit
      Left = 111
      Top = 72
      Width = 91
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NR_FABR'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 4
    end
    object m_WarED: TDBEdit
      Left = 211
      Top = 72
      Width = 278
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NAZ_WARSZTATU'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 5
    end
    object m_IlPrzyjED: TDBEdit
      Left = 12
      Top = 146
      Width = 72
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC_PRZYJ'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 6
    end
    object m_IlWydED: TDBEdit
      Left = 193
      Top = 147
      Width = 72
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC_WYD'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 7
    end
    object m_IlDoWydED: TDBEdit
      Left = 281
      Top = 147
      Width = 72
      Height = 21
      Ctl3D = True
      DataField = 'ILOSC'
      DataSource = m_ProtDetDS
      ParentCtl3D = False
      TabOrder = 8
    end
    object m_IlRemED: TDBEdit
      Left = 96
      Top = 147
      Width = 80
      Height = 19
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC_REM'
      DataSource = m_MagDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 9
    end
  end
  object m_ProtDetDS: TDataSource
    Left = 377
    Top = 137
  end
  object m_MagDS: TDataSource
    Left = 497
    Top = 65
  end
end
