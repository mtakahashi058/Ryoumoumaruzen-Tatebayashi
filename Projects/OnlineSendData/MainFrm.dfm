object MainForm: TMainForm
  Left = 262
  Top = 164
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12458#12531#12521#12452#12531#36865#20449
  ClientHeight = 291
  ClientWidth = 743
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    743
    291)
  PixelsPerInch = 96
  TextHeight = 13
  object SendButton: TButton
    Left = 275
    Top = 130
    Width = 194
    Height = 59
    Anchors = [akTop, akRight]
    Caption = #36865#12288#20449
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = SendButtonClick
  end
  object KeiryoDatePanel: TPanel
    Left = 82
    Top = 80
    Width = 487
    Height = 33
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = #35336#37327#26085
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Bevel1: TBevel
      Left = 0
      Top = 28
      Width = 487
      Height = 5
      Align = alBottom
      Shape = bsBottomLine
    end
    object Label1: TLabel
      Left = 222
      Top = 9
      Width = 15
      Height = 15
      Caption = #65374
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object DatePickerFrom: TDateTimePicker
      Left = 88
      Top = 5
      Width = 121
      Height = 23
      CalAlignment = dtaLeft
      Date = 40777.6027587384
      Time = 40777.6027587384
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 0
    end
    object DatePickerTo: TDateTimePicker
      Left = 250
      Top = 5
      Width = 121
      Height = 23
      CalAlignment = dtaLeft
      Date = 40777.6027587384
      Time = 40777.6027587384
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 1
    end
    object BeforeButton: TButton
      Left = 380
      Top = 3
      Width = 45
      Height = 25
      Caption = '<<'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = BeforeButtonClick
    end
    object NextButton: TButton
      Left = 424
      Top = 3
      Width = 45
      Height = 25
      Caption = '>>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = NextButtonClick
    end
  end
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 743
    Height = 49
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#12458#12531#12521#12452#12531#12391#12487#12540#12479#12434#36865#20449#12375#12414#12377#12290
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnDblClick = TitlePanelDblClick
    DesignSize = (
      743
      49)
    object Button1: TButton
      Left = 626
      Top = 6
      Width = 109
      Height = 37
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      TabOrder = 0
      OnClick = Button1Click
    end
    object SettingButton: TButton
      Left = 512
      Top = 6
      Width = 109
      Height = 37
      Caption = #35373#23450
      TabOrder = 1
      Visible = False
      OnClick = SettingButtonClick
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 272
    Width = 743
    Height = 19
    Panels = <
      item
        Width = 150
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
end
