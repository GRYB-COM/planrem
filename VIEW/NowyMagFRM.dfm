object _NowyMagFRM: T_NowyMagFRM
  Left = 1538
  Top = 609
  Caption = 'Przyj'#281'cie sprz'#281'tu lub rejestracja us'#322'ugi'
  ClientHeight = 385
  ClientWidth = 592
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_BottomPA: TAdvSmoothPanel
    Left = 0
    Top = 354
    Width = 592
    Height = 31
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
    Caption.ColorStart = clBlack
    Caption.ColorEnd = clBlack
    Caption.LineColor = 13542013
    Fill.Color = 16575452
    Fill.ColorTo = 16571329
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 13542013
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alBottom
    TabOrder = 3
    DesignSize = (
      592
      31)
    object AdvSmoothButton4: TAdvSmoothButton
      Left = 492
      Top = 4
      Width = 97
      Height = 25
      Anchors = [akTop, akRight]
      Status.Caption = '0'
      Status.Appearance.Fill.Color = clRed
      Status.Appearance.Fill.ColorMirror = clNone
      Status.Appearance.Fill.ColorMirrorTo = clNone
      Status.Appearance.Fill.GradientType = gtSolid
      Status.Appearance.Fill.BorderColor = clGray
      Status.Appearance.Fill.Rounding = 0
      Status.Appearance.Fill.ShadowOffset = 0
      Status.Appearance.Font.Charset = DEFAULT_CHARSET
      Status.Appearance.Font.Color = clWhite
      Status.Appearance.Font.Height = -11
      Status.Appearance.Font.Name = 'Tahoma'
      Status.Appearance.Font.Style = []
      Caption = 'Zapisz'
      Color = 16644337
      TabOrder = 0
      Version = '1.6.9.1'
      OnClick = AdvSmoothButton4Click
    end
    object AdvSmoothButton1: TAdvSmoothButton
      Left = 389
      Top = 3
      Width = 97
      Height = 25
      Anchors = [akTop, akRight]
      Status.Caption = '0'
      Status.Appearance.Fill.Color = clRed
      Status.Appearance.Fill.ColorMirror = clNone
      Status.Appearance.Fill.ColorMirrorTo = clNone
      Status.Appearance.Fill.GradientType = gtSolid
      Status.Appearance.Fill.BorderColor = clGray
      Status.Appearance.Fill.Rounding = 0
      Status.Appearance.Fill.ShadowOffset = 0
      Status.Appearance.Font.Charset = DEFAULT_CHARSET
      Status.Appearance.Font.Color = clWhite
      Status.Appearance.Font.Height = -11
      Status.Appearance.Font.Name = 'Tahoma'
      Status.Appearance.Font.Style = []
      Caption = 'Anuluj'
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      OnClick = AdvSmoothButton1Click
    end
  end
  object m_MainPA: TAdvSmoothPanel
    Left = 0
    Top = 49
    Width = 592
    Height = 256
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
    Caption.ColorStart = clBlack
    Caption.ColorEnd = clBlack
    Caption.LineColor = 13542013
    Fill.Color = 16575452
    Fill.ColorTo = 16571329
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = 13542013
    Fill.BorderWidth = 0
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alClient
    TabOrder = 1
    object m_NrMagBT: TSpeedButton
      Left = 176
      Top = 21
      Width = 38
      Height = 22
      Hint = 'Najmniejszy wolny nr mag.'
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000FF00FFFF00FF
        9A8B7B513D28FF00FFFF00FF3724139A8B7BFF00FFFF00FFFF00FFFF00FFFF00
        FFFF00FFFF00FFFF00FFFF00FFFF00FF7B6956AD87634C39263F2C189977567B
        6956FF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFFF00FFC1B5A6938373
        624D38D5B79AE1C7B0DEC2A6C4A383624D38938373C1B5A6FF00FFFF00FF3724
        139A8B7BFF00FFFF00FF5C42299C7857D3B8A0E0CEBF8E7B6A8E7B69EAD5C2D3
        B8A09C78575C42294C39263F2C189977567B6956FF00FFFF00FFFF00FF674A30
        F2E1D7917F6DCBB5A3BCA590AD9F8FF2E1D7674A30D5B79AE1C7B0DEC2A6C4A3
        83624D38938373C1B5A6FF00FF72563AF6E7DE6B5841A49587E7D1BF8E7B69F6
        E7DE72563AE0CEBF8E7B6A8E7B69EAD5C2D3B8A09C78575C42297F6245B79675
        DEC9B7AB99896853408F7D6ADCCCBCDEC9B7B796757F6245CBB5A3BCA590AD9F
        8FF2E1D7674A30FF00FFC2B29F998167886D53E0CBBAF3E5DCF0DED1D1BAA488
        6D53998167C2B29FA49587E7D1BF8E7B69F6E7DE72563AFF00FFFF00FFFF00FF
        AB967EB7997D75573D6F5237AA8B6FAB967EDEC9B7AB99896853408F7D6ADCCC
        BCDEC9B7B796757F6245FF00FFFF00FF6958A103509803509803509803509803
        5098035098035098035098035098035098466368998167C2B29FFF00FFFF00FF
        03509831A3D75BC9EA93EDF79EEEFA90EDFF5ACCF629A3E50E7FD30873CB107D
        C7055AA0FF00FFFF00FFFF00FFFF00FF03509866E9FF7EEDFFA6FFFFA5FBFF7B
        E1FA47BFEE219FE7097BD70472D31A98E9035098FF00FFFF00FFFF00FFFF00FF
        03509868DEFF8FEAFFB7FBFFBCFAFFAAEDFB79D3F34EB7EE2899E01788DA1C96
        E3035098FF00FFFF00FFFF00FFFF00FF03509884D7F3B2EDFBD3FAFFD3FAFFD3
        FAFFD3FAFFD3FAFFD3FAFF98DAF75ABDF2035098FF00FFFF00FFFF00FFFF00FF
        03509841B4E93EB0E34CBFE94CBFE94CBFE94CBFE94CBFE94CBFE943B8E938A5
        E3035098FF00FFFF00FFFF00FFFF00FFAC1ADD03509803509803529903529904
        539A03529A03529A0357A3035098035098AC1ADDFF00FFFF00FF}
      OnClick = m_NrMagBTClick
    end
    object Label12: TLabel
      Left = 85
      Top = 26
      Width = 4
      Height = 13
      Caption = '/'
      Transparent = True
    end
    object Label10: TLabel
      Left = 46
      Top = 26
      Width = 4
      Height = 13
      Caption = '/'
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 3
      Width = 101
      Height = 13
      Caption = 'Numer magazynowy:'
      Transparent = True
    end
    object Label2: TLabel
      Left = 278
      Top = 62
      Width = 75
      Height = 13
      Caption = 'Nazwa sprz'#281'tu:'
      Transparent = True
    end
    object Label4: TLabel
      Left = 103
      Top = 202
      Width = 33
      Height = 13
      Caption = 'Uwagi:'
      Transparent = True
    end
    object Label5: TLabel
      Left = 544
      Top = 62
      Width = 26
      Height = 13
      Caption = 'Ilo'#347#263':'
      Transparent = True
    end
    object Label7: TLabel
      Left = 12
      Top = 134
      Width = 73
      Height = 13
      Caption = 'Data przyj'#281'cia:'
      Transparent = True
    end
    object Label1: TLabel
      Left = 352
      Top = 134
      Width = 35
      Height = 13
      Caption = 'Nr rej.:'
      Transparent = True
    end
    object Label13: TLabel
      Left = 465
      Top = 134
      Width = 42
      Height = 13
      Caption = 'Nr fabr.:'
      Transparent = True
    end
    object Label14: TLabel
      Left = 166
      Top = 62
      Width = 51
      Height = 13
      Caption = 'Dostawca:'
      Transparent = True
    end
    object Label9: TLabel
      Left = 211
      Top = 134
      Width = 35
      Height = 13
      Caption = 'PST nr:'
      Transparent = True
    end
    object Label16: TLabel
      Left = 103
      Top = 134
      Width = 73
      Height = 13
      Caption = 'Nr prot. przyj.:'
      Transparent = True
    end
    object Label3: TLabel
      Left = 103
      Top = 62
      Width = 57
      Height = 13
      Caption = 'Rodz. rem.:'
      Transparent = True
    end
    object Label17: TLabel
      Left = 16
      Top = 62
      Width = 48
      Height = 13
      Caption = 'Warsztat:'
      Transparent = True
    end
    object Label18: TLabel
      Left = 12
      Top = 202
      Width = 74
      Height = 13
      Caption = 'Prop. data zak:'
      Transparent = True
    end
    object Label21: TLabel
      Left = 122
      Top = 26
      Width = 4
      Height = 13
      Caption = '/'
      Transparent = True
    end
    object m_SerwisCB: TDBLookupComboBox
      Left = 89
      Top = 22
      Width = 32
      Height = 21
      DataField = 'DEPOZYT'
      DataSource = m_DS
      DropDownWidth = 100
      KeyField = 'KOD_SERWISU'
      ListField = 'KOD_SERWISU;NAZ_SERWISU'
      ListSource = m_SerwisDS
      TabOrder = 2
    end
    object m_RokED: TDBEdit
      Left = 51
      Top = 23
      Width = 33
      Height = 19
      Ctl3D = False
      DataField = 'ROK'
      DataSource = m_DS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 1
    end
    object m_NrMagED: TDBEdit
      Left = 12
      Top = 22
      Width = 33
      Height = 21
      DataField = 'NR_MAG'
      DataSource = m_DS
      TabOrder = 0
    end
    object m_SprzetCB: TDBLookupComboBox
      Left = 278
      Top = 81
      Width = 260
      Height = 21
      DataField = 'ID_SPRZETU'
      DataSource = m_DS
      KeyField = 'ID_SPRZETU'
      ListField = 'NAZWA'
      ListSource = m_SprzetDS
      TabOrder = 7
    end
    object m_IloscED: TDBEdit
      Left = 544
      Top = 81
      Width = 38
      Height = 21
      DataField = 'ILOSC'
      DataSource = m_DS
      TabOrder = 8
    end
    object m_UwagiED: TDBEdit
      Left = 103
      Top = 221
      Width = 479
      Height = 21
      DataField = 'UWAGI'
      DataSource = m_DS
      TabOrder = 15
    end
    object m_DataPrzDTP: TDBAdvSmoothDatePicker
      Left = 12
      Top = 153
      Width = 85
      Height = 21
      Flat = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      Lookup.Separator = ';'
      Color = clWindow
      Enabled = True
      ReadOnly = False
      TabOrder = 9
      Text = '2011-03-28'
      Visible = True
      OnKeyDown = DBAdvSmoothDateclearData
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        DA020000424DDA0200000000000036000000280000000D0000000D0000000100
        200000000000A402000000000000000000000000000000000000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F00000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000000000000000000000000000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F0000000000000000000000000000000000000000000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F0000000000000000000000000000000
        0000000000000000000000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000}
      HideCalendarAfterSelection = True
      Calendar.Fill.Color = 15984090
      Calendar.Fill.ColorTo = 15785680
      Calendar.Fill.ColorMirror = clNone
      Calendar.Fill.ColorMirrorTo = clNone
      Calendar.Fill.BorderColor = clNone
      Calendar.Fill.Rounding = 0
      Calendar.Fill.ShadowOffset = 0
      Calendar.Animation = True
      Calendar.ShowCurrentDate = True
      Calendar.DateAppearance.DateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateFont.Color = clWindowText
      Calendar.DateAppearance.DateFont.Height = -11
      Calendar.DateAppearance.DateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateFont.Style = []
      Calendar.DateAppearance.DateFill.Color = 16773091
      Calendar.DateAppearance.DateFill.ColorTo = 16768452
      Calendar.DateAppearance.DateFill.ColorMirror = 16765357
      Calendar.DateAppearance.DateFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.DateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DateFill.BorderColor = clNone
      Calendar.DateAppearance.DateFill.Rounding = 0
      Calendar.DateAppearance.DateFill.ShadowOffset = 0
      Calendar.DateAppearance.DayOfWeekFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DayOfWeekFont.Color = clWindowText
      Calendar.DateAppearance.DayOfWeekFont.Height = -11
      Calendar.DateAppearance.DayOfWeekFont.Name = 'Tahoma'
      Calendar.DateAppearance.DayOfWeekFont.Style = []
      Calendar.DateAppearance.DayOfWeekFill.Color = 15984090
      Calendar.DateAppearance.DayOfWeekFill.ColorTo = 15785680
      Calendar.DateAppearance.DayOfWeekFill.ColorMirror = clNone
      Calendar.DateAppearance.DayOfWeekFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DayOfWeekFill.BorderColor = clNone
      Calendar.DateAppearance.DayOfWeekFill.Rounding = 0
      Calendar.DateAppearance.DayOfWeekFill.ShadowOffset = 0
      Calendar.DateAppearance.SelectedDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.SelectedDateFont.Color = clWindowText
      Calendar.DateAppearance.SelectedDateFont.Height = -11
      Calendar.DateAppearance.SelectedDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.SelectedDateFont.Style = []
      Calendar.DateAppearance.SelectedDateFill.Color = 11196927
      Calendar.DateAppearance.SelectedDateFill.ColorTo = 7257087
      Calendar.DateAppearance.SelectedDateFill.ColorMirror = 4370174
      Calendar.DateAppearance.SelectedDateFill.ColorMirrorTo = 8053246
      Calendar.DateAppearance.SelectedDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.SelectedDateFill.BorderColor = 4370174
      Calendar.DateAppearance.SelectedDateFill.Rounding = 0
      Calendar.DateAppearance.SelectedDateFill.ShadowOffset = 0
      Calendar.DateAppearance.CurrentDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.CurrentDateFont.Color = clWindowText
      Calendar.DateAppearance.CurrentDateFont.Height = -11
      Calendar.DateAppearance.CurrentDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.CurrentDateFont.Style = []
      Calendar.DateAppearance.CurrentDateFill.Color = 7778289
      Calendar.DateAppearance.CurrentDateFill.ColorTo = 4296947
      Calendar.DateAppearance.CurrentDateFill.ColorMirror = 946929
      Calendar.DateAppearance.CurrentDateFill.ColorMirrorTo = 5021693
      Calendar.DateAppearance.CurrentDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.CurrentDateFill.BorderColor = 4548219
      Calendar.DateAppearance.CurrentDateFill.Rounding = 0
      Calendar.DateAppearance.CurrentDateFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFill.Color = 16773091
      Calendar.DateAppearance.WeekendFill.ColorTo = 16768452
      Calendar.DateAppearance.WeekendFill.ColorMirror = 16765357
      Calendar.DateAppearance.WeekendFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.WeekendFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.WeekendFill.BorderColor = clNone
      Calendar.DateAppearance.WeekendFill.Rounding = 0
      Calendar.DateAppearance.WeekendFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekendFont.Color = clWindowText
      Calendar.DateAppearance.WeekendFont.Height = -11
      Calendar.DateAppearance.WeekendFont.Name = 'Tahoma'
      Calendar.DateAppearance.WeekendFont.Style = []
      Calendar.DateAppearance.HoverDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.HoverDateFont.Color = clWindowText
      Calendar.DateAppearance.HoverDateFont.Height = -11
      Calendar.DateAppearance.HoverDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.HoverDateFont.Style = []
      Calendar.DateAppearance.HoverDateFill.Color = 15465983
      Calendar.DateAppearance.HoverDateFill.ColorTo = 11332863
      Calendar.DateAppearance.HoverDateFill.ColorMirror = 5888767
      Calendar.DateAppearance.HoverDateFill.ColorMirrorTo = 10807807
      Calendar.DateAppearance.HoverDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.HoverDateFill.BorderColor = 10079963
      Calendar.DateAppearance.HoverDateFill.Rounding = 0
      Calendar.DateAppearance.HoverDateFill.ShadowOffset = 0
      Calendar.DateAppearance.MonthDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.MonthDateFont.Color = clWindowText
      Calendar.DateAppearance.MonthDateFont.Height = -11
      Calendar.DateAppearance.MonthDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.MonthDateFont.Style = []
      Calendar.DateAppearance.YearDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.YearDateFont.Color = clWindowText
      Calendar.DateAppearance.YearDateFont.Height = -11
      Calendar.DateAppearance.YearDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.YearDateFont.Style = []
      Calendar.DateAppearance.WeekNumbers.Font.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekNumbers.Font.Color = clWindowText
      Calendar.DateAppearance.WeekNumbers.Font.Height = -11
      Calendar.DateAppearance.WeekNumbers.Font.Name = 'Tahoma'
      Calendar.DateAppearance.WeekNumbers.Font.Style = []
      Calendar.DateAppearance.WeekNumbers.Fill.Color = 15984090
      Calendar.DateAppearance.WeekNumbers.Fill.ColorTo = 15785680
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirror = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirrorTo = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.BorderColor = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.Rounding = 0
      Calendar.DateAppearance.WeekNumbers.Fill.ShadowOffset = 0
      Calendar.DateAppearance.DisabledDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DisabledDateFont.Color = clGray
      Calendar.DateAppearance.DisabledDateFont.Height = -11
      Calendar.DateAppearance.DisabledDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DisabledDateFont.Style = []
      Calendar.DateAppearance.DisabledDateFill.Color = 15921906
      Calendar.DateAppearance.DisabledDateFill.ColorTo = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirror = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirrorTo = 15921906
      Calendar.DateAppearance.DisabledDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DisabledDateFill.BorderColor = clNone
      Calendar.DateAppearance.DisabledDateFill.Rounding = 0
      Calendar.DateAppearance.DisabledDateFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFill.Color = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirror = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateBeforeFill.BorderColor = clNone
      Calendar.DateAppearance.DateBeforeFill.Rounding = 0
      Calendar.DateAppearance.DateBeforeFill.ShadowOffset = 0
      Calendar.DateAppearance.DateAfterFill.Color = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirror = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateAfterFill.BorderColor = clNone
      Calendar.DateAppearance.DateAfterFill.Rounding = 0
      Calendar.DateAppearance.DateAfterFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateBeforeFont.Color = clSilver
      Calendar.DateAppearance.DateBeforeFont.Height = -11
      Calendar.DateAppearance.DateBeforeFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateBeforeFont.Style = []
      Calendar.DateAppearance.DateAfterFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateAfterFont.Color = clSilver
      Calendar.DateAppearance.DateAfterFont.Height = -11
      Calendar.DateAppearance.DateAfterFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateAfterFont.Style = []
      Calendar.StatusAppearance.Fill.Color = clRed
      Calendar.StatusAppearance.Fill.ColorMirror = clNone
      Calendar.StatusAppearance.Fill.ColorMirrorTo = clNone
      Calendar.StatusAppearance.Fill.GradientType = gtSolid
      Calendar.StatusAppearance.Fill.BorderColor = clGray
      Calendar.StatusAppearance.Fill.Rounding = 0
      Calendar.StatusAppearance.Fill.ShadowOffset = 0
      Calendar.StatusAppearance.Font.Charset = DEFAULT_CHARSET
      Calendar.StatusAppearance.Font.Color = clWhite
      Calendar.StatusAppearance.Font.Height = -11
      Calendar.StatusAppearance.Font.Name = 'Tahoma'
      Calendar.StatusAppearance.Font.Style = []
      Calendar.Footer.Fill.Color = 16773091
      Calendar.Footer.Fill.ColorTo = 16765615
      Calendar.Footer.Fill.ColorMirror = clNone
      Calendar.Footer.Fill.ColorMirrorTo = clNone
      Calendar.Footer.Fill.BorderColor = 16765615
      Calendar.Footer.Fill.Rounding = 0
      Calendar.Footer.Fill.ShadowOffset = 0
      Calendar.Footer.Font.Charset = DEFAULT_CHARSET
      Calendar.Footer.Font.Color = 7485192
      Calendar.Footer.Font.Height = -11
      Calendar.Footer.Font.Name = 'Tahoma'
      Calendar.Footer.Font.Style = []
      Calendar.Header.Fill.Color = 16773091
      Calendar.Header.Fill.ColorTo = 16765615
      Calendar.Header.Fill.ColorMirror = clNone
      Calendar.Header.Fill.ColorMirrorTo = clNone
      Calendar.Header.Fill.BorderColor = 16765615
      Calendar.Header.Fill.Rounding = 0
      Calendar.Header.Fill.ShadowOffset = 0
      Calendar.Header.ArrowColor = 7485192
      Calendar.Header.Font.Charset = DEFAULT_CHARSET
      Calendar.Header.Font.Color = 7485192
      Calendar.Header.Font.Height = -11
      Calendar.Header.Font.Name = 'Tahoma'
      Calendar.Header.Font.Style = []
      Calendar.Width = 257
      Calendar.Height = 249
      Calendar.ShowHint = False
      Date = 40630.000000000000000000
      DataField = 'DATA_PRZYJ'
      DataSource = m_DS
    end
    object m_NrRejED: TDBEdit
      Left = 352
      Top = 153
      Width = 107
      Height = 21
      DataField = 'NR_REJ'
      DataSource = m_DS
      TabOrder = 12
    end
    object m_NrFabrED: TDBEdit
      Left = 465
      Top = 153
      Width = 117
      Height = 21
      DataField = 'NR_FABR'
      DataSource = m_DS
      TabOrder = 13
    end
    object m_PodstED: TDBEdit
      Left = 211
      Top = 153
      Width = 135
      Height = 21
      DataField = 'PODSTAWA'
      DataSource = m_DS
      TabOrder = 11
    end
    object m_ProtPrzyjCB: TDBEdit
      Left = 103
      Top = 153
      Width = 102
      Height = 21
      DataField = 'PROT_PRZYJ'
      DataSource = m_DS
      TabOrder = 10
    end
    object m_RodzRemCB: TDBLookupComboBox
      Left = 103
      Top = 81
      Width = 57
      Height = 21
      DataField = 'ID_REMONTU'
      DataSource = m_DS
      DropDownRows = 15
      DropDownWidth = 120
      KeyField = 'ID_REMONTU'
      ListField = 'NAZWA'
      ListSource = m_RemDS
      NullValueKey = 46
      TabOrder = 5
    end
    object m_WarsztatCB: TDBLookupComboBox
      Left = 16
      Top = 81
      Width = 81
      Height = 21
      DataField = 'ID_KOMORKI'
      DataSource = m_DS
      DropDownWidth = 357
      KeyField = 'ID_KOMORKI'
      ListField = 'KOD; NAZWA'
      ListSource = m_WarsztatDS
      NullValueKey = 46
      TabOrder = 4
      OnCloseUp = clearWarKeyBuff
      OnDropDown = clearWarKeyBuff
      OnEnter = clearWarKeyBuff
      OnExit = clearWarKeyBuff
      OnKeyPress = m_WarsztatCBKeyPress
    end
    object m_DostCB: TAdvDBLookupComboBox
      Left = 166
      Top = 81
      Width = 106
      Height = 21
      DropDownType = ddAuto
      Enabled = True
      LabelPosition = lpLeftTop
      LabelMargin = 4
      LabelTransparent = False
      LabelAlwaysEnabled = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      LabelWidth = 0
      LookupColumn = 0
      LookupMethod = lmNormal
      LookupLoad = llAlways
      TabOrder = 6
      OnKeyUp = m_DostCBKeyUp
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 80
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'JW'
          Name = 'Column0'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 400
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'JEDNOSTKA'
          Name = 'Column1'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_JEDNOSTKI'
      DataSource = m_DS
      DropWidth = 350
      DropStretchColumn = -1
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      GridLines = False
      KeyField = 'ID_JEDNOSTKI'
      ListSource = m_JWDS
      SortUpGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080008080
        8000808080008080800080808000808080008080800080808000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000}
      SortDownGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00808080008080
        8000808080008080800080808000808080008080800080808000}
      ShowGridTitleRow = False
      Version = '1.8.1.0'
    end
    object DBAdvSmoothDatePicker1: TDBAdvSmoothDatePicker
      Left = 12
      Top = 221
      Width = 85
      Height = 21
      Flat = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      Lookup.Separator = ';'
      Color = clWindow
      Enabled = True
      ReadOnly = False
      TabOrder = 14
      Text = '2011-03-28'
      Visible = True
      OnKeyDown = DBAdvSmoothDateclearData
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        DA020000424DDA0200000000000036000000280000000D0000000D0000000100
        200000000000A402000000000000000000000000000000000000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F00000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000000000000000000000000000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F0000000000000000000000000000000000000000000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F0000000000000000000000000000000
        0000000000000000000000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000}
      HideCalendarAfterSelection = True
      Calendar.Fill.Color = 15984090
      Calendar.Fill.ColorTo = 15785680
      Calendar.Fill.ColorMirror = clNone
      Calendar.Fill.ColorMirrorTo = clNone
      Calendar.Fill.BorderColor = clNone
      Calendar.Fill.Rounding = 0
      Calendar.Fill.ShadowOffset = 0
      Calendar.Animation = True
      Calendar.ShowCurrentDate = True
      Calendar.DateAppearance.DateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateFont.Color = clWindowText
      Calendar.DateAppearance.DateFont.Height = -11
      Calendar.DateAppearance.DateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateFont.Style = []
      Calendar.DateAppearance.DateFill.Color = 16773091
      Calendar.DateAppearance.DateFill.ColorTo = 16768452
      Calendar.DateAppearance.DateFill.ColorMirror = 16765357
      Calendar.DateAppearance.DateFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.DateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DateFill.BorderColor = clNone
      Calendar.DateAppearance.DateFill.Rounding = 0
      Calendar.DateAppearance.DateFill.ShadowOffset = 0
      Calendar.DateAppearance.DayOfWeekFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DayOfWeekFont.Color = clWindowText
      Calendar.DateAppearance.DayOfWeekFont.Height = -11
      Calendar.DateAppearance.DayOfWeekFont.Name = 'Tahoma'
      Calendar.DateAppearance.DayOfWeekFont.Style = []
      Calendar.DateAppearance.DayOfWeekFill.Color = 15984090
      Calendar.DateAppearance.DayOfWeekFill.ColorTo = 15785680
      Calendar.DateAppearance.DayOfWeekFill.ColorMirror = clNone
      Calendar.DateAppearance.DayOfWeekFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DayOfWeekFill.BorderColor = clNone
      Calendar.DateAppearance.DayOfWeekFill.Rounding = 0
      Calendar.DateAppearance.DayOfWeekFill.ShadowOffset = 0
      Calendar.DateAppearance.SelectedDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.SelectedDateFont.Color = clWindowText
      Calendar.DateAppearance.SelectedDateFont.Height = -11
      Calendar.DateAppearance.SelectedDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.SelectedDateFont.Style = []
      Calendar.DateAppearance.SelectedDateFill.Color = 11196927
      Calendar.DateAppearance.SelectedDateFill.ColorTo = 7257087
      Calendar.DateAppearance.SelectedDateFill.ColorMirror = 4370174
      Calendar.DateAppearance.SelectedDateFill.ColorMirrorTo = 8053246
      Calendar.DateAppearance.SelectedDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.SelectedDateFill.BorderColor = 4370174
      Calendar.DateAppearance.SelectedDateFill.Rounding = 0
      Calendar.DateAppearance.SelectedDateFill.ShadowOffset = 0
      Calendar.DateAppearance.CurrentDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.CurrentDateFont.Color = clWindowText
      Calendar.DateAppearance.CurrentDateFont.Height = -11
      Calendar.DateAppearance.CurrentDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.CurrentDateFont.Style = []
      Calendar.DateAppearance.CurrentDateFill.Color = 7778289
      Calendar.DateAppearance.CurrentDateFill.ColorTo = 4296947
      Calendar.DateAppearance.CurrentDateFill.ColorMirror = 946929
      Calendar.DateAppearance.CurrentDateFill.ColorMirrorTo = 5021693
      Calendar.DateAppearance.CurrentDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.CurrentDateFill.BorderColor = 4548219
      Calendar.DateAppearance.CurrentDateFill.Rounding = 0
      Calendar.DateAppearance.CurrentDateFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFill.Color = 16773091
      Calendar.DateAppearance.WeekendFill.ColorTo = 16768452
      Calendar.DateAppearance.WeekendFill.ColorMirror = 16765357
      Calendar.DateAppearance.WeekendFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.WeekendFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.WeekendFill.BorderColor = clNone
      Calendar.DateAppearance.WeekendFill.Rounding = 0
      Calendar.DateAppearance.WeekendFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekendFont.Color = clWindowText
      Calendar.DateAppearance.WeekendFont.Height = -11
      Calendar.DateAppearance.WeekendFont.Name = 'Tahoma'
      Calendar.DateAppearance.WeekendFont.Style = []
      Calendar.DateAppearance.HoverDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.HoverDateFont.Color = clWindowText
      Calendar.DateAppearance.HoverDateFont.Height = -11
      Calendar.DateAppearance.HoverDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.HoverDateFont.Style = []
      Calendar.DateAppearance.HoverDateFill.Color = 15465983
      Calendar.DateAppearance.HoverDateFill.ColorTo = 11332863
      Calendar.DateAppearance.HoverDateFill.ColorMirror = 5888767
      Calendar.DateAppearance.HoverDateFill.ColorMirrorTo = 10807807
      Calendar.DateAppearance.HoverDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.HoverDateFill.BorderColor = 10079963
      Calendar.DateAppearance.HoverDateFill.Rounding = 0
      Calendar.DateAppearance.HoverDateFill.ShadowOffset = 0
      Calendar.DateAppearance.MonthDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.MonthDateFont.Color = clWindowText
      Calendar.DateAppearance.MonthDateFont.Height = -11
      Calendar.DateAppearance.MonthDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.MonthDateFont.Style = []
      Calendar.DateAppearance.YearDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.YearDateFont.Color = clWindowText
      Calendar.DateAppearance.YearDateFont.Height = -11
      Calendar.DateAppearance.YearDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.YearDateFont.Style = []
      Calendar.DateAppearance.WeekNumbers.Font.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekNumbers.Font.Color = clWindowText
      Calendar.DateAppearance.WeekNumbers.Font.Height = -11
      Calendar.DateAppearance.WeekNumbers.Font.Name = 'Tahoma'
      Calendar.DateAppearance.WeekNumbers.Font.Style = []
      Calendar.DateAppearance.WeekNumbers.Fill.Color = 15984090
      Calendar.DateAppearance.WeekNumbers.Fill.ColorTo = 15785680
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirror = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirrorTo = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.BorderColor = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.Rounding = 0
      Calendar.DateAppearance.WeekNumbers.Fill.ShadowOffset = 0
      Calendar.DateAppearance.DisabledDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DisabledDateFont.Color = clGray
      Calendar.DateAppearance.DisabledDateFont.Height = -11
      Calendar.DateAppearance.DisabledDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DisabledDateFont.Style = []
      Calendar.DateAppearance.DisabledDateFill.Color = 15921906
      Calendar.DateAppearance.DisabledDateFill.ColorTo = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirror = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirrorTo = 15921906
      Calendar.DateAppearance.DisabledDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DisabledDateFill.BorderColor = clNone
      Calendar.DateAppearance.DisabledDateFill.Rounding = 0
      Calendar.DateAppearance.DisabledDateFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFill.Color = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirror = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateBeforeFill.BorderColor = clNone
      Calendar.DateAppearance.DateBeforeFill.Rounding = 0
      Calendar.DateAppearance.DateBeforeFill.ShadowOffset = 0
      Calendar.DateAppearance.DateAfterFill.Color = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirror = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateAfterFill.BorderColor = clNone
      Calendar.DateAppearance.DateAfterFill.Rounding = 0
      Calendar.DateAppearance.DateAfterFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateBeforeFont.Color = clSilver
      Calendar.DateAppearance.DateBeforeFont.Height = -11
      Calendar.DateAppearance.DateBeforeFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateBeforeFont.Style = []
      Calendar.DateAppearance.DateAfterFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateAfterFont.Color = clSilver
      Calendar.DateAppearance.DateAfterFont.Height = -11
      Calendar.DateAppearance.DateAfterFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateAfterFont.Style = []
      Calendar.StatusAppearance.Fill.Color = clRed
      Calendar.StatusAppearance.Fill.ColorMirror = clNone
      Calendar.StatusAppearance.Fill.ColorMirrorTo = clNone
      Calendar.StatusAppearance.Fill.GradientType = gtSolid
      Calendar.StatusAppearance.Fill.BorderColor = clGray
      Calendar.StatusAppearance.Fill.Rounding = 0
      Calendar.StatusAppearance.Fill.ShadowOffset = 0
      Calendar.StatusAppearance.Font.Charset = DEFAULT_CHARSET
      Calendar.StatusAppearance.Font.Color = clWhite
      Calendar.StatusAppearance.Font.Height = -11
      Calendar.StatusAppearance.Font.Name = 'Tahoma'
      Calendar.StatusAppearance.Font.Style = []
      Calendar.Footer.Fill.Color = 16773091
      Calendar.Footer.Fill.ColorTo = 16765615
      Calendar.Footer.Fill.ColorMirror = clNone
      Calendar.Footer.Fill.ColorMirrorTo = clNone
      Calendar.Footer.Fill.BorderColor = 16765615
      Calendar.Footer.Fill.Rounding = 0
      Calendar.Footer.Fill.ShadowOffset = 0
      Calendar.Footer.Font.Charset = DEFAULT_CHARSET
      Calendar.Footer.Font.Color = 7485192
      Calendar.Footer.Font.Height = -11
      Calendar.Footer.Font.Name = 'Tahoma'
      Calendar.Footer.Font.Style = []
      Calendar.Header.Fill.Color = 16773091
      Calendar.Header.Fill.ColorTo = 16765615
      Calendar.Header.Fill.ColorMirror = clNone
      Calendar.Header.Fill.ColorMirrorTo = clNone
      Calendar.Header.Fill.BorderColor = 16765615
      Calendar.Header.Fill.Rounding = 0
      Calendar.Header.Fill.ShadowOffset = 0
      Calendar.Header.ArrowColor = 7485192
      Calendar.Header.Font.Charset = DEFAULT_CHARSET
      Calendar.Header.Font.Color = 7485192
      Calendar.Header.Font.Height = -11
      Calendar.Header.Font.Name = 'Tahoma'
      Calendar.Header.Font.Style = []
      Calendar.Width = 257
      Calendar.Height = 249
      Calendar.ShowHint = False
      Date = 40630.000000000000000000
      DataField = 'DATA_PROP_ZAK'
      DataSource = m_DS
    end
    object m_WydzCB: TDBLookupComboBox
      Left = 127
      Top = 22
      Width = 38
      Height = 21
      DropDownWidth = 411
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD; NAZWA'
      ListSource = m_WydzDS
      TabOrder = 3
    end
  end
  object m_TopPA: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 592
    Height = 49
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
    Caption.ColorStart = clBlack
    Caption.ColorEnd = clBlack
    Caption.LineColor = 13542013
    Fill.Color = 16575452
    Fill.ColorTo = 16575452
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = clNone
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alTop
    TabOrder = 0
    object Label15: TLabel
      Left = 188
      Top = 5
      Width = 263
      Height = 13
      Caption = 'Zadanie,ilo'#347#263' planowana i pozosta'#322'a do wykorzystania:'
      Transparent = True
    end
    object Label11: TLabel
      Left = 121
      Top = 6
      Width = 46
      Height = 13
      Caption = 'Nr harm.:'
      Transparent = True
    end
    object m_FindHarmBB: TSpeedButton
      Left = 544
      Top = 21
      Width = 38
      Height = 22
      Hint = 'Wyszukaj numer harmonogramu'
      Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0E5A
        3E0F5B3F1262440E5A3EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF15614417634629855F449C773D7F65FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1E6A4C216D4F368F
        6B52A58398C5B2256F52FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF2B7859459A7963B0929EC9B8357E61277455FFFFFFFFFFFF
        FFFFFF50505050505050505050505050505050505098989856A68874BAA0A3CD
        BD3D8768317F5EFFFFFFFFFFFF5656565656567F7F7FC9C9C9ECECECECECECC9
        C9C97F7F7F5F5F5F606060AAD2C245906F3B8A67FFFFFFFFFFFFFFFFFF5C5C5C
        AEAEAEFAFAFAF8F8F8F4F4F4F4F4F4F8F8F8FAFAFAA9A9A95F5F5F989898FFFF
        FFFFFFFFFFFFFFFFFFFF636363939393F8F8F8EEEEEEEDEDEDEDEDEDEDEDEDED
        EDEDEFEFEFF6F6F6888888636363FFFFFFFFFFFFFFFFFFFFFFFF6B6B6BD6D6D6
        EEEEEEE6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6E6F0F0F0D6D6D66B6B6BFFFF
        FFFFFFFFFFFFFFFFFFFF737373F1F1F1E0E0E0DEDEDEDEDEDEDEDEDEDEDEDEDE
        DEDEDEDEDEE1E1E1EFEFEF737373FFFFFFFFFFFFFFFFFFFFFFFF7B7B7BF1F1F1
        DCDCDCD7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7D7DDDDDDEDEDED7B7B7BFFFF
        FFFFFFFFFFFFFFFFFFFF838383DBDBDBE4E4E4D0D0D0CFCFCFCFCFCFCFCFCFCF
        CFCFD1D1D1E8E8E8DCDCDC838383FFFFFFFFFFFFFFFFFFFFFFFF8A8A8AB1B1B1
        F3F3F3D6D6D6CCCCCCCACACACACACACCCCCCD8D8D8F3F3F3A6A6A68A8A8AFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFF919191CCCCCCF4F4F4E6E6E6D9D9D9D9D9D9E6
        E6E6F4F4F4C7C7C7919191FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF979797
        979797B8B8B8DFDFDFF1F1F1F1F1F1DFDFDFB8B8B8979797979797FFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9D9D9D9D9D9D9D9D9D9D9D9D9D
        9D9D9D9D9DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      OnClick = m_FindHarmBBClick
    end
    object Label22: TLabel
      Left = 73
      Top = 6
      Width = 42
      Height = 13
      Caption = 'Wydzia'#322':'
      Transparent = True
    end
    object Label23: TLabel
      Left = 12
      Top = 6
      Width = 46
      Height = 13
      Caption = 'Rok dost.'
      Transparent = True
    end
    object m_PlanCB: TAdvDBLookupComboBox
      Left = 121
      Top = 24
      Width = 61
      Height = 21
      DropDownType = ddOnError
      Enabled = True
      LabelPosition = lpLeftTop
      LabelMargin = 4
      LabelTransparent = False
      LabelAlwaysEnabled = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      LabelWidth = 0
      LookupColumn = 0
      LookupMethod = lmNormal
      LookupLoad = llAlways
      TabOrder = 2
      Columns = <
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 50
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'ID_HARMONOGRAMU'
          Name = 'Column0'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end
        item
          FixedColor = clBtnFace
          FixedColorTo = clNone
          GradientDir = gdVertical
          Width = 480
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ListField = 'NAZ_ZAD'
          Name = 'Column1'
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
        end>
      DataField = 'ID_HARM'
      DataSource = m_DS
      DropWidth = 570
      DropStretchColumn = -1
      DropHeight = 400
      DropFont.Charset = DEFAULT_CHARSET
      DropFont.Color = clWindowText
      DropFont.Height = -11
      DropFont.Name = 'Tahoma'
      DropFont.Style = []
      KeyField = 'ID_HARMONOGRAMU'
      ListSource = m_PlanDS
      SortUpGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080008080
        8000808080008080800080808000808080008080800080808000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000}
      SortDownGlyph.Data = {
        36010000424D3601000000000000360000002800000008000000080000000100
        2000000000000001000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C00080808000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C0008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
        C00080808000C0C0C000C0C0C000FFFFFF00C0C0C000C0C0C000C0C0C0008080
        800080808000C0C0C000C0C0C000FFFFFF00FFFFFF00C0C0C000C0C0C0008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00C0C0C000808080008080
        8000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00FFFFFF00808080008080
        8000808080008080800080808000808080008080800080808000}
      ShowGridTitleRow = False
      Version = '1.8.1.0'
    end
    object m_PlanSprzetED: TDBEdit
      Left = 188
      Top = 24
      Width = 292
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'NAZ_ZAD'
      DataSource = m_PlanDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 3
    end
    object m_Wydz1CB: TDBLookupComboBox
      Left = 72
      Top = 25
      Width = 42
      Height = 21
      DropDownWidth = 527
      KeyField = 'ID_WYDZIALU'
      ListField = 'KOD; NAZWA'
      ListSource = m_WydzDS
      TabOrder = 1
    end
    object DBEdit3: TDBEdit
      Left = 486
      Top = 24
      Width = 24
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC'
      DataSource = m_PlanDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 4
    end
    object m_RokPlCB: TDBLookupComboBox
      Left = 15
      Top = 25
      Width = 52
      Height = 21
      DataField = 'ROK'
      DataSource = m_DS
      DropDownRows = 10
      KeyField = 'ROK'
      ListField = 'ROK'
      ListSource = m_RokPlDS
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 516
      Top = 23
      Width = 24
      Height = 19
      TabStop = False
      Color = clInfoBk
      Ctl3D = False
      DataField = 'ILOSC_DOST'
      DataSource = m_PlanDS
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 5
    end
  end
  object m_Bottom1PA: TAdvSmoothPanel
    Left = 0
    Top = 305
    Width = 592
    Height = 49
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
    Caption.ColorStart = clBlack
    Caption.ColorEnd = clBlack
    Caption.LineColor = 13542013
    Fill.Color = 16571328
    Fill.ColorTo = 16571328
    Fill.ColorMirror = clNone
    Fill.ColorMirrorTo = clNone
    Fill.GradientMirrorType = gtVertical
    Fill.BorderColor = clNone
    Fill.Rounding = 10
    Fill.RoundingType = rtNone
    Fill.ShadowOffset = 0
    Version = '1.0.9.2'
    Align = alBottom
    TabOrder = 2
    object Label8: TLabel
      Left = 9
      Top = 1
      Width = 88
      Height = 13
      Caption = 'Data zako'#324'czenia:'
      Transparent = True
    end
    object Label19: TLabel
      Left = 103
      Top = 1
      Width = 60
      Height = 13
      Caption = 'Data przek.:'
      Transparent = True
    end
    object Label20: TLabel
      Left = 194
      Top = 1
      Width = 75
      Height = 13
      Caption = 'Nr prot. przek.:'
      Transparent = True
    end
    object DBAdvSmoothDatePicker2: TDBAdvSmoothDatePicker
      Left = 12
      Top = 18
      Width = 85
      Height = 21
      Flat = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      Lookup.Separator = ';'
      Color = clWindow
      Enabled = True
      ReadOnly = False
      TabOrder = 0
      Text = '2011-03-28'
      Visible = True
      OnKeyDown = DBAdvSmoothDateclearData
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        DA020000424DDA0200000000000036000000280000000D0000000D0000000100
        200000000000A402000000000000000000000000000000000000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F00000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000000000000000000000000000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F0000000000000000000000000000000000000000000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F0000000000000000000000000000000
        0000000000000000000000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000}
      HideCalendarAfterSelection = True
      Calendar.Fill.Color = 15984090
      Calendar.Fill.ColorTo = 15785680
      Calendar.Fill.ColorMirror = clNone
      Calendar.Fill.ColorMirrorTo = clNone
      Calendar.Fill.BorderColor = clNone
      Calendar.Fill.Rounding = 0
      Calendar.Fill.ShadowOffset = 0
      Calendar.Animation = True
      Calendar.ShowCurrentDate = True
      Calendar.DateAppearance.DateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateFont.Color = clWindowText
      Calendar.DateAppearance.DateFont.Height = -11
      Calendar.DateAppearance.DateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateFont.Style = []
      Calendar.DateAppearance.DateFill.Color = 16773091
      Calendar.DateAppearance.DateFill.ColorTo = 16768452
      Calendar.DateAppearance.DateFill.ColorMirror = 16765357
      Calendar.DateAppearance.DateFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.DateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DateFill.BorderColor = clNone
      Calendar.DateAppearance.DateFill.Rounding = 0
      Calendar.DateAppearance.DateFill.ShadowOffset = 0
      Calendar.DateAppearance.DayOfWeekFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DayOfWeekFont.Color = clWindowText
      Calendar.DateAppearance.DayOfWeekFont.Height = -11
      Calendar.DateAppearance.DayOfWeekFont.Name = 'Tahoma'
      Calendar.DateAppearance.DayOfWeekFont.Style = []
      Calendar.DateAppearance.DayOfWeekFill.Color = 15984090
      Calendar.DateAppearance.DayOfWeekFill.ColorTo = 15785680
      Calendar.DateAppearance.DayOfWeekFill.ColorMirror = clNone
      Calendar.DateAppearance.DayOfWeekFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DayOfWeekFill.BorderColor = clNone
      Calendar.DateAppearance.DayOfWeekFill.Rounding = 0
      Calendar.DateAppearance.DayOfWeekFill.ShadowOffset = 0
      Calendar.DateAppearance.SelectedDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.SelectedDateFont.Color = clWindowText
      Calendar.DateAppearance.SelectedDateFont.Height = -11
      Calendar.DateAppearance.SelectedDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.SelectedDateFont.Style = []
      Calendar.DateAppearance.SelectedDateFill.Color = 11196927
      Calendar.DateAppearance.SelectedDateFill.ColorTo = 7257087
      Calendar.DateAppearance.SelectedDateFill.ColorMirror = 4370174
      Calendar.DateAppearance.SelectedDateFill.ColorMirrorTo = 8053246
      Calendar.DateAppearance.SelectedDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.SelectedDateFill.BorderColor = 4370174
      Calendar.DateAppearance.SelectedDateFill.Rounding = 0
      Calendar.DateAppearance.SelectedDateFill.ShadowOffset = 0
      Calendar.DateAppearance.CurrentDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.CurrentDateFont.Color = clWindowText
      Calendar.DateAppearance.CurrentDateFont.Height = -11
      Calendar.DateAppearance.CurrentDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.CurrentDateFont.Style = []
      Calendar.DateAppearance.CurrentDateFill.Color = 7778289
      Calendar.DateAppearance.CurrentDateFill.ColorTo = 4296947
      Calendar.DateAppearance.CurrentDateFill.ColorMirror = 946929
      Calendar.DateAppearance.CurrentDateFill.ColorMirrorTo = 5021693
      Calendar.DateAppearance.CurrentDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.CurrentDateFill.BorderColor = 4548219
      Calendar.DateAppearance.CurrentDateFill.Rounding = 0
      Calendar.DateAppearance.CurrentDateFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFill.Color = 16773091
      Calendar.DateAppearance.WeekendFill.ColorTo = 16768452
      Calendar.DateAppearance.WeekendFill.ColorMirror = 16765357
      Calendar.DateAppearance.WeekendFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.WeekendFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.WeekendFill.BorderColor = clNone
      Calendar.DateAppearance.WeekendFill.Rounding = 0
      Calendar.DateAppearance.WeekendFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekendFont.Color = clWindowText
      Calendar.DateAppearance.WeekendFont.Height = -11
      Calendar.DateAppearance.WeekendFont.Name = 'Tahoma'
      Calendar.DateAppearance.WeekendFont.Style = []
      Calendar.DateAppearance.HoverDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.HoverDateFont.Color = clWindowText
      Calendar.DateAppearance.HoverDateFont.Height = -11
      Calendar.DateAppearance.HoverDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.HoverDateFont.Style = []
      Calendar.DateAppearance.HoverDateFill.Color = 15465983
      Calendar.DateAppearance.HoverDateFill.ColorTo = 11332863
      Calendar.DateAppearance.HoverDateFill.ColorMirror = 5888767
      Calendar.DateAppearance.HoverDateFill.ColorMirrorTo = 10807807
      Calendar.DateAppearance.HoverDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.HoverDateFill.BorderColor = 10079963
      Calendar.DateAppearance.HoverDateFill.Rounding = 0
      Calendar.DateAppearance.HoverDateFill.ShadowOffset = 0
      Calendar.DateAppearance.MonthDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.MonthDateFont.Color = clWindowText
      Calendar.DateAppearance.MonthDateFont.Height = -11
      Calendar.DateAppearance.MonthDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.MonthDateFont.Style = []
      Calendar.DateAppearance.YearDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.YearDateFont.Color = clWindowText
      Calendar.DateAppearance.YearDateFont.Height = -11
      Calendar.DateAppearance.YearDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.YearDateFont.Style = []
      Calendar.DateAppearance.WeekNumbers.Font.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekNumbers.Font.Color = clWindowText
      Calendar.DateAppearance.WeekNumbers.Font.Height = -11
      Calendar.DateAppearance.WeekNumbers.Font.Name = 'Tahoma'
      Calendar.DateAppearance.WeekNumbers.Font.Style = []
      Calendar.DateAppearance.WeekNumbers.Fill.Color = 15984090
      Calendar.DateAppearance.WeekNumbers.Fill.ColorTo = 15785680
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirror = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirrorTo = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.BorderColor = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.Rounding = 0
      Calendar.DateAppearance.WeekNumbers.Fill.ShadowOffset = 0
      Calendar.DateAppearance.DisabledDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DisabledDateFont.Color = clGray
      Calendar.DateAppearance.DisabledDateFont.Height = -11
      Calendar.DateAppearance.DisabledDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DisabledDateFont.Style = []
      Calendar.DateAppearance.DisabledDateFill.Color = 15921906
      Calendar.DateAppearance.DisabledDateFill.ColorTo = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirror = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirrorTo = 15921906
      Calendar.DateAppearance.DisabledDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DisabledDateFill.BorderColor = clNone
      Calendar.DateAppearance.DisabledDateFill.Rounding = 0
      Calendar.DateAppearance.DisabledDateFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFill.Color = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirror = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateBeforeFill.BorderColor = clNone
      Calendar.DateAppearance.DateBeforeFill.Rounding = 0
      Calendar.DateAppearance.DateBeforeFill.ShadowOffset = 0
      Calendar.DateAppearance.DateAfterFill.Color = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirror = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateAfterFill.BorderColor = clNone
      Calendar.DateAppearance.DateAfterFill.Rounding = 0
      Calendar.DateAppearance.DateAfterFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateBeforeFont.Color = clSilver
      Calendar.DateAppearance.DateBeforeFont.Height = -11
      Calendar.DateAppearance.DateBeforeFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateBeforeFont.Style = []
      Calendar.DateAppearance.DateAfterFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateAfterFont.Color = clSilver
      Calendar.DateAppearance.DateAfterFont.Height = -11
      Calendar.DateAppearance.DateAfterFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateAfterFont.Style = []
      Calendar.StatusAppearance.Fill.Color = clRed
      Calendar.StatusAppearance.Fill.ColorMirror = clNone
      Calendar.StatusAppearance.Fill.ColorMirrorTo = clNone
      Calendar.StatusAppearance.Fill.GradientType = gtSolid
      Calendar.StatusAppearance.Fill.BorderColor = clGray
      Calendar.StatusAppearance.Fill.Rounding = 0
      Calendar.StatusAppearance.Fill.ShadowOffset = 0
      Calendar.StatusAppearance.Font.Charset = DEFAULT_CHARSET
      Calendar.StatusAppearance.Font.Color = clWhite
      Calendar.StatusAppearance.Font.Height = -11
      Calendar.StatusAppearance.Font.Name = 'Tahoma'
      Calendar.StatusAppearance.Font.Style = []
      Calendar.Footer.Fill.Color = 16773091
      Calendar.Footer.Fill.ColorTo = 16765615
      Calendar.Footer.Fill.ColorMirror = clNone
      Calendar.Footer.Fill.ColorMirrorTo = clNone
      Calendar.Footer.Fill.BorderColor = 16765615
      Calendar.Footer.Fill.Rounding = 0
      Calendar.Footer.Fill.ShadowOffset = 0
      Calendar.Footer.Font.Charset = DEFAULT_CHARSET
      Calendar.Footer.Font.Color = 7485192
      Calendar.Footer.Font.Height = -11
      Calendar.Footer.Font.Name = 'Tahoma'
      Calendar.Footer.Font.Style = []
      Calendar.Header.Fill.Color = 16773091
      Calendar.Header.Fill.ColorTo = 16765615
      Calendar.Header.Fill.ColorMirror = clNone
      Calendar.Header.Fill.ColorMirrorTo = clNone
      Calendar.Header.Fill.BorderColor = 16765615
      Calendar.Header.Fill.Rounding = 0
      Calendar.Header.Fill.ShadowOffset = 0
      Calendar.Header.ArrowColor = 7485192
      Calendar.Header.Font.Charset = DEFAULT_CHARSET
      Calendar.Header.Font.Color = 7485192
      Calendar.Header.Font.Height = -11
      Calendar.Header.Font.Name = 'Tahoma'
      Calendar.Header.Font.Style = []
      Calendar.Width = 257
      Calendar.Height = 249
      Calendar.ShowHint = False
      Date = 40630.000000000000000000
      DataField = 'DATA_ZAK'
      DataSource = m_DS
    end
    object DBAdvSmoothDatePicker3: TDBAdvSmoothDatePicker
      Left = 103
      Top = 18
      Width = 85
      Height = 21
      Flat = False
      LabelFont.Charset = DEFAULT_CHARSET
      LabelFont.Color = clWindowText
      LabelFont.Height = -11
      LabelFont.Name = 'Tahoma'
      LabelFont.Style = []
      Lookup.Separator = ';'
      Color = clWindow
      Enabled = True
      ReadOnly = False
      TabOrder = 1
      Text = '2011-03-28'
      Visible = True
      OnKeyDown = DBAdvSmoothDateclearData
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        DA020000424DDA0200000000000036000000280000000D0000000D0000000100
        200000000000A402000000000000000000000000000000000000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F00000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000000000000000000000000000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F0000000000000000000000000000000000000000000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F0000000000000000000000000000000
        0000000000000000000000000000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0
        F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000F0F0F000}
      HideCalendarAfterSelection = True
      Calendar.Fill.Color = 15984090
      Calendar.Fill.ColorTo = 15785680
      Calendar.Fill.ColorMirror = clNone
      Calendar.Fill.ColorMirrorTo = clNone
      Calendar.Fill.BorderColor = clNone
      Calendar.Fill.Rounding = 0
      Calendar.Fill.ShadowOffset = 0
      Calendar.Animation = True
      Calendar.ShowCurrentDate = True
      Calendar.DateAppearance.DateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateFont.Color = clWindowText
      Calendar.DateAppearance.DateFont.Height = -11
      Calendar.DateAppearance.DateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateFont.Style = []
      Calendar.DateAppearance.DateFill.Color = 16773091
      Calendar.DateAppearance.DateFill.ColorTo = 16768452
      Calendar.DateAppearance.DateFill.ColorMirror = 16765357
      Calendar.DateAppearance.DateFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.DateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DateFill.BorderColor = clNone
      Calendar.DateAppearance.DateFill.Rounding = 0
      Calendar.DateAppearance.DateFill.ShadowOffset = 0
      Calendar.DateAppearance.DayOfWeekFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DayOfWeekFont.Color = clWindowText
      Calendar.DateAppearance.DayOfWeekFont.Height = -11
      Calendar.DateAppearance.DayOfWeekFont.Name = 'Tahoma'
      Calendar.DateAppearance.DayOfWeekFont.Style = []
      Calendar.DateAppearance.DayOfWeekFill.Color = 15984090
      Calendar.DateAppearance.DayOfWeekFill.ColorTo = 15785680
      Calendar.DateAppearance.DayOfWeekFill.ColorMirror = clNone
      Calendar.DateAppearance.DayOfWeekFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DayOfWeekFill.BorderColor = clNone
      Calendar.DateAppearance.DayOfWeekFill.Rounding = 0
      Calendar.DateAppearance.DayOfWeekFill.ShadowOffset = 0
      Calendar.DateAppearance.SelectedDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.SelectedDateFont.Color = clWindowText
      Calendar.DateAppearance.SelectedDateFont.Height = -11
      Calendar.DateAppearance.SelectedDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.SelectedDateFont.Style = []
      Calendar.DateAppearance.SelectedDateFill.Color = 11196927
      Calendar.DateAppearance.SelectedDateFill.ColorTo = 7257087
      Calendar.DateAppearance.SelectedDateFill.ColorMirror = 4370174
      Calendar.DateAppearance.SelectedDateFill.ColorMirrorTo = 8053246
      Calendar.DateAppearance.SelectedDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.SelectedDateFill.BorderColor = 4370174
      Calendar.DateAppearance.SelectedDateFill.Rounding = 0
      Calendar.DateAppearance.SelectedDateFill.ShadowOffset = 0
      Calendar.DateAppearance.CurrentDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.CurrentDateFont.Color = clWindowText
      Calendar.DateAppearance.CurrentDateFont.Height = -11
      Calendar.DateAppearance.CurrentDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.CurrentDateFont.Style = []
      Calendar.DateAppearance.CurrentDateFill.Color = 7778289
      Calendar.DateAppearance.CurrentDateFill.ColorTo = 4296947
      Calendar.DateAppearance.CurrentDateFill.ColorMirror = 946929
      Calendar.DateAppearance.CurrentDateFill.ColorMirrorTo = 5021693
      Calendar.DateAppearance.CurrentDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.CurrentDateFill.BorderColor = 4548219
      Calendar.DateAppearance.CurrentDateFill.Rounding = 0
      Calendar.DateAppearance.CurrentDateFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFill.Color = 16773091
      Calendar.DateAppearance.WeekendFill.ColorTo = 16768452
      Calendar.DateAppearance.WeekendFill.ColorMirror = 16765357
      Calendar.DateAppearance.WeekendFill.ColorMirrorTo = 16767936
      Calendar.DateAppearance.WeekendFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.WeekendFill.BorderColor = clNone
      Calendar.DateAppearance.WeekendFill.Rounding = 0
      Calendar.DateAppearance.WeekendFill.ShadowOffset = 0
      Calendar.DateAppearance.WeekendFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekendFont.Color = clWindowText
      Calendar.DateAppearance.WeekendFont.Height = -11
      Calendar.DateAppearance.WeekendFont.Name = 'Tahoma'
      Calendar.DateAppearance.WeekendFont.Style = []
      Calendar.DateAppearance.HoverDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.HoverDateFont.Color = clWindowText
      Calendar.DateAppearance.HoverDateFont.Height = -11
      Calendar.DateAppearance.HoverDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.HoverDateFont.Style = []
      Calendar.DateAppearance.HoverDateFill.Color = 15465983
      Calendar.DateAppearance.HoverDateFill.ColorTo = 11332863
      Calendar.DateAppearance.HoverDateFill.ColorMirror = 5888767
      Calendar.DateAppearance.HoverDateFill.ColorMirrorTo = 10807807
      Calendar.DateAppearance.HoverDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.HoverDateFill.BorderColor = 10079963
      Calendar.DateAppearance.HoverDateFill.Rounding = 0
      Calendar.DateAppearance.HoverDateFill.ShadowOffset = 0
      Calendar.DateAppearance.MonthDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.MonthDateFont.Color = clWindowText
      Calendar.DateAppearance.MonthDateFont.Height = -11
      Calendar.DateAppearance.MonthDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.MonthDateFont.Style = []
      Calendar.DateAppearance.YearDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.YearDateFont.Color = clWindowText
      Calendar.DateAppearance.YearDateFont.Height = -11
      Calendar.DateAppearance.YearDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.YearDateFont.Style = []
      Calendar.DateAppearance.WeekNumbers.Font.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.WeekNumbers.Font.Color = clWindowText
      Calendar.DateAppearance.WeekNumbers.Font.Height = -11
      Calendar.DateAppearance.WeekNumbers.Font.Name = 'Tahoma'
      Calendar.DateAppearance.WeekNumbers.Font.Style = []
      Calendar.DateAppearance.WeekNumbers.Fill.Color = 15984090
      Calendar.DateAppearance.WeekNumbers.Fill.ColorTo = 15785680
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirror = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.ColorMirrorTo = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.BorderColor = clNone
      Calendar.DateAppearance.WeekNumbers.Fill.Rounding = 0
      Calendar.DateAppearance.WeekNumbers.Fill.ShadowOffset = 0
      Calendar.DateAppearance.DisabledDateFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DisabledDateFont.Color = clGray
      Calendar.DateAppearance.DisabledDateFont.Height = -11
      Calendar.DateAppearance.DisabledDateFont.Name = 'Tahoma'
      Calendar.DateAppearance.DisabledDateFont.Style = []
      Calendar.DateAppearance.DisabledDateFill.Color = 15921906
      Calendar.DateAppearance.DisabledDateFill.ColorTo = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirror = 11974326
      Calendar.DateAppearance.DisabledDateFill.ColorMirrorTo = 15921906
      Calendar.DateAppearance.DisabledDateFill.GradientMirrorType = gtVertical
      Calendar.DateAppearance.DisabledDateFill.BorderColor = clNone
      Calendar.DateAppearance.DisabledDateFill.Rounding = 0
      Calendar.DateAppearance.DisabledDateFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFill.Color = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirror = clNone
      Calendar.DateAppearance.DateBeforeFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateBeforeFill.BorderColor = clNone
      Calendar.DateAppearance.DateBeforeFill.Rounding = 0
      Calendar.DateAppearance.DateBeforeFill.ShadowOffset = 0
      Calendar.DateAppearance.DateAfterFill.Color = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirror = clNone
      Calendar.DateAppearance.DateAfterFill.ColorMirrorTo = clNone
      Calendar.DateAppearance.DateAfterFill.BorderColor = clNone
      Calendar.DateAppearance.DateAfterFill.Rounding = 0
      Calendar.DateAppearance.DateAfterFill.ShadowOffset = 0
      Calendar.DateAppearance.DateBeforeFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateBeforeFont.Color = clSilver
      Calendar.DateAppearance.DateBeforeFont.Height = -11
      Calendar.DateAppearance.DateBeforeFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateBeforeFont.Style = []
      Calendar.DateAppearance.DateAfterFont.Charset = DEFAULT_CHARSET
      Calendar.DateAppearance.DateAfterFont.Color = clSilver
      Calendar.DateAppearance.DateAfterFont.Height = -11
      Calendar.DateAppearance.DateAfterFont.Name = 'Tahoma'
      Calendar.DateAppearance.DateAfterFont.Style = []
      Calendar.StatusAppearance.Fill.Color = clRed
      Calendar.StatusAppearance.Fill.ColorMirror = clNone
      Calendar.StatusAppearance.Fill.ColorMirrorTo = clNone
      Calendar.StatusAppearance.Fill.GradientType = gtSolid
      Calendar.StatusAppearance.Fill.BorderColor = clGray
      Calendar.StatusAppearance.Fill.Rounding = 0
      Calendar.StatusAppearance.Fill.ShadowOffset = 0
      Calendar.StatusAppearance.Font.Charset = DEFAULT_CHARSET
      Calendar.StatusAppearance.Font.Color = clWhite
      Calendar.StatusAppearance.Font.Height = -11
      Calendar.StatusAppearance.Font.Name = 'Tahoma'
      Calendar.StatusAppearance.Font.Style = []
      Calendar.Footer.Fill.Color = 16773091
      Calendar.Footer.Fill.ColorTo = 16765615
      Calendar.Footer.Fill.ColorMirror = clNone
      Calendar.Footer.Fill.ColorMirrorTo = clNone
      Calendar.Footer.Fill.BorderColor = 16765615
      Calendar.Footer.Fill.Rounding = 0
      Calendar.Footer.Fill.ShadowOffset = 0
      Calendar.Footer.Font.Charset = DEFAULT_CHARSET
      Calendar.Footer.Font.Color = 7485192
      Calendar.Footer.Font.Height = -11
      Calendar.Footer.Font.Name = 'Tahoma'
      Calendar.Footer.Font.Style = []
      Calendar.Header.Fill.Color = 16773091
      Calendar.Header.Fill.ColorTo = 16765615
      Calendar.Header.Fill.ColorMirror = clNone
      Calendar.Header.Fill.ColorMirrorTo = clNone
      Calendar.Header.Fill.BorderColor = 16765615
      Calendar.Header.Fill.Rounding = 0
      Calendar.Header.Fill.ShadowOffset = 0
      Calendar.Header.ArrowColor = 7485192
      Calendar.Header.Font.Charset = DEFAULT_CHARSET
      Calendar.Header.Font.Color = 7485192
      Calendar.Header.Font.Height = -11
      Calendar.Header.Font.Name = 'Tahoma'
      Calendar.Header.Font.Style = []
      Calendar.Width = 257
      Calendar.Height = 249
      Calendar.ShowHint = False
      Date = 40630.000000000000000000
      DataField = 'DATA_PRZEKAZ'
      DataSource = m_DS
    end
    object DBEdit2: TDBEdit
      Left = 194
      Top = 18
      Width = 102
      Height = 21
      DataField = 'PROT_PRZEKAZ'
      DataSource = m_DS
      TabOrder = 2
    end
  end
  object m_SprzetDS: TDataSource
    Left = 89
    Top = 344
  end
  object m_DS: TDataSource
    Left = 400
    Top = 60
  end
  object m_PlanDS: TDataSource
    Left = 13
    Top = 344
  end
  object m_JWDS: TDataSource
    Left = 317
    Top = 344
  end
  object m_WarsztatDS: TDataSource
    Left = 177
    Top = 344
  end
  object m_RemDS: TDataSource
    Left = 245
    Top = 344
  end
  object m_SerwisCD: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'KOD_SERWISU'
        Attributes = [faUnNamed]
        DataType = ftString
        Size = 1
      end
      item
        Name = 'NAZ_SERWISU'
        Attributes = [faUnNamed]
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 384
    Top = 8
  end
  object m_SerwisDS: TDataSource
    DataSet = m_SerwisCD
    Left = 280
    Top = 20
  end
  object m_WydzDS: TDataSource
    OnDataChange = m_WydzDSDataChange
    Left = 245
    Top = 64
  end
  object m_RokPlDS: TDataSource
    Left = 309
    Top = 56
  end
end
