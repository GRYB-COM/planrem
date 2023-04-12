object _pocztaLoginFrm: T_pocztaLoginFrm
  Left = 0
  Top = 0
  Width = 468
  Height = 117
  TabOrder = 0
  object AdvSmoothPanel1: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 468
    Height = 117
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
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 296
    ExplicitTop = 88
    ExplicitWidth = 337
    ExplicitHeight = 289
    object m_ZRokuAGB: TAdvGroupBox
      Left = 7
      Top = 3
      Width = 218
      Height = 105
      BorderColor = 13542013
      RoundEdges = True
      Caption = ' Po'#322#261'czenie '
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 33
        Width = 34
        Height = 13
        Caption = 'Serwer'
      end
      object Label2: TLabel
        Left = 16
        Top = 68
        Width = 20
        Height = 13
        Caption = 'Port'
      end
      object edSerwer: TEdit
        Left = 55
        Top = 30
        Width = 148
        Height = 21
        TabOrder = 0
      end
      object edPort: TEdit
        Left = 55
        Top = 65
        Width = 42
        Height = 21
        NumbersOnly = True
        TabOrder = 1
        Text = '110'
      end
    end
    object AdvGroupBox1: TAdvGroupBox
      Left = 241
      Top = 3
      Width = 218
      Height = 105
      BorderColor = 13542013
      RoundEdges = True
      Caption = ' Konto '
      TabOrder = 1
      object Label3: TLabel
        Left = 16
        Top = 33
        Width = 28
        Height = 13
        Caption = 'Konto'
      end
      object Label4: TLabel
        Left = 16
        Top = 68
        Width = 27
        Height = 13
        Caption = 'Has'#322'o'
      end
      object edKonto: TEdit
        Left = 55
        Top = 30
        Width = 148
        Height = 21
        TabOrder = 0
      end
      object edHaslo: TEdit
        Left = 55
        Top = 65
        Width = 148
        Height = 19
        PasswordChar = '*'
        TabOrder = 1
      end
    end
  end
  object IdPOP31: TIdPOP3
    AutoLogin = True
    SASLMechanisms = <>
    Left = 128
    Top = 72
  end
  object IdSMTP1: TIdSMTP
    SASLMechanisms = <>
    Left = 184
    Top = 72
  end
end
