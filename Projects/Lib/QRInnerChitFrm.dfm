object QRInnerChitForm: TQRInnerChitForm
  Left = 651
  Top = 227
  Width = 597
  Height = 667
  Caption = 'QRInnerChitForm'
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
  object QR: TQuickRep
    Left = 0
    Top = 0
    Width = 439
    Height = 741
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    DataSet = ChitQuery
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
    Page.PaperSize = Default
    Page.Values = (
      0
      1400
      0
      830
      0
      100
      0)
    PrinterSettings.Copies = 1
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.OutputBin = Auto
    PrintIfEmpty = False
    ReportTitle = #35336#37327#31080
    ShowProgress = False
    SnapToGrid = True
    Units = MM
    Zoom = 140
    object QRBand1: TQRBand
      Left = 0
      Top = 0
      Width = 386
      Height = 281
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
        531.056547619048
        729.494047619048)
      BandType = rbTitle
      object QRTitle: TQRLabel
        Left = 105
        Top = 16
        Width = 176
        Height = 35
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          66.1458333333333
          198.4375
          30.2380952380952
          332.619047619048)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #35336#12288#37327#12288#31080
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 18
      end
      object QRShape2: TQRShape
        Left = 0
        Top = 58
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          109.613095238095
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRShape3: TQRShape
        Left = 84
        Top = 58
        Width = 1
        Height = 28
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          158.75
          110.243055555556
          2.20486111111111)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRShape6: TQRShape
        Left = 224
        Top = 58
        Width = 1
        Height = 28
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          423.333333333333
          109.613095238095
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRLabel11: TQRLabel
        Left = 234
        Top = 63
        Width = 60
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          442.232142857143
          119.0625
          113.392857142857)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #35336#37327'No'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape7: TQRShape
        Left = 302
        Top = 58
        Width = 1
        Height = 28
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          570.744047619048
          109.613095238095
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRShape8: TQRShape
        Left = 0
        Top = 92
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          173.869047619048
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRLabel13: TQRLabel
        Left = 3
        Top = 96
        Width = 80
        Height = 24
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          45.3571428571429
          5.66964285714286
          181.428571428571
          151.190476190476)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #36554#12288#30058
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
      object QRShape9: TQRShape
        Left = 84
        Top = 92
        Width = 1
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          158.75
          174.625
          2.64583333333333)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRShape10: TQRShape
        Left = 0
        Top = 120
        Width = 381
        Height = 54
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          102.053571428571
          0
          226.785714285714
          720.044642857143)
        Shape = qrsRectangle
      end
      object TokuTitleLabel: TQRLabel
        Left = 2
        Top = 137
        Width = 79
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          3.7797619047619
          258.91369047619
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #20181#20837#20808
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
      object QRShape11: TQRShape
        Left = 84
        Top = 119
        Width = 1
        Height = 54
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          102.053571428571
          158.75
          224.895833333333
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRLabel7: TQRLabel
        Left = 2
        Top = 63
        Width = 79
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          3.7797619047619
          119.0625
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #26085#12288#20184
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
      object QRDBText7: TQRDBText
        Left = 92
        Top = 149
        Width = 99
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          173.869047619048
          281.592261904762
          187.098214285714)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #24471#24847#20808#30053#31216
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
      object QRDBText8: TQRDBText
        Left = 92
        Top = 125
        Width = 53
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          173.869047619048
          236.235119047619
          100.16369047619)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #24471#24847#20808#12467#12540#12489
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
        Left = 92
        Top = 96
        Width = 71
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          173.869047619048
          181.428571428571
          134.181547619048)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #36554#30058
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 12
      end
      object QRDBText11: TQRDBText
        Left = 92
        Top = 63
        Width = 60
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          173.869047619048
          119.0625
          113.392857142857)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #35336#37327#26085
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
      object QRDBText12: TQRDBText
        Left = 316
        Top = 63
        Width = 60
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          597.202380952381
          119.0625
          113.392857142857)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #20253#31080'No'
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
      object QRShape5: TQRShape
        Left = 0
        Top = 173
        Width = 381
        Height = 54
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          102.053571428571
          0
          326.949404761905
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRDBText10: TQRDBText
        Left = 92
        Top = 202
        Width = 90
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          173.869047619048
          381.755952380952
          170.089285714286)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #38917#30446'1'#30053#31216
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
      object QRDBText13: TQRDBText
        Left = 92
        Top = 178
        Width = 53
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          173.869047619048
          336.39880952381
          100.16369047619)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #38917#30446'1'#12467#12540#12489
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
      object Item1TitleLabel: TQRLabel
        Left = 2
        Top = 190
        Width = 79
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          3.7797619047619
          359.077380952381
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #36939#25644#26989#32773
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
      object QRShape12: TQRShape
        Left = 84
        Top = 173
        Width = 1
        Height = 53
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.16369047619
          158.75
          326.949404761905
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRShape4: TQRShape
        Left = 0
        Top = 226
        Width = 381
        Height = 54
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          102.053571428571
          0
          427.113095238095
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRDBText14: TQRDBText
        Left = 92
        Top = 255
        Width = 90
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          173.869047619048
          481.919642857143
          170.089285714286)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #38917#30446'2'#30053#31216
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
      object QRDBText15: TQRDBText
        Left = 92
        Top = 231
        Width = 53
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          173.869047619048
          436.5625
          100.16369047619)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #38917#30446'2'#12467#12540#12489
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
      object Item2TitleLabel: TQRLabel
        Left = 2
        Top = 243
        Width = 79
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          3.7797619047619
          459.241071428571
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #36939#25644#26989#32773
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
      object QRShape27: TQRShape
        Left = 84
        Top = 226
        Width = 1
        Height = 53
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          100.16369047619
          158.75
          427.113095238095
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
    end
    object QRBand2: TQRBand
      Left = 0
      Top = 426
      Width = 386
      Height = 275
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
        519.717261904762
        729.494047619048)
      BandType = rbSummary
      object QRCompany: TQRLabel
        Left = -3
        Top = 50
        Width = 393
        Height = 24
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          45.3571428571429
          -5.66964285714286
          94.4940476190476
          742.723214285714)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXX'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object QRFooter1: TQRLabel
        Left = 55
        Top = 89
        Width = 276
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          103.943452380952
          168.199404761905
          521.607142857143)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXX'
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
      object QRLabel8: TQRLabel
        Left = 191
        Top = 243
        Width = 4
        Height = 27
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          51.0267857142857
          360.967261904762
          459.241071428571
          7.55952380952381)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = '.'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -3
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 2
      end
      object QRFooter2: TQRLabel
        Left = 55
        Top = 114
        Width = 276
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          103.943452380952
          215.446428571429
          521.607142857143)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXX'
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
      object QRFooter3: TQRLabel
        Left = 55
        Top = 139
        Width = 276
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          103.943452380952
          262.693452380952
          521.607142857143)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXX'
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
      object QRFooter4: TQRLabel
        Left = 55
        Top = 164
        Width = 276
        Height = 22
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          41.577380952381
          103.943452380952
          309.940476190476
          521.607142857143)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXX'
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
    end
    object QRBand3: TQRBand
      Left = 0
      Top = 281
      Width = 386
      Height = 145
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
        274.032738095238
        729.494047619048)
      BandType = rbDetail
      object QRShape1: TQRShape
        Left = 0
        Top = 2
        Width = 381
        Height = 30
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          56.6964285714286
          0
          3.7797619047619
          720.044642857143)
        Shape = qrsRectangle
      end
      object MeigTitleLabel: TQRLabel
        Left = 3
        Top = 7
        Width = 80
        Height = 24
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          45.3571428571429
          5.66964285714286
          13.2291666666667
          151.190476190476)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #21697#12288#30446
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
      object QRShape13: TQRShape
        Left = 84
        Top = 3
        Width = 1
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          158.75
          5.66964285714286
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRShape14: TQRShape
        Left = 0
        Top = 87
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          164.419642857143
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRLabel19: TQRLabel
        Left = 2
        Top = 90
        Width = 79
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          3.7797619047619
          170.089285714286
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#12288#21619
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape15: TQRShape
        Left = 84
        Top = 87
        Width = 1
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          158.75
          164.419642857143
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRLabel21: TQRLabel
        Left = 223
        Top = 93
        Width = 21
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          421.443452380952
          175.758928571429
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
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
      object QRShape16: TQRShape
        Left = 0
        Top = 115
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          217.33630952381
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRDBText1: TQRDBText
        Left = 92
        Top = 9
        Width = 41
        Height = 26
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          49.1369047619048
          173.869047619048
          17.0089285714286
          77.485119047619)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #21697#30446#12467#12540#12489
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
      object QRDBText2: TQRDBText
        Left = 144
        Top = 8
        Width = 80
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          272.142857142857
          15.1190476190476
          151.190476190476)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #21697#30446#30053#31216
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
        Left = 116
        Top = 91
        Width = 97
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          219.22619047619
          171.979166666667
          183.318452380952)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #27491#21619#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        Mask = '###,##0'
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 12
      end
      object QRShape21: TQRShape
        Left = 0
        Top = 59
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          111.502976190476
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRLabel6: TQRLabel
        Left = 2
        Top = 62
        Width = 79
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          3.7797619047619
          117.172619047619
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #31354#12288#36554
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape22: TQRShape
        Left = 84
        Top = 59
        Width = 1
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          158.75
          111.502976190476
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRLabel12: TQRLabel
        Left = 223
        Top = 65
        Width = 21
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          421.443452380952
          122.842261904762
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
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
      object QRDBText4: TQRDBText
        Left = 116
        Top = 63
        Width = 97
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          219.22619047619
          119.0625
          183.318452380952)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #31354#36554#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        Mask = '###,##0'
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 12
      end
      object QRShape23: TQRShape
        Left = 0
        Top = 31
        Width = 381
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          0
          58.5863095238095
          720.044642857143)
        Shape = qrsRectangle
      end
      object QRLabel18: TQRLabel
        Left = 2
        Top = 34
        Width = 79
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          3.7797619047619
          64.2559523809524
          149.300595238095)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #32207#37325#37327
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#26126#26397
        Font.Style = []
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 10
      end
      object QRShape24: TQRShape
        Left = 84
        Top = 31
        Width = 1
        Height = 29
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          54.8065476190476
          158.75
          58.5863095238095
          1.88988095238095)
        Brush.Style = bsClear
        Shape = qrsVertLine
      end
      object QRLabel20: TQRLabel
        Left = 223
        Top = 37
        Width = 21
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          421.443452380952
          69.9255952380952
          39.6875)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
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
        Left = 139
        Top = 35
        Width = 73
        Height = 23
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          43.4672619047619
          262.693452380952
          66.1458333333333
          137.96130952381)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #32207#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        Mask = '###,##0'
        ParentFont = False
        Transparent = True
        WordWrap = True
        FontSize = 12
      end
      object QRDBText6: TQRDBText
        Left = 292
        Top = 93
        Width = 61
        Height = 19
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          35.9077380952381
          551.845238095238
          175.758928571429
          115.282738095238)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = ChitQuery
        DataField = #35336#37327#26085#26178'2'
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
    end
  end
  object ChitQuery: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    OnCalcFields = ChitQueryCalcFields
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#35336#37327
      'WHERE'
      #9#35336#37327'ID = 53'
      'AND'
      #9#23436#20102#21306#20998' = 1')
    Left = 392
    Top = 12
    object ChitQueryID: TIntegerField
      FieldName = #35336#37327'ID'
    end
    object ChitQueryIntegerField: TIntegerField
      FieldName = #35336#37327#26085
      DisplayFormat = '0000/00/00'
    end
    object ChitQueryID2: TIntegerField
      FieldName = #25312#28857'ID'
    end
    object ChitQueryStringField: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object ChitQueryNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object ChitQueryIntegerField2: TIntegerField
      FieldName = #25644#20837#20986#21306#20998
    end
    object ChitQueryStringField2: TStringField
      FieldName = #25644#20837#20986#21306#20998#21517
    end
    object ChitQueryID3: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object ChitQueryIntegerField3: TIntegerField
      FieldName = #36554#30058
    end
    object ChitQueryStringField3: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object ChitQueryID4: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object ChitQueryIntegerField4: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object ChitQueryStringField4: TStringField
      FieldName = #24471#24847#20808#12510#12473#12479#21517#31216
      Size = 50
    end
    object ChitQueryStringField5: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object ChitQueryStringField6: TStringField
      FieldName = #24471#24847#20808#12459#12490
      Size = 50
    end
    object ChitQueryIntegerField5: TIntegerField
      FieldName = #29694#25499#21306#20998
    end
    object ChitQueryStringField7: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object ChitQueryIntegerField1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object ChitQueryIntegerField1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object ChitQueryStringField1: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object ChitQueryStringField12: TStringField
      FieldName = #38917#30446'1'#12510#12473#12479#21517#31216
      Size = 40
    end
    object ChitQueryStringField13: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object ChitQueryStringField14: TStringField
      FieldName = #38917#30446'1'#12459#12490
      Size = 50
    end
    object ChitQueryIntegerField2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object ChitQueryIntegerField22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object ChitQueryStringField22: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object ChitQueryStringField23: TStringField
      FieldName = #38917#30446'2'#12510#12473#12479#21517#31216
      Size = 40
    end
    object ChitQueryStringField24: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object ChitQueryStringField25: TStringField
      FieldName = #38917#30446'2'#12459#12490
      Size = 50
    end
    object ChitQueryStringField8: TStringField
      FieldName = #20633#32771
      Size = 40
    end
    object ChitQueryBCDField: TBCDField
      FieldName = #20253#31080#28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object ChitQueryNo2: TIntegerField
      FieldName = #34892'No'
    end
    object ChitQueryID5: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object ChitQueryIntegerField6: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object ChitQueryStringField9: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object ChitQueryStringField10: TStringField
      FieldName = #21697#30446#12510#12473#12479#21517#31216
      Size = 40
    end
    object ChitQueryStringField11: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object ChitQueryStringField15: TStringField
      FieldName = #21697#30446#12459#12490
      Size = 50
    end
    object ChitQueryIntegerField7: TIntegerField
      FieldName = #21462#24341#21306#20998
    end
    object ChitQueryStringField16: TStringField
      FieldName = #21462#24341#21306#20998#21517
    end
    object ChitQueryID6: TIntegerField
      FieldName = #21697#30446#20998#39006'ID'
    end
    object ChitQueryIntegerField8: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object ChitQueryStringField17: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object ChitQueryStringField18: TStringField
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object ChitQueryStringField19: TStringField
      FieldName = #21697#30446#20998#39006#12459#12490
      Size = 50
    end
    object ChitQueryBCDField1: TBCDField
      FieldName = '1'#22238#30446#37325#37327
      DisplayFormat = '####,###0'
      Precision = 10
      Size = 1
    end
    object ChitQueryDateTimeField1: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
      DisplayFormat = 'hh:nn'
    end
    object ChitQueryBCDField2: TBCDField
      FieldName = '2'#22238#30446#37325#37327
      DisplayFormat = '####,###0'
      Precision = 10
      Size = 1
    end
    object ChitQueryDateTimeField2: TDateTimeField
      FieldName = #35336#37327#26085#26178'2'
      DisplayFormat = 'hh:nn'
    end
    object ChitQueryBCDField3: TBCDField
      FieldName = #35519#25972#29575
      Precision = 10
      Size = 3
    end
    object ChitQueryBCDField4: TBCDField
      FieldName = #35519#25972#37325#37327
      Precision = 10
      Size = 1
    end
    object ChitQueryBCDField5: TBCDField
      FieldName = #37325#37327#24341#12365
      Precision = 10
      Size = 1
    end
    object ChitQueryBCDField6: TBCDField
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '####,###0'
      Precision = 10
      Size = 1
    end
    object ChitQueryBCDField7: TBCDField
      FieldName = #25968#37327
      Precision = 10
      Size = 3
    end
    object ChitQueryID7: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object ChitQueryIntegerField9: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object ChitQueryStringField20: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object ChitQueryBCDField8: TBCDField
      FieldName = #21336#20385
      Precision = 13
      Size = 3
    end
    object ChitQueryBCDField9: TBCDField
      FieldName = #37329#38989
      Precision = 10
      Size = 0
    end
    object ChitQueryBCDField10: TBCDField
      FieldName = #28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object ChitQueryStringField21: TStringField
      FieldName = #26126#32048#20633#32771
    end
    object ChitQueryIntegerField10: TIntegerField
      FieldName = #23436#20102#21306#20998
    end
    object ChitQueryStringField26: TStringField
      FieldName = #23436#20102#21306#20998#21517
    end
    object ChitQueryDateTimeField: TDateTimeField
      FieldName = #26356#26032#26085#26178
    end
    object ChitQueryDateTimeField3: TDateTimeField
      FieldName = #20316#25104#26085#26178
    end
    object ChitQueryIntegerField11: TIntegerField
      FieldKind = fkCalculated
      FieldName = #32207#37325#37327
      DisplayFormat = '####,###0'
      Calculated = True
    end
    object ChitQueryIntegerField12: TIntegerField
      FieldKind = fkCalculated
      FieldName = #31354#36554#37325#37327
      DisplayFormat = '####,###0'
      Calculated = True
    end
  end
end
