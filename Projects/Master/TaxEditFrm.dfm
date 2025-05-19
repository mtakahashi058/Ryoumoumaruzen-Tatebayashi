object TaxEditForm: TTaxEditForm
  Left = 386
  Top = 250
  Width = 555
  Height = 253
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #28040#36027#31246#30331#37682#65295#20462#27491
  Color = 16773616
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object ModePanel: TPanel
    Left = 27
    Top = 122
    Width = 97
    Height = 57
    BevelOuter = bvNone
    Caption = #38283#30330#20013
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object RenzokuCheckBox: TCheckBox
    Left = 32
    Top = 99
    Width = 87
    Height = 17
    Caption = #36899#32154#30331#37682
    TabOrder = 1
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 191
    Width = 539
    Height = 24
    Panels = <>
    SimplePanel = True
  end
  object F1Panel: TPanel
    Left = 185
    Top = 130
    Width = 84
    Height = 19
    Caption = 'F5'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object F2Panel: TPanel
    Left = 271
    Top = 130
    Width = 84
    Height = 19
    Caption = 'F7'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object F3Panel: TPanel
    Left = 357
    Top = 130
    Width = 84
    Height = 19
    Caption = 'F8'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object F4Panel: TPanel
    Left = 443
    Top = 130
    Width = 84
    Height = 19
    Caption = 'F12'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object F5Button: TButton
    Left = 184
    Top = 149
    Width = 87
    Height = 30
    HelpKeyword = 'F1'
    Action = Action5
    ParentShowHint = False
    ShowHint = False
    TabOrder = 7
    TabStop = False
  end
  object F7Button: TButton
    Left = 270
    Top = 149
    Width = 87
    Height = 30
    HelpKeyword = 'F2'
    Action = Action7
    ParentShowHint = False
    ShowHint = False
    TabOrder = 8
    TabStop = False
  end
  object F3Button: TButton
    Left = 356
    Top = 149
    Width = 87
    Height = 30
    HelpKeyword = 'F3'
    Action = Action8
    ParentShowHint = False
    ShowHint = False
    TabOrder = 9
    TabStop = False
  end
  object F4Button: TButton
    Left = 442
    Top = 149
    Width = 87
    Height = 30
    HelpKeyword = 'F4'
    Action = Action12
    ParentShowHint = False
    ShowHint = False
    TabOrder = 10
    TabStop = False
  end
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 513
    Height = 79
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 11
    object DatePanel: TPanel
      Left = 10
      Top = 8
      Width = 219
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = DatePanelEnter
      OnExit = DatePanelExit
      object Label1: TLabel
        Left = 10
        Top = 7
        Width = 64
        Height = 15
        Caption = #38283#22987#26085#20184
      end
      object StartDatePicker: TDateTimePicker
        Tag = 1
        Left = 84
        Top = 3
        Width = 112
        Height = 23
        CalAlignment = dtaLeft
        Date = 40079.7087071296
        Time = 40079.7087071296
        Color = clCream
        DateFormat = dfShort
        DateMode = dmComboBox
        ImeMode = imDisable
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
    end
    object TaxRatePanel: TPanel
      Left = 10
      Top = 41
      Width = 219
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = DatePanelEnter
      OnExit = DatePanelExit
      object Label2: TLabel
        Left = 10
        Top = 7
        Width = 64
        Height = 15
        Caption = #31246'    '#29575
      end
      object TaxRateEdit: TCobEdit
        Tag = 99
        Left = 84
        Top = 3
        Width = 45
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 3
        TabOrder = 0
        Text = '123'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
  end
  object ActionList: TActionList
    Left = 139
    Top = 146
    object Action4: TAction
      Caption = 'Action4'
      ShortCut = 115
    end
    object Action5: TAction
      Caption = #30331#12288#37682
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action7: TAction
      Caption = #21069#12288#12408
      ShortCut = 118
      OnExecute = Action7Execute
    end
    object Action8: TAction
      Caption = #27425#12288#12408
      ShortCut = 119
      OnExecute = Action8Execute
    end
    object Action12: TAction
      Caption = #38281#12376#12427
      ShortCut = 123
      OnExecute = Action12Execute
    end
  end
end
