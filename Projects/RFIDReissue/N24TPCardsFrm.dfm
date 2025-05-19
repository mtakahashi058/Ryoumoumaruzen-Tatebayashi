object N24TPCardsForm: TN24TPCardsForm
  Left = 682
  Top = 223
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'N-24TP'#29992#12459#12540#12489
  ClientHeight = 277
  ClientWidth = 263
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 12
  object AdminButton: TButton
    Left = 31
    Top = 13
    Width = 201
    Height = 47
    Caption = #31649#29702#12459#12540#12489
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TabStop = False
    OnClick = AdminButtonClick
  end
  object ZeroSetButton: TButton
    Left = 31
    Top = 81
    Width = 201
    Height = 47
    Caption = #12476#12525#35373#23450#12459#12540#12489
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    TabStop = False
    OnClick = ZeroSetButtonClick
  end
  object ZeroClrButton: TButton
    Left = 31
    Top = 137
    Width = 201
    Height = 47
    Caption = #12476#12525#35299#38500#12459#12540#12489
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    TabStop = False
    OnClick = ZeroClrButtonClick
  end
  object CancelButton: TButton
    Left = 31
    Top = 217
    Width = 201
    Height = 47
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    TabStop = False
    OnClick = CancelButtonClick
  end
end
