object QRForm: TQRForm
  Left = 1307
  Top = 98
  Width = 1136
  Height = 812
  HorzScrollBar.Position = 16
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
    Left = -12
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
    object PageHeaderBand1: TQRBand
      Left = 38
      Top = 38
      Width = 1066
      Height = 58
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
        153.458333333333
        2820.45833333333)
      BandType = rbPageHeader
      object QRLabel1: TQRLabel
        Left = 452
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
          1195.91666666667
          0
          425.979166666667)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '*** '#26410#20837#37329#19968#35239#34920' ***'
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
      object QRShape1: TQRShape
        Left = 0
        Top = 38
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
          100.541666666667
          2820.45833333333)
        Shape = qrsHorLine
      end
      object QRShape2: TQRShape
        Left = 0
        Top = 57
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
          150.8125
          2820.45833333333)
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
        Left = 48
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
          127
          111.125
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35531#27714#20808#21517#31216
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel6: TQRLabel
        Left = 376
        Top = 42
        Width = 37
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          994.833333333333
          111.125
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35531#27714#26085
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel7: TQRLabel
        Left = 452
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
          1195.91666666667
          111.125
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20837#37329#20104#23450#26085
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel8: TQRLabel
        Left = 524
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
          1386.41666666667
          111.125
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #19981#36275#38989
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel9: TQRLabel
        Left = 624
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
          1651
          111.125
          209.020833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #24310#28382#29702#30001
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRLabel5: TQRLabel
        Left = 996
        Top = 42
        Width = 37
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          2635.25
          111.125
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20837#37329#26085
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
    end
    object DetailBand1: TQRBand
      Left = 38
      Top = 96
      Width = 1066
      Height = 41
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
        108.479166666667
        2820.45833333333)
      BandType = rbDetail
      object QRShape3: TQRShape
        Left = 0
        Top = 38
        Width = 623
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
          1648.35416666667)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object QRDBText02: TQRDBText
        Left = 48
        Top = 4
        Width = 301
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          127
          10.5833333333333
          796.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35531#27714#20808#21517#31216
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText01: TQRDBText
        Left = 4
        Top = 4
        Width = 37
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
          97.8958333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #35531#27714#20808#12467#12540#12489
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
      object QRDBText06: TQRDBText
        Left = 524
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
          1386.41666666667
          10.5833333333333
          209.020833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #19981#36275#38989
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText04: TQRDBText
        Left = 376
        Top = 4
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          994.833333333333
          10.5833333333333
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #32224#20999#26085
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRDBText05: TQRDBText
        Left = 452
        Top = 4
        Width = 61
        Height = 13
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          34.3958333333333
          1195.91666666667
          10.5833333333333
          161.395833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #20837#37329#20104#23450#26085
        Transparent = False
        WordWrap = True
        FontSize = 9
      end
      object QRShape01: TQRShape
        Left = 624
        Top = 1
        Width = 373
        Height = 38
        Frame.Color = clSilver
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          1651
          2.64583333333333
          986.895833333333)
        Brush.Style = bsClear
        Shape = qrsRectangle
      end
      object QRShape02: TQRShape
        Left = 996
        Top = 1
        Width = 69
        Height = 38
        Frame.Color = clSilver
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.541666666667
          2635.25
          2.64583333333333
          182.5625)
        Brush.Style = bsClear
        Shape = qrsRectangle
      end
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#35531#27714#20808'ID,'
      #9#35531#27714#20808#12467#12540#12489','
      #9#35531#27714#20808#21517#31216','
      #9#32224#20999#26085','
      #9#20837#37329#20104#23450#26085','
      #9#20170#22238#35531#27714#38989','
      #9#20837#37329#38989','
      #9#19981#36275#38989
      'FROM'
      #9'#MINYULIST'
      'WHERE'
      #9#19981#36275#38989' > 0'
      'ORDER BY'
      #9#20837#37329#20104#23450#26085', '#32224#20999#26085
      ''
      '/*'
      'SELECT * FROM W_'#26410#20837#37329#12522#12473#12488
      '*/')
    Left = 24
    Top = 12
    object QueryID: TIntegerField
      FieldName = #35531#27714#20808'ID'
    end
    object QueryDSDesigner: TIntegerField
      DisplayWidth = 5
      FieldName = #35531#27714#20808#12467#12540#12489
    end
    object QueryDSDesigner2: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object QueryDSDesigner3: TIntegerField
      FieldName = #32224#20999#26085
      DisplayFormat = '0000/00/00'
    end
    object QueryDSDesigner4: TIntegerField
      FieldName = #20837#37329#20104#23450#26085
      DisplayFormat = '0000/00/00'
    end
    object QueryDSDesigner5: TBCDField
      FieldName = #20170#22238#35531#27714#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object QueryDSDesigner6: TBCDField
      FieldName = #20837#37329#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object QueryDSDesigner7: TBCDField
      FieldName = #19981#36275#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
  end
end
