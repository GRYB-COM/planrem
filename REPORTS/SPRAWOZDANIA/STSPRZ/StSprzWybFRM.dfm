inherited _StSprzWybFRM: T_StSprzWybFRM
  Caption = 'Mo'#380'liwo'#347'ci remontowe 3OWT'
  ClientHeight = 178
  ClientWidth = 416
  OnClose = FormClose
  OnShow = FormShow
  ExplicitWidth = 422
  ExplicitHeight = 203
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 137
    Width = 416
    ExplicitTop = 213
    ExplicitWidth = 416
    inherited bbCancel: TBitBtn
      Left = 255
      ExplicitLeft = 255
    end
    inherited bbWrite: TBitBtn
      Left = 331
      ExplicitLeft = 331
    end
  end
  inherited paMain: TPanel
    Width = 416
    Height = 136
    ExplicitWidth = 416
    ExplicitHeight = 212
    object m_WarLB: TLabel
      Left = 9
      Top = 3
      Width = 42
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object Label1: TLabel
      Left = 9
      Top = 61
      Width = 38
      Height = 13
      Caption = 'Data do'
      Transparent = True
    end
    object m_WarCB: TDBLookupComboBox
      Left = 9
      Top = 22
      Width = 391
      Height = 21
      Anchors = [akLeft, akTop, akRight, akBottom]
      DropDownRows = 30
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarDS
      NullValueKey = 46
      TabOrder = 0
    end
    object m_DataDoDTP: TDateTimePicker
      Left = 9
      Top = 80
      Width = 87
      Height = 21
      Date = 40812.000000000000000000
      Time = 40812.000000000000000000
      TabOrder = 1
    end
  end
  inherited paTop: TPanel
    Width = 416
    ExplicitWidth = 416
  end
  object m_WarDS: TDataSource
    Left = 280
    Top = 56
  end
end
