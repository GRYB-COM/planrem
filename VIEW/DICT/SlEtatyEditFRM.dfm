inherited _SlEtatyEditFRM: T_SlEtatyEditFRM
  Left = 633
  Top = 597
  Caption = 'Etaty'
  ClientHeight = 99
  ClientWidth = 331
  OnShow = FormShow
  ExplicitWidth = 337
  ExplicitHeight = 124
  PixelsPerInch = 96
  TextHeight = 13
  inherited m_BottomASP: TAdvSmoothPanel
    Top = 66
    Width = 331
    ExplicitTop = 66
    ExplicitWidth = 293
    inherited m_CancelBB: TAdvSmoothButton
      Left = 187
      ExplicitLeft = 149
    end
    inherited m_SaveBB: TAdvSmoothButton
      Left = 259
      ExplicitLeft = 221
    end
  end
  inherited m_TopP: TAdvSmoothPanel
    Width = 331
    Height = 66
    ExplicitWidth = 293
    ExplicitHeight = 66
    object Label1: TLabel
      Left = 107
      Top = 12
      Width = 20
      Height = 13
      Caption = 'Etat'
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 12
      Width = 38
      Height = 13
      Caption = 'Data od'
      Transparent = True
    end
    object Label2: TLabel
      Left = 176
      Top = 12
      Width = 49
      Height = 13
      Caption = 'Etat prod.'
      Transparent = True
    end
    object Label3: TLabel
      Left = 246
      Top = 12
      Width = 65
      Height = 13
      Caption = 'Stawka godz.'
      Transparent = True
    end
    object DBEdit1: TDBEdit
      Left = 107
      Top = 27
      Width = 61
      Height = 21
      DataField = 'ETAT'
      DataSource = m_DS
      TabOrder = 1
    end
    object m_DataOdDCP: TAdvDBDateTimePicker
      Left = 12
      Top = 28
      Width = 85
      Height = 21
      DoubleBuffered = True
      Kind = dkDate
      ParentDoubleBuffered = False
      TabOrder = 0
      BorderStyle = bsSingle
      Ctl3D = True
      Version = '1.1.0.0'
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      DataField = 'DATA_OD'
      DataSource = m_DS
    end
    object DBEdit2: TDBEdit
      Left = 176
      Top = 27
      Width = 61
      Height = 21
      DataField = 'ETAT_PROD'
      DataSource = m_DS
      TabOrder = 2
    end
    object DBEdit3: TDBEdit
      Left = 246
      Top = 27
      Width = 61
      Height = 21
      DataField = 'DNIOWKA'
      DataSource = m_DS
      TabOrder = 3
    end
  end
  inherited m_DS: TDataSource
    Top = 56
  end
end
