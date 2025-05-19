object QRForm: TQRForm
  Left = 134
  Top = 85
  Width = 1196
  Height = 856
  Caption = 'QRForm'
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
    Width = 1123
    Height = 794
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    BeforePrint = QuickRepBeforePrint
    DataSet = Query
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
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
    object QRShape36: TQRShape
      Left = 38
      Top = 123
      Width = 1066
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        100.541666666667
        325.4375
        2820.45833333333)
      Brush.Style = bsClear
      Shape = qrsRectangle
    end
    object PageHeaderBand1: TQRBand
      Left = 38
      Top = 38
      Width = 1066
      Height = 115
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
        304.270833333333
        2820.45833333333)
      BandType = rbPageHeader
      object QRLabel1: TQRLabel
        Left = 436
        Top = 0
        Width = 193
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1153.58333333333
          0
          510.645833333333)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '*** '#24471#24847#20808#21029#22770#19978#20803#24115' ***'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 12
      end
      object QRSysData1: TQRSysData
        Left = 0
        Top = 0
        Width = 102
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          0
          269.875)
        Alignment = taLeftJustify
        AlignToBand = True
        AutoSize = True
        Color = clWhite
        Data = qrsDateTime
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = #30330#34892#26085' - '
        Transparent = False
        FontSize = 8
      end
      object QRSysData2: TQRSysData
        Left = 973
        Top = 0
        Width = 93
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2574.39583333333
          0
          246.0625)
        Alignment = taRightJustify
        AlignToBand = True
        AutoSize = True
        Color = clWhite
        Data = qrsPageNumber
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = 'page - '
        Transparent = False
        FontSize = 8
      end
      object QRDBText1: TQRDBText
        Left = 7
        Top = 34
        Width = 42
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          18.5208333333333
          89.9583333333333
          111.125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35531#27714#20808#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText2: TQRDBText
        Left = 60
        Top = 33
        Width = 401
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          158.75
          87.3125
          1060.97916666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35531#27714#20808#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 11
      end
      object QRLabel3: TQRLabel
        Left = 6
        Top = 16
        Width = 76
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          15.875
          42.3333333333333
          201.083333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #24471#24847#20808#21517#31216
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText4: TQRDBText
        Left = 56
        Top = 53
        Width = 29
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          148.166666666667
          140.229166666667
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20303#25152
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText5: TQRDBText
        Left = 56
        Top = 69
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          148.166666666667
          182.5625
          280.458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38651#35441#30058#21495
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel4: TQRLabel
        Left = 8
        Top = 53
        Width = 43
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          21.1666666666667
          140.229166666667
          113.770833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20303#25152#65306
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
      object QRLabel7: TQRLabel
        Left = 9
        Top = 69
        Width = 43
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          23.8125
          182.5625
          113.770833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'TEL1'#65306
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
      object QRDBText7: TQRDBText
        Left = 214
        Top = 69
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          566.208333333333
          182.5625
          280.458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = 'FAX'#30058#21495
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel10: TQRLabel
        Left = 174
        Top = 69
        Width = 36
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          460.375
          182.5625
          95.25)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'FAX'#65306
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
      object NendoLabel: TQRLabel
        Left = 554
        Top = 58
        Width = 85
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1465.79166666667
          153.458333333333
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'04'#26376#24230
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
      object QRShape2: TQRShape
        Left = 735
        Top = 23
        Width = 330
        Height = 38
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          1944.6875
          60.8541666666667
          873.125)
        Shape = qrsRectangle
      end
      object QRLabel15: TQRLabel
        Left = 903
        Top = 26
        Width = 43
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2389.1875
          68.7916666666667
          113.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #32224#26085
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText8: TQRDBText
        Left = 903
        Top = 44
        Width = 43
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2389.1875
          116.416666666667
          113.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #32224#26085#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRLabel16: TQRLabel
        Left = 953
        Top = 26
        Width = 56
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2521.47916666667
          68.7916666666667
          148.166666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20837#37329#26376
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText9: TQRDBText
        Left = 953
        Top = 44
        Width = 56
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2521.47916666667
          116.416666666667
          148.166666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#12469#12452#12488#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        Mask = '0000/00/00'
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRDBText10: TQRDBText
        Left = 1015
        Top = 44
        Width = 43
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2685.52083333333
          116.416666666667
          113.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#26085
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRLabel17: TQRLabel
        Left = 740
        Top = 26
        Width = 75
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          68.7916666666667
          198.4375)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989#31471#25968
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText11: TQRDBText
        Left = 740
        Top = 44
        Width = 75
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          116.416666666667
          198.4375)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989#31471#25968#20966#29702#21306#20998#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRLabel26: TQRLabel
        Left = 820
        Top = 26
        Width = 75
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2169.58333333333
          68.7916666666667
          198.4375)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #28040#36027#31246#31471#25968
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText12: TQRDBText
        Left = 820
        Top = 44
        Width = 75
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2169.58333333333
          116.416666666667
          198.4375)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRLabel28: TQRLabel
        Left = 1015
        Top = 26
        Width = 43
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2685.52083333333
          68.7916666666667
          113.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20837#37329#26085
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRShape30: TQRShape
        Left = 735
        Top = 39
        Width = 330
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          1944.6875
          103.1875
          873.125)
        Shape = qrsRectangle
      end
      object QRShape31: TQRShape
        Left = 817
        Top = 24
        Width = 1
        Height = 38
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          2161.64583333333
          63.5
          2.64583333333333)
        Shape = qrsRectangle
      end
      object QRShape32: TQRShape
        Left = 898
        Top = 24
        Width = 1
        Height = 38
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          2375.95833333333
          63.5
          2.64583333333333)
        Shape = qrsRectangle
      end
      object QRShape34: TQRShape
        Left = 949
        Top = 24
        Width = 1
        Height = 38
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          2510.89583333333
          63.5
          2.64583333333333)
        Shape = qrsRectangle
      end
      object QRShape35: TQRShape
        Left = 1011
        Top = 24
        Width = 1
        Height = 38
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          2674.9375
          63.5
          2.64583333333333)
        Shape = qrsRectangle
      end
      object QRLabel14: TQRLabel
        Left = 5
        Top = 93
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          13.2291666666667
          246.0625
          187.854166666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26085' '#20184
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
      object QRLabel29: TQRLabel
        Left = 91
        Top = 93
        Width = 31
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          240.770833333333
          246.0625
          82.0208333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21306#20998
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
      object QRLabel54: TQRLabel
        Left = 137
        Top = 93
        Width = 352
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          362.479166666667
          246.0625
          931.333333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21697#12288#12288#12288#12288#30446
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
      object QRLabel55: TQRLabel
        Left = 497
        Top = 93
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1314.97916666667
          246.0625
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#12288#12288#37327
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
      object QRLabel56: TQRLabel
        Left = 600
        Top = 93
        Width = 40
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1587.5
          246.0625
          105.833333333333)
        Alignment = taCenter
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
      object QRLabel57: TQRLabel
        Left = 653
        Top = 93
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1727.72916666667
          246.0625
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#12288#12288#20385
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
      object QRLabel59: TQRLabel
        Left = 754
        Top = 93
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1994.95833333333
          246.0625
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#12288#12288#38989
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
      object QRLabel60: TQRLabel
        Left = 858
        Top = 93
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2270.125
          246.0625
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20837#12288#37329#12288#38989
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
      object QRLabel61: TQRLabel
        Left = 962
        Top = 93
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2545.29166666667
          246.0625
          243.416666666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27531#12288#12288#39640
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
      object QRShape1: TQRShape
        Left = 4
        Top = 49
        Width = 501
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          129.645833333333
          1325.5625)
        Brush.Style = bsClear
        Shape = qrsHorLine
      end
      object QRDBText37: TQRDBText
        Left = 467
        Top = 33
        Width = 54
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          1235.60416666667
          87.3125
          142.875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #25964#31216#21306#20998#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 11
      end
      object QRShape40: TQRShape
        Left = 0
        Top = 114
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
          301.625
          2820.45833333333)
        Shape = qrsHorLine
      end
    end
    object DetailBand: TQRBand
      Left = 38
      Top = 193
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
      object QRDBText3: TQRDBText
        Left = 5
        Top = 2
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          13.2291666666667
          5.29166666666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #26085#20184
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText6: TQRDBText
        Left = 91
        Top = 2
        Width = 31
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          240.770833333333
          5.29166666666667
          82.0208333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21306#20998
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText14: TQRDBText
        Left = 137
        Top = 2
        Width = 352
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          362.479166666667
          5.29166666666667
          931.333333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21697#30446#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRDBText15: TQRDBText
        Left = 497
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1314.97916666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #25968#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText33: TQRDBText
        Left = 600
        Top = 2
        Width = 40
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1587.5
          5.29166666666667
          105.833333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21336#20301#12510#12473#12479#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRDBText34: TQRDBText
        Left = 653
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1727.72916666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21336#20385
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object UriLabel: TQRLabel
        Left = 754
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1994.95833333333
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'UriLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NyukinLabel: TQRLabel
        Left = 858
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2270.125
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'NyukinLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ZanLabel: TQRLabel
        Left = 962
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2545.29166666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'ZanLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRGroup1: TQRGroup
      Left = 38
      Top = 153
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRGroup1BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = True
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      Expression = 'Query.'#35531#27714#20808#12467#12540#12489
      FooterBand = QRGroupFooter1
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel12: TQRLabel
        Left = 137
        Top = 2
        Width = 162
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          362.479166666667
          5.29166666666667
          428.625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '**     '#32368'     '#36234'     **'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape37: TQRShape
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
      object ZenZanLabel: TQRLabel
        Left = 962
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2545.29166666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21069#26376#32368#36234#38989
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRChildBand: TQRChildBand
      Left = 38
      Top = 213
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRChildBandBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      ParentBand = DetailBand
      object QRShape33: TQRShape
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
      object SeikyuLabel: TQRLabel
        Left = 962
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2545.29166666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'SeikyuLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape38: TQRShape
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
    object QRGroup2: TQRGroup
      Left = 38
      Top = 173
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRGroup2BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      Expression = 'Query.'#24471#24847#20808#12467#12540#12489
      FooterBand = QRGroupFooter2
      Master = QuickRep
      ReprintOnNewPage = False
      object QRShape39: TQRShape
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
      object TokuNameText: TQRDBText
        Left = 137
        Top = 2
        Width = 376
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          362.479166666667
          5.29166666666667
          994.833333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsItalic]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
    end
    object QRGroupFooter1: TQRBand
      Left = 38
      Top = 253
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRGroupFooter1BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      BandType = rbGroupFooter
      object QRLabel2: TQRLabel
        Left = 302
        Top = 2
        Width = 120
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          799.041666666667
          5.29166666666667
          317.5)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '** '#26376' '#38291' '#21512' '#35336' **'
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
      object QRShape41: TQRShape
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
      object UriKeiLabel: TQRLabel
        Left = 754
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1994.95833333333
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'UriKeiLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object NyukinKeiLabel: TQRLabel
        Left = 858
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2270.125
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'NyukinKeiLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object ZanKeiLabel: TQRLabel
        Left = 962
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2545.29166666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'ZanKeiLabel'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object QRGroupFooter2: TQRBand
      Left = 38
      Top = 233
      Width = 1066
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRGroupFooter2BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2820.45833333333)
      BandType = rbGroupFooter
    end
    object QRShape4: TQRShape
      Left = 120
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        317.5
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape5: TQRShape
      Left = 166
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        439.208333333333
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape7: TQRShape
      Left = 530
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        1402.29166666667
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape8: TQRShape
      Left = 630
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        1666.875
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape9: TQRShape
      Left = 683
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        1807.10416666667
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape10: TQRShape
      Left = 786
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        2079.625
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape11: TQRShape
      Left = 889
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        2352.14583333333
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape12: TQRShape
      Left = 993
      Top = 123
      Width = 2
      Height = 633
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Frame.Style = psClear
      Size.Values = (
        1674.8125
        2627.3125
        325.4375
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'DATE_BEF'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DATE_FROM'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DATE_TO'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'ZEIRITU'
        DataType = ftBCD
        Size = -1
        Value = 50000c
      end
      item
        Name = 'SEIKYU_FROM'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'SEIKYU_TO'
        DataType = ftBCD
        Size = -1
        Value = 999990000c
      end>
    SQL.Strings = (
      'DECLARE @DATE_BEF  AS [DECIMAL]'
      'DECLARE @DATE_FROM AS [DECIMAL]'
      'DECLARE @DATE_TO   AS [DECIMAL]'
      'DECLARE @ZEIRITU   AS [DECIMAL]'
      'DECLARE @SEIKYU_FROM AS [DECIMAL]'
      'DECLARE @SEIKYU_TO   AS [DECIMAL]'
      'SET @DATE_BEF  = :DATE_BEF'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      'SET @ZEIRITU   = :ZEIRITU'
      'SET @SEIKYU_FROM = :SEIKYU_FROM'
      'SET @SEIKYU_TO   = :SEIKYU_TO'
      ''
      'SELECT'
      #9'@DATE_TO AS '#32224#20999#26085','
      #9'@DATE_FROM AS '#38283#22987#26085#20184','
      #9'@DATE_TO AS '#32066#20102#26085#20184','
      ''
      #9'A.'#35531#27714#20808'ID,'
      #9'A.'#35531#27714#20808#12467#12540#12489','
      #9'A.'#35531#27714#20808#21517#31216','
      #9'A.'#24471#24847#20808#20214#25968','
      #9'D.'#24471#24847#20808#12467#12540#12489','
      #9'D.'#24471#24847#20808#21517#31216','
      #9'A.'#37109#20415#30058#21495','
      #9'ISNULL(A.'#20303#25152'1, '#39#39') + ISNULL(A.'#20303#25152'2, '#39#39') AS '#20303#25152','
      #9'A.'#38651#35441#30058#21495','
      #9'A.FAX'#30058#21495','
      #9'A.'#32224#26085#12467#12540#12489','
      #9'A.'#27531#39640#34920#31034#21306#20998','
      #9'A.'#25964#31216','
      #9'A.'#20837#37329#26376', A.'#20837#37329#12469#12452#12488#21517#31216','
      #9'A.'#20837#37329#26085','
      #9'A.'#37329#38989#31471#25968#20966#29702#21306#20998',   A.'#37329#38989#31471#25968#20966#29702#21306#20998#21517#31216','
      #9'A.'#28040#36027#31246#31471#25968#20966#29702#21306#20998', A.'#28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216','
      #9'A.'#21069#26376#32224#20999#26085','
      ''
      #9'ISNULL(A.'#21069#26376#27531#39640',   0) AS '#21069#26376#27531#39640','
      #9'ISNULL(B.'#24403#26376#20837#37329#38989', 0) AS '#24403#26376#20837#37329#38989','
      #9'ISNULL(B.'#24403#26376#35519#25972#38989', 0) AS '#24403#26376#35519#25972#38989','
      
        #9'ISNULL(A.'#21069#26376#27531#39640', 0) - ISNULL(B.'#24403#26376#20837#37329#38989', 0) - ISNULL(B.'#24403#26376#35519#25972#38989', 0) AS ' +
        #24403#26376#32368#36234#38989','
      #9'ISNULL(C.'#24403#26376#22770#19978#38989', 0) AS '#24403#26376#22770#19978#38989','
      #9'F.'#24403#26376#28040#36027#31246#38989','
      ''
      #9'D.'#12487#12540#12479#21306#20998','
      #9'D.'#21306#20998','
      #9'D.'#21462#24341'ID,'
      #9'D.'#26085#20184','
      #9'D.'#25312#28857'ID,'
      #9'D.'#25312#28857#21517#31216','
      #9'D.'#20253#31080'No,'
      #9'D.'#34892'No,'
      #9'D.'#38917#30446'1'#12467#12540#12489','
      #9'D.'#38917#30446'1'#21517#31216','
      #9'D.'#38917#30446'2'#12467#12540#12489','
      #9'D.'#38917#30446'2'#21517#31216','
      #9'D.'#21697#30446#12467#12540#12489','
      #9'D.'#21697#30446#21517#31216','
      #9'D.'#21697#30446#20998#39006#12467#12540#12489','
      #9'D.'#21697#30446#20998#39006#21517#31216','
      #9'D.'#25968#37327','
      #9'D.'#21336#20301#12467#12540#12489','
      #9'D.'#21336#20301#12510#12473#12479#21517#31216','
      #9'D.'#21336#20385','
      #9'D.'#37329#38989','
      ''
      #9'ISNULL(E.'#20253#31080#26522#25968', 0) AS '#20253#31080#26522#25968
      ''
      '/* INTO'#9'#SEIKYU */'
      ''
      'FROM'
      #9'/*'#12304#35531#27714#20808#24773#22577#12305#65291#12304#21069#22238#35531#27714#38989#12305'*/'
      #9'('
      #9'SELECT'
      #9#9'TOKU.'#35531#27714#20808'ID,'
      #9#9'SK.'#24471#24847#20808#12467#12540#12489' AS '#35531#27714#20808#12467#12540#12489','
      #9#9'SK.'#24471#24847#20808#21517#31216' AS '#35531#27714#20808#21517#31216','
      #9#9'TS.'#24471#24847#20808#20214#25968','
      #9#9'TOKU.'#24471#24847#20808#12467#12540#12489','
      #9#9'TOKU.'#24471#24847#20808#21517#31216','
      #9#9'SK.'#37109#20415#30058#21495' AS '#37109#20415#30058#21495','
      #9#9'SK.'#20303#25152'1 AS '#20303#25152'1,'
      #9#9'SK.'#20303#25152'2 AS '#20303#25152'2,'
      #9#9'SK.'#38651#35441#30058#21495','
      #9#9'SK.FAX'#30058#21495','
      #9#9'SK.'#32224#26085' AS '#32224#26085#12467#12540#12489','
      #9#9'SK.'#27531#39640#34920#31034#21306#20998','
      #9#9'SK.'#25964#31216','
      #9#9'SK.'#20837#37329#12469#12452#12488' AS '#20837#37329#26376','
      
        #9#9'CASE'#9'SK.'#20837#37329#12469#12452#12488#9'WHEN 0 THEN '#39#24403#26376#39' WHEN 1 THEN '#39#32716#26376#39' WHEN 2 THEN '#39#32716 +
        #12293#26376#39' WHEN 3 THEN '#39'3'#12533#26376#24460#39' WHEN 4 THEN '#39'4'#12533#26376#24460#39' WHEN 5 THEN '#39'5'#12533#26376#24460#39' WHE' +
        'N 6 THEN '#39'6'#12533#26376#24460#39' ELSE '#39#39' END AS '#20837#37329#12469#12452#12488#21517#31216','
      #9#9'SK.'#20837#37329#26085' AS '#20837#37329#26085','
      
        #9#9'SK.'#37329#38989#31471#25968#20966#29702#21306#20998',   CASE SK.'#37329#38989#31471#25968#20966#29702#21306#20998'   WHEN 1 THEN '#39#22235#25448#20116#20837#39' WHEN 0 TH' +
        'EN '#39#20999#25448#12390#39' WHEN 2 THEN '#39#20999#19978#12370#39' ELSE '#39#39' END AS '#37329#38989#31471#25968#20966#29702#21306#20998#21517#31216','
      
        #9#9'SK.'#28040#36027#31246#31471#25968#20966#29702#21306#20998', CASE SK.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' WHEN 1 THEN '#39#22235#25448#20116#20837#39' WHEN 0 THEN' +
        ' '#39#20999#25448#12390#39' WHEN 2 THEN '#39#20999#19978#12370#39' ELSE '#39#39' END AS '#28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216','
      #9#9'SEIKYU.'#21069#26376#32224#20999#26085','
      #9#9'SEIKYU.'#21069#26376#27531#39640
      #9'FROM'
      #9#9'M_'#24471#24847#20808' AS TOKU'
      #9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS SK ON TOKU.'#35531#27714#20808'ID = SK.'#24471#24847#20808'ID'
      
        #9#9'LEFT OUTER JOIN (SELECT '#35531#27714#20808'ID, COUNT(*) AS '#24471#24847#20808#20214#25968' FROM M_'#24471#24847#20808' GR' +
        'OUP BY '#35531#27714#20808'ID) AS TS ON TOKU.'#35531#27714#20808'ID = TS.'#35531#27714#20808'ID'
      #9#9'LEFT OUTER JOIN ('
      #9#9#9'SELECT'
      #9#9#9#9'S.'#35531#27714#20808'ID,'
      #9#9#9#9'S.'#32224#20999#26085' AS '#21069#26376#32224#20999#26085','
      #9#9#9#9'S.'#24403#26376#27531#39640' AS '#21069#26376#27531#39640
      #9#9#9'FROM'
      #9#9#9#9'('
      #9#9#9#9'SELECT'
      #9#9#9#9#9#35531#27714#20808'ID, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9#9#9'FROM'
      #9#9#9#9#9'D_'#22770#25499
      #9#9#9#9'WHERE'
      #9#9#9#9#9#32224#20999#26085' < @DATE_FROM'
      #9#9#9#9'GROUP BY'
      #9#9#9#9#9#35531#27714#20808'ID'
      #9#9#9#9') AS SG'
      
        #9#9#9#9'LEFT OUTER JOIN D_'#22770#25499' AS S ON SG.'#35531#27714#20808'ID = S.'#35531#27714#20808'ID AND SG.'#32224#20999#26085' =' +
        ' S.'#32224#20999#26085
      #9#9#9') AS SEIKYU ON TOKU.'#24471#24847#20808'ID = SEIKYU.'#35531#27714#20808'ID'
      #9'WHERE'
      #9#9'TOKU.'#29694#25499#21306#20998' = 1'#9'-- '#35531#27714#20808#12363#12388#25499
      #9'AND'
      #9#9'TOKU.'#24471#24847#20808'ID = TOKU.'#35531#27714#20808'ID'
      #9') AS A'
      ''
      #9'/* '#12304#20170#22238#20837#37329#38989#12305#12304#20170#22238#35519#25972#38989#12305' */'
      #9'LEFT OUTER JOIN'
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      #9#9'SUM('#29694#37329') + SUM('#25391#36796') + SUM('#25163#25968#26009') + SUM('#23567#20999#25163') +'
      #9#9'SUM('#25163#24418') + SUM('#30456#27578') + SUM('#20516#24341#12365') + SUM('#12381#12398#20182') AS '#24403#26376#20837#37329#38989','
      #9#9'SUM('#35519#25972') AS '#24403#26376#35519#25972#38989
      #9'FROM'
      #9#9'D_'#20837#37329
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'GROUP BY'
      #9#9#35531#27714#20808'ID'
      #9') AS B ON A.'#35531#27714#20808'ID = B.'#35531#27714#20808'ID'
      ''
      #9'/* '#12304#20170#22238#22770#19978#38989#12305' */'
      #9'LEFT OUTER JOIN'
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      #9#9'SUM('#37329#38989') AS '#24403#26376#22770#19978#38989
      #9'FROM'
      #9#9'V_'#21462#24341' AS T'
      #9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TOKU ON T.'#24471#24847#20808'ID = TOKU.'#24471#24847#20808'ID'
      #9'WHERE'
      
        #9#9#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO AND '#21462#24341#21306#20998' = 1 AND '#23436#20102#21306#20998' = 1 ' +
        'AND T.'#29694#25499#21306#20998' = 1'
      #9'GROUP BY'
      #9#9#35531#27714#20808'ID'
      #9') AS C ON A.'#35531#27714#20808'ID = C.'#35531#27714#20808'ID'
      ''
      #9'/* '#12304#21462#24341#26126#32048#12305' */'
      #9'FULL OUTER JOIN'
      #9'('
      #9'SELECT'
      #9#9'1 AS '#12487#12540#12479#21306#20998','
      #9#9#39#22770#19978#39' AS '#21306#20998','
      #9#9'T.'#21462#24341'ID,'
      #9#9'T.'#21462#24341#26085' AS '#26085#20184','
      #9#9'T.'#25312#28857'ID, T.'#25312#28857#21517#31216','
      #9#9'T.'#20253#31080'No AS '#20253#31080'No,'
      #9#9'T.'#34892'No AS '#34892'No,'
      #9#9'TOKU.'#35531#27714#20808'ID, T.'#24471#24847#20808#12467#12540#12489', TOKU.'#24471#24847#20808#21517#31216','
      #9#9'T.'#38917#30446'1'#12467#12540#12489', T.'#38917#30446'1'#21517#31216','
      #9#9'T.'#38917#30446'2'#12467#12540#12489', T.'#38917#30446'2'#21517#31216','
      #9#9'T.'#21697#30446#12467#12540#12489', T.'#21697#30446#21517#31216','
      #9#9'T.'#21697#30446#20998#39006#12467#12540#12489', T.'#21697#30446#20998#39006#21517#31216','
      #9#9'T.'#25968#37327','
      #9#9'T.'#21336#20301#12467#12540#12489', T.'#21336#20301#12510#12473#12479#21517#31216','
      #9#9'T.'#21336#20385','
      #9#9'T.'#37329#38989
      #9'FROM'
      #9#9'V_'#21462#24341' AS T'
      #9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TOKU ON T.'#24471#24847#20808'ID = TOKU.'#24471#24847#20808'ID'
      #9'WHERE'
      #9#9'T.'#21462#24341#26085' >= @DATE_FROM AND T.'#21462#24341#26085' <= @DATE_TO'
      #9'AND'
      #9#9'T.'#21462#24341#21306#20998' = 1 AND T.'#23436#20102#21306#20998' = 1'
      #9'AND'
      #9#9'TOKU.'#29694#25499#21306#20998' = 1'
      ''
      #9'UNION ALL'
      ''
      #9'/* '#35531#27714#12487#12540#12479' */'
      #9'SELECT'
      #9#9'1 AS '#12487#12540#12479#21306#20998','
      #9#9#39#35531#27714#39' AS '#21306#20998','
      #9#9'NULL   AS '#21462#24341'ID,'
      #9#9#32224#20999#26085' AS '#26085#20184','
      #9#9'NULL   AS '#25312#28857'ID, '#39#39' AS '#25312#28857#21517#31216','
      #9#9'99998  AS '#20253#31080'No,'
      #9#9'NULL   AS '#34892'No,'
      #9#9'TOKU.'#35531#27714#20808'ID, TOKU.'#24471#24847#20808#12467#12540#12489', TOKU.'#24471#24847#20808#21517#31216' AS '#24471#24847#20808#21517#31216','
      #9#9'NULL AS '#38917#30446'1'#12467#12540#12489', '#39#39' AS '#38917#30446'1'#21517#31216','
      #9#9'NULL AS '#38917#30446'2'#12467#12540#12489', '#39#39' AS '#38917#30446'2'#21517#31216','
      #9#9'NULL AS '#21697#30446#12467#12540#12489', '#39#39' AS '#21697#30446#21517#31216','
      #9#9'NULL AS '#21697#30446#20998#39006#12467#12540#12489', '#39#39' AS '#21697#30446#20998#39006#21517#31216','
      #9#9'NULL AS '#25968#37327','
      #9#9'NULL AS '#21336#20301#12467#12540#12489', NULL AS '#21336#20301#21517#31216','
      #9#9'NULL AS '#21336#20385','
      #9#9'SK.'#20170#22238#28040#36027#31246#38989' AS '#37329#38989
      #9'FROM'
      #9#9'V_'#35531#27714' AS SK'
      #9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TOKU ON SK.'#35531#27714#20808'ID = TOKU.'#24471#24847#20808'ID'
      #9'WHERE'
      #9#9'SK.'#32224#20999#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      ''
      #9'UNION ALL'
      ''
      #9'/* '#20837#37329#26126#32048' */'
      #9'SELECT'
      #9#9'2 AS '#12487#12540#12479#21306#20998','
      #9#9#39#20837#37329#39' AS '#21306#20998','
      #9#9'NULL   AS '#21462#24341'ID,'
      #9#9#20837#37329#26085','
      #9#9'NULL   AS '#25312#28857'ID, '#39#39' AS '#25312#28857#21517#31216','
      #9#9'99999  AS '#20253#31080'No,'
      #9#9'NULL   AS '#34892'No,'
      #9#9#35531#27714#20808'ID, '#35531#27714#20808#12467#12540#12489' AS '#24471#24847#20808#12467#12540#12489', '#39#39' AS '#24471#24847#20808#21517#31216','
      #9#9'NULL AS '#38917#30446'1'#12467#12540#12489', '#39#39' AS '#38917#30446'1'#21517#31216','
      #9#9'NULL AS '#38917#30446'2'#12467#12540#12489', '#39#39' AS '#38917#30446'2'#21517#31216','
      #9#9'NULL AS '#21697#30446#12467#12540#12489', '#39#39' AS '#21697#30446#21517#31216','
      #9#9'NULL AS '#21697#30446#20998#39006#12467#12540#12489', '#39#39' AS '#21697#30446#20998#39006#21517#31216','
      #9#9'NULL AS '#25968#37327','
      #9#9'NULL AS '#21336#20301#12467#12540#12489', NULL AS '#21336#20301#21517#31216','
      #9#9'NULL AS '#21336#20385','
      
        #9#9'ISNULL('#29694#37329', 0) + ISNULL('#25391#36796', 0) + ISNULL('#25163#25968#26009', 0) + ISNULL('#23567#20999#25163', 0' +
        ') +'
      
        #9#9'ISNULL('#25163#24418', 0) + ISNULL('#30456#27578', 0) + ISNULL('#20516#24341#12365', 0)       + ISNULL(' +
        #35519#25972', 0)     + ISNULL('#12381#12398#20182', 0) AS '#37329#38989
      #9'FROM'
      #9#9'V_'#20837#37329
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      ''
      #9') AS D ON A.'#35531#27714#20808'ID = D.'#35531#27714#20808'ID'
      ''
      #9'/* '#12304#20253#31080#26522#25968#12305' */'
      #9'LEFT OUTER JOIN'
      #9'('
      #9'SELECT'
      #9#9'X.'#35531#27714#20808'ID,'
      #9#9'COUNT(*) AS '#20253#31080#26522#25968
      #9'FROM'
      #9#9'('
      #9#9'SELECT'
      #9#9#9#35531#27714#20808'ID,'
      #9#9#9#20253#31080'No'
      #9#9'FROM'
      #9#9#9'V_'#21462#24341' AS T'
      #9#9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TOKU ON T.'#24471#24847#20808'ID = TOKU.'#24471#24847#20808'ID'
      #9#9'WHERE'
      
        #9#9#9#21462#24341#26085' >= @DATE_FROM AND '#21462#24341#26085' <= @DATE_TO AND '#21462#24341#21306#20998' = 1 AND '#23436#20102#21306#20998' =' +
        ' 1 AND T.'#29694#25499#21306#20998' = 1'
      #9#9'GROUP BY'
      #9#9#9#35531#27714#20808'ID,'
      #9#9#9#20253#31080'No'
      #9#9') AS X'
      #9'GROUP BY'
      #9#9'X.'#35531#27714#20808'ID'
      #9') AS E ON A.'#35531#27714#20808'ID = E.'#35531#27714#20808'ID'
      ''
      #9'/* '#28040#36027#31246#38989' */'
      #9'LEFT OUTER JOIN ('
      #9#9'SELECT'
      #9#9#9#35531#27714#20808'ID,'
      #9#9#9'SUM('#20170#22238#28040#36027#31246#38989') AS '#24403#26376#28040#36027#31246#38989
      #9#9'FROM'
      #9#9#9'D_'#35531#27714
      #9#9'WHERE'
      #9#9#9#32224#20999#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9#9'GROUP BY'
      #9#9#9#35531#27714#20808'ID'
      #9') AS F ON A.'#35531#27714#20808'ID = F.'#35531#27714#20808'ID'
      ''
      'WHERE'
      #9'A.'#35531#27714#20808'ID > 0'#9'/* <- '#12480#12511#12540' ISNULL('#21069#22238#32224#20999#26085', @DEF_SIME) = @LAST_SIME */'
      ''
      'AND'#9'A.'#35531#27714#20808#12467#12540#12489' BETWEEN @SEIKYU_FROM AND @SEIKYU_TO'
      ''
      'ORDER BY'
      #9'A.'#35531#27714#20808#12467#12540#12489', D.'#24471#24847#20808#12467#12540#12489', A.'#24471#24847#20808#12467#12540#12489', '#26085#20184', '#20253#31080'No, '#34892'No'
      '')
    Left = 8
    Top = 8
    object QueryDSDesigner: TBCDField
      FieldName = #32224#20999#26085
      ReadOnly = True
      DisplayFormat = '0000/00/00;#;#'
      Precision = 18
      Size = 0
    end
    object QueryDSDesigner2: TBCDField
      FieldName = #38283#22987#26085#20184
      ReadOnly = True
      DisplayFormat = '0000/00/00;#;#'
      Precision = 18
      Size = 0
    end
    object QueryDSDesigner3: TBCDField
      FieldName = #32066#20102#26085#20184
      ReadOnly = True
      DisplayFormat = '0000/00/00;#;#'
      Precision = 18
      Size = 0
    end
    object QueryID: TIntegerField
      FieldName = #35531#27714#20808'ID'
    end
    object QueryDSDesigner4: TIntegerField
      FieldName = #35531#27714#20808#12467#12540#12489
    end
    object QueryDSDesigner5: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object QueryDSDesigner6: TIntegerField
      FieldName = #24471#24847#20808#20214#25968
    end
    object QueryDSDesigner7: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object QueryDSDesigner8: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object QueryDSDesigner9: TStringField
      FieldName = #37109#20415#30058#21495
      Size = 10
    end
    object QueryDSDesigner10: TStringField
      FieldName = #20303#25152
      ReadOnly = True
      Size = 80
    end
    object QueryDSDesigner11: TStringField
      FieldName = #38651#35441#30058#21495
      Size = 15
    end
    object QueryFAX: TStringField
      FieldName = 'FAX'#30058#21495
      Size = 15
    end
    object QueryDSDesigner12: TIntegerField
      FieldName = #32224#26085#12467#12540#12489
    end
    object QueryDSDesigner13: TIntegerField
      FieldName = #27531#39640#34920#31034#21306#20998
    end
    object QueryDSDesigner42: TStringField
      FieldName = #25964#31216
      Size = 6
    end
    object QueryDSDesigner14: TIntegerField
      FieldName = #20837#37329#26376
    end
    object QueryDSDesigner15: TStringField
      FieldName = #20837#37329#12469#12452#12488#21517#31216
      Size = 7
    end
    object QueryDSDesigner16: TIntegerField
      FieldName = #20837#37329#26085
    end
    object QueryDSDesigner17: TIntegerField
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998
    end
    object QueryDSDesigner18: TStringField
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998#21517#31216
      Size = 8
    end
    object QueryDSDesigner19: TIntegerField
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998
    end
    object QueryDSDesigner20: TStringField
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216
      Size = 8
    end
    object QueryDSDesigner21: TIntegerField
      FieldName = #21069#26376#32224#20999#26085
      DisplayFormat = '0000/00/00;#;#'
    end
    object QueryDSDesigner22: TBCDField
      FieldName = #21069#26376#27531#39640
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object QueryDSDesigner23: TBCDField
      FieldName = #24403#26376#20837#37329#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner24: TBCDField
      FieldName = #24403#26376#35519#25972#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner25: TBCDField
      FieldName = #24403#26376#32368#36234#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner26: TBCDField
      FieldName = #24403#26376#22770#19978#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner27: TBCDField
      FieldName = #24403#26376#28040#36027#31246#38989
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner28: TIntegerField
      FieldName = #12487#12540#12479#21306#20998
    end
    object QueryDSDesigner29: TStringField
      FieldName = #21306#20998
      Size = 4
    end
    object QueryID2: TIntegerField
      FieldName = #21462#24341'ID'
    end
    object QueryDSDesigner30: TIntegerField
      FieldName = #26085#20184
      DisplayFormat = '0000/00/00;#;#'
    end
    object QueryID3: TIntegerField
      FieldName = #25312#28857'ID'
    end
    object QueryDSDesigner31: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object QueryNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object QueryNo2: TIntegerField
      FieldName = #34892'No'
    end
    object QueryDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object QueryDSDesigner110: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object QueryDSDesigner210: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object QueryDSDesigner211: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object QueryDSDesigner32: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object QueryDSDesigner33: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object QueryDSDesigner34: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object QueryDSDesigner35: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object QueryDSDesigner36: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,##0.000;#,##0.000;#.#'
      Precision = 10
      Size = 3
    end
    object QueryDSDesigner37: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object QueryDSDesigner38: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object QueryDSDesigner39: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '#,##0.000;#,##0.000;#'
      Precision = 13
      Size = 3
    end
    object QueryDSDesigner40: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '#,###'
      Precision = 18
      Size = 0
    end
    object QueryDSDesigner41: TIntegerField
      FieldName = #20253#31080#26522#25968
      ReadOnly = True
    end
  end
end
