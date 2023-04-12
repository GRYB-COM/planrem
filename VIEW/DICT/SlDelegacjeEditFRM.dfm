inherited _SlDelegacjeEditFRM: T_SlDelegacjeEditFRM
  Left = 633
  Top = 597
  Caption = 'Delegacje'
  ClientHeight = 164
  OnActivate = FormActivate
  ExplicitHeight = 189
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 131
    ExplicitTop = 131
  end
  inherited m_TopP: TAdvSmoothPanel
    Height = 131
    ExplicitHeight = 131
    object Label3: TLabel
      Left = 103
      Top = 10
      Width = 34
      Height = 13
      Caption = 'Miesi'#261'c'
      Transparent = True
    end
    object Label1: TLabel
      Left = 143
      Top = 53
      Width = 29
      Height = 13
      Caption = 'Uwagi'
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 53
      Width = 41
      Height = 13
      Caption = 'Kom'#243'rka'
      Transparent = True
    end
    object Label2: TLabel
      Left = 12
      Top = 9
      Width = 18
      Height = 13
      Caption = 'Rok'
      Transparent = True
    end
    object Label4: TLabel
      Left = 103
      Top = 53
      Width = 19
      Height = 13
      Caption = 'Dni:'
      Transparent = True
    end
    object m_MiesCB: TDBLookupComboBox
      Left = 103
      Top = 26
      Width = 111
      Height = 21
      DataField = 'MIESIAC'
      DataSource = m_DS
      DropDownRows = 13
      KeyField = 'NR_MIES'
      ListField = 'NAZ_MIES'
      ListSource = m_MiesDS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 143
      Top = 69
      Width = 230
      Height = 21
      DataField = 'UWAGI'
      DataSource = m_DS
      TabOrder = 4
    end
    object m_komCB: TDBLookupComboBox
      Left = 12
      Top = 69
      Width = 85
      Height = 21
      DataField = 'ID_KOMORKI'
      DataSource = m_DS
      DropDownWidth = 300
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD;NAZWA'
      ListSource = m_komDS
      TabOrder = 1
    end
    object m_RokED: TDBEdit
      Left = 12
      Top = 26
      Width = 85
      Height = 21
      TabStop = False
      DataField = 'ROK'
      DataSource = m_DS
      TabOrder = 2
    end
    object m_DniED: TDBEdit
      Left = 103
      Top = 69
      Width = 34
      Height = 21
      DataField = 'DNI'
      DataSource = m_DS
      TabOrder = 3
    end
  end
  inherited m_DS: TDataSource
    Left = 16
    Top = 104
  end
  object m_komDS: TDataSource
    Left = 60
    Top = 104
  end
  object m_MiesDS: TDataSource
    Left = 128
    Top = 112
  end
end
