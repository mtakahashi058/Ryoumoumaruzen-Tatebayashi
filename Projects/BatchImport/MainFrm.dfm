object MainForm: TMainForm
  Left = 939
  Top = 403
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #25351#31034#35336#35336#37327#12487#12540#12479#21462#12426#36796#12415
  ClientHeight = 220
  ClientWidth = 463
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  DesignSize = (
    463
    220)
  PixelsPerInch = 96
  TextHeight = 12
  object StatusLabel: TLabel
    Left = 16
    Top = 124
    Width = 272
    Height = 16
    Caption = #21463#20449#38283#22987#12508#12479#12531#12434#12463#12522#12483#12463#12375#12390#19979#12373#12356
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 5
    Top = 104
    Width = 453
    Height = 9
    Shape = bsTopLine
  end
  object Label1: TLabel
    Left = 300
    Top = 188
    Width = 80
    Height = 16
    Caption = #21463#20449#28168#12415#65306
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object CountLabel: TLabel
    Left = 388
    Top = 180
    Width = 36
    Height = 24
    Alignment = taRightJustify
    Caption = '999'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 428
    Top = 188
    Width = 16
    Height = 16
    Caption = #20214
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object StdUnitLabel: TLabel
    Left = 17
    Top = 72
    Width = 144
    Height = 16
    Alignment = taCenter
    Caption = #27161#28310#21336#20301#12399#12300'1234'#12301
    Color = clBtnFace
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object ImportButton: TButton
    Left = 11
    Top = 10
    Width = 193
    Height = 46
    Caption = #21463#20449#38283#22987
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ImportButtonClick
  end
  object CloseButton: TButton
    Left = 356
    Top = 10
    Width = 97
    Height = 46
    Anchors = [akTop, akRight]
    Caption = #38281#12376#12427
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = CloseButtonClick
  end
  object ProgressBar: TProgressBar
    Left = 16
    Top = 144
    Width = 431
    Height = 25
    Min = 0
    Max = 100
    TabOrder = 2
  end
  object ConvertCheckBox: TCheckBox
    Left = 268
    Top = 72
    Width = 185
    Height = 17
    Caption = #25563#31639#12510#12473#12479#12434#20351#29992#12377#12427
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
end
