object SettingForm: TSettingForm
  Left = 384
  Top = 171
  Width = 767
  Height = 423
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #35373#23450#30011#38754
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 452
    Top = 240
    Width = 4
    Height = 13
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object SaveButton: TButton
    Left = 496
    Top = 319
    Width = 105
    Height = 29
    Caption = #20445' '#23384
    TabOrder = 0
    OnClick = SaveButtonClick
  end
  object CancelButton: TButton
    Left = 608
    Top = 319
    Width = 81
    Height = 29
    Caption = #12461#12515#12531#12475#12523
    TabOrder = 1
    OnClick = CancelButtonClick
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 20
    Width = 409
    Height = 341
    Caption = #36865#20449#12501#12449#12452#12523#35373#23450
    TabOrder = 2
    object Panel1: TPanel
      Left = 16
      Top = 28
      Width = 153
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #36865#20449#12377#12427
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object SendListBox: TListBox
      Left = 16
      Top = 48
      Width = 153
      Height = 265
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 13
      Items.Strings = (
        'D_'#35336#37327
        'D_'#21462#24341
        'M_'#25563#31639
        'M_'#25312#28857
        'M_'#37504#34892
        'M_'#21306#20998
        'M_'#38917#30446'1'
        'M_'#38917#30446'2'
        'M_'#38917#30446#38306#36899
        'M_'#36554#20001
        'M_'#28040#36027#31246
        'M_'#21046#24481
        'M_'#21336#20301
        'M_'#21336#20385
        'M_'#20253#31080#24773#22577
        'M_'#20253#31080#24773#22577#38306#36899
        'M_'#24471#24847#20808
        'M_'#21697#30446
        'M_'#21697#30446#20998#39006)
      ParentFont = False
      Sorted = True
      TabOrder = 1
    end
    object IgnoreListBox: TListBox
      Left = 236
      Top = 48
      Width = 153
      Height = 265
      Color = 15658734
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 13
      ParentFont = False
      Sorted = True
      TabOrder = 2
    end
    object Panel2: TPanel
      Left = 236
      Top = 28
      Width = 153
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #36865#20449#12375#12394#12356
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object AllSendButton: TButton
      Left = 176
      Top = 92
      Width = 53
      Height = 33
      Caption = '<<<'
      TabOrder = 4
      OnClick = AllSendButtonClick
    end
    object SelectedSendButton: TButton
      Left = 176
      Top = 132
      Width = 53
      Height = 33
      Caption = '<'
      TabOrder = 5
      OnClick = SelectedSendButtonClick
    end
    object SelectedIgnoreButton: TButton
      Left = 176
      Top = 172
      Width = 53
      Height = 33
      Caption = '>'
      TabOrder = 6
      OnClick = SelectedIgnoreButtonClick
    end
    object AllIgnoreButton: TButton
      Left = 176
      Top = 212
      Width = 53
      Height = 33
      Caption = '>>>'
      TabOrder = 7
      OnClick = AllIgnoreButtonClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 436
    Top = 20
    Width = 289
    Height = 213
    Caption = #36865#20449#35443#32048
    TabOrder = 3
    object Panel3: TPanel
      Left = 12
      Top = 28
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #19968#26178#12501#12457#12523#12480
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object LocalFolderEdit: TCobEdit
      Left = 104
      Top = 28
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 1
      Text = '..\Send\'
      IsInsert = True
    end
    object Panel4: TPanel
      Left = 12
      Top = 52
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12469#12540#12496
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object ServerNameEdit: TCobEdit
      Left = 104
      Top = 52
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 3
      Text = 'n-soft.jp'
      IsInsert = True
    end
    object Panel5: TPanel
      Left = 12
      Top = 76
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12509#12540#12488
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object PortEdit: TCobEdit
      Left = 104
      Top = 76
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 5
      IsInsert = True
    end
    object Panel6: TPanel
      Left = 12
      Top = 100
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12518#12540#12470
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object UserEdit: TCobEdit
      Left = 104
      Top = 100
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 7
      Text = 'admin'
      IsInsert = True
    end
    object Panel7: TPanel
      Left = 12
      Top = 124
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12497#12473#12527#12540#12489
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object PasswordEdit: TCobEdit
      Left = 104
      Top = 124
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      PasswordChar = '*'
      TabOrder = 9
      Text = 'nsoft'
      IsInsert = True
    end
    object Panel8: TPanel
      Left = 12
      Top = 148
      Width = 89
      Height = 21
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12497#12473
      Color = 4539717
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 10
    end
    object ServerPathEdit: TCobEdit
      Left = 104
      Top = 148
      Width = 173
      Height = 21
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 11
      Text = 'cgi-bin/upload_test'
      IsInsert = True
    end
    object RichEdit2: TRichEdit
      Left = 28
      Top = 172
      Width = 245
      Height = 31
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clBtnFace
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Lines.Strings = (
        #8251#25312#28857#38291#12391#36865#21463#20449#12434#34892#12358#22580#21512#12289
        #12288#12300#12497#12473#12301#12399#21029#12398#22580#25152#12434#25351#23450#12375#12390#12367#12384#12373#12356#12290
        '')
      ParentFont = False
      TabOrder = 12
    end
  end
  object RichEdit1: TRichEdit
    Left = 436
    Top = 260
    Width = 289
    Height = 31
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 15000573
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    Lines.Strings = (
      #8251#27880#24847#65281#12371#12398#30011#38754#12398#35373#23450#12434#12416#12420#12415#12395#22793#26356#12377#12427#12392#12289
      #12288#27491#24120#12395#36865#21463#20449#12391#12365#12394#12367#12394#12427#21487#33021#24615#12364#12354#12426#12414#12377#12290)
    ParentFont = False
    TabOrder = 4
  end
end
