object MainForm: TMainForm
  Left = 1423
  Top = 46
  Width = 1024
  Height = 710
  Caption = #12521#12505#12523#21360#23383
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
  DesignSize = (
    1016
    676)
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 292
    Top = 10
    Width = 64
    Height = 15
    Alignment = taRightJustify
    Caption = #12467#12540#12489#65306
  end
  object Label2: TLabel
    Left = 534
    Top = 10
    Width = 112
    Height = 15
    Alignment = taRightJustify
    Caption = #21360#23383#38283#22987#20301#32622#65306
  end
  object CheckListBox: TCheckListBox
    Left = 0
    Top = 36
    Width = 1016
    Height = 596
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = 16707053
    Columns = 3
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ItemHeight = 15
    Items.Strings = (
      '1234567890123456789012345678901234567890'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '20'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '30'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '40'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '50'
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '60'
      '')
    ParentFont = False
    TabOrder = 1
    OnClick = CheckListBoxClick
  end
  object btnPrint: TButton
    Left = 664
    Top = 638
    Width = 110
    Height = 28
    Anchors = [akRight, akBottom]
    Caption = #21360' '#21047
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = btnPrintClick
  end
  object btnPreview: TButton
    Left = 776
    Top = 638
    Width = 110
    Height = 28
    Anchors = [akRight, akBottom]
    Caption = #12503#12524#12499#12517#12540
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = btnPreviewClick
  end
  object btnClose: TButton
    Left = 888
    Top = 638
    Width = 110
    Height = 28
    Anchors = [akRight, akBottom]
    Caption = #32066' '#20102
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = btnCloseClick
  end
  object btnAll: TButton
    Left = 8
    Top = 4
    Width = 109
    Height = 28
    Caption = #12377#12409#12390#36984#25246
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = btnAllClick
  end
  object btnNone: TButton
    Left = 120
    Top = 4
    Width = 109
    Height = 28
    Caption = #12377#12409#12390#36984#25246#35299#38500
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = btnNoneClick
  end
  object cedtCode: TCobEdit
    Left = 360
    Top = 7
    Width = 49
    Height = 23
    ImeMode = imClose
    TabOrder = 0
    Text = '12345'
    OnKeyDown = cedtCodeKeyDown
    Alignment = taRightJustify
  end
  object cbRetu: TComboBox
    Left = 648
    Top = 7
    Width = 53
    Height = 23
    Style = csDropDownList
    ImeMode = imClose
    ItemHeight = 15
    ItemIndex = 0
    TabOrder = 7
    Text = '1'#21015
    Items.Strings = (
      '1'#21015
      '2'#21015
      '3'#21015)
  end
  object cbGyo: TComboBox
    Left = 704
    Top = 7
    Width = 53
    Height = 23
    Style = csDropDownList
    ImeMode = imClose
    ItemHeight = 15
    ItemIndex = 0
    TabOrder = 8
    Text = '1'#34892
    Items.Strings = (
      '1'#34892
      '2'#34892
      '3'#34892
      '4'#34892
      '5'#34892
      '6'#34892
      '7'#34892)
  end
end
