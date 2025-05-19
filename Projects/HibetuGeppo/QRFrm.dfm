object QRForm: TQRForm
  Left = 499
  Top = 1
  Width = 1036
  Height = 780
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
    Page.Columns = 7
    Page.Orientation = poLandscape
    Page.PaperSize = A4
    Page.Values = (
      100
      2100
      100
      2970
      250
      100
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
      Left = 40
      Top = 96
      Width = 1045
      Height = 661
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        1748.89583333333
        105.833333333333
        254
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsRectangle
    end
    object PageHeaderBand1: TQRBand
      Left = 94
      Top = 38
      Width = 991
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
        2622.02083333333)
      BandType = rbPageHeader
      object QRLabel1: TQRLabel
        Left = 415
        Top = 0
        Width = 161
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          1098.02083333333
          0
          425.979166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #26989#32773#21029#37528#26564#21029#26085#21029#26376#22577
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
        Left = 898
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
          2375.95833333333
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
      object QRDBText13: TQRDBText
        Left = 16
        Top = 42
        Width = 41
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
          108.479166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#12467#12540#12489
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText12: TQRDBText
        Left = 64
        Top = 42
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          169.333333333333
          111.125
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #24471#24847#20808#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object RangeLabel: TQRLabel
        Left = 16
        Top = 26
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
          68.7916666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 40
      Top = 64
      Width = 61
      Height = 13
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        34.3958333333333
        105.833333333333
        169.333333333333
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
    object QRLabel2: TQRLabel
      Left = 40
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
        105.833333333333
        211.666666666667
        161.395833333333)
      Alignment = taLeftJustify
      AlignToBand = False
      AutoSize = True
      AutoStretch = False
      Caption = #26989#12288#12288#32773#65306
      Color = clWhite
      Transparent = False
      WordWrap = True
      FontSize = 9
    end
    object QRSysData1: TQRSysData
      Left = 39
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
        103.1875
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
      Left = 94
      Top = 101
      Width = 141
      Height = 656
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
        1735.66666666667
        373.0625)
      BandType = rbDetail
      object QRDBText1: TQRDBText
        Left = 8
        Top = 10
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
          26.4583333333333
          129.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21697#30446#30053#31216
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
        DataField = #27491#21619#37325#37327'01'
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
        DataField = #27491#21619#37325#37327'02'
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
        DataField = #27491#21619#37325#37327'03'
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
        DataField = #27491#21619#37325#37327'04'
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
        DataField = #27491#21619#37325#37327'05'
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
        DataField = #27491#21619#37325#37327'06'
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
        DataField = #27491#21619#37325#37327'07'
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
        DataField = #27491#21619#37325#37327'08'
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
        DataField = #27491#21619#37325#37327'09'
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
        DataField = #27491#21619#37325#37327'10'
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
        DataField = #27491#21619#37325#37327'11'
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
        DataField = #27491#21619#37325#37327'12'
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
        DataField = #27491#21619#37325#37327'13'
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
        DataField = #27491#21619#37325#37327'14'
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
        DataField = #27491#21619#37325#37327'15'
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
        DataField = #27491#21619#37325#37327'16'
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
        DataField = #27491#21619#37325#37327'17'
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
        DataField = #27491#21619#37325#37327'18'
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
        DataField = #27491#21619#37325#37327'19'
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
        DataField = #27491#21619#37325#37327'20'
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
        DataField = #27491#21619#37325#37327'21'
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
        DataField = #27491#21619#37325#37327'22'
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
        DataField = #27491#21619#37325#37327'23'
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
        DataField = #27491#21619#37325#37327'24'
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
        DataField = #27491#21619#37325#37327'25'
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
        DataField = #27491#21619#37325#37327'26'
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
        DataField = #27491#21619#37325#37327'27'
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
        DataField = #27491#21619#37325#37327'28'
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
        DataField = #27491#21619#37325#37327'29'
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
        DataField = #27491#21619#37325#37327'30'
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
        DataField = #27491#21619#37325#37327'31'
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
          'Query.'#27491#21619#37325#37327'01 + Query.'#27491#21619#37325#37327'02 + Query.'#27491#21619#37325#37327'03 + Query.'#27491#21619#37325#37327'04 + Quer' +
          'y.'#27491#21619#37325#37327'05 + Query.'#27491#21619#37325#37327'06 + Query.'#27491#21619#37325#37327'07 + Query.'#27491#21619#37325#37327'08 + Query.'#27491#21619 +
          #37325#37327'09 + Query.'#27491#21619#37325#37327'10 + Query.'#27491#21619#37325#37327'11 + Query.'#27491#21619#37325#37327'12 + Query.'#27491#21619#37325#37327'13' +
          ' + Query.'#27491#21619#37325#37327'14 + Query.'#27491#21619#37325#37327'15 + Query.'#27491#21619#37325#37327'16 + Query.'#27491#21619#37325#37327'17 + Q' +
          'uery.'#27491#21619#37325#37327'18 + Query.'#27491#21619#37325#37327'19 + Query.'#27491#21619#37325#37327'20 + Query.'#27491#21619#37325#37327'21 + Query' +
          '.'#27491#21619#37325#37327'22 + Query.'#27491#21619#37325#37327'23 + Query.'#27491#21619#37325#37327'24 + Query.'#27491#21619#37325#37327'25 + Query.'#27491#21619#37325 +
          #37327'26 + Query.'#27491#21619#37325#37327'27 + Query.'#27491#21619#37325#37327'28 + Query.'#27491#21619#37325#37327'29 + Query.'#27491#21619#37325#37327'30 ' +
          '+ Query.'#27491#21619#37325#37327'31'
        Mask = '#,###'
        FontSize = 9
      end
    end
    object DateLabel03: TQRLabel
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 45
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
        119.0625
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 44
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
        116.416666666667
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
      Left = 49
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
        129.645833333333
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
      Left = 44
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
        116.416666666667
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
    object QRGroup1: TQRGroup
      Left = 94
      Top = 97
      Width = 141
      Height = 4
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
        10.5833333333333
        373.0625)
      Expression = 'Query.'#24471#24847#20808#12467#12540#12489
      FooterBand = QRBand1
      Master = QuickRep
      ReprintOnNewPage = False
    end
    object QRShape1: TQRShape
      Left = 93
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
        246.0625
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape3: TQRShape
      Left = 233
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
        616.479166666667
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRBand1: TQRBand
      Left = 94
      Top = 757
      Width = 141
      Height = 5
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      AlignToBottom = False
      Color = clWhite
      ForceNewColumn = True
      ForceNewPage = False
      Size.Values = (
        13.2291666666667
        373.0625)
      BandType = rbGroupFooter
    end
    object QRShape4: TQRShape
      Left = 373
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
        986.895833333333
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape5: TQRShape
      Left = 513
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
        1357.3125
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape6: TQRShape
      Left = 653
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
        1727.72916666667
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape7: TQRShape
      Left = 793
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
        2098.14583333333
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape8: TQRShape
      Left = 933
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
        2468.5625
        254
        5.29166666666667)
      Brush.Style = bsClear
      Shape = qrsVertLine
    end
    object QRShape9: TQRShape
      Left = 40
      Top = 148
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        391.583333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape10: TQRShape
      Left = 40
      Top = 167
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        441.854166666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape11: TQRShape
      Left = 40
      Top = 185
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        489.479166666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape12: TQRShape
      Left = 40
      Top = 204
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        539.75
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape13: TQRShape
      Left = 40
      Top = 223
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        590.020833333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape14: TQRShape
      Left = 40
      Top = 242
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        640.291666666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape15: TQRShape
      Left = 40
      Top = 261
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        690.5625
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape16: TQRShape
      Left = 40
      Top = 280
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        740.833333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape17: TQRShape
      Left = 40
      Top = 298
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        788.458333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape18: TQRShape
      Left = 40
      Top = 317
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        838.729166666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape19: TQRShape
      Left = 40
      Top = 336
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        889
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape20: TQRShape
      Left = 40
      Top = 355
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        939.270833333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape21: TQRShape
      Left = 40
      Top = 374
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        989.541666666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape22: TQRShape
      Left = 40
      Top = 393
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1039.8125
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape23: TQRShape
      Left = 40
      Top = 412
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1090.08333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape24: TQRShape
      Left = 40
      Top = 431
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1140.35416666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape25: TQRShape
      Left = 40
      Top = 450
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1190.625
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape26: TQRShape
      Left = 40
      Top = 469
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1240.89583333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape27: TQRShape
      Left = 40
      Top = 488
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1291.16666666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape28: TQRShape
      Left = 40
      Top = 506
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1338.79166666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape29: TQRShape
      Left = 40
      Top = 525
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1389.0625
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape30: TQRShape
      Left = 40
      Top = 544
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1439.33333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape31: TQRShape
      Left = 40
      Top = 563
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1489.60416666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape32: TQRShape
      Left = 40
      Top = 582
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1539.875
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape33: TQRShape
      Left = 40
      Top = 601
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1590.14583333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape34: TQRShape
      Left = 40
      Top = 619
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1637.77083333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape35: TQRShape
      Left = 40
      Top = 638
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1688.04166666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape36: TQRShape
      Left = 40
      Top = 657
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1738.3125
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape37: TQRShape
      Left = 40
      Top = 676
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1788.58333333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape38: TQRShape
      Left = 40
      Top = 695
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1838.85416666667
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape39: TQRShape
      Left = 40
      Top = 714
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1889.125
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRShape40: TQRShape
      Left = 40
      Top = 733
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        1939.39583333333
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRLabel9: TQRLabel
      Left = 52
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
        137.583333333333
        285.75
        82.0208333333333)
      Alignment = taLeftJustify
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
      Left = 40
      Top = 126
      Width = 1045
      Height = 1
      Frame.Color = clBlack
      Frame.DrawTop = False
      Frame.DrawBottom = False
      Frame.DrawLeft = False
      Frame.DrawRight = False
      Size.Values = (
        2.64583333333333
        105.833333333333
        333.375
        2764.89583333333)
      Brush.Style = bsClear
      Shape = qrsHorLine
    end
    object QRLabel10: TQRLabel
      Left = 52
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
        137.583333333333
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
      Left = 157
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
        415.395833333333
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape43: TQRShape
      Left = 297
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
        785.8125
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape44: TQRShape
      Left = 437
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
        1156.22916666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape45: TQRShape
      Left = 577
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
        1526.64583333333
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape46: TQRShape
      Left = 717
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
        1897.0625
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape47: TQRShape
      Left = 857
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
        2267.47916666667
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRShape48: TQRShape
      Left = 997
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
        2637.89583333333
        338.666666666667
        5.29166666666667)
      Brush.Style = bsClear
      Pen.Style = psDot
      Shape = qrsVertLine
    end
    object QRChildBand1: TQRChildBand
      Left = 94
      Top = 762
      Width = 141
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
        373.0625)
      ParentBand = QRBand1
      object QRLabel4: TQRLabel
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
      object QRLabel5: TQRLabel
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
      object QRExpr1: TQRExpr
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
      object QRExpr2: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'01)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr3: TQRExpr
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
      object QRExpr4: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'02)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr5: TQRExpr
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
      object QRExpr6: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'03)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr7: TQRExpr
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
      object QRExpr8: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'04)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr9: TQRExpr
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
      object QRExpr10: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'05)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr11: TQRExpr
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
      object QRExpr12: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'06)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr13: TQRExpr
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
      object QRExpr14: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'07)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr15: TQRExpr
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
      object QRExpr16: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'08)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr17: TQRExpr
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
      object QRExpr18: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'09)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr19: TQRExpr
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
      object QRExpr20: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'10)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr21: TQRExpr
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
      object QRExpr22: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'11)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr23: TQRExpr
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
      object QRExpr24: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'12)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr25: TQRExpr
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
      object QRExpr26: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'13)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr27: TQRExpr
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
      object QRExpr28: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'14)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr29: TQRExpr
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
      object QRExpr30: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'15)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr31: TQRExpr
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
      object QRExpr32: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'16)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr33: TQRExpr
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
      object QRExpr34: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'17)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr35: TQRExpr
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
      object QRExpr36: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'18)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr37: TQRExpr
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
      object QRExpr38: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'19)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr39: TQRExpr
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
      object QRExpr40: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'20)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr41: TQRExpr
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
      object QRExpr42: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'21)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr43: TQRExpr
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
      object QRExpr44: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'22)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr45: TQRExpr
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
      object QRExpr46: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'23)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr47: TQRExpr
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
      object QRExpr48: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'24)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr49: TQRExpr
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
      object QRExpr50: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'25)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr51: TQRExpr
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
      object QRExpr52: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'26)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr53: TQRExpr
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
      object QRExpr54: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'27)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr55: TQRExpr
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
      object QRExpr56: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'28)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr57: TQRExpr
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
      object QRExpr58: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'29)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr59: TQRExpr
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
      object QRExpr60: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'30)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr61: TQRExpr
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
      object QRExpr62: TQRExpr
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
          'SUM(Query.'#27491#21619#37325#37327'01) + SUM(Query.'#27491#21619#37325#37327'02) + SUM(Query.'#27491#21619#37325#37327'03) + SUM(' +
          'Query.'#27491#21619#37325#37327'04) + SUM(Query.'#27491#21619#37325#37327'05) + SUM(Query.'#27491#21619#37325#37327'06) + SUM(Quer' +
          'y.'#27491#21619#37325#37327'07) + SUM(Query.'#27491#21619#37325#37327'08) + SUM(Query.'#27491#21619#37325#37327'09) + SUM(Query.'#27491#21619 +
          #37325#37327'10) + SUM(Query.'#27491#21619#37325#37327'11) + SUM(Query.'#27491#21619#37325#37327'12) + SUM(Query.'#27491#21619#37325#37327'13' +
          ') + SUM(Query.'#27491#21619#37325#37327'14) + SUM(Query.'#27491#21619#37325#37327'15) + SUM(Query.'#27491#21619#37325#37327'16) + ' +
          'SUM(Query.'#27491#21619#37325#37327'17) + SUM(Query.'#27491#21619#37325#37327'18) + SUM(Query.'#27491#21619#37325#37327'19) + SUM(' +
          'Query.'#27491#21619#37325#37327'20) + SUM(Query.'#27491#21619#37325#37327'21) + SUM(Query.'#27491#21619#37325#37327'22) + SUM(Quer' +
          'y.'#27491#21619#37325#37327'23) + SUM(Query.'#27491#21619#37325#37327'24) + SUM(Query.'#27491#21619#37325#37327'25) + SUM(Query.'#27491#21619 +
          #37325#37327'26) + SUM(Query.'#27491#21619#37325#37327'27) + SUM(Query.'#27491#21619#37325#37327'28) + SUM(Query.'#27491#21619#37325#37327'29' +
          ') + SUM(Query.'#27491#21619#37325#37327'30) + SUM(Query.'#27491#21619#37325#37327'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRExpr63: TQRExpr
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
      object QRExpr64: TQRExpr
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
        Expression = 'SUM(Query.'#27491#21619#37325#37327'31)'
        Mask = '#,###'
        FontSize = 9
      end
      object QRLabel6: TQRLabel
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
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216', '#24471#24847#20808#30053#31216','
      #9#21697#30446#12467#12540#12489', '#21697#30446#21517#31216', '#21697#30446#30053#31216','
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
      #9'SUM('#27491#21619#37325#37327'01) AS '#27491#21619#37325#37327'01,'
      #9'SUM('#27491#21619#37325#37327'02) AS '#27491#21619#37325#37327'02,'
      #9'SUM('#27491#21619#37325#37327'03) AS '#27491#21619#37325#37327'03,'
      #9'SUM('#27491#21619#37325#37327'04) AS '#27491#21619#37325#37327'04,'
      #9'SUM('#27491#21619#37325#37327'05) AS '#27491#21619#37325#37327'05,'
      #9'SUM('#27491#21619#37325#37327'06) AS '#27491#21619#37325#37327'06,'
      #9'SUM('#27491#21619#37325#37327'07) AS '#27491#21619#37325#37327'07,'
      #9'SUM('#27491#21619#37325#37327'08) AS '#27491#21619#37325#37327'08,'
      #9'SUM('#27491#21619#37325#37327'09) AS '#27491#21619#37325#37327'09,'
      #9'SUM('#27491#21619#37325#37327'10) AS '#27491#21619#37325#37327'10,'
      #9'SUM('#27491#21619#37325#37327'11) AS '#27491#21619#37325#37327'11,'
      #9'SUM('#27491#21619#37325#37327'12) AS '#27491#21619#37325#37327'12,'
      #9'SUM('#27491#21619#37325#37327'13) AS '#27491#21619#37325#37327'13,'
      #9'SUM('#27491#21619#37325#37327'14) AS '#27491#21619#37325#37327'14,'
      #9'SUM('#27491#21619#37325#37327'15) AS '#27491#21619#37325#37327'15,'
      #9'SUM('#27491#21619#37325#37327'16) AS '#27491#21619#37325#37327'16,'
      #9'SUM('#27491#21619#37325#37327'17) AS '#27491#21619#37325#37327'17,'
      #9'SUM('#27491#21619#37325#37327'18) AS '#27491#21619#37325#37327'18,'
      #9'SUM('#27491#21619#37325#37327'19) AS '#27491#21619#37325#37327'19,'
      #9'SUM('#27491#21619#37325#37327'20) AS '#27491#21619#37325#37327'20,'
      #9'SUM('#27491#21619#37325#37327'21) AS '#27491#21619#37325#37327'21,'
      #9'SUM('#27491#21619#37325#37327'22) AS '#27491#21619#37325#37327'22,'
      #9'SUM('#27491#21619#37325#37327'23) AS '#27491#21619#37325#37327'23,'
      #9'SUM('#27491#21619#37325#37327'24) AS '#27491#21619#37325#37327'24,'
      #9'SUM('#27491#21619#37325#37327'25) AS '#27491#21619#37325#37327'25,'
      #9'SUM('#27491#21619#37325#37327'26) AS '#27491#21619#37325#37327'26,'
      #9'SUM('#27491#21619#37325#37327'27) AS '#27491#21619#37325#37327'27,'
      #9'SUM('#27491#21619#37325#37327'28) AS '#27491#21619#37325#37327'28,'
      #9'SUM('#27491#21619#37325#37327'29) AS '#27491#21619#37325#37327'29,'
      #9'SUM('#27491#21619#37325#37327'30) AS '#27491#21619#37325#37327'30,'
      #9'SUM('#27491#21619#37325#37327'31) AS '#27491#21619#37325#37327'31'
      ''
      'FROM'
      #9'('
      #9'SELECT'
      #9#9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216', '#24471#24847#20808#30053#31216','
      #9#9#21697#30446#12467#12540#12489', '#21697#30446#21517#31216', '#21697#30446#30053#31216','
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
      #9#9'CASE WHEN '#26085' =  1 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'01,'
      #9#9'CASE WHEN '#26085' =  2 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'02,'
      #9#9'CASE WHEN '#26085' =  3 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'03,'
      #9#9'CASE WHEN '#26085' =  4 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'04,'
      #9#9'CASE WHEN '#26085' =  5 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'05,'
      #9#9'CASE WHEN '#26085' =  6 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'06,'
      #9#9'CASE WHEN '#26085' =  7 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'07,'
      #9#9'CASE WHEN '#26085' =  8 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'08,'
      #9#9'CASE WHEN '#26085' =  9 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'09,'
      #9#9'CASE WHEN '#26085' = 10 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'10,'
      #9#9'CASE WHEN '#26085' = 11 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'11,'
      #9#9'CASE WHEN '#26085' = 12 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'12,'
      #9#9'CASE WHEN '#26085' = 13 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'13,'
      #9#9'CASE WHEN '#26085' = 14 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'14,'
      #9#9'CASE WHEN '#26085' = 15 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'15,'
      #9#9'CASE WHEN '#26085' = 16 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'16,'
      #9#9'CASE WHEN '#26085' = 17 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'17,'
      #9#9'CASE WHEN '#26085' = 18 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'18,'
      #9#9'CASE WHEN '#26085' = 19 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'19,'
      #9#9'CASE WHEN '#26085' = 20 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'20,'
      #9#9'CASE WHEN '#26085' = 21 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'21,'
      #9#9'CASE WHEN '#26085' = 22 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'22,'
      #9#9'CASE WHEN '#26085' = 23 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'23,'
      #9#9'CASE WHEN '#26085' = 24 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'24,'
      #9#9'CASE WHEN '#26085' = 25 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'25,'
      #9#9'CASE WHEN '#26085' = 26 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'26,'
      #9#9'CASE WHEN '#26085' = 27 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'27,'
      #9#9'CASE WHEN '#26085' = 28 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'28,'
      #9#9'CASE WHEN '#26085' = 29 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'29,'
      #9#9'CASE WHEN '#26085' = 30 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'30,'
      #9#9'CASE WHEN '#26085' = 31 THEN '#27491#21619#37325#37327' ELSE 0 END AS '#27491#21619#37325#37327'31'
      #9'FROM'#9
      #9#9'V_'#35336#37327
      #9'WHERE'
      #9#9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9#23436#20102#21306#20998' = 1'
      ''
      #9'-- AND '#24471#24847#20808#12467#12540#12489' = 1'#9#9'/* '#12503#12525#12464#12521#12512#20013#12391#21046#24481' */'
      '--'
      #9') AS X'
      ''
      'GROUP BY'
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216', '#24471#24847#20808#30053#31216','
      #9#21697#30446#12467#12540#12489', '#21697#30446#21517#31216', '#21697#30446#30053#31216
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489', '#21697#30446#12467#12540#12489)
    Left = 24
    Top = 16
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
      FieldName = #21697#30446#12467#12540#12489
    end
    object QueryDSDesigner5: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object QueryDSDesigner6: TStringField
      FieldName = #21697#30446#30053#31216
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
      FieldName = #27491#21619#37325#37327'01'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner022: TBCDField
      FieldName = #27491#21619#37325#37327'02'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner032: TBCDField
      FieldName = #27491#21619#37325#37327'03'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner042: TBCDField
      FieldName = #27491#21619#37325#37327'04'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner052: TBCDField
      FieldName = #27491#21619#37325#37327'05'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner062: TBCDField
      FieldName = #27491#21619#37325#37327'06'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner072: TBCDField
      FieldName = #27491#21619#37325#37327'07'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner082: TBCDField
      FieldName = #27491#21619#37325#37327'08'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner092: TBCDField
      FieldName = #27491#21619#37325#37327'09'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner102: TBCDField
      FieldName = #27491#21619#37325#37327'10'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner112: TBCDField
      FieldName = #27491#21619#37325#37327'11'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner122: TBCDField
      FieldName = #27491#21619#37325#37327'12'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner132: TBCDField
      FieldName = #27491#21619#37325#37327'13'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner142: TBCDField
      FieldName = #27491#21619#37325#37327'14'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner152: TBCDField
      FieldName = #27491#21619#37325#37327'15'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner162: TBCDField
      FieldName = #27491#21619#37325#37327'16'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner172: TBCDField
      FieldName = #27491#21619#37325#37327'17'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner182: TBCDField
      FieldName = #27491#21619#37325#37327'18'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner192: TBCDField
      FieldName = #27491#21619#37325#37327'19'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner202: TBCDField
      FieldName = #27491#21619#37325#37327'20'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner212: TBCDField
      FieldName = #27491#21619#37325#37327'21'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner222: TBCDField
      FieldName = #27491#21619#37325#37327'22'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner232: TBCDField
      FieldName = #27491#21619#37325#37327'23'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner242: TBCDField
      FieldName = #27491#21619#37325#37327'24'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner252: TBCDField
      FieldName = #27491#21619#37325#37327'25'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner262: TBCDField
      FieldName = #27491#21619#37325#37327'26'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner272: TBCDField
      FieldName = #27491#21619#37325#37327'27'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner282: TBCDField
      FieldName = #27491#21619#37325#37327'28'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner292: TBCDField
      FieldName = #27491#21619#37325#37327'29'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner302: TBCDField
      FieldName = #27491#21619#37325#37327'30'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner312: TBCDField
      FieldName = #27491#21619#37325#37327'31'
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
  end
end
