inherited _KwMozlWarWybFRM: T_KwMozlWarWybFRM
  Caption = 'Mo'#380'liwo'#347'ci remontowe 3OWT'
  ClientHeight = 254
  ClientWidth = 416
  OnClose = FormClose
  OnShow = FormShow
  ExplicitWidth = 422
  ExplicitHeight = 279
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 213
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
    Height = 212
    ExplicitTop = 3
    ExplicitWidth = 416
    ExplicitHeight = 212
    object m_RokLB: TLabel
      Left = 10
      Top = 13
      Width = 20
      Height = 13
      Caption = 'Rok'
      Transparent = True
    end
    object m_WydzialLB: TLabel
      Left = 10
      Top = 67
      Width = 39
      Height = 13
      Caption = 'Wydzia'#322
      Transparent = True
    end
    object m_WarLB: TLabel
      Left = 9
      Top = 122
      Width = 42
      Height = 13
      Caption = 'Warsztat'
      Transparent = True
    end
    object m_RokED: TEdit
      Left = 10
      Top = 28
      Width = 86
      Height = 21
      Ctl3D = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      Text = 'm_RokED'
    end
    object m_WydzialCB: TDBLookupComboBox
      Left = 10
      Top = 82
      Width = 391
      Height = 21
      Anchors = [akLeft, akTop, akRight, akBottom]
      DropDownRows = 30
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WydzialDS
      NullValueKey = 46
      TabOrder = 1
      OnCloseUp = m_WydzialCBCloseUp
    end
    object m_WarCB: TDBLookupComboBox
      Left = 9
      Top = 137
      Width = 391
      Height = 21
      Anchors = [akLeft, akTop, akRight, akBottom]
      DropDownRows = 30
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListFieldIndex = 1
      ListSource = m_WarDS
      NullValueKey = 46
      TabOrder = 2
    end
    object m_SumCB: TCheckBox
      Left = 9
      Top = 164
      Width = 390
      Height = 17
      Caption = 'Sumowanie wg typomarki'
      TabOrder = 3
      Visible = False
    end
    object m_DiagCB: TCheckBox
      Left = 9
      Top = 187
      Width = 390
      Height = 17
      Caption = 'Dane diagnostyczne'
      TabOrder = 4
      Visible = False
    end
  end
  inherited paTop: TPanel
    Width = 416
    ExplicitWidth = 416
  end
  object m_WydzialDS: TDataSource
    Left = 128
    Top = 40
  end
  object m_WarDS: TDataSource
    Left = 200
    Top = 40
  end
end
