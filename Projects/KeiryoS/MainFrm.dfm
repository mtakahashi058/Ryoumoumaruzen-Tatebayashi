object MainForm: TMainForm
  Left = 322
  Top = 124
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
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    1016
    737)
  PixelsPerInch = 96
  TextHeight = 15
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
    TabOrder = 2
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      Enabled = False
      ParentShowHint = False
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
      ShowHint = True
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
        Text = #30331#37682#24773#22577
        Width = 280
      end
      item
        Text = #12456#12521#12540#24773#22577
        Width = 280
      end
      item
        Text = #12518#12540#12470#12469#12509#12540#12488#24773#22577
        Width = 50
      end>
    ParentShowHint = False
    ShowHint = True
    SimplePanel = False
  end
  object TairyuPanel: TPanel
    Left = 730
    Top = 61
    Width = 286
    Height = 601
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
    object TairyuKensuLabel: TLabel
      Left = 6
      Top = 265
      Width = 21
      Height = 13
      Alignment = taCenter
      Caption = '(0)'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TairyuGrid: TDBCtrlGrid
      Left = 28
      Top = 1
      Width = 257
      Height = 495
      Hint = #12480#12502#12523#12463#12522#12483#12463#12391#28382#30041#21628#20986#12434#34892#12356#12414#12377
      Align = alRight
      AllowDelete = False
      AllowInsert = False
      ColCount = 1
      Color = clWhite
      DataSource = dsTairyu
      PanelBorder = gbNone
      PanelHeight = 70
      PanelWidth = 240
      ParentColor = False
      ParentShowHint = False
      TabOrder = 0
      RowCount = 7
      SelectedColor = 14999039
      ShowHint = True
      OnDblClick = OnSelectTairyu
      object TairyuTokuisakiLabel: TLabel
        Left = 12
        Top = 50
        Width = 48
        Height = 12
        Alignment = taRightJustify
        Caption = #24471#24847#20808#65313
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 9408399
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object TairyuCarNameText: TDBText
        Left = 112
        Top = 27
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
        Left = 65
        Top = 5
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
        Left = 30
        Top = 7
        Width = 30
        Height = 12
        Alignment = taRightJustify
        Caption = #26085' '#26178
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 9408399
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
      object Shape1: TShape
        Left = 5
        Top = 45
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object Shape2: TShape
        Left = 5
        Top = 23
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuTokuisakiText: TDBText
        Left = 65
        Top = 49
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
        Top = 67
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
      end
      object Shape4: TShape
        Left = 0
        Top = 2
        Width = 17
        Height = 66
        Anchors = [akLeft, akTop, akRight]
        Brush.Color = clGray
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuCarNoText: TDBText
        Left = 65
        Top = 27
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
        Left = 30
        Top = 29
        Width = 30
        Height = 12
        Alignment = taRightJustify
        Caption = #36554' '#30058
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = 9408399
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = OnSelectTairyu
      end
    end
    object RirekiPanel: TPanel
      Left = 1
      Top = 496
      Width = 284
      Height = 104
      Hint = #12480#12502#12523#12463#12522#12483#12463#12418#12375#12367#12399'F11'#12391#23653#27508#21628#20986#12434#34892#12356#12414#12377#12290#12414#12383#12289'[PageUp][PageDown]'#12391#23653#27508#12434#20999#12426#26367#12360#12425#12428#12414#12377#12290
      Align = alBottom
      BevelOuter = bvNone
      Color = 14154709
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnDblClick = Action11Execute
      object Shape5: TShape
        Left = 0
        Top = 0
        Width = 284
        Height = 1
        Align = alTop
        Pen.Color = 4737096
      end
      object RirekiOrderLabel: TLabel
        Left = 121
        Top = 91
        Width = 72
        Height = 11
        Alignment = taCenter
        AutoSize = False
        Caption = '100/100'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        OnDblClick = Action11Execute
      end
      object RirekiDateLabel: TLabel
        Left = 40
        Top = 6
        Width = 173
        Height = 12
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiTokuNameLabel: TLabel
        Left = 76
        Top = 24
        Width = 198
        Height = 12
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiTokuCodeLabel: TLabel
        Left = 32
        Top = 26
        Width = 39
        Height = 10
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiHinCodeLabel: TLabel
        Left = 32
        Top = 42
        Width = 39
        Height = 10
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiHinNameLabel: TLabel
        Left = 76
        Top = 40
        Width = 198
        Height = 12
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiKomoku1NameLabel: TLabel
        Left = 76
        Top = 56
        Width = 198
        Height = 12
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiKomoku1CodeLabel: TLabel
        Left = 32
        Top = 58
        Width = 39
        Height = 10
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiKomoku2NameLabel: TLabel
        Left = 76
        Top = 72
        Width = 198
        Height = 12
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object RirekiKomoku2CodeLabel: TLabel
        Left = 32
        Top = 74
        Width = 39
        Height = 10
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'RirekiDateLabel'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Panel2: TPanel
        Left = 0
        Top = 1
        Width = 27
        Height = 103
        Align = alLeft
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 0
        object Label7: TLabel
          Left = 4
          Top = 17
          Width = 20
          Height = 19
          Caption = #23653
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = 5000268
          Font.Height = -19
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
        end
        object Label15: TLabel
          Left = 4
          Top = 53
          Width = 20
          Height = 19
          Caption = #27508
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = 5000268
          Font.Height = -19
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
        end
      end
      object DispRirekiCheckBox: TCheckBox
        Left = 215
        Top = 2
        Width = 66
        Height = 13
        Caption = #23653#27508#34920#31034
        Checked = True
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 1
        OnClick = DispRirekiCheckBoxClick
      end
      object Button1: TButton
        Left = 28
        Top = 88
        Width = 93
        Height = 17
        Action = ActionRirekiBefore
        Caption = #21069' [PageUp]'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object Button2: TButton
        Left = 192
        Top = 88
        Width = 93
        Height = 17
        Action = ActionRirekiNext
        Caption = #24460' [PageDown]'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
  end
  object ScrollBox: TScrollBox
    Left = 0
    Top = 60
    Width = 717
    Height = 561
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    TabOrder = 1
    DesignSize = (
      717
      561)
    object SharyoPanel: TPanel
      Left = 4
      Top = 8
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
        Hint = #12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
        Caption = #36554#12288#12288#20001
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
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
        Hint = #36554#30058#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 6
        ParentFont = False
        TabOrder = 1
        Text = '123456'
        OnChange = ShabanEditChange
        OnEnter = ShabanEditEnter
        OnExit = ShabanEditExit
        OnKeyDown = ShabanEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object SharyoNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 213
        Height = 27
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '12345678901234567890'
        IsInsert = True
      end
    end
    object TokuPanel: TPanel
      Left = 4
      Top = 56
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
        Hint = #12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
        Caption = #24471' '#24847' '#20808
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TabStop = False
        OnClick = TokuButtonClick
      end
      object TokuCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Hint = #12467#12540#12489#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = TokuCodeEditChange
        OnEnter = ShabanEditEnter
        OnExit = TokuCodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TokuNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 512
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
      Top = 136
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 3
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Komoku1Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Hint = #12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
        Caption = #38917' '#30446' '#65297
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TabStop = False
        OnClick = Komoku1ButtonClick
      end
      object Komoku1CodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Hint = #12467#12540#12489#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = Komoku1CodeEditChange
        OnEnter = ShabanEditEnter
        OnExit = Komoku1CodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
      object Komoku1NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 412
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
      Top = 176
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 4
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Komoku2Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Hint = #12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
        Caption = #38917' '#30446' '#65298
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TabStop = False
        OnClick = Komoku2ButtonClick
      end
      object Komoku2NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 412
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
        Hint = #12467#12540#12489#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = Komoku2CodeEditChange
        OnEnter = ShabanEditEnter
        OnExit = Komoku2CodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object BikoPanel: TPanel
      Left = 4
      Top = 520
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 15
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
        Width = 415
        Height = 27
        Hint = #20633#32771#12434#20837#21147#12375#12390#12367#12384#12373#12356
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
        OnEnter = ShabanEditEnter
        OnKeyDown = BikoEditKeyDown
        IsInsert = True
      end
    end
    object HinPanel: TPanel
      Left = 4
      Top = 96
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object HinButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Hint = #12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
        Caption = #21697#12288#12288#30446
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        TabStop = False
        OnClick = HinButtonClick
      end
      object HinNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 412
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
      object HinCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Hint = #12467#12540#12489#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        OnChange = HinCodeEditChange
        OnEnter = ShabanEditEnter
        OnExit = HinCodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
      object HannyuCombo: TComboBox
        Left = 600
        Top = 5
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
    object SojuPanel: TPanel
      Left = 4
      Top = 224
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 5
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label5: TLabel
        Left = 360
        Top = 12
        Width = 70
        Height = 13
        Caption = #35336#37327#26085#26178#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label13: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object SojuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #65297#22238#30446#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object FirstWEdit: TCobEdit
        Tag = 999
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Hint = #37325#37327#20516#12434#20837#21147#12375#12414#12377#12290'[F10]'#12391#29694#22312#12398#37325#37327#20516#12364#33258#21205#20837#21147#12373#12428#12414#12377
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 7
        ParentFont = False
        TabOrder = 1
        Text = '12345.1'
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        OnKeyDown = FirstWEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object TrailerWeight1Button: TButton
        Tag = 1
        Left = 236
        Top = 6
        Width = 105
        Height = 25
        Caption = #36600#37325#35336#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        TabStop = False
        OnClick = TrailerWeightButtonClick
      end
      object FirstDatePicker: TDateTimePicker
        Tag = 1
        Left = 432
        Top = 7
        Width = 121
        Height = 23
        CalAlignment = dtaLeft
        Date = 40330.5928886227
        Time = 40330.5928886227
        ShowCheckbox = True
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 3
        TabStop = False
        OnChange = WeighingDateTimePickerChange
      end
      object FirstTimePicker: TDateTimePicker
        Left = 560
        Top = 7
        Width = 69
        Height = 23
        CalAlignment = dtaLeft
        Date = 40330.5928886227
        Format = 'HH:mm'
        Time = 40330.5928886227
        DateFormat = dfShort
        DateMode = dmUpDown
        Kind = dtkTime
        ParseInput = False
        TabOrder = 4
        TabStop = False
      end
    end
    object KushaPanel: TPanel
      Left = 4
      Top = 264
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 6
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label8: TLabel
        Left = 360
        Top = 12
        Width = 70
        Height = 13
        Caption = #35336#37327#26085#26178#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object KushaButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #65298#22238#30446#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object SecondWEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Hint = #37325#37327#20516#12434#20837#21147#12375#12414#12377#12290'[F10]'#12391#29694#22312#12398#37325#37327#20516#12364#33258#21205#20837#21147#12373#12428#12414#12377
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 7
        ParentFont = False
        TabOrder = 1
        Text = '12345.1'
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
      object TrailerWeight2Button: TButton
        Tag = 2
        Left = 236
        Top = 6
        Width = 105
        Height = 25
        Caption = #36600#37325#35336#37327
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        TabStop = False
        OnClick = TrailerWeightButtonClick
      end
      object SecondDatePicker: TDateTimePicker
        Tag = 2
        Left = 432
        Top = 7
        Width = 121
        Height = 23
        CalAlignment = dtaLeft
        Date = 40330.5928886227
        Time = 40330.5928886227
        ShowCheckbox = True
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 3
        TabStop = False
        OnChange = WeighingDateTimePickerChange
      end
      object SecondTimePicker: TDateTimePicker
        Left = 560
        Top = 7
        Width = 69
        Height = 23
        CalAlignment = dtaLeft
        Date = 40330.5928886227
        Format = 'HH:mm'
        Time = 40330.5928886227
        DateFormat = dfShort
        DateMode = dmUpDown
        Kind = dtkTime
        ParseInput = False
        TabOrder = 4
        TabStop = False
      end
    end
    object ChoseiPanel: TPanel
      Left = 4
      Top = 304
      Width = 377
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 7
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label9: TLabel
        Left = 168
        Top = 11
        Width = 16
        Height = 16
        Caption = #65285
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 304
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object ChoseiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #35519#12288#12288#25972
        TabOrder = 0
        TabStop = False
      end
      object ChoseirituEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 55
        Height = 27
        Hint = #35519#25972#29575#12434#20837#21147#12375#12390#12367#12384#12373#12356
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 4
        ParentFont = False
        TabOrder = 1
        Text = '99.9'
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiEdit: TCobEdit
        Left = 212
        Top = 5
        Width = 85
        Height = 27
        TabStop = False
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
        Text = '12345.1'
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object ShomiPanel: TPanel
      Left = 4
      Top = 344
      Width = 703
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 9
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label14: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 248
        Top = 12
        Width = 56
        Height = 13
        Caption = #32020#27491#21619#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object PureNetLabel: TLabel
        Left = 340
        Top = 10
        Width = 73
        Height = 16
        Alignment = taRightJustify
        Caption = '999,999 kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object ShomiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #27491#21619#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object ShomiEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Hint = #27491#21619#37325#37327#12364#33258#21205#31639#20986#12373#12428#12414#12377
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
        Text = '12345.1'
        OnEnter = ShabanEditEnter
        OnExit = OnAmountRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object JuryobikiPanel: TPanel
      Left = 388
      Top = 304
      Width = 319
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 8
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label11: TLabel
        Left = 201
        Top = 11
        Width = 19
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object JuryobikiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #37325#37327#24341#12365
        TabOrder = 0
        TabStop = False
      end
      object JuryobikiEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Hint = #37325#37327#24341#12365#12434#20837#21147#12375#12390#12367#12384#12373#12356
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        TabOrder = 1
        Text = '12345.1'
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object SuryoPanel: TPanel
      Left = 284
      Top = 392
      Width = 423
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 11
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object TaniLabel: TLabel
        Left = 248
        Top = 11
        Width = 64
        Height = 16
        Caption = #21336#20301#21517#31216
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object SuryoButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #25968#12288#12288#37327
        TabOrder = 0
        TabStop = False
      end
      object SuryoEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Hint = #25968#37327#12434#20837#21147#12375#12390#12367#12384#12373#12356
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 11
        ParentFont = False
        TabOrder = 1
        Text = '1234567.890'
        OnEnter = ShabanEditEnter
        OnExit = OnAmountRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object TankaPanel: TPanel
      Left = 3
      Top = 432
      Width = 274
      Height = 57
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 12
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object Label6: TLabel
        Left = 86
        Top = 40
        Width = 70
        Height = 13
        Caption = #30331#37682#21336#20385#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object DefTankaLabel: TLabel
        Left = 161
        Top = 38
        Width = 73
        Height = 16
        Alignment = taRightJustify
        Caption = '999,999 kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object TankaButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #21336#12288#12288#20385
        TabOrder = 0
        TabStop = False
      end
      object TankaEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 135
        Height = 27
        Hint = #21336#20385#12434#20837#21147#12375#12390#12367#12384#12373#12356
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 12
        ParentFont = False
        TabOrder = 1
        Text = '12345678.123'
        OnEnter = ShabanEditEnter
        OnExit = TankaEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object KingakuPanel: TPanel
      Left = 284
      Top = 432
      Width = 423
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 13
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object KingakuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #37329#12288#12288#38989
        TabOrder = 0
        TabStop = False
      end
      object KingakuEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Hint = #37329#38989#12434#20837#21147#12375#12390#12367#12384#12373#12356
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 10
        ParentFont = False
        TabOrder = 1
        Text = '1234567890'
        OnEnter = ShabanEditEnter
        OnExit = OnSalesTaxRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object TaniPanel: TPanel
      Left = 4
      Top = 392
      Width = 273
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 10
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object TaniButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #21336#12288#12288#20301
        TabOrder = 0
        TabStop = False
        OnClick = TaniButtonClick
      end
      object TaniCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 45
        Height = 27
        Hint = #12467#12540#12489#12434#20837#21147#12375#12390#12367#12384#12373#12356#12290'('#38917#30446#12508#12479#12531' or [F4]'#8594#12510#12473#12479#21442#29031')'
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 3
        ParentFont = False
        TabOrder = 1
        Text = '123'
        OnChange = TaniCodeEditChange
        OnEnter = ShabanEditEnter
        OnExit = OnWeightRecalc
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit: TCobEdit
        Left = 156
        Top = 5
        Width = 114
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 2
        Text = '1234567890'
        OnEnter = ShabanEditEnter
        IsInsert = True
      end
    end
    object ShohizeiPanel: TPanel
      Left = 283
      Top = 472
      Width = 423
      Height = 37
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 14
      OnEnter = SharyoPanelEnter
      OnExit = SharyoPanelExit
      object ShohizeiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #28040#36027#31246#38989
        TabOrder = 0
        TabStop = False
      end
      object ShohizeiEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Hint = #28040#36027#31246#38989#12364#33258#21205#31639#20986#12373#12428#12414#12377
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imDisable
        MaxLength = 10
        ParentFont = False
        TabOrder = 1
        Text = '1234567890'
        OnEnter = ShabanEditEnter
        IsInsert = True
        Alignment = taRightJustify
      end
    end
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
    object Label1: TLabel
      Left = 960
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
      Left = 116
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
      Left = 268
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
      Left = 724
      Top = 6
      Width = 233
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
      OnChange = KeiryoDatePickerChange
    end
    object KeiryoNoEdit: TCobEdit
      Tag = 1
      Left = 268
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
  object AutoPrintCheck: TCheckBox
    Left = 580
    Top = 630
    Width = 135
    Height = 17
    Hint = #12481#12455#12483#12463#12377#12427#12392#12289#26032#35215#30331#37682#26178#12395#33258#21205#20253#31080#30330#34892#12375#12414#12377
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #20253#31080#12434#21360#23383#12377#12427
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
  end
  object DataDeleteCheck: TCheckBox
    Left = 292
    Top = 630
    Width = 135
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #12487#12540#12479#12434#27531#12373#12394#12356
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object HideTimeCheck: TCheckBox
    Left = 436
    Top = 630
    Width = 135
    Height = 17
    TabStop = False
    Anchors = [akTop, akRight]
    Caption = #26178#38291#12434#21360#23383#12375#12394#12356
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object ActionList: TActionList
    Left = 4
    Top = 624
    object Action1: TAction
      Caption = #26032#35215
      Hint = #30011#38754#12434#12463#12522#12450#12375#12289#26032#12375#12356#20253#31080#12434#20316#25104#12375#12414#12377
      ShortCut = 112
      OnExecute = Action1Execute
    end
    object Action2: TAction
      Caption = #20462#27491
      Hint = #26368#24460#12395#30331#37682#12375#12383#20253#31080#12434#21628#12403#20986#12375#12414#12377
      ShortCut = 113
      OnExecute = Action2Execute
    end
    object Action3: TAction
      Caption = #21066#38500
      Hint = #34920#31034#20013#12398#20253#31080#12434#21066#38500#12375#12414#12377
      ShortCut = 114
      OnExecute = Action3Execute
    end
    object Action4: TAction
      Caption = #21442#29031
      Hint = #36984#25246#38917#30446#12398#12510#12473#12479#21442#29031#30011#38754#12434#34920#31034#12375#12414#12377
      ShortCut = 115
      OnExecute = Action4Execute
    end
    object Action5: TAction
      Caption = #30331#37682
      Hint = #20253#31080#12434#30331#37682#12375#12414#12377
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action6: TAction
      Caption = #21069#12408
      Hint = #21069#12398#20253#31080#12434#21628#20986#12375#12414#12377'('#20462#27491#12514#12540#12489#26178#12398#12415')'
      ShortCut = 117
      OnExecute = Action6Execute
    end
    object Action7: TAction
      Caption = #27425#12408
      Hint = #27425#12398#20253#31080#12434#21628#20986#12375#12414#12377'('#20462#27491#12514#12540#12489#26178#12398#12415')'
      ShortCut = 118
      OnExecute = Action7Execute
    end
    object Action8: TAction
      Caption = #20253#31080#30330#34892
      Hint = #20253#31080#30330#34892#12375#12414#12377
      ShortCut = 119
      OnExecute = Action8Execute
    end
    object Action9: TAction
      Caption = #26908#32034
      Hint = #12487#12540#12479#19968#35239#30011#38754#12434#34920#31034#12375#12414#12377
      ShortCut = 120
      OnExecute = Action9Execute
    end
    object Action10: TAction
      Caption = #37325#37327#20516
      Hint = #37325#37327#20516#12434#20253#31080#12487#12540#12479#12392#12375#12390#21462#12426#36796#12415#12414#12377
      ShortCut = 121
      OnExecute = Action10Execute
    end
    object Action11: TAction
      Caption = #23653#27508#21628#20986
      Hint = #30011#38754#21491#19979#12395#34920#31034#12373#12428#12390#12356#12427#23653#27508#12434#20253#31080#12395#12467#12500#12540#12375#12414#12377
      ShortCut = 122
      OnExecute = Action11Execute
    end
    object Action12: TAction
      Caption = #32066#20102
      Hint = #35336#37327#20966#29702#12434#32066#20102#12375#12414#12377
      ShortCut = 123
      OnExecute = Action12Execute
    end
    object ActionRirekiBefore: TAction
      Caption = #21069#23653#27508' [PageUp]'
      OnExecute = ActionRirekiBeforeExecute
    end
    object ActionRirekiNext: TAction
      Caption = #24460#23653#27508' [PageDown]'
      OnExecute = ActionRirekiNextExecute
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
    Left = 736
    Top = 8
  end
  object SocketReopenTimer: TTimer
    Enabled = False
    OnTimer = SocketReopenTimerTimer
    Left = 764
    Top = 8
  end
  object TairyuTimer: TTimer
    Enabled = False
    OnTimer = TairyuTimerTimer
    Left = 812
    Top = 148
  end
  object Q_Rireki: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'TOP 30'
      #9'MAX('#35336#37327'ID) AS '#35336#37327'ID,'
      #9'MAX('#35336#37327#26085') AS '#35336#37327#26085','
      #9#24471#24847#20808'ID, '#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#21697#30446'ID, '#21697#30446#12467#12540#12489', '#21697#30446#21517#31216','
      #9#38917#30446'1ID, '#38917#30446'1'#12467#12540#12489', '#38917#30446'1'#21517#31216','
      #9#38917#30446'2ID, '#38917#30446'2'#12467#12540#12489', '#38917#30446'2'#21517#31216
      'FROM'
      #9'V_'#35336#37327
      ''
      'WHERE'
      #9#36554#20001'ID = @SHARYO_ID'#9#9'-- '#12503#12525#12464#12521#12512#20013#12391#26360#12365#25563#12360
      ''
      'GROUP BY'
      #9#24471#24847#20808'ID, '#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#21697#30446'ID, '#21697#30446#12467#12540#12489', '#21697#30446#21517#31216','
      #9#38917#30446'1ID, '#38917#30446'1'#12467#12540#12489', '#38917#30446'1'#21517#31216','
      #9#38917#30446'2ID, '#38917#30446'2'#12467#12540#12489', '#38917#30446'2'#21517#31216
      ''
      'ORDER BY'
      #9#35336#37327'ID DESC'
      '')
    Left = 952
    Top = 524
    object Q_RirekiID: TIntegerField
      FieldName = #35336#37327'ID'
      ReadOnly = True
    end
    object Q_RirekiDSDesigner: TIntegerField
      FieldName = #35336#37327#26085
      ReadOnly = True
      DisplayFormat = '"'#26368#32066#35336#37327#26085#65306' "0000/00/00;#;#'
    end
    object Q_RirekiID2: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Q_RirekiDSDesigner2: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_RirekiDSDesigner3: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_RirekiID3: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_RirekiDSDesigner4: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_RirekiDSDesigner5: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_RirekiDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object Q_RirekiDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_RirekiDSDesigner12: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_RirekiDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object Q_RirekiDSDesigner22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_RirekiDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
  end
  object dsRireki: TDataSource
    DataSet = Q_Rireki
    Left = 920
    Top = 524
  end
end
