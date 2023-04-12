inherited _SlWydzialyFRM: T_SlWydzialyFRM
  Left = 427
  Top = 152
  Caption = 'S'#322'ownik wydzia'#322#243'w'
  ClientWidth = 744
  ExplicitLeft = 427
  ExplicitTop = 152
  ExplicitWidth = 760
  ExplicitHeight = 240
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Width = 744
    ExplicitWidth = 744
    DesignSize = (
      744
      33)
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 600
      ExplicitLeft = 600
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 672
      ExplicitLeft = 672
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 744
    ExplicitWidth = 744
    object DBGrid1: TDBGrid [0]
      Left = 3
      Top = 116
      Width = 714
      Height = 169
      Align = alCustom
      Ctl3D = True
      DataSource = m_DS
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentCtl3D = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
    inherited m_DBG: TDBGrid
      Width = 744
      TabOrder = 1
      Columns = <
        item
          Expanded = False
          FieldName = 'KOD'
          Title.Caption = 'Kod'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa wydzia'#322'u'
          Width = 300
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ULICA'
          Title.Caption = 'Ulica'
          Width = 130
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NR_ULICY'
          Title.Caption = 'Numer'
          Width = 40
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'MIASTO'
          Title.Caption = 'Miejscowo'#347#263
          Width = 130
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'KOD_POCZT'
          Title.Caption = 'Kod poczt.'
          Width = 55
          Visible = True
        end>
    end
  end
end
