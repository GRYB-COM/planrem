object _FindHarmFRM: T_FindHarmFRM
  Left = 0
  Top = 0
  Caption = 'Znajd'#378' sprz'#281't'
  ClientHeight = 429
  ClientWidth = 649
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
  inline m_ListaHarmFRA: T_ListaHarmFRA
    Left = 0
    Top = 0
    Width = 649
    Height = 400
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 649
    ExplicitHeight = 400
    inherited m_TopPA: TAdvSmoothPanel
      Width = 649
      Height = 319
      ExplicitWidth = 649
      ExplicitHeight = 319
      inherited m_AG: TDBAdvGrid
        Width = 649
        Height = 319
        ExplicitWidth = 649
        ExplicitHeight = 319
      end
    end
    inherited m_SearchPA: TAdvSmoothPanel
      Width = 649
      ExplicitWidth = 649
    end
  end
  object m_BottomPA: TAdvSmoothPanel
    Left = 0
    Top = 400
    Width = 649
    Height = 29
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
    TabOrder = 1
    DesignSize = (
      649
      29)
    object m_OKBT: TAdvSmoothButton
      Left = 567
      Top = 3
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
      Caption = 'Wybierz'
      Color = 16644337
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = m_OKBTClick
    end
    object m_CancelBT: TAdvSmoothButton
      Left = 490
      Top = 3
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
      Caption = 'Anuluj'
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      ModalResult = 2
    end
  end
  object m_DS: TDataSource
    Left = 468
    Top = 168
  end
end
