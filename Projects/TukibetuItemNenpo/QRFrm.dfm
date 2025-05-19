object QRForm: TQRForm
  Left = 137
  Top = 1
  Width = 1144
  Height = 820
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
    Page.Columns = 5
    Page.Orientation = poLandscape
    Page.PaperSize = A4
    Page.Values = (
      100
      2100
      100
      2970
      210
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
    object QRShape2: TQRShape
      Left = 26
      Top = 96
      Width = 1078
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        68.7916666666667
        254
        2852.20833333333)
      Brush.Style = bsClear
      Shape = qrsRectangle
    end
    object PageHeaderBand1: TQRBand
      Left = 79
      Top = 38
      Width = 1025
      Height = 59
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
        156.104166666667
        2711.97916666667)
      BandType = rbPageHeader
      object TitleLabel: TQRLabel
        Left = 456
        Top = 0
        Width = 113
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1206.5
          0
          298.979166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #26376#21029#38917#30446#21029#24180#22577
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
      object QRSysData2: TQRSysData
        Left = 932
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
          2465.91666666667
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
      object RangeLabel: TQRLabel
        Left = 16
        Top = 42
        Width = 97
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          42.3333333333333
          111.125
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
    end
    object DateLabel01: TQRLabel
      Left = 31
      Top = 154
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        407.458333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRLabel3: TQRLabel
      Left = 26
      Top = 80
      Width = 61
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        68.7916666666667
        211.666666666667
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
    object QRSysData1: TQRSysData
      Left = 25
      Top = 39
      Width = 102
      Height = 14
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        37.0416666666667
        66.1458333333333
        103.1875
        269.875)
      Alignment = taLeftJustify
      AlignToBand = False
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
    object DetailBand1: TQRBand
      Left = 79
      Top = 102
      Width = 205
      Height = 659
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
        1743.60416666667
        542.395833333333)
      BandType = rbDetail
      object QRDBText1: TQRDBText
        Left = 8
        Top = 13
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          34.3958333333333
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#30053#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel7: TQRLabel
        Left = 8
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20214#25968'('#20214')'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel8: TQRLabel
        Left = 84
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          222.25
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #37325#37327'(kg)'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText2: TQRDBText
        Left = 8
        Top = 56
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          148.166666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'01'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText3: TQRDBText
        Left = 72
        Top = 56
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          148.166666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'01'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText4: TQRDBText
        Left = 8
        Top = 78
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          206.375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'02'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText5: TQRDBText
        Left = 72
        Top = 78
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          206.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'02'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText6: TQRDBText
        Left = 8
        Top = 101
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          267.229166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'03'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText7: TQRDBText
        Left = 72
        Top = 101
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          267.229166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'03'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText8: TQRDBText
        Left = 8
        Top = 123
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          325.4375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'04'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText9: TQRDBText
        Left = 72
        Top = 123
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          325.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'04'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText10: TQRDBText
        Left = 8
        Top = 146
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          386.291666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'05'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText11: TQRDBText
        Left = 72
        Top = 146
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          386.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'05'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText14: TQRDBText
        Left = 8
        Top = 168
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          444.5
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'06'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText15: TQRDBText
        Left = 72
        Top = 168
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          444.5
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'06'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText16: TQRDBText
        Left = 8
        Top = 191
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          505.354166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'07'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText17: TQRDBText
        Left = 72
        Top = 191
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          505.354166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'07'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText18: TQRDBText
        Left = 8
        Top = 214
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          566.208333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'08'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText19: TQRDBText
        Left = 72
        Top = 214
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          566.208333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'08'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText20: TQRDBText
        Left = 8
        Top = 236
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          624.416666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'09'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText21: TQRDBText
        Left = 72
        Top = 236
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          624.416666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'09'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText22: TQRDBText
        Left = 8
        Top = 259
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          685.270833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'10'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText23: TQRDBText
        Left = 72
        Top = 259
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          685.270833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'10'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText24: TQRDBText
        Left = 8
        Top = 281
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          743.479166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'11'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText25: TQRDBText
        Left = 72
        Top = 281
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          743.479166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'11'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText26: TQRDBText
        Left = 8
        Top = 304
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          804.333333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'12'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText27: TQRDBText
        Left = 72
        Top = 304
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          804.333333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'12'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr65: TQRExpr
        Left = 8
        Top = 327
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          865.1875
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'Query.'#20214#25968'01 + Query.'#20214#25968'02 + Query.'#20214#25968'03 + Query.'#20214#25968'04 + Query.'#20214#25968'05 +' +
          ' Query.'#20214#25968'06 + Query.'#20214#25968'07 + Query.'#20214#25968'08 + Query.'#20214#25968'09 + Query.'#20214#25968'10 ' +
          '+ Query.'#20214#25968'11 + Query.'#20214#25968'12'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr66: TQRExpr
        Left = 72
        Top = 327
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          865.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'Query.'#37325#37327'01 + Query.'#37325#37327'02 + Query.'#37325#37327'03 + Query.'#37325#37327'04 + Query.'#37325#37327'05 +' +
          ' Query.'#37325#37327'06 + Query.'#37325#37327'07 + Query.'#37325#37327'08 + Query.'#37325#37327'09 + Query.'#37325#37327'10 ' +
          '+ Query.'#37325#37327'11 + Query.'#37325#37327'12'
        Mask = '#,###.#'
        FontSize = 9
      end
      object QRDBText66: TQRDBText
        Left = 144
        Top = 56
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          148.166666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'01'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel11: TQRLabel
        Left = 149
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          394.229166666667
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #37329#38989'('#20870')'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText67: TQRDBText
        Left = 144
        Top = 78
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          206.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'02'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText68: TQRDBText
        Left = 144
        Top = 101
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          267.229166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'03'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText69: TQRDBText
        Left = 144
        Top = 123
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          325.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'04'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText70: TQRDBText
        Left = 144
        Top = 146
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          386.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'05'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText71: TQRDBText
        Left = 144
        Top = 168
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          444.5
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'06'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText72: TQRDBText
        Left = 144
        Top = 191
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          505.354166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'07'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText73: TQRDBText
        Left = 144
        Top = 214
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          566.208333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'08'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText74: TQRDBText
        Left = 144
        Top = 236
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          624.416666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'09'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText75: TQRDBText
        Left = 144
        Top = 259
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          685.270833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'10'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText76: TQRDBText
        Left = 144
        Top = 281
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          743.479166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'11'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText77: TQRDBText
        Left = 144
        Top = 304
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          804.333333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'12'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr67: TQRExpr
        Left = 144
        Top = 327
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          381
          865.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'Query.'#37329#38989'01 + Query.'#37329#38989'02 + Query.'#37329#38989'03 + Query.'#37329#38989'04 + Query.'#37329#38989'05 +' +
          ' Query.'#37329#38989'06 + Query.'#37329#38989'07 + Query.'#37329#38989'08 + Query.'#37329#38989'09 + Query.'#37329#38989'10 ' +
          '+ Query.'#37329#38989'11 + Query.'#37329#38989'12'
        Mask = '#,###'
        FontSize = 9
      end
      object ItemCodeText: TQRDBText
        Left = 4
        Top = 2
        Width = 51
        Height = 10
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          26.4583333333333
          10.5833333333333
          5.29166666666667
          134.9375)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 7
      end
    end
    object DateLabel03: TQRLabel
      Left = 31
      Top = 199
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        526.520833333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel04: TQRLabel
      Left = 31
      Top = 221
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        584.729166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel05: TQRLabel
      Left = 31
      Top = 244
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        645.583333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel09: TQRLabel
      Left = 31
      Top = 334
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        883.708333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel08: TQRLabel
      Left = 31
      Top = 311
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        822.854166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel07: TQRLabel
      Left = 31
      Top = 289
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        764.645833333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel06: TQRLabel
      Left = 31
      Top = 266
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        703.791666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel10: TQRLabel
      Left = 31
      Top = 356
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        941.916666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel11: TQRLabel
      Left = 31
      Top = 379
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        1002.77083333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel12: TQRLabel
      Left = 31
      Top = 401
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        1060.97916666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel13: TQRLabel
      Left = 39
      Top = 424
      Width = 37
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        103.1875
        1121.83333333333
        97.8958333333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #21512#12288#35336
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel02: TQRLabel
      Left = 31
      Top = 176
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        82.0208333333333
        465.666666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'YY'#24180'MM'#26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRShape1: TQRShape
      Left = 79
      Top = 96
      Width = 2
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        209.020833333333
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape3: TQRShape
      Left = 283
      Top = 96
      Width = 2
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        748.770833333333
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape5: TQRShape
      Left = 490
      Top = 96
      Width = 2
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        1296.45833333333
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape6: TQRShape
      Left = 695
      Top = 96
      Width = 2
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        1838.85416666667
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape8: TQRShape
      Left = 899
      Top = 96
      Width = 2
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        2378.60416666667
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape9: TQRShape
      Left = 26
      Top = 148
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        391.583333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape10: TQRShape
      Left = 26
      Top = 170
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        449.791666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape11: TQRShape
      Left = 26
      Top = 193
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        510.645833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape12: TQRShape
      Left = 26
      Top = 215
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        568.854166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape13: TQRShape
      Left = 26
      Top = 238
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        629.708333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 26
      Top = 260
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        687.916666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape15: TQRShape
      Left = 26
      Top = 283
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        748.770833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape16: TQRShape
      Left = 26
      Top = 305
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        806.979166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape17: TQRShape
      Left = 26
      Top = 328
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        867.833333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape18: TQRShape
      Left = 26
      Top = 350
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        926.041666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape19: TQRShape
      Left = 26
      Top = 373
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        986.895833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape20: TQRShape
      Left = 26
      Top = 395
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        1045.10416666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape21: TQRShape
      Left = 26
      Top = 418
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        1105.95833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape22: TQRShape
      Left = 26
      Top = 441
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        1166.8125
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object ItemLabel: TQRLabel
      Left = 38
      Top = 108
      Width = 31
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        100.541666666667
        285.75
        82.0208333333333)
      Alignment = taCenter
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #37528' '#26564
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRShape41: TQRShape
      Left = 26
      Top = 126
      Width = 1077
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        68.7916666666667
        333.375
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRLabel10: TQRLabel
      Left = 46
      Top = 131
      Width = 13
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        121.708333333333
        346.604166666667
        34.3958333333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #26376
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRShape42: TQRShape
      Left = 143
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        378.354166666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape43: TQRShape
      Left = 219
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        579.4375
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape4: TQRShape
      Left = 343
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        907.520833333333
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape44: TQRShape
      Left = 419
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        1108.60416666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape45: TQRShape
      Left = 551
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        1457.85416666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape46: TQRShape
      Left = 627
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        1658.9375
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape7: TQRShape
      Left = 755
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        1997.60416666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape47: TQRShape
      Left = 831
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        2198.6875
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape48: TQRShape
      Left = 959
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        2537.35416666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape49: TQRShape
      Left = 1035
      Top = 128
      Width = 2
      Height = 629
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1664.22916666667
        2738.4375
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object GroupFooterBand: TQRBand
      Left = 79
      Top = 761
      Width = 205
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
        542.395833333333)
      BandType = rbGroupFooter
      object QRLabel2: TQRLabel
        Left = 8
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20214#25968'('#20214')'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel9: TQRLabel
        Left = 84
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          222.25
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #37325#37327'(kg)'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr100: TQRExpr
        Left = 8
        Top = 56
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          148.166666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'01)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr101: TQRExpr
        Left = 72
        Top = 56
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          148.166666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'01)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr102: TQRExpr
        Left = 8
        Top = 78
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          206.375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'02)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr103: TQRExpr
        Left = 72
        Top = 78
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          206.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'02)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr104: TQRExpr
        Left = 8
        Top = 101
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          267.229166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'03)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr105: TQRExpr
        Left = 72
        Top = 101
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          267.229166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'03)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr106: TQRExpr
        Left = 8
        Top = 123
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          325.4375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'04)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr107: TQRExpr
        Left = 72
        Top = 123
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          325.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'04)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr108: TQRExpr
        Left = 8
        Top = 146
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          386.291666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'05)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr109: TQRExpr
        Left = 72
        Top = 146
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          386.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'05)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr110: TQRExpr
        Left = 8
        Top = 168
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          444.5
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'06)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr111: TQRExpr
        Left = 72
        Top = 168
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          444.5
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'06)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr112: TQRExpr
        Left = 8
        Top = 191
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          505.354166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'07)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr113: TQRExpr
        Left = 72
        Top = 191
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          505.354166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'07)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr114: TQRExpr
        Left = 8
        Top = 214
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          566.208333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'08)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr115: TQRExpr
        Left = 72
        Top = 214
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          566.208333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'08)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr116: TQRExpr
        Left = 8
        Top = 236
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          624.416666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'09)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr117: TQRExpr
        Left = 72
        Top = 236
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          624.416666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'09)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr118: TQRExpr
        Left = 8
        Top = 259
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          685.270833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'10)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr119: TQRExpr
        Left = 72
        Top = 259
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          685.270833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'10)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr120: TQRExpr
        Left = 8
        Top = 281
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          743.479166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'11)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr121: TQRExpr
        Left = 72
        Top = 281
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          743.479166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'11)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr122: TQRExpr
        Left = 8
        Top = 304
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          804.333333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr123: TQRExpr
        Left = 72
        Top = 304
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          804.333333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object ItemTotalLabel: TQRLabel
        Left = 24
        Top = 10
        Width = 85
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          63.5
          26.4583333333333
          224.895833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #12304' '#26989' '#32773' '#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel13: TQRLabel
        Left = 155
        Top = 33
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          410.104166666667
          87.3125
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #37329#38989'('#20870')'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr164: TQRExpr
        Left = 143
        Top = 56
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          148.166666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'01)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr165: TQRExpr
        Left = 143
        Top = 78
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          206.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'02)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr166: TQRExpr
        Left = 143
        Top = 101
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          267.229166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'03)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr167: TQRExpr
        Left = 143
        Top = 123
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          325.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'04)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr168: TQRExpr
        Left = 143
        Top = 146
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          386.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'05)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr169: TQRExpr
        Left = 143
        Top = 168
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          444.5
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'06)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr170: TQRExpr
        Left = 143
        Top = 191
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          505.354166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'07)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr171: TQRExpr
        Left = 143
        Top = 214
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          566.208333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'08)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr172: TQRExpr
        Left = 143
        Top = 236
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          624.416666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'09)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr173: TQRExpr
        Left = 143
        Top = 259
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          685.270833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'10)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr174: TQRExpr
        Left = 143
        Top = 281
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          743.479166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'11)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr175: TQRExpr
        Left = 143
        Top = 304
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          804.333333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr1: TQRExpr
        Left = 8
        Top = 327
        Width = 49
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          21.1666666666667
          865.1875
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'SUM(Query.'#20214#25968'01) + SUM(Query.'#20214#25968'02) + SUM(Query.'#20214#25968'03) + SUM(Query.' +
          #20214#25968'04) + SUM(Query.'#20214#25968'05) + SUM(Query.'#20214#25968'06) + SUM(Query.'#20214#25968'07) + SU' +
          'M(Query.'#20214#25968'08) + SUM(Query.'#20214#25968'09) + SUM(Query.'#20214#25968'10) + SUM(Query.'#20214#25968 +
          '11) + SUM(Query.'#20214#25968'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr2: TQRExpr
        Left = 72
        Top = 327
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          190.5
          865.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'SUM(Query.'#37325#37327'01) + SUM(Query.'#37325#37327'02) + SUM(Query.'#37325#37327'03) + SUM(Query.' +
          #37325#37327'04) + SUM(Query.'#37325#37327'05) + SUM(Query.'#37325#37327'06) + SUM(Query.'#37325#37327'07) + SU' +
          'M(Query.'#37325#37327'08) + SUM(Query.'#37325#37327'09) + SUM(Query.'#37325#37327'10) + SUM(Query.'#37325#37327 +
          '11) + SUM(Query.'#37325#37327'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr3: TQRExpr
        Left = 143
        Top = 327
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          378.354166666667
          865.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 
          'SUM(Query.'#37329#38989'01) + SUM(Query.'#37329#38989'02) + SUM(Query.'#37329#38989'03) + SUM(Query.' +
          #37329#38989'04) + SUM(Query.'#37329#38989'05) + SUM(Query.'#37329#38989'06) + SUM(Query.'#37329#38989'07) + SU' +
          'M(Query.'#37329#38989'08) + SUM(Query.'#37329#38989'09) + SUM(Query.'#37329#38989'10) + SUM(Query.'#37329#38989 +
          '11) + SUM(Query.'#37329#38989'12)'
        Mask = '#,###'
        FontSize = 9
      end
    end
    object GroupHeaderBand: TQRGroup
      Left = 79
      Top = 97
      Width = 205
      Height = 5
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
        13.2291666666667
        542.395833333333)
      FooterBand = GroupFooterBand
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object QRLabel1: TQRLabel
      Left = 84
      Top = 16
      Width = 235
      Height = 13
      Enabled = False
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        222.25
        42.3333333333333
        621.770833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = 'TotalQuery'#12399'Excel'#20986#21147#12398#12415#12391#20351#29992#12375#12414#12377#12290
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'DATE_FROM'
        Attributes = [paSigned]
        DataType = ftBCD
        Precision = 8
        Size = 19
        Value = 0c
      end
      item
        Name = 'DATE_TO'
        Attributes = [paSigned]
        DataType = ftBCD
        Precision = 8
        Size = 19
        Value = 999999990000c
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM [DECIMAL]'
      'DECLARE @DATE_TO   [DECIMAL]'
      'SET @DATE_FROM =  :DATE_FROM'
      'SET @DATE_TO   =  :DATE_TO'
      ''
      'SELECT'
      #9#38917#30446'ID, MAX('#38917#30446#12467#12540#12489') AS '#38917#30446#12467#12540#12489', MAX('#38917#30446#30053#31216') AS '#38917#30446#30053#31216','
      #9'SUM('#20214#25968'01) AS '#20214#25968'01,'
      #9'SUM('#20214#25968'02) AS '#20214#25968'02,'
      #9'SUM('#20214#25968'03) AS '#20214#25968'03,'
      #9'SUM('#20214#25968'04) AS '#20214#25968'04,'
      #9'SUM('#20214#25968'05) AS '#20214#25968'05,'
      #9'SUM('#20214#25968'06) AS '#20214#25968'06,'
      #9'SUM('#20214#25968'07) AS '#20214#25968'07,'
      #9'SUM('#20214#25968'08) AS '#20214#25968'08,'
      #9'SUM('#20214#25968'09) AS '#20214#25968'09,'
      #9'SUM('#20214#25968'10) AS '#20214#25968'10,'
      #9'SUM('#20214#25968'11) AS '#20214#25968'11,'
      #9'SUM('#20214#25968'12) AS '#20214#25968'12,'
      ''
      #9'SUM('#37325#37327'01) AS '#37325#37327'01,'
      #9'SUM('#37325#37327'02) AS '#37325#37327'02,'
      #9'SUM('#37325#37327'03) AS '#37325#37327'03,'
      #9'SUM('#37325#37327'04) AS '#37325#37327'04,'
      #9'SUM('#37325#37327'05) AS '#37325#37327'05,'
      #9'SUM('#37325#37327'06) AS '#37325#37327'06,'
      #9'SUM('#37325#37327'07) AS '#37325#37327'07,'
      #9'SUM('#37325#37327'08) AS '#37325#37327'08,'
      #9'SUM('#37325#37327'09) AS '#37325#37327'09,'
      #9'SUM('#37325#37327'10) AS '#37325#37327'10,'
      #9'SUM('#37325#37327'11) AS '#37325#37327'11,'
      #9'SUM('#37325#37327'12) AS '#37325#37327'12,'
      ''
      #9'SUM('#37329#38989'01) AS '#37329#38989'01,'
      #9'SUM('#37329#38989'02) AS '#37329#38989'02,'
      #9'SUM('#37329#38989'03) AS '#37329#38989'03,'
      #9'SUM('#37329#38989'04) AS '#37329#38989'04,'
      #9'SUM('#37329#38989'05) AS '#37329#38989'05,'
      #9'SUM('#37329#38989'06) AS '#37329#38989'06,'
      #9'SUM('#37329#38989'07) AS '#37329#38989'07,'
      #9'SUM('#37329#38989'08) AS '#37329#38989'08,'
      #9'SUM('#37329#38989'09) AS '#37329#38989'09,'
      #9'SUM('#37329#38989'10) AS '#37329#38989'10,'
      #9'SUM('#37329#38989'11) AS '#37329#38989'11,'
      #9'SUM('#37329#38989'12) AS '#37329#38989'12'
      'FROM'
      #9'('
      #9'SELECT'
      #9#9#24471#24847#20808'ID AS '#38917#30446'ID, '#24471#24847#20808#12467#12540#12489' AS '#38917#30446#12467#12540#12489', '#24471#24847#20808#30053#31216' AS '#38917#30446#30053#31216','
      #9
      #9#9'CASE WHEN '#26376' =  4 THEN 1 ELSE 0 END AS '#20214#25968'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN 1 ELSE 0 END AS '#20214#25968'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN 1 ELSE 0 END AS '#20214#25968'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN 1 ELSE 0 END AS '#20214#25968'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN 1 ELSE 0 END AS '#20214#25968'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN 1 ELSE 0 END AS '#20214#25968'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN 1 ELSE 0 END AS '#20214#25968'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN 1 ELSE 0 END AS '#20214#25968'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN 1 ELSE 0 END AS '#20214#25968'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN 1 ELSE 0 END AS '#20214#25968'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN 1 ELSE 0 END AS '#20214#25968'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN 1 ELSE 0 END AS '#20214#25968'12,'
      #9
      #9#9'CASE WHEN '#26376' =  4 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'12,'
      #9
      #9#9'CASE WHEN '#26376' =  4 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'12'
      #9'FROM'
      #9#9'V_'#35336#37327
      #9'WHERE'
      #9#9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9#23436#20102#21306#20998' = 1'
      #9'--$WHERE$'
      #9') AS D'
      'GROUP BY'
      #9#38917#30446'ID'
      'ORDER BY'
      #9#38917#30446#12467#12540#12489
      '')
    Left = 24
    Top = 16
    object QueryID: TIntegerField
      FieldName = #38917#30446'ID'
    end
    object QueryDSDesigner: TIntegerField
      FieldName = #38917#30446#12467#12540#12489
      ReadOnly = True
    end
    object QueryDSDesigner2: TStringField
      FieldName = #38917#30446#30053#31216
      ReadOnly = True
    end
    object QueryDSDesigner01: TIntegerField
      FieldName = #20214#25968'01'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner02: TIntegerField
      FieldName = #20214#25968'02'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner03: TIntegerField
      FieldName = #20214#25968'03'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner04: TIntegerField
      FieldName = #20214#25968'04'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner05: TIntegerField
      FieldName = #20214#25968'05'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner06: TIntegerField
      FieldName = #20214#25968'06'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner07: TIntegerField
      FieldName = #20214#25968'07'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner08: TIntegerField
      FieldName = #20214#25968'08'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner09: TIntegerField
      FieldName = #20214#25968'09'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner10: TIntegerField
      FieldName = #20214#25968'10'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner11: TIntegerField
      FieldName = #20214#25968'11'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner12: TIntegerField
      FieldName = #20214#25968'12'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner012: TBCDField
      FieldName = #37325#37327'01'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner022: TBCDField
      FieldName = #37325#37327'02'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner032: TBCDField
      FieldName = #37325#37327'03'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner042: TBCDField
      FieldName = #37325#37327'04'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner052: TBCDField
      FieldName = #37325#37327'05'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner062: TBCDField
      FieldName = #37325#37327'06'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner072: TBCDField
      FieldName = #37325#37327'07'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner082: TBCDField
      FieldName = #37325#37327'08'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner092: TBCDField
      FieldName = #37325#37327'09'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner102: TBCDField
      FieldName = #37325#37327'10'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner112: TBCDField
      FieldName = #37325#37327'11'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner122: TBCDField
      FieldName = #37325#37327'12'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner013: TBCDField
      FieldName = #37329#38989'01'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner023: TBCDField
      FieldName = #37329#38989'02'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner033: TBCDField
      FieldName = #37329#38989'03'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner043: TBCDField
      FieldName = #37329#38989'04'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner053: TBCDField
      FieldName = #37329#38989'05'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner063: TBCDField
      FieldName = #37329#38989'06'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner073: TBCDField
      FieldName = #37329#38989'07'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner083: TBCDField
      FieldName = #37329#38989'08'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner093: TBCDField
      FieldName = #37329#38989'09'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner103: TBCDField
      FieldName = #37329#38989'10'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner113: TBCDField
      FieldName = #37329#38989'11'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner123: TBCDField
      FieldName = #37329#38989'12'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
  end
  object TotalQuery: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'DATE_FROM'
        Attributes = [paSigned]
        DataType = ftBCD
        Precision = 8
        Size = 19
        Value = 0c
      end
      item
        Name = 'DATE_TO'
        Attributes = [paSigned]
        DataType = ftBCD
        Precision = 8
        Size = 19
        Value = 999999990000c
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM [DECIMAL]'
      'DECLARE @DATE_TO   [DECIMAL]'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      ''
      'SELECT'
      #9'SUM('#20214#25968'01) AS '#20214#25968'01,'
      #9'SUM('#20214#25968'02) AS '#20214#25968'02,'
      #9'SUM('#20214#25968'03) AS '#20214#25968'03,'
      #9'SUM('#20214#25968'04) AS '#20214#25968'04,'
      #9'SUM('#20214#25968'05) AS '#20214#25968'05,'
      #9'SUM('#20214#25968'06) AS '#20214#25968'06,'
      #9'SUM('#20214#25968'07) AS '#20214#25968'07,'
      #9'SUM('#20214#25968'08) AS '#20214#25968'08,'
      #9'SUM('#20214#25968'09) AS '#20214#25968'09,'
      #9'SUM('#20214#25968'10) AS '#20214#25968'10,'
      #9'SUM('#20214#25968'11) AS '#20214#25968'11,'
      #9'SUM('#20214#25968'12) AS '#20214#25968'12,'
      ''
      #9'SUM('#37325#37327'01) AS '#37325#37327'01,'
      #9'SUM('#37325#37327'02) AS '#37325#37327'02,'
      #9'SUM('#37325#37327'03) AS '#37325#37327'03,'
      #9'SUM('#37325#37327'04) AS '#37325#37327'04,'
      #9'SUM('#37325#37327'05) AS '#37325#37327'05,'
      #9'SUM('#37325#37327'06) AS '#37325#37327'06,'
      #9'SUM('#37325#37327'07) AS '#37325#37327'07,'
      #9'SUM('#37325#37327'08) AS '#37325#37327'08,'
      #9'SUM('#37325#37327'09) AS '#37325#37327'09,'
      #9'SUM('#37325#37327'10) AS '#37325#37327'10,'
      #9'SUM('#37325#37327'11) AS '#37325#37327'11,'
      #9'SUM('#37325#37327'12) AS '#37325#37327'12,'
      ''
      #9'SUM('#37329#38989'01) AS '#37329#38989'01,'
      #9'SUM('#37329#38989'02) AS '#37329#38989'02,'
      #9'SUM('#37329#38989'03) AS '#37329#38989'03,'
      #9'SUM('#37329#38989'04) AS '#37329#38989'04,'
      #9'SUM('#37329#38989'05) AS '#37329#38989'05,'
      #9'SUM('#37329#38989'06) AS '#37329#38989'06,'
      #9'SUM('#37329#38989'07) AS '#37329#38989'07,'
      #9'SUM('#37329#38989'08) AS '#37329#38989'08,'
      #9'SUM('#37329#38989'09) AS '#37329#38989'09,'
      #9'SUM('#37329#38989'10) AS '#37329#38989'10,'
      #9'SUM('#37329#38989'11) AS '#37329#38989'11,'
      #9'SUM('#37329#38989'12) AS '#37329#38989'12,'
      'FROM'
      #9'('
      #9'SELECT'
      #9#9#24471#24847#20808'ID AS '#38917#30446'ID, '#24471#24847#20808#12467#12540#12489' AS '#38917#30446#12467#12540#12489', '#24471#24847#20808#30053#31216' AS '#38917#30446#30053#31216','
      ''
      #9#9'CASE WHEN '#26376' =  4 THEN 1 ELSE 0 END AS '#20214#25968'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN 1 ELSE 0 END AS '#20214#25968'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN 1 ELSE 0 END AS '#20214#25968'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN 1 ELSE 0 END AS '#20214#25968'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN 1 ELSE 0 END AS '#20214#25968'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN 1 ELSE 0 END AS '#20214#25968'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN 1 ELSE 0 END AS '#20214#25968'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN 1 ELSE 0 END AS '#20214#25968'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN 1 ELSE 0 END AS '#20214#25968'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN 1 ELSE 0 END AS '#20214#25968'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN 1 ELSE 0 END AS '#20214#25968'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN 1 ELSE 0 END AS '#20214#25968'12,'
      ''
      #9#9'CASE WHEN '#26376' =  4 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'12,'
      ''
      #9#9'CASE WHEN '#26376' =  4 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'01,'
      #9#9'CASE WHEN '#26376' =  5 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'02,'
      #9#9'CASE WHEN '#26376' =  6 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'03,'
      #9#9'CASE WHEN '#26376' =  7 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'04,'
      #9#9'CASE WHEN '#26376' =  8 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'05,'
      #9#9'CASE WHEN '#26376' =  9 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'06,'
      #9#9'CASE WHEN '#26376' = 10 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'07,'
      #9#9'CASE WHEN '#26376' = 11 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'08,'
      #9#9'CASE WHEN '#26376' = 12 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'09,'
      #9#9'CASE WHEN '#26376' =  1 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'10,'
      #9#9'CASE WHEN '#26376' =  2 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'11,'
      #9#9'CASE WHEN '#26376' =  3 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'12'
      #9'FROM'
      #9#9'V_'#35336#37327
      #9'WHERE'
      #9#9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9#23436#20102#21306#20998' = 1'
      #9'AND'
      #9#9#24471#24847#20808#12467#12540#12489' = 2'
      #9'AND'
      #9#9#25312#28857'ID = 1'
      #9'AND'
      #9#9#25644#20837#20986#21306#20998' = 1'
      #9') AS D')
    Left = 56
    Top = 16
    object IntegerField3: TIntegerField
      FieldName = #20214#25968'01'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField4: TIntegerField
      FieldName = #20214#25968'02'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField5: TIntegerField
      FieldName = #20214#25968'03'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField6: TIntegerField
      FieldName = #20214#25968'04'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField7: TIntegerField
      FieldName = #20214#25968'05'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField8: TIntegerField
      FieldName = #20214#25968'06'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField9: TIntegerField
      FieldName = #20214#25968'07'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField10: TIntegerField
      FieldName = #20214#25968'08'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField11: TIntegerField
      FieldName = #20214#25968'09'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField12: TIntegerField
      FieldName = #20214#25968'10'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField13: TIntegerField
      FieldName = #20214#25968'11'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField14: TIntegerField
      FieldName = #20214#25968'12'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object BCDField1: TBCDField
      FieldName = #37325#37327'01'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField2: TBCDField
      FieldName = #37325#37327'02'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField3: TBCDField
      FieldName = #37325#37327'03'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField4: TBCDField
      FieldName = #37325#37327'04'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField5: TBCDField
      FieldName = #37325#37327'05'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField6: TBCDField
      FieldName = #37325#37327'06'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField7: TBCDField
      FieldName = #37325#37327'07'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField8: TBCDField
      FieldName = #37325#37327'08'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField9: TBCDField
      FieldName = #37325#37327'09'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField10: TBCDField
      FieldName = #37325#37327'10'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField11: TBCDField
      FieldName = #37325#37327'11'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField12: TBCDField
      FieldName = #37325#37327'12'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField32: TBCDField
      FieldName = #37329#38989'01'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField33: TBCDField
      FieldName = #37329#38989'02'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField34: TBCDField
      FieldName = #37329#38989'03'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField35: TBCDField
      FieldName = #37329#38989'04'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField36: TBCDField
      FieldName = #37329#38989'05'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField37: TBCDField
      FieldName = #37329#38989'06'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField38: TBCDField
      FieldName = #37329#38989'07'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField39: TBCDField
      FieldName = #37329#38989'08'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField40: TBCDField
      FieldName = #37329#38989'09'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField41: TBCDField
      FieldName = #37329#38989'10'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField42: TBCDField
      FieldName = #37329#38989'11'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField43: TBCDField
      FieldName = #37329#38989'12'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
  end
end
