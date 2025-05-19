object SortSetForm: TSortSetForm
  Left = 389
  Top = 340
  Width = 450
  Height = 290
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #20006#12409#26367#12360#35373#23450
  Color = 16773616
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object SetButton: TButton
    Left = 213
    Top = 184
    Width = 106
    Height = 30
    Action = Action5
    TabOrder = 0
  end
  object CloseButton: TButton
    Left = 319
    Top = 184
    Width = 106
    Height = 30
    Action = Action12
    TabOrder = 1
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 228
    Width = 434
    Height = 24
    Panels = <>
    SimplePanel = True
  end
  object ItemSetGroupBox: TGroupBox
    Left = 16
    Top = 16
    Width = 410
    Height = 137
    Caption = #20006#12409#26367#12360#38917#30446#35373#23450
    TabOrder = 3
    object SeikyushoPrintPanel: TPanel
      Left = 18
      Top = 25
      Width = 370
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = SeikyushoPrintPanelEnter
      OnExit = SeikyushoPrintPanelExit
      object Label1: TLabel
        Left = 15
        Top = 7
        Width = 40
        Height = 15
        Caption = '1'#30058#30446
      end
      object SortComboBox1: TComboBox
        Left = 280
        Top = 3
        Width = 65
        Height = 23
        Color = clCream
        ItemHeight = 15
        ItemIndex = 0
        TabOrder = 0
        Text = #26119#38918
        Items.Strings = (
          #26119#38918
          #38477#38918)
      end
      object ItemComboBox1: TComboBox
        Left = 72
        Top = 3
        Width = 185
        Height = 23
        Color = clCream
        ItemHeight = 15
        TabOrder = 1
        Text = 'ComboBox1'
      end
    end
    object Panel1: TPanel
      Left = 18
      Top = 57
      Width = 370
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = SeikyushoPrintPanelEnter
      OnExit = SeikyushoPrintPanelExit
      object Label2: TLabel
        Left = 15
        Top = 7
        Width = 40
        Height = 15
        Caption = '2'#30058#30446
      end
      object SortComboBox2: TComboBox
        Left = 280
        Top = 3
        Width = 65
        Height = 23
        Color = clCream
        ItemHeight = 15
        ItemIndex = 0
        TabOrder = 0
        Text = #26119#38918
        Items.Strings = (
          #26119#38918
          #38477#38918)
      end
      object ItemComboBox2: TComboBox
        Left = 72
        Top = 3
        Width = 185
        Height = 23
        Color = clCream
        ItemHeight = 15
        TabOrder = 1
        Text = 'ComboBox1'
      end
    end
    object Panel2: TPanel
      Left = 18
      Top = 89
      Width = 370
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = SeikyushoPrintPanelEnter
      OnExit = SeikyushoPrintPanelExit
      object Label3: TLabel
        Left = 15
        Top = 7
        Width = 40
        Height = 15
        Caption = '3'#30058#30446
      end
      object SortComboBox3: TComboBox
        Left = 280
        Top = 3
        Width = 65
        Height = 23
        Color = clCream
        ItemHeight = 15
        ItemIndex = 0
        TabOrder = 0
        Text = #26119#38918
        Items.Strings = (
          #26119#38918
          #38477#38918)
      end
      object ItemComboBox3: TComboBox
        Left = 72
        Top = 3
        Width = 185
        Height = 23
        Color = clCream
        ItemHeight = 15
        TabOrder = 1
        Text = 'ComboBox1'
      end
    end
  end
  object F5Panel: TPanel
    Left = 213
    Top = 165
    Width = 106
    Height = 19
    Caption = 'F5'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object F12Panel: TPanel
    Left = 319
    Top = 165
    Width = 106
    Height = 19
    Caption = 'F12'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object ActionList: TActionList
    Left = 24
    Top = 168
    object Action5: TAction
      Caption = #35373#12288#23450
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action12: TAction
      Caption = #38281#12376#12427
      ShortCut = 123
      OnExecute = Action12Execute
    end
  end
end
