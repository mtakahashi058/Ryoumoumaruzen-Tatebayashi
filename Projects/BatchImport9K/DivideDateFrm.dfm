object DivideDateForm: TDivideDateForm
  Left = 524
  Top = 215
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #26085#20184#12398#25391#12426#20998#12369
  ClientHeight = 289
  ClientWidth = 513
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Date1Panel: TPanel
    Left = 8
    Top = 8
    Width = 497
    Height = 45
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 84
      Top = 15
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20253#31080#30058#21495
    end
    object Label2: TLabel
      Left = 196
      Top = 15
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label3: TLabel
      Left = 264
      Top = 11
      Width = 24
      Height = 24
      Alignment = taRightJustify
      Caption = #8594
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Date1NoFromEdit: TCobEdit
      Tag = 1
      Left = 152
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 0
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date1NoToEdit: TCobEdit
      Tag = 2
      Left = 216
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 1
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date1Picker: TDateTimePicker
      Left = 304
      Top = 11
      Width = 109
      Height = 24
      CalAlignment = dtaLeft
      Date = 41498.4554417245
      Time = 41498.4554417245
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 2
      TabStop = False
    end
    object Date1PrevButton: TButton
      Tag = 1
      Left = 416
      Top = 10
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 3
      TabStop = False
      OnClick = DateNPrevButtonClick
    end
    object Date1NextButton: TButton
      Tag = 1
      Left = 450
      Top = 10
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      TabStop = False
      OnClick = DateNNextButtonClick
    end
    object Panel1: TPanel
      Left = 4
      Top = 8
      Width = 65
      Height = 29
      BevelInner = bvLowered
      Caption = #26085#20184#65297
      Color = 8454016
      TabOrder = 5
    end
  end
  object Date2Panel: TPanel
    Left = 8
    Top = 51
    Width = 497
    Height = 45
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object Label4: TLabel
      Left = 84
      Top = 15
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20253#31080#30058#21495
    end
    object Label5: TLabel
      Left = 196
      Top = 15
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label6: TLabel
      Left = 264
      Top = 11
      Width = 24
      Height = 24
      Alignment = taRightJustify
      Caption = #8594
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Date2NoFromEdit: TCobEdit
      Tag = 2
      Left = 152
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 0
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date2NoToEdit: TCobEdit
      Tag = 2
      Left = 216
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 1
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date2Picker: TDateTimePicker
      Left = 304
      Top = 11
      Width = 109
      Height = 24
      CalAlignment = dtaLeft
      Date = 41498.4554417245
      Time = 41498.4554417245
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 2
      TabStop = False
    end
    object Date2PrevButton: TButton
      Tag = 2
      Left = 416
      Top = 10
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 3
      TabStop = False
      OnClick = DateNPrevButtonClick
    end
    object Date2NextButton: TButton
      Tag = 2
      Left = 450
      Top = 10
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      TabStop = False
      OnClick = DateNNextButtonClick
    end
    object Panel3: TPanel
      Left = 4
      Top = 8
      Width = 65
      Height = 29
      BevelInner = bvLowered
      Caption = #26085#20184#65298
      Color = 8454016
      TabOrder = 5
    end
  end
  object Date3Panel: TPanel
    Left = 8
    Top = 94
    Width = 497
    Height = 45
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object Label7: TLabel
      Left = 84
      Top = 15
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20253#31080#30058#21495
    end
    object Label8: TLabel
      Left = 196
      Top = 15
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label9: TLabel
      Left = 264
      Top = 11
      Width = 24
      Height = 24
      Alignment = taRightJustify
      Caption = #8594
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Date3NoFromEdit: TCobEdit
      Tag = 2
      Left = 152
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 0
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date3NoToEdit: TCobEdit
      Tag = 2
      Left = 216
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 1
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date3Picker: TDateTimePicker
      Left = 304
      Top = 11
      Width = 109
      Height = 24
      CalAlignment = dtaLeft
      Date = 41498.4554417245
      Time = 41498.4554417245
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 2
      TabStop = False
    end
    object Date3PrevButton: TButton
      Tag = 3
      Left = 416
      Top = 10
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 3
      TabStop = False
      OnClick = DateNPrevButtonClick
    end
    object Date3NextButton: TButton
      Tag = 3
      Left = 450
      Top = 10
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      TabStop = False
      OnClick = DateNNextButtonClick
    end
    object Panel4: TPanel
      Left = 4
      Top = 8
      Width = 65
      Height = 29
      BevelInner = bvLowered
      Caption = #26085#20184#65299
      Color = 8454016
      TabOrder = 5
    end
  end
  object PostButton: TButton
    Left = 202
    Top = 248
    Width = 109
    Height = 33
    Caption = #12487#12540#12479#30331#37682
    TabOrder = 5
    OnClick = PostButtonClick
  end
  object CancelButton: TButton
    Left = 412
    Top = 248
    Width = 89
    Height = 33
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 6
  end
  object Date4Panel: TPanel
    Left = 8
    Top = 137
    Width = 497
    Height = 45
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object Label10: TLabel
      Left = 84
      Top = 15
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20253#31080#30058#21495
    end
    object Label11: TLabel
      Left = 196
      Top = 15
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label12: TLabel
      Left = 264
      Top = 11
      Width = 24
      Height = 24
      Alignment = taRightJustify
      Caption = #8594
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Date4NoFromEdit: TCobEdit
      Tag = 2
      Left = 152
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 0
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date4NoToEdit: TCobEdit
      Tag = 2
      Left = 216
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 1
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date4Picker: TDateTimePicker
      Left = 304
      Top = 11
      Width = 109
      Height = 24
      CalAlignment = dtaLeft
      Date = 41498.4554417245
      Time = 41498.4554417245
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 2
      TabStop = False
    end
    object Date4PrevButton: TButton
      Tag = 4
      Left = 416
      Top = 10
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 3
      TabStop = False
      OnClick = DateNPrevButtonClick
    end
    object Date4NextButton: TButton
      Tag = 4
      Left = 450
      Top = 10
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      TabStop = False
      OnClick = DateNNextButtonClick
    end
    object Panel5: TPanel
      Left = 4
      Top = 8
      Width = 65
      Height = 29
      BevelInner = bvLowered
      Caption = #26085#20184#65300
      Color = 8454016
      TabOrder = 5
    end
  end
  object Date5Panel: TPanel
    Left = 8
    Top = 180
    Width = 497
    Height = 45
    Alignment = taLeftJustify
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 4
    object Label13: TLabel
      Left = 84
      Top = 15
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20253#31080#30058#21495
    end
    object Label14: TLabel
      Left = 196
      Top = 15
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label15: TLabel
      Left = 264
      Top = 11
      Width = 24
      Height = 24
      Alignment = taRightJustify
      Caption = #8594
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Date5NoFromEdit: TCobEdit
      Tag = 2
      Left = 152
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 0
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date5NoToEdit: TCobEdit
      Tag = 999
      Left = 216
      Top = 11
      Width = 41
      Height = 24
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      MaxLength = 3
      ParentFont = False
      TabOrder = 1
      Text = '999'
      IsInsert = True
      Alignment = taRightJustify
    end
    object Date5Picker: TDateTimePicker
      Left = 304
      Top = 11
      Width = 109
      Height = 24
      CalAlignment = dtaLeft
      Date = 41498.4554417245
      Time = 41498.4554417245
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 2
      TabStop = False
    end
    object Date5PrevButton: TButton
      Tag = 5
      Left = 416
      Top = 10
      Width = 33
      Height = 25
      Caption = '<<'
      TabOrder = 3
      TabStop = False
      OnClick = DateNPrevButtonClick
    end
    object Date5NextButton: TButton
      Tag = 5
      Left = 450
      Top = 10
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 4
      TabStop = False
      OnClick = DateNNextButtonClick
    end
    object Panel7: TPanel
      Left = 4
      Top = 8
      Width = 65
      Height = 29
      BevelInner = bvLowered
      Caption = #26085#20184#65301
      Color = 8454016
      TabOrder = 5
    end
  end
end
