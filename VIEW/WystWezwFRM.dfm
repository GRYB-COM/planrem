object _WystWezwFRM: T_WystWezwFRM
  Left = 0
  Top = 0
  Caption = 'Wystawianie wezwa'#324
  ClientHeight = 424
  ClientWidth = 437
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_BottomASP: TAdvSmoothPanel
    Left = 0
    Top = 392
    Width = 437
    Height = 32
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
    Align = alBottom
    TabOrder = 0
    DesignSize = (
      437
      32)
    object m_DodajBB: TAdvSmoothButton
      Left = 3
      Top = 6
      Width = 68
      Height = 20
      Anchors = [akLeft, akBottom]
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
      Caption = 'Wystaw'
      Color = 16644337
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Version = '1.6.9.1'
    end
    object m_EdytujBB: TAdvSmoothButton
      Left = 355
      Top = 6
      Width = 79
      Height = 20
      Anchors = [akRight, akBottom]
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
      Caption = 'Zamknij'
      Color = 16644337
      TabOrder = 1
      Version = '1.6.9.1'
      ModalResult = 2
    end
    object m_DelBB: TAdvSmoothButton
      Left = 83
      Top = 6
      Width = 68
      Height = 20
      Hint = 'Usu'#324' zaznaczone powiadomienie'
      Anchors = [akLeft, akBottom]
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
      Caption = 'Usu'#324
      Color = 16644337
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      Version = '1.6.9.1'
    end
  end
  object m_MainPA: TAdvSmoothPanel
    Left = 0
    Top = 0
    Width = 437
    Height = 392
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
    object m_DataWystLB: TLabel
      Left = 3
      Top = 9
      Width = 85
      Height = 13
      Caption = 'Data wystawienia'
      Transparent = True
    end
    object m_GridHeadLB: TLabel
      Left = 3
      Top = 102
      Width = 89
      Height = 14
      Caption = 'm_GridHeadLB'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Transparent = True
    end
    object m_DataWystDoLB: TLabel
      Left = 3
      Top = 47
      Width = 65
      Height = 13
      Caption = 'Data zak. do:'
      Transparent = True
    end
    object m_FiltrWezwRG: TAdvOfficeRadioGroup
      Left = 290
      Top = 9
      Width = 137
      Height = 75
      Version = '1.2.5.0'
      Caption = 'Filtr wezwa'#324
      ParentBackground = False
      TabOrder = 0
      OnClick = OnChange
      ItemIndex = 0
      Items.Strings = (
        'Pierwsze wezwanie'
        'Ostateczne wezwanie')
      Ellipsis = False
    end
    object m_DataWystDCP: TAdvSmoothDatePicker
      Left = 3
      Top = 24
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
      Text = '2011-10-18'
      Visible = True
      OnChange = OnChange
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        76020000424D760200000000000036000000280000000C0000000C0000000100
        2000000000004002000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000000000000000
        000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C0000000000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C0000000000000000000000000000000
        0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000}
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
      Date = 40834.000000000000000000
    end
    object m_ListaSprzGR: TDBAdvGrid
      Left = 0
      Top = 123
      Width = 437
      Height = 269
      Cursor = crDefault
      Align = alBottom
      Anchors = [akLeft, akTop, akRight, akBottom]
      ColCount = 3
      Constraints.MinHeight = 150
      Ctl3D = True
      DefaultRowHeight = 36
      DrawingStyle = gdsGradient
      FixedCols = 0
      RowCount = 2
      FixedRows = 1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goRowSelect]
      ParentCtl3D = False
      ParentFont = False
      ScrollBars = ssBoth
      TabOrder = 2
      ActiveRowShow = True
      ActiveRowColor = clMenuHighlight
      GridLineColor = 15855083
      GridFixedLineColor = 13745060
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ActiveCellColor = 10344697
      ActiveCellColorTo = 6210033
      AutoNumAlign = True
      Bands.Print = True
      BackGround.ColorTo = 6210033
      ColumnHeaders.Strings = (
        'Data wyst.'
        'Dostawca'
        'Ilo'#347#263)
      ControlLook.FixedGradientFrom = 16513526
      ControlLook.FixedGradientTo = 15260626
      ControlLook.FixedGradientHoverFrom = 15000287
      ControlLook.FixedGradientHoverTo = 14406605
      ControlLook.FixedGradientHoverMirrorFrom = 14406605
      ControlLook.FixedGradientHoverMirrorTo = 13813180
      ControlLook.FixedGradientHoverBorder = 12033927
      ControlLook.FixedGradientDownFrom = 14991773
      ControlLook.FixedGradientDownTo = 14991773
      ControlLook.FixedGradientDownMirrorFrom = 14991773
      ControlLook.FixedGradientDownMirrorTo = 14991773
      ControlLook.FixedGradientDownBorder = 14991773
      ControlLook.ControlStyle = csWinXP
      ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownHeader.Font.Color = clWindowText
      ControlLook.DropDownHeader.Font.Height = -11
      ControlLook.DropDownHeader.Font.Name = 'Tahoma'
      ControlLook.DropDownHeader.Font.Style = []
      ControlLook.DropDownHeader.Visible = True
      ControlLook.DropDownHeader.Buttons = <>
      ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownFooter.Font.Color = clWindowText
      ControlLook.DropDownFooter.Font.Height = -11
      ControlLook.DropDownFooter.Font.Name = 'Tahoma'
      ControlLook.DropDownFooter.Font.Style = []
      ControlLook.DropDownFooter.Visible = True
      ControlLook.DropDownFooter.Buttons = <>
      ExcelStyleDecimalSeparator = True
      Filter = <>
      FilterDropDown.Font.Charset = DEFAULT_CHARSET
      FilterDropDown.Font.Color = clWindowText
      FilterDropDown.Font.Height = -11
      FilterDropDown.Font.Name = 'Tahoma'
      FilterDropDown.Font.Style = []
      FilterDropDownClear = '(All)'
      FixedColWidth = 99
      FixedRowHeight = 10
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clWindowText
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      FloatFormat = '%.2f'
      Grouping.HeaderColor = clInfoBk
      Grouping.SummaryColor = clSilver
      Look = glOffice2007
      PrintSettings.Time = ppBottomLeft
      PrintSettings.Date = ppBottomLeft
      PrintSettings.DateFormat = 'dd/mm/yyyy'
      PrintSettings.PageNr = ppBottomRight
      PrintSettings.Title = ppTopCenter
      PrintSettings.Font.Charset = DEFAULT_CHARSET
      PrintSettings.Font.Color = clWindowText
      PrintSettings.Font.Height = -11
      PrintSettings.Font.Name = 'Tahoma'
      PrintSettings.Font.Style = []
      PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
      PrintSettings.FixedFont.Color = clWindowText
      PrintSettings.FixedFont.Height = -11
      PrintSettings.FixedFont.Name = 'Tahoma'
      PrintSettings.FixedFont.Style = []
      PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
      PrintSettings.HeaderFont.Color = clWindowText
      PrintSettings.HeaderFont.Height = -11
      PrintSettings.HeaderFont.Name = 'Tahoma'
      PrintSettings.HeaderFont.Style = []
      PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
      PrintSettings.FooterFont.Color = clWindowText
      PrintSettings.FooterFont.Height = -11
      PrintSettings.FooterFont.Name = 'Tahoma'
      PrintSettings.FooterFont.Style = []
      PrintSettings.LeftSize = 40
      PrintSettings.RightSize = 40
      PrintSettings.PagePrefix = 'Strona'
      PrintSettings.FitToPage = fpGrow
      PrintSettings.PageNumSep = '/'
      PrintSettings.PrintGraphics = True
      ScrollWidth = 16
      SearchFooter.Color = 16513526
      SearchFooter.ColorTo = clNone
      SearchFooter.FindNextCaption = 'Find &next'
      SearchFooter.FindPrevCaption = 'Find &previous'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'Tahoma'
      SearchFooter.Font.Style = []
      SearchFooter.HighLightCaption = 'Highlight'
      SearchFooter.HintClose = 'Close'
      SearchFooter.HintFindNext = 'Find next occurence'
      SearchFooter.HintFindPrev = 'Find previous occurence'
      SearchFooter.HintHighlight = 'Highlight occurences'
      SearchFooter.MatchCaseCaption = 'Match case'
      SelectionColor = 6210033
      Version = '2.2.0.0'
      AutoCreateColumns = True
      AutoRemoveColumns = True
      Columns = <
        item
          Borders = []
          BorderPen.Color = clSilver
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          FieldName = 'DATA_WYST'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Data wyst.'
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clWindowText
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          Width = 99
        end
        item
          Borders = []
          BorderPen.Color = clSilver
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          FieldName = 'JW_MIEJSC'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Dostawca'
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clWindowText
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          HeaderAlignment = taCenter
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          Width = 227
        end
        item
          Borders = []
          BorderPen.Color = clSilver
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          FieldName = 'ILOSC'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Ilo'#347#263
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clWindowText
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          HeaderAlignment = taCenter
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          Width = 70
        end>
      DataSource = m_ListaSprzDS
      InvalidPicture.Data = {
        055449636F6E0000010001002020200000000000A81000001600000028000000
        2000000040000000010020000000000000100000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000006A6A6B256A6A6B606A6A6B946A6A6BC06A6A6BE1
        6A6A6BF86A6A6BF86A6A6BE16A6A6BC06A6A6B946A6A6B606A6A6B2500000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000006A6A6B407575769E787879F19F9F9FF6C0C0C0FDDADADAFFEDEDEEFF
        FBFBFBFFFBFBFBFFEDEDEEFFDADADAFFC0C0C0FD9F9F9FF6787879F17575769E
        6A6A6B4000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000006A6A6B22
        7C7C7C98888889F0BDBDBDFCE9E9EBFED9D9E9FEB5B5DDFE8B8BCDFE595AB7FF
        3739A8FF2B2CA4FF4A49B1FF7171C1FFA1A2D7FFD3D3E8FFEAEAEBFEBEBEBFFC
        888889F07C7C7C986A6A6B220000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000006A6A6B43838383D8
        B7B7B8FAECECEFFEC0C0DFFF7977C4FF2221A0FF12129BFF1010A4FF0C0CA8FF
        0A0AACFF0A0AB4FF0A0AB9FF0D0DBEFF0F0FB1FF1111A6FF5656B8FFAEADDCFF
        ECECEFFEB7B7B8FA838383D86A6A6B4300000000000000000000000000000000
        00000000000000000000000000000000000000006A6A6B4E878788EAD3D3D3FE
        CACAE8FF4443B0FF171799FF11119CFF0C0C98FF0B0B9BFF0B0BA0FF0A0AA6FF
        0909ACFF0909B2FF0808BAFF0707BFFF0B09C8FF0D0DCEFF1111CCFF1010AFFF
        4A49B2FFCFCFEBFFD3D3D3FE878788EA6A6A6B4E000000000000000000000000
        000000000000000000000000000000006A6A6B43878788EAE1E1E1FFA8A8DAFF
        2323A0FF15159CFF0D0D92FF0C0C95FF0C0C99FF0B0B9EFF0B0BA0FF0A0AA6FF
        0909ACFF0909B2FF0808B8FF0808BCFF0808C3FF0C0CC9FF0C0CD0FF0D0DD6FF
        1313CFFF2222A9FFAFAFDEFFE1E1E1FF878788EA6A6A6B430000000000000000
        0000000000000000000000006A6A6B22838383D8D3D3D3FEA8A8D9FF2020A4FF
        13139BFF0C0C92FF0C0C95FF0C0C97FF0C0C99FF0B0B9EFF0B0BA0FF0A0AA4FF
        0A0AA9FF0909B0FF0808B4FF0808BBFF0707C0FF0A0AC6FF0909CCFF0C0CD3FF
        0D0DD8FF1313D3FF1A1AA8FFAEADDEFFD4D4D4FE838383D86A6A6B2200000000
        0000000000000000000000007C7C7C98B7B7B8FACACAE8FF2524A3FF13139FFF
        0C0C97FF0C0C95FF0C0C95FF0C0C91FF0C0C95FF0B0B9EFF0B0BA0FF0A0AA4FF
        0A0AA8FF0909ADFF0909B2FF0808B8FF0808BCFF0707C0FF0808BCFF0707C5FF
        0C0CD3FF0D0DD7FF1212D1FF2020A7FFCDCDEBFFB8B8B9FA7C7C7C9800000000
        00000000000000006A6A6B40888889F0ECECEFFE4545B1FF1616A4FF0B0B9BFF
        0C0C99FF0C0C96FF3333A2FFB9B9D0FF393A9BFF0C0C95FF0B0BA1FF0A0AA4FF
        0A0AA7FF0A0AABFF0909B0FF0808B4FF0808B7FF2F2FC2FFAEAEE2FF4B4BBFFF
        0707BEFF0B0BD1FF0C0CD3FF1413CCFF4848B1FFECECEFFE888889F06A6A6B40
        00000000000000007575769EBFBFBFFD9B9BD5FF1C1CA6FF0C0CA1FF0B0B9FFF
        0B0B9AFF3535A7FFB5B5BEFFE6E6DFFFEDEDEFFF3C3C9CFF0C0C97FF0A0AA4FF
        0A0AA6FF0A0AA9FF0909ADFF0909B0FF2626B5FFCECEDEFFFFFFFBFFEEEEF1FF
        4848BAFF0808BCFF0A0ACDFF0B0BCEFF1111ABFFBEC0E0FFBFC0BFFD7575769E
        000000006A6A6B25787879F1E3E3E5FE4646B2FF1414A8FF0A0AA4FF0B0BA0FF
        2121A9FFBDBDCAFFD0D0C8FFC5C5C5FFE3E3E1FFEDEDEFFF3E3E9EFF0C0C98FF
        0A0AA6FF0A0AA8FF0A0AA9FF2B2BB0FFC0C0CDFFEAEAE2FFEBEBEBFFFEFEF8FF
        EDEDEEFF2828BDFF0707C4FF0809C7FF0F0FC4FF8788CBFFEBEBECFE79797AF1
        6A6A6B256A6A6B609D9E9DF6D6D7E4FF3A3AB3FF1212ADFF0A0AA8FF0A0AA4FF
        1313AAFFABABCFFFD6D6CBFFCACACAFFC6C6C6FFE4E4E0FFEEEEEFFF3F3FA0FF
        0C0C99FF0A0AA6FF2828ABFFB2B2BFFFD8D8CEFFD6D6D8FFE0E0E0FFF6F5EDFF
        D1D1EDFF1E1CC0FF0707BEFF0707BFFF0707C0FF2120AAFFD3D5E9FE9FA0A0F6
        6A6A6B606A6A6B94BDBDBDFBBABBDCFF3A39B7FF2F2FB8FF0909ADFF0A0AA9FF
        0A0AA6FF1515ACFFADADCFFFD6D6CBFFCBCBCAFFC6C6C6FFE4E4E1FFEEEEEFFF
        3838A1FF2222A2FFACABB8FFC8C8C0FFC7C7C8FFCDCDCDFFE1E1D9FFC8CAE1FF
        2424BCFF0808B4FF0808B9FF0808BAFF0808BBFF0F0EABFFA1A2D5FEC0C0C0FC
        6A6A6B946A6A6BC0D9D8D7FE9999D1FF3838BBFF3636BCFF2C2CB7FF0909ADFF
        0A0AA9FF0A0AA4FF1C1CAFFFB1B1CFFFD6D6CBFFCCCCCBFFC7C7C7FFE4E4E1FF
        ECECEEFFACACB7FFC2C2BCFFBEBEBFFFC0C0C0FFCFCFC6FFC1C1D5FF2727B8FF
        0909ACFF0909B2FF0909B2FF0909B4FF0808B4FF0E0EB5FF6E6EBFFFD9D9D9FE
        6A6A6BC06A6A6BE1EBEAEBFF7D7CC7FF3838BFFF3434BEFF3536BEFF2A2AB8FF
        0909B0FF0909ACFF0A0AA8FF1C1CB1FFB2B2D0FFD7D7CCFFCBCBCBFFC7C7C8FF
        C8C8C3FFC6C6C3FFBFBFC1FFBDBDBDFFC5C5BCFFB8B8CEFF2929B5FF0A0AA8FF
        0909ACFF0909ADFF0909AFFF0909AFFF0909AFFF0C0CB0FF4747AFFFECECEDFF
        6A6A6BE16A6A6BF8F9F9F9FF6666C1FF3838C4FF3535C2FF3434C0FF3535BEFF
        3030BCFF1313B4FF0909ADFF0A0AA8FF1E1EB3FFAAAAD0FFD3D3CDFFCCCCCCFF
        C8C8C8FFC3C3C3FFC2C2C1FFC4C4BFFFB2B2CBFF2B2BB4FF0A0AA4FF0A0AA8FF
        0A0AA8FF0A0AA9FF0A0AA9FF0A0AA9FF0A0AA9FF0B0BA9FF3131A6FFFAFAFAFF
        6A6A6BF86A6A6BF8FBFBFBFF5959BEFF3B3BCAFF3A3AC8FF3737C4FF3535C2FF
        3636C0FF3636BEFF2323B8FF0909B1FF0A0AA7FF4949BEFFD6D6D4FFD3D3D1FF
        CDCDCDFFC8C8C8FFC4C4C3FFEDEDEDFF5F5FB3FF0C0C98FF0A0AA7FF0A0AA6FF
        0A0AA6FF0A0AA6FF0A0AA4FF0A0AA6FF0A0AA4FF0B0BA4FF2D2DA6FFFBFBFBFF
        6A6A6BF86A6A6BE1EDEDEEFF7F80CBFF4041CCFF3C3CCAFF3A3AC8FF383AC8FF
        3838C4FF3636C2FF3939C0FF2123B7FF4A4AC2FFCBCBDEFFE0E0DCFFD6D6D6FF
        D2D2D3FFCDCDCEFFC9C9C9FFE2E2E1FFF1F1F2FF4242A3FF0C0C99FF0A0AA4FF
        0A0AA4FF0A0AA4FF0B0BA3FF0B0BA3FF0B0BA1FF0E0EA1FF4443B0FFEDEDEEFF
        6A6A6BE16A6A6BC0DADADAFF9C9BD5FE4949CDFF3E3DD0FF3C3DCEFF3C3CCAFF
        3A3AC8FF3B39C7FF2828BDFF5C5CCCFFE5E5EDFFF4F4EDFFE5E5E6FFDEDEDEFF
        DCDCD9FFD9D9D3FFCDCDCDFFC8C8C8FFE5E5E1FFF1F1F3FF3F3FA0FF0C0C99FF
        0A0AA4FF0B0BA1FF0B0BA0FF0B0BA0FF0B0B9FFF1313A2FF6B6BC0FFDADADAFF
        6A6A6BC06A6A6B94C0C0C0FDBDBAE1FE5655CFFF4141D4FF3F3FD2FF3F3FCEFF
        3D3DCCFF2C2AC3FF5E5ED3FFEBEBF6FFFFFFFAFFF1F1F1FFEDEDEEFFF0F0E9FF
        D2D2E6FFBDBDD6FFDADAD3FFCFCFCFFFC9C9CAFFE5E5E2FFF1F1F3FF3A3AA0FF
        0C0C98FF0B0BA3FF0B0B9FFF0B0B9EFF0B0B9EFF1C1CA4FF9C9CD3FFC1C1C1FD
        6A6A6B946A6A6B609F9F9FF6DAD9EAFF6B6BCFFF4444D7FF4143D6FF4242D3FF
        3434CDFF6464DBFFEFEFFFFFFFFFFFFFFCFCFCFFF6F6F6FFFCFCF4FFE2E1F0FF
        5050CCFF4040C1FFC3C3DBFFE1E1D8FFD4D4D5FFCFCFCFFFE8E8E5FFF2F2F4FF
        4040A2FF0C0C99FF0F0FA2FF0F0FA0FF0F0F9DFF302FA9FFD1D1E8FEA0A0A0F6
        6A6A6B606A6A6B25787879F1E9E9EBFEA7A7DAFF6060DBFF4547DBFF3C3CD6FF
        5857DEFFF2F2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E8F8FF5B5BD4FF
        2828BDFF2A2BBDFF4949C5FFC3C3DBFFE4E4DAFFD5D5D5FFCECED0FFE8E8E5FF
        F4F4F4FF4949AFFF2121A6FF2A2AA6FF2C2BA9FF5557B8FFEAEAECFE787879F1
        6A6A6B25000000007575769EBEBEBEFDC9CAE6FF7A79DBFF4C4CDFFF4141DBFF
        5757E0FFEAEAFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8E7FFFF5B5BD7FF2E2EC6FF
        3E3EC9FF3A3AC5FF2C2EC1FF4A49C8FFC2C2DDFFE3E3DAFFD5D5D4FFDADAD3FF
        CACBD9FF4747BBFF2525ADFF2C2BACFF3332AEFFA5A4D8FFBFBFBFFD7575769E
        00000000000000006A6A6B40888889F0ECECEFFE9696D6FF7B7BE3FF4D4BE0FF
        4141DBFF5F5FE6FFE7E7FFFFFFFFFFFFE9E9FFFF5A5ADCFF3333CAFF4242CFFF
        4040CBFF3D3DC9FF3D3EC8FF3030C2FF4848C9FFC0C0DDFFECEEDEFFD0D0E0FF
        5554C7FF2828B3FF3232B4FF3434B1FF5453B7FFECECEFFE888889F06A6A6B40
        0000000000000000000000007C7C7C98B7B7B8FAD0D0ECFF8F8FDBFF6868E3FF
        4E4EE2FF3E40DBFF6565E9FFB2B2F7FF6565E4FF393BD2FF4646D7FF4343D4FF
        4343D1FF4242CFFF4040CBFF3F3FCAFF3333C4FF4E4ECBFF9E9EE2FF5C5BCFFF
        292ABAFF3636BCFF3938B8FF3F3EB1FFCBCBE9FFB7B7B8FA7C7C7C9800000000
        0000000000000000000000006A6A6B22838383D8D3D3D3FEB5B5E2FF9E9EE4FF
        6766E2FF4E50E6FF4646E0FF3D3DDAFF4444DCFF4B4BDCFF4848DBFF4847D9FF
        4646D5FF4443D3FF4343D1FF4242CFFF4143CDFF3A3AC8FF312FC5FF3535C3FF
        3C3CC3FF3D3DBEFF403FB5FFACACDCFFD3D3D3FE838383D86A6A6B2200000000
        000000000000000000000000000000006A6A6B43878788EAE1E1E1FFB5B5E2FF
        A7A6E4FF7877E5FF5151E5FF4F4FE4FF4E4EE2FF4D4DE0FF4C4CDEFF4B4BDCFF
        4949DBFF4848D7FF4747D5FF4545D3FF4545D1FF4343CFFF4242CCFF3F3FCBFF
        4343C2FF4645B6FFADADDCFFE1E1E1FF878788EA6A6A6B430000000000000000
        00000000000000000000000000000000000000006A6A6B4E878788EAD3D3D3FE
        D0D0ECFFAAA9DFFFA2A2ECFF6565E3FF5151E6FF4F4FE4FF4F4DE4FF4D4DE0FF
        4D4DDFFF4D4DDCFF4C49DBFF4A4AD8FF4749D6FF4747D4FF4949CBFF4B4BC3FF
        8E8ED0FFCDCCE8FFD3D3D3FE878788EA6A6A6B4E000000000000000000000000
        0000000000000000000000000000000000000000000000006A6A6B43838383D8
        B7B7B8FAECECEFFEC3C2E5FFADAEE1FF9E9DE8FF6F6FE0FF5C5CE1FF5452E2FF
        5051E1FF4F4FDFFF4F4FDBFF5150D6FF5151CFFF5F5FC8FFA1A1D3FEC7C8E0FE
        E4E4E7FEB7B7B8FA838383D86A6A6B4300000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000006A6A6B22
        7C7C7C98888889F0BFBFBFFDEBEBECFED8D9EBFEBDBDE4FEA8A7DCFF9695D7FF
        8886D4FF7F7DCEFF8C8BD2FFA1A2D9FFC0BEE1FED9D9EAFEEAEAECFEBFBFBFFD
        888889F07C7C7C986A6A6B220000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000006A6A6B407575769E787879F19F9F9FF6C0C0C0FDDADADAFFEDEDEEFF
        FBFBFBFFFBFBFBFFEDEDEEFFDADADAFFC0C0C0FD9F9F9FF6787879F17575769E
        6A6A6B4000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000006A6A6B256A6A6B606A6A6B946A6A6BC06A6A6BE1
        6A6A6BF86A6A6BF86A6A6BE16A6A6BC06A6A6B946A6A6B606A6A6B2500000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FFC003FFFF0000FFFC00003FF800001FF000000FE0000007C0000003
        C000000380000001800000010000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000080000001
        80000001C0000003C0000003E0000007F000000FF800001FFC00003FFF0000FF
        FFC003FF}
      ShowUnicode = False
      ColWidths = (
        99
        227
        70)
    end
    object m_ModeRG: TAdvOfficeRadioGroup
      Left = 94
      Top = 9
      Width = 190
      Height = 75
      Version = '1.2.5.0'
      Caption = 'Tryb pracy'
      ParentBackground = False
      TabOrder = 3
      OnClick = OnChange
      ItemIndex = 0
      Items.Strings = (
        'Wystaw nowe wezwanie'
        'Przegl'#261'daj istniej'#261'ce wezwawnia')
      Ellipsis = False
    end
    object m_DataWystDoDCP: TAdvSmoothDatePicker
      Left = 3
      Top = 63
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
      TabOrder = 4
      Text = '2011-10-18'
      Visible = True
      OnChange = OnChange
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        76020000424D760200000000000036000000280000000C0000000C0000000100
        2000000000004002000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000000000000000
        000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C0000000000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C0000000000000000000000000000000
        0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000}
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
      Date = 40834.000000000000000000
    end
    object m_DataWystOdDCP: TAdvSmoothDatePicker
      Left = 4
      Top = 24
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
      TabOrder = 5
      Text = '2011-10-18'
      Visible = True
      OnChange = OnChange
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        76020000424D760200000000000036000000280000000C0000000C0000000100
        2000000000004002000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000000000000000
        000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C0000000000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C0000000000000000000000000000000
        0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000}
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
      Date = 40834.000000000000000000
    end
    object m_DataZakDoDCP: TAdvSmoothDatePicker
      Left = 3
      Top = 63
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
      TabOrder = 6
      Text = '2011-10-18'
      Visible = True
      OnChange = OnChange
      Version = '2.0.1.6'
      ButtonStyle = bsDropDown
      ButtonWidth = 16
      Etched = False
      Glyph.Data = {
        76020000424D760200000000000036000000280000000C0000000C0000000100
        2000000000004002000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000000000000000
        000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C0000000000000000000000000000000000000000000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C0000000000000000000000000000000
        0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
        C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000}
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
      Date = 40834.000000000000000000
    end
  end
  object m_ListaSprzDS: TDataSource
    Left = 80
    Top = 152
  end
end
