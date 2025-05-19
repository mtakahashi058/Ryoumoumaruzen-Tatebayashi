object SeikyushoTateForm: TSeikyushoTateForm
  Left = 1727
  Top = 72
  Width = 845
  Height = 1021
  Caption = 'SeikyushoTateForm'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 12
  object QuickRep: TQuickRep
    Left = 4
    Top = 4
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    BeforePrint = QuickRepBeforePrint
    DataSet = DM.Q_Seikyu
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#26126#26397
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
    Page.Values = (
      100
      2970
      140
      2100
      80
      60
      0)
    PrinterSettings.Copies = 1
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.OutputBin = Auto
    PrintIfEmpty = True
    ReportTitle = #35531#27714#26360
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object QRShapeLine12: TQRShape
      Left = 30
      Top = 342
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        904.875
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine01: TQRShape
      Left = 30
      Top = 122
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        322.791666666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine02: TQRShape
      Left = 30
      Top = 142
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        375.708333333333
        1963.20833333333)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShapeLine03: TQRShape
      Left = 30
      Top = 162
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        428.625
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine04: TQRShape
      Left = 30
      Top = 182
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        481.541666666667
        1963.20833333333)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShapeLine05: TQRShape
      Left = 30
      Top = 202
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        534.458333333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine06: TQRShape
      Left = 30
      Top = 222
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        587.375
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine07: TQRShape
      Left = 30
      Top = 242
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        640.291666666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine08: TQRShape
      Left = 30
      Top = 262
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        693.208333333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine09: TQRShape
      Left = 30
      Top = 282
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        746.125
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine10: TQRShape
      Left = 30
      Top = 302
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        799.041666666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeLine11: TQRShape
      Left = 30
      Top = 322
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        851.958333333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShapeWaku: TQRShape
      Left = 30
      Top = 339
      Width = 742
      Height = 746
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1973.79166666667
        79.375
        896.9375
        1963.20833333333)
      Brush.Style = bsClear
      Pen.Width = 2
      Shape = qrsRectangle
    end
    object PageHeaderBand: TQRBand
      Left = 30
      Top = 53
      Width = 741
      Height = 25
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = PageHeaderBandBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        66.1458333333333
        1960.5625)
      BandType = rbPageHeader
      object ColorShape: TQRShape
        Left = 388
        Top = 0
        Width = 189
        Height = 24
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          63.5
          1026.58333333333
          0
          500.0625)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object QRDBText2: TQRDBText
        Left = 103
        Top = 320
        Width = 50
        Height = 13
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          272.520833333333
          846.666666666667
          132.291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataField = #35531#27714#20808#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel2: TQRLabel
        Left = 8
        Top = 320
        Width = 91
        Height = 13
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          846.666666666667
          240.770833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12362#23458#27096#12467#12540#12489'No.'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object PageNumberLabel: TQRLabel
        Left = 722
        Top = 13
        Width = 19
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1910.29166666667
          34.3958333333333
          50.2708333333333)
        Alignment = taRightJustify
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '1'#38913
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object DateLabel: TQRLabel
        Left = 656
        Top = 0
        Width = 85
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1735.66666666667
          0
          224.895833333333)
        Alignment = taRightJustify
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '2008'#24180'01'#26376'31'#26085
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object TitleLabel: TQRLabel
        Left = 397
        Top = 2
        Width = 170
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          1050.39583333333
          5.29166666666667
          449.791666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35531#12288#27714#12288#26360#12288'('#25511')'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 14
      end
      object QRLabel4: TQRLabel
        Left = 606
        Top = 0
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1603.375
          0
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #30330#34892#26085#65306
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object QRShape22: TQRShape
      Left = 30
      Top = 362
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        957.791666666667
        1963.20833333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape23: TQRShape
      Left = 30
      Top = 382
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1010.70833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape24: TQRShape
      Left = 30
      Top = 402
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1063.625
        1963.20833333333)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape25: TQRShape
      Left = 30
      Top = 422
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1116.54166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape26: TQRShape
      Left = 30
      Top = 442
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1169.45833333333
        1963.20833333333)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape27: TQRShape
      Left = 30
      Top = 462
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1222.375
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape28: TQRShape
      Left = 30
      Top = 482
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1275.29166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape29: TQRShape
      Left = 30
      Top = 502
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1328.20833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape30: TQRShape
      Left = 30
      Top = 522
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1381.125
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape31: TQRShape
      Left = 30
      Top = 542
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1434.04166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape32: TQRShape
      Left = 30
      Top = 562
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1486.95833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape33: TQRShape
      Left = 30
      Top = 582
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1539.875
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape34: TQRShape
      Left = 30
      Top = 602
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1592.79166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape35: TQRShape
      Left = 30
      Top = 622
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1645.70833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape36: TQRShape
      Left = 30
      Top = 642
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1698.625
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape37: TQRShape
      Left = 30
      Top = 662
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1751.54166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape38: TQRShape
      Left = 30
      Top = 682
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1804.45833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 30
      Top = 702
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1857.375
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape39: TQRShape
      Left = 30
      Top = 722
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1910.29166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRImage2: TQRImage
      Left = 19
      Top = 421
      Width = 4
      Height = 4
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        10.5833333333333
        50.2708333333333
        1113.89583333333
        10.5833333333333)
      Picture.Data = {
        07544269746D6170C6050000424DC60500000000000036040000280000001400
        000014000000010008000000000090010000120B0000120B0000000100000000
        000000000000FFFFFF0080808000404040002020200099999900000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000030201010101010101010101010101010101010103000405010101010101
        0101010101010101010103000000040501010101010101010101010101010300
        0000000004050101010101010101010101010300000000000000040501010101
        0101010101010300000000000000000004050101010101010101030000000000
        0000000000000405010101010101030000000000000000000000000004050101
        0101030000000000000000000000000000000405010103000000000000000000
        0000000000000000040503000000000000000000000000000000000004050300
        0000000000000000000000000000040501010300000000000000000000000000
        0405010101010300000000000000000000000405010101010101030000000000
        0000000004050101010101010101030000000000000004050101010101010101
        0101030000000000040501010101010101010101010103000000040501010101
        0101010101010101010103000405010101010101010101010101010101010302
        010101010101010101010101010101010101}
      Stretch = True
    end
    object QRImage1: TQRImage
      Left = 1074
      Top = 451
      Width = 4
      Height = 4
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        10.5833333333333
        2841.625
        1193.27083333333
        10.5833333333333)
      Picture.Data = {
        07544269746D6170C6050000424DC60500000000000036040000280000001400
        000014000000010008000000000090010000120B0000120B0000000100000000
        000000000000FFFFFF0080808000404040002020200099999900000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000010101010101010101010101010101010101020301010101010101010101
        0101010101010504000301010101010101010101010101010504000000030101
        0101010101010101010105040000000000030101010101010101010105040000
        0000000000030101010101010101050400000000000000000003010101010101
        0504000000000000000000000003010101010504000000000000000000000000
        0003010105040000000000000000000000000000000305040000000000000000
        0000000000000000000305040000000000000000000000000000000000030101
        0504000000000000000000000000000000030101010105040000000000000000
        0000000000030101010101010504000000000000000000000003010101010101
        0101050400000000000000000003010101010101010101010504000000000000
        0003010101010101010101010101050400000000000301010101010101010101
        0101010105040000000301010101010101010101010101010101050400030101
        010101010101010101010101010101010203}
      Stretch = True
    end
    object Message3Label: TQRLabel
      Left = 30
      Top = 1087
      Width = 463
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        2876.02083333333
        1225.02083333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #21462#24341#37504#34892'  *  '#9675#9675#37504#34892#9675#9675#25903#24215' '#26222#36890' 123456  *  '#9675#9675#37504#34892#9675#9675#25903#24215' '#26222#36890' 123456  *'
      Color = clWhite
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #65325#65331' '#26126#26397
      Font.Style = []
      ParentFont = False
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object GroupHeaderSeikyu: TQRGroup
      Left = 30
      Top = 363
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeaderSeikyuBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      Expression = 'Q_Seikyu.'#35531#27714#20808#12467#12540#12489
      FooterBand = GroupFooterSeikyu
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel10: TQRLabel
        Left = 696
        Top = 4
        Width = 43
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          113.770833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Seikyu'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupHeader1: TQRGroup
      Left = 30
      Top = 383
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeader1BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      Expression = 'Q_Seikyu.G1'
      FooterBand = GroupFooter1
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel11: TQRLabel
        Left = 696
        Top = 4
        Width = 15
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'G1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupHeader2: TQRGroup
      Left = 30
      Top = 403
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeader2BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      FooterBand = GroupFooter2
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel12: TQRLabel
        Left = 696
        Top = 4
        Width = 15
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'G2'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand1: TQRBand
      Left = 30
      Top = 483
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = DetailBand1BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbDetail
      object DateDBText: TQRDBText
        Left = 3
        Top = 3
        Width = 36
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          7.9375
          7.9375
          95.25)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #31777#26131#21462#24341#26085
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextSuryo: TQRDBText
        Left = 267
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          706.4375
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #25968#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextTani: TQRDBText
        Left = 371
        Top = 3
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          981.604166666667
          7.9375
          129.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #21336#20301#12510#12473#12479#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextTanka: TQRDBText
        Left = 426
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1127.125
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #21336#20385
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextKingaku: TQRDBText
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #37329#38989
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextHinName: TQRDBText
        Left = 52
        Top = 3
        Width = 211
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          137.583333333333
          7.9375
          558.270833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #21697#30446#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBTextBiko: TQRDBText
        Left = 628
        Top = 3
        Width = 113
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1661.58333333333
          7.9375
          298.979166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #20633#32771
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel9: TQRLabel
        Left = 696
        Top = 4
        Width = 43
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          113.770833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'Detail'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupFooter1: TQRBand
      Left = 30
      Top = 583
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooter1BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbGroupFooter
      object QRShape19: TQRShape
        Left = 0
        Top = 0
        Width = 741
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Frame.Style = psClear
        Size.Values = (
          52.9166666666667
          0
          0
          1960.5625)
        Brush.Color = 13158600
        Pen.Style = psClear
        Shape = qrsRectangle
      end
      object ShokeiLabel1: TQRLabel
        Left = 46
        Top = 3
        Width = 406
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          121.708333333333
          7.9375
          1074.20833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #9632' 12345678901234567890123456789012345678901234567890'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold, fsItalic]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRExpr5: TQRExpr
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        Color = clWhite
        ParentFont = False
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Q_Seikyu.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel8: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#23567#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
    end
    object GroupFooterSeikyu: TQRBand
      Left = 30
      Top = 603
      Width = 741
      Height = 61
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooterSeikyuBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        161.395833333333
        1960.5625)
      BandType = rbGroupFooter
      object ColorShape4: TQRShape
        Left = 424
        Top = 38
        Width = 201
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          1121.83333333333
          100.541666666667
          531.8125)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object QRLabel1: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#21512#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel27: TQRLabel
        Left = 454
        Top = 23
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          60.8541666666667
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#28040#36027#31246' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel37: TQRLabel
        Left = 454
        Top = 43
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          113.770833333333
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#32207#21512#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object ShohizeiLabel: TQRLabel
        Left = 525
        Top = 23
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          60.8541666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '#,###,###,##0'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TotalLabel: TQRLabel
        Left = 525
        Top = 43
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          113.770833333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '#,###,###,##0'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object UriageGokeiLabel: TQRLabel
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '#,###,###,##0'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRShape1: TQRShape
      Left = 30
      Top = 742
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1963.20833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape2: TQRShape
      Left = 30
      Top = 762
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2016.125
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape10: TQRShape
      Left = 30
      Top = 782
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2069.04166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape40: TQRShape
      Left = 30
      Top = 802
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2121.95833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape41: TQRShape
      Left = 30
      Top = 822
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2174.875
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape42: TQRShape
      Left = 30
      Top = 842
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2227.79166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape43: TQRShape
      Left = 30
      Top = 862
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2280.70833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape44: TQRShape
      Left = 30
      Top = 882
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2333.625
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape45: TQRShape
      Left = 30
      Top = 902
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2386.54166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape46: TQRShape
      Left = 30
      Top = 922
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2439.45833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape47: TQRShape
      Left = 30
      Top = 942
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2492.375
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape48: TQRShape
      Left = 30
      Top = 962
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2545.29166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape49: TQRShape
      Left = 30
      Top = 982
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2598.20833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape50: TQRShape
      Left = 30
      Top = 1002
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2651.125
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape51: TQRShape
      Left = 30
      Top = 1022
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2704.04166666667
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape52: TQRShape
      Left = 30
      Top = 1042
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2756.95833333333
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape53: TQRShape
      Left = 30
      Top = 1062
      Width = 742
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        2809.875
        1963.20833333333)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object GroupHeader3: TQRGroup
      Left = 30
      Top = 423
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeader3BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      FooterBand = GroupFooter3
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel13: TQRLabel
        Left = 696
        Top = 4
        Width = 15
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'G3'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupHeader4: TQRGroup
      Left = 30
      Top = 443
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeader4BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      FooterBand = GroupFooter4
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel14: TQRLabel
        Left = 696
        Top = 4
        Width = 15
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'G4'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupHeader5: TQRGroup
      Left = 30
      Top = 463
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeader5BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      FooterBand = GroupFooter5
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel15: TQRLabel
        Left = 696
        Top = 4
        Width = 15
        Height = 14
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1841.5
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'G5'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object GroupFooter2: TQRBand
      Left = 30
      Top = 563
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooter2BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbGroupFooter
      object QRShape54: TQRShape
        Left = 0
        Top = 0
        Width = 741
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Frame.Style = psClear
        Size.Values = (
          52.9166666666667
          0
          0
          1960.5625)
        Brush.Color = 15132390
        Pen.Style = psClear
        Shape = qrsRectangle
      end
      object ShokeiLabel2: TQRLabel
        Left = 46
        Top = 3
        Width = 365
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          121.708333333333
          7.9375
          965.729166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '[12345678901234567890123456789012345678901234567890]'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRExpr4: TQRExpr
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Q_Seikyu.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel7: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#23567#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
    end
    object GroupFooter3: TQRBand
      Left = 30
      Top = 543
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooter3BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbGroupFooter
      object ShokeiLabel3: TQRLabel
        Left = 46
        Top = 3
        Width = 365
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          121.708333333333
          7.9375
          965.729166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '[12345678901234567890123456789012345678901234567890]'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr3: TQRExpr
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Q_Seikyu.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel6: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#23567#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object GroupFooter4: TQRBand
      Left = 30
      Top = 523
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooter4BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbGroupFooter
      object ShokeiLabel4: TQRLabel
        Left = 46
        Top = 3
        Width = 365
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          121.708333333333
          7.9375
          965.729166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '[12345678901234567890123456789012345678901234567890]'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr2: TQRExpr
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Q_Seikyu.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel5: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#23567#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object GroupFooter5: TQRBand
      Left = 30
      Top = 503
      Width = 741
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooter5BeforePrint
      Color = clWhite
      Enabled = False
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        1960.5625)
      BandType = rbGroupFooter
      object ShokeiLabel5: TQRLabel
        Left = 46
        Top = 3
        Width = 365
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          121.708333333333
          7.9375
          965.729166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '[12345678901234567890123456789012345678901234567890]'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr1: TQRExpr
        Left = 525
        Top = 3
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1389.0625
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Q_Seikyu.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel3: TQRLabel
        Left = 454
        Top = 3
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1201.20833333333
          7.9375
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '* '#23567#12288#35336' *'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object QRShapeTate01: TQRShape
      Left = 74
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        195.791666666667
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShapeTate03: TQRShape
      Left = 395
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        1045.10416666667
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShapeTate04: TQRShape
      Left = 454
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        1201.20833333333
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShapeTate05: TQRShape
      Left = 553
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        1463.14583333333
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShapeTate06: TQRShape
      Left = 653
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        1727.72916666667
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShapeTate02: TQRShape
      Left = 295
      Top = 340
      Width = 2
      Height = 745
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1971.14583333333
        780.520833333333
        899.583333333333
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRChildBand1: TQRChildBand
      Left = 30
      Top = 78
      Width = 741
      Height = 285
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        754.0625
        1960.5625)
      ParentBand = PageHeaderBand
      object QRShape3: TQRShape
        Left = 0
        Top = 193
        Width = 601
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          0
          510.645833333333
          1590.14583333333)
        Brush.Style = bsClear
        Pen.Width = 2
        Shape = qrsRectangle
      end
      object QRShape12: TQRShape
        Left = 614
        Top = 193
        Width = 127
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1624.54166666667
          510.645833333333
          336.020833333333)
        Pen.Width = 2
        Shape = qrsRectangle
      end
      object ColorShape1: TQRShape
        Left = 0
        Top = 193
        Width = 601
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          0
          510.645833333333
          1590.14583333333)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object YubinDBLabel: TQRDBText
        Left = 84
        Top = 4
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          222.25
          10.5833333333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #37109#20415#30058#21495
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object YubinTLabel: TQRLabel
        Left = 64
        Top = 4
        Width = 15
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          10.5833333333333
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12306
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel6: TQRLabel
        Left = 501
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1325.5625
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel1: TQRLabel
        Left = 1
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2.64583333333333
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel2: TQRLabel
        Left = 101
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          267.229166666667
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel3: TQRLabel
        Left = 201
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          531.8125
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel4: TQRLabel
        Left = 301
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          796.395833333333
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel5: TQRLabel
        Left = 401
        Top = 220
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1060.97916666667
          582.083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ShameiLabel: TQRLabel
        Left = 436
        Top = 19
        Width = 278
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          1153.58333333333
          50.2708333333333
          735.541666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #26666' '#24335' '#20250' '#31038' '#26085' '#26412' '#35069' '#34913' '#25152
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object SeikyumotoLabel02: TQRLabel
        Left = 436
        Top = 61
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          161.395833333333
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#22524#29577#30476#20816#29577#37089#32654#37324#30010#23567#33538#30000#65301#65302#65296
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object KagamiLabel06: TQRLabel
        Left = 502
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1328.20833333333
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#28040#36027#31246#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KagamiLabel01: TQRLabel
        Left = 2
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          5.29166666666667
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21069#22238#35531#27714#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KagamiLabel02: TQRLabel
        Left = 102
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          269.875
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#20837#37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KagamiLabel03: TQRLabel
        Left = 202
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          534.458333333333
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#35519#25972#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KagamiLabel04: TQRLabel
        Left = 302
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          799.041666666667
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#32368#36234#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KagamiLabel05: TQRLabel
        Left = 402
        Top = 198
        Width = 97
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1063.625
          523.875
          256.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#22770#19978#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape6: TQRShape
        Left = 199
        Top = 193
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          526.520833333333
          510.645833333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape7: TQRShape
        Left = 299
        Top = 193
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          791.104166666667
          510.645833333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape8: TQRShape
        Left = 399
        Top = 193
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1055.6875
          510.645833333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape9: TQRShape
        Left = 499
        Top = 193
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1320.27083333333
          510.645833333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRLabel22: TQRLabel
        Left = 282
        Top = 87
        Width = 68
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          746.125
          230.1875
          179.916666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12362#23458#27096#12467#12540#12489#65306
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#65328#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 8
      end
      object QRDBText1: TQRDBText
        Left = 350
        Top = 87
        Width = 31
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          926.041666666667
          230.1875
          82.0208333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #35531#27714#20808#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 8
      end
      object Message1Label: TQRLabel
        Left = 4
        Top = 175
        Width = 743
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          463.020833333333
          1965.85416666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #19978#27573#12513#12483#12475#12540#12472#12288#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ColorShape2: TQRShape
        Left = 614
        Top = 193
        Width = 127
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          1624.54166666667
          510.645833333333
          336.020833333333)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object KagamiLabel07: TQRLabel
        Left = 617
        Top = 198
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1632.47916666667
          523.875
          322.791666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#35531#27714#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel7: TQRLabel
        Left = 622
        Top = 220
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          1645.70833333333
          582.083333333333
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 11
      end
      object SeikyumotoLabel03: TQRLabel
        Left = 436
        Top = 77
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          203.729166666667
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288'TEL'#12288#65296#65300#65305#65301#65293#65303#65302#65293#65297#65298#65299#65297'('#20195')'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel04: TQRLabel
        Left = 436
        Top = 93
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          246.0625
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288'FAX'#12288#65296#65300#65305#65301#65293#65303#65302#65293#65298#65298#65296#65305
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel05: TQRLabel
        Left = 436
        Top = 110
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          291.041666666667
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #22823#23470#21942#26989#25152#12288#12306#65299#65299#65296#65293#65296#65304#65301#65302
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel06: TQRLabel
        Left = 436
        Top = 126
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          333.375
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#22524#29577#30476#12373#12356#12383#12414#24066#22823#23470#21306#19977#27211'3'#65293'248'#65293'1'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel07: TQRLabel
        Left = 436
        Top = 142
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          375.708333333333
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288'TEL'#12288#65296#65300#65304#65293#65302#65298#65296#65293#65303#65301#65296#65296'('#20195')'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel08: TQRLabel
        Left = 436
        Top = 159
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          420.6875
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288'FAX'#12288#65296#65300#65304#65293#65302#65298#65296#65293#65303#65301#65298#65296
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object SeikyumotoLabel01: TQRLabel
        Left = 436
        Top = 45
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1153.58333333333
          119.0625
          804.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26412#31038#12539#24037#22580#12288#12306#65299#65302#65303#65293#65296#65297#65296#65297
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object ColorShape3: TQRShape
        Left = 0
        Top = 261
        Width = 742
        Height = 25
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          66.1458333333333
          0
          690.5625
          1963.20833333333)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object MeiTitleLabel01: TQRLabel
        Left = 4
        Top = 267
        Width = 36
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          706.4375
          95.25)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26085#20184
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel02: TQRLabel
        Left = 50
        Top = 267
        Width = 211
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          132.291666666667
          706.4375
          558.270833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21697#21517
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel03: TQRLabel
        Left = 270
        Top = 267
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          714.375
          706.4375
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel04: TQRLabel
        Left = 371
        Top = 267
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          981.604166666667
          706.4375
          129.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20301
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel05: TQRLabel
        Left = 428
        Top = 267
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1132.41666666667
          706.4375
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20385
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel06: TQRLabel
        Left = 528
        Top = 267
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1397
          706.4375
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel07: TQRLabel
        Left = 628
        Top = 267
        Width = 109
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1661.58333333333
          706.4375
          288.395833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20633#32771
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object Message2Label: TQRLabel
        Left = 4
        Top = 244
        Width = 743
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          645.583333333333
          1965.85416666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20013#27573#12513#12483#12475#12540#12472#12288#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293#65293
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SeikyusakiLabel: TQRLabel
        Left = 64
        Top = 66
        Width = 338
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          174.625
          894.291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #35531#27714#20808#21517#31216
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape5: TQRShape
        Left = 99
        Top = 193
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          261.9375
          510.645833333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object Add1DBLabel: TQRDBText
        Left = 64
        Top = 23
        Width = 338
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          60.8541666666667
          894.291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #20303#25152'1'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Add2DBLabel: TQRDBText
        Left = 64
        Top = 43
        Width = 338
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          169.333333333333
          113.770833333333
          894.291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = DM.Q_Seikyu
        DataField = #20303#25152'2'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRChildBand2: TQRChildBand
      Left = 30
      Top = 664
      Width = 741
      Height = 46
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        121.708333333333
        1960.5625)
      object ColorShape3_: TQRShape
        Left = 0
        Top = 20
        Width = 742
        Height = 25
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          66.1458333333333
          0
          52.9166666666667
          1963.20833333333)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object SeikyusakiLabel_: TQRLabel
        Left = 8
        Top = 2
        Width = 338
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          21.1666666666667
          5.29166666666667
          894.291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #35531#27714#20808#21517#31216
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel01_: TQRLabel
        Left = 4
        Top = 26
        Width = 36
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          68.7916666666667
          95.25)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26085#20184
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel02_: TQRLabel
        Left = 50
        Top = 26
        Width = 211
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          132.291666666667
          68.7916666666667
          558.270833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21697#21517
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel03_: TQRLabel
        Left = 270
        Top = 26
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          714.375
          68.7916666666667
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel04_: TQRLabel
        Left = 371
        Top = 26
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          981.604166666667
          68.7916666666667
          129.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20301
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel05_: TQRLabel
        Left = 428
        Top = 26
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1132.41666666667
          68.7916666666667
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20385
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel06_: TQRLabel
        Left = 528
        Top = 26
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1397
          68.7916666666667
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object MeiTitleLabel07_: TQRLabel
        Left = 628
        Top = 26
        Width = 109
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1661.58333333333
          68.7916666666667
          288.395833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20633#32771
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
    end
  end
end
