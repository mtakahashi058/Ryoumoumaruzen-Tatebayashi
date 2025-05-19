object CardIssueForm: TCardIssueForm
  Left = 408
  Top = 22
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'RFID '#12459#12540#12489#20316#25104
  ClientHeight = 734
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 65
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288'RFID'#12459#12540#12489' '#30330#34892
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 674
    Width = 1016
    Height = 60
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1016
      60)
    object CloseButton: TButton
      Left = 868
      Top = 10
      Width = 129
      Height = 39
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = CloseButtonClick
    end
    object N24TPCardsButton: TButton
      Left = 12
      Top = 10
      Width = 201
      Height = 39
      Anchors = [akTop, akRight]
      Caption = 'N-24TP'#29992#12459#12540#12489
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnClick = N24TPCardsButtonClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 65
    Width = 1016
    Height = 609
    Align = alClient
    TabOrder = 2
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 1014
      Height = 607
      ActivePage = CardSheet
      Align = alClient
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      Style = tsFlatButtons
      TabHeight = 44
      TabOrder = 0
      TabWidth = 160
      object CardSheet: TTabSheet
        Caption = #19968#33324#12459#12540#12489
        ImageIndex = 3
        TabVisible = False
        DesignSize = (
          1006
          597)
        object Panel4: TPanel
          Left = 36
          Top = 8
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#20869#23481#12434#20837#21147#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object CarNoPanel: TPanel
          Left = 126
          Top = 140
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#30058
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Bevel2: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TokuTitlePanel: TPanel
          Left = 126
          Top = 185
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          object Bevel3: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object IssueButton: TButton
          Tag = 999
          Left = 717
          Top = 482
          Width = 195
          Height = 59
          Anchors = [akTop, akRight]
          Caption = #30330#34892
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 24
          OnClick = IssueButtonClick
        end
        object Item1TitlePanel: TPanel
          Left = 126
          Top = 274
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          object Bevel4: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item2TitlePanel: TPanel
          Left = 126
          Top = 320
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 17
          object Bevel1: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object CarNoEdit: TCobEdit
          Tag = 1
          Left = 328
          Top = 140
          Width = 93
          Height = 32
          ImeMode = imDisable
          MaxLength = 6
          TabOrder = 2
          OnChange = CarNoEditChange
          OnExit = CarNoEditExit
          OnKeyDown = CarNoEditKeyDown
          IsInsert = True
          Alignment = taRightJustify
        end
        object TokuEdit: TCobEdit
          Tag = 2
          Left = 344
          Top = 185
          Width = 77
          Height = 32
          ImeMode = imDisable
          MaxLength = 4
          TabOrder = 6
          OnChange = TokuEditChange
          OnKeyDown = TokuEditKeyDown
          IsInsert = True
          Alignment = taRightJustify
        end
        object Item1Edit: TCobEdit
          Tag = 3
          Left = 344
          Top = 274
          Width = 77
          Height = 32
          ImeMode = imDisable
          MaxLength = 4
          TabOrder = 14
          OnChange = Item1EditChange
          OnKeyDown = Item1EditKeyDown
          IsInsert = True
          Alignment = taRightJustify
        end
        object Item2Edit: TCobEdit
          Tag = 4
          Left = 344
          Top = 320
          Width = 77
          Height = 32
          ImeMode = imDisable
          MaxLength = 4
          TabOrder = 18
          OnChange = Item2EditChange
          OnKeyDown = Item2EditKeyDown
          IsInsert = True
          Alignment = taRightJustify
        end
        object TokuNameEdit: TCobEdit
          Tag = 2
          Left = 428
          Top = 185
          Width = 377
          Height = 32
          TabStop = False
          Color = clSilver
          ReadOnly = True
          TabOrder = 7
        end
        object Item1NameEdit: TCobEdit
          Tag = 3
          Left = 428
          Top = 274
          Width = 377
          Height = 32
          TabStop = False
          Color = clSilver
          ReadOnly = True
          TabOrder = 15
        end
        object Item2NameEdit: TCobEdit
          Tag = 4
          Left = 428
          Top = 320
          Width = 377
          Height = 32
          TabStop = False
          Color = clSilver
          ReadOnly = True
          TabOrder = 19
        end
        object TokuRefButton: TButton
          Left = 810
          Top = 185
          Width = 75
          Height = 32
          Caption = #21442#29031
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          TabStop = False
          OnClick = TokuRefButtonClick
        end
        object Item1RefButton: TButton
          Left = 810
          Top = 274
          Width = 75
          Height = 32
          Caption = #21442#29031
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 16
          TabStop = False
          OnClick = Item1RefButtonClick
        end
        object Item2RefButton: TButton
          Left = 810
          Top = 320
          Width = 75
          Height = 32
          Caption = #21442#29031
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 20
          TabStop = False
          OnClick = Item2RefButtonClick
        end
        object Panel1: TPanel
          Left = 342
          Top = 368
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#31354#36554#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 25
          object Bevel5: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TareEdit: TCobEdit
          Tag = 5
          Left = 548
          Top = 368
          Width = 109
          Height = 32
          ImeMode = imDisable
          MaxLength = 5
          TabOrder = 21
          IsInsert = True
          Alignment = taRightJustify
        end
        object Panel2: TPanel
          Left = 342
          Top = 404
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#20001#32207#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 26
          object Bevel6: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object GrossLimitEdit: TCobEdit
          Tag = 6
          Left = 548
          Top = 404
          Width = 109
          Height = 32
          ImeMode = imDisable
          MaxLength = 6
          TabOrder = 22
          IsInsert = True
          Alignment = taRightJustify
        end
        object Panel5: TPanel
          Left = 342
          Top = 440
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#26368#22823#31309#36617#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 27
          object Bevel7: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object NetLimitEdit: TCobEdit
          Tag = 7
          Left = 548
          Top = 440
          Width = 109
          Height = 32
          ImeMode = imDisable
          MaxLength = 6
          TabOrder = 23
          IsInsert = True
          Alignment = taRightJustify
        end
        object HinTitlePanel: TPanel
          Left = 126
          Top = 230
          Width = 191
          Height = 32
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          object Bevel8: TBevel
            Left = 0
            Top = 23
            Width = 191
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object HinEdit: TCobEdit
          Tag = 3
          Left = 344
          Top = 230
          Width = 77
          Height = 32
          ImeMode = imDisable
          MaxLength = 4
          TabOrder = 10
          OnChange = HinEditChange
          OnKeyDown = HinEditKeyDown
          IsInsert = True
          Alignment = taRightJustify
        end
        object HinNameEdit: TCobEdit
          Tag = 3
          Left = 428
          Top = 230
          Width = 377
          Height = 32
          TabStop = False
          Color = clSilver
          ReadOnly = True
          TabOrder = 11
        end
        object HinRefButton: TButton
          Left = 810
          Top = 230
          Width = 75
          Height = 32
          Caption = #21442#29031
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 12
          TabStop = False
          OnClick = HinRefButtonClick
        end
        object CarNameEdit: TCobEdit
          Tag = 2
          Left = 428
          Top = 140
          Width = 377
          Height = 32
          TabStop = False
          Color = clSilver
          ImeMode = imOpen
          MaxLength = 20
          ReadOnly = True
          TabOrder = 3
          IsInsert = True
        end
        object CarRefButton: TButton
          Left = 810
          Top = 140
          Width = 75
          Height = 32
          Caption = #21442#29031
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          TabStop = False
          OnClick = CarRefButtonClick
        end
        object ClearButton: TButton
          Tag = 999
          Left = 792
          Top = 66
          Width = 120
          Height = 35
          Anchors = [akTop, akRight]
          Caption = #12463#12522#12450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 28
          OnClick = ClearButtonClick
        end
      end
    end
  end
  object ActivateTimer: TTimer
    Left = 616
    Top = 28
  end
end
