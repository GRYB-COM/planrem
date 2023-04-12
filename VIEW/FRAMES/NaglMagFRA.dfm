object _NaglMagFRA: T_NaglMagFRA
  Left = 0
  Top = 0
  Width = 1012
  Height = 304
  Align = alClient
  TabOrder = 0
  ExplicitWidth = 451
  object m_TopP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 1012
    Height = 304
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
    ExplicitWidth = 451
    object AdvSmoothPanel1: TAdvSmoothPanel
      Left = 7
      Top = 7
      Width = 245
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
      TabOrder = 0
      object Label10: TLabel
        Left = 12
        Top = 7
        Width = 36
        Height = 13
        Caption = 'Nazwa:'
        Transparent = True
      end
      object Label11: TLabel
        Left = 12
        Top = 51
        Width = 93
        Height = 13
        Caption = 'Dostarczono przez:'
        Transparent = True
      end
      object Label12: TLabel
        Left = 12
        Top = 95
        Width = 86
        Height = 13
        Caption = 'Nr pr. stanu tech.'
        Transparent = True
      end
      object Label13: TLabel
        Left = 192
        Top = 95
        Width = 26
        Height = 13
        Caption = 'Ilo'#347#263':'
        Transparent = True
      end
      object Label14: TLabel
        Left = 12
        Top = 139
        Width = 73
        Height = 13
        Caption = 'Data przyjecia:'
        Transparent = True
      end
      object Label15: TLabel
        Left = 124
        Top = 139
        Width = 88
        Height = 13
        Caption = 'Nr prot. przyjecia:'
        Transparent = True
      end
      object Label3: TLabel
        Left = 102
        Top = 95
        Width = 66
        Height = 13
        Caption = 'Nr fabryczny:'
        Transparent = True
      end
      object m_IloscDBE: TDBEdit
        Left = 192
        Top = 114
        Width = 41
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'ILOSC'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 0
      end
      object DBEdit1: TDBEdit
        Left = 12
        Top = 158
        Width = 106
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'DATA_PRZYJ'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 1
      end
      object DBEdit2: TDBEdit
        Left = 124
        Top = 158
        Width = 109
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'PROT_PRZYJ'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 2
      end
      object DBEdit3: TDBEdit
        Left = 12
        Top = 114
        Width = 86
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'PODSTAWA'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 3
      end
      object DBEdit6: TDBEdit
        Left = 12
        Top = 70
        Width = 221
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'JW_MIEJSCOWOSC'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 4
      end
      object DBEdit7: TDBEdit
        Left = 12
        Top = 26
        Width = 221
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'SPRZET'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 5
      end
      object DBEdit11: TDBEdit
        Left = 102
        Top = 114
        Width = 86
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'NR_FABR'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 6
      end
    end
    object AdvSmoothPanel2: TAdvSmoothPanel
      Left = 258
      Top = 7
      Width = 240
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
      TabOrder = 1
      object Label17: TLabel
        Left = 12
        Top = 95
        Width = 65
        Height = 13
        Caption = 'Stan sprz'#281'tu:'
        Transparent = True
      end
      object Label20: TLabel
        Left = 124
        Top = 95
        Width = 100
        Height = 13
        Caption = 'Planowana data zak:'
        Transparent = True
      end
      object Label16: TLabel
        Left = 16
        Top = 7
        Width = 90
        Height = 13
        Caption = 'Warsztat wiod'#261'cy:'
        Transparent = True
      end
      object Label2: TLabel
        Left = 12
        Top = 51
        Width = 80
        Height = 13
        Caption = 'Rodzaj remontu:'
        Transparent = True
      end
      object Label1: TLabel
        Left = 12
        Top = 135
        Width = 104
        Height = 13
        Caption = 'Protok'#243#322' przekazania:'
        Transparent = True
      end
      object DBEdit8: TDBEdit
        Left = 12
        Top = 26
        Width = 218
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'NAZWA_WAR'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 0
      end
      object DBEdit9: TDBEdit
        Left = 12
        Top = 114
        Width = 106
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'STATUS'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 1
      end
      object DBEdit10: TDBEdit
        Left = 12
        Top = 70
        Width = 218
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'RODZAJ_REM'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 2
      end
      object DBEdit5: TDBEdit
        Left = 12
        Top = 154
        Width = 218
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'PROT_PRZEKAZ'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 3
      end
      object DBEdit4: TDBEdit
        Left = 124
        Top = 114
        Width = 106
        Height = 19
        Color = clInfoBk
        Ctl3D = False
        DataField = 'DATA_ZAK'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 4
      end
    end
    object AdvSmoothPanel4: TAdvSmoothPanel
      Left = 3373
      Top = 7
      Width = 112
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
      Anchors = [akTop, akRight]
      TabOrder = 2
      ExplicitLeft = 2812
      DesignSize = (
        112
        188)
      object AdvSmoothButton1: TAdvSmoothButton
        Left = 7
        Top = 39
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
        Caption = 'Usu'#324
        Color = 16644337
        TabOrder = 0
        Version = '1.6.9.1'
      end
      object AdvSmoothButton2: TAdvSmoothButton
        Left = 7
        Top = 8
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
        Caption = 'Edytuj'
        Color = 16644337
        TabOrder = 1
        Version = '1.6.9.1'
      end
    end
    object AdvSmoothPanel5: TAdvSmoothPanel
      Left = 504
      Top = 7
      Width = 272
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
      TabOrder = 3
      object Label21: TLabel
        Left = 12
        Top = 7
        Width = 29
        Height = 13
        Caption = 'Uwagi'
        Transparent = True
      end
      object m_UwagiDBM: TDBMemo
        Left = 12
        Top = 26
        Width = 249
        Height = 151
        Color = clInfoBk
        Ctl3D = False
        DataField = 'UWAGI'
        DataSource = m_DS
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 0
      end
    end
  end
  object m_DS: TDataSource
    Left = 204
    Top = 20
  end
end
