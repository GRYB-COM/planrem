inherited _SprRoczneWybFRM: T_SprRoczneWybFRM
  Caption = 'Sprawozdane'
  ClientHeight = 242
  ClientWidth = 245
  OnClose = FormClose
  OnShow = FormShow
  ExplicitWidth = 251
  ExplicitHeight = 267
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 201
    Width = 245
    ExplicitTop = 180
    ExplicitWidth = 245
    inherited bbCancel: TBitBtn
      Left = 84
      ExplicitLeft = 84
    end
    inherited bbWrite: TBitBtn
      Left = 160
      ExplicitLeft = 160
    end
  end
  inherited paMain: TPanel
    Width = 245
    Height = 200
    ExplicitWidth = 245
    ExplicitHeight = 179
    object m_RokLB: TLabel
      Left = 10
      Top = 7
      Width = 20
      Height = 13
      Caption = 'Rok'
      Transparent = True
    end
    object Label1: TLabel
      Left = 111
      Top = 91
      Width = 36
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object m_SprRG: TRadioGroup
      Left = 10
      Top = 49
      Width = 223
      Height = 79
      Caption = 'Sprawozdanie'
      Items.Strings = (
        'za:'
        'za ca'#322'y rok')
      TabOrder = 1
      OnClick = m_SprRGClick
    end
    object m_RokED: TEdit
      Left = 10
      Top = 22
      Width = 86
      Height = 21
      Ctl3D = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      NumbersOnly = True
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      Text = 'm_RokED'
    end
    object m_PolRokCB: TComboBox
      Left = 56
      Top = 69
      Width = 83
      Height = 21
      DropDownCount = 12
      ItemIndex = 0
      TabOrder = 2
      Text = 'I p'#243#322'rocze'
      Items.Strings = (
        'I p'#243#322'rocze'
        'II p'#243#322'rocze')
    end
    object m_InfoCB: TCheckBox
      Left = 10
      Top = 144
      Width = 215
      Height = 17
      Caption = 'Informacja diagnostyczna'
      TabOrder = 3
    end
    object m_NewZestCB: TCheckBox
      Left = 10
      Top = 163
      Width = 215
      Height = 17
      Caption = 'Nowa wersja zestawienia'
      TabOrder = 4
    end
  end
  inherited paTop: TPanel
    Width = 245
    ExplicitWidth = 245
  end
end
