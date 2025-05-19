object MainForm: TMainForm
  Left = 314
  Top = 141
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'N9500/9600'#12363#12425#12510#12473#12479#12487#12540#12479#21463#20449
  ClientHeight = 236
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
    236)
  PixelsPerInch = 96
  TextHeight = 12
  object StatusLabel: TLabel
    Left = 16
    Top = 144
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
    Top = 124
    Width = 453
    Height = 9
    Shape = bsTopLine
  end
  object Label1: TLabel
    Left = 332
    Top = 208
    Width = 48
    Height = 16
    Alignment = taRightJustify
    Caption = #20966#29702#65306
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object CountLabel: TLabel
    Left = 388
    Top = 200
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
    Top = 208
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
    TabOrder = 0
    OnClick = CloseButtonClick
  end
  object ProgressBar: TProgressBar
    Left = 16
    Top = 164
    Width = 431
    Height = 25
    Min = 0
    Max = 100
    TabOrder = 1
  end
  object ItemImportButton: TButton
    Left = 11
    Top = 62
    Width = 214
    Height = 46
    Caption = #38917#30446#24773#22577#21463#20449
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ItemImportButtonClick
  end
  object CarsImportButton: TButton
    Left = 11
    Top = 10
    Width = 214
    Height = 46
    Caption = #36554#20001#24773#22577#21463#20449
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = CarsImportButtonClick
  end
end
