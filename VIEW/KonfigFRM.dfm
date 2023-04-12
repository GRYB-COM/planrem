object _KonfigFRM: T_KonfigFRM
  Left = 0
  Top = 0
  Caption = 'Sta'#322'e parametry'
  ClientHeight = 219
  ClientWidth = 369
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
  object m_SearchPA: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 369
    Height = 186
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
    Fill.ColorTo = 15786194
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 14922381
    Fill.Rounding = 0
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alClient
    TabOrder = 0
    object m_PageCTRL: TAdvSmoothTabPager
      Left = 0
      Top = 0
      Width = 369
      Height = 186
      Align = alClient
      ActivePage = m_EksportPA
      TabPosition = tpTopLeft
      TabSettings.StartMargin = 4
      TabSettings.Width = 110
      TabReorder = False
      TabOrder = 0
      object m_WartDOmPG: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 367
        Height = 158
        Caption = 'Warto'#347'ci domy'#347'lne'
        PageAppearance.Color = 16773091
        PageAppearance.ColorTo = 16768452
        PageAppearance.ColorMirror = clNone
        PageAppearance.ColorMirrorTo = clNone
        PageAppearance.GradientMirrorType = gtVertical
        PageAppearance.BorderColor = 16765357
        PageAppearance.Rounding = 0
        PageAppearance.ShadowOffset = 0
        TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Appearance.Font.Color = clWindowText
        TabAppearance.Appearance.Font.Height = -11
        TabAppearance.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Appearance.Font.Style = []
        TabAppearance.Status.Caption = '0'
        TabAppearance.Status.Appearance.Fill.Color = clRed
        TabAppearance.Status.Appearance.Fill.ColorMirror = clNone
        TabAppearance.Status.Appearance.Fill.ColorMirrorTo = clNone
        TabAppearance.Status.Appearance.Fill.GradientType = gtSolid
        TabAppearance.Status.Appearance.Fill.BorderColor = clGray
        TabAppearance.Status.Appearance.Fill.Rounding = 0
        TabAppearance.Status.Appearance.Fill.ShadowOffset = 0
        TabAppearance.Status.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Status.Appearance.Font.Color = clWhite
        TabAppearance.Status.Appearance.Font.Height = -11
        TabAppearance.Status.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Status.Appearance.Font.Style = []
        TabAppearance.BevelColor = 16765357
        TabAppearance.BevelColorDown = 16640730
        TabAppearance.BevelColorSelected = 16640730
        TabAppearance.BevelColorHot = 16640730
        TabAppearance.BevelColorDisabled = 16640730
        TabAppearance.Color = 16773091
        TabAppearance.ColorDown = 11196927
        TabAppearance.ColorDisabled = 16765357
        object m_WartDomPA: TAdvSmoothPanel
          Left = 2
          Top = 2
          Width = 363
          Height = 154
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
          Fill.Color = 16511718
          Fill.ColorTo = 15654350
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
          object Label11: TLabel
            Left = 16
            Top = 6
            Width = 85
            Height = 13
            Caption = 'Domy'#347'lny wydzia'#322
            Transparent = True
          end
          object Label5: TLabel
            Left = 16
            Top = 52
            Width = 58
            Height = 13
            Caption = 'Bie'#380#261'cy rok:'
            Transparent = True
          end
          object m_WydzCB: TDBLookupComboBox
            Left = 17
            Top = 25
            Width = 336
            Height = 21
            DropDownWidth = 500
            KeyField = 'ID_WYDZIALU'
            ListField = 'KOD;NAZWA;ID_WYDZIALU'
            ListFieldIndex = 1
            ListSource = m_WydzDS
            TabOrder = 0
          end
          object m_RokED: TEdit
            Left = 13
            Top = 71
            Width = 58
            Height = 21
            Alignment = taRightJustify
            NumbersOnly = True
            TabOrder = 1
            Text = '2011'
          end
        end
      end
      object m_PowiadPG: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 367
        Height = 158
        Caption = 'Powiadomienia'
        PageAppearance.Color = 16773091
        PageAppearance.ColorTo = 16768452
        PageAppearance.ColorMirror = clNone
        PageAppearance.ColorMirrorTo = clNone
        PageAppearance.GradientMirrorType = gtVertical
        PageAppearance.BorderColor = 16765357
        PageAppearance.Rounding = 0
        PageAppearance.ShadowOffset = 0
        TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Appearance.Font.Color = clWindowText
        TabAppearance.Appearance.Font.Height = -11
        TabAppearance.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Appearance.Font.Style = []
        TabAppearance.Status.Caption = '0'
        TabAppearance.Status.Appearance.Fill.Color = clRed
        TabAppearance.Status.Appearance.Fill.ColorMirror = clNone
        TabAppearance.Status.Appearance.Fill.ColorMirrorTo = clNone
        TabAppearance.Status.Appearance.Fill.GradientType = gtSolid
        TabAppearance.Status.Appearance.Fill.BorderColor = clGray
        TabAppearance.Status.Appearance.Fill.Rounding = 0
        TabAppearance.Status.Appearance.Fill.ShadowOffset = 0
        TabAppearance.Status.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Status.Appearance.Font.Color = clWhite
        TabAppearance.Status.Appearance.Font.Height = -11
        TabAppearance.Status.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Status.Appearance.Font.Style = []
        TabAppearance.BevelColor = 16765357
        TabAppearance.BevelColorDown = 16640730
        TabAppearance.BevelColorSelected = 16640730
        TabAppearance.BevelColorHot = 16640730
        TabAppearance.BevelColorDisabled = 16640730
        TabAppearance.Color = 16773091
        TabAppearance.ColorDown = 11196927
        TabAppearance.ColorDisabled = 16765357
        object m_PowPA: TAdvSmoothPanel
          Left = 2
          Top = 2
          Width = 363
          Height = 154
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
          Fill.Color = 16511718
          Fill.ColorTo = 15654350
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
          object m_TermDostLB: TLabel
            Left = 16
            Top = 16
            Width = 86
            Height = 13
            Caption = 'Terminy dostawy:'
            Transparent = True
          end
          object Label1: TLabel
            Left = 16
            Top = 43
            Width = 47
            Height = 13
            Caption = 'I kwarta'#322':'
            Transparent = True
          end
          object Label2: TLabel
            Left = 192
            Top = 43
            Width = 51
            Height = 13
            Caption = 'II kwarta'#322':'
            Transparent = True
          end
          object Label3: TLabel
            Left = 16
            Top = 86
            Width = 55
            Height = 13
            Caption = 'III kwarta'#322':'
            Transparent = True
          end
          object Label4: TLabel
            Left = 192
            Top = 86
            Width = 53
            Height = 13
            Caption = 'IV kwarta'#322':'
            Transparent = True
          end
          object m_IKWDateDTP: TAdvDateTimePicker
            Left = 77
            Top = 39
            Width = 81
            Height = 21
            Date = 40865.000000000000000000
            Time = 40865.000000000000000000
            DoubleBuffered = True
            Kind = dkDate
            ParentDoubleBuffered = False
            TabOrder = 0
            BorderStyle = bsSingle
            Ctl3D = True
            DateTime = 40865.000000000000000000
            Version = '1.1.0.0'
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
          end
          object m_IIKWDateDTP: TAdvDateTimePicker
            Left = 251
            Top = 39
            Width = 81
            Height = 21
            Date = 40865.000000000000000000
            Time = 40865.000000000000000000
            DoubleBuffered = True
            Kind = dkDate
            ParentDoubleBuffered = False
            TabOrder = 1
            BorderStyle = bsSingle
            Ctl3D = True
            DateTime = 40865.000000000000000000
            Version = '1.1.0.0'
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
          end
          object m_IIIKWDateDTP: TAdvDateTimePicker
            Left = 77
            Top = 82
            Width = 81
            Height = 21
            Date = 40865.000000000000000000
            Time = 40865.000000000000000000
            DoubleBuffered = True
            Kind = dkDate
            ParentDoubleBuffered = False
            TabOrder = 2
            BorderStyle = bsSingle
            Ctl3D = True
            DateTime = 40865.000000000000000000
            Version = '1.1.0.0'
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
          end
          object m_IVKWDateDTP: TAdvDateTimePicker
            Left = 251
            Top = 82
            Width = 81
            Height = 21
            Date = 40865.000000000000000000
            Time = 40865.000000000000000000
            DoubleBuffered = True
            Kind = dkDate
            ParentDoubleBuffered = False
            TabOrder = 3
            BorderStyle = bsSingle
            Ctl3D = True
            DateTime = 40865.000000000000000000
            Version = '1.1.0.0'
            LabelFont.Charset = DEFAULT_CHARSET
            LabelFont.Color = clWindowText
            LabelFont.Height = -11
            LabelFont.Name = 'Tahoma'
            LabelFont.Style = []
          end
        end
      end
      object m_EksportPA: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 367
        Height = 158
        Caption = 'Eksport'
        PageAppearance.Color = 16773091
        PageAppearance.ColorTo = 16768452
        PageAppearance.ColorMirror = clNone
        PageAppearance.ColorMirrorTo = clNone
        PageAppearance.GradientMirrorType = gtVertical
        PageAppearance.BorderColor = 16765357
        PageAppearance.Rounding = 0
        PageAppearance.ShadowOffset = 0
        TabAppearance.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Appearance.Font.Color = clWindowText
        TabAppearance.Appearance.Font.Height = -11
        TabAppearance.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Appearance.Font.Style = []
        TabAppearance.Status.Caption = '0'
        TabAppearance.Status.Appearance.Fill.Color = clRed
        TabAppearance.Status.Appearance.Fill.ColorMirror = clNone
        TabAppearance.Status.Appearance.Fill.ColorMirrorTo = clNone
        TabAppearance.Status.Appearance.Fill.GradientType = gtSolid
        TabAppearance.Status.Appearance.Fill.BorderColor = clGray
        TabAppearance.Status.Appearance.Fill.Rounding = 0
        TabAppearance.Status.Appearance.Fill.ShadowOffset = 0
        TabAppearance.Status.Appearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Status.Appearance.Font.Color = clWhite
        TabAppearance.Status.Appearance.Font.Height = -11
        TabAppearance.Status.Appearance.Font.Name = 'Tahoma'
        TabAppearance.Status.Appearance.Font.Style = []
        TabAppearance.BevelColor = 16765357
        TabAppearance.BevelColorDown = 16640730
        TabAppearance.BevelColorSelected = 16640730
        TabAppearance.BevelColorHot = 16640730
        TabAppearance.BevelColorDisabled = 16640730
        TabAppearance.Color = 16773091
        TabAppearance.ColorDown = 11196927
        TabAppearance.ColorDisabled = 16765357
        object m_EkspPathBB: TSpeedButton
          Left = 333
          Top = 37
          Width = 22
          Height = 22
          Hint = 'Wyszukaj numer harmonogramu'
          Glyph.Data = {
            CE070000424DCE07000000000000360000002800000024000000120000000100
            1800000000009807000000000000000000000000000000000000C8D0D4C8D0D4
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFC8D0D4C8D0D4C8D0D4C8D0D480808080808080808080
            8080808080808080808080808080808080808080808080808080808080808080
            C8D0D4C8D0D4C8D0D4FFFFFFCF6116CF6116CF6116CF6116CF6116CF6116CF61
            16CF6116CF6116CF6116CF6116CF6116CF6116CF6116FFFFFFC8D0D4C8D0D480
            8080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4
            C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4FFFFFFCF6116D57128D57128D571
            28D57128D57128D57128D57128D57128D57128D57128D57128D57128D57128D5
            7128CF6116FFFFFF808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4
            C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080FFFF
            FFCF6116D57128FFFFFFFFFFFFFFFFFFDB813ADB813ADB813ADB813ADB813ADB
            813AFFFFFFFFFFFFFFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0D4808080
            808080808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D48080808080808080
            80C8D0D4C8D0D4808080FFFFFFCF6116D57128FFFFFFE1914DE1914DE1914DE1
            914DE1914DE1914DE1914DE1914DE1914DE1914DFFFFFFD57128CF6116FFFFFF
            808080C8D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0
            D4C8D0D4C8D0D4C8D0D4808080C8D0D4C8D0D4808080FFFFFFCF6116D57128FF
            FFFFE1914DFFFFFFFFFFFFE7A05FFFFFFFFFFFFFE7A05FFFFFFFFFFFFFE1914D
            FFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0D4808080C8D0D48080808080
            80C8D0D4808080808080C8D0D4808080808080C8D0D4808080C8D0D4C8D0D480
            8080FFFFFFCF6116D57128FFFFFFE1914DFFFFFFFFFFFFEDB071FFFFFFFFFFFF
            EDB071FFFFFFFFFFFFE1914DFFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0
            D4808080C8D0D4808080808080C8D0D4808080808080C8D0D4808080808080C8
            D0D4808080C8D0D4C8D0D4808080FFFFFFCF6116D57128FFFFFFE1914DE7A05F
            EDB071F3C084F3C084F3C084F3C084EDB071E7A05FE1914DFFFFFFD57128CF61
            16FFFFFF808080C8D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8
            D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4C8D0D4808080FFFFFFCF6116
            D57128FFFFFFE1914DE7A05FEDB071F3C084F9D096F9D096F3C084EDB071E7A0
            5FE1914DFFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0D4808080C8D0D4C8
            D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4
            C8D0D4808080FFFFFFCF6116D57128FFFFFFE1914DE7A05FEDB071F3C084F9D0
            96F9D096F3C084EDB071E7A05FE1914DFFFFFFD57128CF6116FFFFFF808080C8
            D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4
            C8D0D4C8D0D4808080C8D0D4C8D0D4808080FFFFFFCF6116D57128FFFFFFE191
            4DE7A05FEDB071F3C084F3C084F3C084F3C084EDB071E7A05FE1914DFFFFFFD5
            7128CF6116FFFFFF808080C8D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8D0D4
            C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4C8D0D4808080FFFF
            FFCF6116D57128FFFFFFE1914DE7A05FEDB071EDB071EDB071EDB071EDB071ED
            B071E7A05FE1914DFFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0D4808080
            C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D48080
            80C8D0D4C8D0D4808080FFFFFFCF6116D57128FFFFFFE1914DE7A05FE7A05FE7
            A05FE7A05FE7A05FE7A05FE7A05FE7A05FE1914DFFFFFFD57128CF6116FFFFFF
            808080C8D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0
            D4C8D0D4C8D0D4C8D0D4808080C8D0D4C8D0D4808080FFFFFFCF6116D57128FF
            FFFFE1914DE1914DE1914DE1914DE1914DE1914DE1914DE1914DE1914DE1914D
            FFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0D4808080C8D0D4C8D0D4C8D0
            D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4C8D0D480
            8080FFFFFFCF6116D57128FFFFFFFFFFFFFFFFFFDB813ADB813ADB813ADB813A
            DB813ADB813AFFFFFFFFFFFFFFFFFFD57128CF6116FFFFFF808080C8D0D4C8D0
            D4808080808080808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D480808080
            8080808080C8D0D4C8D0D4808080FFFFFFCF6116D57128D57128D57128D57128
            D57128D57128D57128D57128D57128D57128D57128D57128D57128D57128CF61
            16FFFFFF808080C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8
            D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4808080C8D0D4FFFFFF
            CF6116CF6116CF6116CF6116CF6116CF6116CF6116CF6116CF6116CF6116CF61
            16CF6116CF6116CF6116FFFFFFC8D0D4C8D0D4808080C8D0D4C8D0D4C8D0D4C8
            D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4
            808080C8D0D4C8D0D4C8D0D4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC8D0D4C8D0D4C8D0D4C8
            D0D4808080808080808080808080808080808080808080808080808080808080
            808080808080808080808080C8D0D4C8D0D4}
          NumGlyphs = 2
          OnClick = m_EkspPathBBClick
        end
        object Label6: TLabel
          Left = 16
          Top = 16
          Width = 134
          Height = 13
          Caption = 'Plik konfiguracyjny eksportu'
          Transparent = True
        end
        object Label7: TLabel
          Left = 18
          Top = 74
          Width = 166
          Height = 13
          Caption = 'Nazwa wynikowego pliku  eksportu'
          Transparent = True
        end
        object m_EkspPathED: TEdit
          Left = 16
          Top = 36
          Width = 311
          Height = 21
          TabOrder = 0
          Text = 'm_EkspPathED'
        end
        object m_EkspFileNameED: TEdit
          Left = 18
          Top = 93
          Width = 311
          Height = 21
          TabOrder = 1
          Text = 'dane'
        end
      end
      object AdvTabSet1: TAdvTabSet
        Left = 176
        Top = 24
        Width = 185
        Height = 21
        Version = '1.7.1.3'
        ActiveFont.Charset = DEFAULT_CHARSET
        ActiveFont.Color = clWindowText
        ActiveFont.Height = -11
        ActiveFont.Name = 'Tahoma'
        ActiveFont.Style = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        AdvTabs = <>
        FreeOnClose = False
        GradientDirection = gdVertical
        TabMargin.LeftMargin = 2
        TabMargin.TopMargin = 2
        TabMargin.RightMargin = 0
        TabOverlap = 0
      end
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 186
    Width = 369
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
    Fill.Color = 16511718
    Fill.ColorTo = 15654350
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
      369
      33)
    object m_CancelBB: TAdvSmoothButton
      Left = 228
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
      ModalResult = 2
    end
    object m_SaveBB: TAdvSmoothButton
      Left = 300
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
  object m_WydzDS: TDataSource
    Left = 104
    Top = 160
  end
  object m_EkspPathOD: TOpenDialog
    FileName = 'export.ini'
    Filter = 'Plik eksportu|*export.ini|Plik ini|*.ini|Dowolny plik|*.*'
    Left = 176
    Top = 168
  end
end
