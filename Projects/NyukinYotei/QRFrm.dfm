object QRForm: TQRForm
  Left = 97
  Top = 120
  Width = 1136
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
    DataSet = Query
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
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
      80
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
    object PageHeaderBand1: TQRBand
      Left = 30
      Top = 38
      Width = 1074
      Height = 75
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
        198.4375
        2841.625)
      BandType = rbPageHeader
      object QRLabel1: TQRLabel
        Left = 464
        Top = 0
        Width = 145
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1227.66666666667
          0
          383.645833333333)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '*** '#20837#37329#20104#23450#34920' ***'
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
        Left = 981
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
          2595.5625
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
      object QRShape1: TQRShape
        Left = 0
        Top = 38
        Width = 1074
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          100.541666666667
          2841.625)
        Shape = qrsHorLine
      end
      object QRShape2: TQRShape
        Left = 0
        Top = 73
        Width = 1074
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          193.145833333333
          2841.625)
        Shape = qrsHorLine
      end
      object QRLabel3: TQRLabel
        Left = 4
        Top = 24
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          63.5
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20986#21147#31684#22258#65306
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object RangeLabel: TQRLabel
        Left = 76
        Top = 24
        Width = 97
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          201.083333333333
          63.5
          256.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #65308#20986#21147#31684#22258#20869#23481#65310
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel2: TQRLabel
        Left = 4
        Top = 58
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          153.458333333333
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #24471#24847#20808#21517#31216
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel4: TQRLabel
        Left = 168
        Top = 58
        Width = 25
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          444.5
          153.458333333333
          66.1458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #32224#26085
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel7: TQRLabel
        Left = 200
        Top = 58
        Width = 37
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          529.166666666667
          153.458333333333
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #25903#25173#26085
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel10: TQRLabel
        Left = 272
        Top = 58
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          719.666666666667
          153.458333333333
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #25903#25173#26041#27861
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel13: TQRLabel
        Left = 320
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          846.666666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '6'#12534#26376#20197#21069#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel14: TQRLabel
        Left = 404
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1068.91666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '5'#12534#26376#21069#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel15: TQRLabel
        Left = 488
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1291.16666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '4'#12534#26376#21069#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel16: TQRLabel
        Left = 572
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1513.41666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '3'#12534#26376#21069#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel17: TQRLabel
        Left = 656
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1735.66666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21069#12293#26376#20998#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel26: TQRLabel
        Left = 740
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21069#26376#20998#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel27: TQRLabel
        Left = 824
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2180.16666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #24403#26376#20998#27531
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel28: TQRLabel
        Left = 908
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2402.41666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #22770#25499#21512#35336
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel29: TQRLabel
        Left = 992
        Top = 58
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2624.66666666667
          153.458333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #22238#21454#20104#23450#38989
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel1: TQRLabel
        Left = 320
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          846.666666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = '<= yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel2: TQRLabel
        Left = 404
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1068.91666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel3: TQRLabel
        Left = 488
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1291.16666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel4: TQRLabel
        Left = 572
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1513.41666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel5: TQRLabel
        Left = 656
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1735.66666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel6: TQRLabel
        Left = 740
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object MonthLabel7: TQRLabel
        Left = 824
        Top = 42
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2180.16666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = 'yyyy/mm'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object DetailBand1: TQRBand
      Left = 30
      Top = 133
      Width = 1074
      Height = 36
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
        95.25
        2841.625)
      BandType = rbDetail
      object QRShape3: TQRShape
        Left = 0
        Top = 34
        Width = 1074
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          89.9583333333333
          2841.625)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object QRDBText1: TQRDBText
        Left = 4
        Top = 4
        Width = 157
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          10.5833333333333
          415.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#21517#31216'1'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText2: TQRDBText
        Left = 4
        Top = 20
        Width = 157
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          52.9166666666667
          415.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#21517#31216'2'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText3: TQRDBText
        Left = 168
        Top = 4
        Width = 25
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          444.5
          10.5833333333333
          66.1458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #32224#26085#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText4: TQRDBText
        Left = 200
        Top = 4
        Width = 73
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          529.166666666667
          10.5833333333333
          193.145833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#26085#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText5: TQRDBText
        Left = 272
        Top = 4
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          719.666666666667
          10.5833333333333
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#26041#27861#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan6: TQRDBText
        Left = 320
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          846.666666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'6'
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
      object QRDBTextZan5: TQRDBText
        Left = 404
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1068.91666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'5'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan4: TQRDBText
        Left = 488
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1291.16666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'4'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan3: TQRDBText
        Left = 572
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1513.41666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'3'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan2: TQRDBText
        Left = 656
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1735.66666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'2'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan1: TQRDBText
        Left = 740
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'1'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBTextZan0: TQRDBText
        Left = 824
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2180.16666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22770#25499#27531'0'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText14: TQRDBText
        Left = 908
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2402.41666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35531#27714'0'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText15: TQRDBText
        Left = 992
        Top = 4
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2624.66666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22238#21454#20104#23450#38989
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText16: TQRDBText
        Left = 128
        Top = 20
        Width = 33
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          338.666666666667
          52.9166666666667
          87.3125)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsItalic]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 8
      end
    end
    object QRGroup1: TQRGroup
      Left = 30
      Top = 113
      Width = 1074
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
        2841.625)
      Expression = 'Query.'#20837#37329#20104#23450#26085
      Master = QuickRep
      ReprintOnNewPage = False
      object QRShape4: TQRShape
        Left = 0
        Top = 0
        Width = 1074
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          0
          0
          2841.625)
        Brush.Color = 15658734
        Pen.Style = psClear
        Shape = qrsRectangle
      end
      object QRLabel12: TQRLabel
        Left = 4
        Top = 3
        Width = 85
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          7.9375
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #65308#20837#37329#20104#23450#26085#65310
        Color = clWhite
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRDBText6: TQRDBText
        Left = 108
        Top = 3
        Width = 67
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          285.75
          7.9375
          177.270833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#20104#23450#26085
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRShape5: TQRShape
        Left = 0
        Top = 18
        Width = 1074
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
          2841.625)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
    object SummaryBand1: TQRBand
      Left = 30
      Top = 169
      Width = 1074
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
        2841.625)
      BandType = rbSummary
      object QRShape6: TQRShape
        Left = 0
        Top = 0
        Width = 1074
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          0
          0
          2841.625)
        Brush.Color = 15658734
        Pen.Style = psClear
        Shape = qrsRectangle
      end
      object QRLabel5: TQRLabel
        Left = 4
        Top = 3
        Width = 85
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          10.5833333333333
          7.9375
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #65308#12288#21512#12288#35336#12288#65310
        Color = clWhite
        Transparent = True
        WordWrap = True
        FontSize = 9
      end
      object QRExpr1: TQRExpr
        Left = 320
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          846.666666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'6)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr2: TQRExpr
        Left = 404
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1068.91666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'5)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr3: TQRExpr
        Left = 488
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1291.16666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'4)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr4: TQRExpr
        Left = 572
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1513.41666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'3)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr5: TQRExpr
        Left = 656
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1735.66666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'2)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr6: TQRExpr
        Left = 740
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1957.91666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'1)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr7: TQRExpr
        Left = 824
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2180.16666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22770#25499#27531'0)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr8: TQRExpr
        Left = 908
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2402.41666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#35531#27714'0)'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRExpr9: TQRExpr
        Left = 992
        Top = 3
        Width = 79
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2624.66666666667
          7.9375
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = True
        WordWrap = True
        Expression = 'SUM(Query.'#22238#21454#20104#23450#38989')'
        Mask = '#,##0'
        FontSize = 9
      end
      object QRShape8: TQRShape
        Left = 0
        Top = 18
        Width = 1074
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
          2841.625)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
    end
  end
  object Query_: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    OnCalcFields = Query_CalcFields
    Parameters = <
      item
        Name = 'DT_FROM6'
        DataType = ftBCD
        Size = -1
        Value = 200909010000c
      end
      item
        Name = 'DT_TO6'
        DataType = ftBCD
        Size = -1
        Value = 200909300000c
      end
      item
        Name = 'DT_FROM5'
        DataType = ftBCD
        Size = -1
        Value = 200910010000c
      end
      item
        Name = 'DT_TO5'
        DataType = ftBCD
        Size = -1
        Value = 200910310000c
      end
      item
        Name = 'DT_FROM4'
        DataType = ftBCD
        Size = -1
        Value = 200911010000c
      end
      item
        Name = 'DT_TO4'
        DataType = ftBCD
        Size = -1
        Value = 200911310000c
      end
      item
        Name = 'DT_FROM3'
        DataType = ftBCD
        Size = -1
        Value = 200912010000c
      end
      item
        Name = 'DT_TO3'
        DataType = ftBCD
        Size = -1
        Value = 200912310000c
      end
      item
        Name = 'DT_FROM2'
        DataType = ftBCD
        Size = -1
        Value = 201001010000c
      end
      item
        Name = 'DT_TO2'
        DataType = ftBCD
        Size = -1
        Value = 201001310000c
      end
      item
        Name = 'DT_FROM1'
        DataType = ftBCD
        Size = -1
        Value = 201002010000c
      end
      item
        Name = 'DT_TO1'
        DataType = ftBCD
        Size = -1
        Value = 201002280000c
      end
      item
        Name = 'DT_FROM'
        DataType = ftBCD
        Size = -1
        Value = 201003010000c
      end
      item
        Name = 'DT_TO'
        DataType = ftBCD
        Size = -1
        Value = 201003310000c
      end>
    SQL.Strings = (
      'DECLARE @DT_FROM6 [DECIMAL]'
      'DECLARE @DT_TO6   [DECIMAL]'
      'DECLARE @DT_FROM5 [DECIMAL]'
      'DECLARE @DT_TO5   [DECIMAL]'
      'DECLARE @DT_FROM4 [DECIMAL]'
      'DECLARE @DT_TO4   [DECIMAL]'
      'DECLARE @DT_FROM3 [DECIMAL]'
      'DECLARE @DT_TO3   [DECIMAL]'
      'DECLARE @DT_FROM2 [DECIMAL]'
      'DECLARE @DT_TO2   [DECIMAL]'
      'DECLARE @DT_FROM1 [DECIMAL]'
      'DECLARE @DT_TO1   [DECIMAL]'
      'DECLARE @DT_FROM  [DECIMAL]'
      'DECLARE @DT_TO    [DECIMAL]'
      'SET @DT_FROM6 = :DT_FROM6'
      'SET @DT_TO6   = :DT_TO6'
      'SET @DT_FROM5 = :DT_FROM5'
      'SET @DT_TO5   = :DT_TO5'
      'SET @DT_FROM4 = :DT_FROM4'
      'SET @DT_TO4   = :DT_TO4'
      'SET @DT_FROM3 = :DT_FROM3'
      'SET @DT_TO3   = :DT_TO3'
      'SET @DT_FROM2 = :DT_FROM2'
      'SET @DT_TO2   = :DT_TO2'
      'SET @DT_FROM1 = :DT_FROM1'
      'SET @DT_TO1   = :DT_TO1'
      'SET @DT_FROM  = :DT_FROM'
      'SET @DT_TO    = :DT_TO'
      ''
      'SELECT'
      #9'TK.'#24471#24847#20808'ID,'
      #9'TK.'#24471#24847#20808#12467#12540#12489','
      #9'TK.'#24471#24847#20808#21517#31216', TK.'#24471#24847#20808#30053#31216','
      #9'TK.'#32224#26085','
      
        #9'CASE WHEN TK.'#32224#26085' = 99 THEN '#39#26411#39' ELSE CAST(TK.'#32224#26085' AS VARCHAR) END +' +
        ' '#39#26085#39' AS '#32224#26085#21517#31216','
      #9'TK.'#20837#37329#12469#12452#12488', TK.'#20837#37329#26085','
      
        #9'TK.'#20837#37329#12469#12452#12488#21517#31216' + CASE WHEN TK.'#20837#37329#26085' = 99 THEN '#39#26411#39' ELSE CAST(TK.'#20837#37329#26085' AS' +
        ' VARCHAR) END + '#39#26085#39' AS '#20837#37329#26085#21517#31216','
      #9'TK.'#20837#37329#26041#27861', TK.'#20837#37329#26041#27861#21517#31216','
      ''
      
        #9'ISNULL(B6.'#32224#20999#26085', ISNULL(B5.'#32224#20999#26085', ISNULL(B4.'#32224#20999#26085', ISNULL(B3.'#32224#20999#26085', ISN' +
        'ULL(B2.'#32224#20999#26085', ISNULL(B1.'#32224#20999#26085', ISNULL(B0.'#32224#20999#26085', 0))))))) AS '#32224#20999#26085','
      #9'ISNULL(B6.'#20170#22238#35531#27714#38989', 0) AS '#27531#39640'6,'
      #9'ISNULL(B5.'#22770#19978'5, 0) AS '#22770#19978'5,'
      #9'ISNULL(B4.'#22770#19978'4, 0) AS '#22770#19978'4,'
      #9'ISNULL(B3.'#22770#19978'3, 0) AS '#22770#19978'3,'
      #9'ISNULL(B2.'#22770#19978'2, 0) AS '#22770#19978'2,'
      #9'ISNULL(B1.'#22770#19978'1, 0) AS '#22770#19978'1,'
      #9'ISNULL(B0.'#22770#19978'0, 0) AS '#22770#19978'0,'
      #9'ISNULL(B0.'#35531#27714'0, 0) AS '#35531#27714'0,'
      #9'ISNULL(NY.'#20837#37329#20104#23450#38989', 0) AS '#20837#37329#20104#23450#38989','
      #9'ISNULL(NY.'#20837#37329#20104#23450#26085', 0) AS '#20837#37329#20104#23450#26085
      ''
      'FROM'
      #9'V_'#24471#24847#20808' AS TK'
      ''
      #9'/* 6'#12534#26376#20197#21069' */'
      #9'LEFT OUTER JOIN ('
      #9#9'SELECT'#9'SK.'#35531#27714#20808'ID, '#20170#22238#35531#27714#38989', SK.'#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714' AS SK'
      #9#9'RIGHT OUTER JOIN ('
      
        #9#9#9'SELECT'#9'MAX('#32224#20999#26085') AS '#32224#20999#26085', '#35531#27714#20808'ID FROM D_'#35531#27714' WHERE '#32224#20999#26085' BETWEEN @DT' +
        '_FROM6 AND @DT_TO6 GROUP BY '#35531#27714#20808'ID'
      #9#9#9') AS M6 ON SK.'#32224#20999#26085' = M6.'#32224#20999#26085' AND SK.'#35531#27714#20808'ID = M6.'#35531#27714#20808'ID'
      #9') AS B6 ON TK.'#24471#24847#20808'ID = B6.'#35531#27714#20808'ID'
      ''
      #9'/* 5'#12534#26376#21069' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'5, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM5 AND @DT_TO5'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B5 ON TK.'#24471#24847#20808'ID = B5.'#35531#27714#20808'ID'
      ''
      #9'/* 4'#12534#26376#21069' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'4, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM4 AND @DT_TO4'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B4 ON TK.'#24471#24847#20808'ID = B4.'#35531#27714#20808'ID'
      ''
      #9'/* 3'#12534#26376#21069' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'3, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM3 AND @DT_TO3'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B3 ON TK.'#24471#24847#20808'ID = B3.'#35531#27714#20808'ID'
      ''
      #9'/* 2'#12534#26376#21069' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'2, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE '#32224#20999#26085' BETWEEN @DT_FROM2 AND @DT_TO2'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B2 ON TK.'#24471#24847#20808'ID = B2.'#35531#27714#20808'ID'
      ''
      #9'/* '#21069#26376' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'1, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM1 AND @DT_TO1'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B1 ON TK.'#24471#24847#20808'ID = B1.'#35531#27714#20808'ID'
      ''
      #9'/* '#24403#26376' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) A' +
        'S '#22770#19978'0, MAX('#20170#22238#35531#27714#38989') AS '#35531#27714'0, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM AND @DT_TO'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS B0 ON TK.'#24471#24847#20808'ID = B0.'#35531#27714#20808'ID'
      ''
      #9'/* '#24403#26376#20837#37329#20104#23450' */'
      #9'LEFT OUTER JOIN ('
      
        #9#9'SELECT'#9#35531#27714#20808'ID, MAX('#20837#37329#20104#23450#26085') AS '#20837#37329#20104#23450#26085', ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISN' +
        'ULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#20837#37329#20104#23450#38989
      #9#9'FROM'#9'D_'#35531#27714
      #9#9'WHERE'#9#20837#37329#20104#23450#26085' BETWEEN @DT_FROM AND @DT_TO'
      #9#9'GROUP BY '#35531#27714#20808'ID'
      #9') AS NY ON TK.'#24471#24847#20808'ID = NY.'#35531#27714#20808'ID'
      ''
      'WHERE'
      #9'TK.'#29694#25499#21306#20998' = 1'
      'AND'
      #9'TK.'#24471#24847#20808'ID = TK.'#35531#27714#20808'ID'
      'AND'
      #9'('
      #9#9'ISNULL(B6.'#20170#22238#35531#27714#38989', 0) <> 0 OR'
      #9#9'ISNULL(B5.'#22770#19978'5, 0)      <> 0 OR'
      #9#9'ISNULL(B4.'#22770#19978'4, 0)      <> 0 OR'
      #9#9'ISNULL(B3.'#22770#19978'3, 0)      <> 0 OR'
      #9#9'ISNULL(B2.'#22770#19978'2, 0)      <> 0 OR'
      #9#9'ISNULL(B1.'#22770#19978'1, 0)      <> 0 OR'
      #9#9'ISNULL(B0.'#22770#19978'0, 0)      <> 0'
      #9')'
      ''
      '-- AND TK.'#24471#24847#20808#12467#12540#12489' IN (1, 2, 3)'
      ''
      'ORDER BY'
      #9'NY.'#20837#37329#20104#23450#26085', TK.'#32224#26085', TK.'#20837#37329#12469#12452#12488', TK.'#20837#37329#26085', TK.'#24471#24847#20808#12467#12540#12489
      '')
    Left = 20
    Top = 16
    object Query_ID: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Query_DSDesigner: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Query_DSDesigner2: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Query_DSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Query_DSDesigner4: TIntegerField
      FieldName = #32224#26085
    end
    object Query_DSDesigner5: TStringField
      DisplayWidth = 20
      FieldName = #32224#26085#21517#31216
      ReadOnly = True
      Size = 32
    end
    object Query_DSDesigner6: TIntegerField
      FieldName = #20837#37329#12469#12452#12488
    end
    object Query_DSDesigner7: TIntegerField
      FieldName = #20837#37329#26085
    end
    object Query_DSDesigner8: TStringField
      FieldName = #20837#37329#26085#21517#31216
      ReadOnly = True
      Size = 52
    end
    object Query_DSDesigner9: TIntegerField
      FieldName = #20837#37329#26041#27861
    end
    object Query_DSDesigner10: TStringField
      FieldName = #20837#37329#26041#27861#21517#31216
    end
    object Query_DSDesigner17: TIntegerField
      FieldName = #32224#20999#26085
      ReadOnly = True
    end
    object Query_DSDesigner62: TBCDField
      FieldName = #27531#39640'6'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Query_DSDesigner52: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'5'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner42: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'4'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner32: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'3'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner22: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'2'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner1: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'1'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner0: TBCDField
      DisplayWidth = 10
      FieldName = #22770#19978'0'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner02: TBCDField
      DisplayWidth = 10
      FieldName = #35531#27714'0'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Query_DSDesigner15: TBCDField
      DisplayWidth = 10
      FieldName = #20837#37329#20104#23450#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object Query_DSDesigner16: TIntegerField
      FieldName = #20837#37329#20104#23450#26085
      ReadOnly = True
      DisplayFormat = '0000/00/00;----------;----------'
    end
    object Query_StringField1: TStringField
      FieldKind = fkCalculated
      FieldName = #24471#24847#20808#21517#31216'1'
      Size = 26
      Calculated = True
    end
    object Query_StringField2: TStringField
      FieldKind = fkCalculated
      FieldName = #24471#24847#20808#21517#31216'2'
      Size = 26
      Calculated = True
    end
    object Query_Field6: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'6'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field5: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'5'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field4: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'4'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field3: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'3'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field2: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'2'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field1: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'1'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field0: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'0'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object Query_Field: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22238#21454#20104#23450#38989
      DisplayFormat = '#,##0'
      Calculated = True
    end
  end
  object Query: TADODataSet
    Connection = DM.ADOConnection
    OnCalcFields = QueryCalcFields
    CommandText = 
      'DECLARE @DT_FROM6 [DECIMAL]'#13#10'DECLARE @DT_TO6   [DECIMAL]'#13#10'DECLAR' +
      'E @DT_FROM5 [DECIMAL]'#13#10'DECLARE @DT_TO5   [DECIMAL]'#13#10'DECLARE @DT_' +
      'FROM4 [DECIMAL]'#13#10'DECLARE @DT_TO4   [DECIMAL]'#13#10'DECLARE @DT_FROM3 ' +
      '[DECIMAL]'#13#10'DECLARE @DT_TO3   [DECIMAL]'#13#10'DECLARE @DT_FROM2 [DECIM' +
      'AL]'#13#10'DECLARE @DT_TO2   [DECIMAL]'#13#10'DECLARE @DT_FROM1 [DECIMAL]'#13#10'D' +
      'ECLARE @DT_TO1   [DECIMAL]'#13#10'DECLARE @DT_FROM  [DECIMAL]'#13#10'DECLARE' +
      ' @DT_TO    [DECIMAL]'#13#10'SET @DT_FROM6 = :DT_FROM6'#13#10'SET @DT_TO6   =' +
      ' :DT_TO6'#13#10'SET @DT_FROM5 = :DT_FROM5'#13#10'SET @DT_TO5   = :DT_TO5'#13#10'SE' +
      'T @DT_FROM4 = :DT_FROM4'#13#10'SET @DT_TO4   = :DT_TO4'#13#10'SET @DT_FROM3 ' +
      '= :DT_FROM3'#13#10'SET @DT_TO3   = :DT_TO3'#13#10'SET @DT_FROM2 = :DT_FROM2'#13 +
      #10'SET @DT_TO2   = :DT_TO2'#13#10'SET @DT_FROM1 = :DT_FROM1'#13#10'SET @DT_TO1' +
      '   = :DT_TO1'#13#10'SET @DT_FROM  = :DT_FROM'#13#10'SET @DT_TO    = :DT_TO'#13#10 +
      #13#10'SELECT'#13#10#9'TK.'#24471#24847#20808'ID,'#13#10#9'TK.'#24471#24847#20808#12467#12540#12489','#13#10#9'TK.'#24471#24847#20808#21517#31216', TK.'#24471#24847#20808#30053#31216','#13#10#9'TK.'#32224#26085',' +
      #13#10#9'CASE WHEN TK.'#32224#26085' = 99 THEN '#39#26411#39' ELSE CAST(TK.'#32224#26085' AS VARCHAR) END' +
      ' + '#39#26085#39' AS '#32224#26085#21517#31216','#13#10#9'TK.'#20837#37329#12469#12452#12488', TK.'#20837#37329#26085','#13#10#9'TK.'#20837#37329#12469#12452#12488#21517#31216' + CASE WHEN TK.' +
      #20837#37329#26085' = 99 THEN '#39#26411#39' ELSE CAST(TK.'#20837#37329#26085' AS VARCHAR) END + '#39#26085#39' AS '#20837#37329#26085#21517 +
      #31216','#13#10#9'TK.'#20837#37329#26041#27861', TK.'#20837#37329#26041#27861#21517#31216','#13#10#13#10#9'ISNULL(B6.'#32224#20999#26085', ISNULL(B5.'#32224#20999#26085', ISNUL' +
      'L(B4.'#32224#20999#26085', ISNULL(B3.'#32224#20999#26085', ISNULL(B2.'#32224#20999#26085', ISNULL(B1.'#32224#20999#26085', ISNULL(B0' +
      '.'#32224#20999#26085', 0))))))) AS '#32224#20999#26085','#13#10#9'ISNULL(B6.'#20170#22238#35531#27714#38989', 0) AS '#27531#39640'6,'#13#10#9'ISNULL(B5' +
      '.'#22770#19978'5, 0) AS '#22770#19978'5,'#13#10#9'ISNULL(B4.'#22770#19978'4, 0) AS '#22770#19978'4,'#13#10#9'ISNULL(B3.'#22770#19978'3, 0)' +
      ' AS '#22770#19978'3,'#13#10#9'ISNULL(B2.'#22770#19978'2, 0) AS '#22770#19978'2,'#13#10#9'ISNULL(B1.'#22770#19978'1, 0) AS '#22770#19978'1,' +
      #13#10#9'ISNULL(B0.'#22770#19978'0, 0) AS '#22770#19978'0,'#13#10#9'ISNULL(B0.'#35531#27714'0, 0) AS '#35531#27714'0,'#13#10#9'ISNUL' +
      'L(NY.'#20837#37329#20104#23450#38989', 0) AS '#20837#37329#20104#23450#38989','#13#10#9'ISNULL(NY.'#20837#37329#20104#23450#26085', 0) AS '#20837#37329#20104#23450#26085#13#10#13#10'FROM'#13 +
      #10#9'V_'#24471#24847#20808' AS TK'#13#10#13#10#9'/* 6'#12534#26376#20197#21069' */'#13#10#9'LEFT OUTER JOIN ('#13#10#9#9'SELECT'#9'SK.'#35531 +
      #27714#20808'ID, '#20170#22238#35531#27714#38989', SK.'#32224#20999#26085#13#10#9#9'FROM'#9'D_'#35531#27714' AS SK'#13#10#9#9'RIGHT OUTER JOIN ('#13#10#9#9 +
      #9'SELECT'#9'MAX('#32224#20999#26085') AS '#32224#20999#26085', '#35531#27714#20808'ID FROM D_'#35531#27714' WHERE '#32224#20999#26085' BETWEEN @DT_F' +
      'ROM6 AND @DT_TO6 GROUP BY '#35531#27714#20808'ID'#13#10#9#9#9') AS M6 ON SK.'#32224#20999#26085' = M6.'#32224#20999#26085' A' +
      'ND SK.'#35531#27714#20808'ID = M6.'#35531#27714#20808'ID'#13#10#9') AS B6 ON TK.'#24471#24847#20808'ID = B6.'#35531#27714#20808'ID'#13#10#13#10#9'/* 5' +
      #12534#26376#21069' */'#13#10#9'LEFT OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0' +
      ') + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#22770#19978'5, MAX('#32224#20999#26085') AS '#32224#20999#26085#13#10#9#9'FROM'#9'D_'#35531#27714#13 +
      #10#9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM5 AND @DT_TO5'#13#10#9#9'GROUP BY '#35531#27714#20808'ID'#13#10#9')' +
      ' AS B5 ON TK.'#24471#24847#20808'ID = B5.'#35531#27714#20808'ID'#13#10#13#10#9'/* 4'#12534#26376#21069' */'#13#10#9'LEFT OUTER JOIN (' +
      #13#10#9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0)' +
      ' AS '#22770#19978'4, MAX('#32224#20999#26085') AS '#32224#20999#26085#13#10#9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_F' +
      'ROM4 AND @DT_TO4'#13#10#9#9'GROUP BY '#35531#27714#20808'ID'#13#10#9') AS B4 ON TK.'#24471#24847#20808'ID = B4.'#35531#27714 +
      #20808'ID'#13#10#13#10#9'/* 3'#12534#26376#21069' */'#13#10#9'LEFT OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(S' +
      'UM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#22770#19978'3, MAX('#32224#20999#26085') AS '#32224#20999#26085#13#10 +
      #9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM3 AND @DT_TO3'#13#10#9#9'GROUP ' +
      'BY '#35531#27714#20808'ID'#13#10#9') AS B3 ON TK.'#24471#24847#20808'ID = B3.'#35531#27714#20808'ID'#13#10#13#10#9'/* 2'#12534#26376#21069' */'#13#10#9'LEFT ' +
      'OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM' +
      '('#20170#22238#28040#36027#31246#38989'), 0) AS '#22770#19978'2, MAX('#32224#20999#26085') AS '#32224#20999#26085#13#10#9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHERE '#32224#20999#26085' B' +
      'ETWEEN @DT_FROM2 AND @DT_TO2'#13#10#9#9'GROUP BY '#35531#27714#20808'ID'#13#10#9') AS B2 ON TK.'#24471 +
      #24847#20808'ID = B2.'#35531#27714#20808'ID'#13#10#13#10#9'/* '#21069#26376' */'#13#10#9'LEFT OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID' +
      ', ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#22770#19978'1, MAX('#32224#20999#26085 +
      ') AS '#32224#20999#26085#13#10#9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM1 AND @DT_TO1' +
      #13#10#9#9'GROUP BY '#35531#27714#20808'ID'#13#10#9') AS B1 ON TK.'#24471#24847#20808'ID = B1.'#35531#27714#20808'ID'#13#10#13#10#9'/* '#24403#26376' */' +
      #13#10#9'LEFT OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID, ISNULL(SUM('#20170#22238#22770#19978#38989'), 0) + IS' +
      'NULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#22770#19978'0, MAX('#20170#22238#35531#27714#38989') AS '#35531#27714'0, MAX('#32224#20999#26085') AS '#32224#20999#26085#13 +
      #10#9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHERE'#9#32224#20999#26085' BETWEEN @DT_FROM AND @DT_TO'#13#10#9#9'GROUP B' +
      'Y '#35531#27714#20808'ID'#13#10#9') AS B0 ON TK.'#24471#24847#20808'ID = B0.'#35531#27714#20808'ID'#13#10#13#10#9'/* '#24403#26376#20837#37329#20104#23450' */'#13#10#9'LEFT' +
      ' OUTER JOIN ('#13#10#9#9'SELECT'#9#35531#27714#20808'ID, MAX('#20837#37329#20104#23450#26085') AS '#20837#37329#20104#23450#26085', ISNULL(SUM('#20170 +
      #22238#22770#19978#38989'), 0) + ISNULL(SUM('#20170#22238#28040#36027#31246#38989'), 0) AS '#20837#37329#20104#23450#38989#13#10#9#9'FROM'#9'D_'#35531#27714#13#10#9#9'WHER' +
      'E'#9#20837#37329#20104#23450#26085' BETWEEN @DT_FROM AND @DT_TO'#13#10#9#9'GROUP BY '#35531#27714#20808'ID'#13#10#9') AS NY ' +
      'ON TK.'#24471#24847#20808'ID = NY.'#35531#27714#20808'ID'#13#10#13#10'WHERE'#13#10#9'TK.'#29694#25499#21306#20998' = 1'#13#10'AND'#13#10#9'TK.'#24471#24847#20808'ID = ' +
      'TK.'#35531#27714#20808'ID'#13#10'AND'#13#10#9'('#13#10#9#9'ISNULL(B6.'#20170#22238#35531#27714#38989', 0) <> 0 OR'#13#10#9#9'ISNULL(B5.'#22770#19978 +
      '5, 0)      <> 0 OR'#13#10#9#9'ISNULL(B4.'#22770#19978'4, 0)      <> 0 OR'#13#10#9#9'ISNULL(B' +
      '3.'#22770#19978'3, 0)      <> 0 OR'#13#10#9#9'ISNULL(B2.'#22770#19978'2, 0)      <> 0 OR'#13#10#9#9'ISNU' +
      'LL(B1.'#22770#19978'1, 0)      <> 0 OR'#13#10#9#9'ISNULL(B0.'#22770#19978'0, 0)      <> 0'#13#10#9')'#13#10#13 +
      #10'-- AND TK.'#24471#24847#20808#12467#12540#12489' IN (1, 2, 3)'#13#10#13#10'ORDER BY'#13#10#9'NY.'#20837#37329#20104#23450#26085', TK.'#32224#26085', TK' +
      '.'#20837#37329#12469#12452#12488', TK.'#20837#37329#26085', TK.'#24471#24847#20808#12467#12540#12489#13#10
    Parameters = <
      item
        Name = 'DT_FROM6'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO6'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM5'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO5'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM4'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO4'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM3'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO3'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM2'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO2'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM1'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO1'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_FROM'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DT_TO'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end>
    Left = 68
    Top = 16
    object QueryID: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object QueryDSDesigner: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object QueryDSDesigner2: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object QueryDSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object QueryDSDesigner4: TIntegerField
      FieldName = #32224#26085
    end
    object QueryDSDesigner5: TStringField
      FieldName = #32224#26085#21517#31216
      ReadOnly = True
      Size = 32
    end
    object QueryDSDesigner6: TIntegerField
      FieldName = #20837#37329#12469#12452#12488
    end
    object QueryDSDesigner7: TIntegerField
      FieldName = #20837#37329#26085
    end
    object QueryDSDesigner8: TStringField
      FieldName = #20837#37329#26085#21517#31216
      ReadOnly = True
      Size = 52
    end
    object QueryDSDesigner9: TIntegerField
      FieldName = #20837#37329#26041#27861
    end
    object QueryDSDesigner10: TStringField
      FieldName = #20837#37329#26041#27861#21517#31216
    end
    object QueryDSDesigner11: TIntegerField
      FieldName = #32224#20999#26085
      ReadOnly = True
      DisplayFormat = '0000/00/00;#;#'
    end
    object QueryDSDesigner62: TBCDField
      FieldName = #27531#39640'6'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object QueryDSDesigner52: TBCDField
      FieldName = #22770#19978'5'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner42: TBCDField
      FieldName = #22770#19978'4'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner32: TBCDField
      FieldName = #22770#19978'3'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner22: TBCDField
      FieldName = #22770#19978'2'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner1: TBCDField
      FieldName = #22770#19978'1'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner0: TBCDField
      FieldName = #22770#19978'0'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner02: TBCDField
      FieldName = #35531#27714'0'
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object QueryDSDesigner12: TBCDField
      FieldName = #20837#37329#20104#23450#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner13: TIntegerField
      FieldName = #20837#37329#20104#23450#26085
      ReadOnly = True
      DisplayFormat = '0000/00/00;----/--/--;----/--/--'
    end
    object QueryStringField1: TStringField
      FieldKind = fkCalculated
      FieldName = #24471#24847#20808#21517#31216'1'
      Size = 26
      Calculated = True
    end
    object QueryStringField2: TStringField
      FieldKind = fkCalculated
      FieldName = #24471#24847#20808#21517#31216'2'
      Size = 26
      Calculated = True
    end
    object QueryField6: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'6'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField5: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'5'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField4: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'4'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField3: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'3'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField2: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'2'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField1: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'1'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField0: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22770#25499#27531'0'
      DisplayFormat = '#,##0'
      Calculated = True
    end
    object QueryField: TCurrencyField
      FieldKind = fkCalculated
      FieldName = #22238#21454#20104#23450#38989
      DisplayFormat = '#,##0'
      Calculated = True
    end
  end
end
