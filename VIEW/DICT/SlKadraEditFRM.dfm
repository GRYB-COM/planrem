inherited _SlKadraEditFRM: T_SlKadraEditFRM
  Left = 520
  Top = 207
  ActiveControl = edKod
  Caption = 'Kadra'
  ClientHeight = 228
  ClientWidth = 368
  ExplicitWidth = 374
  ExplicitHeight = 253
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 195
    Width = 368
    ExplicitTop = 201
    ExplicitWidth = 368
    object Label3: TLabel [0]
      Left = 2
      Top = 0
      Width = 216
      Height = 33
      AutoSize = False
      Caption = 
        'Zatrudnienie z dok'#322'adno'#347'ci'#261' co do miesi'#261'ca pojedy'#324'cze dni wyr'#243'wn' +
        'ywa'#263' delegacjami'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Transparent = True
      WordWrap = True
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 224
      ExplicitLeft = 224
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 296
      ExplicitLeft = 296
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 368
    Height = 195
    ExplicitWidth = 368
    ExplicitHeight = 195
    object Label7: TLabel
      Left = 12
      Top = 12
      Width = 18
      Height = 13
      Caption = 'Kod'
      Transparent = True
    end
    object Label1: TLabel
      Left = 87
      Top = 12
      Width = 32
      Height = 13
      Caption = 'Nazwa'
      Transparent = True
    end
    object Label2: TLabel
      Left = 178
      Top = 12
      Width = 61
      Height = 13
      Caption = 'Pe'#322'na nazwa'
      Transparent = True
    end
    object Label4: TLabel
      Left = 12
      Top = 56
      Width = 39
      Height = 13
      Caption = 'Przerwa'
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 98
      Width = 32
      Height = 13
      Caption = 'S'#322'u'#380'ba'
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 140
      Width = 41
      Height = 13
      Caption = 'Choroba'
      Transparent = True
    end
    object Label10: TLabel
      Left = 87
      Top = 56
      Width = 98
      Height = 13
      Caption = 'Godziny szkoleniowe'
      Transparent = True
    end
    object m_szkolGrid: TDBGrid
      Left = 87
      Top = 72
      Width = 208
      Height = 105
      Ctl3D = True
      DataSource = m_szkolDS
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentCtl3D = False
      TabOrder = 6
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
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'RBH'
          Title.Caption = 'Godziny'
          Width = 72
          Visible = True
        end>
    end
    object m_Dodaj: TAdvSmoothButton
      Left = 301
      Top = 72
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
      TabOrder = 7
      Version = '1.6.9.1'
      OnClick = m_DodajClick
    end
    object m_Edytuj: TAdvSmoothButton
      Left = 301
      Top = 101
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
      TabOrder = 8
      Version = '1.6.9.1'
      OnClick = m_EdytujClick
    end
    object m_Usun: TAdvSmoothButton
      Left = 301
      Top = 130
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
      TabOrder = 9
      Version = '1.6.9.1'
      OnClick = m_UsunClick
    end
    object edKod: TDBEdit
      Left = 12
      Top = 28
      Width = 69
      Height = 21
      DataField = 'KOD'
      DataSource = m_DS
      TabOrder = 0
    end
    object edNazwa: TDBEdit
      Left = 87
      Top = 28
      Width = 85
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
    object DBEdit2: TDBEdit
      Left = 178
      Top = 28
      Width = 179
      Height = 21
      DataField = 'PELNA_NAZWA'
      DataSource = m_DS
      TabOrder = 2
    end
    object DBEdit5: TDBEdit
      Left = 12
      Top = 72
      Width = 60
      Height = 21
      DataField = 'PRZERWA'
      DataSource = m_DS
      TabOrder = 3
    end
    object DBEdit6: TDBEdit
      Left = 12
      Top = 114
      Width = 60
      Height = 21
      DataField = 'SLUZBA'
      DataSource = m_DS
      TabOrder = 4
    end
    object DBEdit7: TDBEdit
      Left = 12
      Top = 156
      Width = 60
      Height = 21
      DataField = 'CHOROBA'
      DataSource = m_DS
      TabOrder = 5
    end
  end
  inherited m_DS: TDataSource
    Left = 104
    Top = 120
  end
  object m_szkolDS: TDataSource
    Left = 160
    Top = 120
  end
end
