inherited _SlJednostkiEditFRM: T_SlJednostkiEditFRM
  Left = 577
  Top = 343
  Caption = '_SlJednostkiEditFRM'
  ClientHeight = 191
  ClientWidth = 407
  ExplicitWidth = 413
  ExplicitHeight = 216
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 158
    Width = 407
    ExplicitTop = 158
    ExplicitWidth = 407
    inherited m_CancelBB: TAdvSmoothButton
      Left = 263
      ExplicitLeft = 263
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 335
      ExplicitLeft = 335
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 407
    Height = 158
    ExplicitWidth = 407
    ExplicitHeight = 158
    object Label1: TLabel
      Left = 12
      Top = 12
      Width = 36
      Height = 13
      Caption = 'Kod JW'
      Transparent = True
    end
    object Label2: TLabel
      Left = 78
      Top = 12
      Width = 32
      Height = 13
      Caption = 'Nazwa'
      Transparent = True
    end
    object Label3: TLabel
      Left = 194
      Top = 12
      Width = 61
      Height = 13
      Caption = 'Pe'#322'na nazwa'
      Transparent = True
    end
    object Label4: TLabel
      Left = 12
      Top = 58
      Width = 59
      Height = 13
      Caption = 'Miejscowo'#347#263
      Transparent = True
    end
    object Label5: TLabel
      Left = 194
      Top = 58
      Width = 36
      Height = 13
      Caption = 'Telefon'
      Transparent = True
    end
    object Label6: TLabel
      Left = 298
      Top = 58
      Width = 18
      Height = 13
      Caption = 'Fax'
      Transparent = True
    end
    object Label7: TLabel
      Left = 12
      Top = 104
      Width = 84
      Height = 13
      Caption = 'Nr oddzia'#322'u gosp.'
      Transparent = True
    end
    object edKod: TDBEdit
      Left = 12
      Top = 28
      Width = 60
      Height = 21
      DataField = 'JW'
      DataSource = m_DS
      TabOrder = 0
    end
    object edNazwa: TDBEdit
      Left = 78
      Top = 28
      Width = 110
      Height = 21
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 1
    end
    object edNazwaP: TDBEdit
      Left = 194
      Top = 28
      Width = 200
      Height = 21
      DataField = 'NAZWA_PELNA'
      DataSource = m_DS
      TabOrder = 2
    end
    object edMiasto: TDBEdit
      Left = 12
      Top = 74
      Width = 176
      Height = 21
      DataField = 'MIEJSCOWOSC'
      DataSource = m_DS
      TabOrder = 3
    end
    object edTel: TDBEdit
      Left = 194
      Top = 74
      Width = 98
      Height = 21
      DataField = 'TELEFON'
      DataSource = m_DS
      TabOrder = 4
    end
    object edFax: TDBEdit
      Left = 298
      Top = 74
      Width = 98
      Height = 21
      DataField = 'FAX'
      DataSource = m_DS
      TabOrder = 5
    end
    object edNrOdGsp: TDBEdit
      Left = 12
      Top = 120
      Width = 98
      Height = 21
      DataField = 'NR_ODDZ_GOSP'
      DataSource = m_DS
      TabOrder = 6
    end
  end
  inherited m_DS: TDataSource
    Left = 196
    Top = 126
  end
end
