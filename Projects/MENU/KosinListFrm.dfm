object KosinListForm: TKosinListForm
  Left = 280
  Top = 112
  Width = 234
  Height = 276
  BorderIcons = [biSystemMenu]
  Caption = #26356#26032#12501#12449#12452#12523#12522#12473#12488
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  DesignSize = (
    226
    242)
  PixelsPerInch = 96
  TextHeight = 12
  object KosinListBox: TListBox
    Left = 12
    Top = 8
    Width = 201
    Height = 169
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = 15461355
    ItemHeight = 12
    TabOrder = 0
  end
  object Button1: TButton
    Left = 58
    Top = 204
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = #26356#26032
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object Button2: TButton
    Left = 138
    Top = 204
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 2
  end
  object chSettingFile: TCheckBox
    Left = 12
    Top = 182
    Width = 141
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #35373#23450#12501#12449#12452#12523#12434#12467#12500#12540#12377#12427
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
end
