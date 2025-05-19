object QRForm: TQRForm
  Left = 228
  Top = 114
  Width = 838
  Height = 596
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
      Height = 84
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
        222.25
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
        Left = 306
        Top = 5
        Width = 105
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          809.625
          13.2291666666667
          277.8125)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '2'#38917#30446#21029#38598#35336#34920
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
        Top = 81
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
          214.3125
          1899.70833333333)
        Shape = qrsHorLine
      end
      object Item2Label: TQRLabel
        Left = 77
        Top = 65
        Width = 141
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          203.729166666667
          171.979166666667
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #38917#30446'2'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object WeightLabel: TQRLabel
        Left = 302
        Top = 65
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          799.041666666667
          171.979166666667
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37325#37327'(kg)'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AmountLabel: TQRLabel
        Left = 417
        Top = 65
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1103.3125
          171.979166666667
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
        Left = 604
        Top = 65
        Width = 106
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1598.08333333333
          171.979166666667
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
        Left = 527
        Top = 65
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          1394.35416666667
          171.979166666667
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
        Left = 228
        Top = 65
        Width = 65
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          603.25
          171.979166666667
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
      object Item1Label: TQRLabel
        Left = 45
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
          119.0625
          129.645833333333
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #38917#30446'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand: TQRBand
      Left = 49
      Top = 142
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
      object ItemText2: TQRDBText
        Left = 77
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
          203.729166666667
          7.9375
          373.0625)
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
      object WeightText: TQRDBText
        Left = 302
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
          799.041666666667
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #21512#35336#37325#37327
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object AmountText: TQRDBText
        Left = 417
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
          1103.3125
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
        Left = 527
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
          1394.35416666667
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
        Left = 604
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
          1598.08333333333
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
        Left = 33
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
          87.3125
          7.9375
          95.25)
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
      object QRDBText2: TQRDBText
        Left = 228
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
          603.25
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
      Top = 184
      Width = 718
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
        1899.70833333333)
      BandType = rbSummary
      object QRLabel1: TQRLabel
        Left = 77
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
          203.729166666667
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
      object QRExpr1: TQRExpr
        Left = 302
        Top = 3
        Width = 108
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          799.041666666667
          7.9375
          285.75)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#21512#35336#37325#37327')'
        Mask = '#,##0.#'
        FontSize = 10
      end
      object MoneyExpr: TQRExpr
        Left = 604
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
          1598.08333333333
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#21512#35336#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRExpr2: TQRExpr
        Left = 228
        Top = 3
        Width = 67
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          603.25
          7.9375
          177.270833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#22238#25968')'
        Mask = '#,##0.#'
        FontSize = 10
      end
      object QRShape4: TQRShape
        Left = 0
        Top = 19
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
          50.2708333333333
          1899.70833333333)
        Shape = qrsHorLine
      end
    end
    object Item1GroupHeaderBand: TQRGroup
      Left = 49
      Top = 122
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
      Expression = 'Query.'#38917#30446'ID1'
      FooterBand = Item1GroupFooterBand
      Master = QuickRep
      ReprintOnNewPage = False
      object ItemText1: TQRDBText
        Left = 45
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
          119.0625
          7.9375
          373.0625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#30053#31216'1'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRDBText4: TQRDBText
        Left = 1
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
          2.64583333333333
          7.9375
          95.25)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Query
        DataField = #38917#30446#12467#12540#12489'1'
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object Item1GroupFooterBand: TQRBand
      Left = 49
      Top = 162
      Width = 718
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
        1899.70833333333)
      BandType = rbGroupFooter
      object SumItem1Label: TQRLabel
        Left = 77
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
          203.729166666667
          10.5833333333333
          373.0625)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #12304' '#38917' '#30446' '#35336' '#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRExpr3: TQRExpr
        Left = 302
        Top = 3
        Width = 108
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          799.041666666667
          7.9375
          285.75)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#21512#35336#37325#37327')'
        Mask = '#,##0.#'
        FontSize = 10
      end
      object Item1MoneyExpr: TQRExpr
        Left = 604
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
          1598.08333333333
          7.9375
          280.458333333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#21512#35336#37329#38989')'
        Mask = '#,##0'
        FontSize = 10
      end
      object QRExpr5: TQRExpr
        Left = 228
        Top = 3
        Width = 67
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          603.25
          7.9375
          177.270833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        ResetAfterPrint = True
        Transparent = False
        WordWrap = True
        Expression = 'SUM(Query.'#22238#25968')'
        Mask = '#,##0.#'
        FontSize = 10
      end
      object QRShape5: TQRShape
        Left = 0
        Top = 19
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
          50.2708333333333
          1899.70833333333)
        Shape = qrsHorLine
      end
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      
        #9'V.'#24471#24847#20808'ID AS '#38917#30446'ID1, MAX(V.'#24471#24847#20808#12467#12540#12489') AS '#38917#30446#12467#12540#12489'1, MAX(V.'#24471#24847#20808#30053#31216') AS '#38917#30446#30053#31216 +
        '1,'
      
        #9'V.'#21697#30446'ID   AS '#38917#30446'ID2, MAX(V.'#21697#30446#12467#12540#12489')   AS '#38917#30446#12467#12540#12489'2, MAX(V.'#21697#30446#30053#31216')   AS '#38917 +
        #30446#30053#31216'2,'
      ' '#9'MAX(KEN.'#22238#25968') AS '#22238#25968','
      ' '#9'SUM(V.'#27491#21619#37325#37327') AS '#21512#35336#37325#37327','
      ' '#9'SUM(V.'#25968#37327') AS '#21512#35336#25968#37327','
      ' '#9'V.'#21336#20301#12467#12540#12489', MAX(V.'#21336#20301#12510#12473#12479#21517#31216') AS '#21336#20301','
      ' '#9'SUM(V.'#37329#38989') AS '#21512#35336#37329#38989' '
      'FROM'
      #9'V_'#35336#37327' AS V'
      ' '#9'LEFT OUTER JOIN'
      ' '#9#9'('
      #9#9'SELECT'
      ' '#9#9#9#24471#24847#20808'ID,'
      #9#9#9#21697#30446'ID,'
      #9#9#9#21336#20301#12467#12540#12489','
      #9#9#9'COUNT('#20253#31080'No) AS '#22238#25968
      ' '#9#9'FROM'
      #9#9#9'('
      #9#9#9'SELECT'
      #9#9#9#9'V.'#24471#24847#20808'ID, V.'#21697#30446'ID, V.'#21336#20301#12467#12540#12489', V.'#35336#37327#26085', V.'#20253#31080'No'
      #9#9#9'FROM'
      #9#9#9#9'V_'#35336#37327' AS V'
      #9#9#9'WHERE'
      #9#9#9#9'V.'#35336#37327#26085' BETWEEN 20081101 AND 20081130'
      #9#9#9'AND'
      #9#9#9#9'V.'#23436#20102#21306#20998' = 1'
      #9#9#9'GROUP BY'
      #9#9#9#9'V.'#24471#24847#20808'ID, V.'#21697#30446'ID, V.'#21336#20301#12467#12540#12489', V.'#35336#37327#26085', V.'#20253#31080'No'
      #9#9#9') AS X'
      #9#9'GROUP BY'
      #9#9#9#24471#24847#20808'ID, '#21697#30446'ID, '#21336#20301#12467#12540#12489
      #9#9') AS KEN'
      
        ' '#9'ON V.'#24471#24847#20808'ID = KEN.'#24471#24847#20808'ID AND V.'#21697#30446'ID = KEN.'#21697#30446'ID AND V.'#21336#20301#12467#12540#12489' = KEN' +
        '.'#21336#20301#12467#12540#12489
      'WHERE'
      #9'V.'#35336#37327#26085' BETWEEN 20081101 AND 20090531'
      'AND'
      #9'V.'#23436#20102#21306#20998' = 1'
      'GROUP BY'
      ' '#9'V.'#24471#24847#20808'ID, V.'#21697#30446'ID, V.'#21336#20301#12467#12540#12489
      'ORDER BY'
      ' '#9'V.'#38917#30446#12467#12540#12489'1, V.'#38917#30446'ID1, V.'#38917#30446#12467#12540#12489'2, V.'#38917#30446'ID2, V.'#21336#20301#12467#12540#12489)
    Left = 8
    Top = 8
    object QueryID1: TIntegerField
      FieldName = #38917#30446'ID1'
    end
    object QueryDSDesigner1: TIntegerField
      FieldName = #38917#30446#12467#12540#12489'1'
      ReadOnly = True
    end
    object QueryDSDesigner12: TStringField
      FieldName = #38917#30446#30053#31216'1'
      ReadOnly = True
    end
    object QueryID2: TIntegerField
      FieldName = #38917#30446'ID2'
    end
    object QueryDSDesigner2: TIntegerField
      FieldName = #38917#30446#12467#12540#12489'2'
      ReadOnly = True
    end
    object QueryDSDesigner22: TStringField
      FieldName = #38917#30446#30053#31216'2'
      ReadOnly = True
    end
    object QueryDSDesigner3: TIntegerField
      FieldName = #22238#25968
      ReadOnly = True
      DisplayFormat = '#,##0'
    end
    object QueryDSDesigner4: TBCDField
      FieldName = #21512#35336#37325#37327
      ReadOnly = True
      DisplayFormat = '#,##0.#'
      Precision = 32
      Size = 1
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
