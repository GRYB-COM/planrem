object _ImporterWizjaJB: T_ImporterWizjaJB
  Left = 414
  Top = 372
  BorderIcons = [biSystemMenu]
  Caption = 'Import danych'
  ClientHeight = 148
  ClientWidth = 461
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 461
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
    DesignSize = (
      461
      148)
    object m_CaptLB: TLabel
      Left = 12
      Top = 29
      Width = 399
      Height = 13
      Alignment = taCenter
      Caption = 
        'Import zostanie przeprowadzony z danych nast'#281'puj'#261'cych warsztat'#243'w' +
        ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object m_WarLB: TLabel
      Left = 13
      Top = 45
      Width = 445
      Height = 32
      Anchors = [akLeft, akTop, akRight, akBottom]
      AutoSize = False
      Caption = 
        'Eksport danych zostanie przeprowadzony na rzecz nast'#281'puj'#261'cych wa' +
        'rsztat'#243'w:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
      WordWrap = True
      ExplicitWidth = 447
      ExplicitHeight = 34
    end
    object m_DataLB: TLabel
      Left = 13
      Top = 9
      Width = 399
      Height = 13
      Alignment = taCenter
      Caption = 
        'Import zostanie przeprowadzony z danych nast'#281'puj'#261'cych warsztat'#243'w' +
        ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object m_progressBar: TAdvSmoothProgressBar
      Left = 111
      Top = 97
      Width = 342
      Height = 17
      Step = 1.000000000000000000
      Maximum = 100.000000000000000000
      Appearance.BackGroundFill.Color = 16771287
      Appearance.BackGroundFill.ColorTo = 16765615
      Appearance.BackGroundFill.ColorMirror = clNone
      Appearance.BackGroundFill.ColorMirrorTo = clNone
      Appearance.BackGroundFill.BorderColor = clSilver
      Appearance.BackGroundFill.Rounding = 0
      Appearance.BackGroundFill.ShadowOffset = 0
      Appearance.ProgressFill.Color = 16705764
      Appearance.ProgressFill.ColorTo = 9649920
      Appearance.ProgressFill.ColorMirror = 16765357
      Appearance.ProgressFill.ColorMirrorTo = 16767936
      Appearance.ProgressFill.GradientMirrorType = gtVertical
      Appearance.ProgressFill.BorderColor = 16765357
      Appearance.ProgressFill.Rounding = 0
      Appearance.ProgressFill.ShadowOffset = 0
      Appearance.Font.Charset = DEFAULT_CHARSET
      Appearance.Font.Color = clWindowText
      Appearance.Font.Height = -11
      Appearance.Font.Name = 'Tahoma'
      Appearance.Font.Style = []
      Appearance.ProgressFont.Charset = DEFAULT_CHARSET
      Appearance.ProgressFont.Color = clWindowText
      Appearance.ProgressFont.Height = -11
      Appearance.ProgressFont.Name = 'Tahoma'
      Appearance.ProgressFont.Style = []
      Appearance.ValueFormat = '%.0f%%'
      Version = '1.5.0.1'
      MarqueeInterval = 1
      Anchors = [akLeft, akRight, akBottom]
    end
    object bbPrepareData: TAdvGlowButton
      Left = 12
      Top = 94
      Width = 93
      Height = 24
      Anchors = [akLeft, akBottom]
      AntiAlias = aaNone
      Caption = 'Wczytaj dane'
      ImageIndex = 12
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = bbPrepareDataClick
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
    object bbClose: TAdvGlowButton
      Left = 373
      Top = 121
      Width = 80
      Height = 24
      Anchors = [akRight, akBottom]
      AntiAlias = aaNone
      Caption = 'Zamknij'
      ImageIndex = 12
      NotesFont.Charset = DEFAULT_CHARSET
      NotesFont.Color = clWindowText
      NotesFont.Height = -11
      NotesFont.Name = 'Tahoma'
      NotesFont.Style = []
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = bbCloseClick
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
  object m_OpenDialog: TOpenDialog
    Filter = 'plik nieskompresowany PDRJ|*.pdrj|plik skomprezowany ZIP|*.zip'
    FilterIndex = 2
    Left = 264
    Top = 40
  end
end
