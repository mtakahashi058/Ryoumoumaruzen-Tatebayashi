object DotSlipPrintForm: TDotSlipPrintForm
  Left = 379
  Top = 83
  Width = 458
  Height = 640
  Caption = 'DotSlipPrintForm'
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 16
  object QuickRep: TQuickRep
    Left = 8
    Top = 24
    Width = 334
    Height = 529
    Frame.Color = clBlack
    Frame.DrawTop = False
    Frame.DrawBottom = False
    Frame.DrawLeft = False
    Frame.DrawRight = False
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
      885
      0
      0
      0)
    PrinterSettings.Copies = 1
    PrinterSettings.Duplex = False
    PrinterSettings.FirstPage = 0
    PrinterSettings.LastPage = 0
    PrinterSettings.OutputBin = Auto
    PrintIfEmpty = True
    ShowProgress = False
    SnapToGrid = True
    Units = MM
    Zoom = 100
    object QRBand1: TQRBand
      Left = 0
      Top = 0
      Width = 334
      Height = 529
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
        1399.64583333333
        883.708333333333)
      BandType = rbDetail
      object QRDBText1: TQRDBText
        Left = 66
        Top = 52
        Width = 79
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          174.625
          137.583333333333
          209.020833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #20253#31080'No'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object QRDBText2: TQRDBText
        Left = 150
        Top = 52
        Width = 101
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          396.875
          137.583333333333
          267.229166666667)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #35336#37327#26085
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object QRDBText3: TQRDBText
        Left = 50
        Top = 84
        Width = 63
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          132.291666666667
          222.25
          166.6875)
        Alignment = taCenter
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #36554#30058
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object Row1CodeText: TQRDBText
        Left = 23
        Top = 119
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          60.8541666666667
          314.854166666667
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'2'#12467#12540#12489
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
      object Row1NameText: TQRDBText
        Left = 56
        Top = 118
        Width = 193
        Height = 18
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          47.625
          148.166666666667
          312.208333333333
          510.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'2'#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object Row3CodeText: TQRDBText
        Left = 23
        Top = 183
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          60.8541666666667
          484.1875
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'3'#12467#12540#12489
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
      object Row3NameText: TQRDBText
        Left = 56
        Top = 182
        Width = 193
        Height = 18
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          47.625
          148.166666666667
          481.541666666667
          510.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'3'#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object Row2CodeText: TQRDBText
        Left = 23
        Top = 151
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          60.8541666666667
          399.520833333333
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'1'#12467#12540#12489
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
      object Row2NameText: TQRDBText
        Left = 56
        Top = 150
        Width = 193
        Height = 18
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          47.625
          148.166666666667
          396.875
          510.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'1'#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object GrossTimeText: TQRDBText
        Left = 47
        Top = 244
        Width = 51
        Height = 21
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          124.354166666667
          645.583333333333
          134.9375)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #35336#37327#26085#26178'1'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object GrossWText: TQRDBText
        Left = 134
        Top = 244
        Width = 91
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          354.541666666667
          645.583333333333
          240.770833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #32207#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object TareWText: TQRDBText
        Left = 134
        Top = 277
        Width = 91
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          354.541666666667
          732.895833333333
          240.770833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #31354#36554#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object NetWText: TQRDBText
        Left = 134
        Top = 310
        Width = 91
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          354.541666666667
          820.208333333333
          240.770833333333)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #27491#21619#37325#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object QRLabel1: TQRLabel
        Left = 149
        Top = 440
        Width = 7
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          394.229166666667
          1164.16666666667
          18.5208333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = '.'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clSilver
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 8
      end
      object Row4CodeText: TQRDBText
        Left = 23
        Top = 214
        Width = 29
        Height = 17
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          44.9791666666667
          60.8541666666667
          566.208333333333
          76.7291666666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'3'#12467#12540#12489
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
      object Row4NameText: TQRDBText
        Left = 56
        Top = 213
        Width = 193
        Height = 18
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          47.625
          148.166666666667
          563.5625
          510.645833333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #38917#30446'3'#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 13
      end
      object TareTimeText: TQRDBText
        Left = 47
        Top = 277
        Width = 51
        Height = 21
        Enabled = False
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          124.354166666667
          732.895833333333
          134.9375)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #35336#37327#26085#26178'2'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object AmountText: TQRExpr
        Left = 136
        Top = 342
        Width = 89
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          359.833333333333
          904.875
          235.479166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        Color = clWhite
        ParentFont = False
        ResetAfterPrint = False
        Transparent = False
        WordWrap = True
        Expression = 'Q_Slip.'#37329#38989' + Q_Slip.'#20253#31080#28040#36027#31246#38989
        Mask = '##,###,##0'
        FontSize = 15
      end
      object QuantityText: TQRDBText
        Left = 22
        Top = 342
        Width = 71
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          58.2083333333333
          904.875
          187.854166666667)
        Alignment = taRightJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #25968#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object QRLabel2: TQRLabel
        Left = 30
        Top = 52
        Width = 31
        Height = 20
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          52.9166666666667
          79.375
          137.583333333333
          82.0208333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'No.'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 14
      end
      object UnitText: TQRDBText
        Left = 96
        Top = 342
        Width = 25
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          254
          904.875
          66.1458333333333)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = False
        AutoStretch = False
        Color = clWhite
        DataSet = Q_Slip
        DataField = #21336#20301#12510#12473#12479#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object YenLabel: TQRLabel
        Left = 228
        Top = 342
        Width = 21
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          603.25
          904.875
          55.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = #20870
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object QRLabel3: TQRLabel
        Left = 228
        Top = 244
        Width = 21
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          603.25
          645.583333333333
          55.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object QRLabel4: TQRLabel
        Left = 228
        Top = 277
        Width = 21
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          603.25
          732.895833333333
          55.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
      object QRLabel5: TQRLabel
        Left = 228
        Top = 310
        Width = 21
        Height = 21
        Frame.Color = clBlack
        Frame.DrawTop = False
        Frame.DrawBottom = False
        Frame.DrawLeft = False
        Frame.DrawRight = False
        Size.Values = (
          55.5625
          603.25
          820.208333333333
          55.5625)
        Alignment = taLeftJustify
        AlignToBand = False
        AutoSize = True
        AutoStretch = False
        Caption = 'kg'
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        Transparent = False
        WordWrap = True
        FontSize = 15
      end
    end
  end
  object Q_Slip: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM '
      #9'V_'#35336#37327
      'WHERE'
      #9#35336#37327'ID = 29')
    Left = 9
    Top = 5
    object Q_SlipID: TAutoIncField
      FieldName = #35336#37327'ID'
      ReadOnly = True
    end
    object Q_SlipDSDesigner: TIntegerField
      FieldName = #35336#37327#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_SlipDSDesigner2: TIntegerField
      FieldName = #24180
      ReadOnly = True
    end
    object Q_SlipDSDesigner3: TIntegerField
      FieldName = #26376
      ReadOnly = True
    end
    object Q_SlipDSDesigner4: TIntegerField
      FieldName = #26085
      ReadOnly = True
    end
    object Q_SlipID2: TIntegerField
      FieldName = #25312#28857'ID'
    end
    object Q_SlipDSDesigner5: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object Q_SlipNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_SlipDSDesigner6: TIntegerField
      FieldName = #25644#20837#20986#21306#20998
    end
    object Q_SlipDSDesigner7: TStringField
      FieldName = #25644#20837#20986#21306#20998#21517
    end
    object Q_SlipID3: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_SlipDSDesigner8: TIntegerField
      FieldName = #36554#30058
    end
    object Q_SlipDSDesigner9: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_SlipID4: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Q_SlipDSDesigner10: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_SlipDSDesigner11: TStringField
      FieldName = #24471#24847#20808#12510#12473#12479#21517#31216
      Size = 50
    end
    object Q_SlipDSDesigner12: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Q_SlipDSDesigner13: TStringField
      FieldName = #24471#24847#20808#12459#12490
      Size = 50
    end
    object Q_SlipDSDesigner14: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_SlipDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object Q_SlipDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_SlipDSDesigner15: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner16: TStringField
      FieldName = #38917#30446'1'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner17: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object Q_SlipDSDesigner18: TStringField
      FieldName = #38917#30446'1'#12459#12490
      Size = 50
    end
    object Q_SlipDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object Q_SlipDSDesigner22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_SlipDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner24: TStringField
      FieldName = #38917#30446'2'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner25: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object Q_SlipDSDesigner26: TStringField
      FieldName = #38917#30446'2'#12459#12490
      Size = 50
    end
    object Q_SlipDSDesigner19: TStringField
      FieldName = #20633#32771
      Size = 40
    end
    object Q_SlipDSDesigner20: TBCDField
      FieldName = #20253#31080#28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object Q_SlipNo2: TIntegerField
      FieldName = #34892'No'
    end
    object Q_SlipID5: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_SlipDSDesigner21: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_SlipDSDesigner27: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner28: TStringField
      FieldName = #21697#30446#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner29: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object Q_SlipDSDesigner30: TStringField
      FieldName = #21697#30446#12459#12490
      Size = 50
    end
    object Q_SlipID6: TAutoIncField
      FieldName = #21697#30446#20998#39006'ID'
      ReadOnly = True
    end
    object Q_SlipDSDesigner31: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object Q_SlipDSDesigner32: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object Q_SlipDSDesigner33: TStringField
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object Q_SlipDSDesigner34: TStringField
      FieldName = #21697#30446#20998#39006#12459#12490
      Size = 50
    end
    object Q_SlipDSDesigner110: TBCDField
      FieldName = '1'#22238#30446#37325#37327
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_SlipDSDesigner111: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
      DisplayFormat = 'hh:nn'
    end
    object Q_SlipDSDesigner210: TBCDField
      FieldName = '2'#22238#30446#37325#37327
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_SlipDSDesigner211: TDateTimeField
      FieldName = #35336#37327#26085#26178'2'
      DisplayFormat = 'hh:nn'
    end
    object Q_SlipDSDesigner35: TBCDField
      FieldName = #35519#25972#29575
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 3
    end
    object Q_SlipDSDesigner36: TBCDField
      FieldName = #35519#25972#37325#37327
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_SlipDSDesigner37: TBCDField
      FieldName = #37325#37327#24341#12365
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_SlipDSDesigner38: TBCDField
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '#,###,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_SlipDSDesigner39: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '###,###,###.##'
      Precision = 10
      Size = 3
    end
    object Q_SlipID7: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object Q_SlipDSDesigner40: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object Q_SlipDSDesigner41: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object Q_SlipDSDesigner42: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '###,###,###.#'
      Precision = 13
      Size = 3
    end
    object Q_SlipDSDesigner43: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '###,###,##0'
      Precision = 10
      Size = 0
    end
    object Q_SlipDSDesigner44: TBCDField
      FieldName = #28040#36027#31246#38989
      DisplayFormat = '###,###,##0'
      Precision = 10
      Size = 0
    end
    object Q_SlipDSDesigner45: TStringField
      FieldName = #26126#32048#20633#32771
    end
    object Q_SlipDSDesigner46: TIntegerField
      FieldName = #23436#20102#21306#20998
    end
    object Q_SlipDSDesigner47: TStringField
      FieldName = #23436#20102#21306#20998#21517
    end
    object Q_SlipDSDesigner48: TDateTimeField
      FieldName = #26356#26032#26085#26178
    end
    object Q_SlipDSDesigner49: TDateTimeField
      FieldName = #20316#25104#26085#26178
    end
    object Q_SlipDSDesigner50: TIntegerField
      FieldName = #29694#25499#21306#20998
    end
  end
end
