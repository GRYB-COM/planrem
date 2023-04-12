inherited _SlWydzialyEditFRM: T_SlWydzialyEditFRM
  Left = 670
  Top = 173
  Caption = 'Wydzia'#322'y'
  ClientHeight = 144
  ClientWidth = 448
  ExplicitWidth = 454
  ExplicitHeight = 169
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 111
    Width = 448
    ExplicitTop = 111
    ExplicitWidth = 448
    inherited m_CancelBB: TAdvSmoothButton
      Left = 304
      ExplicitLeft = 304
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 376
      ExplicitLeft = 376
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 448
    Height = 111
    ExplicitWidth = 448
    ExplicitHeight = 111
    object Label1: TLabel
      Left = 12
      Top = 12
      Width = 18
      Height = 13
      Caption = 'Kod'
      Transparent = True
    end
    object Label2: TLabel
      Left = 68
      Top = 12
      Width = 76
      Height = 13
      Caption = 'Nazwa wydzialu'
      Transparent = True
    end
    object Label3: TLabel
      Left = 12
      Top = 57
      Width = 22
      Height = 13
      Caption = 'Ulica'
      Transparent = True
    end
    object Label4: TLabel
      Left = 196
      Top = 57
      Width = 31
      Height = 13
      Caption = 'Numer'
      Transparent = True
    end
    object Label5: TLabel
      Left = 240
      Top = 57
      Width = 59
      Height = 13
      Caption = 'Miejscowo'#347#263
      Transparent = True
    end
    object Label6: TLabel
      Left = 386
      Top = 57
      Width = 51
      Height = 13
      Caption = 'Kod poczt.'
      Transparent = True
    end
    object DBEdit2: TDBEdit
      Left = 68
      Top = 28
      Width = 368
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      DataField = 'NAZWA'
      DataSource = m_DS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 12
      Top = 28
      Width = 50
      Height = 21
      DataField = 'KOD'
      DataSource = m_DS
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 12
      Top = 73
      Width = 178
      Height = 21
      DataField = 'ULICA'
      DataSource = m_DS
      TabOrder = 2
    end
    object DBEdit4: TDBEdit
      Left = 196
      Top = 73
      Width = 38
      Height = 21
      DataField = 'NR_ULICY'
      DataSource = m_DS
      TabOrder = 3
    end
    object DBEdit5: TDBEdit
      Left = 240
      Top = 73
      Width = 140
      Height = 21
      DataField = 'MIASTO'
      DataSource = m_DS
      TabOrder = 4
    end
    object DBEdit6: TDBEdit
      Left = 386
      Top = 73
      Width = 50
      Height = 21
      DataField = 'KOD_POCZT'
      DataSource = m_DS
      TabOrder = 5
    end
  end
  inherited m_DS: TDataSource
    Top = 112
  end
end
