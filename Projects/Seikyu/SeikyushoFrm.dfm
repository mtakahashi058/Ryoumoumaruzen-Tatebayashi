object SeikyushoForm: TSeikyushoForm
  Left = 1381
  Top = 105
  Width = 1152
  Height = 846
  Caption = 'SeikyushoForm'
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
    Left = 8
    Top = 8
    Width = 1123
    Height = 794
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    BeforePrint = QuickRepBeforePrint
    DataSet = Q_Seikyu
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
    Page.Orientation = poLandscape
    Page.PaperSize = A4
    Page.Values = (
      100
      2100
      100
      2970
      160
      180
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
    object QRShape20: TQRShape
      Left = 60
      Top = 324
      Width = 993
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        158.75
        857.25
        2627.3125)
      Brush.Style = bsClear
      Pen.Width = 3
      Shape = qrsRectangle
    end
    object PageHeaderBand1: TQRBand
      Left = 60
      Top = 38
      Width = 994
      Height = 306
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = PageHeaderBand1BeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        809.625
        2629.95833333333)
      BandType = rbPageHeader
      object QRShape12: TQRShape
        Left = 766
        Top = 218
        Width = 226
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          2026.70833333333
          576.791666666667
          597.958333333333)
        Pen.Width = 3
        Shape = qrsRectangle
      end
      object QRShape3: TQRShape
        Left = 0
        Top = 218
        Width = 684
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          0
          576.791666666667
          1809.75)
        Pen.Width = 3
        Shape = qrsRectangle
      end
      object QRShape11: TQRShape
        Left = 0
        Top = 218
        Width = 684
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          0
          576.791666666667
          1809.75)
        Brush.Color = clBlack
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
        DataSet = Q_Seikyu
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
      object YubinLabel: TQRDBText
        Left = 80
        Top = 41
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          211.666666666667
          108.479166666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
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
      object YubinTLabel: TQRLabel
        Left = 60
        Top = 41
        Width = 15
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          108.479166666667
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
      object PageNumberLabel: TQRLabel
        Left = 972
        Top = 20
        Width = 22
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2571.75
          52.9166666666667
          58.2083333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '1'#38913
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
        Left = 580
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1534.58333333333
          648.229166666667
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
        Left = 13
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          34.3958333333333
          648.229166666667
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
      object KingakuLabel2: TQRLabel
        Left = 129
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          341.3125
          648.229166666667
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
        Left = 242
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          640.291666666667
          648.229166666667
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
        Left = 354
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          936.625
          648.229166666667
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
        Left = 467
        Top = 245
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1235.60416666667
          648.229166666667
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
      object HakkobiLabel: TQRLabel
        Left = 817
        Top = 36
        Width = 99
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2161.64583333333
          95.25
          261.9375)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2008'#24180'01'#26376'31'#26085
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
      object TitleLabel: TQRLabel
        Left = 439
        Top = 0
        Width = 116
        Height = 22
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          58.2083333333333
          1161.52083333333
          0
          306.916666666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #35531#12288#27714#12288#26360
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 16
      end
      object QRLabel4: TQRLabel
        Left = 754
        Top = 36
        Width = 57
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1994.95833333333
          95.25
          150.8125)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #30330#34892#26085#65306
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SeikyumotoLabel01: TQRLabel
        Left = 684
        Top = 56
        Width = 310
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          1809.75
          148.166666666667
          820.208333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20013' '#36960' '#29872' '#22659' '#20445' '#20840' '#26666' '#24335' '#20250' '#31038
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
        Left = 692
        Top = 80
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          211.666666666667
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20195#34920#21462#32224#24441#12288#39640#12288#27211#12288#12288#21191
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
      object QRLabel15: TQRLabel
        Left = 581
        Top = 222
        Width = 91
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1537.22916666667
          587.375
          240.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#28040#36027#31246#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel17: TQRLabel
        Left = 6
        Top = 222
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          15.875
          587.375
          280.458333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #21069#22238#36804#12398#35531#27714#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel18: TQRLabel
        Left = 122
        Top = 222
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          322.791666666667
          587.375
          280.458333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#36804#12398#20837#37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel19: TQRLabel
        Left = 250
        Top = 222
        Width = 76
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          661.458333333333
          587.375
          201.083333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#35519#25972#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel20: TQRLabel
        Left = 362
        Top = 222
        Width = 76
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          957.791666666667
          587.375
          201.083333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#32368#36234#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel21: TQRLabel
        Left = 475
        Top = 222
        Width = 76
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1256.77083333333
          587.375
          201.083333333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#22770#19978#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape6: TQRShape
        Left = 230
        Top = 218
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          608.541666666667
          576.791666666667
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape7: TQRShape
        Left = 343
        Top = 218
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          907.520833333333
          576.791666666667
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape8: TQRShape
        Left = 456
        Top = 218
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1206.5
          576.791666666667
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape9: TQRShape
        Left = 569
        Top = 218
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1505.47916666667
          576.791666666667
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRLabel22: TQRLabel
        Left = 242
        Top = 168
        Width = 85
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          640.291666666667
          444.5
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35531#27714#20808#12467#12540#12489#65306
        Color = clWhite
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
      object QRDBText1: TQRDBText
        Left = 330
        Top = 168
        Width = 39
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          873.125
          444.5
          103.1875)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
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
      object QRLabel23: TQRLabel
        Left = 40
        Top = 200
        Width = 463
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          105.833333333333
          529.166666666667
          1225.02083333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #19979#35352#12398#36890#12426#12372#35531#27714#30003#12375#19978#12370#12414#12377#12290#23578#12289#12362#25903#25173#28168#12415#12398#31680#12399#12372#23481#36198#12367#12384#12373#12356#12290
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape4: TQRShape
        Left = 766
        Top = 218
        Width = 226
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          2026.70833333333
          576.791666666667
          597.958333333333)
        Brush.Color = clBlack
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object QRLabel24: TQRLabel
        Left = 834
        Top = 222
        Width = 91
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2206.625
          587.375
          240.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20170#22238#12372#35531#27714#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object KingakuLabel7: TQRLabel
        Left = 799
        Top = 242
        Width = 131
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          2114.02083333333
          640.291666666667
          346.604166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object SeikyumotoLabel03: TQRLabel
        Left = 692
        Top = 94
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          248.708333333333
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26412#12288#12288#31038#12288#12306#65300#65299#65302#65293#65296#65296#65296#65300
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
        Left = 692
        Top = 108
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          285.75
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#25499#24029#24066#20843#22338#65299#65297#65303#65293#65299
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
        Left = 692
        Top = 123
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          325.4375
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#65332#65317#65324#65306#65296#65301#65299#65303#65288#65298#65303#65289#65297#65298#65300#65304
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
        Left = 692
        Top = 137
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          362.479166666667
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#65318#65313#65336#65306#65296#65301#65299#65303#65288#65298#65303#65289#65296#65305#65298#65297
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
        Left = 692
        Top = 151
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          399.520833333333
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #31532#65298#24037#22580#12288#12306#65300#65299#65302#65293#65296#65298#65298#65298
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
        Left = 692
        Top = 166
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          439.208333333333
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#25499#24029#24066#19979#22402#26408#65298#65301#65296#65300#65293#65302
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
      object SeikyumotoLabel09: TQRLabel
        Left = 692
        Top = 180
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          476.25
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#65332#65317#65324#65306#65296#65301#65299#65303#65288#65302#65297#65289#65296#65302#65296#65296
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
      object SeikyumotoLabel10: TQRLabel
        Left = 692
        Top = 195
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1830.91666666667
          515.9375
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12288#12288#12288#12288#12288#12288#65318#65313#65336#65306#65296#65301#65299#65303#65288#65298#65300#65289#65302#65302#65298#65303
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
      object QRShape19: TQRShape
        Left = 0
        Top = 286
        Width = 993
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          0
          756.708333333333
          2627.3125)
        Brush.Color = clBlack
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object QRLabel31: TQRLabel
        Left = 4
        Top = 289
        Width = 81
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          764.645833333333
          214.3125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26085#20184
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel32: TQRLabel
        Left = 92
        Top = 289
        Width = 321
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          243.416666666667
          764.645833333333
          849.3125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21697#21517
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel33: TQRLabel
        Left = 423
        Top = 289
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1119.1875
          764.645833333333
          277.8125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel34: TQRLabel
        Left = 539
        Top = 289
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1426.10416666667
          764.645833333333
          129.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20301
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel35: TQRLabel
        Left = 598
        Top = 289
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1582.20833333333
          764.645833333333
          277.8125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20385
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel29: TQRLabel
        Left = 713
        Top = 289
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          764.645833333333
          277.8125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRLabel30: TQRLabel
        Left = 828
        Top = 289
        Width = 161
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2190.75
          764.645833333333
          425.979166666667)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20633#32771
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object HurikaeCodeLabel: TQRLabel
        Left = 396
        Top = 168
        Width = 187
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          1047.75
          444.5
          494.770833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #33258#21205#25391#26367#12467#12540#12489#65306'123456789012345'
        Color = clWhite
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
      object HikiwatasibiLabel: TQRLabel
        Left = 477
        Top = 269
        Width = 522
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1262.0625
          711.729166666667
          1381.125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #8251'yyyy'#24180'mm'#26376'dd'#26085#12395#25351#23450#21475#24231#12424#12426#24341#33853#12392#12375#12356#12383#12375#12414#12377#12290'dd'#26085#12364#22303#26085#31069#26085#12398#22580#21512#12399#12289#32716#21942#26989#26085#12392#12394#12426#12414#12377#12290
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object AddressLabel1: TQRLabel
        Left = 60
        Top = 68
        Width = 309
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          179.916666666667
          817.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20303#25152'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AddressLabel2: TQRLabel
        Left = 60
        Top = 84
        Width = 309
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          222.25
          817.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20303#25152'2'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AddressLabel3: TQRLabel
        Left = 60
        Top = 100
        Width = 85
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          264.583333333333
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20303#25152'3'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SeikyusakiLabel1: TQRLabel
        Left = 60
        Top = 123
        Width = 309
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          325.4375
          817.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #35531#27714#20808#21517#31216'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SeikyusakiLabel2: TQRLabel
        Left = 60
        Top = 139
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          158.75
          367.770833333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21517#31216'2'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object HonshaLabel: TQRLabel
        Left = 674
        Top = 93
        Width = 15
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1783.29166666667
          246.0625
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #9678
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object DainiLabel: TQRLabel
        Left = 674
        Top = 150
        Width = 15
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1783.29166666667
          396.875
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #9678
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object SeikyuNoLabel: TQRLabel
        Left = 755
        Top = 20
        Width = 190
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1997.60416666667
          52.9166666666667
          502.708333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35531#27714'NO'#65306' YYMM-DDHHNN-999999'
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
      object QRShape5: TQRShape
        Left = 117
        Top = 218
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          309.5625
          576.791666666667
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
    end
    object QRShape22: TQRShape
      Left = 60
      Top = 362
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        957.791666666667
        2627.3125)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape23: TQRShape
      Left = 60
      Top = 382
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1010.70833333333
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape24: TQRShape
      Left = 60
      Top = 402
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1063.625
        2627.3125)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape25: TQRShape
      Left = 60
      Top = 422
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1116.54166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape26: TQRShape
      Left = 60
      Top = 442
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1169.45833333333
        2627.3125)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape27: TQRShape
      Left = 60
      Top = 462
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1222.375
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape28: TQRShape
      Left = 60
      Top = 482
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1275.29166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape29: TQRShape
      Left = 60
      Top = 502
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1328.20833333333
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape30: TQRShape
      Left = 60
      Top = 522
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1381.125
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape31: TQRShape
      Left = 60
      Top = 542
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1434.04166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape32: TQRShape
      Left = 60
      Top = 562
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1486.95833333333
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape33: TQRShape
      Left = 60
      Top = 582
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1539.875
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape34: TQRShape
      Left = 60
      Top = 602
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1592.79166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape35: TQRShape
      Left = 60
      Top = 622
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1645.70833333333
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape36: TQRShape
      Left = 60
      Top = 642
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1698.625
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape37: TQRShape
      Left = 60
      Top = 662
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1751.54166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape38: TQRShape
      Left = 60
      Top = 682
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1804.45833333333
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 60
      Top = 702
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1857.375
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape39: TQRShape
      Left = 60
      Top = 722
      Width = 993
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        158.75
        1910.29166666667
        2627.3125)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRImage2: TQRImage
      Left = 37
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
        97.8958333333333
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
    object QRImage3: TQRImage
      Left = 810
      Top = 20
      Width = 4
      Height = 4
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        10.5833333333333
        2143.125
        52.9166666666667
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
        0000010101010101010101050501010101010101010101010101010101010104
        0401010101010101010101010101010101010500000501010101010101010101
        0101010101010400000401010101010101010101010101010105000000000501
        0101010101010101010101010104000000000401010101010101010101010101
        0500000000000005010101010101010101010101040000000000000401010101
        0101010101010105000000000000000005010101010101010101010400000000
        0000000004010101010101010101050000000000000000000005010101010101
        0101040000000000000000000004010101010101010500000000000000000000
        0000050101010101010400000000000000000000000004010101010105000000
        0000000000000000000000050101010104000000000000000000000000000004
        0101010500000000000000000000000000000000050101040000000000000000
        0000000000000000040102000000000000000000000000000000000000020303
        030303030303030303030303030303030303}
      Stretch = True
    end
    object FooterLabel: TQRLabel
      Left = 64
      Top = 747
      Width = 989
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        169.333333333333
        1976.4375
        2616.72916666667)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = False
      AutoStretch = False
      Caption = 
        #21462#24341#37504#34892'  *  '#28165#27700#37504#34892#25499#24029#25903#24215' '#24403#24231' 524  *  '#12473#12523#12460#37504#34892#25499#24029#25903#24215' '#26222#36890' 413-871  *  '#38745#23713#37504#34892#25499#24029#25903#24215' '#26222 +
        #36890' 152243  *  '#25499#24029#20449#29992#37329#24235#19979#20451#25903#24215' '#26222#36890' 52363'
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
    object QRShape13: TQRShape
      Left = 148
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        391.583333333333
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape15: TQRShape
      Left = 593
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        1568.97916666667
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape16: TQRShape
      Left = 652
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        1725.08333333333
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape17: TQRShape
      Left = 767
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        2029.35416666667
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape18: TQRShape
      Left = 883
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        2336.27083333333
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape21: TQRShape
      Left = 477
      Top = 324
      Width = 2
      Height = 420
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1111.25
        1262.0625
        857.25
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object GroupHeaderSeikyu: TQRGroup
      Left = 60
      Top = 344
      Width = 994
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = True
      Size.Values = (
        52.9166666666667
        2629.95833333333)
      Expression = 'Q_Seikyu.'#35531#27714#20808'ID'
      FooterBand = GroupFooterSeikyu
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object GroupHeaderGenb: TQRGroup
      Left = 60
      Top = 364
      Width = 994
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupHeaderGenbBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2629.95833333333)
      Expression = 'Q_Seikyu.'#24471#24847#20808'ID'
      FooterBand = GroupFooterGenb
      Master = QuickRep
      ReprintOnNewPage = False
      object TokuisakiLabel: TQRLabel
        Left = 96
        Top = 3
        Width = 445
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          254
          7.9375
          1177.39583333333)
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
    end
    object QRGroupKenmei: TQRGroup
      Left = 60
      Top = 384
      Width = 994
      Height = 20
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = QRGroupKenmeiBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        52.9166666666667
        2629.95833333333)
      Expression = 'Q_Seikyu.'#21462#24341'ID'
      Master = QuickRep
      ReprintOnNewPage = False
      object KenmeiLabel: TQRLabel
        Left = 96
        Top = 3
        Width = 445
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          254
          7.9375
          1177.39583333333)
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
    end
    object DetailBand1: TQRBand
      Left = 60
      Top = 404
      Width = 994
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
        2629.95833333333)
      BandType = rbDetail
      object DateDBText: TQRDBText
        Left = 3
        Top = 3
        Width = 81
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
          214.3125)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#26085#20184
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
        Left = 423
        Top = 3
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1119.1875
          7.9375
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#25968#37327
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
      object QRDBText16: TQRDBText
        Left = 539
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
          1426.10416666667
          7.9375
          129.645833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#21336#20301#21517#31216
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
      object QRDBText17: TQRDBText
        Left = 598
        Top = 3
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1582.20833333333
          7.9375
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#21336#20385
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
        Left = 713
        Top = 3
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          7.9375
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#37329#38989
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
      object QRDBText3: TQRDBText
        Left = 96
        Top = 3
        Width = 281
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          254
          7.9375
          743.479166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#21697#30446#21517#31216
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
        Left = 836
        Top = 3
        Width = 141
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2211.91666666667
          7.9375
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Seikyu
        DataField = #22770#19978#20633#32771
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
    object GroupFooterGenb: TQRBand
      Left = 60
      Top = 424
      Width = 994
      Height = 40
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      BeforePrint = GroupFooterGenbBeforePrint
      Color = clWhite
      ForceNewColumn = False
      ForceNewPage = False
      Size.Values = (
        105.833333333333
        2629.95833333333)
      BandType = rbGroupFooter
      object GFGLabel: TQRLabel
        Left = 642
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
          1698.625
          7.9375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #35336
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
      object GenbKeiLabel: TQRLabel
        Left = 713
        Top = 3
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          7.9375
          277.8125)
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
    object GroupFooterSeikyu: TQRBand
      Left = 60
      Top = 464
      Width = 994
      Height = 60
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
        158.75
        2629.95833333333)
      BandType = rbGroupFooter
      object QRLabel1: TQRLabel
        Left = 642
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
          1698.625
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
        Left = 642
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
          1698.625
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
        Left = 642
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
          1698.625
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
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object ShohizeiLabel: TQRLabel
        Left = 713
        Top = 23
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          60.8541666666667
          277.8125)
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
        Left = 713
        Top = 43
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          113.770833333333
          277.8125)
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
      object UriageGokeiLabel: TQRLabel
        Left = 713
        Top = 3
        Width = 105
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1886.47916666667
          7.9375
          277.8125)
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
  end
  object Q_Seikyu: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <
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
        Value = 999999990000c
      end
      item
        Name = 'SIME'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'ZEI'
        DataType = ftBCD
        Size = -1
        Value = 50000c
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM AS [DECIMAL]'
      'DECLARE @DATE_TO   AS [DECIMAL]'
      'DECLARE @SIME AS [DECIMAL]'
      'DECLARE @TAX_RATE  AS [DECIMAL]'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      'SET @SIME = :SIME'
      'SET @TAX_RATE  = :ZEI'
      ''
      'SELECT'
      #9'@DATE_TO   AS '#32224#20999#26085','
      #9'@DATE_FROM AS '#38283#22987#26085#20184','
      #9'@DATE_TO   AS '#32066#20102#26085#20184','
      #9'A.'#35531#27714#20808'ID, A.'#35531#27714#20808#12467#12540#12489', A.'#35531#27714#20808#21517#31216','
      #9'A.'#33258#21205#25391#26367#12467#12540#12489','
      #9'A.'#37109#20415#30058#21495','
      #9'A.'#20303#25152'1, A.'#20303#25152'2,'
      #9'A.'#25964#31216#21306#20998', A.'#25964#31216#21306#20998#21517#31216','
      #9'A.'#27531#39640#34920#31034#21306#20998','
      #9'A.'#20837#37329#12469#12452#12488','
      #9'A.'#20837#37329#26085','
      #9'A.'#20837#37329#26041#27861', A.'#20837#37329#26041#27861#21517#31216','
      #9'A.'#21942#26989#25285#24403#31038#21729#12467#12540#12489', A.'#21942#26989#25285#24403#31038#21729#21517#31216','
      #9'A.'#20107#21209#25285#24403#31038#21729#12467#12540#12489', A.'#20107#21209#25285#24403#31038#21729#21517#31216','
      #9'A.'#26376#38989','
      #9'A.'#21069#22238#32224#20999#26085','
      #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) AS '#21069#22238#35531#27714#38989','
      #9'ISNULL(B.'#20837#37329#38989', 0)     AS '#20837#37329#38989','
      #9'ISNULL(B.'#35519#25972#38989', 0)     AS '#35519#25972#38989','
      
        #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20837#37329#38989', 0) + ISNULL(B.'#35519#25972#38989', 0)) AS '#32368 +
        #36234#38989','
      #9'ISNULL(C.'#22770#19978#38989', 0) AS '#22770#19978#38989','
      #9'ISNULL(C.'#28040#36027#31246#38989', 0)   AS '#28040#36027#31246#38989','
      
        #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20837#37329#38989', 0) + ISNULL(B.'#35519#25972#38989', 0)) + IS' +
        'NULL(C.'#22770#19978#38989', 0) + ISNULL(C.'#28040#36027#31246#38989', 0) AS '#20170#22238#35531#27714#38989','
      #9'D.'#21462#24341'ID, D.'#21462#24341#26126#32048'ID,'
      #9'D.'#12487#12540#12479#21306#20998', D.'#26126#32048'NO,'
      #9'D.'#24471#24847#20808'ID, D.'#24471#24847#20808#12467#12540#12489', D.'#24471#24847#20808#21517#31216','
      #9'D.'#20214#21517','
      #9'D.'#22770#19978#26085#20184','
      #9'D.'#22770#19978#21697#30446'ID, D.'#22770#19978#21697#30446#21517#31216','
      #9'D.'#22770#19978#25968#37327','
      #9'D.'#22770#19978#21336#20301#12467#12540#12489', D.'#22770#19978#21336#20301#21517#31216','
      #9'D.'#22770#19978#21336#20385','
      #9'D.'#22770#19978#37329#38989','
      #9'D.'#22770#19978#20633#32771','
      #9'D.'#22770#19978#20633#32771#34920#31034#21306#20998
      'FROM'
      #9'/*'#12304#35531#27714#20808#24773#22577#12305#65291#12304#21069#22238#35531#27714#38989#12305'*/'
      #9'('
      #9'SELECT'
      #9#9'T.'#24471#24847#20808'ID     AS '#35531#27714#20808'ID,'
      #9#9'T.'#24471#24847#20808#12467#12540#12489' AS '#35531#27714#20808#12467#12540#12489','
      #9#9'T.'#33258#21205#25391#26367#12467#12540#12489','
      #9#9'T.'#24471#24847#20808#21517#31216'   AS '#35531#27714#20808#21517#31216','
      #9#9'T.'#37109#20415#30058#21495','
      #9#9'T.'#20303#25152'1,'
      #9#9'T.'#20303#25152'2,'
      #9#9'T.'#37329#38989#31471#25968#20966#29702#21306#20998','
      #9#9'T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998','
      #9#9'T.'#29694#25499#21306#20998','
      #9#9'T.'#32224#26085','
      #9#9'T.'#25964#31216#21306#20998', T.'#25964#31216#21306#20998#21517#31216','
      #9#9'T.'#27531#39640#34920#31034#21306#20998','
      #9#9'T.'#20837#37329#12469#12452#12488','
      #9#9'T.'#20837#37329#26085','
      #9#9'T.'#20837#37329#26041#27861', T.'#20837#37329#26041#27861#21517#31216','
      #9#9'T.'#21942#26989#25285#24403#31038#21729'ID, T.'#21942#26989#25285#24403#31038#21729#12467#12540#12489', T.'#21942#26989#25285#24403#31038#21729#21517#31216','
      #9#9'T.'#20107#21209#25285#24403#31038#21729'ID, T.'#20107#21209#25285#24403#31038#21729#12467#12540#12489', T.'#20107#21209#25285#24403#31038#21729#21517#31216','
      #9#9'T.'#20808#26041#25285#24403#32773#21517','
      #9#9'T.'#26376#38989','
      #9#9'S.'#21069#22238#32224#20999#26085','
      #9#9'S.'#21069#22238#35531#27714#38989
      #9'FROM'
      #9#9'V_'#24471#24847#20808' AS T'
      #9#9'LEFT OUTER JOIN('
      #9#9#9'SELECT'
      #9#9#9#9'S.'#35531#27714#20808'ID,'
      #9#9#9#9'S.'#32224#20999#26085' AS '#21069#22238#32224#20999#26085','
      #9#9#9#9'S.'#20170#22238#35531#27714#38989' AS '#21069#22238#35531#27714#38989
      #9#9#9'FROM'
      #9#9#9#9'('
      #9#9#9#9'SELECT'
      #9#9#9#9#9#35531#27714#20808'ID, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9#9#9'FROM'
      #9#9#9#9#9'D_'#35531#27714
      #9#9#9#9'WHERE'
      #9#9#9#9#9#32224#20999#26085' < @DATE_FROM'
      #9#9#9#9'GROUP BY'
      #9#9#9#9#9#35531#27714#20808'ID'
      #9#9#9#9') AS SG'
      
        #9#9#9#9'LEFT OUTER JOIN D_'#35531#27714' AS S ON SG.'#35531#27714#20808'ID = S.'#35531#27714#20808'ID AND SG.'#32224#20999#26085' =' +
        ' S.'#32224#20999#26085
      #9#9#9') AS S ON T.'#35531#27714#20808'ID = S.'#35531#27714#20808'ID'
      #9'WHERE'
      #9#9'T.'#32224#26085' = @SIME'
      #9'AND'
      
        #9#9'T.'#24471#24847#20808'ID = T.'#35531#27714#20808'ID /*T.'#35531#27714#20808'ID IN (SELECT '#35531#27714#20808'ID FROM M_'#24471#24847#20808' GROUP ' +
        'BY '#35531#27714#20808'ID)*/'
      #9') AS A'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'/* '#37857#37096' '#20837#37329#38989', '#35519#25972#38989' */'
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      
        #9#9'SUM('#29694#37329') + SUM('#25391#36796') + SUM('#25391#36796#25163#25968#26009') + SUM('#33258#21205#25391#26367') + SUM('#23567#20999#25163') + SUM('#25163#24418 +
        ') + SUM('#30456#27578') + SUM('#20516#24341') + SUM('#12381#12398#20182') AS '#20837#37329#38989','
      #9#9'SUM('#35519#25972') AS '#35519#25972#38989#9
      #9'FROM'
      #9#9'D_'#20837#37329
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'GROUP BY'
      #9#9#35531#27714#20808'ID'
      #9') AS B ON A.'#35531#27714#20808'ID = B.'#35531#27714#20808'ID'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'/* '#37857#37096' '#22770#19978#38989', '#28040#36027#31246#38989' */'
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      #9#9'SUM('#22770#19978#38989') AS '#22770#19978#38989','
      #9#9'SUM('#28040#36027#31246#38989') AS '#28040#36027#31246#38989
      #9'FROM'
      #9#9'('
      #9#9'SELECT'
      #9#9#9'D.'#35531#27714#20808'ID,'
      #9#9#9'ISNULL(D.'#31246#21029#22770#19978#38989', 0) + ISNULL(D.'#31246#36796#22770#19978#38989', 0) AS '#22770#19978#38989','
      
        #9#9#9'CASE WHEN D.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 0 THEN FLOOR(ISNULL(D.'#31246#21029#22770#19978#38989', 0) * @TA' +
        'X_RATE / 100)'
      
        #9#9#9#9' WHEN D.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 1 THEN ROUND(ISNULL(D.'#31246#21029#22770#19978#38989', 0) * @TAX_R' +
        'ATE / 100, 0)'
      
        #9#9#9#9' WHEN D.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 2 THEN CEILING(ISNULL(D.'#31246#21029#22770#19978#38989', 0) * @TAX' +
        '_RATE / 100)'
      #9#9#9'END AS '#28040#36027#31246#38989
      #9#9'FROM'
      #9#9#9'('
      #9#9#9'SELECT'
      #9#9#9#9'M.'#35531#27714#20808'ID,'
      #9#9#9#9'CASE WHEN M.'#31246#21306#20998' = 1 THEN SUM(M.'#22770#19978#37329#38989') ELSE 0 END AS '#31246#21029#22770#19978#38989','
      #9#9#9#9'CASE WHEN M.'#31246#21306#20998' = 2 THEN SUM(M.'#22770#19978#37329#38989') ELSE 0 END AS '#31246#36796#22770#19978#38989','
      #9#9#9#9'MAX(M.'#28040#36027#31246#31471#25968#20966#29702#21306#20998') AS '#28040#36027#31246#31471#25968#20966#29702#21306#20998
      #9#9#9'FROM'
      #9#9#9#9'('
      #9#9#9#9'SELECT'
      #9#9#9#9#9'T.'#24471#24847#20808'ID,'
      #9#9#9#9#9'TM.'#22770#19978#21697#30446'ID,'
      #9#9#9#9#9'TM.'#22770#19978#21336#20301'ID,'
      #9#9#9#9#9'TM.'#22770#19978#37329#38989','
      #9#9#9#9#9'TM.'#22770#19978#31246#21306#20998' AS '#31246#21306#20998','
      #9#9#9#9#9'TK.'#35531#27714#20808'ID,'
      #9#9#9#9#9'TK.'#28040#36027#31246#31471#25968#20966#29702#21306#20998
      #9#9#9#9'FROM'
      #9#9#9#9#9'D_'#21462#24341#26126#32048' AS TM'
      #9#9#9#9#9'LEFT OUTER JOIN D_'#21462#24341' AS T'
      #9#9#9#9#9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TK ON T.'#24471#24847#20808'ID = TK.'#24471#24847#20808'ID'
      #9#9#9#9#9'ON TM.'#21462#24341'ID = T.'#21462#24341'ID'
      #9#9#9#9'WHERE'
      #9#9#9#9#9'TM.'#22770#19978#26085#20184' BETWEEN @DATE_FROM AND @DATE_TO'
      #9#9#9#9') AS M'
      #9#9#9'GROUP BY'
      #9#9#9#9'M.'#35531#27714#20808'ID, M.'#31246#21306#20998
      #9#9#9') AS D'
      #9#9') AS G'
      #9'GROUP BY'
      #9#9'G.'#35531#27714#20808'ID'
      #9') AS C ON A.'#35531#27714#20808'ID = C.'#35531#27714#20808'ID'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'/* '#22770#19978#26126#32048' */'
      #9'('
      #9'SELECT'
      #9#9'TM.'#21462#24341#26126#32048'ID,'
      #9#9'1 AS '#12487#12540#12479#21306#20998','
      #9#9'1 AS '#34920#31034#38918','
      #9#9'TM.'#22770#19978#26085#20184', TM.'#21462#24341'ID, TM.'#26126#32048'NO,'
      #9#9'T.'#24471#24847#20808'ID, TK.'#24471#24847#20808#12467#12540#12489', TK.'#24471#24847#20808#21517#31216', TK.'#35531#27714#20808'ID,'
      #9#9'T.'#20214#21517','
      #9#9'TM.'#22770#19978#21697#30446'ID, TM.'#22770#19978#21697#30446#21517#31216','
      #9#9'TM.'#22770#19978#25968#37327','
      #9#9'TM.'#22770#19978#21336#20301'ID, TN.'#21336#20301#12467#12540#12489' AS '#22770#19978#21336#20301#12467#12540#12489', TN.'#21336#20301#21517#31216' AS '#22770#19978#21336#20301#21517#31216','
      #9#9'TM.'#22770#19978#21336#20385','
      #9#9'TM.'#22770#19978#37329#38989','
      #9#9'TM.'#22770#19978#20633#32771','
      #9#9'TM.'#22770#19978#20633#32771#34920#31034#21306#20998
      #9'FROM'
      #9#9'D_'#21462#24341#26126#32048' AS TM'
      #9#9'LEFT OUTER JOIN M_'#21336#20301' AS TN ON TM.'#22770#19978#21336#20301'ID = TN.'#21336#20301'ID'
      #9#9'LEFT OUTER JOIN D_'#21462#24341' AS T'
      #9#9#9'LEFT OUTER JOIN M_'#24471#24847#20808' AS TK ON T.'#24471#24847#20808'ID = TK.'#24471#24847#20808'ID'
      #9#9'ON TM.'#21462#24341'ID = T.'#21462#24341'ID'
      #9'WHERE'
      #9#9'TM.'#22770#19978#26085#20184' BETWEEN @DATE_FROM AND @DATE_TO'
      ''
      #9'UNION ALL'
      ''
      #9'/* '#20837#37329#26126#32048' */'
      #9'SELECT'
      #9#9'-1 AS '#21462#24341#26126#32048'ID,'
      #9#9'2 AS '#12487#12540#12479#21306#20998','
      #9#9'3 AS '#34920#31034#38918','
      #9#9#20837#37329#26085', 0 AS '#21462#24341'ID, 0 AS '#26126#32048'NO,'
      #9#9'NULL AS '#24471#24847#20808'ID, NULL AS '#24471#24847#20808#12467#12540#12489', '#39#39' AS '#24471#24847#20808#21517#31216', '#35531#27714#20808'ID,'
      #9#9'NULL AS '#20214#21517','
      #9#9'0 AS '#22770#19978#21697#30446'ID, '#39#20837#37329#39' AS '#22770#19978#21697#30446#21517#31216','
      #9#9'NULL AS '#22770#19978#25968#37327','
      #9#9'NULL AS '#22770#19978#21336#20301'ID, NULL AS '#22770#19978#21336#20301#12467#12540#12489', '#39#39' AS '#22770#19978#21336#20301#21517#31216','
      #9#9'NULL AS '#22770#19978#21336#20385','
      
        #9#9'ISNULL('#29694#37329', 0) + ISNULL('#25391#36796', 0) + ISNULL('#25391#36796#25163#25968#26009', 0) + ISNULL('#33258#21205#25391#26367 +
        ', 0) + ISNULL('#23567#20999#25163', 0) +'
      
        #9#9'ISNULL('#25163#24418', 0) + ISNULL('#30456#27578', 0) + ISNULL('#20516#24341', 0)       + ISNULL('#35519 +
        #25972', 0)     + ISNULL('#12381#12398#20182', 0) AS '#37329#38989','
      #9#9#39#39' AS '#22770#19978#20633#32771','
      #9#9'1 AS '#22770#19978#20633#32771#34920#31034#21306#20998
      #9'FROM'
      #9#9'D_'#20837#37329
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      ''
      #9') AS D ON A.'#35531#27714#20808'ID = D.'#35531#27714#20808'ID'
      'WHERE'
      
        #9'(ISNULL(C.'#22770#19978#38989', 0) > 0 OR ISNULL(A.'#21069#22238#35531#27714#38989', 0) <> 0 OR ISNULL(B.'#20837#37329 +
        #38989', 0) <> 0 OR ISNULL(B.'#35519#25972#38989', 0) <> 0)'#9#9'/* '#12487#12540#12479#20316#25104#29992' */'
      
        '--'#9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20837#37329#38989', 0) + ISNULL(B.'#35519#25972#38989', 0)) + ' +
        'ISNULL(C.'#22770#19978#38989', 0) + ISNULL(C.'#28040#36027#31246#38989', 0) <> 0'#9'/* '#30330#34892#29992' */'
      '--AND'#9'A.'#35531#27714#20808#12467#12540#12489' BETWEEN '#39'000058'#39' AND '#39'000058'#39
      '--AND'#9'A.'#20107#21209#25285#24403#31038#21729#12467#12540#12489' = 1'
      ''
      'ORDER BY'
      
        #9'A.'#20107#21209#25285#24403#31038#21729#12467#12540#12489', A.'#35531#27714#20808#12467#12540#12489', D.'#12487#12540#12479#21306#20998', D.'#24471#24847#20808#12467#12540#12489', D.'#34920#31034#38918', D.'#22770#19978#26085#20184', D.'#21462#24341'ID' +
        ', D.'#26126#32048'NO'
      '')
    Left = 12
    Top = 16
    object Q_SeikyuDSDesigner: TBCDField
      FieldName = #32224#20999#26085
      ReadOnly = True
      DisplayFormat = '0000/00/00'
      Precision = 18
      Size = 0
    end
    object Q_SeikyuDSDesigner2: TBCDField
      FieldName = #38283#22987#26085#20184
      ReadOnly = True
      DisplayFormat = '0000/00/00'
      Precision = 18
      Size = 0
    end
    object Q_SeikyuDSDesigner3: TBCDField
      FieldName = #32066#20102#26085#20184
      ReadOnly = True
      DisplayFormat = '0000/00/00'
      Precision = 18
      Size = 0
    end
    object Q_SeikyuID: TIntegerField
      FieldName = #35531#27714#20808'ID'
    end
    object Q_SeikyuDSDesigner4: TStringField
      FieldName = #35531#27714#20808#12467#12540#12489
      Size = 6
    end
    object Q_SeikyuDSDesigner5: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object Q_SeikyuDSDesigner6: TStringField
      FieldName = #33258#21205#25391#26367#12467#12540#12489
      Size = 15
    end
    object Q_SeikyuDSDesigner7: TStringField
      FieldName = #37109#20415#30058#21495
      Size = 10
    end
    object Q_SeikyuDSDesigner1: TStringField
      FieldName = #20303#25152'1'
      Size = 50
    end
    object Q_SeikyuDSDesigner22: TStringField
      FieldName = #20303#25152'2'
      Size = 50
    end
    object Q_SeikyuDSDesigner8: TIntegerField
      FieldName = #25964#31216#21306#20998
    end
    object Q_SeikyuDSDesigner9: TStringField
      FieldName = #25964#31216#21306#20998#21517#31216
    end
    object Q_SeikyuDSDesigner10: TIntegerField
      FieldName = #27531#39640#34920#31034#21306#20998
    end
    object Q_SeikyuDSDesigner11: TIntegerField
      FieldName = #20837#37329#12469#12452#12488
    end
    object Q_SeikyuDSDesigner12: TIntegerField
      FieldName = #20837#37329#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_SeikyuDSDesigner13: TIntegerField
      FieldName = #20837#37329#26041#27861
    end
    object Q_SeikyuDSDesigner14: TStringField
      FieldName = #20837#37329#26041#27861#21517#31216
    end
    object Q_SeikyuDSDesigner15: TIntegerField
      FieldName = #21942#26989#25285#24403#31038#21729#12467#12540#12489
    end
    object Q_SeikyuDSDesigner16: TStringField
      FieldName = #21942#26989#25285#24403#31038#21729#21517#31216
      Size = 12
    end
    object Q_SeikyuDSDesigner17: TIntegerField
      FieldName = #20107#21209#25285#24403#31038#21729#12467#12540#12489
    end
    object Q_SeikyuDSDesigner18: TStringField
      FieldName = #20107#21209#25285#24403#31038#21729#21517#31216
      Size = 12
    end
    object Q_SeikyuDSDesigner19: TBCDField
      FieldName = #26376#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_SeikyuDSDesigner20: TIntegerField
      FieldName = #21069#22238#32224#20999#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_SeikyuDSDesigner21: TBCDField
      FieldName = #21069#22238#35531#27714#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_SeikyuDSDesigner23: TBCDField
      FieldName = #20837#37329#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner24: TBCDField
      FieldName = #35519#25972#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner25: TBCDField
      FieldName = #32368#36234#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner26: TBCDField
      FieldName = #22770#19978#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner27: TBCDField
      FieldName = #28040#36027#31246#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner28: TBCDField
      FieldName = #20170#22238#35531#27714#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuID5: TIntegerField
      FieldName = #21462#24341'ID'
      ReadOnly = True
    end
    object Q_SeikyuID3: TIntegerField
      FieldName = #21462#24341#26126#32048'ID'
      ReadOnly = True
    end
    object Q_SeikyuNO: TIntegerField
      FieldName = #26126#32048'NO'
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner29: TIntegerField
      FieldName = #12487#12540#12479#21306#20998
      ReadOnly = True
    end
    object Q_SeikyuID2: TIntegerField
      FieldName = #24471#24847#20808'ID'
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner30: TStringField
      FieldName = #24471#24847#20808#12467#12540#12489
      ReadOnly = True
      Size = 6
    end
    object Q_SeikyuDSDesigner31: TStringField
      FieldName = #24471#24847#20808#21517#31216
      ReadOnly = True
      Size = 50
    end
    object Q_SeikyuDSDesigner40: TStringField
      FieldName = #20214#21517
      ReadOnly = True
      Size = 50
    end
    object Q_SeikyuDSDesigner32: TIntegerField
      FieldName = #22770#19978#26085#20184
      ReadOnly = True
      DisplayFormat = '0000/00/00'
    end
    object Q_SeikyuID4: TIntegerField
      FieldName = #22770#19978#21697#30446'ID'
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner33: TStringField
      FieldName = #22770#19978#21697#30446#21517#31216
      ReadOnly = True
      Size = 40
    end
    object Q_SeikyuDSDesigner34: TBCDField
      FieldName = #22770#19978#25968#37327
      ReadOnly = True
      DisplayFormat = '#,##0.0##'
      Precision = 13
      Size = 3
    end
    object Q_SeikyuDSDesigner35: TIntegerField
      FieldName = #22770#19978#21336#20301#12467#12540#12489
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner36: TStringField
      FieldName = #22770#19978#21336#20301#21517#31216
      ReadOnly = True
      Size = 10
    end
    object Q_SeikyuDSDesigner37: TBCDField
      FieldName = #22770#19978#21336#20385
      ReadOnly = True
      DisplayFormat = '#,###.##'
      Precision = 10
      Size = 0
    end
    object Q_SeikyuDSDesigner38: TBCDField
      FieldName = #22770#19978#37329#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 19
      Size = 0
    end
    object Q_SeikyuDSDesigner39: TStringField
      FieldName = #22770#19978#20633#32771
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner41: TIntegerField
      FieldName = #22770#19978#20633#32771#34920#31034#21306#20998
      ReadOnly = True
    end
  end
end
