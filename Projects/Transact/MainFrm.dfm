object MainForm: TMainForm
  Left = 205
  Top = 48
  Width = 1010
  Height = 769
  Caption = #21462#24341#12487#12540#12479#20837#21147
  Color = 16773616
  Constraints.MinHeight = 734
  Constraints.MinWidth = 1000
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
  PixelsPerInch = 96
  TextHeight = 15
  object KeyPanel: TPanel
    Left = 0
    Top = 656
    Width = 994
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
    TabOrder = 4
    object F1Panel: TPanel
      Left = 12
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
      Left = 92
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
      Left = 172
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
      Left = 252
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
      Left = 342
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
      Left = 422
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
      Left = 502
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
      Left = 582
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
      Left = 672
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
      Left = 752
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
      Left = 832
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
      Left = 912
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
      Left = 11
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
      Left = 91
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
      Left = 171
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
      Left = 251
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
      Left = 341
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
      Left = 421
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
      Left = 501
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
      Left = 581
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
      Left = 671
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
      Left = 751
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
      Left = 831
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
      Left = 911
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
    Top = 713
    Width = 994
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
  object ScrollBox: TScrollBox
    Left = 4
    Top = 72
    Width = 717
    Height = 261
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 16773616
    ParentColor = False
    TabOrder = 1
    DesignSize = (
      717
      261)
    object SharyoPanel: TPanel
      Left = 6
      Top = 20
      Width = 703
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
      Left = 6
      Top = 76
      Width = 703
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
        Width = 509
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
      Left = 6
      Top = 124
      Width = 703
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
      Left = 6
      Top = 168
      Width = 703
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
      Left = 6
      Top = 212
      Width = 703
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
        IsInsert = True
      end
    end
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 994
    Height = 65
    Align = alTop
    BevelOuter = bvNone
    Color = 9498256
    TabOrder = 0
    object Label20: TLabel
      Left = 116
      Top = 10
      Width = 48
      Height = 16
      Caption = #21462#24341#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 264
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
    object Label22: TLabel
      Left = 760
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
    object DatePicker: TDateTimePicker
      Tag = 1
      Left = 116
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
      OnChange = DatePickerChange
    end
    object NoEdit: TCobEdit
      Tag = 1
      Left = 264
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
      OnKeyDown = NoEditKeyDown
      Alignment = taRightJustify
    end
    object PlaceCombo: TComboBox
      Tag = 1
      Left = 760
      Top = 27
      Width = 225
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
      TabOrder = 2
      Text = #26412#31038'5678901234567890'
      OnChange = PlaceComboChange
      Items.Strings = (
        #26412#31038'5678901234567890')
    end
  end
  object SummaryPanel: TPanel
    Left = 440
    Top = 568
    Width = 269
    Height = 81
    BevelOuter = bvLowered
    TabOrder = 3
    object Label1: TLabel
      Left = 12
      Top = 33
      Width = 64
      Height = 15
      Caption = #21512#35336#37329#38989
    end
    object Label2: TLabel
      Left = 12
      Top = 57
      Width = 64
      Height = 15
      Caption = #28040#36027#31246#35336
    end
    object UAmountLabel: TLabel
      Left = 156
      Top = 32
      Width = 81
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object UTotalZeiLabel: TLabel
      Left = 156
      Top = 56
      Width = 81
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 244
      Top = 57
      Width = 16
      Height = 15
      Caption = #20870
    end
    object Label7: TLabel
      Left = 244
      Top = 33
      Width = 16
      Height = 15
      Caption = #20870
    end
    object Label3: TLabel
      Left = 4
      Top = 8
      Width = 68
      Height = 15
      Caption = #12304#22770#19978#12305
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object PageControl: TPageControl
    Left = 8
    Top = 344
    Width = 981
    Height = 217
    ActivePage = TransSheet
    TabHeight = 28
    TabIndex = 0
    TabOrder = 2
    OnChange = PageControlChange
    OnEnter = PageControlEnter
    object TransSheet: TTabSheet
      Caption = #21462#24341#12487#12540#12479
      object DetailGrid: TStrColGrid
        Tag = 9999
        Left = 0
        Top = 0
        Width = 973
        Height = 179
        Align = alClient
        ColCount = 10
        Ctl3D = True
        DefaultRowHeight = 22
        DefaultDrawing = False
        RowCount = 7
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 0
        OnDrawCell = DetailGridDrawCell
        OnKeyDown = DetailGridKeyDown
        OnSelectCell = DetailGridSelectCell
        OnSetEditText = DetailGridSetEditText
        CellParams = <
          item
            Alignment = taCenter
            Caption = 'No'
            CellColor = clWindow
            Col = 0
            ColMax = 0
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-No'
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21306#20998
            CellColor = clWindow
            Col = 1
            ColMax = 1
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21306#20998
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = '*'
            CellColor = clWindow
            Col = 2
            ColMax = 2
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21697#21517#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21697#21517
            CaptionType = ctCaption
            CellColor = clWindow
            Col = 3
            ColMax = 3
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21697#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #25968#37327
            CellColor = clWindow
            Col = 4
            ColMax = 4
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#25968#37327
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = '*'
            CellColor = clWindow
            Col = 5
            ColMax = 5
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20301#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21336#20301
            CellColor = clWindow
            Col = 6
            ColMax = 6
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20301
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21336#20385#12288
            CellColor = clWindow
            Col = 7
            ColMax = 7
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20385
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #37329#38989
            CellColor = clWindow
            Col = 8
            ColMax = 8
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#37329#38989
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #20633#32771
            CellColor = clWindow
            Col = 9
            ColMax = 9
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#20633#32771
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            CellColor = clBtnFace
            CellColorEnabled = True
            Col = 0
            ColMax = 0
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'NoLine'
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taCenter
            CellColor = clWindow
            Col = 1
            ColMax = 1
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlBottom
            Name = #21306#20998
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 2
            ColMax = 2
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21697#21517#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = 15658734
            CellColorEnabled = True
            Col = 3
            ColMax = 3
            FontColor = clWindowText
            FontWidth = 1
            ImeMode = imOpen
            ImeModeEnabled = True
            Layout = tlCenter
            Name = #21697#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 4
            ColMax = 4
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #25968#37327
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 5
            ColMax = 5
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20301#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = 15658734
            CellColorEnabled = True
            Col = 6
            ColMax = 6
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20301#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 7
            ColMax = 7
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20385
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = 15658734
            CellColorEnabled = True
            Col = 8
            ColMax = 8
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #37329#38989
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = clNone
            Col = 9
            ColMax = 9
            FontColor = clWindowText
            FontWidth = 1
            ImeMode = imHira
            ImeModeEnabled = True
            Layout = tlCenter
            Name = #20633#32771
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end>
        Fonts = <>
        Alignment = taRightJustify
        FixedAlignment = taCenter
        FixedLayout = tlCenter
        FocusCellColor = 15138815
        FocusCellFontColor = clBlack
        FocusCellFontColorEnabled = True
        Layout = tlCenter
        OnCellChanged = DetailGridCellChanged
        ColWidths = (
          30
          46
          48
          282
          65
          54
          97
          115
          154
          64)
      end
      object TankaUpdateButton: TButton
        Left = 712
        Top = 3
        Width = 33
        Height = 20
        Caption = #26356#26032
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = TankaUpdateButtonClick
      end
    end
    object KeiryoSheet: TTabSheet
      Caption = #35336#37327#12487#12540#12479
      ImageIndex = 1
      object KeiryoGrid: TStrColGrid
        Left = 0
        Top = 0
        Width = 973
        Height = 179
        Align = alClient
        ColCount = 9
        Ctl3D = True
        DefaultRowHeight = 22
        DefaultDrawing = False
        RowCount = 7
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 0
        OnDrawCell = DetailGridDrawCell
        CellParams = <
          item
            Alignment = taCenter
            Caption = 'No'
            CellColor = clWindow
            Col = 0
            ColMax = 0
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-No'
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = '*'
            CellColor = clWindow
            Col = 1
            ColMax = 1
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21697#21517#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21697#21517
            CaptionType = ctCaption
            CellColor = clWindow
            Col = 2
            ColMax = 2
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21697#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #25968#37327
            CellColor = clWindow
            Col = 3
            ColMax = 3
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#25968#37327
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = '*'
            CellColor = clWindow
            Col = 4
            ColMax = 4
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20301#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21336#20301
            CellColor = clWindow
            Col = 5
            ColMax = 5
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20301
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #21336#20385
            CellColor = clWindow
            Col = 6
            ColMax = 6
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#21336#20385
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #37329#38989
            CellColor = clWindow
            Col = 7
            ColMax = 7
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#37329#38989
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            Caption = #20633#32771
            CellColor = clWindow
            Col = 8
            ColMax = 8
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'F-'#20633#32771
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            Row = 0
            RowMax = 0
            Tag = 0
          end
          item
            Alignment = taCenter
            CellColor = clBtnFace
            CellColorEnabled = True
            Col = 0
            ColMax = 0
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = 'NoLine'
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
            OptionsEnabled = True
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 1
            ColMax = 1
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21697#21517#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = 15658734
            CellColorEnabled = True
            Col = 2
            ColMax = 2
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21697#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 3
            ColMax = 3
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #25968#37327
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 4
            ColMax = 4
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20301#12467#12540#12489
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = 15658734
            CellColorEnabled = True
            Col = 5
            ColMax = 5
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20301#21517
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            Alignment = taRightJustify
            CellColor = clWindow
            Col = 6
            ColMax = 7
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #21336#20385#65291#37329#38989
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end
          item
            CellColor = clWindow
            Col = 8
            ColMax = 8
            FontColor = clWindowText
            FontWidth = 1
            ImeModeEnabled = False
            Layout = tlCenter
            Name = #20633#32771
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
            RangeEnabled = True
            Row = 1
            RowMax = 999
            Tag = 0
          end>
        Fonts = <>
        Alignment = taCenter
        FixedAlignment = taCenter
        FixedLayout = tlCenter
        FocusCellFontColorEnabled = True
        Layout = tlCenter
        ColWidths = (
          30
          56
          337
          74
          31
          64
          97
          115
          154)
      end
    end
  end
  object Panel1: TPanel
    Left = 720
    Top = 568
    Width = 269
    Height = 81
    BevelOuter = bvLowered
    TabOrder = 6
    object Label4: TLabel
      Left = 12
      Top = 33
      Width = 64
      Height = 15
      Caption = #21512#35336#37329#38989
    end
    object Label8: TLabel
      Left = 12
      Top = 57
      Width = 64
      Height = 15
      Caption = #28040#36027#31246#35336
    end
    object SAmountLabel: TLabel
      Left = 156
      Top = 32
      Width = 81
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object STotalZeiLabel: TLabel
      Left = 156
      Top = 56
      Width = 81
      Height = 17
      Alignment = taRightJustify
      Caption = '1,234,567'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 244
      Top = 57
      Width = 16
      Height = 15
      Caption = #20870
    end
    object Label12: TLabel
      Left = 244
      Top = 33
      Width = 16
      Height = 15
      Caption = #20870
    end
    object Label13: TLabel
      Left = 4
      Top = 8
      Width = 68
      Height = 15
      Caption = #12304#20181#20837#12305
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 740
    Top = 72
    Width = 249
    Height = 85
    BevelOuter = bvLowered
    TabOrder = 7
    object Label9: TLabel
      Left = 24
      Top = 33
      Width = 48
      Height = 15
      Caption = #35336#37327#26085
    end
    object Label10: TLabel
      Left = 24
      Top = 57
      Width = 48
      Height = 15
      Caption = #20253#31080'No'
    end
    object Label18: TLabel
      Left = 4
      Top = 8
      Width = 102
      Height = 15
      Caption = #12304#35336#37327#24773#22577#12305
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clMaroon
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
    end
    object KeiryoDate: TCobEdit
      Left = 96
      Top = 29
      Width = 121
      Height = 23
      TabStop = False
      ParentColor = True
      ReadOnly = True
      TabOrder = 0
      Alignment = taRightJustify
    end
    object KeiryoNo: TCobEdit
      Left = 96
      Top = 53
      Width = 121
      Height = 23
      TabStop = False
      ParentColor = True
      ReadOnly = True
      TabOrder = 1
      Alignment = taRightJustify
    end
  end
  object Panel3: TPanel
    Left = 8
    Top = 564
    Width = 269
    Height = 45
    BevelOuter = bvLowered
    TabOrder = 8
    object RowInsertButton: TButton
      Left = 12
      Top = 8
      Width = 101
      Height = 29
      Caption = #34892#25407#20837
      TabOrder = 0
      TabStop = False
      OnClick = RowInsertButtonClick
    end
    object RowDeleteButton: TButton
      Left = 156
      Top = 8
      Width = 101
      Height = 29
      Caption = #34892#21066#38500
      TabOrder = 1
      TabStop = False
      OnClick = RowDeleteButtonClick
    end
  end
  object Panel4: TPanel
    Left = 808
    Top = 168
    Width = 180
    Height = 169
    BevelOuter = bvNone
    TabOrder = 9
    object DefTankaGrid: TStrColGrid
      Tag = 9999
      Left = 0
      Top = 0
      Width = 180
      Height = 169
      TabStop = False
      Align = alClient
      ColCount = 2
      Ctl3D = True
      DefaultRowHeight = 22
      DefaultDrawing = False
      RowCount = 7
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goRowSelect]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      CellParams = <
        item
          Alignment = taCenter
          Caption = 'No'
          CellColor = clWindow
          Col = 0
          ColMax = 0
          FontColor = clWindowText
          FontWidth = 1
          ImeModeEnabled = False
          Layout = tlCenter
          Name = 'F-No'
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
          RangeEnabled = True
          Row = 0
          RowMax = 0
          Tag = 0
        end
        item
          Alignment = taCenter
          Caption = #30331#37682#21336#20385
          CellColor = clWindow
          Col = 1
          ColMax = 1
          FontColor = clWindowText
          FontWidth = 1
          ImeModeEnabled = False
          Layout = tlCenter
          Name = 'F-'#21336#20385
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goAlwaysShowEditor]
          RangeEnabled = True
          Row = 0
          RowMax = 0
          Tag = 0
        end
        item
          Alignment = taCenter
          CellColor = clBtnFace
          CellColorEnabled = True
          Col = 0
          ColMax = 0
          FontColor = clWindowText
          FontWidth = 1
          ImeModeEnabled = False
          Layout = tlCenter
          Name = 'NoLine'
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
          OptionsEnabled = True
          RangeEnabled = True
          Row = 1
          RowMax = 999
          Tag = 0
        end
        item
          Alignment = taRightJustify
          CellColor = clWindow
          Col = 1
          ColMax = 1
          FontColor = clWindowText
          FontWidth = 1
          ImeModeEnabled = False
          Layout = tlCenter
          Name = #21336#20385
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected]
          RangeEnabled = True
          Row = 1
          RowMax = 999
          Tag = 0
        end>
      Fonts = <>
      Alignment = taRightJustify
      FixedAlignment = taCenter
      FixedLayout = tlCenter
      FocusDraw = False
      FocusCellColor = 15138815
      Layout = tlCenter
      ColWidths = (
        30
        139)
    end
  end
  object ActionList: TActionList
    Left = 332
    Top = 612
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
      Caption = #21442#29031
      Hint = #38917#30446#12434#21442#29031#12377#12427
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
      Enabled = False
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
      ShortCut = 121
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
end
