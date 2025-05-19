object QRForm: TQRForm
  Left = 369
  Top = 110
  Width = 842
  Height = 872
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
    Width = 794
    Height = 1123
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
    BeforePrint = QuickRepBeforePrint
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
    object PageHeaderBand1: TQRBand
      Left = 49
      Top = 38
      Width = 718
      Height = 65
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
        171.979166666667
        1899.70833333333)
      BandType = rbPageHeader
      object QRSysData2: TQRSysData
        Left = 621
        Top = 0
        Width = 97
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          1643.0625
          0
          256.645833333333)
        Alignment = taRightJustify
        AlignToBand = True
        AutoSize = True
        Color = clWhite
        Data = qrsPageNumber
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = 'P - '
        Transparent = False
        FontSize = 8
      end
      object QRSysData1: TQRSysData
        Left = 0
        Top = 0
        Width = 121
        Height = 12
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          31.75
          0
          0
          320.145833333333)
        Alignment = taLeftJustify
        AlignToBand = True
        AutoSize = True
        Color = clWhite
        Data = qrsDateTime
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Text = #20986#21147#26085' - '
        Transparent = False
        FontSize = 8
      end
      object TitleLabel: TQRLabel
        Left = 318
        Top = 0
        Width = 81
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          841.375
          0
          214.3125)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #26376#21029#38598#35336#34920
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
        Left = 329
        Top = 23
        Width = 60
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          870.479166666667
          60.8541666666667
          158.75)
        Alignment = taCenter
        AlignToBand = True
        AutoSize = True
        AutoStretch = False
        Caption = #20986#21147#31684#22258#65306
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape1: TQRShape
        Left = 0
        Top = 38
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          100.541666666667
          1899.70833333333)
        Shape = qrsHorLine
      end
      object QRLabel1: TQRLabel
        Left = 4
        Top = 44
        Width = 29
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          116.416666666667
          76.7291666666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #24180#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape2: TQRShape
        Left = 0
        Top = 62
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          164.041666666667
          1899.70833333333)
        Shape = qrsHorLine
      end
      object QRLabel2: TQRLabel
        Left = 88
        Top = 44
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          116.416666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327#12304'kg'#12305
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRLabel4: TQRLabel
        Left = 188
        Top = 44
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          116.416666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989#12304#20870#12305
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
    object DetailBand1: TQRBand
      Left = 49
      Top = 103
      Width = 718
      Height = 242
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
        640.291666666667
        1899.70833333333)
      BandType = rbDetail
      object QRShape3: TQRShape
        Left = 0
        Top = 17
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          44.9791666666667
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel01: TQRLabel
        Left = 4
        Top = 2
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          5.29166666666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'04'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel01: TQRLabel
        Left = 88
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel01: TQRLabel
        Left = 188
        Top = 2
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          5.29166666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape4: TQRShape
        Left = 0
        Top = 37
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          97.8958333333333
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel02: TQRLabel
        Left = 4
        Top = 22
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          58.2083333333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'05'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel02: TQRLabel
        Left = 88
        Top = 22
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          58.2083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel02: TQRLabel
        Left = 188
        Top = 22
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          58.2083333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape5: TQRShape
        Left = 0
        Top = 57
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          150.8125
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel03: TQRLabel
        Left = 4
        Top = 42
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          111.125
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'06'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel03: TQRLabel
        Left = 88
        Top = 42
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          111.125
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel03: TQRLabel
        Left = 188
        Top = 42
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          111.125
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape6: TQRShape
        Left = 0
        Top = 77
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          203.729166666667
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel04: TQRLabel
        Left = 4
        Top = 62
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          164.041666666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'07'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel04: TQRLabel
        Left = 88
        Top = 62
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          164.041666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel04: TQRLabel
        Left = 188
        Top = 62
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          164.041666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape7: TQRShape
        Left = 0
        Top = 97
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          256.645833333333
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel05: TQRLabel
        Left = 4
        Top = 82
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          216.958333333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'08'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel05: TQRLabel
        Left = 88
        Top = 82
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          216.958333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel05: TQRLabel
        Left = 188
        Top = 82
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          216.958333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape8: TQRShape
        Left = 0
        Top = 117
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          309.5625
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel06: TQRLabel
        Left = 4
        Top = 102
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          269.875
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'09'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel06: TQRLabel
        Left = 88
        Top = 102
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          269.875
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel06: TQRLabel
        Left = 188
        Top = 102
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          269.875
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape9: TQRShape
        Left = 4
        Top = 137
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          362.479166666667
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel07: TQRLabel
        Left = 4
        Top = 122
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          322.791666666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'10'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel07: TQRLabel
        Left = 88
        Top = 122
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          322.791666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel07: TQRLabel
        Left = 188
        Top = 122
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          322.791666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape10: TQRShape
        Left = 4
        Top = 157
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          415.395833333333
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel08: TQRLabel
        Left = 4
        Top = 142
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          375.708333333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'11'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel08: TQRLabel
        Left = 88
        Top = 142
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          375.708333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel08: TQRLabel
        Left = 188
        Top = 142
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          375.708333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape11: TQRShape
        Left = 4
        Top = 177
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          468.3125
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel09: TQRLabel
        Left = 4
        Top = 162
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          428.625
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2009'#24180'12'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel09: TQRLabel
        Left = 88
        Top = 162
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          428.625
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel09: TQRLabel
        Left = 188
        Top = 162
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          428.625
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape12: TQRShape
        Left = 0
        Top = 197
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          0
          521.229166666667
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel10: TQRLabel
        Left = 4
        Top = 182
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          481.541666666667
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2010'#24180'01'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel10: TQRLabel
        Left = 88
        Top = 182
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          481.541666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel10: TQRLabel
        Left = 188
        Top = 182
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          481.541666666667
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape13: TQRShape
        Left = 4
        Top = 217
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          574.145833333333
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel11: TQRLabel
        Left = 4
        Top = 202
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          534.458333333333
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2010'#24180'02'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel11: TQRLabel
        Left = 88
        Top = 202
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          534.458333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel11: TQRLabel
        Left = 188
        Top = 202
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          534.458333333333
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object QRShape14: TQRShape
        Left = 4
        Top = 237
        Width = 718
        Height = 2
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          5.29166666666667
          10.5833333333333
          627.0625
          1899.70833333333)
        Pen.Style = psDot
        Shape = qrsHorLine
      end
      object MonthLabel12: TQRLabel
        Left = 4
        Top = 222
        Width = 71
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          10.5833333333333
          587.375
          187.854166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '2010'#24180'03'#26376
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object JuryoLabel12: TQRLabel
        Left = 88
        Top = 222
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          232.833333333333
          587.375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #27491#21619#37325#37327
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
      object KinLabel12: TQRLabel
        Left = 188
        Top = 222
        Width = 92
        Height = 14
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          37.0416666666667
          497.416666666667
          587.375
          243.416666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Caption = #37329#38989'1'
        Color = clWhite
        Transparent = False
        WordWrap = True
        FontSize = 10
      end
    end
  end
  object Query: TADOQuery
    Connection = DM.ADOConnection
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
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM decimal'
      'DECLARE @DATE_TO decimal'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      ''
      'SELECT'
      #9#24180' * 100 + '#26376' AS '#24180#26376','
      #9#24180','
      #9#26376','
      #9'SUM('#27491#21619#37325#37327') AS '#27491#21619#37325#37327','
      #9'SUM('#37329#38989') AS '#37329#38989
      'FROM'
      #9'V_'#35336#37327' AS X'
      'WHERE'
      #9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      'AND'
      #9#23436#20102#21306#20998' = 1'
      '-- AND'#9#24471#24847#20808#12467#12540#12489' = 999'#9'/* '#32094#36796#38917#30446' */'
      '-- AND'#9#25312#28857'ID = 1'#9#9'/* '#25312#28857'     */'
      '-- AND'#9#25644#20837#20986#21306#20998' = 1'#9#9'/* '#25644#20837#20986'   */'
      '-- AND'#9#21462#24341#21306#20998' = 1'#9#9'/* '#21462#24341'     */'
      '-- AND'#9#29694#25499#21306#20998' = 1'#9#9'/* '#29694#25499'     */'
      ''
      'GROUP BY'
      #9#24180', '#26376
      'ORDER BY'
      #9#24180', '#26376
      '')
    Left = 8
    Top = 8
    object QueryDSDesigner5: TIntegerField
      FieldName = #24180#26376
      ReadOnly = True
      DisplayFormat = '0000'#39#24180#39'00'#39#26376#39
    end
    object QueryDSDesigner: TIntegerField
      FieldName = #24180
    end
    object QueryDSDesigner2: TIntegerField
      FieldName = #26376
    end
    object QueryDSDesigner3: TBCDField
      FieldName = #27491#21619#37325#37327
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 1
    end
    object QueryDSDesigner4: TBCDField
      FieldName = #37329#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
  end
end
