object QRForm: TQRForm
  Left = 228
  Top = 114
  Width = 824
  Height = 500
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
    Left = 0
    Top = 0
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
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
    Page.Orientation = poPortrait
    Page.PaperSize = A4
    Page.Values = (
      100
      2970
      100
      2100
      130
      70
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
      Left = 49
      Top = 38
      Width = 718
      Height = 68
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
        179.916666666667
        1899.70833333333)
      BandType = rbPageHeader
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
      object QRSysData2: TQRSysData
        Left = 598
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
          1582.20833333333
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
      object TitleLabel: TQRLabel
        Left = 310
        Top = 5
        Width = 97
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          820.208333333333
          13.2291666666667
          256.645833333333)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #38917#30446#21029#38598#35336#34920
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
      object RangeLabel: TQRLabel
        Left = 169
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
          447.145833333333
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
      object QRShape1: TQRShape
        Left = 0
        Top = 46
        Width = 718
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          121.708333333333
          1899.70833333333)
        Shape = qrsHorLine
      end
      object QRShape2: TQRShape
        Left = 0
        Top = 65
        Width = 718
        Height = 1
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          2.64583333333333
          0
          171.979166666667
          1899.70833333333)
        Shape = qrsHorLine
      end
      object ItemLabel: TQRLabel
        Left = 53
        Top = 49
        Width = 141
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          140.229166666667
          129.645833333333
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #38917#30446
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AmountLabel: TQRLabel
        Left = 292
        Top = 49
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          772.583333333333
          129.645833333333
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #25968#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MoneyLabel: TQRLabel
        Left = 500
        Top = 49
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1322.91666666667
          129.645833333333
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TaniLabel: TQRLabel
        Left = 402
        Top = 49
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1063.625
          129.645833333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21336#20301
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel2: TQRLabel
        Left = 208
        Top = 49
        Width = 65
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          550.333333333333
          129.645833333333
          171.979166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #22238#25968
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand: TQRBand
      Left = 49
      Top = 106
      Width = 718
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
        1899.70833333333)
      BandType = rbDetail
      object ItemText: TQRDBText
        Left = 53
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
          140.229166666667
          7.9375
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#30053#31216
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape3: TQRShape
        Left = 0
        Top = 18
        Width = 718
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
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object AmountText: TQRDBText
        Left = 292
        Top = 3
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          772.583333333333
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21512#35336#25968#37327
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object TaniText: TQRDBText
        Left = 402
        Top = 3
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1063.625
          7.9375
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21336#20301
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MoneyText: TQRDBText
        Left = 500
        Top = 3
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1322.91666666667
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21512#35336#37329#38989
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText1: TQRDBText
        Left = 5
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
          13.2291666666667
          7.9375
          95.25)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#12467#12540#12489
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText2: TQRDBText
        Left = 208
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
          550.333333333333
          7.9375
          171.979166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #22238#25968
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object SummaryBand1: TQRBand
      Left = 49
      Top = 126
      Width = 718
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
        1899.70833333333)
      BandType = rbSummary
      object QRLabel1: TQRLabel
        Left = 53
        Top = 4
        Width = 141
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          140.229166666667
          10.5833333333333
          373.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12304' '#21512' '#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object MoneyExpr: TQRExpr
        Left = 500
        Top = 3
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1322.91666666667
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = False
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#21512#35336#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRExpr2: TQRExpr
        Left = 208
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
          550.333333333333
          7.9375
          171.979166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = False
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#22238#25968')'
        Mask = '#,##0.#'
        FontSize = 10
      end
      object QRShape4: TQRShape
        Left = 0
        Top = 18
        Width = 718
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
          1899.70833333333)
        Shape = qrsHorLine
      end
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    Parameters = <>
    SQL.Strings = (
      'DECLARE @DATE_FROM AS [DECIMAL]'
      'DECLARE @DATE_TO   AS [DECIMAL]'
      'SET @DATE_FROM = 20100601'
      'SET @DATE_TO   = 20100731'
      ''
      'SELECT'
      #9'V.'#36554#20001'ID AS '#38917#30446'ID, MAX(V.'#36554#30058') AS '#38917#30446#12467#12540#12489', MAX(V.'#36554#20001#21517#31216') AS '#38917#30446#30053#31216','
      ' '#9'MAX(KEN.'#22238#25968') AS '#22238#25968','
      ' '#9'SUM(V.'#25968#37327') AS '#21512#35336#25968#37327','
      ' '#9'V.'#21336#20301#12467#12540#12489', MAX(V.'#21336#20301#12510#12473#12479#21517#31216') AS '#21336#20301','
      ' '#9'SUM(V.'#37329#38989') AS '#21512#35336#37329#38989' '
      'FROM'
      #9'V_'#21462#24341' AS V'
      ' '#9'LEFT OUTER JOIN'
      ' '#9#9'('
      #9#9'SELECT'
      ' '#9#9#9#36554#20001'ID,'
      #9#9#9#21336#20301#12467#12540#12489','
      #9#9#9'COUNT(*) AS '#22238#25968
      ' '#9#9'FROM'
      #9#9#9'('
      #9#9#9'SELECT'
      #9#9#9#9'V.'#36554#20001'ID, V.'#21336#20301#12467#12540#12489', V.'#21462#24341#26085', V.'#20253#31080'No'
      #9#9#9'FROM'
      #9#9#9#9'V_'#21462#24341' AS V'
      #9#9#9'WHERE'
      #9#9#9#9'V.'#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9#9#9'GROUP BY'
      #9#9#9#9'V.'#36554#20001'ID, V.'#21336#20301#12467#12540#12489', V.'#21462#24341#26085', V.'#20253#31080'No'
      #9#9#9') AS X'
      #9#9'GROUP BY'
      #9#9#9#36554#20001'ID, '#21336#20301#12467#12540#12489
      #9#9') AS KEN'
      ' '#9'ON V.'#36554#20001'ID = KEN.'#36554#20001'ID AND V.'#21336#20301#12467#12540#12489' = KEN.'#21336#20301#12467#12540#12489
      'WHERE'
      #9'V.'#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      'AND'
      #9'V.'#23436#20102#21306#20998' = 1'
      'GROUP BY'
      ' '#9'V.'#36554#20001'ID, V.'#21336#20301#12467#12540#12489
      'ORDER BY'
      ' '#9'V.'#38917#30446#12467#12540#12489', V.'#38917#30446'ID, V.'#21336#20301#12467#12540#12489)
    Left = 8
    Top = 8
    object QueryDSDesigner: TIntegerField
      FieldName = #38917#30446#12467#12540#12489
    end
    object QueryDSDesigner2: TStringField
      FieldName = #38917#30446#30053#31216
      ReadOnly = True
    end
    object QueryDSDesigner3: TIntegerField
      FieldName = #22238#25968
      ReadOnly = True
      DisplayFormat = '#,##0'
    end
    object QueryDSDesigner5: TBCDField
      FieldName = #21512#35336#25968#37327
      ReadOnly = True
      DisplayFormat = '#,##0.000'
      Precision = 32
      Size = 3
    end
    object QueryDSDesigner6: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object QueryDSDesigner7: TStringField
      FieldName = #21336#20301
      ReadOnly = True
      Size = 10
    end
    object QueryDSDesigner8: TBCDField
      FieldName = #21512#35336#37329#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 32
      Size = 0
    end
  end
end
