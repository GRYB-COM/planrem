object MeldTygQRP: TMeldTygQRP
  Left = 24
  Top = 145
  Caption = 'MeldTygQRP'
  ClientHeight = 613
  ClientWidth = 1248
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
    Width = 1248
    Height = 613
    ActivePage = TabSheet4
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
          Top = 99
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
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Sprz'#281't przyj'#281'ty'
      ImageIndex = 1
      object m_SprzPrzyjQR: TQuickRep
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
        object m_PageHeaderQB: TQRBand
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
          object QRExpr2: TQRExpr
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
        object m_DetailPrzyjQB: TQRBand
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
          BeforePrint = m_DetailPrzyjQBBeforePrint
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
          object m_NrMagQE: TQRExpr
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
            Expression = 'NR_MAG_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape11: TQRShape
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
          object QRLabel2: TQRExpr
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
            Expression = 'NR_HARM_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape12: TQRShape
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
          object QRLabel3: TQRExpr
            Left = 129
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
              213.320312500000000000
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
            Expression = 'WARSZTAT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape13: TQRShape
            Left = 172
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
              284.427083333333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NazSprzPrzyjQRE: TQRExpr
            Left = 176
            Top = 4
            Width = 152
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              291.041666666667000000
              6.614583333333330000
              251.354166666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape14: TQRShape
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
          object QRLabel5: TQRExpr
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
            Expression = 'NR_ILOSC_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape15: TQRShape
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
          object m_JWPrzyjQRE: TQRExpr
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
            Expression = 'JW_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape16: TQRShape
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
          object m_ProtStTechPrzyjQRE: TQRExpr
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
            Expression = 'PROT_ST_TECH_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape17: TQRShape
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
          object QRLabel8: TQRExpr
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
            Expression = 'RODZ_REM_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape18: TQRShape
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
          object m_ProtPrzyjQRE: TQRExpr
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
            Expression = 'PROT_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape19: TQRShape
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
          object QRLabel10: TQRExpr
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
            Expression = 'DATA_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape20: TQRShape
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
          object QRLabel11: TQRExpr
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
            Expression = 'UWAGI_PRZYJ'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object PageFooterBand1: TQRBand
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
          object QRSysData1: TQRSysData
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
          object QRSysData2: TQRSysData
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
        object m_TitleChildQB: TQRChildBand
          Left = 60
          Top = 321
          Width = 1149
          Height = 6
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
            9.921875000000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object ChildBand1: TQRChildBand
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
          ParentBand = m_PageHeaderQB
          PrintOrder = cboAfterParent
          object QRLabel1: TQRLabel
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
            Caption = 'Nr mag.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape21: TQRShape
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
          object QRLabel12: TQRLabel
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
          object QRShape22: TQRShape
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
          object QRLabel13: TQRLabel
            Left = 129
            Top = 15
            Width = 38
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              213.320312500000000000
              24.804687500000000000
              62.838541666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape23: TQRShape
            Left = 172
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
              284.427083333333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel14: TQRLabel
            Left = 176
            Top = 15
            Width = 152
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              291.041666666667000000
              24.804687500000000000
              251.354166666667000000)
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
          object QRShape24: TQRShape
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
          object QRLabel15: TQRLabel
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
          object QRShape25: TQRShape
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
          object QRLabel16: TQRLabel
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
          object QRShape26: TQRShape
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
          object QRLabel17: TQRLabel
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
          object QRShape27: TQRShape
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
          object QRLabel18: TQRLabel
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
          object QRShape28: TQRShape
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
          object QRLabel19: TQRLabel
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
          object QRShape29: TQRShape
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
          object QRLabel20: TQRLabel
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
          object QRShape30: TQRShape
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
          object QRLabel21: TQRLabel
            Left = 966
            Top = 15
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
              24.804687500000000000
              292.695312500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi dot. Nr KUT'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object m_Title1BA: TQRBand
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
          object QRLabel22: TQRLabel
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
            Caption = 'Sprz'#281't przyj'#281'ty do remontu'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object ColumnHeaderBand1: TQRBand
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
          object QRLabel23: TQRLabel
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
            Caption = 'Nr mag.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape1: TQRShape
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
          object QRLabel24: TQRLabel
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
          object QRShape2: TQRShape
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
          object QRLabel25: TQRLabel
            Left = 129
            Top = 15
            Width = 38
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              213.320312500000000000
              24.804687500000000000
              62.838541666666700000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'W-t'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape3: TQRShape
            Left = 172
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
              284.427083333333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel26: TQRLabel
            Left = 176
            Top = 15
            Width = 152
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              291.041666666667000000
              24.804687500000000000
              251.354166666667000000)
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
          object QRShape4: TQRShape
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
          object QRLabel27: TQRLabel
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
          object QRShape5: TQRShape
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
          object QRLabel28: TQRLabel
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
          object QRShape6: TQRShape
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
          object QRLabel29: TQRLabel
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
          object QRShape7: TQRShape
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
          object QRLabel30: TQRLabel
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
          object QRShape8: TQRShape
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
          object QRLabel31: TQRLabel
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
          object QRShape9: TQRShape
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
          object QRLabel32: TQRLabel
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
          object QRShape10: TQRShape
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
          object QRLabel33: TQRLabel
            Left = 966
            Top = 15
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
              24.804687500000000000
              292.695312500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi dot. Nr KUT'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object SummaryBand1: TQRBand
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
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Sprz'#281't wydany'
      ImageIndex = 2
      object m_SprzPrzekQR: TQuickRep
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
        object QRBand1: TQRBand
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
          object QRExpr1: TQRExpr
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
        object QRBand3: TQRBand
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
          BeforePrint = QRBand3BeforePrint
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
          object QRExpr3: TQRExpr
            Left = 8
            Top = 4
            Width = 45
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
              74.414062500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NR_MAG_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape31: TQRShape
            Left = 60
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
              99.218750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_NazSprzPrzekQRE: TQRExpr
            Left = 69
            Top = 6
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666670000
              114.101562500000000000
              9.921875000000000000
              363.802083333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape34: TQRShape
            Left = 295
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
              487.825520833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr8: TQRExpr
            Left = 305
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
              504.361979166667000000
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
            Expression = 'NR_ILOSC_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape35: TQRShape
            Left = 375
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
              620.117187500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_JWPrzekQRE: TQRExpr
            Left = 385
            Top = 4
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              636.653645833333000000
              6.614583333333330000
              496.093750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'JW_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape36: TQRShape
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
          object m_ProtPrzekQRE: TQRExpr
            Left = 705
            Top = 4
            Width = 120
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1165.820312500000000000
              6.614583333333330000
              198.437500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'PROT_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape39: TQRShape
            Left = 835
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
              1380.794270833330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr13: TQRExpr
            Left = 845
            Top = 4
            Width = 95
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1397.330729166670000000
              6.614583333333330000
              157.096354166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape40: TQRShape
            Left = 945
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
              1562.695312500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr14: TQRExpr
            Left = 950
            Top = 4
            Width = 195
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1570.963541666670000000
              6.614583333333330000
              322.460937500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UWAGI_PRZEK'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand4: TQRBand
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
          object QRSysData3: TQRSysData
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
          object QRSysData4: TQRSysData
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
        object QRChildBand1: TQRChildBand
          Left = 60
          Top = 321
          Width = 1149
          Height = 6
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
            9.921875000000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object QRChildBand2: TQRChildBand
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
          ParentBand = QRBand1
          PrintOrder = cboAfterParent
          object QRLabel34: TQRLabel
            Left = 8
            Top = 4
            Width = 45
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
              74.414062500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr mag.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape41: TQRShape
            Left = 60
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
              99.218750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel37: TQRLabel
            Left = 68
            Top = 15
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              112.447916666667000000
              24.804687500000000000
              363.802083333333000000)
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
          object QRShape44: TQRShape
            Left = 295
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
              487.825520833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel38: TQRLabel
            Left = 305
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
              504.361979166667000000
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
          object QRShape45: TQRShape
            Left = 375
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
              620.117187500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel39: TQRLabel
            Left = 385
            Top = 15
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              636.653645833333000000
              24.804687500000000000
              496.093750000000000000)
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
          object QRShape46: TQRShape
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
          object QRLabel42: TQRLabel
            Left = 705
            Top = 4
            Width = 120
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1165.820312500000000000
              6.614583333333330000
              198.437500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr protoko'#322'u przekazania '
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape49: TQRShape
            Left = 835
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
              1380.794270833330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel43: TQRLabel
            Left = 845
            Top = 4
            Width = 95
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1397.330729166670000000
              6.614583333333330000
              157.096354166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przekazania'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape50: TQRShape
            Left = 945
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
              1562.695312500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel44: TQRLabel
            Left = 950
            Top = 15
            Width = 195
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1570.963541666670000000
              24.804687500000000000
              322.460937500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand5: TQRBand
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
          object QRLabel45: TQRLabel
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
            Caption = 'Sprz'#281't przekazany po remoncie'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand6: TQRBand
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
          object QRLabel46: TQRLabel
            Left = 8
            Top = 4
            Width = 45
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
              74.414062500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr mag.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape51: TQRShape
            Left = 60
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
              99.218750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel49: TQRLabel
            Left = 68
            Top = 15
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              112.447916666667000000
              24.804687500000000000
              363.802083333333000000)
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
          object QRShape54: TQRShape
            Left = 295
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
              487.825520833333000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel50: TQRLabel
            Left = 305
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
              504.361979166667000000
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
          object QRShape55: TQRShape
            Left = 375
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
              620.117187500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel51: TQRLabel
            Left = 385
            Top = 15
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              636.653645833333000000
              24.804687500000000000
              496.093750000000000000)
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
          object QRShape56: TQRShape
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
          object QRLabel54: TQRLabel
            Left = 705
            Top = 4
            Width = 120
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1165.820312500000000000
              6.614583333333330000
              198.437500000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr protoko'#322'u przekazania '
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape59: TQRShape
            Left = 835
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
              1380.794270833330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel55: TQRLabel
            Left = 845
            Top = 4
            Width = 95
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1397.330729166670000000
              6.614583333333330000
              157.096354166667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data przekazania'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape60: TQRShape
            Left = 945
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
              1562.695312500000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel56: TQRLabel
            Left = 950
            Top = 15
            Width = 195
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1570.963541666670000000
              24.804687500000000000
              322.460937500000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Uwagi'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand7: TQRBand
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
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Sprz'#281't wyremontowany'
      ImageIndex = 3
      object m_SprzRemQR: TQuickRep
        Left = 2
        Top = -3
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
        object QRBand8: TQRBand
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
          object QRExpr5: TQRExpr
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
        object QRBand9: TQRBand
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
          BeforePrint = QRBand9BeforePrint
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
          object m_NazSprzRemQRE: TQRExpr
            Left = 4
            Top = 2
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666670000
              6.614583333333333000
              3.307291666666667000
              363.802083333333300000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'NAZ_SPRZ_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape38: TQRShape
            Left = 230
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
              380.338541666667000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr16: TQRExpr
            Left = 235
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
              388.606770833333000000
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
            Expression = 'NR_ILOSC_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape42: TQRShape
            Left = 300
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
              496.093750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_JWRemQRE: TQRExpr
            Left = 305
            Top = 4
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              504.361979166667000000
              6.614583333333330000
              496.093750000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'JW_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape43: TQRShape
            Left = 610
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
              1008.723958333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object m_KutRemQRE: TQRExpr
            Left = 615
            Top = 4
            Width = 80
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1016.992187500000000000
              6.614583333333330000
              132.291666666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'KUT_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape47: TQRShape
            Left = 700
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
              1157.552083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr19: TQRExpr
            Left = 705
            Top = 4
            Width = 70
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1165.820312500000000000
              6.614583333333330000
              115.755208333333000000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'RBH_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape53: TQRShape
            Left = 880
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
              1455.208333333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr22: TQRExpr
            Left = 885
            Top = 4
            Width = 250
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1463.476562500000000000
              6.614583333333330000
              413.411458333333000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'UWAGI_REM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape52: TQRShape
            Left = 780
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
              1289.843750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRExpr6: TQRExpr
            Left = 785
            Top = 4
            Width = 90
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1298.111979166670000000
              6.614583333333330000
              148.828125000000000000)
            Alignment = taRightJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Color = clWhite
            ResetAfterPrint = False
            Transparent = True
            WordWrap = True
            Expression = 'DATA_KONTR_ROM'
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand10: TQRBand
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
          object QRSysData5: TQRSysData
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
          object QRSysData6: TQRSysData
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
        object QRChildBand3: TQRChildBand
          Left = 60
          Top = 321
          Width = 1149
          Height = 6
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
            9.921875000000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
        end
        object QRChildBand4: TQRChildBand
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
          ParentBand = QRBand8
          PrintOrder = cboAfterParent
          object QRLabel41: TQRLabel
            Left = 5
            Top = 15
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              8.268229166666670000
              24.804687500000000000
              363.802083333333000000)
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
          object QRShape62: TQRShape
            Left = 230
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
              380.338541666667000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel47: TQRLabel
            Left = 235
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
              388.606770833333000000
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
          object QRShape63: TQRShape
            Left = 300
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
              496.093750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel48: TQRLabel
            Left = 305
            Top = 15
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              504.361979166667000000
              24.804687500000000000
              496.093750000000000000)
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
          object QRShape64: TQRShape
            Left = 610
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
              1008.723958333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel52: TQRLabel
            Left = 615
            Top = 15
            Width = 80
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1016.992187500000000000
              24.804687500000000000
              132.291666666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr KUT'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape65: TQRShape
            Left = 700
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
              1157.552083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel53: TQRLabel
            Left = 705
            Top = 15
            Width = 70
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1165.820312500000000000
              24.804687500000000000
              115.755208333333000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263' rbh'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape67: TQRShape
            Left = 780
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
              1289.843750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel58: TQRLabel
            Left = 785
            Top = 4
            Width = 90
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1298.111979166670000000
              6.614583333333330000
              148.828125000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data kontr. tech.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape68: TQRShape
            Left = 880
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
              1455.208333333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel59: TQRLabel
            Left = 885
            Top = 4
            Width = 250
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1463.476562500000000000
              6.614583333333330000
              413.411458333333000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Czy powiadomienie (je'#380'eli NIE uzasadnienie)'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand11: TQRBand
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
          object QRLabel60: TQRLabel
            Left = 8
            Top = 4
            Width = 849
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
              1403.945312500000000000)
            Alignment = taLeftJustify
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 
              'Sprz'#281't (partia sprz'#281'tu)  wyremontowany w 100% i przygotowany do ' +
              'przekazania '
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand12: TQRBand
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
          object QRLabel64: TQRLabel
            Left = 5
            Top = 15
            Width = 220
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              8.268229166666670000
              24.804687500000000000
              363.802083333333000000)
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
          object QRShape72: TQRShape
            Left = 230
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
              380.338541666667000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel65: TQRLabel
            Left = 235
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
              388.606770833333000000
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
          object QRShape73: TQRShape
            Left = 300
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
              496.093750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel66: TQRLabel
            Left = 305
            Top = 15
            Width = 300
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              504.361979166667000000
              24.804687500000000000
              496.093750000000000000)
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
          object QRShape74: TQRShape
            Left = 610
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
              1008.723958333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel67: TQRLabel
            Left = 615
            Top = 15
            Width = 80
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1016.992187500000000000
              24.804687500000000000
              132.291666666667000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Nr KUT'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape75: TQRShape
            Left = 700
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
              1157.552083333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel68: TQRLabel
            Left = 705
            Top = 15
            Width = 70
            Height = 29
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              47.955729166666700000
              1165.820312500000000000
              24.804687500000000000
              115.755208333333000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Ilo'#347#263' rbh'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape77: TQRShape
            Left = 780
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
              1289.843750000000000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel70: TQRLabel
            Left = 785
            Top = 4
            Width = 90
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1298.111979166670000000
              6.614583333333330000
              148.828125000000000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Data kontr. tech.'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
          object QRShape78: TQRShape
            Left = 880
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
              1455.208333333330000000
              0.000000000000000000
              1.653645833333330000)
            Shape = qrsVertLine
            VertAdjust = 0
          end
          object QRLabel71: TQRLabel
            Left = 885
            Top = 4
            Width = 250
            Height = 51
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              84.335937500000000000
              1463.476562500000000000
              6.614583333333330000
              413.411458333333000000)
            Alignment = taCenter
            AlignToBand = False
            AutoSize = False
            AutoStretch = True
            Caption = 'Czy powiadomienie (je'#380'eli NIE uzasadnienie)'
            Color = clWhite
            Transparent = True
            WordWrap = True
            ExportAs = exptText
            WrapStyle = BreakOnSpaces
            FontSize = 10
          end
        end
        object QRBand13: TQRBand
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
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Sprz'#281't w depozycie'
      ImageIndex = 4
      object m_SprzDepQR: TQuickRep
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
        object QRChildBand6: TQRChildBand
          Left = 60
          Top = 321
          Width = 1149
          Height = 6
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
            9.921875000000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          PrintOrder = cboAfterParent
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
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Podsumowanie'
      ImageIndex = 5
      object m_PodsumQR: TQuickRep
        Left = 2
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
        object QRBand20: TQRBand
          Left = 60
          Top = 60
          Width = 1149
          Height = 213
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
            352.226562500000000000
            1900.039062500000000000)
          PreCaluculateBandHeight = False
          KeepOnOnePage = False
          BandType = rbTitle
          object m_UwagiWnioskiQRM: TQRMemo
            Left = 8
            Top = 8
            Width = 1121
            Height = 98
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              162.057291666667000000
              13.229166666666700000
              13.229166666666700000
              1853.736979166670000000)
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
              '')
            Transparent = False
            WordWrap = True
            FullJustify = False
            MaxBreakChars = 0
            FontSize = 10
          end
          object QRMemo1: TQRMemo
            Left = 656
            Top = 120
            Width = 401
            Height = 89
            Frame.Color = clBlack
            Frame.DrawTop = False
            Frame.DrawBottom = False
            Frame.DrawLeft = False
            Frame.DrawRight = False
            Size.Values = (
              147.174479166667000000
              1084.791666666670000000
              198.437500000000000000
              663.111979166667000000)
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
        object QRChildBand8: TQRChildBand
          Left = 60
          Top = 273
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
    PrinterSettings.Orientation = poPortrait
    PrinterSettings.PaperSize = Letter
    PageCount = 0
    Left = 208
    Top = 376
  end
end
