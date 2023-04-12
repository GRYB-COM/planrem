object _MeldTygQRP: T_MeldTygQRP
  Left = 24
  Top = 145
  Caption = '_MeldTygQRP'
  ClientHeight = 693
  ClientWidth = 1284
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1284
    Height = 693
    ActivePage = TabSheet3
    Align = alClient
    TabOrder = 0
    object Tytul: TTabSheet
      Caption = 'Tytul'
      object m_TitleQR: TQuickRep
        Left = -30
        Top = 0
        Width = 1270
        Height = 1796
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poPortrait
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = True
        SnapToGrid = True
        Units = MM
        Zoom = 160
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand2: TQRBand
          Left = 60
          Top = 60
          Width = 1149
          Height = 39
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = ChildBand2
          Size.Values = (
            64.492187500000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object QRExpr4: TQRExpr
            Left = 233
            Top = 3
            Width = 683
            Height = 33
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              54.570312500000000000
              385.299479166666700000
              4.960937500000000000
              1129.440104166667000000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            Color = clWhite
            OnPrint = QRExpr4Print
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 11
          end
        end
        object QRChildBand5: TQRChildBand
          Left = 60
          Top = 103
          Width = 1149
          Height = 2
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            3.307291666666667000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object ChildBand2: TQRChildBand
          Left = 60
          Top = 99
          Width = 1149
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            6.614583333333333000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand2
          PrintOrder = cboAfterParent
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Sprz'#281't przyj'#281'ty'
      ImageIndex = 1
      object m_SprzPrzyjQR: TQuickRep
        Left = -36
        Top = 5
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        BeforePrint = clearLP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = False
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object m_PageHeaderQB: TQRBand
          Left = 38
          Top = 38
          Width = 1047
          Height = 22
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            58.208333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object m_SprzPrzyjPH: TQRExpr
            Left = 372
            Top = 3
            Width = 302
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              984.250000000000000000
              7.937500000000000000
              799.041666666666700000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_SprzPrzyjPHPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object m_DetailPrzyjQB: TQRBand
          Left = 38
          Top = 159
          Width = 1047
          Height = 18
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = m_DetailPrzyjQBBeforePrint
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            47.625000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object m_PodstawaQRE: TQRExpr
            Left = 112
            Top = 1
            Width = 125
            Height = 16
            Margins.Left = 0
            Margins.Right = 0
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              296.333333333333300000
              2.645833333333333000
              330.729166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PODSTAWA'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object m_NrMagQE: TQRExpr
            Left = 32
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              84.666666666666670000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_NrMagQEPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'WARSZTAT'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape11: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel2: TQRExpr
            Left = 65
            Top = 1
            Width = 50
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              171.979166666666700000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ID_HARM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape12: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape13: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NazSprzPrzyjQRE: TQRExpr
            Left = 230
            Top = 1
            Width = 167
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              608.541666666666700000
              2.645833333333333000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape14: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NrIlQRE: TQRExpr
            Left = 554
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1465.791666666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KOD_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape15: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_JWPrzyjQRE: TQRExpr
            Left = 400
            Top = 1
            Width = 150
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1058.333333333333000000
              2.645833333333333000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_JEDNOSTKI'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape16: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NrFabrQRE: TQRExpr
            Left = 667
            Top = 1
            Width = 58
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1764.770833333333000000
              2.645833333333333000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_FABR'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape17: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel8: TQRExpr
            Left = 728
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1926.166666666667000000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ILOSC'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape18: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_ProtPrzyjQRE: TQRExpr
            Left = 611
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1616.604166666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape19: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel10: TQRExpr
            Left = 761
            Top = 1
            Width = 71
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2013.479166666667000000
              2.645833333333333000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape20: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_UwagiPrzyjQRE: TQRExpr
            Left = 836
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2211.916666666667000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PROP_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRExpr7: TQRExpr
            Left = 2
            Top = 1
            Width = 25
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              5.291666666666667000
              2.645833333333333000
              66.145833333333330000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = getLP
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'LP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape97: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr9: TQRExpr
            Left = 904
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2391.833333333333000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape101: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object PageFooterBand1: TQRBand
          Left = 38
          Top = 181
          Width = 1047
          Height = 26
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            68.791666666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData1: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData2: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object m_TitleChildQB: TQRChildBand
          Left = 38
          Top = 207
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object ChildBand1: TQRChildBand
          Left = 38
          Top = 60
          Width = 1047
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          Enabled = False
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = m_PageHeaderQB
          PrintOrder = cboAfterParent
          object QRLabel1: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape21: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel12: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape22: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel13: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape23: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel14: TQRLabel
            Left = 230
            Top = 10
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              26.458333333333330000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape24: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel15: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape25: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel16: TQRLabel
            Left = 400
            Top = 10
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              26.458333333333330000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape26: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel17: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape27: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel18: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape28: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel19: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape29: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel20: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape30: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel21: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel4: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape37: TQRShape
            Left = 29
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel6: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape98: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object m_Title1BA: TQRBand
          Left = 38
          Top = 100
          Width = 1047
          Height = 23
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_PrzyjHeadQRB
          Size.Values = (
            60.854166666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_SprzPrzyjLB: TQRLabel
            Left = 5
            Top = 2
            Width = 301
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              13.229166666666700000
              6.614583333333330000
              795.403645833334000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't przyj'#281'ty do remontu zgodnie z planem'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_PrzyjHeadQRB: TQRBand
          Left = 38
          Top = 123
          Width = 1047
          Height = 36
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_DetailPrzyjQB
          Size.Values = (
            95.250000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel23: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape1: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel24: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape2: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel25: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape3: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel26: TQRLabel
            Left = 230
            Top = 9
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              23.812500000000000000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape4: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel27: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape5: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel28: TQRLabel
            Left = 400
            Top = 9
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              23.812500000000000000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape6: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel29: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape7: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel30: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape8: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel31: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape9: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel32: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape10: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel33: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel5: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape79: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape99: TQRShape
            Left = 902
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel7: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object SummaryBand1: TQRBand
          Left = 38
          Top = 177
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Sprz'#281't przyj'#281'ty nieplanowy'
      ImageIndex = 6
      object m_SprzPrzyjNplQR: TQuickRep
        Left = 6
        Top = 5
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        BeforePrint = clearLP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = False
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand21: TQRBand
          Left = 38
          Top = 38
          Width = 1047
          Height = 22
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            58.208333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object m_SprzPrzyjNplPH: TQRExpr
            Left = 372
            Top = 3
            Width = 302
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              984.250000000000000000
              7.937500000000000000
              799.041666666666700000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_SprzPrzyjNplPHPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object m_PrzyjNplDetailQRB: TQRBand
          Left = 38
          Top = 159
          Width = 1047
          Height = 18
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = m_DetailPrzyjQBBeforePrint
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            47.625000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object QRExpr14: TQRExpr
            Left = 112
            Top = 1
            Width = 125
            Height = 16
            Margins.Left = 0
            Margins.Right = 0
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              296.333333333333300000
              2.645833333333333000
              330.729166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PODSTAWA'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRExpr15: TQRExpr
            Left = 32
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              84.666666666666670000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_NrMagQEPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'WARSZTAT'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape89: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr17: TQRExpr
            Left = 65
            Top = 1
            Width = 50
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              171.979166666666700000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ID_HARM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape100: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape102: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr18: TQRExpr
            Left = 230
            Top = 1
            Width = 167
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              608.541666666666700000
              2.645833333333333000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape103: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr21: TQRExpr
            Left = 554
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1465.791666666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KOD_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape104: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr23: TQRExpr
            Left = 400
            Top = 1
            Width = 150
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1058.333333333333000000
              2.645833333333333000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_JEDNOSTKI'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape105: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr25: TQRExpr
            Left = 667
            Top = 1
            Width = 58
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1764.770833333333000000
              2.645833333333333000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_FABR'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape106: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr26: TQRExpr
            Left = 728
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1926.166666666667000000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ILOSC'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape107: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr28: TQRExpr
            Left = 611
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1616.604166666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape108: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr31: TQRExpr
            Left = 761
            Top = 1
            Width = 71
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2013.479166666667000000
              2.645833333333333000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape109: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr32: TQRExpr
            Left = 836
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2211.916666666667000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PROP_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRExpr33: TQRExpr
            Left = 2
            Top = 1
            Width = 25
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              5.291666666666667000
              2.645833333333333000
              66.145833333333330000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = getLP
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'LP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape110: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr34: TQRExpr
            Left = 904
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2391.833333333333000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape111: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand23: TQRBand
          Left = 38
          Top = 181
          Width = 1047
          Height = 26
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            68.791666666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData9: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData10: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object QRChildBand9: TQRChildBand
          Left = 38
          Top = 207
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object QRChildBand10: TQRChildBand
          Left = 38
          Top = 60
          Width = 1047
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          Enabled = False
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand21
          PrintOrder = cboAfterParent
          object QRLabel3: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape112: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel9: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape113: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel11: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape114: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel40: TQRLabel
            Left = 230
            Top = 10
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              26.458333333333330000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape115: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel78: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape116: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel87: TQRLabel
            Left = 400
            Top = 10
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              26.458333333333330000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape117: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel88: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape118: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel89: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape119: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel90: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape120: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel91: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape121: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel92: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel93: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape122: TQRShape
            Left = 29
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel94: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape123: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand24: TQRBand
          Left = 38
          Top = 100
          Width = 1047
          Height = 23
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzRemDetailQRB
          Size.Values = (
            60.854166666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_SprzPrzyjNplLB: TQRLabel
            Left = 5
            Top = 2
            Width = 301
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              13.229166666666700000
              6.614583333333330000
              795.403645833334000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't przyj'#281'ty do remontu poza planem'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_PrzyjNplHeadQRB: TQRBand
          Left = 38
          Top = 123
          Width = 1047
          Height = 36
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_PrzyjNplDetailQRB
          Size.Values = (
            95.250000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel96: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape124: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel97: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape125: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel98: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape126: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel99: TQRLabel
            Left = 230
            Top = 9
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              23.812500000000000000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape127: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel100: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape128: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel101: TQRLabel
            Left = 400
            Top = 9
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              23.812500000000000000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape129: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel102: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape130: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel103: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape131: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel104: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape132: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel105: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape133: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel106: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel107: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape134: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape135: TQRShape
            Left = 902
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel108: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand26: TQRBand
          Left = 38
          Top = 177
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'Depozyt'
      ImageIndex = 7
      object m_SprzDepQR: TQuickRep
        Left = 22
        Top = 5
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        BeforePrint = clearLP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = False
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand27: TQRBand
          Left = 38
          Top = 38
          Width = 1047
          Height = 22
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            58.208333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object m_SprzDepHP: TQRExpr
            Left = 372
            Top = 3
            Width = 302
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              984.250000000000000000
              7.937500000000000000
              799.041666666666700000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_SprzDepHPPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object m_SprzDepDetailQRB: TQRBand
          Left = 38
          Top = 159
          Width = 1047
          Height = 18
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = m_DetailPrzyjQBBeforePrint
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_PrzyjNplDetailQRB
          Size.Values = (
            47.625000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object QRExpr36: TQRExpr
            Left = 112
            Top = 1
            Width = 125
            Height = 16
            Margins.Left = 0
            Margins.Right = 0
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              296.333333333333300000
              2.645833333333333000
              330.729166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PODSTAWA'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRExpr37: TQRExpr
            Left = 32
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              84.666666666666670000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_NrMagQEPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'WARSZTAT'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape136: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr38: TQRExpr
            Left = 65
            Top = 1
            Width = 50
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              171.979166666666700000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ID_HARM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape137: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape138: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr39: TQRExpr
            Left = 230
            Top = 1
            Width = 167
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              608.541666666666700000
              2.645833333333333000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape139: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr40: TQRExpr
            Left = 554
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1465.791666666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KOD_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape140: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr41: TQRExpr
            Left = 400
            Top = 1
            Width = 150
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1058.333333333333000000
              2.645833333333333000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_JEDNOSTKI'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape141: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr42: TQRExpr
            Left = 667
            Top = 1
            Width = 58
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1764.770833333333000000
              2.645833333333333000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_FABR'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape142: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr43: TQRExpr
            Left = 728
            Top = 1
            Width = 30
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1926.166666666667000000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ILOSC'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape143: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr44: TQRExpr
            Left = 611
            Top = 1
            Width = 54
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1616.604166666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape144: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr45: TQRExpr
            Left = 761
            Top = 1
            Width = 71
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2013.479166666667000000
              2.645833333333333000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape145: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr46: TQRExpr
            Left = 836
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2211.916666666667000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PROP_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRExpr47: TQRExpr
            Left = 2
            Top = 1
            Width = 25
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              5.291666666666667000
              2.645833333333333000
              66.145833333333330000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = getLP
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'LP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape146: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr48: TQRExpr
            Left = 904
            Top = 1
            Width = 65
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              2391.833333333333000000
              2.645833333333333000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape147: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand29: TQRBand
          Left = 38
          Top = 181
          Width = 1047
          Height = 26
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            68.791666666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData11: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData12: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object QRChildBand11: TQRChildBand
          Left = 38
          Top = 207
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object QRChildBand12: TQRChildBand
          Left = 38
          Top = 60
          Width = 1047
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          Enabled = False
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand27
          PrintOrder = cboAfterParent
          object QRLabel109: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape148: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel110: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape149: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel111: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape150: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel112: TQRLabel
            Left = 230
            Top = 10
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              26.458333333333330000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape151: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel113: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape152: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel114: TQRLabel
            Left = 400
            Top = 10
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              26.458333333333330000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape153: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel115: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape154: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel116: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape155: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel117: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape156: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel118: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape157: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel119: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel120: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape158: TQRShape
            Left = 29
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel121: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape159: TQRShape
            Left = 902
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand30: TQRBand
          Left = 38
          Top = 100
          Width = 1047
          Height = 23
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzDepHeadQRB
          Size.Values = (
            60.854166666666670000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_SprzDepLB: TQRLabel
            Left = 5
            Top = 2
            Width = 301
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              13.229166666666700000
              6.614583333333330000
              795.403645833334000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't przyj'#281'ty do depozytu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_SprzDepHeadQRB: TQRBand
          Left = 38
          Top = 123
          Width = 1047
          Height = 36
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzDepDetailQRB
          Size.Values = (
            95.250000000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel123: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape160: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel124: TQRLabel
            Left = 65
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              171.979166666666700000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape161: TQRShape
            Left = 116
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              306.916666666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel125: TQRLabel
            Left = 117
            Top = 9
            Width = 110
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              309.562500000000000000
              23.812500000000000000
              291.041666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape162: TQRShape
            Left = 228
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              603.250000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel126: TQRLabel
            Left = 230
            Top = 9
            Width = 167
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              608.541666666666700000
              23.812500000000000000
              441.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape163: TQRShape
            Left = 399
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1055.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel127: TQRLabel
            Left = 554
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1465.791666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape164: TQRShape
            Left = 551
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1457.854166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel128: TQRLabel
            Left = 400
            Top = 9
            Width = 150
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1058.333333333333000000
              23.812500000000000000
              396.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape165: TQRShape
            Left = 609
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1611.312500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel129: TQRLabel
            Left = 667
            Top = 2
            Width = 58
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1764.770833333333000000
              5.291666666666667000
              153.458333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Numer fabryczny'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape166: TQRShape
            Left = 726
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1920.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel130: TQRLabel
            Left = 728
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1926.166666666667000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape167: TQRShape
            Left = 759
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2008.187500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel131: TQRLabel
            Left = 611
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1616.604166666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape168: TQRShape
            Left = 665
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1759.479166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel132: TQRLabel
            Left = 761
            Top = 2
            Width = 71
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2013.479166666667000000
              5.291666666666667000
              187.854166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape169: TQRShape
            Left = 834
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2206.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel133: TQRLabel
            Left = 836
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2211.916666666667000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRLabel134: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape170: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape171: TQRShape
            Left = 902
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2386.541666666667000000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel135: TQRLabel
            Left = 904
            Top = 2
            Width = 65
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2391.833333333333000000
              5.291666666666667000
              171.979166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zako'#324'czenia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_SprzDepChildQRB: TQRBand
          Left = 38
          Top = 177
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Sprz'#281't wyremontowany'
      ImageIndex = 3
      object m_SprzRemQR: TQuickRep
        Left = 3
        Top = 3
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        BeforePrint = clearLP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          70.000000000000000000
          70.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = False
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand8: TQRBand
          Left = 26
          Top = 38
          Width = 1070
          Height = 22
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            58.208333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object m_SprzRemQRPH: TQRExpr
            Left = 384
            Top = 3
            Width = 302
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1016.000000000000000000
              7.937500000000000000
              799.041666666666700000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_SprzRemQRPHPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object m_SprzRemDetailQRB: TQRBand
          Left = 26
          Top = 159
          Width = 1070
          Height = 16
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = m_SprzRemDetailQRBBeforePrint
          Color = clWhite
          TransparentBand = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -8
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzRemChildQRB
          ParentFont = False
          Size.Values = (
            42.333333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object m_PodstRemQRE: TQRExpr
            Left = 97
            Top = 1
            Width = 95
            Height = 14
            Margins.Left = 0
            Margins.Right = 0
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              256.645833333333300000
              2.645833333333333000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(PODSTAWA)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr6: TQRExpr
            Left = 32
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              84.666666666666670000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_NrMagQEPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'WARSZTAT'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape38: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr12: TQRExpr
            Left = 65
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              171.979166666666700000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ID_HARM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape42: TQRShape
            Left = 95
            Top = -1
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              251.354166666666700000
              -2.645833333333333000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape43: TQRShape
            Left = 246
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              650.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NazSprzRemQRE: TQRExpr
            Left = 247
            Top = 1
            Width = 116
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              653.520833333333300000
              2.645833333333333000
              306.916666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(NAZ_SPRZ)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape47: TQRShape
            Left = 364
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              963.083333333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr19: TQRExpr
            Left = 492
            Top = 1
            Width = 54
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1301.750000000000000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KOD_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape52: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_JWRemQRE: TQRExpr
            Left = 365
            Top = 1
            Width = 127
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              965.729166666666700000
              2.645833333333333000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(NAZ_JEDNOSTKI)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape53: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NrFabrRemQRE: TQRExpr
            Left = 604
            Top = 1
            Width = 40
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1598.083333333333000000
              2.645833333333333000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_FABR'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape62: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr49: TQRExpr
            Left = 648
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1714.500000000000000000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ILOSC'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape63: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_ProtPrzyjRemQRE: TQRExpr
            Left = 548
            Top = 1
            Width = 54
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1449.916666666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape64: TQRShape
            Left = 602
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1592.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr51: TQRExpr
            Left = 681
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1801.812500000000000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape65: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr52: TQRExpr
            Left = 735
            Top = 1
            Width = 48
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1944.687500000000000000
              2.645833333333333000
              127.000000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PROP_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr53: TQRExpr
            Left = 2
            Top = 1
            Width = 25
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              5.291666666666667000
              2.645833333333333000
              66.145833333333330000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = getLP
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'LP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape67: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr54: TQRExpr
            Left = 787
            Top = 1
            Width = 48
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2082.270833333333000000
              2.645833333333333000
              127.000000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape68: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape192: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr55: TQRExpr
            Left = 194
            Top = 1
            Width = 51
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              513.291666666666700000
              2.645833333333333000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'SYGN_MAG'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr2: TQRExpr
            Left = 839
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2219.854166666667000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'L_POWIAD'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape195: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr5: TQRExpr
            Left = 892
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2360.083333333333000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_POWIAD'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape196: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr16: TQRExpr
            Left = 946
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2502.958333333333000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZEKAZ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape197: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand10: TQRBand
          Left = 26
          Top = 179
          Width = 1070
          Height = 27
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            71.437500000000000000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData5: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData6: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object QRChildBand4: TQRChildBand
          Left = 26
          Top = 60
          Width = 1070
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          Enabled = False
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand8
          PrintOrder = cboAfterParent
          object QRLabel22: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape72: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel41: TQRLabel
            Left = 65
            Top = 2
            Width = 30
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              171.979166666666700000
              5.291666666666667000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape73: TQRShape
            Left = 95
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              251.354166666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel47: TQRLabel
            Left = 97
            Top = 9
            Width = 95
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              256.645833333333300000
              23.812500000000000000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape74: TQRShape
            Left = 246
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              650.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel48: TQRLabel
            Left = 247
            Top = 9
            Width = 115
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              653.520833333333300000
              23.812500000000000000
              304.270833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape75: TQRShape
            Left = 363
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              960.437500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel52: TQRLabel
            Left = 492
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1301.750000000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape77: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel53: TQRLabel
            Left = 364
            Top = 10
            Width = 127
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              963.083333333333300000
              26.458333333333330000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape78: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel58: TQRLabel
            Left = 605
            Top = 9
            Width = 40
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1600.729166666667000000
              23.812500000000000000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr fabr.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape172: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel59: TQRLabel
            Left = 648
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1714.500000000000000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape173: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel60: TQRLabel
            Left = 549
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1452.562500000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape174: TQRShape
            Left = 603
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1595.437500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel64: TQRLabel
            Left = 681
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1801.812500000000000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape175: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel65: TQRLabel
            Left = 734
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1942.041666666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel66: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape176: TQRShape
            Left = 29
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel67: TQRLabel
            Left = 787
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              2082.270833333333000000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape177: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape190: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel145: TQRLabel
            Left = 194
            Top = 2
            Width = 51
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              513.291666666666700000
              5.291666666666667000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sygn. mag.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel147: TQRLabel
            Left = 839
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2219.854166666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Liczba wyst. pow.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape193: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel148: TQRLabel
            Left = 892
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2360.083333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data ost. powiad.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape198: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel151: TQRLabel
            Left = 946
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2502.958333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data przekaz.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape201: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand11: TQRBand
          Left = 26
          Top = 100
          Width = 1070
          Height = 23
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzRemHeadQRB
          Size.Values = (
            60.854166666666670000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_SprzRemQRLB: TQRLabel
            Left = 4
            Top = 2
            Width = 301
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              10.583333333333330000
              5.291666666666667000
              796.395833333333300000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't wyremontowany'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_SprzRemHeadQRB: TQRBand
          Left = 26
          Top = 123
          Width = 1070
          Height = 36
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzRemDetailQRB
          Size.Values = (
            95.250000000000000000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel70: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape178: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel71: TQRLabel
            Left = 65
            Top = 2
            Width = 30
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              171.979166666666700000
              5.291666666666667000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape179: TQRShape
            Left = 95
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              251.354166666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel95: TQRLabel
            Left = 97
            Top = 9
            Width = 95
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              256.645833333333300000
              23.812500000000000000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape180: TQRShape
            Left = 247
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              653.520833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel122: TQRLabel
            Left = 248
            Top = 9
            Width = 115
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              656.166666666666700000
              23.812500000000000000
              304.270833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape181: TQRShape
            Left = 364
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              963.083333333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel136: TQRLabel
            Left = 492
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1301.750000000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape182: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel137: TQRLabel
            Left = 365
            Top = 9
            Width = 127
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              965.729166666666700000
              23.812500000000000000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape183: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel138: TQRLabel
            Left = 604
            Top = 9
            Width = 40
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1598.083333333333000000
              23.812500000000000000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr fabr.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape184: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel139: TQRLabel
            Left = 648
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1714.500000000000000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape185: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel140: TQRLabel
            Left = 548
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1449.916666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape186: TQRShape
            Left = 602
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1592.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel141: TQRLabel
            Left = 681
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1801.812500000000000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape187: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel142: TQRLabel
            Left = 734
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1942.041666666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel143: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape188: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape189: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel144: TQRLabel
            Left = 787
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              2082.270833333333000000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape191: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel146: TQRLabel
            Left = 194
            Top = 2
            Width = 51
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              513.291666666666700000
              5.291666666666667000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sygn. mag.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel68: TQRLabel
            Left = 839
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2219.854166666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Liczba wyst. pow.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape194: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel149: TQRLabel
            Left = 892
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2360.083333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data ost. powiad.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape199: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel150: TQRLabel
            Left = 946
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2502.958333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data przekaz.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape200: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object m_SprzRemChildQRB: TQRBand
          Left = 26
          Top = 175
          Width = 1070
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
        object ChildBand5: TQRChildBand
          Left = 26
          Top = 206
          Width = 1070
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand10
          PrintOrder = cboAfterParent
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Sprz'#281't wydany'
      ImageIndex = 2
      object m_SprzPrzekQR: TQuickRep
        Left = 3
        Top = 3
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        BeforePrint = clearLP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          70.000000000000000000
          70.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = False
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand1: TQRBand
          Left = 26
          Top = 38
          Width = 1070
          Height = 22
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            58.208333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object m_SprzPrzekPHLB: TQRExpr
            Left = 384
            Top = 3
            Width = 302
            Height = 16
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.333333333333330000
              1016.000000000000000000
              7.937500000000000000
              799.041666666666700000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_SprzPrzekPHLBPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object m_SprzPrzekDetailQRB: TQRBand
          Left = 26
          Top = 159
          Width = 1070
          Height = 16
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = m_SprzRemDetailQRBBeforePrint
          Color = clWhite
          TransparentBand = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -8
          Font.Name = 'Arial Narrow'
          Font.Style = []
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzPrzekChildQRB
          ParentFont = False
          Size.Values = (
            42.333333333333330000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object QRExpr3: TQRExpr
            Left = 97
            Top = 1
            Width = 95
            Height = 14
            Margins.Left = 0
            Margins.Right = 0
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              256.645833333333300000
              2.645833333333333000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(PODSTAWA)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr8: TQRExpr
            Left = 32
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              84.666666666666670000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = m_NrMagQEPrint
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'WARSZTAT'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape31: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr13: TQRExpr
            Left = 65
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              171.979166666666700000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ID_HARM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape34: TQRShape
            Left = 95
            Top = -1
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              251.354166666666700000
              -2.645833333333333000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape35: TQRShape
            Left = 246
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              650.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr22: TQRExpr
            Left = 247
            Top = 1
            Width = 116
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              653.520833333333300000
              2.645833333333333000
              306.916666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(NAZ_SPRZ)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape36: TQRShape
            Left = 364
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              963.083333333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr35: TQRExpr
            Left = 492
            Top = 1
            Width = 54
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1301.750000000000000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KOD_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape39: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr50: TQRExpr
            Left = 365
            Top = 1
            Width = 127
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              965.729166666666700000
              2.645833333333333000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UPPER(NAZ_JEDNOSTKI)'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape40: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr56: TQRExpr
            Left = 604
            Top = 1
            Width = 40
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1598.083333333333000000
              2.645833333333333000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_FABR'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape41: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr57: TQRExpr
            Left = 648
            Top = 1
            Width = 30
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1714.500000000000000000
              2.645833333333333000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'ILOSC'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape44: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr58: TQRExpr
            Left = 548
            Top = 1
            Width = 54
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1449.916666666667000000
              2.645833333333333000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape45: TQRShape
            Left = 602
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              1592.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr59: TQRExpr
            Left = 681
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1801.812500000000000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape46: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr60: TQRExpr
            Left = 735
            Top = 1
            Width = 48
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              1944.687500000000000000
              2.645833333333333000
              127.000000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PROP_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr61: TQRExpr
            Left = 2
            Top = 1
            Width = 25
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              5.291666666666667000
              2.645833333333333000
              66.145833333333330000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            OnPrint = getLP
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = False
            Expression = 'LP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape49: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr62: TQRExpr
            Left = 787
            Top = 1
            Width = 48
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2082.270833333333000000
              2.645833333333333000
              127.000000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_ZAK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape50: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape51: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 10
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              26.458333333333330000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr63: TQRExpr
            Left = 194
            Top = 1
            Width = 51
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              513.291666666666700000
              2.645833333333333000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'SYGN_MAG'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRExpr64: TQRExpr
            Left = 839
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2219.854166666667000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'L_POWIAD'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape54: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr65: TQRExpr
            Left = 892
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2360.083333333333000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_POWIAD'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape55: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr66: TQRExpr
            Left = 946
            Top = 1
            Width = 50
            Height = 14
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              37.041666666666670000
              2502.958333333333000000
              2.645833333333333000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -8
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZEKAZ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 6
          end
          object QRShape56: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 25
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333330000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand4: TQRBand
          Left = 26
          Top = 180
          Width = 1070
          Height = 26
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            68.791666666666670000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData3: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData4: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object QRChildBand2: TQRChildBand
          Left = 26
          Top = 60
          Width = 1070
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          Enabled = False
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand1
          PrintOrder = cboAfterParent
          object QRLabel34: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape59: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel37: TQRLabel
            Left = 65
            Top = 2
            Width = 30
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              171.979166666666700000
              5.291666666666667000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape60: TQRShape
            Left = 95
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              251.354166666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel38: TQRLabel
            Left = 97
            Top = 9
            Width = 95
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              256.645833333333300000
              23.812500000000000000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape202: TQRShape
            Left = 246
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              650.875000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel39: TQRLabel
            Left = 247
            Top = 9
            Width = 115
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              653.520833333333300000
              23.812500000000000000
              304.270833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape203: TQRShape
            Left = 363
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              960.437500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel42: TQRLabel
            Left = 492
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1301.750000000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape204: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel43: TQRLabel
            Left = 364
            Top = 10
            Width = 127
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              963.083333333333300000
              26.458333333333330000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape205: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel44: TQRLabel
            Left = 605
            Top = 9
            Width = 40
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1600.729166666667000000
              23.812500000000000000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr fabr.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape206: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel45: TQRLabel
            Left = 648
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1714.500000000000000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape207: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel46: TQRLabel
            Left = 549
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1452.562500000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape208: TQRShape
            Left = 603
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1595.437500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel49: TQRLabel
            Left = 681
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1801.812500000000000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape209: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel50: TQRLabel
            Left = 734
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1942.041666666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel51: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape210: TQRShape
            Left = 29
            Top = 2
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              5.291666666666667000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel54: TQRLabel
            Left = 787
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              2082.270833333333000000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape211: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape212: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel55: TQRLabel
            Left = 194
            Top = 2
            Width = 51
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              513.291666666666700000
              5.291666666666667000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sygn. mag.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel56: TQRLabel
            Left = 839
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2219.854166666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Liczba wyst. pow.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape213: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel152: TQRLabel
            Left = 892
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2360.083333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data ost. powiad.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape214: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel153: TQRLabel
            Left = 946
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2502.958333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data przekaz.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape215: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object QRBand5: TQRBand
          Left = 26
          Top = 100
          Width = 1070
          Height = 23
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzPrzekHeadQRB
          Size.Values = (
            60.854166666666670000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_SprzPrzekLB: TQRLabel
            Left = 4
            Top = 2
            Width = 301
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              10.583333333333330000
              5.291666666666667000
              796.395833333333300000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't przekazany po remoncie'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_SprzPrzekHeadQRB: TQRBand
          Left = 26
          Top = 123
          Width = 1070
          Height = 36
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          LinkBand = m_SprzPrzekDetailQRB
          Size.Values = (
            95.250000000000000000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel155: TQRLabel
            Left = 32
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              84.666666666666670000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape216: TQRShape
            Left = 63
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              166.687500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel156: TQRLabel
            Left = 65
            Top = 2
            Width = 30
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              171.979166666666700000
              5.291666666666667000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape217: TQRShape
            Left = 95
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              251.354166666666700000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel157: TQRLabel
            Left = 97
            Top = 9
            Width = 95
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              256.645833333333300000
              23.812500000000000000
              251.354166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Podstawa'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape218: TQRShape
            Left = 247
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              653.520833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel158: TQRLabel
            Left = 248
            Top = 9
            Width = 115
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              656.166666666666700000
              23.812500000000000000
              304.270833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Typ sprz'#281'tu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape219: TQRShape
            Left = 364
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              963.083333333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel159: TQRLabel
            Left = 492
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1301.750000000000000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Kod remontu'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape220: TQRShape
            Left = 492
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1301.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel160: TQRLabel
            Left = 365
            Top = 9
            Width = 127
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              965.729166666666700000
              23.812500000000000000
              336.020833333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Dostawca'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape221: TQRShape
            Left = 546
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1444.625000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel161: TQRLabel
            Left = 604
            Top = 9
            Width = 40
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1598.083333333333000000
              23.812500000000000000
              105.833333333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr fabr.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape222: TQRShape
            Left = 646
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1709.208333333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel162: TQRLabel
            Left = 648
            Top = 9
            Width = 30
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              1714.500000000000000000
              23.812500000000000000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape223: TQRShape
            Left = 679
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1796.520833333333000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel163: TQRLabel
            Left = 548
            Top = 2
            Width = 54
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1449.916666666667000000
              5.291666666666667000
              142.875000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Protok'#243#322' przyj.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape224: TQRShape
            Left = 602
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1592.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel164: TQRLabel
            Left = 681
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1801.812500000000000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj'#281'cia'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape225: TQRShape
            Left = 732
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              1936.750000000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel165: TQRLabel
            Left = 734
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              1942.041666666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Prop. data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel166: TQRLabel
            Left = 2
            Top = 9
            Width = 26
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              5.291666666666667000
              23.812500000000000000
              68.791666666666670000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'L.p.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape226: TQRShape
            Left = 29
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              76.729166666666670000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRShape227: TQRShape
            Left = 785
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2076.979166666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel167: TQRLabel
            Left = 787
            Top = 9
            Width = 50
            Height = 18
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.625000000000000000
              2082.270833333333000000
              23.812500000000000000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data zak.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape228: TQRShape
            Left = 193
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              510.645833333333300000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel168: TQRLabel
            Left = 194
            Top = 2
            Width = 51
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              513.291666666666700000
              5.291666666666667000
              134.937500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sygn. mag.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRLabel169: TQRLabel
            Left = 839
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2219.854166666667000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Liczba wyst. pow.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape229: TQRShape
            Left = 837
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2214.562500000000000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel170: TQRLabel
            Left = 892
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2360.083333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data ost. powiad.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape230: TQRShape
            Left = 890
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2354.791666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel171: TQRLabel
            Left = 946
            Top = 2
            Width = 50
            Height = 32
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.666666666666670000
              2502.958333333333000000
              5.291666666666667000
              132.291666666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Caption = 'Data przekaz.'
            Color = clWhite
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = [fsBold]
            ParentFont = False
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
          object QRShape231: TQRShape
            Left = 944
            Top = 0
            Width = 1
            Height = 39
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              103.187500000000000000
              2497.666666666667000000
              0.000000000000000000
              2.645833333333333000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
        end
        object m_SprzPrzekChildQRB: TQRBand
          Left = 26
          Top = 175
          Width = 1070
          Height = 5
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            13.229166666666670000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
        object QRChildBand1: TQRChildBand
          Left = 26
          Top = 206
          Width = 1070
          Height = 2
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            5.291666666666667000
            2831.041666666667000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand4
          PrintOrder = cboAfterParent
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Sprz'#281't w depozycie'
      ImageIndex = 4
      object m_SprzDep1QR: TQuickRep
        Left = -6
        Top = 5
        Width = 1270
        Height = 1796
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poPortrait
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = True
        SnapToGrid = True
        Units = MM
        Zoom = 160
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand14: TQRBand
          Left = 60
          Top = 60
          Width = 1149
          Height = 26
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            42.994791666666670000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageHeader
          object QRExpr10: TQRExpr
            Left = 333
            Top = 3
            Width = 483
            Height = 33
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              54.570312500000000000
              550.664062500000000000
              4.960937500000000000
              798.710937500000000000)
            Alignment = taCenter
            AlignToBand = True
            AutoSize = True
            AutoStretch = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Arial Narrow'
            Font.Style = []
            Color = clWhite
            ParentFont = False
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 
              #39'Meldunek tygodniowy kierownika Dzialu/Sekcji za okres 19-24.07.' +
              '2010'#39
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 8
          end
        end
        object QRBand15: TQRBand
          Left = 60
          Top = 245
          Width = 1149
          Height = 37
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          BeforePrint = QRBand15BeforePrint
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            61.184895833333330000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbDetail
          object QRExpr11: TQRExpr
            Left = 8
            Top = 4
            Width = 38
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              13.229166666666700000
              6.614583333333330000
              62.838541666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_MAG_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape32: TQRShape
            Left = 51
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              84.335937500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr20: TQRExpr
            Left = 56
            Top = 4
            Width = 60
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              92.604166666666700000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_HARM_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape33: TQRShape
            Left = 121
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              200.091145833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NazSprzDepQRE: TQRExpr
            Left = 127
            Top = 2
            Width = 200
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666670000
              210.013020833333300000
              3.307291666666667000
              330.729166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape48: TQRShape
            Left = 333
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              550.664062500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr24: TQRExpr
            Left = 338
            Top = 4
            Width = 60
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              558.932291666667000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_ILOSC_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape57: TQRShape
            Left = 403
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              666.419270833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_JWDepQRE: TQRExpr
            Left = 408
            Top = 4
            Width = 281
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              674.687500000000000000
              6.614583333333330000
              464.674479166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'JW_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape58: TQRShape
            Left = 695
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              1149.283854166670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_ProtStTechDepQRE: TQRExpr
            Left = 699
            Top = 4
            Width = 60
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1155.898437500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_ST_TECH_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape61: TQRShape
            Left = 764
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              1263.385416666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr27: TQRExpr
            Left = 770
            Top = 4
            Width = 48
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1273.307291666670000000
              6.614583333333330000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'RODZ_REM_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape66: TQRShape
            Left = 822
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              1359.296875000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_ProtDepQRE: TQRExpr
            Left = 827
            Top = 4
            Width = 60
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1367.565104166670000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape69: TQRShape
            Left = 892
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              1475.052083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr29: TQRExpr
            Left = 897
            Top = 4
            Width = 60
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1483.320312500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape70: TQRShape
            Left = 962
            Top = 0
            Width = 1
            Height = 40
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              66.145833333333300000
              1590.807291666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr30: TQRExpr
            Left = 966
            Top = 4
            Width = 177
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1597.421875000000000000
              6.614583333333330000
              292.695312500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UWAGI_DEP'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand16: TQRBand
          Left = 60
          Top = 289
          Width = 1149
          Height = 32
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            52.916666666666670000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData7: TQRSysData
            Left = 8
            Top = 4
            Width = 91
            Height = 26
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.994791666666670000
              13.229166666666670000
              6.614583333333333000
              150.481770833333300000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = False
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData8: TQRSysData
            Left = 1073
            Top = 4
            Width = 66
            Height = 26
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              42.994791666666670000
              1774.361979166667000000
              6.614583333333333000
              109.140625000000000000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = False
            ExportAs = exptText
            FontSize = 10
          end
        end
        object QRChildBand7: TQRChildBand
          Left = 60
          Top = 86
          Width = 1149
          Height = 64
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand14
          PrintOrder = cboAfterParent
          object QRLabel35: TQRLabel
            Left = 8
            Top = 4
            Width = 38
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              13.229166666666700000
              6.614583333333330000
              62.838541666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr dep.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape71: TQRShape
            Left = 51
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              84.335937500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel36: TQRLabel
            Left = 56
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              92.604166666666700000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape76: TQRShape
            Left = 121
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              200.091145833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel57: TQRLabel
            Left = 125
            Top = 15
            Width = 200
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              206.705729166667000000
              24.804687500000000000
              330.729166666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nazwa sprz'#281'tu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape80: TQRShape
            Left = 333
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              550.664062500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel61: TQRLabel
            Left = 338
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              558.932291666667000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr/ ilosc'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape81: TQRShape
            Left = 403
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              666.419270833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel62: TQRLabel
            Left = 408
            Top = 15
            Width = 281
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              674.687500000000000000
              24.804687500000000000
              464.674479166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr J.W. Miejscowo'#347#263
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape82: TQRShape
            Left = 695
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1149.283854166670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel63: TQRLabel
            Left = 699
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1155.898437500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr pr. st. tech.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape83: TQRShape
            Left = 764
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1263.385416666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel69: TQRLabel
            Left = 770
            Top = 4
            Width = 48
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1273.307291666670000000
              6.614583333333330000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Rodz. rem.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape84: TQRShape
            Left = 822
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1359.296875000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel72: TQRLabel
            Left = 827
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1367.565104166670000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr pr. przyj.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape85: TQRShape
            Left = 892
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1475.052083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel73: TQRLabel
            Left = 897
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1483.320312500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape86: TQRShape
            Left = 962
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1590.807291666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel74: TQRLabel
            Left = 966
            Top = 4
            Width = 177
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1597.421875000000000000
              6.614583333333330000
              292.695312500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi i przyczyny przyj'#281'cia do depozytu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand17: TQRBand
          Left = 60
          Top = 150
          Width = 1149
          Height = 37
          Frame.Color = clBlack
          Frame.DrawTop = False
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            61.184895833333330000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object QRLabel75: TQRLabel
            Left = 8
            Top = 4
            Width = 481
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              13.229166666666700000
              6.614583333333330000
              795.403645833334000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Sprz'#281't przyj'#281'ty do depozytu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand18: TQRBand
          Left = 60
          Top = 187
          Width = 1149
          Height = 58
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            95.911458333333330000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbColumnHeader
          object QRLabel76: TQRLabel
            Left = 8
            Top = 4
            Width = 38
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              13.229166666666700000
              6.614583333333330000
              62.838541666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr dep.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape87: TQRShape
            Left = 51
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              84.335937500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel77: TQRLabel
            Left = 56
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              92.604166666666700000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr harm.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape88: TQRShape
            Left = 121
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              200.091145833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel79: TQRLabel
            Left = 125
            Top = 15
            Width = 200
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              206.705729166667000000
              24.804687500000000000
              330.729166666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nazwa sprz'#281'tu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape90: TQRShape
            Left = 333
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              550.664062500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel80: TQRLabel
            Left = 338
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              558.932291666667000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr/ ilosc'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape91: TQRShape
            Left = 403
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              666.419270833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel81: TQRLabel
            Left = 408
            Top = 15
            Width = 281
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              674.687500000000000000
              24.804687500000000000
              464.674479166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr J.W. Miejscowo'#347#263
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape92: TQRShape
            Left = 695
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1149.283854166670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel82: TQRLabel
            Left = 699
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1155.898437500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr pr. st. tech.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape93: TQRShape
            Left = 764
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1263.385416666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel83: TQRLabel
            Left = 770
            Top = 4
            Width = 48
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1273.307291666670000000
              6.614583333333330000
              79.375000000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Rodz. rem.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape94: TQRShape
            Left = 822
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1359.296875000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel84: TQRLabel
            Left = 827
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1367.565104166670000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr pr. przyj.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape95: TQRShape
            Left = 892
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1475.052083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel85: TQRLabel
            Left = 897
            Top = 4
            Width = 60
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1483.320312500000000000
              6.614583333333330000
              99.218750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przyj.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape96: TQRShape
            Left = 962
            Top = 0
            Width = 1
            Height = 63
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              104.179687500000000000
              1590.807291666670000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel86: TQRLabel
            Left = 966
            Top = 4
            Width = 177
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1597.421875000000000000
              6.614583333333330000
              292.695312500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi i przyczyny przyj'#281'cia do depozytu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand19: TQRBand
          Left = 60
          Top = 282
          Width = 1149
          Height = 7
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            11.575520833333330000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbSummary
        end
        object ChildBand6: TQRChildBand
          Left = 60
          Top = 321
          Width = 1149
          Height = 3
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            4.960937500000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand16
          PrintOrder = cboAfterParent
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Podsumowanie'
      ImageIndex = 5
      object m_PodsumQR: TQuickRep
        Left = -2
        Top = 3
        Width = 1123
        Height = 794
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial Narrow'
        Font.Style = []
        Functions.Strings = (
          'PAGENUMBER'
          'COLUMNNUMBER'
          'REPORTTITLE')
        Functions.DATA = (
          '0'
          '0'
          #39#39)
        Options = [FirstPageHeader, LastPageFooter]
        Page.Columns = 1
        Page.Orientation = poLandscape
        Page.PaperSize = A4
        Page.Continuous = False
        Page.Values = (
          100.000000000000000000
          2100.000000000000000000
          100.000000000000000000
          2970.000000000000000000
          100.000000000000000000
          100.000000000000000000
          0.000000000000000000)
        PrinterSettings.Copies = 1
        PrinterSettings.OutputBin = Auto
        PrinterSettings.Duplex = True
        PrinterSettings.FirstPage = 0
        PrinterSettings.LastPage = 0
        PrinterSettings.UseStandardprinter = False
        PrinterSettings.UseCustomBinCode = False
        PrinterSettings.CustomBinCode = 0
        PrinterSettings.ExtendedDuplex = 0
        PrinterSettings.UseCustomPaperCode = False
        PrinterSettings.CustomPaperCode = 0
        PrinterSettings.PrintMetaFile = False
        PrinterSettings.PrintQuality = 0
        PrinterSettings.Collate = 0
        PrinterSettings.ColorOption = 0
        PrintIfEmpty = True
        SnapToGrid = True
        Units = MM
        Zoom = 100
        PrevFormStyle = fsNormal
        PreviewInitialState = wsNormal
        PrevInitialZoom = qrZoomToWidth
        PreviewDefaultSaveType = stQRP
        PreviewLeft = 0
        PreviewTop = 0
        object QRBand20: TQRBand
          Left = 38
          Top = 38
          Width = 1047
          Height = 251
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            664.104166666666700000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_UwagiWnioskiQRM: TQRMemo
            Left = 5
            Top = 5
            Width = 701
            Height = 158
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              418.041666666666700000
              13.229166666666670000
              13.229166666666670000
              1854.729166666667000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Color = clWhite
            Lines.Strings = (
              'PROPOZYCJE I WNIOSKI'
              
                '................................................................' +
                '................................................................' +
                '................................................................' +
                '..............'
              ''
              
                '................................................................' +
                '................................................................' +
                '................................................................' +
                '..............'
              ''
              
                '................................................................' +
                '................................................................' +
                '................................................................' +
                '..............'
              ''
              
                '................................................................' +
                '................................................................' +
                '................................................................' +
                '..............'
              ''
              
                '................................................................' +
                '................................................................' +
                '................................................................' +
                '..............'
              '')
            Transparent = False
            WordWrap = True
            FullJustify = False
            MaxBreakChars = 0
            FontSize = 10
          end
          object QRMemo1: TQRMemo
            Left = 712
            Top = 176
            Width = 251
            Height = 56
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              148.166666666666700000
              1883.833333333333000000
              465.666666666666700000
              664.104166666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = False
            Color = clWhite
            Lines.Strings = (
              'PODPIS KIEROWNIKA'
              ''
              
                '................................................................' +
                '......')
            Transparent = False
            WordWrap = True
            FullJustify = False
            MaxBreakChars = 0
            FontSize = 10
          end
        end
        object ChildBand3: TQRChildBand
          Left = 38
          Top = 289
          Width = 1047
          Height = 40
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            105.833333333333300000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand20
          PrintOrder = cboAfterParent
        end
        object QRBand9: TQRBand
          Left = 38
          Top = 329
          Width = 1047
          Height = 27
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = True
          Frame.DrawLeft = True
          Frame.DrawRight = True
          AlignToBottom = False
          Color = clSilver
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            71.437500000000000000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbPageFooter
          object QRSysData13: TQRSysData
            Left = 5
            Top = 5
            Width = 57
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              13.229166666666670000
              13.229166666666670000
              150.812500000000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsDateTime
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
          object QRSysData14: TQRSysData
            Left = 921
            Top = 4
            Width = 41
            Height = 17
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              44.979166666666670000
              2436.812500000000000000
              10.583333333333330000
              108.479166666666700000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = True
            Color = clWhite
            Data = qrsPageNumber
            Transparent = True
            ExportAs = exptText
            FontSize = 10
          end
        end
        object ChildBand4: TQRChildBand
          Left = 38
          Top = 356
          Width = 1047
          Height = 4
          Frame.Color = clBlack
          Frame.DrawTop = True
          Frame.DrawBottom = False
          Frame.DrawLeft = False
          Frame.DrawRight = False
          AlignToBottom = False
          Color = clWhite
          TransparentBand = False
          ForceNewColumn = False
          ForceNewPage = False
          Size.Values = (
            10.583333333333330000
            2770.187500000000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          ParentBand = QRBand9
          PrintOrder = cboAfterParent
        end
      end
    end
  end
  object m_CompQR: TQRCompositeReport
    OnAddReports = m_CompQRAddReports
    Options = []
    PrinterSettings.Copies = 1
    PrinterSettings.OutputBin = Auto
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.UseStandardprinter = False
    PrinterSettings.UseCustomBinCode = False
    PrinterSettings.CustomBinCode = 0
    PrinterSettings.ExtendedDuplex = 0
    PrinterSettings.UseCustomPaperCode = False
    PrinterSettings.CustomPaperCode = 0
    PrinterSettings.PrintMetaFile = False
    PrinterSettings.PrintQuality = 0
    PrinterSettings.Collate = 0
    PrinterSettings.ColorOption = 0
    PrinterSettings.Orientation = poLandscape
    PrinterSettings.PaperSize = Letter
    PageCount = 0
    Left = 208
    Top = 376
  end
end
