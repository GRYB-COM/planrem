inherited _MeldTygWybFRM: T_MeldTygWybFRM
  Caption = 'Meldunek tygodniowy'
  ClientHeight = 104
  ClientWidth = 216
  Position = poOwnerFormCenter
  OnShow = FormShow
  ExplicitWidth = 222
  ExplicitHeight = 129
  PixelsPerInch = 96
  TextHeight = 13
  inherited paBottom: TPanel
    Top = 63
    Width = 216
    ExplicitTop = 63
    ExplicitWidth = 216
    inherited bbCancel: TBitBtn
      Left = 131
      Enabled = False
      Visible = False
      ExplicitLeft = 131
    end
    inherited bbWrite: TBitBtn
      Left = 131
      Caption = 'Zamknij'
      ExplicitLeft = 131
    end
    inherited m_PrintPrevFR: T_PopupButton
      inherited popup: TPopupMenu
        object m_SQRTMI: TMenuItem
          Caption = 'Wersja SQR'
        end
        object m_ExcellTMI: TMenuItem
          Caption = 'Wersja XLS'
        end
      end
    end
  end
  inherited paMain: TPanel
    Width = 216
    Height = 62
    ExplicitWidth = 216
    ExplicitHeight = 62
    object Label1: TLabel
      Left = 9
      Top = 6
      Width = 81
      Height = 13
      Caption = 'Meldunek za dni:'
    end
    object m_DataOdDTP: TDateTimePicker
      Left = 9
      Top = 25
      Width = 81
      Height = 21
      Date = 40606.000000000000000000
      Time = 40606.000000000000000000
      TabOrder = 0
      OnChange = m_DataOdDTPChange
    end
    object m_DataDoDTP: TDateTimePicker
      Left = 111
      Top = 25
      Width = 83
      Height = 21
      Date = 40606.000000000000000000
      Time = 40606.000000000000000000
      TabOrder = 1
    end
  end
  inherited paTop: TPanel
    Width = 216
    ExplicitWidth = 216
  end
end
