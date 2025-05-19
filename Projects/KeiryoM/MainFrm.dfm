object MainForm: TMainForm
  Left = -1452
  Top = 178
  Width = 1024
  Height = 768
  Caption = #35336#37327#20966#29702
  Color = 16773616
  Constraints.MinHeight = 734
  Constraints.MinWidth = 1024
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    1016
    737)
  PixelsPerInch = 96
  TextHeight = 15
  object MeisaiScrollBox: TScrollBox
    Left = 1
    Top = 281
    Width = 718
    Height = 30
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 16773616
    ParentColor = False
    TabOrder = 9
    object MeisaiAddButton: TButton
      Left = 40
      Top = 0
      Width = 83
      Height = 30
      Caption = #26126#32048#36861#21152
      TabOrder = 0
      OnClick = MeisaiAddButtonClick
    end
    object MeisaiDeleteButton: TButton
      Left = 136
      Top = 0
      Width = 83
      Height = 30
      Caption = #26126#32048#21066#38500
      TabOrder = 1
      OnClick = MeisaiDeleteButtonClick
    end
    object RecalcButton: TButton
      Left = 232
      Top = 0
      Width = 83
      Height = 30
      Caption = #20877#35336#31639
      TabOrder = 2
      OnClick = RecalcButtonClick
    end
    object HannyuCombo: TComboBox
      Left = 584
      Top = 3
      Width = 97
      Height = 27
      Style = csDropDownList
      Color = clCream
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 19
      ItemIndex = 0
      ParentFont = False
      TabOrder = 3
      TabStop = False
      Text = '1:'#25644#20837
      OnKeyDown = HannyuComboKeyDown
      Items.Strings = (
        '1:'#25644#20837
        '2:'#25644#20986)
    end
  end
  object ScrollBox: TScrollBox
    Left = 1
    Top = 60
    Width = 718
    Height = 220
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 16773616
    ParentColor = False
    TabOrder = 1
    DesignSize = (
      718
      220)
    object SharyoPanel: TPanel
      Left = 4
      Top = 3
      Width = 709
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object SharyoButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #36554#12288#12288#20001
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = False
        OnClick = SharyoButtonClick
      end
      object ShabanEdit: TCobEdit
        Tag = 1
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 6
        ParentFont = False
        TabOrder = 1
        Text = '123456'
        OnChange = ShabanEditChange
        OnExit = ShabanEditExit
        OnKeyDown = ShabanEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object SharyoNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 209
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '12345678901234567890'
        IsInsert = True
      end
    end
    object TokuPanel: TPanel
      Left = 4
      Top = 42
      Width = 709
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object TokuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #24471' '#24847' '#20808
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = False
        OnClick = TokuButtonClick
      end
      object TokuCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = TokuCodeEditChange
        OnExit = TokuCodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TokuNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 508
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '12345678901234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object Komoku1Panel: TPanel
      Left = 4
      Top = 81
      Width = 709
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Komoku1Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #38917' '#30446' '#65297
        TabOrder = 0
        TabStop = False
        OnClick = Komoku1ButtonClick
      end
      object Komoku1CodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = Komoku1CodeEditChange
        OnExit = Komoku1CodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
      object Komoku1NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 409
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object Komoku2Panel: TPanel
      Left = 4
      Top = 120
      Width = 709
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 3
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Komoku2Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #38917' '#30446' '#65298
        TabOrder = 0
        TabStop = False
        OnClick = Komoku2ButtonClick
      end
      object Komoku2NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 409
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
      object Komoku2CodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = Komoku2CodeEditChange
        OnExit = Komoku2CodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object BikoPanel: TPanel
      Left = 4
      Top = 160
      Width = 709
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 4
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object BikoButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #20633#12288#12288#32771
        TabOrder = 0
        TabStop = False
      end
      object BikoEdit: TCobEdit
        Tag = 999
        Left = 108
        Top = 5
        Width = 409
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imHira
        MaxLength = 40
        ParentFont = False
        TabOrder = 1
        Text = '1234567890123456789012345678901234567890'
        OnKeyDown = BikoEditKeyDown
        OnKeyPress = BikoEditKeyPress
        IsInsert = True
      end
    end
  end
  object KeyPanel: TPanel
    Left = 0
    Top = 662
    Width = 1016
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    Color = 4276545
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object F1Panel: TPanel
      Left = 17
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F1'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
    end
    object F2Panel: TPanel
      Left = 97
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F2'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
    end
    object F3Panel: TPanel
      Left = 177
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F3'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 14
    end
    object F4Panel: TPanel
      Left = 257
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F4'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
    end
    object F5Panel: TPanel
      Left = 347
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F5'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 16
    end
    object F6Panel: TPanel
      Left = 427
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F6'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 17
    end
    object F7Panel: TPanel
      Left = 507
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F7'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 18
    end
    object F8Panel: TPanel
      Left = 587
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F8'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 19
    end
    object F9Panel: TPanel
      Left = 677
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F9'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 20
    end
    object F10Panel: TPanel
      Left = 757
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F10'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 21
    end
    object F11Panel: TPanel
      Left = 837
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F11'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 22
    end
    object F12Panel: TPanel
      Left = 917
      Top = 5
      Width = 79
      Height = 16
      Caption = 'F12'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 23
    end
    object F1Button: TButton
      Left = 16
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F1'
      Action = Action1
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
      TabStop = False
    end
    object F2Button: TButton
      Left = 96
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F2'
      Action = Action2
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      TabStop = False
    end
    object F3Button: TButton
      Left = 176
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F3'
      Action = Action3
      ParentShowHint = False
      ShowHint = False
      TabOrder = 2
      TabStop = False
    end
    object F4Button: TButton
      Left = 256
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F4'
      Action = Action4
      ParentShowHint = False
      ShowHint = False
      TabOrder = 3
      TabStop = False
    end
    object F5Button: TButton
      Left = 346
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F5'
      Action = Action5
      ParentShowHint = False
      ShowHint = False
      TabOrder = 4
      TabStop = False
    end
    object F6Button: TButton
      Left = 426
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F6'
      Action = Action6
      ParentShowHint = False
      ShowHint = False
      TabOrder = 5
      TabStop = False
    end
    object F7Button: TButton
      Left = 506
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F7'
      Action = Action7
      ParentShowHint = False
      ShowHint = False
      TabOrder = 6
      TabStop = False
    end
    object F8Button: TButton
      Left = 586
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F8'
      Action = Action8
      ParentShowHint = False
      ShowHint = False
      TabOrder = 7
      TabStop = False
    end
    object F9Button: TButton
      Left = 676
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F9'
      Action = Action9
      ParentShowHint = False
      ShowHint = False
      TabOrder = 8
      TabStop = False
    end
    object F10Button: TButton
      Left = 756
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F10'
      Action = Action10
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 9
      TabStop = False
    end
    object F11Button: TButton
      Left = 836
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F11'
      Action = Action11
      ParentShowHint = False
      ShowHint = False
      TabOrder = 10
      TabStop = False
    end
    object F12Button: TButton
      Left = 916
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F12'
      Action = Action12
      ParentShowHint = False
      ShowHint = False
      TabOrder = 11
      TabStop = False
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 719
    Width = 1016
    Height = 18
    Panels = <
      item
        Width = 500
      end
      item
        Width = 50
      end>
    ParentShowHint = False
    ShowHint = True
    SimplePanel = True
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 61
    Align = alTop
    BevelOuter = bvNone
    Color = 16562584
    TabOrder = 0
    DesignSize = (
      1016
      61)
    object kgPanel: TLabel
      Left = 954
      Top = 13
      Width = 46
      Height = 42
      Anchors = [akTop, akRight]
      Caption = 'Kg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -35
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 108
      Top = 10
      Width = 48
      Height = 16
      Caption = #35336#37327#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 260
      Top = 10
      Width = 48
      Height = 16
      Caption = #20253#31080'No'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object KyotenLabel: TLabel
      Left = 484
      Top = 10
      Width = 32
      Height = 16
      Caption = #25312#28857
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 380
      Top = 10
      Width = 64
      Height = 16
      Caption = #35336#37327#26178#21051
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object ModePanel: TPanel
      Left = 12
      Top = 10
      Width = 77
      Height = 43
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Caption = #20462#27491
      Color = 13563088
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object WeightPanel: TPanel
      Left = 726
      Top = 6
      Width = 221
      Height = 51
      Alignment = taRightJustify
      Anchors = [akTop, akRight]
      BevelOuter = bvNone
      Color = clBlack
      Font.Charset = ANSI_CHARSET
      Font.Color = 13498276
      Font.Height = -48
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object KeiryoDatePicker: TDateTimePicker
      Tag = 1
      Left = 108
      Top = 27
      Width = 129
      Height = 27
      CalAlignment = dtaLeft
      Date = 39587.8647289815
      Time = 39587.8647289815
      Color = clCream
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 0
      OnChange = KeiryoDatePickerChange
    end
    object KeiryoNoEdit: TCobEdit
      Tag = 1
      Left = 260
      Top = 27
      Width = 105
      Height = 27
      Color = clCream
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 1
      Text = '123456789'
      OnKeyDown = KeiryoNoEditKeyDown
      Alignment = taRightJustify
    end
    object PlaceCombo: TComboBox
      Tag = 1
      Left = 484
      Top = 27
      Width = 225
      Height = 27
      Style = csDropDownList
      Color = clCream
      Enabled = False
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 19
      ItemIndex = 0
      ParentFont = False
      TabOrder = 2
      Text = #26412#31038'5678901234567890'
      OnChange = PlaceComboChange
      Items.Strings = (
        #26412#31038'5678901234567890')
    end
    object KeiryoTimePicker: TDateTimePicker
      Tag = 1
      Left = 380
      Top = 27
      Width = 77
      Height = 27
      CalAlignment = dtaLeft
      Date = 39587.9993055556
      Format = 'HH:mm'
      Time = 39587.9993055556
      Color = clCream
      DateFormat = dfShort
      DateMode = dmUpDown
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      Kind = dtkTime
      ParseInput = False
      ParentFont = False
      TabOrder = 5
    end
  end
  object AutoPrintCheck: TCheckBox
    Left = 569
    Top = 262
    Width = 141
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #20253#31080#12434#21360#23383#12377#12427
    TabOrder = 5
  end
  object DataDeleteCheck: TCheckBox
    Left = 249
    Top = 262
    Width = 149
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #12487#12540#12479#12434#27531#12373#12394#12356
    TabOrder = 6
  end
  object HideTimeCheck: TCheckBox
    Left = 409
    Top = 262
    Width = 149
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #26178#38291#12434#21360#23383#12375#12394#12356
    TabOrder = 7
  end
  object SCGrid: TStrColGrid
    Tag = 888
    Left = 0
    Top = 325
    Width = 1016
    Height = 311
    Align = alBottom
    ColCount = 9
    DefaultColWidth = 60
    DefaultRowHeight = 21
    DefaultDrawing = False
    RowCount = 7
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goAlwaysShowEditor]
    TabOrder = 2
    OnClick = SCGridClick
    OnDblClick = SCGridDblClick
    OnDrawCell = SCGridDrawCell
    OnKeyDown = SCGridKeyDown
    OnKeyPress = SCGridKeyPress
    OnSelectCell = SCGridSelectCell
    OnSetEditText = SCGridSetEditText
    CellParams = <
      item
        Alignment = taCenter
        CellColor = clBtnFace
        Col = 0
        ColMax = 99
        FontColor = clWindowText
        FontWidth = 1
        ImeModeEnabled = False
        Layout = tlCenter
        Name = 'ItemNameColumn'
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect]
        OptionsEnabled = True
        Row = 0
        RowMax = 2
        Tag = 1
      end
      item
        CellColor = 16050642
        Col = 0
        ColMax = 99
        Brush.Color = clWindow
        FontColor = clWindowText
        FontWidth = 1
        ImeModeEnabled = False
        Layout = tlCenter
        Name = 'DataColumn'
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
        OptionsEnabled = True
        Row = 3
        RowMax = 99
        Tag = 0
      end>
    Fonts = <>
    FixedLayout = tlBottom
    Layout = tlTop
    OnCellChanged = SCGridCellChanged
    ColWidths = (
      60
      60
      60
      60
      60
      60
      60
      60
      60)
  end
  object TotalPanel: TPanel
    Left = 0
    Top = 636
    Width = 1016
    Height = 26
    Align = alBottom
    BevelOuter = bvNone
    Color = 13891060
    TabOrder = 10
    object TotalWeightTitle: TLabel
      Left = 86
      Top = 7
      Width = 72
      Height = 15
      Caption = #21512#35336#37325#37327':'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TotalWeightLabel: TLabel
      Left = 163
      Top = 6
      Width = 150
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567,890kg'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
    object MoneyTitle: TLabel
      Left = 358
      Top = 7
      Width = 40
      Height = 15
      Caption = #37329#38989':'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object MoneyLabel: TLabel
      Left = 398
      Top = 6
      Width = 130
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567,890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TaxTitle: TLabel
      Left = 558
      Top = 7
      Width = 56
      Height = 15
      Caption = #28040#36027#31246':'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TaxLabel: TLabel
      Left = 618
      Top = 6
      Width = 130
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567,890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TotalMoneyTitle: TLabel
      Left = 782
      Top = 7
      Width = 72
      Height = 15
      Caption = #21512#35336#37329#38989':'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TotalMoneyLabel: TLabel
      Left = 861
      Top = 6
      Width = 130
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567,890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TotalWeightShape: TShape
      Left = 86
      Top = 22
      Width = 231
      Height = 1
    end
    object MoneyShape: TShape
      Left = 355
      Top = 22
      Width = 176
      Height = 1
    end
    object TaxShape: TShape
      Left = 556
      Top = 22
      Width = 194
      Height = 1
    end
    object TotalMoneyShape: TShape
      Left = 781
      Top = 22
      Width = 217
      Height = 1
    end
  end
  object PostMessageCheck: TCheckBox
    Left = 81
    Top = 262
    Width = 161
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #30331#37682#12513#12483#12475#12540#12472#12394#12375
    TabOrder = 11
  end
  object TairyuPanel: TPanel
    Left = 730
    Top = 61
    Width = 286
    Height = 264
    Align = alRight
    BevelOuter = bvLowered
    Color = 14803425
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object Label16: TLabel
      Left = 4
      Top = 25
      Width = 22
      Height = 21
      Caption = #28382
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 4
      Top = 73
      Width = 22
      Height = 21
      Caption = #30041
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 4
      Top = 121
      Width = 22
      Height = 21
      Caption = #36554
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 4
      Top = 217
      Width = 22
      Height = 21
      Caption = #22577
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label23: TLabel
      Left = 4
      Top = 169
      Width = 22
      Height = 21
      Caption = #24773
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -21
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TairyuGrid: TDBCtrlGrid
      Left = 28
      Top = 1
      Width = 257
      Height = 262
      Align = alRight
      AllowDelete = False
      AllowInsert = False
      ColCount = 1
      Color = clWhite
      DataSource = dsTairyu
      PanelBorder = gbNone
      PanelHeight = 65
      PanelWidth = 240
      ParentColor = False
      TabOrder = 0
      RowCount = 4
      SelectedColor = 14999039
      OnDblClick = OnSelectTairyu
      object TairyuTokuisakiLabel: TLabel
        Left = 20
        Top = 47
        Width = 56
        Height = 13
        Caption = #24471#24847#20808#65313
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 5066061
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object TairyuCarNameText: TDBText
        Left = 124
        Top = 25
        Width = 165
        Height = 14
        DataField = #36554#20001#21517#31216
        DataSource = dsTairyu
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object TairyuDateText: TDBText
        Left = 77
        Top = 3
        Width = 153
        Height = 14
        DataField = #35336#37327#26085#26178'1'
        DataSource = dsTairyu
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object TairyuDateLabel: TLabel
        Left = 20
        Top = 5
        Width = 42
        Height = 13
        Caption = #26085#12288#26178
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 5066061
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object Shape1: TShape
        Left = 5
        Top = 43
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object Shape2: TShape
        Left = 5
        Top = 21
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuTokuisakiText: TDBText
        Left = 77
        Top = 46
        Width = 165
        Height = 14
        DataField = #24471#24847#20808#30053#31216
        DataSource = dsTairyu
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object Shape3: TShape
        Left = 5
        Top = 62
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
      end
      object Shape4: TShape
        Left = 0
        Top = 2
        Width = 17
        Height = 61
        Anchors = [akLeft, akTop, akRight]
        Brush.Color = clGray
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuCarNoText: TDBText
        Left = 77
        Top = 25
        Width = 41
        Height = 14
        DataField = #36554#30058
        DataSource = dsTairyu
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        OnDblClick = OnSelectTairyu
      end
      object Label2: TLabel
        Left = 20
        Top = 27
        Width = 42
        Height = 13
        Caption = #36554#12288#30058
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 5066061
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
    end
  end
  object ActionList: TActionList
    Left = 388
    Top = 284
    object Action1: TAction
      Caption = #26032#35215
      Hint = #26032#12375#12356#20253#31080#12434#20316#25104#12377#12427
      ShortCut = 112
      OnExecute = Action1Execute
    end
    object Action2: TAction
      Caption = #20462#27491
      Hint = #28382#30041#36554#24773#22577#12434#21628#12403#20986#12377
      ShortCut = 113
      OnExecute = Action2Execute
    end
    object Action3: TAction
      Caption = #21066#38500
      Hint = #20253#31080#12434#21066#38500#12377#12427
      ShortCut = 114
      OnExecute = Action3Execute
    end
    object Action4: TAction
      ShortCut = 115
      OnExecute = Action4Execute
    end
    object Action5: TAction
      Caption = #30331#37682
      Hint = #20253#31080#12434#30331#37682#12377#12427
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action6: TAction
      Caption = #21069#12408
      ShortCut = 117
      OnExecute = Action6Execute
    end
    object Action7: TAction
      Caption = #27425#12408
      ShortCut = 118
      OnExecute = Action7Execute
    end
    object Action8: TAction
      Caption = #20253#31080#30330#34892
      Hint = #20253#31080#30330#34892#12377#12427
      ShortCut = 119
      OnExecute = Action8Execute
    end
    object Action9: TAction
      Caption = #26908#32034
      Hint = #20253#31080#12434#26908#32034#12377#12427
      ShortCut = 120
      OnExecute = Action9Execute
    end
    object Action10: TAction
      Caption = #37325#37327#20516
      Hint = #37325#37327#20516#12434#21462#24471#12377#12427
      ShortCut = 121
      OnExecute = Action10Execute
    end
    object Action11: TAction
      ShortCut = 122
    end
    object Action12: TAction
      Caption = #32066#20102
      Hint = #35336#37327#20966#29702#12434#32066#20102#12377#12427
      ShortCut = 123
      OnExecute = Action12Execute
    end
  end
  object Q_Tairyu: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    BeforeOpen = Q_TairyuBeforeOpen
    AfterOpen = Q_TairyuAfterOpen
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#35336#37327'ID,'
      #9#35336#37327#26085#26178'1,'
      #9#35336#37327#26085','
      #9#20253#31080'No,'
      #9#36554#30058','
      #9#36554#20001#21517#31216','
      #9#24471#24847#20808#30053#31216
      'FROM'
      #9'V_'#35336#37327
      'WHERE'
      #9#34892'No = 1'
      'AND'
      #9#23436#20102#21306#20998' = 0')
    Left = 820
    Top = 216
    object Q_TairyuDSDesigner: TIntegerField
      FieldName = #35336#37327#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_TairyuNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_TairyuDSDesigner5: TIntegerField
      FieldName = #36554#30058
    end
    object Q_TairyuDSDesigner2: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_TairyuDSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Q_TairyuDSDesigner1: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
      DisplayFormat = 'yyyy-mm-dd h:nn'
    end
    object Q_TairyuID: TAutoIncField
      FieldName = #35336#37327'ID'
      ReadOnly = True
    end
  end
  object dsTairyu: TDataSource
    DataSet = Q_Tairyu
    Left = 792
    Top = 216
  end
  object Q_Meisai: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#35336#37327'ID,'
      #9#20253#31080'No,'
      #9#34892'No,'
      #9'X.'#21697#30446'ID, HM.'#21697#30446#12467#12540#12489', '
      #9'X.'#21697#30446#21517#31216','
      #9'1'#22238#30446#37325#37327','
      #9#35336#37327#26085#26178'1,'
      #9'2'#22238#30446#37325#37327','
      #9#35336#37327#26085#26178'2,'
      #9#35519#25972#29575','
      #9#35519#25972#37325#37327','
      #9#37325#37327#24341#12365','
      #9#27491#21619#37325#37327','
      #9#25968#37327','
      #9'X.'#21336#20301'ID, TN.'#21336#20301#21517#31216','
      #9#21336#20385','
      #9#37329#38989','
      #9#26126#32048#20633#32771
      ''
      'FROM'
      #9'V_'#35336#37327' AS X'
      #9'LEFT OUTER JOIN M_'#21336#20301' AS TN ON X.'#21336#20301'ID = TN.'#21336#20301'ID'
      #9'LEFT OUTER JOIN M_'#21697#30446' AS HM ON X.'#21697#30446'ID = HM.'#21697#30446'ID')
    Left = 836
    Top = 288
    object Q_MeisaiID: TAutoIncField
      FieldName = #35336#37327'ID'
      ReadOnly = True
      Visible = False
    end
    object Q_MeisaiNo: TIntegerField
      FieldName = #20253#31080'No'
      Visible = False
    end
    object Q_MeisaiNo2: TIntegerField
      DisplayWidth = 4
      FieldName = #34892'No'
    end
    object Q_MeisaiID2: TIntegerField
      FieldName = #21697#30446'ID'
      Visible = False
    end
    object Q_MeisaiDSDesigner13: TIntegerField
      DisplayLabel = '*'
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_MeisaiDSDesigner: TStringField
      DisplayWidth = 20
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_MeisaiDSDesigner2: TBCDField
      DisplayWidth = 8
      FieldName = #32207#37325#37327
      DisplayFormat = '#,###'
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner1: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
      Visible = False
    end
    object Q_MeisaiDSDesigner3: TBCDField
      DisplayWidth = 8
      FieldName = #31354#36554#37325#37327
      DisplayFormat = '#,###'
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner22: TDateTimeField
      FieldName = #35336#37327#26085#26178'2'
      Visible = False
    end
    object Q_MeisaiDSDesigner4: TBCDField
      DisplayWidth = 6
      FieldName = #35519#25972#29575
      Precision = 10
      Size = 3
    end
    object Q_MeisaiDSDesigner5: TBCDField
      DisplayWidth = 8
      FieldName = #35519#25972#37325#37327
      DisplayFormat = '#,###'
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner6: TBCDField
      DisplayWidth = 8
      FieldName = #37325#37327#24341#12365
      DisplayFormat = '#,###'
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner7: TBCDField
      DisplayWidth = 8
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '#,###'
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner8: TBCDField
      DisplayWidth = 10
      FieldName = #25968#37327
      DisplayFormat = '#,###.###'
      Precision = 10
      Size = 3
    end
    object Q_MeisaiID3: TIntegerField
      FieldName = #21336#20301'ID'
      Visible = False
    end
    object Q_MeisaiDSDesigner9: TStringField
      DisplayLabel = #21336#20301
      DisplayWidth = 6
      FieldName = #21336#20301#21517#31216
      Size = 10
    end
    object Q_MeisaiDSDesigner10: TBCDField
      DisplayWidth = 10
      FieldName = #21336#20385
      DisplayFormat = '#,###.###'
      Precision = 13
      Size = 3
    end
    object Q_MeisaiDSDesigner11: TBCDField
      DisplayWidth = 13
      FieldName = #37329#38989
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_MeisaiDSDesigner12: TStringField
      FieldName = #26126#32048#20633#32771
    end
  end
  object dsMeisai: TDataSource
    DataSet = Q_Meisai
    Left = 868
    Top = 288
  end
  object ClientSocket: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnRead = ClientSocketRead
    OnError = ClientSocketError
    Left = 332
    Top = 284
  end
  object SocketReopenTimer: TTimer
    Enabled = False
    OnTimer = SocketReopenTimerTimer
    Left = 360
    Top = 284
  end
  object TairyuTimer: TTimer
    Enabled = False
    OnTimer = TairyuTimerTimer
    Left = 812
    Top = 148
  end
end
