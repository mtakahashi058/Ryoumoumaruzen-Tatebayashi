object MainForm: TMainForm
  Left = 326
  Top = 182
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12487#12540#12479#21463#20449
  ClientHeight = 291
  ClientWidth = 745
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    745
    291)
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 745
    Height = 49
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#12458#12531#12521#12452#12531#12391#12487#12540#12479#12434#21463#20449#12375#12414#12377#12290
    Color = 12975102
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnDblClick = TitlePanelDblClick
    DesignSize = (
      745
      49)
    object Button1: TButton
      Left = 628
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
    Width = 745
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
  object ReceiveButton: TButton
    Left = 275
    Top = 122
    Width = 194
    Height = 59
    Anchors = [akTop, akRight]
    Caption = #21463#12288#20449
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ReceiveButtonClick
  end
end
