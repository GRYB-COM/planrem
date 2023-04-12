object _KUTrbhFRA: T_KUTrbhFRA
  Left = 0
  Top = 0
  Width = 417
  Height = 334
  TabOrder = 0
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 334
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
    Align = alClient
    TabOrder = 0
    object Label7: TLabel
      Left = 0
      Top = 3
      Width = 146
      Height = 13
      Caption = 'Rozliczenie planu w miesi'#261'cach'
      Transparent = True
    end
    object m_DBG: TDBGrid
      Left = 0
      Top = 20
      Width = 401
      Height = 258
      Ctl3D = True
      DataSource = m_RbhDS
      DrawingStyle = gdsGradient
      Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentCtl3D = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnDrawColumnCell = m_DBGDrawColumnCell
      Columns = <
        item
          Expanded = False
          FieldName = 'MIESIAC'
          ReadOnly = True
          Title.Caption = 'Miesi'#261'c'
          Width = 80
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PLAN_ILOSC'
          Title.Caption = 'Ilo'#347#263' planowana'
          Width = 82
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ILOSC'
          Title.Caption = 'Ilo'#347#263
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'LICZBA_RBH'
          Title.Caption = 'Liczba RBH'
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PLAN_RBH'
          Title.Caption = 'Planowane RBH'
          Width = 85
          Visible = True
        end>
    end
    object m_SumIlPED: TEdit
      Left = 148
      Top = 284
      Width = 59
      Height = 19
      Alignment = taRightJustify
      Ctl3D = False
      NumbersOnly = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 1
      Text = 'm_SumIlPED'
    end
    object m_RazemED: TEdit
      Left = 87
      Top = 284
      Width = 59
      Height = 19
      Alignment = taRightJustify
      Ctl3D = False
      NumbersOnly = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 2
      Text = 'RAZEM:'
    end
    object m_SumIlRED: TEdit
      Left = 210
      Top = 284
      Width = 59
      Height = 19
      Alignment = taRightJustify
      Ctl3D = False
      NumbersOnly = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 3
      Text = 'm_SumIlPED'
    end
    object m_SumRBHPED: TEdit
      Left = 272
      Top = 284
      Width = 59
      Height = 19
      Alignment = taRightJustify
      Ctl3D = False
      NumbersOnly = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 4
      Text = 'm_SumIlPED'
    end
    object m_SumRBHRED: TEdit
      Left = 337
      Top = 284
      Width = 59
      Height = 19
      Alignment = taRightJustify
      Ctl3D = False
      NumbersOnly = True
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 5
      Text = 'm_SumIlPED'
    end
  end
  object m_RbhDS: TDataSource
    Left = 220
    Top = 84
  end
end
