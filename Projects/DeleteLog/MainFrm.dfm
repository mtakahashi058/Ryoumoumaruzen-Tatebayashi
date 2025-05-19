object MainForm: TMainForm
  Left = 325
  Top = 123
  Width = 593
  Height = 126
  Caption = #12525#12464#21066#38500
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 20
    Top = 36
    Width = 72
    Height = 15
    Caption = #26085#20184#31684#22258':'
  end
  object Label2: TLabel
    Left = 265
    Top = 36
    Width = 17
    Height = 15
    Caption = #65374
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DatePickerFrom: TDateTimePicker
    Left = 124
    Top = 32
    Width = 125
    Height = 23
    CalAlignment = dtaLeft
    CalColors.BackColor = 8454143
    Date = 40156.7374976852
    Time = 40156.7374976852
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 1
  end
  object DatePickerTo: TDateTimePicker
    Left = 320
    Top = 32
    Width = 125
    Height = 23
    CalAlignment = dtaLeft
    Date = 40156.7374976852
    Time = 40156.7374976852
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 3
  end
  object DeleteLogButton: TButton
    Left = 468
    Top = 21
    Width = 85
    Height = 48
    Caption = #12525#12464#21066#38500
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = DeleteLogButtonClick
  end
  object FromCheckBox: TCheckBox
    Left = 107
    Top = 36
    Width = 17
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 0
    OnClick = FromCheckBoxClick
  end
  object ToCheckBox: TCheckBox
    Left = 303
    Top = 36
    Width = 17
    Height = 17
    Checked = True
    State = cbChecked
    TabOrder = 2
    OnClick = ToCheckBoxClick
  end
end
