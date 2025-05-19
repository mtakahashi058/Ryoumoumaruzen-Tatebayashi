object FirstWeightStateForm: TFirstWeightStateForm
  Left = 246
  Top = 30
  BorderStyle = bsSingle
  Caption = 'FirstWeightStateForm'
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
  object Label2: TLabel
    Left = 762
    Top = 460
    Width = 46
    Height = 48
    Caption = 'kg'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Panel5: TPanel
    Left = 165
    Top = 84
    Width = 677
    Height = 81
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = '1'#22238#30446#37325#37327#12434#30906#35469#12375#12390#12367#12384#12373#12356
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object InfoPanel: TPanel
    Left = 195
    Top = 200
    Width = 617
    Height = 233
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Item1Label: TLabel
      Left = 12
      Top = 118
      Width = 380
      Height = 37
      Caption = '12345678901234567890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object CarNoLabel: TLabel
      Left = 12
      Top = 15
      Width = 323
      Height = 37
      Alignment = taCenter
      Caption = 'XXXXXXXXXXXXXXXXX'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Item2Label: TLabel
      Left = 12
      Top = 170
      Width = 380
      Height = 37
      Caption = '12345678901234567890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TokuLabel: TLabel
      Left = 12
      Top = 66
      Width = 380
      Height = 37
      Caption = '12345678901234567890'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Item1ChangeButton: TButton
      Left = 492
      Top = 116
      Width = 97
      Height = 41
      Caption = #22793#26356
      TabOrder = 2
      OnClick = Item1ChangeButtonClick
    end
    object Item2ChangeButton: TButton
      Left = 492
      Top = 168
      Width = 97
      Height = 41
      Caption = #22793#26356
      TabOrder = 3
      OnClick = Item2ChangeButtonClick
    end
    object CarNoChangeButton: TButton
      Left = 492
      Top = 12
      Width = 97
      Height = 41
      Caption = #22793#26356
      TabOrder = 0
      OnClick = CarNoChangeButtonClick
    end
    object TokuChangeButton: TButton
      Left = 492
      Top = 64
      Width = 97
      Height = 41
      Caption = #22793#26356
      TabOrder = 1
      OnClick = TokuChangeButtonClick
    end
  end
  object CancelButton: TButton
    Left = 50
    Top = 609
    Width = 165
    Height = 49
    Caption = #21462#28040
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = CancelButtonClick
  end
  object WeightPanel: TPanel
    Left = 432
    Top = 448
    Width = 319
    Height = 69
    Alignment = taRightJustify
    BevelOuter = bvLowered
    Caption = 'XXXXXX '
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ConfirmButton: TButton
    Left = 763
    Top = 571
    Width = 201
    Height = 87
    Caption = #30906#35469
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = ConfirmButtonClick
  end
  object WarningMemo: TMemo
    Left = 265
    Top = 532
    Width = 477
    Height = 89
    BorderStyle = bsNone
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    Lines.Strings = (
      #22865#32004#26399#38480#12364#20999#12428#12390#12356#12414#12377#12290)
    ParentColor = True
    ParentFont = False
    TabOrder = 5
  end
end
