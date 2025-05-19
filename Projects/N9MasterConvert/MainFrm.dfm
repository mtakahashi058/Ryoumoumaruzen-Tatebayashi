object MainForm: TMainForm
  Left = 396
  Top = 227
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'N9 CSV -> ScM'
  ClientHeight = 199
  ClientWidth = 411
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 65
    Height = 12
    Caption = #23550#35937#12501#12449#12452#12523
  end
  object RefButton: TButton
    Left = 377
    Top = 21
    Width = 21
    Height = 25
    Caption = '...'
    TabOrder = 1
    OnClick = RefButtonClick
  end
  object FileEdit: TEdit
    Left = 13
    Top = 23
    Width = 361
    Height = 20
    TabOrder = 0
  end
  object MasterGroup: TRadioGroup
    Left = 13
    Top = 52
    Width = 241
    Height = 89
    Caption = #12501#12449#12452#12523#12398#31278#39006
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      #36554#20001#12510#12473#12479
      #24471#24847#20808#12510#12473#12479
      #38917#30446#65297#12510#12473#12479
      #38917#30446#65298#12510#12473#12479
      #21697#30446#12510#12473#12479)
    TabOrder = 2
  end
  object CnvButton: TButton
    Left = 157
    Top = 156
    Width = 97
    Height = 29
    Caption = #22793#25563#38283#22987
    TabOrder = 3
    OnClick = CnvButtonClick
  end
  object OpenDialog: TOpenDialog
    Filter = #20840#12390#12398#12501#12449#12452#12523'|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 213
    Top = 8
  end
end
