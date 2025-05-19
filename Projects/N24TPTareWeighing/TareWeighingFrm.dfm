object TareWeighingForm: TTareWeighingForm
  Left = 302
  Top = 36
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'N-24TP '#31354#36554#37325#37327#35336#37327
  ClientHeight = 734
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 93
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#12288'N-24TP '#31354#36554#37325#37327#35336#37327
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 656
    Width = 1016
    Height = 78
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1016
      78)
    object CloseButton: TButton
      Left = 20
      Top = 10
      Width = 281
      Height = 59
      Anchors = [akTop, akRight]
      Caption = #31649#29702#12513#12491#12517#12540#12395#25147#12427
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = CloseButtonClick
    end
    object BackButton: TButton
      Left = 780
      Top = 10
      Width = 207
      Height = 59
      Anchors = [akTop, akRight]
      Caption = #65308#12288#25147#12427
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnClick = BackButtonClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 93
    Width = 1016
    Height = 563
    Align = alClient
    TabOrder = 2
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 1014
      Height = 561
      ActivePage = ModeSelectSheet
      Align = alClient
      Style = tsFlatButtons
      TabOrder = 0
      object WaitCardSheet: TTabSheet
        Caption = 'WaitCardSheet'
        ImageIndex = 4
        TabVisible = False
        object StatusLabel: TLabel
          Left = 207
          Top = 352
          Width = 132
          Height = 24
          Caption = 'StatusLabel'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clMaroon
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
        end
        object Panel10: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#12434#12363#12374#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object StatusMemo: TMemo
          Left = 207
          Top = 404
          Width = 593
          Height = 125
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            #12459#12540#12489#24418#24335#12364#28961#21177#12391#12377#12290
            #12371#12398#12459#12540#12489#12399#12289#24403#12471#12473#12486#12512#12391#12399#20351#29992#12391#12365#12414#12379#12435#12290
            #12372#20102#25215#12367#12384#12373#12356#12290)
          ParentColor = True
          ParentFont = False
          TabOrder = 1
        end
      end
      object ModeSelectSheet: TTabSheet
        Caption = 'ModeSelectSheet'
        ImageIndex = 3
        TabVisible = False
        DesignSize = (
          1006
          551)
        object Panel4: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #20966#29702#12434#36984#25246#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object SetTareButton: TButton
          Left = 151
          Top = 400
          Width = 326
          Height = 73
          Anchors = [akTop, akRight]
          Caption = #31354#36554#37325#37327#12434#35373#23450#12377#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          TabStop = False
          OnClick = SetTareButtonClick
        end
        object Panel1: TPanel
          Left = 142
          Top = 288
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#30058
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object Bevel1: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item2TitlePanel: TPanel
          Left = 142
          Top = 240
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#38917#30446'2'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          object Bevel5: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object CarNoPanel: TPanel
          Left = 362
          Top = 288
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 4
        end
        object Item2Panel: TPanel
          Left = 362
          Top = 240
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 5
        end
        object TokuTitlePanel: TPanel
          Left = 142
          Top = 96
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#24471#24847#20808
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          object Bevel6: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TokuPanel: TPanel
          Left = 362
          Top = 96
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 7
        end
        object Button1: TButton
          Left = 528
          Top = 400
          Width = 326
          Height = 73
          Anchors = [akTop, akRight]
          Caption = #31354#36554#37325#37327#12434#28961#21177#12395#12377#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          TabStop = False
          OnClick = Button1Click
        end
        object Memo1: TMemo
          Left = 529
          Top = 488
          Width = 486
          Height = 37
          Anchors = [akTop, akRight]
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clMaroon
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          Lines.Strings = (
            #28961#21177#12395#12377#12427#12392#12289#19968#22238#35336#37327#12391#12399#12394#12367#12394#12426#12414#12377#12290)
          ParentColor = True
          ParentFont = False
          TabOrder = 9
        end
        object Panel5: TPanel
          Left = 360
          Top = 336
          Width = 269
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = ' '#31354#36554#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          object Bevel4: TBevel
            Left = 0
            Top = 24
            Width = 269
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
          object TareWeightLabel: TLabel
            Left = 141
            Top = 4
            Width = 120
            Height = 24
            Alignment = taRightJustify
            Caption = '          '
            Font.Charset = SHIFTJIS_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = []
            ParentFont = False
          end
        end
        object Item1TitlePanel: TPanel
          Left = 142
          Top = 192
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#38917#30446'1'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 11
          object Bevel2: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item1Panel: TPanel
          Left = 362
          Top = 192
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 12
        end
        object MeigTitlePanel: TPanel
          Left = 142
          Top = 144
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#37528#26564
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          object Bevel3: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object MeigPanel: TPanel
          Left = 362
          Top = 144
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 14
        end
      end
      object WarningSheet: TTabSheet
        Caption = 'WarningSheet'
        ImageIndex = 2
        TabVisible = False
        DesignSize = (
          1006
          551)
        object WarningMemo: TMemo
          Left = 172
          Top = 128
          Width = 661
          Height = 205
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            #12371#12398#12459#12540#12489#12395#12399#36554#30058#12364#25351#23450#12373#12428#12390#12356#12414#12379#12435#12290
            ''
            ''
            #12371#12398#12459#12540#12489#12395#31354#36554#37325#37327#12434#35373#23450#12377#12427#12392#12289#12371#12398#12459#12540#12489#12391#12398#35336#37327#12364
            #20840#12390#19968#22238#35336#37327#12395#12394#12387#12390#12375#12414#12356#12414#12377#12290
            ''
            ''
            #20966#29702#12434#32154#12369#12427#22580#21512#12399#12289#30906#35469#12508#12479#12531#12434#25276#12375#12390#12367#12384#12373#12356#12290)
          ParentColor = True
          ParentFont = False
          TabOrder = 0
        end
        object WarningConfirmButton: TButton
          Left = 406
          Top = 386
          Width = 195
          Height = 59
          Anchors = [akTop, akRight]
          Caption = #30906#35469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          TabStop = False
          OnClick = WarningConfirmButtonClick
        end
        object Panel3: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#12434#30906#35469#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
      end
      object WeighTareSheet: TTabSheet
        Caption = 'WeighTareSheet'
        ImageIndex = 4
        TabVisible = False
        DesignSize = (
          1006
          551)
        object Panel7: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #31354#36554#37325#37327#12434#30906#35469#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object WeightPanel: TPanel
          Left = 368
          Top = 123
          Width = 270
          Height = 74
          Align = alCustom
          Alignment = taRightJustify
          Anchors = [akTop, akRight]
          BevelOuter = bvLowered
          Color = clBlack
          Font.Charset = ANSI_CHARSET
          Font.Color = clLime
          Font.Height = -48
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object WeighTareButton: TButton
          Left = 406
          Top = 386
          Width = 195
          Height = 59
          Anchors = [akTop, akRight]
          Caption = #35373#23450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          TabStop = False
          OnClick = WeighTareButtonClick
        end
      end
      object CompleteSheet: TTabSheet
        Caption = 'CompleteSheet'
        ImageIndex = 3
        TabVisible = False
        DesignSize = (
          1006
          551)
        object Panel6: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #20966#29702#12364#23436#20102#12375#12414#12375#12383
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object CompleteMemo: TMemo
          Left = 172
          Top = 168
          Width = 661
          Height = 205
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            #31354#36554#37325#37327#12434#28961#21177#12395#12375#12414#12375#12383#12290)
          ParentColor = True
          ParentFont = False
          TabOrder = 1
        end
        object CompleteConfirmButton: TButton
          Left = 406
          Top = 386
          Width = 195
          Height = 59
          Anchors = [akTop, akRight]
          Caption = #30906#35469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          TabStop = False
          OnClick = CompleteConfirmButtonClick
        end
      end
    end
  end
  object ActivateTimer: TTimer
    OnTimer = ActivateTimerTimer
    Left = 616
    Top = 28
  end
  object ClientSocket: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 8080
    OnRead = ClientSocketRead
    OnError = ClientSocketError
    Left = 644
    Top = 28
  end
end
