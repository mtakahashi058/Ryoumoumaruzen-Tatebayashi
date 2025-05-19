object SeikyushoYokoForm: TSeikyushoYokoForm
  Left = 190
  Top = 119
  Width = 1146
  Height = 850
  Caption = 'SeikyushoYokoForm'
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
    Top = 8
    Width = 1123
    Height = 794
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
    Page.Orientation = poLandscape
    Page.PaperSize = A4
    Page.Values = (
      100
      2100
      140
      2970
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
    object QRShape20: TQRShape
      Left = 30
      Top = 312
      Width = 1071
      Height = 445
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1177.39583333333
        79.375
        825.5
        2833.6875)
      Brush.Style = bsClear
      Pen.Width = 2
      Shape = qrsRectangle
    end
    object PageHeaderBand1: TQRBand
      Left = 30
      Top = 53
      Width = 1070
      Height = 284
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
        751.416666666667
        2831.04166666667)
      BandType = rbPageHeader
      object ColorShape: TQRShape
        Left = 433
        Top = 0
        Width = 203
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          68.7916666666667
          1145.64583333333
          0
          537.104166666667)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object QRShape12: TQRShape
        Left = 880
        Top = 190
        Width = 189
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          2328.33333333333
          502.708333333333
          500.0625)
        Pen.Width = 2
        Shape = qrsRectangle
      end
      object QRShape3: TQRShape
        Left = 0
        Top = 190
        Width = 777
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          0
          502.708333333333
          2055.8125)
        Pen.Width = 2
        Shape = qrsRectangle
      end
      object ColorShape1: TQRShape
        Left = 0
        Top = 190
        Width = 777
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          0
          502.708333333333
          2055.8125)
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
      object YubinDBLabel: TQRDBText
        Left = 84
        Top = 25
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
          66.1458333333333
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
        Left = 64
        Top = 25
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
          66.1458333333333
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
        Left = 1047
        Top = 4
        Width = 19
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2770.1875
          10.5833333333333
          50.2708333333333)
        Alignment = taRightJustify
        AlignToBand = False
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
      object KingakuLabel6: TQRLabel
        Left = 648
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          1714.5
          571.5
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
      object KingakuLabel1: TQRLabel
        Left = 1
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          2.64583333333333
          571.5
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
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
      object KingakuLabel2: TQRLabel
        Left = 129
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          341.3125
          571.5
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
      object KingakuLabel3: TQRLabel
        Left = 259
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          685.270833333333
          571.5
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
      object KingakuLabel4: TQRLabel
        Left = 388
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          1026.58333333333
          571.5
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
      object KingakuLabel5: TQRLabel
        Left = 518
        Top = 216
        Width = 105
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          1370.54166666667
          571.5
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
      object DateLabel: TQRLabel
        Left = 907
        Top = 4
        Width = 85
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2399.77083333333
          10.5833333333333
          224.895833333333)
        Alignment = taRightJustify
        AlignToBand = False
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
        Left = 433
        Top = 3
        Width = 203
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          1145.64583333333
          7.9375
          537.104166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = False
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
        Left = 858
        Top = 4
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2270.125
          10.5833333333333
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
      object ShameiLabel: TQRLabel
        Left = 764
        Top = 28
        Width = 278
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          2021.41666666667
          74.0833333333333
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
        Left = 764
        Top = 70
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          185.208333333333
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
        Left = 650
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1719.79166666667
          515.9375
          322.791666666667)
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
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          5.29166666666667
          515.9375
          322.791666666667)
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
        Left = 131
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          346.604166666667
          515.9375
          322.791666666667)
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
        Left = 261
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          690.5625
          515.9375
          322.791666666667)
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
        Left = 390
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1031.875
          515.9375
          322.791666666667)
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
        Left = 520
        Top = 195
        Width = 122
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1375.83333333333
          515.9375
          322.791666666667)
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
        Left = 255
        Top = 190
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          674.6875
          502.708333333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape7: TQRShape
        Left = 383
        Top = 190
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1013.35416666667
          502.708333333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape8: TQRShape
        Left = 515
        Top = 190
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1362.60416666667
          502.708333333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRShape9: TQRShape
        Left = 647
        Top = 190
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          1711.85416666667
          502.708333333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object QRLabel22: TQRLabel
        Left = 282
        Top = 112
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
          296.333333333333
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
        Top = 112
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
          296.333333333333
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
        Left = 0
        Top = 168
        Width = 743
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          444.5
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
        Left = 880
        Top = 190
        Width = 189
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          60.8541666666667
          2328.33333333333
          502.708333333333
          500.0625)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object KagamiLabel07: TQRLabel
        Left = 880
        Top = 194
        Width = 187
        Height = 16
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          42.3333333333333
          2328.33333333333
          513.291666666667
          494.770833333333)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20170#22238#35531#27714#38989
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 11
      end
      object KingakuLabel7: TQRLabel
        Left = 922
        Top = 215
        Width = 105
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          2439.45833333333
          568.854166666667
          277.8125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '#,###,###,###'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 12
      end
      object SeikyumotoLabel03: TQRLabel
        Left = 764
        Top = 86
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          227.541666666667
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
        Left = 764
        Top = 102
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          269.875
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
        Left = 764
        Top = 119
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          314.854166666667
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
        Left = 764
        Top = 135
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          357.1875
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
        Left = 764
        Top = 151
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          399.520833333333
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
        Left = 764
        Top = 168
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          444.5
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
        Left = 764
        Top = 54
        Width = 304
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2021.41666666667
          142.875
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
        Top = 258
        Width = 1071
        Height = 27
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          71.4375
          0
          682.625
          2833.6875)
        Brush.Color = 16759671
        Pen.Color = clGray
        Shape = qrsRectangle
      end
      object MeiTitleLabel01: TQRLabel
        Left = 4
        Top = 263
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
          695.854166666667
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
        Left = 52
        Top = 263
        Width = 351
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          137.583333333333
          695.854166666667
          928.6875)
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
        Left = 422
        Top = 263
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1116.54166666667
          695.854166666667
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
        Left = 523
        Top = 263
        Width = 49
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1383.77083333333
          695.854166666667
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
        Left = 580
        Top = 263
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
          695.854166666667
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
        Left = 680
        Top = 263
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1799.16666666667
          695.854166666667
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
        Left = 780
        Top = 263
        Width = 285
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2063.75
          695.854166666667
          754.0625)
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
        Left = 0
        Top = 241
        Width = 743
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          0
          637.645833333333
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
        Top = 91
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
          240.770833333333
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
        Left = 127
        Top = 190
        Width = 2
        Height = 46
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          121.708333333333
          336.020833333333
          502.708333333333
          5.29166666666667)
        Pen.Width = 2
        Shape = qrsVertLine
      end
      object Add1DBLabel: TQRDBText
        Left = 64
        Top = 48
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
          127
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
        Top = 68
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
          179.916666666667
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
    object QRShape22: TQRShape
      Left = 30
      Top = 335
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        886.354166666667
        2833.6875)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape23: TQRShape
      Left = 30
      Top = 375
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        992.1875
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape24: TQRShape
      Left = 30
      Top = 395
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1045.10416666667
        2833.6875)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape25: TQRShape
      Left = 30
      Top = 415
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1098.02083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape26: TQRShape
      Left = 30
      Top = 435
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1150.9375
        2833.6875)
      Brush.Color = 16119285
      Shape = qrsHorLine
    end
    object QRShape27: TQRShape
      Left = 30
      Top = 455
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1203.85416666667
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape28: TQRShape
      Left = 30
      Top = 475
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1256.77083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape29: TQRShape
      Left = 30
      Top = 495
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1309.6875
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape30: TQRShape
      Left = 30
      Top = 515
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1362.60416666667
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape31: TQRShape
      Left = 30
      Top = 535
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1415.52083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape32: TQRShape
      Left = 30
      Top = 555
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1468.4375
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape33: TQRShape
      Left = 30
      Top = 575
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1521.35416666667
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape34: TQRShape
      Left = 30
      Top = 595
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1574.27083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape35: TQRShape
      Left = 30
      Top = 615
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1627.1875
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape36: TQRShape
      Left = 30
      Top = 635
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1680.10416666667
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape37: TQRShape
      Left = 30
      Top = 655
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1733.02083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape38: TQRShape
      Left = 30
      Top = 675
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1785.9375
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 30
      Top = 695
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1838.85416666667
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRShape39: TQRShape
      Left = 30
      Top = 715
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1891.77083333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object QRImage2: TQRImage
      Left = 23
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
        60.8541666666667
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
      Left = 1102
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
        2915.70833333333
        1113.89583333333
        10.5833333333333)
      Picture.Data = {
        07544269746D6170C6050000424DC60500000000000036040000280000001400
        000014000000010008000000000090010000120B0000120B0000000100000001
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
      Top = 760
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
        2010.83333333333
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
      Top = 337
      Width = 1070
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
        2831.04166666667)
      Expression = 'Q_Seikyu.'#35531#27714#20808#12467#12540#12489
      FooterBand = GroupFooterSeikyu
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel10: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 357
      Width = 1070
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
        2831.04166666667)
      Expression = 'Q_Seikyu.G1'
      FooterBand = GroupFooter1
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel11: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 377
      Width = 1070
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
        2831.04166666667)
      FooterBand = GroupFooter2
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel12: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 457
      Width = 1070
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
        2831.04166666667)
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
        Left = 423
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
          1119.1875
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
        Left = 527
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
          1394.35416666667
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
        Left = 582
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
          1539.875
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
        Left = 681
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
          1801.8125
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
        Width = 351
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
          928.6875)
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
        Left = 780
        Top = 3
        Width = 285
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          2063.75
          7.9375
          754.0625)
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
        Left = 1020
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
          2698.75
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
      Top = 557
      Width = 1070
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
        2831.04166666667)
      BandType = rbGroupFooter
      object ShokeiLabel1: TQRLabel
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
      object QRExpr5: TQRExpr
        Left = 681
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
          1801.8125
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
      object QRLabel8: TQRLabel
        Left = 610
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
          1613.95833333333
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
    object QRShape1: TQRShape
      Left = 30
      Top = 735
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        1944.6875
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object GroupHeader3: TQRGroup
      Left = 30
      Top = 397
      Width = 1070
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
        2831.04166666667)
      FooterBand = GroupFooter3
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel13: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 417
      Width = 1070
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
        2831.04166666667)
      FooterBand = GroupFooter4
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel14: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 437
      Width = 1070
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
        2831.04166666667)
      FooterBand = GroupFooter5
      Master = QuickRep
      ReprintOnNewPage = False
      object QRLabel15: TQRLabel
        Left = 1020
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
          2698.75
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
      Top = 537
      Width = 1070
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
        2831.04166666667)
      BandType = rbGroupFooter
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
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr4: TQRExpr
        Left = 681
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
          1801.8125
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
      object QRLabel7: TQRLabel
        Left = 610
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
          1613.95833333333
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
    object GroupFooter3: TQRBand
      Left = 30
      Top = 517
      Width = 1070
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
        2831.04166666667)
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
        Left = 681
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
          1801.8125
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
        Left = 610
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
          1613.95833333333
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
      Top = 497
      Width = 1070
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
        2831.04166666667)
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
        Left = 681
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
          1801.8125
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
        Left = 610
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
          1613.95833333333
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
      Top = 477
      Width = 1070
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
        2831.04166666667)
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
        Left = 681
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
          1801.8125
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
        Left = 610
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
          1613.95833333333
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
    object QRShape13: TQRShape
      Left = 74
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        195.791666666667
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape15: TQRShape
      Left = 547
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        1447.27083333333
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape16: TQRShape
      Left = 606
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        1603.375
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape17: TQRShape
      Left = 705
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        1865.3125
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape18: TQRShape
      Left = 805
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        2129.89583333333
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRShape21: TQRShape
      Left = 447
      Top = 312
      Width = 2
      Height = 444
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1174.75
        1182.6875
        825.5
        5.29166666666667)
      Pen.Width = 2
      Shape = qrsVertLine
    end
    object QRImage3: TQRImage
      Left = 879
      Top = 45
      Width = 4
      Height = 4
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        10.5833333333333
        2325.6875
        119.0625
        10.5833333333333)
      Picture.Data = {
        07544269746D6170C6050000424DC60500000000000036040000280000001400
        000014000000010008000000000090010000120B0000120B0000000100000001
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
    object QRShape2: TQRShape
      Left = 30
      Top = 355
      Width = 1071
      Height = 2
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        5.29166666666667
        79.375
        939.270833333333
        2833.6875)
      Brush.Color = 15461355
      Shape = qrsHorLine
    end
    object GroupFooterSeikyu: TQRBand
      Left = 30
      Top = 577
      Width = 1070
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
        2831.04166666667)
      BandType = rbGroupFooter
      object QRLabel1: TQRLabel
        Left = 610
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
          1613.95833333333
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
        Left = 610
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
          1613.95833333333
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
        Left = 610
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
          1613.95833333333
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
        Left = 681
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
          1801.8125
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
        Left = 681
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
          1801.8125
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
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object UriageGokeiLabel: TQRLabel
        Left = 681
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
          1801.8125
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
  end
end
