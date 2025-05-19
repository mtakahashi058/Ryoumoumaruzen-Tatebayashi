object QRForm: TQRForm
  Left = 121
  Top = 133
  Width = 1157
  Height = 500
  Caption = 'QRForm'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object QuickRep: TQuickRep
    Left = 0
    Top = 0
    Width = 1123
    Height = 794
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    BeforePrint = QuickRepBeforePrint
    DataSet = Query
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
    Page.Values = (
      100
      2100
      100
      2970
      100
      50
      0)
    PrinterSettings.Copies = 1
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.OutputBin = Auto
    PrintIfEmpty = True
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object PageHeaderBand: TQRBand
      Left = 38
      Top = 38
      Width = 1066
      Height = 86
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
        227.541666666667
        2820.45833333333)
      BandType = rbPageHeader
      object Item2CodeLabel: TQRLabel
        Left = 1
        Top = 67
        Width = 37
        Height = 15
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          2.64583333333333
          177.270833333333
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '12345'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item2NameLabel: TQRLabel
        Left = 46
        Top = 67
        Width = 142
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          121.708333333333
          177.270833333333
          375.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #38917#30446'2'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item3CodeLabel: TQRLabel
        Left = 196
        Top = 67
        Width = 37
        Height = 15
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          518.583333333333
          177.270833333333
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '12345'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item3NameLabel: TQRLabel
        Left = 241
        Top = 67
        Width = 142
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          637.645833333333
          177.270833333333
          375.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #38917#30446'3'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object DateLabel: TQRLabel
        Left = 388
        Top = 67
        Width = 72
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1026.58333333333
          177.270833333333
          190.5)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #35336#37327#26085
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NoLabel: TQRLabel
        Left = 465
        Top = 67
        Width = 65
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1230.3125
          177.270833333333
          171.979166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20253#31080'No'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NetWLabel: TQRLabel
        Left = 619
        Top = 67
        Width = 93
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1637.77083333333
          177.270833333333
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AmountLabel: TQRLabel
        Left = 718
        Top = 67
        Width = 93
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1899.70833333333
          177.270833333333
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TaniLabel: TQRLabel
        Left = 814
        Top = 67
        Width = 44
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          2153.70833333333
          177.270833333333
          116.416666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20301
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ShabanLabel: TQRLabel
        Left = 570
        Top = 67
        Width = 44
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1508.125
          177.270833333333
          116.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #36554#30058
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object PriceLabel: TQRLabel
        Left = 863
        Top = 67
        Width = 93
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          2283.35416666667
          177.270833333333
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20385
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MoneyLabel: TQRLabel
        Left = 959
        Top = 67
        Width = 100
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          2537.35416666667
          177.270833333333
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TitleLabel: TQRLabel
        Left = 474
        Top = 3
        Width = 118
        Height = 18
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          47.625
          1254.125
          7.9375
          312.208333333333)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '3'#38917#30446#21029#26126#32048#34920
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object QRSysData1: TQRSysData
        Left = 5
        Top = 2
        Width = 121
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          13.2291666666667
          5.29166666666667
          320.145833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsDateTime
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = #30330#34892#26085' - '
        Transparent = False
        FontSize = 8
      end
      object RangeLabel: TQRLabel
        Left = 343
        Top = 26
        Width = 379
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          907.520833333333
          68.7916666666667
          1002.77083333333)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #20986#21147#31684#22258#65306'2008/11/01 '#65374' 2008/11/30'#12288#25644#20837#20986#21306#20998#65306#12377#12409#12390
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRSysData2: TQRSysData
        Left = 926
        Top = 2
        Width = 115
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          2450.04166666667
          5.29166666666667
          304.270833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        Color = clWhite
        Data = qrsPageNumber
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = 'Page - '
        Transparent = False
        FontSize = 8
      end
      object QRShape1: TQRShape
        Left = 0
        Top = 63
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          166.6875
          2820.45833333333)
        Shape = qrsHorLine
      end
      object QRShape2: TQRShape
        Left = 8
        Top = 84
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          21.1666666666667
          222.25
          2820.45833333333)
        Shape = qrsHorLine
      end
      object LineNoLabel: TQRLabel
        Left = 535
        Top = 67
        Width = 29
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          1415.52083333333
          177.270833333333
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #34892'No'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item1Label: TQRLabel
        Left = 1
        Top = 46
        Width = 36
        Height = 15
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          39.6875
          2.64583333333333
          121.708333333333
          95.25)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #38917#30446'1'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand: TQRBand
      Left = 38
      Top = 154
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = DetailBandBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      BandType = rbDetail
      object Item2CodeText: TQRDBText
        Left = 1
        Top = 3
        Width = 37
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2.64583333333333
          7.9375
          97.8958333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#12467#12540#12489'2'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item2NameText: TQRDBText
        Left = 46
        Top = 3
        Width = 142
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
          375.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#30053#31216'2'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item3CodeText: TQRDBText
        Left = 196
        Top = 3
        Width = 37
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          518.583333333333
          7.9375
          97.8958333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#12467#12540#12489'3'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object Item3NameText: TQRDBText
        Left = 241
        Top = 3
        Width = 142
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          637.645833333333
          7.9375
          375.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#30053#31216'3'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object DateText: TQRDBText
        Left = 388
        Top = 3
        Width = 72
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1026.58333333333
          7.9375
          190.5)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35336#37327#26085
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NoText: TQRDBText
        Left = 465
        Top = 3
        Width = 65
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1230.3125
          7.9375
          171.979166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20253#31080'No'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ShabanText: TQRDBText
        Left = 570
        Top = 3
        Width = 44
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1508.125
          7.9375
          116.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #36554#30058
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NetWText: TQRDBText
        Left = 619
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1637.77083333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #27491#21619#37325#37327
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AmountText: TQRDBText
        Left = 718
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1899.70833333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #25968#37327
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TaniText: TQRDBText
        Left = 814
        Top = 3
        Width = 44
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2153.70833333333
          7.9375
          116.416666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21336#20301#12510#12473#12479#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object PriceText: TQRDBText
        Left = 863
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2283.35416666667
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21336#20385
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MoneyText: TQRDBText
        Left = 959
        Top = 3
        Width = 100
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2537.35416666667
          7.9375
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object LineNoText: TQRDBText
        Left = 535
        Top = 3
        Width = 29
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1415.52083333333
          7.9375
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #34892'No'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape3: TQRShape
        Left = 0
        Top = 18
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          47.625
          2820.45833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
    object SummaryBand: TQRBand
      Left = 38
      Top = 234
      Width = 1066
      Height = 22
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
        58.2083333333333
        2820.45833333333)
      BandType = rbSummary
      object QRExpr5: TQRExpr
        Left = 619
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1637.77083333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#27491#21619#37325#37327')'
        Mask = '#,##0'
        FontSize = 10
      end
      object MoneyExpr: TQRExpr
        Left = 959
        Top = 3
        Width = 100
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2537.35416666667
          7.9375
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRLabel4: TQRLabel
        Left = 471
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
          1246.1875
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12304' '#21512'   '#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape4: TQRShape
        Left = 0
        Top = 19
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          50.2708333333333
          2820.45833333333)
        Shape = qrsHorLine
      end
    end
    object Item1GroupHeaderBand: TQRGroup
      Left = 38
      Top = 124
      Width = 1066
      Height = 10
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = Item1GroupHeaderBandBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = True
      Size.Values = (
        26.4583333333333
        2820.45833333333)
      Expression = 'Query.'#38917#30446#12467#12540#12489'1'
      FooterBand = Item1GroupFooterBand
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object Item2GroupHeaderBand: TQRGroup
      Left = 38
      Top = 134
      Width = 1066
      Height = 10
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
        26.4583333333333
        2820.45833333333)
      Expression = 'Query.'#38917#30446#12467#12540#12489'2'
      FooterBand = Item2GroupFooterBand
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object Item1GroupFooterBand: TQRBand
      Left = 38
      Top = 214
      Width = 1066
      Height = 20
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
        52.9166666666667
        2820.45833333333)
      BandType = rbGroupFooter
      object QRExpr3: TQRExpr
        Left = 619
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1637.77083333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#27491#21619#37325#37327')'
        Mask = '#,##0'
        FontSize = 10
      end
      object Item1MoneyExpr: TQRExpr
        Left = 959
        Top = 3
        Width = 100
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2537.35416666667
          7.9375
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object SumItem1Label: TQRLabel
        Left = 471
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
          1246.1875
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12304' '#38917#30446'1'#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape7: TQRShape
        Left = 0
        Top = 18
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          47.625
          2820.45833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
    object Item2GroupFooterBand: TQRBand
      Left = 38
      Top = 194
      Width = 1066
      Height = 20
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
        52.9166666666667
        2820.45833333333)
      BandType = rbGroupFooter
      object QRExpr1: TQRExpr
        Left = 619
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1637.77083333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#27491#21619#37325#37327')'
        Mask = '#,##0'
        FontSize = 10
      end
      object Item2MoneyExpr: TQRExpr
        Left = 959
        Top = 3
        Width = 100
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2537.35416666667
          7.9375
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object SumItem2Label: TQRLabel
        Left = 471
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
          1246.1875
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12304' '#38917#30446'2'#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape6: TQRShape
        Left = 0
        Top = 18
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          47.625
          2820.45833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
    object Item3GroupHeaderBand: TQRGroup
      Left = 38
      Top = 144
      Width = 1066
      Height = 10
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
        26.4583333333333
        2820.45833333333)
      Expression = 'Query.'#38917#30446#12467#12540#12489'3'
      FooterBand = Item3GroupFooterBand
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object Item3GroupFooterBand: TQRBand
      Left = 38
      Top = 174
      Width = 1066
      Height = 20
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
        52.9166666666667
        2820.45833333333)
      BandType = rbGroupFooter
      object QRExpr2: TQRExpr
        Left = 619
        Top = 3
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1637.77083333333
          7.9375
          246.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#27491#21619#37325#37327')'
        Mask = '#,##0'
        FontSize = 10
      end
      object Item3MoneyExpr: TQRExpr
        Left = 959
        Top = 3
        Width = 100
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2537.35416666667
          7.9375
          264.583333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object SumItem3Label: TQRLabel
        Left = 471
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
          1246.1875
          7.9375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12304' '#38917#30446'3'#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape5: TQRShape
        Left = 0
        Top = 18
        Width = 1066
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          47.625
          2820.45833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    LockType = ltReadOnly
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#24471#24847#20808'ID AS '#38917#30446'ID1, '#24471#24847#20808#12467#12540#12489' AS '#38917#30446#12467#12540#12489'1, '#24471#24847#20808#30053#31216' AS '#38917#30446#30053#31216'1,'
      #9#21697#30446'ID   AS '#38917#30446'ID2, '#21697#30446#12467#12540#12489'   AS '#38917#30446#12467#12540#12489'2, '#21697#30446#30053#31216'   AS '#38917#30446#30053#31216'2,'
      #9#38917#30446'1ID  AS '#38917#30446'ID3, '#38917#30446'1'#12467#12540#12489'  AS '#38917#30446#12467#12540#12489'3, '#38917#30446'1'#30053#31216'  AS '#38917#30446#30053#31216'3,'
      #9#35336#37327#26085','
      #9#20253#31080'No,'
      #9#34892'No,'
      #9#36554#30058','
      #9#27491#21619#37325#37327','
      #9#25968#37327','
      #9#21336#20301#12467#12540#12489', '#21336#20301#12510#12473#12479#21517#31216','
      #9#21336#20385','
      #9#37329#38989
      'FROM'
      #9'V_'#35336#37327
      'WHERE'
      #9#35336#37327#26085' BETWEEN 20100701 AND 20100731'
      'AND'
      #9#23436#20102#21306#20998' = 1'
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489', '#21697#30446#12467#12540#12489', '#38917#30446'1'#12467#12540#12489', '#35336#37327#26085', '#20253#31080'No')
    Left = 8
    Top = 8
    object QueryID1: TIntegerField
      FieldName = #38917#30446'ID1'
    end
    object QueryDSDesigner1: TIntegerField
      FieldName = #38917#30446#12467#12540#12489'1'
    end
    object QueryDSDesigner12: TStringField
      FieldName = #38917#30446#30053#31216'1'
      Size = 50
    end
    object QueryID2: TIntegerField
      FieldName = #38917#30446'ID2'
    end
    object QueryDSDesigner2: TIntegerField
      FieldName = #38917#30446#12467#12540#12489'2'
    end
    object QueryDSDesigner22: TStringField
      FieldName = #38917#30446#30053#31216'2'
    end
    object QueryID3: TIntegerField
      FieldName = #38917#30446'ID3'
    end
    object QueryDSDesigner32: TIntegerField
      FieldName = #38917#30446#12467#12540#12489'3'
    end
    object QueryDSDesigner33: TStringField
      FieldName = #38917#30446#30053#31216'3'
    end
    object QueryDSDesigner: TIntegerField
      FieldName = #35336#37327#26085
      DisplayFormat = '0000/00/00'
    end
    object QueryNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object QueryNo2: TIntegerField
      FieldName = #34892'No'
    end
    object QueryDSDesigner3: TIntegerField
      FieldName = #36554#30058
    end
    object QueryDSDesigner4: TBCDField
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 1
    end
    object QueryDSDesigner5: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,##0.###'
      Precision = 10
      Size = 3
    end
    object QueryDSDesigner6: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object QueryDSDesigner7: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object QueryDSDesigner8: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '#,##0.###'
      Precision = 13
      Size = 3
    end
    object QueryDSDesigner9: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
  end
  object MeigaraQuery: TADOQuery
    Connection = DM.ADOConnection
    LockType = ltReadOnly
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#21697#30446#12467#12540#12489','
      
        #9'CASE WHEN MAX('#21697#30446#21517#31216') IS NULL OR MAX('#21697#30446#21517#31216') = '#39#39' THEN '#39#21517#31216#26410#20837#21147#39' ELSE' +
        ' MAX('#21697#30446#21517#31216') END AS '#21697#30446#21517#31216','
      #9'SUM('#27491#21619#37325#37327') AS '#37325#37327','
      #9'SUM('#37329#38989')     AS '#37329#38989
      'FROM'
      #9'V_'#35336#37327
      'WHERE'
      #9#35336#37327#26085' BETWEEN 20110601 AND 20110630'
      'AND'
      #9#23436#20102#21306#20998' = 1'
      'GROUP BY'
      #9#21697#30446#12467#12540#12489)
    Left = 64
    Top = 8
    object MeigaraQueryDSDesigner: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object MeigaraQueryDSDesigner2: TStringField
      FieldName = #21697#30446#21517#31216
      ReadOnly = True
      Size = 40
    end
    object MeigaraQueryDSDesigner3: TBCDField
      FieldName = #37325#37327
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 1
    end
    object MeigaraQueryDSDesigner4: TBCDField
      FieldName = #37329#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
  end
end
