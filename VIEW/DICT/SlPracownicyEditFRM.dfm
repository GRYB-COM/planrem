inherited _SlPracownicyEditFRM: T_SlPracownicyEditFRM
  Left = 582
  Top = 335
  ActiveControl = m_stpCB
  Caption = 'Pracownicy'
  ClientHeight = 463
  ClientWidth = 440
  ExplicitWidth = 446
  ExplicitHeight = 488
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 430
    Width = 440
    ExplicitTop = 430
    ExplicitWidth = 440
    inherited m_CancelBB: TAdvSmoothButton
      Left = 296
      ExplicitLeft = 296
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 368
      ExplicitLeft = 368
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 440
    Height = 430
    ExplicitWidth = 440
    ExplicitHeight = 430
    object Label1: TLabel
      Left = 108
      Top = 12
      Width = 44
      Height = 13
      Caption = 'Nazwisko'
      Transparent = True
    end
    object Label2: TLabel
      Left = 281
      Top = 12
      Width = 20
      Height = 13
      Caption = 'Imi'#281
      Transparent = True
    end
    object Label3: TLabel
      Left = 12
      Top = 12
      Width = 36
      Height = 13
      Caption = 'Stopie'#324
      Transparent = True
    end
    object Label4: TLabel
      Left = 108
      Top = 106
      Width = 54
      Height = 13
      Caption = 'Stanowisko'
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 107
      Width = 28
      Height = 13
      Caption = 'Kadra'
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 64
      Width = 41
      Height = 13
      Caption = 'Kom'#243'rka'
      Transparent = True
    end
    object Label7: TLabel
      Left = 13
      Top = 323
      Width = 49
      Height = 13
      Caption = 'Etat prod.'
      Transparent = True
    end
    object Label8: TLabel
      Left = 13
      Top = 372
      Width = 65
      Height = 13
      Caption = 'Stawka godz.'
      Transparent = True
    end
    object Label12: TLabel
      Left = 13
      Top = 268
      Width = 20
      Height = 13
      Caption = 'Etat'
      Transparent = True
    end
    object Label13: TLabel
      Left = 13
      Top = 161
      Width = 73
      Height = 13
      Caption = 'Zatrudniony od'
      Transparent = True
    end
    object Label9: TLabel
      Left = 12
      Top = 217
      Width = 12
      Height = 13
      Caption = 'do'
      Transparent = True
    end
    object m_NazED: TDBEdit
      Left = 108
      Top = 28
      Width = 160
      Height = 21
      DataField = 'NAZWISKO'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_ImED: TDBEdit
      Left = 281
      Top = 28
      Width = 145
      Height = 21
      DataField = 'IMIE'
      DataSource = m_DS
      TabOrder = 2
    end
    object m_stpCB: TDBLookupComboBox
      Left = 12
      Top = 28
      Width = 90
      Height = 21
      DataField = 'ID_STOPNIA'
      DataSource = m_DS
      KeyField = 'ID_STOPNIA'
      ListField = 'NAZWA'
      ListSource = m_stpDS
      TabOrder = 0
    end
    object m_stnCB: TDBLookupComboBox
      Left = 108
      Top = 123
      Width = 318
      Height = 21
      DataField = 'ID_STANOWISKA'
      DataSource = m_DS
      KeyField = 'ID_STANOWISKA'
      ListField = 'NAZWA;KOD'
      ListSource = m_stnDS
      TabOrder = 5
    end
    object m_kdrCB: TDBLookupComboBox
      Left = 12
      Top = 123
      Width = 90
      Height = 21
      DataField = 'KADRA'
      DataSource = m_DS
      KeyField = 'KOD'
      ListField = 'NAZWA'
      ListSource = m_kdrDS
      TabOrder = 4
    end
    object m_komCB: TDBLookupComboBox
      Left = 12
      Top = 80
      Width = 414
      Height = 21
      DataField = 'ID_KOMORKI'
      DataSource = m_DS
      DropDownWidth = 300
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_komDS
      TabOrder = 3
    end
    object m_EtataPrED: TDBEdit
      Left = 13
      Top = 339
      Width = 87
      Height = 21
      DataField = 'ETAT_PR'
      DataSource = m_DS
      TabOrder = 9
    end
    object m_StawkaGodzED: TDBEdit
      Left = 13
      Top = 388
      Width = 87
      Height = 21
      DataField = 'ETAT_NPR'
      DataSource = m_DS
      TabOrder = 10
    end
    object m_EtatED: TDBEdit
      Left = 13
      Top = 284
      Width = 87
      Height = 21
      DataField = 'ETAT_KOR'
      DataSource = m_DS
      TabOrder = 8
    end
    object m_DataOdDTP: TAdvDBDateTimePicker
      Left = 13
      Top = 180
      Width = 89
      Height = 21
      Date = 40961.629641203710000000
      Time = 40961.629641203710000000
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 6
      OnKeyDown = m_DataDoDTPKeyDown
      BorderStyle = bsSingle
      Ctl3D = True
      DateTime = 40961.629641203710000000
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_OD'
      DataSource = m_DS
    end
    object m_DataDoDTP: TAdvDBDateTimePicker
      Left = 13
      Top = 236
      Width = 87
      Height = 21
      Date = 40961.629641203710000000
      Time = 40961.629641203710000000
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 7
      OnKeyDown = m_DataDoDTPKeyDown
      BorderStyle = bsSingle
      Ctl3D = True
      DateTime = 40961.629641203710000000
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_DO'
      DataSource = m_DS
    end
    object m_WolneTPC: TAdvSmoothTabPager
      Left = 108
      Top = 161
      Width = 318
      Height = 248
      ActivePage = AdvSmoothTabPager12
      Color = 15587527
      TabPosition = tpTopLeft
      TabSettings.LeftMargin = 1
      TabSettings.RightMargin = 1
      TabSettings.StartMargin = 1
      TabSettings.Spacing = 1
      TabSettings.Width = 75
      TabReorder = False
      TabOrder = 11
      object AdvSmoothTabPage1: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 316
        Height = 220
        Caption = 'Etaty'
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
        object m_EtatyGR: TDBGrid
          Left = 19
          Top = 3
          Width = 294
          Height = 185
          Ctl3D = True
          DataSource = m_EtatyDS
          DrawingStyle = gdsGradient
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          ParentCtl3D = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnDblClick = m_EdytujClick
          Columns = <
            item
              Expanded = False
              FieldName = 'DATA_OD'
              Title.Caption = 'Data od.'
              Width = 60
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'ETAT'
              Title.Caption = 'Etat'
              Width = 40
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'ETAT_PROD'
              Title.Caption = 'Etat pr.'
              Width = 40
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DNIOWKA'
              Title.Caption = 'Stawka godz.'
              Width = 70
              Visible = True
            end>
        end
        object m_AddEtatBT: TAdvSmoothButton
          Left = 11
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Dodaj'
          Color = 16311241
          TabOrder = 1
          Version = '1.6.9.1'
          OnClick = m_AddEtatBTClick
        end
        object m_EdEtatBT: TAdvSmoothButton
          Left = 73
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Zmie'#324
          Color = 16311241
          TabOrder = 2
          Version = '1.6.9.1'
          OnClick = m_EdEtatBTClick
        end
        object m_DelEtatBB: TAdvSmoothButton
          Left = 135
          Top = 196
          Width = 56
          Height = 21
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
          Color = 16311241
          TabOrder = 3
          Version = '1.6.9.1'
          OnClick = m_DelEtatBBClick
        end
      end
      object AdvSmoothTabPager11: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 316
        Height = 220
        Caption = 'Urlopy'
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
        object m_urlopGrid: TDBGrid
          Left = 19
          Top = 5
          Width = 294
          Height = 185
          Ctl3D = True
          DataSource = m_urlopDS
          DrawingStyle = gdsGradient
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          ParentCtl3D = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnDblClick = m_EdytujClick
          Columns = <
            item
              Expanded = False
              FieldName = 'NAZ_MIES'
              Title.Caption = 'Miesi'#261'c'
              Width = 80
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'URLOP'
              Title.Caption = 'Urlop'
              Visible = True
            end>
        end
        object m_Dodaj: TAdvSmoothButton
          Left = 11
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Dodaj'
          Color = 16311241
          TabOrder = 1
          Version = '1.6.9.1'
          OnClick = m_DodajClick
        end
        object m_Edytuj: TAdvSmoothButton
          Left = 73
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Zmie'#324
          Color = 16311241
          TabOrder = 2
          Version = '1.6.9.1'
          OnClick = m_EdytujClick
        end
        object m_Usun: TAdvSmoothButton
          Left = 135
          Top = 196
          Width = 56
          Height = 21
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
          Color = 16311241
          TabOrder = 3
          Version = '1.6.9.1'
          OnClick = m_UsunClick
        end
      end
      object AdvSmoothTabPager12: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 316
        Height = 220
        Caption = 'Delegacje'
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
        object m_delGrid: TDBGrid
          Left = 11
          Top = 5
          Width = 294
          Height = 185
          Ctl3D = True
          DataSource = m_delDS
          DrawingStyle = gdsGradient
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          ParentCtl3D = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnDblClick = m_EdytujDClick
          Columns = <
            item
              Expanded = False
              FieldName = 'ROK'
              Title.Caption = 'Rok'
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'NAZ_MIES'
              Title.Caption = 'Miesi'#261'c'
              Width = 65
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'KOD'
              Title.Caption = 'Kom'#243'rka'
              Width = 48
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'DNI'
              Title.Caption = 'Dni'
              Visible = True
            end>
        end
        object m_DodajD: TAdvSmoothButton
          Left = 11
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Dodaj'
          Color = 16311241
          TabOrder = 1
          Version = '1.6.9.1'
          OnClick = m_DodajDClick
        end
        object m_EdytujD: TAdvSmoothButton
          Left = 73
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Zmie'#324
          Color = 16311241
          TabOrder = 2
          Version = '1.6.9.1'
          OnClick = m_EdytujDClick
        end
        object m_UsunD: TAdvSmoothButton
          Left = 135
          Top = 196
          Width = 56
          Height = 21
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
          Color = 16311241
          TabOrder = 3
          Version = '1.6.9.1'
          OnClick = m_UsunDClick
        end
      end
      object AdvSmoothTabPager13: TAdvSmoothTabPage
        Left = 1
        Top = 26
        Width = 316
        Height = 220
        Caption = 'Dni wolne'
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
        object m_DodajZ: TAdvSmoothButton
          Left = 11
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Dodaj'
          Color = 16311241
          TabOrder = 0
          Version = '1.6.9.1'
          OnClick = m_DodajZClick
        end
        object m_EdytujZ: TAdvSmoothButton
          Left = 73
          Top = 196
          Width = 56
          Height = 21
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
          Caption = 'Zmie'#324
          Color = 16311241
          TabOrder = 1
          Version = '1.6.9.1'
          OnClick = m_EdytujZClick
        end
        object m_UsunZ: TAdvSmoothButton
          Left = 135
          Top = 196
          Width = 56
          Height = 21
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
          Color = 16311241
          TabOrder = 2
          Version = '1.6.9.1'
          OnClick = m_UsunZClick
        end
        object m_WolneGR: TDBGrid
          Left = 12
          Top = 5
          Width = 293
          Height = 185
          Ctl3D = True
          DataSource = m_zwDS
          DrawingStyle = gdsGradient
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          ParentCtl3D = False
          TabOrder = 3
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnDblClick = m_EdytujDClick
          Columns = <
            item
              Expanded = False
              FieldName = 'NAZ_MIES'
              Title.Caption = 'Miesi'#261'c'
              Width = 65
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'KOD_ZW'
              Title.Caption = 'Kod'
              Width = 30
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'LICZBA_DNI'
              Title.Caption = 'Liczba dni'
              Width = 55
              Visible = True
            end>
        end
      end
    end
  end
  inherited m_DS: TDataSource
    Left = 8
    Top = 416
  end
  object m_urlopDS: TDataSource
    Left = 136
    Top = 328
  end
  object m_stpDS: TDataSource
    Left = 56
    Top = 416
  end
  object m_stnDS: TDataSource
    Left = 192
    Top = 328
  end
  object m_komDS: TDataSource
    Left = 248
    Top = 328
  end
  object m_kdrDS: TDataSource
    Left = 368
    Top = 328
  end
  object m_delDS: TDataSource
    Left = 304
    Top = 328
  end
  object m_zwDS: TDataSource
    Left = 344
    Top = 248
  end
  object m_EtatyDS: TDataSource
    Left = 144
    Top = 272
  end
end
