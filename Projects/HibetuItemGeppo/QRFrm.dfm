object QRForm: TQRForm
  Left = 80
  Top = 0
  Width = 1138
  Height = 800
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
        Caption = #26085#21029#38917#30446#21029#26376#22577
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
      Left = 30
      Top = 152
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        402.166666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 1'#26085'('#28779')'
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
      object ItemNameText: TQRDBText
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
        Top = 74
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
          195.791666666667
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
        Top = 74
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
          195.791666666667
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
        Top = 93
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
          246.0625
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
        Top = 93
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
          246.0625
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
        Top = 112
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
          296.333333333333
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
        Top = 112
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
          296.333333333333
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
        Top = 131
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
          346.604166666667
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
        Top = 131
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
          346.604166666667
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
        Top = 150
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
          396.875
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
        Top = 150
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
          396.875
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
        Top = 169
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
          447.145833333333
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
        Top = 169
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
          447.145833333333
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
        Top = 187
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
          494.770833333333
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
        Top = 187
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
          494.770833333333
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
        Top = 206
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
          545.041666666667
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
        Top = 206
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
          545.041666666667
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
        Top = 225
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
          595.3125
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
        Top = 225
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
          595.3125
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
          21.1666666666667
          645.583333333333
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
        Top = 244
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
          645.583333333333
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
        Top = 263
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
          695.854166666667
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
        Top = 263
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
          695.854166666667
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
      object QRDBText28: TQRDBText
        Left = 8
        Top = 282
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
          746.125
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'13'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText29: TQRDBText
        Left = 72
        Top = 282
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
          746.125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'13'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText30: TQRDBText
        Left = 8
        Top = 300
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
          793.75
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'14'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText31: TQRDBText
        Left = 72
        Top = 300
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
          793.75
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'14'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText32: TQRDBText
        Left = 8
        Top = 319
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
          844.020833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'15'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText33: TQRDBText
        Left = 72
        Top = 319
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
          844.020833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'15'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText34: TQRDBText
        Left = 8
        Top = 338
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
          894.291666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'16'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText35: TQRDBText
        Left = 72
        Top = 338
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
          894.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'16'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText36: TQRDBText
        Left = 8
        Top = 357
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
          944.5625
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'17'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText37: TQRDBText
        Left = 72
        Top = 357
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
          944.5625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'17'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText38: TQRDBText
        Left = 8
        Top = 376
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
          994.833333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'18'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText39: TQRDBText
        Left = 72
        Top = 376
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
          994.833333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'18'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText40: TQRDBText
        Left = 8
        Top = 395
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
          1045.10416666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'19'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText41: TQRDBText
        Left = 72
        Top = 395
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
          1045.10416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'19'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText42: TQRDBText
        Left = 8
        Top = 413
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
          1092.72916666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'20'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText43: TQRDBText
        Left = 72
        Top = 413
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
          1092.72916666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'20'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText44: TQRDBText
        Left = 8
        Top = 432
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
          1143
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'21'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText45: TQRDBText
        Left = 72
        Top = 432
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
          1143
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'21'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText46: TQRDBText
        Left = 8
        Top = 451
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
          1193.27083333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'22'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText47: TQRDBText
        Left = 72
        Top = 451
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
          1193.27083333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'22'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText48: TQRDBText
        Left = 8
        Top = 470
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
          1243.54166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'23'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText49: TQRDBText
        Left = 72
        Top = 470
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
          1243.54166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'23'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText50: TQRDBText
        Left = 8
        Top = 489
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
          1293.8125
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'24'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText51: TQRDBText
        Left = 72
        Top = 489
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
          1293.8125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'24'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText52: TQRDBText
        Left = 8
        Top = 508
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
          1344.08333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'25'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText53: TQRDBText
        Left = 72
        Top = 508
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
          1344.08333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'25'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText54: TQRDBText
        Left = 8
        Top = 526
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
          1391.70833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'26'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText55: TQRDBText
        Left = 72
        Top = 526
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
          1391.70833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'26'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText56: TQRDBText
        Left = 8
        Top = 545
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
          1441.97916666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'27'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText57: TQRDBText
        Left = 72
        Top = 545
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
          1441.97916666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'27'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText58: TQRDBText
        Left = 8
        Top = 564
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
          1492.25
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'28'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText59: TQRDBText
        Left = 72
        Top = 564
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
          1492.25
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'28'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText60: TQRDBText
        Left = 8
        Top = 583
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
          1542.52083333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'29'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText61: TQRDBText
        Left = 72
        Top = 583
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
          1542.52083333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'29'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText62: TQRDBText
        Left = 8
        Top = 602
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
          1592.79166666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'30'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText63: TQRDBText
        Left = 72
        Top = 602
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
          1592.79166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'30'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText64: TQRDBText
        Left = 8
        Top = 621
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
          1643.0625
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20214#25968'31'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText65: TQRDBText
        Left = 72
        Top = 621
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
          1643.0625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37325#37327'31'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr65: TQRExpr
        Left = 8
        Top = 641
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
          1695.97916666667
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
          '+ Query.'#20214#25968'11 + Query.'#20214#25968'12 + Query.'#20214#25968'13 + Query.'#20214#25968'14 + Query.'#20214#25968'15' +
          ' + Query.'#20214#25968'16 + Query.'#20214#25968'17 + Query.'#20214#25968'18 + Query.'#20214#25968'19 + Query.'#20214#25968'2' +
          '0 + Query.'#20214#25968'21 + Query.'#20214#25968'22 + Query.'#20214#25968'23 + Query.'#20214#25968'24 + Query.'#20214#25968 +
          '25 + Query.'#20214#25968'26 + Query.'#20214#25968'27 + Query.'#20214#25968'28 + Query.'#20214#25968'29 + Query.'#20214 +
          #25968'30 + Query.'#20214#25968'31'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr66: TQRExpr
        Left = 72
        Top = 641
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
          1695.97916666667
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
          '+ Query.'#37325#37327'11 + Query.'#37325#37327'12 + Query.'#37325#37327'13 + Query.'#37325#37327'14 + Query.'#37325#37327'15' +
          ' + Query.'#37325#37327'16 + Query.'#37325#37327'17 + Query.'#37325#37327'18 + Query.'#37325#37327'19 + Query.'#37325#37327'2' +
          '0 + Query.'#37325#37327'21 + Query.'#37325#37327'22 + Query.'#37325#37327'23 + Query.'#37325#37327'24 + Query.'#37325#37327 +
          '25 + Query.'#37325#37327'26 + Query.'#37325#37327'27 + Query.'#37325#37327'28 + Query.'#37325#37327'29 + Query.'#37325 +
          #37327'30 + Query.'#37325#37327'31'
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
        Top = 74
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
          195.791666666667
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
        Top = 93
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
          246.0625
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
        Top = 112
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
          296.333333333333
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
        Top = 131
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
          346.604166666667
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
        Top = 150
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
          396.875
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
        Top = 169
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
          447.145833333333
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
        Top = 187
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
          494.770833333333
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
        Top = 206
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
          545.041666666667
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
        Top = 225
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
          595.3125
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
        Top = 244
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
          645.583333333333
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
        Top = 263
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
          695.854166666667
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
      object QRDBText78: TQRDBText
        Left = 144
        Top = 282
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
          746.125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'13'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText79: TQRDBText
        Left = 144
        Top = 300
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
          793.75
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'14'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText80: TQRDBText
        Left = 144
        Top = 319
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
          844.020833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'15'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText81: TQRDBText
        Left = 144
        Top = 338
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
          894.291666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'16'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText82: TQRDBText
        Left = 144
        Top = 357
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
          944.5625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'17'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText83: TQRDBText
        Left = 144
        Top = 376
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
          994.833333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'18'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText84: TQRDBText
        Left = 144
        Top = 395
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
          1045.10416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'19'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText85: TQRDBText
        Left = 144
        Top = 413
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
          1092.72916666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'20'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText86: TQRDBText
        Left = 144
        Top = 432
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
          1143
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'21'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText87: TQRDBText
        Left = 144
        Top = 451
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
          1193.27083333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'22'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText88: TQRDBText
        Left = 144
        Top = 470
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
          1243.54166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'23'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText89: TQRDBText
        Left = 144
        Top = 489
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
          1293.8125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'24'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText90: TQRDBText
        Left = 144
        Top = 508
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
          1344.08333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'25'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText91: TQRDBText
        Left = 144
        Top = 526
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
          1391.70833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'26'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText92: TQRDBText
        Left = 144
        Top = 545
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
          1441.97916666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'27'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText93: TQRDBText
        Left = 144
        Top = 564
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
          1492.25
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'28'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText94: TQRDBText
        Left = 144
        Top = 583
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
          1542.52083333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'29'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText95: TQRDBText
        Left = 144
        Top = 602
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
          1592.79166666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'30'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText96: TQRDBText
        Left = 144
        Top = 621
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
          1643.0625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #37329#38989'31'
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRExpr67: TQRExpr
        Left = 144
        Top = 641
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
          1695.97916666667
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
          '+ Query.'#37329#38989'11 + Query.'#37329#38989'12 + Query.'#37329#38989'13 + Query.'#37329#38989'14 + Query.'#37329#38989'15' +
          ' + Query.'#37329#38989'16 + Query.'#37329#38989'17 + Query.'#37329#38989'18 + Query.'#37329#38989'19 + Query.'#37329#38989'2' +
          '0 + Query.'#37329#38989'21 + Query.'#37329#38989'22 + Query.'#37329#38989'23 + Query.'#37329#38989'24 + Query.'#37329#38989 +
          '25 + Query.'#37329#38989'26 + Query.'#37329#38989'27 + Query.'#37329#38989'28 + Query.'#37329#38989'29 + Query.'#37329 +
          #38989'30 + Query.'#37329#38989'31'
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
      Left = 30
      Top = 189
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        500.0625
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 3'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel04: TQRLabel
      Left = 30
      Top = 208
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        550.333333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 4'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel05: TQRLabel
      Left = 30
      Top = 227
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        600.604166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 5'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel09: TQRLabel
      Left = 30
      Top = 302
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        799.041666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 9'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel08: TQRLabel
      Left = 30
      Top = 283
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        748.770833333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 8'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel07: TQRLabel
      Left = 30
      Top = 265
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        701.145833333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 7'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel06: TQRLabel
      Left = 30
      Top = 246
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        650.875
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 6'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel10: TQRLabel
      Left = 30
      Top = 321
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        849.3125
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '10'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel11: TQRLabel
      Left = 30
      Top = 340
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        899.583333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '11'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel12: TQRLabel
      Left = 30
      Top = 359
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        949.854166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '12'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel13: TQRLabel
      Left = 30
      Top = 378
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1000.125
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '13'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel14: TQRLabel
      Left = 30
      Top = 396
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1047.75
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel15: TQRLabel
      Left = 30
      Top = 415
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1098.02083333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel19: TQRLabel
      Left = 30
      Top = 491
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1299.10416666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel18: TQRLabel
      Left = 30
      Top = 472
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1248.83333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel17: TQRLabel
      Left = 30
      Top = 453
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1198.5625
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel16: TQRLabel
      Left = 31
      Top = 434
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
        1148.29166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel20: TQRLabel
      Left = 30
      Top = 509
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1346.72916666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel21: TQRLabel
      Left = 30
      Top = 528
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1397
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel22: TQRLabel
      Left = 30
      Top = 547
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1447.27083333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel23: TQRLabel
      Left = 30
      Top = 566
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1497.54166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel24: TQRLabel
      Left = 30
      Top = 585
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1547.8125
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel25: TQRLabel
      Left = 30
      Top = 604
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1598.08333333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel29: TQRLabel
      Left = 30
      Top = 679
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1796.52083333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel28: TQRLabel
      Left = 30
      Top = 660
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1746.25
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel27: TQRLabel
      Left = 30
      Top = 641
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1695.97916666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel26: TQRLabel
      Left = 30
      Top = 622
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1645.70833333333
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel30: TQRLabel
      Left = 30
      Top = 698
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1846.79166666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object DateLabel31: TQRLabel
      Left = 30
      Top = 717
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        1897.0625
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = '31'#26085'('#28779')'
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRLabel39: TQRLabel
      Left = 35
      Top = 737
      Width = 37
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        92.6041666666667
        1949.97916666667
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
      Left = 30
      Top = 170
      Width = 49
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        79.375
        449.791666666667
        129.645833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = ' 2'#26085'('#28779')'
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
      Top = 167
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
        441.854166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape11: TQRShape
      Left = 26
      Top = 185
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
        489.479166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape12: TQRShape
      Left = 26
      Top = 204
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
        539.75
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape13: TQRShape
      Left = 26
      Top = 223
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
        590.020833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 26
      Top = 242
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
        640.291666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape15: TQRShape
      Left = 26
      Top = 261
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
        690.5625
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape16: TQRShape
      Left = 26
      Top = 280
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
        740.833333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape17: TQRShape
      Left = 26
      Top = 298
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
        788.458333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape18: TQRShape
      Left = 26
      Top = 317
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
        838.729166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape19: TQRShape
      Left = 26
      Top = 336
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
        889
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape20: TQRShape
      Left = 26
      Top = 355
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
        939.270833333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape21: TQRShape
      Left = 26
      Top = 374
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
        989.541666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape22: TQRShape
      Left = 26
      Top = 393
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
        1039.8125
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape23: TQRShape
      Left = 26
      Top = 412
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
        1090.08333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape24: TQRShape
      Left = 26
      Top = 431
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
        1140.35416666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape25: TQRShape
      Left = 26
      Top = 450
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
        1190.625
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape26: TQRShape
      Left = 26
      Top = 469
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
        1240.89583333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape27: TQRShape
      Left = 26
      Top = 488
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
        1291.16666666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape28: TQRShape
      Left = 26
      Top = 506
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
        1338.79166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape29: TQRShape
      Left = 26
      Top = 525
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
        1389.0625
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape30: TQRShape
      Left = 26
      Top = 544
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
        1439.33333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape31: TQRShape
      Left = 26
      Top = 563
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
        1489.60416666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape32: TQRShape
      Left = 26
      Top = 582
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
        1539.875
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape33: TQRShape
      Left = 26
      Top = 601
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
        1590.14583333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape34: TQRShape
      Left = 26
      Top = 619
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
        1637.77083333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape35: TQRShape
      Left = 26
      Top = 638
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
        1688.04166666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape36: TQRShape
      Left = 26
      Top = 657
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
        1738.3125
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape37: TQRShape
      Left = 26
      Top = 676
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
        1788.58333333333
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape38: TQRShape
      Left = 26
      Top = 695
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
        1838.85416666667
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape39: TQRShape
      Left = 26
      Top = 714
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
        1889.125
        2849.5625)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape40: TQRShape
      Left = 26
      Top = 733
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
        1939.39583333333
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
      Left = 38
      Top = 131
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
        346.604166666667
        82.0208333333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #26085' '#20184
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
        Top = 74
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
          195.791666666667
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
        Top = 74
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
          195.791666666667
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
        Top = 93
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
          246.0625
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
        Top = 93
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
          246.0625
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
        Top = 112
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
          296.333333333333
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
        Top = 112
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
          296.333333333333
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
        Top = 131
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
          346.604166666667
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
        Top = 131
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
          346.604166666667
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
        Top = 150
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
          396.875
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
        Top = 150
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
          396.875
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
        Top = 169
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
          447.145833333333
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
        Top = 169
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
          447.145833333333
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
        Top = 188
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
          497.416666666667
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
        Top = 188
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
          497.416666666667
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
        Top = 206
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
          545.041666666667
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
        Top = 206
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
          545.041666666667
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
        Top = 225
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
          595.3125
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
        Top = 225
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
          595.3125
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
          21.1666666666667
          645.583333333333
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
        Top = 244
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
          645.583333333333
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
        Top = 263
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
          695.854166666667
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
        Top = 263
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
          695.854166666667
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
      object QRExpr124: TQRExpr
        Left = 8
        Top = 282
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
          746.125
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'13)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr125: TQRExpr
        Left = 72
        Top = 282
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
          746.125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'13)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr126: TQRExpr
        Left = 8
        Top = 301
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
          796.395833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'14)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr127: TQRExpr
        Left = 72
        Top = 301
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
          796.395833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'14)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr128: TQRExpr
        Left = 8
        Top = 320
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
          846.666666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'15)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr129: TQRExpr
        Left = 72
        Top = 320
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
          846.666666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'15)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr130: TQRExpr
        Left = 8
        Top = 339
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
          896.9375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'16)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr131: TQRExpr
        Left = 72
        Top = 339
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
          896.9375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'16)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr132: TQRExpr
        Left = 8
        Top = 357
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
          944.5625
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'17)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr133: TQRExpr
        Left = 72
        Top = 357
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
          944.5625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'17)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr134: TQRExpr
        Left = 8
        Top = 376
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
          994.833333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'18)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr135: TQRExpr
        Left = 72
        Top = 376
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
          994.833333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'18)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr136: TQRExpr
        Left = 8
        Top = 395
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
          1045.10416666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'19)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr137: TQRExpr
        Left = 72
        Top = 395
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
          1045.10416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'19)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr138: TQRExpr
        Left = 8
        Top = 414
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
          1095.375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'20)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr139: TQRExpr
        Left = 72
        Top = 414
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
          1095.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'20)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr140: TQRExpr
        Left = 8
        Top = 433
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
          1145.64583333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'21)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr141: TQRExpr
        Left = 72
        Top = 433
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
          1145.64583333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'21)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr142: TQRExpr
        Left = 8
        Top = 452
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
          1195.91666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'22)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr143: TQRExpr
        Left = 72
        Top = 452
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
          1195.91666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'22)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr144: TQRExpr
        Left = 8
        Top = 471
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
          1246.1875
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'23)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr145: TQRExpr
        Left = 72
        Top = 471
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
          1246.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'23)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr146: TQRExpr
        Left = 8
        Top = 490
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
          1296.45833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'24)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr147: TQRExpr
        Left = 72
        Top = 490
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
          1296.45833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'24)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr148: TQRExpr
        Left = 8
        Top = 508
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
          1344.08333333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'25)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr149: TQRExpr
        Left = 72
        Top = 508
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
          1344.08333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'25)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr150: TQRExpr
        Left = 8
        Top = 527
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
          1394.35416666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'26)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr151: TQRExpr
        Left = 72
        Top = 527
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
          1394.35416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'26)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr152: TQRExpr
        Left = 8
        Top = 546
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
          1444.625
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'27)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr153: TQRExpr
        Left = 72
        Top = 546
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
          1444.625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'27)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr154: TQRExpr
        Left = 8
        Top = 565
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
          1494.89583333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'28)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr155: TQRExpr
        Left = 72
        Top = 565
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
          1494.89583333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'28)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr156: TQRExpr
        Left = 8
        Top = 584
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
          1545.16666666667
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'29)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr157: TQRExpr
        Left = 72
        Top = 584
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
          1545.16666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'29)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr158: TQRExpr
        Left = 8
        Top = 603
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
          1595.4375
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'30)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr159: TQRExpr
        Left = 72
        Top = 603
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
          1595.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'30)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr160: TQRExpr
        Left = 8
        Top = 641
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
          1695.97916666667
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
          '11) + SUM(Query.'#20214#25968'12) + SUM(Query.'#20214#25968'13) + SUM(Query.'#20214#25968'14) + SUM(' +
          'Query.'#20214#25968'15) + SUM(Query.'#20214#25968'16) + SUM(Query.'#20214#25968'17) + SUM(Query.'#20214#25968'18' +
          ') + SUM(Query.'#20214#25968'19) + SUM(Query.'#20214#25968'20) + SUM(Query.'#20214#25968'21) + SUM(Qu' +
          'ery.'#20214#25968'22) + SUM(Query.'#20214#25968'23) + SUM(Query.'#20214#25968'24) + SUM(Query.'#20214#25968'25) ' +
          '+ SUM(Query.'#20214#25968'26) + SUM(Query.'#20214#25968'27) + SUM(Query.'#20214#25968'28) + SUM(Quer' +
          'y.'#20214#25968'29) + SUM(Query.'#20214#25968'30) + SUM(Query.'#20214#25968'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr161: TQRExpr
        Left = 72
        Top = 641
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
          1695.97916666667
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
          '11) + SUM(Query.'#37325#37327'12) + SUM(Query.'#37325#37327'13) + SUM(Query.'#37325#37327'14) + SUM(' +
          'Query.'#37325#37327'15) + SUM(Query.'#37325#37327'16) + SUM(Query.'#37325#37327'17) + SUM(Query.'#37325#37327'18' +
          ') + SUM(Query.'#37325#37327'19) + SUM(Query.'#37325#37327'20) + SUM(Query.'#37325#37327'21) + SUM(Qu' +
          'ery.'#37325#37327'22) + SUM(Query.'#37325#37327'23) + SUM(Query.'#37325#37327'24) + SUM(Query.'#37325#37327'25) ' +
          '+ SUM(Query.'#37325#37327'26) + SUM(Query.'#37325#37327'27) + SUM(Query.'#37325#37327'28) + SUM(Quer' +
          'y.'#37325#37327'29) + SUM(Query.'#37325#37327'30) + SUM(Query.'#37325#37327'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr162: TQRExpr
        Left = 8
        Top = 622
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
          1645.70833333333
          129.645833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#20214#25968'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr163: TQRExpr
        Left = 72
        Top = 622
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
          1645.70833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37325#37327'31)'
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
        Top = 74
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
          195.791666666667
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
        Top = 93
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
          246.0625
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
        Top = 112
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
          296.333333333333
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
        Top = 131
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
          346.604166666667
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
        Top = 150
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
          396.875
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
        Top = 169
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
          447.145833333333
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
        Top = 188
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
          497.416666666667
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
        Top = 206
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
          545.041666666667
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
        Top = 225
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
          595.3125
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
        Top = 244
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
          645.583333333333
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
        Top = 263
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
          695.854166666667
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
      object QRExpr176: TQRExpr
        Left = 143
        Top = 282
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
          746.125
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'13)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr177: TQRExpr
        Left = 143
        Top = 301
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
          796.395833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'14)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr178: TQRExpr
        Left = 143
        Top = 320
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
          846.666666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'15)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr179: TQRExpr
        Left = 143
        Top = 339
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
          896.9375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'16)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr180: TQRExpr
        Left = 143
        Top = 357
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
          944.5625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'17)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr181: TQRExpr
        Left = 143
        Top = 376
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
          994.833333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'18)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr182: TQRExpr
        Left = 143
        Top = 395
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
          1045.10416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'19)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr183: TQRExpr
        Left = 143
        Top = 414
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
          1095.375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'20)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr184: TQRExpr
        Left = 143
        Top = 433
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
          1145.64583333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'21)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr185: TQRExpr
        Left = 143
        Top = 452
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
          1195.91666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'22)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr186: TQRExpr
        Left = 143
        Top = 471
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
          1246.1875
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'23)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr187: TQRExpr
        Left = 143
        Top = 490
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
          1296.45833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'24)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr188: TQRExpr
        Left = 143
        Top = 508
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
          1344.08333333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'25)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr189: TQRExpr
        Left = 143
        Top = 527
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
          1394.35416666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'26)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr190: TQRExpr
        Left = 143
        Top = 546
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
          1444.625
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'27)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr191: TQRExpr
        Left = 143
        Top = 565
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
          1494.89583333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'28)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr192: TQRExpr
        Left = 143
        Top = 584
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
          1545.16666666667
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'29)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr193: TQRExpr
        Left = 143
        Top = 603
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
          1595.4375
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'30)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr194: TQRExpr
        Left = 143
        Top = 622
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
          1645.70833333333
          161.395833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#37329#38989'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr195: TQRExpr
        Left = 143
        Top = 641
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
          1695.97916666667
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
          '11) + SUM(Query.'#37329#38989'12) + SUM(Query.'#37329#38989'13) + SUM(Query.'#37329#38989'14) + SUM(' +
          'Query.'#37329#38989'15) + SUM(Query.'#37329#38989'16) + SUM(Query.'#37329#38989'17) + SUM(Query.'#37329#38989'18' +
          ') + SUM(Query.'#37329#38989'19) + SUM(Query.'#37329#38989'20) + SUM(Query.'#37329#38989'21) + SUM(Qu' +
          'ery.'#37329#38989'22) + SUM(Query.'#37329#38989'23) + SUM(Query.'#37329#38989'24) + SUM(Query.'#37329#38989'25) ' +
          '+ SUM(Query.'#37329#38989'26) + SUM(Query.'#37329#38989'27) + SUM(Query.'#37329#38989'28) + SUM(Quer' +
          'y.'#37329#38989'29) + SUM(Query.'#37329#38989'30) + SUM(Query.'#37329#38989'31)'
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
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
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
      #9'SUM('#20214#25968'13) AS '#20214#25968'13,'
      #9'SUM('#20214#25968'14) AS '#20214#25968'14,'
      #9'SUM('#20214#25968'15) AS '#20214#25968'15,'
      #9'SUM('#20214#25968'16) AS '#20214#25968'16,'
      #9'SUM('#20214#25968'17) AS '#20214#25968'17,'
      #9'SUM('#20214#25968'18) AS '#20214#25968'18,'
      #9'SUM('#20214#25968'19) AS '#20214#25968'19,'
      #9'SUM('#20214#25968'20) AS '#20214#25968'20,'
      #9'SUM('#20214#25968'21) AS '#20214#25968'21,'
      #9'SUM('#20214#25968'22) AS '#20214#25968'22,'
      #9'SUM('#20214#25968'23) AS '#20214#25968'23,'
      #9'SUM('#20214#25968'24) AS '#20214#25968'24,'
      #9'SUM('#20214#25968'25) AS '#20214#25968'25,'
      #9'SUM('#20214#25968'26) AS '#20214#25968'26,'
      #9'SUM('#20214#25968'27) AS '#20214#25968'27,'
      #9'SUM('#20214#25968'28) AS '#20214#25968'28,'
      #9'SUM('#20214#25968'29) AS '#20214#25968'29,'
      #9'SUM('#20214#25968'30) AS '#20214#25968'30,'
      #9'SUM('#20214#25968'31) AS '#20214#25968'31,'
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
      #9'SUM('#37325#37327'13) AS '#37325#37327'13,'
      #9'SUM('#37325#37327'14) AS '#37325#37327'14,'
      #9'SUM('#37325#37327'15) AS '#37325#37327'15,'
      #9'SUM('#37325#37327'16) AS '#37325#37327'16,'
      #9'SUM('#37325#37327'17) AS '#37325#37327'17,'
      #9'SUM('#37325#37327'18) AS '#37325#37327'18,'
      #9'SUM('#37325#37327'19) AS '#37325#37327'19,'
      #9'SUM('#37325#37327'20) AS '#37325#37327'20,'
      #9'SUM('#37325#37327'21) AS '#37325#37327'21,'
      #9'SUM('#37325#37327'22) AS '#37325#37327'22,'
      #9'SUM('#37325#37327'23) AS '#37325#37327'23,'
      #9'SUM('#37325#37327'24) AS '#37325#37327'24,'
      #9'SUM('#37325#37327'25) AS '#37325#37327'25,'
      #9'SUM('#37325#37327'26) AS '#37325#37327'26,'
      #9'SUM('#37325#37327'27) AS '#37325#37327'27,'
      #9'SUM('#37325#37327'28) AS '#37325#37327'28,'
      #9'SUM('#37325#37327'29) AS '#37325#37327'29,'
      #9'SUM('#37325#37327'30) AS '#37325#37327'30,'
      #9'SUM('#37325#37327'31) AS '#37325#37327'31,'
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
      #9'SUM('#37329#38989'13) AS '#37329#38989'13,'
      #9'SUM('#37329#38989'14) AS '#37329#38989'14,'
      #9'SUM('#37329#38989'15) AS '#37329#38989'15,'
      #9'SUM('#37329#38989'16) AS '#37329#38989'16,'
      #9'SUM('#37329#38989'17) AS '#37329#38989'17,'
      #9'SUM('#37329#38989'18) AS '#37329#38989'18,'
      #9'SUM('#37329#38989'19) AS '#37329#38989'19,'
      #9'SUM('#37329#38989'20) AS '#37329#38989'20,'
      #9'SUM('#37329#38989'21) AS '#37329#38989'21,'
      #9'SUM('#37329#38989'22) AS '#37329#38989'22,'
      #9'SUM('#37329#38989'23) AS '#37329#38989'23,'
      #9'SUM('#37329#38989'24) AS '#37329#38989'24,'
      #9'SUM('#37329#38989'25) AS '#37329#38989'25,'
      #9'SUM('#37329#38989'26) AS '#37329#38989'26,'
      #9'SUM('#37329#38989'27) AS '#37329#38989'27,'
      #9'SUM('#37329#38989'28) AS '#37329#38989'28,'
      #9'SUM('#37329#38989'29) AS '#37329#38989'29,'
      #9'SUM('#37329#38989'30) AS '#37329#38989'30,'
      #9'SUM('#37329#38989'31) AS '#37329#38989'31'
      'FROM'
      #9'('
      #9'SELECT'
      #9#9#24471#24847#20808'ID AS '#38917#30446'ID, '#24471#24847#20808#12467#12540#12489' AS '#38917#30446#12467#12540#12489', '#24471#24847#20808#30053#31216' AS '#38917#30446#30053#31216','
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN 1 ELSE 0 END AS '#20214#25968'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN 1 ELSE 0 END AS '#20214#25968'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN 1 ELSE 0 END AS '#20214#25968'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN 1 ELSE 0 END AS '#20214#25968'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN 1 ELSE 0 END AS '#20214#25968'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN 1 ELSE 0 END AS '#20214#25968'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN 1 ELSE 0 END AS '#20214#25968'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN 1 ELSE 0 END AS '#20214#25968'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN 1 ELSE 0 END AS '#20214#25968'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN 1 ELSE 0 END AS '#20214#25968'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN 1 ELSE 0 END AS '#20214#25968'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN 1 ELSE 0 END AS '#20214#25968'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN 1 ELSE 0 END AS '#20214#25968'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN 1 ELSE 0 END AS '#20214#25968'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN 1 ELSE 0 END AS '#20214#25968'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN 1 ELSE 0 END AS '#20214#25968'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN 1 ELSE 0 END AS '#20214#25968'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN 1 ELSE 0 END AS '#20214#25968'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN 1 ELSE 0 END AS '#20214#25968'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN 1 ELSE 0 END AS '#20214#25968'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN 1 ELSE 0 END AS '#20214#25968'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN 1 ELSE 0 END AS '#20214#25968'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN 1 ELSE 0 END AS '#20214#25968'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN 1 ELSE 0 END AS '#20214#25968'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN 1 ELSE 0 END AS '#20214#25968'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN 1 ELSE 0 END AS '#20214#25968'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN 1 ELSE 0 END AS '#20214#25968'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN 1 ELSE 0 END AS '#20214#25968'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN 1 ELSE 0 END AS '#20214#25968'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN 1 ELSE 0 END AS '#20214#25968'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN 1 ELSE 0 END AS '#20214#25968'31,'
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'31,'
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'31'
      #9'FROM'
      #9#9'V_'#35336#37327
      #9'WHERE'
      #9#9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9#23436#20102#21306#20998' = 1'
      '/*'#9'$WHERE$*/'
      '/*'
      #9'AND'
      #9#9#24471#24847#20808#12467#12540#12489' = 2'
      #9'AND'
      #9#9#25312#28857'ID = 1'
      #9'AND'
      #9#9#25644#20837#20986#21306#20998' = 1'
      '*/'
      #9') AS D'
      'GROUP BY'
      #9#38917#30446'ID'
      'ORDER BY'
      #9#38917#30446#12467#12540#12489)
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
    object QueryDSDesigner13: TIntegerField
      FieldName = #20214#25968'13'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner14: TIntegerField
      FieldName = #20214#25968'14'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner15: TIntegerField
      FieldName = #20214#25968'15'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner16: TIntegerField
      FieldName = #20214#25968'16'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner17: TIntegerField
      FieldName = #20214#25968'17'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner18: TIntegerField
      FieldName = #20214#25968'18'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner19: TIntegerField
      FieldName = #20214#25968'19'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner20: TIntegerField
      FieldName = #20214#25968'20'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner21: TIntegerField
      FieldName = #20214#25968'21'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner22: TIntegerField
      FieldName = #20214#25968'22'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner23: TIntegerField
      FieldName = #20214#25968'23'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner24: TIntegerField
      FieldName = #20214#25968'24'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner25: TIntegerField
      FieldName = #20214#25968'25'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner26: TIntegerField
      FieldName = #20214#25968'26'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner27: TIntegerField
      FieldName = #20214#25968'27'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner28: TIntegerField
      FieldName = #20214#25968'28'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner29: TIntegerField
      FieldName = #20214#25968'29'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner30: TIntegerField
      FieldName = #20214#25968'30'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object QueryDSDesigner31: TIntegerField
      FieldName = #20214#25968'31'
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
    object QueryDSDesigner132: TBCDField
      FieldName = #37325#37327'13'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner142: TBCDField
      FieldName = #37325#37327'14'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner152: TBCDField
      FieldName = #37325#37327'15'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner162: TBCDField
      FieldName = #37325#37327'16'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner172: TBCDField
      FieldName = #37325#37327'17'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner182: TBCDField
      FieldName = #37325#37327'18'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner192: TBCDField
      FieldName = #37325#37327'19'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner202: TBCDField
      FieldName = #37325#37327'20'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner212: TBCDField
      FieldName = #37325#37327'21'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner222: TBCDField
      FieldName = #37325#37327'22'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner232: TBCDField
      FieldName = #37325#37327'23'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner242: TBCDField
      FieldName = #37325#37327'24'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner252: TBCDField
      FieldName = #37325#37327'25'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner262: TBCDField
      FieldName = #37325#37327'26'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner272: TBCDField
      FieldName = #37325#37327'27'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner282: TBCDField
      FieldName = #37325#37327'28'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner292: TBCDField
      FieldName = #37325#37327'29'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner302: TBCDField
      FieldName = #37325#37327'30'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner312: TBCDField
      FieldName = #37325#37327'31'
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
    object QueryDSDesigner133: TBCDField
      FieldName = #37329#38989'13'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner143: TBCDField
      FieldName = #37329#38989'14'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner153: TBCDField
      FieldName = #37329#38989'15'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner163: TBCDField
      FieldName = #37329#38989'16'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner173: TBCDField
      FieldName = #37329#38989'17'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner183: TBCDField
      FieldName = #37329#38989'18'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner193: TBCDField
      FieldName = #37329#38989'19'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner203: TBCDField
      FieldName = #37329#38989'20'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner213: TBCDField
      FieldName = #37329#38989'21'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner223: TBCDField
      FieldName = #37329#38989'22'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner233: TBCDField
      FieldName = #37329#38989'23'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner243: TBCDField
      FieldName = #37329#38989'24'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner253: TBCDField
      FieldName = #37329#38989'25'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner263: TBCDField
      FieldName = #37329#38989'26'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner273: TBCDField
      FieldName = #37329#38989'27'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner283: TBCDField
      FieldName = #37329#38989'28'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner293: TBCDField
      FieldName = #37329#38989'29'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner303: TBCDField
      FieldName = #37329#38989'30'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object QueryDSDesigner313: TBCDField
      FieldName = #37329#38989'31'
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
      #9'SUM('#20214#25968'13) AS '#20214#25968'13,'
      #9'SUM('#20214#25968'14) AS '#20214#25968'14,'
      #9'SUM('#20214#25968'15) AS '#20214#25968'15,'
      #9'SUM('#20214#25968'16) AS '#20214#25968'16,'
      #9'SUM('#20214#25968'17) AS '#20214#25968'17,'
      #9'SUM('#20214#25968'18) AS '#20214#25968'18,'
      #9'SUM('#20214#25968'19) AS '#20214#25968'19,'
      #9'SUM('#20214#25968'20) AS '#20214#25968'20,'
      #9'SUM('#20214#25968'21) AS '#20214#25968'21,'
      #9'SUM('#20214#25968'22) AS '#20214#25968'22,'
      #9'SUM('#20214#25968'23) AS '#20214#25968'23,'
      #9'SUM('#20214#25968'24) AS '#20214#25968'24,'
      #9'SUM('#20214#25968'25) AS '#20214#25968'25,'
      #9'SUM('#20214#25968'26) AS '#20214#25968'26,'
      #9'SUM('#20214#25968'27) AS '#20214#25968'27,'
      #9'SUM('#20214#25968'28) AS '#20214#25968'28,'
      #9'SUM('#20214#25968'29) AS '#20214#25968'29,'
      #9'SUM('#20214#25968'30) AS '#20214#25968'30,'
      #9'SUM('#20214#25968'31) AS '#20214#25968'31,'
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
      #9'SUM('#37325#37327'13) AS '#37325#37327'13,'
      #9'SUM('#37325#37327'14) AS '#37325#37327'14,'
      #9'SUM('#37325#37327'15) AS '#37325#37327'15,'
      #9'SUM('#37325#37327'16) AS '#37325#37327'16,'
      #9'SUM('#37325#37327'17) AS '#37325#37327'17,'
      #9'SUM('#37325#37327'18) AS '#37325#37327'18,'
      #9'SUM('#37325#37327'19) AS '#37325#37327'19,'
      #9'SUM('#37325#37327'20) AS '#37325#37327'20,'
      #9'SUM('#37325#37327'21) AS '#37325#37327'21,'
      #9'SUM('#37325#37327'22) AS '#37325#37327'22,'
      #9'SUM('#37325#37327'23) AS '#37325#37327'23,'
      #9'SUM('#37325#37327'24) AS '#37325#37327'24,'
      #9'SUM('#37325#37327'25) AS '#37325#37327'25,'
      #9'SUM('#37325#37327'26) AS '#37325#37327'26,'
      #9'SUM('#37325#37327'27) AS '#37325#37327'27,'
      #9'SUM('#37325#37327'28) AS '#37325#37327'28,'
      #9'SUM('#37325#37327'29) AS '#37325#37327'29,'
      #9'SUM('#37325#37327'30) AS '#37325#37327'30,'
      #9'SUM('#37325#37327'31) AS '#37325#37327'31,'
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
      #9'SUM('#37329#38989'13) AS '#37329#38989'13,'
      #9'SUM('#37329#38989'14) AS '#37329#38989'14,'
      #9'SUM('#37329#38989'15) AS '#37329#38989'15,'
      #9'SUM('#37329#38989'16) AS '#37329#38989'16,'
      #9'SUM('#37329#38989'17) AS '#37329#38989'17,'
      #9'SUM('#37329#38989'18) AS '#37329#38989'18,'
      #9'SUM('#37329#38989'19) AS '#37329#38989'19,'
      #9'SUM('#37329#38989'20) AS '#37329#38989'20,'
      #9'SUM('#37329#38989'21) AS '#37329#38989'21,'
      #9'SUM('#37329#38989'22) AS '#37329#38989'22,'
      #9'SUM('#37329#38989'23) AS '#37329#38989'23,'
      #9'SUM('#37329#38989'24) AS '#37329#38989'24,'
      #9'SUM('#37329#38989'25) AS '#37329#38989'25,'
      #9'SUM('#37329#38989'26) AS '#37329#38989'26,'
      #9'SUM('#37329#38989'27) AS '#37329#38989'27,'
      #9'SUM('#37329#38989'28) AS '#37329#38989'28,'
      #9'SUM('#37329#38989'29) AS '#37329#38989'29,'
      #9'SUM('#37329#38989'30) AS '#37329#38989'30,'
      #9'SUM('#37329#38989'31) AS '#37329#38989'31'
      'FROM'
      #9'('
      #9'SELECT'
      #9#9#24471#24847#20808'ID AS '#38917#30446'ID, '#24471#24847#20808#12467#12540#12489' AS '#38917#30446#12467#12540#12489', '#24471#24847#20808#30053#31216' AS '#38917#30446#30053#31216','
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN 1 ELSE 0 END AS '#20214#25968'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN 1 ELSE 0 END AS '#20214#25968'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN 1 ELSE 0 END AS '#20214#25968'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN 1 ELSE 0 END AS '#20214#25968'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN 1 ELSE 0 END AS '#20214#25968'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN 1 ELSE 0 END AS '#20214#25968'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN 1 ELSE 0 END AS '#20214#25968'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN 1 ELSE 0 END AS '#20214#25968'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN 1 ELSE 0 END AS '#20214#25968'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN 1 ELSE 0 END AS '#20214#25968'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN 1 ELSE 0 END AS '#20214#25968'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN 1 ELSE 0 END AS '#20214#25968'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN 1 ELSE 0 END AS '#20214#25968'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN 1 ELSE 0 END AS '#20214#25968'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN 1 ELSE 0 END AS '#20214#25968'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN 1 ELSE 0 END AS '#20214#25968'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN 1 ELSE 0 END AS '#20214#25968'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN 1 ELSE 0 END AS '#20214#25968'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN 1 ELSE 0 END AS '#20214#25968'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN 1 ELSE 0 END AS '#20214#25968'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN 1 ELSE 0 END AS '#20214#25968'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN 1 ELSE 0 END AS '#20214#25968'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN 1 ELSE 0 END AS '#20214#25968'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN 1 ELSE 0 END AS '#20214#25968'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN 1 ELSE 0 END AS '#20214#25968'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN 1 ELSE 0 END AS '#20214#25968'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN 1 ELSE 0 END AS '#20214#25968'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN 1 ELSE 0 END AS '#20214#25968'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN 1 ELSE 0 END AS '#20214#25968'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN 1 ELSE 0 END AS '#20214#25968'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN 1 ELSE 0 END AS '#20214#25968'31,'
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#37325#37327'31,'
      #9
      #9#9'CASE WHEN '#26085' =  1 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN '#37329#38989' ELSE 0 END AS '#37329#38989'31'
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
    object IntegerField15: TIntegerField
      FieldName = #20214#25968'13'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField16: TIntegerField
      FieldName = #20214#25968'14'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField17: TIntegerField
      FieldName = #20214#25968'15'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField18: TIntegerField
      FieldName = #20214#25968'16'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField19: TIntegerField
      FieldName = #20214#25968'17'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField20: TIntegerField
      FieldName = #20214#25968'18'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField21: TIntegerField
      FieldName = #20214#25968'19'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField22: TIntegerField
      FieldName = #20214#25968'20'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField23: TIntegerField
      FieldName = #20214#25968'21'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField24: TIntegerField
      FieldName = #20214#25968'22'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField25: TIntegerField
      FieldName = #20214#25968'23'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField26: TIntegerField
      FieldName = #20214#25968'24'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField27: TIntegerField
      FieldName = #20214#25968'25'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField28: TIntegerField
      FieldName = #20214#25968'26'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField29: TIntegerField
      FieldName = #20214#25968'27'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField30: TIntegerField
      FieldName = #20214#25968'28'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField31: TIntegerField
      FieldName = #20214#25968'29'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField32: TIntegerField
      FieldName = #20214#25968'30'
      ReadOnly = True
      DisplayFormat = '#,###'
    end
    object IntegerField33: TIntegerField
      FieldName = #20214#25968'31'
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
    object BCDField13: TBCDField
      FieldName = #37325#37327'13'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField14: TBCDField
      FieldName = #37325#37327'14'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField15: TBCDField
      FieldName = #37325#37327'15'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField16: TBCDField
      FieldName = #37325#37327'16'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField17: TBCDField
      FieldName = #37325#37327'17'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField18: TBCDField
      FieldName = #37325#37327'18'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField19: TBCDField
      FieldName = #37325#37327'19'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField20: TBCDField
      FieldName = #37325#37327'20'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField21: TBCDField
      FieldName = #37325#37327'21'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField22: TBCDField
      FieldName = #37325#37327'22'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField23: TBCDField
      FieldName = #37325#37327'23'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField24: TBCDField
      FieldName = #37325#37327'24'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField25: TBCDField
      FieldName = #37325#37327'25'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField26: TBCDField
      FieldName = #37325#37327'26'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField27: TBCDField
      FieldName = #37325#37327'27'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField28: TBCDField
      FieldName = #37325#37327'28'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField29: TBCDField
      FieldName = #37325#37327'29'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField30: TBCDField
      FieldName = #37325#37327'30'
      ReadOnly = True
      DisplayFormat = '#,###.#'
      Precision = 32
      Size = 1
    end
    object BCDField31: TBCDField
      FieldName = #37325#37327'31'
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
    object BCDField44: TBCDField
      FieldName = #37329#38989'13'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField45: TBCDField
      FieldName = #37329#38989'14'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField46: TBCDField
      FieldName = #37329#38989'15'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField47: TBCDField
      FieldName = #37329#38989'16'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField48: TBCDField
      FieldName = #37329#38989'17'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField49: TBCDField
      FieldName = #37329#38989'18'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField50: TBCDField
      FieldName = #37329#38989'19'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField51: TBCDField
      FieldName = #37329#38989'20'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField52: TBCDField
      FieldName = #37329#38989'21'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField53: TBCDField
      FieldName = #37329#38989'22'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField54: TBCDField
      FieldName = #37329#38989'23'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField55: TBCDField
      FieldName = #37329#38989'24'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField56: TBCDField
      FieldName = #37329#38989'25'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField57: TBCDField
      FieldName = #37329#38989'26'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField58: TBCDField
      FieldName = #37329#38989'27'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField59: TBCDField
      FieldName = #37329#38989'28'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField60: TBCDField
      FieldName = #37329#38989'29'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField61: TBCDField
      FieldName = #37329#38989'30'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object BCDField62: TBCDField
      FieldName = #37329#38989'31'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
  end
end
