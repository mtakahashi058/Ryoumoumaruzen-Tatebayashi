object CarNoInputForm: TCarNoInputForm
  Left = 160
  Top = 69
  BorderStyle = bsSingle
  Caption = 'CarNoInputForm'
  ClientHeight = 678
  ClientWidth = 975
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 60
    Top = 20
    Width = 677
    Height = 57
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #36554#30058#12434#20837#21147#12375#12390#12367#12384#12373#12356
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 58
    Top = 616
    Width = 165
    Height = 49
    Caption = #21462#28040
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = CancelButtonClick
  end
  object CarNoPanel: TPanel
    Left = 192
    Top = 224
    Width = 197
    Height = 81
    BevelInner = bvLowered
    Caption = '9999'
    Color = clWhite
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object CarNoSetButton: TButton
    Left = 182
    Top = 340
    Width = 217
    Height = 81
    Caption = #27770#23450
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = CarNoSetButtonClick
  end
  object CarNoInputPanel: TPanel
    Left = 528
    Top = 120
    Width = 449
    Height = 497
    BevelInner = bvLowered
    TabOrder = 4
    object Input7Button: TButton
      Tag = 7
      Left = 26
      Top = 16
      Width = 121
      Height = 101
      Caption = '7'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = Input0ButtonClick
    end
    object Input8Button: TButton
      Tag = 8
      Left = 166
      Top = 16
      Width = 121
      Height = 101
      Caption = '8'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = Input0ButtonClick
    end
    object Input9Button: TButton
      Tag = 9
      Left = 302
      Top = 16
      Width = 121
      Height = 101
      Caption = '9'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = Input0ButtonClick
    end
    object Input4Button: TButton
      Tag = 4
      Left = 26
      Top = 136
      Width = 121
      Height = 101
      Caption = '4'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = Input0ButtonClick
    end
    object Input5Button: TButton
      Tag = 5
      Left = 166
      Top = 136
      Width = 121
      Height = 101
      Caption = '5'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = Input0ButtonClick
    end
    object Input6Button: TButton
      Tag = 6
      Left = 302
      Top = 136
      Width = 121
      Height = 101
      Caption = '6'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = Input0ButtonClick
    end
    object Input1Button: TButton
      Tag = 1
      Left = 26
      Top = 256
      Width = 121
      Height = 101
      Caption = '1'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Input0ButtonClick
    end
    object Input2Button: TButton
      Tag = 2
      Left = 166
      Top = 256
      Width = 121
      Height = 101
      Caption = '2'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Input0ButtonClick
    end
    object Input3Button: TButton
      Tag = 3
      Left = 302
      Top = 256
      Width = 121
      Height = 101
      Caption = '3'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Input0ButtonClick
    end
    object Input0Button: TButton
      Left = 26
      Top = 376
      Width = 121
      Height = 101
      Caption = '0'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -91
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Input0ButtonClick
    end
    object InputBackButton: TButton
      Tag = 10
      Left = 166
      Top = 376
      Width = 121
      Height = 101
      Caption = #35330#27491
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -48
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = Input0ButtonClick
    end
    object InputClearButton: TButton
      Tag = 11
      Left = 302
      Top = 376
      Width = 121
      Height = 101
      Caption = #28040#21435
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -48
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      OnClick = Input0ButtonClick
    end
  end
end
