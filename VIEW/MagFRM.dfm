object _MagFRM: T_MagFRM
  Left = 635
  Top = 231
  Caption = 'Kartoteka'
  ClientHeight = 724
  ClientWidth = 1195
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 920
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  WindowState = wsMaximized
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_BottP: TAdvSmoothPanel
    Left = 0
    Top = 691
    Width = 1195
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
    TabOrder = 0
    DesignSize = (
      1195
      33)
    object AdvSmoothButton3: TAdvSmoothButton
      Left = 1095
      Top = 6
      Width = 97
      Height = 23
      Anchors = [akRight, akBottom]
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
      OnClick = AdvSmoothButton3Click
    end
    object m_DelSprzBB: TAdvSmoothButton
      Left = 10
      Top = 6
      Width = 84
      Height = 21
      Hint = 'Szukaj nr KUT'
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
      Caption = 'Usu'#324' sprz'#281't'
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      OnClick = m_DelSprzBBClick
    end
  end
  inline m_SzukajFRA: T_SzukajFRA
    Left = 0
    Top = 0
    Width = 1195
    Height = 62
    Align = alTop
    TabOrder = 1
    ExplicitWidth = 1195
    ExplicitHeight = 62
    inherited m_TopP: TAdvSmoothPanel
      Width = 1195
      Height = 62
      ExplicitWidth = 1195
      ExplicitHeight = 62
    end
  end
  object m_MainP: TAdvSmoothPanel
    Left = 0
    Top = 62
    Width = 1195
    Height = 629
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
    object m_RightP: TAdvSmoothPanel
      Left = 107
      Top = 201
      Width = 1088
      Height = 428
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
      inline m_DokFRA: T_DokFRA
        Left = 0
        Top = 0
        Width = 1088
        Height = 428
        Align = alClient
        TabOrder = 3
        Visible = False
        ExplicitWidth = 1088
        ExplicitHeight = 428
        inherited m_BottomASP: TAdvSmoothPanel
          Width = 1088
          Height = 397
          ExplicitWidth = 1088
          ExplicitHeight = 397
          inherited DBAdvGrid1: TDBAdvGrid
            Width = 1088
            Height = 397
            ExplicitWidth = 1088
            ExplicitHeight = 397
          end
        end
        inherited AdvSmoothPanel1: TAdvSmoothPanel
          Top = 397
          Width = 1088
          ExplicitTop = 397
          ExplicitWidth = 1088
        end
      end
      inline m_KosztyFRA: T_KosztyFRA
        Left = 0
        Top = 0
        Width = 1088
        Height = 428
        Align = alClient
        TabOrder = 0
        Visible = False
        ExplicitWidth = 1088
        ExplicitHeight = 428
        inherited m_TopP: TAdvSmoothPanel
          Width = 1088
          Height = 370
          ExplicitWidth = 1088
          ExplicitHeight = 370
          inherited m_DBG: TDBGrid
            Width = 1088
            Height = 370
          end
        end
        inherited AdvSmoothPanel1: TAdvSmoothPanel
          Top = 399
          Width = 1088
          ExplicitTop = 399
          ExplicitWidth = 1088
          inherited AdvSmoothButton1: TAdvSmoothButton
            OnClick = _KosztyFRA1AdvSmoothButton1Click
          end
          inherited AdvSmoothButton2: TAdvSmoothButton
            OnClick = _KosztyFRA1AdvSmoothButton2Click
          end
        end
        inherited AdvSmoothPanel2: TAdvSmoothPanel
          Width = 1088
          ExplicitWidth = 1088
        end
      end
      inline m_PowiadomFRA: T_PowiadomFRA
        Left = 0
        Top = 301
        Width = 681
        Height = 240
        TabOrder = 1
        Visible = False
        ExplicitTop = 301
        ExplicitWidth = 681
        inherited AdvSmoothPanel1: TAdvSmoothPanel
          Width = 681
          ExplicitWidth = 681
        end
        inherited m_TopP: TAdvSmoothPanel
          Width = 681
          ExplicitWidth = 681
          inherited m_DBG: TDBGrid
            Width = 681
          end
        end
        inherited AdvSmoothPanel2: TAdvSmoothPanel
          Width = 681
          ExplicitWidth = 681
        end
      end
      inline m_KutyFRA: T_KutyFRA
        Left = 0
        Top = 0
        Width = 1088
        Height = 428
        Align = alClient
        TabOrder = 2
        Visible = False
        ExplicitWidth = 1088
        ExplicitHeight = 428
        inherited m_BottomPA: TAdvSmoothPanel
          Top = 396
          Width = 1088
          ExplicitTop = 396
          ExplicitWidth = 1088
          inherited m_NewBT: TAdvSmoothButton
            OnClick = m_KutyFRAm_NewBTClick
          end
          inherited m_EditBT: TAdvSmoothButton
            OnClick = m_KutyFRAm_EditBTClick
          end
          inherited m_DelBT: TAdvSmoothButton
            OnClick = m_KutyFRAm_DelBTClick
          end
        end
        inherited m_TopP: TAdvSmoothPanel
          Width = 1088
          Height = 396
          ExplicitWidth = 1088
          ExplicitHeight = 396
          inherited m_AG: TDBAdvGrid
            Width = 1088
            Height = 396
            Columns = <
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'SYGN_ZLECENIA'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Sygnatura'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 100
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'ID_HARM'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Nr harm.'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'KOD_WARSZTATU'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'W/t'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 30
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'DATA_WYST'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Data wyst.'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 65
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'ZADANIE'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Zadanie'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 306
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'LICZBA_RBH'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'RBH nom.'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 55
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'WYK_RBH'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'RBH wyk.'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 55
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'WYK_IL'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Ilo'#347#263
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 30
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'DATA_ZAK'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Data zak.'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 65
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'DATA_ZDA_KUT'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                Header = 'Data zdania'
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 66
              end
              item
                Borders = []
                BorderPen.Color = clSilver
                CheckFalse = 'N'
                CheckTrue = 'Y'
                Color = clWindow
                FieldName = 'UWAGI'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                HeaderFont.Charset = DEFAULT_CHARSET
                HeaderFont.Color = clWindowText
                HeaderFont.Height = -11
                HeaderFont.Name = 'Tahoma'
                HeaderFont.Style = []
                PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
                PrintFont.Charset = DEFAULT_CHARSET
                PrintFont.Color = clWindowText
                PrintFont.Height = -11
                PrintFont.Name = 'Tahoma'
                PrintFont.Style = []
                Width = 261
              end>
            ExplicitLeft = 3
            ExplicitTop = 1
            ExplicitWidth = 1088
            ExplicitHeight = 396
            ColWidths = (
              100
              50
              30
              65
              306
              55
              55
              30
              65
              66
              261)
          end
        end
      end
    end
    object m_LeftP: TAdvSmoothPanel
      Left = 0
      Top = 201
      Width = 107
      Height = 428
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
      Align = alLeft
      TabOrder = 1
      DesignSize = (
        107
        428)
      object m_KUTBT: TAdvSmoothButton
        Left = 3
        Top = 6
        Width = 101
        Height = 37
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
        Caption = 'KUT'
        Color = 16644337
        TabOrder = 0
        Version = '1.6.9.1'
        OnClick = m_KUTBTClick
      end
      object AdvSmoothButton1: TAdvSmoothButton
        Left = 3
        Top = 82
        Width = 101
        Height = 37
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
        Caption = 'POWIADOMIENIA'
        Color = 16644337
        TabOrder = 1
        Visible = False
        Version = '1.6.9.1'
      end
      object AdvSmoothButton4: TAdvSmoothButton
        Left = 3
        Top = 44
        Width = 101
        Height = 37
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
        Caption = 'DOKUMENTY'
        Color = 16644337
        TabOrder = 2
        Version = '1.6.9.1'
        OnClick = AdvSmoothButton4Click
      end
    end
    object m_TopP: TAdvSmoothPanel
      Left = 0
      Top = 0
      Width = 1195
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
      Align = alTop
      TabOrder = 2
      DesignSize = (
        1195
        201)
      inline m_NaglMagFRA: T_NaglMagFRA
        Left = 0
        Top = 0
        Width = 1195
        Height = 201
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 1195
        ExplicitHeight = 201
        inherited m_TopP: TAdvSmoothPanel
          Width = 1195
          Height = 201
          ExplicitWidth = 1195
          ExplicitHeight = 201
          inherited AdvSmoothPanel2: TAdvSmoothPanel
            inherited DBEdit10: TDBEdit
              Left = 14
              ExplicitLeft = 14
            end
          end
          inherited AdvSmoothPanel4: TAdvSmoothPanel
            Left = 3556
            ExplicitLeft = 3556
          end
        end
      end
      object m_NewMagBT: TAdvSmoothButton
        Left = 1081
        Top = 3
        Width = 112
        Height = 21
        Hint = 'Szukaj nr KUT'
        Anchors = [akRight]
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
        Caption = 'Nowa pozycja'
        Color = 16644337
        TabOrder = 1
        Version = '1.6.9.1'
      end
      object m_EditMagBT: TAdvSmoothButton
        Left = 1080
        Top = 30
        Width = 112
        Height = 21
        Hint = 'Szukaj nr KUT'
        Anchors = [akRight]
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
        Caption = 'Edycja magazynu'
        Color = 16644337
        TabOrder = 2
        Version = '1.6.9.1'
      end
      object m_CloseMagBT: TAdvSmoothButton
        Left = 1080
        Top = 57
        Width = 112
        Height = 21
        Hint = 'Szukaj nr KUT'
        Anchors = [akRight]
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
        Caption = 'Koniec rem.'
        Color = 16644337
        TabOrder = 3
        Visible = False
        Version = '1.6.9.1'
      end
      object AdvSmoothPanel5: TAdvSmoothPanel
        Left = 782
        Top = 6
        Width = 293
        Height = 188
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
        Fill.GradientType = gtNone
        Fill.GradientMirrorType = gtNone
        Fill.BorderColor = 14922381
        Fill.Rounding = 8
        Fill.ShadowOffset = 0
        Fill.Glow = gmGradient
        Version = '1.0.9.2'
        Align = alCustom
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 4
        object Label21: TLabel
          Left = 12
          Top = 7
          Width = 32
          Height = 13
          Caption = 'Koszty'
          Transparent = True
        end
        inline m_SumKosztyFRA: T_KUTkosztySumFRA
          Left = 6
          Top = 29
          Width = 278
          Height = 151
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 0
          ExplicitLeft = 6
          ExplicitTop = 29
        end
      end
    end
  end
end
