inherited _SlSprzetRodzajeEditFRM: T_SlSprzetRodzajeEditFRM
  Left = 622
  Top = 443
  Caption = '_SlSprzetRodzajeEditFRM'
  ClientHeight = 143
  ClientWidth = 305
  ExplicitLeft = 622
  ExplicitTop = 443
  ExplicitWidth = 321
  ExplicitHeight = 180
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 110
    Width = 305
    ExplicitTop = 67
    ExplicitWidth = 424
    inherited m_CancelBB: TAdvSmoothButton
      Left = 161
      ExplicitLeft = 280
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 233
      ExplicitLeft = 352
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 305
    Height = 110
    ExplicitWidth = 424
    ExplicitHeight = 67
    object Label2: TLabel
      Left = 12
      Top = 55
      Width = 110
      Height = 13
      Caption = 'Nazwa rodzaju sprz'#281'tu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 12
      Top = 12
      Width = 68
      Height = 13
      Caption = 'Grupa sprz'#281'tu'
      Transparent = True
    end
    object DBEdit2: TDBEdit
      Left = 12
      Top = 71
      Width = 280
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_grCB: TDBLookupComboBox
      Left = 12
      Top = 28
      Width = 280
      Height = 21
      DataField = 'ID_GR_SPRZ'
      DataSource = m_DS
      DropDownRows = 10
      DropDownWidth = 280
      KeyField = 'ID_GR_SPRZ'
      ListField = 'ID_GR_SPRZ;NAZWA'
      ListFieldIndex = 1
      ListSource = m_grDS
      TabOrder = 0
    end
  end
  inherited m_DS: TDataSource
    Left = 22
    Top = 100
  end
  object m_grDS: TDataSource
    Left = 72
    Top = 100
  end
end
