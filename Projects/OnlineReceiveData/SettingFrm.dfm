object SettingForm: TSettingForm
  Left = 384
  Top = 171
  Width = 346
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
    Left = 36
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
    Left = 80
    Top = 319
    Width = 105
    Height = 29
    Caption = #20445' '#23384
    TabOrder = 0
    OnClick = SaveButtonClick
  end
  object CancelButton: TButton
    Left = 192
    Top = 319
    Width = 81
    Height = 29
    Caption = #12461#12515#12531#12475#12523
    TabOrder = 1
    OnClick = CancelButtonClick
  end
  object GroupBox2: TGroupBox
    Left = 20
    Top = 20
    Width = 289
    Height = 213
    Caption = #21463#20449#35443#32048
    TabOrder = 2
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
    Left = 20
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
    TabOrder = 3
  end
end
