object YubinSearchForm: TYubinSearchForm
  Left = 691
  Top = 681
  Width = 870
  Height = 600
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #37109#20415#30058#21495#26908#32034
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 10
    Top = 5
    Width = 208
    Height = 15
    Caption = #9312#37117#36947#24220#30476#12434#36984#25246#12375#12390#19979#12373#12356
    Color = clBtnFace
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 10
    Top = 133
    Width = 208
    Height = 15
    Caption = #9313#24066#21306#30010#26449#12434#36984#25246#12375#12390#19979#12373#12356
    Color = clBtnFace
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label3: TLabel
    Left = 10
    Top = 331
    Width = 176
    Height = 15
    Caption = #9314#30010#22495#12434#36984#25246#12375#12390#19979#12373#12356
    Color = clBtnFace
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlue
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label4: TLabel
    Left = 10
    Top = 534
    Width = 144
    Height = 15
    Caption = #9315#35442#24403#12377#12427#37109#20415#30058#21495
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object KenListBox: TListBox
    Left = 8
    Top = 25
    Width = 841
    Height = 100
    AutoComplete = False
    Columns = 8
    ImeMode = imHira
    ItemHeight = 15
    Items.Strings = (
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890')
    TabOrder = 0
    OnClick = KenListBoxClick
  end
  object SiListBox: TListBox
    Left = 8
    Top = 155
    Width = 841
    Height = 170
    AutoComplete = False
    Columns = 6
    ImeMode = imHira
    ItemHeight = 15
    Items.Strings = (
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890'
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890')
    TabOrder = 1
    OnClick = SiListBoxClick
  end
  object TyouikiListBox: TListBox
    Left = 8
    Top = 352
    Width = 841
    Height = 170
    AutoComplete = False
    Columns = 6
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ImeMode = imHira
    ItemHeight = 13
    Items.Strings = (
      
        '1234567890123456789012345678901234567890123456789012345678901234' +
        '567890123456789012345678901234567890')
    ParentFont = False
    TabOrder = 2
    OnClick = TyouikiListBoxClick
  end
  object YubinEdit: TCobEdit
    Left = 171
    Top = 530
    Width = 66
    Height = 23
    TabOrder = 3
    Text = '1234567'
    OnChange = YubinEditChange
  end
  object FixButton: TButton
    Left = 640
    Top = 526
    Width = 105
    Height = 30
    Caption = #30906#12288#23450
    ModalResult = 1
    TabOrder = 4
  end
  object CancelButton: TButton
    Left = 744
    Top = 526
    Width = 105
    Height = 30
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 5
  end
end
