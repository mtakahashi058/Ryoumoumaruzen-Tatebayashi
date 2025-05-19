object MainForm: TMainForm
  Left = 265
  Top = 117
  Width = 1024
  Height = 768
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #35336#37327#20966#29702' (M)'
  Color = 16773616
  Constraints.MinHeight = 728
  Constraints.MinWidth = 1024
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    1016
    737)
  PixelsPerInch = 96
  TextHeight = 15
  object MeisaiAddButton: TSpeedButton
    Left = 8
    Top = 352
    Width = 81
    Height = 28
    Caption = #26126#32048#36861#21152
    OnClick = MeisaiAddButtonClick
  end
  object RecalcButton: TSpeedButton
    Left = 176
    Top = 352
    Width = 81
    Height = 28
    Caption = #37325#37327#20877#35336#31639
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    OnClick = RecalcButtonClick
  end
  object MeisakiDeleteButton: TSpeedButton
    Left = 92
    Top = 352
    Width = 81
    Height = 28
    Caption = #26126#32048#21066#38500
    OnClick = SpeedButton2Click
  end
  object AnbunButton: TSpeedButton
    Left = 8
    Top = 384
    Width = 81
    Height = 28
    Caption = #25353#20998
    OnClick = AnbunButtonClick
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
    Height = 358
    Align = alRight
    BevelOuter = bvLowered
    Color = 14803425
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    object Label16: TLabel
      Left = 6
      Top = 13
      Width = 16
      Height = 16
      Caption = #28382
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 6
      Top = 45
      Width = 16
      Height = 16
      Caption = #30041
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 6
      Top = 77
      Width = 16
      Height = 16
      Caption = #36554
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 6
      Top = 141
      Width = 16
      Height = 16
      Caption = #22577
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label23: TLabel
      Left = 6
      Top = 109
      Width = 16
      Height = 16
      Caption = #24773
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = 5000268
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TairyuKensuLabel: TLabel
      Left = 6
      Top = 173
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
      Height = 256
      Hint = #12480#12502#12523#12463#12522#12483#12463#12391#28382#30041#21628#20986#12434#34892#12356#12414#12377
      Align = alRight
      AllowDelete = False
      AllowInsert = False
      ColCount = 1
      Color = clWhite
      DataSource = dsTairyu
      PanelBorder = gbNone
      PanelHeight = 64
      PanelWidth = 240
      ParentColor = False
      ParentShowHint = False
      TabOrder = 0
      RowCount = 4
      SelectedColor = 14999039
      ShowHint = True
      OnDblClick = OnSelectTairyu
      object TairyuTokuisakiLabel: TLabel
        Left = 12
        Top = 46
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
        Top = 23
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
        Top = 2
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
        Top = 4
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
        Top = 39
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object Shape2: TShape
        Left = 5
        Top = 18
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuTokuisakiText: TDBText
        Left = 65
        Top = 44
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
        Top = 60
        Width = 236
        Height = 1
        Anchors = [akLeft, akTop, akRight]
        Pen.Color = clSilver
      end
      object Shape4: TShape
        Left = 0
        Top = 2
        Width = 17
        Height = 59
        Anchors = [akLeft, akTop, akRight]
        Brush.Color = clGray
        Pen.Color = clSilver
        Pen.Style = psDot
      end
      object TairyuCarNoText: TDBText
        Left = 65
        Top = 23
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
        Top = 25
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
      Top = 257
      Width = 284
      Height = 100
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
        Top = 87
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
      object RirekiKomoku1NameLabel: TLabel
        Left = 76
        Top = 44
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
        Top = 46
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
        Top = 64
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
        Top = 66
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
        Height = 99
        Align = alLeft
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 0
        object Label7: TLabel
          Left = 6
          Top = 17
          Width = 16
          Height = 16
          Caption = #23653
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = 5000268
          Font.Height = -16
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
        end
        object Label15: TLabel
          Left = 6
          Top = 53
          Width = 16
          Height = 16
          Caption = #27508
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = 5000268
          Font.Height = -16
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
        Top = 84
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
        Top = 84
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
    Height = 289
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    TabOrder = 1
    DesignSize = (
      717
      289)
    object SharyoPanel: TPanel
      Left = 8
      Top = 16
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
        OnEnter = SharyoNameEditEnter
        OnExit = SharyoNameEditExit
        IsInsert = True
      end
    end
    object TokuPanel: TPanel
      Left = 8
      Top = 64
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
        Width = 513
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
      Left = 8
      Top = 108
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
        Width = 413
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
      Left = 8
      Top = 152
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
        Width = 413
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
      Left = 8
      Top = 196
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
        Width = 413
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
        OnExit = BikoEditExit
        OnKeyDown = BikoEditKeyDown
        IsInsert = True
      end
    end
    object AutoPrintCheck: TCheckBox
      Left = 569
      Top = 254
      Width = 135
      Height = 17
      Hint = #12481#12455#12483#12463#12377#12427#12392#12289#26032#35215#30331#37682#26178#12395#33258#21205#20253#31080#30330#34892#12375#12414#12377
      TabStop = False
      Anchors = [akRight, akBottom]
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
      Left = 280
      Top = 254
      Width = 135
      Height = 17
      TabStop = False
      Anchors = [akRight, akBottom]
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
      Left = 424
      Top = 254
      Width = 135
      Height = 17
      TabStop = False
      Anchors = [akRight, akBottom]
      Caption = #26178#38291#12434#21360#23383#12375#12394#12356
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 7
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
      Left = 112
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
      Left = 480
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
    object Label3: TLabel
      Left = 387
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
      Left = 112
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
      OnKeyDown = KeiryoNoEditKeyDown
      Alignment = taRightJustify
    end
    object PlaceCombo: TComboBox
      Tag = 1
      Left = 480
      Top = 27
      Width = 229
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
    object ShudoCheckBox: TCheckBox
      Left = 628
      Top = 8
      Width = 69
      Height = 16
      Caption = #25163#21205#20837#21147
      Color = 16562584
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 5
      OnClick = ShudoCheckBoxClick
    end
    object KeiryoTimePicker: TDateTimePicker
      Tag = 1
      Left = 387
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
      TabOrder = 6
    end
  end
  object MeisaiScrollBox1: TScrollBox
    Left = 0
    Top = 419
    Width = 1016
    Height = 214
    HorzScrollBar.Smooth = True
    HorzScrollBar.Visible = False
    VertScrollBar.Visible = False
    Align = alBottom
    BevelInner = bvLowered
    BevelKind = bkFlat
    BorderStyle = bsNone
    TabOrder = 2
    object Shape6: TShape
      Left = 423
      Top = 8
      Width = 1
      Height = 187
      Pen.Color = clSilver
      Pen.Style = psDot
    end
    object GyoEdit1: TCobEdit
      Tag = 1
      Left = 4
      Top = 32
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 0
      Text = '1'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit1: TCobEdit
      Left = 32
      Top = 32
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 1
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit1: TCobEdit
      Left = 89
      Top = 32
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 2
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object GyoTitleEdit: TCobEdit
      Left = 4
      Top = 8
      Width = 25
      Height = 23
      TabStop = False
      Color = 4210752
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 18
      Text = #34892
      Alignment = taCenter
    end
    object HinCodeTitleEdit: TCobEdit
      Left = 32
      Top = 8
      Width = 54
      Height = 21
      TabStop = False
      Color = 4210752
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 19
      Text = #12467#12540#12489
      Alignment = taCenter
    end
    object HinNameTitleEdit: TCobEdit
      Left = 89
      Top = 8
      Width = 332
      Height = 23
      TabStop = False
      Color = 4210752
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 20
      Text = #21697#30446#21517#31216
      OnClick = HinNameTitleEditClick
      Alignment = taCenter
    end
    object MeisaiScrollBox2: TScrollBox
      Left = 454
      Top = 0
      Width = 585
      Height = 212
      HorzScrollBar.ButtonSize = 40
      HorzScrollBar.Increment = 50
      HorzScrollBar.ParentColor = False
      Align = alCustom
      Anchors = [akLeft, akTop, akRight]
      BevelInner = bvNone
      BorderStyle = bsNone
      TabOrder = 21
      object WeightEdit11: TCobEdit
        Left = 0
        Top = 32
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 0
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightTitleEdit1: TCobEdit
        Left = 0
        Top = 8
        Width = 70
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 78
        Text = '1'#22238#30446
        Alignment = taCenter
      end
      object WeightTitleEdit2: TCobEdit
        Left = 73
        Top = 8
        Width = 70
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 79
        Text = '2'#22238#30446
        Alignment = taCenter
      end
      object WeightEdit12: TCobEdit
        Left = 73
        Top = 32
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 1
        Text = '1234567'
        OnEnter = WeightEdit12Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiTitleEdit: TCobEdit
        Left = 146
        Top = 8
        Width = 119
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 80
        Text = #35519#25972
        Alignment = taCenter
      end
      object ChoseiPerEdit1: TCobEdit
        Left = 146
        Top = 32
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 2
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit1: TCobEdit
        Left = 195
        Top = 32
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 3
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightTitleEdit: TCobEdit
        Left = 268
        Top = 8
        Width = 70
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 81
        Text = #37325#37327#24341
        Alignment = taCenter
      end
      object BikiWeightEdit1: TCobEdit
        Left = 268
        Top = 32
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 4
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiTitleEdit: TCobEdit
        Left = 341
        Top = 8
        Width = 70
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 82
        Text = #27491#21619#37325
        Alignment = taCenter
      end
      object ShomiEdit1: TCobEdit
        Left = 341
        Top = 32
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 5
        Text = '1234567'
        OnChange = ShomiEdit1Change
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit1: TCobEdit
        Left = 511
        Top = 32
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 7
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniTitleEdit: TCobEdit
        Left = 511
        Top = 8
        Width = 99
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 83
        Text = #21336#20301
        OnClick = TaniTitleEditClick
        Alignment = taCenter
      end
      object TaniNameEdit1: TCobEdit
        Left = 552
        Top = 32
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 8
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit1: TCobEdit
        Left = 414
        Top = 32
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 6
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        OnKeyDown = SuryoEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object SuryoTitleEdit: TCobEdit
        Left = 414
        Top = 8
        Width = 94
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 84
        Text = #25968#37327
        Alignment = taCenter
      end
      object TankaEdit1: TCobEdit
        Left = 613
        Top = 32
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 9
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TankaTitleEdit: TCobEdit
        Left = 613
        Top = 8
        Width = 94
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 85
        Text = #21336#20385
        Alignment = taCenter
      end
      object KingakuEdit1: TCobEdit
        Left = 710
        Top = 32
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 10
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuTitleEdit: TCobEdit
        Left = 710
        Top = 8
        Width = 94
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 86
        Text = #37329#38989
        Alignment = taCenter
      end
      object BikoEdit1: TCobEdit
        Left = 904
        Top = 32
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 12
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object BikoTitleEdit: TCobEdit
        Left = 904
        Top = 8
        Width = 175
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 87
        Text = #26126#32048#20633#32771
        Alignment = taCenter
      end
      object WeightEdit21: TCobEdit
        Left = 0
        Top = 60
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 13
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit22: TCobEdit
        Left = 73
        Top = 60
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 14
        Text = '1234567'
        OnEnter = WeightEdit22Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiPerEdit2: TCobEdit
        Left = 146
        Top = 60
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 15
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit2: TCobEdit
        Left = 195
        Top = 60
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 16
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightEdit2: TCobEdit
        Left = 268
        Top = 60
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 17
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiEdit2: TCobEdit
        Left = 341
        Top = 60
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 18
        Text = '1234567'
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit2: TCobEdit
        Left = 511
        Top = 60
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 20
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit2: TCobEdit
        Left = 552
        Top = 60
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 21
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit2: TCobEdit
        Left = 414
        Top = 60
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 19
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit31: TCobEdit
        Left = 0
        Top = 88
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 26
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit32: TCobEdit
        Left = 73
        Top = 88
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 27
        Text = '1234567'
        OnEnter = WeightEdit22Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiPerEdit3: TCobEdit
        Left = 146
        Top = 88
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 28
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit3: TCobEdit
        Left = 195
        Top = 88
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 29
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightEdit3: TCobEdit
        Left = 268
        Top = 88
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 30
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiEdit3: TCobEdit
        Left = 341
        Top = 88
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 31
        Text = '1234567'
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit3: TCobEdit
        Left = 511
        Top = 88
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 33
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit3: TCobEdit
        Left = 552
        Top = 88
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 34
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit3: TCobEdit
        Left = 414
        Top = 88
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 32
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit41: TCobEdit
        Left = 0
        Top = 116
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 39
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit42: TCobEdit
        Left = 73
        Top = 116
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 40
        Text = '1234567'
        OnEnter = WeightEdit22Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiPerEdit4: TCobEdit
        Left = 146
        Top = 116
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 41
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit4: TCobEdit
        Left = 195
        Top = 116
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 42
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightEdit4: TCobEdit
        Left = 268
        Top = 116
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 43
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiEdit4: TCobEdit
        Left = 341
        Top = 116
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 44
        Text = '1234567'
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit4: TCobEdit
        Left = 511
        Top = 116
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 46
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit4: TCobEdit
        Left = 552
        Top = 116
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 47
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit4: TCobEdit
        Left = 414
        Top = 116
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 45
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit51: TCobEdit
        Left = 0
        Top = 144
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 52
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit52: TCobEdit
        Left = 73
        Top = 144
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 53
        Text = '1234567'
        OnEnter = WeightEdit22Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiPerEdit5: TCobEdit
        Left = 146
        Top = 144
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 54
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit5: TCobEdit
        Left = 195
        Top = 144
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 55
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightEdit5: TCobEdit
        Left = 268
        Top = 144
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 56
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiEdit5: TCobEdit
        Left = 341
        Top = 144
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 57
        Text = '1234567'
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit5: TCobEdit
        Left = 511
        Top = 144
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 59
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit5: TCobEdit
        Left = 552
        Top = 144
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 60
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit5: TCobEdit
        Left = 414
        Top = 144
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 58
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit61: TCobEdit
        Left = 0
        Top = 172
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 65
        Text = '1234567'
        OnEnter = WeightEdit11Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object WeightEdit62: TCobEdit
        Left = 73
        Top = 172
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 66
        Text = '1234567'
        OnEnter = WeightEdit22Enter
        OnExit = WeightEdit11Exit
        OnKeyDown = WeightEdit12KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiPerEdit6: TCobEdit
        Left = 146
        Top = 172
        Width = 46
        Height = 23
        ImeMode = imClose
        TabOrder = 67
        Text = '9.9%'
        OnChange = ChoseiPerEdit1Change
        OnEnter = ChoseiPerEdit1Enter
        OnExit = ChoseiPerEdit1Exit
        OnKeyDown = ChoseiPerEdit1KeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiWeightEdit6: TCobEdit
        Left = 195
        Top = 172
        Width = 70
        Height = 23
        TabStop = False
        Color = 15000804
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 68
        Text = '1234567'
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikiWeightEdit6: TCobEdit
        Left = 268
        Top = 172
        Width = 70
        Height = 23
        ImeMode = imClose
        TabOrder = 69
        Text = '1234567'
        OnEnter = BikiWeightEdit1Enter
        OnExit = WeightEdit11Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShomiEdit6: TCobEdit
        Left = 341
        Top = 172
        Width = 70
        Height = 23
        TabStop = False
        ImeMode = imClose
        MaxLength = 7
        TabOrder = 70
        Text = '1234567'
        OnExit = ShomiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniCodeEdit6: TCobEdit
        Left = 511
        Top = 172
        Width = 38
        Height = 23
        ImeMode = imClose
        TabOrder = 72
        Text = '123'
        OnChange = TaniCodeEdit1Change
        OnEnter = TaniCodeEdit1Enter
        OnExit = TaniCodeEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit6: TCobEdit
        Left = 552
        Top = 172
        Width = 58
        Height = 23
        TabStop = False
        Color = 14152959
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 73
        Text = '123456'
        IsInsert = True
      end
      object SuryoEdit6: TCobEdit
        Left = 414
        Top = 172
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 71
        Text = '123456789.'
        OnEnter = SuryoEdit1Enter
        OnExit = SuryoEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object TankaEdit2: TCobEdit
        Left = 613
        Top = 60
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 22
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuEdit2: TCobEdit
        Left = 710
        Top = 60
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 23
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikoEdit2: TCobEdit
        Left = 904
        Top = 60
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 25
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object TankaEdit3: TCobEdit
        Left = 613
        Top = 88
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 35
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuEdit3: TCobEdit
        Left = 710
        Top = 88
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 36
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikoEdit3: TCobEdit
        Left = 904
        Top = 88
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 38
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object TankaEdit4: TCobEdit
        Left = 613
        Top = 116
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 48
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuEdit4: TCobEdit
        Left = 710
        Top = 116
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 49
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikoEdit4: TCobEdit
        Left = 904
        Top = 116
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 51
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object TankaEdit5: TCobEdit
        Left = 613
        Top = 144
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 61
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuEdit5: TCobEdit
        Left = 710
        Top = 144
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 62
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikoEdit5: TCobEdit
        Left = 904
        Top = 144
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 64
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object TankaEdit6: TCobEdit
        Left = 613
        Top = 172
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 74
        Text = '1234567890'
        OnEnter = TankaEdit1Enter
        OnExit = TankaEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object KingakuEdit6: TCobEdit
        Left = 710
        Top = 172
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 75
        Text = '1234567890'
        OnEnter = KingakuEdit1Enter
        OnExit = KingakuEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object BikoEdit6: TCobEdit
        Tag = 999
        Left = 904
        Top = 172
        Width = 175
        Height = 23
        ImeMode = imHira
        TabOrder = 77
        Text = '12345678901234567890'
        OnEnter = BikoEdit1Enter
        OnExit = BikoEdit1Exit
        OnKeyDown = HinCodeEdit1KeyDown
        IsInsert = True
      end
      object ShouhizeiTitleEdit: TCobEdit
        Left = 807
        Top = 8
        Width = 94
        Height = 23
        TabStop = False
        Color = 4210752
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 88
        Text = #28040#36027#31246
        Alignment = taCenter
      end
      object ShouhizeiEdit1: TCobEdit
        Left = 807
        Top = 32
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 11
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShouhizeiEdit2: TCobEdit
        Left = 807
        Top = 60
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 24
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShouhizeiEdit3: TCobEdit
        Left = 807
        Top = 88
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 37
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShouhizeiEdit4: TCobEdit
        Left = 807
        Top = 116
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 50
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShouhizeiEdit5: TCobEdit
        Left = 807
        Top = 144
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 63
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
      object ShouhizeiEdit6: TCobEdit
        Left = 808
        Top = 171
        Width = 94
        Height = 23
        ImeMode = imClose
        TabOrder = 76
        Text = '1234567890'
        OnEnter = ShouhizeiEdit1Enter
        OnExit = ShouhizeiEdit1Exit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object GyoEdit2: TCobEdit
      Tag = 1
      Left = 4
      Top = 60
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 3
      Text = '2'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit2: TCobEdit
      Left = 32
      Top = 60
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 4
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit2: TCobEdit
      Left = 89
      Top = 60
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 5
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object GyoEdit3: TCobEdit
      Tag = 3
      Left = 4
      Top = 88
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 6
      Text = '3'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit3: TCobEdit
      Left = 32
      Top = 88
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 7
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit3: TCobEdit
      Left = 89
      Top = 88
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 8
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object GyoEdit4: TCobEdit
      Tag = 4
      Left = 4
      Top = 116
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 9
      Text = '4'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit4: TCobEdit
      Left = 32
      Top = 116
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 10
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit4: TCobEdit
      Left = 89
      Top = 116
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 11
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object GyoEdit5: TCobEdit
      Tag = 5
      Left = 4
      Top = 144
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 12
      Text = '5'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit5: TCobEdit
      Left = 32
      Top = 144
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 13
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit5: TCobEdit
      Left = 89
      Top = 144
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 14
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object GyoEdit6: TCobEdit
      Tag = 6
      Left = 4
      Top = 172
      Width = 25
      Height = 23
      TabStop = False
      Color = 15000804
      TabOrder = 15
      Text = '6'
      IsInsert = True
      Alignment = taCenter
    end
    object HinCodeEdit6: TCobEdit
      Left = 32
      Top = 172
      Width = 54
      Height = 23
      ImeMode = imClose
      TabOrder = 16
      Text = '99999'
      OnChange = HinCodeEdit1Change
      OnEnter = HinCodeEdit1Enter
      OnExit = HinCodeEdit1Exit
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
      Alignment = taRightJustify
    end
    object HinNameEdit6: TCobEdit
      Left = 89
      Top = 172
      Width = 332
      Height = 23
      TabStop = False
      Color = 14152959
      ImeMode = imHira
      ReadOnly = True
      TabOrder = 17
      Text = '1234567890123456789012345678901234567890'
      OnKeyDown = HinCodeEdit1KeyDown
      IsInsert = True
    end
    object StringGridID: TStringGrid
      Left = 364
      Top = 8
      Width = 57
      Height = 189
      TabStop = False
      Color = 9959677
      ColCount = 1
      DefaultRowHeight = 25
      FixedCols = 0
      RowCount = 7
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 22
      Visible = False
      ColWidths = (
        49)
    end
  end
  object KingakuPanel: TPanel
    Left = 458
    Top = 351
    Width = 254
    Height = 45
    Anchors = [akRight, akBottom]
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 6
    OnEnter = SharyoPanelEnter
    OnExit = SharyoPanelExit
    object Button3: TButton
      Left = 4
      Top = 7
      Width = 109
      Height = 31
      Caption = #37329#38989#35336'('#31246#36796')'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
    end
    object ZeikomiEdit: TCobEdit
      Tag = 999
      Left = 120
      Top = 11
      Width = 126
      Height = 24
      TabStop = False
      Color = 9107709
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imHira
      MaxLength = 40
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      Text = '\9,999,999,999'
      OnEnter = ShabanEditEnter
      IsInsert = True
      Alignment = taRightJustify
    end
  end
  object HannyuPanel: TPanel
    Left = 271
    Top = 351
    Width = 182
    Height = 45
    Anchors = [akRight, akBottom]
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 7
    OnEnter = SharyoPanelEnter
    OnExit = SharyoPanelExit
    object Button6: TButton
      Left = 4
      Top = 7
      Width = 61
      Height = 31
      Caption = #25644#20837#20986
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
    end
    object HannyuCombo: TComboBox
      Left = 76
      Top = 10
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
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnKeyDown = HannyuCombo_KeyDown
      Items.Strings = (
        '1:'#25644#20837
        '2:'#25644#20986)
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 633
    Width = 1016
    Height = 29
    Align = alBottom
    Alignment = taRightJustify
    Color = 16773616
    TabOrder = 8
    DesignSize = (
      1016
      29)
    object WeightSumTitleLabel: TLabel
      Left = 478
      Top = 8
      Width = 42
      Height = 13
      Alignment = taRightJustify
      Anchors = [akLeft, akTop, akRight]
      Caption = #37325#37327#35336
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object KingakuSumTitleLabel: TLabel
      Left = 621
      Top = 8
      Width = 84
      Height = 13
      Alignment = taRightJustify
      Caption = #37329#38989#35336'('#31246#21029')'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object ShohizeiTitleLabel: TLabel
      Left = 848
      Top = 8
      Width = 42
      Height = 13
      Alignment = taRightJustify
      Caption = #28040#36027#31246
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object ShomiSumEdit: TCobEdit
      Left = 523
      Top = 3
      Width = 89
      Height = 23
      TabStop = False
      Anchors = [akRight]
      Color = 14152959
      ReadOnly = True
      TabOrder = 0
      Text = '1234567'
      IsInsert = True
      Alignment = taRightJustify
    end
    object KingakuSumEdit: TCobEdit
      Left = 707
      Top = 3
      Width = 94
      Height = 23
      TabStop = False
      Color = 14152959
      ReadOnly = True
      TabOrder = 1
      Text = '1234567890'
      IsInsert = True
      Alignment = taRightJustify
    end
    object ShohizeiEdit: TCobEdit
      Left = 896
      Top = 3
      Width = 94
      Height = 23
      TabStop = False
      Color = 14152959
      ReadOnly = True
      TabOrder = 2
      Text = '1234567890'
      IsInsert = True
      Alignment = taRightJustify
    end
  end
  object ActionList: TActionList
    Left = 52
    Top = 608
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
    Left = 932
    Top = 164
    object Q_MeisaiID: TIntegerField
      FieldName = #35336#37327'ID'
    end
    object Q_MeisaiNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_MeisaiNo2: TIntegerField
      FieldName = #34892'No'
    end
    object Q_MeisaiID2: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_MeisaiDSDesigner: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_MeisaiDSDesigner2: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_MeisaiDSDesigner3: TIntegerField
      FieldName = #22238#30446#37325#37327
      ReadOnly = True
    end
    object Q_MeisaiDSDesigner1: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
    end
    object Q_Meisai_1: TIntegerField
      FieldName = #22238#30446#37325#37327'_1'
      ReadOnly = True
    end
    object Q_MeisaiDSDesigner22: TDateTimeField
      FieldName = #35336#37327#26085#26178'2'
    end
    object Q_MeisaiDSDesigner4: TBCDField
      FieldName = #35519#25972#29575
      Precision = 10
      Size = 3
    end
    object Q_MeisaiDSDesigner5: TBCDField
      FieldName = #35519#25972#37325#37327
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner6: TBCDField
      FieldName = #37325#37327#24341#12365
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner7: TBCDField
      FieldName = #27491#21619#37325#37327
      Precision = 10
      Size = 1
    end
    object Q_MeisaiDSDesigner8: TBCDField
      FieldName = #25968#37327
      Precision = 10
      Size = 3
    end
    object Q_MeisaiID3: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object Q_MeisaiDSDesigner9: TStringField
      FieldName = #21336#20301#21517#31216
      Size = 10
    end
    object Q_MeisaiDSDesigner10: TBCDField
      FieldName = #21336#20385
      Precision = 13
      Size = 3
    end
    object Q_MeisaiDSDesigner11: TBCDField
      FieldName = #37329#38989
      Precision = 10
      Size = 0
    end
    object Q_MeisaiDSDesigner12: TStringField
      FieldName = #26126#32048#20633#32771
    end
  end
  object dsMeisai: TDataSource
    DataSet = Q_Meisai
    Left = 964
    Top = 164
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
      #9'-- '#21697#30446'ID, '#21697#30446#12467#12540#12489', '#21697#30446#21517#31216','
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
      #9'-- '#21697#30446'ID, '#21697#30446#12467#12540#12489', '#21697#30446#21517#31216','
      #9#38917#30446'1ID, '#38917#30446'1'#12467#12540#12489', '#38917#30446'1'#21517#31216','
      #9#38917#30446'2ID, '#38917#30446'2'#12467#12540#12489', '#38917#30446'2'#21517#31216
      ''
      'ORDER BY'
      #9#35336#37327'ID DESC'
      '')
    Left = 956
    Top = 292
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
    Left = 924
    Top = 292
  end
end
