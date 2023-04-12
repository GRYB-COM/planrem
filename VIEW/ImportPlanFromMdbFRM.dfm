object _ImportPlanFromMdbFRM: T_ImportPlanFromMdbFRM
  Left = 225
  Top = 221
  Caption = 'Import danych z MS Access'
  ClientHeight = 170
  ClientWidth = 473
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 473
    Height = 137
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
    DesignSize = (
      473
      137)
    object m_PathLB: TLabel
      Left = 16
      Top = 8
      Width = 124
      Height = 13
      Caption = #346'cie'#380'ka do bazy MS Acess'
      Transparent = True
    end
    object Label1: TLabel
      Left = 16
      Top = 75
      Width = 22
      Height = 13
      Caption = 'Rok:'
      Transparent = True
    end
    object m_PathED: TEdit
      Left = 16
      Top = 27
      Width = 409
      Height = 21
      Color = clInfoBk
      ReadOnly = True
      TabOrder = 0
      OnChange = enableRun
    end
    object m_OpenBT: TAdvSmoothButton
      Left = 431
      Top = 27
      Width = 29
      Height = 21
      Hint = 'Otw'#243'rz'
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
      TabOrder = 1
      HorizontalSpacing = 0
      Version = '1.6.9.1'
      OnClick = m_OpenBTClick
    end
    object m_RunBB: TAdvSmoothButton
      Left = 363
      Top = 68
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
      Caption = 'Importuj'
      Color = 16644337
      TabOrder = 2
      Version = '1.6.9.1'
    end
    object m_RokED: TEdit
      Left = 40
      Top = 72
      Width = 41
      Height = 21
      NumbersOnly = True
      TabOrder = 3
      Text = '2014'
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 137
    Width = 473
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
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      473
      33)
    object m_CloseBB: TAdvSmoothButton
      Left = 373
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
      Caption = 'Zamknij'
      Color = 16644337
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = m_CloseBBClick
    end
  end
  object m_PathOD: TOpenDialog
    DefaultExt = '*.mdb'
    Filter = 'Bazy danych MS Access|*.mdb|Wszystkie pliki|*.*'
    Left = 144
    Top = 72
  end
end
