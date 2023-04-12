object _ListaOldHarmFRM: T_ListaOldHarmFRM
  Left = 0
  Top = 0
  Caption = 'Plan - harmonogram do przeniesiena'
  ClientHeight = 549
  ClientWidth = 998
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 45
    Width = 998
    Height = 473
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object m_HarmGR: TDBGrid
      Left = 0
      Top = 0
      Width = 998
      Height = 473
      Align = alClient
      Color = clWhite
      DataSource = m_HarmDS
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'ID_HARMONOGRAMU'
          Title.Caption = 'Nr harm.'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'JW_MIEJSCOWOSC'
          Title.Caption = 'Dostawca'
          Width = 151
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZ_REMONTU'
          Title.Caption = 'Rodz. rem.'
          Width = 58
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZ_SPRZETU'
          Title.Caption = 'Sprz'#281't'
          Width = 257
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ZADANIE'
          Title.Caption = 'Zadanie'
          Width = 318
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = 'ILOSC'
          Title.Alignment = taCenter
          Title.Caption = 'Ilo'#347#263
          Width = 57
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = 'PLAN_RBH'
          Title.Alignment = taCenter
          Title.Caption = 'RBH'
          Width = 57
          Visible = True
        end>
    end
  end
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 998
    Height = 45
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
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 15
      Top = 3
      Width = 44
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_WarCB: TDBLookupComboBox
      Left = 15
      Top = 21
      Width = 306
      Height = 21
      DropDownRows = 30
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarDS
      NullValueKey = 46
      TabOrder = 0
      OnCloseUp = m_WarCBCloseUp
    end
  end
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 518
    Width = 998
    Height = 31
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
    TabOrder = 2
    DesignSize = (
      998
      31)
    object m_SaveBB: TAdvSmoothButton
      Left = 918
      Top = 6
      Width = 68
      Height = 20
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
      OnClick = m_SaveBBClick
    end
    object m_MoveBB: TAdvSmoothButton
      Left = 3
      Top = 6
      Width = 68
      Height = 20
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
      Caption = 'Przenie'#347
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
    end
  end
  object m_HarmDS: TDataSource
    Left = 176
    Top = 72
  end
  object m_WarDS: TDataSource
    Left = 259
    Top = 72
  end
end
