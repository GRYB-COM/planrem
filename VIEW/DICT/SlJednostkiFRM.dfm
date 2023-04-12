inherited _SlJednostkiFRM: T_SlJednostkiFRM
  Left = 364
  Top = 150
  Caption = 'S'#322'ownik jednostek'
  ClientHeight = 584
  ClientWidth = 796
  ExplicitWidth = 802
  ExplicitHeight = 609
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 551
    Width = 796
    ExplicitTop = 551
    ExplicitWidth = 796
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 652
      ExplicitLeft = 652
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 724
      ExplicitLeft = 724
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 796
    Height = 551
    Fill.Color = 16248031
    ExplicitWidth = 796
    ExplicitHeight = 551
    object Label1: TLabel [0]
      Left = 14
      Top = 11
      Width = 40
      Height = 13
      Caption = 'Kod JW:'
      Transparent = True
    end
    object Label2: TLabel [1]
      Left = 120
      Top = 11
      Width = 63
      Height = 13
      Caption = 'Miejscowo'#347#263':'
      Transparent = True
    end
    inherited m_DBG: TDBGrid
      Top = 62
      Width = 796
      Height = 489
      Align = alNone
      TabOrder = 2
      Columns = <
        item
          Expanded = False
          FieldName = 'JW'
          Title.Caption = 'Kod JW'
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA'
          Title.Caption = 'Nazwa'
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWA_PELNA'
          Title.Caption = 'Pe'#322'na nazwa'
          Width = 200
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'MIEJSCOWOSC'
          Title.Caption = 'Miejscowo'#347#263
          Width = 120
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'TELEFON'
          Title.Caption = 'Telefon'
          Width = 90
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FAX'
          Title.Caption = 'Fax'
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NR_ODDZ_GOSP'
          Title.Caption = 'Nr oddzia'#322'u'
          Width = 85
          Visible = True
        end>
    end
    object edKodJW: TEdit
      Left = 14
      Top = 27
      Width = 100
      Height = 21
      TabOrder = 0
      OnChange = edKodJWChange
    end
    object edMiasto: TEdit
      Left = 120
      Top = 27
      Width = 200
      Height = 21
      TabOrder = 1
      OnChange = edMiastoChange
    end
  end
end
