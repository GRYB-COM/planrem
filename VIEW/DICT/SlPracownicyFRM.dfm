inherited _SlPracownicyFRM: T_SlPracownicyFRM
  Left = 805
  Top = 211
  Caption = 'Pracownicy'
  ClientHeight = 356
  ClientWidth = 510
  ExplicitWidth = 516
  ExplicitHeight = 381
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 323
    Width = 510
    ExplicitTop = 323
    ExplicitWidth = 510
    inherited m_DodajBB: TAdvSmoothButton
      OnClick = m_DodajBBClick
    end
    inherited m_EdytujBB: TAdvSmoothButton
      OnClick = m_EdytujBBClick
    end
    inherited m_CancelBB: TAdvSmoothButton
      Left = 366
      ExplicitLeft = 366
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 438
      ExplicitLeft = 438
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 510
    Height = 323
    ExplicitWidth = 510
    ExplicitHeight = 323
    inherited m_DBG: TDBGrid
      Top = 32
      Width = 510
      Align = alBottom
      Columns = <
        item
          Expanded = False
          FieldName = 'STOPIEN'
          Title.Caption = 'Stopie'#324
          Width = 84
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAZWISKO'
          Title.Caption = 'Nazwisko'
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IMIE'
          Title.Caption = 'Imi'#281
          Width = 110
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'KOMORKA'
          Title.Caption = 'Kom'#243'rka'
          Width = 50
          Visible = True
        end>
    end
    object AdvSmoothPanel1: TAdvSmoothPanel
      Left = 0
      Top = 0
      Width = 510
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
      Align = alTop
      TabOrder = 1
      object Label1: TLabel
        Left = 8
        Top = 10
        Width = 41
        Height = 13
        Caption = 'Kom'#243'rka'
        Transparent = True
      end
      object m_komCB: TDBLookupComboBox
        Left = 55
        Top = 6
        Width = 365
        Height = 21
        DropDownRows = 15
        KeyField = 'ID_KOMORKI'
        ListField = 'KOD;NAZWA'
        ListFieldIndex = 1
        ListSource = m_komDS
        NullValueKey = 46
        TabOrder = 0
        OnCloseUp = m_komCBCloseUp
      end
    end
  end
  object m_komDS: TDataSource
    Left = 72
    Top = 80
  end
end
