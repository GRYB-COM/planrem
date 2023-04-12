object _KUTkosztySumFRA: T_KUTkosztySumFRA
  Left = 0
  Top = 0
  Width = 278
  Height = 151
  Ctl3D = False
  ParentCtl3D = False
  TabOrder = 0
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 278
    Height = 151
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
    object DBGrid1: TDBGrid
      Left = 0
      Top = 0
      Width = 278
      Height = 151
      Align = alClient
      Color = clInfoBk
      DataSource = m_DS
      Options = [dgColumnResize, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Koszt'
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SUMA'
          Title.Caption = 'Suma koszt'#243'w'
          Width = 101
          Visible = True
        end>
    end
  end
  object m_DS: TDataSource
    Left = 136
    Top = 80
  end
end
