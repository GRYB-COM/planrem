inherited _pocztaPopFra: T_pocztaPopFra
  Left = 257
  Top = 158
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Odbieranie poczty'
  ClientHeight = 578
  ClientWidth = 700
  Constraints.MinHeight = 570
  Constraints.MinWidth = 708
  OnClose = FormClose
  ExplicitLeft = 257
  ExplicitTop = 158
  ExplicitWidth = 708
  ExplicitHeight = 612
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 700
    Height = 174
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
    Align = alTop
    TabOrder = 0
    inline m_pocztaLoginFrm: T_pocztaLoginFrm
      Left = 3
      Top = 3
      Width = 469
      Height = 118
      TabOrder = 0
      ExplicitLeft = 3
      ExplicitTop = 3
      ExplicitWidth = 469
      ExplicitHeight = 118
      inherited AdvSmoothPanel1: TAdvSmoothPanel
        Width = 469
        Height = 118
        ExplicitWidth = 469
        ExplicitHeight = 118
      end
    end
    object AdvGroupBox1: TAdvGroupBox
      Left = 479
      Top = 10
      Width = 218
      Height = 105
      BorderColor = 13542013
      RoundEdges = True
      TabOrder = 1
      object bbSprawdz: TAdvGlowButton
        Left = 24
        Top = 24
        Width = 80
        Height = 24
        Hint = 'Pobieranie nag'#322#243'wk'#243'w wiadomo'#347'ci'
        AntiAlias = aaNone
        Caption = 'Sprawd'#378
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = bbSprawdzClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object bbOdbierz: TAdvGlowButton
        Left = 116
        Top = 24
        Width = 80
        Height = 24
        Hint = 'Pobieranie wiadomo'#347'ci'
        AntiAlias = aaNone
        Caption = 'Odbierz'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = bbOdbierzClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object bbRozlacz: TAdvGlowButton
        Left = 68
        Top = 55
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Roz'#322#261'cz'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 2
        OnClick = bbRozlaczClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
    end
    object AdvGroupBox2: TAdvGroupBox
      Left = 3
      Top = 127
      Width = 694
      Height = 45
      BorderColor = 13542013
      RoundEdges = True
      TabOrder = 2
      object bbOdpowiedz: TAdvGlowButton
        Left = 116
        Top = 10
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Odpowiedz'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 0
        OnClick = bbOdpowiedzClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object bbPrzeslij: TAdvGlowButton
        Left = 202
        Top = 10
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Prze'#347'lij'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 1
        OnClick = bbPrzeslijClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object bbNowa: TAdvGlowButton
        Left = 24
        Top = 10
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Nowa'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 2
        OnClick = bbNowaClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object bbUsun: TAdvGlowButton
        Left = 338
        Top = 10
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Usu'#324
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 3
        OnClick = bbUsunClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
    end
  end
  object m_statusBar: TAdvOfficeStatusBar
    Left = 0
    Top = 559
    Width = 700
    Height = 19
    AnchorHint = False
    Panels = <
      item
        AppearanceStyle = psLight
        DateFormat = 'yyyy-MM-dd'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 80
      end
      item
        AppearanceStyle = psLight
        DateFormat = 'yyyy-MM-dd'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 100
      end
      item
        AppearanceStyle = psLight
        DateFormat = 'yyyy-MM-dd'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 130
      end
      item
        AppearanceStyle = psLight
        DateFormat = 'yyyy-MM-dd'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        TimeFormat = 'hh:mm:ss'
        Width = 50
      end>
    SimplePanel = True
    URLColor = clBlue
    Version = '1.3.0.2'
  end
  object AdvSmoothPanel2: TAdvSmoothPanel
    Left = 0
    Top = 174
    Width = 700
    Height = 385
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
    TabOrder = 2
    object AdvSmoothPanel3: TAdvSmoothPanel
      Left = 0
      Top = 316
      Width = 700
      Height = 69
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
      TabOrder = 0
      object Label1: TLabel
        Left = 65
        Top = 9
        Width = 75
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Za'#322#261'czniki'
      end
      object bbZapisz: TAdvGlowButton
        Left = 60
        Top = 28
        Width = 80
        Height = 24
        AntiAlias = aaNone
        Caption = 'Zapisz'
        ImageIndex = 12
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 0
        OnClick = bbZapiszClick
        Appearance.BorderColor = clGray
        Appearance.BorderColorHot = 4227327
        Appearance.ColorTo = cl3DLight
        Appearance.ColorChecked = 16111818
        Appearance.ColorCheckedTo = 16367008
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 16111818
        Appearance.ColorDownTo = 16367008
        Appearance.ColorHot = 8971519
        Appearance.ColorHotTo = clWhite
        Appearance.ColorMirrorTo = clBtnFace
        Appearance.ColorMirrorHot = 8121085
        Appearance.ColorMirrorHotTo = 109822
        Appearance.ColorMirrorDown = 16102556
        Appearance.ColorMirrorDownTo = 16768988
        Appearance.ColorMirrorChecked = 16102556
        Appearance.ColorMirrorCheckedTo = 16768988
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        DropDownDirection = ddRight
        DropDownSplit = False
      end
      object m_zalaczniki: TListBox
        Left = 179
        Top = 4
        Width = 518
        Height = 61
        ItemHeight = 13
        TabOrder = 1
      end
    end
    object AdvSmoothPanel4: TAdvSmoothPanel
      Left = 0
      Top = 0
      Width = 700
      Height = 316
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
      object AdvSplitter1: TAdvSplitter
        Left = 0
        Top = 166
        Width = 700
        Height = 3
        Cursor = crVSplit
        Align = alTop
        MinSize = 60
        ResizeStyle = rsLine
        Appearance.BorderColor = clNone
        Appearance.BorderColorHot = clNone
        Appearance.Color = clWhite
        Appearance.ColorTo = clSilver
        Appearance.ColorHot = clWhite
        Appearance.ColorHotTo = clGray
        GripStyle = sgDots
        ExplicitWidth = 325
      end
      object m_listaWiadomosci: TListView
        Left = 0
        Top = 0
        Width = 700
        Height = 166
        Align = alTop
        Checkboxes = True
        Columns = <
          item
            Caption = 'Nadawca'
            Width = 150
          end
          item
            Caption = 'Temat'
            Width = 370
          end
          item
            Caption = 'Data'
            Width = 80
          end
          item
            Caption = 'Za'#322#261'czniki'
            Width = 20
          end
          item
            Caption = 'Rozmiar'
            Width = 40
          end>
        Constraints.MinHeight = 60
        GridLines = True
        HideSelection = False
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnSelectItem = m_listaWiadomosciSelectItem
      end
      object m_wiadomosc: TMemo
        Left = 0
        Top = 169
        Width = 700
        Height = 147
        Align = alClient
        Constraints.MinHeight = 60
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 1
      end
    end
  end
  object m_saveDialog: TSaveDialog
    OnCanClose = m_saveDialogCanClose
    Left = 448
    Top = 224
  end
  object IdMessage1: TIdMessage
    AttachmentEncoding = 'UUE'
    BccList = <>
    CCList = <>
    Encoding = meDefault
    FromList = <
      item
      end>
    Recipients = <>
    ReplyTo = <>
    ConvertPreamble = True
    Left = 520
    Top = 216
  end
end